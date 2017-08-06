/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
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

// Includes for thirdparty libraries.
#include <sqlite3.h>

// Includes for our utilities.
#include "Utility/Cryptography/FNV1Hash.h"
#include "Utility/Text/Variadicstring.h"
#include "Utility/Binary/Patternscan.h"
#include "Utility/Binary/Memprotect.h"
#include "Utility/Data/Bytebuffer.h"
#include "Utility/Binary/Hooking.h"
#include "Utility/Text/Logfile.h"
#include "Utility/Data/Database.h"
#include "Utility/Data/Base64.h"
#include "Utility/Text/CSV.h"

// Includes for our components.
#include "Steam/Interfaces/Interfaces.h"
#include "Steam/Steaminterface.h"
#include "Steam/Steamcallback.h"
#include "Steam/Steam.h"
