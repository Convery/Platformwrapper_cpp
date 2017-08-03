/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Defines the base class and which interfaces
        have been implemented so far.
*/

#pragma once
#include "../../Stdinclude.h"

// A structure to mimic an actual class.
struct Fakeclass
{
    void *Vtable;
    void *Methods[70];

    Fakeclass()
    {
        Vtable = &Methods;
    }
};

// User statistics.
struct SteamUserstats001 : public Fakeclass
{
    SteamUserstats001();
};
struct SteamUserstats002 : public Fakeclass
{
    SteamUserstats002();
};
struct SteamUserstats003 : public Fakeclass
{
    SteamUserstats003();
};
struct SteamUserstats004 : public Fakeclass
{
    SteamUserstats004();
};
struct SteamUserstats005 : public Fakeclass
{
    SteamUserstats005();
};
struct SteamUserstats006 : public Fakeclass
{
    SteamUserstats006();
};
struct SteamUserstats007 : public Fakeclass
{
    SteamUserstats007();
};
struct SteamUserstats008 : public Fakeclass
{
    SteamUserstats008();
};
struct SteamUserstats009 : public Fakeclass
{
    SteamUserstats009();
};
struct SteamUserstats010 : public Fakeclass
{
    SteamUserstats010();
};
struct SteamUserstats011 : public Fakeclass
{
    SteamUserstats011();
};

// Steam utility interfaces.
struct SteamUtilities001 : public Fakeclass
{
    SteamUtilities001();
};
struct SteamUtilities002 : public Fakeclass
{
    SteamUtilities002();
};
struct SteamUtilities003 : public Fakeclass
{
    SteamUtilities003();
};
struct SteamUtilities004 : public Fakeclass
{
    SteamUtilities004();
};
struct SteamUtilities005 : public Fakeclass
{
    SteamUtilities005();
};
struct SteamUtilities006 : public Fakeclass
{
    SteamUtilities006();
};
struct SteamUtilities007 : public Fakeclass
{
    SteamUtilities007();
};
