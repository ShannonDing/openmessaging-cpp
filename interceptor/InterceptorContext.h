#ifndef OMS_INTERCEPTOR_CONTEXT_H
#define OMS_INTERCEPTOR_CONTEXT_H

#include "Namespace.h"
#include "OMS.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, interceptor)

        class InterceptorContext : private Uncopyable {
        public:
            virtual ~InterceptorContext() {
            }

            virtual KeyValuePtr attributes() = 0;

        };

    typedef NS::shared_ptr<InterceptorContext> InterceptorContextPtr;

END_NAMESPACE_3(io, openmessaging, interceptor)
#endif //OMS_INTERCEPTOR_CONTEXT_H
