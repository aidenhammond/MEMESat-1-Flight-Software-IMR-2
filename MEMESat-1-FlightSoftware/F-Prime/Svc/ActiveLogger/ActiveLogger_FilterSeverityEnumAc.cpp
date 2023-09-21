// ======================================================================
// \title  ActiveLogger_FilterSeverity
// \author Auto-generated
// \brief  cpp file for ActiveLogger_FilterSeverity
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
#include "ActiveLogger_FilterSeverityEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  ActiveLogger_FilterSeverity :: ActiveLogger_FilterSeverity():Serializable()
  {
    this->e = static_cast<t>(WARNING_HI);
  }

  ActiveLogger_FilterSeverity :: ActiveLogger_FilterSeverity(const t e):Serializable()
  {
    this->e = e;
  }

  ActiveLogger_FilterSeverity :: ActiveLogger_FilterSeverity(const ActiveLogger_FilterSeverity& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  ActiveLogger_FilterSeverity& ActiveLogger_FilterSeverity :: operator=(const ActiveLogger_FilterSeverity& other)
  {
    this->e = other.e;
    return *this;
  }

  ActiveLogger_FilterSeverity& ActiveLogger_FilterSeverity :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  ActiveLogger_FilterSeverity& ActiveLogger_FilterSeverity :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool ActiveLogger_FilterSeverity :: operator==(const ActiveLogger_FilterSeverity& other) const
  {
    return this->e == other.e;
  }

  bool ActiveLogger_FilterSeverity :: operator!=(const ActiveLogger_FilterSeverity& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const ActiveLogger_FilterSeverity& obj) {
    os << "ActiveLogger_FilterSeverity::";
    const ActiveLogger_FilterSeverity::t e = obj.e;
    switch (e) {
        case ActiveLogger_FilterSeverity::WARNING_HI:
          os << "WARNING_HI";
          break;
        case ActiveLogger_FilterSeverity::WARNING_LO:
          os << "WARNING_LO";
          break;
        case ActiveLogger_FilterSeverity::COMMAND:
          os << "COMMAND";
          break;
        case ActiveLogger_FilterSeverity::ACTIVITY_HI:
          os << "ACTIVITY_HI";
          break;
        case ActiveLogger_FilterSeverity::ACTIVITY_LO:
          os << "ACTIVITY_LO";
          break;
        case ActiveLogger_FilterSeverity::DIAGNOSTIC:
          os << "DIAGNOSTIC";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus ActiveLogger_FilterSeverity :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus ActiveLogger_FilterSeverity :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void ActiveLogger_FilterSeverity :: toString(Fw::StringBase& text) const {
    const ActiveLogger_FilterSeverity::t e = this->e;
    switch (e) {
        case ActiveLogger_FilterSeverity::WARNING_HI:
          text = "WARNING_HI";
          break;
        case ActiveLogger_FilterSeverity::WARNING_LO:
          text = "WARNING_LO";
          break;
        case ActiveLogger_FilterSeverity::COMMAND:
          text = "COMMAND";
          break;
        case ActiveLogger_FilterSeverity::ACTIVITY_HI:
          text = "ACTIVITY_HI";
          break;
        case ActiveLogger_FilterSeverity::ACTIVITY_LO:
          text = "ACTIVITY_LO";
          break;
        case ActiveLogger_FilterSeverity::DIAGNOSTIC:
          text = "DIAGNOSTIC";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
