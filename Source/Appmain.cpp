/*
    Initial author: Convery
    Started: 2017-03-27
    License: MIT
*/

#include "StdInclude.h"
#include "Steam/Steam.h"

// Clear the logfile on startup so we only save this session.
namespace { struct Deletelog { Deletelog() { Clearlogfile(); } }; static Deletelog Deleted{}; }

// Ayria plugin exports.
extern "C"
{
    EXPORT_ATTR void __cdecl onInitializationStart(bool Reserved)
    {
        static bool Initialized = false;
        if (Initialized) return;
        else Initialized = true;
        
        constexpr const char *Steamdll = sizeof(size_t) == sizeof(uint64_t) ? "steam_api64.dll" : "steam_api.dll";

        #define PATCH_STEAM_IAT(Function)                                           \
        size_t Address ##Function = GetIATFunction(Steamdll, #Function);            \
        if(Address ##Function) *(size_t *)Address ##Function = size_t(Function);    \

        // Steamworks exports.
        {
            PATCH_STEAM_IAT(SteamAppList);
            PATCH_STEAM_IAT(SteamApps);
            PATCH_STEAM_IAT(SteamClient);
            PATCH_STEAM_IAT(SteamController);
            PATCH_STEAM_IAT(SteamFriends);
            PATCH_STEAM_IAT(SteamGameServer);
            PATCH_STEAM_IAT(SteamGameServerHTTP);
            PATCH_STEAM_IAT(SteamGameServerInventory);
            PATCH_STEAM_IAT(SteamGameServerNetworking);
            PATCH_STEAM_IAT(SteamGameServerStats);
            PATCH_STEAM_IAT(SteamGameServerUGC);
            PATCH_STEAM_IAT(SteamGameServerUtils);
            PATCH_STEAM_IAT(SteamHTMLSurface);
            PATCH_STEAM_IAT(SteamHTTP);
            PATCH_STEAM_IAT(SteamInventory);
            PATCH_STEAM_IAT(SteamMatchmaking);
            PATCH_STEAM_IAT(SteamMatchmakingServers);
            PATCH_STEAM_IAT(SteamMusic);
            PATCH_STEAM_IAT(SteamMusicRemote);
            PATCH_STEAM_IAT(SteamNetworking);
            PATCH_STEAM_IAT(SteamRemoteStorage);
            PATCH_STEAM_IAT(SteamScreenshots);
            PATCH_STEAM_IAT(SteamUnifiedMessages);
            PATCH_STEAM_IAT(SteamUGC);
            PATCH_STEAM_IAT(SteamUser);
            PATCH_STEAM_IAT(SteamUserStats);
            PATCH_STEAM_IAT(SteamUtils);
            PATCH_STEAM_IAT(SteamVideo);
            PATCH_STEAM_IAT(SteamMasterServerUpdater);

            PATCH_STEAM_IAT(SteamAPI_Init);
            PATCH_STEAM_IAT(SteamAPI_InitSafe);
            PATCH_STEAM_IAT(SteamAPI_Shutdown);
            PATCH_STEAM_IAT(SteamAPI_IsSteamRunning);
            PATCH_STEAM_IAT(SteamAPI_GetSteamInstallPath);
            PATCH_STEAM_IAT(SteamAPI_RestartAppIfNecessary);

            PATCH_STEAM_IAT(SteamAPI_RunCallbacks);
            PATCH_STEAM_IAT(SteamAPI_RegisterCallback);
            PATCH_STEAM_IAT(SteamAPI_UnregisterCallback);
            PATCH_STEAM_IAT(SteamAPI_RegisterCallResult);
            PATCH_STEAM_IAT(SteamAPI_UnregisterCallResult);

            PATCH_STEAM_IAT(SteamGameServer_BSecure);
            PATCH_STEAM_IAT(SteamGameServer_Shutdown);
            PATCH_STEAM_IAT(SteamGameServer_RunCallbacks);
            PATCH_STEAM_IAT(SteamGameServer_GetSteamID);
            PATCH_STEAM_IAT(SteamGameServer_Init);
            PATCH_STEAM_IAT(SteamGameServer_InitSafe);
        }
    }
    EXPORT_ATTR void __cdecl onInitializationDone(bool Reserved)
    {
        static bool Initialized = false;
        if (Initialized) return;
        else Initialized = true;
        
        /*
            Usage:
            ----------------------------------------------------------------------
            This callback is called when another module notifies the bootstrapper
            that the game is initialized, or at most 3 seconds after startup. Your
            plugin should do all its .data segment modifications from this func.
        */
    }
    EXPORT_ATTR void __cdecl onMessage(uint32_t MessageID, uint32_t Messagesize, const void *Messagedata)
    {
        /*
            Usage:
            ----------------------------------------------------------------------
            This callback is called when a plugin calls the bootstrapper export to
            broadcast a message to all plugins. The messageID should be unique to
            your plugin so there's no confusion. The data is generally formatted
            as a ByteBuffer structure, but it's not guaranteed to. Use with care.
        */

        // MessageID is a FNV1a_32 hash of a string.
        switch (MessageID)
        {
            case Compiletimehash::FNV1a_32("Platformwrapper_Default"):
            default: break;
        }
    }
}

// Default entrypoint for windows.
#ifdef _WIN32
#include <Windows.h>
BOOLEAN WINAPI DllMain(HINSTANCE hDllHandle, DWORD nReason, LPVOID Reserved)
{
    switch ( nReason )
    {
        case DLL_PROCESS_ATTACH:
        {
            // Rather not handle all thread updates.
            DisableThreadLibraryCalls(hDllHandle);
            break;
        }
    }

    return TRUE;
}
#endif
