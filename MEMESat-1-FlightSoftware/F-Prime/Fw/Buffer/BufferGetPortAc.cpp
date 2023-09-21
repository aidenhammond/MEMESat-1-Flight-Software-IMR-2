#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Buffer/BufferGetPortAc.hpp>
namespace Fw {


    namespace {

        class BufferGetPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputBufferGetPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputBufferGetPort::SERIALIZED_SIZE];

        };

    }
    InputBufferGetPort::InputBufferGetPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputBufferGetPort::init() {
        Fw::InputPortBase::init();
    }

    void InputBufferGetPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    Fw::Buffer InputBufferGetPort::invoke(U32 size) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        return this->m_func(this->m_comp, this->m_portNum, size);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputBufferGetPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        FW_ASSERT(0);

        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputBufferGetPort::OutputBufferGetPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputBufferGetPort::init() {
    Fw::OutputPortBase::init();
}

void OutputBufferGetPort::addCallPort(InputBufferGetPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

Fw::Buffer OutputBufferGetPort::invoke(U32 size) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    return this->m_port->invoke(size);

} // end OutputBufferGetPort::invoke(...)

} // end namespace Fw
