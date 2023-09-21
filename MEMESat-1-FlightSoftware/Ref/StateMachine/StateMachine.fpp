module Ref {

  @ Component for sending a math operation
  active component StateMachine {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    async input port Run: Svc.Sched

    async input port ChangeState: ChangeState

    output port epsbuffer: Fw.BufferSend

    output port readyForPowerOff: readyForPowerOff_port

    output port epsCommand: Fw.BufferSend
    # ----------------------------------------------------------------------
    # Special ports
    # ----------------------------------------------------------------------

    @ Command receive port
    command recv port cmdIn

    @ Command registration port
    command reg port cmdRegOut

    @ Command response port
    command resp port cmdResponseOut

    @ Event port
    event port eventOut

    @ Telemetry port
    telemetry port tlmOut

    @ Text event port
    text event port textEventOut

    @ Time get port
    time get port timeGetOut

    # ----------------------------------------------------------------------
    # Commands
    # ----------------------------------------------------------------------
    @ Command from Ground Station to change state
    async command CHANGE_STATE(
        state: State @< State to change to from Ground Station
    )


    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    event STATE_CHANGE(
        state: State @< State to change to
    )\
    severity activity high \
    id 0 \
    format "State Change to {}"

    @ Attempt to autoswitch to Cruise
    event AUTO_SWITCH_TO_CRUISE(
    )\
    severity warning high \
    id 1 \
    format "Attempt to autoswitch to Cruise"

    event SHUTDOWN(
    ) \
    severity activity high \
    id 2\
    format "Shutdown"

    event RESTART(
    ) \
    severity activity high \
    id 3\
    format "Restart"
    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------

    @ The first value
    telemetry STATE: State id 0 update on change format "Current State: {}"
    telemetry RESTART_COUNT: U32 id 1 update on change format "Restart Count: {}"
    telemetry SHUTDOWN_COUNT: U32 id 2 update on change format "Shutdown Count: {}"

  }

}
