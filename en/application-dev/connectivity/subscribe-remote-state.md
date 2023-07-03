# Subscribing to State Changes of a Remote Object

IPC/RPC allows you to subscribe to the state changes of a remote stub object. When the remote stub object dies, a death notification will be sent to your local proxy object. Such subscription and unsubscription are controlled by APIs. To be specific, you need to implement the **DeathRecipient** interface and the **onRemoteDied** API to clear resources. This callback is invoked when the process accommodating the remote stub object dies, or the device accommodating the remote stub object leaves the network. It is worth noting that these APIs should be called in the following order: The proxy object must first subscribe to death notifications of the stub object. If the stub object is in the normal state, the proxy object can cancel the subscription as required. If the process of the stub object exits or the device hosting the stub object goes offline, subsequent operations customized by the proxy object will be automatically triggered.

## When to Use

This subscription mechanism is applicable when the local proxy object needs to detect death of the process hosting the remote stub object or network detach of the device hosting the remote stub object. When the proxy detects death of the remote stub object, the proxy can clear local resources. Currently, IPC supports death notification for anonymous objects, but RPC does not. That is, you can only subscribe to death notifications of services that have been registered with SAMgr.


## **Development Using Native APIs**

| API| Return Value Type| Feature Description|
| -------- | -------- | -------- |
| AddDeathRecipient(const sptr\<DeathRecipient> &recipient); | bool | Adds a recipient for death notifications of a remote stub object.|
| RemoveDeathRecipient(const sptr\<DeathRecipient> &recipient); | bool | Removes the recipient for death notifications of a remote stub object.|
| OnRemoteDied(const wptr\<IRemoteObject> &object); | void | Called when the remote stub object dies.|

### Sample Code

```C++
#include "iremote_broker.h"
#include "iremote_stub.h"

// Define message codes.
enum {
    TRANS_ID_PING_ABILITY = 5,
    TRANS_ID_REVERSED_MONITOR
};

const std::string DESCRIPTOR = "test.ITestAbility";

class ITestService : public IRemoteBroker {
public:
    // DECLARE_INTERFACE_DESCRIPTOR is mandatory, and the input parameter is std::u16string.
    DECLARE_INTERFACE_DESCRIPTOR(to_utf16(DESCRIPTOR));
    virtual int TestPingAbility(const std::u16string &dummy) = 0; // Define functions.
};

class TestServiceProxy : public IRemoteProxy<ITestAbility> {
public:
    explicit TestAbilityProxy(const sptr<IRemoteObject> &impl);
    virtual int TestPingAbility(const std::u16string &dummy) override;
    int TestAnonymousStub();
private:
    static inline BrokerDelegator<TestAbilityProxy> delegator_; // Use the iface_cast macro.
};

TestServiceProxy::TestServiceProxy(const sptr<IRemoteObject> &impl)
    : IRemoteProxy<ITestAbility>(impl)
{
}

int TestServiceProxy::TestPingAbility(const std::u16string &dummy){
    MessageOption option;
    MessageParcel dataParcel, replyParcel;
    dataParcel.WriteString16(dummy);
    int error = PeerHolder::Remote()->SendRequest(TRANS_ID_PING_ABILITY, dataParcel, replyParcel, option);
    int result = (error == ERR_NONE) ? replyParcel.ReadInt32() : -1;
    return result;
}
```

```c++
#include "iremote_object.h"

class TestDeathRecipient : public IRemoteObject::DeathRecipient {
public:
    virtual void OnRemoteDied(const wptr<IRemoteObject>& remoteObject);
}

void TestDeathRecipient::OnRemoteDied(const wptr<IRemoteObject>& remoteObject)
{
}
```

```c++
sptr<IPCObjectProxy> object = new IPCObjectProxy(1, to_utf16(DESCRIPTOR));
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient());// Construct a death notification recipient.
bool result = object->AddDeathRecipient(deathRecipient); // Add a recipient for death notifications.
result = object->RemoveDeathRecipient(deathRecipient); // Remove the recipient for death notifications.
```

## **Development Using JS APIs**

| API                  | Return Value Type| Feature Description                                                         |
| ------------------------ | ---------- | ----------------------------------------------------------------- |
| registerDeathRecipient   | void       | Adds a recipient for death notifications of the remote object, including death notifications of the remote proxy.|
| unregisterDeathRecipient | void       | Removes the recipient for death notifications of the remote object.                             |
| onRemoteDied             | void       | Called to perform subsequent operations when a death notification of the remote object is received.   |

