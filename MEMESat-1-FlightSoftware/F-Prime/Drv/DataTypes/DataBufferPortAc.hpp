/*
 * DataBufferPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_DATABUFFER_PORT_HPP_
#define DRV_DATABUFFER_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Drv/DataTypes/DataBuffer.hpp>


namespace Drv {

    /// Input DataBuffer port description
    /// 

    class InputDataBufferPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Drv::DataBuffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Drv::DataBuffer &buff); //!< port callback definition

        InputDataBufferPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Drv::DataBuffer &buff); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output DataBuffer port description
    /// 

    class OutputDataBufferPort : public Fw::OutputPortBase {
      public:
        OutputDataBufferPort();
        void init();
        void addCallPort(InputDataBufferPort* callPort);
        void invoke(Drv::DataBuffer &buff);
      protected:
      private:
        InputDataBufferPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_DATABUFFER_PORT_HPP_ */

