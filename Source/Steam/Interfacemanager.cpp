/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#include "Steam.h"
#include <unordered_map>
#include "Interfaces/All.h"
#include "Interfacemanager.h"

constexpr const char *Steamdllname = sizeof(size_t) == sizeof(uint64_t) ? "steam_api64.dll" : "steam_api.dll";

// Interface names to scan for and their type.
std::unordered_map<eInterfaceType, std::string> Scannames =
{
    {eInterfaceType::STEAM_APPLIST, "test"}
};

// The interfaces we support.
std::vector<std::pair<eInterfaceType /* Type */, void * /* Interface */>> Interfacestore;
std::unordered_map<eInterfaceType /* Type */, void * /* Interface */> Interfacemap;
std::unordered_map<std::string /* Name */, void * /* Interface */> Interfacenames;

void Setmapbyname(eInterfaceType Type, const char *Name)
{
    Interfacemap[Type] = Interfacemanager::Fetchinterface(Name);
}
void Interfacemanager::Initialize()
{
    // Check for a cache file.
    {
        const char *Cachename = "./Plugins/Platformwrapper/Steam_Interfacecache";
        std::FILE *Filehandle = std::fopen(Cachename, "rt");
        if (Filehandle)
        {
            char InputString[1024]{};
            while (fgets(InputString, 1024, Filehandle))
            {
                #define Checktype(Interfacename, Type)          \
                if(std::strstr(InputString, Interfacename))     \
                { Setmapbyname(Type, InputString); continue; }  \

                // Add by type.
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
                Checktype("SteamUnifiedmessages0", STEAM_UNIFIEDMESSAGES);
                Checktype("SteamGameserverStats0", STEAM_GAMESERVERSTATS);
                Checktype("SteamMatchamkingservers0", STEAM_MATCHMAKINGSERVERS);
                Checktype("SteamMasterserverUpdater0", STEAM_MASTERSERVERUPDATER);
            }

            fclose(Filehandle);
            return;
        }
    }

    // Check for a backup file, in the case of devs compiling as a steam_api replacement.
    {
        std::string Backupname = std::string(Steamdllname) + ".bak";
        std::FILE *Filehandle = std::fopen(Backupname.c_str(), "rb");
        if(!Filehandle) Filehandle = std::fopen(Steamdllname, "rb");
        if (!Filehandle)
        {
            InfoPrint("No interfaces could be loaded, contact the developers.");
            InfoPrint("The Platformwrapper will use the latest version of interfaces as a hail Mary.");
            return;
        }

        /*
            TODO(Convery):
            Something something scan the dll for interfaces.
        */
    }
}
void *Interfacemanager::Fetchinterface(const char *Name)
{
    auto Result = Interfacenames.find(Name);
    if (Result != Interfacenames.end()) return Result->second;

    DebugPrint(va("%s had no interface with the name \"%s\"", __FUNCTION__, Name).c_str());
    return nullptr;
}
void *Interfacemanager::Fetchinterface(eInterfaceType Type)
{
    // Return the interface by name if available.
    auto Result = Interfacemap.find(Type);
    if (Result != Interfacemap.end()) return Result->second;

    // Search through the created interfaces to find the latest version as a fallback.
    for (auto Iterator = Interfacestore.rbegin(); Iterator != Interfacestore.rend(); Iterator++)
    {
        if (Iterator->first == Type)
            return Iterator->second;
    }

    DebugPrint(va("%s had no interface for the type %i", __FUNCTION__, Type).c_str());
    return nullptr;
}
void Interfacemanager::Addinterface(eInterfaceType Type, const char *Name, void *Interface)
{
    Interfacestore.push_back({ Type, Interface });
    Interfacenames[Name] = Interface;
}
