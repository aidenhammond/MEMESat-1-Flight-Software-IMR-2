module Ref {


  port SendSchedulePort(
    name: string @< Name of schedule for libcron task
    schedule: string @< Schedule in libcron format
    action: ScheduleOp
  )
  enum ScheduleOp {
    START
    STOP
  }


  port RunSchedulePort(
    status: ScheduleStatus
  )
  enum ScheduleStatus {
    RUNNING
    STOPPED
    FAILED
  }

}
