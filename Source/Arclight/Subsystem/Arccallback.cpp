/*
    Initial author: Convery (tcn@hedgehogscience.com)
    Started: 03-02-2018
    License: MIT
    Notes:
        Arc callbacks for async requests.
*/

#include "../../Stdinclude.hpp"

namespace Arccallback
{
    std::list<PWCallback *> Callbackhandlers;

    // Add a games callback to the internal mapping.
    void Registercallback(PWCallback *Callbackhandler, int32_t CallbackID)
    {
        Debugprint(va("Registering callback \"%s\".", Callbackname(CallbackID).c_str()));

        Callbackhandler->CallbackID = CallbackID;
        Callbackhandlers.push_back(Callbackhandler);
    }

    // Remove a games callback from the internal mapping.
    void Removecallback(PWCallback *Callbackhandler)
    {
        for (auto Iterator = Callbackhandlers.begin(); Iterator != Callbackhandlers.end(); ++Iterator)
        {
            if (*Iterator == Callbackhandler)
            {
                Debugprint(va("Removing callback \"%s\".", Callbackname(Callbackhandler->CallbackID).c_str()));
                Callbackhandlers.erase(Iterator);
                break;
            }
        }
    }

    // Call all callbacks, usually every frame.
    void Runcallbacks()
    {

    }

    // Debug information.
    void Buildnamemap();
    std::unordered_map<int32_t, std::string> Callbacknames;
    std::string Callbackname(int32_t CallbackID)
    {
        static bool Initialized = false;
        if(!Initialized) Buildnamemap();
        Initialized = true;

        #if defined (ARC_PRINTCALLBACKS)
        return Callbacknames[CallbackID];
        #else
        return va("%d", CallbackID);
        #endif
    }

    void Buildnamemap()
    {
        // Set the first entry for legacy functionality.
        Callbacknames[0] = "";

        #if defined (ARC_PRINTCALLBACKS)
        Callbacknames[102] = "LobbyEnter_t";
        Callbacknames[103] = "LobbyDataUpdate_t";
        Callbacknames[104] = "LobbyChatUpdate_t";
        Callbacknames[106] = "LobbyMatchList_t";
        Callbacknames[107] = "LobbyCreated_t";

        Callbacknames[202] = "P2PSessionRequest_t";
        Callbacknames[203] = "P2PSessionConnectFail_t";

        Callbacknames[301] = "GameInvite_t";
        Callbacknames[302] = "FriendsStatus_t";

        Callbacknames[401] = "P2PSessionRequest_t";
        #endif
    }
}

