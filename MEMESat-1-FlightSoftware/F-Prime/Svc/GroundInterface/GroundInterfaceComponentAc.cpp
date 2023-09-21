// ======================================================================
// \title  GroundInterfaceComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for GroundInterface component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/GroundInterface/GroundInterfaceComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputComPort *GroundInterfaceComponentBase ::
    get_downlinkPort_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_downlinkPort_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_downlinkPort_InputPort[portNum];
  }

  Fw::InputBufferSendPort *GroundInterfaceComponentBase ::
    get_fileDownlinkBufferSendIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_fileDownlinkBufferSendIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_fileDownlinkBufferSendIn_InputPort[portNum];
  }

  Fw::InputBufferSendPort *GroundInterfaceComponentBase ::
    get_readCallback_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_readCallback_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_readCallback_InputPort[portNum];
  }

  Svc::InputSchedPort *GroundInterfaceComponentBase ::
    get_schedIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_schedIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_schedIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void GroundInterfaceComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Log_OutputPort[portNum].addCallPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void GroundInterfaceComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputLogTextPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_LogText_OutputPort[portNum].addCallPort(port);
  }
#endif

  void GroundInterfaceComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputTimePort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_Time_OutputPort[portNum].addCallPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_fileDownlinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_fileDownlinkBufferSendOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_fileDownlinkBufferSendOut_OutputPort[portNum].addCallPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_fileUplinkBufferGet_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferGetPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_fileUplinkBufferGet_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_fileUplinkBufferGet_OutputPort[portNum].addCallPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_fileUplinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_fileUplinkBufferSendOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_fileUplinkBufferSendOut_OutputPort[portNum].addCallPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_readPoll_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_readPoll_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_readPoll_OutputPort[portNum].addCallPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_uplinkPort_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputComPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_uplinkPort_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_uplinkPort_OutputPort[portNum].addCallPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_write_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputBufferSendPort* port
    )
  {
    FW_ASSERT(portNum < this->getNum_write_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_write_OutputPort[portNum].addCallPort(port);
  }

  // ----------------------------------------------------------------------
  // Serialization connectors for output ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void GroundInterfaceComponentBase ::
    set_Log_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Log_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_Log_OutputPort[portNum].registerSerialPort(port);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void GroundInterfaceComponentBase ::
    set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_LogText_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_LogText_OutputPort[portNum].registerSerialPort(port);
  }
#endif

  void GroundInterfaceComponentBase ::
    set_Time_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_Time_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_Time_OutputPort[portNum].registerSerialPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_fileDownlinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_fileDownlinkBufferSendOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_fileDownlinkBufferSendOut_OutputPort[portNum].registerSerialPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_fileUplinkBufferGet_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_fileUplinkBufferGet_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_fileUplinkBufferGet_OutputPort[portNum].registerSerialPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_fileUplinkBufferSendOut_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_fileUplinkBufferSendOut_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_fileUplinkBufferSendOut_OutputPort[portNum].registerSerialPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_readPoll_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_readPoll_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_readPoll_OutputPort[portNum].registerSerialPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_uplinkPort_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_uplinkPort_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_uplinkPort_OutputPort[portNum].registerSerialPort(port);
  }

  void GroundInterfaceComponentBase ::
    set_write_OutputPort(
        NATIVE_INT_TYPE portNum,
        Fw::InputSerializePort *port
    )
  {
    FW_ASSERT(portNum < this->getNum_write_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_write_OutputPort[portNum].registerSerialPort(port);
  }

#endif

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    GroundInterfaceComponentBase :: GroundInterfaceComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void GroundInterfaceComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port downlinkPort
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_downlinkPort_InputPorts();
        port++
    ) {

      this->m_downlinkPort_InputPort[port].init();
      this->m_downlinkPort_InputPort[port].addCallComp(
          this,
          m_p_downlinkPort_in
      );
      this->m_downlinkPort_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_downlinkPort_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_downlinkPort_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port fileDownlinkBufferSendIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_fileDownlinkBufferSendIn_InputPorts();
        port++
    ) {

      this->m_fileDownlinkBufferSendIn_InputPort[port].init();
      this->m_fileDownlinkBufferSendIn_InputPort[port].addCallComp(
          this,
          m_p_fileDownlinkBufferSendIn_in
      );
      this->m_fileDownlinkBufferSendIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_fileDownlinkBufferSendIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_fileDownlinkBufferSendIn_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port readCallback
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_readCallback_InputPorts();
        port++
    ) {

      this->m_readCallback_InputPort[port].init();
      this->m_readCallback_InputPort[port].addCallComp(
          this,
          m_p_readCallback_in
      );
      this->m_readCallback_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_readCallback_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_readCallback_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port schedIn
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_schedIn_InputPorts();
        port++
    ) {

      this->m_schedIn_InputPort[port].init();
      this->m_schedIn_InputPort[port].addCallComp(
          this,
          m_p_schedIn_in
      );
      this->m_schedIn_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_schedIn_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_schedIn_InputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port Log
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_Log_OutputPorts();
        port++
    ) {
      this->m_Log_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Log_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_Log_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port LogText
#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_LogText_OutputPorts();
        port++
    ) {
      this->m_LogText_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_LogText_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_LogText_OutputPort[port].setObjName(portName);
#endif

    }
