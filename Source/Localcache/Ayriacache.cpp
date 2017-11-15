/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-11-2017
    License: MIT
    Notes:
        Account-data provided by Ayria.
*/

#pragma once
#include "../Stdinclude.h"

namespace Ayriacache
{
    Account Accountinformation;
    std::vector<Friend> Friendslist;

    // Create the database on startup.
    void Ayriacachecreation()
    {
        Database::Execute("CREATE TABLE IF NOT EXISTS Ayria_account (Accountname TEXT, AvatarPNG TEXT, Locale TEXT, UserID INTEGER);");
        Database::Execute("CREATE TABLE IF NOT EXISTS Ayria_friends (Accountname TEXT, AvatarPNG TEXT, Game TEXT, UserID INTEGER, Status INTEGER);");
    }

    // Fetch the account information.
    void Fetchaccountcache()
    {
        auto Rows = Database::Get("Ayria_account", "1=1");

        // Use default information.
        if (Rows.size() == 0)
        {
            Accountinformation.Accountname = "Ayria";
            Accountinformation.AvatarPNG = "";
            Accountinformation.Locale = "en-us";
            Accountinformation.UserID = 0xDEADC0DE;
        }
        else
        {
            for (auto &Item : Rows[0])
            {
                if (0 == std::strcmp(Item.Name.c_str(), "Accountname"))
                {
                    Accountinformation.Accountname = *Item.Stringvalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "AvatarPNG"))
                {
                    Accountinformation.AvatarPNG = Base64::Decode(*Item.Stringvalue.get());
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "Locale"))
                {
                    Accountinformation.Locale = *Item.Stringvalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "UserID"))
                {
                    Accountinformation.UserID = *Item.Integervalue.get();
                    continue;
                }
            }
        }
    }

    // Fetch the friendslist.
    void Fetchfriendscache()
    {
        auto Rows = Database::Get("Ayria_friends", "1=1");
        std::vector<Friend> Locallist;

        for (auto &Row : Rows)
        {
            Friend Localfriend;

            for (auto &Item : Row)
            {
                if (0 == std::strcmp(Item.Name.c_str(), "Accountname"))
                {
                    Localfriend.Accountname = *Item.Stringvalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "AvatarPNG"))
                {
                    Localfriend.AvatarPNG = Base64::Decode(*Item.Stringvalue.get());
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "Game"))
                {
                    Localfriend.Game = *Item.Stringvalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "UserID"))
                {
                    Localfriend.UserID = *Item.Integervalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "Status"))
                {
                    Localfriend.Status = *Item.Integervalue.get();
                    continue;
                }
            }

            Locallist.push_back(Localfriend);
        }

        Friendslist = Locallist;
    }

    namespace
    {
        struct Ayriastartup
        {
            Ayriastartup()
            {
                Localcache::Addtask(Ayriacachecreation, 0xFFFFFF);
                Localcache::Addtask(Fetchaccountcache, 60000);
                Localcache::Addtask(Fetchfriendscache, 5000);
            }
        };
        static Ayriastartup Startup{};
    }
}
