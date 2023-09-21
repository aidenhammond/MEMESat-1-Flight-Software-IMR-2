/*
 * PrmSetPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_PRMSET_PORT_HPP_
#define FW_PRMSET_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Prm/ParamBuffer.hpp>


namespace Fw {

    /// Input PrmSet port description
    /// 

    class InputPrmSetPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(FwPrmIdType) + Fw::ParamBuffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, FwPrmIdType id, Fw::ParamBuffer &val); //!< port callback definition

        InputPrmSetPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(FwPrmIdType id, Fw::ParamBuffer &val); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output PrmSet port description
    /// 

    class OutputPrmSetPort : public Fw::OutputPortBase {
      public:
        OutputPrmSetPort();
        void init();
        void addCallPort(InputPrmSetPort* callPort);
        void invoke(FwPrmIdType id, Fw::ParamBuffer &val);
      protected:
      private:
        InputPrmSetPort* m_port;
    };
} // end namespace Fw
#endif /* FW_PRMSET_PORT_HPP_ */

