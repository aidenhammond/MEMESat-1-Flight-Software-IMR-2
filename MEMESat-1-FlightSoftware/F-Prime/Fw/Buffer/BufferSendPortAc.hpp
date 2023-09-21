/*
 * BufferSendPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_BUFFERSEND_PORT_HPP_
#define FW_BUFFERSEND_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Buffer/Buffer.hpp>


namespace Fw {

    /// Input BufferSend port description
    /// 

    class InputBufferSendPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::Buffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::Buffer &fwBuffer); //!< port callback definition

        InputBufferSendPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Fw::Buffer &fwBuffer); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output BufferSend port description
    /// 

    class OutputBufferSendPort : public Fw::OutputPortBase {
      public:
        OutputBufferSendPort();
        void init();
        void addCallPort(InputBufferSendPort* callPort);
        void invoke(Fw::Buffer &fwBuffer);
      protected:
      private:
        InputBufferSendPort* m_port;
    };
} // end namespace Fw
#endif /* FW_BUFFERSEND_PORT_HPP_ */

