#ifndef OMS_RESOURCE_MANAGER_H
#define OMS_RESOURCE_MANAGER_H

#include <string>

#include "../smart_pointer.h"
#include "../ServiceLifecycle.h"
#include "../KeyValue.h"
#include "../routing/Routing.h"
#include "../Namespace.h"

BEGIN_NAMESPACE_3(io, openmessaging, manager)

    /**
     * The {@code ResourceManager} is to provide a unified interface of resource management,
     * allowing developers to manage the namespace, queue and routing resources.
     * <p>
     * Create, set, get and delete are the four basic operations of {@code ResourceManager}.
     * <p>
     * {@code ResourceManager} also supports fetching and updating resource attributes dynamically.
     * <p>
     * {@link MessagingAccessPoint#resourceManager()} ()} is the unique method to obtain a {@code ResourceManager}
     * instance. Changes made through this instance will immediately apply to the message-oriented middleware (MOM) behind
     * {@code MessagingAccessPoint}.
     * <p>
     * All operations conducted via this instance are confined to the configured namespace,
     * with default namespace derived from the OMS driver url of {@code MessagingAccessPoint}.Change namespace
     * by {@link ResourceManager#switchNamespace(String)} whenever necessary.
     *
     * @version OMS 1.0.0
     * @since OMS 1.0.0
     */
    class ResourceManager : public virtual Uncopyable {
    public:
        virtual ~ResourceManager() {

        }

        /**
         * Creates a {@code Namespace} resource with some preset attributes.
         *
         * @param nsName the name of the new namespace
         * @param attributes the preset attributes
         */
        virtual void createNamespace(const std::string &ns) = 0;

        /**
         * Deletes an existing namespace resource.
         *
         * @param ns the namespace to delete
         * @throws OMSResourceNotExistException if the specified namespace does not exist
         */
        virtual void deleteNamespace(const std::string &ns) = 0;

        /**
         * Gets the namespace list in the current {@code MessagingAccessPoint}.
         *
         * @return the list of all namespaces
         */
        virtual std::vector<std::string> listNamespaces() = 0;

        /**
         * Switches the default namespace to the new one, and all the operations will reflect to
         * the new namespace after the method returns successfully.
         *
         * @param ns the target namespace to switch to
         * @throws OMSResourceNotExistException if the new namespace does not exist
         */
        virtual void switchNamespace(const std::string &ns) = 0;

        /**
         * Creates a {@code Queue} resource in the configured namespace with some preset attributes.
         *
         * @param queueName the name of the new queue
         * @param attributes the preset attributes
         * @throws OMSResourceNotExistException if the specified queue name is duplicated
         */
        virtual void createQueue(const std::string &ns, const std::string &queue, KeyValuePtr attributes) = 0;

        /**
         * Deletes an existing queue resource.
         *
         * @param queueName the queue needs to be deleted
         * @throws OMSResourceNotExistException if the specified queue or namespace does not exist
         */
        virtual void deleteQueue(const std::string &queue) = 0;

        /**
         * Gets the queue list in the configured namespace.
         *
         * @return the list of all queues
         */
        virtual std::vector<std::string> listQueues() = 0;


        virtual void routing(const std::string &sourceQueue, const std::string &targetQueue) = 0;


        virtual void filter(const std::string &queue, const std::string &filter) = 0;


    };

    typedef NS::shared_ptr<ResourceManager> ResourceManagerPtr;

END_NAMESPACE_3(io, openmessaging, manager)

#endif // OMS_RESOURCE_MANAGER_H
