// ======================================================================
// \title  LinuxI2cDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for LinuxI2cDriver component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef LINUXI2CDRIVER_COMP_HPP_
#define LINUXI2CDRIVER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Os/Mutex.hpp>
#include <Fw/Buffer/Buffer.hpp>
#include <Drv/I2cDriverPorts/I2cPortAc.hpp>
#include <Drv/I2cDriverPorts/I2cWriteReadPortAc.hpp>

namespace Drv {

  //! \class LinuxI2cDriverComponentBase
  //! \brief Auto-generated base for LinuxI2cDriver component
  //!
  class LinuxI2cDriverComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class LinuxI2cDriverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return read[portNum]
    //!
    Drv::InputI2cPort* get_read_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return write[portNum]
    //!
    Drv::InputI2cPort* get_write_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return writeRead[portNum]
    //!
    Drv::InputI2cWriteReadPort* get_writeRead_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a LinuxI2cDriverComponentBase object
    //!
    LinuxI2cDriverComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a LinuxI2cDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a LinuxI2cDriverComponentBase object
    //!
    virtual ~LinuxI2cDriverComponentBase();

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

    //! Handler for input port read
    //
    virtual Drv::I2cStatus read_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &serBuffer /*!< 
      Buffer with data to read/write to/from
      */
    ) = 0;

    //! Handler for input port write
    //
    virtual Drv::I2cStatus write_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &serBuffer /*!< 
      Buffer with data to read/write to/from
      */
    ) = 0;

    //! Handler for input port writeRead
    //
    virtual Drv::I2cStatus writeRead_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &writeBuffer, /*!< 
      Buffer to write data to the i2c device
      */
        Fw::Buffer &readBuffer /*!< 
      Buffer to read back data from the i2c device, must set size when passing in read buffer
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port read
    //!
    Drv::I2cStatus read_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &serBuffer /*!< 
      Buffer with data to read/write to/from
      */
    );

    //! Handler base-class function for input port write
    //!
    Drv::I2cStatus write_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &serBuffer /*!< 
      Buffer with data to read/write to/from
      */
    );

    //! Handler base-class function for input port writeRead
    //!
    Drv::I2cStatus writeRead_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &writeBuffer, /*!< 
      Buffer to write data to the i2c device
      */
        Fw::Buffer &readBuffer /*!< 
      Buffer to read back data from the i2c device, must set size when passing in read buffer
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of read input ports
    //!
    //! \return The number of read input ports
    //!
    NATIVE_INT_TYPE getNum_read_InputPorts();

    //! Get the number of write input ports
    //!
    //! \return The number of write input ports
    //!
    NATIVE_INT_TYPE getNum_write_InputPorts();

    //! Get the number of writeRead input ports
    //!
    //! \return The number of writeRead input ports
    //!
    NATIVE_INT_TYPE getNum_writeRead_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_READ_INPUT_PORTS = 1,
       NUM_WRITE_INPUT_PORTS = 1,
       NUM_WRITEREAD_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port read
    //!
    Drv::InputI2cPort m_read_InputPort[NUM_READ_INPUT_PORTS];

    //! Input port write
    //!
    Drv::InputI2cPort m_write_InputPort[NUM_WRITE_INPUT_PORTS];

    //! Input port writeRead
    //!
    Drv::InputI2cWriteReadPort m_writeRead_InputPort[NUM_WRITEREAD_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port read
    //!
    static Drv::I2cStatus m_p_read_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &serBuffer /*!< 
      Buffer with data to read/write to/from
      */
    );

    //! Callback for port write
    //!
    static Drv::I2cStatus m_p_write_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &serBuffer /*!< 
      Buffer with data to read/write to/from
      */
    );

    //! Callback for port writeRead
    //!
    static Drv::I2cStatus m_p_writeRead_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        U32 addr, /*!< 
      I2C slave device address
      */
        Fw::Buffer &writeBuffer, /*!< 
      Buffer to write data to the i2c device
      */
        Fw::Buffer &readBuffer /*!< 
      Buffer to read back data from the i2c device, must set size when passing in read buffer
      */
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Mutexes
    // ----------------------------------------------------------------------

    //! Mutex for guarded ports
    //!
    Os::Mutex m_guardedPortMutex;



  };

} // end namespace Drv
#endif
