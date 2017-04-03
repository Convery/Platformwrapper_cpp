/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#include "Steam.h"

// Registry and environment.
#ifdef _WIN32
#include <Windows.h>
#endif

// Steam components.
constexpr const char *Gameoverlay = sizeof(void *) == 8 ? "gameoverlayrenderer64.dll" : "gameoverlayrenderer.dll";
constexpr const char *Steamregistry = sizeof(void *) == 8 ? "Software\\Wow6432Node\\Valve\\Steam" : "Software\\Valve\\Steam";

extern "C"
{
    // Interface access.
    EXPORT_ATTR void *SteamAppList()
    {
        return Interfacemanager::Fetchinterface(STEAM_APPLIST);
    }
    EXPORT_ATTR void *SteamApps()
    {
        return Interfacemanager::Fetchinterface(STEAM_APPS);
    }
    EXPORT_ATTR void *SteamClient()
    {
        return Interfacemanager::Fetchinterface(STEAM_CLIENT);
    }
    EXPORT_ATTR void *SteamController()
    {
        return Interfacemanager::Fetchinterface(STEAM_CONTROLLER);
    }
    EXPORT_ATTR void *SteamFriends()
    {
        return Interfacemanager::Fetchinterface(STEAM_FRIENDS);
    }
    EXPORT_ATTR void *SteamGameServer()
    {
        return Interfacemanager::Fetchinterface(STEAM_GAMESERVER);
    }
    EXPORT_ATTR void *SteamGameServerHTTP()
    {
        return Interfacemanager::Fetchinterface(STEAM_HTTP);
    }
    EXPORT_ATTR void *SteamGameServerInventory()
    {
        return Interfacemanager::Fetchinterface(STEAM_INVENTORY);
    }
    EXPORT_ATTR void *SteamGameServerNetworking()
    {
        return Interfacemanager::Fetchinterface(STEAM_NETWORKING);
    }
    EXPORT_ATTR void *SteamGameServerStats()
    {
        return Interfacemanager::Fetchinterface(STEAM_GAMESERVERSTATS);
    }
    EXPORT_ATTR void *SteamGameServerUGC()
    {
        return Interfacemanager::Fetchinterface(STEAM_UGC);
    }
    EXPORT_ATTR void *SteamGameServerUtils()
    {
        return Interfacemanager::Fetchinterface(STEAM_UTILS);
    }
    EXPORT_ATTR void *SteamHTMLSurface()
    {
        return Interfacemanager::Fetchinterface(STEAM_HTMLSURFACE);
    }
    EXPORT_ATTR void *SteamHTTP()
    {
        return Interfacemanager::Fetchinterface(STEAM_HTTP);
    }
    EXPORT_ATTR void *SteamInventory()
    {
        return Interfacemanager::Fetchinterface(STEAM_INVENTORY);
    }
    EXPORT_ATTR void *SteamMatchmaking()
    {
        return Interfacemanager::Fetchinterface(STEAM_MATCHMAKING);
    }
    EXPORT_ATTR void *SteamMatchmakingServers()
    {
        return Interfacemanager::Fetchinterface(STEAM_MATCHMAKINGSERVERS);
    }
    EXPORT_ATTR void *SteamMusic()
    {
        return Interfacemanager::Fetchinterface(STEAM_MUSIC);
    }
    EXPORT_ATTR void *SteamMusicRemote()
    {
        return Interfacemanager::Fetchinterface(STEAM_MUSICREMOTE);
    }
    EXPORT_ATTR void *SteamNetworking()
    {
        return Interfacemanager::Fetchinterface(STEAM_NETWORKING);
    }
    EXPORT_ATTR void *SteamRemoteStorage()
    {
        return Interfacemanager::Fetchinterface(STEAM_REMOTESTORAGE);
    }
    EXPORT_ATTR void *SteamScreenshots()
    {
        return Interfacemanager::Fetchinterface(STEAM_SCREENSHOTS);
    }
    EXPORT_ATTR void *SteamUnifiedMessages()
    {
        return Interfacemanager::Fetchinterface(STEAM_UNIFIEDMESSAGES);
    }
    EXPORT_ATTR void *SteamUGC()
    {
        return Interfacemanager::Fetchinterface(STEAM_UGC);
    }
    EXPORT_ATTR void *SteamUser()
    {
        return Interfacemanager::Fetchinterface(STEAM_USER);
    }
    EXPORT_ATTR void *SteamUserStats()
    {
        return Interfacemanager::Fetchinterface(STEAM_USERSTATS);
    }
    EXPORT_ATTR void *SteamUtils()
    {
        return Interfacemanager::Fetchinterface(STEAM_UTILS);
    }
    EXPORT_ATTR void *SteamVideo()
    {
        return Interfacemanager::Fetchinterface(STEAM_VIDEO);
    }
    EXPORT_ATTR void *SteamMasterServerUpdater()
    {
        return Interfacemanager::Fetchinterface(STEAM_MASTERSERVERUPDATER);
    }

    // Initialization and shutdown.
    EXPORT_ATTR bool SteamAPI_Init()
    {
        PrintFunction();

        // Check if we are forcing offline mode.
        for (int i = 0; i < __argc && !Steamconfig::Offline; ++i)
            Steamconfig::Offline = nullptr != std::strstr(__argv[i], "-AYRIA_OFFLINE");

        // Read the application ID from a file if the host
        // is too old to use RestartApp or a dev build.
        if (Steamconfig::ApplicationID == 0)
        {
            FILE *Filehandle;

            // Open the configuration file.
            Filehandle = fopen("steam_appid.txt", "r");
            if (!Filehandle) Filehandle = fopen("ayria_appid.txt", "r");
            if (!Filehandle)
            {
                DebugPrint("No appconfig file found. Exiting.");
                exit(0xDEAD);
            }

            // Read the uint32.
            fscanf_s(Filehandle, "%u", &Steamconfig::ApplicationID);
            fclose(Filehandle);
        }

        // If no application ID is provided, we can't do much.
        if (Steamconfig::ApplicationID == 0)
        {
            InfoPrint("No application ID has been provided to the wrapper.");
            InfoPrint("This will probably cause errors. Contact the developer.");
        }

#ifdef _WIN32
        // Set the environment variable for games that use it.
        SetEnvironmentVariableA("SteamAppId", va("%lu", Steamconfig::ApplicationID).c_str());
        SetEnvironmentVariableA("SteamGameId", va("%llu", Steamconfig::ApplicationID & 0xFFFFFF).c_str());

        // Get the install directory.
        HKEY hRegKey;
        unsigned long Size = 260;
        if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, Steamregistry, 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
        {
            RegQueryValueExA(hRegKey, "InstallPath", NULL, NULL, (BYTE*)Steamconfig::Path, &Size);
            RegCloseKey(hRegKey);
        }

        // Add the active process to the registry.
        if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Valve\\Steam\\ActiveProcess", 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
        {
            DWORD UserID = Steamconfig::UserID & 0xffffffff;
            DWORD ProcessID = GetCurrentProcessId();
            std::string Clientpath32 = va("%s\\steamclient.dll", Steamconfig::Path);
            std::string Clientpath64 = va("%s\\steamclient64.dll", Steamconfig::Path);

            RegSetValueExA(hRegKey, "ActiveUser", NULL, REG_DWORD, (LPBYTE)&UserID, sizeof(DWORD));
            RegSetValueExA(hRegKey, "pid", NULL, REG_DWORD, (LPBYTE)&ProcessID, sizeof(DWORD));
            RegSetValueExA(hRegKey, "SteamClientDll", NULL, REG_SZ, (LPBYTE)Clientpath32.c_str(), Clientpath32.length() + 1);
            RegSetValueExA(hRegKey, "SteamClientDll64", NULL, REG_SZ, (LPBYTE)Clientpath64.c_str(), Clientpath64.length() + 1);
            RegSetValueExA(hRegKey, "Universe", NULL, REG_SZ, (LPBYTE)"Public", (DWORD)std::strlen("Public") + 1);

            RegCloseKey(hRegKey);
        }

        // Set the game to active.
        DWORD dwDisposition;
        if (RegCreateKeyExA(HKEY_CURRENT_USER, va("Software\\Valve\\Steam\\Apps\\%i", Steamconfig::ApplicationID).c_str(), 0, NULL, 0, KEY_WRITE, NULL, &hRegKey, &dwDisposition) == ERROR_SUCCESS)
        {
            DWORD Running = TRUE;

            RegSetValueExA(hRegKey, "Installed", NULL, REG_DWORD, (LPBYTE)&Running, sizeof(DWORD));
            RegSetValueExA(hRegKey, "Running", NULL, REG_DWORD, (LPBYTE)&Running, sizeof(DWORD));

            RegCloseKey(hRegKey);
        }

        // Load the overlay.
        SetDllDirectoryA(Steamconfig::Path);
        LoadLibraryA(va("%s\\%s", Steamconfig::Path, Gameoverlay).c_str());
#endif

        // Initialize the interface manager.
        Interfacemanager::Initialize();
        return true;
    }
    EXPORT_ATTR bool SteamAPI_InitSafe()
    {
        return SteamAPI_Init();
    }
    EXPORT_ATTR void SteamAPI_Shutdown()
    {
    }
    EXPORT_ATTR bool SteamAPI_IsSteamRunning()
    {
        return true;
    }
    EXPORT_ATTR const char *SteamAPI_GetSteamInstallPath()
    {
        return Steamconfig::Path;
    }
    EXPORT_ATTR bool SteamAPI_RestartAppIfNecessary(uint32_t unOwnAppID)
    {
        // The host application reports a ID on startup.
        Steamconfig::ApplicationID = unOwnAppID;

        // Usage information.
        InfoPrint(va("Starting steamapp %i", Steamconfig::ApplicationID).c_str());
        return false;
    }

    // Callback management.
    EXPORT_ATTR void SteamAPI_RunCallbacks()
    {
        SteamCallback::RunCallbacks();
    }
    EXPORT_ATTR void SteamAPI_RegisterCallback(void *pCallback, int iCallback)
    {
        if (pCallback)
            SteamCallback::RegisterCallback(static_cast<CallbackBase *>(pCallback), iCallback);
    }
    EXPORT_ATTR void SteamAPI_UnregisterCallback(void *pCallback, int iCallback)
    {
        if (pCallback)
            SteamCallback::UnregisterCallback(static_cast<CallbackBase *>(pCallback), iCallback);
    }
    EXPORT_ATTR void SteamAPI_RegisterCallResult(void *pCallback, uint64_t hAPICall)
    {
        if (pCallback)
            SteamCallback::RegisterCallResult(hAPICall, static_cast<CallbackBase *>(pCallback));
    }
    EXPORT_ATTR void SteamAPI_UnregisterCallResult(void *pCallback, uint64_t hAPICall)
    {
        if (pCallback)
            SteamCallback::UnregisterCallResult(hAPICall, static_cast<CallbackBase *>(pCallback));
    }

    // Dedicated server mode.    
    EXPORT_ATTR bool SteamGameServer_BSecure()
    {
        return true;
    }
    EXPORT_ATTR void SteamGameServer_Shutdown()
    {
        Steamconfig::Server = false;
    }
    EXPORT_ATTR void SteamGameServer_RunCallbacks()
    {
        SteamCallback::RunCallbacks();
    }
    EXPORT_ATTR uint64_t SteamGameServer_GetSteamID()
    {
        return Steamconfig::UserID;
    }
    EXPORT_ATTR bool SteamGameServer_Init(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, uint32_t eServerMode, const char *pchVersionString)
    {
        Steamconfig::Server = true;

        // Debug information about the servermode.
        DebugPrint("Server startup:");
        DebugPrint(va("IP: %u.%u.%u.%u", ((uint8_t *)&unIP)[0], ((uint8_t *)&unIP)[1], ((uint8_t *)&unIP)[2], ((uint8_t *)&unIP)[3]).c_str());
        DebugPrint(va("Query port: %u", usQueryPort).c_str());
        DebugPrint(va("Game port: %u", usGamePort).c_str());

        return true;
    }
    EXPORT_ATTR bool SteamGameServer_InitSafe(uint32_t unIP, uint16_t usSteamPort, uint16_t usGamePort, uint16_t usQueryPort, uint32_t eServerMode, const char *pchVersionString)
    {
        return SteamGameServer_Init(unIP, usSteamPort, usGamePort, usQueryPort, eServerMode, pchVersionString);
    }
}
