module Ref {

  @ Port for confirm the change in state
  port StateConfirm(
               state: State @< The state of the component
             )
  
  port ChangeState(
                state: State @< The state of the component
              )

  port readyForPowerOff_port(
                result: bool @< The state of the component
              )

}