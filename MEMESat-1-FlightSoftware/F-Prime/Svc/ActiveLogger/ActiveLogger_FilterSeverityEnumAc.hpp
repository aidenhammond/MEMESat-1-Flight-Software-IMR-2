// ======================================================================
// \title  ActiveLogger_FilterSeverity.hpp
// \author Auto-generated
// \brief  hpp file for ActiveLogger_FilterSeverity
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

#ifndef Svc_ActiveLogger_FilterSeverity_HPP
#define Svc_ActiveLogger_FilterSeverity_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! Severity level for event filtering
  //! Similar to Fw::LogSeverity, but no FATAL event
  //! 
  class ActiveLogger_FilterSeverity : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    WARNING_HI = 0, //!< Filter WARNING_HI events
    WARNING_LO = 1, //!< Filter WARNING_LO events
    COMMAND = 2, //!< Filter COMMAND events
    ACTIVITY_HI = 3, //!< Filter ACTIVITY_HI events
    ACTIVITY_LO = 4, //!< Filter ACTIVITY_LO events
    DIAGNOSTIC = 5, //!< Filter DIAGNOSTIC events
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in ActiveLogger_FilterSeverity enum
    static const U32 NUM_CONSTANTS = 6;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct ActiveLogger_FilterSeverity object with default initialization
    ActiveLogger_FilterSeverity();

    //! Construct ActiveLogger_FilterSeverity object and initialize its value
    ActiveLogger_FilterSeverity(
        const t e //!< The enum value
        );

    //! Copy constructor
    ActiveLogger_FilterSeverity(
        const ActiveLogger_FilterSeverity& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    ActiveLogger_FilterSeverity& operator=(
        const ActiveLogger_FilterSeverity& other //!< The other object
        );

    //! Assignment operator
    ActiveLogger_FilterSeverity& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    ActiveLogger_FilterSeverity& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const ActiveLogger_FilterSeverity& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const ActiveLogger_FilterSeverity& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for ActiveLogger_FilterSeverity object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const ActiveLogger_FilterSeverity& obj //!< The object
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
