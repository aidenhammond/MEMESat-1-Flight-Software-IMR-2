/*
 * SendFileRequestPort.hpp
 *
 *  Created on: Monday, 15 August 2022
 *  Author:     aiden
 *
 */
#ifndef SVC_SENDFILEREQUEST_PORT_HPP_
#define SVC_SENDFILEREQUEST_PORT_HPP_

#include <cstring>
#include <cstdio>
#include <FpConfig.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>
#include <Svc/FileDownlink/SendFileResponseSerializableAc.hpp>


namespace Svc {

    class sourceFileNameString : public Fw::StringBase {
        public:

            enum {
                SERIALIZED_SIZE = 100 + sizeof(FwBuffSizeType) //!< Serialized size of sourceFileNameString
            };

            sourceFileNameString(const char* src); //!< char buffer constructor
            sourceFileNameString(const Fw::StringBase& src); //!< other string constructor
            sourceFileNameString(const sourceFileNameString& src); //!< same type string constructor
            sourceFileNameString(); //!< default constructor
            sourceFileNameString& operator=(const sourceFileNameString& other); //!< assignment operator
            sourceFileNameString& operator=(const Fw::StringBase& other); //!< other string assignment operator
            sourceFileNameString& operator=(const char* other); //!< char* assignment operator
            ~sourceFileNameString(); //!< destructor

            const char* toChar() const; //!< return internal buffer
            NATIVE_UINT_TYPE getCapacity() const;

        private:

            char m_buf[100]; //!< buffer for string
    };


    class destFileNameString : public Fw::StringBase {
        public:

            enum {
                SERIALIZED_SIZE = 100 + sizeof(FwBuffSizeType) //!< Serialized size of destFileNameString
            };

            destFileNameString(const char* src); //!< char buffer constructor
            destFileNameString(const Fw::StringBase& src); //!< other string constructor
            destFileNameString(const destFileNameString& src); //!< same type string constructor
            destFileNameString(); //!< default constructor
            destFileNameString& operator=(const destFileNameString& other); //!< assignment operator
            destFileNameString& operator=(const Fw::StringBase& other); //!< other string assignment operator
            destFileNameString& operator=(const char* other); //!< char* assignment operator
            ~destFileNameString(); //!< destructor

            const char* toChar() const; //!< return internal buffer
            NATIVE_UINT_TYPE getCapacity() const;

        private:

            char m_buf[100]; //!< buffer for string
    };


    /// Input SendFileRequest port description
    /// 

    class InputSendFileRequestPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sourceFileNameString::SERIALIZED_SIZE + destFileNameString::SERIALIZED_SIZE + sizeof(U32) + sizeof(U32) //!< serialized size of port arguments
        };
        typedef Svc::SendFileResponse (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, const sourceFileNameString &sourceFileName, const destFileNameString &destFileName, U32 offset, U32 length); //!< port callback definition

        InputSendFileRequestPort(); //!< constructor
        void init(); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        Svc::SendFileResponse invoke(const sourceFileNameString &sourceFileName, const destFileNameString &destFileName, U32 offset, U32 length); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        Fw::SerializeStatus invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Output SendFileRequest port description
    /// 

    class OutputSendFileRequestPort : public Fw::OutputPortBase {
      public:
        OutputSendFileRequestPort();
        void init();
        void addCallPort(InputSendFileRequestPort* callPort);
        Svc::SendFileResponse invoke(const sourceFileNameString &sourceFileName, const destFileNameString &destFileName, U32 offset, U32 length);
      protected:
      private:
        InputSendFileRequestPort* m_port;
    };
} // end namespace Svc
#endif /* SVC_SENDFILEREQUEST_PORT_HPP_ */

