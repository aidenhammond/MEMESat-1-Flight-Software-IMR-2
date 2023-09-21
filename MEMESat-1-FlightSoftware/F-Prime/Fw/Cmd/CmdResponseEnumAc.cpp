// ======================================================================
// \title  CmdResponse
// \author Auto-generated
// \brief  cpp file for CmdResponse
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
#include "CmdResponseEnumAc.hpp"

namespace Fw {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  CmdResponse :: CmdResponse():Serializable()
  {
    this->e = static_cast<t>(OK);
  }

  CmdResponse :: CmdResponse(const t e):Serializable()
  {
    this->e = e;
  }

  CmdResponse :: CmdResponse(const CmdResponse& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  CmdResponse& CmdResponse :: operator=(const CmdResponse& other)
  {
    this->e = other.e;
    return *this;
  }

  CmdResponse& CmdResponse :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  CmdResponse& CmdResponse :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool CmdResponse :: operator==(const CmdResponse& other) const
  {
    return this->e == other.e;
  }

  bool CmdResponse :: operator!=(const CmdResponse& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const CmdResponse& obj) {
    os << "CmdResponse::";
    const CmdResponse::t e = obj.e;
    switch (e) {
        case CmdResponse::OK:
          os << "OK";
          break;
        case CmdResponse::INVALID_OPCODE:
          os << "INVALID_OPCODE";
          break;
        case CmdResponse::VALIDATION_ERROR:
          os << "VALIDATION_ERROR";
          break;
        case CmdResponse::FORMAT_ERROR:
          os << "FORMAT_ERROR";
          break;
        case CmdResponse::EXECUTION_ERROR:
          os << "EXECUTION_ERROR";
          break;
        case CmdResponse::BUSY:
          os << "BUSY";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus CmdResponse :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus CmdResponse :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void CmdResponse :: toString(Fw::StringBase& text) const {
    const CmdResponse::t e = this->e;
    switch (e) {
        case CmdResponse::OK:
          text = "OK";
          break;
        case CmdResponse::INVALID_OPCODE:
          text = "INVALID_OPCODE";
          break;
        case CmdResponse::VALIDATION_ERROR:
          text = "VALIDATION_ERROR";
          break;
        case CmdResponse::FORMAT_ERROR:
          text = "FORMAT_ERROR";
          break;
        case CmdResponse::EXECUTION_ERROR:
          text = "EXECUTION_ERROR";
          break;
        case CmdResponse::BUSY:
          text = "BUSY";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
