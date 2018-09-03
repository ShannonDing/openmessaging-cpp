#ifndef OMS_CHECK_CONTEXT_H
#define OMS_CHECK_CONTEXT_H

#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

    class CheckContext : private Uncopyable {
    public:
        virtual ~CheckContext() {

        }
        /**
         * Commits a transaction.
         */
        virtual void commit() = 0;
        /**
         * Rolls back a transaction.
         */
        virtual void rollback() = 0;
        /**
         * Unknown transaction status, may be this transaction still on going.
         */
        virtual void unknown() = 0;

    };

    typedef NS::shared_ptr<CheckContext> CheckContextPtr;

END_NAMESPACE_3(io, openmessaging, producer)

#endif //OMS_CHECK_CONTEXT_H
