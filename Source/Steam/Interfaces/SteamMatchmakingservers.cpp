/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 10-02-2018
    License: MIT
    Notes:
        Steam server browser.
*/

#include "../../Stdinclude.hpp"

#pragma region Methods
class SteamMatchmakingservers
{
public:
    // Version 1.
    void RequestInternetServerList( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return ;
	}
	void RequestLANServerList( uint32_t iApp, void *pRequestServersResponse )
	{
		Printfunction();
		return ;
	}
	void RequestFriendsServerList( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return ;
	}
	void RequestFavoritesServerList( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return ;
	}
	void RequestHistoryServerList( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return ;
	}
	void RequestSpectatorServerList( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return ;
	}
	void *GetServerDetails( uint32_t eType, int iServer )
	{
		Printfunction();
		return nullptr;
	} 
	void CancelQuery( uint32_t eType )
	{
		Printfunction();
		return ;
	} 
	void RefreshQuery( uint32_t eType )
	{
		Printfunction();
		return ;
	} 
	bool IsRefreshing( uint32_t eType )
	{
		Printfunction();
		return false;
	} 
	int GetServerCount( uint32_t eType )
	{
		Printfunction();
		return 0;
	} 
	void RefreshServer( uint32_t eType, int iServer )
	{
		Printfunction();
		return ;
	} 
	int32_t PingServer( uint32_t unIP, uint16_t usPort, void *pRequestServersResponse )
	{
		Printfunction();
		return 0;
	} 
	int32_t PlayerDetails( uint32_t unIP, uint16_t usPort, void *pRequestServersResponse )
	{
		Printfunction();
		return 0;
	}
	int32_t ServerRules( uint32_t unIP, uint16_t usPort, void *pRequestServersResponse )
	{
		Printfunction();
		return 0;
	} 
    void CancelServerQuery( int32_t hServerQuery )
	{
		Printfunction();
		return ;
	} 

    // Version 2.
    void *RequestInternetServerList2( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return nullptr;
	}
	void *RequestLANServerList2( uint32_t iApp, void *pRequestServersResponse )
	{
		Printfunction();
		return nullptr;
	}
	void *RequestFriendsServerList2( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return nullptr;
	}
	void *RequestFavoritesServerList2( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return nullptr;
	}
	void *RequestHistoryServerList2( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return nullptr;
	}
	void *RequestSpectatorServerList2( uint32_t iApp, void **ppchFilters, uint32_t nFilters, void *pRequestServersResponse )
	{
		Printfunction();
		return nullptr;
	}
    void ReleaseRequest( void *hServerListRequest )
	{
		Printfunction();
		return ;
	}
};
#pragma endregion

SteamMatchmakingservers001::SteamMatchmakingservers001()
{
    Createmethod(0, SteamMatchmakingservers, RequestInternetServerList);
    Createmethod(1, SteamMatchmakingservers, RequestLANServerList);
    Createmethod(2, SteamMatchmakingservers, RequestFriendsServerList);
    Createmethod(3, SteamMatchmakingservers, RequestFavoritesServerList);
    Createmethod(4, SteamMatchmakingservers, RequestHistoryServerList);
    Createmethod(5, SteamMatchmakingservers, RequestSpectatorServerList);
    Createmethod(6, SteamMatchmakingservers, GetServerDetails);
    Createmethod(7, SteamMatchmakingservers, CancelQuery);
    Createmethod(8, SteamMatchmakingservers, RefreshQuery);
    Createmethod(9, SteamMatchmakingservers, IsRefreshing);
    Createmethod(10, SteamMatchmakingservers, GetServerCount);
    Createmethod(11, SteamMatchmakingservers, RefreshServer);
    Createmethod(12, SteamMatchmakingservers, PingServer);
    Createmethod(13, SteamMatchmakingservers, PlayerDetails);
    Createmethod(14, SteamMatchmakingservers, ServerRules);
    Createmethod(15, SteamMatchmakingservers, CancelServerQuery);
};
SteamMatchmakingservers002::SteamMatchmakingservers002()
{    
    Createmethod(0, SteamMatchmakingservers, RequestInternetServerList2);
    Createmethod(1, SteamMatchmakingservers, RequestLANServerList2);
    Createmethod(2, SteamMatchmakingservers, RequestFriendsServerList2);
    Createmethod(3, SteamMatchmakingservers, RequestFavoritesServerList2);
    Createmethod(4, SteamMatchmakingservers, RequestHistoryServerList2);
    Createmethod(5, SteamMatchmakingservers, RequestSpectatorServerList2);
    Createmethod(6, SteamMatchmakingservers, ReleaseRequest);
    Createmethod(7, SteamMatchmakingservers, GetServerDetails);
    Createmethod(8, SteamMatchmakingservers, CancelQuery);
    Createmethod(9, SteamMatchmakingservers, RefreshQuery);
    Createmethod(10, SteamMatchmakingservers, IsRefreshing);
    Createmethod(11, SteamMatchmakingservers, GetServerCount);
    Createmethod(12, SteamMatchmakingservers, RefreshServer);
    Createmethod(13, SteamMatchmakingservers, PingServer);
    Createmethod(14, SteamMatchmakingservers, PlayerDetails);
    Createmethod(15, SteamMatchmakingservers, ServerRules);
    Createmethod(16, SteamMatchmakingservers, CancelServerQuery);
};

struct Steammatchmakingserversloader
{
    Steammatchmakingserversloader()
    {
        Createinterface(STEAM_MATCHMAKINGSERVERS, SteamMatchmakingservers001);
        Createinterface(STEAM_MATCHMAKINGSERVERS, SteamMatchmakingservers002);
    }
};
static Steammatchmakingserversloader Interfaceloader{};
