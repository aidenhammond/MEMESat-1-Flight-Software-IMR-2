// ======================================================================
// \title  GenericRepeaterComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for GenericRepeater component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/GenericRepeater/GenericRepeaterComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputSerializePort *GenericRepeaterComponentBase ::
    get_portIn_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_portIn_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_portIn_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Typed connectors for output ports
  // ----------------------------------------------------------------------

  void GenericRepeaterComponentBase ::
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

  void GenericRepeaterComponentBase ::
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

    GenericRepeaterComponentBase :: GenericRepeaterComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void GenericRepeaterComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

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

  GenericRepeaterComponentBase::
    ~GenericRepeaterComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  Fw::SerializeStatus GenericRepeaterComponentBase ::
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

  NATIVE_INT_TYPE GenericRepeaterComponentBase ::
    getNum_portIn_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_portIn_InputPort));
  }

  NATIVE_INT_TYPE GenericRepeaterComponentBase ::
    getNum_portOut_OutputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_portOut_OutputPort));
  }

  // ----------------------------------------------------------------------
  // Port connection status queries
  // ----------------------------------------------------------------------

  bool GenericRepeaterComponentBase ::
    isConnected_portOut_OutputPort(NATIVE_INT_TYPE portNum)
  {
     FW_ASSERT(
        portNum < this->getNum_portOut_OutputPorts(),
        static_cast<AssertArg>(portNum)
     );
     return this->m_portOut_OutputPort[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Call for messages received on serial input ports
  // ----------------------------------------------------------------------

#if FW_PORT_SERIALIZATION

  void GenericRepeaterComponentBase ::
    m_p_portIn_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        Fw::SerializeBufferBase& buffer) {

    FW_ASSERT(callComp);
    GenericRepeaterComponentBase* compPtr = static_cast<GenericRepeaterComponentBase*>(callComp);
    compPtr->portIn_handlerBase(portNum,buffer);
  }

  void GenericRepeaterComponentBase ::
    portIn_handlerBase(
        NATIVE_INT_TYPE portNum,
        Fw::SerializeBufferBase& buffer) {
    this->portIn_handler(portNum,buffer);
  }
#endif

} // end namespace Svc
