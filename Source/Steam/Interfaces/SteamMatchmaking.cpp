/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam gameplay information.
*/

#include "../../Stdinclude.hpp"

// Callbacks.
#pragma pack( push, 8 )
struct LobbyCreated_t
{
    enum { k_iCallback = 513 };

    EResult m_eResult;
    uint64_t m_ulSteamIDLobby;
};
struct LobbyEnter_t
{
    enum { k_iCallback = 504 };

    CSteamID m_ulSteamIDLobby;
    uint32_t m_rgfChatPermissions;
    bool m_bLocked;
    uint32_t m_EChatRoomEnterResponse;
};
#pragma pack( pop )

#pragma region Methods
class SteamMatchmaking
{
public:
    int GetFavoriteGameCount()
    {
        Printfunction();
        return 0;
    }
    bool GetFavoriteGame0(int iGame, uint32_t *pnAppID, uint32_t *pnIP, uint16_t *pnConnPort, uint32_t *punFlags, uint32_t *pRTime32LastPlayedOnServer)
    {
        Printfunction();
        return false;
    }
    int AddFavoriteGame0(uint32_t nAppID, uint32_t nIP, uint16_t nConnPort, uint32_t unFlags, uint32_t rTime32LastPlayedOnServer)
    {
        Printfunction();
        return 0;
    }
    bool RemoveFavoriteGame0(uint32_t nAppID, uint32_t nIP, uint16_t nConnPort, uint32_t unFlags)
    {
        Printfunction();
        return false;
    }
    bool GetFavoriteGame2(int iGame, uint32_t *pnAppID, uint32_t *pnIP, uint16_t *pnConnPort, uint16_t *pnQueryPort, uint32_t *punFlags, uint32_t *pRTime32LastPlayedOnServer)
    {
        Printfunction();
        return false;
    }
    int AddFavoriteGame2(uint32_t nAppID, uint32_t nIP, uint16_t nConnPort, uint16_t nQueryPort, uint32_t unFlags, uint32_t rTime32LastPlayedOnServer)
    {
        Printfunction();
        return false;
    }
    bool RemoveFavoriteGame2(uint32_t nAppID, uint32_t nIP, uint16_t nConnPort, uint16_t nQueryPort, uint32_t unFlags)
    {
        Printfunction();
        return false;
    }
    void RequestLobbyList0(uint64_t ulGameID, struct MatchMakingKeyValuePair_t *pFilters, uint32_t nFilters)
    {
        Printfunction();
    }
    CSteamID GetLobbyByIndex(int iLobby)
    {
        Printfunction();
        return CSteamID(Steamconfig::UserID);
    }
    void CreateLobby0(uint64_t ulGameID, bool bPrivate)
    {
        Printfunction();
    }
    void JoinLobby0(CSteamID steamIDLobby)
    {
        Printfunction();
    }
    void LeaveLobby(CSteamID steamIDLobby)
    {
        Printfunction();
    }
    bool InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee)
    {
        Printfunction();
        return false;
    }
    int GetNumLobbyMembers(CSteamID steamIDLobby)
    {
        return 1;
    }
    CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember)
    {
        return CSteamID(Steamconfig::UserID);
    }
    const char *GetLobbyData(CSteamID SteamIDLobby, const char *pchKey)
    {
        Printfunction();
        return "";
    }
    void SetLobbyData0(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
    {
        Debugprint(va("%s - Key: \"%s\" - Value: \"%s\"", __FUNCTION__, pchKey, pchValue));
    }
    const char *GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey)
    {
        Printfunction();
        return "";
    }
    void SetLobbyMemberData(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
    {
        Debugprint(va("%s - Key: \"%s\" - Value: \"%s\"", __FUNCTION__, pchKey, pchValue));
    }
    void ChangeLobbyAdmin(CSteamID steamIDLobby, CSteamID steamIDNewAdmin)
    {
        Printfunction();
    }
    bool SendLobbyChatMsg(CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody)
    {
        Printfunction();
        return false;
    }
    int GetLobbyChatEntry(CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, uint32_t  *peChatEntryType)
    {
        Printfunction();
        return 0;
    }
    bool RequestLobbyData(CSteamID steamIDLobby)
    {
        Printfunction();
        return false;
    }
    bool GetFavoriteGame1(int iGame, uint32_t *pnAppID, uint32_t *pnIP, uint16_t *pnConnPort, uint16_t *pnQueryPort, uint32_t *punFlags, uint32_t *pRTime32LastPlayedOnServer)
    {
        Printfunction();
        return false;
    }
    int AddFavoriteGame1(uint32_t nAppID, uint32_t nIP, uint16_t nConnPort, uint16_t nQueryPort, uint32_t unFlags, uint32_t rTime32LastPlayedOnServer)
    {
        Printfunction();
        return 0;
    }
    bool RemoveFavoriteGame1(uint32_t nAppID, uint32_t nIP, uint16_t nConnPort, uint16_t nQueryPort, uint32_t unFlags)
    {
        Printfunction();
        return false;
    }
    void RequestLobbyList1()
    {
        Printfunction();
    }
    void CreateLobby1(bool bPrivate)
    {
        Printfunction();
    }
    void SetLobbyGameServer(CSteamID steamIDLobby, uint32_t unGameServerIP, uint16_t unGameServerPort, CSteamID steamIDGameServer)
    {
        Printfunction();
    }
    uint64_t RequestLobbyList2()
    {
        Printfunction();
        return 0;
    }
    void AddRequestLobbyListFilter(const char *pchKeyToMatch, const char *pchValueToMatch)
    {
        Printfunction();
    }
    void AddRequestLobbyListNumericalFilter0(const char *pchKeyToMatch, int nValueToMatch, int nComparisonType)
    {
        Printfunction();
    }
    void AddRequestLobbyListSlotsAvailableFilter()
    {
        Printfunction();
    }
    bool SetLobbyData1(CSteamID steamIDLobby, const char *pchKey, const char *pchValue)
    {
        Debugprint(va("%s - Key: \"%s\" - Value: \"%s\"", __FUNCTION__, pchKey, pchValue));
        return true;
    }
    bool GetLobbyGameServer(CSteamID steamIDLobby, uint32_t *punGameServerIP, uint16_t *punGameServerPort, CSteamID *psteamIDGameServer)
    {
        Printfunction();
        return false;
    }
    bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers)
    {
        Printfunction();
        return true;
    }
    int GetLobbyMemberLimit(CSteamID steamIDLobby)
    {
        Printfunction();
        return 1;
    }
    void SetLobbyVoiceEnabled(CSteamID steamIDLobby, bool bEnabled)
    {
        Printfunction();
    }
    bool RequestFriendsLobbies()
    {
        Printfunction();
        return false;
    }
    void AddRequestLobbyListNearValueFilter(const char *pchKeyToMatch, int nValueToBeCloseTo)
    {
        Printfunction();
    }
    uint64_t CreateLobby2(uint32_t eLobbyType)
    {
        Printfunction();
        return 0;
    }
    uint64_t JoinLobby1(CSteamID steamIDLobby)
    {
        Infoprint(va("Joining lobby 0c%llx.", steamIDLobby));

        auto RequestID = Steamcallback::Createrequest();
        LobbyEnter_t *Response = new LobbyEnter_t();
        Response->m_ulSteamIDLobby = steamIDLobby;
        Response->m_EChatRoomEnterResponse = 1;
        Response->m_rgfChatPermissions = -1;
        Response->m_bLocked = false;

        Steamcallback::Completerequest({ Response, sizeof(*Response), Response->k_iCallback, RequestID });
        return RequestID;
    }
    bool SetLobbyType(CSteamID steamIDLobby, uint32_t eLobbyType)
    {
        Printfunction();
        return true;
    }
    CSteamID GetLobbyOwner(CSteamID steamIDLobby)
    {
        return CSteamID(Steamconfig::UserID);
    }
    double GetLobbyDistance(CSteamID steamIDLobby)
    {
        Printfunction();
        return 0.0;
    }
    void AddRequestLobbyListStringFilter(const char *pchKeyToMatch, const char *pchValueToMatch, uint32_t eComparisonType)
    {
        Printfunction();
    }
    void AddRequestLobbyListNumericalFilter1(const char *pchKeyToMatch, int nValueToMatch, uint32_t eComparisonType)
    {
        Printfunction();
    }
    void AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable)
    {
        Printfunction();
    }
    uint64_t CreateLobby3(uint32_t eLobbyType, int cMaxMembers)
    {
        auto LobbyID = CSteamID(1337, 0x40000, 1, k_EAccountTypeChat);
        auto RequestID = Steamcallback::Createrequest();
        auto Response = new LobbyCreated_t();

        Response->m_eResult = k_EResultOK;
        Response->m_ulSteamIDLobby = LobbyID.ConvertToUint64();
        Infoprint(va("Creating a lobby of type %d for %d players.", eLobbyType, cMaxMembers));
        Steamcallback::Completerequest({ Response, sizeof(*Response), Response->k_iCallback, RequestID });

        return RequestID;
    }
    int GetLobbyDataCount(CSteamID steamIDLobby)
    {
        Printfunction();
        return false;
    }
    bool GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize)
    {
        Printfunction();
        return false;
    }
    bool DeleteLobbyData(CSteamID steamIDLobby, const char *pchKey)
    {
        Printfunction();
        return false;
    }
    bool SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable)
    {
        Printfunction();
        return false;
    }
    bool SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner)
    {
        Printfunction();
        return false;
    }
    void AddRequestLobbyListDistanceFilter(uint32_t eLobbyDistanceFilter)
    {
        Printfunction();
    }
    void AddRequestLobbyListResultCountFilter(int cMaxResults)
    {
        Printfunction();
    }
    void AddRequestLobbyListCompatibleMembersFilter(CSteamID steamID)
    {
        Printfunction();
    }
    bool SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobby2)
    {
        Printfunction();
        return false;
    }
};
#pragma endregion

