// ======================================================================
// \title  BufferLogger_LogState
// \author Auto-generated
// \brief  cpp file for BufferLogger_LogState
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
#include "BufferLogger_LogStateEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  BufferLogger_LogState :: BufferLogger_LogState():Serializable()
  {
    this->e = static_cast<t>(LOGGING_ON);
  }

  BufferLogger_LogState :: BufferLogger_LogState(const t e):Serializable()
  {
    this->e = e;
  }

  BufferLogger_LogState :: BufferLogger_LogState(const BufferLogger_LogState& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  BufferLogger_LogState& BufferLogger_LogState :: operator=(const BufferLogger_LogState& other)
  {
    this->e = other.e;
    return *this;
  }

  BufferLogger_LogState& BufferLogger_LogState :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  BufferLogger_LogState& BufferLogger_LogState :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool BufferLogger_LogState :: operator==(const BufferLogger_LogState& other) const
  {
    return this->e == other.e;
  }

  bool BufferLogger_LogState :: operator!=(const BufferLogger_LogState& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const BufferLogger_LogState& obj) {
    os << "BufferLogger_LogState::";
    const BufferLogger_LogState::t e = obj.e;
    switch (e) {
        case BufferLogger_LogState::LOGGING_ON:
          os << "LOGGING_ON";
          break;
        case BufferLogger_LogState::LOGGING_OFF:
          os << "LOGGING_OFF";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus BufferLogger_LogState :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus BufferLogger_LogState :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void BufferLogger_LogState :: toString(Fw::StringBase& text) const {
    const BufferLogger_LogState::t e = this->e;
    switch (e) {
        case BufferLogger_LogState::LOGGING_ON:
          text = "LOGGING_ON";
          break;
        case BufferLogger_LogState::LOGGING_OFF:
          text = "LOGGING_OFF";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