#endif

    // Initialize output port Time
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_Time_OutputPorts();
        port++
    ) {
      this->m_Time_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_Time_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_Time_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port fileDownlinkBufferSendOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_fileDownlinkBufferSendOut_OutputPorts();
        port++
    ) {
      this->m_fileDownlinkBufferSendOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_fileDownlinkBufferSendOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_fileDownlinkBufferSendOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port fileUplinkBufferGet
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_fileUplinkBufferGet_OutputPorts();
        port++
    ) {
      this->m_fileUplinkBufferGet_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_fileUplinkBufferGet_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_fileUplinkBufferGet_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port fileUplinkBufferSendOut
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_fileUplinkBufferSendOut_OutputPorts();
        port++
    ) {
      this->m_fileUplinkBufferSendOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_fileUplinkBufferSendOut_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_fileUplinkBufferSendOut_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port readPoll
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_readPoll_OutputPorts();
        port++
    ) {
      this->m_readPoll_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_readPoll_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_readPoll_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port uplinkPort
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_uplinkPort_OutputPorts();
        port++
    ) {
      this->m_uplinkPort_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_uplinkPort_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_uplinkPort_OutputPort[port].setObjName(portName);
#endif

    }

    // Initialize output port write
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_write_OutputPorts();
        port++
    ) {
      this->m_write_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_write_OutputPort[%d]",
          this->m_objName,
          port
      );
      this->m_write_OutputPort[port].setObjName(portName);
#endif

    }


  }

  GroundInterfaceComponentBase::
    ~GroundInterfaceComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  void GroundInterfaceComponentBase ::
    fileDownlinkBufferSendOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_fileDownlinkBufferSendOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_fileDownlinkBufferSendOut_OutputPort[portNum].invoke(fwBuffer);
  }

  Fw::Buffer GroundInterfaceComponentBase ::
    fileUplinkBufferGet_out(
        NATIVE_INT_TYPE portNum,
        U32 size
    )
  {
    FW_ASSERT(portNum < this->getNum_fileUplinkBufferGet_OutputPorts(),static_cast<AssertArg>(portNum));
    return this->m_fileUplinkBufferGet_OutputPort[portNum].invoke(size);
  }

  void GroundInterfaceComponentBase ::
    fileUplinkBufferSendOut_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_fileUplinkBufferSendOut_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_fileUplinkBufferSendOut_OutputPort[portNum].invoke(fwBuffer);
  }

  void GroundInterfaceComponentBase ::
    readPoll_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_readPoll_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_readPoll_OutputPort[portNum].invoke(fwBuffer);
  }

  void GroundInterfaceComponentBase ::
    uplinkPort_out(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(portNum < this->getNum_uplinkPort_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_uplinkPort_OutputPort[portNum].invoke(data, context);
  }

  void GroundInterfaceComponentBase ::
    write_out(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(portNum < this->getNum_write_OutputPorts(),static_cast<AssertArg>(portNum));
    this->m_write_OutputPort[portNum].invoke(fwBuffer);
  }

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_Log_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Log_OutputPort));
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_LogText_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_LogText_OutputPort));
  }
#endif

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_Time_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_Time_OutputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_downlinkPort_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_downlinkPort_InputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_fileDownlinkBufferSendIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_fileDownlinkBufferSendIn_InputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_fileDownlinkBufferSendOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_fileDownlinkBufferSendOut_OutputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_fileUplinkBufferGet_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_fileUplinkBufferGet_OutputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_fileUplinkBufferSendOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_fileUplinkBufferSendOut_OutputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_readCallback_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_readCallback_InputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_readPoll_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_readPoll_OutputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_schedIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_schedIn_InputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_uplinkPort_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_uplinkPort_OutputPort));
  }

  NATIVE_INT_TYPE GroundInterfaceComponentBase ::
    getNum_write_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_write_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool GroundInterfaceComponentBase ::
    isConnected_Log_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Log_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_Log_OutputPort[portNum].isConnected();
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  bool GroundInterfaceComponentBase ::
    isConnected_LogText_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_LogText_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_LogText_OutputPort[portNum].isConnected();
  }
