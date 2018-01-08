/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam exports for IAT hooking.
*/

#pragma once
#include "../Stdinclude.hpp"
#include "Subsystem/CSteamID.h"

// Configuration.
namespace Steamconfig
{
    // Application info.
    extern char Language[32];
    extern uint32_t ApplicationID;
    extern uint64_t Startuptimestamp;

    // Network access.
    extern bool LAN;
    extern bool Server;
    extern bool Offline;

    // User information.
    extern char Path[260];
    extern uint64_t UserID;
    extern char Username[17];
}

// Exports.
extern "C"
{
    // Interface access.
    EXPORT_ATTR void *SteamInternal_CreateInterface(const char *Interfacename);
    EXPORT_ATTR void *SteamAppList();
    EXPORT_ATTR void *SteamApps();
    EXPORT_ATTR void *SteamClient();
    EXPORT_ATTR void *SteamController();
    EXPORT_ATTR void *SteamFriends();
    EXPORT_ATTR void *SteamGameServer();
    EXPORT_ATTR void *SteamGameServerHTTP();
    EXPORT_ATTR void *SteamGameServerInventory();
    EXPORT_ATTR void *SteamGameServerNetworking();
    EXPORT_ATTR void *SteamGameServerStats();
    EXPORT_ATTR void *SteamGameServerUGC();
    EXPORT_ATTR void *SteamGameServerUtils();
    EXPORT_ATTR void *SteamHTMLSurface();
    EXPORT_ATTR void *SteamHTTP();
    EXPORT_ATTR void *SteamInventory();
    EXPORT_ATTR void *SteamMatchmaking();
    EXPORT_ATTR void *SteamMatchmakingServers();
    EXPORT_ATTR void *SteamMusic();
    EXPORT_ATTR void *SteamMusicRemote();
    EXPORT_ATTR void *SteamNetworking();
    EXPORT_ATTR void *SteamRemoteStorage();
    EXPORT_ATTR void *SteamScreenshots();
    EXPORT_ATTR void *SteamUnifiedMessages();
    EXPORT_ATTR void *SteamUGC();
    EXPORT_ATTR void *SteamUser();
    EXPORT_ATTR void *SteamUserStats();
    EXPORT_ATTR void *SteamUtils();
    EXPORT_ATTR void *SteamVideo();
    EXPORT_ATTR void *SteamMasterServerUpdater();

    // Initialization and shutdown.
    EXPORT_ATTR bool SteamAPI_Init();
    EXPORT_ATTR bool SteamAPI_InitSafe();
    EXPORT_ATTR void SteamAPI_Shutdown();
    EXPORT_ATTR bool SteamAPI_IsSteamRunning();
    EXPORT_ATTR const char *SteamAPI_GetSteamInstallPath();
    EXPORT_ATTR bool SteamAPI_RestartAppIfNecessary(uint32_t unOwnAppID);

    // Direct connections to Steam.
    EXPORT_ATTR int32_t SteamAPI_GetHSteamUser();
    EXPORT_ATTR int32_t SteamAPI_GetHSteamPipe();
    EXPORT_ATTR int32_t SteamGameServer_GetHSteamUser();
    EXPORT_ATTR int32_t SteamGameServer_GetHSteamPipe();

    // Callback management.
    EXPORT_ATTR void SteamAPI_RunCallbacks();
    EXPORT_ATTR void SteamAPI_RegisterCallback(void *pCallback, int iCallback);
    EXPORT_ATTR void SteamAPI_UnregisterCallback(void *pCallback, int iCallback);
    EXPORT_ATTR void SteamAPI_RegisterCallResult(void *pCallback, uint64_t hAPICall);
    EXPORT_ATTR void SteamAPI_UnregisterCallResult(void *pCallback, uint64_t hAPICall);

    // Dedicated server mode.
    EXPORT_ATTR bool SteamGameServer_BSecure();
    EXPORT_ATTR void SteamGameServer_Shutdown();
    EXPORT_ATTR void SteamGameServer_RunCallbacks();
    EXPORT_ATTR uint64_t SteamGameServer_GetSteamID();
    EXPORT_ATTR bool SteamGameServer_Init(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, uint32_t eServerMode, const char *pchVersionString);
    EXPORT_ATTR bool SteamGameServer_InitSafe(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, uint32_t eServerMode, const char *pchVersionString);
    EXPORT_ATTR bool SteamInternal_GameServer_Init(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, uint32_t eServerMode, const char *pchVersionString);
}
