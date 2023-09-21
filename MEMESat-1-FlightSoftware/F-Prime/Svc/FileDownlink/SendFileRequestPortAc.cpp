#include <FpConfig.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringUtils.hpp>

#include <Svc/FileDownlink/SendFileRequestPortAc.hpp>
namespace Svc {


    sourceFileNameString::sourceFileNameString(const char* src): StringBase() {
        Fw::StringUtils::string_copy(this->m_buf, src, sizeof(this->m_buf));
    }

    sourceFileNameString::sourceFileNameString(const Fw::StringBase& src): StringBase() {
         Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
    }

    sourceFileNameString::sourceFileNameString(const sourceFileNameString& src): StringBase() {
         Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
    }

    sourceFileNameString::sourceFileNameString(): StringBase() {
        this->m_buf[0] = 0;
    }

    sourceFileNameString& sourceFileNameString::operator=(const sourceFileNameString& other) {
        if(this == &other) {
            return *this;
        }

        Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
        return *this;
    }

    sourceFileNameString& sourceFileNameString::operator=(const StringBase& other) {
        if(this == &other) {
            return *this;
        }

        Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
        return *this;
    }

    sourceFileNameString& sourceFileNameString::operator=(const char* other) {
        Fw::StringUtils::string_copy(this->m_buf, other, sizeof(this->m_buf));
        return *this;
    }

    sourceFileNameString::~sourceFileNameString() {
    }

    const char* sourceFileNameString::toChar() const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE sourceFileNameString::getCapacity() const {
        return sizeof(this->m_buf);
    }


    destFileNameString::destFileNameString(const char* src): StringBase() {
        Fw::StringUtils::string_copy(this->m_buf, src, sizeof(this->m_buf));
    }

    destFileNameString::destFileNameString(const Fw::StringBase& src): StringBase() {
         Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
    }

    destFileNameString::destFileNameString(const destFileNameString& src): StringBase() {
         Fw::StringUtils::string_copy(this->m_buf, src.toChar(), sizeof(this->m_buf));
    }

    destFileNameString::destFileNameString(): StringBase() {
        this->m_buf[0] = 0;
    }

    destFileNameString& destFileNameString::operator=(const destFileNameString& other) {
        if(this == &other) {
            return *this;
        }

        Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
        return *this;
    }

    destFileNameString& destFileNameString::operator=(const StringBase& other) {
        if(this == &other) {
            return *this;
        }

        Fw::StringUtils::string_copy(this->m_buf, other.toChar(), sizeof(this->m_buf));
        return *this;
    }

    destFileNameString& destFileNameString::operator=(const char* other) {
        Fw::StringUtils::string_copy(this->m_buf, other, sizeof(this->m_buf));
        return *this;
    }

    destFileNameString::~destFileNameString() {
    }

    const char* destFileNameString::toChar() const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE destFileNameString::getCapacity() const {
        return sizeof(this->m_buf);
    }


    namespace {

        class SendFileRequestPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity() const {
                    return InputSendFileRequestPort::SERIALIZED_SIZE;
                }

                U8* getBuffAddr() {
                    return m_buff;
                }

                const U8* getBuffAddr() const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputSendFileRequestPort::SERIALIZED_SIZE];

        };

    }
    InputSendFileRequestPort::InputSendFileRequestPort() :
        Fw::InputPortBase(),
        m_func(nullptr) {
    }

    void InputSendFileRequestPort::init() {
        Fw::InputPortBase::init();
    }

    void InputSendFileRequestPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    Svc::SendFileResponse InputSendFileRequestPort::invoke(const sourceFileNameString &sourceFileName, const destFileNameString &destFileName, U32 offset, U32 length) {

#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        return this->m_func(this->m_comp, this->m_portNum, sourceFileName, destFileName, offset, length);
    }

#if FW_PORT_SERIALIZATION == 1    
    Fw::SerializeStatus InputSendFileRequestPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        FW_ASSERT(0);

        return Fw::FW_SERIALIZE_OK;
    }
#endif

OutputSendFileRequestPort::OutputSendFileRequestPort() :
            Fw::OutputPortBase(),
    m_port(nullptr) {
}

void OutputSendFileRequestPort::init() {
    Fw::OutputPortBase::init();
}

void OutputSendFileRequestPort::addCallPort(InputSendFileRequestPort* callPort) {
    FW_ASSERT(callPort);

    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = nullptr;
#endif
}

Svc::SendFileResponse OutputSendFileRequestPort::invoke(const sourceFileNameString &sourceFileName, const destFileNameString &destFileName, U32 offset, U32 length) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    return this->m_port->invoke(sourceFileName, destFileName, offset, length);

} // end OutputSendFileRequestPort::invoke(...)

} // end namespace Svc
