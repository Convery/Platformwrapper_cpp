/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-11-2017
    License: MIT
    Notes:
        Data provided by the Ayria client.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace Ayriacache
{
    struct Account
    {
        std::string Accountname;
        std::string AvatarPNG;
        std::string Locale;
        uint64_t UserID;
    };
    struct Friend
    {
        std::string Accountname;
        std::string AvatarPNG;
        std::string Game;
        uint64_t UserID;
        uint64_t Status;
    };

    extern Account Accountinformation;
    extern std::vector<Friend> Friendslist;
}
