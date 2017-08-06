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

// If both DLC-ID and app-ID are set, app-ID is the owner of the DLC.
using Steamitem_t = struct { uint32_t DLCID; uint32_t ApplicationID; std::string Installpath; };
std::vector<Steamitem_t> Purchaseditems;
void Updatepurchases()
{
    #if defined(_WIN32)
    std::FILE *Pipe = _popen("ayria://steamgames", "rt");
    #else
    std::FILE *Pipe = popen("ayria://steamgames", "rt");
    #endif

    if (!Pipe) return;

    // The output is split into chucks of 10 games..
    auto Buffer = std::make_unique<char[]>(8192);
    while (std::fgets(Buffer.get(), 8192, Pipe))
    {
        try
        {
            auto Parsed = nlohmann::json::parse(Buffer.get());

            for (auto &Item : Parsed["Steamgames"])
            {
                uint32_t ApplicationID;
                std::string Installpath;

                if (Item["ApplicationID"].is_null()) continue;
                if (Item["Installpath"].is_null()) continue;
                if (Item["DLCID"].is_null()) continue;

                Purchaseditems.push_back({ Item["DLCID"], Item["ApplicationID"], Item["Installpath"] });
            }
        }
        catch (...) {};
    }

    #if defined(_WIN32)
    _pclose(Pipe);
    #else
    pclose(Pipe);
    #endif
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
        if (0 == Purchaseditems.size()) Updatepurchases();

        // If we could not fetch any info, assume ownership.
        if (0 == Purchaseditems.size()) return true;

        for (auto &Item : Purchaseditems)
            if (Item.ApplicationID == nAppID)
                return true;

        return false;
    }
    bool BIsDlcInstalled(uint32_t nAppID)
    {
        // Get the purchased items.
        if (0 == Purchaseditems.size()) Updatepurchases();

        // If we could not fetch any info, assume ownership.
        if (0 == Purchaseditems.size()) return true;

        for (auto &Item : Purchaseditems)
            if (Item.ApplicationID == nAppID && Item.DLCID)
                return true;

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
        int Count = 0;

        for (auto &Item : Purchaseditems)
            if (Item.ApplicationID == Steamconfig::ApplicationID)
                if (Item.DLCID)
                    Count++;

        return Count;
    }
    bool BGetDLCDataByIndex(int iDLC, uint32_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize)
    {
        Printfunction();
        return false;
    }
    void InstallDLC(uint32_t nAppID)
    {
        Printfunction();
        return;
    }
    void UninstallDLC(uint32_t nAppID)
    {
        Printfunction();
        return;
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
        if (0 == Purchaseditems.size()) Updatepurchases();

        for (auto &Item : Purchaseditems)
        {
            if (Item.ApplicationID == appID)
            {
                if (Item.Installpath.size() <= cchFolderBufferSize)
                {
                    std::strcpy(pchFolder, Item.Installpath.c_str());
                    return Item.Installpath.size();
                }
            }
        }

        return 0;
    }
    bool BIsAppInstalled(uint32_t appID)
    {
        // Get the purchased items.
        if (0 == Purchaseditems.size()) Updatepurchases();

        // If we could not fetch any info, assume ownership.
        if (0 == Purchaseditems.size()) return true;

        for (auto &Item : Purchaseditems)
        {
            if (Item.ApplicationID == appID || Item.DLCID == appID)
            {
                std::FILE *Filehandle = std::fopen(Item.Installpath.c_str(), "rb");
                if (!Filehandle) return false;
                std::fclose(Filehandle);
                return true;
            }
        }

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
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps001", new SteamApps001);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps002", new SteamApps002);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps003", new SteamApps003);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps004", new SteamApps004);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps005", new SteamApps005);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps006", new SteamApps006);
        Interfacemanager::Addinterface(STEAM_APPS, "SteamApps007", new SteamApps007);
    }
};
static Steamappsloader Interfaceloader{};
