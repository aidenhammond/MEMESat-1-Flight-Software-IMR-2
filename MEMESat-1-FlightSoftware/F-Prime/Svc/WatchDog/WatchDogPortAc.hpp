/*
 * WatchDogPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_WATCHDOG_PORT_HPP_
#define SVC_WATCHDOG_PORT_HPP_

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

    /// Input WatchDog port description
    /// 

    class InputWatchDogPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(U32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, U32 code); //!< port callback definition

        InputWatchDogPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(U32 code); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output WatchDog port description
    /// 

    class OutputWatchDogPort : public Fw::OutputPortBase {
      public:
        OutputWatchDogPort();
        void init();
        void addCallPort(InputWatchDogPort* callPort);
        void invoke(U32 code);
      protected:
      private:
        InputWatchDogPort* m_port;
    };
} // end namespace Svc
#endif /* SVC_WATCHDOG_PORT_HPP_ */

