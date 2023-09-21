// ======================================================================
// \title  ActiveTextLoggerComponentAc.cpp
// \author Auto-generated
// \brief  cpp file for ActiveTextLogger component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <cstdio>
#include <FpConfig.hpp>
#include <Svc/ActiveTextLogger/ActiveTextLoggerComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#if FW_ENABLE_TEXT_LOGGING
#include <Fw/Types/String.hpp>
#endif


namespace Svc {

  // ----------------------------------------------------------------------
  // Anonymous namespace to prevent name collisions
  // ----------------------------------------------------------------------

  namespace {

    typedef enum {
      ACTIVETEXTLOGGER_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
      INT_IF_TEXTQUEUE
    } MsgTypeEnum;

    // Get the max size by doing a union of the input port serialization sizes.

    typedef union {
      // Size of TextQueue argument list
      BYTE TextQueueIntIfSize[
        Fw::InternalInterfaceString::SERIALIZED_SIZE +
        0
      ];
    } BuffUnion;

    // Define a message buffer class large enough to handle all the
    // asynchronous inputs to the component

    class ComponentIpcSerializableBuffer :
      public Fw::SerializeBufferBase
    {

      public:

        enum {
          // Max. message size = size of data + message id + port
          SERIALIZATION_SIZE =
            sizeof(BuffUnion) +
            sizeof(NATIVE_INT_TYPE) +
            sizeof(NATIVE_INT_TYPE)
        };

        NATIVE_UINT_TYPE getBuffCapacity() const {
          return sizeof(m_buff);
        }

        U8* getBuffAddr() {
          return m_buff;
        }

        const U8* getBuffAddr() const {
          return m_buff;
        }

      private:
        // Should be the max of all the input ports serialized sizes...
        U8 m_buff[SERIALIZATION_SIZE];

    };

  }

  // ----------------------------------------------------------------------
  // Getters for numbers of input ports
  // ----------------------------------------------------------------------

