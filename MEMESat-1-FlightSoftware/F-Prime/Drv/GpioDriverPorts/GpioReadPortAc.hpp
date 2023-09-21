/*
 * GpioReadPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_GPIOREAD_PORT_HPP_
#define DRV_GPIOREAD_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace Drv {

    /// Input GpioRead port description
    /// 

    class InputGpioReadPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(bool) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, bool &state); //!< port callback definition

        InputGpioReadPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(bool &state); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output GpioRead port description
    /// 

    class OutputGpioReadPort : public Fw::OutputPortBase {
      public:
        OutputGpioReadPort();
        void init();
        void addCallPort(InputGpioReadPort* callPort);
        void invoke(bool &state);
      protected:
      private:
        InputGpioReadPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_GPIOREAD_PORT_HPP_ */

