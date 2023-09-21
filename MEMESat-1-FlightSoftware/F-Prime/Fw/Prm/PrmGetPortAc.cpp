#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Prm/PrmGetPortAc.hpp>
namespace Fw {


    namespace {

        class PrmGetPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputPrmGetPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputPrmGetPort::SERIALIZED_SIZE];

        };

    }
    InputPrmGetPort::InputPrmGetPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputPrmGetPort::init() {
        Fw::InputPortBase::init();
    }

    void InputPrmGetPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    Fw::ParamValid InputPrmGetPort::invoke(FwPrmIdType id, Fw::ParamBuffer &val) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        return this->m_func(this->m_comp, this->m_portNum, id, val);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputPrmGetPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        FW_ASSERT(0);

        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputPrmGetPort::OutputPrmGetPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputPrmGetPort::init() {
    Fw::OutputPortBase::init();
}

void OutputPrmGetPort::addCallPort(InputPrmGetPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

Fw::ParamValid OutputPrmGetPort::invoke(FwPrmIdType id, Fw::ParamBuffer &val) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    return this->m_port->invoke(id, val);

} // end OutputPrmGetPort::invoke(...)

} // end namespace Fw
