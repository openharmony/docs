# IPC与RPC通信开发指导

## 场景介绍

IPC/RPC的主要工作是让运行在不同进程的Proxy和Stub互相通信，包括Proxy和Stub运行在不同设备的情况。


## 接口说明

**表1** Native侧IPC接口

| 类/接口 | 方法 | 功能说明 |
| -------- | -------- | -------- |
| [IRemoteBroker](../reference/apis/js-apis-rpc.md#iremotebroker) | sptr&lt;IRemoteObject&gt; AsObject() | 返回通信对象。派生类需要实现，Stub端返回RemoteObject对象本身，Proxy端返回代理对象。 |
| IRemoteStub | virtual int OnRemoteRequest(uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option) | 请求处理方法，派生类需要重写该方法用来处理Proxy的请求并返回结果。 |
| IRemoteProxy |  | 业务Proxy类，派生自IRemoteProxy类。 |


## 开发步骤

**Native侧开发步骤**

1.添加依赖

sdk依赖：

```
external_deps = [
  "ipc:ipc_core",
]
```

此外， IPC/RPC依赖的refbase实现在公共基础库下，请增加对utils的依赖：

```
deps = [
 “//utils/native/base:utils”
]
include_dirs = [
“//utils/native/base/include”,
]
```

2. 定义IPC接口ITestAbility

   SA接口继承IPC基类接口IRemoteBroker，接口里定义描述符、业务函数和消息码，其中业务函数在Proxy端和Stub端都需要实现。

   ```
   class ITestAbility : public IRemoteBroker {
   public:
       // DECLARE_INTERFACE_DESCRIPTOR是必需的，入参需使用std::u16string；
       DECLARE_INTERFACE_DESCRIPTOR("test.ITestAbility");
       int TRANS_ID_PING_ABILITY = 1; // 定义消息码
       virtual int TestPingAbility(const std::u16string &dummy) = 0; // 定义业务函数
   };
   ```

3. 定义和实现服务端TestAbilityStub

   该类是和IPC框架相关的实现，需要继承 IRemoteStub&lt;ITestAbility&gt;。Stub端作为接收请求的一端，需重写OnRemoteRequest方法用于接收客户端调用。

   ```
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
   ```
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

   ```
   class TestAbilityProxy : public IRemoteProxy<ITestAbility> {
   public:
       explicit TestAbilityProxy(const sptr<IRemoteObject> &impl);
       int TestPingService(const std::u16string &dummy) override;
   private:
       static inline BrokerDelegator<TestAbilityProxy> delegator_; // 方便后续使用iface_cast宏
   }
   
   TestAbilityProxy::TestAbilityProxy(const sptr<IRemoteObject> &impl)
       : IRemoteProxy<ITestAbility>(impl)
   {
   }
   
   int TestAbilityProxy::TestPingService(const std::u16string &dummy){
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

   ```
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

   ```
   // 获取本设备内注册的SA的proxy
   sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId);
   sptr<ITestAbility> testAbility = iface_cast<ITestAbility>(remoteObject); // 使用iface_cast宏转换成具体类型
   
   // 获取其他设备注册的SA的proxy
   sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId, deviceId); // deviceId是指定设备的标识符
   sptr<TestAbilityProxy> proxy(new TestAbilityProxy(remoteObject)); // 直接构造具体Proxy
   ```

**JS侧开发步骤**

1. 添加依赖

```
import rpc from "@ohos.rpc"
import featureAbility from "@ohos.ability.featureAbility"
```

2. 客户端构造变量want，指定要绑定的Ability所在应用的包名、组件名，如果是跨设备的场景，还需要目标设备NetworkId。构造变量connect，指定绑定成功、绑定失败、断开连接时的回调函数。使用featureAbility提供的接口绑定Ability。

   ```
   import rpc from "@ohos.rpc"
   import featureAbility from "@ohos.ability.featureAbility"
   
   let proxy = null
   let connectId = null
   
   // 单个设备
   let want = {
       // 包名和组件名写实际的值
       "bundleName": "ohos.rpc.test.server",
       "abilityName": "ohos.rpc.test.server.ServiceAbility",
   }
   let connect = {
       onConnect:function(elementName, remote) {
           proxy = remote
       },
       onDisconnect:function(elementName) {
       },
       onFailed:function() {
           proxy = null
       }
   }
   connectId = featureAbility.connectAbility(want, connect)
   
   // 如果是跨设备绑定，可以使用deviceManager获取目标设备NetworkId
   import deviceManager from '@ohos.distributedHardware.deviceManager'
   function deviceManagerCallback(deviceManager) {
       let deviceList = deviceManager.getTrustedDeviceListSync()
       let deviceId = deviceList[0].deviceId
       let want = {
           "bundleName": "ohos.rpc.test.server",
           "abilityName": "ohos.rpc.test.service.ServiceAbility",
           "deviceId": deviceId,
           "flags": 256
       }
       connectId = featureAbility.connectAbility(want, connect)
   }
   // 第一个参数是本应用的包名，第二个参数是接收deviceManager的回调函数
   deviceManager.createDeviceManager("ohos.rpc.test", deviceManagerCallback)
   ```



3. 服务端被绑定的Ability在onConnect方法里返回继承自rpc.RemoteObject的对象，该对象需要实现onRemoteMessageRequest方法，处理客户端的请求。

   ```
   import rpc from "@ohos.rpc"
   onConnect(want: Want) {
       var robj:rpc.RemoteObject = new Stub("rpcTestAbility")
       return robj
   }
   class Stub extends rpc.RemoteObject {
       constructor(descriptor) {
           super(descriptor)
       }
       onRemoteMessageRequest(code, data, reply, option) {
           // 根据code处理客户端的请求
           return true
       }
   }
   ```



4. 客户端在onConnect回调里接收到代理对象，调用sendRequestAsync方法发起请求，在期约或者回调函数里接收结果。

   ```
   import rpc from "@ohos.rpc"
   // 使用期约
   let option = new rpc.MessageOption()
   let data = rpc.MessageParcel.create()
   let reply = rpc.MessageParcel.create()
   // 往data里写入参数
   proxy.sendRequestAsync(1, data, reply, option)
       .then(function(result) {
           if (result.errCode != 0) {
               console.error("send request failed, errCode: " + result.errCode)
               return
           }
           // 从result.reply里读取结果
       })
       .catch(function(e) {
           console.error("send request got exception: " + e)
       }
       .finally(() => {
           data.reclaim()
           reply.reclaim()
       })
   
   // 使用回调函数
   function sendRequestCallback(result) {
       try {
           if (result.errCode != 0) {
               console.error("send request failed, errCode: " + result.errCode)
               return
           }
           // 从result.reply里读取结果
       } finally {
           result.data.reclaim()
           result.reply.reclaim()
       }
   }
   let option = new rpc.MessageOption()
   let data = rpc.MessageParcel.create()
   let reply = rpc.MessageParcel.create()
   // 往data里写入参数
   proxy.sendRequest(1, data, reply, option, sendRequestCallback)
   ```



5. IPC通信结束后，使用featureAbility的接口断开连接。

   ```
   import rpc from "@ohos.rpc"
   import featureAbility from "@ohos.ability.featureAbility"
   function disconnectCallback() {
       console.info("disconnect ability done")
   }
   featureAbility.disconnectAbility(connectId, disconnectCallback)
   ```

