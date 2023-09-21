// ======================================================================
// \title  CmdSequencer_FileReadStage.hpp
// \author Auto-generated
// \brief  hpp file for CmdSequencer_FileReadStage
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

#ifndef Svc_CmdSequencer_FileReadStage_HPP
#define Svc_CmdSequencer_FileReadStage_HPP

#include "Fw/Types/String.hpp"
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Serializable.hpp"

namespace Svc {
  //! 
  //! The stage of the file read operation
  //! 
  class CmdSequencer_FileReadStage : public Fw::Serializable
  {
    public:
    // ----------------------------------------------------------------------
    // Types
    // ----------------------------------------------------------------------

    typedef enum {
    READ_HEADER = 0,
    READ_HEADER_SIZE = 1,
    DESER_SIZE = 2,
    DESER_NUM_RECORDS = 3,
    DESER_TIME_BASE = 4,
    DESER_TIME_CONTEXT = 5,
    READ_SEQ_CRC = 6,
    READ_SEQ_DATA = 7,
    READ_SEQ_DATA_SIZE = 8,
        } t;

    public:

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum {
        SERIALIZED_SIZE = sizeof(I32)
        };

    //! Number of items in CmdSequencer_FileReadStage enum
    static const U32 NUM_CONSTANTS = 9;

    public:

    // ----------------------------------------------------------------------
    // Constructors
    // ----------------------------------------------------------------------

    //! Construct CmdSequencer_FileReadStage object with default initialization
    CmdSequencer_FileReadStage();

    //! Construct CmdSequencer_FileReadStage object and initialize its value
    CmdSequencer_FileReadStage(
        const t e //!< The enum value
        );

    //! Copy constructor
    CmdSequencer_FileReadStage(
        const CmdSequencer_FileReadStage& other //!< The other object
        );

    public:

    // ----------------------------------------------------------------------
    // Operators
    // ----------------------------------------------------------------------

    //! Assignment operator
    CmdSequencer_FileReadStage& operator=(
        const CmdSequencer_FileReadStage& other //!< The other object
        );

    //! Assignment operator
    CmdSequencer_FileReadStage& operator=(
        const NATIVE_INT_TYPE a //!< The integer to copy
        );

    //! Assignment operator
    CmdSequencer_FileReadStage& operator=(
        const NATIVE_UINT_TYPE a //!< The integer to copy
        );

    //! Equality operator
    bool operator==(
        const CmdSequencer_FileReadStage& other //!< The other object
        ) const;

    //! Inequality operator
    bool operator!=(
        const CmdSequencer_FileReadStage& other //!< The other object
        ) const;

#ifdef BUILD_UT
    //! Ostream operator for CmdSequencer_FileReadStage object
    friend std::ostream& operator<<(
        std::ostream& os, //!< The ostream
        const CmdSequencer_FileReadStage& obj //!< The object
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
