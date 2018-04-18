/*
    Initial author: Convery (tcn@ayria.se)
    Started: 10-02-2018
    License: MIT
    Notes:
        Steam interface proxy.
*/

#include "../../Stdinclude.hpp"

#pragma region Methods
class SteamClient
{
public:
    // Version 6.
	int32_t CreateSteamPipe()
	{
		Printfunction();
		return 0;
	}
	bool BReleaseSteamPipe( int32_t hSteamPipe )
	{
		Printfunction();
		return false;
	}
	int32_t CreateGlobalUser( int32_t *phSteamPipe )
	{
		Printfunction();
		return 0;
	}
	int32_t ConnectToGlobalUser( int32_t hSteamPipe )
	{
		Printfunction();
		return 0;
	}
	int32_t CreateLocalUser( int32_t *phSteamPipe )
	{
		Printfunction();
		return 0;
	}
	void ReleaseUser( int32_t hSteamPipe, int32_t hUser )
	{
		Printfunction();
		return ;
	}
	void *GetISteamUser( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamUser();
	}
	void *GetIVAC( int32_t hSteamUser )
	{
		Printfunction();
		return nullptr;
	}
	void *GetISteamGameServer( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamGameServer();
	}
	void SetLocalIPBinding( uint32_t unIP, uint16_t usPort )
	{
		Printfunction();
		return ;
	} 
	const char *GetUniverseName( uint32_t eUniverse )
	{
		Printfunction();
		return "";
	}
	void *GetISteamFriends( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamFriends();
	}
	void *GetISteamUtils( int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamUtils();
	}
	void *GetISteamBilling( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return nullptr;
	}
	void *GetISteamMatchmaking( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamMatchmaking();
	}
	void *GetISteamContentServer( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return nullptr;
	}
	void *GetISteamApps( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamApps();
	}
	void *GetISteamMasterServerUpdater( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return nullptr;
	}
	void *GetISteamMatchmakingServers( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamMatchmakingServers();
	}
	void RunFrame()
	{
		Printfunction();
		return SteamAPI_RunCallbacks();
	}
    uint32_t GetIPCCallCount()
	{
		Printfunction();
		return 20;
	}

    // Version 7.
    void *GetISteamGenericInterface( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return new Fakeclass();
	}
    void *GetISteamUserStats( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamUserStats();
	}
    void *GetISteamNetworking( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamNetworking();
	}
    void SetWarningMessageHook( void *pFunction )
	{
		Printfunction();
		return ;
	}
    void *GetISteamRemoteStorage( int32_t hSteamuser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamRemoteStorage();
	}

    // Version 9.
    void *GetISteamGameServerStats( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamGameServerStats();
	}

    // Version 10.
    bool BShutdownIfAllPipesClosed()
	{
		Printfunction();
		return false;
	}
    void *GetISteamHTTP( int32_t hSteamuser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamHTTP();
	}

    // Version 11.
    void *GetISteamScreenshots( int32_t hSteamuser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamScreenshots();
	}

    // Version 12.
    void *GetISteamUnifiedMessages( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamUnifiedMessages();
	}
    void *GetISteamController( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamController();
	}

    // Version 13.
    void *GetISteamUGC( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamUGC();
	}
	void *GetISteamInventory( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamInventory();
	}
	void *GetISteamVideo( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamVideo();
	}
    void *GetISteamAppList( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamAppList();
	}

    // Version 14.
    void *GetISteamMusic( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamMusic();
	}

    // Version 15.
    void *GetISteamMusicRemote( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamMusicRemote();
	}

    // Version 16.
    void *GetISteamHTMLSurface( int32_t hSteamUser, int32_t hSteamPipe, const char *pchVersion )
	{
		Printfunction();
		return SteamHTMLSurface();
	}
	void Set_SteamAPI_CPostAPIResultInProcess(void(*)(uint64_t callHandle, void *, uint32_t unCallbackSize, int iCallbackNum))
	{
		Printfunction();
		return ;
	}
	void Remove_SteamAPI_CPostAPIResultInProcess(void(*)(uint64_t callHandle, void *, uint32_t unCallbackSize, int iCallbackNum))
	{
		Printfunction();
		return ;
	}
    void Set_SteamAPI_CCheckCallbackRegisteredInProcess(unsigned int(*)(int iCallbackNum))
	{
		Printfunction();
		return ;
	}
};
#pragma endregion

