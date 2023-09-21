#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/DataTypes/DataBufferPortAc.hpp>
namespace Drv {


    namespace {

        class DataBufferPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputDataBufferPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputDataBufferPort::SERIALIZED_SIZE];

        };

    }
    InputDataBufferPort::InputDataBufferPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputDataBufferPort::init() {
        Fw::InputPortBase::init();
    }

    void InputDataBufferPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputDataBufferPort::invoke(Drv::DataBuffer &buff) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, buff);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputDataBufferPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Drv::DataBuffer buff;
        _status = buffer.deserialize(buff);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, buff);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputDataBufferPort::OutputDataBufferPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputDataBufferPort::init() {
    Fw::OutputPortBase::init();
}

void OutputDataBufferPort::addCallPort(InputDataBufferPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputDataBufferPort::invoke(Drv::DataBuffer &buff) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(buff);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        DataBufferPortBuffer _buffer;
        status = _buffer.serialize(buff);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputDataBufferPort::invoke(...)

} // end namespace Drv
