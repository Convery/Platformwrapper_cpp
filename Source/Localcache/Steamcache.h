/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-11-2017
    License: MIT
    Notes:
        Steam data per appID.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace Steamcache
{
    struct Game
    {
        uint32_t AppID;
        uint32_t DLCCount;
        std::string Friendlyname;
        std::string Installpath;
    };
    struct DLC
    {
        uint32_t DLCID;
        std::string Installpath;
    };

    extern std::vector<Game> Ownedgames;
    extern std::vector<DLC> DLCEntries;
}
