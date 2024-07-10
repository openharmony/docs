# Subscribing to State Changes of a Remote Object

You can subscribe to the state changes of a remote stub object in IPC/RPC. When the remote stub object dies, a death notification will be sent to your local proxy object. Such subscription and unsubscription are controlled by APIs. To be specific, you need to implement the **DeathRecipient** interface and the **onRemoteDied** API to clear resources. This callback is invoked when the process hosting the remote stub object dies, or the device hosting the remote stub object leaves the network. It is worth noting that these APIs should be called in the following order: The proxy object must first subscribe to death notifications of the stub object. If the stub object is in the normal state, the proxy object can cancel the subscription as required. If the process of the stub object exits or the device hosting the stub object goes offline, subsequent operations customized by the proxy object will be automatically triggered.

## When to Use

This subscription mechanism is applicable when the local proxy object needs to detect death of the process hosting the remote stub object or network detach of the device hosting the remote stub object. When the proxy detects death of the remote stub object, the proxy can clear local resources. Currently, IPC supports death notification for anonymous objects, but RPC does not. That is, you can only subscribe to death notifications of services that have been registered with SAMgr.

<!--Del-->
## Development Using Native APIs

| Name                                                             |  Description                    |
| ------------------------------------------------------------------- | ------------------------- |
| bool AddDeathRecipient(const sptr\<DeathRecipient> &recipient);     | Adds a recipient for death notifications of a remote stub object.    |
| bool RemoveDeathRecipient(const sptr\<DeathRecipient> &recipient);  | Removes the recipient for death notifications of a remote stub object.|
| void OnRemoteDied(const wptr\<IRemoteObject> &object);              | Called when the remote stub object dies.|

### Example

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
    static inline BrokerDelegator<TestAbilityProxy> delegator_; // For use of the iface_cast macro at a later time
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

```C++
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
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient()); // Construct a death notification recipient.
bool result = object->AddDeathRecipient(deathRecipient); // Add a recipient for death notifications.
result = object->RemoveDeathRecipient(deathRecipient); // Remove the recipient for death notifications.
```
<!--DelEnd-->

## Development Using ArkTS APIs

> **NOTE**
>
> - The sample code in this topic implements communication between system applications across processes.
>
> - Currently, third-party applications cannot implement ServiceExtensionAbility. The UIAbility components of a third-party application can connect to the ServiceExtensionAbility provided by the system via **Context**.
>
> - The development applies only to the scenario, in which the client is a third-party application and the server is a system application.

| Name                                                      | Return Value Type| Description                                                    |
| ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| [registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1) | void       | Adds a recipient for death notifications of the remote object, including death notifications of the remote proxy.|
| [unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1) | void       | Removes the recipient for death notifications of the remote object.                        |
| [onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied) | void       | Called to perform subsequent operations when a death notification of the remote object is received.|

### Example

```ts
// If the FA model is used, import featureAbility from @kit.AbilityKit.
// import { featureAbility } from '@kit.AbilityKit';
import { Want, common } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let proxy: rpc.IRemoteObject | undefined;
let connect: common.ConnectOptions = {
  onConnect: (elementName, remoteProxy) => {
    hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called.');
    proxy = remoteProxy;
  },
  onDisconnect: (elementName) => {
    hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
  },
  onFailed: () => {
    hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
  }
};
let want: Want = {
  bundleName: "com.ohos.server",
  abilityName: "com.ohos.server.EntryAbility",
};
// Use this method to connect to the ability in the FA model.
// FA.connectAbility(want, connect);

// Save the connection ID, which will be used for the subsequent service disconnection.
let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
// Save the connection ID, which will be used for the subsequent service disconnection.
let connectionId = context.connectServiceExtensionAbility(want, connect);
```

The **proxy** object in the **onConnect** callback can be assigned a value only after the ability is connected asynchronously. After that, [unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1) of the **proxy** object can be called to unregister the callback for receiving the death notification of the remote object.

```ts
import { rpc } from '@kit.IPCKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

class MyDeathRecipient implements rpc.DeathRecipient{
  onRemoteDied() {
    hilog.info(0x0000, 'testTag', 'server died');
  }
}
let deathRecipient = new MyDeathRecipient();
if (proxy != undefined) {
  proxy.registerDeathRecipient(deathRecipient, 0);
  proxy.unregisterDeathRecipient(deathRecipient, 0);
}
```

## Reverse Death Notification (Anonymous Stub)

Forward dead notification is a mechanism that allows the proxy to detect death notifications of the stub. To achieve reverse dead notification, we can leverage the forward dead notification mechanism to allow the stub to detect death notifications of the proxy. 

Suppose there are two processes: A (the process hosting the original stub) and B (the process hosting the original proxy). After obtaining the proxy object of process A, process B creates an anonymous stub object (that is, a stub object not registered with SAMgr), which can be called a callback stub. Then, process B calls **SendRequest** to send the callback stub to the original stub of process A. As a result, process A obtains the callback proxy of process B. When process B dies or the device hosting process B detaches from the network, the callback stub dies. The callback proxy detects the death of the callback stub and sends a death notification to the original stub. In this way, reverse death notification is implemented.

**NOTE**

> - Reverse death notification can only be used for cross-process communication within a device.
> - When an anonymous stub object is not pointed to by any proxy, the kernel automatically reclaims the object.

### Example

```c++
// Proxy
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

// Stub

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
