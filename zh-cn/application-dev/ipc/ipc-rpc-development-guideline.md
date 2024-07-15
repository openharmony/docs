# IPC与RPC通信开发指导

## 场景介绍

IPC/RPC的主要工作是让运行在不同进程的Proxy和Stub互相通信，包括Proxy和Stub运行在不同设备的情况。

<!--Del-->
## 接口说明

**表1** Native侧IPC接口

| 接口名                               | 描述                                                             |
| ------------------------------------ | ---------------------------------------------------------------- |
| sptr&lt;IRemoteObject&gt; AsObject() | 返回通信对象。Stub端返回RemoteObject对象本身，Proxy端返回代理对象。 |
| virtual int OnRemoteRequest(uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option) | 请求处理方法，派生类需要重写该方法用来处理Proxy的请求并返回结果。 |
| IRemoteProxy | Remote()->SendRequest(code, data, reply, option)  | 消息发送方法，业务的Proxy类需要从IRemoteProxy类派生，该方法用来向对端发送消息。 |
<!--DelEnd-->

## 开发步骤

<!--Del-->
### **Native侧开发步骤**

1. 添加依赖

   SDK依赖：

   ```
   #ipc场景
   external_deps = [
     "ipc:ipc_single",
   ]

   #rpc场景
   external_deps = [
     "ipc:ipc_core",
   ]
   ```

   此外， IPC/RPC依赖的refbase实现在公共基础库下，请增加对utils的依赖：

   ```
   external_deps = [
     "c_utils:utils",
   ]
   ```

2. 定义IPC接口ITestAbility

   SA接口继承IPC基类接口IRemoteBroker，接口里定义描述符、业务函数和消息码，其中业务函数在Proxy端和Stub端都需要实现。

   ```c++
   #include "iremote_broker.h"

   //定义消息码
   const int TRANS_ID_PING_ABILITY = 5;

   const std::string DESCRIPTOR = "test.ITestAbility";

   class ITestAbility : public IRemoteBroker {
   public:
       // DECLARE_INTERFACE_DESCRIPTOR是必需的，入参需使用std::u16string;
       DECLARE_INTERFACE_DESCRIPTOR(to_utf16(DESCRIPTOR));
       virtual int TestPingAbility(const std::u16string &dummy) = 0; // 定义业务函数
   };
   ```

3. 定义和实现服务端TestAbilityStub

   该类是和IPC框架相关的实现，需要继承 IRemoteStub&lt;ITestAbility&gt;。Stub端作为接收请求的一端，需重写OnRemoteRequest方法用于接收客户端调用。

   ```c++
   #include "iability_test.h"
   #include "iremote_stub.h"

   class TestAbilityStub : public IRemoteStub<ITestAbility> {
   public:
       virtual int OnRemoteRequest(uint32_t code, MessageParcel &data, MessageParcel &reply, MessageOption &option) override;
       int TestPingAbility(const std::u16string &dummy) override;
    };

   int TestAbilityStub::OnRemoteRequest(uint32_t code,
       MessageParcel &data, MessageParcel &reply, MessageOption &option)
   {
       switch (code) {
           case TRANS_ID_PING_ABILITY: {
               std::u16string dummy = data.ReadString16();
               int result = TestPingAbility(dummy);
               reply.WriteInt32(result);
               return 0;
           }
           default:
               return IPCObjectStub::OnRemoteRequest(code, data, reply, option);
       }
   }
   ```

4. 定义服务端业务函数具体实现类TestAbility

   ```c++
   #include "iability_server_test.h"

   class TestAbility : public TestAbilityStub {
   public:
       int TestPingAbility(const std::u16string &dummy);
   }

   int TestAbility::TestPingAbility(const std::u16string &dummy) {
       return 0;
   }
   ```

