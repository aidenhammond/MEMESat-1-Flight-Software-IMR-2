/*
 * SpiReadWritePort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_SPIREADWRITE_PORT_HPP_
#define DRV_SPIREADWRITE_PORT_HPP_

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


namespace Drv {

    /// Input SpiReadWrite port description
    /// 

    class InputSpiReadWritePort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::Buffer::SERIALIZED_SIZE + Fw::Buffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer); //!< port callback definition

        InputSpiReadWritePort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output SpiReadWrite port description
    /// 

    class OutputSpiReadWritePort : public Fw::OutputPortBase {
      public:
        OutputSpiReadWritePort();
        void init();
        void addCallPort(InputSpiReadWritePort* callPort);
        void invoke(Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer);
      protected:
      private:
        InputSpiReadWritePort* m_port;
    };
} // end namespace Drv
#endif /* DRV_SPIREADWRITE_PORT_HPP_ */

