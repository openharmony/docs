# IPC & RPC Development<a name="EN-US_TOPIC_0000001103710988"></a>

## When to Use<a name="section18502174174019"></a>

IPC/RPC enables a proxy and a stub that run on different processes to communicate with each other, regardless of whether they run on the same or different devices.

## Available APIs<a name="section1633115419401"></a>

**Table  1** Native IPC APIs

| Class/Interface | Function | Description |
| --------------- | -------- | ----------- |
| [IRemoteBroker](../reference/apis/js-apis-rpc.md#iremotebroker) | sptr<IRemoteObject> AsObject() | Obtains the holder of a remote proxy object. This method must be implemented by the derived classes of **IRemoteBroker**. If you call this method on the stub, the **RemoteObject** is returned; if you call this method on the proxy, the proxy object is returned. |
| IRemoteStub | virtual int OnRemoteRequest(uint32_t code, MessageParcel &data, MessageParcel &reply, MessageOption &option) | Called to process a request from the proxy and return the result. Derived classes need to override this method. |
| IRemoteProxy | | Service proxy classes are derived from the **IRemoteProxy** class. |

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


