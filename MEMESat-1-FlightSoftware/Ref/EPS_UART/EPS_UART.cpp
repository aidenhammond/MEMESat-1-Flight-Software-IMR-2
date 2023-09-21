// ======================================================================
// \title  EPS_UART.cpp
// \author Matthew Santoro
// \brief  cpp file for EPS_UART component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <Ref/EPS_UART/EPS_UART.hpp>
#include <FpConfig.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Logger/Logger.hpp"
#include <iostream>

#include <cstring>
#include <inttypes.h>

namespace Ref
{

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  EPS_UART ::
      EPS_UART(
          const char *const compName) : EPS_UARTComponentBase(compName)
  {
  }

  void EPS_UART ::
      init(
          const NATIVE_INT_TYPE queueDepth,
          const NATIVE_INT_TYPE instance)
  {
    EPS_UARTComponentBase::init(queueDepth, instance);
  }

  // Step 0: The linux serial driver keeps its storage externally. This means that we need to supply it some buffers to
  //         work with. This code will loop through our member variables holding the buffers and send them to the linux
  //         serial driver.  'preamble' is automatically called after the system is constructed, before the system runs
  //         at steady-state. This allows for initialization code that invokes working ports.
  void EPS_UART::preamble()
  {
    for (NATIVE_INT_TYPE buffer = 0; buffer < NUM_UART_BUFFERS; buffer++)
    {
      // Assign the raw data to the buffer. Make sure to include the side of the region assigned.
      this->m_recvBuffers[buffer].setData(this->m_uartBuffers[buffer]);
      this->m_recvBuffers[buffer].setSize(UART_READ_BUFF_SIZE);
      // Invoke the port to send the buffer out.
      this->serialBufferOut_out(0, this->m_recvBuffers[buffer]);
    }
    // this->requestTelemetry();
  }

