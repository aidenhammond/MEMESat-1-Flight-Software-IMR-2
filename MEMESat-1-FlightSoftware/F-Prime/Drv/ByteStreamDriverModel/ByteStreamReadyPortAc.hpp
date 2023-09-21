/*
 * ByteStreamReadyPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_BYTESTREAMREADY_PORT_HPP_
#define DRV_BYTESTREAMREADY_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace Drv {

    /// Input ByteStreamReady port description
    /// 

    class InputByteStreamReadyPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = 0 //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum); //!< port callback definition

        InputByteStreamReadyPort(); //!< constructor
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
    /// Output ByteStreamReady port description
    /// 

    class OutputByteStreamReadyPort : public Fw::OutputPortBase {
      public:
        OutputByteStreamReadyPort();
        void init();
        void addCallPort(InputByteStreamReadyPort* callPort);
        void invoke();
      protected:
      private:
        InputByteStreamReadyPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_BYTESTREAMREADY_PORT_HPP_ */

