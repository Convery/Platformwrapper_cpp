/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#include "All.h"

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;

#pragma region Methods
class SteamApps
{
public:
    int GetAppData(uint32_t nAppID, const char *pchKey, char *pchValue, int cchValueMax)
    {
        PrintFunction();
        return 0;
    }
    bool BIsSubscribed()
    {
        return true;
    }
    bool BIsLowViolence()
    {
        PrintFunction();
        return false;
    }
    bool BIsCybercafe()
    {
        PrintFunction();
        return false;
    }
    bool BIsVACBanned()
    {
        return false;
    }
    const char *GetCurrentGameLanguage()
    {
        PrintFunction();
        return Steamconfig::Language;
    }
    const char *GetAvailableGameLanguages()
    {
        PrintFunction();
        return Steamconfig::Language;
    }
    bool BIsSubscribedApp(uint32_t nAppID)
    {
        /*
            TODO(Convery):
            Query the database to see if the user owns this game.
        */

        return true;
    }
    bool BIsDlcInstalled(uint32_t nAppID)
    {
        /*
            TODO(Convery):
            Query the database to see if the user owns this DLC.
        */

        return true;
    }
    uint32_t GetEarliestPurchaseUnixTime(uint32_t nAppID)
    {
        PrintFunction();
        return uint32_t(Steamconfig::StartupTimestamp - 600);
    }
    bool BIsSubscribedFromFreeWeekend()
    {
        PrintFunction();
        return false;
    }
    int GetDLCCount()
    {
        PrintFunction();

        /*
            TODO(Convery):
            Query the database to see how many DLC we should handle.
        */

        return 0;
    }
    bool BGetDLCDataByIndex(int iDLC, uint32_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize)
    {
        PrintFunction();
        return false;
    }
    void InstallDLC(uint32_t nAppID)
    {
        PrintFunction();
        return;
    }
    void UninstallDLC(uint32_t nAppID)
    {
        PrintFunction();
        return;
    }
    void RequestAppProofOfPurchaseKey(uint32_t nAppID)
    {
        PrintFunction();
        return;
    }
    bool GetCurrentBetaName(char *pchName, int cchNameBufferSize)
    {
        PrintFunction();
        return false;
    }
    bool MarkContentCorrupt(bool bMissingFilesOnly)
    {
        PrintFunction();
        return false;
    }
    uint32_t GetInstalledDepots0(uint32_t *pvecDepots, uint32_t cMaxDepots)
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetAppInstallDir(uint32_t appID, char *pchFolder, uint32_t cchFolderBufferSize)
    {
        PrintFunction();

        /*
            TODO(Convery):
            Implement a portable GetWorkingDirectory().
        */

        return 0;
    }
    bool BIsAppInstalled(uint32_t appID)
    {
        /*
            TODO(Convery):
            Query the database to see if the user owns this DLC.
        */

        return false;
    }
    uint32_t GetInstalledDepots1(uint32_t appID, uint32_t *pvecDepots, uint32_t cMaxDepots)
    {
        PrintFunction();
        return 0;
    }
    CSteamID GetAppOwner()
    {
        PrintFunction();
        return CSteamID(Steamconfig::UserID);
    }
    const char *GetLaunchQueryParam(const char *pchKey)
    {
        PrintFunction();
        return "";
    }
    bool GetDlcDownloadProgress(uint32_t nAppID, uint64_t *punBytesDownloaded, uint64_t *punBytesTotal)
    {
        PrintFunction();
        return true;
    }
    int GetAppBuildId()
    {
        PrintFunction();
        return 0;
    }
    uint64_t RegisterActivationCode(const char *pchActivationCode)
    {
        PrintFunction();
        return 0;
    }
};
#pragma endregion

