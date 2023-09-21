#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/I2cDriverPorts/I2cPortAc.hpp>
namespace Drv {


    namespace {

        class I2cPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputI2cPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputI2cPort::SERIALIZED_SIZE];

        };

    }
    InputI2cPort::InputI2cPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputI2cPort::init() {
        Fw::InputPortBase::init();
    }

    void InputI2cPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    Drv::I2cStatus InputI2cPort::invoke(U32 addr, Fw::Buffer &serBuffer) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        return this->m_func(this->m_comp, this->m_portNum, addr, serBuffer);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputI2cPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        FW_ASSERT(0);

        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputI2cPort::OutputI2cPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputI2cPort::init() {
    Fw::OutputPortBase::init();
}

void OutputI2cPort::addCallPort(InputI2cPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

Drv::I2cStatus OutputI2cPort::invoke(U32 addr, Fw::Buffer &serBuffer) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    return this->m_port->invoke(addr, serBuffer);

} // end OutputI2cPort::invoke(...)

} // end namespace Drv
