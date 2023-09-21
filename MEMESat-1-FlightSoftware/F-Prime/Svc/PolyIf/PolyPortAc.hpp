/*
 * PolyPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_POLY_PORT_HPP_
#define SVC_POLY_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Svc/PolyIf/MeasurementStatusEnumAc.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Types/PolyType.hpp>


namespace Svc {

    /// Input Poly port description
    /// 

    class InputPolyPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(U32) + Svc::MeasurementStatus::SERIALIZED_SIZE + Fw::Time::SERIALIZED_SIZE + Fw::PolyType::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, U32 entry, Svc::MeasurementStatus &status, Fw::Time &time, Fw::PolyType &val); //!< port callback definition

        InputPolyPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(U32 entry, Svc::MeasurementStatus &status, Fw::Time &time, Fw::PolyType &val); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output Poly port description
    /// 

    class OutputPolyPort : public Fw::OutputPortBase {
      public:
        OutputPolyPort();
        void init();
        void addCallPort(InputPolyPort* callPort);
        void invoke(U32 entry, Svc::MeasurementStatus &status, Fw::Time &time, Fw::PolyType &val);
      protected:
      private:
        InputPolyPort* m_port;
    };
} // end namespace Svc
#endif /* SVC_POLY_PORT_HPP_ */

