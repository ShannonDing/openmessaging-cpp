#ifndef OMS_PRODUCER_INTERCEPTOR_H
#define OMS_PRODUCER_INTERCEPTOR_H

#include "Namespace.h"
#include "Uncopyable.h"
#include "smart_pointer.h"
#include "Message.h"

BEGIN_NAMESPACE_3(io, openmessaging, interceptor)

    /**
     * A {@code ProducerInterceptor} is used to intercept send operations of producer.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class ProducerInterceptor : private Uncopyable {
    public:
        virtual ~ProducerInterceptor() {

        }

        virtual std::string name() const = 0;

        /**
         * Invoked before the message is actually sent to the network.
         * <p>
         * This allows for modification of the message if necessary.
         *
         * @param message a message will be sent.
         * @param attributes the extensible attributes delivered to the intercept thread.
         */
        virtual void preSend(const MessagePtr &message, const InterceptorContextPtr &context = kv_nullptr) = 0;

        /**
         * Invoked immediately after the successful send invocation.
         *
         * @param message the message is actually sent.
         * @param attributes the extensible attributes delivered to the intercept thread.
         */
        virtual void postSend(const MessagePtr &message, const InterceptorContextPtr &context = kv_nullptr) = 0;

    };
    typedef NS::shared_ptr<ProducerInterceptor> ProducerInterceptorPtr;

END_NAMESPACE_3(io, openmessaging, interceptor)

#endif // OMS_PRODUCER_INTERCEPTOR_H
