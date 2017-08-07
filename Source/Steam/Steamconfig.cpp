/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam configuration.
*/

#include "../Stdinclude.h"

// Configuration.
namespace Steamconfig
{
    // Application info.
    char Language[32]{ "english" };
    uint32_t ApplicationID{ 0 };
    uint64_t Startuptimestamp{ uint64_t(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count()) };

    // Network access.
    bool LAN{ false };
    bool Server{ false };
    bool Offline{ false };

    // User information.
    char Path[260]{};
    uint64_t UserID{ 0x1100001DEADC0DE };
    char Username[17]{ "Ayria" };
}
