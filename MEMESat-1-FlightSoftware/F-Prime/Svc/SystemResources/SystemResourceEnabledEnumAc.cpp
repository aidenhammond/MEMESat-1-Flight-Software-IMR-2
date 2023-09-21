// ======================================================================
// \title  SystemResourceEnabled
// \author Auto-generated
// \brief  cpp file for SystemResourceEnabled
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
#include "SystemResourceEnabledEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  SystemResourceEnabled :: SystemResourceEnabled():Serializable()
  {
    this->e = static_cast<t>(DISABLED);
  }

  SystemResourceEnabled :: SystemResourceEnabled(const t e):Serializable()
  {
    this->e = e;
  }

  SystemResourceEnabled :: SystemResourceEnabled(const SystemResourceEnabled& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  SystemResourceEnabled& SystemResourceEnabled :: operator=(const SystemResourceEnabled& other)
  {
    this->e = other.e;
    return *this;
  }

  SystemResourceEnabled& SystemResourceEnabled :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  SystemResourceEnabled& SystemResourceEnabled :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool SystemResourceEnabled :: operator==(const SystemResourceEnabled& other) const
  {
    return this->e == other.e;
  }

  bool SystemResourceEnabled :: operator!=(const SystemResourceEnabled& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const SystemResourceEnabled& obj) {
    os << "SystemResourceEnabled::";
    const SystemResourceEnabled::t e = obj.e;
    switch (e) {
        case SystemResourceEnabled::DISABLED:
          os << "DISABLED";
          break;
        case SystemResourceEnabled::ENABLED:
          os << "ENABLED";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus SystemResourceEnabled :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus SystemResourceEnabled :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void SystemResourceEnabled :: toString(Fw::StringBase& text) const {
    const SystemResourceEnabled::t e = this->e;
    switch (e) {
        case SystemResourceEnabled::DISABLED:
          text = "DISABLED";
          break;
        case SystemResourceEnabled::ENABLED:
          text = "ENABLED";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
