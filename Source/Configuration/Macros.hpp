/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 08-01-2018
    License: MIT
    Notes:
        C preprocessor macros for /Utility code.
*/

#pragma once

// Debug information logging.
#if defined(NDEBUG)
    #define Printfunction()
    #define Debugprint(string)
#else
    #define Printfunction() Logformatted(__FUNCTION__, 'T')
    #define Debugprint(string) Logformatted(string, 'D')
#endif

// General information.
#define Infoprint(string) Logformatted(string, 'I')
#define vaprint(format, ...) Logprint(va(format, __VA_ARGS__))
