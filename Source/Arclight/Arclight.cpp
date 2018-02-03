/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 03-02-2018
    License: MIT
    Notes:
        ARC exports implementation.
*/

#include "../Stdinclude.hpp"

namespace CC_SDK
{
    // Implemented like ArcSDK.
    class EXPORT_ATTR ArcID
    {
        wchar_t *Internalstring;

    public:
        wchar_t *Get()
        {
            return Internalstring;
        }
        void Set(const wchar_t *Input)
        {
            size_t Length = std::wcslen(Input);
            std::memcpy(Internalstring, Input, Length * 2);
        }

        ArcID()
        {
            Internalstring = new wchar_t[256]();
        };
        ArcID(ArcID &Parent)
        {
            Internalstring = new wchar_t[256]();
            Set(Parent.Internalstring);
        };
        ArcID(const wchar_t *Plaintext)
        {
            Internalstring = new wchar_t[256]();
            Set(Plaintext);
        };
        ~ArcID() 
        { 
            delete[] Internalstring; 
        };

        ArcID &operator = (const ArcID &Right) noexcept
        {
            Set(Right.Internalstring);
            return *this;
        }
        bool operator < (const ArcID &Right)
        {
            return wcscmp(Internalstring, Right.Internalstring) < 0;
        }
    };
    class EXPORT_ATTR LobbyID
    {
        wchar_t *Internalstring;

    public:
        wchar_t *Get()
        {
            return Internalstring;
        }
        void Set(const wchar_t *Input)
        {
            size_t Length = std::wcslen(Input);
            std::memcpy(Internalstring, Input, Length * 2);
        }

        LobbyID()
        {
            Internalstring = new wchar_t[256]();
        };
        LobbyID(LobbyID &Parent)
        {
            Internalstring = new wchar_t[256]();
            Set(Parent.Internalstring);
        };
        LobbyID(const wchar_t *Plaintext)
        {
            Internalstring = new wchar_t[256]();
            Set(Plaintext);
        };
        ~LobbyID() 
        { 
            delete[] Internalstring; 
        };

        LobbyID &operator = (const LobbyID &Right) noexcept
        {
            Set(Right.Internalstring);
            return *this;
        }
        bool operator < (const LobbyID &Right)
        {
            return wcscmp(Internalstring, Right.Internalstring) < 0;
        }
    };
}

#pragma pack(1)
struct Arclightcallback_t
{
    uint32_t CallbackID;
    void    *Gamestate;
    void    *Callback;
    void    *Data;

    Arclightcallback_t() = default;
    Arclightcallback_t(Arclightcallback_t &Right) = default;
    virtual uint32_t Resultsize() = 0;
};
#pragma pack(0)

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
    EXPORT_ATTR int64_t CC_GetArcRunningMode(int64_t a1)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_GetLaunchedParameter(const wchar_t *Gameabbreviation, int Language, wchar_t *Buffer, signed int Bufferlength)
    {
        std::wstring Parameters;

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

        // Build the parameterstring.
        Parameters.append(L"41");           // Current state.
        Parameters.append(L"|");            // Separator.
        Parameters.append(Gameabbreviation);
        Parameters.append(L"|");
        Parameters.append(LanguagefromID(Language));

        // NOTE(Convery): There's one more parameter field to RE.
        std::memcpy(Buffer, Parameters.c_str(), Parameters.size() * 2);
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
    EXPORT_ATTR int64_t CC_GetTokenEx(int64_t a1, int *a2)
    {
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
        static wchar_t Internalstate[1080]{ L"This is our secret, probably encrypted, internal state.."};
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
    EXPORT_ATTR int64_t CC_RegisterCallback(Arclightcallback_t *Callback, uint32_t CallbackID)
    {
        auto toReadable = [](uint32_t ID) -> const char *
        {
            switch (ID)
            {
                case 102: return "LobbyEnter_t";
                case 103: return "LobbyDataUpdate_t";
                case 104: return "LobbyChatUpdate_t";
                case 106: return "LobbyMatchList_t";
                case 108: return "LobbyCreated_t";

                case 202: return "P2PSessionRequest_t";
                case 203: return "P2PSessionConnectFail_t";

                case 301: return "GameInvite_t";
                case 302: return "FriendsStatus_t";

                case 401: return "P2PSessionRequest_t";

                default: return "Unknown";
            }
        };

        Debugprint(va("Register callback: %s", toReadable(CallbackID)));
        return -2;
    }
    EXPORT_ATTR int64_t CC_RunCallbacks()
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_SetViewableRect(const wchar_t *Gameabbreviation, uint32_t Top, uint32_t Left, uint32_t Bottom, uint32_t Right)
    {
        Debugprint(va("Creating gamewindow at %u %u %u %u", Top, Left, Bottom, Right));
        return 0;
    }
    EXPORT_ATTR int64_t CC_ShowOverlay(int64_t a1, unsigned int a2)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_UnInit(int64_t a1)
    {
        return 0;
    }
    EXPORT_ATTR int64_t CC_UnregisterCallback(Arclightcallback_t *Callback)
    {
        return 0;
    }
}
