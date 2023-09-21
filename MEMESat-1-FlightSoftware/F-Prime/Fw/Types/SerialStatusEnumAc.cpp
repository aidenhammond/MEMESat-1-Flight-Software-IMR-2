// ======================================================================
// \title  SerialStatus
// \author Auto-generated
// \brief  cpp file for SerialStatus
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
#include "SerialStatusEnumAc.hpp"

namespace Fw {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SerialStatus :: SerialStatus():Serializable()
  {
    this->e = static_cast<t>(OK);
  }

  SerialStatus :: SerialStatus(const t e):Serializable()
  {
    this->e = e;
  }

  SerialStatus :: SerialStatus(const SerialStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  SerialStatus& SerialStatus :: operator=(const SerialStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  SerialStatus& SerialStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  SerialStatus& SerialStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool SerialStatus :: operator==(const SerialStatus& other) const
  {
    return this->e == other.e;
  }

  bool SerialStatus :: operator!=(const SerialStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SerialStatus& obj) {
    os << "SerialStatus::";
    const SerialStatus::t e = obj.e;
    switch (e) {
        case SerialStatus::OK:
          os << "OK";
          break;
        case SerialStatus::FORMAT_ERROR:
          os << "FORMAT_ERROR";
          break;
        case SerialStatus::NO_ROOM_LEFT:
          os << "NO_ROOM_LEFT";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus SerialStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus SerialStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void SerialStatus :: toString(Fw::StringBase& text) const {
    const SerialStatus::t e = this->e;
    switch (e) {
        case SerialStatus::OK:
          text = "OK";
          break;
        case SerialStatus::FORMAT_ERROR:
          text = "FORMAT_ERROR";
          break;
        case SerialStatus::NO_ROOM_LEFT:
          text = "NO_ROOM_LEFT";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
