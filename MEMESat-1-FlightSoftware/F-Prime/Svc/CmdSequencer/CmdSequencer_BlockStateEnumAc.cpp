// ======================================================================
// \title  CmdSequencer_BlockState
// \author Auto-generated
// \brief  cpp file for CmdSequencer_BlockState
//
// \copyright
// Copyright 2018 California Institute of Technology.
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

#include <cstring>
#include <limits>
#include "Fw/Types/Assert.hpp"
#include "CmdSequencer_BlockStateEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  CmdSequencer_BlockState :: CmdSequencer_BlockState():Serializable()
  {
    this->e = static_cast<t>(BLOCK);
  }

  CmdSequencer_BlockState :: CmdSequencer_BlockState(const t e):Serializable()
  {
    this->e = e;
  }

  CmdSequencer_BlockState :: CmdSequencer_BlockState(const CmdSequencer_BlockState& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  CmdSequencer_BlockState& CmdSequencer_BlockState :: operator=(const CmdSequencer_BlockState& other)
  {
    this->e = other.e;
    return *this;
  }

  CmdSequencer_BlockState& CmdSequencer_BlockState :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  CmdSequencer_BlockState& CmdSequencer_BlockState :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool CmdSequencer_BlockState :: operator==(const CmdSequencer_BlockState& other) const
  {
    return this->e == other.e;
  }

  bool CmdSequencer_BlockState :: operator!=(const CmdSequencer_BlockState& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const CmdSequencer_BlockState& obj) {
    os << "CmdSequencer_BlockState::";
    const CmdSequencer_BlockState::t e = obj.e;
    switch (e) {
        case CmdSequencer_BlockState::BLOCK:
          os << "BLOCK";
          break;
        case CmdSequencer_BlockState::NO_BLOCK:
          os << "NO_BLOCK";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus CmdSequencer_BlockState :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus CmdSequencer_BlockState :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void CmdSequencer_BlockState :: toString(Fw::StringBase& text) const {
    const CmdSequencer_BlockState::t e = this->e;
    switch (e) {
        case CmdSequencer_BlockState::BLOCK:
          text = "BLOCK";
          break;
        case CmdSequencer_BlockState::NO_BLOCK:
          text = "NO_BLOCK";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
