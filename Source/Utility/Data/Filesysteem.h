/*
    Initial author: Convery (tcn@ayria.se)
    Started: 07-08-2017
    License: MIT
    Notes:
        [Insert some line about how this is a utility for
        new developers to get up and running quickly; not
        just me being too lazy to use stdio             ]
*/

#pragma once

#include "../../Stdinclude.h"

inline std::string Readfile(std::string Path)
{
    std::FILE *Filehandle = std::fopen(Path.c_str(), "rb");
    if (!Filehandle) return "";

    std::fseek(Filehandle, 0, SEEK_END);
    auto Length = std::ftell(Filehandle);
    std::fseek(Filehandle, 0, SEEK_SET);

    auto Buffer = std::make_unique<char[]>(Length);
    std::fread(Buffer.get(), Length, 1, Filehandle);
    std::fclose(Filehandle);

    return std::string(Buffer.get(), Length);
}
inline void Writefile(std::string Path, std::string Buffer)
{
    std::FILE *Filehandle = std::fopen(Path.c_str(), "wb");
    if (!Filehandle) return;

    std::fwrite(Buffer.data(), Buffer.size(), 1, Filehandle);
    std::fclose(Filehandle);
}
inline bool Fileexists(std::string Path)
{
    std::FILE *Filehandle = std::fopen(Path.c_str(), "rb");
    if (!Filehandle) return false;
    std::fclose(Filehandle);
    return true;
}
