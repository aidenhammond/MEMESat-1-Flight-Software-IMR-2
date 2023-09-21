/*
 * FatalEventPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_FATALEVENT_PORT_HPP_
#define SVC_FATALEVENT_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace Svc {

    /// Input FatalEvent port description
    /// 

    class InputFatalEventPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(FwEventIdType) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, FwEventIdType Id); //!< port callback definition

        InputFatalEventPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(FwEventIdType Id); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output FatalEvent port description
    /// 

    class OutputFatalEventPort : public Fw::OutputPortBase {
      public:
        OutputFatalEventPort();
        void init();
        void addCallPort(InputFatalEventPort* callPort);
        void invoke(FwEventIdType Id);
      protected:
      private:
        InputFatalEventPort* m_port;
    };
} // end namespace Svc
#endif /* SVC_FATALEVENT_PORT_HPP_ */

