// ======================================================================
// \title  GroundInterfaceComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for GroundInterface component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef GROUNDINTERFACE_COMP_HPP_
#define GROUNDINTERFACE_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>
#include <Fw/Com/ComPortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>

namespace Svc {

  //! \class GroundInterfaceComponentBase
  //! \brief Auto-generated base for GroundInterface component
  //!
  class GroundInterfaceComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class GroundInterfaceComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return downlinkPort[portNum]
    //!
    Fw::InputComPort* get_downlinkPort_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return fileDownlinkBufferSendIn[portNum]
    //!
    Fw::InputBufferSendPort* get_fileDownlinkBufferSendIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return readCallback[portNum]
    //!
    Fw::InputBufferSendPort* get_readCallback_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return schedIn[portNum]
    //!
    Svc::InputSchedPort* get_schedIn_InputPort(
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

    //! Connect port to fileDownlinkBufferSendOut[portNum]
    //!
    void set_fileDownlinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to fileUplinkBufferGet[portNum]
    //!
    void set_fileUplinkBufferGet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferGetPort *port /*!< The port*/
    );

    //! Connect port to fileUplinkBufferSendOut[portNum]
    //!
    void set_fileUplinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to readPoll[portNum]
    //!
    void set_readPoll_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to uplinkPort[portNum]
    //!
    void set_uplinkPort_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputComPort *port /*!< The port*/
    );

    //! Connect port to write[portNum]
    //!
    void set_write_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
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

    //! Connect port to fileDownlinkBufferSendOut[portNum]
    //!
    void set_fileDownlinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to fileUplinkBufferGet[portNum]
    //!
    void set_fileUplinkBufferGet_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to fileUplinkBufferSendOut[portNum]
    //!
    void set_fileUplinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to readPoll[portNum]
    //!
    void set_readPoll_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to uplinkPort[portNum]
    //!
    void set_uplinkPort_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to write[portNum]
    //!
    void set_write_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a GroundInterfaceComponentBase object
    //!
    GroundInterfaceComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a GroundInterfaceComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a GroundInterfaceComponentBase object
    //!
    virtual ~GroundInterfaceComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    //! Mutex operations for guarded ports.
    // ----------------------------------------------------------------------
    //! You can override these operations to provide more sophisticated
    //! synchronization.
    // ----------------------------------------------------------------------

    //! Lock the guarded mutex
    //!
    virtual void lock();

    //! Unlock the guarded mutex
    //!
    virtual void unLock();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port downlinkPort
    //
    virtual void downlinkPort_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    ) = 0;

    //! Handler for input port fileDownlinkBufferSendIn
    //
    virtual void fileDownlinkBufferSendIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

    //! Handler for input port readCallback
    //
    virtual void readCallback_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

    //! Handler for input port schedIn
    //
    virtual void schedIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port downlinkPort
    //!
    void downlinkPort_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Handler base-class function for input port fileDownlinkBufferSendIn
    //!
    void fileDownlinkBufferSendIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Handler base-class function for input port readCallback
    //!
    void readCallback_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Handler base-class function for input port schedIn
    //!
    void schedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port fileDownlinkBufferSendOut
    //!
    void fileDownlinkBufferSendOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port fileUplinkBufferGet
    //!
    Fw::Buffer fileUplinkBufferGet_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

    //! Invoke output port fileUplinkBufferSendOut
    //!
    void fileUplinkBufferSendOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port readPoll
    //!
    void readPoll_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port uplinkPort
    //!
    void uplinkPort_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Invoke output port write
    //!
    void write_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of downlinkPort input ports
    //!
    //! \return The number of downlinkPort input ports
    //!
    NATIVE_INT_TYPE getNum_downlinkPort_InputPorts();

    //! Get the number of fileDownlinkBufferSendIn input ports
    //!
    //! \return The number of fileDownlinkBufferSendIn input ports
    //!
    NATIVE_INT_TYPE getNum_fileDownlinkBufferSendIn_InputPorts();

    //! Get the number of readCallback input ports
    //!
    //! \return The number of readCallback input ports
    //!
    NATIVE_INT_TYPE getNum_readCallback_InputPorts();

    //! Get the number of schedIn input ports
    //!
    //! \return The number of schedIn input ports
    //!
    NATIVE_INT_TYPE getNum_schedIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_DOWNLINKPORT_INPUT_PORTS = 1,
       NUM_FILEDOWNLINKBUFFERSENDIN_INPUT_PORTS = 1,
       NUM_READCALLBACK_INPUT_PORTS = 1,
       NUM_SCHEDIN_INPUT_PORTS = 1,
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

    //! Get the number of fileDownlinkBufferSendOut output ports
    //!
    //! \return The number of fileDownlinkBufferSendOut output ports
    //!
    NATIVE_INT_TYPE getNum_fileDownlinkBufferSendOut_OutputPorts();

    //! Get the number of fileUplinkBufferGet output ports
    //!
    //! \return The number of fileUplinkBufferGet output ports
    //!
    NATIVE_INT_TYPE getNum_fileUplinkBufferGet_OutputPorts();

    //! Get the number of fileUplinkBufferSendOut output ports
    //!
    //! \return The number of fileUplinkBufferSendOut output ports
    //!
    NATIVE_INT_TYPE getNum_fileUplinkBufferSendOut_OutputPorts();

    //! Get the number of readPoll output ports
    //!
    //! \return The number of readPoll output ports
    //!
    NATIVE_INT_TYPE getNum_readPoll_OutputPorts();

    //! Get the number of uplinkPort output ports
    //!
    //! \return The number of uplinkPort output ports
    //!
    NATIVE_INT_TYPE getNum_uplinkPort_OutputPorts();

    //! Get the number of write output ports
    //!
    //! \return The number of write output ports
    //!
    NATIVE_INT_TYPE getNum_write_OutputPorts();


    enum {
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_FILEDOWNLINKBUFFERSENDOUT_OUTPUT_PORTS = 1,
       NUM_FILEUPLINKBUFFERGET_OUTPUT_PORTS = 1,
       NUM_FILEUPLINKBUFFERSENDOUT_OUTPUT_PORTS = 1,
       NUM_READPOLL_OUTPUT_PORTS = 1,
       NUM_UPLINKPORT_OUTPUT_PORTS = 1,
       NUM_WRITE_OUTPUT_PORTS = 1,
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

    //! Check whether port fileDownlinkBufferSendOut is connected
    //!
    //! \return Whether port fileDownlinkBufferSendOut is connected
    //!
    bool isConnected_fileDownlinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port fileUplinkBufferGet is connected
    //!
    //! \return Whether port fileUplinkBufferGet is connected
    //!
    bool isConnected_fileUplinkBufferGet_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port fileUplinkBufferSendOut is connected
    //!
    //! \return Whether port fileUplinkBufferSendOut is connected
    //!
    bool isConnected_fileUplinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port readPoll is connected
    //!
    //! \return Whether port readPoll is connected
    //!
    bool isConnected_readPoll_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port uplinkPort is connected
    //!
    //! \return Whether port uplinkPort is connected
    //!
    bool isConnected_uplinkPort_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port write is connected
    //!
    //! \return Whether port write is connected
    //!
    bool isConnected_write_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_GROUNDINTERFACEERROR = 0x0, /* An error in the ground interface, here to make the UTs happy. */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event GroundInterfaceError
    //!
    /* An error in the ground interface, here to make the UTs happy. */
    void log_WARNING_HI_GroundInterfaceError(

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

    //! Input port downlinkPort
    //!
    Fw::InputComPort m_downlinkPort_InputPort[NUM_DOWNLINKPORT_INPUT_PORTS];

    //! Input port fileDownlinkBufferSendIn
    //!
    Fw::InputBufferSendPort m_fileDownlinkBufferSendIn_InputPort[NUM_FILEDOWNLINKBUFFERSENDIN_INPUT_PORTS];

    //! Input port readCallback
    //!
    Fw::InputBufferSendPort m_readCallback_InputPort[NUM_READCALLBACK_INPUT_PORTS];

    //! Input port schedIn
    //!
    Svc::InputSchedPort m_schedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

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

    //! Output port fileDownlinkBufferSendOut
    //!
    Fw::OutputBufferSendPort m_fileDownlinkBufferSendOut_OutputPort[NUM_FILEDOWNLINKBUFFERSENDOUT_OUTPUT_PORTS];

    //! Output port fileUplinkBufferGet
    //!
    Fw::OutputBufferGetPort m_fileUplinkBufferGet_OutputPort[NUM_FILEUPLINKBUFFERGET_OUTPUT_PORTS];

    //! Output port fileUplinkBufferSendOut
    //!
    Fw::OutputBufferSendPort m_fileUplinkBufferSendOut_OutputPort[NUM_FILEUPLINKBUFFERSENDOUT_OUTPUT_PORTS];

    //! Output port readPoll
    //!
    Fw::OutputBufferSendPort m_readPoll_OutputPort[NUM_READPOLL_OUTPUT_PORTS];

    //! Output port uplinkPort
    //!
    Fw::OutputComPort m_uplinkPort_OutputPort[NUM_UPLINKPORT_OUTPUT_PORTS];

    //! Output port write
    //!
    Fw::OutputBufferSendPort m_write_OutputPort[NUM_WRITE_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port downlinkPort
    //!
    static void m_p_downlinkPort_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::ComBuffer &data, /*!< 
      Buffer containing packet data
      */
        U32 context /*!< 
      Call context value; meaning chosen by user
      */
    );

    //! Callback for port fileDownlinkBufferSendIn
    //!
    static void m_p_fileDownlinkBufferSendIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Callback for port readCallback
    //!
    static void m_p_readCallback_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Callback for port schedIn
    //!
    static void m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< 
      The call order
      */
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };

} // end namespace Svc
#endif
