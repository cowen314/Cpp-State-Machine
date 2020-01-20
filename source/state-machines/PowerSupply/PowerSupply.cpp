#include <tinyfsm.h>
#include "PowerSupply.h"

class PowerSupply
{

    /* Default event handling */

    PowerSupply::react(ConnectionRequested const &) { };
    PowerSupply::react(DisconnectRequested const &) { };
    PowerSupply::react(RampToCurrentRequested const &) { };
    PowerSupply::react(RampToVoltageRequested const &) { };

    /* Action implementations */
    
    void Connect()
    {
        // TODO
    }
    
    // TODO

}


/* Stateful event handling*/

class Disconnected : public PowerSupply
{
    void ConnectRequested()
    {
        // TODO attempt to establish connection
        Connect();  // this will just call the parent implementation, right?
        bool success = true;
        if (success == true)
            transit<>();

    }

    void
}