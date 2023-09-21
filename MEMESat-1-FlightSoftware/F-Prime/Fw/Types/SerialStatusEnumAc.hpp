// ======================================================================
// \title  SerialStatus.hpp
// \author Auto-generated
// \brief  hpp file for SerialStatus
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

#ifndef Fw_SerialStatus_HPP
#define Fw_SerialStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Fw {
  //! 
  //! Serialization status
  //! 
  class SerialStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    OK = 0, //!< Serialization operation succeeded
    FORMAT_ERROR = 1, //!< Data was the wrong format (e.g. wrong packet type)
    NO_ROOM_LEFT = 2, //!< No room left in the buffer to serialize data
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in SerialStatus enum
    static const U32 NUM_CONSTANTS = 3;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct SerialStatus object with default initialization
    SerialStatus();

    //! Construct SerialStatus object and initialize its value
    SerialStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    SerialStatus(
        const SerialStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    SerialStatus& operator=(
        const SerialStatus& other //!< The other object
        );

    //! Assignment operator
    SerialStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    SerialStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const SerialStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const SerialStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for SerialStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const SerialStatus& obj //!< The object
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
