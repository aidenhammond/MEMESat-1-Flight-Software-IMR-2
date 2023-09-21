// ======================================================================
// \title  CmdSequencer_BlockState.hpp
// \author Auto-generated
// \brief  hpp file for CmdSequencer_BlockState
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

#ifndef Svc_CmdSequencer_BlockState_HPP
#define Svc_CmdSequencer_BlockState_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! Sequencer blocking state
  //! 
  class CmdSequencer_BlockState : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    BLOCK = 0,
    NO_BLOCK = 1,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in CmdSequencer_BlockState enum
    static const U32 NUM_CONSTANTS = 2;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct CmdSequencer_BlockState object with default initialization
    CmdSequencer_BlockState();

    //! Construct CmdSequencer_BlockState object and initialize its value
    CmdSequencer_BlockState(
        const t e //!< The enum value
        );

    //! Copy constructor
    CmdSequencer_BlockState(
        const CmdSequencer_BlockState& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    CmdSequencer_BlockState& operator=(
        const CmdSequencer_BlockState& other //!< The other object
        );

    //! Assignment operator
    CmdSequencer_BlockState& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    CmdSequencer_BlockState& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const CmdSequencer_BlockState& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const CmdSequencer_BlockState& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for CmdSequencer_BlockState object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const CmdSequencer_BlockState& obj //!< The object
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
