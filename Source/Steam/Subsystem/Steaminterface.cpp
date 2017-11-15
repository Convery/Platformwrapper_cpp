/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam interfaces usually supplied by the
        Steamclient.dll or libsteam.so
*/

#include "../../Stdinclude.h"
#include <sstream>

// Steam_api providers.
constexpr const char *Steamso = "libsteam_api.so";
constexpr const char *Steamdll = sizeof(size_t) == sizeof(uint64_t) ? "steam_api64.dll" : "steam_api.dll";

// Steam interface scanning.
std::vector<std::pair<eInterfaceType /* Type */, void * /* Interface */>> *Interfacestore;
std::unordered_map<eInterfaceType /* Type */, void * /* Interface */> Interfacemap;
std::unordered_map<std::string /* Name */, void * /* Interface */> *Interfacenames;
std::unordered_map<const char *, std::pair<const char *, eInterfaceType>> Scandata =
{
    //        Scanstring                     Interface              Type
    { "STEAMAPPS_INTERFACE_VERSION001", {"SteamApps001", eInterfaceType::STEAM_APPS } },
    { "STEAMAPPS_INTERFACE_VERSION002", {"SteamApps002", eInterfaceType::STEAM_APPS } },
    { "STEAMAPPS_INTERFACE_VERSION003", {"SteamApps003", eInterfaceType::STEAM_APPS } },
    { "STEAMAPPS_INTERFACE_VERSION004", {"SteamApps004", eInterfaceType::STEAM_APPS } },
    { "STEAMAPPS_INTERFACE_VERSION005", {"SteamApps005", eInterfaceType::STEAM_APPS } },
    { "STEAMAPPS_INTERFACE_VERSION006", {"SteamApps006", eInterfaceType::STEAM_APPS } },
    { "STEAMAPPS_INTERFACE_VERSION007", {"SteamApps007", eInterfaceType::STEAM_APPS } },

    { "SteamFriends001", {"SteamFriends001", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends002", {"SteamFriends002", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends003", {"SteamFriends003", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends004", {"SteamFriends004", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends005", {"SteamFriends005", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends006", {"SteamFriends006", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends007", {"SteamFriends007", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends008", {"SteamFriends008", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends009", {"SteamFriends009", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends010", {"SteamFriends010", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends011", {"SteamFriends011", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends012", {"SteamFriends012", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends013", {"SteamFriends013", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends014", {"SteamFriends014", eInterfaceType::STEAM_FRIENDS } },
    { "SteamFriends015", {"SteamFriends015", eInterfaceType::STEAM_FRIENDS } },

    { "SteamGameServer001", {"SteamGameserver001", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer002", {"SteamGameserver002", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer003", {"SteamGameserver003", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer004", {"SteamGameserver004", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer005", {"SteamGameserver005", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer006", {"SteamGameserver006", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer007", {"SteamGameserver007", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer008", {"SteamGameserver008", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer009", {"SteamGameserver009", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer010", {"SteamGameserver010", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer011", {"SteamGameserver011", eInterfaceType::STEAM_GAMESERVER } },
    { "SteamGameServer012", {"SteamGameserver012", eInterfaceType::STEAM_GAMESERVER } },

    { "SteamMatchMaking001", {"SteamMatchmaking001", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking002", {"SteamMatchmaking002", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking003", {"SteamMatchmaking003", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking004", {"SteamMatchmaking004", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking005", {"SteamMatchmaking005", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking006", {"SteamMatchmaking006", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking007", {"SteamMatchmaking007", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking008", {"SteamMatchmaking008", eInterfaceType::STEAM_MATCHMAKING } },
    { "SteamMatchMaking009", {"SteamMatchmaking009", eInterfaceType::STEAM_MATCHMAKING } },

    { "SteamNetworking001", {"SteamNetworking001", eInterfaceType::STEAM_NETWORKING } },
    { "SteamNetworking002", {"SteamNetworking002", eInterfaceType::STEAM_NETWORKING } },
    { "SteamNetworking003", {"SteamNetworking003", eInterfaceType::STEAM_NETWORKING } },
    { "SteamNetworking004", {"SteamNetworking004", eInterfaceType::STEAM_NETWORKING } },
    { "SteamNetworking005", {"SteamNetworking005", eInterfaceType::STEAM_NETWORKING } },

    { "STEAMREMOTESTORAGE_INTERFACE_VERSION001", {"SteamRemotestorage001", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION002", {"SteamRemotestorage002", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION003", {"SteamRemotestorage003", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION004", {"SteamRemotestorage004", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION005", {"SteamRemotestorage005", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION006", {"SteamRemotestorage006", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION007", {"SteamRemotestorage007", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION008", {"SteamRemotestorage008", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION009", {"SteamRemotestorage009", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION010", {"SteamRemotestorage010", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION011", {"SteamRemotestorage011", eInterfaceType::STEAM_REMOTESTORAGE } },
    { "STEAMREMOTESTORAGE_INTERFACE_VERSION012", {"SteamRemotestorage012", eInterfaceType::STEAM_REMOTESTORAGE } },

    { "STEAMSCREENSHOTS_INTERFACE_VERSION001", {"SteamScreenshots001", eInterfaceType::STEAM_SCREENSHOTS } },
    { "STEAMSCREENSHOTS_INTERFACE_VERSION002", {"SteamScreenshots002", eInterfaceType::STEAM_SCREENSHOTS } },

    { "SteamUser001", {"SteamUser001", eInterfaceType::STEAM_USER } },
    { "SteamUser002", {"SteamUser002", eInterfaceType::STEAM_USER } },
    { "SteamUser003", {"SteamUser003", eInterfaceType::STEAM_USER } },
    { "SteamUser004", {"SteamUser004", eInterfaceType::STEAM_USER } },
    { "SteamUser005", {"SteamUser005", eInterfaceType::STEAM_USER } },
    { "SteamUser006", {"SteamUser006", eInterfaceType::STEAM_USER } },
    { "SteamUser007", {"SteamUser007", eInterfaceType::STEAM_USER } },
    { "SteamUser008", {"SteamUser008", eInterfaceType::STEAM_USER } },
    { "SteamUser009", {"SteamUser009", eInterfaceType::STEAM_USER } },
    { "SteamUser010", {"SteamUser010", eInterfaceType::STEAM_USER } },
    { "SteamUser011", {"SteamUser011", eInterfaceType::STEAM_USER } },
    { "SteamUser012", {"SteamUser012", eInterfaceType::STEAM_USER } },
    { "SteamUser013", {"SteamUser013", eInterfaceType::STEAM_USER } },
    { "SteamUser014", {"SteamUser014", eInterfaceType::STEAM_USER } },
    { "SteamUser015", {"SteamUser015", eInterfaceType::STEAM_USER } },
    { "SteamUser016", {"SteamUser016", eInterfaceType::STEAM_USER } },
    { "SteamUser017", {"SteamUser017", eInterfaceType::STEAM_USER } },
    { "SteamUser018", {"SteamUser018", eInterfaceType::STEAM_USER } },

    { "STEAMUSERSTATS_INTERFACE_VERSION001", {"SteamUserstats001", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION002", {"SteamUserstats002", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION003", {"SteamUserstats003", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION004", {"SteamUserstats004", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION005", {"SteamUserstats005", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION006", {"SteamUserstats006", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION007", {"SteamUserstats007", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION008", {"SteamUserstats008", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION009", {"SteamUserstats009", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION010", {"SteamUserstats010", eInterfaceType::STEAM_USERSTATS } },
    { "STEAMUSERSTATS_INTERFACE_VERSION011", {"SteamUserstats011", eInterfaceType::STEAM_USERSTATS } },

    { "SteamUtils001", {"SteamUtilities001", eInterfaceType::STEAM_UTILS } },
    { "SteamUtils002", {"SteamUtilities002", eInterfaceType::STEAM_UTILS } },
    { "SteamUtils003", {"SteamUtilities003", eInterfaceType::STEAM_UTILS } },
    { "SteamUtils004", {"SteamUtilities004", eInterfaceType::STEAM_UTILS } },
    { "SteamUtils005", {"SteamUtilities005", eInterfaceType::STEAM_UTILS } },
    { "SteamUtils006", {"SteamUtilities006", eInterfaceType::STEAM_UTILS } },
    { "SteamUtils007", {"SteamUtilities007", eInterfaceType::STEAM_UTILS } },

    { "SteamMasterServerUpdater001", {"SteamMasterserverUpdater001", eInterfaceType::STEAM_MASTERSERVERUPDATER } },

    /* More interfaces */
};

// Create the map from cache.
void Setmapbyname(eInterfaceType Type, const char *Name)
{
    Interfacemap[Type] = Interfacemanager::Fetchinterface(Name);
}
void Createcache(std::FILE *Filehandle)
{
    std::vector<const char *> Results;

    // Check the filesize.
    std::fseek(Filehandle, 0, SEEK_END);
    auto Filesize = std::ftell(Filehandle);
    std::fseek(Filehandle, 0, SEEK_SET);

    // Read into a buffer.
    auto Buffer = std::make_unique<char[]>(Filesize);
    std::fread(Buffer.get(), Filesize, 1, Filehandle);

    // Iterate through the buffer and find the interfaces.
    for (long i = 0; i < Filesize; ++i)
    {
        // Skip to the interesting data.
        if (Buffer[i] != 'S') continue;

        // Check all scandata.
        for (auto &Item : Scandata)
        {
            if (std::strstr(&Buffer[i], Item.first))
            {
                Setmapbyname(Item.second.second, Item.second.first);
                Results.push_back(Item.second.first);
                break;
            }
        }
    }

    // Write to the cache.
    {
        std::string Databuffer;
        for (auto &Item : Results)
            Databuffer += va("%s\n", Item);

        Package::Write("Steaminterfacecache", Databuffer);
    }
}
bool Readcache()
{
    if (!Package::Exists("Steaminterfacecache"))
        return false;

    auto Filebuffer = Package::Read("Steaminterfacecache");
    if (Filebuffer.size() == 0)
        return false;

    std::string Inputstring;
    auto Filestream = std::istringstream(Filebuffer);
    while(std::getline(Filestream, Inputstring, '\n'))
    {
        #define Checktype(Interfacename, Type)                  \
        if(std::strstr(Inputstring.c_str(), Interfacename))     \
        { Setmapbyname(Type, Inputstring.c_str()); continue; }  \

        // Add the interface by type.
        Checktype("SteamUGC0", STEAM_UGC);
        Checktype("SteamApps0", STEAM_APPS);
        Checktype("SteamUser0", STEAM_USER);
        Checktype("SteamHTTP0", STEAM_HTTP);
        Checktype("SteamMusic0", STEAM_MUSIC);
        Checktype("SteamVideo0", STEAM_VIDEO);
        Checktype("SteamClient0", STEAM_CLIENT);
        Checktype("SteamUtilities0", STEAM_UTILS);
        Checktype("SteamFriends0", STEAM_FRIENDS);
        Checktype("SteamApplist0", STEAM_APPLIST);
        Checktype("SteamInventory0", STEAM_INVENTORY);
        Checktype("SteamUserstats0", STEAM_USERSTATS);
        Checktype("SteamController0", STEAM_CONTROLLER);
        Checktype("SteamGameserver0", STEAM_GAMESERVER);
        Checktype("SteamNetworking0", STEAM_NETWORKING);
        Checktype("SteamHTMLSurface0", STEAM_HTMLSURFACE);
        Checktype("SteamMusicremote0", STEAM_MUSICREMOTE);
        Checktype("SteamScreenshots0", STEAM_SCREENSHOTS);
        Checktype("SteamMatchmaking0", STEAM_MATCHMAKING);
        Checktype("SteamRemotestorage0", STEAM_REMOTESTORAGE);
        Checktype("SteamContentserver0", STEAM_CONTENTSERVER);
        Checktype("SteamUnifiedmessages0", STEAM_UNIFIEDMESSAGES);
        Checktype("SteamGameserverStats0", STEAM_GAMESERVERSTATS);
        Checktype("SteamMatchamkingservers0", STEAM_MATCHMAKINGSERVERS);
        Checktype("SteamMasterserverUpdater0", STEAM_MASTERSERVERUPDATER);
    }

    return true;
}

// Initialize and read the interfaces as needed.
void Interfacemanager::Initialize()
{
    // Read the configuration from cache.
    if (Readcache()) return;

    // Platform specific name.
    #if defined(_WIN32)
        std::string Libraryname = Steamdll;
    #else
        std::string Libraryname = Steamso;
    #endif

    // Else we create a new cache.
    std::string Backupname = Libraryname + ".bak";
    std::FILE *Filehandle = std::fopen(Backupname.c_str(), "rb");
    if (!Filehandle) Filehandle = std::fopen(Libraryname.c_str(), "rb");
    if (!Filehandle) Filehandle = std::fopen(("lib/" + Backupname).c_str(), "rb");
    if (!Filehandle) Filehandle = std::fopen(("lib/" + Libraryname).c_str(), "rb");
    if (!Filehandle)
    {
        Infoprint("No interface-information could be loaded, missing steam_api.");
        Infoprint("The Platformwrapper will use the latest version of interfaces as a hail Mary.");
        return;
    }
    Createcache(Filehandle);
    std::fclose(Filehandle);
}
void *Interfacemanager::Fetchinterface(const char *Name)
{
    // Internal lookup.
    auto Result = Interfacenames->find(Name);
    if (Result != Interfacenames->end()) return Result->second;

    // External lookup.
    for (auto &Item : Scandata)
        if (0 == std::strcmp(Item.second.first, Name))
            return Fetchinterface(Item.first);

    Debugprint(va("%s had no interface with the name \"%s\".", __FUNCTION__, Name));
    return nullptr;
}
void *Interfacemanager::Fetchinterface(eInterfaceType Type)
{
    // Return the interface by name if available.
    auto Result = Interfacemap.find(Type);
    if (Result != Interfacemap.end())
        return Result->second;

    // Search through the created interfaces to find the latest version as a fallback.
    for (auto Iterator = Interfacestore->rbegin(); Iterator != Interfacestore->rend(); Iterator++)
    {
        if (Iterator->first == Type)
            return Iterator->second;
    }

    Debugprint(va("%s had no interface for the type %i.", __FUNCTION__, Type));
    return nullptr;
}
void Interfacemanager::Addinterface(eInterfaceType Type, const char *Name, void *Interface)
{
    if(!Interfacestore) Interfacestore = new std::vector<std::pair<eInterfaceType, void *>>();
    if(!Interfacenames) Interfacenames = new std::unordered_map<std::string, void *>();

    Interfacestore->push_back({ Type, Interface });
    Interfacenames->emplace(Name, Interface);
}
