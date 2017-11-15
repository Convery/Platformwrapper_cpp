/*
    Initial author: Convery (tcn@ayria.se)
    Started: 06-08-2017
    License: MIT
    Notes:
        Implements steams async requests.
        We generally return directly though.
*/

#pragma once
#include "../../Stdinclude.h"

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
}
