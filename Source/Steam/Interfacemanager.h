/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#pragma once
#include <cstdint>

// Types.
enum eInterfaceType
{
    STEAM_UGC,
    STEAM_APPS,
    STEAM_USER,
    STEAM_HTTP,
    STEAM_MUSIC,
    STEAM_UTILS,
    STEAM_VIDEO,
    STEAM_CLIENT,
    STEAM_FRIENDS,
    STEAM_APPLIST,
    STEAM_INVENTORY,
    STEAM_USERSTATS,
    STEAM_CONTROLLER,
    STEAM_GAMESERVER,
    STEAM_NETWORKING,
    STEAM_HTMLSURFACE,
    STEAM_MUSICREMOTE,
    STEAM_SCREENSHOTS,
    STEAM_MATCHMAKING,
    STEAM_REMOTESTORAGE,
    STEAM_CONTENTSERVER,
    STEAM_UNIFIEDMESSAGES,
    STEAM_GAMESERVERSTATS,
    STEAM_MATCHMAKINGSERVERS,
    STEAM_MASTERSERVERUPDATER,
    STEAM_MAX,
    STEAM_INVALID
};

struct Interfacemanager
{
    static void Initialize();
    static void *Fetchinterface(const char *Name);
    static void *Fetchinterface(eInterfaceType Type);
    static void Addinterface(eInterfaceType Type, const char *Name, void *Interface);
};
