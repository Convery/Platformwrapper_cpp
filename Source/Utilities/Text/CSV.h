/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#pragma once

// Annoying warnings on windows.
#if defined(_WIN32) && !defined(_CRT_SECURE_NO_WARNINGS)
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <vector>

class CSV
{
    std::vector<std::vector<std::string>> EntryBuffer;

public:
    bool Readfile(const char *Filepath);
    bool Writefile(const char *Filepath);
    std::string Getvalue(size_t Row, size_t Col);
    void Addrow(std::vector<std::string> Values);
};
