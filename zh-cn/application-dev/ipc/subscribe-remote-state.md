# 远端状态订阅开发实例

IPC/RPC提供对远端Stub对象状态的订阅机制，在远端Stub对象消亡时，可触发消亡通知告诉本地Proxy对象。这种状态通知订阅需要调用特定接口完成，当不再需要订阅时也需要调用特定接口取消。使用这种订阅机制的用户，需要实现消亡通知接口DeathRecipient并实现onRemoteDied方法清理资源。该方法会在远端Stub对象所在进程消亡或所在设备离开组网时被回调。值得注意的是，调用这些接口有一定的顺序。首先，需要Proxy订阅Stub消亡通知，若在订阅期间Stub状态正常，则在不再需要时取消订阅；若在订阅期间Stub所在进程退出或者所在设备退出组网，则会自动触发Proxy自定义的后续操作。

## 使用场景

这种订阅机制适用于本地Proxy对象需要感知远端Stub对象所在进程消亡，或所在设备离开组网的场景。当Proxy感知到Stub端消亡后，可适当清理本地资源。此外，RPC目前不提供匿名Stub对象的消亡通知，即只有向SAMgr注册过的服务才能被订阅消亡通知，IPC则支持匿名对象的消亡通知。

<!--Del-->
## Native侧接口

| 接口名                                                              |  描述                     |
| ------------------------------------------------------------------- | ------------------------- |
| bool AddDeathRecipient(const sptr\<DeathRecipient> &recipient);     | 订阅远端Stub对象状态。     |
| bool RemoveDeathRecipient(const sptr\<DeathRecipient> &recipient);  | 取消订阅远端Stub对象状态。 |
| void OnRemoteDied(const wptr\<IRemoteObject> &object);              | 当远端Stub对象死亡时回调。 |

### 参考代码

```C++
#include "iremote_broker.h"
#include "iremote_stub.h"

//定义消息码
enum {
    TRANS_ID_PING_ABILITY = 5,
    TRANS_ID_REVERSED_MONITOR
};

const std::string DESCRIPTOR = "test.ITestAbility";

class ITestService : public IRemoteBroker {
public:
    // DECLARE_INTERFACE_DESCRIPTOR是必需的，入参需使用std::u16string；
    DECLARE_INTERFACE_DESCRIPTOR(to_utf16(DESCRIPTOR));
    virtual int TestPingAbility(const std::u16string &dummy) = 0; // 定义业务函数
};

class TestServiceProxy : public IRemoteProxy<ITestAbility> {
public:
    explicit TestAbilityProxy(const sptr<IRemoteObject> &impl);
    virtual int TestPingAbility(const std::u16string &dummy) override;
    int TestAnonymousStub();
private:
    static inline BrokerDelegator<TestAbilityProxy> delegator_; // 方便后续使用iface_cast宏
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
sptr<IRemoteObject::DeathRecipient> deathRecipient (new TestDeathRecipient()); // 构造一个消亡通知对象
bool result = object->AddDeathRecipient(deathRecipient); // 注册消亡通知
result = object->RemoveDeathRecipient(deathRecipient); // 移除消亡通知
```
<!--DelEnd-->

## ArkTS侧接口

> **说明：**
>
> - 此文档中的示例代码描述的是系统应用跨进程通信。
>
> - 当前不支持三方应用实现ServiceExtensionAbility，三方应用的UIAbility组件可以通过Context连接系统提供的ServiceExtensionAbility。
>
> - 当前使用场景： 仅限客户端是三方应用，服务端是系统应用。

| 接口名                                                       | 返回值类型 | 功能描述                                                     |
| ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| [registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1) | void       | 注册用于接收远程对象消亡通知的回调，增加 proxy 对象上的消亡通知。 |
| [unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1) | void       | 注销用于接收远程对象消亡通知的回调。                         |
| [onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied) | void       | 在成功添加死亡通知订阅后，当远端对象死亡时，将自动调用本方法。 |

### 参考代码

```ts
// FA模型需要从@kit.AbilityKit导入featureAbility
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
// FA模型通过此方法连接服务
// FA.connectAbility(want, connect);

// 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
// 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
let connectionId = context.connectServiceExtensionAbility(want, connect);
```

上述onConnect回调函数中的proxy对象需要等ability异步连接成功后才会被赋值，然后才可调用proxy对象的[unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1)接口方法注销死亡回调

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

## Stub感知Proxy消亡（匿名Stub的使用）

正向的消亡通知是Proxy感知Stub的状态，若想达到反向的死消亡通知，即Stub感知Proxy的状态，可以巧妙的利用正向消亡通知。如两个进程A（原Stub所在进程）和B（原Proxy所在进程），进程B在获取到进程A的Proxy对象后，在B进程新建一个匿名Stub对象（匿名指未向SAMgr注册），可称之为回调Stub，再通过SendRequest接口将回调Stub传给进程A的原Stub。这样一来，进程A便获取到了进程B的回调Proxy。当进程B消亡或B所在设备离开组网时，回调Stub会消亡，回调Proxy会感知，进而通知给原Stub，便实现了反向消亡通知。

注意：

> 反向死亡通知仅限设备内跨进程通信使用，不可用于跨设备。

> 当匿名Stub对象没有被任何一个Proxy指向的时候，内核会自动回收。

### 参考代码

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

