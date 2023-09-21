// ======================================================================
// \title  PollStatus
// \author Auto-generated
// \brief  cpp file for PollStatus
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
#include "PollStatusEnumAc.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  PollStatus :: PollStatus():Serializable()
  {
    this->e = static_cast<t>(POLL_OK);
  }

  PollStatus :: PollStatus(const t e):Serializable()
  {
    this->e = e;
  }

  PollStatus :: PollStatus(const PollStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  PollStatus& PollStatus :: operator=(const PollStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  PollStatus& PollStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  PollStatus& PollStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool PollStatus :: operator==(const PollStatus& other) const
  {
    return this->e == other.e;
  }

  bool PollStatus :: operator!=(const PollStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const PollStatus& obj) {
    os << "PollStatus::";
    const PollStatus::t e = obj.e;
    switch (e) {
        case PollStatus::POLL_OK:
          os << "POLL_OK";
          break;
        case PollStatus::POLL_RETRY:
          os << "POLL_RETRY";
          break;
        case PollStatus::POLL_ERROR:
          os << "POLL_ERROR";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus PollStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus PollStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void PollStatus :: toString(Fw::StringBase& text) const {
    const PollStatus::t e = this->e;
    switch (e) {
        case PollStatus::POLL_OK:
          text = "POLL_OK";
          break;
        case PollStatus::POLL_RETRY:
          text = "POLL_RETRY";
          break;
        case PollStatus::POLL_ERROR:
          text = "POLL_ERROR";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
