// ======================================================================
// \title  DeserialStatus.hpp
// \author Auto-generated
// \brief  hpp file for DeserialStatus
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

#ifndef Fw_DeserialStatus_HPP
#define Fw_DeserialStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Fw {
  //! 
  //! Deserialization status
  //! 
  class DeserialStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    OK = 0,
    BUFFER_EMPTY = 3, //!< Deserialization buffer was empty when trying to read data
    FORMAT_ERROR = 4, //!< Deserialization data had incorrect values (unexpected data types)
    SIZE_MISMATCH = 5, //!< Data was left in in the buffer, but not enough to deserialize
    TYPE_MISMATCH = 6, //!< Deserialized type ID didn't match
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in DeserialStatus enum
    static const U32 NUM_CONSTANTS = 5;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct DeserialStatus object with default initialization
    DeserialStatus();

    //! Construct DeserialStatus object and initialize its value
    DeserialStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    DeserialStatus(
        const DeserialStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    DeserialStatus& operator=(
        const DeserialStatus& other //!< The other object
        );

    //! Assignment operator
    DeserialStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    DeserialStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const DeserialStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const DeserialStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for DeserialStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const DeserialStatus& obj //!< The object
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
