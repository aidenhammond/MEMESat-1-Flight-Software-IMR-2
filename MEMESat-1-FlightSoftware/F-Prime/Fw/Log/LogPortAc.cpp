#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Log/LogPortAc.hpp>
namespace Fw {


    namespace {

        class LogPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputLogPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputLogPort::SERIALIZED_SIZE];

        };

    }
    InputLogPort::InputLogPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputLogPort::init() {
        Fw::InputPortBase::init();
    }

    void InputLogPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputLogPort::invoke(FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::LogBuffer &args) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, id, timeTag, severity, args);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputLogPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        FwEventIdType id;
        _status = buffer.deserialize(id);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::Time timeTag;
        _status = buffer.deserialize(timeTag);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::LogSeverity severity;
        _status = buffer.deserialize(severity);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::LogBuffer args;
        _status = buffer.deserialize(args);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, id, timeTag, severity, args);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputLogPort::OutputLogPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputLogPort::init() {
    Fw::OutputPortBase::init();
}

void OutputLogPort::addCallPort(InputLogPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputLogPort::invoke(FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::LogBuffer &args) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(id, timeTag, severity, args);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        LogPortBuffer _buffer;
        status = _buffer.serialize(id);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(timeTag);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(severity);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(args);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputLogPort::invoke(...)

} // end namespace Fw