  Fw::InputLogTextPort *ActiveTextLoggerComponentBase ::
    get_TextLogger_InputPort(NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_TextLogger_InputPorts(),static_cast<AssertArg>(portNum));
    return &this->m_TextLogger_InputPort[portNum];
  }

  // ----------------------------------------------------------------------
  // Component construction, initialization, and destruction
  // ----------------------------------------------------------------------

    ActiveTextLoggerComponentBase :: ActiveTextLoggerComponentBase(const char* compName) :
        Fw::ActiveComponentBase(compName) {



  }

  void ActiveTextLoggerComponentBase ::
    init(
        NATIVE_INT_TYPE queueDepth,
        NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class
    Fw::ActiveComponentBase::init(instance);

    // Connect input port TextLogger
    for (
        NATIVE_INT_TYPE port = 0;
        port < this->getNum_TextLogger_InputPorts();
        port++
    ) {

      this->m_TextLogger_InputPort[port].init();
      this->m_TextLogger_InputPort[port].addCallComp(
          this,
          m_p_TextLogger_in
      );
      this->m_TextLogger_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
      char portName[120];
      (void) snprintf(
          portName,
          sizeof(portName),
          "%s_TextLogger_InputPort[%d]",
          this->m_objName,
          port
      );
      this->m_TextLogger_InputPort[port].setObjName(portName);
#endif

    }

    Os::Queue::QueueStatus qStat =
    this->createQueue(
        queueDepth,
        ComponentIpcSerializableBuffer::SERIALIZATION_SIZE
    );
    FW_ASSERT(
        Os::Queue::QUEUE_OK == qStat,
        static_cast<AssertArg>(qStat)
    );

  }

  ActiveTextLoggerComponentBase::
    ~ActiveTextLoggerComponentBase() {

  }

  // ----------------------------------------------------------------------
  // Invocation functions for output ports
  // ----------------------------------------------------------------------

  // ----------------------------------------------------------------------
  // Getters for numbers of ports
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ActiveTextLoggerComponentBase ::
    getNum_TextLogger_InputPorts()
  {
    return static_cast<NATIVE_INT_TYPE>(FW_NUM_ARRAY_ELEMENTS(this->m_TextLogger_InputPort));
  }

  // ----------------------------------------------------------------------
  // Invocation functions for interfaces
  // ----------------------------------------------------------------------

  void ActiveTextLoggerComponentBase::
    TextQueue_internalInterfaceInvoke(
        const Fw::InternalInterfaceString& text
    )
  {

    ComponentIpcSerializableBuffer msg;
    Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

    // Serialize the message ID
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(INT_IF_TEXTQUEUE));
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    // Fake port number to make message dequeue work
    _status = msg.serialize(static_cast<NATIVE_INT_TYPE>(0));
    FW_ASSERT (
        _status == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(_status)
    );

    _status = msg.serialize(text);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK, static_cast<AssertArg>(_status));

    // send message
    Os::Queue::QueueBlocking _block =
      Os::Queue::QUEUE_NONBLOCKING;
    Os::Queue::QueueStatus qStatus =
      this->m_queue.send(msg, 1,_block);
    if (qStatus == Os::Queue::QUEUE_FULL) {
        this->incNumMsgDropped();
        return;
    }
    FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(qStatus)
    );

  }

  // ----------------------------------------------------------------------
  // Calls for invocations received on typed input ports
  // ----------------------------------------------------------------------

  void ActiveTextLoggerComponentBase ::
    m_p_TextLogger_in(
        Fw::PassiveComponentBase* callComp,
        NATIVE_INT_TYPE portNum,
        FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::TextLogString &text
    )
  {
    FW_ASSERT(callComp);
    ActiveTextLoggerComponentBase* compPtr = static_cast<ActiveTextLoggerComponentBase*>(callComp);
    compPtr->TextLogger_handlerBase(portNum, id, timeTag, severity, text);
  }

  // ----------------------------------------------------------------------
  // Port handler base-class functions for typed input ports
  // ----------------------------------------------------------------------

  void ActiveTextLoggerComponentBase ::
    TextLogger_handlerBase(
        NATIVE_INT_TYPE portNum,
        FwEventIdType id, Fw::Time &timeTag, const Fw::LogSeverity &severity, Fw::TextLogString &text
    )
  {

    // Make sure port number is valid
    FW_ASSERT(portNum < this->getNum_TextLogger_InputPorts(),static_cast<AssertArg>(portNum));

    // Down call to pure virtual handler method implemented in Impl class
    this->TextLogger_handler(portNum, id, timeTag, severity, text);

  }

  // ----------------------------------------------------------------------
  // Message dispatch method for active and queued components. Called
  // by active component thread or implementation code for queued components
  // ----------------------------------------------------------------------

  Fw::QueuedComponentBase::MsgDispatchStatus ActiveTextLoggerComponentBase ::
    doDispatch()
  {
    ComponentIpcSerializableBuffer msg;
    NATIVE_INT_TYPE priority = 0;

    Os::Queue::QueueStatus msgStatus = this->m_queue.receive(msg,priority,Os::Queue::QUEUE_BLOCKING);
    FW_ASSERT(
        msgStatus == Os::Queue::QUEUE_OK,
        static_cast<AssertArg>(msgStatus)
    );

    // Reset to beginning of buffer
    msg.resetDeser();

    NATIVE_INT_TYPE desMsg = 0;
    Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(deserStatus)
    );

    MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

    if (msgType == ACTIVETEXTLOGGER_COMPONENT_EXIT) {
      return MSG_DISPATCH_EXIT;
    }

    NATIVE_INT_TYPE portNum = 0;
    deserStatus = msg.deserialize(portNum);
    FW_ASSERT(
        deserStatus == Fw::FW_SERIALIZE_OK,
        static_cast<AssertArg>(deserStatus)
    );

    switch (msgType) {

      // Handle internal interface TextQueue
      case INT_IF_TEXTQUEUE: {

        Fw::InternalInterfaceString text;
        deserStatus = msg.deserialize(text);

        // Internal interfaces should always deserialize
        FW_ASSERT(
            Fw::FW_SERIALIZE_OK == deserStatus,
            static_cast<AssertArg>(deserStatus)
        );

        // Make sure there was no data left over.
        // That means the buffer size was incorrect.
        FW_ASSERT(
            msg.getBuffLeft() == 0,
            static_cast<AssertArg>(msg.getBuffLeft())
        );

        // Call handler function
        this->TextQueue_internalInterfaceHandler(text);

        break;

      }

      default:
        return MSG_DISPATCH_ERROR;

    }

    return MSG_DISPATCH_OK;

  }

} // end namespace Svc