  EPS_UART ::
      ~EPS_UART()
  {
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  // this method is for sending data to the EPS. what data does the obc have that the eps doesnt

  void EPS_UART::logTelem(uint8_t* data)
  {
    uint8_t type = data[0];
    // //std::cout << "Type: " << (int)type << std::endl;
    int32_t temp = 0;
    I64 tempArray[2];
    bool switchArray[3];
    switch (type)
    {
    case VBATT_VOLTAGE:
      std::memcpy(&temp, &data[1], sizeof(int));
      //std::cout << "VBATT_VOLTAGE: " << temp << std::endl;
      this->tlmWrite_VBATT_VOLTAGE(temp);
      break;
    case VBATT_CURRENT:
      std::memcpy(&temp, &data[1], sizeof(int));
      //std::cout << "VBATT_CURRENT: " << temp << std::endl;
      this->tlmWrite_VBATT_CURRENT(temp);
      break;
    case CELL_VOLTAGE:
      //std::cout << "CELL_VOLTAGE: [";
      for (uint8_t i = 0; i < 2; i++)
      {
        std::memcpy(&tempArray[i], &data[1 + i * sizeof(int32_t)], sizeof(int32_t));
        tempArray[i] = (uint32_t)tempArray[i];
        //std::cout << tempArray[i] << ", ";;
      }
      //std::cout << "]" << std::endl;
      this->tlmWrite_CELL_VOLTAGE(tempArray);
      break;
    case CELL_CURRENT:
    //std::cout << "CELL_CURRENT: [";
      for (uint8_t i = 0; i < 2; i++)
      {
        std::memcpy(&tempArray[i], &data[1 + i * sizeof(int32_t)], sizeof(int32_t));
        tempArray[i] = (uint32_t)tempArray[i];
        //std::cout << tempArray[i] << ", ";;
      }
      //std::cout << "]" << std::endl;
      this->tlmWrite_CELL_CURRENT(tempArray);
      break;
    case BATTERY_TEMP:
      std::memcpy(&temp, &data[1], sizeof(int));
      //std::cout << "BATTERY_TEMP: " << temp << std::endl;
      this->tlmWrite_BATT_TEMP(temp);
      break;
    case HEATER_STATUS:
      std::memcpy(&temp, &data[1], sizeof(bool));
      //std::cout << "HEATER_STATUS: " << temp << std::endl;
      this->tlmWrite_HEATER_STATUS(temp);
      break;
    case SOLAR_PANEL_VOLTAGE:
    //std::cout << "SOLAR_PANEL_VOLTAGE: [";
      for (uint8_t i = 0; i < 2; i++)
      {
        std::memcpy(&tempArray[i], &data[1 + i * sizeof(int)], sizeof(int));
        tempArray[i] = (uint32_t)tempArray[i];
        //std::cout << tempArray[i] << ", ";;
      }
      //std::cout << "]" << std::endl;
      this->tlmWrite_SOLAR_PANEL_VOLTAGE(tempArray);
      break;
    case SOLAR_PANEL_CURRENT:
    //std::cout << "SOLAR_PANEL_CURRENT: [";
      for (uint8_t i = 0; i < 2; i++)
      {
        std::memcpy(&tempArray[i], &data[1 + i * sizeof(int)], sizeof(int));
        tempArray[i] = (uint32_t)tempArray[i];
        //std::cout << tempArray[i] << ", ";;
      }
      //std::cout << "]" << std::endl;
      this->tlmWrite_SOLAR_PANEL_CURRENT(tempArray);
      break;
    case VOLTAGE_5V0:
      std::memcpy(&temp, &data[1], sizeof(int));
      //std::cout << "VOLTAGE_5V0: " << temp << std::endl;
      this->tlmWrite_VOLTAGE_5V0(temp);
      break;
    case CURRENT_5V0:
      std::memcpy(&temp, &data[1], sizeof(int));
      //std::cout << "CURRENT_5V0: " << temp << std::endl;
      this->tlmWrite_CURRENT_5V0(temp);
      break;
    case VOLTAGE_3V3:
      std::memcpy(&temp, &data[1], sizeof(int));
      //std::cout << "VOLTAGE_3V3: " << temp << std::endl;
      this->tlmWrite_VOLTAGE_3V3(temp);
      break;
    case CURRENT_3V3:
      std::memcpy(&temp, &data[1], sizeof(int));
      //std::cout << "CURRENT_3V3: " << temp << std::endl;
      this->tlmWrite_CURRENT_3V3(temp);
      break;
    case SWITCH_STATE:
    //std::cout << "SWITCH_STATE: [";
      for (uint8_t i = 0; i < 3; i++)
      {
        std::memcpy(&switchArray[i], &data[1 + i * sizeof(int)], sizeof(int));
        //std::cout << switchArray[i] << ", ";
      }
      //std::cout << "]" << std::endl;
      this->tlmWrite_SWITCH_STATE(switchArray);
      break;
    default:
      //std::cout << "ERROR: Invalid EPS UART data type" << std::endl;
      break;
    }
  }

  uint16_t EPS_UART::calcChecksum(uint8_t *data, uint8_t length)
  {
    // printf("Check summing data\n\r");
    // printf("Length: %d\n\r", length);

    uint8_t lsb, msb;
    uint16_t checksum = 0;
    for (uint8_t i = 2; i < length - 3; i++)
    {
      lsb = checksum;
      msb = (checksum >> 8) + data[i];
      lsb += msb;
      checksum = ((uint16_t)msb << 8) | (uint16_t)lsb;
    }
    // printf("Checksum 2: %d\n", checksum);
    return checksum;
  }

  uint16_t EPS_UART::calcChecksum(std::vector<U8> buffer)
  {
    // printk("Checksumming data\n");
    // printk("Length: %d\n", length);

    int length = buffer.size();
    uint8_t lsb, msb;
    uint16_t checksum = 0;
    for (uint8_t i = 2; i < length - 3; i++)
    {
      lsb = checksum;
      msb = (checksum >> 8) + buffer[i];
      lsb += msb;
      checksum = ((uint16_t)msb << 8) | (uint16_t)lsb;
    }
    // printk("Checksum 2: %d\n", checksum);
    return checksum;
  }

  void EPS_UART::parseUART(uint8_t* buffer, U32 size)
  {
    // print packet
    // for (U32 i = 0; i < size; i++)
    // {
    //   printf("%02x ", buffer[i]);
    // }
    // printf("\n");

    if (buffer[0] == 0xBE && buffer[1] == 0xEF)
    {
      // check checksum
      uint16_t checksum = calcChecksum(buffer, size);
      uint16_t checksum2 = (buffer[size - 3] << 8) | buffer[size - 2];
      // I think we should send the ack packet earlier 
      if (checksum == checksum2)
      {
        U8 ack_pkt[8] = {0xBE, 0xEF, ACK, 0x00, 0x00, 0x00, 0x00, '\n'};
        uint16_t checksum;
        checksum = calcChecksum(ack_pkt, 1);
        ack_pkt[5] = checksum >> 8;
        ack_pkt[6] = checksum & 0xFF;
        outBuff.set(ack_pkt, 8);
        this->UartWrite_out(0, outBuff);
        /*
         *  NOP         : 0x00
         *
         *  ERROR       : 0x07
         *
         *  RESET       : 0x80
         *
         *
         *
         *  GET_DATA    : 0x02
         *
         *  RETURN_DATA : 0x03
         *
         *  SET_VALUE   : 0x04
         *
         *  RESEND      : 0x05
         *
         */

        /**
         * Packet format
         * sync byte high buff0
         * sync byte low  buff1
         * message type   buff2
         * message length buff3
         * message data * buff4
         * checksum high
         * checksum low
         * 
         */

        switch (buffer[2])
        {
        case NOP:
          this->log_ACTIVITY_HI_EPS_UartMsgIn("NOP");
          break;
        case ACK:
          this->log_ACTIVITY_HI_EPS_UartMsgIn("ACK");
          break;
        case GET_DATA:
          this->log_ACTIVITY_HI_EPS_UartMsgIn("GET DATA");
          // request data from EPS
          // This is asking for data for the eps from the pi. This will mainly be the current state of the fsm
          // getData(packet);
          this->log_ACTIVITY_HI_EPS_UartMsgIn("GET DATA");
          getData(buffer + 4);
          break;
        case SET_VALUE:
          this->log_ACTIVITY_HI_EPS_UartMsgIn("SET VALUE");
          logTelem(buffer + 4);
          break;
        case RESEND:
          //std::cout << "RESEND" << std::endl;
          this->log_ACTIVITY_HI_EPS_UartMsgIn("RESEND");
          this->UartWrite_out(0, lastBuff);
          break;
        case RESET:
          //std::cout << "RESET" << std::endl;
          this->log_ACTIVITY_HI_EPS_UartMsgIn("RESET");
          // change fsm state to restart
          // will need to log the stages of the shutdown and add a timeout on eps for a hard shutdown
          break;
        default:
          //std::cout << "ERROR" << std::endl;
          this->log_ACTIVITY_HI_EPS_UartMsgIn("ERROR");
          // change fsm state to error
          break;
        }
        this->packetBuff.clear();
        packetSize = 0;
      }
      else
      {
        // checksum is bad
        printf("Checksum is bad\n");
        printf("Bad Checksum: %d\r\n",checksum);
        U8 ack_pkt[8] = {0xBE, 0xEF, RESEND, 0x00, 0x00, 0x00, 0x00, '\n'};
        uint16_t checksum;
        checksum = calcChecksum(ack_pkt, 1);
        ack_pkt[5] = checksum >> 8;
        ack_pkt[6] = checksum & 0xFF;
        outBuff.set(ack_pkt, 8);
        this->UartWrite_out(0, outBuff);
      }
    }
    else
    {
      printf("Packet is bad\r\n");
      // for(int i = 0; i < size; i++){
      //   printf("%d\r\n",buffer[buffer]);
      // }
      U8 ack_pkt[8] = {0xBE, 0xEF, RESEND, 0x00, 0x00, 0x00, 0x00, '\n'};
      uint16_t checksum;
      checksum = calcChecksum(ack_pkt, 1);
      ack_pkt[5] = checksum >> 8;
      ack_pkt[6] = checksum & 0xFF;
      outBuff.set(ack_pkt, 8);
      this->UartWrite_out(0, outBuff);
    }
    this->packetBuff.clear();
    packetSize = 0;
  }

  // this method will send requested data to the eps mcu
    // this will mainly be for syncing the fsm states
  void EPS_UART::getData(uint8_t* requested){
    
  }

  void EPS_UART::outsideCommandBuffer_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer /*!< Buffer containing data*/
      ) {
        // send the buffer to the eps
        // how do we catch the ack packet

        //EPS_Packet packet;
        U32 buffer_size = static_cast<U32>(fwBuffer.getSize());
        uint8_t *pointer = reinterpret_cast<uint8_t *>(fwBuffer.getData());

        //fwBuffer.setSize(UART_READ_BUFF_SIZE);
        //this->UartWrite_out(0 fwBuffer);
        //this->serialBufferOut_out(0, fwBuffer);

        uint8_t pkt_len = buffer_size + 5;
        U8 pkt[pkt_len];
        uint16_t checksum;

        pkt[0] = 0xBE;
        pkt[1] = 0xEF;
        pkt[2] = pointer[0];    //message type
        pkt[3] = pointer[1];  //message len
        for(int i = 0; i < buffer_size - 2; i++) {
          pkt[i + 4] = pointer[i + 2];
        }   //message data
        checksum = calcChecksum(pkt, 2 + buffer_size);
        pkt[pkt_len - 2] = checksum >> 8;
        pkt[pkt_len - 1] = checksum & 0xFF;
        pkt[pkt_len] = '\n';

        outBuff.set(pkt, pkt_len);
        this->UartWrite_out(0, outBuff);
      }

