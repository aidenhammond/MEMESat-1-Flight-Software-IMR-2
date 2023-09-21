// ======================================================================
// \title  PrmDb_PrmWriteError
// \author Auto-generated
// \brief  cpp file for PrmDb_PrmWriteError
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
#include "PrmDb_PrmWriteErrorEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  PrmDb_PrmWriteError :: PrmDb_PrmWriteError():Serializable()
  {
    this->e = static_cast<t>(OPEN);
  }

  PrmDb_PrmWriteError :: PrmDb_PrmWriteError(const t e):Serializable()
  {
    this->e = e;
  }

  PrmDb_PrmWriteError :: PrmDb_PrmWriteError(const PrmDb_PrmWriteError& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  PrmDb_PrmWriteError& PrmDb_PrmWriteError :: operator=(const PrmDb_PrmWriteError& other)
  {
    this->e = other.e;
    return *this;
  }

  PrmDb_PrmWriteError& PrmDb_PrmWriteError :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  PrmDb_PrmWriteError& PrmDb_PrmWriteError :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool PrmDb_PrmWriteError :: operator==(const PrmDb_PrmWriteError& other) const
  {
    return this->e == other.e;
  }

  bool PrmDb_PrmWriteError :: operator!=(const PrmDb_PrmWriteError& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const PrmDb_PrmWriteError& obj) {
    os << "PrmDb_PrmWriteError::";
    const PrmDb_PrmWriteError::t e = obj.e;
    switch (e) {
        case PrmDb_PrmWriteError::OPEN:
          os << "OPEN";
          break;
        case PrmDb_PrmWriteError::DELIMITER:
          os << "DELIMITER";
          break;
        case PrmDb_PrmWriteError::DELIMITER_SIZE:
          os << "DELIMITER_SIZE";
          break;
        case PrmDb_PrmWriteError::RECORD_SIZE:
          os << "RECORD_SIZE";
          break;
        case PrmDb_PrmWriteError::RECORD_SIZE_SIZE:
          os << "RECORD_SIZE_SIZE";
          break;
        case PrmDb_PrmWriteError::PARAMETER_ID:
          os << "PARAMETER_ID";
          break;
        case PrmDb_PrmWriteError::PARAMETER_ID_SIZE:
          os << "PARAMETER_ID_SIZE";
          break;
        case PrmDb_PrmWriteError::PARAMETER_VALUE:
          os << "PARAMETER_VALUE";
          break;
        case PrmDb_PrmWriteError::PARAMETER_VALUE_SIZE:
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

  Fw::SerializeStatus PrmDb_PrmWriteError :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus PrmDb_PrmWriteError :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void PrmDb_PrmWriteError :: toString(Fw::StringBase& text) const {
    const PrmDb_PrmWriteError::t e = this->e;
    switch (e) {
        case PrmDb_PrmWriteError::OPEN:
          text = "OPEN";
          break;
        case PrmDb_PrmWriteError::DELIMITER:
          text = "DELIMITER";
          break;
        case PrmDb_PrmWriteError::DELIMITER_SIZE:
          text = "DELIMITER_SIZE";
          break;
        case PrmDb_PrmWriteError::RECORD_SIZE:
          text = "RECORD_SIZE";
          break;
        case PrmDb_PrmWriteError::RECORD_SIZE_SIZE:
          text = "RECORD_SIZE_SIZE";
          break;
        case PrmDb_PrmWriteError::PARAMETER_ID:
          text = "PARAMETER_ID";
          break;
        case PrmDb_PrmWriteError::PARAMETER_ID_SIZE:
          text = "PARAMETER_ID_SIZE";
          break;
        case PrmDb_PrmWriteError::PARAMETER_VALUE:
          text = "PARAMETER_VALUE";
          break;
        case PrmDb_PrmWriteError::PARAMETER_VALUE_SIZE:
          text = "PARAMETER_VALUE_SIZE";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
