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
    std::string Accountname;
    std::string AvatarPNG;
    std::string Locale;
    uint64_t UserID;

    // Create the database on startup.
    void Ayriacachecreation()
    {
        Database::Execute("CREATE TABLE IF NOT EXISTS Ayriaaccount (Accountname TEXT, AvatarPNG TEXT, Locale TEXT, UserID INTEGER);");
    }

    // Fetch the account information.
    void Fetchaccountcache()
    {
        auto Rows = Database::Get("Ayriaaccount", "TRUE");

        // Use default information.
        if (Rows.size() == 0)
        {
            Accountname = "Ayria";
            AvatarPNG = "";
            Locale = "en-us";
            UserID = 0xDEADC0DE;
        }
        else
        {
            for (auto &Item : Rows[0])
            {
                if (0 == std::strcmp(Item.Name.c_str(), "Accountname"))
                {
                    Accountname = *Item.Stringvalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "AvatarPNG"))
                {
                    AvatarPNG = Base64::Decode(*Item.Stringvalue.get());
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "Locale"))
                {
                    Locale = *Item.Stringvalue.get();
                    continue;
                }

                if (0 == std::strcmp(Item.Name.c_str(), "UserID"))
                {
                    UserID = *Item.Integervalue.get();
                    continue;
                }
            }
        }
    }

    namespace
    {
        struct Ayriastartup
        {
            Ayriastartup()
            {
                Localcache::Addtask(Ayriacachecreation, 0xFFFFFF);
                Localcache::Addtask(Fetchaccountcache, 5000);
            }
        };
        static Ayriastartup Startup();
    }
}
