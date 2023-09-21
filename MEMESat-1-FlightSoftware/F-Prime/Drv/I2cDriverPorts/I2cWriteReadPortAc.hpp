/*
 * I2cWriteReadPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_I2CWRITEREAD_PORT_HPP_
#define DRV_I2CWRITEREAD_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Drv/I2cDriverPorts/I2cStatusEnumAc.hpp>
#include <Fw/Buffer/Buffer.hpp>


namespace Drv {

    /// Input I2cWriteRead port description
    /// 

    class InputI2cWriteReadPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(U32) + Fw::Buffer::SERIALIZED_SIZE + Fw::Buffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef Drv::I2cStatus (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, U32 addr, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer); //!< port callback definition

        InputI2cWriteReadPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Drv::I2cStatus invoke(U32 addr, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output I2cWriteRead port description
    /// 

    class OutputI2cWriteReadPort : public Fw::OutputPortBase {
      public:
        OutputI2cWriteReadPort();
        void init();
        void addCallPort(InputI2cWriteReadPort* callPort);
        Drv::I2cStatus invoke(U32 addr, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer);
      protected:
      private:
        InputI2cWriteReadPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_I2CWRITEREAD_PORT_HPP_ */

