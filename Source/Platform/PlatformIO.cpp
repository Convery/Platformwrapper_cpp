/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 03-02-2018
    License: MIT
    Notes:
        A very simple implementation mainly using blocking IO.
        Should be replaced for version 2.0.
*/

#include "../Stdinclude.hpp"

namespace Platform
{
    std::unordered_map <Messagetype_t, std::function<void(std::string Data)>> OOBCallbacks;

    // Register a callback for responses.
    void Registercallback(Messagetype_t Type, std::function<void(std::string Data)> Callback)
    {
        OOBCallbacks[Type] = Callback;
    }

    // Send a request and get a sync JSON response.
    #if defined(_WIN32)
    std::string Sendrequest(Messagetype_t Type, std::string &&Data)
    {
        std::string Result{ "{}" };

        // Open the named pipe.
        HANDLE Pipe = CreateFileA("\\\\.\\pipe\\Ayriapipe", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if (Pipe == INVALID_HANDLE_VALUE) return Result;

        // Format the message so we can do a single send.
        auto Formatted = va("%u|%s", Type, Data.c_str());
        WriteFile(Pipe, Formatted.c_str(), (uint32_t)Formatted.size(), NULL, NULL);

        // Poll until we get our response.
        while (true)
        {
            // Read the next message.
            char Buffer[2048]{};
            if (ReadFile(Pipe, Buffer, 2048, NULL, NULL) == FALSE)
                break;

            // 'Deserialize'
            char JSON[2048]{};
            uint32_t MSGType{};
            std::sscanf(Buffer, "%u|%2048s", &MSGType, JSON);

            // Check if it's the one we expect, else OOB.
            if (MSGType != uint32_t(Type + 1))
            {
                OOBCallbacks[(Messagetype_t)MSGType](JSON);
            }
            else
            {
                Result = JSON;
                break;
            }
        }

        // Cleanup the pipe.
        CloseHandle(Pipe);
        return Result;
    }
    #else
    std::string Sendrequest(Messagetype_t Type, std::string &&Data)
    {
        std::string Result{ "{}" };

        // Open the named pipe.
        mkfifo(".Ayriapipe", 0666);
        int Pipe = open(".Ayriapipe", O_RDWR);
        if (!Pipe) return Result;

        // Format the message so we can do a single send.
        auto Formatted = va("%u|%2048s", Type, Data.c_str());
        write(Pipe, Formatted.c_str(), (uint32_t)Formatted.size());

        // Poll until we get our response.
        while (true)
        {
            // Read the next message.
            char Buffer[2048]{};
            if (read(Pipe, Buffer, 2048) <= 0)
                break;

            // 'Deserialize'
            char JSON[2048]{};
            uint32_t MSGType{};
            std::sscanf(Buffer, "%u|%s", &MSGType, JSON);

            // Check if it's the one we expect, else OOB.
            if (MSGType != uint32_t(Type + 1))
            {
                OOBCallbacks[(Messagetype_t)MSGType](JSON);
            }
            else
            {
                Result = JSON;
                break;
            }
        }

        // Cleanup the pipe.
        close(Pipe);
        return Result;
    }
    #endif
}
