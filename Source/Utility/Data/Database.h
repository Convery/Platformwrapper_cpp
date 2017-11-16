/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-11-2017
    License: MIT
    Notes:
        Wraps SQLIte to provide simple interface for PackageFS.
        Should probably implement sqlite3_vfs
*/

#pragma once
#include "../../Stdinclude.h"

#if __has_include("sqlite3.h")
#include "sqlite3.h"
#endif

namespace Database
{
    // The datatypes this wrapper supports.
    enum class Databasetype
    {
        NONE = 0,
        INT = 1,
        FLOAT = 2,
        STRING = 3
    };

    // A dataentry in the table.
    struct Databasevalue
    {
        Databasetype Type;
        std::string Name;

        std::unique_ptr<std::string> Stringvalue;
        std::unique_ptr<uint64_t> Integervalue;
        std::unique_ptr<double> Floatvalue;

        Databasevalue() = default;
        Databasevalue(const Databasevalue &Ref)
        {
            Type = Ref.Type;
            Name = Ref.Name;

            Integervalue.swap(const_cast<Databasevalue &>(Ref).Integervalue);
            Stringvalue.swap(const_cast<Databasevalue &>(Ref).Stringvalue);
            Floatvalue.swap(const_cast<Databasevalue &>(Ref).Floatvalue);
        }
    };
    using Databaserow = std::vector<Databasevalue>;

    // Create a database value.
    template <typename T> Databasevalue Value(std::string Name, T Input);
    template <> inline Databasevalue Value(std::string Name, uint64_t Input)
    {
        Databasevalue Result;
        Result.Integervalue = std::make_unique<uint64_t>(Input);
        Result.Type = Databasetype::INT;
        Result.Name = Name;
        return Result;
    }
    template <> inline Databasevalue Value(std::string Name, std::string Input)
    {
        Databasevalue Result;
        Result.Stringvalue = std::make_unique<std::string>(Input);
        Result.Type = Databasetype::STRING;
        Result.Name = Name;
        return Result;
    }
    template <> inline Databasevalue Value(std::string Name, double Input)
    {
        Databasevalue Result;
        Result.Floatvalue = std::make_unique<double>(Input);
        Result.Type = Databasetype::FLOAT;
        Result.Name = Name;
        return Result;
    }

    // Serialization.
    inline std::string to_string(Databasevalue &Value)
    {
        auto Escapestring = [](Databasevalue &Value) -> std::string
        {
            auto Pointer = Value.Stringvalue->c_str();
            std::string Result;

            while(*Pointer)
            {
                if(*Pointer == '\x00' || *Pointer == '\x1a' ||
                   *Pointer == '\r' || *Pointer == '\\' ||
                   *Pointer == '\'' || *Pointer == '\"' ||
                   *Pointer == '\n') Result += '\\';

                Result += *Pointer;
                Pointer++;
            }

            return Result;
        };

        switch(Value.Type)
        {
            case Databasetype::INT: return va("%llu", *Value.Integervalue.get());
            case Databasetype::FLOAT: return va("%f", *Value.Floatvalue.get());
            case Databasetype::STRING: return va("\'%s\'", Escapestring(Value).c_str());
            case Databasetype::NONE:
            default: return "";
        }
    }

    #if !__has_include("sqlite3.h")
    inline void Save(std::string Filename) {};
    inline void Load(std::string Filename) {};
    inline void Execute(std::string Querystring) {};
    inline bool Set(std::string Tablename, Databaserow Row) { return false; }:
    inline std::vector<Databaserow> Get(std::string Tablename, std::string Condition) { return {}; };
    #else

