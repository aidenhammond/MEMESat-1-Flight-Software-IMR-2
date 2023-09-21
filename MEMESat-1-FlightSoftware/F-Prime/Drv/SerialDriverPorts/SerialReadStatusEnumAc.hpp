// ======================================================================
// \title  SerialReadStatus.hpp
// \author Auto-generated
// \brief  hpp file for SerialReadStatus
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

#ifndef Drv_SerialReadStatus_HPP
#define Drv_SerialReadStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Drv {
  class SerialReadStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    SER_OK = 0, //!< Transaction okay
    SER_PARITY_ERR = 1, //!< Parity error on data
    SER_NO_BUFFERS = 2, //!< Serial driver ran out of buffers
    SER_BUFFER_TOO_SMALL = 3, //!< Target buffer is too small
    SER_OTHER_ERR = 4, //!< Other errors that don't fit
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in SerialReadStatus enum
    static const U32 NUM_CONSTANTS = 5;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct SerialReadStatus object with default initialization
    SerialReadStatus();

    //! Construct SerialReadStatus object and initialize its value
    SerialReadStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    SerialReadStatus(
        const SerialReadStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    SerialReadStatus& operator=(
        const SerialReadStatus& other //!< The other object
        );

    //! Assignment operator
    SerialReadStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    SerialReadStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const SerialReadStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const SerialReadStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for SerialReadStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const SerialReadStatus& obj //!< The object
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
