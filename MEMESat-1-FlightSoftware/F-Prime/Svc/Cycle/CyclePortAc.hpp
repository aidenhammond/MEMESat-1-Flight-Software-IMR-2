/*
 * CyclePort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_CYCLE_PORT_HPP_
#define SVC_CYCLE_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Svc/Cycle/TimerVal.hpp>


namespace Svc {

    /// Input Cycle port description
    /// 

    class InputCyclePort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Svc::TimerVal::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Svc::TimerVal &cycleStart); //!< port callback definition

        InputCyclePort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Svc::TimerVal &cycleStart); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output Cycle port description
    /// 

    class OutputCyclePort : public Fw::OutputPortBase {
      public:
        OutputCyclePort();
        void init();
        void addCallPort(InputCyclePort* callPort);
        void invoke(Svc::TimerVal &cycleStart);
      protected:
      private:
        InputCyclePort* m_port;
    };
} // end namespace Svc
#endif /* SVC_CYCLE_PORT_HPP_ */

