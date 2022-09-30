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

1. 定义IPC接口ITestAbility

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

2. 定义和实现服务端TestAbilityStub

   该类是和IPC框架相关的实现，需要继承 IRemoteStub&lt;ITestAbility&gt;。Stub端作为接收请求的一端，需重写OnRemoteRequest方法用于接收客户端调用。

   ```
   class TestAbilityStub : public IRemoteStub<ITestAbility> {
   public:    
       virtual int OnRemoteRequest(uint32_t code, MessageParcel &data, MessageParcel &reply, MessageOption &option) override;
       int TestPingAbility(const std::u16string &dummy) override;
    };
   
   int TestServiceStub::OnRemoteRequest(uint32_t code,
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

3. 定义服务端业务函数具体实现类TestAbility
   ```
   class TestAbility : public TestAbilityStub {
   public:
       int TestPingAbility(const std::u16string &dummy);
   }
   
   int TestAbility::TestPingAbility(const std::u16string &dummy) {
       return 0;
   }
   ```

4. 定义和实现客户端 TestAbilityProxy

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

5. SA注册与启动

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

6. SA获取与调用

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

