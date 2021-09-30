# IPC与RPC通信开发指导<a name="ZH-CN_TOPIC_0000001103710988"></a>

-   [场景介绍](#section18502174174019)
-   [接口说明](#section1633115419401)
-   [开发步骤](#section4207112818418)

## 场景介绍<a name="section18502174174019"></a>

IPC/RPC的主要工作是让运行在不同进程的Proxy和Stub互相通信，包括Proxy和Stub运行在不同设备的情况。

## 接口说明<a name="section1633115419401"></a>

**表 1**  Native侧IPC接口

<a name="table178849240013"></a>
<table><thead align="left"><tr id="row6884924608"><th class="cellrowborder" valign="top" width="14.12141214121412%" id="mcps1.2.4.1.1"><p id="p98846241706"><a name="p98846241706"></a><a name="p98846241706"></a>类/接口</p>
</th>
<th class="cellrowborder" valign="top" width="52.54525452545254%" id="mcps1.2.4.1.2"><p id="p1488482414020"><a name="p1488482414020"></a><a name="p1488482414020"></a>方法</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p388516244016"><a name="p388516244016"></a><a name="p388516244016"></a>功能说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15885824402"><td class="cellrowborder" valign="top" width="14.12141214121412%" headers="mcps1.2.4.1.1 "><p id="p08859241008"><a name="p08859241008"></a><a name="p08859241008"></a>IRemoteBroker</p>
</td>
<td class="cellrowborder" valign="top" width="52.54525452545254%" headers="mcps1.2.4.1.2 "><p id="p388572412010"><a name="p388572412010"></a><a name="p388572412010"></a>sptr&lt;IRemoteObject&gt; AsObject()</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p13885724405"><a name="p13885724405"></a><a name="p13885724405"></a>返回通信对象。派生类需要实现，Stub端返回RemoteObject对象本身，Proxy端返回代理对象。</p>
</td>
</tr>
<tr id="row138859241808"><td class="cellrowborder" valign="top" width="14.12141214121412%" headers="mcps1.2.4.1.1 "><p id="p1888515245012"><a name="p1888515245012"></a><a name="p1888515245012"></a>IRemoteStub</p>
</td>
<td class="cellrowborder" valign="top" width="52.54525452545254%" headers="mcps1.2.4.1.2 "><p id="p1388516240011"><a name="p1388516240011"></a><a name="p1388516240011"></a>virtual int OnRemoteRequest(uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option)</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1188582414016"><a name="p1188582414016"></a><a name="p1188582414016"></a>请求处理方法，派生类需要重写，处理Proxy的请求并返回结果。</p>
</td>
</tr>
<tr id="row108856241904"><td class="cellrowborder" valign="top" width="14.12141214121412%" headers="mcps1.2.4.1.1 "><p id="p6885924609"><a name="p6885924609"></a><a name="p6885924609"></a>IRemoteProxy</p>
</td>
<td class="cellrowborder" valign="top" width="52.54525452545254%" headers="mcps1.2.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p688592413018"><a name="p688592413018"></a><a name="p688592413018"></a>业务Proxy类派生自IRemoteProxy类。</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section4207112818418"></a>

**Native侧开发步骤**

1.  定义IPC接口ITestAbility

    SA接口继承IPC基类接口IRemoteBroker，接口里定义描述符、业务函数和消息码，其中业务函数在Proxy端和Stub端都需要实现。

    ```
    class ITestAbility : public IRemoteBroker {
    public:
    // DECLARE_INTERFACE_DESCRIPTOR是必须的， 入参需使用std::u16string；
    DECLARE_INTERFACE_DESCRIPTOR(u"test.ITestAbility");
    int TRANS_ID_PING_ABILITY = 1; // 定义消息码
    virtual int TestPingAbility(const std::u16string &dummy) = 0; // 定义业务函数
    };
    ```

2.  定义和实现服务端TestAbilityStub

    该类是和IPC框架相关的实现，需要继承 IRemoteStub<ITestAbility\>。Stub端作为接收请求的一端，需重写OnRemoteRequest方法用于接收客户端调用。

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

3.  定义服务端业务函数具体实现类TestAbility

    ```
    class TestAbility : public TestAbilityStub {
    public:
        int TestPingAbility(const std::u16string &dummy);
    }
    
    int TestAbility::TestPingAbility(const std::u16string &dummy) {
        return 0;
    }
    ```

4.  定义和实现客户端TestAbilityProxy

    该类是Proxy端实现，继承IRemoteProxy<ITestAbility\>，调用SendRequest接口向Stub端发送请求，对外暴露服务端提供的能力。

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
    
    int TestAbilityProxy::TestPingService(const std::u16string &dummy) {
        MessageOption option;
        MessageParcel dataParcel, replyParcel;
        dataParcel.WriteString16(dummy);
        int error = Remote()->SendRequest(TRANS_ID_PING_ABILITY, dataParcel, replyParcel, option);
        int result = (error == ERR_NONE) ? replyParcel.ReadInt32() : -1;
        return result;
    }
    ```

5.  SA注册与启动

    SA需要将自己的TestAbilityStub实例通过AddSystemAbility接口注册到SystemAbilityManager，设备内与分布式的注册参数不同。

    ```
    // 注册到本设备内
    auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    samgr->AddSystemAbility(said, new TestAbility());
    
    // 在组网场景下，会被同步到其他设备上
    auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ISystemAbilityManager::SAExtraProp saExtra;
    saExtra.isDistributed = true; // 设置为分布式SA
    int result = samgr->AddSystemAbility(said, new TestAbility(), saExtra);
    ```

6.  SA获取与调用

    通过SystemAbilityManager的GetSystemAbility方法可获取到对应SA的代理IRemoteObject，然后构造TestAbilityProxy即可。

    ```
    // 获取本设备内注册的SA的proxy
    sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(said);
    sptr<ITestAbility> testAbility = iface_cast<ITestAbility>(remoteObject); // 使用iface_cast宏转换成具体类型
    
    // 获取其他设备注册的SA的Proxy
    sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(sdid, deviceId); // deviceId是指定设备的标识符
    sptr<TestAbilityProxy> proxy(new TestAbilityProxy(remoteObject)); // 直接构造具体Proxy
    ```


