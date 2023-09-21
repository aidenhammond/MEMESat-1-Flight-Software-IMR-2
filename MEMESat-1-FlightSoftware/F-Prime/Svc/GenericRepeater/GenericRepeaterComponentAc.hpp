// ======================================================================
// \title  GenericRepeaterComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for GenericRepeater component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef GENERICREPEATER_COMP_HPP_
#define GENERICREPEATER_COMP_HPP_

#include <FpConfig.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>

namespace Svc {

  //! \class GenericRepeaterComponentBase
  //! \brief Auto-generated base for GenericRepeater component
  //!
  class GenericRepeaterComponentBase :
    public Fw::PassiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class GenericRepeaterComponentBaseFriend;

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

    //! Construct a GenericRepeaterComponentBase object
    //!
    GenericRepeaterComponentBase(
        const char* compName = "" /*!< Component name*/
    );

    //! Initialize a GenericRepeaterComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a GenericRepeaterComponentBase object
    //!
    virtual ~GenericRepeaterComponentBase();

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

    //! Get the number of portIn input ports
    //!
    //! \return The number of portIn input ports
    //!
    NATIVE_INT_TYPE getNum_portIn_InputPorts();


    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------

    enum {
       NUM_PORTIN_INPUT_PORTS = 1,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of portOut output ports
    //!
    //! \return The number of portOut output ports
    //!
    NATIVE_INT_TYPE getNum_portOut_OutputPorts();


    enum {
       NUM_PORTOUT_OUTPUT_PORTS = 2,
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

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
    // Serial input ports
    // ----------------------------------------------------------------------

    //! Input port portIn
    //!
    Fw::InputSerializePort m_portIn_InputPort[NUM_PORTIN_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Serial output ports
    // ----------------------------------------------------------------------

    //! Output port portOut
    //!
    Fw::OutputSerializePort m_portOut_OutputPort[NUM_PORTOUT_OUTPUT_PORTS];

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



  };

} // end namespace Svc
#endif