    // Save and load the database from disk.
    inline void Save(std::string Filename)
    {
        static std::mutex Threadguard;

        Threadguard.lock();
        {
            // Connect to the database 1.
            sqlite3 *Ondiskdatabase;
            if (SQLITE_OK != sqlite3_open_v2("Tempfile.db", &Ondiskdatabase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
                return Infoprint("Could not connect to database.");

            // Connect to the database 2.
            sqlite3 *Memorydatabase;
            if (SQLITE_OK != sqlite3_open_v2("file:" MODULENAME "?mode=memory&cache=shared", &Memorydatabase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
                return Infoprint("Could not connect to database.");

            // Start backing up the database.
            auto Backup = sqlite3_backup_init(Ondiskdatabase, "main", Memorydatabase, "main");
            if (Backup)
            {
                sqlite3_backup_step(Backup, -1);
                sqlite3_backup_finish(Backup);
            }

            // Close the databases.
            sqlite3_close(Ondiskdatabase);
            sqlite3_close(Memorydatabase);

            // Read the DB from disk and delete it.
            auto Filebuffer = Readfile("Tempfile.db");
            std::remove("Tempfile.db");

            // Store in the package.
            Package::Write(Filename, Filebuffer);
        }
        Threadguard.unlock();
    }
    inline void Load(std::string Filename)
    {
        static std::mutex Threadguard;

        Threadguard.lock();
        {
            // Write the file to disk because sqlite.
            Writefile("Tempfile.db", Package::Read(Filename));

            // Connect to the database 1.
            sqlite3 *Ondiskdatabase;
            if (SQLITE_OK != sqlite3_open_v2("Tempfile.db", &Ondiskdatabase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
                return Infoprint("Could not connect to database.");

            // Connect to the database 2.
            sqlite3 *Memorydatabase;
            if (SQLITE_OK != sqlite3_open_v2("file:" MODULENAME "?mode=memory&cache=shared", &Memorydatabase, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
                return Infoprint("Could not connect to database.");

            // Start backing up the database.
            auto Backup = sqlite3_backup_init(Memorydatabase, "main", Ondiskdatabase, "main");
            if (Backup)
            {
                sqlite3_backup_step(Backup, -1);
                sqlite3_backup_finish(Backup);
            }

            // Close the on-disk database, leave the memory.
            sqlite3_close(Ondiskdatabase);
            //sqlite3_close(Memorydatabase);

            // Delete the file from disk.
            std::remove("Tempfile.db");
        }
        Threadguard.unlock();
    }

    // Database IO.
    inline std::vector<Databaserow> Get(std::string Tablename, std::string Condition)
    {
        std::vector<Databaserow> Result;

        // Connect to the database.
        sqlite3 *Databasehandle;
        if( SQLITE_OK != sqlite3_open_v2("file:" MODULENAME "?mode=memory&cache=shared", &Databasehandle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
        {
            Infoprint("Could not connect to database.");
            return Result;
        }

        // Query callback.
        auto Lambda = [](void *Input, int Resultcount, char **Resultvalues, char **Resultnames) -> int
        {
            Databaserow Row;

            // Dumb parsing.
            for (int i = 0; i < Resultcount; ++i)
            {
                Databasevalue Value;
                Value.Name = Resultnames[i];

                // Check if it's a float.
                double Floatvalue = std::strtod(Resultvalues[i], nullptr);
                if (Floatvalue == 0.0f || Floatvalue == HUGE_VALF)
                {
                    Value.Floatvalue = std::make_unique<double>(Floatvalue);
                    Value.Type = Databasetype::FLOAT;
                    Row.push_back(std::move(Value));
                    continue;
                }

                // Check if it's an integer.
                uint64_t Integervalue = std::strtoull(Resultvalues[i], nullptr, 16);
                if (Integervalue > 0 && Integervalue < ULLONG_MAX)
                {
                    Value.Integervalue = std::make_unique<uint64_t>(Integervalue);
                    Value.Type = Databasetype::INT;
                    Row.push_back(std::move(Value));
                    continue;
                }

                // Check if it's a string.
                std::string Stringvalue = Resultvalues[i];
                if (Stringvalue.size() > 0)
                {
                    Value.Stringvalue = std::make_unique<std::string>(Stringvalue);
                    Value.Type = Databasetype::STRING;
                    Row.push_back(std::move(Value));
                    continue;
                }

                // Cry.
                Value.Type = Databasetype::NONE;
                Row.push_back(std::move(Value));
            }

            auto Array = reinterpret_cast<std::vector<Databaserow> *>(Input);
            Array->push_back(std::move(Row));
            return 0;
        };

        if(SQLITE_OK == sqlite3_exec(Databasehandle, va("SELECT * FROM %s WHERE %s;", Tablename.c_str(), Condition.c_str()).c_str(), Lambda, &Result, NULL))
        {
            sqlite3_close(Databasehandle);
            return Result;
        }

        sqlite3_close(Databasehandle);
        return Result;
    }
    inline bool Set(std::string Tablename, Databaserow Row)
    {
        // Connect to the database.
        sqlite3 *Databasehandle;
        if( SQLITE_OK != sqlite3_open_v2("file:" MODULENAME "?mode=memory&cache=shared", &Databasehandle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
        {
            Infoprint("Could not connect to database.");
            return false;
        }

        // Create a query from the input.
        std::string Querystring = va("INSERT INTO %s ( ", Tablename.c_str());
        for(auto &Item : Row) Querystring += va("%s,", Item.Name.c_str());
        Querystring.pop_back(); Querystring += " ) VALUES ( ";
        for(auto &Item : Row) Querystring += to_string(Item);
        Querystring += " );";

        // Run the query and return.
        if(SQLITE_OK == sqlite3_exec(Databasehandle, Querystring.c_str(), NULL, NULL, NULL))
        {
            sqlite3_close(Databasehandle);
            return true;
        }

        sqlite3_close(Databasehandle);
        return false;
    }
    inline void Execute(std::string Querystring)
    {
        // Connect to the database.
        sqlite3 *Databasehandle;
        if( SQLITE_OK != sqlite3_open_v2("file:" MODULENAME "?mode=memory&cache=shared", &Databasehandle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
            return Infoprint("Could not connect to database.");

        sqlite3_exec(Databasehandle, Querystring.c_str(), NULL, NULL, NULL);
        sqlite3_close(Databasehandle);
    }
    #endif
}
