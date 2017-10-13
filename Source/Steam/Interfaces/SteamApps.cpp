/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam application information.
*/

#include "../../Stdinclude.h"

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;
#define Createinterface(Enum, Class)            \
static Class DEV ## Class;                      \
Interfacemanager::Addinterface(Enum, #Class, &DEV ## Class);

// A cache of owned application.
struct Steamgame_t
{
    uint32_t DLCCount;
    uint32_t ApplicationID;
    std::string Installationpath;
};
std::vector<Steamgame_t> Gameslist;

// Update the cache as requested.
void Loadgames()
{
    std::string JSONBuffer;
    Gameslist.clear();

    // Offlinemode reads from disk.
    if (Steamconfig::Offline)
    {
        JSONBuffer = Readfile("./Plugins/" MODULENAME "/Steamgames.json");
    }
    else
    {
        JSONBuffer = Readpipe("ayria://getgames");
    }

    try
    {
        auto Parsed = nlohmann::json::parse(JSONBuffer.c_str());

        for (auto &Item : Parsed["Steamgames"])
        {
            Gameslist.push_back({ Item["DLCCount"], Item["ApplicationID"], Item["Installationpath"] });
        }
    }
    catch (...) {};
}
void Savegames()
{
    nlohmann::json Object;

    for (auto &Item : Gameslist)
    {
        Object["Steamgames"] +=
        {
            { "DLCCount", Item.DLCCount},
            { "ApplicationID", Item.ApplicationID },
            { "Installationpath", Item.Installationpath }
        };
    }

    Writefile("./Plugins/" MODULENAME "/Steamgames.json", Object.dump(4));
}

#pragma region Methods
class SteamApps
{
public:
    int GetAppData(uint32_t nAppID, const char *pchKey, char *pchValue, int cchValueMax)
    {
        Printfunction();
        return 0;
    }
    bool BIsSubscribed()
    {
        return true;
    }
    bool BIsLowViolence()
    {
        Printfunction();
        return false;
    }
    bool BIsCybercafe()
    {
        Printfunction();
        return false;
    }
    bool BIsVACBanned()
    {
        return false;
    }
    const char *GetCurrentGameLanguage()
    {
        Printfunction();
        return Steamconfig::Language;
    }
    const char *GetAvailableGameLanguages()
    {
        Printfunction();
        return Steamconfig::Language;
    }
    bool BIsSubscribedApp(uint32_t nAppID)
    {
        // Get the purchased items.
        if (0 == Gameslist.size()) Loadgames();

        // If we could not fetch any info, assume ownership.
        if (0 == Gameslist.size()) return true;

        for (auto &Item : Gameslist)
            if (Item.ApplicationID == nAppID)
                return true;

        return false;
    }
    bool BIsDlcInstalled(uint32_t nAppID)
    {
        // Get the purchased items.
        if (0 == Gameslist.size()) Loadgames();

        // If we could not fetch any info, assume ownership.
        if (0 == Gameslist.size()) return true;

        for (auto &Item : Gameslist)
            if (Item.ApplicationID == nAppID)
                return Fileexists(Item.Installationpath);

        return false;
    }
    uint32_t GetEarliestPurchaseUnixTime(uint32_t nAppID)
    {
        Printfunction();
        return uint32_t(Steamconfig::Startuptimestamp - 600);
    }
    bool BIsSubscribedFromFreeWeekend()
    {
        Printfunction();
        return false;
    }
    int GetDLCCount()
    {
        Printfunction();

        for (auto &Item : Gameslist)
            if (Item.ApplicationID == Steamconfig::ApplicationID)
                return Item.DLCCount;

        return 0;
    }
    bool BGetDLCDataByIndex(int iDLC, uint32_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize)
    {
        Printfunction();
        return false;
    }
    void InstallDLC(uint32_t nAppID)
    {
        Infoprint(va("Installing DLC %u..", nAppID));

        if (Writepipe("ayria://addgame", nlohmann::json({ "Steamgame", { "ApplicationID", nAppID } })))
            return Loadgames();

        for (auto &Item : Gameslist)
            if (Item.ApplicationID == Steamconfig::ApplicationID)
                Item.DLCCount++;

        Gameslist.push_back({ 0, nAppID, "" });
        Savegames();
    }
    void UninstallDLC(uint32_t nAppID)
    {
        Infoprint(va("Uninstalling DLC %u..", nAppID));

        if (Writepipe("ayria://removegame", nlohmann::json({ "Steamgame", { "ApplicationID", nAppID } })))
            return Loadgames();

        for (auto &Item : Gameslist)
            if (Item.ApplicationID == Steamconfig::ApplicationID)
                Item.DLCCount--;

        for (auto Iterator = Gameslist.begin(); Iterator != Gameslist.end(); ++Iterator)
        {
            if (Iterator->ApplicationID == nAppID)
            {
                Gameslist.erase(Iterator);
                break;
            }
        }
    }
    void RequestAppProofOfPurchaseKey(uint32_t nAppID)
    {
        Printfunction();
        return;
    }
    bool GetCurrentBetaName(char *pchName, int cchNameBufferSize)
    {
        Printfunction();
        return false;
    }
    bool MarkContentCorrupt(bool bMissingFilesOnly)
    {
        Printfunction();
        return false;
    }
    uint32_t GetInstalledDepots0(uint32_t *pvecDepots, uint32_t cMaxDepots)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetAppInstallDir(uint32_t appID, char *pchFolder, uint32_t cchFolderBufferSize)
    {
        Printfunction();

        // Get the purchased items.
        if (0 == Gameslist.size()) Loadgames();

        for (auto &Item : Gameslist)
        {
            if (Item.ApplicationID == appID)
            {
                if (Item.Installationpath.size() <= cchFolderBufferSize)
                {
                    std::strcpy(pchFolder, Item.Installationpath.c_str());
                    return uint32_t(Item.Installationpath.size());
                }
            }
        }

        return 0;
    }
    bool BIsAppInstalled(uint32_t appID)
    {
        // Get the purchased items.
        if (0 == Gameslist.size()) Loadgames();

        // If we could not fetch any info, assume ownership.
        if (0 == Gameslist.size()) return true;

        for (auto &Item : Gameslist)
            if (Item.ApplicationID == appID)
                return Fileexists(Item.Installationpath);

        return false;
    }
    uint32_t GetInstalledDepots1(uint32_t appID, uint32_t *pvecDepots, uint32_t cMaxDepots)
    {
        Printfunction();
        return 0;
    }
    CSteamID GetAppOwner()
    {
        Printfunction();
        return CSteamID(Steamconfig::UserID);
    }
    const char *GetLaunchQueryParam(const char *pchKey)
    {
        Printfunction();
        return "";
    }
    bool GetDlcDownloadProgress(uint32_t nAppID, uint64_t *punBytesDownloaded, uint64_t *punBytesTotal)
    {
        Printfunction();

        /*
            NOTE(Convery):
            I'm not sure if we can ever implement this function.
            A thirdparty delivering content could be considered
            some form of piracy. Check this with legal.
        */

        return false;
    }
    int GetAppBuildId()
    {
        Printfunction();
        return 0;
    }
    uint64_t RegisterActivationCode(const char *pchActivationCode)
    {
        Printfunction();
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
        Createinterface(STEAM_APPS, SteamApps001);
        Createinterface(STEAM_APPS, SteamApps002);
        Createinterface(STEAM_APPS, SteamApps003);
        Createinterface(STEAM_APPS, SteamApps004);
        Createinterface(STEAM_APPS, SteamApps005);
        Createinterface(STEAM_APPS, SteamApps006);
        Createinterface(STEAM_APPS, SteamApps007);
    }
};
static Steamappsloader Interfaceloader{};