  void EPS_UART ::
      serialRecv_handler(
          const NATIVE_INT_TYPE portNum,
          Fw::Buffer &serBuffer,
          Drv::SerialReadStatus &serial_status)
  {
    // Local variable definitions
    int status = 0;
    EPS_Packet packet;

    // Grab the size (used amount of the buffer) and a pointer to the data in the buffer
    U32 buffsize = static_cast<U32>(serBuffer.getSize());
    uint8_t *pointer = reinterpret_cast<uint8_t *>(serBuffer.getData());
    // Check for invalid read status, log an error, return buffer and abort if there is a problem
    if (serial_status != Drv::SerialReadStatus::SER_OK)
    {
      // Fw::Logger::logMsg("[WARNING] Received buffer with bad packet: %s\n", serial_status);
      // We MUST return the buffer or the serial driver won't be able to reuse it. The same buffer send call is used
      // as we did in "preamble".  Since the buffer's size was overwritten to hold the actual data size, we need to
      // reset it to the full data block size before returning it.
      serBuffer.setSize(UART_READ_BUFF_SIZE);
      this->serialBufferOut_out(0, serBuffer);
      return;
    }
    else
    {
      // print packet
      if(buffsize == (pointer[3] + 7)){
        // //std::cout << "Return Buffer" << std::endl;
        serBuffer.setSize(UART_READ_BUFF_SIZE);
        this->serialBufferOut_out(0, serBuffer);

        parseUART(pointer, buffsize);
      } else {
        //Resend
        U8 ack_pkt[8] = {0xBE, 0xEF, RESEND, 0x00, 0x00, 0x00, 0x00, '\n'};
        uint16_t checksum;
        checksum = calcChecksum(ack_pkt, 1);
        ack_pkt[5] = checksum >> 8;
        ack_pkt[6] = checksum & 0xFF;
        outBuff.set(ack_pkt, 8);
        this->UartWrite_out(0, outBuff);
      } // TODO: Attention! Added by Marius because of compile error in EPS_UART on memesat-dev branch!
    }
  }
} // end namespace Ref
