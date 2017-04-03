/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#include "Steam.h"
#include "Steamcallbacks.h"

std::unordered_map<uint64_t, bool> SteamCallback::_Calls;
std::unordered_map<uint64_t, CallbackBase *> SteamCallback::_ResultHandlers;
std::vector<SteamAPIResult_t> SteamCallback::_Results;
std::vector<CallbackBase*> SteamCallback::_Callbacks;
int32_t SteamCallback::_CallID;
std::mutex Threadsafe;

void SteamCallback::RegisterCallback(CallbackBase *handler, int32_t callback)
{
    DebugPrint(va("%s <%s>", __FUNCTION__, GetCallbackName(callback)).c_str());

    Threadsafe.lock();
    {
        handler->SetICallback(callback);
        _Callbacks.push_back(handler);
    }
    Threadsafe.unlock();
}
void SteamCallback::RegisterCallResult(uint64_t call, CallbackBase *result)
{
    DebugPrint(va("%s <%s> (%lli)", __FUNCTION__, GetCallbackName(result->GetICallback()), call).c_str());

    Threadsafe.lock();
    {
        _ResultHandlers[call] = result;
    }
    Threadsafe.unlock();
}
void SteamCallback::UnregisterCallback(CallbackBase *handler, int32_t callback)
{
    DebugPrint(va("%s <%s>", __FUNCTION__, GetCallbackName(callback)).c_str());
}
void SteamCallback::UnregisterCallResult(uint64_t call, CallbackBase *result)
{
    DebugPrint(va("%s <%lli>", __FUNCTION__, call).c_str());

    Threadsafe.lock();
    {
        _ResultHandlers.erase(call);
    }
    Threadsafe.unlock();
}

uint64_t SteamCallback::RegisterCall()
{
    Threadsafe.lock();
    {
        _Calls[++_CallID] = false;
        DebugPrint(va("%s <%i>", __FUNCTION__, _CallID).c_str());
    }
    Threadsafe.unlock();
    return _CallID;
}
void SteamCallback::ReturnCall(void* data, int32_t size, int32_t type, uint64_t call)
{
    SteamAPIResult_t result;

    Threadsafe.lock();
    {
        _Calls[call] = true;
        result.Call = call;
        result.Data = data;
        result.Size = size;
        result.Type = type;

        DebugPrint(va("%s <%lli, %s>", __FUNCTION__, call, GetCallbackName(type)).c_str());
        _Results.push_back(result);
    }
    Threadsafe.unlock();
}
void SteamCallback::RunCallbacks()
{
    std::vector<SteamAPIResult_t>::iterator iter;

    Threadsafe.lock();
    {
        for (iter = _Results.begin(); iter != _Results.end(); ++iter)
        {
            if (_ResultHandlers.find(iter->Call) != _ResultHandlers.end())
            {
                _ResultHandlers[iter->Call]->Run(iter->Data, false, iter->Call);
            }

            std::vector<CallbackBase*>::iterator cbiter;

            for (cbiter = _Callbacks.begin(); cbiter < _Callbacks.end(); ++cbiter)
            {
                CallbackBase* cb = *cbiter;

                if (cb && cb->GetICallback() == iter->Type)
                {
                    cb->Run(iter->Data, false, 0);
                }
            }
        }

        _Results.clear();
    }
    Threadsafe.unlock();
}

bool SteamCallback::CallComplete(uint64_t call)
{
    bool Result = false;

    Threadsafe.lock();
    {
        if (_Calls.find(call) != _Calls.end())
            Result = _Calls.find(call)->second;
    }
    Threadsafe.unlock();

    return Result;
}

