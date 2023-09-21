/*
 * ByteStreamSendPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_BYTESTREAMSEND_PORT_HPP_
#define DRV_BYTESTREAMSEND_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Drv/ByteStreamDriverModel/SendStatusEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>


namespace Drv {

    /// Input ByteStreamSend port description
    /// 

    class InputByteStreamSendPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::Buffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef Drv::SendStatus (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::Buffer &sendBuffer); //!< port callback definition

        InputByteStreamSendPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Drv::SendStatus invoke(Fw::Buffer &sendBuffer); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output ByteStreamSend port description
    /// 

    class OutputByteStreamSendPort : public Fw::OutputPortBase {
      public:
        OutputByteStreamSendPort();
        void init();
        void addCallPort(InputByteStreamSendPort* callPort);
        Drv::SendStatus invoke(Fw::Buffer &sendBuffer);
      protected:
      private:
        InputByteStreamSendPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_BYTESTREAMSEND_PORT_HPP_ */

