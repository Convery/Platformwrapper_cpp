/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-02-2018
    License: MIT
    Notes:
        ARC exports implementation.
*/

#include "../Stdinclude.hpp"

// Create a request or response from a list of parameters.
std::wstring Createmessage(uint32_t Messagetype, std::vector<std::wstring> Parameters)
{
    std::wstring Result;

    wchar_t Number[16]{};
    _itow(Messagetype, Number, 10);

    Result += Number;
    for (auto &Item : Parameters)
    {
        Result += L"|";
        Result += Item;
    }

    return Result;
}

// Interfaces.
extern "C"
{
    EXPORT_ATTR void *ArcFriends()
    {
        return nullptr;
    }
    EXPORT_ATTR void *Matchmaking()
    {
        return nullptr;
    }
    EXPORT_ATTR void *Networking()
    {
        return nullptr;
    }

    EXPORT_ATTR int64_t CC_GetAccountName(const wchar_t *State, wchar_t *Buffer, uint32_t Bufferlength)
    {
        // Return an accountname.
        std::memset(Buffer, 0, Bufferlength * 2);
        std::memcpy(Buffer, L"Ayria", 12);

        return 0;
    }
    EXPORT_ATTR int64_t CC_GetArcID(int64_t a1, int64_t a2)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_GetArcRunningMode(uint32_t *Mode)
    {
        // enum Mode { Arc = 0, Steam = 1 }
        *Mode = 1;

        return 0;
    }
    EXPORT_ATTR int64_t CC_GetLaunchedParameter(const wchar_t *Gameabbreviation, int Language, wchar_t *Buffer, signed int Bufferlength)
    {
        // Enum to string.
        auto LanguagefromID = [](int Language) -> const wchar_t *
        {
            switch (Language)
            {
                case 1: return L"en";
                case 2: return L"de";
                case 3: return L"fr";
                case 4: return L"pt";
                case 5: return L"ru";
                case 6: return L"tr";

                case 0:
                default:
                    return L"";
            }
        };

        // Should be enum >= 0.
        if (Language < 0) return 0xE0000002;

        // Game built against old SDK?
        if (Bufferlength < 128) return 0xE000001A;

        // Clear the games buffer.
        std::memset(Buffer, 0, Bufferlength * 2);

        // Format a response from the input.
        auto Response = Createmessage(41, { Gameabbreviation, LanguagefromID(Language) });
        std::memcpy(Buffer, Response.c_str(), Response.size() * 2);
        return 0;
    }
    EXPORT_ATTR int64_t CC_GetNickName(const wchar_t *State, wchar_t *Buffer, uint32_t Bufferlength)
    {
        // Return a nickname.
        std::memset(Buffer, 0, Bufferlength * 2);
        std::memcpy(Buffer, L"Ayria", 12);

        return 0;
    }
    EXPORT_ATTR int64_t CC_GetSteamTicket(int64_t a1, unsigned int *a2)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_GetToken(int64_t a1, int64_t a2, int64_t a3, unsigned int *a4, unsigned int *a5)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_GetTokenEx(const wchar_t *State, const wchar_t *Accountname, const wchar_t *Gameabbreviation, wchar_t *Buffer, uint32_t Bufferlength, uint32_t Sendduration)
    {
        // Format a response from the input.
        auto Response = Createmessage(10, { Accountname, Gameabbreviation });
        std::memcpy(Buffer, Response.c_str(), Response.size() * 2);
        return 0;
    }
    EXPORT_ATTR int64_t CC_GetUserAvatarLink(int64_t a1, wchar_t *a2, unsigned int *a3, int a4)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_GotoUrlInOverlay(int64_t a1, const wchar_t *a2)
    {
        return 0;
    }
    EXPORT_ATTR wchar_t *CC_Init(int64_t a1, int64_t GameID, uint32_t *Handles)
    {
        static wchar_t Internalstate[]{ L"This is our secret, probably encrypted, internal state.."};
        Debugprint(va("Initializing gameID %u", GameID));

        // Set the environment handles.
        if (Handles[0]) SetEnvironmentVariableA("ArcGameWindowHandle", va("%u", Handles[0]).c_str());
        // TODO(Convery): Research Handles[1] as it's a hardcoded ID.
        if (Handles[2]) SetEnvironmentVariableA("ArcGameMessageId", va("%u", Handles[2]).c_str());

        return Internalstate;
    }
    EXPORT_ATTR char CC_InstalledFromArc(unsigned int a1, unsigned int a2)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_InviteFriendInOverlay(int64_t a1, int64_t *a2)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_LaunchClient(const wchar_t *Gameabbreviation, int a2, int64_t a3)
    {
        Debugprint(va("Starting game \"%ls\"", Gameabbreviation));

        /*
            TODO(Convery):
            SetEnvironmentVariableW
                "CoreGameId"
                "ArcGameExeName"
                "ArcGameInstallPath"
                "ArcProcessId"
                "ArcGameAbbr"
                "ArcEnableOverlay"
        */

        // Status::Initialized
        return 0xE0000019;
    }
    EXPORT_ATTR int64_t CC_RegisterCallback(Arccallback::PWCallback *Callback, int32_t CallbackID)
    {
        Arccallback::Registercallback(Callback, CallbackID);
        return -2;
    }
    EXPORT_ATTR int64_t CC_RunCallbacks()
    {
        Arccallback::Runcallbacks();
        return 0;
    }
    EXPORT_ATTR int64_t CC_SetViewableRect(const wchar_t *Gameabbreviation, uint32_t Top, uint32_t Left, uint32_t Bottom, uint32_t Right)
    {
        Debugprint(va("Gamewindow position: %u %u %u %u", Top, Left, Bottom, Right));
        return 0;
    }
    EXPORT_ATTR int64_t CC_ShowOverlay(int64_t a1, unsigned int a2)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_UnInit(const wchar_t *State)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_UnregisterCallback(Arccallback::PWCallback *Callback)
    {
        Arccallback::Removecallback(Callback);
        return 0;
    }
}
