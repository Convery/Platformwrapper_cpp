/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-02-2018
    License: MIT
    Notes:
        Arc callbacks for async requests.
*/

#pragma once
#include "../../Stdinclude.hpp"

namespace Arccallback
{
    // Result of the async request.
    using Result_t = struct Anontype_t { uint32_t CallbackID; std::string Data; std::function<void(void *Callback, std::string &Data)> Run; };

    #pragma pack(1)
    struct PWCallback
    {
        uint32_t CallbackID;
        void    *Gamestate;
        void    *Callback;
        void    *Data;

        PWCallback() = default;
        PWCallback(PWCallback &Right) = default;
        virtual uint32_t Resultsize() = 0;
    };
    #pragma pack()

    // Add a games callback to the internal mapping.
    void Registercallback(PWCallback *Callbackhandler, uint32_t CallbackID);

    // Remove a games callback from the internal mapping.
    void Removecallback(PWCallback *Callbackhandler);

    // Return data to the game.
    void Completerequest(Result_t Result);

    // Call all callbacks, usually every frame.
    void Runcallbacks();

    // Debug information.
    std::string Callbackname(uint32_t CallbackID);
}
