/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 09-01-2018
    License: MIT
    Notes:
        Generic datastructures for the platforms.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace Platform
{
    enum class Subplatform : uint32_t
    {
        NONE = 0,
        AYRIA = 1,
        STEAM = 2,
        MAX
    };
    enum class Playerstatus : uint32_t
    {
        NONE = 0,
        ONLINE = 1,
        OFFLINE = 2,
        FAKEOFFLINE = 3,
        MAX
    };

    struct Application
    {
        uint32_t UniqueID;
        Subplatform Provider;
        std::string Friendlyname;
        std::string Installationpath;
    };
    using DLCinformation = Application;
    using Gameinformation = Application;

    struct Account
    {
        uint64_t AccountID;
        Playerstatus Status;
        std::string AvatarURL;
        std::string Currentgame;
        std::string Accountname;
        std::string Accountlocale;
    };
    using Userinformation = Account;
    using Friendinformation = Account;

    struct Leaderboard
    {
        struct Entry
        {
            int64_t Score;
            uint64_t Rank;
            uint64_t UserID;
            uint64_t Modifiedtime;
        };

        Subplatform Provider;
        uint32_t ApplicationID;
        uint64_t LeaderboardID;
        std::vector<Entry> Entries;
    };
    using Playerstats = Leaderboard;

    struct Lobby
    {
        bool Public;
        bool Locked;
        bool Silent;
        bool Reserved;
        uint32_t Slots;
        uint64_t OwnerID;
        uint64_t UniqueID;
        uint32_t Reserved2;
        Subplatform Provider;
        std::string Password;
        std::string Friendlyname;
        std::vector<uint64_t> Members;
        std::vector<std::pair<std::string, std::string>> Keyvalues;
    };
    using Chatroom = Lobby;
    using Matchmakinglobby = Lobby;
}
