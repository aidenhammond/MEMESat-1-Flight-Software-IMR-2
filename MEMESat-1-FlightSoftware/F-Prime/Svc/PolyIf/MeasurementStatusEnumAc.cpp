// ======================================================================
// \title  MeasurementStatus
// \author Auto-generated
// \brief  cpp file for MeasurementStatus
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
#include "MeasurementStatusEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  MeasurementStatus :: MeasurementStatus():Serializable()
  {
    this->e = static_cast<t>(OK);
  }

  MeasurementStatus :: MeasurementStatus(const t e):Serializable()
  {
    this->e = e;
  }

  MeasurementStatus :: MeasurementStatus(const MeasurementStatus& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  MeasurementStatus& MeasurementStatus :: operator=(const MeasurementStatus& other)
  {
    this->e = other.e;
    return *this;
  }

  MeasurementStatus& MeasurementStatus :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  MeasurementStatus& MeasurementStatus :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool MeasurementStatus :: operator==(const MeasurementStatus& other) const
  {
    return this->e == other.e;
  }

  bool MeasurementStatus :: operator!=(const MeasurementStatus& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const MeasurementStatus& obj) {
    os << "MeasurementStatus::";
    const MeasurementStatus::t e = obj.e;
    switch (e) {
        case MeasurementStatus::OK:
          os << "OK";
          break;
        case MeasurementStatus::FAILURE:
          os << "FAILURE";
          break;
        case MeasurementStatus::STALE:
          os << "STALE";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus MeasurementStatus :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus MeasurementStatus :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void MeasurementStatus :: toString(Fw::StringBase& text) const {
    const MeasurementStatus::t e = this->e;
    switch (e) {
        case MeasurementStatus::OK:
          text = "OK";
          break;
        case MeasurementStatus::FAILURE:
          text = "FAILURE";
          break;
        case MeasurementStatus::STALE:
          text = "STALE";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
