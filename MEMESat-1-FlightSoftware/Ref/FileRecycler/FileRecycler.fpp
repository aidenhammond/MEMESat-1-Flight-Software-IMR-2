module Ref {
  
  @ Component for sending a math operation
  active component FileRecycler {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    @ Port for recieving the operation request
    async input port fileRecyclerOpIn: FileRecyclerOpPort

    @ Internal port
    output port toFileRecyclerHandler: FileRecyclerOpPort

    sync input port readyForPowerOff: FileRecyclerStatusPort

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
    param get port prmGetOut

    @ Parameter set
    param set port prmSetOut

    # ----------------------------------------------------------------------
    # Parameters
    # ----------------------------------------------------------------------

    param MAX_FILES: U32 default 1000 id 0 \
      set opcode 0x0A00 \
      save opcode 0x0A01  

    param SCHEDULE: string default "0 * * * * ?" id 1 \
      set opcode 0x0A02 \
      save opcode 0x0A03

    param SYS_RESET: U8 default 0 id 2 \
      set opcode 0x0A04 \
      save opcode 0x0A05

    #param SCHEDULE_MODE: FileRecyclerOp default MAX id 2 \
    #  set opcode 0x0A04 \
    #  save opcode 0x0A05

    # ----------------------------------------------------------------------
    # Commands
    # ----------------------------------------------------------------------

    @ clean up data 
    sync command CLEAN_UP_DATA (
      count: U32 @< file attribute that determines which files are deleted
      op: FileRecyclerOp
    )

    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    @ File Recycler command received
    event COMMAND_RECV(
      count: U32 @< file attribute that determines which files are deleted
      op: FileRecyclerOp
                      ) \
      severity command \
      format "FileRecycler command received: {d} {}" 

    @ Received math result
    event CLEAN_UP_DATA_COMPLETED (
                  status: Status @< returns the status of completion 
                ) \
      severity diagnostic \
      id 1 \
      format "Status: {}" 

    event SCHEDULE_ERROR (
        status: ScheduleStatus
      ) \
      severity warning low \
      id 2 \
      format "FileRecycler scheduledHandler failed with status {}"

    event SCHEDULE_RAN () \
      severity diagnostic \
      id 3 \
      format "FileRecycler scheduledHandler Ran"

    event SCHEDULE_CHANGED_TO(
      schedule: string     
      ) \
      severity diagnostic \
      id 4 \
      format "Schedule changed to {}"

    # Need to add status
    @ Downlinks the name of removed file
    event FILE_REMOVE (
                  year: U16
                  month: string
                  day: U8
                  hour: U8
                  minute: U8
                  second: U8
                  name: string
                  status: string
                  message: string
                ) \
      severity diagnostic \
      id 5 \
      format "[{} {} {} {}:{}:{}]: File ({}) removed with status {} and status message {}"

    @ Not currently being used
    event NUM_FILES_UPDATED (
                  num: U32
                ) \
      severity diagnostic \
      id 6 \
      format "Number of files to keep updated to {}"

    event CANNOT_OPEN_DIR (
                  name: string 
                ) \
      severity warning high \
      id 7 \
      format "Failed opening directory {}"

    event RECYCLER_STOPPED_BY_SYS_RESET () \
      severity warning low \
      id 8 \
      format "Recycler was stopped by being set for system reset"

    event STAT_ERROR (
                  error_number: U32
                  error_name: string
                  message: string
                ) \
      severity warning low \
      id 9 \
      format "Stat object returned non-zero value {} ({}) on file read. Message: {}"
    event UNEXPECTED_DIRECTORY_STATUS (
                  status: FauxOsStatus
                ) \
      severity warning low \
      id 10 \
      format "The OS::Directory::Status returned {} from reading the storage directory is different than expected." 

    #event DELETE_EVENT_FAILED {
    #              name: string
    #              stat_time: string
    #              delete_status: Status
    #              op: FileRecyclerOp
    #            } \
    #  severity warning low \
    #  id 8 \
    #  format "File {} with recorded creation time {} has a deletion status of {} from op {}"
      
    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------

    @ The operation
    # telemetry OP: FileRecyclerOp
    telemetry MAX_FILES: U32 id 0 update on change format "Max number of files {}"
    telemetry NUM_FILES_REMOVED: U32 id 1 format "Number of files: {}"
    telemetry RECYCLER_TYPE: FileRecyclerOp id 2 format "FileRecycler ran with op {}"
    telemetry CLEAN_UP_DATA_COMPLETED: Status id 3 update on change format "Clean up data completed: {}"
    #telemetry DELETE_STATUS: Status id 4 format "Deletion of file was {}"
  }

}
