#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Tlm/TlmGetPortAc.hpp>
namespace Fw {


    namespace {

        class TlmGetPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputTlmGetPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputTlmGetPort::SERIALIZED_SIZE];

        };

    }
    InputTlmGetPort::InputTlmGetPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputTlmGetPort::init() {
        Fw::InputPortBase::init();
    }

    void InputTlmGetPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputTlmGetPort::invoke(FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, id, timeTag, val);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputTlmGetPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        FwChanIdType id;
        _status = buffer.deserialize(id);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::Time timeTag;
        _status = buffer.deserialize(timeTag);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::TlmBuffer val;
        _status = buffer.deserialize(val);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, id, timeTag, val);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputTlmGetPort::OutputTlmGetPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputTlmGetPort::init() {
    Fw::OutputPortBase::init();
}

void OutputTlmGetPort::addCallPort(InputTlmGetPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputTlmGetPort::invoke(FwChanIdType id, Fw::Time &timeTag, Fw::TlmBuffer &val) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(id, timeTag, val);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        TlmGetPortBuffer _buffer;
        status = _buffer.serialize(id);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(timeTag);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(val);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputTlmGetPort::invoke(...)

} // end namespace Fw
