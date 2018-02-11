/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 08-01-2018
    License: MIT
    Notes:
        Provides the entrypoint for Windows and Nix.
*/

#include "Stdinclude.hpp"

// Callbacks from the bootstrapper (Bootstrapmodule_cpp).
extern "C" EXPORT_ATTR void onInitializationStart(bool Reserved)
{
    // Helper macros to save the developers fingers.
    #if defined(_WIN32)
    #define GETFUNC(Module, Function) GetProcAddress(GetModuleHandleA(Module), Function)
    #else
    #define GETFUNC(Module, Function) dlsym(dlopen(Module, RTLD_LAZY), Function)
    #endif
    #define INSTALL_HOOK(Module, Import, Replacement)                       \
    {auto Address = GETFUNC(Module, Import);                                \
    if(Address) Hooking::Stomphook().Installhook(Address, Replacement);}    \

    /*
        TODO(Convery):
        Make it optional to install these hooks by patching
        the applications IAT rather than stomphooking the
        loaded modules. Although STMSIG_Bypass and other
        such plugins would make modifications to the
        modules somewhat irrelevant.
    */

    // Steam_api exports.
    #if defined(_WIN32)
    constexpr const char *Steamlib = sizeof(void *) == sizeof(uint64_t) ? "steam_api64.dll" : "steam_api.dll";
    #else
    constexpr const char *Steamlib = sizeof(void *) == sizeof(uint64_t) ? "libsteam_api64.so" : "libsteam_api.so";
    #endif
    INSTALL_HOOK(Steamlib, "SteamAPI_RestartAppIfNecessary", SteamAPI_RestartAppIfNecessary);
    INSTALL_HOOK(Steamlib, "SteamInternal_CreateInterface", SteamInternal_CreateInterface);
    INSTALL_HOOK(Steamlib, "SteamGameServer_GetHSteamUser", SteamGameServer_GetHSteamUser);
    INSTALL_HOOK(Steamlib, "SteamGameServer_GetHSteamPipe", SteamGameServer_GetHSteamPipe);
    INSTALL_HOOK(Steamlib, "SteamAPI_UnregisterCallResult", SteamAPI_UnregisterCallResult);
    INSTALL_HOOK(Steamlib, "SteamInternal_GameServer_Init", SteamInternal_GameServer_Init);
    INSTALL_HOOK(Steamlib, "SteamAPI_GetSteamInstallPath", SteamAPI_GetSteamInstallPath);
    INSTALL_HOOK(Steamlib, "SteamGameServer_RunCallbacks", SteamGameServer_RunCallbacks);
    INSTALL_HOOK(Steamlib, "SteamAPI_UnregisterCallback", SteamAPI_UnregisterCallback);
    INSTALL_HOOK(Steamlib, "SteamAPI_RegisterCallResult", SteamAPI_RegisterCallResult);
    INSTALL_HOOK(Steamlib, "SteamGameServer_GetSteamID", SteamGameServer_GetSteamID);
    INSTALL_HOOK(Steamlib, "SteamAPI_RegisterCallback", SteamAPI_RegisterCallback);
    INSTALL_HOOK(Steamlib, "SteamGameServerNetworking", SteamGameServerNetworking);
    INSTALL_HOOK(Steamlib, "SteamGameServer_InitSafe", SteamGameServer_InitSafe);
    INSTALL_HOOK(Steamlib, "SteamGameServerInventory", SteamGameServerInventory);
    INSTALL_HOOK(Steamlib, "SteamMasterServerUpdater", SteamMasterServerUpdater);
    INSTALL_HOOK(Steamlib, "SteamGameServer_Shutdown", SteamGameServer_Shutdown);
    INSTALL_HOOK(Steamlib, "SteamGameServer_BSecure", SteamGameServer_BSecure);
    INSTALL_HOOK(Steamlib, "SteamMatchmakingServers", SteamMatchmakingServers);
    INSTALL_HOOK(Steamlib, "SteamAPI_IsSteamRunning", SteamAPI_IsSteamRunning);
    INSTALL_HOOK(Steamlib, "SteamAPI_GetHSteamUser", SteamAPI_GetHSteamUser);
    INSTALL_HOOK(Steamlib, "SteamAPI_GetHSteamPipe", SteamAPI_GetHSteamPipe);
    INSTALL_HOOK(Steamlib, "SteamAPI_RunCallbacks", SteamAPI_RunCallbacks);
    INSTALL_HOOK(Steamlib, "SteamUnifiedMessages", SteamUnifiedMessages);
    INSTALL_HOOK(Steamlib, "SteamGameServerStats", SteamGameServerStats);
    INSTALL_HOOK(Steamlib, "SteamGameServerUtils", SteamGameServerUtils);
    INSTALL_HOOK(Steamlib, "SteamGameServer_Init", SteamGameServer_Init);
    INSTALL_HOOK(Steamlib, "SteamGameServerHTTP", SteamGameServerHTTP);
    INSTALL_HOOK(Steamlib, "SteamGameServerUGC", SteamGameServerUGC);
    INSTALL_HOOK(Steamlib, "SteamRemoteStorage", SteamRemoteStorage);
    INSTALL_HOOK(Steamlib, "SteamAPI_InitSafe", SteamAPI_InitSafe);
    INSTALL_HOOK(Steamlib, "SteamAPI_Shutdown", SteamAPI_Shutdown);
    INSTALL_HOOK(Steamlib, "SteamHTMLSurface", SteamHTMLSurface);
    INSTALL_HOOK(Steamlib, "SteamScreenshots", SteamScreenshots);
    INSTALL_HOOK(Steamlib, "SteamMusicRemote", SteamMusicRemote);
    INSTALL_HOOK(Steamlib, "SteamMatchmaking", SteamMatchmaking);
    INSTALL_HOOK(Steamlib, "SteamNetworking", SteamNetworking);
    INSTALL_HOOK(Steamlib, "SteamController", SteamController);
    INSTALL_HOOK(Steamlib, "SteamGameServer", SteamGameServer);
    INSTALL_HOOK(Steamlib, "SteamInventory", SteamInventory);
    INSTALL_HOOK(Steamlib, "SteamUserStats", SteamUserStats);
    INSTALL_HOOK(Steamlib, "SteamAPI_Init", SteamAPI_Init);
    INSTALL_HOOK(Steamlib, "SteamAppList", SteamAppList);
    INSTALL_HOOK(Steamlib, "SteamFriends", SteamFriends);
    INSTALL_HOOK(Steamlib, "SteamClient", SteamClient);
    INSTALL_HOOK(Steamlib, "SteamMusic", SteamMusic);
    INSTALL_HOOK(Steamlib, "SteamUtils", SteamUtils);
    INSTALL_HOOK(Steamlib, "SteamVideo", SteamVideo);
    INSTALL_HOOK(Steamlib, "SteamApps", SteamApps);
    INSTALL_HOOK(Steamlib, "SteamUser", SteamUser);
    INSTALL_HOOK(Steamlib, "SteamHTTP", SteamHTTP);
    INSTALL_HOOK(Steamlib, "SteamUGC", SteamUGC);

    // Arclight exports.
    #if defined(_WIN32)
    constexpr const char *Arclib = "ArcSDK.dll";
    #else
    constexpr const char *Arclib = ""; // TODO(Convery): Investigate this.
    #endif
    INSTALL_HOOK(Arclib, "CC_InviteFriendInOverlay", CC_InviteFriendInOverlay);
    INSTALL_HOOK(Arclib, "CC_GetLaunchedParameter", CC_GetLaunchedParameter);
    INSTALL_HOOK(Arclib, "CC_UnregisterCallback", CC_UnregisterCallback);
    INSTALL_HOOK(Arclib, "CC_GetArcRunningMode", CC_GetArcRunningMode);
    INSTALL_HOOK(Arclib, "CC_GetUserAvatarLink", CC_GetUserAvatarLink);
    INSTALL_HOOK(Arclib, "CC_RegisterCallback", CC_RegisterCallback);
    INSTALL_HOOK(Arclib, "CC_InstalledFromArc", CC_InstalledFromArc);
    INSTALL_HOOK(Arclib, "CC_GotoUrlInOverlay", CC_GotoUrlInOverlay);
    INSTALL_HOOK(Arclib, "CC_GetSteamTicket", CC_GetSteamTicket);
    INSTALL_HOOK(Arclib, "CC_GetAccountName", CC_GetAccountName);
    INSTALL_HOOK(Arclib, "CC_LaunchClient", CC_LaunchClient);
    INSTALL_HOOK(Arclib, "CC_RunCallbacks", CC_RunCallbacks);
    INSTALL_HOOK(Arclib, "CC_GetNickName", CC_GetNickName);
    INSTALL_HOOK(Arclib, "CC_ShowOverlay", CC_ShowOverlay);
    INSTALL_HOOK(Arclib, "CC_GetTokenEx", CC_GetTokenEx);
    INSTALL_HOOK(Arclib, "CC_GetToken", CC_GetToken);
    INSTALL_HOOK(Arclib, "CC_GetArcID", CC_GetArcID);
    INSTALL_HOOK(Arclib, "Matchmaking", Matchmaking);
    INSTALL_HOOK(Arclib, "Networking", Networking);
    INSTALL_HOOK(Arclib, "ArcFriends", ArcFriends);
    INSTALL_HOOK(Arclib, "CC_UnInit", CC_UnInit);
    INSTALL_HOOK(Arclib, "CC_Init", CC_Init);
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

            // Clear the previous sessions logfile.
            Clearlog();

            // Initialize the database.
            Database::Load("Platformwrapper.db");
            std::atexit([]() { Database::Save("Platformwrapper.db"); std::remove("file"); });

            // For developers we sideload a bootstrapper and create a console.
            #if !defined (NDEBUG)
                AllocConsole();
                freopen("CONOUT$", "w", stdout);
                freopen("CONOUT$", "w", stderr);
                SetConsoleTitleA("Debug Console");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
                LoadLibraryA("Localbootstrap.dll");
            #endif
        }
    }

    return TRUE;
}
#else
__attribute__((constructor)) void DllMain()
{
    // Clear the previous sessions logfile.
    Clearlog();

    // Initialize the database.
    Database::Load("Platformwrapper.db");
    std::atexit([]() { Database::Save("Platformwrapper.db"); std::remove("file"); });

    // For developers we sideload a bootstrapper.
    #if !defined (NDEBUG)
        dlopen("Localbootstrap", RTLD_LAZY);
    #endif
}
#endif