SteamMatchmaking001::SteamMatchmaking001()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame0);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame0);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame0);
    Createmethod(4, SteamMatchmaking, GetFavoriteGame2);
    Createmethod(5, SteamMatchmaking, AddFavoriteGame2);
    Createmethod(6, SteamMatchmaking, RemoveFavoriteGame2);
    Createmethod(7, SteamMatchmaking, RequestLobbyList0);
    Createmethod(8, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(9, SteamMatchmaking, CreateLobby0);
    Createmethod(10, SteamMatchmaking, JoinLobby0);
    Createmethod(11, SteamMatchmaking, LeaveLobby);
    Createmethod(12, SteamMatchmaking, InviteUserToLobby);
    Createmethod(13, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(14, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(15, SteamMatchmaking, GetLobbyData);
    Createmethod(16, SteamMatchmaking, SetLobbyData0);
    Createmethod(17, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(18, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(19, SteamMatchmaking, ChangeLobbyAdmin);
    Createmethod(20, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(21, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(22, SteamMatchmaking, RequestLobbyData);
};
SteamMatchmaking002::SteamMatchmaking002()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList1);
    Createmethod(5, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(7, SteamMatchmaking, JoinLobby0);
    Createmethod(8, SteamMatchmaking, LeaveLobby);
    Createmethod(9, SteamMatchmaking, InviteUserToLobby);
    Createmethod(10, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(11, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(12, SteamMatchmaking, GetLobbyData);
    Createmethod(13, SteamMatchmaking, SetLobbyData0);
    Createmethod(14, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(15, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(16, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(17, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(18, SteamMatchmaking, RequestLobbyData);
    Createmethod(19, SteamMatchmaking, SetLobbyGameServer);
};
SteamMatchmaking003::SteamMatchmaking003()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList2);
    Createmethod(5, SteamMatchmaking, AddRequestLobbyListFilter);
    Createmethod(6, SteamMatchmaking, AddRequestLobbyListNumericalFilter0);
    Createmethod(7, SteamMatchmaking, AddRequestLobbyListSlotsAvailableFilter);
    Createmethod(8, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(9, SteamMatchmaking, CreateLobby1);
    Createmethod(10, SteamMatchmaking, JoinLobby0);
    Createmethod(11, SteamMatchmaking, LeaveLobby);
    Createmethod(12, SteamMatchmaking, InviteUserToLobby);
    Createmethod(13, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(14, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(15, SteamMatchmaking, GetLobbyData);
    Createmethod(16, SteamMatchmaking, SetLobbyData1);
    Createmethod(17, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(18, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(19, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(20, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(21, SteamMatchmaking, RequestLobbyData);
    Createmethod(22, SteamMatchmaking, SetLobbyGameServer);
    Createmethod(23, SteamMatchmaking, GetLobbyGameServer);
    Createmethod(24, SteamMatchmaking, SetLobbyMemberLimit);
    Createmethod(25, SteamMatchmaking, GetLobbyMemberLimit);
    Createmethod(26, SteamMatchmaking, SetLobbyVoiceEnabled);
    Createmethod(27, SteamMatchmaking, RequestFriendsLobbies);
};
SteamMatchmaking004::SteamMatchmaking004()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList2);
    Createmethod(5, SteamMatchmaking, AddRequestLobbyListFilter);
    Createmethod(6, SteamMatchmaking, AddRequestLobbyListNumericalFilter0);
    Createmethod(7, SteamMatchmaking, AddRequestLobbyListSlotsAvailableFilter);
    Createmethod(8, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(9, SteamMatchmaking, CreateLobby1);
    Createmethod(10, SteamMatchmaking, JoinLobby0);
    Createmethod(11, SteamMatchmaking, LeaveLobby);
    Createmethod(12, SteamMatchmaking, InviteUserToLobby);
    Createmethod(13, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(14, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(15, SteamMatchmaking, GetLobbyData);
    Createmethod(16, SteamMatchmaking, SetLobbyData1);
    Createmethod(17, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(18, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(19, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(20, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(21, SteamMatchmaking, RequestLobbyData);
    Createmethod(22, SteamMatchmaking, SetLobbyGameServer);
    Createmethod(23, SteamMatchmaking, GetLobbyGameServer);
    Createmethod(24, SteamMatchmaking, SetLobbyMemberLimit);
    Createmethod(25, SteamMatchmaking, GetLobbyMemberLimit);
    Createmethod(26, SteamMatchmaking, RequestFriendsLobbies);
};
SteamMatchmaking005::SteamMatchmaking005()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList2);
    Createmethod(5, SteamMatchmaking, AddRequestLobbyListFilter);
    Createmethod(6, SteamMatchmaking, AddRequestLobbyListNumericalFilter0);
    Createmethod(7, SteamMatchmaking, AddRequestLobbyListSlotsAvailableFilter);
    Createmethod(8, SteamMatchmaking, AddRequestLobbyListNearValueFilter);
    Createmethod(9, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(10, SteamMatchmaking, CreateLobby2);
    Createmethod(11, SteamMatchmaking, JoinLobby1);
    Createmethod(12, SteamMatchmaking, LeaveLobby);
    Createmethod(13, SteamMatchmaking, InviteUserToLobby);
    Createmethod(14, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(15, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(16, SteamMatchmaking, GetLobbyData);
    Createmethod(17, SteamMatchmaking, SetLobbyData1);
    Createmethod(18, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(19, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(20, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(21, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(22, SteamMatchmaking, RequestLobbyData);
    Createmethod(23, SteamMatchmaking, SetLobbyGameServer);
    Createmethod(24, SteamMatchmaking, GetLobbyGameServer);
    Createmethod(25, SteamMatchmaking, SetLobbyMemberLimit);
    Createmethod(26, SteamMatchmaking, GetLobbyMemberLimit);
    Createmethod(27, SteamMatchmaking, RequestFriendsLobbies);
    Createmethod(28, SteamMatchmaking, SetLobbyType);
    Createmethod(29, SteamMatchmaking, GetLobbyOwner);
    Createmethod(30, SteamMatchmaking, GetLobbyDistance);
};
SteamMatchmaking006::SteamMatchmaking006()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList2);
    Createmethod(5, SteamMatchmaking, AddRequestLobbyListFilter);
    Createmethod(6, SteamMatchmaking, AddRequestLobbyListNumericalFilter0);
    Createmethod(7, SteamMatchmaking, AddRequestLobbyListNearValueFilter);
    Createmethod(8, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(9, SteamMatchmaking, CreateLobby2);
    Createmethod(10, SteamMatchmaking, JoinLobby1);
    Createmethod(11, SteamMatchmaking, LeaveLobby);
    Createmethod(12, SteamMatchmaking, InviteUserToLobby);
    Createmethod(13, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(14, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(15, SteamMatchmaking, GetLobbyData);
    Createmethod(16, SteamMatchmaking, SetLobbyData1);
    Createmethod(17, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(18, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(19, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(20, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(21, SteamMatchmaking, RequestLobbyData);
    Createmethod(22, SteamMatchmaking, SetLobbyGameServer);
    Createmethod(23, SteamMatchmaking, GetLobbyGameServer);
    Createmethod(24, SteamMatchmaking, SetLobbyMemberLimit);
    Createmethod(25, SteamMatchmaking, GetLobbyMemberLimit);
    Createmethod(26, SteamMatchmaking, SetLobbyType);
    Createmethod(27, SteamMatchmaking, GetLobbyOwner);
};
SteamMatchmaking007::SteamMatchmaking007()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList2);
    Createmethod(5, SteamMatchmaking, AddRequestLobbyListStringFilter);
    Createmethod(6, SteamMatchmaking, AddRequestLobbyListNumericalFilter1);
    Createmethod(7, SteamMatchmaking, AddRequestLobbyListNearValueFilter);
    Createmethod(8, SteamMatchmaking, AddRequestLobbyListFilterSlotsAvailable);
    Createmethod(9, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(10, SteamMatchmaking, CreateLobby3);
    Createmethod(11, SteamMatchmaking, JoinLobby1);
    Createmethod(12, SteamMatchmaking, LeaveLobby);
    Createmethod(13, SteamMatchmaking, InviteUserToLobby);
    Createmethod(14, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(15, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(16, SteamMatchmaking, GetLobbyData);
    Createmethod(17, SteamMatchmaking, SetLobbyData1);
    Createmethod(18, SteamMatchmaking, GetLobbyDataCount);
    Createmethod(19, SteamMatchmaking, GetLobbyDataByIndex);
    Createmethod(20, SteamMatchmaking, DeleteLobbyData);
    Createmethod(21, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(22, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(23, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(24, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(25, SteamMatchmaking, RequestLobbyData);
    Createmethod(26, SteamMatchmaking, SetLobbyGameServer);
    Createmethod(27, SteamMatchmaking, GetLobbyGameServer);
    Createmethod(28, SteamMatchmaking, SetLobbyMemberLimit);
    Createmethod(29, SteamMatchmaking, GetLobbyMemberLimit);
    Createmethod(30, SteamMatchmaking, SetLobbyType);
    Createmethod(31, SteamMatchmaking, SetLobbyJoinable);
    Createmethod(32, SteamMatchmaking, GetLobbyOwner);
    Createmethod(33, SteamMatchmaking, SetLobbyOwner);
};
SteamMatchmaking008::SteamMatchmaking008()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList2);
    Createmethod(5, SteamMatchmaking, AddRequestLobbyListStringFilter);
    Createmethod(6, SteamMatchmaking, AddRequestLobbyListNumericalFilter1);
    Createmethod(7, SteamMatchmaking, AddRequestLobbyListNearValueFilter);
    Createmethod(8, SteamMatchmaking, AddRequestLobbyListFilterSlotsAvailable);
    Createmethod(9, SteamMatchmaking, AddRequestLobbyListDistanceFilter);
    Createmethod(10, SteamMatchmaking, AddRequestLobbyListResultCountFilter);
    Createmethod(11, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(12, SteamMatchmaking, CreateLobby3);
    Createmethod(13, SteamMatchmaking, JoinLobby1);
    Createmethod(14, SteamMatchmaking, LeaveLobby);
    Createmethod(15, SteamMatchmaking, InviteUserToLobby);
    Createmethod(16, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(17, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(18, SteamMatchmaking, GetLobbyData);
    Createmethod(19, SteamMatchmaking, SetLobbyData1);
    Createmethod(20, SteamMatchmaking, GetLobbyDataCount);
    Createmethod(21, SteamMatchmaking, GetLobbyDataByIndex);
    Createmethod(22, SteamMatchmaking, DeleteLobbyData);
    Createmethod(23, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(24, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(25, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(26, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(27, SteamMatchmaking, RequestLobbyData);
    Createmethod(28, SteamMatchmaking, SetLobbyGameServer);
    Createmethod(29, SteamMatchmaking, GetLobbyGameServer);
    Createmethod(30, SteamMatchmaking, SetLobbyMemberLimit);
    Createmethod(31, SteamMatchmaking, GetLobbyMemberLimit);
    Createmethod(32, SteamMatchmaking, SetLobbyType);
    Createmethod(33, SteamMatchmaking, SetLobbyJoinable);
    Createmethod(34, SteamMatchmaking, GetLobbyOwner);
    Createmethod(35, SteamMatchmaking, SetLobbyOwner);
};
SteamMatchmaking009::SteamMatchmaking009()
{
    Createmethod(0, SteamMatchmaking, GetFavoriteGameCount);
    Createmethod(1, SteamMatchmaking, GetFavoriteGame1);
    Createmethod(2, SteamMatchmaking, AddFavoriteGame1);
    Createmethod(3, SteamMatchmaking, RemoveFavoriteGame1);
    Createmethod(4, SteamMatchmaking, RequestLobbyList2);
    Createmethod(5, SteamMatchmaking, AddRequestLobbyListStringFilter);
    Createmethod(6, SteamMatchmaking, AddRequestLobbyListNumericalFilter1);
    Createmethod(7, SteamMatchmaking, AddRequestLobbyListNearValueFilter);
    Createmethod(8, SteamMatchmaking, AddRequestLobbyListFilterSlotsAvailable);
    Createmethod(9, SteamMatchmaking, AddRequestLobbyListDistanceFilter);
    Createmethod(10, SteamMatchmaking, AddRequestLobbyListResultCountFilter);
    Createmethod(11, SteamMatchmaking, AddRequestLobbyListCompatibleMembersFilter);
    Createmethod(12, SteamMatchmaking, GetLobbyByIndex);
    Createmethod(13, SteamMatchmaking, CreateLobby3);
    Createmethod(14, SteamMatchmaking, JoinLobby1);
    Createmethod(15, SteamMatchmaking, LeaveLobby);
    Createmethod(16, SteamMatchmaking, InviteUserToLobby);
    Createmethod(17, SteamMatchmaking, GetNumLobbyMembers);
    Createmethod(18, SteamMatchmaking, GetLobbyMemberByIndex);
    Createmethod(19, SteamMatchmaking, GetLobbyData);
    Createmethod(20, SteamMatchmaking, SetLobbyData1);
    Createmethod(21, SteamMatchmaking, GetLobbyDataCount);
    Createmethod(22, SteamMatchmaking, GetLobbyDataByIndex);
    Createmethod(23, SteamMatchmaking, DeleteLobbyData);
    Createmethod(24, SteamMatchmaking, GetLobbyMemberData);
    Createmethod(25, SteamMatchmaking, SetLobbyMemberData);
    Createmethod(26, SteamMatchmaking, SendLobbyChatMsg);
    Createmethod(27, SteamMatchmaking, GetLobbyChatEntry);
    Createmethod(28, SteamMatchmaking, RequestLobbyData);
    Createmethod(29, SteamMatchmaking, SetLobbyGameServer);
    Createmethod(30, SteamMatchmaking, GetLobbyGameServer);
    Createmethod(31, SteamMatchmaking, SetLobbyMemberLimit);
    Createmethod(32, SteamMatchmaking, GetLobbyMemberLimit);
    Createmethod(33, SteamMatchmaking, SetLobbyType);
    Createmethod(34, SteamMatchmaking, SetLobbyJoinable);
    Createmethod(35, SteamMatchmaking, GetLobbyOwner);
    Createmethod(36, SteamMatchmaking, SetLobbyOwner);
    Createmethod(37, SteamMatchmaking, SetLinkedLobby);
};

struct Steammatchmakingloader
{
    Steammatchmakingloader()
    {
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking001);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking002);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking003);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking004);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking005);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking006);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking007);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking008);
        Createinterface(STEAM_MATCHMAKING, SteamMatchmaking009);
    }
};
static Steammatchmakingloader Interfaceloader{};
