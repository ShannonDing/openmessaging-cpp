#ifndef OMS_CONSUMER_H
#define OMS_CONSUMER_H

#include <string>

#include "smart_pointer.h"
#include "ServiceLifecycle.h"
#include "MessageListener.h"
#include "Namespace.h"
#include "OMS.h"
#include "interceptor/ConsumerInterceptor.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)
    /**
     * A {@code Consumer} object to receive messages from multiple queues, these messages are pushed from
     * MOM server to {@code Consumer} client.
     *
     * @version OMS 1.0
     * @see MessagingAccessPoint#createConsumer()
     * @since OMS 1.0
     */
    class Consumer : public virtual ServiceLifecycle {
    public:
        virtual ~Consumer() {

        }


        /**
         * Resumes the {@code Consumer} after a suspend.
         * <p>
         * This method resumes the {@code Consumer} instance after it was suspended.
         * The instance will not receive new messages between the suspend and resume calls.
         *
         * @throws OMSRuntimeException if the instance has not been suspended.
         * @see Consumer#suspend()
         */
        virtual void resume() = 0;

        /**
         * Suspends the {@code Consumer} for later resumption.
         * <p>
         * This method suspends the consumer until it is resumed.
         * The consumer will not receive new messages between the suspend and resume calls.
         * <p>
         * This method behaves exactly as if it simply performs the call {@code suspend(0)}.
         *
         * @throws OMSRuntimeException if the instance is not currently running.
         * @see Consumer#resume()
         */
        virtual void suspend(long timeout = 0) = 0;

        /**
         * This method is used to find out whether the {@code Consumer} is suspended.
         *
         * @return true if this {@code Consumer} is suspended, false otherwise
         */
        virtual bool isSuspended() = 0;

        /**
         * Attaches the {@code Consumer} to a specified queue, with a {@code MessageListener}.
         * <p>
         * {@link MessageListener#onReceived(Message, MessageListener.Context)} will be called when new
         * delivered message is coming.
         *
         * @param queueName a specified queue
         * @param listener a specified listener to receive new message
         * @return this {@code Consumer} instance
         */
        virtual Consumer &bindQueue(const std::string &queueName,
                                    const MessageListenerPtr &listener) = 0;

        /**
         * Detaches the {@code Consumer} from a specified queue.
         * <p>
         * After the success call, this consumer won't receive new message
         * from the specified queue any more.
         *
         * @param queueName a specified queue
         * @return this {@code Consumer} instance
         */
        virtual Consumer &unbindQueue(const std::string &queueName) = 0;

        /**
         * Adds a {@code ConsumerInterceptor} instance to this consumer.
         *
         * @param interceptor an interceptor instance
         */
        virtual void addInterceptor(const interceptor::ConsumerInterceptorPtr &interceptor) = 0;

        /**
         * Removes an interceptor from this consumer.
         *
         * @param interceptor an interceptor to be removed
         */
        virtual void removeInterceptor(const interceptor::ConsumerInterceptorPtr &interceptor) = 0;
        virtual MessagePtr &receive(long timeout) = 0;
        virtual void ack(String receiptHandle) = 0;
    };

    typedef NS::shared_ptr<Consumer> ConsumerPtr;

END_NAMESPACE_3(io, openmessaging, consumer)

#endif //OMS_CONSUMER_H
