/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam platform specific screenshots.
*/

#include "../../Stdinclude.hpp"

#pragma region Methods
class SteamScreenshots
{
public:
    uint32_t WriteScreenshot(void *pubRGB, uint32_t cubRGB, int nWidth, int nHeight)
    {
        Printfunction();
        return 0;
    }
    uint32_t AddScreenshotToLibrary(const char *pchJpegOrTGAFilename, const char *pchJpegOrTGAThumbFilename, int nWidth, int nHeight)
    {
        Printfunction();
        return 0;
    }
    void TriggerScreenshot()
    {
        Printfunction();
    }
    void HookScreenshots(bool bHook)
    {
        Printfunction();
    }
    bool SetLocation(uint32_t hScreenshot, const char *pchLocation)
    {
        Printfunction();
        return false;
    }
    bool TagUser(uint32_t hScreenshot, CSteamID steamID)
    {
        Printfunction();
        return false;
    }
    bool TagPublishedFile(uint32_t hScreenshot, uint64_t unPublishedFileId)
    {
        Printfunction();
        return false;
    }
};
#pragma endregion

SteamScreenshots001::SteamScreenshots001()
{
    Createmethod(0, SteamScreenshots, WriteScreenshot);
    Createmethod(1, SteamScreenshots, AddScreenshotToLibrary);
    Createmethod(2, SteamScreenshots, TriggerScreenshot);
    Createmethod(3, SteamScreenshots, HookScreenshots);
    Createmethod(4, SteamScreenshots, SetLocation);
    Createmethod(5, SteamScreenshots, TagUser);
};
SteamScreenshots002::SteamScreenshots002()
{
    Createmethod(0, SteamScreenshots, WriteScreenshot);
    Createmethod(1, SteamScreenshots, AddScreenshotToLibrary);
    Createmethod(2, SteamScreenshots, TriggerScreenshot);
    Createmethod(3, SteamScreenshots, HookScreenshots);
    Createmethod(4, SteamScreenshots, SetLocation);
    Createmethod(5, SteamScreenshots, TagUser);
    Createmethod(6, SteamScreenshots, TagPublishedFile);
};

struct Steamscreenshotsloader
{
    Steamscreenshotsloader()
    {
        Createinterface(STEAM_SCREENSHOTS, SteamScreenshots001);
        Createinterface(STEAM_SCREENSHOTS, SteamScreenshots002);
    }
};
static Steamscreenshotsloader Interfaceloader{};