5. 定义和实现客户端 TestAbilityProxy

   该类是Proxy端实现，继承IRemoteProxy&lt;ITestAbility&gt;，调用SendRequest接口向Stub端发送请求，对外暴露服务端提供的能力。

   ```c++
   #include "iability_test.h"
   #include "iremote_proxy.h"
   #include "iremote_object.h"

   class TestAbilityProxy : public IRemoteProxy<ITestAbility> {
   public:
       explicit TestAbilityProxy(const sptr<IRemoteObject> &impl);
       int TestPingAbility(const std::u16string &dummy) override;
   private:
       static inline BrokerDelegator<TestAbilityProxy> delegator_; // 方便后续使用iface_cast宏
   }

   TestAbilityProxy::TestAbilityProxy(const sptr<IRemoteObject> &impl)
       : IRemoteProxy<ITestAbility>(impl)
   {
   }

   int TestAbilityProxy::TestPingAbility(const std::u16string &dummy){
       MessageOption option;
       MessageParcel dataParcel, replyParcel;
       dataParcel.WriteString16(dummy);
       int error = Remote()->SendRequest(TRANS_ID_PING_ABILITY, dataParcel, replyParcel, option);
       int result = (error == ERR_NONE) ? replyParcel.ReadInt32() : -1;
       return result;
   }
   ```

6. SA注册与启动

   SA需要将自己的TestAbilityStub实例通过AddSystemAbility接口注册到SystemAbilityManager，设备内与分布式的注册参数不同。

   ```c++
   // 注册到本设备内
   auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   samgr->AddSystemAbility(saId, new TestAbility());

   // 在组网场景下，会被同步到其他设备上
   auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   ISystemAbilityManager::SAExtraProp saExtra;
   saExtra.isDistributed = true; // 设置为分布式SA
   int result = samgr->AddSystemAbility(saId, new TestAbility(), saExtra);
   ```

7. SA获取与调用

   通过SystemAbilityManager的GetSystemAbility方法可获取到对应SA的代理IRemoteObject，然后构造TestAbilityProxy即可。

   ```c++
   // 获取本设备内注册的SA的proxy
   sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId);
   sptr<ITestAbility> testAbility = iface_cast<ITestAbility>(remoteObject); // 使用iface_cast宏转换成具体类型

   // 获取其他设备注册的SA的proxy
   sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();

   // networkId是组网场景下对应设备的标识符，可以通过GetLocalNodeDeviceInfo获取
   sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId, networkId);
   sptr<TestAbilityProxy> proxy(new TestAbilityProxy(remoteObject)); // 直接构造具体Proxy
   ```
<!--DelEnd-->
### **ArkTS侧开发步骤**

> **说明：**
>
> - 此文档中的示例代码描述的是系统应用跨进程通信。
>
> - 当前不支持三方应用实现ServiceExtensionAbility，三方应用的UIAbility组件可以通过Context连接系统提供的ServiceExtensionAbility。
>
> - 当前使用场景： 仅限客户端是三方应用，服务端是系统应用。

1. 添加依赖

   ```ts
    // FA模型需要从@kit.AbilityKit导入featureAbility
    // import { featureAbility } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    ```

2. 绑定Ability

   首先，构造变量want，指定要绑定的Ability所在应用的包名、组件名，如果是跨设备的场景，还需要绑定目标设备NetworkId（组网场景下对应设备的标识符，可以使用distributedDeviceManager获取目标设备的NetworkId）；然后，构造变量connect，指定绑定成功、绑定失败、断开连接时的回调函数；最后，FA模型使用featureAbility提供的接口绑定Ability，Stage模型通过context获取服务后用提供的接口绑定Ability。

   ```ts
    // FA模型需要从@kit.AbilityKit导入featureAbility
    // import { featureAbility } from "@kit.AbilityKit";
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let dmInstance: distributedDeviceManager.DeviceManager | undefined;
    let proxy: rpc.IRemoteObject | undefined;
    let connectId: number;

    // 单个设备绑定Ability
    let want: Want = {
      // 包名和组件名写实际的值
      bundleName: "ohos.rpc.test.server",
      abilityName: "ohos.rpc.test.server.ServiceAbility",
    };
    let connect: common.ConnectOptions = {
      onConnect: (elementName, remoteProxy) => {
        hilog.info(0x0000, 'testTag', 'RpcClient: js onConnect called');
        proxy = remoteProxy;
      },
      onDisconnect: (elementName) => {
        hilog.info(0x0000, 'testTag', 'RpcClient: onDisconnect');
      },
      onFailed: () => {
        hilog.info(0x0000, 'testTag', 'RpcClient: onFailed');
      }
    };
    // FA模型使用此方法连接服务
    // connectId = featureAbility.connectAbility(want, connect);

    let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
    // 建立连接后返回的Id需要保存下来，在解绑服务时需要作为参数传入
    connectId = context.connectServiceExtensionAbility(want,connect);

    // 跨设备绑定
    try{
      dmInstance = distributedDeviceManager.createDeviceManager("ohos.rpc.test");
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'createDeviceManager errCode:' + err.code + ', errMessage:' + err.message);
    }

    // 使用distributedDeviceManager获取目标设备NetworkId
    if (dmInstance != undefined) {
      let deviceList = dmInstance.getAvailableDeviceListSync();
      let networkId = deviceList[0].networkId;
      let want: Want = {
        bundleName: "ohos.rpc.test.server",
        abilityName: "ohos.rpc.test.service.ServiceAbility",
        deviceId: networkId,
        flags: 256
      };
      // 建立连接后返回的Id需要保存下来，在断开连接时需要作为参数传入
      // FA模型使用此方法连接服务
      // connectId = featureAbility.connectAbility(want, connect);

      // 第一个参数是本应用的包名，第二个参数是接收distributedDeviceManager的回调函数
      connectId = context.connectServiceExtensionAbility(want,connect);
    }
   ```

