/*
 * TlmGetPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_TLMGET_PORT_HPP_
#define FW_TLMGET_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>


namespace Fw {

    /// Input TlmGet port description
    /// 

    class InputTlmGetPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(FwChanIdType) + Fw::Time::SERIALIZED_SIZE + Fw::TlmBuffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val); //!< port callback definition

        InputTlmGetPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output TlmGet port description
    /// 

    class OutputTlmGetPort : public Fw::OutputPortBase {
      public:
        OutputTlmGetPort();
        void init();
        void addCallPort(InputTlmGetPort* callPort);
        void invoke(FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val);
      protected:
      private:
        InputTlmGetPort* m_port;
    };
} // end namespace Fw
#endif /* FW_TLMGET_PORT_HPP_ */

