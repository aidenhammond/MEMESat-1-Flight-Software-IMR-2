/*
 * BufferGetPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_BUFFERGET_PORT_HPP_
#define FW_BUFFERGET_PORT_HPP_

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

    /// Input BufferGet port description
    /// 

    class InputBufferGetPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(U32) //!< serialized size of port arguments
        };
        typedef Fw::Buffer (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, U32 size); //!< port callback definition

        InputBufferGetPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Fw::Buffer invoke(U32 size); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output BufferGet port description
    /// 

    class OutputBufferGetPort : public Fw::OutputPortBase {
      public:
        OutputBufferGetPort();
        void init();
        void addCallPort(InputBufferGetPort* callPort);
        Fw::Buffer invoke(U32 size);
      protected:
      private:
        InputBufferGetPort* m_port;
    };
} // end namespace Fw
#endif /* FW_BUFFERGET_PORT_HPP_ */

