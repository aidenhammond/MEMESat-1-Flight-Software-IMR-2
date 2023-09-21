module Ref {
    @ State Machine States
    enum State {
        START_UP        @< Start Up Mode
        CRUISE          @< Cruise Mode
        SAFE_ANOM       @< Safe Mode Anomaly
        SAFE_CRIT_PWR   @< Critical Power Mode
        RESTART         @< Restart Mode
        SHUTDOWN        @< Shutdown Mode
    }
}