/*
    Initial author: Convery
    Started: 2017-4-27
    License: MIT
*/

#include "All.h"

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;

#pragma region Methods
class SteamMasterserverUpdater
{
public:
    void SetActive(bool bActive)
    {
        PrintFunction();
    }
    void SetHeartbeatInterval(int iHeartbeatInterval)
    {
        PrintFunction();
    }
    bool HandleIncomingPacket(const void *pData, int cbData, uint32_t srcIP, uint16_t srcPort)
    {
        PrintFunction();
        return false;
    }
    int GetNextOutgoingPacket(void *pOut, int cbMaxOut, uint32_t *pNetAdr, uint16_t *pPort)
    {
        PrintFunction();
        return 0;
    }
    void SetBasicServerData(unsigned short nProtocolVersion, bool bDedicatedServer, const char *pRegionName, const char *pProductName, unsigned short nMaxReportedClients, bool bPasswordProtected, const char *pGameDescription)
    {
        PrintFunction();
    }
    void ClearAllKeyValues()
    {
        PrintFunction();
    }
    void SetKeyValue(const char *pKey, const char *pValue)
    {
        PrintFunction();
    }
    void NotifyShutdown()
    {
        PrintFunction();
    }
    bool WasRestartRequested()
    {
        PrintFunction();
        return false;
    }
    void ForceHeartbeat()
    {
        PrintFunction();
    }
    bool AddMasterServer(const char *pServerAddress)
    {
        PrintFunction();
        return false;
    }
    bool RemoveMasterServer(const char *pServerAddress)
    {
        PrintFunction();
        return false;
    }
    int GetNumMasterServers()
    {
        PrintFunction();
        return 0;
    }
    int GetMasterServerAddress(int iServer, char *pOut, int outBufferSize)
    {
        PrintFunction();
        return 0;
    }
};
#pragma endregion

SteamMasterserverUpdater001::SteamMasterserverUpdater001()
{
    Createmethod(0, SteamMasterserverUpdater, SetActive);
    Createmethod(1, SteamMasterserverUpdater, SetHeartbeatInterval);
    Createmethod(2, SteamMasterserverUpdater, HandleIncomingPacket);
    Createmethod(3, SteamMasterserverUpdater, GetNextOutgoingPacket);
    Createmethod(4, SteamMasterserverUpdater, SetBasicServerData);
    Createmethod(5, SteamMasterserverUpdater, ClearAllKeyValues);
    Createmethod(6, SteamMasterserverUpdater, SetKeyValue);
    Createmethod(7, SteamMasterserverUpdater, NotifyShutdown);
    Createmethod(8, SteamMasterserverUpdater, WasRestartRequested);
    Createmethod(9, SteamMasterserverUpdater, ForceHeartbeat);
    Createmethod(10, SteamMasterserverUpdater, AddMasterServer);
    Createmethod(11, SteamMasterserverUpdater, RemoveMasterServer);
    Createmethod(12, SteamMasterserverUpdater, GetNumMasterServers);
    Createmethod(13, SteamMasterserverUpdater, GetMasterServerAddress);
};

struct Steambrowserloader
{
    Steambrowserloader()
    {
        Interfacemanager::Addinterface(STEAM_MASTERSERVERUPDATER, "SteamMasterserverUpdater001", new SteamMasterserverUpdater001);
    }
};
static Steambrowserloader Interfaceloader;
