module Ref {

  @ Component for sending a math operation
  active component Rtc {

    # ----------------------------------------------------------------------
    # General ports
    # ----------------------------------------------------------------------

    @ Port for recieving the operation request
    #async input port RtcIn: RtcOp 
    async input port removeCronSchedIn: RemoveCronJobOp
    output port schedOut: Svc.SendFileRequest

    @ The rate group scheduler input
    sync input port schedIn: Svc.Sched 

    # ----------------------------------------------------------------------
    # Special ports
    # ----------------------------------------------------------------------

    @ Command receive port
    command recv port cmdIn

    @ Command registration port
    command reg port cmdRegOut

   # @ Parameter get
    #param get port prmGetOut

    #@ Parameter get
    #param set port prmSetOut

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
    # Parameters
    # ----------------------------------------------------------------------
 
#    param SCHEDULES: string default "" id 0x59 \
 #     set opcode 13 \
  #    save opcode 14
 
    # ----------------------------------------------------------------------
    # Commands
    # ----------------------------------------------------------------------

    #@ clean up data 
    sync command GET_SCHEDULE_LIST (
       destFileName: string size 100 @< Path to store downlinked schedule list at
    )
    sync command REMOVE_SCHED (
       name: string
    )
    sync command CHANGE_SCHED_FREQ (
       name: string
       new_sched: string
    )
    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------

    @ File Recycler command received
    event COMMAND_RECV(
                      ) \
      severity activity low \
      format "getting schedule list..." 

  }

}