SteamApps001::SteamApps001()
{
    Createmethod(0, SteamApps, GetAppData);
};
SteamApps002::SteamApps002()
{
    Createmethod(0, SteamApps, BIsSubscribed);
    Createmethod(1, SteamApps, BIsLowViolence);
    Createmethod(2, SteamApps, BIsCybercafe);
    Createmethod(3, SteamApps, BIsVACBanned);
    Createmethod(4, SteamApps, GetCurrentGameLanguage);
    Createmethod(5, SteamApps, GetAvailableGameLanguages);
    Createmethod(6, SteamApps, BIsSubscribedApp);
};
SteamApps003::SteamApps003()
{
    Createmethod(0, SteamApps, BIsSubscribed);
    Createmethod(1, SteamApps, BIsLowViolence);
    Createmethod(2, SteamApps, BIsCybercafe);
    Createmethod(3, SteamApps, BIsVACBanned);
    Createmethod(4, SteamApps, GetCurrentGameLanguage);
    Createmethod(5, SteamApps, GetAvailableGameLanguages);
    Createmethod(6, SteamApps, BIsSubscribedApp);
    Createmethod(7, SteamApps, BIsDlcInstalled);
};
SteamApps004::SteamApps004()
{
    Createmethod(0, SteamApps, BIsSubscribed);
    Createmethod(1, SteamApps, BIsLowViolence);
    Createmethod(2, SteamApps, BIsCybercafe);
    Createmethod(3, SteamApps, BIsVACBanned);
    Createmethod(4, SteamApps, GetCurrentGameLanguage);
    Createmethod(5, SteamApps, GetAvailableGameLanguages);
    Createmethod(6, SteamApps, BIsSubscribedApp);
    Createmethod(7, SteamApps, BIsDlcInstalled);
    Createmethod(8, SteamApps, GetEarliestPurchaseUnixTime);
    Createmethod(9, SteamApps, BIsSubscribedFromFreeWeekend);
    Createmethod(10, SteamApps, GetDLCCount);
    Createmethod(11, SteamApps, BGetDLCDataByIndex);
    Createmethod(12, SteamApps, InstallDLC);
    Createmethod(13, SteamApps, UninstallDLC);
};
SteamApps005::SteamApps005()
{
    Createmethod(0, SteamApps, BIsSubscribed);
    Createmethod(1, SteamApps, BIsLowViolence);
    Createmethod(2, SteamApps, BIsCybercafe);
    Createmethod(3, SteamApps, BIsVACBanned);
    Createmethod(4, SteamApps, GetCurrentGameLanguage);
    Createmethod(5, SteamApps, GetAvailableGameLanguages);
    Createmethod(6, SteamApps, BIsSubscribedApp);
    Createmethod(7, SteamApps, BIsDlcInstalled);
    Createmethod(8, SteamApps, GetEarliestPurchaseUnixTime);
    Createmethod(9, SteamApps, BIsSubscribedFromFreeWeekend);
    Createmethod(10, SteamApps, GetDLCCount);
    Createmethod(11, SteamApps, BGetDLCDataByIndex);
    Createmethod(12, SteamApps, InstallDLC);
    Createmethod(13, SteamApps, UninstallDLC);
    Createmethod(14, SteamApps, RequestAppProofOfPurchaseKey);
    Createmethod(15, SteamApps, GetCurrentBetaName);
    Createmethod(16, SteamApps, MarkContentCorrupt);
    Createmethod(17, SteamApps, GetInstalledDepots0);
    Createmethod(18, SteamApps, GetAppInstallDir);
    Createmethod(19, SteamApps, BIsAppInstalled);
};
SteamApps006::SteamApps006()
{
    Createmethod(0, SteamApps, BIsSubscribed);
    Createmethod(1, SteamApps, BIsLowViolence);
    Createmethod(2, SteamApps, BIsCybercafe);
    Createmethod(3, SteamApps, BIsVACBanned);
    Createmethod(4, SteamApps, GetCurrentGameLanguage);
    Createmethod(5, SteamApps, GetAvailableGameLanguages);
    Createmethod(6, SteamApps, BIsSubscribedApp);
    Createmethod(7, SteamApps, BIsDlcInstalled);
    Createmethod(8, SteamApps, GetEarliestPurchaseUnixTime);
    Createmethod(9, SteamApps, BIsSubscribedFromFreeWeekend);
    Createmethod(10, SteamApps, GetDLCCount);
    Createmethod(11, SteamApps, BGetDLCDataByIndex);
    Createmethod(12, SteamApps, InstallDLC);
    Createmethod(13, SteamApps, UninstallDLC);
    Createmethod(14, SteamApps, RequestAppProofOfPurchaseKey);
    Createmethod(15, SteamApps, GetCurrentBetaName);
    Createmethod(16, SteamApps, MarkContentCorrupt);
    Createmethod(17, SteamApps, GetInstalledDepots1);
    Createmethod(18, SteamApps, GetAppInstallDir);
    Createmethod(19, SteamApps, BIsAppInstalled);
    Createmethod(20, SteamApps, GetAppOwner);
    Createmethod(21, SteamApps, GetLaunchQueryParam);
};
SteamApps007::SteamApps007()
{
    Createmethod(0, SteamApps, BIsSubscribed);
    Createmethod(1, SteamApps, BIsLowViolence);
    Createmethod(2, SteamApps, BIsCybercafe);
    Createmethod(3, SteamApps, BIsVACBanned);
    Createmethod(4, SteamApps, GetCurrentGameLanguage);
    Createmethod(5, SteamApps, GetAvailableGameLanguages);
    Createmethod(6, SteamApps, BIsSubscribedApp);
    Createmethod(7, SteamApps, BIsDlcInstalled);
    Createmethod(8, SteamApps, GetEarliestPurchaseUnixTime);
    Createmethod(9, SteamApps, BIsSubscribedFromFreeWeekend);
    Createmethod(10, SteamApps, GetDLCCount);
    Createmethod(11, SteamApps, BGetDLCDataByIndex);
    Createmethod(12, SteamApps, InstallDLC);
    Createmethod(13, SteamApps, UninstallDLC);
    Createmethod(14, SteamApps, RequestAppProofOfPurchaseKey);
    Createmethod(15, SteamApps, GetCurrentBetaName);
    Createmethod(16, SteamApps, MarkContentCorrupt);
    Createmethod(17, SteamApps, GetInstalledDepots1);
    Createmethod(18, SteamApps, GetAppInstallDir);
    Createmethod(19, SteamApps, BIsAppInstalled);
    Createmethod(20, SteamApps, GetAppOwner);
    Createmethod(21, SteamApps, GetLaunchQueryParam);
    Createmethod(22, SteamApps, GetDlcDownloadProgress);
    Createmethod(23, SteamApps, GetAppBuildId);
    Createmethod(24, SteamApps, RegisterActivationCode);
};

struct Steamappsloader
{
    Steamappsloader()
    {
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps001", new SteamApps001);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps002", new SteamApps002);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps003", new SteamApps003);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps004", new SteamApps004);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps005", new SteamApps005);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps006", new SteamApps006);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps007", new SteamApps007);
    }
};
static Steamappsloader Interfaceloader;
