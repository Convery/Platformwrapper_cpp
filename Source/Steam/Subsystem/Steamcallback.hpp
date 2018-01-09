/*
    Initial author: Convery (tcn@ayria.se)
    Started: 06-08-2017
    License: MIT
    Notes:
        Implements steams async requests.
        We generally return directly though.
*/

#pragma once
#include "../../Stdinclude.hpp"

namespace Steamcallback
{
    // Result of the async request.
    using Result_t = struct Anontype_t { void *Databuffer; int32_t Buffersize; int32_t Requesttype; uint64_t RequestID; };

    // The callback the games expect.
    class Valvecallback
    {
    public:
        Valvecallback() { m_nCallbackFlags = 0; m_iCallback = 0; }
        virtual void Run(void *pvParam) = 0;
        virtual void Run(void *pvParam, bool bIOFailure, uint64_t hSteamAPICall) = 0;
        int GetICallback() { return m_iCallback; }
        void SetICallback(int i) { m_iCallback = i; }
        virtual int GetCallbackSizeBytes() = 0;

    protected:
        enum { k_ECallbackFlagsRegistered = 0x01, k_ECallbackFlagsGameServer = 0x02 };
        uint8_t m_nCallbackFlags;
        int m_iCallback;
    };

    // Add a games callback and result to the internal mapping.
    void Registercallback(Valvecallback *Callbackhandler, int32_t CallbackID);
    void Registerresult(Valvecallback *Callbackhandler, uint64_t RequestID);
    void Markcallbackactive(int32_t CallbackID, uint64_t RequestID);

    // Remove a games callback and result from the internal mapping.
    void Removecallback(Valvecallback *Callbackhandler, int32_t CallbackID);
    void Removeresult(Valvecallback *Callbackhandler, uint64_t RequestID);

    // Create and complete the requests.
    void Completerequest(Result_t Result);
    uint64_t Createrequest();

    // Call all callbacks, usually every frame.
    void Runcallbacks();

    // Check the status of a request.
    bool isRequestcomplete(uint64_t RequestID);

    // Debug information.
    std::string Callbackname(int32_t CallbackID);

    // Callback types used as a base.
    enum Steamcallbacktype
    {
        k_iSteamUserCallbacks = 100,
        k_iSteamGameServerCallbacks = 200,
        k_iSteamFriendsCallbacks = 300,
        k_iSteamBillingCallbacks = 400,
        k_iSteamMatchmakingCallbacks = 500,
        k_iSteamContentServerCallbacks = 600,
        k_iSteamUtilsCallbacks = 700,
        k_iClientFriendsCallbacks = 800,
        k_iClientUserCallbacks = 900,
        k_iSteamAppsCallbacks = 1000,
        k_iSteamUserStatsCallbacks = 1100,
        k_iSteamNetworkingCallbacks = 1200,
        k_iClientRemoteStorageCallbacks = 1300,
        k_iSteamUserItemsCallbacks = 1400,
        k_iSteamGameServerItemsCallbacks = 1500,
        k_iClientUtilsCallbacks = 1600,
        k_iSteamGameCoordinatorCallbacks = 1700,
        k_iSteamGameServerStatsCallbacks = 1800,
        k_iSteam2AsyncCallbacks = 1900,
        k_iSteamGameStatsCallbacks = 2000,
        k_iClientHTTPCallbacks = 2100,
        k_iClientScreenshotsCallbacks = 2200,
        k_iSteamScreenshotsCallbacks = 2300,
        k_iClientAudioCallbacks = 2400,
        k_iSteamUnifiedMessagesCallbacks = 2500,
        k_iClientUnifiedMessagesCallbacks = 2600,
        k_iClientControllerCallbacks = 2700,
        k_iSteamControllerCallbacks = 2800,
        k_iClientParentalSettingsCallbacks = 2900,
        k_iClientDeviceAuthCallbacks = 3000,
        k_iClientNetworkDeviceManagerCallbacks = 3100,
        k_iClientMusicCallbacks = 3200,
        k_iClientRemoteClientManagerCallbacks = 3300,
        k_iClientUGCCallbacks = 3400,
        k_iSteamStreamClientCallbacks = 3500,
        k_IClientProductBuilderCallbacks = 3600,
        k_iClientShortcutsCallbacks = 3700,
        k_iClientRemoteControlManagerCallbacks = 3800,
        k_iSteamAppListCallbacks = 3900,
        k_iSteamMusicCallbacks = 4000,
        k_iSteamMusicRemoteCallbacks = 4100,
        k_iClientVRCallbacks = 4200,
        k_iClientReservedCallbacks = 4300,
        k_iSteamReservedCallbacks = 4400,
        k_iSteamHTMLSurfaceCallbacks = 4500,
        k_iClientVideoCallbacks = 4600,
        k_iClientInventoryCallbacks = 4700,
    };
}
