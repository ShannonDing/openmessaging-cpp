#ifndef OMS_CONTEXT_H
#define OMS_CONTEXT_H

#include "Namespace.h"
#include "OMS.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, consumer)

        class Context : private Uncopyable {
        public:
            virtual ~Context() {
            }

            /**
             * Acknowledges the specified and consumed message, which is related to this {@code Context}.
             * <p>
             * Messages that have been received but not acknowledged may be redelivered.
             */
            virtual void ack() = 0;
        };

    typedef NS::shared_ptr<Context> ContextPtr;

END_NAMESPACE_3(io, openmessaging, consumer)
#endif //OMS_CONTEXT_H
