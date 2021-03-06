#include <tinyfsm.hpp>

/* Events */

struct ConnectRequested : tinyfsm::Event { };
struct RampToVoltageRequested : tinyfsm::Event { };  // this might carry an location with it
struct RampToCurrentRequested : tinyfsm::Event { };  // this might carry an location with it
struct DisconnectRequested : tinyfsm::Event { };
struct ResetErrorRequested : tinyfsm::Event { };

/* State machine */

class StoplightSM : tinyfsm::Fsm<StoplightSM>
{
    public:
        /* Default reaction for unhandled events */ 
        void react(tinyfsm::Event const &) { };

        /* Event methods */
        virtual void react(ConnectRequested const &);  // why are these constant address pointers?
        virtual void react(RampToVoltageRequested const &);
        virtual void react(RampToCurrentRequested const &);
        virtual void react(DisconnectRequested const &);
        virtual void react(ResetErrorRequested const &);

    protected:
        float voltageLimit;
        float currentLimit;
        float rampTime;

        /* Actions */
        bool Connect();
        void RampToVoltage();
        void RampToCurrent();
        void Disconnect();
    
    // public:
        // float getTimerValue { return timerValue_ms; }

};