// ======================================================================
// \title  PrmDb_PrmWriteError.hpp
// \author Auto-generated
// \brief  hpp file for PrmDb_PrmWriteError
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

#ifndef Svc_PrmDb_PrmWriteError_HPP
#define Svc_PrmDb_PrmWriteError_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! Parameter write error
  //! 
  class PrmDb_PrmWriteError : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    OPEN = 0,
    DELIMITER = 1,
    DELIMITER_SIZE = 2,
    RECORD_SIZE = 3,
    RECORD_SIZE_SIZE = 4,
    PARAMETER_ID = 5,
    PARAMETER_ID_SIZE = 6,
    PARAMETER_VALUE = 7,
    PARAMETER_VALUE_SIZE = 8,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in PrmDb_PrmWriteError enum
    static const U32 NUM_CONSTANTS = 9;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct PrmDb_PrmWriteError object with default initialization
    PrmDb_PrmWriteError();

    //! Construct PrmDb_PrmWriteError object and initialize its value
    PrmDb_PrmWriteError(
        const t e //!< The enum value
        );

    //! Copy constructor
    PrmDb_PrmWriteError(
        const PrmDb_PrmWriteError& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    PrmDb_PrmWriteError& operator=(
        const PrmDb_PrmWriteError& other //!< The other object
        );

    //! Assignment operator
    PrmDb_PrmWriteError& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    PrmDb_PrmWriteError& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const PrmDb_PrmWriteError& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const PrmDb_PrmWriteError& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for PrmDb_PrmWriteError object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const PrmDb_PrmWriteError& obj //!< The object
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
