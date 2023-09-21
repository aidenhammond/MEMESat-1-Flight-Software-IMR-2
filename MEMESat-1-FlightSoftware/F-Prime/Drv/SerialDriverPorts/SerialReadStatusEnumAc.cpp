// ======================================================================
// \title  SerialReadStatus
// \author Auto-generated
// \brief  cpp file for SerialReadStatus
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
#include "SerialReadStatusEnumAc.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SerialReadStatus :: SerialReadStatus():Serializable()
  {
    this->e = static_cast<t>(SER_OK);
  }

  SerialReadStatus :: SerialReadStatus(const t e):Serializable()
  {
    this->e = e;
  }

  SerialReadStatus :: SerialReadStatus(const SerialReadStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  SerialReadStatus& SerialReadStatus :: operator=(const SerialReadStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  SerialReadStatus& SerialReadStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  SerialReadStatus& SerialReadStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool SerialReadStatus :: operator==(const SerialReadStatus& other) const
  {
    return this->e == other.e;
  }

  bool SerialReadStatus :: operator!=(const SerialReadStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SerialReadStatus& obj) {
    os << "SerialReadStatus::";
    const SerialReadStatus::t e = obj.e;
    switch (e) {
        case SerialReadStatus::SER_OK:
          os << "SER_OK";
          break;
        case SerialReadStatus::SER_PARITY_ERR:
          os << "SER_PARITY_ERR";
          break;
        case SerialReadStatus::SER_NO_BUFFERS:
          os << "SER_NO_BUFFERS";
          break;
        case SerialReadStatus::SER_BUFFER_TOO_SMALL:
          os << "SER_BUFFER_TOO_SMALL";
          break;
        case SerialReadStatus::SER_OTHER_ERR:
          os << "SER_OTHER_ERR";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus SerialReadStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus SerialReadStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void SerialReadStatus :: toString(Fw::StringBase& text) const {
    const SerialReadStatus::t e = this->e;
    switch (e) {
        case SerialReadStatus::SER_OK:
          text = "SER_OK";
          break;
        case SerialReadStatus::SER_PARITY_ERR:
          text = "SER_PARITY_ERR";
          break;
        case SerialReadStatus::SER_NO_BUFFERS:
          text = "SER_NO_BUFFERS";
          break;
        case SerialReadStatus::SER_BUFFER_TOO_SMALL:
          text = "SER_BUFFER_TOO_SMALL";
          break;
        case SerialReadStatus::SER_OTHER_ERR:
          text = "SER_OTHER_ERR";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
