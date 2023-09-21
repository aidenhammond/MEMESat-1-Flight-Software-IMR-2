/*
 * ByteStreamPollPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_BYTESTREAMPOLL_PORT_HPP_
#define DRV_BYTESTREAMPOLL_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Drv/ByteStreamDriverModel/PollStatusEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>


namespace Drv {

    /// Input ByteStreamPoll port description
    /// 

    class InputByteStreamPollPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::Buffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef Drv::PollStatus (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::Buffer &pollBuffer); //!< port callback definition

        InputByteStreamPollPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Drv::PollStatus invoke(Fw::Buffer &pollBuffer); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output ByteStreamPoll port description
    /// 

    class OutputByteStreamPollPort : public Fw::OutputPortBase {
      public:
        OutputByteStreamPollPort();
        void init();
        void addCallPort(InputByteStreamPollPort* callPort);
        Drv::PollStatus invoke(Fw::Buffer &pollBuffer);
      protected:
      private:
        InputByteStreamPollPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_BYTESTREAMPOLL_PORT_HPP_ */

