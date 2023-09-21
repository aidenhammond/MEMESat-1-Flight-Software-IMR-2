// ======================================================================
// \title  LinuxI2cDriverComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for LinuxI2cDriver component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Drv/LinuxI2cDriver/LinuxI2cDriverComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Drv {

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Drv::InputI2cPort *LinuxI2cDriverComponentBase ::
    get_read_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_read_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_read_InputPort[portNum];
  }

  Drv::InputI2cPort *LinuxI2cDriverComponentBase ::
    get_write_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_write_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_write_InputPort[portNum];
  }

  Drv::InputI2cWriteReadPort *LinuxI2cDriverComponentBase ::
    get_writeRead_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_writeRead_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_writeRead_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    LinuxI2cDriverComponentBase :: LinuxI2cDriverComponentBase(const char* compName) :
        Fw::PassiveComponentBase(compName) {



  }

  void LinuxI2cDriverComponentBase ::
    init(NATIVE_INT_TYPE instance)
  {

    // Initialize base class
    Fw::PassiveComponentBase::init(instance);

    // Connect input port read
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_read_InputPorts();
        port++
    ) {

      this->m_read_InputPort[port].init();
      this->m_read_InputPort[port].addCallComp(
          this,
          m_p_read_in
      );
      this->m_read_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_read_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_read_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port write
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_write_InputPorts();
        port++
    ) {

      this->m_write_InputPort[port].init();
      this->m_write_InputPort[port].addCallComp(
          this,
          m_p_write_in
      );
      this->m_write_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_write_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_write_InputPort[port].setObjName(portName);
#endif

    }

    // Connect input port writeRead
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_writeRead_InputPorts();
        port++
    ) {

      this->m_writeRead_InputPort[port].init();
      this->m_writeRead_InputPort[port].addCallComp(
          this,
          m_p_writeRead_in
      );
      this->m_writeRead_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_writeRead_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_writeRead_InputPort[port].setObjName(portName);
#endif

    }


  }

  LinuxI2cDriverComponentBase::
    ~LinuxI2cDriverComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE LinuxI2cDriverComponentBase ::
    getNum_read_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_read_InputPort));
  }

  NATIVE_INT_TYPE LinuxI2cDriverComponentBase ::
    getNum_write_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_write_InputPort));
  }

  NATIVE_INT_TYPE LinuxI2cDriverComponentBase ::
    getNum_writeRead_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_writeRead_InputPort));
  }

  // ----------------------------------------------------------------------
  // Mutex functions for guarded ports
  // ----------------------------------------------------------------------

  void LinuxI2cDriverComponentBase ::
    lock()
  {
    this->m_guardedPortMutex.lock();
  }

  void LinuxI2cDriverComponentBase ::
    unLock()
  {
    this->m_guardedPortMutex.unLock();
  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  Drv::I2cStatus LinuxI2cDriverComponentBase ::
    m_p_read_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 addr, Fw::Buffer &serBuffer
    )
  {
    FW_ASSERT(callComp);
    LinuxI2cDriverComponentBase* compPtr = static_cast<LinuxI2cDriverComponentBase*>(callComp);
    return compPtr->read_handlerBase(portNum, addr, serBuffer);
  }

  Drv::I2cStatus LinuxI2cDriverComponentBase ::
    m_p_write_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 addr, Fw::Buffer &serBuffer
    )
  {
    FW_ASSERT(callComp);
    LinuxI2cDriverComponentBase* compPtr = static_cast<LinuxI2cDriverComponentBase*>(callComp);
    return compPtr->write_handlerBase(portNum, addr, serBuffer);
  }

  Drv::I2cStatus LinuxI2cDriverComponentBase ::
    m_p_writeRead_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        U32 addr, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer
    )
  {
    FW_ASSERT(callComp);
    LinuxI2cDriverComponentBase* compPtr = static_cast<LinuxI2cDriverComponentBase*>(callComp);
    return compPtr->writeRead_handlerBase(portNum, addr, writeBuffer, readBuffer);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  Drv::I2cStatus LinuxI2cDriverComponentBase ::
    read_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 addr, Fw::Buffer &serBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_read_InputPorts(),static_cast<AssertArg>(portNum));
    Drv::I2cStatus  retVal;

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->read_handler(portNum, addr, serBuffer);

    // Unlock guard mutex
    this->unLock();

    return retVal;

  }

  Drv::I2cStatus LinuxI2cDriverComponentBase ::
    write_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 addr, Fw::Buffer &serBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_write_InputPorts(),static_cast<AssertArg>(portNum));
    Drv::I2cStatus  retVal;

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->write_handler(portNum, addr, serBuffer);

    // Unlock guard mutex
    this->unLock();

    return retVal;

  }

  Drv::I2cStatus LinuxI2cDriverComponentBase ::
    writeRead_handlerBase(
        NATIVE_INT_TYPE portNum,
        U32 addr, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_writeRead_InputPorts(),static_cast<AssertArg>(portNum));
    Drv::I2cStatus  retVal;

    // Lock guard mutex before calling
    this->lock();

    // Down call to pure virtual handler method implemented in Impl class
    retVal = this->writeRead_handler(portNum, addr, writeBuffer, readBuffer);

    // Unlock guard mutex
    this->unLock();

    return retVal;

  }

} // end namespace Drv
