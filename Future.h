#ifndef OMS_FUTURE_H
#define OMS_FUTURE_H

#include <exception>
#include <climits>

#include "smart_pointer.h"
#include "producer/SendResult.h"
#include "Uncopyable.h"
#include "FutureListener.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * A {@code Future} represents the result of an asynchronous computation.  Methods are provided to check if the
     * computation is complete, to wait for its completion, and to retrieve the result of the computation.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Future : private Uncopyable {
    public:
        virtual ~Future() {

        }

        /**
         * Returns {@code true} if this task was cancelled before it completed normally.
         *
         * @return {@code true} if this task was cancelled before it completed
         */
        virtual bool isCancelled() = 0;

        /**
         * Returns {@code true} if this task completed.
         * <p>
         * Completion may be due to normal termination, an exception, or cancellation -- in all of these cases, this method
         * will return {@code true}.
         *
         * @return {@code true} if this task completed
         */
        virtual bool isDone() = 0;

        /**
         * Waits if necessary for at most the given time for the computation to complete, and then retrieves its result, if
         * available.
         *
         * @param timeout the maximum time to wait
         * @return the computed result <p> if the computation was cancelled
         */
        virtual producer::SendResultPtr get(unsigned long timeout = LONG_MAX) = 0;

        /**
         * Adds the specified listener to this future. The specified listener is notified when this future is done. If this
         * future is already completed, the specified listener will be notified immediately.
         *
         * @param listener FutureListener
         */
        virtual Future &addListener(FutureListenerPtr listener) = 0;

        /**
         * Returns the cause of the failed future
         *
         * @return the cause of the failure. {@code null} if succeeded or this future is not completed yet.
         */
        virtual std::exception &getThrowable() = 0;

    };

    typedef NS::shared_ptr<Future> FuturePtr;

END_NAMESPACE_2(io, openmessaging)

#endif //OMS_FUTURE_H
