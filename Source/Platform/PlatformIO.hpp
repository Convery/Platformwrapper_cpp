/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 03-02-2018
    License: MIT
    Notes:
        A very simple implementation mainly using blocking IO.
        Should be replaced for version 2.0.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace Platform
{
    enum Messagetype_t
    {
        Accountinfo_request = 0,
        Accountinfo_response = 1
    };

    // Register a callback for responses.
    void Registercallback(Messagetype_t Type, std::function<void(std::string Data)> Callback);

    // Send a request and get a sync JSON response.
    std::string Sendrequest(Messagetype_t Type, std::string &&Data);
}
