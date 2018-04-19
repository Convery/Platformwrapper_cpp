/*
    Initial author: Convery (tcn@ayria.se)
    Started: 08-01-2018
    License: MIT
    Notes:
        Provides the entrypoint for Windows and Nix.
*/

#include "Stdinclude.hpp"

// Callbacks from the bootstrapper (Bootstrapmodule_cpp).
extern "C" EXPORT_ATTR void onInitializationStart(bool Reserved)
{
    // Helpers rather than the old macros.
    auto Commandlinecontains = [](std::string_view Needle) -> bool
    {
        #if defined (_WIN32)
        return !!std::strstr(GetCommandLineA(), Needle.data());
        #else
        std::FILE *Filehandle = std::fopen("/proc/self/cmdline", "r");
        char Buffer[1024]{};
        if (Filehandle)
        {
            std::fgets(Buffer, 1024, Filehandle);
            std::fclose(Filehandle);
        }
        return !!std::strstr(Buffer, Needle.data());
        #endif
    };
    auto InstallSTOMP = [](std::string_view Modulename, std::string_view Functionname, void *Target) -> void
    {
        #if defined(_WIN32)
        auto Address = GetProcAddress(LoadLibraryA(Modulename.data()), Functionname.data());
        #else
        auto Address = dlsym(dlopen(Modulename.data(), RTLD_LAZY), Functionname.data());
        #endif

        if(Address) Hooking::Stomphook<>::Install(Address, Target);
    };
    auto InstallIAT = [](std::string_view Modulename, std::string_view Functionname, void *Target) -> void
    {
        auto Address = Pattern::Findimportaddress(Modulename, Functionname);
        if (Address) *(size_t *)Address = (size_t)Target;
    };
    std::function<void(std::string_view, std::string_view, void *)> Installer{ InstallIAT };

    // The modules that should be handled.
    #if defined(_WIN32)
    constexpr const char *Arclib = "ArcSDK.dll";
    constexpr const char *Steamlib = sizeof(void *) == sizeof(uint64_t) ? "steam_api64.dll" : "steam_api.dll";
    #else
    constexpr const char *Arclib = ""; // TODO(Convery): Investigate this.
    constexpr const char *Steamlib = sizeof(void *) == sizeof(uint64_t) ? "libsteam_api64.so" : "libsteam_api.so";
    #endif

    // Check if we should prefer stomp-hooking.
    if (Commandlinecontains("-stomp"))
    {
        Installer = InstallSTOMP;
    }

    // Hook steams exports.
    #pragma region STEAM
    Installer(Steamlib, "SteamAPI_RestartAppIfNecessary", SteamAPI_RestartAppIfNecessary);
    Installer(Steamlib, "SteamInternal_CreateInterface", SteamInternal_CreateInterface);
    Installer(Steamlib, "SteamGameServer_GetHSteamUser", SteamGameServer_GetHSteamUser);
    Installer(Steamlib, "SteamGameServer_GetHSteamPipe", SteamGameServer_GetHSteamPipe);
    Installer(Steamlib, "SteamAPI_UnregisterCallResult", SteamAPI_UnregisterCallResult);
    Installer(Steamlib, "SteamInternal_GameServer_Init", SteamInternal_GameServer_Init);
    Installer(Steamlib, "SteamAPI_GetSteamInstallPath", SteamAPI_GetSteamInstallPath);
    Installer(Steamlib, "SteamGameServer_RunCallbacks", SteamGameServer_RunCallbacks);
    Installer(Steamlib, "SteamAPI_UnregisterCallback", SteamAPI_UnregisterCallback);
    Installer(Steamlib, "SteamAPI_RegisterCallResult", SteamAPI_RegisterCallResult);
    Installer(Steamlib, "SteamGameServer_GetSteamID", SteamGameServer_GetSteamID);
    Installer(Steamlib, "SteamAPI_RegisterCallback", SteamAPI_RegisterCallback);
    Installer(Steamlib, "SteamGameServerNetworking", SteamGameServerNetworking);
    Installer(Steamlib, "SteamGameServer_InitSafe", SteamGameServer_InitSafe);
    Installer(Steamlib, "SteamGameServerInventory", SteamGameServerInventory);
    Installer(Steamlib, "SteamMasterServerUpdater", SteamMasterServerUpdater);
    Installer(Steamlib, "SteamGameServer_Shutdown", SteamGameServer_Shutdown);
    Installer(Steamlib, "SteamGameServer_BSecure", SteamGameServer_BSecure);
    Installer(Steamlib, "SteamMatchmakingServers", SteamMatchmakingServers);
    Installer(Steamlib, "SteamAPI_IsSteamRunning", SteamAPI_IsSteamRunning);
    Installer(Steamlib, "SteamAPI_GetHSteamUser", SteamAPI_GetHSteamUser);
    Installer(Steamlib, "SteamAPI_GetHSteamPipe", SteamAPI_GetHSteamPipe);
    Installer(Steamlib, "SteamAPI_RunCallbacks", SteamAPI_RunCallbacks);
    Installer(Steamlib, "SteamUnifiedMessages", SteamUnifiedMessages);
    Installer(Steamlib, "SteamGameServerStats", SteamGameServerStats);
    Installer(Steamlib, "SteamGameServerUtils", SteamGameServerUtils);
    Installer(Steamlib, "SteamGameServer_Init", SteamGameServer_Init);
    Installer(Steamlib, "SteamGameServerHTTP", SteamGameServerHTTP);
    Installer(Steamlib, "SteamGameServerUGC", SteamGameServerUGC);
    Installer(Steamlib, "SteamRemoteStorage", SteamRemoteStorage);
    Installer(Steamlib, "SteamAPI_InitSafe", SteamAPI_InitSafe);
    Installer(Steamlib, "SteamAPI_Shutdown", SteamAPI_Shutdown);
    Installer(Steamlib, "SteamHTMLSurface", SteamHTMLSurface);
    Installer(Steamlib, "SteamScreenshots", SteamScreenshots);
    Installer(Steamlib, "SteamMusicRemote", SteamMusicRemote);
    Installer(Steamlib, "SteamMatchmaking", SteamMatchmaking);
    Installer(Steamlib, "SteamNetworking", SteamNetworking);
    Installer(Steamlib, "SteamController", SteamController);
    Installer(Steamlib, "SteamGameServer", SteamGameServer);
    Installer(Steamlib, "SteamInventory", SteamInventory);
    Installer(Steamlib, "SteamUserStats", SteamUserStats);
    Installer(Steamlib, "SteamAPI_Init", SteamAPI_Init);
    Installer(Steamlib, "SteamAppList", SteamAppList);
    Installer(Steamlib, "SteamFriends", SteamFriends);
    Installer(Steamlib, "SteamClient", SteamClient);
    Installer(Steamlib, "SteamMusic", SteamMusic);
    Installer(Steamlib, "SteamUtils", SteamUtils);
    Installer(Steamlib, "SteamVideo", SteamVideo);
    Installer(Steamlib, "SteamApps", SteamApps);
    Installer(Steamlib, "SteamUser", SteamUser);
    Installer(Steamlib, "SteamHTTP", SteamHTTP);
    Installer(Steamlib, "SteamUGC", SteamUGC);
    #pragma endregion

    // Hook Arc exports.
    #pragma region ARC
    Installer(Arclib, "CC_InviteFriendInOverlay", CC_InviteFriendInOverlay);
    Installer(Arclib, "CC_GetLaunchedParameter", CC_GetLaunchedParameter);
    Installer(Arclib, "CC_UnregisterCallback", CC_UnregisterCallback);
    Installer(Arclib, "CC_GetArcRunningMode", CC_GetArcRunningMode);
    Installer(Arclib, "CC_GetUserAvatarLink", CC_GetUserAvatarLink);
    Installer(Arclib, "CC_RegisterCallback", CC_RegisterCallback);
    Installer(Arclib, "CC_InstalledFromArc", CC_InstalledFromArc);
    Installer(Arclib, "CC_GotoUrlInOverlay", CC_GotoUrlInOverlay);
    Installer(Arclib, "CC_GetSteamTicket", CC_GetSteamTicket);
    Installer(Arclib, "CC_GetAccountName", CC_GetAccountName);
    Installer(Arclib, "CC_LaunchClient", CC_LaunchClient);
    Installer(Arclib, "CC_RunCallbacks", CC_RunCallbacks);
    Installer(Arclib, "CC_GetNickName", CC_GetNickName);
    Installer(Arclib, "CC_ShowOverlay", CC_ShowOverlay);
    Installer(Arclib, "CC_GetTokenEx", CC_GetTokenEx);
    Installer(Arclib, "CC_GetToken", CC_GetToken);
    Installer(Arclib, "CC_GetArcID", CC_GetArcID);
    Installer(Arclib, "Matchmaking", Matchmaking);
    Installer(Arclib, "Networking", Networking);
    Installer(Arclib, "ArcFriends", ArcFriends);
    Installer(Arclib, "CC_UnInit", CC_UnInit);
    Installer(Arclib, "CC_Init", CC_Init);
    #pragma endregion
}
extern "C" EXPORT_ATTR void onInitializationDone(bool Reserved)
{
    /*
        ----------------------------------------------------------------------
        This callback is called when the platform notifies the bootstrapper,
        or at most 3 seconds after startup. This is the perfect time to start
        communicating with other plugins and modify the games .data segment.
        ----------------------------------------------------------------------
    */
}
extern "C" EXPORT_ATTR void onMessage(uint32_t MessageID, uint32_t Messagesize, const void *Messagedata)
{
    /*
        ----------------------------------------------------------------------
        This callback is called when another plugin broadcasts a message. They
        can safely be ignored, but if you want to make use of the system you
        should create a unique name for your messages. We recommend that you
        base it on your pluginname as shown below, we also recommend that you
        use the bytebuffer format for data.
        ----------------------------------------------------------------------
    */

    // Create a buffer from the data as such:
    // Bytebuffer Message{ Messagesize, Messagedata};

    // MessageID is a FNV1a_32 hash of a string.
    switch (MessageID)
    {
        case Hash::FNV1a_32(MODULENAME "::Default"):
        default: break;
    }
}

