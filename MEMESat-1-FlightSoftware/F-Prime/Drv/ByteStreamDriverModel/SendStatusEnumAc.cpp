// ======================================================================
// \title  SendStatus
// \author Auto-generated
// \brief  cpp file for SendStatus
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
#include "SendStatusEnumAc.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SendStatus :: SendStatus():Serializable()
  {
    this->e = static_cast<t>(SEND_OK);
  }

  SendStatus :: SendStatus(const t e):Serializable()
  {
    this->e = e;
  }

  SendStatus :: SendStatus(const SendStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  SendStatus& SendStatus :: operator=(const SendStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  SendStatus& SendStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  SendStatus& SendStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool SendStatus :: operator==(const SendStatus& other) const
  {
    return this->e == other.e;
  }

  bool SendStatus :: operator!=(const SendStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SendStatus& obj) {
    os << "SendStatus::";
    const SendStatus::t e = obj.e;
    switch (e) {
        case SendStatus::SEND_OK:
          os << "SEND_OK";
          break;
        case SendStatus::SEND_RETRY:
          os << "SEND_RETRY";
          break;
        case SendStatus::SEND_ERROR:
          os << "SEND_ERROR";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus SendStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus SendStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void SendStatus :: toString(Fw::StringBase& text) const {
    const SendStatus::t e = this->e;
    switch (e) {
        case SendStatus::SEND_OK:
          text = "SEND_OK";
          break;
        case SendStatus::SEND_RETRY:
          text = "SEND_RETRY";
          break;
        case SendStatus::SEND_ERROR:
          text = "SEND_ERROR";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
