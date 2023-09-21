#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Drv/Udp/ByteStreamRecvPortAc.hpp>
namespace Drv {


    namespace {

        class ByteStreamRecvPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputByteStreamRecvPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputByteStreamRecvPort::SERIALIZED_SIZE];

        };

    }
    InputByteStreamRecvPort::InputByteStreamRecvPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputByteStreamRecvPort::init() {
        Fw::InputPortBase::init();
    }

    void InputByteStreamRecvPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputByteStreamRecvPort::invoke(Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, recvBuffer, recvStatus);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputByteStreamRecvPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        Fw::Buffer recvBuffer;
        _status = buffer.deserialize(recvBuffer);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        Drv::RecvStatus recvStatus;
        _status = buffer.deserialize(recvStatus);
        if (Fw::FW_SERIALIZE_OK != _status) {
            return _status;
        }

        this->m_func(this->m_comp, this->m_portNum, recvBuffer, recvStatus);
    
        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputByteStreamRecvPort::OutputByteStreamRecvPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputByteStreamRecvPort::init() {
    Fw::OutputPortBase::init();
}

void OutputByteStreamRecvPort::addCallPort(InputByteStreamRecvPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

void OutputByteStreamRecvPort::invoke(Fw::Buffer &recvBuffer, const Drv::RecvStatus &recvStatus) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(recvBuffer, recvStatus);
#if FW_PORT_SERIALIZATION
    } else if (this->m_serPort) {

        Fw::SerializeStatus status;

        ByteStreamRecvPortBuffer _buffer;
        status = _buffer.serialize(recvBuffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(recvStatus);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = this->m_serPort->invokeSerial(_buffer);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));
    }
#else
    }
#endif

} // end OutputByteStreamRecvPort::invoke(...)

} // end namespace Drv
