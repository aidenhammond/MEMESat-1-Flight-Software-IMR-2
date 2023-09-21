module Ref {

  @ Component for sending a math operation
  active component TlmChanWrapper {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------
    
    output port tlmChanOut: Svc.Sched

    # Schedule Ports
    output port sendSchedule: Ref.SendSchedulePort
    async input port scheduledHandler: Ref.RunSchedulePort

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

    @ Parameter get
    param get port paramGet

    @ Parameter set
    param set port paramSet

    # ----------------------------------------------------------------------
    # Parameters
    # ----------------------------------------------------------------------

    param SCHEDULE: string default "0 * * * * ?" id 1 \
      set opcode 0x0002 \
      save opcode 0x0003

    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    event SCHEDULE_ERROR(
        status: ScheduleStatus
      ) \
      severity warning low \
      id 3 \
      format "TlmChanWrapper scheduleHandler failed with status {}"

    event SCHEDULE_CHANGED_TO(
      schedule: string     
      ) \
      severity activity low \
      id 4 \
      format "Schedule changed to {}"

    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------

    @ Telemetry for the status of the last schedule change operation
    @ performed on the TlmChanWrapper
    telemetry StatusOfSchedule: ScheduleStatus id 0x10 \
        format "{}"
    

  }
}
