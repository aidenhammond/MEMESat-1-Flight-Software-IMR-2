/*
 * CmdSeqInPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_CMDSEQIN_PORT_HPP_
#define SVC_CMDSEQIN_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Types/String.hpp>


namespace Svc {

    /// Input CmdSeqIn port description
    /// 

    class InputCmdSeqInPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::String::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::String &filename); //!< port callback definition

        InputCmdSeqInPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Fw::String &filename); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output CmdSeqIn port description
    /// 

    class OutputCmdSeqInPort : public Fw::OutputPortBase {
      public:
        OutputCmdSeqInPort();
        void init();
        void addCallPort(InputCmdSeqInPort* callPort);
        void invoke(Fw::String &filename);
      protected:
      private:
        InputCmdSeqInPort* m_port;
    };
} // end namespace Svc
#endif /* SVC_CMDSEQIN_PORT_HPP_ */

