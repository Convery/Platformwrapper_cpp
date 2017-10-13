/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam networking information.
*/

#include "../../Stdinclude.h"

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;
#define Createinterface(Enum, Class)            \
static Class DEV ## Class;                      \
Interfacemanager::Addinterface(Enum, #Class, &DEV ## Class);

#pragma region Methods
class SteamNetworking
{
public:
    uint32_t CreateListenSocket0(int nVirtualP2PPort, uint32_t nIP, uint16_t nPort)
    {
        Printfunction();
        return 0;
    }
    uint32_t CreateP2PConnectionSocket0(CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec)
    {
        Printfunction();
        return 0;
    }
    uint32_t CreateConnectionSocket(uint32_t nIP, uint16_t nPort, int nTimeoutSec)
    {
        Printfunction();
        return 0;
    }
    bool DestroySocket(uint32_t hSocket, bool bNotifyRemoteEnd)
    {
        Printfunction();
        return false;
    }
    bool DestroyListenSocket(uint32_t hSocket, bool bNotifyRemoteEnd)
    {
        Printfunction();
        return false;
    }
    bool SendDataOnSocket(uint32_t hSocket, void *pubData, uint32_t cubData, bool bReliable)
    {
        Printfunction();
        return false;
    }
    bool IsDataAvailableOnSocket(uint32_t hSocket, uint32_t *pcubMsgSize)
    {
        Printfunction();
        return false;
    }
    bool RetrieveDataFromSocket(uint32_t hSocket, void *pubDest, uint32_t cubDest, uint32_t *pcubMsgSize)
    {
        Printfunction();
        return false;
    }
    bool IsDataAvailable(uint32_t hListenSocket, uint32_t *pcubMsgSize, uint32_t *phSocket)
    {
        return false;
    }
    bool RetrieveData0(uint32_t hListenSocket, void *pubDest, uint32_t cubDest, uint32_t *pcubMsgSize)
    {
        Printfunction();
        return false;
    }
    bool GetSocketInfo0(uint32_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32_t *punIPRemote, uint16_t *punPortRemote)
    {
        Printfunction();
        return false;
    }
    bool GetListenSocketInfo(uint32_t hListenSocket, uint32_t *pnIP, uint16_t *pnPort)
    {
        Printfunction();
        return false;
    }
    uint32_t CreateListenSocket1(int nVirtualP2PPort, uint32_t nIP, uint16_t nPort, bool bAllowUseOfPacketRelay)
    {
        Printfunction();
        return 0;
    }
    uint32_t CreateP2PConnectionSocket1(CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay)
    {
        Printfunction();
        return 0;
    }
    bool RetrieveData1(uint32_t hListenSocket, void *pubDest, uint32_t cubDest, uint32_t *pcubMsgSize, uint32_t *phSocket)
    {
        Printfunction();
        return false;
    }
    bool GetSocketInfo1(uint32_t hSocket, CSteamID *pSteamIDRemote, uint32_t *peSocketStatus, uint32_t *punIPRemote, uint16_t *punPortRemote)
    {
        Printfunction();
        return false;
    }
    uint32_t GetSocketConnectionType(uint32_t hSocket)
    {
        Printfunction();
        return 0;
    }
    int GetMaxPacketSize(uint32_t hSocket)
    {
        Printfunction();
        return 0;
    }
    bool SendP2PPacket0(CSteamID steamIDRemote, const void *pubData, uint32_t cubData, uint32_t eP2PSendType)
    {
        Printfunction();
        return false;
    }
    bool IsP2PPacketAvailable0(uint32_t *pcubMsgSize)
    {
        return false;
    }
    bool ReadP2PPacket0(void *pubDest, uint32_t cubDest, uint32_t *pcubMsgSize, CSteamID *psteamIDRemote)
    {
        Printfunction();
        return false;
    }
    bool AcceptP2PSessionWithUser(CSteamID steamIDRemote)
    {
        Printfunction();
        return false;
    }
    bool CloseP2PSessionWithUser(CSteamID steamIDRemote)
    {
        Printfunction();
        return false;
    }
    bool GetP2PSessionState(CSteamID steamIDRemote, struct P2PSessionState_t *pConnectionState)
    {
        Printfunction();
        return false;
    }
    bool SendP2PPacket1(CSteamID steamIDRemote, const void *pubData, uint32_t cubData, uint32_t eP2PSendType, int iVirtualPort)
    {
        Printfunction();
        return false;
    }
    bool IsP2PPacketAvailable1(uint32_t *pcubMsgSize, int iVirtualPort)
    {
        return false;
    }
    bool ReadP2PPacket1(void *pubDest, uint32_t cubDest, uint32_t *pcubMsgSize, CSteamID *psteamIDRemote, int iVirtualPort)
    {
        Printfunction();
        return false;
    }
    bool CloseP2PChannelWithUser(CSteamID steamIDRemote, int iVirtualPort)
    {
        Printfunction();
        return false;
    }
    bool AllowP2PPacketRelay(bool bAllow)
    {
        Printfunction();
        return false;
    }
};
#pragma endregion

SteamNetworking001::SteamNetworking001()
{
    Createmethod(0, SteamNetworking, CreateListenSocket0);
    Createmethod(1, SteamNetworking, CreateP2PConnectionSocket0);
    Createmethod(2, SteamNetworking, CreateConnectionSocket);
    Createmethod(3, SteamNetworking, DestroySocket);
    Createmethod(4, SteamNetworking, DestroyListenSocket);
    Createmethod(5, SteamNetworking, SendDataOnSocket);
    Createmethod(6, SteamNetworking, IsDataAvailableOnSocket);
    Createmethod(7, SteamNetworking, RetrieveDataFromSocket);
    Createmethod(8, SteamNetworking, IsDataAvailable);
    Createmethod(9, SteamNetworking, RetrieveData0);
    Createmethod(10, SteamNetworking, GetSocketInfo0);
    Createmethod(11, SteamNetworking, GetListenSocketInfo);
};
SteamNetworking002::SteamNetworking002()
{
    Createmethod(0, SteamNetworking, CreateListenSocket1);
    Createmethod(1, SteamNetworking, CreateP2PConnectionSocket1);
    Createmethod(2, SteamNetworking, CreateConnectionSocket);
    Createmethod(3, SteamNetworking, DestroySocket);
    Createmethod(4, SteamNetworking, DestroyListenSocket);
    Createmethod(5, SteamNetworking, SendDataOnSocket);
    Createmethod(6, SteamNetworking, IsDataAvailableOnSocket);
    Createmethod(7, SteamNetworking, RetrieveDataFromSocket);
    Createmethod(8, SteamNetworking, IsDataAvailable);
    Createmethod(9, SteamNetworking, RetrieveData1);
    Createmethod(10, SteamNetworking, GetSocketInfo1);
    Createmethod(11, SteamNetworking, GetListenSocketInfo);
    Createmethod(12, SteamNetworking, GetSocketConnectionType);
    Createmethod(13, SteamNetworking, GetMaxPacketSize);
};
SteamNetworking003::SteamNetworking003()
{
    Createmethod(0, SteamNetworking, SendP2PPacket0);
    Createmethod(1, SteamNetworking, IsP2PPacketAvailable0);
    Createmethod(2, SteamNetworking, ReadP2PPacket0);
    Createmethod(3, SteamNetworking, AcceptP2PSessionWithUser);
    Createmethod(4, SteamNetworking, CloseP2PSessionWithUser);
    Createmethod(5, SteamNetworking, GetP2PSessionState);
    Createmethod(6, SteamNetworking, CreateListenSocket1);
    Createmethod(7, SteamNetworking, CreateP2PConnectionSocket1);
    Createmethod(8, SteamNetworking, CreateConnectionSocket);
    Createmethod(9, SteamNetworking, DestroySocket);
    Createmethod(10, SteamNetworking, DestroyListenSocket);
    Createmethod(11, SteamNetworking, SendDataOnSocket);
    Createmethod(12, SteamNetworking, IsDataAvailableOnSocket);
    Createmethod(13, SteamNetworking, RetrieveDataFromSocket);
    Createmethod(14, SteamNetworking, IsDataAvailable);
    Createmethod(15, SteamNetworking, RetrieveData1);
    Createmethod(16, SteamNetworking, GetSocketInfo0);
    Createmethod(17, SteamNetworking, GetListenSocketInfo);
    Createmethod(18, SteamNetworking, GetSocketConnectionType);
    Createmethod(19, SteamNetworking, GetMaxPacketSize);
};
SteamNetworking004::SteamNetworking004()
{
    Createmethod(0, SteamNetworking, SendP2PPacket1);
    Createmethod(1, SteamNetworking, IsP2PPacketAvailable1);
    Createmethod(2, SteamNetworking, ReadP2PPacket1);
    Createmethod(3, SteamNetworking, AcceptP2PSessionWithUser);
    Createmethod(4, SteamNetworking, CloseP2PSessionWithUser);
    Createmethod(5, SteamNetworking, GetP2PSessionState);
    Createmethod(6, SteamNetworking, CreateListenSocket1);
    Createmethod(7, SteamNetworking, CreateP2PConnectionSocket1);
    Createmethod(8, SteamNetworking, CreateConnectionSocket);
    Createmethod(9, SteamNetworking, DestroySocket);
    Createmethod(10, SteamNetworking, DestroyListenSocket);
    Createmethod(11, SteamNetworking, SendDataOnSocket);
    Createmethod(12, SteamNetworking, IsDataAvailableOnSocket);
    Createmethod(13, SteamNetworking, RetrieveDataFromSocket);
    Createmethod(14, SteamNetworking, IsDataAvailable);
    Createmethod(15, SteamNetworking, RetrieveData1);
    Createmethod(16, SteamNetworking, GetSocketInfo0);
    Createmethod(17, SteamNetworking, GetListenSocketInfo);
    Createmethod(18, SteamNetworking, GetSocketConnectionType);
    Createmethod(19, SteamNetworking, GetMaxPacketSize);
};
SteamNetworking005::SteamNetworking005()
{
    Createmethod(0, SteamNetworking, SendP2PPacket1);
    Createmethod(1, SteamNetworking, IsP2PPacketAvailable1);
    Createmethod(2, SteamNetworking, ReadP2PPacket1);
    Createmethod(3, SteamNetworking, AcceptP2PSessionWithUser);
    Createmethod(4, SteamNetworking, CloseP2PSessionWithUser);
    Createmethod(5, SteamNetworking, CloseP2PChannelWithUser);
    Createmethod(6, SteamNetworking, GetP2PSessionState);
    Createmethod(7, SteamNetworking, AllowP2PPacketRelay);
    Createmethod(8, SteamNetworking, CreateListenSocket1);
    Createmethod(9, SteamNetworking, CreateP2PConnectionSocket1);
    Createmethod(10, SteamNetworking, CreateConnectionSocket);
    Createmethod(11, SteamNetworking, DestroySocket);
    Createmethod(12, SteamNetworking, DestroyListenSocket);
    Createmethod(13, SteamNetworking, SendDataOnSocket);
    Createmethod(14, SteamNetworking, IsDataAvailableOnSocket);
    Createmethod(15, SteamNetworking, RetrieveDataFromSocket);
    Createmethod(16, SteamNetworking, IsDataAvailable);
    Createmethod(17, SteamNetworking, RetrieveData1);
    Createmethod(18, SteamNetworking, GetSocketInfo0);
    Createmethod(19, SteamNetworking, GetListenSocketInfo);
    Createmethod(20, SteamNetworking, GetSocketConnectionType);
    Createmethod(21, SteamNetworking, GetMaxPacketSize);
};

struct Steamnetworkingloader
{
    Steamnetworkingloader()
    {
        Createinterface(STEAM_NETWORKING, SteamNetworking001);
        Createinterface(STEAM_NETWORKING, SteamNetworking002);
        Createinterface(STEAM_NETWORKING, SteamNetworking003);
        Createinterface(STEAM_NETWORKING, SteamNetworking004);
        Createinterface(STEAM_NETWORKING, SteamNetworking005);
    }
};
static Steamnetworkingloader Interfaceloader{};