#if defined _WIN32
BOOLEAN WINAPI DllMain(HINSTANCE hDllHandle, DWORD nReason, LPVOID Reserved)
{
    switch (nReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            // Opt-out of further thread notifications.
            DisableThreadLibraryCalls(hDllHandle);

            // Ensure that the logfile directory exists.
            _mkdir("./Plugins/");
            _mkdir("./Plugins/Logs/");

            // Clear the previous sessions logfile.
            Clearlog();

            // Initialize the database.
            Database::Load("Platformwrapper.db");
            std::atexit([]() { Database::Save("Platformwrapper.db"); std::remove("file"); });

            // Although useless for most users, we create a console if we get a switch.
            #if defined(NDEBUG)
            if (std::strstr(GetCommandLineA(), "-devcon"))
            #endif
            {
                AllocConsole();
                freopen("CONOUT$", "w", stdout);
                freopen("CONOUT$", "w", stderr);
                SetConsoleTitleA("Developer Console");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            }

            // Sideload the bootstrapper if it's available.
            LoadLibraryA("Localbootstrap.dll");
        }
    }

    return TRUE;
}
#else
__attribute__((constructor)) void DllMain()
{
    // Ensure that the logfile directory exists.
    mkdir("./Plugins/", S_IRWXU | S_IRWXG);
    mkdir("./Plugins/Logs/", S_IRUSR | S_IWUSR);

    // Clear the previous sessions logfile.
    Clearlog();

    // Initialize the database.
    Database::Load("Platformwrapper.db");
    std::atexit([]() { Database::Save("Platformwrapper.db"); std::remove("file"); });

    // Sideload the bootstrapper if it's available.
    dlopen("Localbootstrap", RTLD_LAZY);
}
#endif
