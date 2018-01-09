/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Defines the base class and which interfaces
        have been implemented so far.
*/

#pragma once
#include "../../Stdinclude.hpp"

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

// Create the fake class from real methods.
#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;
#define Createinterface(Enum, Class)            \
static Class DEV ## Class;                      \
Interfacemanager::Addinterface(Enum, #Class, &DEV ## Class);

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

// Steam application information.
struct SteamApps001 : public Fakeclass
{
    SteamApps001();
};
struct SteamApps002 : public Fakeclass
{
    SteamApps002();
};
struct SteamApps003 : public Fakeclass
{
    SteamApps003();
};
struct SteamApps004 : public Fakeclass
{
    SteamApps004();
};
struct SteamApps005 : public Fakeclass
{
    SteamApps005();
};
struct SteamApps006 : public Fakeclass
{
    SteamApps006();
};
struct SteamApps007 : public Fakeclass
{
    SteamApps007();
};

// Steam friendslist information.
struct SteamFriends001 : public Fakeclass
{
    SteamFriends001();
};
struct SteamFriends002 : public Fakeclass
{
    SteamFriends002();
};
struct SteamFriends003 : public Fakeclass
{
    SteamFriends003();
};
struct SteamFriends004 : public Fakeclass
{
    SteamFriends004();
};
struct SteamFriends005 : public Fakeclass
{
    SteamFriends005();
};
struct SteamFriends006 : public Fakeclass
{
    SteamFriends006();
};
struct SteamFriends007 : public Fakeclass
{
    SteamFriends007();
};
struct SteamFriends008 : public Fakeclass
{
    SteamFriends008();
};
struct SteamFriends009 : public Fakeclass
{
    SteamFriends009();
};
struct SteamFriends010 : public Fakeclass
{
    SteamFriends010();
};
struct SteamFriends011 : public Fakeclass
{
    SteamFriends011();
};
struct SteamFriends012 : public Fakeclass
{
    SteamFriends012();
};
struct SteamFriends013 : public Fakeclass
{
    SteamFriends013();
};
struct SteamFriends014 : public Fakeclass
{
    SteamFriends014();
};
struct SteamFriends015 : public Fakeclass
{
    SteamFriends015();
};

// Steam p2p networking.
struct SteamNetworking001 : public Fakeclass
{
    SteamNetworking001();
};
struct SteamNetworking002 : public Fakeclass
{
    SteamNetworking002();
};
struct SteamNetworking003 : public Fakeclass
{
    SteamNetworking003();
};
struct SteamNetworking004 : public Fakeclass
{
    SteamNetworking004();
};
struct SteamNetworking005 : public Fakeclass
{
    SteamNetworking005();
};

// Steam user information.
struct SteamUser001 : public Fakeclass
{
    SteamUser001();
};
struct SteamUser002 : public Fakeclass
{
    SteamUser002();
};
struct SteamUser003 : public Fakeclass
{
    SteamUser003();
};
struct SteamUser004 : public Fakeclass
{
    SteamUser004();
};
struct SteamUser005 : public Fakeclass
{
    SteamUser005();
};
struct SteamUser006 : public Fakeclass
{
    SteamUser006();
};
struct SteamUser007 : public Fakeclass
{
    SteamUser007();
};
struct SteamUser008 : public Fakeclass
{
    SteamUser008();
};
struct SteamUser009 : public Fakeclass
{
    SteamUser009();
};
struct SteamUser010 : public Fakeclass
{
    SteamUser010();
};
struct SteamUser011 : public Fakeclass
{
    SteamUser011();
};
struct SteamUser012 : public Fakeclass
{
    SteamUser012();
};
struct SteamUser013 : public Fakeclass
{
    SteamUser013();
};
struct SteamUser014 : public Fakeclass
{
    SteamUser014();
};
struct SteamUser015 : public Fakeclass
{
    SteamUser015();
};
struct SteamUser016 : public Fakeclass
{
    SteamUser016();
};
struct SteamUser017 : public Fakeclass
{
    SteamUser017();
};
struct SteamUser018 : public Fakeclass
{
    SteamUser018();
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

// Serverhosting.
struct SteamGameserver001 : public Fakeclass
{
    SteamGameserver001();
};
struct SteamGameserver002 : public Fakeclass
{
    SteamGameserver002();
};
struct SteamGameserver003 : public Fakeclass
{
    SteamGameserver003();
};
struct SteamGameserver004 : public Fakeclass
{
    SteamGameserver004();
};
struct SteamGameserver005 : public Fakeclass
{
    SteamGameserver005();
};
struct SteamGameserver006 : public Fakeclass
{
    SteamGameserver006();
};
struct SteamGameserver007 : public Fakeclass
{
    SteamGameserver007();
};
struct SteamGameserver008 : public Fakeclass
{
    SteamGameserver008();
};
struct SteamGameserver009 : public Fakeclass
{
    SteamGameserver009();
};
struct SteamGameserver010 : public Fakeclass
{
    SteamGameserver010();
};
struct SteamGameserver011 : public Fakeclass
{
    SteamGameserver011();
};
struct SteamGameserver012 : public Fakeclass
{
    SteamGameserver012();
};

// P2P matchmaking.
struct SteamMatchmaking001 : public Fakeclass
{
    SteamMatchmaking001();
};
struct SteamMatchmaking002 : public Fakeclass
{
    SteamMatchmaking002();
};
struct SteamMatchmaking003 : public Fakeclass
{
    SteamMatchmaking003();
};
struct SteamMatchmaking004 : public Fakeclass
{
    SteamMatchmaking004();
};
struct SteamMatchmaking005 : public Fakeclass
{
    SteamMatchmaking005();
};
struct SteamMatchmaking006 : public Fakeclass
{
    SteamMatchmaking006();
};
struct SteamMatchmaking007 : public Fakeclass
{
    SteamMatchmaking007();
};
struct SteamMatchmaking008 : public Fakeclass
{
    SteamMatchmaking008();
};
struct SteamMatchmaking009 : public Fakeclass
{
    SteamMatchmaking009();
};

// Cloudstorage.
struct SteamRemotestorage001 : public Fakeclass
{
    SteamRemotestorage001();
};
struct SteamRemotestorage002 : public Fakeclass
{
    SteamRemotestorage002();
};
struct SteamRemotestorage003 : public Fakeclass
{
    SteamRemotestorage003();
};
struct SteamRemotestorage004 : public Fakeclass
{
    SteamRemotestorage004();
};
struct SteamRemotestorage005 : public Fakeclass
{
    SteamRemotestorage005();
};
struct SteamRemotestorage006 : public Fakeclass
{
    SteamRemotestorage006();
};
struct SteamRemotestorage007 : public Fakeclass
{
    SteamRemotestorage007();
};
struct SteamRemotestorage008 : public Fakeclass
{
    SteamRemotestorage008();
};
struct SteamRemotestorage009 : public Fakeclass
{
    SteamRemotestorage009();
};
struct SteamRemotestorage010 : public Fakeclass
{
    SteamRemotestorage010();
};
struct SteamRemotestorage011 : public Fakeclass
{
    SteamRemotestorage011();
};
struct SteamRemotestorage012 : public Fakeclass
{
    SteamRemotestorage012();
};

// Screenshots.
struct SteamScreenshots001 : public Fakeclass
{
    SteamScreenshots001();
};
struct SteamScreenshots002 : public Fakeclass
{
    SteamScreenshots002();
};

// Server browser.
struct SteamMasterserverUpdater001 : public Fakeclass
{
    SteamMasterserverUpdater001();
};
