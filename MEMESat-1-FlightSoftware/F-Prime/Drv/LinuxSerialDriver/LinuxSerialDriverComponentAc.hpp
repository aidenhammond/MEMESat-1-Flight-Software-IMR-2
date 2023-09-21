// ======================================================================
// \title  LinuxSerialDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for LinuxSerialDriver component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef LINUXSERIALDRIVER_COMP_HPP_
#define LINUXSERIALDRIVER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Drv/SerialDriverPorts/SerialReadPortAc.hpp>
#include <Drv/SerialDriverPorts/SerialWritePortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>

namespace Drv {

  //! \class LinuxSerialDriverComponentBase
  //! \brief Auto-generated base for LinuxSerialDriver component
  //!
  class LinuxSerialDriverComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class LinuxSerialDriverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return readBufferSend[portNum]
    //!
    Fw::InputBufferSendPort* get_readBufferSend_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return serialSend[portNum]
    //!
    Drv::InputSerialWritePort* get_serialSend_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

    //! Connect port to serialRecv[portNum]
    //!
    void set_serialRecv_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Drv::InputSerialReadPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to serialRecv[portNum]
    //!
    void set_serialRecv_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a LinuxSerialDriverComponentBase object
    //!
    LinuxSerialDriverComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a LinuxSerialDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a LinuxSerialDriverComponentBase object
    //!
    virtual ~LinuxSerialDriverComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port readBufferSend
    //
    virtual void readBufferSend_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

