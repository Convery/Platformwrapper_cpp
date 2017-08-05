/*
    Initial author: Convery (tcn@ayria.se)
    Started: 05-08-2017
    License: MIT
    Notes:
        Wraps SQLIte to provide simple interface.
*/

#include "../../Stdinclude.h"

namespace Database
{
    // The datatypes the wrapper supports.
    enum eDatatype : uint8_t
    {
        NONE = 0,
        INT = 1,
        FLOAT = 2,
        STRING = 3
    };

    // Input/output for the database.
    using Value_t = std::pair<eDatatype, void *>;
    using Column_t = std::pair<std::string, Value_t>;

    // Serialization.
    inline std::string to_string(Value_t &Input)
    {
        auto Escapestring = [](Value_t &Input) -> std::string
        {
            auto Pointer = *(const char **)Input.second;
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

        switch(Input.first)
        {
            case eDatatype::INT: return va("%llu", *(uint64_t *)Input.second);
            case eDatatype::FLOAT: return va("%f", *(float *)Input.second);
            case eDatatype::STRING: return va("\'%s\'", Escapestring(Input).c_str());
            case eDatatype::NONE:
            default: return "";
        }
    }

    // Database IO.
    inline bool Get(std::string Tablename, std::vector<Column_t> Columns)
    {
        // Connect to the database.
        sqlite3 *Databasehandle;
        if( SQLITE_OK != sqlite3_open_v2("./Plugins/" MODULENAME "/" DATABASENAME, &Databasehandle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
        {
            Infoprint("Could not connect to database.");
            return false;
        }

        // Query callback.
        auto Lambda = [](void *Input, int Resultcount, char **Resultvalues, char **Resultnames) -> int
        {
            auto Array = reinterpret_cast<std::vector<Column_t> *>(Input);

            for (int i = 0; i < Resultcount; ++i)
            {
                for(auto &Item : *Array)
                {
                    if(0 == std::strcmp(Resultnames[i], Item.first.c_str()))
                    {
                        switch(Item.second.first)
                        {
                            case eDatatype::INT: *(uint64_t *)Item.second.second = std::strtoull(Resultvalues[i], NULL, 10); break;
                            case eDatatype::FLOAT: *(float *)Item.second.second = std::strtof(Resultvalues[i], NULL); break;
                            case eDatatype::STRING: std::strcpy(*(char **)Item.second.second, Resultvalues[i]); break;
                            case eDatatype::NONE:
                            default: break;
                        }

                        break;
                    }
                }
            }

            return 0;
        };

        if(SQLITE_OK == sqlite3_exec(Databasehandle, va("SELECT * FROM %s;", Tablename.c_str()).c_str(), Lambda, &Columns, NULL))
        {
            sqlite3_close(Databasehandle);
            return true;
        }

        sqlite3_close(Databasehandle);
        return false;
    }
    inline bool Set(std::string Tablename, std::vector<Column_t> Columns)
    {
        // Connect to the database.
        sqlite3 *Databasehandle;
        if( SQLITE_OK != sqlite3_open_v2("./Plugins/" MODULENAME "/" DATABASENAME, &Databasehandle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
        {
            Infoprint("Could not connect to database.");
            return false;
        }

        // A string that we can use to parse the input.
        std::string Querystring = va("INSERT INTO %s ( ", Tablename.c_str());
        for(auto &Item : Columns) Querystring += va("%s,", Item.first.c_str());
        Querystring.pop_back();
        Querystring += " ) VALUES ( ";
        for(auto &Item : Columns) Querystring += to_string(Item.second);
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
        if( SQLITE_OK != sqlite3_open_v2("./Plugins/" MODULENAME "/" DATABASENAME, &Databasehandle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL))
            return Infoprint("Could not connect to database.");

        sqlite3_exec(Databasehandle, Querystring.c_str(), NULL, NULL, NULL);
        sqlite3_close(Databasehandle);
    }
}
