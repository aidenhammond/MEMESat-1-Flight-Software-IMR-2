#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Fw/Cmd/CmdResponsePortAc.hpp>
namespace Fw {


    namespace {

        class CmdResponsePortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputCmdResponsePort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputCmdResponsePort::SERIALIZED_SIZE];

        };

    }
    InputCmdResponsePort::InputCmdResponsePort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputCmdResponsePort::init() {
        Fw::InputPortBase::init();
    }

    void InputCmdResponsePort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputCmdResponsePort::invoke(FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdResponse &response) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, opCode, cmdSeq, response);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputCmdResponsePort::invokeSerial(Fw::SerializeBufferBase &buffer) {
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

        Fw::CmdResponse response;
        _status = buffer.deserialize(response);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, opCode, cmdSeq, response);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputCmdResponsePort::OutputCmdResponsePort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputCmdResponsePort::init() {
    Fw::OutputPortBase::init();
}

void OutputCmdResponsePort::addCallPort(InputCmdResponsePort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputCmdResponsePort::invoke(FwOpcodeType opCode, U32 cmdSeq, const Fw::CmdResponse &response) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(opCode, cmdSeq, response);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        CmdResponsePortBuffer _buffer;
        status = _buffer.serialize(opCode);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(cmdSeq);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(response);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputCmdResponsePort::invoke(...)

} // end namespace Fw
