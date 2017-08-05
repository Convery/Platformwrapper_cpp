/*
    Initial author: Convery (tcn@ayria.se)
    Started: 05-08-2017
    License: MIT
    Notes:
        Basic CSV IO.
*/

#pragma once
#include "../../Stdinclude.h"

namespace CSV
{
    using Column_t = std::string;
    using Row_t = std::vector<Column_t>;
    using Collection_t = std::vector<Row_t>;

    // Helpers for cleaner code.
    inline void Addrow(Row_t Row, Collection_t &Data)
    {
        Data.push_back(Row);
    }
    inline Column_t Getvalue(size_t Row, size_t Column, Collection_t &Data)
    {
        if(0 == Data.size()) return "";
        if(Row > Data.size() - 1) return "";
        if(Column > Data[Row].size() - 1) return "";
        return Data[Row][Column];
    }

    // Reimplementation of standard functionality.
    #if defined (_WIN32)
    char *strsep(char **String, const char *Delimiter)
    {
        char *Start = *String;
        char *Part;

        Part = (Start != NULL) ? strpbrk(Start, Delimiter) : NULL;

        if (Part == NULL)
            *String = NULL;
        else
        {
            *Part = '\0';
            *String = Part + 1;
        }

        return Start;
    }
    #endif

    // Input and output.
    inline Collection_t Readfile(const char *Filepath)
    {
        Collection_t Result;

        // Open the input file.
        std::FILE *Filehandle = std::fopen(Filepath, "r");
        if (!Filehandle) return Result;

        // Grab each line from the file.
        auto Linebuffer = std::make_unique<char[]>(1024);
        while(std::fgets(Linebuffer.get(), 1024, Filehandle))
        {
            // Check if the line is 'empty'.
            if(std::strlen(Linebuffer.get()) < 3) continue;

            // Check if the line is a comment.
            if(*Linebuffer.get() == '#') continue;

            // Build the row from the linedata.
            auto Line = &*Linebuffer.get();
            Row_t Localrow;
            while (true)
            {
                // Get a token.
                auto Token = strsep(&Line, ",\n\0");
                if(!Token || *Token == '\0') break;

                // Skip whitespace.
                while(*Token == ' ') Token++;

                // Add the value to the row.
                Localrow.push_back(Token);
            }

            // Add the row to the collection.
            Addrow(Localrow, Result);
        }

        std::fclose(Filehandle);
        return Result;
    }
    inline bool Writefile(const char *Filepath, Collection_t &Data)
    {
        // Check if we have anything to write.
        if(0 == Data.size()) return false;

        // Open the output file.
        std::FILE *Filehandle = std::fopen(Filepath, "w");
        if(!Filehandle) return false;

        // Write a cute little warning header.
        std::fputs("# This file is generated through Ayrias utility.\n", Filehandle);
        std::fputs("# Please do not edit it manually.\n\n", Filehandle);

        // Write each row to the file.
        for(auto &Row : Data)
        {
            std::string Formated;

            // Format the values.
            for(auto &Col : Row)
            {
                Formated += Col;
                Formated += ", ";
            }

            // Remove the last ", " and add a newline.
            Formated.pop_back();
            Formated.pop_back();
            Formated += "\n";

            // Write the row.
            std::fputs(Formated.c_str(), Filehandle);
        }

        std::fclose(Filehandle);
        return true;
    }
}