static std::unordered_map<uint32_t, char *> CallbackNames;
void BuildCallbackMap();
const char *SteamCallback::GetCallbackName(int32_t ID)
{
    static bool Initialized = false;
    if (!Initialized) BuildCallbackMap();
    Initialized = true;

#ifndef STEAM_PRINTCALLBACKS
    ID = 0;
#endif

    return CallbackNames[ID];
}
void BuildCallbackMap()
{
    CallbackNames[0] = "";

#ifdef STEAM_PRINTCALLBACKS

    CallbackNames[101] = "SteamServersConnected";
    CallbackNames[102] = "SteamServerConnectFailure";
    CallbackNames[103] = "SteamServersDisconnected";
    CallbackNames[104] = "BeginLogonRetry";
    CallbackNames[113] = "ClientGameServerDeny";
    CallbackNames[114] = "PrimaryChatDestinationSetOld";
    CallbackNames[115] = "GSPolicyResponse";
    CallbackNames[117] = "IPCFailure";
    CallbackNames[125] = "LicensesUpdated";
    CallbackNames[130] = "AppLifetimeNotice";
    CallbackNames[141] = "DRMSDKFileTransferResult";
    CallbackNames[143] = "ValidateAuthTicketResponse";
    CallbackNames[152] = "MicroTxnAuthorizationResponse";
    CallbackNames[154] = "EncryptedAppTicketResponse";
    CallbackNames[163] = "GetAuthSessionTicketResponse";
    CallbackNames[164] = "GameWebCallback";

    CallbackNames[201] = "GSClientApprove";
    CallbackNames[202] = "GSClientDeny";
    CallbackNames[203] = "GSClientKick";
    CallbackNames[204] = "GSClientSteam2Deny";
    CallbackNames[205] = "GSClientSteam2Accept";
    CallbackNames[206] = "GSClientAchievementStatus";
    CallbackNames[207] = "GSGameplayStats";
    CallbackNames[208] = "GSClientGroupStatus";
    CallbackNames[209] = "GSReputation";
    CallbackNames[210] = "AssociateWithClanResult";
    CallbackNames[211] = "ComputeNewPlayerCompatibilityResult";

    CallbackNames[304] = "PersonaStateChange";
    CallbackNames[331] = "GameOverlayActivated";
    CallbackNames[332] = "GameServerChangeRequested";
    CallbackNames[333] = "GameLobbyJoinRequested";
    CallbackNames[334] = "AvatarImageLoaded";
    CallbackNames[335] = "ClanOfficerListResponse";
    CallbackNames[336] = "FriendRichPresenceUpdate";
    CallbackNames[337] = "GameRichPresenceJoinRequested";
    CallbackNames[338] = "GameConnectedClanChatMsg";
    CallbackNames[339] = "GameConnectedChatJoin";
    CallbackNames[340] = "GameConnectedChatLeave";
    CallbackNames[341] = "DownloadClanActivityCountsResult";
    CallbackNames[342] = "JoinClanChatRoomCompletionResult";
    CallbackNames[343] = "GameConnectedFriendChatMsg";
    CallbackNames[344] = "FriendsGetFollowerCount";
    CallbackNames[345] = "FriendsIsFollowing";
    CallbackNames[346] = "FriendsEnumerateFollowingList";
    CallbackNames[347] = "SetPersonaNameResponse";

    CallbackNames[501] = "FavoritesListChangedOld";
    CallbackNames[502] = "FavoritesListChanged";
    CallbackNames[503] = "LobbyInvite";
    CallbackNames[504] = "LobbyEnter";
    CallbackNames[505] = "LobbyDataUpdate";
    CallbackNames[506] = "LobbyChatUpdate";
    CallbackNames[507] = "LobbyChatMsg";
    CallbackNames[508] = "LobbyAdminChange";
    CallbackNames[509] = "LobbyGameCreated";
    CallbackNames[510] = "LobbyMatchList";
    CallbackNames[511] = "LobbyClosing";
    CallbackNames[512] = "LobbyKicked";
    CallbackNames[513] = "LobbyCreated";
    CallbackNames[514] = "RequestFriendsLobbiesResponse";

    CallbackNames[701] = "IPCountry";
    CallbackNames[702] = "LowBatteryPower";
    CallbackNames[703] = "SteamAPICallCompleted";
    CallbackNames[704] = "SteamShutdown";
    CallbackNames[705] = "CheckFileSignature";
    CallbackNames[706] = "NetStartDialogFinished";
    CallbackNames[707] = "NetStartDialogUnloaded";
    CallbackNames[708] = "PS3SystemMenuClosed";
    CallbackNames[709] = "PS3NPMessageSelected";
    CallbackNames[710] = "PS3KeyboardDialogFinished";
    CallbackNames[711] = "SteamConfigStoreChanged";
    CallbackNames[712] = "PS3PSNStatusChange";
    CallbackNames[713] = "SteamUtils_Reserved";
    CallbackNames[714] = "GamepadTextInputDismissed";
    CallbackNames[715] = "SteamUtils_Reserved";

    CallbackNames[805] = "FriendChatMsg";
    CallbackNames[810] = "ChatRoomMsg";
    CallbackNames[811] = "ChatRoomDlgClose";
    CallbackNames[812] = "ChatRoomClosing";
    CallbackNames[819] = "ClanInfoChanged";
    CallbackNames[836] = "FriendsMenuChange";

    CallbackNames[903] = "PrimaryChatDestinationSet";
    CallbackNames[963] = "FriendMessageHistoryChatLog";

    CallbackNames[1001] = "AppDataChanged";
    CallbackNames[1002] = "RequestAppCallbacksComplete";
    CallbackNames[1003] = "AppInfoUpdateComplete";
    CallbackNames[1004] = "AppEventTriggered";
    CallbackNames[1005] = "DlcInstalled";
    CallbackNames[1006] = "AppEventStateChange";

    CallbackNames[1101] = "UserStatsReceived";
    CallbackNames[1102] = "UserStatsStored";
    CallbackNames[1103] = "UserAchievementStored";

    CallbackNames[1201] = "SocketStatusChanged";
    CallbackNames[1202] = "P2PSessionRequest";
    CallbackNames[1203] = "P2PSessionConnectFail";

    CallbackNames[1603] = "CellIDChanged";

    /*
        TODO(Convery):
        Add the billions of callbacks.
        I do not think this is a great use of our time.
        As such, we request that developers add the ones used
        by the game they are developing for and open a pull.
    */
#endif
}
