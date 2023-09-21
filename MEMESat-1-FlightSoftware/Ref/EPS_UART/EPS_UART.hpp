// ======================================================================
// \title  EPS_UART.hpp
// \author Matthew Santoro
// \brief  hpp file for EPS_UART component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef EPS_UART_HPP
#define EPS_UART_HPP

#include "Ref/EPS_UART/EPS_UARTComponentAc.hpp"
#include <semaphore.h>
#include <vector>
#include <fcntl.h>
#include <pthread.h>

// Need to define the memory footprint of our buffers. This means defining a count of buffers, and how big each is.
// REVISIT **************************
#define NUM_UART_BUFFERS 5 
#define UART_READ_BUFF_SIZE 40

namespace Ref {

  class EPS_UART :
    public EPS_UARTComponentBase
  {

    enum MessageType {
      NOP = 0x00,
      ACK = 0x01,
      ERROR = 0x07,
      RESET = 0x80,

      GET_DATA = 0x02,
      RETURN_DATA = 0x03,
      SET_VALUE = 0x04,
      RESEND = 0x05
    };

    enum SensorData {
      VBATT_VOLTAGE = 0x00,
      VBATT_CURRENT = 0x01,
      CELL_VOLTAGE = 0x02,
      CELL_CURRENT = 0x03,
      BATTERY_TEMP = 0x04,
      HEATER_STATUS = 0x05,
      SOLAR_PANEL_VOLTAGE = 0x06,
      SOLAR_PANEL_CURRENT = 0x07,
      VOLTAGE_5V0 = 0x08,
      CURRENT_5V0 = 0x09,
      VOLTAGE_3V3 = 0x0A,
      CURRENT_3V3 = 0x0B,
      SWITCH_STATE = 0x0C,
      SENSOR_DATA = 0x0D,
      FSM_STATE = 0x0E
    };

    enum States{
      STATE_INIT,
      STATE_IDLE,
      STATE_CRUISE,
      STATE_ERROR,
      STATE_LOW_PWR,
      STATE_STM_CTL
    };

      /**
       * EPS_Packet:
       *   A structure containing the information in the EPS Packet
       */
      struct EPS_Packet {
          uint8_t syncByteHigh;
          uint8_t syncByteLow;
          uint8_t messageType;
          uint8_t messageLength;
          uint8_t* messageData;
          uint8_t messageChecksumHigh;
          uint8_t messageChecksumLow;
      };

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object EPS_UART
      //!
      EPS_UART(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object EPS_UART
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object EPS_UART
      //!
      ~EPS_UART();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      void outsideCommandBuffer_handler(
        const NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer /*!< Buffer containing data*/
      ) override;
      
      //! Handler implementation for serialRecv
      //!
      void serialRecv_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Buffer &serBuffer, /*!< Buffer containing data*/
          Drv::SerialReadStatus &status /*!< Status of read*/
      ) override;
    
    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      uint16_t calcChecksum(uint8_t *buffer, uint8_t length);
      uint16_t calcChecksum(std::vector<U8>);
      void getData(uint8_t*);
      void logTelem(uint8_t*);
      void parseUART(uint8_t* buffer, U32 size);

      //! Preamble
      // This will be called once when the task starts up
      void preamble() override;


      // ----------------------------------------------------------------------
      // Private member variables and telemetry
      // ----------------------------------------------------------------------

      //! Create member variables to store buffers and the data array that those buffers point to
      Fw::Buffer outBuff;
      Fw::Buffer lastBuff;
      std::vector<U8> packetBuff;
      uint8_t packetSize;
      Fw::Buffer m_recvBuffers[NUM_UART_BUFFERS];
      BYTE m_uartBuffers[NUM_UART_BUFFERS][UART_READ_BUFF_SIZE];


    };

} // end namespace Ref

#endif
