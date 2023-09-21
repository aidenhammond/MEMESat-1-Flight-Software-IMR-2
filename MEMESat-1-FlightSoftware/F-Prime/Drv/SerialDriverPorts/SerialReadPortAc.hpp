/*
 * SerialReadPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_SERIALREAD_PORT_HPP_
#define DRV_SERIALREAD_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Drv/SerialDriverPorts/SerialReadStatusEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>


namespace Drv {

    /// Input SerialRead port description
    /// 

    class InputSerialReadPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::Buffer::SERIALIZED_SIZE + Drv::SerialReadStatus::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::Buffer &serBuffer, Drv::SerialReadStatus &status); //!< port callback definition

        InputSerialReadPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Fw::Buffer &serBuffer, Drv::SerialReadStatus &status); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output SerialRead port description
    /// 

    class OutputSerialReadPort : public Fw::OutputPortBase {
      public:
        OutputSerialReadPort();
        void init();
        void addCallPort(InputSerialReadPort* callPort);
        void invoke(Fw::Buffer &serBuffer, Drv::SerialReadStatus &status);
      protected:
      private:
        InputSerialReadPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_SERIALREAD_PORT_HPP_ */

