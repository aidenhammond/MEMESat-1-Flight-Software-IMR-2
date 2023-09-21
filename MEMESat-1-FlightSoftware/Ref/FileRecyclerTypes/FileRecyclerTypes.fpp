module Ref {
    @ A file recycler operation
    enum FileRecyclerOp {
      BEFORETIME = 3@< Deletes all files created before specified time
      AFTERTIME = 2@< Deletes all files created after specified time
      NUM = 1@< Deletes specified number of images in order of age, beginning with oldest
      MAX = 0@< Defines the maximum number of images to be kept in storage
    }
    enum CronOp {
      START @< Starts the cronjob
      STOP @< Stops the cronjob
    }

    @ A return status
    enum Status {
      COMPLETED = 0
      FAILED = 1
    }

    struct FauxOsStatus {
      status: string,
      status_message: string,
    }

    #@ Status of a file upon being deleted
    # Make this an array?
    #enum DeleteStatus {
      
  #}
  
}
