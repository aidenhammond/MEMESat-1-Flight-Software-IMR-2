#include <Svc/FileDownlink/SendFileResponseSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/StringUtils.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/String.hpp>
#endif
#include <cstring>
namespace Svc {
// public methods

SendFileResponse::SendFileResponse(): Serializable() {
    this->m_status = Svc::SendFileStatus::STATUS_OK;
    this->m_context = 0;
}

SendFileResponse::SendFileResponse(const SendFileResponse& src) : Serializable() {
    this->set(src.m_status, src.m_context);
}

SendFileResponse::SendFileResponse(const SendFileResponse* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_status, src->m_context);
}

SendFileResponse::SendFileResponse(const Svc::SendFileStatus& status, U32 context) : Serializable() {
    this->set(status, context);
}


SendFileResponse& SendFileResponse::operator=(const SendFileResponse& src) {
    if(this == &src) {
            return *this;
    }

    this->set(src.m_status, src.m_context);
    return *this;
}

bool SendFileResponse::operator==(const SendFileResponse& src) const {
    return (
        (src.m_status == this->m_status) &&
        (src.m_context == this->m_context) &&
        true);
}

void SendFileResponse::set(const Svc::SendFileStatus& status, U32 context) {
    this->m_status = status;
    this->m_context = context;
}

const Svc::SendFileStatus& SendFileResponse::getstatus() const {
    return this->m_status;
}

U32 SendFileResponse::getcontext() const {
    return this->m_context;
}


void SendFileResponse::setstatus(const Svc::SendFileStatus& val) {
    this->m_status = val;
}
void SendFileResponse::setcontext(U32 val) {
    this->m_context = val;
}
Fw::SerializeStatus SendFileResponse::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    // serialize type ID
    stat = buffer.serialize(static_cast<U32>(SendFileResponse::TYPE_ID));
#endif

    stat = buffer.serialize(this->m_status);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_context);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus SendFileResponse::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != SendFileResponse::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif

    stat = buffer.deserialize(this->m_status);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_context);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void SendFileResponse::toString(Fw::StringBase& text) const {

    static const char * formatString =
       "("
       "status = %s, "
       "context = "
       ")";

    // declare strings to hold any serializable toString() arguments


    Fw::String statusStr;
    this->m_status.toString(statusStr);

    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,statusStr.toChar()
       ,this->m_context
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate

    text = outputString;
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const SendFileResponse& obj) {
        Fw::String str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Svc
