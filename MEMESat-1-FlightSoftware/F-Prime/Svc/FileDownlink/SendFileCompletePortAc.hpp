/*
 * SendFileCompletePort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_SENDFILECOMPLETE_PORT_HPP_
#define SVC_SENDFILECOMPLETE_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Svc/FileDownlink/SendFileResponseSerializableAc.hpp>


namespace Svc {

    /// Input SendFileComplete port description
    /// 

    class InputSendFileCompletePort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Svc::SendFileResponse::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, const Svc::SendFileResponse &resp); //!< port callback definition

        InputSendFileCompletePort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(const Svc::SendFileResponse &resp); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output SendFileComplete port description
    /// 

    class OutputSendFileCompletePort : public Fw::OutputPortBase {
      public:
        OutputSendFileCompletePort();
        void init();
        void addCallPort(InputSendFileCompletePort* callPort);
        void invoke(const Svc::SendFileResponse &resp);
      protected:
      private:
        InputSendFileCompletePort* m_port;
    };
} // end namespace Svc
#endif /* SVC_SENDFILECOMPLETE_PORT_HPP_ */

