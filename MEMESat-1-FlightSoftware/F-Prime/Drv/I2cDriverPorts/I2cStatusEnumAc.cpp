// ======================================================================
// \title  I2cStatus
// \author Auto-generated
// \brief  cpp file for I2cStatus
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
#include "I2cStatusEnumAc.hpp"

namespace Drv {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  I2cStatus :: I2cStatus():Serializable()
  {
    this->e = static_cast<t>(I2C_OK);
  }

  I2cStatus :: I2cStatus(const t e):Serializable()
  {
    this->e = e;
  }

  I2cStatus :: I2cStatus(const I2cStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  I2cStatus& I2cStatus :: operator=(const I2cStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  I2cStatus& I2cStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  I2cStatus& I2cStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool I2cStatus :: operator==(const I2cStatus& other) const
  {
    return this->e == other.e;
  }

  bool I2cStatus :: operator!=(const I2cStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const I2cStatus& obj) {
    os << "I2cStatus::";
    const I2cStatus::t e = obj.e;
    switch (e) {
        case I2cStatus::I2C_OK:
          os << "I2C_OK";
          break;
        case I2cStatus::I2C_ADDRESS_ERR:
          os << "I2C_ADDRESS_ERR";
          break;
        case I2cStatus::I2C_WRITE_ERR:
          os << "I2C_WRITE_ERR";
          break;
        case I2cStatus::I2C_READ_ERR:
          os << "I2C_READ_ERR";
          break;
        case I2cStatus::I2C_OTHER_ERR:
          os << "I2C_OTHER_ERR";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus I2cStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus I2cStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void I2cStatus :: toString(Fw::StringBase& text) const {
    const I2cStatus::t e = this->e;
    switch (e) {
        case I2cStatus::I2C_OK:
          text = "I2C_OK";
          break;
        case I2cStatus::I2C_ADDRESS_ERR:
          text = "I2C_ADDRESS_ERR";
          break;
        case I2cStatus::I2C_WRITE_ERR:
          text = "I2C_WRITE_ERR";
          break;
        case I2cStatus::I2C_READ_ERR:
          text = "I2C_READ_ERR";
          break;
        case I2cStatus::I2C_OTHER_ERR:
          text = "I2C_OTHER_ERR";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
