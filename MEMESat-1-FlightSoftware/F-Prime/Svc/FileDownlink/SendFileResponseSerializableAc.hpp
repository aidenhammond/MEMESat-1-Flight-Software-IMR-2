/*
 * SendFileResponse.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SENDFILERESPONSE_HPP_
#define SENDFILERESPONSE_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/StringType.hpp>
#include <cstdio> // snprintf
#ifdef BUILD_UT
#include <iostream>
#include <Fw/Types/String.hpp>
#endif
#endif
#include <Svc/FileDownlink/SendFileStatusEnumAc.hpp>

namespace Svc {

class SendFileResponse : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        Svc::SendFileStatus::SERIALIZED_SIZE +
        sizeof(U32)
    }; //!< serializable size of SendFileResponse

    SendFileResponse(); //!< Default constructor
    SendFileResponse(const SendFileResponse* src); //!< pointer copy constructor
    SendFileResponse(const SendFileResponse& src); //!< reference copy constructor
    SendFileResponse(const Svc::SendFileStatus& status, U32 context); //!< constructor with arguments
    SendFileResponse& operator=(const SendFileResponse& src); //!< equal operator
    bool operator==(const SendFileResponse& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const SendFileResponse& obj);
#endif

    void set(const Svc::SendFileStatus& status, U32 context); //!< set values

    const Svc::SendFileStatus& getstatus() const; //!< get member status
    U32 getcontext() const; //!< get member context

    void setstatus(const Svc::SendFileStatus& val); //!< set member status
    void setcontext(U32 val); //!< set member context


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0xD4B93574 //!< type id
    };

    Svc::SendFileStatus m_status; //<! status - 
    U32 m_context; //<! context - 
private:

};
} // end namespace Svc
#endif /* SENDFILERESPONSE_HPP_ */

