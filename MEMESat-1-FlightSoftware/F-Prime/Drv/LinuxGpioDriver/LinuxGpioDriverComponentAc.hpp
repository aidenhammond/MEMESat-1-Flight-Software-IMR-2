// ======================================================================
// \title  LinuxGpioDriverComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for LinuxGpioDriver component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef LINUXGPIODRIVER_COMP_HPP_
#define LINUXGPIODRIVER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Svc/Cycle/TimerVal.hpp>
#include <Drv/GpioDriverPorts/GpioReadPortAc.hpp>
#include <Drv/GpioDriverPorts/GpioWritePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Fw/Time/TimePortAc.hpp>
#include <Svc/Cycle/CyclePortAc.hpp>

namespace Drv {

  //! \class LinuxGpioDriverComponentBase
  //! \brief Auto-generated base for LinuxGpioDriver component
  //!
  class LinuxGpioDriverComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class LinuxGpioDriverComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return gpioRead[portNum]
    //!
    Drv::InputGpioReadPort* get_gpioRead_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return gpioWrite[portNum]
    //!
    Drv::InputGpioWritePort* get_gpioWrite_InputPort(
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

    //! Connect port to intOut[portNum]
    //!
    void set_intOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::InputCyclePort *port /*!< The port*/
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

    //! Connect port to intOut[portNum]
    //!
    void set_intOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a LinuxGpioDriverComponentBase object
    //!
    LinuxGpioDriverComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a LinuxGpioDriverComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a LinuxGpioDriverComponentBase object
    //!
    virtual ~LinuxGpioDriverComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port gpioRead
    //
    virtual void gpioRead_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool &state 
    ) = 0;

    //! Handler for input port gpioWrite
    //
    virtual void gpioWrite_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool state 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port gpioRead
    //!
    void gpioRead_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool &state 
    );

    //! Handler base-class function for input port gpioWrite
    //!
    void gpioWrite_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool state 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port intOut
    //!
    void intOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Svc::TimerVal &cycleStart /*!< 
      Cycle start timer value
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of gpioRead input ports
    //!
    //! \return The number of gpioRead input ports
    //!
    NATIVE_INT_TYPE getNum_gpioRead_InputPorts();

    //! Get the number of gpioWrite input ports
    //!
    //! \return The number of gpioWrite input ports
    //!
    NATIVE_INT_TYPE getNum_gpioWrite_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_GPIOREAD_INPUT_PORTS = 1,
       NUM_GPIOWRITE_INPUT_PORTS = 1,
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

    //! Get the number of intOut output ports
    //!
    //! \return The number of intOut output ports
    //!
    NATIVE_INT_TYPE getNum_intOut_OutputPorts();


    enum {
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_INTOUT_OUTPUT_PORTS = 2,
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

    //! Check whether port intOut is connected
    //!
    //! \return Whether port intOut is connected
    //!
    bool isConnected_intOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_GP_OPENERROR = 0x0, /* Open error */
      EVENTID_GP_CONFIGERROR = 0x1, /* GPIO configure error */
      EVENTID_GP_WRITEERROR = 0x2, /* GPIO write error */
      EVENTID_GP_READERROR = 0x3, /* GPIO read error */
      EVENTID_GP_PORTOPENED = 0x4, /* GPIO opened notification */
      EVENTID_GP_INTSTARTERROR = 0x5, /* GPIO interrupt start error notification */
      EVENTID_GP_INTWAITERROR = 0x6, /* GPIO interrupt wait error notification */
    };

    // ----------------------------------------------------------------------
    // Event Throttle values - sets initial value of countdown variable
    // ----------------------------------------------------------------------

    enum {
      EVENTID_GP_WRITEERROR_THROTTLE = 5, /*!< Throttle reset count for GP_WriteError*/
      EVENTID_GP_READERROR_THROTTLE = 5, /*!< Throttle reset count for GP_ReadError*/
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event GP_OpenError
    //!
    /* Open error */
    void log_WARNING_HI_GP_OpenError(
        I32 gpio, /*!< The device*/
        I32 error, /*!< The error code*/
        const Fw::LogStringArg& msg /*!< The error string*/
    );


    //! Log event GP_ConfigError
    //!
    /* GPIO configure error */
    void log_WARNING_HI_GP_ConfigError(
        I32 gpio, /*!< The device*/
        I32 error /*!< The error code*/
    );


    //! Log event GP_WriteError
    //!
    /* GPIO write error */
    void log_WARNING_HI_GP_WriteError(
        I32 gpio, /*!< The device*/
        I32 error /*!< The error code*/
    );

    // reset throttle value for GP_WriteError
    void log_WARNING_HI_GP_WriteError_ThrottleClear();

    //! Log event GP_ReadError
    //!
    /* GPIO read error */
    void log_WARNING_HI_GP_ReadError(
        I32 gpio, /*!< The device*/
        I32 error /*!< The error code*/
    );

    // reset throttle value for GP_ReadError
    void log_WARNING_HI_GP_ReadError_ThrottleClear();

    //! Log event GP_PortOpened
    //!
    /* GPIO opened notification */
    void log_ACTIVITY_HI_GP_PortOpened(
        I32 gpio /*!< The device*/
    );


    //! Log event GP_IntStartError
    //!
    /* GPIO interrupt start error notification */
    void log_WARNING_HI_GP_IntStartError(
        I32 gpio /*!< The device*/
    );


    //! Log event GP_IntWaitError
    //!
    /* GPIO interrupt wait error notification */
    void log_WARNING_HI_GP_IntWaitError(
        I32 gpio /*!< The device*/
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

    //! Input port gpioRead
    //!
    Drv::InputGpioReadPort m_gpioRead_InputPort[NUM_GPIOREAD_INPUT_PORTS];

    //! Input port gpioWrite
    //!
    Drv::InputGpioWritePort m_gpioWrite_InputPort[NUM_GPIOWRITE_INPUT_PORTS];

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

    //! Output port intOut
    //!
    Svc::OutputCyclePort m_intOut_OutputPort[NUM_INTOUT_OUTPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port gpioRead
    //!
    static void m_p_gpioRead_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool &state 
    );

    //! Callback for port gpioWrite
    //!
    static void m_p_gpioWrite_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        bool state 
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------
    NATIVE_UINT_TYPE m_GP_WriteErrorThrottle; //!< throttle for GP_WriteError
    NATIVE_UINT_TYPE m_GP_ReadErrorThrottle; //!< throttle for GP_ReadError

  };

} // end namespace Drv
#endif
