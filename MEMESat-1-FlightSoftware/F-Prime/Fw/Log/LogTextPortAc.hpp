/*
 * LogTextPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_LOGTEXT_PORT_HPP_
#define FW_LOGTEXT_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Log/LogSeverityEnumAc.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Time/Time.hpp>


namespace Fw {

    /// Input LogText port description
    /// 

    class InputLogTextPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(FwEventIdType) + Fw::Time::SERIALIZED_SIZE + Fw::LogSeverity::SERIALIZED_SIZE + Fw::TextLogString::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::TextLogString &text); //!< port callback definition

        InputLogTextPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::TextLogString &text); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output LogText port description
    /// 

    class OutputLogTextPort : public Fw::OutputPortBase {
      public:
        OutputLogTextPort();
        void init();
        void addCallPort(InputLogTextPort* callPort);
        void invoke(FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::TextLogString &text);
      protected:
      private:
        InputLogTextPort* m_port;
    };
} // end namespace Fw
#endif /* FW_LOGTEXT_PORT_HPP_ */

