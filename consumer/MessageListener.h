#ifndef OMS_MESSAGE_LISTENER_H
#define OMS_MESSAGE_LISTENER_H

#include "smart_pointer.h"
#include "Context.h"
#include "Namespace.h"
#include "Message.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

    /**
     * The message listener interface. A message listener must implement this {@code MessageListener} interface and register
     * itself to a consumer instance to asynchronously receive messages.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class MessageListener : private Uncopyable {
    public:
        virtual ~MessageListener() {

        }

        /**
         * Callback method to receive incoming messages.
         * <p>
         * A message listener should handle different types of {@code Message}.
         *
         * @param message the received message object.
         * @param context the context delivered to the consume thread.
         */
        virtual void onReceived(MessagePtr &message, ContextPtr &context) = 0;
    };

    typedef NS::shared_ptr<MessageListener> MessageListenerPtr;

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_MESSAGE_LISTENER_H
