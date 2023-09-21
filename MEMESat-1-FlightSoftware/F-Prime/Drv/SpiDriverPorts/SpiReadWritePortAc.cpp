#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/SpiDriverPorts/SpiReadWritePortAc.hpp>
namespace Drv {


    namespace {

        class SpiReadWritePortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputSpiReadWritePort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputSpiReadWritePort::SERIALIZED_SIZE];

        };

    }
    InputSpiReadWritePort::InputSpiReadWritePort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputSpiReadWritePort::init() {
        Fw::InputPortBase::init();
    }

    void InputSpiReadWritePort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputSpiReadWritePort::invoke(Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, writeBuffer, readBuffer);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputSpiReadWritePort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Fw::Buffer writeBuffer;
        _status = buffer.deserialize(writeBuffer);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::Buffer readBuffer;
        _status = buffer.deserialize(readBuffer);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, writeBuffer, readBuffer);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputSpiReadWritePort::OutputSpiReadWritePort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputSpiReadWritePort::init() {
    Fw::OutputPortBase::init();
}

void OutputSpiReadWritePort::addCallPort(InputSpiReadWritePort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputSpiReadWritePort::invoke(Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(writeBuffer, readBuffer);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        SpiReadWritePortBuffer _buffer;
        status = _buffer.serialize(writeBuffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(readBuffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputSpiReadWritePort::invoke(...)

} // end namespace Drv
