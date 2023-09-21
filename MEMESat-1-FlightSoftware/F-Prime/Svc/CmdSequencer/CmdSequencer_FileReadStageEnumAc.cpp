// ======================================================================
// \title  CmdSequencer_FileReadStage
// \author Auto-generated
// \brief  cpp file for CmdSequencer_FileReadStage
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
#include "CmdSequencer_FileReadStageEnumAc.hpp"

namespace Svc {

  // ----------------------------------------------------------------------
  // Constructors
  // ----------------------------------------------------------------------

  CmdSequencer_FileReadStage :: CmdSequencer_FileReadStage():Serializable()
  {
    this->e = static_cast<t>(READ_HEADER);
  }

  CmdSequencer_FileReadStage :: CmdSequencer_FileReadStage(const t e):Serializable()
  {
    this->e = e;
  }

  CmdSequencer_FileReadStage :: CmdSequencer_FileReadStage(const CmdSequencer_FileReadStage& other):Serializable()
  {
    this->e = other.e;
  }

  // ----------------------------------------------------------------------
  // Instance methods
  // ----------------------------------------------------------------------

  CmdSequencer_FileReadStage& CmdSequencer_FileReadStage :: operator=(const CmdSequencer_FileReadStage& other)
  {
    this->e = other.e;
    return *this;
  }

  CmdSequencer_FileReadStage& CmdSequencer_FileReadStage :: operator=(const NATIVE_INT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  CmdSequencer_FileReadStage& CmdSequencer_FileReadStage :: operator=(const NATIVE_UINT_TYPE a)
  {
    FW_ASSERT(a == 0 || a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 || a == 8, static_cast<t>(a));
    this->e = static_cast<t>(a);
    return *this;
  }

  bool CmdSequencer_FileReadStage :: operator==(const CmdSequencer_FileReadStage& other) const
  {
    return this->e == other.e;
  }

  bool CmdSequencer_FileReadStage :: operator!=(const CmdSequencer_FileReadStage& other) const
  {
    return !(*this == other);
  }

#ifdef BUILD_UT
  std::ostream& operator<<(std::ostream& os, const CmdSequencer_FileReadStage& obj) {
    os << "CmdSequencer_FileReadStage::";
    const CmdSequencer_FileReadStage::t e = obj.e;
    switch (e) {
        case CmdSequencer_FileReadStage::READ_HEADER:
          os << "READ_HEADER";
          break;
        case CmdSequencer_FileReadStage::READ_HEADER_SIZE:
          os << "READ_HEADER_SIZE";
          break;
        case CmdSequencer_FileReadStage::DESER_SIZE:
          os << "DESER_SIZE";
          break;
        case CmdSequencer_FileReadStage::DESER_NUM_RECORDS:
          os << "DESER_NUM_RECORDS";
          break;
        case CmdSequencer_FileReadStage::DESER_TIME_BASE:
          os << "DESER_TIME_BASE";
          break;
        case CmdSequencer_FileReadStage::DESER_TIME_CONTEXT:
          os << "DESER_TIME_CONTEXT";
          break;
        case CmdSequencer_FileReadStage::READ_SEQ_CRC:
          os << "READ_SEQ_CRC";
          break;
        case CmdSequencer_FileReadStage::READ_SEQ_DATA:
          os << "READ_SEQ_DATA";
          break;
        case CmdSequencer_FileReadStage::READ_SEQ_DATA_SIZE:
          os << "READ_SEQ_DATA_SIZE";
          break;
        default:
          os << "[invalid]";
          break;
    }
    os << " (" << e << ")";
    return os;
  }
#endif

  Fw::SerializeStatus CmdSequencer_FileReadStage :: serialize(Fw::SerializeBufferBase& buffer) const
  {
    Fw::SerializeStatus status;
    status = buffer.serialize(static_cast<I32>(this->e));
    return status;
  }

  Fw::SerializeStatus CmdSequencer_FileReadStage :: deserialize(Fw::SerializeBufferBase& buffer)
  {
    Fw::SerializeStatus status;
    I32 es;
    status = buffer.deserialize(es);
    if (status == Fw::FW_SERIALIZE_OK)
      this->e = static_cast<t>(es);
    return status;
  }

  #if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void CmdSequencer_FileReadStage :: toString(Fw::StringBase& text) const {
    const CmdSequencer_FileReadStage::t e = this->e;
    switch (e) {
        case CmdSequencer_FileReadStage::READ_HEADER:
          text = "READ_HEADER";
          break;
        case CmdSequencer_FileReadStage::READ_HEADER_SIZE:
          text = "READ_HEADER_SIZE";
          break;
        case CmdSequencer_FileReadStage::DESER_SIZE:
          text = "DESER_SIZE";
          break;
        case CmdSequencer_FileReadStage::DESER_NUM_RECORDS:
          text = "DESER_NUM_RECORDS";
          break;
        case CmdSequencer_FileReadStage::DESER_TIME_BASE:
          text = "DESER_TIME_BASE";
          break;
        case CmdSequencer_FileReadStage::DESER_TIME_CONTEXT:
          text = "DESER_TIME_CONTEXT";
          break;
        case CmdSequencer_FileReadStage::READ_SEQ_CRC:
          text = "READ_SEQ_CRC";
          break;
        case CmdSequencer_FileReadStage::READ_SEQ_DATA:
          text = "READ_SEQ_DATA";
          break;
        case CmdSequencer_FileReadStage::READ_SEQ_DATA_SIZE:
          text = "READ_SEQ_DATA_SIZE";
          break;
        default:
          text = "[invalid]";
          break;
    }
  }
  #endif

}
