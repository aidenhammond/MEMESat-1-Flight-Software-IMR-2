// ======================================================================
// \title  ActiveLogger_Enabled
// \author Auto-generated
// \brief  cpp file for ActiveLogger_Enabled
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
#include "ActiveLogger_EnabledEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  ActiveLogger_Enabled :: ActiveLogger_Enabled():Serializable()
  {
    this->e = static_cast<t>(ENABLED);
  }

  ActiveLogger_Enabled :: ActiveLogger_Enabled(const t e):Serializable()
  {
    this->e = e;
  }

  ActiveLogger_Enabled :: ActiveLogger_Enabled(const ActiveLogger_Enabled& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  ActiveLogger_Enabled& ActiveLogger_Enabled :: operator=(const ActiveLogger_Enabled& other)
  {
    this->e = other.e;
    return *this;
  }

  ActiveLogger_Enabled& ActiveLogger_Enabled :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  ActiveLogger_Enabled& ActiveLogger_Enabled :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool ActiveLogger_Enabled :: operator==(const ActiveLogger_Enabled& other) const
  {
    return this->e == other.e;
  }

  bool ActiveLogger_Enabled :: operator!=(const ActiveLogger_Enabled& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const ActiveLogger_Enabled& obj) {
    os << "ActiveLogger_Enabled::";
    const ActiveLogger_Enabled::t e = obj.e;
    switch (e) {
        case ActiveLogger_Enabled::ENABLED:
          os << "ENABLED";
          break;
        case ActiveLogger_Enabled::DISABLED:
          os << "DISABLED";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus ActiveLogger_Enabled :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus ActiveLogger_Enabled :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void ActiveLogger_Enabled :: toString(Fw::StringBase& text) const {
    const ActiveLogger_Enabled::t e = this->e;
    switch (e) {
        case ActiveLogger_Enabled::ENABLED:
          text = "ENABLED";
          break;
        case ActiveLogger_Enabled::DISABLED:
          text = "DISABLED";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
