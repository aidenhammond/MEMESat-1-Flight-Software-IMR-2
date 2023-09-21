/*
 * I2cPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_I2C_PORT_HPP_
#define DRV_I2C_PORT_HPP_

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

    /// Input I2c port description
    /// 

    class InputI2cPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(U32) + Fw::Buffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef Drv::I2cStatus (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, U32 addr, Fw::Buffer &serBuffer); //!< port callback definition

        InputI2cPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Drv::I2cStatus invoke(U32 addr, Fw::Buffer &serBuffer); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output I2c port description
    /// 

    class OutputI2cPort : public Fw::OutputPortBase {
      public:
        OutputI2cPort();
        void init();
        void addCallPort(InputI2cPort* callPort);
        Drv::I2cStatus invoke(U32 addr, Fw::Buffer &serBuffer);
      protected:
      private:
        InputI2cPort* m_port;
    };
} // end namespace Drv
#endif /* DRV_I2C_PORT_HPP_ */

