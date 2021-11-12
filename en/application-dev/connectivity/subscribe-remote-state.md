# Subscribing to State Changes of a Remote Object<a name="EN-US_TOPIC_0000001104030756"></a>

IPC/RPC allows you to subscribe to the state changes of a remote stub object. When the remote stub object dies, a death notification will be sent to your local proxy object. You can also unsubscribe from the state changes if they are no longer needed. Such subscription and unsubscription are controlled by APIs. To be specific, you need to implement the  **IRemoteObject.DeathRecipient**  interface and the  **onRemoteDied**  method to clear resources. This callback is invoked when the process accommodating the remote stub object dies, or the device accommodating the remote stub object leaves the network. It is worth noting that these APIs should be called in the following order: The proxy object must first subscribe to death notifications of the stub object. If the stub object does not die, the proxy object can cancel the subscription when it is no longer required. If the stub object dies, subsequent operations customized by the proxy object will be automatically triggered, and the subscription does not need to be manually canceled.

Currently, IPC supports death notifications for anonymous objects, but RPC does not. That is, you can only subscribe to death notifications of services that have been registered with SAMgr.

**Development Using Native APIs**

The following APIs are used to add a recipient for death notifications of a remote stub object, remove such a recipient, and perform subsequent operations upon receiving a death notification of the remote stub object:

```
bool AddDeathRecipient(const sptr<DeathRecipient> &recipient);
bool RemoveDeathRecipient(const sptr<DeathRecipient> &recipient);
void OnRemoteDied(const wptr<IRemoteObject> &object);
```

The sample code is as follows:

```
class TestDeathRecipient : public IRemoteObject::DeathRecipient {
public:
    virtual void OnRemoteDied(const wptr<IRemoteObject>& remoteObject);
}
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient()); // Construct a death notification recipient.
bool result = proxy->AddDeathRecipient(deathRecipient); // Add the recipient to the proxy.
result = proxy->RemoveDeathRecipient(deathRecipient); // Remove the recipient.
```

