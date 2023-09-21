#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Prm/PrmSetPortAc.hpp>
namespace Fw {


    namespace {

        class PrmSetPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputPrmSetPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputPrmSetPort::SERIALIZED_SIZE];

        };

    }
    InputPrmSetPort::InputPrmSetPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputPrmSetPort::init() {
        Fw::InputPortBase::init();
    }

    void InputPrmSetPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputPrmSetPort::invoke(FwPrmIdType id, Fw::ParamBuffer &val) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, id, val);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputPrmSetPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        FwPrmIdType id;
        _status = buffer.deserialize(id);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::ParamBuffer val;
        _status = buffer.deserialize(val);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, id, val);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputPrmSetPort::OutputPrmSetPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputPrmSetPort::init() {
    Fw::OutputPortBase::init();
}

void OutputPrmSetPort::addCallPort(InputPrmSetPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputPrmSetPort::invoke(FwPrmIdType id, Fw::ParamBuffer &val) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(id, val);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        PrmSetPortBuffer _buffer;
        status = _buffer.serialize(id);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(val);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputPrmSetPort::invoke(...)

} // end namespace Fw
