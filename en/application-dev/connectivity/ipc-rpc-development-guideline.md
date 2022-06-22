# IPC & RPC Development<a name="EN-US_TOPIC_0000001103710988"></a>

## When to Use<a name="section18502174174019"></a>

IPC/RPC enables a proxy and a stub that run on different processes to communicate with each other, regardless of whether they run on the same or different devices.

## Available APIs<a name="section1633115419401"></a>

**Table  1** Native IPC APIs

<a name="table178849240013"></a>
<table><thead align="left"><tr id="row6884924608"><th class="cellrowborder" valign="top" width="14.12141214121412%" id="mcps1.2.4.1.1"><p id="p98846241706"><a name="p98846241706"></a><a name="p98846241706"></a>Class/Interface</p>
</th>
<th class="cellrowborder" valign="top" width="52.54525452545254%" id="mcps1.2.4.1.2"><p id="p1488482414020"><a name="p1488482414020"></a><a name="p1488482414020"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p388516244016"><a name="p388516244016"></a><a name="p388516244016"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15885824402"><td class="cellrowborder" valign="top" width="14.12141214121412%" headers="mcps1.2.4.1.1 "><p id="p08859241008"><a name="p08859241008"></a><a name="p08859241008"></a>IRemoteBroker</p>
</td>
<td class="cellrowborder" valign="top" width="52.54525452545254%" headers="mcps1.2.4.1.2 "><p id="p388572412010"><a name="p388572412010"></a><a name="p388572412010"></a>sptr&lt;IRemoteObject&gt; AsObject()</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p13885724405"><a name="p13885724405"></a><a name="p13885724405"></a>Obtains the holder of a remote proxy object. This method must be implemented by the derived classes of <strong id="b18927631105113"><a name="b18927631105113"></a><a name="b18927631105113"></a>IRemoteBroker</strong>. If you call this method on the stub, the <strong id="b7932163110519"><a name="b7932163110519"></a><a name="b7932163110519"></a>RemoteObject</strong> is returned; if you call this method on the proxy, the proxy object is returned.</p>
</td>
</tr>
<tr id="row138859241808"><td class="cellrowborder" valign="top" width="14.12141214121412%" headers="mcps1.2.4.1.1 "><p id="p1888515245012"><a name="p1888515245012"></a><a name="p1888515245012"></a>IRemoteStub</p>
</td>
<td class="cellrowborder" valign="top" width="52.54525452545254%" headers="mcps1.2.4.1.2 "><p id="p1388516240011"><a name="p1388516240011"></a><a name="p1388516240011"></a>virtual int OnRemoteRequest(uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option)</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1188582414016"><a name="p1188582414016"></a><a name="p1188582414016"></a>Called to process a request from the proxy and return the result. Derived classes need to override this method.</p>
</td>
</tr>
<tr id="row108856241904"><td class="cellrowborder" valign="top" width="14.12141214121412%" headers="mcps1.2.4.1.1 "><p id="p6885924609"><a name="p6885924609"></a><a name="p6885924609"></a>IRemoteProxy</p>
</td>
<td class="cellrowborder" valign="top" width="52.54525452545254%" headers="mcps1.2.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p688592413018"><a name="p688592413018"></a><a name="p688592413018"></a>Service proxy classes are derived from the <strong id="b169739356519"><a name="b169739356519"></a><a name="b169739356519"></a>IRemoteProxy</strong> class.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section4207112818418"></a>

**Using Native APIs**

1.  Define the IPC interface **ITestAbility**.

    **ITestAbility** inherits the IPC base class **IRemoteBroker** and defines descriptors, functions, and message code. The functions need to be implemented on both the proxy and stub.

    ```
    class ITestAbility : public IRemoteBroker {
    public:
    // DECLARE_INTERFACE_DESCRIPTOR is mandatory, and the input parameter is std::u16string.
    DECLARE_INTERFACE_DESCRIPTOR(u"test.ITestAbility");
    int TRANS_ID_PING_ABILITY = 1; // Define the message code.
    virtual int TestPingAbility(const std::u16string &dummy) = 0; // Define functions.
    };
    ```

2.  Define and implement service provider **TestAbilityStub**.

    This class is related to the IPC framework and needs to inherit **IRemoteStub<ITestAbility\>**. You need to override **OnRemoteRequest** on the stub to receive requests from the proxy.

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

3.  Define the **TestAbility** class that implements functions for the stub.

    ```
    class TestAbility : public TestAbilityStub {
    public:
        int TestPingAbility(const std::u16string &dummy);
    }
    
    int TestAbility::TestPingAbility(const std::u16string &dummy) {
        return 0;
    }
    ```

4.  Define and implement **TestAbilityProxy**.

    This class is implemented on the proxy and inherits **IRemoteProxy<ITestAbility\>**. You can call **SendRequest** to send a request to the stub and expose the capabilities provided by the stub.

    ```
    class TestAbilityProxy : public IRemoteProxy<ITestAbility> {
    public:
        explicit TestAbilityProxy(const sptr<IRemoteObject> &impl);
        int TestPingService(const std::u16string &dummy) override;
    private:
        static inline BrokerDelegator<TestAbilityProxy> delegator_; // Use the iface_cast macro.
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

5.  Register and start an SA.

    Call **AddSystemAbility** to register the **TestAbilityStub** instance of the SA with **SystemAbilityManager**. The registration parameters vary depending on whether the **SystemAbilityManager** resides on the same device as the SA.

    ```
    // Register the TestAbilityStub instance with the SystemAbilityManager on the same device as the SA.
    auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    samgr->AddSystemAbility(saId, new TestAbility());
    
    // Register the TestAbilityStub instance with the SystemAbilityManager on a different device.
    auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    ISystemAbilityManager::SAExtraProp saExtra;
    saExtra.isDistributed = true; // Set a distributed SA.
    int result = samgr->AddSystemAbility(saId, new TestAbility(), saExtra);
    ```

6.  Obtain the SA.

    Call the **GetSystemAbility** function of the **SystemAbilityManager** class to obtain the **IRemoteObject** for the SA, and create a **TestAbilityProxy** instance.

    ```
    // Obtain the proxy of the SA registered on the local device.
    sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId);
    sptr<ITestAbility> testAbility = iface_cast<ITestAbility>(remoteObject); // Use the iface_cast macro to convert the proxy to a specific type.
    
    // Obtain the proxies of the SAs registered with other devices.
    sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
    sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId, deviceId); // deviceId identifies a device.
    sptr<TestAbilityProxy> proxy(new TestAbilityProxy(remoteObject)); // Construct a proxy.
    ```