    //! Handler for input port serialSend
    //
    virtual void serialSend_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &serBuffer 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port readBufferSend
    //!
    void readBufferSend_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Handler base-class function for input port serialSend
    //!
    void serialSend_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &serBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port serialRecv
    //!
    void serialRecv_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &serBuffer, /*!< 
      Buffer containing data
      */
        Drv::SerialReadStatus &status /*!< 
      Status of read
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of readBufferSend input ports
    //!
    //! \return The number of readBufferSend input ports
    //!
    NATIVE_INT_TYPE getNum_readBufferSend_InputPorts();

    //! Get the number of serialSend input ports
    //!
    //! \return The number of serialSend input ports
    //!
    NATIVE_INT_TYPE getNum_serialSend_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_READBUFFERSEND_INPUT_PORTS = 1,
       NUM_SERIALSEND_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of Log output ports
    //!
    //! \return The number of Log output ports
    //!
    NATIVE_INT_TYPE getNum_Log_OutputPorts();

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts();
#endif

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts();

    //! Get the number of Tlm output ports
    //!
    //! \return The number of Tlm output ports
    //!
    NATIVE_INT_TYPE getNum_Tlm_OutputPorts();

    //! Get the number of serialRecv output ports
    //!
    //! \return The number of serialRecv output ports
    //!
    NATIVE_INT_TYPE getNum_serialRecv_OutputPorts();


    enum {
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
       NUM_SERIALRECV_OUTPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port Log is connected
    //!
    //! \return Whether port Log is connected
    //!
    bool isConnected_Log_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Tlm is connected
    //!
    //! \return Whether port Tlm is connected
    //!
    bool isConnected_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port serialRecv is connected
    //!
    //! \return Whether port serialRecv is connected
    //!
    bool isConnected_serialRecv_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_DR_OPENERROR = 0x0, /* UART open error */
      EVENTID_DR_CONFIGERROR = 0x1, /* UART config error */
      EVENTID_DR_WRITEERROR = 0x2, /* UART write error */
      EVENTID_DR_READERROR = 0x3, /* UART read error */
      EVENTID_DR_PORTOPENED = 0x4, /* UART port opened event */
      EVENTID_DR_NOBUFFERS = 0x5, /* UART ran out of buffers */
      EVENTID_DR_BUFFERTOOSMALL = 0x6, /* UART ran out of buffers */
    };

    // ----------------------------------------------------------------------
    // Event Throttle values - sets initial value of countdown variable
    // ----------------------------------------------------------------------

    enum {
      EVENTID_DR_WRITEERROR_THROTTLE = 5, /*!< Throttle reset count for DR_WriteError*/
      EVENTID_DR_READERROR_THROTTLE = 5, /*!< Throttle reset count for DR_ReadError*/
      EVENTID_DR_NOBUFFERS_THROTTLE = 20, /*!< Throttle reset count for DR_NoBuffers*/
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event DR_OpenError
    //!
    /* UART open error */
    void log_WARNING_HI_DR_OpenError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error, /*!< The error code*/
        const Fw::LogStringArg& name /*!< error string*/
    );


    //! Log event DR_ConfigError
    //!
    /* UART config error */
    void log_WARNING_HI_DR_ConfigError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error /*!< The error code*/
    );


    //! Log event DR_WriteError
    //!
    /* UART write error */
    void log_WARNING_HI_DR_WriteError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error /*!< The error code*/
    );

    // reset throttle value for DR_WriteError
    void log_WARNING_HI_DR_WriteError_ThrottleClear();

    //! Log event DR_ReadError
    //!
    /* UART read error */
    void log_WARNING_HI_DR_ReadError(
        const Fw::LogStringArg& device, /*!< The device*/
        I32 error /*!< The error code*/
    );

    // reset throttle value for DR_ReadError
    void log_WARNING_HI_DR_ReadError_ThrottleClear();

    //! Log event DR_PortOpened
    //!
    /* UART port opened event */
    void log_ACTIVITY_HI_DR_PortOpened(
        const Fw::LogStringArg& device /*!< The device*/
    );


    //! Log event DR_NoBuffers
    //!
    /* UART ran out of buffers */
    void log_WARNING_HI_DR_NoBuffers(
        const Fw::LogStringArg& device /*!< The device*/
    );

    // reset throttle value for DR_NoBuffers
    void log_WARNING_HI_DR_NoBuffers_ThrottleClear();

    //! Log event DR_BufferTooSmall
    //!
    /* UART ran out of buffers */
    void log_WARNING_HI_DR_BufferTooSmall(
        const Fw::LogStringArg& device, /*!< The device*/
        U32 size, /*!< The provided buffer size*/
        U32 needed /*!< The buffer size needed*/
    );


  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_DR_BYTESSENT = 0x0, //!< Channel ID for DR_BytesSent
      CHANNELID_DR_BYTESRECV = 0x1, //!< Channel ID for DR_BytesRecv
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel DR_BytesSent
    //!
    /* Bytes Sent */
    void tlmWrite_DR_BytesSent(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

    //! Write telemetry channel DR_BytesRecv
    //!
    /* Bytes Received */
    void tlmWrite_DR_BytesRecv(
        U32 arg /*!< The telemetry value*/,
        Fw::Time _tlmTime=Fw::Time() /*!< Timestamp. Default: unspecified, request from getTime port*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //! Get the time
    //!
    //! \return The current time
    //!
    Fw::Time getTime();



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port readBufferSend
    //!
    Fw::InputBufferSendPort m_readBufferSend_InputPort[NUM_READBUFFERSEND_INPUT_PORTS];

    //! Input port serialSend
    //!
    Drv::InputSerialWritePort m_serialSend_InputPort[NUM_SERIALSEND_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

    //! Output port serialRecv
    //!
    Drv::OutputSerialReadPort m_serialRecv_OutputPort[NUM_SERIALRECV_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port readBufferSend
    //!
    static void m_p_readBufferSend_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Callback for port serialSend
    //!
    static void m_p_serialSend_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &serBuffer 
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------
    NATIVE_UINT_TYPE m_DR_WriteErrorThrottle; //!< throttle for DR_WriteError
    NATIVE_UINT_TYPE m_DR_ReadErrorThrottle; //!< throttle for DR_ReadError
    NATIVE_UINT_TYPE m_DR_NoBuffersThrottle; //!< throttle for DR_NoBuffers

  };

} // end namespace Drv
#endif
