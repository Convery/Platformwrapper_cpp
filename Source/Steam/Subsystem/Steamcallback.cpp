/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 06-08-2017
    License: MIT
    Notes:
        Implements steams async requests.
        We generally return directly though.
*/

#include "../../Stdinclude.hpp"

namespace Steamcallback
{
    std::unordered_map<uint64_t /* RequestID */, Valvecallback *> Activerequests;
    std::unordered_map<uint64_t /* RequestID */, bool> Requeststatus;
    std::vector<Valvecallback *> Callbackhandlers;
    std::atomic<uint64_t> GlobalrequestID;
    std::vector<Result_t> Requestresults;
    std::mutex Threadguard;

    // Add a games callback and result to the internal mapping.
    void Registercallback(Valvecallback *Callbackhandler, int32_t CallbackID)
    {
        Debugprint(va("Registering callback \"%s\".", Callbackname(CallbackID).c_str()));

        Callbackhandler->SetICallback(CallbackID);
        Callbackhandlers.push_back(Callbackhandler);
    }
    void Registerresult(Valvecallback *Callbackhandler, uint64_t RequestID)
    {
        Debugprint(va("Registering result for RequestID 0x%llx (\"%s\").", RequestID, Callbackname(Callbackhandler->GetICallback()).c_str()));
        Activerequests[RequestID] = Callbackhandler;
    }
    void Markcallbackactive(int32_t CallbackID, uint64_t RequestID)
    {
        Threadguard.lock();
        {
            for (auto &Item : Callbackhandlers)
            {
                if (Item->GetICallback() == CallbackID)
                {
                    Activerequests[RequestID] = Item;
                }
            }
        }
        Threadguard.unlock();
    }

    // Remove a games callback and result from the internal mapping.
    void Removecallback(Valvecallback *Callbackhandler, int32_t CallbackID)
    {
        Debugprint(va("Removing callback \"%s\".", Callbackname(CallbackID).c_str()));

        for (auto Iterator = Callbackhandlers.begin(); Iterator != Callbackhandlers.end(); ++Iterator)
        {
            if (*Iterator == Callbackhandler)
            {
                Callbackhandlers.erase(Iterator);
                break;
            }
        }
    }
    void Removeresult(Valvecallback *Callbackhandler, uint64_t RequestID)
    {
        Debugprint(va("Removing result for RequestID 0x%llx (\"%s\").", RequestID, Callbackname(Callbackhandler->GetICallback()).c_str()));
        Activerequests.erase(RequestID);
    }

    // Create and complete the requests.
    void Completerequest(Result_t Result)
    {
        Threadguard.lock();
        {
            Requestresults.push_back(Result);
            Requeststatus[Result.RequestID] = true;
            Debugprint(va("Request with ID 0x%llx completed.", Result.RequestID));
        }
        Threadguard.unlock();
    }
    uint64_t Createrequest()
    {
        // We start off at 1 since 0 gets treated as an error by some games.
        auto ID = ++GlobalrequestID;

        Debugprint(va("Request with ID 0x%llx created.", ID));
        Requeststatus[ID] = false;
        return ID;
    }

    // Call all callbacks, usually every frame.
    void Runcallbacks()
    {
        Threadguard.lock();
        {
            // For all our results.
            LABEL_RESTART:
            for (auto Resultiterator = Requestresults.begin(); Resultiterator != Requestresults.end(); ++Resultiterator)
            {
                // Delay the result if the request is not synchronized yet.
                if (!Requeststatus[Resultiterator->RequestID]) continue;

                // Get the games callback if available.
                auto Callback = Activerequests.find(Resultiterator->RequestID);
                if (Callback == Activerequests.end()) continue;

                // Pass the result to the game.
                Callback->second->Run(Resultiterator->Databuffer, false, Resultiterator->RequestID);

                // Remove the result from the list.
                Requestresults.erase(Resultiterator);
                goto LABEL_RESTART;
            }
        }
        Threadguard.unlock();
    }

    // Check the status of a request.
    bool isRequestcomplete(uint64_t RequestID)
    {
        auto Status = Requeststatus.find(RequestID);
        if (Status == Requeststatus.end()) return false;
        return Status->second;
    }

    // Debug information.
    void Buildnamemap();
    std::unordered_map<int32_t, std::string> Callbacknames;
    std::string Callbackname(int32_t CallbackID)
    {
        static bool Initialized = false;
        if(!Initialized) Buildnamemap();
        Initialized = true;

        #if defined (STEAM_PRINTCALLBACKS)
        return Callbacknames[CallbackID];
        #else
        return va("%d", CallbackID);
        #endif
    }

