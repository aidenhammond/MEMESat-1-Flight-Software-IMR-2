// ======================================================================
// \title  I2cStatus.hpp
// \author Auto-generated
// \brief  hpp file for I2cStatus
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

#ifndef Drv_I2cStatus_HPP
#define Drv_I2cStatus_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Drv {
  class I2cStatus : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    I2C_OK = 0, //!< Transaction okay
    I2C_ADDRESS_ERR = 1, //!< I2C address invalid
    I2C_WRITE_ERR = 2, //!< I2C write failed
    I2C_READ_ERR = 3, //!< I2C read failed
    I2C_OTHER_ERR = 4, //!< Other errors that don't fit
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in I2cStatus enum
    static const U32 NUM_CONSTANTS = 5;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct I2cStatus object with default initialization
    I2cStatus();

    //! Construct I2cStatus object and initialize its value
    I2cStatus(
        const t e //!< The enum value
        );

    //! Copy constructor
    I2cStatus(
        const I2cStatus& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    I2cStatus& operator=(
        const I2cStatus& other //!< The other object
        );

    //! Assignment operator
    I2cStatus& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    I2cStatus& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const I2cStatus& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const I2cStatus& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for I2cStatus object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const I2cStatus& obj //!< The object
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
