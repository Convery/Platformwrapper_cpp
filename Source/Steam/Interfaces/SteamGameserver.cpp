/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam game hosting.
*/

#include "../../Stdinclude.h"

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;

#pragma region Methods
class SteamGameserver
{
public:
    void LogOn0()
    {
        Printfunction();
    }
    void LogOff()
    {
        Printfunction();
    }
    bool BLoggedOn()
    {
        Printfunction();
        return true;
    }
    void SetSpawnCount(uint32_t ucSpawn)
    {
        Printfunction();
    }
    bool GetSteam2GetEncryptionKeyToSendToNewClient(void *pvEncryptionKey, uint32_t *pcbEncryptionKey, uint32_t cbMaxEncryptionKey)
    {
        Printfunction();
        return false;
    }
    bool SendSteam2UserConnect(uint32_t unUserID, const void *pvRawKey, uint32_t unKeyLen, uint32_t unIPPublic, uint16_t usPort, const void *pvCookie, uint32_t cubCookie)
    {
        Printfunction();
        return false;
    }
    bool SendSteam3UserConnect(CSteamID steamID, uint32_t unIPPublic, const void *pvCookie, uint32_t cubCookie)
    {
        Printfunction();
        return false;
    }
    bool RemoveUserConnect(uint32_t unUserID)
    {
        Printfunction();
        return false;
    }
    bool SendUserDisconnect0(CSteamID steamID, uint32_t unUserID)
    {
        Printfunction();
        return false;
    }
    bool SendUserStatusResponse(CSteamID steamID, int nSecondsConnected, int nSecondsSinceLast)
    {
        Printfunction();
        return false;
    }
    bool Obsolete_GSSetStatus(int32_t nAppIdServed, uint32_t unServerFlags, int cPlayers, int cPlayersMax, int cBotPlayers, int unGamePort, const char *pchServerName, const char *pchGameDir, const char *pchMapName, const char *pchVersion)
    {
        Printfunction();
        return false;
    }
    bool UpdateStatus0(int cPlayers, int cPlayersMax, int cBotPlayers, const char *pchServerName, const char *pchMapName)
    {
        Printfunction();
        return false;
    }
    bool BSecure()
    {
        Printfunction();
        return true;
    }
    CSteamID GetSteamID()
    {
        Printfunction();
        return CSteamID(Steamconfig::UserID);
    }
    bool SetServerType0(int32_t nGameAppId, uint32_t unServerFlags, uint32_t unGameIP, uint32_t unGamePort, const char *pchGameDir, const char *pchVersion)
    {
        Printfunction();
        return false;
    }
    bool SetServerType1(int32_t nGameAppId, uint32_t unServerFlags, uint32_t unGameIP, uint16_t unGamePort, uint16_t usSpectatorPort, uint16_t usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode)
    {
        Printfunction();
        return false;
    }
    bool UpdateStatus1(int cPlayers, int cPlayersMax, int cBotPlayers, const char *pchServerName, const char *pSpectatorServerName, const char *pchMapName)
    {
        Printfunction();
        return false;
    }
    bool CreateUnauthenticatedUser(CSteamID *pSteamID)
    {
        Printfunction();
        return false;
    }
    bool SetUserData(CSteamID steamIDUser, const char *pchPlayerName, uint32_t uScore)
    {
        Printfunction();
        return false;
    }
    void UpdateSpectatorPort(uint16_t unSpectatorPort)
    {
        Printfunction();
    }
    void SetGameType(const char *pchGameType)
    {
        Printfunction();
    }
    bool SendUserConnect(uint32_t, uint32_t, uint16_t, const void *, uint32_t)
    {
        Printfunction();
        return false;
    }
    bool GetUserAchievementStatus(CSteamID steamID, const char *pchAchievementName)
    {
        Printfunction();
        return false;
    }
    bool SendUserConnectAndAuthenticate0(CSteamID steamIDUser, uint32_t, void *, uint32_t)
    {
        Printfunction();
        return false;
    }
    CSteamID CreateUnauthenticatedUserConnection()
    {
        Printfunction();
        return CSteamID(Steamconfig::UserID);
    }
    void SendUserDisconnect1(CSteamID steamIDUser)
    {
        Printfunction();
    }
    bool BUpdateUserData(CSteamID steamIDUser, const char *pchPlayerName, uint32_t uScore)
    {
        Printfunction();
        return false;
    }
    bool BSetServerType0(int32_t nGameAppId, uint32_t unServerFlags, uint32_t unGameIP, uint16_t unGamePort, uint16_t usSpectatorPort, uint16_t usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode)
    {
        Printfunction();
        return false;
    }
    bool BGetUserAchievementStatus(CSteamID steamID, const char *pchAchievementName)
    {
        Printfunction();
        return false;
    }
    bool SendUserConnectAndAuthenticate1(uint32_t unIPClient, const void *pvAuthBlob, uint32_t cubAuthBlobSize, CSteamID *pSteamIDUser)
    {
        Printfunction();
        return false;
    }
    bool BSetServerType1(uint32_t unServerFlags, uint32_t unGameIP, uint16_t unGamePort, uint16_t unSpectatorPort, uint16_t usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode)
    {
        Printfunction();
        return false;
    }
    void UpdateServerStatus(int cPlayers, int cPlayersMax, int cBotPlayers, const char *pchServerName, const char *pSpectatorServerName, const char *pchMapName)
    {
        Printfunction();
    }
    void GetGameplayStats()
    {
        Printfunction();
    }
    bool RequestUserGroupStatus(CSteamID steamIDUser, CSteamID steamIDGroup)
    {
        Printfunction();
        return false;
    }
    uint32_t GetPublicIP()
    {
        Printfunction();
        return 0;
    }
    uint32_t UserHasLicenseForApp(CSteamID steamID, uint32_t appID)
    {
        Printfunction();
        return 0;
    }
    void SetGameTags(const char *pchGameTags)
    {
        Printfunction();
    }
    uint64_t GetServerReputation()
    {
        Printfunction();
        return 0;
    }
    uint32_t GetAuthSessionTicket(void *pTicket, int cbMaxTicket, uint32_t *pcbTicket)
    {
        Printfunction();
        return 0;
    }
    uint32_t BeginAuthSession(const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
    {
        Printfunction();
        return 0;
    }
    void EndAuthSession(CSteamID steamID)
    {
        Printfunction();
    }
    void CancelAuthTicket(uint32_t hAuthTicket)
    {
        Printfunction();
    }
    bool InitGameServer(uint32_t unGameIP, uint16_t unGamePort, uint16_t usQueryPort, uint32_t unServerFlags, uint32_t nAppID, const char *pchVersion)
    {
        Printfunction();
        return true;
    }
    void SetProduct(const char *pchProductName)
    {
        Printfunction();
    }
    void SetGameDescription(const char *pchGameDescription)
    {
        Printfunction();
    }
    void SetModDir(const char *pchModDir)
    {
        Printfunction();
    }
    void SetDedicatedServer(bool bDedicatedServer)
    {
        Printfunction();
    }
    void LogOn1(const char *pszAccountName, const char *pszPassword)
    {
        Printfunction();
    }
    void LogOnAnonymous()
    {
        Printfunction();
    }
    bool WasRestartRequested()
    {
        Printfunction();
        return false;
    }
    void SetMaxPlayerCount(int cPlayersMax)
    {
        Printfunction();
    }
    void SetBotPlayerCount(int cBotPlayers)
    {
        Printfunction();
    }
    void SetServerName(const char *pszServerName)
    {
        Printfunction();
    }
    void SetMapName(const char *pszMapName)
    {
        Printfunction();
    }
    void SetPasswordProtected(bool bPasswordProtected)
    {
        Printfunction();
    }
    void SetSpectatorPort(uint16_t unSpectatorPort)
    {
        Printfunction();
    }
    void SetSpectatorServerName(const char *pszSpectatorServerName)
    {
        Printfunction();
    }
    void ClearAllKeyValues()
    {
        Printfunction();
    }
    void SetKeyValue(const char *pKey, const char *pValue)
    {
        Printfunction();
    }
    void SetGameData(const char *pchGameData)
    {
        Printfunction();
    }
    void SetRegion(const char *pchRegionName)
    {
        Printfunction();
    }
    int SendUserConnectAndAuthenticate2(uint32_t unIPClient, const void *pvAuthBlob, uint32_t cubAuthBlobSize, CSteamID *pSteamIDUser)
    {
        Printfunction();
        return 0;
    }
    bool HandleIncomingPacket(const void *pData, int cbData, uint32_t srcIP, uint16_t srcPort)
    {
        Printfunction();
        return false;
    }
    int GetNextOutgoingPacket(void *pOut, int cbMaxOut, uint32_t *pNetAdr, uint16_t *pPort)
    {
        Printfunction();
        return 0;
    }
    void EnableHeartbeats(bool bActive)
    {
        Printfunction();
    }
    void SetHeartbeatInterval(int iHeartbeatInterval)
    {
        Printfunction();
    }
    void ForceHeartbeat()
    {
        Printfunction();
    }
    uint64_t AssociateWithClan(CSteamID clanID)
    {
        Printfunction();
        return 0;
    }
    uint64_t ComputeNewPlayerCompatibility(CSteamID steamID)
    {
        Printfunction();
        return 0;
    }
    void LogOn2(const char *pszUnk)
    {
        Printfunction();
    }
};
#pragma endregion

SteamGameserver001::SteamGameserver001()
{
    /* No steamworks SDK info */
};
SteamGameserver002::SteamGameserver002()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, SetSpawnCount);
    Createmethod(4, SteamGameserver, GetSteam2GetEncryptionKeyToSendToNewClient);
    Createmethod(5, SteamGameserver, SendSteam2UserConnect);
    Createmethod(6, SteamGameserver, SendSteam3UserConnect);
    Createmethod(7, SteamGameserver, RemoveUserConnect);
    Createmethod(8, SteamGameserver, SendUserDisconnect0);
    Createmethod(9, SteamGameserver, SendUserStatusResponse);
    Createmethod(10, SteamGameserver, Obsolete_GSSetStatus);
    Createmethod(11, SteamGameserver, UpdateStatus0);
    Createmethod(12, SteamGameserver, BSecure);
    Createmethod(13, SteamGameserver, GetSteamID);
    Createmethod(14, SteamGameserver, SetServerType0);
    Createmethod(15, SteamGameserver, SetServerType1);
    Createmethod(16, SteamGameserver, UpdateStatus1);
    Createmethod(17, SteamGameserver, CreateUnauthenticatedUser);
    Createmethod(18, SteamGameserver, SetUserData);
    Createmethod(19, SteamGameserver, UpdateSpectatorPort);
    Createmethod(20, SteamGameserver, SetGameType);
};
SteamGameserver003::SteamGameserver003()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, GetSteamID);
    Createmethod(4, SteamGameserver, GetSteam2GetEncryptionKeyToSendToNewClient);
    Createmethod(5, SteamGameserver, SendUserConnect);
    Createmethod(6, SteamGameserver, RemoveUserConnect);
    Createmethod(7, SteamGameserver, SendUserDisconnect0);
    Createmethod(8, SteamGameserver, SetSpawnCount);
    Createmethod(9, SteamGameserver, SetServerType1);
    Createmethod(10, SteamGameserver, UpdateStatus1);
    Createmethod(11, SteamGameserver, CreateUnauthenticatedUser);
    Createmethod(12, SteamGameserver, SetUserData);
    Createmethod(13, SteamGameserver, UpdateSpectatorPort);
    Createmethod(14, SteamGameserver, SetGameType);
    Createmethod(15, SteamGameserver, GetUserAchievementStatus);
};
SteamGameserver004::SteamGameserver004()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, BSecure);
    Createmethod(4, SteamGameserver, GetSteamID);
    Createmethod(5, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(6, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(7, SteamGameserver, SendUserDisconnect1);
    Createmethod(8, SteamGameserver, BUpdateUserData);
    Createmethod(9, SteamGameserver, BSetServerType1);
    Createmethod(10, SteamGameserver, UpdateServerStatus);
    Createmethod(11, SteamGameserver, UpdateSpectatorPort);
    Createmethod(12, SteamGameserver, SetGameType);
    Createmethod(13, SteamGameserver, BGetUserAchievementStatus);
    Createmethod(14, SteamGameserver, GetGameplayStats);
};
SteamGameserver005::SteamGameserver005()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, BSecure);
    Createmethod(4, SteamGameserver, GetSteamID);
    Createmethod(5, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(6, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(7, SteamGameserver, SendUserDisconnect1);
    Createmethod(8, SteamGameserver, BUpdateUserData);
    Createmethod(9, SteamGameserver, BSetServerType1);
    Createmethod(10, SteamGameserver, UpdateServerStatus);
    Createmethod(11, SteamGameserver, UpdateSpectatorPort);
    Createmethod(12, SteamGameserver, SetGameType);
    Createmethod(13, SteamGameserver, BGetUserAchievementStatus);
    Createmethod(14, SteamGameserver, GetGameplayStats);
};
SteamGameserver006::SteamGameserver006()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, BSecure);
    Createmethod(4, SteamGameserver, GetSteamID);
    Createmethod(5, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(6, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(7, SteamGameserver, SendUserDisconnect1);
    Createmethod(8, SteamGameserver, BUpdateUserData);
    Createmethod(9, SteamGameserver, BSetServerType1);
    Createmethod(10, SteamGameserver, UpdateServerStatus);
    Createmethod(11, SteamGameserver, UpdateSpectatorPort);
    Createmethod(12, SteamGameserver, SetGameType);
    Createmethod(13, SteamGameserver, BGetUserAchievementStatus);
    Createmethod(14, SteamGameserver, GetGameplayStats);
    Createmethod(15, SteamGameserver, RequestUserGroupStatus);
};
SteamGameserver007::SteamGameserver007()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, BSecure);
    Createmethod(4, SteamGameserver, GetSteamID);
    Createmethod(5, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(6, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(7, SteamGameserver, SendUserDisconnect1);
    Createmethod(8, SteamGameserver, BUpdateUserData);
    Createmethod(9, SteamGameserver, BSetServerType1);
    Createmethod(10, SteamGameserver, UpdateServerStatus);
    Createmethod(11, SteamGameserver, UpdateSpectatorPort);
    Createmethod(12, SteamGameserver, SetGameType);
    Createmethod(13, SteamGameserver, BGetUserAchievementStatus);
    Createmethod(14, SteamGameserver, GetGameplayStats);
    Createmethod(15, SteamGameserver, RequestUserGroupStatus);
    Createmethod(16, SteamGameserver, GetPublicIP);
};
SteamGameserver008::SteamGameserver008()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, BSecure);
    Createmethod(4, SteamGameserver, GetSteamID);
    Createmethod(5, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(6, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(7, SteamGameserver, SendUserDisconnect1);
    Createmethod(8, SteamGameserver, BUpdateUserData);
    Createmethod(9, SteamGameserver, BSetServerType1);
    Createmethod(10, SteamGameserver, UpdateServerStatus);
    Createmethod(11, SteamGameserver, UpdateSpectatorPort);
    Createmethod(12, SteamGameserver, SetGameType);
    Createmethod(13, SteamGameserver, BGetUserAchievementStatus);
    Createmethod(14, SteamGameserver, GetGameplayStats);
    Createmethod(15, SteamGameserver, RequestUserGroupStatus);
    Createmethod(16, SteamGameserver, GetPublicIP);
    Createmethod(17, SteamGameserver, SetGameData);
    Createmethod(18, SteamGameserver, UserHasLicenseForApp);
};
SteamGameserver009::SteamGameserver009()
{
    Createmethod(0, SteamGameserver, LogOn0);
    Createmethod(1, SteamGameserver, LogOff);
    Createmethod(2, SteamGameserver, BLoggedOn);
    Createmethod(3, SteamGameserver, BSecure);
    Createmethod(4, SteamGameserver, GetSteamID);
    Createmethod(5, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(6, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(7, SteamGameserver, SendUserDisconnect1);
    Createmethod(8, SteamGameserver, BUpdateUserData);
    Createmethod(9, SteamGameserver, UpdateSpectatorPort);
    Createmethod(10, SteamGameserver, SetGameTags);
    Createmethod(11, SteamGameserver, GetGameplayStats);
    Createmethod(12, SteamGameserver, GetServerReputation);
    Createmethod(13, SteamGameserver, RequestUserGroupStatus);
    Createmethod(14, SteamGameserver, GetPublicIP);
    Createmethod(15, SteamGameserver, SetGameData);
    Createmethod(16, SteamGameserver, UserHasLicenseForApp);
    Createmethod(17, SteamGameserver, GetAuthSessionTicket);
    Createmethod(18, SteamGameserver, BeginAuthSession);
    Createmethod(19, SteamGameserver, EndAuthSession);
    Createmethod(20, SteamGameserver, CancelAuthTicket);
};
SteamGameserver010::SteamGameserver010()
{
    Createmethod(0, SteamGameserver, InitGameServer);
    Createmethod(1, SteamGameserver, SetProduct);
    Createmethod(2, SteamGameserver, SetGameDescription);
    Createmethod(3, SteamGameserver, SetModDir);
    Createmethod(4, SteamGameserver, SetDedicatedServer);
    Createmethod(5, SteamGameserver, LogOn1);
    Createmethod(6, SteamGameserver, LogOnAnonymous);
    Createmethod(7, SteamGameserver, LogOff);
    Createmethod(8, SteamGameserver, BLoggedOn);
    Createmethod(9, SteamGameserver, BSecure);
    Createmethod(10, SteamGameserver, GetSteamID);
    Createmethod(11, SteamGameserver, WasRestartRequested);
    Createmethod(12, SteamGameserver, SetMaxPlayerCount);
    Createmethod(13, SteamGameserver, SetBotPlayerCount);
    Createmethod(14, SteamGameserver, SetServerName);
    Createmethod(15, SteamGameserver, SetMapName);
    Createmethod(16, SteamGameserver, SetPasswordProtected);
    Createmethod(17, SteamGameserver, SetSpectatorPort);
    Createmethod(18, SteamGameserver, SetSpectatorServerName);
    Createmethod(19, SteamGameserver, ClearAllKeyValues);
    Createmethod(20, SteamGameserver, SetKeyValue);
    Createmethod(21, SteamGameserver, SetGameTags);
    Createmethod(22, SteamGameserver, SetGameData);
    Createmethod(23, SteamGameserver, SetRegion);
    Createmethod(24, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(25, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(26, SteamGameserver, SendUserDisconnect1);
    Createmethod(27, SteamGameserver, BUpdateUserData);
    Createmethod(28, SteamGameserver, GetAuthSessionTicket);
    Createmethod(29, SteamGameserver, BeginAuthSession);
    Createmethod(30, SteamGameserver, EndAuthSession);
    Createmethod(31, SteamGameserver, CancelAuthTicket);
    Createmethod(32, SteamGameserver, UserHasLicenseForApp);
    Createmethod(33, SteamGameserver, RequestUserGroupStatus);
    Createmethod(34, SteamGameserver, GetGameplayStats);
    Createmethod(35, SteamGameserver, GetServerReputation);
    Createmethod(36, SteamGameserver, GetPublicIP);
    Createmethod(37, SteamGameserver, HandleIncomingPacket);
    Createmethod(38, SteamGameserver, GetNextOutgoingPacket);
    Createmethod(39, SteamGameserver, EnableHeartbeats);
    Createmethod(40, SteamGameserver, SetHeartbeatInterval);
    Createmethod(41, SteamGameserver, ForceHeartbeat);
    Createmethod(42, SteamGameserver, AssociateWithClan);
    Createmethod(43, SteamGameserver, ComputeNewPlayerCompatibility);
};
SteamGameserver011::SteamGameserver011()
{
    Createmethod(0, SteamGameserver, InitGameServer);
    Createmethod(1, SteamGameserver, SetProduct);
    Createmethod(2, SteamGameserver, SetGameDescription);
    Createmethod(3, SteamGameserver, SetModDir);
    Createmethod(4, SteamGameserver, SetDedicatedServer);
    Createmethod(5, SteamGameserver, LogOn2);
    Createmethod(6, SteamGameserver, LogOnAnonymous);
    Createmethod(7, SteamGameserver, LogOff);
    Createmethod(8, SteamGameserver, BLoggedOn);
    Createmethod(9, SteamGameserver, BSecure);
    Createmethod(10, SteamGameserver, GetSteamID);
    Createmethod(11, SteamGameserver, WasRestartRequested);
    Createmethod(12, SteamGameserver, SetMaxPlayerCount);
    Createmethod(13, SteamGameserver, SetBotPlayerCount);
    Createmethod(14, SteamGameserver, SetServerName);
    Createmethod(15, SteamGameserver, SetMapName);
    Createmethod(16, SteamGameserver, SetPasswordProtected);
    Createmethod(17, SteamGameserver, SetSpectatorPort);
    Createmethod(18, SteamGameserver, SetSpectatorServerName);
    Createmethod(19, SteamGameserver, ClearAllKeyValues);
    Createmethod(20, SteamGameserver, SetKeyValue);
    Createmethod(21, SteamGameserver, SetGameTags);
    Createmethod(22, SteamGameserver, SetGameData);
    Createmethod(23, SteamGameserver, SetRegion);
    Createmethod(24, SteamGameserver, SendUserConnectAndAuthenticate1);
    Createmethod(25, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(26, SteamGameserver, SendUserDisconnect1);
    Createmethod(27, SteamGameserver, BUpdateUserData);
    Createmethod(28, SteamGameserver, GetAuthSessionTicket);
    Createmethod(29, SteamGameserver, BeginAuthSession);
    Createmethod(30, SteamGameserver, EndAuthSession);
    Createmethod(31, SteamGameserver, CancelAuthTicket);
    Createmethod(32, SteamGameserver, UserHasLicenseForApp);
    Createmethod(33, SteamGameserver, RequestUserGroupStatus);
    Createmethod(34, SteamGameserver, GetGameplayStats);
    Createmethod(35, SteamGameserver, GetServerReputation);
    Createmethod(36, SteamGameserver, GetPublicIP);
    Createmethod(37, SteamGameserver, HandleIncomingPacket);
    Createmethod(38, SteamGameserver, GetNextOutgoingPacket);
    Createmethod(39, SteamGameserver, EnableHeartbeats);
    Createmethod(40, SteamGameserver, SetHeartbeatInterval);
    Createmethod(41, SteamGameserver, ForceHeartbeat);
    Createmethod(42, SteamGameserver, AssociateWithClan);
    Createmethod(43, SteamGameserver, ComputeNewPlayerCompatibility);
};
SteamGameserver012::SteamGameserver012()
{
    Createmethod(0, SteamGameserver, InitGameServer);
    Createmethod(1, SteamGameserver, SetProduct);
    Createmethod(2, SteamGameserver, SetGameDescription);
    Createmethod(3, SteamGameserver, SetModDir);
    Createmethod(4, SteamGameserver, SetDedicatedServer);
    Createmethod(5, SteamGameserver, LogOn2);
    Createmethod(6, SteamGameserver, LogOnAnonymous);
    Createmethod(7, SteamGameserver, LogOff);
    Createmethod(8, SteamGameserver, BLoggedOn);
    Createmethod(9, SteamGameserver, BSecure);
    Createmethod(10, SteamGameserver, GetSteamID);
    Createmethod(11, SteamGameserver, WasRestartRequested);
    Createmethod(12, SteamGameserver, SetMaxPlayerCount);
    Createmethod(13, SteamGameserver, SetBotPlayerCount);
    Createmethod(14, SteamGameserver, SetServerName);
    Createmethod(15, SteamGameserver, SetMapName);
    Createmethod(16, SteamGameserver, SetPasswordProtected);
    Createmethod(17, SteamGameserver, SetSpectatorPort);
    Createmethod(18, SteamGameserver, SetSpectatorServerName);
    Createmethod(19, SteamGameserver, ClearAllKeyValues);
    Createmethod(20, SteamGameserver, SetKeyValue);
    Createmethod(21, SteamGameserver, SetGameTags);
    Createmethod(22, SteamGameserver, SetGameData);
    Createmethod(23, SteamGameserver, SetRegion);
    Createmethod(24, SteamGameserver, SendUserConnectAndAuthenticate2);
    Createmethod(25, SteamGameserver, CreateUnauthenticatedUserConnection);
    Createmethod(26, SteamGameserver, SendUserDisconnect1);
    Createmethod(27, SteamGameserver, BUpdateUserData);
    Createmethod(28, SteamGameserver, GetAuthSessionTicket);
    Createmethod(29, SteamGameserver, BeginAuthSession);
    Createmethod(30, SteamGameserver, EndAuthSession);
    Createmethod(31, SteamGameserver, CancelAuthTicket);
    Createmethod(32, SteamGameserver, UserHasLicenseForApp);
    Createmethod(33, SteamGameserver, RequestUserGroupStatus);
    Createmethod(34, SteamGameserver, GetGameplayStats);
    Createmethod(35, SteamGameserver, GetServerReputation);
    Createmethod(36, SteamGameserver, GetPublicIP);
    Createmethod(37, SteamGameserver, HandleIncomingPacket);
    Createmethod(38, SteamGameserver, GetNextOutgoingPacket);
    Createmethod(39, SteamGameserver, EnableHeartbeats);
    Createmethod(40, SteamGameserver, SetHeartbeatInterval);
    Createmethod(41, SteamGameserver, ForceHeartbeat);
    Createmethod(42, SteamGameserver, AssociateWithClan);
    Createmethod(43, SteamGameserver, ComputeNewPlayerCompatibility);
};

struct Steamgameserverloader
{
    Steamgameserverloader()
    {
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver001", new SteamGameserver001);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver002", new SteamGameserver002);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver003", new SteamGameserver003);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver004", new SteamGameserver004);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver005", new SteamGameserver005);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver006", new SteamGameserver006);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver007", new SteamGameserver007);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver008", new SteamGameserver008);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver009", new SteamGameserver009);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver010", new SteamGameserver010);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver011", new SteamGameserver011);
        Interfacemanager::Addinterface(STEAM_GAMESERVER, "SteamGameserver012", new SteamGameserver012);
    }
};
static Steamgameserverloader Interfaceloader{};
