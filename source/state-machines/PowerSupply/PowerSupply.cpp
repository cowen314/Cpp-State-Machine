#include <tinyfsm.h>
#include "PowerSupply.h"

class PowerSupply : public tinyfsm::Fsm<PowerSupply>
{

    /* Default event handling */

    PowerSupply::react(ConnectRequested const &) { };
    PowerSupply::react(DisconnectRequested const &) { };
    PowerSupply::react(RampToCurrentRequested const &) { };
    PowerSupply::react(RampToVoltageRequested const &) { };
    PowerSupply::react(ResetErrorRequested const &) { };
    // TODO add an event that requires the use of multiple actions, to demonstrate how actions are different from events

    /* Action (reusable function) implementations */

    protected:
    bool Connect()  // return True if connection succeeds, False otherwise 
    {
        // TODO
    }
    
    void RampToCurrent()
    {
        // TODO
    }

    void RampToVoltage()
    {
        // TODO
    }

    void Disconnect()
    {
        // TODO
    }

}


/* Stateful event handling*/

class Disconnected : public PowerSupply
{
    void react(ConnectRequested const & e) override
    {
        bool success = PowerSupply::Connect();
        if (success == true)
            transit<Connected>();
    }
}


class Connected : public PowerSupply
{
    void react(DisconnectRequested const & e) override
    {
        PowerSupply::Disconnect();
        transit<Disconnected>();
    }

    void react(RampToCurrentRequested const & e) override
    {
        /*
        there are a couple ways this might be implemented, can't decide on the best one
        - you could transition to ramping, ramp to current, and transition back to connected all right here
        - alternatively, you could transition to ramping, which would call an on-enter action that ramps the current, then fires some event to bring us back to the connected state
        */
        transit<Ramping>();
        PowerSupply::RampToCurrent();
        transit<Connected>();
    }

    void react(RampToVoltageRequested const & e) override
    {       
        transit<Ramping>();
        PowerSupply::RampToVoltage();
        transit<Connected>();
    }
}


class Ramping : public PowerSupply
{
    void react(DisconnectRequested const & e) override
    {
        PowerSupply::Disconnect();
        transit<Disconnected>();
    }
}

class Error : public PowerSupply
{
    void react(ResetErrorRequested const & e) override
    {
        transit<Disconnected>();
    }
}