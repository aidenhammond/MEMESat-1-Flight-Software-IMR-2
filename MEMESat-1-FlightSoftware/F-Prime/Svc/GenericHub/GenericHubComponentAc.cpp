// ======================================================================
// \title  GenericHubComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for GenericHub component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/GenericHub/GenericHubComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputBufferSendPort *GenericHubComponentBase ::
    get_buffersIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_buffersIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_buffersIn_InputPort[portNum];
  }

  Fw::InputBufferSendPort *GenericHubComponentBase ::
    get_dataIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_dataIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_dataIn_InputPort[portNum];
  }

  Fw::InputSerializePort *GenericHubComponentBase ::
    get_portIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_portIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_portIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void GenericHubComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].addCallPort(port);
  }

  void GenericHubComponentBase ::
    set_buffersOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_buffersOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_buffersOut_OutputPort[portNum].addCallPort(port);
  }

  void GenericHubComponentBase ::
    set_dataInDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_dataInDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_dataInDeallocate_OutputPort[portNum].addCallPort(port);
  }

  void GenericHubComponentBase ::
    set_dataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_dataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_dataOut_OutputPort[portNum].addCallPort(port);
  }

  void GenericHubComponentBase ::
    set_dataOutAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferGetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_dataOutAllocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_dataOutAllocate_OutputPort[portNum].addCallPort(port);
  }

  void GenericHubComponentBase ::
    set_portOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_portOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_portOut_OutputPort[portNum].registerSerialPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void GenericHubComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_bufferDeallocate_OutputPort[portNum].registerSerialPort(port);
  }

  void GenericHubComponentBase ::
    set_buffersOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_buffersOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_buffersOut_OutputPort[portNum].registerSerialPort(port);
  }

  void GenericHubComponentBase ::
    set_dataInDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_dataInDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_dataInDeallocate_OutputPort[portNum].registerSerialPort(port);
  }

  void GenericHubComponentBase ::
    set_dataOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_dataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_dataOut_OutputPort[portNum].registerSerialPort(port);
  }

  void GenericHubComponentBase ::
    set_dataOutAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_dataOutAllocate_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_dataOutAllocate_OutputPort[portNum].registerSerialPort(port);
  }

  void GenericHubComponentBase ::
    set_portOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputPortBase *port
    )
  {
    FW_ASSERT(portNum < this->getNum_portOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_portOut_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    GenericHubComponentBase :: GenericHubComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void GenericHubComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port buffersIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_buffersIn_InputPorts();
        port++
    ) {

      this->m_buffersIn_InputPort[port].init();
      this->m_buffersIn_InputPort[port].addCallComp(
          this,
          m_p_buffersIn_in
      );
      this->m_buffersIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_buffersIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_buffersIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port dataIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_dataIn_InputPorts();
        port++
    ) {

      this->m_dataIn_InputPort[port].init();
      this->m_dataIn_InputPort[port].addCallComp(
          this,
          m_p_dataIn_in
      );
      this->m_dataIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_dataIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_dataIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port portIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_portIn_InputPorts();
        port++
    ) {

      this->m_portIn_InputPort[port].init();
      this->m_portIn_InputPort[port].addCallComp(
          this,
          m_p_portIn_in
      );
      this->m_portIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_portIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_portIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port bufferDeallocate
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_bufferDeallocate_OutputPorts();
        port++
    ) {
      this->m_bufferDeallocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferDeallocate_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_bufferDeallocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port buffersOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_buffersOut_OutputPorts();
        port++
    ) {
      this->m_buffersOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_buffersOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_buffersOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port dataInDeallocate
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_dataInDeallocate_OutputPorts();
        port++
    ) {
      this->m_dataInDeallocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_dataInDeallocate_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_dataInDeallocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port dataOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_dataOut_OutputPorts();
        port++
    ) {
      this->m_dataOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_dataOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_dataOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port dataOutAllocate
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_dataOutAllocate_OutputPorts();
        port++
    ) {
      this->m_dataOutAllocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_dataOutAllocate_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_dataOutAllocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port portOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_portOut_OutputPorts();
        port++
    ) {
      this->m_portOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_portOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_portOut_OutputPort[port].setObjName(portName);
#endif

    }


  }

  GenericHubComponentBase::
    ~GenericHubComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void GenericHubComponentBase ::
    bufferDeallocate_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].invoke(fwBuffer);
  }

  void GenericHubComponentBase ::
    buffersOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_buffersOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_buffersOut_OutputPort[portNum].invoke(fwBuffer);
  }

  void GenericHubComponentBase ::
    dataInDeallocate_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_dataInDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_dataInDeallocate_OutputPort[portNum].invoke(fwBuffer);
  }

  void GenericHubComponentBase ::
    dataOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_dataOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_dataOut_OutputPort[portNum].invoke(fwBuffer);
  }

  Fw::Buffer GenericHubComponentBase ::
    dataOutAllocate_out(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(portNum < this->getNum_dataOutAllocate_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_dataOutAllocate_OutputPort[portNum].invoke(size);
  }

  Fw::SerializeStatus GenericHubComponentBase ::
    portOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::SerializeBufferBase &Buffer
    )
  {
    FW_ASSERT(portNum < this->getNum_portOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_portOut_OutputPort[portNum].invokeSerial(Buffer);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_bufferDeallocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferDeallocate_OutputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_buffersIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_buffersIn_InputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_buffersOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_buffersOut_OutputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_dataIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_dataIn_InputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_dataInDeallocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_dataInDeallocate_OutputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_dataOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_dataOut_OutputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_dataOutAllocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_dataOutAllocate_OutputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_portIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_portIn_InputPort));
  }

  NATIVE_INT_TYPE GenericHubComponentBase ::
    getNum_portOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_portOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool GenericHubComponentBase ::
    isConnected_bufferDeallocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_bufferDeallocate_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_bufferDeallocate_OutputPort[portNum].isConnected();
  }

  bool GenericHubComponentBase ::
    isConnected_buffersOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_buffersOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_buffersOut_OutputPort[portNum].isConnected();
  }

  bool GenericHubComponentBase ::
    isConnected_dataInDeallocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_dataInDeallocate_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_dataInDeallocate_OutputPort[portNum].isConnected();
  }

  bool GenericHubComponentBase ::
    isConnected_dataOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_dataOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_dataOut_OutputPort[portNum].isConnected();
  }

  bool GenericHubComponentBase ::
    isConnected_dataOutAllocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_dataOutAllocate_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_dataOutAllocate_OutputPort[portNum].isConnected();
  }

  bool GenericHubComponentBase ::
    isConnected_portOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_portOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_portOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void GenericHubComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void GenericHubComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Call for messages received on serial input ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void GenericHubComponentBase ::
    m_p_portIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::SerializeBufferBase& buffer) {

    FW_ASSERT(callComp);
    GenericHubComponentBase* compPtr = static_cast<GenericHubComponentBase*>(callComp);
    compPtr->portIn_handlerBase(portNum,buffer);
  }

  void GenericHubComponentBase ::
    portIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::SerializeBufferBase& buffer) {
     // lock call
    this->lock();
    this->portIn_handler(portNum,buffer);
    this->unLock();
  }
#endif

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void GenericHubComponentBase ::
    m_p_buffersIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    GenericHubComponentBase* compPtr = static_cast<GenericHubComponentBase*>(callComp);
    compPtr->buffersIn_handlerBase(portNum, fwBuffer);
  }

  void GenericHubComponentBase ::
    m_p_dataIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    GenericHubComponentBase* compPtr = static_cast<GenericHubComponentBase*>(callComp);
    compPtr->dataIn_handlerBase(portNum, fwBuffer);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void GenericHubComponentBase ::
    buffersIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_buffersIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->buffersIn_handler(portNum, fwBuffer);

    // Unlock guard mutex
    this->unLock();

  }

  void GenericHubComponentBase ::
    dataIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_dataIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->dataIn_handler(portNum, fwBuffer);

  }

} // end namespace Svc
