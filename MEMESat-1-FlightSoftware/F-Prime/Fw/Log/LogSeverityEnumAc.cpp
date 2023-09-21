// ======================================================================
// \title  LogSeverity
// \author Auto-generated
// \brief  cpp file for LogSeverity
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
#include "LogSeverityEnumAc.hpp"

namespace Fw {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  LogSeverity :: LogSeverity():Serializable()
  {
    this->e = static_cast<t>(FATAL);
  }

  LogSeverity :: LogSeverity(const t e):Serializable()
  {
    this->e = e;
  }

  LogSeverity :: LogSeverity(const LogSeverity& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  LogSeverity& LogSeverity :: operator=(const LogSeverity& other)
  {
    this->e = other.e;
    return *this;
  }

  LogSeverity& LogSeverity :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  LogSeverity& LogSeverity :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool LogSeverity :: operator==(const LogSeverity& other) const
  {
    return this->e == other.e;
  }

  bool LogSeverity :: operator!=(const LogSeverity& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const LogSeverity& obj) {
    os << "LogSeverity::";
    const LogSeverity::t e = obj.e;
    switch (e) {
        case LogSeverity::FATAL:
          os << "FATAL";
          break;
        case LogSeverity::WARNING_HI:
          os << "WARNING_HI";
          break;
        case LogSeverity::WARNING_LO:
          os << "WARNING_LO";
          break;
        case LogSeverity::COMMAND:
          os << "COMMAND";
          break;
        case LogSeverity::ACTIVITY_HI:
          os << "ACTIVITY_HI";
          break;
        case LogSeverity::ACTIVITY_LO:
          os << "ACTIVITY_LO";
          break;
        case LogSeverity::DIAGNOSTIC:
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

  Fw::SerializeStatus LogSeverity :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus LogSeverity :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void LogSeverity :: toString(Fw::StringBase& text) const {
    const LogSeverity::t e = this->e;
    switch (e) {
        case LogSeverity::FATAL:
          text = "FATAL";
          break;
        case LogSeverity::WARNING_HI:
          text = "WARNING_HI";
          break;
        case LogSeverity::WARNING_LO:
          text = "WARNING_LO";
          break;
        case LogSeverity::COMMAND:
          text = "COMMAND";
          break;
        case LogSeverity::ACTIVITY_HI:
          text = "ACTIVITY_HI";
          break;
        case LogSeverity::ACTIVITY_LO:
          text = "ACTIVITY_LO";
          break;
        case LogSeverity::DIAGNOSTIC:
          text = "DIAGNOSTIC";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
