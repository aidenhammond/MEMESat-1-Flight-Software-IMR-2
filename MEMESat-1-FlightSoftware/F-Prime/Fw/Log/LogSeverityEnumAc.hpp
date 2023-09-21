// ======================================================================
// \title  LogSeverity.hpp
// \author Auto-generated
// \brief  hpp file for LogSeverity
//
// \copyright
// Copyright (C) 2018 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
//
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ======================================================================

#ifndef Fw_LogSeverity_HPP
#define Fw_LogSeverity_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Fw {
  //! 
  //! Enum representing event severity
  //! 
  class LogSeverity : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    FATAL = 1, //!< A fatal non-recoverable event
    WARNING_HI = 2, //!< A serious but recoverable event
    WARNING_LO = 3, //!< A less serious but recoverable event
    COMMAND = 4, //!< An activity related to commanding
    ACTIVITY_HI = 5, //!< Important informational events
    ACTIVITY_LO = 6, //!< Less important informational events
    DIAGNOSTIC = 7, //!< Software diagnostic events
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in LogSeverity enum
    static const U32 NUM_CONSTANTS = 7;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct LogSeverity object with default initialization
    LogSeverity();

    //! Construct LogSeverity object and initialize its value
    LogSeverity(
        const t e //!< The enum value
        );

    //! Copy constructor
    LogSeverity(
        const LogSeverity& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    LogSeverity& operator=(
        const LogSeverity& other //!< The other object
        );

    //! Assignment operator
    LogSeverity& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    LogSeverity& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const LogSeverity& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const LogSeverity& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for LogSeverity object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const LogSeverity& obj //!< The object
        );
#endif

    public:

    // ----------------------------------------------------------------------
    // Methods
    // ----------------------------------------------------------------------

    //! Serialization
    Fw::SerializeStatus serialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
        ) const;

    //! Deserialization
    Fw::SerializeStatus deserialize(
        Fw::SerializeBufferBase& buffer //!< The serial buffer
        );

#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    //! ENUM toString
    void toString(Fw::StringBase& text) const;  //!< generate text from serializable
#endif

    public:

    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The enumeration value
    t e;
  };
}
#endif
