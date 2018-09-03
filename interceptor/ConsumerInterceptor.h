#ifndef OMS_CONSUMER_INTERCEPTOR_H
#define OMS_CONSUMER_INTERCEPTOR_H

#include "smart_pointer.h"
#include "Namespace.h"
#include "Uncopyable.h"
#include "Message.h"

BEGIN_NAMESPACE_3(io, openmessaging, interceptor)

    /**
     * A {@code ConsumerInterceptor} is used to intercept consume operations of consumer.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class ConsumerInterceptor : private Uncopyable {
    public:
        virtual ~ConsumerInterceptor() {

        }

        virtual std::string name() const = 0;
        /**
         * Invoked before the invocation of {@link MessageListener#onReceived(Message, Context)}.
         *
         * @param message the message is actually received.
         * @param attributes the extensible attributes delivered to the intercept thread.
         */
        virtual void preReceive(const MessagePtr &message, const InterceptorContextPtr &attributes = kv_nullptr) = 0;

        /**
         * Invoked after the invocation of {@link MessageListener#onReceived(Message, MessageListener.Context)}.
         *
         * @param message the message is actually received.
         * @param attributes the extensible attributes delivered to the intercept thread.
         */
        virtual void postReceive(const MessagePtr &message, const InterceptorContextPtr &attributes = kv_nullptr) = 0;
    };

    typedef NS::shared_ptr<ConsumerInterceptor> ConsumerInterceptorPtr;

END_NAMESPACE_3(io, openmessaging, interceptor)

#endif //OMS_CONSUMER_INTERCEPTOR_H
