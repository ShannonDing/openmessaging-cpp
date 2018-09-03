#ifndef OMS_TRANSACTIONAL_SEND_RESULT_H
#define OMS_TRANSACTIONAL_SEND_RESULT_H

#include <string>

#include "smart_pointer.h"
#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_3(io, openmessaging, producer)

    /**
     * The result of sending a OMS message to server
     * with the message id and some properties.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class TransactionalSendResult : public SendResult {
    public:
        virtual ~TransactionalSendResult() {

        }

        virtual std::string transactionId() = 0;

        virtual void commit() = 0;

        virtual void rollback() = 0;
    };

    typedef NS::shared_ptr<SendResult> TransactionalSendResultPtr;

END_NAMESPACE_3(io, openmessaging, producer)

#endif // OMS_TRANSACTIONAL_SEND_RESULT_H
