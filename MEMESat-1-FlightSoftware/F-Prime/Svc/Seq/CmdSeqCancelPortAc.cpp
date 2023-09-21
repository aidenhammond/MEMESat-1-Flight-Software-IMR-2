#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Svc/Seq/CmdSeqCancelPortAc.hpp>
namespace Svc {


    namespace {

        class CmdSeqCancelPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputCmdSeqCancelPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return nullptr;
                }

                const U8* getBuffAddr() const {
                    return nullptr;
                }

        private:


        };

    }
    InputCmdSeqCancelPort::InputCmdSeqCancelPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputCmdSeqCancelPort::init() {
        Fw::InputPortBase::init();
    }

    void InputCmdSeqCancelPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputCmdSeqCancelPort::invoke() {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputCmdSeqCancelPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        this->m_func(this->m_comp, this->m_portNum);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputCmdSeqCancelPort::OutputCmdSeqCancelPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputCmdSeqCancelPort::init() {
    Fw::OutputPortBase::init();
}

void OutputCmdSeqCancelPort::addCallPort(InputCmdSeqCancelPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputCmdSeqCancelPort::invoke() {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke();
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        CmdSeqCancelPortBuffer _buffer;
        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputCmdSeqCancelPort::invoke(...)

} // end namespace Svc