### Obtaining the Context

If you use the stage model, you need to obtain the context before connecting to an ability.

```ts
import Ability from "@ohos.app.ability.UIAbility";

export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.log("[Demo] MainAbility onCreate");
        globalThis.context = this.context;
    }
    onDestroy() {
        console.log("[Demo] MainAbility onDestroy");
    }
    onWindowStageCreate(windowStage) {
        // Main window is created, set main page for this ability
        console.log("[Demo] MainAbility onWindowStageCreate");
    }
    onWindowStageDestroy() {
        // Main window is destroyed, release UI related resources
        console.log("[Demo] MainAbility onWindowStageDestroy");
    }
    onForeground() {
        // Ability has brought to foreground
        console.log("[Demo] MainAbility onForeground");
    }
    onBackground() {
        // Ability has back to background
        console.log("[Demo] MainAbility onBackground");
    }
}
```

### Sample Code

```ts
// Import @ohos.ability.featureAbility only for the application developed based on the FA model.
// import FA from "@ohos.ability.featureAbility";

let proxy;
let connect = {
    onConnect: function(elementName, remoteProxy) {
        console.log("RpcClient: js onConnect called.");
        proxy = remoteProxy;
    },
    onDisconnect: function(elementName) {
        console.log("RpcClient: onDisconnect");
    },
    onFailed: function() {
        console.log("RpcClient: onFailed");
    }
};
let want = {
    "bundleName": "com.ohos.server",
    "abilityName": "com.ohos.server.EntryAbility",
};
// Use this method to connect to the ability in the FA model.
// FA.connectAbility(want, connect);

globalThis.context.connectServiceExtensionAbility(want, connect);

class MyDeathRecipient {
    onRemoteDied() {
        console.log("server died");
    }
}
let deathRecipient = new MyDeathRecipient();
proxy.registerDeathRecippient(deathRecipient, 0);
proxy.unregisterDeathRecipient(deathRecipient, 0);
```

## Reverse Death Notification (Anonymous Stub)

Forward dead notification is a mechanism that allows the proxy to detect death notifications of the stub. To achieve reverse dead notification, we can leverage the forward dead notification mechanism to allow the stub to detect death notifications of the proxy. Suppose there are two processes, A (the process hosting the original stub) and B (the process hosting the original proxy). After obtaining the proxy object of process A, process B creates an anonymous stub object (that is, a stub object not registered with SAMgr), which can be called a callback stub. Then, process B calls **SendRequest** to send the callback stub to the original stub of process A. As a result, process A obtains the callback proxy of process B. When process B dies or the device hosting process B detaches from the network, the callback stub dies. The callback proxy detects the death of the callback stub and sends a death notification to the original stub. In this way, reverse death notification is implemented.

Note:

> Reverse death notification can only be used for cross-process communication within a device.

> When an anonymous stub object is not pointed by any proxy, the kernel automatically reclaims the object.

### Sample Code

```c++
//Proxy
int TestAbilityProxy::TestAnonymousStub()
{
    MessageOption option;
    MessageParcel dataParcel, replyParcel;
    dataParcel.UpdateDataVersion(Remote());
    dataParcel.WriteRemoteObject(new TestAbilityStub());
    int error = Remote()->SendRequest(TRANS_ID_REVERSED_MONITOR,dataParcel, replyParcel, option);
    int result = (error == ERR_NONE) ? replyParcel.ReadInt32() : -1;
    return result;
}

//Stub

int TestAbilityStub::OnRemoteRequest(uint32_t code, MessageParcel &data, MessageParcel &reply, MessageOption &option)
{
    switch (code) {
        case TRANS_ID_REVERSED_MONITOR: {
            sptr<IRemoteObject> obj = data.ReadRemoteObject();
            if (obj == nullptr) {
                reply.WriteInt32(ERR_NULL_OBJECT);
                return ERR_NULL_OBJECT;
            }
            bool result = obj->AddDeathRecipient(new TestDeathRecipient());
            result ? reply.WriteInt32(ERR_NONE) : reply.WriteInt32(-1);
            break;
        }
        default:
            break;
    }
    return ERR_NONE;
}
```
