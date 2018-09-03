#ifndef OMS_HEADERS_H
#define OMS_HEADERS_H

#include <string>

#include "smart_pointer.h"
#include "Namespace.h"
#include "Uncopyable.h"

BEGIN_NAMESPACE_2(io, openmessaging)

    /**
     * The {@code Message} interface is the root interface of all OMS messages, and the most commonly used OMS message is
     * {@link BytesMessage}.
     * <p>
     * Most message-oriented middleware (MOM) products treat messages as lightweight entities that consist of a header and a
     * body, like <a href="http://rocketmq.apache.org/">Apache RocketMQ</a>. The header part contains fields used for message
     * routing and identification; the body part contains the application data to sent.
     * <p>
     * The {@code Message} is a lightweight entity that only contains properties related to information of a specific message
     * object, and the {@code Message} is composed of the following parts:
     *
     * <UL>
     * <LI>Header - All messages support the same set of header fields. Header fields contain values used by both
     * clients and providers to identify and route messages.
     * <LI>Properties - Each message contains a built-in facility for supporting application-defined property values.
     * Properties provide an efficient mechanism for supporting application-defined message filtering.
     * </UL>
     *
     * The body part is deferred to the sub-classes of {@code Message}.
     *
     * @version OMS 1.0
     * @since OMS 1.0
     */
    class Headers : private Uncopyable {
    public:
        virtual ~Headers() {

        }
        virtual Headers &setDestination(const std::string &destination) = 0;
        virtual Headers &setMessageId(const std::string &messageId) = 0;
        virtual Headers &setBornTimestamp(long bornTimestamp) = 0;
        virtual Headers &setBornHost(const std::string &bornHost) = 0;
        virtual Headers &setStoreTimestamp(long storeTimestamp) = 0;
        virtual Headers &setStoreHost(const std::string &storeHost) = 0;
        virtual Headers &setDelayTime(long delayTime) = 0;
        virtual Headers &setExpireTime(long expireTime) = 0;
        virtual Headers &setPriority(short priority) = 0;
        virtual Headers &setDurability(short durability) = 0;
        virtual Headers &setMessageKey(const std::string &messageKey) = 0;
        virtual Headers &setTraceId(const std::string &traceId) = 0;
        virtual Headers &setDeliveryCount(short deliveryCount) = 0;
        virtual Headers &setTransactionId(const std::string &transactionId) = 0;
        virtual Headers &setCorrelationId(const std::string &scorrelationId) = 0;
        virtual Headers &setCompression(short compression) = 0;

        virtual std::string getDestination() = 0;
        virtual std::string getMessageId() = 0;
        virtual long getBornTimestamp() = 0;
        virtual std::string getBornHost() = 0;
        virtual long getStoreTimestamp() = 0;
        virtual std::string getStoreHost() = 0;
        virtual long getDelayTime() = 0;
        virtual long getExpireTime() = 0;
        virtual short getPriority() = 0;
        virtual short getDurability() = 0;
        virtual std::string getMessageKey() = 0;
        virtual std::string getTraceId() = 0;
        virtual short getDeliveryCount() = 0;
        virtual std::string getTransactionId() = 0;
        virtual std::string getCorrelationId() = 0;
        virtual short getCompression() = 0;
    };

    typedef NS::shared_ptr<Headers> HeadersPtr;

END_NAMESPACE_2(io, openmessaging)

#endif // OMS_HEADERS_H
