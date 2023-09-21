/*
 * SerialWritePort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef DRV_SERIALWRITE_PORT_HPP_
#define DRV_SERIALWRITE_PORT_HPP_

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

    /// Input SerialWrite port description
    /// 

    class InputSerialWritePort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = Fw::Buffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, Fw::Buffer &serBuffer); //!< port callback definition

        InputSerialWritePort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(Fw::Buffer &serBuffer); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output SerialWrite port description
    /// 

    class OutputSerialWritePort : public Fw::OutputPortBase {
      public:
        OutputSerialWritePort();
        void init();
        void addCallPort(InputSerialWritePort* callPort);
        void invoke(Fw::Buffer &serBuffer);
      protected:
      private:
        InputSerialWritePort* m_port;
    };
} // end namespace Drv
#endif /* DRV_SERIALWRITE_PORT_HPP_ */

