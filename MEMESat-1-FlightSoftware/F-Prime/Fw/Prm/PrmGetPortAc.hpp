/*
 * PrmGetPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef FW_PRMGET_PORT_HPP_
#define FW_PRMGET_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Prm/ParamValidEnumAc.hpp>
#include <Fw/Prm/ParamBuffer.hpp>


namespace Fw {

    /// Input PrmGet port description
    /// 

    class InputPrmGetPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(FwPrmIdType) + Fw::ParamBuffer::SERIALIZED_SIZE //!< serialized size of port arguments
        };
        typedef Fw::ParamValid (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, FwPrmIdType id, Fw::ParamBuffer &val); //!< port callback definition

        InputPrmGetPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Fw::ParamValid invoke(FwPrmIdType id, Fw::ParamBuffer &val); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output PrmGet port description
    /// 

    class OutputPrmGetPort : public Fw::OutputPortBase {
      public:
        OutputPrmGetPort();
        void init();
        void addCallPort(InputPrmGetPort* callPort);
        Fw::ParamValid invoke(FwPrmIdType id, Fw::ParamBuffer &val);
      protected:
      private:
        InputPrmGetPort* m_port;
    };
} // end namespace Fw
#endif /* FW_PRMGET_PORT_HPP_ */

