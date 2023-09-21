#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/GpioDriverPorts/GpioReadPortAc.hpp>
namespace Drv {


    namespace {

        class GpioReadPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputGpioReadPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputGpioReadPort::SERIALIZED_SIZE];

        };

    }
    InputGpioReadPort::InputGpioReadPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputGpioReadPort::init() {
        Fw::InputPortBase::init();
    }

    void InputGpioReadPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputGpioReadPort::invoke(bool &state) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, state);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputGpioReadPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
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

OutputGpioReadPort::OutputGpioReadPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputGpioReadPort::init() {
    Fw::OutputPortBase::init();
}

void OutputGpioReadPort::addCallPort(InputGpioReadPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputGpioReadPort::invoke(bool &state) {
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

        GpioReadPortBuffer _buffer;
        status = _buffer.serialize(state);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputGpioReadPort::invoke(...)

} // end namespace Drv
