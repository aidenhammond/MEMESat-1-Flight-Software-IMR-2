// ======================================================================
// \title  DeserialStatus
// \author Auto-generated
// \brief  cpp file for DeserialStatus
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
#include "DeserialStatusEnumAc.hpp"

namespace Fw {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  DeserialStatus :: DeserialStatus():Serializable()
  {
    this->e = static_cast<t>(OK);
  }

  DeserialStatus :: DeserialStatus(const t e):Serializable()
  {
    this->e = e;
  }

  DeserialStatus :: DeserialStatus(const DeserialStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  DeserialStatus& DeserialStatus :: operator=(const DeserialStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  DeserialStatus& DeserialStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 3 || a == 4 || a == 5 || a == 6, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  DeserialStatus& DeserialStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 3 || a == 4 || a == 5 || a == 6, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool DeserialStatus :: operator==(const DeserialStatus& other) const
  {
    return this->e == other.e;
  }

  bool DeserialStatus :: operator!=(const DeserialStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const DeserialStatus& obj) {
    os << "DeserialStatus::";
    const DeserialStatus::t e = obj.e;
    switch (e) {
        case DeserialStatus::OK:
          os << "OK";
          break;
        case DeserialStatus::BUFFER_EMPTY:
          os << "BUFFER_EMPTY";
          break;
        case DeserialStatus::FORMAT_ERROR:
          os << "FORMAT_ERROR";
          break;
        case DeserialStatus::SIZE_MISMATCH:
          os << "SIZE_MISMATCH";
          break;
        case DeserialStatus::TYPE_MISMATCH:
          os << "TYPE_MISMATCH";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus DeserialStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus DeserialStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void DeserialStatus :: toString(Fw::StringBase& text) const {
    const DeserialStatus::t e = this->e;
    switch (e) {
        case DeserialStatus::OK:
          text = "OK";
          break;
        case DeserialStatus::BUFFER_EMPTY:
          text = "BUFFER_EMPTY";
          break;
        case DeserialStatus::FORMAT_ERROR:
          text = "FORMAT_ERROR";
          break;
        case DeserialStatus::SIZE_MISMATCH:
          text = "SIZE_MISMATCH";
          break;
        case DeserialStatus::TYPE_MISMATCH:
          text = "TYPE_MISMATCH";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
