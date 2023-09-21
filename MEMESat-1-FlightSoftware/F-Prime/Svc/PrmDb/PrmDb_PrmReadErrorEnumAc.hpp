// ======================================================================
// \title  PrmDb_PrmReadError.hpp
// \author Auto-generated
// \brief  hpp file for PrmDb_PrmReadError
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

#ifndef Svc_PrmDb_PrmReadError_HPP
#define Svc_PrmDb_PrmReadError_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! Parameter read error
  //! 
  class PrmDb_PrmReadError : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    OPEN = 0,
    DELIMITER = 1,
    DELIMITER_SIZE = 2,
    DELIMITER_VALUE = 3,
    RECORD_SIZE = 4,
    RECORD_SIZE_SIZE = 5,
    RECORD_SIZE_VALUE = 6,
    PARAMETER_ID = 7,
    PARAMETER_ID_SIZE = 8,
    PARAMETER_VALUE = 9,
    PARAMETER_VALUE_SIZE = 10,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in PrmDb_PrmReadError enum
    static const U32 NUM_CONSTANTS = 11;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct PrmDb_PrmReadError object with default initialization
    PrmDb_PrmReadError();

    //! Construct PrmDb_PrmReadError object and initialize its value
    PrmDb_PrmReadError(
        const t e //!< The enum value
        );

    //! Copy constructor
    PrmDb_PrmReadError(
        const PrmDb_PrmReadError& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    PrmDb_PrmReadError& operator=(
        const PrmDb_PrmReadError& other //!< The other object
        );

    //! Assignment operator
    PrmDb_PrmReadError& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    PrmDb_PrmReadError& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const PrmDb_PrmReadError& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const PrmDb_PrmReadError& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for PrmDb_PrmReadError object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const PrmDb_PrmReadError& obj //!< The object
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
