#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/I2cDriverPorts/I2cWriteReadPortAc.hpp>
namespace Drv {


    namespace {

        class I2cWriteReadPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputI2cWriteReadPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputI2cWriteReadPort::SERIALIZED_SIZE];

        };

    }
    InputI2cWriteReadPort::InputI2cWriteReadPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputI2cWriteReadPort::init() {
        Fw::InputPortBase::init();
    }

    void InputI2cWriteReadPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    Drv::I2cStatus InputI2cWriteReadPort::invoke(U32 addr, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        return this->m_func(this->m_comp, this->m_portNum, addr, writeBuffer, readBuffer);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputI2cWriteReadPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        FW_ASSERT(0);

        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputI2cWriteReadPort::OutputI2cWriteReadPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputI2cWriteReadPort::init() {
    Fw::OutputPortBase::init();
}

void OutputI2cWriteReadPort::addCallPort(InputI2cWriteReadPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

Drv::I2cStatus OutputI2cWriteReadPort::invoke(U32 addr, Fw::Buffer &writeBuffer, Fw::Buffer &readBuffer) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    return this->m_port->invoke(addr, writeBuffer, readBuffer);

} // end OutputI2cWriteReadPort::invoke(...)

} // end namespace Drv
