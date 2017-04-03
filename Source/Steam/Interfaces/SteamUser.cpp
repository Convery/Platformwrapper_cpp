/*
    Initial author: Convery
    Started: 2017-4-3
    License: MIT
*/

#include "All.h"
#include <algorithm>

#define Createmethod(Index, Class, Function)    \
auto Temp ##Function = &Class::Function;        \
Methods[Index] = *(void **)&Temp ##Function;

// A ticket that is encrypted with Ayrias key.
// This ensures that no one can mess with it.
static unsigned char Ticketdata[128];
struct EncryptedAppTicketResponse_t
{
    enum { k_iCallback = 154 };

    EResult m_eResult;
};

#pragma region Methods
class SteamUser
{
public:
    uint32_t GetHSteamUser()
    {
        PrintFunction();
        return 0;
    }
    void LogOn(CSteamID steamID)
    {
        PrintFunction();
        return;
    }
    void LogOff()
    {
        PrintFunction();
        return;
    }
    bool BLoggedOn()
    {
        return true;
    }
    uint32_t GetLogonState()
    {
        PrintFunction();
        return 0;
    }
    bool BConnected()
    {
        PrintFunction();
        return true;
    }
    CSteamID GetSteamID()
    {
        // Cache marker
        return CSteamID(Steamconfig::UserID);
    }
    bool IsVACBanned(uint32_t eVACBan)
    {
        PrintFunction();
        return false;
    }
    bool RequireShowVACBannedMessage(uint32_t eVACBan)
    {
        PrintFunction();
        return false;
    }
    void AcknowledgeVACBanning(uint32_t eVACBan)
    {
        PrintFunction();
    }
    int NClientGameIDAdd(int nGameID)
    {
        PrintFunction();
        return 0;
    }
    void RemoveClientGame(int nClientGameID)
    {
        PrintFunction();
    }
    void SetClientGameServer(int nClientGameID, uint32_t unIPServer, uint16_t usPortServer)
    {
        PrintFunction();
    }
    void SetSteam2Ticket(uint8_t *pubTicket, int cubTicket)
    {
        PrintFunction();
    }
    void AddServerNetAddress(uint32_t unIP, uint16_t unPort)
    {
        PrintFunction();
    }
    bool SetEmail(const char *pchEmail)
    {
        PrintFunction();
        return false;
    }
    int GetSteamGameConnectToken(void *pBlob, int cbMaxBlob)
    {
        PrintFunction();
        return 0;
    }
    bool SetRegistryString(uint32_t eRegistrySubTree, const char *pchKey, const char *pchValue)
    {
        PrintFunction();
        return false;
    }
    bool GetRegistryString(uint32_t eRegistrySubTree, const char *pchKey, char *pchValue, int cbValue)
    {
        PrintFunction();
        return false;
    }
    bool SetRegistryInt(uint32_t eRegistrySubTree, const char *pchKey, int iValue)
    {
        PrintFunction();
        return false;
    }
    bool GetRegistryInt(uint32_t eRegistrySubTree, const char *pchKey, int *piValue)
    {
        PrintFunction();
        return false;
    }
    int InitiateGameConnection0(void *pBlob, int cbMaxBlob, CSteamID steamID, int nGameAppID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        PrintFunction();
        return 0;
    }
    void TerminateGameConnection(uint32_t unIPServer, uint16_t usPortServer)
    {
        PrintFunction();
    }
    void SetSelfAsPrimaryChatDestination()
    {
        PrintFunction();
    }
    bool IsPrimaryChatDestination()
    {
        PrintFunction();
        return false;
    }
    void RequestLegacyCDKey(uint32_t iAppID)
    {
        PrintFunction();
    }
    int InitiateGameConnection1(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID nGameAppID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        PrintFunction();
        return 0;
    }
    bool SendGuestPassByEmail(const char *pchEmailAccount, uint64_t gidGuestPassID, bool bResending)
    {
        PrintFunction();
        return false;
    }
    bool SendGuestPassByAccountID(uint32_t uAccountID, uint64_t gidGuestPassID, bool bResending)
    {
        PrintFunction();
        return false;
    }
    bool AckGuestPass(const char *pchGuestPassCode)
    {
        PrintFunction();
        return false;
    }
    bool RedeemGuestPass(const char *pchGuestPassCode)
    {
        PrintFunction();
        return false;
    }
    uint32_t GetGuestPassToGiveCount()
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetGuestPassToRedeemCount()
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetGuestPassLastUpdateTime()
    {
        PrintFunction();
        return 0;
    }
    bool GetGuestPassToGiveInfo(uint32_t nPassIndex, uint64_t *pgidGuestPassID, int* pnPackageID, uint32_t* pRTime32Created, uint32_t* pRTime32Expiration, uint32_t* pRTime32Sent, uint32_t* pRTime32Redeemed, char * pchRecipientAddress, int cRecipientAddressSize)
    {
        PrintFunction();
        return false;
    }
    bool GetGuestPassToRedeemInfo(uint32_t nPassIndex, uint64_t *pgidGuestPassID, int* pnPackageID, uint32_t* pRTime32Created, uint32_t* pRTime32Expiration, uint32_t* pRTime32Sent, uint32_t* pRTime32Redeemed)
    {
        PrintFunction();
        return false;
    }
    bool GetGuestPassToRedeemSenderAddress(uint32_t nPassIndex, char* pchSenderAddress, int cSenderAddressSize)
    {
        PrintFunction();
        return false;
    }
    bool GetGuestPassToRedeemSenderName(uint32_t nPassIndex, char* pchSenderName, int cSenderNameSize)
    {
        PrintFunction();
        return false;
    }
    void AcknowledgeMessageByGID(const char *pchMessageGID)
    {
        PrintFunction();
    }
    bool SetLanguage(const char *pchLanguage)
    {
        PrintFunction();
        return !strcpy_s(Steamconfig::Language, 31, pchLanguage);
    }
    void TrackAppUsageEvent0(CGameID gameID, uint32_t eAppUsageEvent, const char *pchExtraInfo = "")
    {
        PrintFunction();
    }
    void SetAccountName(const char* pchAccountName)
    {
        PrintFunction();
    }
    void SetPassword(const char* pchPassword)
    {
        PrintFunction();
    }
    void SetAccountCreationTime(uint32_t rtime32Time)
    {
        PrintFunction();
    }
    int InitiateGameConnection2(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID nGameAppID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure, void *pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey)
    {
        PrintFunction();
        return 0;
    }
    void RefreshSteam2Login()
    {
        PrintFunction();
    }
    int InitiateGameConnection3(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID gameID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure, void *pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey)
    {
        PrintFunction();
        return 0;
    }
    int InitiateGameConnection4(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID gameID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        PrintFunction();
        return 0;
    }
    int InitiateGameConnection5(void *pBlob, int cbMaxBlob, CSteamID steamID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        PrintFunction();
        return 0;
    }
    int InitiateGameConnection6(void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        PrintFunction();
        return 0;
    }
    bool GetUserDataFolder(char *pchBuffer, int cubBuffer)
    {
        PrintFunction();
        return false;
    }
    void StartVoiceRecording()
    {
        PrintFunction();
    }
    void StopVoiceRecording()
    {
        PrintFunction();
    }
    uint32_t GetCompressedVoice(void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten)
    {
        PrintFunction();
        return 0;
    }
    uint32_t DecompressVoice0(void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten)
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetAuthSessionTicket(void *pTicket, int cbMaxTicket, uint32_t *pcbTicket)
    {
        PrintFunction();

        // k_HAuthTicketInvalid
        return 0;
    }
    uint32_t BeginAuthSession(const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
    {
        DebugPrint(va("%s for 0x%llx", __func__, steamID.ConvertToUint64()).c_str());

        return 0;
    }
    void EndAuthSession(CSteamID steamID)
    {
        PrintFunction();
    }
    void CancelAuthTicket(uint32_t hAuthTicket)
    {
        PrintFunction();
    }
    uint32_t UserHasLicenseForApp(CSteamID steamID, uint32_t appID)
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetAvailableVoice0(uint32_t *pcbCompressed, uint32_t *pcbUncompressed)
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetVoice0(bool bWantCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32_t cbUncompressedDestBufferSize, uint32_t *nUncompressBytesWritten)
    {
        PrintFunction();
        return 0;
    }
    bool BIsBehindNAT()
    {
        PrintFunction();
        return false;
    }
    void AdvertiseGame(CSteamID steamIDGameServer, uint32_t unIPServer, uint16_t usPortServer)
    {
        PrintFunction();
    }
    uint64_t RequestEncryptedAppTicket(void *pDataToInclude, unsigned int cbDataToInclude)
    {
        PrintFunction();
        uint64_t AsyncCall;
        EncryptedAppTicketResponse_t *Response;
        unsigned int Ticketsize = sizeof(Ticketdata);

        // Fetch a ticket from the client when online.
        if (!Steamconfig::Offline)
        {
            // TODO(Convery): Interact with the pipe to the desktop client.
        }
        else
        {
            memset(Ticketdata, 0, Ticketsize);
        }

        // Include the additional data at the end of the ticket.
        memcpy(&Ticketdata[32], pDataToInclude, std::min(cbDataToInclude, Ticketsize - 32));

        // Create the call and return it instantly.
        AsyncCall = SteamCallback::RegisterCall();
        Response = new EncryptedAppTicketResponse_t();
        Response->m_eResult = k_EResultOK;
        SteamCallback::ReturnCall(Response, sizeof(EncryptedAppTicketResponse_t), Response->k_iCallback, AsyncCall);
        return AsyncCall;
    }
    bool GetEncryptedAppTicket(void *pTicket, unsigned int cbMaxTicket, uint32_t *pcbTicket)
    {
        PrintFunction();
        memcpy(pTicket, Ticketdata, std::min(cbMaxTicket, (unsigned int)sizeof(Ticketdata)));
        *pcbTicket = sizeof(Ticketdata);
        return true;
    }
    uint32_t DecompressVoice1(void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t nSamplesPerSec)
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetVoiceOptimalSampleRate()
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetAvailableVoice1(uint32_t *pcbCompressed, uint32_t *pcbUncompressed, uint32_t nUncompressedVoiceDesiredSampleRate)
    {
        PrintFunction();
        return 0;
    }
    uint32_t GetVoice1(bool bWantCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32_t cbUncompressedDestBufferSize, uint32_t *nUncompressBytesWritten, uint32_t nUncompressedVoiceDesiredSampleRate)
    {
        // k_EVoiceResultNoData
        return 3;
    }
    uint32_t DecompressVoice2(const void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t nDesiredSampleRate)
    {
        PrintFunction();
        return 0;
    }
    int GetGameBadgeLevel(int nSeries, bool bFoil)
    {
        PrintFunction();
        return 0;
    }
    int GetPlayerSteamLevel()
    {
        PrintFunction();
        return 0;
    }
    void TrackAppUsageEvent1(CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "")
    {
        PrintFunction();
    }
    uint64_t RequestStoreAuthURL(const char *pchRedirectURL)
    {
        PrintFunction();
        return 0;
    }
};
#pragma endregion

SteamUser001::SteamUser001()
{
    // Missing SDK info.
};
SteamUser002::SteamUser002()
{
    // Missing SDK info.
};
SteamUser003::SteamUser003()
{
    // Missing SDK info.
};
SteamUser004::SteamUser004()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, LogOn);
    Createmethod(2, SteamUser, LogOff);
    Createmethod(3, SteamUser, BLoggedOn);
    Createmethod(4, SteamUser, GetLogonState);
    Createmethod(5, SteamUser, BConnected);
    Createmethod(6, SteamUser, GetSteamID);
    Createmethod(7, SteamUser, IsVACBanned);
    Createmethod(8, SteamUser, RequireShowVACBannedMessage);
    Createmethod(9, SteamUser, AcknowledgeVACBanning);
    Createmethod(10, SteamUser, NClientGameIDAdd);
    Createmethod(11, SteamUser, RemoveClientGame);
    Createmethod(12, SteamUser, SetClientGameServer);
    Createmethod(13, SteamUser, SetSteam2Ticket);
    Createmethod(14, SteamUser, AddServerNetAddress);
    Createmethod(15, SteamUser, SetEmail);
    Createmethod(16, SteamUser, GetSteamGameConnectToken);
    Createmethod(17, SteamUser, SetRegistryString);
    Createmethod(18, SteamUser, GetRegistryString);
    Createmethod(19, SteamUser, SetRegistryInt);
    Createmethod(20, SteamUser, GetRegistryInt);
    Createmethod(21, SteamUser, InitiateGameConnection0);
    Createmethod(22, SteamUser, TerminateGameConnection);
    Createmethod(23, SteamUser, SetSelfAsPrimaryChatDestination);
    Createmethod(24, SteamUser, IsPrimaryChatDestination);
    Createmethod(25, SteamUser, RequestLegacyCDKey);
};
SteamUser005::SteamUser005()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, LogOn);
    Createmethod(2, SteamUser, LogOff);
    Createmethod(3, SteamUser, BLoggedOn);
    Createmethod(4, SteamUser, GetLogonState);
    Createmethod(5, SteamUser, BConnected);
    Createmethod(6, SteamUser, GetSteamID);
    Createmethod(7, SteamUser, IsVACBanned);
    Createmethod(8, SteamUser, RequireShowVACBannedMessage);
    Createmethod(9, SteamUser, AcknowledgeVACBanning);
    Createmethod(10, SteamUser, SetSteam2Ticket);
    Createmethod(11, SteamUser, AddServerNetAddress);
    Createmethod(12, SteamUser, SetEmail);
    Createmethod(13, SteamUser, SetRegistryString);
    Createmethod(14, SteamUser, GetRegistryString);
    Createmethod(15, SteamUser, SetRegistryInt);
    Createmethod(16, SteamUser, GetRegistryInt);
    Createmethod(17, SteamUser, InitiateGameConnection1);
    Createmethod(18, SteamUser, TerminateGameConnection);
    Createmethod(19, SteamUser, SetSelfAsPrimaryChatDestination);
    Createmethod(20, SteamUser, IsPrimaryChatDestination);
    Createmethod(21, SteamUser, RequestLegacyCDKey);
    Createmethod(22, SteamUser, SendGuestPassByEmail);
    Createmethod(23, SteamUser, SendGuestPassByAccountID);
    Createmethod(24, SteamUser, AckGuestPass);
    Createmethod(25, SteamUser, RedeemGuestPass);
    Createmethod(26, SteamUser, GetGuestPassToGiveCount);
    Createmethod(27, SteamUser, GetGuestPassToRedeemCount);
    Createmethod(28, SteamUser, GetGuestPassLastUpdateTime);
    Createmethod(29, SteamUser, GetGuestPassToGiveInfo);
    Createmethod(30, SteamUser, GetGuestPassToRedeemInfo);
    Createmethod(31, SteamUser, GetGuestPassToRedeemSenderAddress);
    Createmethod(32, SteamUser, GetGuestPassToRedeemSenderName);
    Createmethod(33, SteamUser, AcknowledgeMessageByGID);
    Createmethod(34, SteamUser, SetLanguage);
    Createmethod(35, SteamUser, TrackAppUsageEvent0);
    Createmethod(36, SteamUser, SetAccountName);
    Createmethod(37, SteamUser, SetPassword);
    Createmethod(38, SteamUser, SetAccountCreationTime);
};
SteamUser006::SteamUser006()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, LogOn);
    Createmethod(2, SteamUser, LogOff);
    Createmethod(3, SteamUser, BLoggedOn);
    Createmethod(4, SteamUser, GetSteamID);
    Createmethod(5, SteamUser, SetRegistryString);
    Createmethod(6, SteamUser, GetRegistryString);
    Createmethod(7, SteamUser, SetRegistryInt);
    Createmethod(8, SteamUser, GetRegistryInt);
    Createmethod(9, SteamUser, InitiateGameConnection1);
    Createmethod(10, SteamUser, TerminateGameConnection);
    Createmethod(11, SteamUser, TrackAppUsageEvent0);
};
SteamUser007::SteamUser007()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, LogOn);
    Createmethod(2, SteamUser, LogOff);
    Createmethod(3, SteamUser, BLoggedOn);
    Createmethod(4, SteamUser, GetSteamID);
    Createmethod(5, SteamUser, SetRegistryString);
    Createmethod(6, SteamUser, GetRegistryString);
    Createmethod(7, SteamUser, SetRegistryInt);
    Createmethod(8, SteamUser, GetRegistryInt);
    Createmethod(9, SteamUser, InitiateGameConnection2);
    Createmethod(10, SteamUser, TerminateGameConnection);
    Createmethod(11, SteamUser, TrackAppUsageEvent0);
    Createmethod(12, SteamUser, RefreshSteam2Login);
};
SteamUser008::SteamUser008()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection3);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, RefreshSteam2Login);
};
SteamUser009::SteamUser009()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection4);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, RefreshSteam2Login);
};
SteamUser010::SteamUser010()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection5);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
};
SteamUser011::SteamUser011()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetCompressedVoice);
    Createmethod(10, SteamUser, DecompressVoice0);
};
SteamUser012::SteamUser012()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetCompressedVoice);
    Createmethod(10, SteamUser, DecompressVoice0);
    Createmethod(11, SteamUser, GetAuthSessionTicket);
    Createmethod(12, SteamUser, BeginAuthSession);
    Createmethod(13, SteamUser, EndAuthSession);
    Createmethod(14, SteamUser, CancelAuthTicket);
    Createmethod(15, SteamUser, UserHasLicenseForApp);
};
SteamUser013::SteamUser013()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetAvailableVoice0);
    Createmethod(10, SteamUser, GetVoice0);
    Createmethod(11, SteamUser, DecompressVoice0);
    Createmethod(12, SteamUser, GetAuthSessionTicket);
    Createmethod(13, SteamUser, BeginAuthSession);
    Createmethod(14, SteamUser, EndAuthSession);
    Createmethod(15, SteamUser, CancelAuthTicket);
    Createmethod(16, SteamUser, UserHasLicenseForApp);
    Createmethod(17, SteamUser, BIsBehindNAT);
};
SteamUser014::SteamUser014()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetAvailableVoice0);
    Createmethod(10, SteamUser, GetVoice0);
    Createmethod(11, SteamUser, DecompressVoice0);
    Createmethod(12, SteamUser, GetAuthSessionTicket);
    Createmethod(13, SteamUser, BeginAuthSession);
    Createmethod(14, SteamUser, EndAuthSession);
    Createmethod(15, SteamUser, CancelAuthTicket);
    Createmethod(16, SteamUser, UserHasLicenseForApp);
    Createmethod(17, SteamUser, BIsBehindNAT);
    Createmethod(18, SteamUser, AdvertiseGame);
    Createmethod(19, SteamUser, RequestEncryptedAppTicket);
    Createmethod(20, SteamUser, GetEncryptedAppTicket);
};
SteamUser015::SteamUser015()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetAvailableVoice0);
    Createmethod(10, SteamUser, GetVoice0);
    Createmethod(11, SteamUser, DecompressVoice1);
    Createmethod(12, SteamUser, GetVoiceOptimalSampleRate);
    Createmethod(13, SteamUser, GetAuthSessionTicket);
    Createmethod(14, SteamUser, BeginAuthSession);
    Createmethod(15, SteamUser, EndAuthSession);
    Createmethod(16, SteamUser, CancelAuthTicket);
    Createmethod(17, SteamUser, UserHasLicenseForApp);
    Createmethod(18, SteamUser, BIsBehindNAT);
    Createmethod(19, SteamUser, AdvertiseGame);
    Createmethod(20, SteamUser, RequestEncryptedAppTicket);
    Createmethod(21, SteamUser, GetEncryptedAppTicket);
};
SteamUser016::SteamUser016()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetAvailableVoice1);
    Createmethod(10, SteamUser, GetVoice1);
    Createmethod(11, SteamUser, DecompressVoice2);
    Createmethod(12, SteamUser, GetVoiceOptimalSampleRate);
    Createmethod(13, SteamUser, GetAuthSessionTicket);
    Createmethod(14, SteamUser, BeginAuthSession);
    Createmethod(15, SteamUser, EndAuthSession);
    Createmethod(16, SteamUser, CancelAuthTicket);
    Createmethod(17, SteamUser, UserHasLicenseForApp);
    Createmethod(18, SteamUser, BIsBehindNAT);
    Createmethod(19, SteamUser, AdvertiseGame);
    Createmethod(20, SteamUser, RequestEncryptedAppTicket);
    Createmethod(21, SteamUser, GetEncryptedAppTicket);
};
SteamUser017::SteamUser017()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent0);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetAvailableVoice1);
    Createmethod(10, SteamUser, GetVoice1);
    Createmethod(11, SteamUser, DecompressVoice2);
    Createmethod(12, SteamUser, GetVoiceOptimalSampleRate);
    Createmethod(13, SteamUser, GetAuthSessionTicket);
    Createmethod(14, SteamUser, BeginAuthSession);
    Createmethod(15, SteamUser, EndAuthSession);
    Createmethod(16, SteamUser, CancelAuthTicket);
    Createmethod(17, SteamUser, UserHasLicenseForApp);
    Createmethod(18, SteamUser, BIsBehindNAT);
    Createmethod(19, SteamUser, AdvertiseGame);
    Createmethod(20, SteamUser, RequestEncryptedAppTicket);
    Createmethod(21, SteamUser, GetEncryptedAppTicket);
    Createmethod(23, SteamUser, GetGameBadgeLevel);
    Createmethod(24, SteamUser, GetPlayerSteamLevel);
};
SteamUser018::SteamUser018()
{
    Createmethod(0, SteamUser, GetHSteamUser);
    Createmethod(1, SteamUser, BLoggedOn);
    Createmethod(2, SteamUser, GetSteamID);
    Createmethod(3, SteamUser, InitiateGameConnection6);
    Createmethod(4, SteamUser, TerminateGameConnection);
    Createmethod(5, SteamUser, TrackAppUsageEvent1);
    Createmethod(6, SteamUser, GetUserDataFolder);
    Createmethod(7, SteamUser, StartVoiceRecording);
    Createmethod(8, SteamUser, StopVoiceRecording);
    Createmethod(9, SteamUser, GetAvailableVoice1);
    Createmethod(10, SteamUser, GetVoice1);
    Createmethod(11, SteamUser, DecompressVoice2);
    Createmethod(12, SteamUser, GetVoiceOptimalSampleRate);
    Createmethod(13, SteamUser, GetAuthSessionTicket);
    Createmethod(14, SteamUser, BeginAuthSession);
    Createmethod(15, SteamUser, EndAuthSession);
    Createmethod(16, SteamUser, CancelAuthTicket);
    Createmethod(17, SteamUser, UserHasLicenseForApp);
    Createmethod(18, SteamUser, BIsBehindNAT);
    Createmethod(19, SteamUser, AdvertiseGame);
    Createmethod(20, SteamUser, RequestEncryptedAppTicket);
    Createmethod(21, SteamUser, GetEncryptedAppTicket);
    Createmethod(22, SteamUser, GetGameBadgeLevel);
    Createmethod(23, SteamUser, GetPlayerSteamLevel);
    Createmethod(24, SteamUser, RequestStoreAuthURL);
};

struct Steamuserloader
{
    Steamuserloader()
    {
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser001", new SteamUser001);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser002", new SteamUser002);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser003", new SteamUser003);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser004", new SteamUser004);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser005", new SteamUser005);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser006", new SteamUser006);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser007", new SteamUser007);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser008", new SteamUser008);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser009", new SteamUser009);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser010", new SteamUser010);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser011", new SteamUser011);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser012", new SteamUser012);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser013", new SteamUser013);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser014", new SteamUser014);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser015", new SteamUser015);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser016", new SteamUser016);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser017", new SteamUser017);
        Interfacemanager::Addinterface(STEAM_USER, "SteamUser018", new SteamUser018);
    }
};
static Steamuserloader Interfaceloader;
