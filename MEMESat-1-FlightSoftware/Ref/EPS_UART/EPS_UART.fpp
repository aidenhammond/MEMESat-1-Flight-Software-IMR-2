module Ref {

  @ Component for parsing EPS UART data 
  active component EPS_UART {

    # ----------------------------------------------------------------------
    # Serial ports
    # ----------------------------------------------------------------------

    @ Port for receiving serial data

    async input port serialRecv: Drv.SerialRead

    sync input port outsideCommandBuffer: Fw.BufferSend

    output port serialBufferOut: Fw.BufferSend

    output port UartWrite: Drv.SerialWrite

    output port ChangeState: ChangeState

    # ----------------------------------------------------------------------
    # Special ports
    # ----------------------------------------------------------------------

    # @ Command receive port
    # command recv port cmdIn

    # @ Command registration port
    # command reg port cmdRegOut

    # @ Command response port
    # command resp port cmdResponseOut

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

    # # TODO: Add commands here
    # async command TEST_COMMAND(
    #                        val1: F32 @< The first operand
    #                        val2: F32 @< The second operand
    #                      )

    # ----------------------------------------------------------------------
    # Events
    # ----------------------------------------------------------------------
    
    # TODO: Add events here
    @ Message received on UART
    event EPS_UartMsgIn(
                        msg: string size 40 @< The message
                      ) \
      severity activity high \
      id 1 \
      format "Received msg {} on UART"

    # ----------------------------------------------------------------------
    # Telemetry
    # ----------------------------------------------------------------------

    @ Number of bytes received on the UART
    telemetry EPS_UartRecvBytes: U32 id 1

    @ Last received UART text message
    telemetry EPS_LastMsg: string size 40 id 2

    # ----------------------------------------------------------------------
    # Health Telemetry
    # ----------------------------------------------------------------------
    telemetry VBATT_VOLTAGE: I64 id 3
    telemetry VBATT_CURRENT: I64 id 4
    telemetry CELL_VOLTAGE: CELL_DATA id 5
    telemetry CELL_CURRENT: CELL_DATA id 6
    telemetry BATT_TEMP: I64 id 7
    telemetry HEATER_STATUS: bool id 8
    telemetry SOLAR_PANEL_VOLTAGE: PANEL_DATA id 9
    telemetry SOLAR_PANEL_CURRENT: PANEL_DATA id 10
    telemetry VOLTAGE_5V0: I64 id 11
    telemetry CURRENT_5V0: I64 id 12
    telemetry VOLTAGE_3V3: I64 id 13
    telemetry CURRENT_3V3: I64 id 14
    telemetry SWITCH_STATE: SWITCH_STATE id 15

  }

}
