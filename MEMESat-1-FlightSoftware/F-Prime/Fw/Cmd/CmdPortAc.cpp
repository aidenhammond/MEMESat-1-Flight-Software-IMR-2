#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Cmd/CmdPortAc.hpp>
namespace Fw {


    namespace {

        class CmdPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputCmdPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputCmdPort::SERIALIZED_SIZE];

        };

    }
    InputCmdPort::InputCmdPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputCmdPort::init() {
        Fw::InputPortBase::init();
    }

    void InputCmdPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputCmdPort::invoke(FwOpcodeType opCode, U32 cmdSeq, Fw::CmdArgBuffer &args) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, opCode, cmdSeq, args);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputCmdPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        FwOpcodeType opCode;
        _status = buffer.deserialize(opCode);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        U32 cmdSeq;
        _status = buffer.deserialize(cmdSeq);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Fw::CmdArgBuffer args;
        _status = buffer.deserialize(args);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, opCode, cmdSeq, args);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputCmdPort::OutputCmdPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputCmdPort::init() {
    Fw::OutputPortBase::init();
}

void OutputCmdPort::addCallPort(InputCmdPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputCmdPort::invoke(FwOpcodeType opCode, U32 cmdSeq, Fw::CmdArgBuffer &args) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(opCode, cmdSeq, args);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        CmdPortBuffer _buffer;
        status = _buffer.serialize(opCode);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(cmdSeq);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(args);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputCmdPort::invoke(...)

} // end namespace Fw