    void Buildnamemap()
    {
        // Set the first entry for legacy functionality.
        Callbacknames[0] = "";

        #if defined (STEAM_PRINTCALLBACKS)
        Callbacknames[100] = "Base::Steamuser";
        Callbacknames[101] = "SteamServersConnected";
        Callbacknames[102] = "SteamServerConnectFailure";
        Callbacknames[103] = "SteamServersDisconnected";
        Callbacknames[104] = "BeginLogonRetry";
        Callbacknames[113] = "ClientGameServerDeny";
        Callbacknames[114] = "PrimaryChatDestinationSetOld";
        Callbacknames[115] = "GSPolicyResponse";
        Callbacknames[117] = "IPCFailure";
        Callbacknames[125] = "LicensesUpdated";
        Callbacknames[130] = "AppLifetimeNotice";
        Callbacknames[141] = "DRMSDKFileTransferResult";
        Callbacknames[143] = "ValidateAuthTicketResponse";
        Callbacknames[152] = "MicroTxnAuthorizationResponse";
        Callbacknames[154] = "EncryptedAppTicketResponse";
        Callbacknames[163] = "GetAuthSessionTicketResponse";
        Callbacknames[164] = "GameWebCallback";

        Callbacknames[200] = "Base::Steamgameserver";
        Callbacknames[201] = "GSClientApprove";
        Callbacknames[202] = "GSClientDeny";
        Callbacknames[203] = "GSClientKick";
        Callbacknames[204] = "GSClientSteam2Deny";
        Callbacknames[205] = "GSClientSteam2Accept";
        Callbacknames[206] = "GSClientAchievementStatus";
        Callbacknames[207] = "GSGameplayStats";
        Callbacknames[208] = "GSClientGroupStatus";
        Callbacknames[209] = "GSReputation";
        Callbacknames[210] = "AssociateWithClanResult";
        Callbacknames[211] = "ComputeNewPlayerCompatibilityResult";

        Callbacknames[300] = "Base::Steamfriends";
        Callbacknames[304] = "PersonaStateChange";
        Callbacknames[331] = "GameOverlayActivated";
        Callbacknames[332] = "GameServerChangeRequested";
        Callbacknames[333] = "GameLobbyJoinRequested";
        Callbacknames[334] = "AvatarImageLoaded";
        Callbacknames[335] = "ClanOfficerListResponse";
        Callbacknames[336] = "FriendRichPresenceUpdate";
        Callbacknames[337] = "GameRichPresenceJoinRequested";
        Callbacknames[338] = "GameConnectedClanChatMsg";
        Callbacknames[339] = "GameConnectedChatJoin";
        Callbacknames[340] = "GameConnectedChatLeave";
        Callbacknames[341] = "DownloadClanActivityCountsResult";
        Callbacknames[342] = "JoinClanChatRoomCompletionResult";
        Callbacknames[343] = "GameConnectedFriendChatMsg";
        Callbacknames[344] = "FriendsGetFollowerCount";
        Callbacknames[345] = "FriendsIsFollowing";
        Callbacknames[346] = "FriendsEnumerateFollowingList";
        Callbacknames[347] = "SetPersonaNameResponse";

        Callbacknames[400] = "Base::Steambilling";

        Callbacknames[500] = "Base::Steammatchmaking";
        Callbacknames[501] = "FavoritesListChangedOld";
        Callbacknames[502] = "FavoritesListChanged";
        Callbacknames[503] = "LobbyInvite";
        Callbacknames[504] = "LobbyEnter";
        Callbacknames[505] = "LobbyDataUpdate";
        Callbacknames[506] = "LobbyChatUpdate";
        Callbacknames[507] = "LobbyChatMsg";
        Callbacknames[508] = "LobbyAdminChange";
        Callbacknames[509] = "LobbyGameCreated";
        Callbacknames[510] = "LobbyMatchList";
        Callbacknames[511] = "LobbyClosing";
        Callbacknames[512] = "LobbyKicked";
        Callbacknames[513] = "LobbyCreated";
        Callbacknames[514] = "RequestFriendsLobbiesResponse";

        Callbacknames[600] = "Base::Steamcontent";

        Callbacknames[700] = "Base::Steamutilities";
        Callbacknames[701] = "IPCountry";
        Callbacknames[702] = "LowBatteryPower";
        Callbacknames[703] = "SteamAPICallCompleted";
        Callbacknames[704] = "SteamShutdown";
        Callbacknames[705] = "CheckFileSignature";
        Callbacknames[706] = "NetStartDialogFinished";
        Callbacknames[707] = "NetStartDialogUnloaded";
        Callbacknames[708] = "PS3SystemMenuClosed";
        Callbacknames[709] = "PS3NPMessageSelected";
        Callbacknames[710] = "PS3KeyboardDialogFinished";
        Callbacknames[711] = "SteamConfigStoreChanged";
        Callbacknames[712] = "PS3PSNStatusChange";
        Callbacknames[713] = "SteamUtils_Reserved";
        Callbacknames[714] = "GamepadTextInputDismissed";
        Callbacknames[715] = "SteamUtils_Reserved";

        Callbacknames[800] = "Base::Clientfriends";
        Callbacknames[805] = "FriendChatMsg";
        Callbacknames[810] = "ChatRoomMsg";
        Callbacknames[811] = "ChatRoomDlgClose";
        Callbacknames[812] = "ChatRoomClosing";
        Callbacknames[819] = "ClanInfoChanged";
        Callbacknames[836] = "FriendsMenuChange";

        Callbacknames[900] = "Base::Clientuser";
        Callbacknames[903] = "PrimaryChatDestinationSet";
        Callbacknames[963] = "FriendMessageHistoryChatLog";

        Callbacknames[1000] = "Base::Steamapps";
        Callbacknames[1001] = "AppDataChanged";
        Callbacknames[1002] = "RequestAppCallbacksComplete";
        Callbacknames[1003] = "AppInfoUpdateComplete";
        Callbacknames[1004] = "AppEventTriggered";
        Callbacknames[1005] = "DlcInstalled";
        Callbacknames[1006] = "AppEventStateChange";

        Callbacknames[1100] = "Base::Steamuserstats";
        Callbacknames[1101] = "UserStatsReceived";
        Callbacknames[1102] = "UserStatsStored";
        Callbacknames[1103] = "UserAchievementStored";

        Callbacknames[1200] = "Base::Steamnetworking";
        Callbacknames[1201] = "SocketStatusChanged";
        Callbacknames[1202] = "P2PSessionRequest";
        Callbacknames[1203] = "P2PSessionConnectFail";

        Callbacknames[1300] = "Base::Clientremotestorage";
        Callbacknames[1317] = "RemoteStorageDownloadUGCResult";

        Callbacknames[1400] = "Base::Steamuseritems";

        Callbacknames[1500] = "Base::Steamgameserveritems";

        Callbacknames[1600] = "Base::Clientutilities";
        Callbacknames[1603] = "CellIDChanged";

        Callbacknames[1700] = "Base::Steamgamecoordinator";

        Callbacknames[1800] = "Base::Steamgameserverstats";

        Callbacknames[1900] = "Base::Steam2Async";

        Callbacknames[2000] = "Base::Steamgamestats";

        Callbacknames[2100] = "Base::ClientHTTP";

        Callbacknames[2200] = "Base::Clientscreenshots";

        Callbacknames[2300] = "Base::Steamscreenshots";

        Callbacknames[2400] = "Base::Clientaudio";

        Callbacknames[2500] = "Base::Steamunifiedmessages";

        Callbacknames[2600] = "Base::Clientunifiedmessages";

        Callbacknames[2700] = "Base::Clientcontroller";

        Callbacknames[2800] = "Base::Steamcontroller";

        Callbacknames[2900] = "Base::Clientparentalsettings";

        Callbacknames[3000] = "Base::Clientdeviceauthentication";

        Callbacknames[3100] = "Base::Clientnetworkdevicemanager";

        Callbacknames[3200] = "Base::Clientmusic";

        Callbacknames[3300] = "Base::Clientremoteclientmanager";

        Callbacknames[3400] = "Base::ClientUGC";

        Callbacknames[3500] = "Base::Steamstreamclient";

        Callbacknames[3600] = "Base::Clientproductbuilder";

        Callbacknames[3700] = "Base::Clientshortcuts";

        Callbacknames[3800] = "Base::Clientremotecontrolmanager";

        Callbacknames[3900] = "Base::Steamapplist";

        Callbacknames[4000] = "Base::Steammusic";

        Callbacknames[4100] = "Base::Steammusicremote";

        Callbacknames[4200] = "Base::ClientVR";

        Callbacknames[4300] = "Base::Clientreserved";

        Callbacknames[4400] = "Base::Steamreserved";

        Callbacknames[4500] = "Base::SteamHTML";

        Callbacknames[4600] = "Base::Clientvideo";

        Callbacknames[4700] = "Base::Clientinventory";
        #endif

        /*
            TODO(Convery):
            There is about a million names for the callbacks.
            I do not think it's a good use of my time to add them.
            Please add the ones your game uses and open a pull request.
        */
    }
}
