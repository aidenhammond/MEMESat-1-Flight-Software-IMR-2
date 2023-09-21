#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Com/ComPortAc.hpp>
namespace Fw {


    namespace {

        class ComPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputComPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputComPort::SERIALIZED_SIZE];

        };

    }
    InputComPort::InputComPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputComPort::init() {
        Fw::InputPortBase::init();
    }

    void InputComPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputComPort::invoke(Fw::ComBuffer &data, U32 context) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, data, context);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputComPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Fw::ComBuffer data;
        _status = buffer.deserialize(data);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        U32 context;
        _status = buffer.deserialize(context);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, data, context);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputComPort::OutputComPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputComPort::init() {
    Fw::OutputPortBase::init();
}

void OutputComPort::addCallPort(InputComPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputComPort::invoke(Fw::ComBuffer &data, U32 context) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(data, context);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        ComPortBuffer _buffer;
        status = _buffer.serialize(data);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(context);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputComPort::invoke(...)

} // end namespace Fw
