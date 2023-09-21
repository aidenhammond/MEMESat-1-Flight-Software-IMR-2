#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/GpioDriverPorts/GpioWritePortAc.hpp>
namespace Drv {


    namespace {

        class GpioWritePortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputGpioWritePort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputGpioWritePort::SERIALIZED_SIZE];

        };

    }
    InputGpioWritePort::InputGpioWritePort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputGpioWritePort::init() {
        Fw::InputPortBase::init();
    }

    void InputGpioWritePort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputGpioWritePort::invoke(bool state) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, state);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputGpioWritePort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        bool state;
        _status = buffer.deserialize(state);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, state);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputGpioWritePort::OutputGpioWritePort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputGpioWritePort::init() {
    Fw::OutputPortBase::init();
}

void OutputGpioWritePort::addCallPort(InputGpioWritePort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputGpioWritePort::invoke(bool state) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(state);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        GpioWritePortBuffer _buffer;
        status = _buffer.serialize(state);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputGpioWritePort::invoke(...)

} // end namespace Drv
