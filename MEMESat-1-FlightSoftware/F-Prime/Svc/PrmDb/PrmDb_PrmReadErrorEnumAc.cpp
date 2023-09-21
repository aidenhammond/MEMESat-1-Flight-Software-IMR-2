// ======================================================================
// \title  PrmDb_PrmReadError
// \author Auto-generated
// \brief  cpp file for PrmDb_PrmReadError
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
#include "PrmDb_PrmReadErrorEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  PrmDb_PrmReadError :: PrmDb_PrmReadError():Serializable()
  {
    this->e = static_cast<t>(OPEN);
  }

  PrmDb_PrmReadError :: PrmDb_PrmReadError(const t e):Serializable()
  {
    this->e = e;
  }

  PrmDb_PrmReadError :: PrmDb_PrmReadError(const PrmDb_PrmReadError& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  PrmDb_PrmReadError& PrmDb_PrmReadError :: operator=(const PrmDb_PrmReadError& other)
  {
    this->e = other.e;
    return *this;
  }

  PrmDb_PrmReadError& PrmDb_PrmReadError :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 10, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  PrmDb_PrmReadError& PrmDb_PrmReadError :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8 || a == 9 || a == 10, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool PrmDb_PrmReadError :: operator==(const PrmDb_PrmReadError& other) const
  {
    return this->e == other.e;
  }

  bool PrmDb_PrmReadError :: operator!=(const PrmDb_PrmReadError& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const PrmDb_PrmReadError& obj) {
    os << "PrmDb_PrmReadError::";
    const PrmDb_PrmReadError::t e = obj.e;
    switch (e) {
        case PrmDb_PrmReadError::OPEN:
          os << "OPEN";
          break;
        case PrmDb_PrmReadError::DELIMITER:
          os << "DELIMITER";
          break;
        case PrmDb_PrmReadError::DELIMITER_SIZE:
          os << "DELIMITER_SIZE";
          break;
        case PrmDb_PrmReadError::DELIMITER_VALUE:
          os << "DELIMITER_VALUE";
          break;
        case PrmDb_PrmReadError::RECORD_SIZE:
          os << "RECORD_SIZE";
          break;
        case PrmDb_PrmReadError::RECORD_SIZE_SIZE:
          os << "RECORD_SIZE_SIZE";
          break;
        case PrmDb_PrmReadError::RECORD_SIZE_VALUE:
          os << "RECORD_SIZE_VALUE";
          break;
        case PrmDb_PrmReadError::PARAMETER_ID:
          os << "PARAMETER_ID";
          break;
        case PrmDb_PrmReadError::PARAMETER_ID_SIZE:
          os << "PARAMETER_ID_SIZE";
          break;
        case PrmDb_PrmReadError::PARAMETER_VALUE:
          os << "PARAMETER_VALUE";
          break;
        case PrmDb_PrmReadError::PARAMETER_VALUE_SIZE:
          os << "PARAMETER_VALUE_SIZE";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus PrmDb_PrmReadError :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus PrmDb_PrmReadError :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void PrmDb_PrmReadError :: toString(Fw::StringBase& text) const {
    const PrmDb_PrmReadError::t e = this->e;
    switch (e) {
        case PrmDb_PrmReadError::OPEN:
          text = "OPEN";
          break;
        case PrmDb_PrmReadError::DELIMITER:
          text = "DELIMITER";
          break;
        case PrmDb_PrmReadError::DELIMITER_SIZE:
          text = "DELIMITER_SIZE";
          break;
        case PrmDb_PrmReadError::DELIMITER_VALUE:
          text = "DELIMITER_VALUE";
          break;
        case PrmDb_PrmReadError::RECORD_SIZE:
          text = "RECORD_SIZE";
          break;
        case PrmDb_PrmReadError::RECORD_SIZE_SIZE:
          text = "RECORD_SIZE_SIZE";
          break;
        case PrmDb_PrmReadError::RECORD_SIZE_VALUE:
          text = "RECORD_SIZE_VALUE";
          break;
        case PrmDb_PrmReadError::PARAMETER_ID:
          text = "PARAMETER_ID";
          break;
        case PrmDb_PrmReadError::PARAMETER_ID_SIZE:
          text = "PARAMETER_ID_SIZE";
          break;
        case PrmDb_PrmReadError::PARAMETER_VALUE:
          text = "PARAMETER_VALUE";
          break;
        case PrmDb_PrmReadError::PARAMETER_VALUE_SIZE:
          text = "PARAMETER_VALUE_SIZE";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