#endif

  bool GroundInterfaceComponentBase ::
    isConnected_Time_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_Time_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_Time_OutputPort[portNum].isConnected();
  }

  bool GroundInterfaceComponentBase ::
    isConnected_fileDownlinkBufferSendOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_fileDownlinkBufferSendOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_fileDownlinkBufferSendOut_OutputPort[portNum].isConnected();
  }

  bool GroundInterfaceComponentBase ::
    isConnected_fileUplinkBufferGet_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_fileUplinkBufferGet_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_fileUplinkBufferGet_OutputPort[portNum].isConnected();
  }

  bool GroundInterfaceComponentBase ::
    isConnected_fileUplinkBufferSendOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_fileUplinkBufferSendOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_fileUplinkBufferSendOut_OutputPort[portNum].isConnected();
  }

  bool GroundInterfaceComponentBase ::
    isConnected_readPoll_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_readPoll_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_readPoll_OutputPort[portNum].isConnected();
  }

  bool GroundInterfaceComponentBase ::
    isConnected_uplinkPort_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_uplinkPort_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_uplinkPort_OutputPort[portNum].isConnected();
  }

  bool GroundInterfaceComponentBase ::
    isConnected_write_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_write_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_write_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  Fw::Time GroundInterfaceComponentBase ::
    getTime()
  {
    if (this->m_Time_OutputPort[0].isConnected()) {
      Fw::Time _time;
      this->m_Time_OutputPort[0].invoke(_time);
      return _time;
    } else {
      return Fw::Time(TB_NONE,0,0);
    }
  }

  // ----------------------------------------------------------------------
  // Event handling functions
  // ----------------------------------------------------------------------

  void GroundInterfaceComponentBase ::
    log_WARNING_HI_GroundInterfaceError(
        
    )
  {


    // Get the time
    Fw::Time _logTime;
    if (this->m_Time_OutputPort[0].isConnected()) {
       this->m_Time_OutputPort[0].invoke( _logTime);
    }

    FwEventIdType _id = static_cast<FwEventIdType>(0);

    _id = this->getIdBase() + EVENTID_GROUNDINTERFACEERROR;

    // Emit the event on the log port
    if (this->m_Log_OutputPort[0].isConnected()) {

      Fw::LogBuffer _logBuff;
#if FW_AMPCS_COMPATIBLE
      // for AMPCS, need to encode zero arguments
      Fw::SerializeStatus _zero_status = Fw::FW_SERIALIZE_OK;
      _zero_status = _logBuff.serialize(static_cast<U8>(0));
      FW_ASSERT(
          _zero_status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_zero_status)
      );
#endif


      this->m_Log_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logBuff
      );

    }

    // Emit the event on the text log port
#if FW_ENABLE_TEXT_LOGGING
    if (this->m_LogText_OutputPort[0].isConnected()) {

#if FW_OBJECT_NAMES == 1
      const char* _formatString =
        "(%s) %s: Ground interface encountered an error";
#else
      const char* _formatString =
        "%s: Ground interface encountered an error";
#endif

      char _textBuffer[FW_LOG_TEXT_BUFFER_SIZE];

      (void) snprintf(
          _textBuffer,
          FW_LOG_TEXT_BUFFER_SIZE,
          _formatString,
#if FW_OBJECT_NAMES == 1
          this->m_objName,
#endif
          "GroundInterfaceError "
      );

      // Null terminate
      _textBuffer[FW_LOG_TEXT_BUFFER_SIZE-1] = 0;
      Fw::TextLogString _logString = _textBuffer;
      this->m_LogText_OutputPort[0].invoke(
          _id,
          _logTime,Fw::LogSeverity::WARNING_HI,
          _logString
      );

    }
#endif

  }


  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void GroundInterfaceComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void GroundInterfaceComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void GroundInterfaceComponentBase ::
    m_p_downlinkPort_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {
    FW_ASSERT(callComp);
    GroundInterfaceComponentBase* compPtr = static_cast<GroundInterfaceComponentBase*>(callComp);
    compPtr->downlinkPort_handlerBase(portNum, data, context);
  }

  void GroundInterfaceComponentBase ::
    m_p_fileDownlinkBufferSendIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    GroundInterfaceComponentBase* compPtr = static_cast<GroundInterfaceComponentBase*>(callComp);
    compPtr->fileDownlinkBufferSendIn_handlerBase(portNum, fwBuffer);
  }

  void GroundInterfaceComponentBase ::
    m_p_readCallback_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {
    FW_ASSERT(callComp);
    GroundInterfaceComponentBase* compPtr = static_cast<GroundInterfaceComponentBase*>(callComp);
    compPtr->readCallback_handlerBase(portNum, fwBuffer);
  }

  void GroundInterfaceComponentBase ::
    m_p_schedIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(callComp);
    GroundInterfaceComponentBase* compPtr = static_cast<GroundInterfaceComponentBase*>(callComp);
    compPtr->schedIn_handlerBase(portNum, context);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void GroundInterfaceComponentBase ::
    downlinkPort_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::ComBuffer &data, U32 context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_downlinkPort_InputPorts(),static_cast<AssertArg>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->downlinkPort_handler(portNum, data, context);

    // Unlock guard mutex
    this->unLock();

  }

  void GroundInterfaceComponentBase ::
    fileDownlinkBufferSendIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_fileDownlinkBufferSendIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->fileDownlinkBufferSendIn_handler(portNum, fwBuffer);

    // Unlock guard mutex
    this->unLock();

  }

  void GroundInterfaceComponentBase ::
    readCallback_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::Buffer &fwBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_readCallback_InputPorts(),static_cast<AssertArg>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->readCallback_handler(portNum, fwBuffer);

    // Unlock guard mutex
    this->unLock();

  }

  void GroundInterfaceComponentBase ::
    schedIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_schedIn_InputPorts(),static_cast<AssertArg>(portNum));

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    this->schedIn_handler(portNum, context);

    // Unlock guard mutex
    this->unLock();

  }

} // end namespace Svc
