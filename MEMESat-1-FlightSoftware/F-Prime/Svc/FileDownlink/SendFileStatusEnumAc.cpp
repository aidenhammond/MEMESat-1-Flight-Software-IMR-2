// ======================================================================
// \title  SendFileStatus
// \author Auto-generated
// \brief  cpp file for SendFileStatus
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
#include "SendFileStatusEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SendFileStatus :: SendFileStatus():Serializable()
  {
    this->e = static_cast<t>(STATUS_OK);
  }

  SendFileStatus :: SendFileStatus(const t e):Serializable()
  {
    this->e = e;
  }

  SendFileStatus :: SendFileStatus(const SendFileStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  SendFileStatus& SendFileStatus :: operator=(const SendFileStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  SendFileStatus& SendFileStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  SendFileStatus& SendFileStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool SendFileStatus :: operator==(const SendFileStatus& other) const
  {
    return this->e == other.e;
  }

  bool SendFileStatus :: operator!=(const SendFileStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SendFileStatus& obj) {
    os << "SendFileStatus::";
    const SendFileStatus::t e = obj.e;
    switch (e) {
        case SendFileStatus::STATUS_OK:
          os << "STATUS_OK";
          break;
        case SendFileStatus::STATUS_ERROR:
          os << "STATUS_ERROR";
          break;
        case SendFileStatus::STATUS_INVALID:
          os << "STATUS_INVALID";
          break;
        case SendFileStatus::STATUS_BUSY:
          os << "STATUS_BUSY";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus SendFileStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus SendFileStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void SendFileStatus :: toString(Fw::StringBase& text) const {
    const SendFileStatus::t e = this->e;
    switch (e) {
        case SendFileStatus::STATUS_OK:
          text = "STATUS_OK";
          break;
        case SendFileStatus::STATUS_ERROR:
          text = "STATUS_ERROR";
          break;
        case SendFileStatus::STATUS_INVALID:
          text = "STATUS_INVALID";
          break;
        case SendFileStatus::STATUS_BUSY:
          text = "STATUS_BUSY";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
