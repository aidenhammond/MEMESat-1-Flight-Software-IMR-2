/*
 * ComPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_COM_PORT_HPP_
#define FW_COM_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Com/ComBuffer.hpp>


namespace Fw {

    /// Input Com port description
    /// 

    class InputComPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::ComBuffer::SERIALIZED_SIZE + sizeof(U32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::ComBuffer &data, U32 context); //!< port callback definition

        InputComPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Fw::ComBuffer &data, U32 context); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output Com port description
    /// 

    class OutputComPort : public Fw::OutputPortBase {
      public:
        OutputComPort();
        void init();
        void addCallPort(InputComPort* callPort);
        void invoke(Fw::ComBuffer &data, U32 context);
      protected:
      private:
        InputComPort* m_port;
    };
} // end namespace Fw
#endif /* FW_COM_PORT_HPP_ */

