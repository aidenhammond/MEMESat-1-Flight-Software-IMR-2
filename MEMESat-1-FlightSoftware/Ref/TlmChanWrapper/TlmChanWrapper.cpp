// ======================================================================
// \title  TlmChanWrapper.cpp
// \author michael
// \brief  cpp file for TlmChanWrapper component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/TlmChanWrapper/TlmChanWrapper.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  TlmChanWrapper ::
    TlmChanWrapper(
        const char *const compName
    ) : TlmChanWrapperComponentBase(compName)
  {

  }

  void TlmChanWrapper ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    TlmChanWrapperComponentBase::init(queueDepth, instance);
  }
  

  TlmChanWrapper ::
    ~TlmChanWrapper()
  {

  }

  void TlmChanWrapper::preamble() {
    Fw::ParamValid valid;
    Fw::ParamString val = this->paramGet_SCHEDULE(valid);
    const char* schedule_parameter = val.toChar();
    FW_ASSERT(
      valid.e == Fw::ParamValid::VALID || valid.e == Fw::ParamValid::DEFAULT,
      valid.e
    );
    this->sendSchedule_out(0, "TlmChan", schedule_parameter, Ref::ScheduleOp::START);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void TlmChanWrapper ::
    scheduledHandler_handler(
        const NATIVE_INT_TYPE portNum,
        const Ref::ScheduleStatus &status
    )
  {
    if (status == Ref::ScheduleStatus::FAILED || status == Ref::ScheduleStatus::STOPPED) {
       this->log_WARNING_LO_SCHEDULE_ERROR(status);
       return;
    }
    this->tlmChanOut_out(0,0);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void TlmChanWrapper :: 
    parameterUpdated(
      FwPrmIdType id
    )
  {
    if (id == 1) {
      Fw::ParamValid valid;
      const Fw::ParamString schedule_param = this->paramGet_SCHEDULE(valid);
      const char* schedule = schedule_param.toChar();
      FW_ASSERT(
        valid.e == Fw::ParamValid::VALID || valid.e == Fw::ParamValid::DEFAULT,
        valid.e
      );
      this->sendSchedule_out(0, "TlmChan", schedule, ScheduleOp::START);
      this->log_ACTIVITY_LO_SCHEDULE_CHANGED_TO(schedule);
    }
  }
} // end namespace Ref
