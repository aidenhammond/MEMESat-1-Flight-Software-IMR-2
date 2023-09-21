/*
 * CmdSeqCancelPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_CMDSEQCANCEL_PORT_HPP_
#define SVC_CMDSEQCANCEL_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace Svc {

    /// Input CmdSeqCancel port description
    /// 

    class InputCmdSeqCancelPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = 0 //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum); //!< port callback definition

        InputCmdSeqCancelPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output CmdSeqCancel port description
    /// 

    class OutputCmdSeqCancelPort : public Fw::OutputPortBase {
      public:
        OutputCmdSeqCancelPort();
        void init();
        void addCallPort(InputCmdSeqCancelPort* callPort);
        void invoke();
      protected:
      private:
        InputCmdSeqCancelPort* m_port;
    };
} // end namespace Svc
#endif /* SVC_CMDSEQCANCEL_PORT_HPP_ */

