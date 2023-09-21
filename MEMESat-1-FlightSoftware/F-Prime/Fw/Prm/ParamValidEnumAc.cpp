// ======================================================================
// \title  ParamValid
// \author Auto-generated
// \brief  cpp file for ParamValid
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
#include "ParamValidEnumAc.hpp"

namespace Fw {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  ParamValid :: ParamValid():Serializable()
  {
    this->e = static_cast<t>(UNINIT);
  }

  ParamValid :: ParamValid(const t e):Serializable()
  {
    this->e = e;
  }

  ParamValid :: ParamValid(const ParamValid& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  ParamValid& ParamValid :: operator=(const ParamValid& other)
  {
    this->e = other.e;
    return *this;
  }

  ParamValid& ParamValid :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  ParamValid& ParamValid :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool ParamValid :: operator==(const ParamValid& other) const
  {
    return this->e == other.e;
  }

  bool ParamValid :: operator!=(const ParamValid& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const ParamValid& obj) {
    os << "ParamValid::";
    const ParamValid::t e = obj.e;
    switch (e) {
        case ParamValid::UNINIT:
          os << "UNINIT";
          break;
        case ParamValid::VALID:
          os << "VALID";
          break;
        case ParamValid::INVALID:
          os << "INVALID";
          break;
        case ParamValid::DEFAULT:
          os << "DEFAULT";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus ParamValid :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus ParamValid :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void ParamValid :: toString(Fw::StringBase& text) const {
    const ParamValid::t e = this->e;
    switch (e) {
        case ParamValid::UNINIT:
          text = "UNINIT";
          break;
        case ParamValid::VALID:
          text = "VALID";
          break;
        case ParamValid::INVALID:
          text = "INVALID";
          break;
        case ParamValid::DEFAULT:
          text = "DEFAULT";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
