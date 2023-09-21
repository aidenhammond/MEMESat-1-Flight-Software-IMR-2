/*
 * CmdPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_CMD_PORT_HPP_
#define FW_CMD_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>


namespace Fw {

    /// Input Cmd port description
    /// 

    class InputCmdPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(FwOpcodeType) + sizeof(U32) + Fw::CmdArgBuffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, FwOpcodeType opCode, U32 cmdSeq, Fw::CmdArgBuffer &args); //!< port callback definition

        InputCmdPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(FwOpcodeType opCode, U32 cmdSeq, Fw::CmdArgBuffer &args); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output Cmd port description
    /// 

    class OutputCmdPort : public Fw::OutputPortBase {
      public:
        OutputCmdPort();
        void init();
        void addCallPort(InputCmdPort* callPort);
        void invoke(FwOpcodeType opCode, U32 cmdSeq, Fw::CmdArgBuffer &args);
      protected:
      private:
        InputCmdPort* m_port;
    };
} // end namespace Fw
#endif /* FW_CMD_PORT_HPP_ */

