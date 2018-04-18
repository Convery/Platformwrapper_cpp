/*
    Initial author: Convery (tcn@ayria.se)
    Started: 03-08-2017
    License: MIT
    Notes:
        Steam profile information.
*/

#include "../../Stdinclude.hpp"

/*
    NOTE(Convery):
    Steam creates a ticket and encrypts it with their publickey.
    Then the games backend/middleware can ask steam to decrypt it.
    We may want to offer a similar service, but for now it's plaintext.
*/
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
        Printfunction();
        return 0;
    }
    void LogOn(CSteamID steamID)
    {
        Printfunction();
        return;
    }
    void LogOff()
    {
        Printfunction();
        return;
    }
    bool BLoggedOn()
    {
        return true;
    }
    uint32_t GetLogonState()
    {
        Printfunction();
        return 0;
    }
    bool BConnected()
    {
        Printfunction();
        return true;
    }
    CSteamID GetSteamID()
    {
        // Cache marker
        return CSteamID(Steamconfig::UserID);
    }
    bool IsVACBanned(uint32_t eVACBan)
    {
        Printfunction();
        return false;
    }
    bool RequireShowVACBannedMessage(uint32_t eVACBan)
    {
        Printfunction();
        return false;
    }
    void AcknowledgeVACBanning(uint32_t eVACBan)
    {
        Printfunction();
    }
    int NClientGameIDAdd(int nGameID)
    {
        Printfunction();
        return 0;
    }
    void RemoveClientGame(int nClientGameID)
    {
        Printfunction();
    }
    void SetClientGameServer(int nClientGameID, uint32_t unIPServer, uint16_t usPortServer)
    {
        Printfunction();
    }
    void SetSteam2Ticket(uint8_t *pubTicket, int cubTicket)
    {
        Printfunction();
    }
    void AddServerNetAddress(uint32_t unIP, uint16_t unPort)
    {
        Printfunction();
    }
    bool SetEmail(const char *pchEmail)
    {
        Printfunction();
        return false;
    }
    int GetSteamGameConnectToken(void *pBlob, int cbMaxBlob)
    {
        Printfunction();
        return 0;
    }
    bool SetRegistryString(uint32_t eRegistrySubTree, const char *pchKey, const char *pchValue)
    {
        Printfunction();
        return false;
    }
    bool GetRegistryString(uint32_t eRegistrySubTree, const char *pchKey, char *pchValue, int cbValue)
    {
        Printfunction();
        return false;
    }
    bool SetRegistryInt(uint32_t eRegistrySubTree, const char *pchKey, int iValue)
    {
        Printfunction();
        return false;
    }
    bool GetRegistryInt(uint32_t eRegistrySubTree, const char *pchKey, int *piValue)
    {
        Printfunction();
        return false;
    }
    int InitiateGameConnection0(void *pBlob, int cbMaxBlob, CSteamID steamID, int nGameAppID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        Printfunction();
        return 0;
    }
    void TerminateGameConnection(uint32_t unIPServer, uint16_t usPortServer)
    {
        Printfunction();
    }
    void SetSelfAsPrimaryChatDestination()
    {
        Printfunction();
    }
    bool IsPrimaryChatDestination()
    {
        Printfunction();
        return false;
    }
    void RequestLegacyCDKey(uint32_t iAppID)
    {
        Printfunction();
    }
    int InitiateGameConnection1(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID nGameAppID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        Printfunction();
        return 0;
    }
    bool SendGuestPassByEmail(const char *pchEmailAccount, uint64_t gidGuestPassID, bool bResending)
    {
        Printfunction();
        return false;
    }
    bool SendGuestPassByAccountID(uint32_t uAccountID, uint64_t gidGuestPassID, bool bResending)
    {
        Printfunction();
        return false;
    }
    bool AckGuestPass(const char *pchGuestPassCode)
    {
        Printfunction();
        return false;
    }
    bool RedeemGuestPass(const char *pchGuestPassCode)
    {
        Printfunction();
        return false;
    }
    uint32_t GetGuestPassToGiveCount()
    {
        Printfunction();
        return 0;
    }
    uint32_t GetGuestPassToRedeemCount()
    {
        Printfunction();
        return 0;
    }
    uint32_t GetGuestPassLastUpdateTime()
    {
        Printfunction();
        return 0;
    }
    bool GetGuestPassToGiveInfo(uint32_t nPassIndex, uint64_t *pgidGuestPassID, int* pnPackageID, uint32_t* pRTime32Created, uint32_t* pRTime32Expiration, uint32_t* pRTime32Sent, uint32_t* pRTime32Redeemed, char * pchRecipientAddress, int cRecipientAddressSize)
    {
        Printfunction();
        return false;
    }
    bool GetGuestPassToRedeemInfo(uint32_t nPassIndex, uint64_t *pgidGuestPassID, int* pnPackageID, uint32_t* pRTime32Created, uint32_t* pRTime32Expiration, uint32_t* pRTime32Sent, uint32_t* pRTime32Redeemed)
    {
        Printfunction();
        return false;
    }
    bool GetGuestPassToRedeemSenderAddress(uint32_t nPassIndex, char* pchSenderAddress, int cSenderAddressSize)
    {
        Printfunction();
        return false;
    }
    bool GetGuestPassToRedeemSenderName(uint32_t nPassIndex, char* pchSenderName, int cSenderNameSize)
    {
        Printfunction();
        return false;
    }
    void AcknowledgeMessageByGID(const char *pchMessageGID)
    {
        Printfunction();
    }
    bool SetLanguage(const char *pchLanguage)
    {
        Printfunction();
        return !!std::strcpy(Steamconfig::Language, pchLanguage);
    }
    void TrackAppUsageEvent0(CGameID gameID, uint32_t eAppUsageEvent, const char *pchExtraInfo = "")
    {
        Printfunction();
    }
    void SetAccountName(const char* pchAccountName)
    {
        Printfunction();
    }
    void SetPassword(const char* pchPassword)
    {
        Printfunction();
    }
    void SetAccountCreationTime(uint32_t rtime32Time)
    {
        Printfunction();
    }
    int InitiateGameConnection2(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID nGameAppID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure, void *pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey)
    {
        Printfunction();
        return 0;
    }
    void RefreshSteam2Login()
    {
        Printfunction();
    }
    int InitiateGameConnection3(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID gameID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure, void *pvSteam2GetEncryptionKey, int cbSteam2GetEncryptionKey)
    {
        Printfunction();
        return 0;
    }
    int InitiateGameConnection4(void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID gameID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        Printfunction();
        return 0;
    }
    int InitiateGameConnection5(void *pBlob, int cbMaxBlob, CSteamID steamID, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        Printfunction();
        return 0;
    }
    int InitiateGameConnection6(void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32_t unIPServer, uint16_t usPortServer, bool bSecure)
    {
        Printfunction();
        return 0;
    }
    bool GetUserDataFolder(char *pchBuffer, int cubBuffer)
    {
        Printfunction();
        return false;
    }
    void StartVoiceRecording()
    {
        Printfunction();
    }
    void StopVoiceRecording()
    {
        Printfunction();
    }
    uint32_t GetCompressedVoice(void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten)
    {
        Printfunction();
        return 0;
    }
    uint32_t DecompressVoice0(void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetAuthSessionTicket(void *pTicket, int cbMaxTicket, uint32_t *pcbTicket)
    {
        Printfunction();

        // k_HAuthTicketInvalid
        return 0;
    }
    uint32_t BeginAuthSession(const void *pAuthTicket, int cbAuthTicket, CSteamID steamID)
    {
        Debugprint(va("%s for 0x%llx", __func__, steamID.ConvertToUint64()));

        return 0;
    }
    void EndAuthSession(CSteamID steamID)
    {
        Printfunction();
    }
    void CancelAuthTicket(uint32_t hAuthTicket)
    {
        Printfunction();
    }
    uint32_t UserHasLicenseForApp(CSteamID steamID, uint32_t appID)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetAvailableVoice0(uint32_t *pcbCompressed, uint32_t *pcbUncompressed)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetVoice0(bool bWantCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32_t cbUncompressedDestBufferSize, uint32_t *nUncompressBytesWritten)
    {
        Printfunction();
        return 0;
    }
    bool BIsBehindNAT()
    {
        Printfunction();
        return false;
    }
    void AdvertiseGame(CSteamID steamIDGameServer, uint32_t unIPServer, uint16_t usPortServer)
    {
        Printfunction();
    }
    uint64_t RequestEncryptedAppTicket(void *pDataToInclude, unsigned int cbDataToInclude)
    {
        // Clear the buffer and fill the ticket part with useful data.
        std::memset(Ticketdata, 0, sizeof(Ticketdata));
        std::memcpy(&Ticketdata[0], &Steamconfig::UserID, 8);
        std::memcpy(&Ticketdata[8], Steamconfig::Username, 16);
        std::memcpy(&Ticketdata[24], "\x00", 1);
        /* NOTE(Convery): 7 bytes unused */

        // Append the extra data.
        std::memcpy(&Ticketdata[32], pDataToInclude, std::min(cbDataToInclude, (unsigned int)sizeof(Ticketdata) - 32));

        // Return the ticket to the game.
        auto RequestID = Steamcallback::Createrequest();
        auto Response = new EncryptedAppTicketResponse_t();

        Response->m_eResult = k_EResultOK;
        Infoprint(va("Creating an \"encrypted\" ticket with %d bytes of gamedata.", cbDataToInclude));
        Steamcallback::Completerequest({ Response, sizeof(*Response), Response->k_iCallback, RequestID });

        return RequestID;
    }
    bool GetEncryptedAppTicket(void *pTicket, unsigned int cbMaxTicket, uint32_t *pcbTicket)
    {
        Printfunction();
        memcpy(pTicket, Ticketdata, std::min(cbMaxTicket, (unsigned int)sizeof(Ticketdata)));
        *pcbTicket = sizeof(Ticketdata);
        return true;
    }
    uint32_t DecompressVoice1(void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t nSamplesPerSec)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetVoiceOptimalSampleRate()
    {
        Printfunction();
        return 0;
    }
    uint32_t GetAvailableVoice1(uint32_t *pcbCompressed, uint32_t *pcbUncompressed, uint32_t nUncompressedVoiceDesiredSampleRate)
    {
        Printfunction();
        return 0;
    }
    uint32_t GetVoice1(bool bWantCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32_t cbUncompressedDestBufferSize, uint32_t *nUncompressBytesWritten, uint32_t nUncompressedVoiceDesiredSampleRate)
    {
        // k_EVoiceResultNoData
        return 3;
    }
    uint32_t DecompressVoice2(const void *pCompressed, uint32_t cbCompressed, void *pDestBuffer, uint32_t cbDestBufferSize, uint32_t *nBytesWritten, uint32_t nDesiredSampleRate)
    {
        Printfunction();
        return 0;
    }
    int GetGameBadgeLevel(int nSeries, bool bFoil)
    {
        Printfunction();
        return 0;
    }
    int GetPlayerSteamLevel()
    {
        Printfunction();
        return 0;
    }
    void TrackAppUsageEvent1(CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "")
    {
        Printfunction();
    }
    uint64_t RequestStoreAuthURL(const char *pchRedirectURL)
    {
        Printfunction();
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
        Createinterface(STEAM_USER, SteamUser001);
        Createinterface(STEAM_USER, SteamUser002);
        Createinterface(STEAM_USER, SteamUser003);
        Createinterface(STEAM_USER, SteamUser004);
        Createinterface(STEAM_USER, SteamUser005);
        Createinterface(STEAM_USER, SteamUser006);
        Createinterface(STEAM_USER, SteamUser007);
        Createinterface(STEAM_USER, SteamUser008);
        Createinterface(STEAM_USER, SteamUser009);
        Createinterface(STEAM_USER, SteamUser010);
        Createinterface(STEAM_USER, SteamUser011);
        Createinterface(STEAM_USER, SteamUser012);
        Createinterface(STEAM_USER, SteamUser013);
        Createinterface(STEAM_USER, SteamUser014);
        Createinterface(STEAM_USER, SteamUser015);
        Createinterface(STEAM_USER, SteamUser016);
        Createinterface(STEAM_USER, SteamUser017);
        Createinterface(STEAM_USER, SteamUser018);
    }
};
static Steamuserloader Interfaceloader{};
