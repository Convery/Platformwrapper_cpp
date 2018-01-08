/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam social information.
*/

#include "../../Stdinclude.hpp"

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;
#define Createinterface(Enum, Class)            \
static Class DEV ## Class;                      \
Interfacemanager::Addinterface(Enum, #Class, &DEV ## Class);

// A cache of friends and their status.
struct Steamfriend_t
{
    std::string Username;
    uint64_t UserID;
    bool Online;
};
std::vector<Steamfriend_t> Friendslist;

// Update the cache as requested.
void Loadfriends()
{
    std::string JSONBuffer;
    Friendslist.clear();

    // Offlinemode reads from disk.
    if (Steamconfig::Offline)
    {
        JSONBuffer = Package::Read("Steamfriends.json");
    }
    else
    {
        JSONBuffer = Readpipe("ayria://getfriends");
    }

    try
    {
        auto Parsed = nlohmann::json::parse(JSONBuffer.c_str());

        for (auto &Item : Parsed["Steamfriends"])
        {
            Friendslist.push_back({ Item["Username"], Item["UserID"], false });
        }
    }
    catch (...) {};
}
void Savefriends()
{
    nlohmann::json Object;

    for (auto &Item : Friendslist)
    {
        Object["Steamfriends"] += { { "Username", Item.Username}, { "UserID", Item.UserID } };
    }

    Package::Write("Steamfriends.json", Object.dump(4));
}

#pragma region Methods
class SteamFriends
{
public:
    const char *GetPersonaName()
    {
        return Steamconfig::Username;
    }
    void SetPersonaName0(const char *pchPersonaName)
    {
        Printfunction();
        std::strcpy(Steamconfig::Username, pchPersonaName);
    }
    uint32_t GetPersonaState()
    {
        Printfunction();
        return 0;
    }
    void SetPersonaState(uint32_t ePersonaState)
    {
        Printfunction();
    }
    bool AddFriend(CSteamID steamIDFriend)
    {
        Printfunction();

        if (Writepipe("ayria://addfriend", nlohmann::json({ "Steamfriend", { "UserID", steamIDFriend.ConvertToUint64() } }).dump(4)))
        {
            Loadfriends();
            return true;
        }

        Friendslist.push_back({ "Unknown player", steamIDFriend.ConvertToUint64(), false });
        Savefriends();
        return true;
    }
    bool RemoveFriend(CSteamID steamIDFriend)
    {
        Printfunction();

        if (Writepipe("ayria://removefriend", nlohmann::json({ "Steamfriend", { "UserID", steamIDFriend.ConvertToUint64() } }).dump(4)))
        {
            Loadfriends();
            return true;
        }

        for (auto Iterator = Friendslist.begin(); Iterator != Friendslist.end(); ++Iterator)
        {
            if (Iterator->UserID == steamIDFriend.ConvertToUint64())
            {
                Friendslist.erase(Iterator);
                break;
            }
        }

        return true;
    }
    bool HasFriend0(CSteamID steamIDFriend)
    {
        Printfunction();

        for (auto Iterator = Friendslist.begin(); Iterator != Friendslist.end(); ++Iterator)
        {
            if (Iterator->UserID == steamIDFriend.ConvertToUint64())
            {
                return true;
            }
        }

        return false;
    }
    uint32_t GetFriendRelationship(CSteamID steamIDFriend)
    {
        Printfunction();

        for (auto Iterator = Friendslist.begin(); Iterator != Friendslist.end(); ++Iterator)
        {
            if (Iterator->UserID == steamIDFriend.ConvertToUint64())
            {
                // EFriendRelationship::Friend
                return 3;
            }
        }

        return 0;
    }
    uint32_t GetFriendPersonaState(CSteamID steamIDFriend)
    {
        Printfunction();

        for (auto Iterator = Friendslist.begin(); Iterator != Friendslist.end(); ++Iterator)
        {
            if (Iterator->UserID == steamIDFriend.ConvertToUint64())
            {
                if (Iterator->Online) return 1;
                else return 0;
            }
        }

        // EPersonaState::Offline
        return 0;
    }
    bool Deprecated_GetFriendGamePlayed(CSteamID steamIDFriend, int32_t *pnGameID, uint32_t *punGameIP, uint16_t *pusGamePort)
    {
        Printfunction();
        return false;
    }
    const char *GetFriendPersonaName(CSteamID steamIDFriend)
    {
        Printfunction();
        for (auto Iterator = Friendslist.begin(); Iterator != Friendslist.end(); ++Iterator)
        {
            if (Iterator->UserID == steamIDFriend.ConvertToUint64())
            {
                return Iterator->Username.c_str();
            }
        }

        return "Unknown player";
    }
    uint32_t AddFriendByName(const char *pchEmailOrAccountName)
    {
        Printfunction();

        if (Writepipe("ayria://addfriend", nlohmann::json({ "Steamfriend", { "Username", pchEmailOrAccountName} }).dump(4)))
        {
            Loadfriends();
            return 1;
        }

        Friendslist.push_back({ pchEmailOrAccountName, 0, false });
        Savefriends();
        return 1;
    }
    int GetFriendCount0()
    {
        return (int)Friendslist.size();
    }
    CSteamID GetFriendByIndex0(int iFriend)
    {
        Printfunction();
        return CSteamID(Friendslist[iFriend].UserID);
    }
    void SendMsgToFriend0(CSteamID steamIDFriend, uint32_t eFriendMsgType, const char *pchMsgBody)
    {
        Printfunction();
    }
    void SetFriendRegValue(CSteamID steamIDFriend, const char *pchKey, const char *pchValue)
    {
        Printfunction();
    }
    const char *GetFriendRegValue(CSteamID steamIDFriend, const char *pchKey)
    {
        Printfunction();
        return "";
    }
    const char *GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPersonaName)
    {
        Printfunction();
        return "";
    }
    int GetChatMessage(CSteamID steamIDFriend, int iChatID, void *pvData, int cubData, uint32_t *peFriendMsgType)
    {
        Printfunction();
        return 0;
    }
    bool SendMsgToFriend1(CSteamID steamIDFriend, uint32_t eFriendMsgType, const void *pvMsgBody, int cubMsgBody)
    {
        Printfunction();
        return false;
    }
    int GetChatIDOfChatHistoryStart(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    void SetChatHistoryStart(CSteamID steamIDFriend, int iChatID)
    {
        Printfunction();
    }
    void ClearChatHistory(CSteamID steamIDFriend)
    {
        Printfunction();
    }
    uint32_t InviteFriendByEmail0(const char *pchEmailOrAccountName)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetBlockedFriendCount()
    {
        Printfunction();
        return 0;
    }
    bool GetFriendGamePlayed0(CSteamID steamIDFriend, uint64_t *pulGameID, uint32_t *punGameIP, uint16_t *pusGamePort)
    {
        Printfunction();
        return false;
    }
    bool GetFriendGamePlayed2(CSteamID steamDIFriend, uint64_t *pulGameID, uint32_t *punGameIP, uint16_t *pusGamePort, uint16_t *pusQueryPort)
    {
        Printfunction();
        return false;
    }
    int GetFriendCount1(uint32_t iFriendFlags)
    {
        return (int)Friendslist.size();
    }
    CSteamID GetFriendByIndex1(int iFriend, uint32_t iFriendFlags)
    {
        Printfunction();
        return CSteamID(Friendslist[iFriend].UserID);
    }
    bool GetFriendGamePlayed1(CSteamID steamIDFriend, uint64_t *pulGameID, uint32_t *punGameIP, uint16_t *pusGamePort, uint16_t *pusQueryPort)
    {
        Printfunction();
        return false;
    }
    bool HasFriend1(CSteamID steamIDFriend, uint32_t iFriendFlags)
    {
        Printfunction();

        for (auto Iterator = Friendslist.begin(); Iterator != Friendslist.end(); ++Iterator)
        {
            if (Iterator->UserID == steamIDFriend.ConvertToUint64())
            {
                return true;
            }
        }

        return false;
    }
    bool InviteFriendByEmail1(const char *emailAddr)
    {
        Printfunction();
        return false;
    }
    int GetClanCount()
    {
        Printfunction();
        return 0;
    }
    CSteamID GetClanByIndex(int iClan)
    {
        Printfunction();
        return CSteamID(Steamconfig::UserID);
    }
    const char *GetClanName(CSteamID steamIDClan)
    {
        Printfunction();
        return "AYA";
    }
    bool InviteFriendToClan(CSteamID steamIDfriend, CSteamID steamIDclan)
    {
        Printfunction();
        return false;
    }
    bool AcknowledgeInviteToClan(CSteamID steamID, bool)
    {
        Printfunction();
        return false;
    }
    int GetFriendCountFromSource(CSteamID steamIDSource)
    {
        return 0;
    }
    CSteamID GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend)
    {
        Printfunction();
        return CSteamID(Friendslist[iFriend].UserID);
    }
    int GetFriendAvatar0(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    bool IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource)
    {
        Printfunction();
        return false;
    }
    void SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking)
    {
        Printfunction();
    }
    void ActivateGameOverlay(const char *pchDialog)
    {
        Printfunction();
    }
    int GetFriendAvatar1(CSteamID steamIDFriend, int eAvatarSize)
    {
        Printfunction();
        return 0;
    }
    CSteamID GetFriendByIndex2(int iFriend, int iFriendFlags)
    {
        Printfunction();
        return CSteamID(Friendslist[iFriend].UserID);
    }
    bool GetFriendGamePlayed3(CSteamID steamIDFriend, struct FriendGameInfo_t *pFriendGameInfo)
    {
        Printfunction();
        return false;
    }
    void ActivateGameOverlayToUser(const char *pchDialog, CSteamID steamID)
    {
        Printfunction();
    }
    void ActivateGameOverlayToWebPage(const char *pchURL)
    {
        Printfunction();
    }
    void ActivateGameOverlayToStore0(uint32_t nAppID)
    {
        Printfunction();
    }
    void SetPlayedWith(CSteamID steamIDUserPlayedWith)
    {
        Printfunction();
    }
    const char *GetClanTag(CSteamID steamIDClan)
    {
        Printfunction();
        return "AYA";
    }
    void ActivateGameOverlayInviteDialog(CSteamID steamIDLobby)
    {
        Printfunction();
    }
    int GetSmallFriendAvatar(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    int GetMediumFriendAvatar(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    int GetLargeFriendAvatar(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    bool RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly)
    {
        Printfunction();
        return false;
    }
    uint64_t RequestClanOfficerList(CSteamID steamIDClan)
    {
        Printfunction();
        return 0;
    }
    CSteamID GetClanOwner(CSteamID steamIDClan)
    {
        Printfunction();
        return CSteamID(Steamconfig::UserID);
    }
    int GetClanOfficerCount(CSteamID steamIDClan)
    {
        Printfunction();
        return 0;
    }
    CSteamID GetClanOfficerByIndex(CSteamID steamIDClan, int iOfficer)
    {
        Printfunction();
        return CSteamID(Steamconfig::UserID);
    }
    uint32_t GetUserRestrictions()
    {
        Printfunction();
        return 0;
    }
    int GetFriendCount2(int iFriendFlags)
    {
        Printfunction();
        return 0;
    }
    bool HasFriend2(CSteamID steamIDFriend, int iFriendFlags)
    {
        Printfunction();
        return false;
    }
    bool SetRichPresence(const char *pchKey, const char *pchValue)
    {
        return true;
    }
    void ClearRichPresence()
    {
        Printfunction();
    }
    const char *GetFriendRichPresence(CSteamID steamIDFriend, const char *pchKey)
    {
        Printfunction();
        return "";
    }
    int GetFriendRichPresenceKeyCount(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    const char *GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey)
    {
        Printfunction();
        return "";
    }
    bool InviteUserToGame(CSteamID steamIDFriend, const char *pchConnectString)
    {
        Printfunction();
        return false;
    }
    int GetCoplayFriendCount()
    {
        Printfunction();
        return 0;
    }
    CSteamID GetCoplayFriend(int iCoplayFriend)
    {
        Printfunction();
        return CSteamID(Friendslist[iCoplayFriend].UserID);
    }
    int GetFriendCoplayTime(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetFriendCoplayGame(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    bool GetClanActivityCounts(CSteamID steamID, int *pnOnline, int *pnInGame, int *pnChatting)
    {
        Printfunction();
        return false;
    }
    uint64_t DownloadClanActivityCounts(CSteamID groupIDs[], int nIds)
    {
        Printfunction();
        return 0;
    }
    uint64_t JoinClanChatRoom(CSteamID groupID)
    {
        Printfunction();
        return 0;
    }
    bool LeaveClanChatRoom(CSteamID groupID)
    {
        Printfunction();
        return false;
    }
    int GetClanChatMemberCount(CSteamID groupID)
    {
        Printfunction();
        return 0;
    }
    CSteamID GetChatMemberByIndex(CSteamID groupID, int iIndex)
    {
        Printfunction();
        return CSteamID(uint64_t(0));
    }
    bool SendClanChatMessage(CSteamID groupID, const char *cszMessage)
    {
        Printfunction();
        return false;
    }
    int GetClanChatMessage(CSteamID groupID, int iChatID, void *pvData, int cubData, uint32_t *peChatEntryType, CSteamID *pSteamIDChatter)
    {
        Printfunction();
        return 0;
    }
    bool IsClanChatAdmin(CSteamID groupID, CSteamID userID)
    {
        Printfunction();
        return false;
    }
    bool IsClanChatWindowOpenInSteam(CSteamID groupID)
    {
        Printfunction();
        return false;
    }
    bool OpenClanChatWindowInSteam(CSteamID groupID)
    {
        Printfunction();
        return false;
    }
    bool CloseClanChatWindowInSteam(CSteamID groupID)
    {
        Printfunction();
        return false;
    }
    bool SetListenForFriendsMessages(bool bListen)
    {
        Printfunction();
        return false;
    }
    bool ReplyToFriendMessage(CSteamID friendID, const char *cszMessage)
    {
        Printfunction();
        return false;
    }
    int GetFriendMessage(CSteamID friendID, int iChatID, void *pvData, int cubData, uint32_t *peChatEntryType)
    {
        Printfunction();
        return 0;
    }
    void RequestFriendRichPresence(CSteamID steamIDFriend)
    {
        Printfunction();
        return;
    }
    uint64_t GetFollowerCount(CSteamID steamID)
    {
        Printfunction();
        return 0;
    }
    uint64_t IsFollowing(CSteamID steamID)
    {
        Printfunction();
        return 0;
    }
    uint64_t EnumerateFollowingList(uint32_t unStartIndex)
    {
        Printfunction();
        return 0;
    }
    uint64_t SetPersonaName1(const char *pchPersonaName)
    {
        Printfunction();
        return 0;
    }
    void ActivateGameOverlayToStore1(uint32_t nAppID, uint32_t eFlag)
    {
        Printfunction();
        return;
    }
    const char *GetPlayerNickname(CSteamID steamIDPlayer)
    {
        Printfunction();
        return "AYA";
    }
    uint64_t SetPersonaName2(const char *pchPersonaName)
    {
        Printfunction();
        std::strcpy(Steamconfig::Username, pchPersonaName);
        return 0;
    }
    int GetFriendSteamLevel(CSteamID steamIDFriend)
    {
        Printfunction();
        return 0;
    }
    int16_t GetFriendsGroupCount()
    {
        Printfunction();
        return 0;
    }
    int16_t GetFriendsGroupIDByIndex(int32_t)
    {
        Printfunction();
        return 0;
    }
    const char *GetFriendsGroupName(int16_t)
    {
        Printfunction();
        return "";
    }
    int GetFriendsGroupMembersCount(int16_t)
    {
        Printfunction();
        return 0;
    }
    int GetFriendsGroupMembersList(int16_t, CSteamID *, int32_t)
    {
        Printfunction();
        return 0;
    }
};
#pragma endregion

SteamFriends001::SteamFriends001()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, SetPersonaState);
    Createmethod(4, SteamFriends, AddFriend);
    Createmethod(5, SteamFriends, RemoveFriend);
    Createmethod(6, SteamFriends, HasFriend0);
    Createmethod(7, SteamFriends, GetFriendRelationship);
    Createmethod(8, SteamFriends, GetFriendPersonaState);
    Createmethod(9, SteamFriends, Deprecated_GetFriendGamePlayed);
    Createmethod(10, SteamFriends, GetFriendPersonaName);
    Createmethod(11, SteamFriends, AddFriendByName);
    Createmethod(12, SteamFriends, GetFriendCount0);
    Createmethod(13, SteamFriends, GetFriendByIndex0);
    Createmethod(14, SteamFriends, SendMsgToFriend0);
    Createmethod(15, SteamFriends, SetFriendRegValue);
    Createmethod(16, SteamFriends, GetFriendRegValue);
    Createmethod(17, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(18, SteamFriends, GetChatMessage);
    Createmethod(19, SteamFriends, SendMsgToFriend1);
    Createmethod(20, SteamFriends, GetChatIDOfChatHistoryStart);
    Createmethod(21, SteamFriends, SetChatHistoryStart);
    Createmethod(22, SteamFriends, ClearChatHistory);
    Createmethod(23, SteamFriends, InviteFriendByEmail0);
    Createmethod(24, SteamFriends, GetBlockedFriendCount);
    Createmethod(25, SteamFriends, GetFriendGamePlayed0);
    Createmethod(26, SteamFriends, GetFriendGamePlayed2);
};
SteamFriends002::SteamFriends002()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, SetPersonaState);
    Createmethod(4, SteamFriends, GetFriendCount1);
    Createmethod(5, SteamFriends, GetFriendByIndex1);
    Createmethod(6, SteamFriends, GetFriendRelationship);
    Createmethod(7, SteamFriends, GetFriendPersonaState);
    Createmethod(8, SteamFriends, GetFriendPersonaName);
    Createmethod(9, SteamFriends, SetFriendRegValue);
    Createmethod(10, SteamFriends, GetFriendRegValue);
    Createmethod(11, SteamFriends, GetFriendGamePlayed1);
    Createmethod(12, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(13, SteamFriends, AddFriend);
    Createmethod(14, SteamFriends, RemoveFriend);
    Createmethod(15, SteamFriends, HasFriend1);
    Createmethod(16, SteamFriends, AddFriendByName);
    Createmethod(17, SteamFriends, InviteFriendByEmail1);
    Createmethod(18, SteamFriends, GetChatMessage);
    Createmethod(19, SteamFriends, SendMsgToFriend1);
    Createmethod(20, SteamFriends, GetChatIDOfChatHistoryStart);
    Createmethod(21, SteamFriends, SetChatHistoryStart);
    Createmethod(22, SteamFriends, ClearChatHistory);
    Createmethod(23, SteamFriends, GetClanCount);
    Createmethod(24, SteamFriends, GetClanByIndex);
    Createmethod(25, SteamFriends, GetClanName);
    Createmethod(26, SteamFriends, InviteFriendToClan);
    Createmethod(27, SteamFriends, AcknowledgeInviteToClan);
    Createmethod(28, SteamFriends, GetFriendCountFromSource);
    Createmethod(29, SteamFriends, GetFriendFromSourceByIndex);
};
SteamFriends003::SteamFriends003()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendAvatar0);
    Createmethod(9, SteamFriends, GetFriendGamePlayed1);
    Createmethod(10, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(11, SteamFriends, HasFriend1);
    Createmethod(12, SteamFriends, GetClanCount);
    Createmethod(13, SteamFriends, GetClanByIndex);
    Createmethod(14, SteamFriends, GetClanName);
    Createmethod(15, SteamFriends, GetFriendCountFromSource);
    Createmethod(16, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(17, SteamFriends, IsUserInSource);
    Createmethod(18, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(19, SteamFriends, ActivateGameOverlay);
};
SteamFriends004::SteamFriends004()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendAvatar1);
    Createmethod(9, SteamFriends, GetFriendGamePlayed1);
    Createmethod(10, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(11, SteamFriends, HasFriend1);
    Createmethod(12, SteamFriends, GetClanCount);
    Createmethod(13, SteamFriends, GetClanByIndex);
    Createmethod(14, SteamFriends, GetClanName);
    Createmethod(15, SteamFriends, GetFriendCountFromSource);
    Createmethod(16, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(17, SteamFriends, IsUserInSource);
    Createmethod(18, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(19, SteamFriends, ActivateGameOverlay);
};
SteamFriends005::SteamFriends005()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendAvatar1);
    Createmethod(9, SteamFriends, GetFriendGamePlayed3);
    Createmethod(10, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(11, SteamFriends, HasFriend1);
    Createmethod(12, SteamFriends, GetClanCount);
    Createmethod(13, SteamFriends, GetClanByIndex);
    Createmethod(14, SteamFriends, GetClanName);
    Createmethod(15, SteamFriends, GetFriendCountFromSource);
    Createmethod(16, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(17, SteamFriends, IsUserInSource);
    Createmethod(18, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(19, SteamFriends, ActivateGameOverlay);
    Createmethod(20, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(21, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(22, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(23, SteamFriends, SetPlayedWith);
};
SteamFriends006::SteamFriends006()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendAvatar1);
    Createmethod(9, SteamFriends, GetFriendGamePlayed3);
    Createmethod(10, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(11, SteamFriends, HasFriend1);
    Createmethod(12, SteamFriends, GetClanCount);
    Createmethod(13, SteamFriends, GetClanByIndex);
    Createmethod(14, SteamFriends, GetClanName);
    Createmethod(15, SteamFriends, GetClanTag);
    Createmethod(16, SteamFriends, GetFriendCountFromSource);
    Createmethod(17, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(18, SteamFriends, IsUserInSource);
    Createmethod(19, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(20, SteamFriends, ActivateGameOverlay);
    Createmethod(21, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(22, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(23, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(24, SteamFriends, SetPlayedWith);
    Createmethod(25, SteamFriends, ActivateGameOverlayInviteDialog);
};
SteamFriends007::SteamFriends007()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, HasFriend1);
    Createmethod(11, SteamFriends, GetClanCount);
    Createmethod(12, SteamFriends, GetClanByIndex);
    Createmethod(13, SteamFriends, GetClanName);
    Createmethod(14, SteamFriends, GetClanTag);
    Createmethod(15, SteamFriends, GetFriendCountFromSource);
    Createmethod(16, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(17, SteamFriends, IsUserInSource);
    Createmethod(18, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(19, SteamFriends, ActivateGameOverlay);
    Createmethod(20, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(21, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(22, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(23, SteamFriends, SetPlayedWith);
    Createmethod(24, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(25, SteamFriends, GetSmallFriendAvatar);
    Createmethod(26, SteamFriends, GetMediumFriendAvatar);
    Createmethod(27, SteamFriends, GetLargeFriendAvatar);
};
SteamFriends008::SteamFriends008()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, HasFriend1);
    Createmethod(11, SteamFriends, GetClanCount);
    Createmethod(12, SteamFriends, GetClanByIndex);
    Createmethod(13, SteamFriends, GetClanName);
    Createmethod(14, SteamFriends, GetClanTag);
    Createmethod(15, SteamFriends, GetFriendCountFromSource);
    Createmethod(16, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(17, SteamFriends, IsUserInSource);
    Createmethod(18, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(19, SteamFriends, ActivateGameOverlay);
    Createmethod(20, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(21, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(22, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(23, SteamFriends, SetPlayedWith);
    Createmethod(24, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(25, SteamFriends, GetSmallFriendAvatar);
    Createmethod(26, SteamFriends, GetMediumFriendAvatar);
    Createmethod(27, SteamFriends, GetLargeFriendAvatar);
    Createmethod(28, SteamFriends, RequestUserInformation);
    Createmethod(29, SteamFriends, RequestClanOfficerList);
    Createmethod(30, SteamFriends, GetClanOwner);
    Createmethod(31, SteamFriends, GetClanOfficerCount);
    Createmethod(32, SteamFriends, GetClanOfficerByIndex);
    Createmethod(33, SteamFriends, GetUserRestrictions);
};
SteamFriends009::SteamFriends009()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, HasFriend1);
    Createmethod(11, SteamFriends, GetClanCount);
    Createmethod(12, SteamFriends, GetClanByIndex);
    Createmethod(13, SteamFriends, GetClanName);
    Createmethod(14, SteamFriends, GetClanTag);
    Createmethod(15, SteamFriends, GetFriendCountFromSource);
    Createmethod(16, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(17, SteamFriends, IsUserInSource);
    Createmethod(18, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(19, SteamFriends, ActivateGameOverlay);
    Createmethod(20, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(21, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(22, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(23, SteamFriends, SetPlayedWith);
    Createmethod(24, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(25, SteamFriends, GetSmallFriendAvatar);
    Createmethod(26, SteamFriends, GetMediumFriendAvatar);
    Createmethod(27, SteamFriends, GetLargeFriendAvatar);
    Createmethod(28, SteamFriends, RequestUserInformation);
    Createmethod(29, SteamFriends, RequestClanOfficerList);
    Createmethod(30, SteamFriends, GetClanOwner);
    Createmethod(31, SteamFriends, GetClanOfficerCount);
    Createmethod(32, SteamFriends, GetClanOfficerByIndex);
    Createmethod(33, SteamFriends, GetUserRestrictions);
    Createmethod(34, SteamFriends, SetRichPresence);
    Createmethod(35, SteamFriends, ClearRichPresence);
    Createmethod(36, SteamFriends, GetFriendRichPresence);
    Createmethod(37, SteamFriends, GetFriendRichPresenceKeyCount);
    Createmethod(38, SteamFriends, GetFriendRichPresenceKeyByIndex);
    Createmethod(39, SteamFriends, InviteUserToGame);
    Createmethod(40, SteamFriends, GetCoplayFriendCount);
    Createmethod(41, SteamFriends, GetCoplayFriend);
    Createmethod(42, SteamFriends, GetFriendCoplayTime);
    Createmethod(43, SteamFriends, GetFriendCoplayGame);
};
SteamFriends010::SteamFriends010()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, HasFriend1);
    Createmethod(11, SteamFriends, GetClanCount);
    Createmethod(12, SteamFriends, GetClanByIndex);
    Createmethod(13, SteamFriends, GetClanName);
    Createmethod(14, SteamFriends, GetClanTag);
    Createmethod(15, SteamFriends, GetClanActivityCounts);
    Createmethod(16, SteamFriends, DownloadClanActivityCounts);
    Createmethod(17, SteamFriends, GetFriendCountFromSource);
    Createmethod(18, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(19, SteamFriends, IsUserInSource);
    Createmethod(20, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(21, SteamFriends, ActivateGameOverlay);
    Createmethod(22, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(23, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(24, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(25, SteamFriends, SetPlayedWith);
    Createmethod(26, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(27, SteamFriends, GetSmallFriendAvatar);
    Createmethod(28, SteamFriends, GetMediumFriendAvatar);
    Createmethod(29, SteamFriends, GetLargeFriendAvatar);
    Createmethod(30, SteamFriends, RequestUserInformation);
    Createmethod(31, SteamFriends, RequestClanOfficerList);
    Createmethod(32, SteamFriends, GetClanOwner);
    Createmethod(33, SteamFriends, GetClanOfficerCount);
    Createmethod(34, SteamFriends, GetClanOfficerByIndex);
    Createmethod(35, SteamFriends, GetUserRestrictions);
    Createmethod(36, SteamFriends, SetRichPresence);
    Createmethod(37, SteamFriends, ClearRichPresence);
    Createmethod(38, SteamFriends, GetFriendRichPresence);
    Createmethod(39, SteamFriends, GetFriendRichPresenceKeyCount);
    Createmethod(40, SteamFriends, GetFriendRichPresenceKeyByIndex);
    Createmethod(41, SteamFriends, InviteUserToGame);
    Createmethod(42, SteamFriends, GetCoplayFriendCount);
    Createmethod(43, SteamFriends, GetCoplayFriend);
    Createmethod(44, SteamFriends, GetFriendCoplayTime);
    Createmethod(45, SteamFriends, GetFriendCoplayGame);
    Createmethod(46, SteamFriends, JoinClanChatRoom);
    Createmethod(47, SteamFriends, LeaveClanChatRoom);
    Createmethod(48, SteamFriends, GetClanChatMemberCount);
    Createmethod(49, SteamFriends, GetChatMemberByIndex);
    Createmethod(50, SteamFriends, SendClanChatMessage);
    Createmethod(51, SteamFriends, GetClanChatMessage);
    Createmethod(52, SteamFriends, IsClanChatAdmin);
    Createmethod(53, SteamFriends, IsClanChatWindowOpenInSteam);
    Createmethod(54, SteamFriends, OpenClanChatWindowInSteam);
    Createmethod(55, SteamFriends, CloseClanChatWindowInSteam);
    Createmethod(56, SteamFriends, SetListenForFriendsMessages);
    Createmethod(57, SteamFriends, ReplyToFriendMessage);
    Createmethod(58, SteamFriends, GetFriendMessage);
};
SteamFriends011::SteamFriends011()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName0);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, HasFriend1);
    Createmethod(11, SteamFriends, GetClanCount);
    Createmethod(12, SteamFriends, GetClanByIndex);
    Createmethod(13, SteamFriends, GetClanName);
    Createmethod(14, SteamFriends, GetClanTag);
    Createmethod(15, SteamFriends, GetClanActivityCounts);
    Createmethod(16, SteamFriends, DownloadClanActivityCounts);
    Createmethod(17, SteamFriends, GetFriendCountFromSource);
    Createmethod(18, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(19, SteamFriends, IsUserInSource);
    Createmethod(20, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(21, SteamFriends, ActivateGameOverlay);
    Createmethod(22, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(23, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(24, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(25, SteamFriends, SetPlayedWith);
    Createmethod(26, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(27, SteamFriends, GetSmallFriendAvatar);
    Createmethod(28, SteamFriends, GetMediumFriendAvatar);
    Createmethod(29, SteamFriends, GetLargeFriendAvatar);
    Createmethod(30, SteamFriends, RequestUserInformation);
    Createmethod(31, SteamFriends, RequestClanOfficerList);
    Createmethod(32, SteamFriends, GetClanOwner);
    Createmethod(33, SteamFriends, GetClanOfficerCount);
    Createmethod(34, SteamFriends, GetClanOfficerByIndex);
    Createmethod(35, SteamFriends, GetUserRestrictions);
    Createmethod(36, SteamFriends, SetRichPresence);
    Createmethod(37, SteamFriends, ClearRichPresence);
    Createmethod(38, SteamFriends, GetFriendRichPresence);
    Createmethod(39, SteamFriends, GetFriendRichPresenceKeyCount);
    Createmethod(40, SteamFriends, GetFriendRichPresenceKeyByIndex);
    Createmethod(41, SteamFriends, RequestFriendRichPresence);
    Createmethod(42, SteamFriends, InviteUserToGame);
    Createmethod(43, SteamFriends, GetCoplayFriendCount);
    Createmethod(44, SteamFriends, GetCoplayFriend);
    Createmethod(45, SteamFriends, GetFriendCoplayTime);
    Createmethod(46, SteamFriends, GetFriendCoplayGame);
    Createmethod(47, SteamFriends, JoinClanChatRoom);
    Createmethod(48, SteamFriends, LeaveClanChatRoom);
    Createmethod(49, SteamFriends, GetClanChatMemberCount);
    Createmethod(50, SteamFriends, GetChatMemberByIndex);
    Createmethod(51, SteamFriends, SendClanChatMessage);
    Createmethod(52, SteamFriends, GetClanChatMessage);
    Createmethod(53, SteamFriends, IsClanChatAdmin);
    Createmethod(54, SteamFriends, IsClanChatWindowOpenInSteam);
    Createmethod(55, SteamFriends, OpenClanChatWindowInSteam);
    Createmethod(56, SteamFriends, CloseClanChatWindowInSteam);
    Createmethod(57, SteamFriends, SetListenForFriendsMessages);
    Createmethod(58, SteamFriends, ReplyToFriendMessage);
    Createmethod(59, SteamFriends, GetFriendMessage);
    Createmethod(60, SteamFriends, GetFollowerCount);
    Createmethod(61, SteamFriends, IsFollowing);
    Createmethod(62, SteamFriends, EnumerateFollowingList);
};
SteamFriends012::SteamFriends012()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName1);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, HasFriend1);
    Createmethod(11, SteamFriends, GetClanCount);
    Createmethod(12, SteamFriends, GetClanByIndex);
    Createmethod(13, SteamFriends, GetClanName);
    Createmethod(14, SteamFriends, GetClanTag);
    Createmethod(15, SteamFriends, GetClanActivityCounts);
    Createmethod(16, SteamFriends, DownloadClanActivityCounts);
    Createmethod(17, SteamFriends, GetFriendCountFromSource);
    Createmethod(18, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(19, SteamFriends, IsUserInSource);
    Createmethod(20, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(21, SteamFriends, ActivateGameOverlay);
    Createmethod(22, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(23, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(24, SteamFriends, ActivateGameOverlayToStore0);
    Createmethod(25, SteamFriends, SetPlayedWith);
    Createmethod(26, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(27, SteamFriends, GetSmallFriendAvatar);
    Createmethod(28, SteamFriends, GetMediumFriendAvatar);
    Createmethod(29, SteamFriends, GetLargeFriendAvatar);
    Createmethod(30, SteamFriends, RequestUserInformation);
    Createmethod(31, SteamFriends, RequestClanOfficerList);
    Createmethod(32, SteamFriends, GetClanOwner);
    Createmethod(33, SteamFriends, GetClanOfficerCount);
    Createmethod(34, SteamFriends, GetClanOfficerByIndex);
    Createmethod(35, SteamFriends, GetUserRestrictions);
    Createmethod(36, SteamFriends, SetRichPresence);
    Createmethod(37, SteamFriends, ClearRichPresence);
    Createmethod(38, SteamFriends, GetFriendRichPresence);
    Createmethod(39, SteamFriends, GetFriendRichPresenceKeyCount);
    Createmethod(40, SteamFriends, GetFriendRichPresenceKeyByIndex);
    Createmethod(41, SteamFriends, RequestFriendRichPresence);
    Createmethod(42, SteamFriends, InviteUserToGame);
    Createmethod(43, SteamFriends, GetCoplayFriendCount);
    Createmethod(44, SteamFriends, GetCoplayFriend);
    Createmethod(45, SteamFriends, GetFriendCoplayTime);
    Createmethod(46, SteamFriends, GetFriendCoplayGame);
    Createmethod(47, SteamFriends, JoinClanChatRoom);
    Createmethod(48, SteamFriends, LeaveClanChatRoom);
    Createmethod(49, SteamFriends, GetClanChatMemberCount);
    Createmethod(50, SteamFriends, GetChatMemberByIndex);
    Createmethod(51, SteamFriends, SendClanChatMessage);
    Createmethod(52, SteamFriends, GetClanChatMessage);
    Createmethod(53, SteamFriends, IsClanChatAdmin);
    Createmethod(54, SteamFriends, IsClanChatWindowOpenInSteam);
    Createmethod(55, SteamFriends, OpenClanChatWindowInSteam);
    Createmethod(56, SteamFriends, CloseClanChatWindowInSteam);
    Createmethod(57, SteamFriends, SetListenForFriendsMessages);
    Createmethod(58, SteamFriends, ReplyToFriendMessage);
    Createmethod(59, SteamFriends, GetFriendMessage);
    Createmethod(60, SteamFriends, GetFollowerCount);
    Createmethod(61, SteamFriends, IsFollowing);
    Createmethod(62, SteamFriends, EnumerateFollowingList);
};
SteamFriends013::SteamFriends013()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName1);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, HasFriend1);
    Createmethod(11, SteamFriends, GetClanCount);
    Createmethod(12, SteamFriends, GetClanByIndex);
    Createmethod(13, SteamFriends, GetClanName);
    Createmethod(14, SteamFriends, GetClanTag);
    Createmethod(15, SteamFriends, GetClanActivityCounts);
    Createmethod(16, SteamFriends, DownloadClanActivityCounts);
    Createmethod(17, SteamFriends, GetFriendCountFromSource);
    Createmethod(18, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(19, SteamFriends, IsUserInSource);
    Createmethod(20, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(21, SteamFriends, ActivateGameOverlay);
    Createmethod(22, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(23, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(24, SteamFriends, ActivateGameOverlayToStore1);
    Createmethod(25, SteamFriends, SetPlayedWith);
    Createmethod(26, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(27, SteamFriends, GetSmallFriendAvatar);
    Createmethod(28, SteamFriends, GetMediumFriendAvatar);
    Createmethod(29, SteamFriends, GetLargeFriendAvatar);
    Createmethod(30, SteamFriends, RequestUserInformation);
    Createmethod(31, SteamFriends, RequestClanOfficerList);
    Createmethod(32, SteamFriends, GetClanOwner);
    Createmethod(33, SteamFriends, GetClanOfficerCount);
    Createmethod(34, SteamFriends, GetClanOfficerByIndex);
    Createmethod(35, SteamFriends, GetUserRestrictions);
    Createmethod(36, SteamFriends, SetRichPresence);
    Createmethod(37, SteamFriends, ClearRichPresence);
    Createmethod(38, SteamFriends, GetFriendRichPresence);
    Createmethod(39, SteamFriends, GetFriendRichPresenceKeyCount);
    Createmethod(40, SteamFriends, GetFriendRichPresenceKeyByIndex);
    Createmethod(41, SteamFriends, RequestFriendRichPresence);
    Createmethod(42, SteamFriends, InviteUserToGame);
    Createmethod(43, SteamFriends, GetCoplayFriendCount);
    Createmethod(44, SteamFriends, GetCoplayFriend);
    Createmethod(45, SteamFriends, GetFriendCoplayTime);
    Createmethod(46, SteamFriends, GetFriendCoplayGame);
    Createmethod(47, SteamFriends, JoinClanChatRoom);
    Createmethod(48, SteamFriends, LeaveClanChatRoom);
    Createmethod(49, SteamFriends, GetClanChatMemberCount);
    Createmethod(50, SteamFriends, GetChatMemberByIndex);
    Createmethod(51, SteamFriends, SendClanChatMessage);
    Createmethod(52, SteamFriends, GetClanChatMessage);
    Createmethod(53, SteamFriends, IsClanChatAdmin);
    Createmethod(54, SteamFriends, IsClanChatWindowOpenInSteam);
    Createmethod(55, SteamFriends, OpenClanChatWindowInSteam);
    Createmethod(56, SteamFriends, CloseClanChatWindowInSteam);
    Createmethod(57, SteamFriends, SetListenForFriendsMessages);
    Createmethod(58, SteamFriends, ReplyToFriendMessage);
    Createmethod(59, SteamFriends, GetFriendMessage);
    Createmethod(60, SteamFriends, GetFollowerCount);
    Createmethod(61, SteamFriends, IsFollowing);
    Createmethod(62, SteamFriends, EnumerateFollowingList);
};
SteamFriends014::SteamFriends014()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName1);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, GetPlayerNickname);
    Createmethod(11, SteamFriends, HasFriend1);
    Createmethod(12, SteamFriends, GetClanCount);
    Createmethod(13, SteamFriends, GetClanByIndex);
    Createmethod(14, SteamFriends, GetClanName);
    Createmethod(15, SteamFriends, GetClanTag);
    Createmethod(16, SteamFriends, GetClanActivityCounts);
    Createmethod(17, SteamFriends, DownloadClanActivityCounts);
    Createmethod(18, SteamFriends, GetFriendCountFromSource);
    Createmethod(19, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(20, SteamFriends, IsUserInSource);
    Createmethod(21, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(22, SteamFriends, ActivateGameOverlay);
    Createmethod(23, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(24, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(25, SteamFriends, ActivateGameOverlayToStore1);
    Createmethod(26, SteamFriends, SetPlayedWith);
    Createmethod(27, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(28, SteamFriends, GetSmallFriendAvatar);
    Createmethod(29, SteamFriends, GetMediumFriendAvatar);
    Createmethod(30, SteamFriends, GetLargeFriendAvatar);
    Createmethod(31, SteamFriends, RequestUserInformation);
    Createmethod(32, SteamFriends, RequestClanOfficerList);
    Createmethod(33, SteamFriends, GetClanOwner);
    Createmethod(34, SteamFriends, GetClanOfficerCount);
    Createmethod(35, SteamFriends, GetClanOfficerByIndex);
    Createmethod(36, SteamFriends, GetUserRestrictions);
    Createmethod(37, SteamFriends, SetRichPresence);
    Createmethod(38, SteamFriends, ClearRichPresence);
    Createmethod(39, SteamFriends, GetFriendRichPresence);
    Createmethod(40, SteamFriends, GetFriendRichPresenceKeyCount);
    Createmethod(41, SteamFriends, GetFriendRichPresenceKeyByIndex);
    Createmethod(42, SteamFriends, RequestFriendRichPresence);
    Createmethod(43, SteamFriends, InviteUserToGame);
    Createmethod(44, SteamFriends, GetCoplayFriendCount);
    Createmethod(45, SteamFriends, GetCoplayFriend);
    Createmethod(46, SteamFriends, GetFriendCoplayTime);
    Createmethod(47, SteamFriends, GetFriendCoplayGame);
    Createmethod(48, SteamFriends, JoinClanChatRoom);
    Createmethod(49, SteamFriends, LeaveClanChatRoom);
    Createmethod(50, SteamFriends, GetClanChatMemberCount);
    Createmethod(51, SteamFriends, GetChatMemberByIndex);
    Createmethod(52, SteamFriends, SendClanChatMessage);
    Createmethod(53, SteamFriends, GetClanChatMessage);
    Createmethod(54, SteamFriends, IsClanChatAdmin);
    Createmethod(55, SteamFriends, IsClanChatWindowOpenInSteam);
    Createmethod(56, SteamFriends, OpenClanChatWindowInSteam);
    Createmethod(57, SteamFriends, CloseClanChatWindowInSteam);
    Createmethod(58, SteamFriends, SetListenForFriendsMessages);
    Createmethod(59, SteamFriends, ReplyToFriendMessage);
    Createmethod(60, SteamFriends, GetFriendMessage);
    Createmethod(61, SteamFriends, GetFollowerCount);
    Createmethod(62, SteamFriends, IsFollowing);
    Createmethod(63, SteamFriends, EnumerateFollowingList);
};
SteamFriends015::SteamFriends015()
{
    Createmethod(0, SteamFriends, GetPersonaName);
    Createmethod(1, SteamFriends, SetPersonaName1);
    Createmethod(2, SteamFriends, GetPersonaState);
    Createmethod(3, SteamFriends, GetFriendCount1);
    Createmethod(4, SteamFriends, GetFriendByIndex1);
    Createmethod(5, SteamFriends, GetFriendRelationship);
    Createmethod(6, SteamFriends, GetFriendPersonaState);
    Createmethod(7, SteamFriends, GetFriendPersonaName);
    Createmethod(8, SteamFriends, GetFriendGamePlayed3);
    Createmethod(9, SteamFriends, GetFriendPersonaNameHistory);
    Createmethod(10, SteamFriends, GetFriendSteamLevel);
    Createmethod(11, SteamFriends, GetPlayerNickname);
    Createmethod(12, SteamFriends, GetFriendsGroupCount);
    Createmethod(13, SteamFriends, GetFriendsGroupIDByIndex);
    Createmethod(14, SteamFriends, GetFriendsGroupName);
    Createmethod(15, SteamFriends, GetFriendsGroupMembersCount);
    Createmethod(16, SteamFriends, GetFriendsGroupMembersList);
    Createmethod(17, SteamFriends, HasFriend1);
    Createmethod(18, SteamFriends, GetClanCount);
    Createmethod(19, SteamFriends, GetClanByIndex);
    Createmethod(20, SteamFriends, GetClanName);
    Createmethod(21, SteamFriends, GetClanTag);
    Createmethod(22, SteamFriends, GetClanActivityCounts);
    Createmethod(23, SteamFriends, DownloadClanActivityCounts);
    Createmethod(24, SteamFriends, GetFriendCountFromSource);
    Createmethod(25, SteamFriends, GetFriendFromSourceByIndex);
    Createmethod(26, SteamFriends, IsUserInSource);
    Createmethod(27, SteamFriends, SetInGameVoiceSpeaking);
    Createmethod(28, SteamFriends, ActivateGameOverlay);
    Createmethod(29, SteamFriends, ActivateGameOverlayToUser);
    Createmethod(30, SteamFriends, ActivateGameOverlayToWebPage);
    Createmethod(31, SteamFriends, ActivateGameOverlayToStore1);
    Createmethod(32, SteamFriends, SetPlayedWith);
    Createmethod(33, SteamFriends, ActivateGameOverlayInviteDialog);
    Createmethod(34, SteamFriends, GetSmallFriendAvatar);
    Createmethod(35, SteamFriends, GetMediumFriendAvatar);
    Createmethod(36, SteamFriends, GetLargeFriendAvatar);
    Createmethod(37, SteamFriends, RequestUserInformation);
    Createmethod(38, SteamFriends, RequestClanOfficerList);
    Createmethod(39, SteamFriends, GetClanOwner);
    Createmethod(40, SteamFriends, GetClanOfficerCount);
    Createmethod(41, SteamFriends, GetClanOfficerByIndex);
    Createmethod(42, SteamFriends, GetUserRestrictions);
    Createmethod(43, SteamFriends, SetRichPresence);
    Createmethod(44, SteamFriends, ClearRichPresence);
    Createmethod(45, SteamFriends, GetFriendRichPresence);
    Createmethod(46, SteamFriends, GetFriendRichPresenceKeyCount);
    Createmethod(47, SteamFriends, GetFriendRichPresenceKeyByIndex);
    Createmethod(48, SteamFriends, RequestFriendRichPresence);
    Createmethod(49, SteamFriends, InviteUserToGame);
    Createmethod(50, SteamFriends, GetCoplayFriendCount);
    Createmethod(51, SteamFriends, GetCoplayFriend);
    Createmethod(52, SteamFriends, GetFriendCoplayTime);
    Createmethod(53, SteamFriends, GetFriendCoplayGame);
    Createmethod(54, SteamFriends, JoinClanChatRoom);
    Createmethod(55, SteamFriends, LeaveClanChatRoom);
    Createmethod(56, SteamFriends, GetClanChatMemberCount);
    Createmethod(57, SteamFriends, GetChatMemberByIndex);
    Createmethod(58, SteamFriends, SendClanChatMessage);
    Createmethod(59, SteamFriends, GetClanChatMessage);
    Createmethod(60, SteamFriends, IsClanChatAdmin);
    Createmethod(61, SteamFriends, IsClanChatWindowOpenInSteam);
    Createmethod(62, SteamFriends, OpenClanChatWindowInSteam);
    Createmethod(63, SteamFriends, CloseClanChatWindowInSteam);
    Createmethod(64, SteamFriends, SetListenForFriendsMessages);
    Createmethod(65, SteamFriends, ReplyToFriendMessage);
    Createmethod(66, SteamFriends, GetFriendMessage);
    Createmethod(67, SteamFriends, GetFollowerCount);
    Createmethod(68, SteamFriends, IsFollowing);
    Createmethod(69, SteamFriends, EnumerateFollowingList);
};

struct Steamfriendsloader
{
    Steamfriendsloader()
    {
        Createinterface(STEAM_FRIENDS, SteamFriends001);
        Createinterface(STEAM_FRIENDS, SteamFriends002);
        Createinterface(STEAM_FRIENDS, SteamFriends003);
        Createinterface(STEAM_FRIENDS, SteamFriends004);
        Createinterface(STEAM_FRIENDS, SteamFriends005);
        Createinterface(STEAM_FRIENDS, SteamFriends006);
        Createinterface(STEAM_FRIENDS, SteamFriends007);
        Createinterface(STEAM_FRIENDS, SteamFriends008);
        Createinterface(STEAM_FRIENDS, SteamFriends009);
        Createinterface(STEAM_FRIENDS, SteamFriends010);
        Createinterface(STEAM_FRIENDS, SteamFriends011);
        Createinterface(STEAM_FRIENDS, SteamFriends012);
        Createinterface(STEAM_FRIENDS, SteamFriends013);
        Createinterface(STEAM_FRIENDS, SteamFriends014);
        Createinterface(STEAM_FRIENDS, SteamFriends015);

        Loadfriends();
    }
};
static Steamfriendsloader Interfaceloader{};