3. 服务端处理客户端请求

   服务端被绑定的Ability在onConnect方法里返回继承自[rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject)的对象，该对象需要实现[onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9)方法，处理客户端的请求。

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { Want } from '@kit.AbilityKit';
    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // 根据code处理客户端的请求
        return true;
      }

      onConnect(want: Want) {
        const robj: rpc.RemoteObject = new Stub("rpcTestAbility");
        return robj;
      }
    }
   ```

4. 客户端处理服务端响应

   客户端在onConnect回调里接收到代理对象，调用[sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9-2)方法发起请求，在期约（用于表示一个异步操作的最终完成或失败及其结果值）或者回调函数里接收结果。

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // 使用期约
    let option = new rpc.MessageOption();
    let data = rpc.MessageSequence.create();
    let reply = rpc.MessageSequence.create();
    // 往data里写入参数
    let proxy: rpc.IRemoteObject | undefined;
    if (proxy != undefined) {
      proxy.sendMessageRequest(1, data, reply, option)
        .then((result: rpc.RequestResult) => {
          if (result.errCode != 0) {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
            return;
          }
          // 从result.reply里读取结果
        })
        .catch((e: Error) => {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest got exception: ' + e);
        })
        .finally(() => {
          data.reclaim();
          reply.reclaim();
        })
    }

    // 使用回调函数
    function sendRequestCallback(err: Error, result: rpc.RequestResult) {
      try {
        if (result.errCode != 0) {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
          return;
        }
        // 从result.reply里读取结果
      } finally {
          result.data.reclaim();
          result.reply.reclaim();
      }
    }
    let options = new rpc.MessageOption();
    let datas = rpc.MessageSequence.create();
    let replys = rpc.MessageSequence.create();
    // 往data里写入参数
    if (proxy != undefined) {
      proxy.sendMessageRequest(1, datas, replys, options, sendRequestCallback);
    }
   ```

5. 断开连接

   IPC通信结束后，FA模型使用featureAbility的接口断开连接，Stage模型在获取context后用提供的接口断开连接。

   ```ts
    // FA模型需要从@kit.AbilityKit导入featureAbility
    // import { featureAbility } from "@kit.AbilityKit";
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    function disconnectCallback() {
      hilog.info(0x0000, 'testTag', 'disconnect ability done');
    }
    // FA模型使用此方法断开连接
    // featureAbility.disconnectAbility(connectId, disconnectCallback);

    let proxy: rpc.IRemoteObject | undefined;
    let connectId: number;

    // 单个设备绑定Ability
    let want: Want = {
      // 包名和组件名写实际的值
      bundleName: "ohos.rpc.test.server",
      abilityName: "ohos.rpc.test.server.ServiceAbility",
    };
    let connect: common.ConnectOptions = {
      onConnect: (elementName, remote) => {
        proxy = remote;
      },
      onDisconnect: (elementName) => {
      },
      onFailed: () => {
        proxy;
      }
    };
    // FA模型使用此方法连接服务
    // connectId = featureAbility.connectAbility(want, connect);

    connectId = this.context.connectServiceExtensionAbility(want,connect);

    this.context.disconnectServiceExtensionAbility(connectId);
   ```

## 相关实例

针对IPC与RPC通信开发，有以下相关实例可供参考：

- [RPC通信（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Connectivity/RPC)
