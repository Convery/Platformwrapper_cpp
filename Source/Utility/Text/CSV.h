/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Basic CSV IO.
*/

#pragma once
#include "../../Stdinclude.h"

struct CSV
{
    std::vector<std::vector<std::string>> Entrybuffer;

    bool Readfile(const char *Filepath);
    bool Writefile(const char *Filepath);
    std::string Getvalue(size_t Row, size_t Col);
    void Addrow(std::vector<std::string> Values);
};
