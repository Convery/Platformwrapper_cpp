/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 03-02-2018
    License: MIT
    Notes:
        Arc callbacks for async requests.
*/

#pragma once
#include "../../Stdinclude.hpp"

namespace Arccallback
{
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
    void Registercallback(PWCallback *Callbackhandler, int32_t CallbackID);

    // Remove a games callback from the internal mapping.
    void Removecallback(PWCallback *Callbackhandler);

    // Call all callbacks, usually every frame.
    void Runcallbacks();

    // Debug information.
    std::string Callbackname(int32_t CallbackID);
}
