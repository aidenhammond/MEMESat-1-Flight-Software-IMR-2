#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Svc/Fatal/FatalEventPortAc.hpp>
namespace Svc {


    namespace {

        class FatalEventPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputFatalEventPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputFatalEventPort::SERIALIZED_SIZE];

        };

    }
    InputFatalEventPort::InputFatalEventPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputFatalEventPort::init() {
        Fw::InputPortBase::init();
    }

    void InputFatalEventPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputFatalEventPort::invoke(FwEventIdType Id) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, Id);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputFatalEventPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        FwEventIdType Id;
        _status = buffer.deserialize(Id);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, Id);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputFatalEventPort::OutputFatalEventPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputFatalEventPort::init() {
    Fw::OutputPortBase::init();
}

void OutputFatalEventPort::addCallPort(InputFatalEventPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputFatalEventPort::invoke(FwEventIdType Id) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(Id);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        FatalEventPortBuffer _buffer;
        status = _buffer.serialize(Id);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputFatalEventPort::invoke(...)

} // end namespace Svc
