/*
    Initial author: Convery (tcn@ayria.se)
    Started: 07-08-2017
    License: MIT
    Notes:
*/

#pragma once

// Includes for configuration settings.
#include "Configuration/Defines.h"
#include "Configuration/Macros.h"

// Includes for standard libraries.
#include <unordered_map>
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <vector>
#include <memory>
#include <chrono>
#include <atomic>
#include <mutex>
#include <ctime>
#include <list>

// Includes for platform libraries.
#if defined (_WIN32)
#include <Windows.h>
#include <direct.h>
#undef min
#undef max
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#endif

// Includes for thirdparty libraries.
#include <nlohmann/json.hpp>

// Includes for our utilities.
#include "Utility/Cryptography/FNV1Hash.h"
#include "Utility/Text/Variadicstring.h"
#include "Utility/Binary/Patternscan.h"
#include "Utility/Binary/Memprotect.h"
#include "Utility/Data/Bytebuffer.h"
#include "Utility/Data/PackageFS.h"
#include "Utility/Binary/Hooking.h"
#include "Utility/Data/SystemIO.h"
#include "Utility/Text/Logfile.h"
#include "Utility/Data/Base64.h"
#include "Utility/Text/CSV.h"

// Includes for our components.
#include "Steam/Interfaces/Interfaces.h"
#include "Steam/Steaminterface.h"
#include "Steam/Steamcallback.h"
#include "Steam/Steam.h"
