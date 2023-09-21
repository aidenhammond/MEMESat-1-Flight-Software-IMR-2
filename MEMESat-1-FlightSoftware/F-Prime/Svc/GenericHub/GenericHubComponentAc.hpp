// ======================================================================
// \title  GenericHubComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for GenericHub component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef GENERICHUB_COMP_HPP_
#define GENERICHUB_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Fw/Buffer/BufferGetPortAc.hpp>
#include <Fw/Buffer/BufferSendPortAc.hpp>

namespace Svc {

  //! \class GenericHubComponentBase
  //! \brief Auto-generated base for GenericHub component
  //!
  class GenericHubComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class GenericHubComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return buffersIn[portNum]
    //!
    Fw::InputBufferSendPort* get_buffersIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return dataIn[portNum]
    //!
    Fw::InputBufferSendPort* get_dataIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Get serial input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return portIn[portNum]
    //!
    Fw::InputSerializePort* get_portIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to bufferDeallocate[portNum]
    //!
    void set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to buffersOut[portNum]
    //!
    void set_buffersOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to dataInDeallocate[portNum]
    //!
    void set_dataInDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to dataOut[portNum]
    //!
    void set_dataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferSendPort *port /*!< The port*/
    );

    //! Connect port to dataOutAllocate[portNum]
    //!
    void set_dataOutAllocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputBufferGetPort *port /*!< The port*/
    );

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to bufferDeallocate[portNum]
    //!
    void set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to buffersOut[portNum]
    //!
    void set_buffersOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to dataInDeallocate[portNum]
    //!
    void set_dataInDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to dataOut[portNum]
    //!
    void set_dataOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to dataOutAllocate[portNum]
    //!
    void set_dataOutAllocate_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  public:

    // ----------------------------------------------------------------------
    // Connect serial input ports to serial output ports
    // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

    //! Connect port to portOut[portNum]
    //!
    void set_portOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );


  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to serial output ports
    // ----------------------------------------------------------------------

    //! Connect port to portOut[portNum]
    //!
    void set_portOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputPortBase *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a GenericHubComponentBase object
    //!
    GenericHubComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a GenericHubComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a GenericHubComponentBase object
    //!
    virtual ~GenericHubComponentBase();

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

    //! Handler for input port buffersIn
    //
    virtual void buffersIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

    //! Handler for input port dataIn
    //
    virtual void dataIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port buffersIn
    //!
    void buffersIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Handler base-class function for input port dataIn
    //!
    void dataIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for serial input ports
    // ----------------------------------------------------------------------

    //! Handler for input port portIn
    //!
    virtual void portIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for serial input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port portIn
    //!
    void portIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for serial async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port bufferDeallocate
    //!
    void bufferDeallocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port buffersOut
    //!
    void buffersOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port dataInDeallocate
    //!
    void dataInDeallocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port dataOut
    //!
    void dataOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Invoke output port dataOutAllocate
    //!
    Fw::Buffer dataOutAllocate_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 size 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for serial output ports
    // ----------------------------------------------------------------------

    //! Invoke output port portOut
    //!
    Fw::SerializeStatus portOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of buffersIn input ports
    //!
    //! \return The number of buffersIn input ports
    //!
    NATIVE_INT_TYPE getNum_buffersIn_InputPorts();

    //! Get the number of dataIn input ports
    //!
    //! \return The number of dataIn input ports
    //!
    NATIVE_INT_TYPE getNum_dataIn_InputPorts();

    //! Get the number of portIn input ports
    //!
    //! \return The number of portIn input ports
    //!
    NATIVE_INT_TYPE getNum_portIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_BUFFERSIN_INPUT_PORTS = 10,
       NUM_DATAIN_INPUT_PORTS = 1,
       NUM_PORTIN_INPUT_PORTS = 10,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of bufferDeallocate output ports
    //!
    //! \return The number of bufferDeallocate output ports
    //!
    NATIVE_INT_TYPE getNum_bufferDeallocate_OutputPorts();

    //! Get the number of buffersOut output ports
    //!
    //! \return The number of buffersOut output ports
    //!
    NATIVE_INT_TYPE getNum_buffersOut_OutputPorts();

    //! Get the number of dataInDeallocate output ports
    //!
    //! \return The number of dataInDeallocate output ports
    //!
    NATIVE_INT_TYPE getNum_dataInDeallocate_OutputPorts();

    //! Get the number of dataOut output ports
    //!
    //! \return The number of dataOut output ports
    //!
    NATIVE_INT_TYPE getNum_dataOut_OutputPorts();

    //! Get the number of dataOutAllocate output ports
    //!
    //! \return The number of dataOutAllocate output ports
    //!
    NATIVE_INT_TYPE getNum_dataOutAllocate_OutputPorts();

    //! Get the number of portOut output ports
    //!
    //! \return The number of portOut output ports
    //!
    NATIVE_INT_TYPE getNum_portOut_OutputPorts();


    enum {
       NUM_BUFFERDEALLOCATE_OUTPUT_PORTS = 1,
       NUM_BUFFERSOUT_OUTPUT_PORTS = 10,
       NUM_DATAINDEALLOCATE_OUTPUT_PORTS = 1,
       NUM_DATAOUT_OUTPUT_PORTS = 1,
       NUM_DATAOUTALLOCATE_OUTPUT_PORTS = 1,
       NUM_PORTOUT_OUTPUT_PORTS = 10,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port bufferDeallocate is connected
    //!
    //! \return Whether port bufferDeallocate is connected
    //!
    bool isConnected_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port buffersOut is connected
    //!
    //! \return Whether port buffersOut is connected
    //!
    bool isConnected_buffersOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port dataInDeallocate is connected
    //!
    //! \return Whether port dataInDeallocate is connected
    //!
    bool isConnected_dataInDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port dataOut is connected
    //!
    //! \return Whether port dataOut is connected
    //!
    bool isConnected_dataOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port dataOutAllocate is connected
    //!
    //! \return Whether port dataOutAllocate is connected
    //!
    bool isConnected_dataOutAllocate_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port portOut is connected
    //!
    //! \return Whether port portOut is connected
    //!
    bool isConnected_portOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port buffersIn
    //!
    Fw::InputBufferSendPort m_buffersIn_InputPort[NUM_BUFFERSIN_INPUT_PORTS];

    //! Input port dataIn
    //!
    Fw::InputBufferSendPort m_dataIn_InputPort[NUM_DATAIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Serial input ports
    // ----------------------------------------------------------------------

    //! Input port portIn
    //!
    Fw::InputSerializePort m_portIn_InputPort[NUM_PORTIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port bufferDeallocate
    //!
    Fw::OutputBufferSendPort m_bufferDeallocate_OutputPort[NUM_BUFFERDEALLOCATE_OUTPUT_PORTS];

    //! Output port buffersOut
    //!
    Fw::OutputBufferSendPort m_buffersOut_OutputPort[NUM_BUFFERSOUT_OUTPUT_PORTS];

    //! Output port dataInDeallocate
    //!
    Fw::OutputBufferSendPort m_dataInDeallocate_OutputPort[NUM_DATAINDEALLOCATE_OUTPUT_PORTS];

    //! Output port dataOut
    //!
    Fw::OutputBufferSendPort m_dataOut_OutputPort[NUM_DATAOUT_OUTPUT_PORTS];

    //! Output port dataOutAllocate
    //!
    Fw::OutputBufferGetPort m_dataOutAllocate_OutputPort[NUM_DATAOUTALLOCATE_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Serial output ports
    // ----------------------------------------------------------------------

    //! Output port portOut
    //!
    Fw::OutputSerializePort m_portOut_OutputPort[NUM_PORTOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port buffersIn
    //!
    static void m_p_buffersIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

    //! Callback for port dataIn
    //!
    static void m_p_dataIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::Buffer &fwBuffer 
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Call for messages received on serial input ports
    // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION


    //! Serial port callback
    //!
    static void m_p_portIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::SerializeBufferBase &Buffer /*!< The serialization buffer*/
    );

#endif

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;



  };

} // end namespace Svc
#endif