SteamClient001::SteamClient001()
{
    /*
        Missing SDK information.
    */
};
SteamClient002::SteamClient002()
{
    /*
        Missing SDK information.
    */
};
SteamClient003::SteamClient003()
{
    /*
        Missing SDK information.
    */
};
SteamClient004::SteamClient004()
{
    /*
        Missing SDK information.
    */
};
SteamClient005::SteamClient005()
{
    /*
        Missing SDK information.
    */
};
SteamClient006::SteamClient006()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, CreateGlobalUser);
    Createmethod(3, SteamClient, ConnectToGlobalUser);
    Createmethod(4, SteamClient, CreateLocalUser);
    Createmethod(5, SteamClient, ReleaseUser);
    Createmethod(6, SteamClient, GetISteamUser);
    Createmethod(7, SteamClient, GetIVAC);
    Createmethod(8, SteamClient, GetISteamGameServer);
    Createmethod(9, SteamClient, SetLocalIPBinding);
    Createmethod(10, SteamClient, GetUniverseName);
    Createmethod(11, SteamClient, GetISteamFriends);
    Createmethod(12, SteamClient, GetISteamUtils);
    Createmethod(13, SteamClient, GetISteamBilling);
    Createmethod(14, SteamClient, GetISteamMatchmaking);
    Createmethod(15, SteamClient, GetISteamContentServer);
    Createmethod(16, SteamClient, GetISteamApps);
    Createmethod(17, SteamClient, GetISteamMasterServerUpdater);
    Createmethod(18, SteamClient, GetISteamMatchmakingServers);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
};
SteamClient007::SteamClient007()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamContentServer);
    Createmethod(12, SteamClient, GetISteamMasterServerUpdater);
    Createmethod(13, SteamClient, GetISteamMatchmakingServers);
    Createmethod(14, SteamClient, GetISteamGenericInterface);
    Createmethod(15, SteamClient, RunFrame);
    Createmethod(16, SteamClient, GetIPCCallCount);
    Createmethod(17, SteamClient, GetISteamUserStats);
    Createmethod(18, SteamClient, GetISteamApps);
    Createmethod(19, SteamClient, GetISteamNetworking);
    Createmethod(20, SteamClient, SetWarningMessageHook);
    Createmethod(21, SteamClient, GetISteamRemoteStorage);
};
SteamClient008::SteamClient008()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMasterServerUpdater);
    Createmethod(12, SteamClient, GetISteamMatchmakingServers);
    Createmethod(13, SteamClient, GetISteamGenericInterface);
    Createmethod(14, SteamClient, GetISteamUserStats);
    Createmethod(15, SteamClient, GetISteamApps);
    Createmethod(16, SteamClient, GetISteamNetworking);
    Createmethod(17, SteamClient, GetISteamRemoteStorage);
    Createmethod(18, SteamClient, RunFrame);
    Createmethod(19, SteamClient, GetIPCCallCount);
    Createmethod(20, SteamClient, SetWarningMessageHook);
};
SteamClient009::SteamClient009()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMasterServerUpdater);
    Createmethod(12, SteamClient, GetISteamMatchmakingServers);
    Createmethod(13, SteamClient, GetISteamGenericInterface);
    Createmethod(14, SteamClient, GetISteamUserStats);
    Createmethod(15, SteamClient, GetISteamGameServerStats);
    Createmethod(16, SteamClient, GetISteamApps);
    Createmethod(17, SteamClient, GetISteamNetworking);
    Createmethod(18, SteamClient, GetISteamRemoteStorage);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
};
SteamClient010::SteamClient010()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMasterServerUpdater);
    Createmethod(12, SteamClient, GetISteamMatchmakingServers);
    Createmethod(13, SteamClient, GetISteamGenericInterface);
    Createmethod(14, SteamClient, GetISteamUserStats);
    Createmethod(15, SteamClient, GetISteamGameServerStats);
    Createmethod(16, SteamClient, GetISteamApps);
    Createmethod(17, SteamClient, GetISteamNetworking);
    Createmethod(18, SteamClient, GetISteamRemoteStorage);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
    Createmethod(22, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(23, SteamClient, GetISteamHTTP);
};
SteamClient011::SteamClient011()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMasterServerUpdater);
    Createmethod(12, SteamClient, GetISteamMatchmakingServers);
    Createmethod(13, SteamClient, GetISteamGenericInterface);
    Createmethod(14, SteamClient, GetISteamUserStats);
    Createmethod(15, SteamClient, GetISteamGameServerStats);
    Createmethod(16, SteamClient, GetISteamApps);
    Createmethod(17, SteamClient, GetISteamNetworking);
    Createmethod(18, SteamClient, GetISteamRemoteStorage);
    Createmethod(19, SteamClient, GetISteamScreenshots);
    Createmethod(20, SteamClient, RunFrame);
    Createmethod(21, SteamClient, GetIPCCallCount);
    Createmethod(22, SteamClient, SetWarningMessageHook);
    Createmethod(23, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(24, SteamClient, GetISteamHTTP);
};
SteamClient012::SteamClient012()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMatchmakingServers);
    Createmethod(12, SteamClient, GetISteamGenericInterface);
    Createmethod(13, SteamClient, GetISteamUserStats);
    Createmethod(14, SteamClient, GetISteamGameServerStats);
    Createmethod(15, SteamClient, GetISteamApps);
    Createmethod(16, SteamClient, GetISteamNetworking);
    Createmethod(17, SteamClient, GetISteamRemoteStorage);
    Createmethod(18, SteamClient, GetISteamScreenshots);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
    Createmethod(22, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(23, SteamClient, GetISteamHTTP);
    Createmethod(24, SteamClient, GetISteamUnifiedMessages);
    Createmethod(25, SteamClient, GetISteamController);
};
SteamClient013::SteamClient013()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMatchmakingServers);
    Createmethod(12, SteamClient, GetISteamGenericInterface);
    Createmethod(13, SteamClient, GetISteamUserStats);
    Createmethod(14, SteamClient, GetISteamGameServerStats);
    Createmethod(15, SteamClient, GetISteamApps);
    Createmethod(16, SteamClient, GetISteamNetworking);
    Createmethod(17, SteamClient, GetISteamRemoteStorage);
    Createmethod(18, SteamClient, GetISteamScreenshots);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
    Createmethod(22, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(23, SteamClient, GetISteamHTTP);
    Createmethod(24, SteamClient, GetISteamUnifiedMessages);
    Createmethod(25, SteamClient, GetISteamController);
    Createmethod(26, SteamClient, GetISteamUGC);
    Createmethod(27, SteamClient, GetISteamInventory);
    Createmethod(28, SteamClient, GetISteamVideo);
    Createmethod(29, SteamClient, GetISteamAppList);
};
SteamClient014::SteamClient014()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMatchmakingServers);
    Createmethod(12, SteamClient, GetISteamGenericInterface);
    Createmethod(13, SteamClient, GetISteamUserStats);
    Createmethod(14, SteamClient, GetISteamGameServerStats);
    Createmethod(15, SteamClient, GetISteamApps);
    Createmethod(16, SteamClient, GetISteamNetworking);
    Createmethod(17, SteamClient, GetISteamRemoteStorage);
    Createmethod(18, SteamClient, GetISteamScreenshots);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
    Createmethod(22, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(23, SteamClient, GetISteamHTTP);
    Createmethod(24, SteamClient, GetISteamUnifiedMessages);
    Createmethod(25, SteamClient, GetISteamController);
    Createmethod(26, SteamClient, GetISteamUGC);
    Createmethod(27, SteamClient, GetISteamInventory);
    Createmethod(28, SteamClient, GetISteamVideo);
    Createmethod(29, SteamClient, GetISteamAppList);
    Createmethod(30, SteamClient, GetISteamMusic);
};
SteamClient015::SteamClient015()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMatchmakingServers);
    Createmethod(12, SteamClient, GetISteamGenericInterface);
    Createmethod(13, SteamClient, GetISteamUserStats);
    Createmethod(14, SteamClient, GetISteamGameServerStats);
    Createmethod(15, SteamClient, GetISteamApps);
    Createmethod(16, SteamClient, GetISteamNetworking);
    Createmethod(17, SteamClient, GetISteamRemoteStorage);
    Createmethod(18, SteamClient, GetISteamScreenshots);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
    Createmethod(22, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(23, SteamClient, GetISteamHTTP);
    Createmethod(24, SteamClient, GetISteamUnifiedMessages);
    Createmethod(25, SteamClient, GetISteamController);
    Createmethod(26, SteamClient, GetISteamUGC);
    Createmethod(27, SteamClient, GetISteamInventory);
    Createmethod(28, SteamClient, GetISteamVideo);
    Createmethod(29, SteamClient, GetISteamAppList);
    Createmethod(30, SteamClient, GetISteamMusic);
    Createmethod(31, SteamClient, GetISteamMusicRemote);
};
SteamClient016::SteamClient016()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMatchmakingServers);
    Createmethod(12, SteamClient, GetISteamGenericInterface);
    Createmethod(13, SteamClient, GetISteamUserStats);
    Createmethod(14, SteamClient, GetISteamGameServerStats);
    Createmethod(15, SteamClient, GetISteamApps);
    Createmethod(16, SteamClient, GetISteamNetworking);
    Createmethod(17, SteamClient, GetISteamRemoteStorage);
    Createmethod(18, SteamClient, GetISteamScreenshots);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
    Createmethod(22, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(23, SteamClient, GetISteamHTTP);
    Createmethod(24, SteamClient, GetISteamUnifiedMessages);
    Createmethod(25, SteamClient, GetISteamController);
    Createmethod(26, SteamClient, GetISteamUGC);
    Createmethod(27, SteamClient, GetISteamInventory);
    Createmethod(28, SteamClient, GetISteamVideo);
    Createmethod(29, SteamClient, GetISteamAppList);
    Createmethod(30, SteamClient, GetISteamMusic);
    Createmethod(31, SteamClient, GetISteamMusicRemote);
    Createmethod(32, SteamClient, GetISteamHTMLSurface);
    Createmethod(33, SteamClient, Set_SteamAPI_CPostAPIResultInProcess);
    Createmethod(34, SteamClient, Remove_SteamAPI_CPostAPIResultInProcess);
    Createmethod(35, SteamClient, Set_SteamAPI_CCheckCallbackRegisteredInProcess);
};
SteamClient017::SteamClient017()
{
    Createmethod(0, SteamClient, CreateSteamPipe);
    Createmethod(1, SteamClient, BReleaseSteamPipe);
    Createmethod(2, SteamClient, ConnectToGlobalUser);
    Createmethod(3, SteamClient, CreateLocalUser);
    Createmethod(4, SteamClient, ReleaseUser);
    Createmethod(5, SteamClient, GetISteamUser);
    Createmethod(6, SteamClient, GetISteamGameServer);
    Createmethod(7, SteamClient, SetLocalIPBinding);
    Createmethod(8, SteamClient, GetISteamFriends);
    Createmethod(9, SteamClient, GetISteamUtils);
    Createmethod(10, SteamClient, GetISteamMatchmaking);
    Createmethod(11, SteamClient, GetISteamMatchmakingServers);
    Createmethod(12, SteamClient, GetISteamGenericInterface);
    Createmethod(13, SteamClient, GetISteamUserStats);
    Createmethod(14, SteamClient, GetISteamGameServerStats);
    Createmethod(15, SteamClient, GetISteamApps);
    Createmethod(16, SteamClient, GetISteamNetworking);
    Createmethod(17, SteamClient, GetISteamRemoteStorage);
    Createmethod(18, SteamClient, GetISteamScreenshots);
    Createmethod(19, SteamClient, RunFrame);
    Createmethod(20, SteamClient, GetIPCCallCount);
    Createmethod(21, SteamClient, SetWarningMessageHook);
    Createmethod(22, SteamClient, BShutdownIfAllPipesClosed);
    Createmethod(23, SteamClient, GetISteamHTTP);
    Createmethod(24, SteamClient, GetISteamUnifiedMessages);
    Createmethod(25, SteamClient, GetISteamController);
    Createmethod(26, SteamClient, GetISteamUGC);
    Createmethod(27, SteamClient, GetISteamAppList);
    Createmethod(28, SteamClient, GetISteamMusic);
    Createmethod(29, SteamClient, GetISteamMusicRemote);
    Createmethod(30, SteamClient, GetISteamHTMLSurface);
    Createmethod(31, SteamClient, Set_SteamAPI_CPostAPIResultInProcess);
    Createmethod(32, SteamClient, Remove_SteamAPI_CPostAPIResultInProcess);
    Createmethod(33, SteamClient, Set_SteamAPI_CCheckCallbackRegisteredInProcess);
    Createmethod(34, SteamClient, GetISteamInventory);
    Createmethod(35, SteamClient, GetISteamVideo);
};

struct Steamclientloader
{
    Steamclientloader()
    {
        Createinterface(STEAM_CLIENT, SteamClient001);
        Createinterface(STEAM_CLIENT, SteamClient002);
        Createinterface(STEAM_CLIENT, SteamClient003);
        Createinterface(STEAM_CLIENT, SteamClient004);
        Createinterface(STEAM_CLIENT, SteamClient005);
        Createinterface(STEAM_CLIENT, SteamClient006);
        Createinterface(STEAM_CLIENT, SteamClient007);
        Createinterface(STEAM_CLIENT, SteamClient008);
        Createinterface(STEAM_CLIENT, SteamClient009);
        Createinterface(STEAM_CLIENT, SteamClient010);
        Createinterface(STEAM_CLIENT, SteamClient011);
        Createinterface(STEAM_CLIENT, SteamClient012);
        Createinterface(STEAM_CLIENT, SteamClient013);
        Createinterface(STEAM_CLIENT, SteamClient014);
        Createinterface(STEAM_CLIENT, SteamClient015);
        Createinterface(STEAM_CLIENT, SteamClient016);
        Createinterface(STEAM_CLIENT, SteamClient017);
    }
};
static Steamclientloader Interfaceloader{};
