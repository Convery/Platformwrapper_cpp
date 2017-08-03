/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Platform specific utilities for steam.
*/

#include "../../Stdinclude.h"

#if defined (_WIN32)
#include <Windows.h>

constexpr const char *Gameoverlay = sizeof(void *) == 8 ? "gameoverlayrenderer64.dll" : "gameoverlayrenderer.dll";
#endif

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;

#pragma region Methods
class SteamUtils
{
public:
    uint32_t GetSecondsSinceAppActive()
    {
        Printfunction();
        return uint32_t(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() - Steamconfig::Startuptimestamp);
    }
    uint32_t GetSecondsSinceComputerActive()
    {
        Printfunction();
        return uint32_t(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() - Steamconfig::Startuptimestamp + 600);
    }
    uint32_t GetConnectedUniverse()
    {
        Printfunction();

        // k_EUniversePublic
        return 1;
    }
    uint32_t GetServerRealTime()
    {
        Printfunction();
        return uint32_t(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    }

    const char *GetIPCountry()
    {
        Printfunction();
        /*
            TODO(Convery):
            Connect to the client dll and ask.
        */

        return "SE";
    }
    bool GetImageSize(int iImage, uint32_t *pnWidth, uint32_t *pnHeight)
    {
        Printfunction();

        // We do not handle any image requests.
        return false;
    }
    bool GetImageRGBA(int iImage, uint8_t *pubDest, int nDestBufferSize)
    {
        Printfunction();

        // We do not handle any image requests.
        return false;
    }
    bool GetCSERIPPort(uint32_t *unIP, uint16_t *usPort)
    {
        Printfunction();

        // As we don't connect to steam directly, this is not needed.
        return false;
    }
    uint8_t GetCurrentBatteryPower()
    {
        Printfunction();

        // We are always on AC power.
        return 255;
    }

    uint32_t GetAppID()
    {
        Printfunction();
        return Steamconfig::ApplicationID;
    }
    void SetOverlayNotificationPosition(uint32_t eNotificationPosition)
    {
        #if defined (_WIN32)
        HMODULE Library = GetModuleHandleA(Gameoverlay);
        if (Library)
        {
            FARPROC _SetNotificationPosition = GetProcAddress(Library, "SetNotificationPosition");

            if (_SetNotificationPosition)
            {
                ((void(*)(int32_t))_SetNotificationPosition)(eNotificationPosition);
            }
        }
        #endif
    }
    bool IsAPICallCompleted(uint64_t hSteamAPICall, bool *pbFailed)
    {
        return SteamCallback::CallComplete(hSteamAPICall);
    }
    uint32_t GetAPICallFailureReason(uint64_t hSteamAPICall)
    {
        return 0;
    }
    bool GetAPICallResult(uint64_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed)
    {
        Printfunction();
        return false;
    }
    void RunFrame()
    {
        SteamCallback::RunCallbacks();
    }
    uint32_t GetIPCCallCount()
    {
        Printfunction();

        // Debug information.
        return 100;
    }
    void SetWarningMessageHook(size_t pFunction)
    {
        Printfunction();
    }

    bool IsOverlayEnabled()
    {
        #if defined (_WIN32)
        HMODULE Library = GetModuleHandleA(Gameoverlay);
        if (Library)
        {
            FARPROC _IsOverlayEnabled = GetProcAddress(Library, "IsOverlayEnabled");

            if (_IsOverlayEnabled)
            {
                return ((bool(*)())_IsOverlayEnabled)();
            }
        }
        #endif
        return false;
    }

    bool BOverlayNeedsPresent()
    {
        #if defined (_WIN32)
        HMODULE Library = GetModuleHandleA(Gameoverlay);
        if (Library)
        {
            FARPROC _BOverlayNeedsPresent = GetProcAddress(Library, "BOverlayNeedsPresent");

            if (_BOverlayNeedsPresent)
            {
                return ((bool(*)())_BOverlayNeedsPresent)();
            }
        }
        #endif
        return false;
    }
    uint64_t CheckFileSignature(const char *szFileName)
    {
        Printfunction();
        return 0;
    }
    bool ShowGamepadTextInput(uint32_t eInputMode, uint32_t eInputLineMode, const char *szText, uint32_t uMaxLength)
    {
        Printfunction();
        return false;
    }
    uint32_t GetEnteredGamepadTextLength()
    {
        Printfunction();
        return 0;
    }
    bool GetEnteredGamepadTextInput(char *pchValue, uint32_t cchValueMax)
    {
        Printfunction();
        return false;
    }

    const char *GetSteamUILanguage()
    {
        Printfunction();
        return Steamconfig::Language;
    }
    bool IsSteamRunningInVR()
    {
        Printfunction();
        return false;
    }
};
#pragma endregion

SteamUtilities001::SteamUtilities001()
{
    Createmethod(0, SteamUtils, GetSecondsSinceAppActive);
    Createmethod(1, SteamUtils, GetSecondsSinceComputerActive);
    Createmethod(2, SteamUtils, GetConnectedUniverse);
    Createmethod(3, SteamUtils, GetServerRealTime);
}
SteamUtilities002::SteamUtilities002()
{
    Createmethod(0, SteamUtils, GetSecondsSinceAppActive);
    Createmethod(1, SteamUtils, GetSecondsSinceComputerActive);
    Createmethod(2, SteamUtils, GetConnectedUniverse);
    Createmethod(3, SteamUtils, GetServerRealTime);
    Createmethod(4, SteamUtils, GetIPCountry);
    Createmethod(5, SteamUtils, GetImageSize);
    Createmethod(6, SteamUtils, GetImageRGBA);
    Createmethod(7, SteamUtils, GetCSERIPPort);
    Createmethod(8, SteamUtils, GetCurrentBatteryPower);
}
SteamUtilities003::SteamUtilities003()
{
    Createmethod(0, SteamUtils, GetSecondsSinceAppActive);
    Createmethod(1, SteamUtils, GetSecondsSinceComputerActive);
    Createmethod(2, SteamUtils, GetConnectedUniverse);
    Createmethod(3, SteamUtils, GetServerRealTime);
    Createmethod(4, SteamUtils, GetIPCountry);
    Createmethod(5, SteamUtils, GetImageSize);
    Createmethod(6, SteamUtils, GetImageRGBA);
    Createmethod(7, SteamUtils, GetCSERIPPort);
    Createmethod(8, SteamUtils, GetCurrentBatteryPower);
    Createmethod(9, SteamUtils, GetAppID);
    Createmethod(10, SteamUtils, SetOverlayNotificationPosition);
    Createmethod(11, SteamUtils, IsAPICallCompleted);
    Createmethod(12, SteamUtils, GetAPICallFailureReason);
    Createmethod(13, SteamUtils, GetAPICallResult);
    Createmethod(14, SteamUtils, RunFrame);
    Createmethod(15, SteamUtils, GetIPCCallCount);
    Createmethod(16, SteamUtils, SetWarningMessageHook);
}
SteamUtilities004::SteamUtilities004()
{
    Createmethod(0, SteamUtils, GetSecondsSinceAppActive);
    Createmethod(1, SteamUtils, GetSecondsSinceComputerActive);
    Createmethod(2, SteamUtils, GetConnectedUniverse);
    Createmethod(3, SteamUtils, GetServerRealTime);
    Createmethod(4, SteamUtils, GetIPCountry);
    Createmethod(5, SteamUtils, GetImageSize);
    Createmethod(6, SteamUtils, GetImageRGBA);
    Createmethod(7, SteamUtils, GetCSERIPPort);
    Createmethod(8, SteamUtils, GetCurrentBatteryPower);
    Createmethod(9, SteamUtils, GetAppID);
    Createmethod(10, SteamUtils, SetOverlayNotificationPosition);
    Createmethod(11, SteamUtils, IsAPICallCompleted);
    Createmethod(12, SteamUtils, GetAPICallFailureReason);
    Createmethod(13, SteamUtils, GetAPICallResult);
    Createmethod(14, SteamUtils, RunFrame);
    Createmethod(15, SteamUtils, GetIPCCallCount);
    Createmethod(16, SteamUtils, SetWarningMessageHook);
    Createmethod(17, SteamUtils, IsOverlayEnabled);
}
SteamUtilities005::SteamUtilities005()
{
    Createmethod(0, SteamUtils, GetSecondsSinceAppActive);
    Createmethod(1, SteamUtils, GetSecondsSinceComputerActive);
    Createmethod(2, SteamUtils, GetConnectedUniverse);
    Createmethod(3, SteamUtils, GetServerRealTime);
    Createmethod(4, SteamUtils, GetIPCountry);
    Createmethod(5, SteamUtils, GetImageSize);
    Createmethod(6, SteamUtils, GetImageRGBA);
    Createmethod(7, SteamUtils, GetCSERIPPort);
    Createmethod(8, SteamUtils, GetCurrentBatteryPower);
    Createmethod(9, SteamUtils, GetAppID);
    Createmethod(10, SteamUtils, SetOverlayNotificationPosition);
    Createmethod(11, SteamUtils, IsAPICallCompleted);
    Createmethod(12, SteamUtils, GetAPICallFailureReason);
    Createmethod(13, SteamUtils, GetAPICallResult);
    Createmethod(14, SteamUtils, RunFrame);
    Createmethod(15, SteamUtils, GetIPCCallCount);
    Createmethod(16, SteamUtils, SetWarningMessageHook);
    Createmethod(17, SteamUtils, IsOverlayEnabled);
    Createmethod(18, SteamUtils, BOverlayNeedsPresent);
    Createmethod(19, SteamUtils, CheckFileSignature);
    Createmethod(20, SteamUtils, ShowGamepadTextInput);
    Createmethod(21, SteamUtils, GetEnteredGamepadTextLength);
    Createmethod(22, SteamUtils, GetEnteredGamepadTextInput);
};
SteamUtilities006::SteamUtilities006()
{
    Createmethod(0, SteamUtils, GetSecondsSinceAppActive);
    Createmethod(1, SteamUtils, GetSecondsSinceComputerActive);
    Createmethod(2, SteamUtils, GetConnectedUniverse);
    Createmethod(3, SteamUtils, GetServerRealTime);
    Createmethod(4, SteamUtils, GetIPCountry);
    Createmethod(5, SteamUtils, GetImageSize);
    Createmethod(6, SteamUtils, GetImageRGBA);
    Createmethod(7, SteamUtils, GetCSERIPPort);
    Createmethod(8, SteamUtils, GetCurrentBatteryPower);
    Createmethod(9, SteamUtils, GetAppID);
    Createmethod(10, SteamUtils, SetOverlayNotificationPosition);
    Createmethod(11, SteamUtils, IsAPICallCompleted);
    Createmethod(12, SteamUtils, GetAPICallFailureReason);
    Createmethod(13, SteamUtils, GetAPICallResult);
    Createmethod(14, SteamUtils, RunFrame);
    Createmethod(15, SteamUtils, GetIPCCallCount);
    Createmethod(16, SteamUtils, SetWarningMessageHook);
    Createmethod(17, SteamUtils, IsOverlayEnabled);
    Createmethod(18, SteamUtils, BOverlayNeedsPresent);
    Createmethod(19, SteamUtils, CheckFileSignature);
    Createmethod(20, SteamUtils, ShowGamepadTextInput);
    Createmethod(21, SteamUtils, GetEnteredGamepadTextLength);
    Createmethod(22, SteamUtils, GetEnteredGamepadTextInput);
    Createmethod(23, SteamUtils, GetSteamUILanguage);
    Createmethod(24, SteamUtils, IsSteamRunningInVR);
};
SteamUtilities007::SteamUtilities007()
{
    Createmethod(0, SteamUtils, GetSecondsSinceAppActive);
    Createmethod(1, SteamUtils, GetSecondsSinceComputerActive);
    Createmethod(2, SteamUtils, GetConnectedUniverse);
    Createmethod(3, SteamUtils, GetServerRealTime);
    Createmethod(4, SteamUtils, GetIPCountry);
    Createmethod(5, SteamUtils, GetImageSize);
    Createmethod(6, SteamUtils, GetImageRGBA);
    Createmethod(7, SteamUtils, GetCSERIPPort);
    Createmethod(8, SteamUtils, GetCurrentBatteryPower);
    Createmethod(9, SteamUtils, GetAppID);
    Createmethod(10, SteamUtils, SetOverlayNotificationPosition);
    Createmethod(11, SteamUtils, IsAPICallCompleted);
    Createmethod(12, SteamUtils, GetAPICallFailureReason);
    Createmethod(13, SteamUtils, GetAPICallResult);
    Createmethod(14, SteamUtils, RunFrame);
    Createmethod(15, SteamUtils, GetIPCCallCount);
    Createmethod(16, SteamUtils, SetWarningMessageHook);
    Createmethod(17, SteamUtils, IsOverlayEnabled);
    Createmethod(18, SteamUtils, BOverlayNeedsPresent);
    Createmethod(19, SteamUtils, CheckFileSignature);
    Createmethod(20, SteamUtils, ShowGamepadTextInput);
    Createmethod(21, SteamUtils, GetEnteredGamepadTextLength);
    Createmethod(22, SteamUtils, GetEnteredGamepadTextInput);
    Createmethod(23, SteamUtils, GetSteamUILanguage);
    Createmethod(24, SteamUtils, IsSteamRunningInVR);
};

struct Steamutilitiesloader
{
    Steamutilitiesloader()
    {
        Interfacemanager::Addinterface(STEAM_UTILS, "SteamUtilities001", new SteamUtilities001);
        Interfacemanager::Addinterface(STEAM_UTILS, "SteamUtilities002", new SteamUtilities002);
        Interfacemanager::Addinterface(STEAM_UTILS, "SteamUtilities003", new SteamUtilities003);
        Interfacemanager::Addinterface(STEAM_UTILS, "SteamUtilities004", new SteamUtilities004);
        Interfacemanager::Addinterface(STEAM_UTILS, "SteamUtilities005", new SteamUtilities005);
        Interfacemanager::Addinterface(STEAM_UTILS, "SteamUtilities006", new SteamUtilities006);
        Interfacemanager::Addinterface(STEAM_UTILS, "SteamUtilities007", new SteamUtilities007);
    }
};
static Steamutilitiesloader Interfaceloader{};
