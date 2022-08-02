# Subscribing to State Changes of a Remote Object

IPC/RPC allows you to subscribe to the state changes of a remote stub object. When the remote stub object dies, a death notification will be sent to your local proxy object. Such subscription and unsubscription are controlled by APIs. To be specific, you need to implement the **DeathRecipient** interface and the **onRemoteDied** method to clear resources. This callback is invoked when the process accommodating the remote stub object dies, or the device accommodating the remote stub object leaves the network. It is worth noting that these APIs should be called in the following order: The proxy object must first subscribe to death notifications of the stub object. If the stub object is in the normal state, the proxy object can cancel the subscription as required. If the process of the stub object exits or the device hosting the stub object goes offline, subsequent operations customized by the proxy object will be automatically triggered.




## **Development Using Native APIs**

| API| Description|
| -------- | -------- |
| AddDeathRecipient(const sptr\<DeathRecipient> &recipient); | Adds a recipient for death notifications of a remote stub object.|
| RemoveDeathRecipient(const sptr\<DeathRecipient> &recipient); | Removes the recipient for death notifications of a remote stub object.|
| OnRemoteDied(const wptr\<IRemoteObject> &object); | Called when the remote stub object dies.|


## Sample Code


```
class TestDeathRecipient : public IRemoteObject::DeathRecipient {
public:
    virtual void OnRemoteDied(const wptr<IRemoteObject>& remoteObject);
}
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient());// Construct a death notification recipient.
bool result = proxy->AddDeathRecipient(deathRecipient); // Add a recipient for death notifications.
result = proxy->RemoveDeathRecipient(deathRecipient); // Remove the recipient for death notifications.
```
