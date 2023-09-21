#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/SerialDriverPorts/SerialReadPortAc.hpp>
namespace Drv {


    namespace {

        class SerialReadPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputSerialReadPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputSerialReadPort::SERIALIZED_SIZE];

        };

    }
    InputSerialReadPort::InputSerialReadPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputSerialReadPort::init() {
        Fw::InputPortBase::init();
    }

    void InputSerialReadPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputSerialReadPort::invoke(Fw::Buffer &serBuffer, Drv::SerialReadStatus &status) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, serBuffer, status);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputSerialReadPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Fw::Buffer serBuffer;
        _status = buffer.deserialize(serBuffer);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Drv::SerialReadStatus status;
        _status = buffer.deserialize(status);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, serBuffer, status);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputSerialReadPort::OutputSerialReadPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputSerialReadPort::init() {
    Fw::OutputPortBase::init();
}

void OutputSerialReadPort::addCallPort(InputSerialReadPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputSerialReadPort::invoke(Fw::Buffer &serBuffer, Drv::SerialReadStatus &status) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(serBuffer, status);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        SerialReadPortBuffer _buffer;
        status = _buffer.serialize(serBuffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(status);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputSerialReadPort::invoke(...)

} // end namespace Drv
