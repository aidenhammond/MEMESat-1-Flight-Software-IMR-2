module Ref {
  
  @ Port for requesting the deletion of certain files of a given basis
  port FileRecyclerOpPort(
    count: U32 @< File attribute that determines which files are deleted
    op: FileRecyclerOp
  )
  @ Port for indicating completion
  port FileRecyclerStatusPort(
    result: bool @< Whether or not something was completed successfully
  ) 

  port MemeRecyclerOpPort(
    op: CronOp
  )

}  
