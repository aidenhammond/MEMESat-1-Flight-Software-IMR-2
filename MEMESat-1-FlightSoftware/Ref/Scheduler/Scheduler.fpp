module Ref {

  @ Component for sending a math operation
  active component Scheduler {

    constant initNumConnections = 2
    array schedulerStatusArray = [initNumConnections] ScheduleStatus
    array schedulerScheduleArray = [initNumConnections] string
    array schedulerNameArray = [initNumConnections] string

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    @ Port for recieving the operation request

    output port DownlinkCurrentSchedules: Svc.SendFileRequest

    output port runSchedule: [initNumConnections] Ref.RunSchedulePort
    async input port getSchedule: [initNumConnections] Ref.SendSchedulePort priority 10 block @< If this works, it will log task_running (activity low) twice, once for before any changes to the schedule were made, andonce after
    match getSchedule with runSchedule

    @ The rate group scheduler input
    sync input port tick: Svc.Sched 

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

    @ Downlinks file containing a list of the current schedules 
    async command GET_SCHEDULE_LIST (
       destFileName: string size 100 @< Path to store downlinked schedule list at
    )
    
    sync command STOP_SCHEDULE (
       name: string size 15 @< Name of schedule to stop
    )

    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    @ Getting Schedule List (NEEDS TO BE IMPLEMENTED)
    event GETTING_LIST(
                      ) \
      severity diagnostic \
      format "getting schedule list..." 
  
    @ Get Schedule Port Number Invoked Incorrectly
    event WARN_PORT_NUM_GET_SCHEDULE_HANDLER(
        portNum: U8
      ) \
      severity warning low \
      format "Port number {} passed to getSchedule_handler is incorrect. Invoker schedule unchanged."

    @ Warns ground station if name string is empty
    event NAME_STRING_EMPTY(
        portNum: U8
      ) \
      severity warning low \
      format "Name string passed to port {} for getSchedule is empty"

    @ Warns ground station if schedule is incorrect
    event SCHEDULE_INCORRECT(
        schedule: string
        portNum: U8
        name: string
        status: ScheduleStatus
      ) \
      severity warning low \
      format "Schedule {} passed to port {} ({}) for getSchedule is formatted incorrectly. Schedule is {}"

    event TASK_RUNNING(
        name: string
        status: ScheduleStatus
      ) \
      severity activity low \
      format "The status of schedule {} is {}"

    event DOWNLINKED_SCHEDULE(
        destination_file: string
      ) \
      severity diagnostic \
      format "The list of schedules was downlinked to destination file {}"

    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------

    # Scheduler Telemetry
    @ Status of the FileRecycler schedule 
    telemetry FILE_RECYCLER_PORT_STATUS : ScheduleStatus id 0 update on change

    @ Status of the TlmChan schedule 
    telemetry TLM_CHAN_PORT_STATUS : ScheduleStatus id 1 update on change 
  }
}
