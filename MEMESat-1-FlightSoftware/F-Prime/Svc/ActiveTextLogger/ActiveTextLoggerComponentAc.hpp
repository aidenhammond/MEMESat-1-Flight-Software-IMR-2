// ======================================================================
// \title  ActiveTextLoggerComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for ActiveTextLogger component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ACTIVETEXTLOGGER_COMP_HPP_
#define ACTIVETEXTLOGGER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Types/InternalInterfaceString.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif

namespace Svc {

  //! \class ActiveTextLoggerComponentBase
  //! \brief Auto-generated base for ActiveTextLogger component
  //!
  class ActiveTextLoggerComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class ActiveTextLoggerComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return TextLogger[portNum]
    //!
    Fw::InputLogTextPort* get_TextLogger_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

    //! Construct a ActiveTextLoggerComponentBase object
    //!
    ActiveTextLoggerComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a ActiveTextLoggerComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a ActiveTextLoggerComponentBase object
    //!
    virtual ~ActiveTextLoggerComponentBase();

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port TextLogger
    //
    virtual void TextLogger_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType id, /*!< 
      Log ID
      */
        Fw::Time &timeTag, /*!< 
      Time Tag
      */
        const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
        Fw::TextLogString &text /*!< 
      Text of log message
      */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port TextLogger
    //!
    void TextLogger_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType id, /*!< 
      Log ID
      */
        Fw::Time &timeTag, /*!< 
      Time Tag
      */
        const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
        Fw::TextLogString &text /*!< 
      Text of log message
      */
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of TextLogger input ports
    //!
    //! \return The number of TextLogger input ports
    //!
    NATIVE_INT_TYPE getNum_TextLogger_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_TEXTLOGGER_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

  PROTECTED:

    // ----------------------------------------------------------------------
    // Internal interface handlers
    // ----------------------------------------------------------------------

    //! Internal Interface handler for TextQueue
    //!
    virtual void TextQueue_internalInterfaceHandler(
        const Fw::InternalInterfaceString& text /*!< 
          The text string
          */
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Internal interface base-class functions
    // ----------------------------------------------------------------------

    //! Base class function for TextQueue
    //!
    void TextQueue_internalInterfaceInvoke(
        const Fw::InternalInterfaceString& text /*!< 
          The text string
          */
    );



  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port TextLogger
    //!
    Fw::InputLogTextPort m_TextLogger_InputPort[NUM_TEXTLOGGER_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port TextLogger
    //!
    static void m_p_TextLogger_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwEventIdType id, /*!< 
      Log ID
      */
        Fw::Time &timeTag, /*!< 
      Time Tag
      */
        const Fw::LogSeverity &severity, /*!< 
      The severity argument
      */
        Fw::TextLogString &text /*!< 
      Text of log message
      */
    );

  PRIVATE:

    // ----------------------------------------------------------------------
    // Message dispatch functions
    // ----------------------------------------------------------------------

    //! Called in the message loop to dispatch a message from the queue
    //!
    virtual MsgDispatchStatus doDispatch();



  };

} // end namespace Svc
#endif
