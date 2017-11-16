/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-11-2017
    License: MIT
    Notes:
        Steam data per appID.
*/

#include "../Stdinclude.h"

namespace Steamcache
{
    std::vector<Game> Ownedgames;
    std::vector<DLC> DLCEntries;

    // Create the database on startup.
    void Steamcachecreation()
    {
        Database::Execute("CREATE TABLE IF NOT EXISTS Steam_games (AppID INTEGER UNIQUE, DLCCount INTEGER, Friendlyname TEXT, Installpath TEXT);");
        Database::Execute("CREATE TABLE IF NOT EXISTS Steam_DLC (DLCID INTEGER UNIQUE, Installpath TEXT);");
    }

    // Fetch the owned games.
    void Fetchgamecache()
    {
        auto Rows = Database::Get("Steam_games", "1=1");
        std::vector<Game> Localgames;

        for (auto &Row : Rows)
        {
            Game Localgame;

            for (auto &Item : Row)
            {
                if (0 == std::strcmp(Item.Name.c_str(), "AppID"))
                {
                    Localgame.AppID = uint32_t(*Item.Integervalue.get());
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "DLCCount"))
                {
                    Localgame.DLCCount = uint32_t(*Item.Integervalue.get());
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "Friendlyname"))
                {
                    Localgame.Friendlyname = *Item.Stringvalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "Installpath"))
                {
                    Localgame.Installpath = *Item.Stringvalue.get();
                    continue;
                }
            }

            Localgames.push_back(Localgame);
        }

        Ownedgames = Localgames;
    }

    // Fetch the DLC info.
    void FetchDLCcache()
    {
        // Load any DLC from disk and insert it into the DB.
        try
        {
            auto JSONBuffer = Package::Read("Steamgames.json");
            auto Parsed = nlohmann::json::parse(JSONBuffer.c_str());

            for (auto &Item : Parsed["Steamgames"])
            {
                Database::Set("Steam_DLC",
                {
                    Database::Value<uint64_t>("DLCID", Item["DLCID"]),
                    Database::Value<std::string>("Installationpath", Item["Installationpath"])
                });
            }

            Package::Delete("Steamgames.json");
        }
        catch (...) {};

        auto Rows = Database::Get("Steam_DLC", "1=1");
        std::vector<DLC> LocalDLCs;

        for (auto &Row : Rows)
        {
            DLC LocalDLC;

            for (auto &Item : Row)
            {
                if (0 == std::strcmp(Item.Name.c_str(), "DLCID"))
                {
                    LocalDLC.DLCID = uint32_t(*Item.Integervalue.get());
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "Installpath"))
                {
                    LocalDLC.Installpath = *Item.Stringvalue.get();
                    continue;
                }
            }

            LocalDLCs.push_back(LocalDLC);
        }

        DLCEntries = LocalDLCs;
    }

    namespace
    {
        struct Steamstartup
        {
            Steamstartup()
            {
                Localcache::Addtask(Steamcachecreation, 0xFFFFFF);
                Localcache::Addtask(Fetchgamecache, 0xFFFFFF);
                Localcache::Addtask(FetchDLCcache, 0xFFFFFF);
            }
        };
        static Steamstartup Startup{};
    }
}
