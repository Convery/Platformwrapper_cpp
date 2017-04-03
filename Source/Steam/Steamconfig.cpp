/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#include "Steam.h"

// Configuration.
namespace Steamconfig
{
    // Application info.
    char Language[32]{ "english" };
    uint32_t ApplicationID{ 0 };
    int64_t StartupTimestamp{ std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() };

    // Network access.
    bool LAN{ false };
    bool Server{ false };
    bool Offline{ false };

    // User information.
    char Path[260]{};
    uint64_t UserID{ 0x1100001DEADC0DE };
    char Username[17]{ "Ayria" };
}