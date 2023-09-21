# notes to self, use bytearray(struct.pack()) for floats
# use bytes() for ints

import random
from tabnanny import check
import serial
import os, serial, pty
from enum import Enum
import threading
import time
import sys
import getch
import struct

# Define a return command
class MessageType(Enum):
    NOP = 0x00
    ACK = 0x01
    ERROR = 0x07
    RESET = 0x80

    GET_DATA = 0x02
    RETURN_DATA = 0x03
    SET_VALUE = 0x04
    RESEND = 0x05

class SensorData(Enum):
    VBATT_VOLTAGE = 0x00
    VBATT_CURRENT = 0x01
    CELL_VOLTAGE = 0x02
    CELL_CURRENT = 0x03
    BATTERY_TEMP = 0x04
    HEATER_STATUS = 0x05
    SOLAR_PANEL_VOLTAGE = 0x06
    SOLAR_PANEL_CURRENT = 0x07
    VOLTAGE_5V0 = 0x08
    CURRENT_5V0 = 0x09
    VOLTAGE_3V3 = 0x0A
    CURRENT_3V3 = 0x0B
    SWITCH_STATE = 0x0C

class StateMachineState(Enum):
    STATE_INIT = 0x00
    STATE_IDLE = 0x01
    STATE_RUN = 0x02
    STATE_ERROR = 0x03
    STATE_LOW_POWER = 0x04
    STATE_STM_CTL = 0x05

data = {
    SensorData.VBATT_VOLTAGE.value: 0,
    SensorData.VBATT_CURRENT.value: 0,
    SensorData.CELL_VOLTAGE.value: [],
    SensorData.CELL_CURRENT.value: [],
    SensorData.BATTERY_TEMP.value: 0,
    SensorData.HEATER_STATUS.value: 0,
    SensorData.SOLAR_PANEL_VOLTAGE.value: [],
    SensorData.SOLAR_PANEL_CURRENT.value: [],
    SensorData.VOLTAGE_5V0.value: 0,
    SensorData.CURRENT_5V0.value: 0,
    SensorData.VOLTAGE_3V3.value: 0,
    SensorData.CURRENT_3V3.value: 0,
    SensorData.SWITCH_STATE.value: [1,1,1],
}

state = {
    "state": StateMachineState.STATE_INIT,
    "error": 0,
}

ser = None
read = None
write = None

def generate_data():
    while True:
        for key in data:
            if key == SensorData.CELL_VOLTAGE.value or key == SensorData.CELL_CURRENT.value:
                data[key] = [int(8000*random.random()) for i in range(0, 2)]
            elif key == SensorData.SOLAR_PANEL_VOLTAGE.value or key == SensorData.SOLAR_PANEL_CURRENT.value:
                data[key] = [int(8000*random.random()) for i in range(0, 2)]
            elif key == SensorData.SWITCH_STATE.value:
                data[key] = [random.randint(0, 1) for i in range(0, 3)]
            elif key == SensorData.HEATER_STATUS.value:
                data[key] = random.randint(0, 1)
            else:
                data[key] = int(8000*random.random())
        time.sleep(1)

def calc_checksum(msg):
    checksum = 0
    for c in msg[2:]:
        lsb = checksum & 0xFF
        msb = (((checksum >> 8) & 0xFF) + c) & 0xFF
        lsb += msb
        lsb &= 0xFF
        checksum = (msb << 8) | lsb
    # print("New Checksum: ",checksum)
    return checksum

def read_data(val):
    print(str(val)+": ",end="")
    print(data[val])
    pkt = bytes([val])
    if val == SensorData.CELL_VOLTAGE.value or val == SensorData.CELL_CURRENT.value or \
        val == SensorData.SOLAR_PANEL_VOLTAGE.value or val == SensorData.SOLAR_PANEL_CURRENT.value or \
            val == SensorData.SWITCH_STATE.value:
        for i in data[val]:
            pkt += bytes(struct.pack('i', i))
    else:
       pkt += bytes(struct.pack('i', data[val]))
    return pkt

def parse_msg(msg):
    global ser
    msg_checksum = (msg[-3] << 8) | msg[-2]
    # print("msg checksum: {}".format(msg_checksum))
    if calc_checksum(msg[:-3]) != msg_checksum:
        # Send error message
        print("checksum error")
        return 1
    else:
        if msg[2] == MessageType.GET_DATA.value:
            # send the data from the data dict
            pkt = read_data(msg[4])
            msg = bytes([MessageType.SET_VALUE.value, len(pkt)]) + pkt
            msg = bytes([0xBE, 0xEF]) + msg
            send_msg(msg)
            return 0
        elif msg[0] == MessageType.SET_VALUE.value:
            # Set value this is for constants
            return 0
        elif msg[0] == MessageType.RESET.value:
            # Reset, not sure what this means yet
            return 0
        else:
            # Send error message
            msg = bytes([0xBE, 0xEF, MessageType.ERROR.value, 0x00])
            checksum = msg_checksum(msg)
            msg += bytes([checksum >> 8, checksum & 0xFF])
            ser.write(msg)
            return 1

def send_msg(msg):
    global ser
    # print("Send Msg: ", msg,base=16)
    checksum = calc_checksum(msg)
    msg += bytes([checksum >> 8, checksum & 0xFF])
    print("Sent Bytes: {}".format(" ".join('0x{:02x}'.format(n) for n in msg)))
    ser.write(msg)
    # msg = ser.read_until()

def main():
    print ("uart started")
    mode = input("Send or receive? (s/r): ").lower()
    send = True if mode == "s" else False
    global write, ser
    if(send):
        data_gen_thread = threading.Thread(target=generate_data, daemon=True)
        data_gen_thread.start()
    port = "/dev/ttys014"
    ser = serial.Serial(port, 115200)
    print("EPS Spoof on port: " + port)
    state["State"] = StateMachineState.STATE_IDLE
    while send:
        for data in SensorData:
            pkt = read_data(data.value)
            msg = bytes([MessageType.SET_VALUE.value,len(pkt)]) + pkt
            msg = bytes([0xBE, 0xEF]) + msg
            send_msg(msg)
            print ("message sent")
            time.sleep(1)
        time.sleep(5)
    while not send:
        msg = ser.read()
        time.sleep(0.03)
        msg += ser.read(ser.inWaiting())
        if(msg):
            print (''.join('{:02x}'.format(x) for x in msg))

if __name__ == '__main__':
    main()
