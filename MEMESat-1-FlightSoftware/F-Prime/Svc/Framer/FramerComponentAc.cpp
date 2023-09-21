// ======================================================================
// \title  FramerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for Framer component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/Framer/FramerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputBufferSendPort *FramerComponentBase ::
    get_bufferIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_bufferIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_bufferIn_InputPort[portNum];
  }

  Fw::InputComPort *FramerComponentBase ::
    get_comIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_comIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_comIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].addCallPort(port);
  }

  void FramerComponentBase ::
    set_framedAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferGetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedAllocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_framedAllocate_OutputPort[portNum].addCallPort(port);
  }

  void FramerComponentBase ::
    set_framedOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Drv::InputByteStreamSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_framedOut_OutputPort[portNum].addCallPort(port);
  }

  void FramerComponentBase ::
    set_timeGet_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGet_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_timeGet_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void FramerComponentBase ::
    set_bufferDeallocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_bufferDeallocate_OutputPort[portNum].registerSerialPort(port);
  }

  void FramerComponentBase ::
    set_framedAllocate_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedAllocate_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_framedAllocate_OutputPort[portNum].registerSerialPort(port);
  }

  void FramerComponentBase ::
    set_framedOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_framedOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_framedOut_OutputPort[portNum].registerSerialPort(port);
  }

  void FramerComponentBase ::
    set_timeGet_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_timeGet_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_timeGet_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    FramerComponentBase :: FramerComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void FramerComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port bufferIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_bufferIn_InputPorts();
        port++
    ) {

      this->m_bufferIn_InputPort[port].init();
      this->m_bufferIn_InputPort[port].addCallComp(
          this,
          m_p_bufferIn_in
      );
      this->m_bufferIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_bufferIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_bufferIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port comIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_comIn_InputPorts();
        port++
    ) {

      this->m_comIn_InputPort[port].init();
      this->m_comIn_InputPort[port].addCallComp(
          this,
          m_p_comIn_in
      );
      this->m_comIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_comIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_comIn_InputPort[port].setObjName(portName);
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

    // Initialize output port framedAllocate
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_framedAllocate_OutputPorts();
        port++
    ) {
      this->m_framedAllocate_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_framedAllocate_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_framedAllocate_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port framedOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_framedOut_OutputPorts();
        port++
    ) {
      this->m_framedOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_framedOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_framedOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port timeGet
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_timeGet_OutputPorts();
        port++
    ) {
      this->m_timeGet_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_timeGet_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_timeGet_OutputPort[port].setObjName(portName);
#endif

    }


  }

  FramerComponentBase::
    ~FramerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    bufferDeallocate_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_bufferDeallocate_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_bufferDeallocate_OutputPort[portNum].invoke(fwBuffer);
  }

  Fw::Buffer FramerComponentBase ::
    framedAllocate_out(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(portNum < this->getNum_framedAllocate_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_framedAllocate_OutputPort[portNum].invoke(size);
  }

  Drv::SendStatus FramerComponentBase ::
    framedOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &sendBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_framedOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_framedOut_OutputPort[portNum].invoke(sendBuffer);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_bufferDeallocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferDeallocate_OutputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_bufferIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_bufferIn_InputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_comIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_comIn_InputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_framedAllocate_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_framedAllocate_OutputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_framedOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_framedOut_OutputPort));
  }

  NATIVE_INT_TYPE FramerComponentBase ::
    getNum_timeGet_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_timeGet_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool FramerComponentBase ::
    isConnected_bufferDeallocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_bufferDeallocate_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_bufferDeallocate_OutputPort[portNum].isConnected();
  }

  bool FramerComponentBase ::
    isConnected_framedAllocate_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_framedAllocate_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_framedAllocate_OutputPort[portNum].isConnected();
  }

  bool FramerComponentBase ::
    isConnected_framedOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_framedOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_framedOut_OutputPort[portNum].isConnected();
  }

  bool FramerComponentBase ::
    isConnected_timeGet_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_timeGet_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_timeGet_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time FramerComponentBase ::
    getTime()
  {
    if (this->m_timeGet_OutputPort[0].isConnected()) {
      Fw::Time _time;
      this->m_timeGet_OutputPort[0].invoke(_time);
      return _time;
    } else {
      return Fw::Time(TB_NONE,0,0);
    }
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void FramerComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    m_p_bufferIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    FramerComponentBase* compPtr = static_cast<FramerComponentBase*>(callComp);
    compPtr->bufferIn_handlerBase(portNum, fwBuffer);
  }

  void FramerComponentBase ::
    m_p_comIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(callComp);
    FramerComponentBase* compPtr = static_cast<FramerComponentBase*>(callComp);
    compPtr->comIn_handlerBase(portNum, data, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void FramerComponentBase ::
    bufferIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_bufferIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->bufferIn_handler(portNum, fwBuffer);

    // Unlock guard mutex
    this->unLock();

  }

  void FramerComponentBase ::
    comIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_comIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->comIn_handler(portNum, data, context);

    // Unlock guard mutex
    this->unLock();

  }

} // end namespace Svc
