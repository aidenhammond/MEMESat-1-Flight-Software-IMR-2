// ======================================================================
// \title  CmdSequencer_SeqMode
// \author Auto-generated
// \brief  cpp file for CmdSequencer_SeqMode
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
#include "CmdSequencer_SeqModeEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  CmdSequencer_SeqMode :: CmdSequencer_SeqMode():Serializable()
  {
    this->e = static_cast<t>(STEP);
  }

  CmdSequencer_SeqMode :: CmdSequencer_SeqMode(const t e):Serializable()
  {
    this->e = e;
  }

  CmdSequencer_SeqMode :: CmdSequencer_SeqMode(const CmdSequencer_SeqMode& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  CmdSequencer_SeqMode& CmdSequencer_SeqMode :: operator=(const CmdSequencer_SeqMode& other)
  {
    this->e = other.e;
    return *this;
  }

  CmdSequencer_SeqMode& CmdSequencer_SeqMode :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  CmdSequencer_SeqMode& CmdSequencer_SeqMode :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool CmdSequencer_SeqMode :: operator==(const CmdSequencer_SeqMode& other) const
  {
    return this->e == other.e;
  }

  bool CmdSequencer_SeqMode :: operator!=(const CmdSequencer_SeqMode& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const CmdSequencer_SeqMode& obj) {
    os << "CmdSequencer_SeqMode::";
    const CmdSequencer_SeqMode::t e = obj.e;
    switch (e) {
        case CmdSequencer_SeqMode::STEP:
          os << "STEP";
          break;
        case CmdSequencer_SeqMode::AUTO:
          os << "AUTO";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus CmdSequencer_SeqMode :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus CmdSequencer_SeqMode :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void CmdSequencer_SeqMode :: toString(Fw::StringBase& text) const {
    const CmdSequencer_SeqMode::t e = this->e;
    switch (e) {
        case CmdSequencer_SeqMode::STEP:
          text = "STEP";
          break;
        case CmdSequencer_SeqMode::AUTO:
          text = "AUTO";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
