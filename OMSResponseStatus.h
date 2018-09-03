//
// Created by Shannon on 2018/9/2.
//

#ifndef OMS_RESPONSE_STATUS_H
#define OMS_RESPONSE_STATUS_H
BEGIN_NAMESPACE_u2(io, openmessaging)
enum Error{
    UnsupportedVersion = 1101,
    Success = 1200,
    BadRequest = 1400,
    Unauthorized = 1401,
    MessageBodyRequired = 1402,
    Forbidden = 1403,
    DestinationNotFound = 1404,
    NamespaceNotFound = 1405,
    DestinationAlreadyExists = 1406,
    NamespaceAlreadyExists = 1407,
    ConsumerIdAlreadyExists = 1408,
    ProducerIdAlreadyExists = 1409,
    RequestTimeout = 1410,
    MessageAttributesTooLarge = 1411,
    MessageHeaderTooLarge = 1412,
    MessageBodyTooLarge = 1413,
    NoNewMessageFound = 1414,
    MaxTopicsReached = 1415,
    MaxQueuesReached = 1416,
    MaxNamespacesReached = 1417,
    BadParameter = 1416,
    ServerStatus = 1500,
    StorageServiceStatus = 1501,
    StorageServiceBusy = 1502,
    ServiceNotAvailable = 1503,
    FlushDiskTimeout = 1504,
    CreateMessagingAccessPointFailed = 10000,
    IllegalDriver = 10001,
    IllegalVersion = 10002,
    VersionNotCompatibleSpecification = 10003,
};
END_NAMESPACE_2(io, openmessaging)
#endif //OMS_RESPONSE_STATUS_H
