# IPC & RPC Development Guidelines

## When to Use

IPC/RPC enables a proxy and a stub that run on different processes to communicate with each other, regardless of whether they run on the same or different devices.


## Available APIs

Table 1 Native IPC APIs

| Class| API| Description|
| -------- | -------- | -------- |
| [IRemoteBroker](../reference/apis/js-apis-rpc.md#iremotebroker) | sptr&lt;IRemoteObject&gt; AsObject() | Obtains the holder of a remote proxy object. If you call this API on the stub, the **RemoteObject** is returned; if you call this API on the proxy, the proxy object is returned.|
| IRemoteStub | virtual int OnRemoteRequest(uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option) | Called to process a request from the proxy and return the result. Derived classes need to override this API.|
| IRemoteProxy |  | Service proxy class, which is derived from the **IRemoteProxy** class.|


## How to Develop

### **Using Native APIs**

1. Add dependencies.

   SDK dependency:

   ```
   #IPC scenario
   external_deps = [
     "ipc:ipc_single",
   ]

   #RPC scenario
   external_deps = [
     "ipc:ipc_core",
   ]
   ```

   In addition, the refbase implementation on which IPC/RPC depends is stored in **//utils**. Add the dependency on the Utils source code.

   ```
   external_deps = [
     "c_utils:utils",
   ]
   ```

2. Define the IPC interface **ITestAbility**.

   **ITestAbility** inherits the IPC base class **IRemoteBroker** and defines descriptors, functions, and message code. The functions need to be implemented on both the proxy and stub.

   ```c++
   #include "iremote_broker.h"

   // Define message codes.
   const int TRANS_ID_PING_ABILITY = 5;

   const std::string DESCRIPTOR = "test.ITestAbility";

   class ITestAbility : public IRemoteBroker {
   public:
       // DECLARE_INTERFACE_DESCRIPTOR is mandatory, and the input parameter is std::u16string.
       DECLARE_INTERFACE_DESCRIPTOR(to_utf16(DESCRIPTOR));
       virtual int TestPingAbility(const std::u16string &dummy) = 0; // Define functions.
   };
   ```

3. Define and implement service provider **TestAbilityStub**.

   This class is related to the IPC framework and needs to inherit **IRemoteStub&lt;ITestAbility&gt;**. You need to override **OnRemoteRequest** on the stub to receive requests from the proxy.

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

4. Define the **TestAbility** class that implements functions for the stub.

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

5. Define and implement **TestAbilityProxy**.

   This class is implemented on the proxy and inherits **IRemoteProxy&lt;ITestAbility&gt;**. You can call **SendRequest** to send a request to the stub and expose the capabilities provided by the stub.

   ```c++
   #include "iability_test.h"
   #include "iremote_proxy.h"
   #include "iremote_object.h"

   class TestAbilityProxy : public IRemoteProxy<ITestAbility> {
   public:
       explicit TestAbilityProxy(const sptr<IRemoteObject> &impl);
       int TestPingAbility(const std::u16string &dummy) override;
   private:
       static inline BrokerDelegator<TestAbilityProxy> delegator_; // Use the iface_cast macro.
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

6. Register and start an SA.

   Call **AddSystemAbility** to register the **TestAbilityStub** instance of the SA with **SystemAbilityManager**. The registration parameters vary depending on whether the **SystemAbilityManager** resides on the same device as the SA.

   ```c++
   // Register the TestAbilityStub instance with the SystemAbilityManager on the same device as the SA.
   auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   samgr->AddSystemAbility(saId, new TestAbility());

   // Register the TestAbilityStub instance with the SystemAbilityManager on a different device.
   auto samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   ISystemAbilityManager::SAExtraProp saExtra;
   saExtra.isDistributed = true; // Set a distributed SA.
   int result = samgr->AddSystemAbility(saId, new TestAbility(), saExtra);
   ```

7. Obtain the SA.

   Call the **GetSystemAbility** function of the **SystemAbilityManager** class to obtain the **IRemoteObject** for the SA, and create a **TestAbilityProxy** instance.

   ```c++
   // Obtain the proxy of the SA registered on the local device.
   sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();
   sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId);
   sptr<ITestAbility> testAbility = iface_cast<ITestAbility>(remoteObject); // Use the iface_cast macro to convert the proxy to a specific type.

   // Obtain the proxy of the SA registered with any other devices.
   sptr<ISystemAbilityManager> samgr = SystemAbilityManagerClient::GetInstance().GetSystemAbilityManager();

   // networkId is the device identifier and can be obtained through GetLocalNodeDeviceInfo.
   sptr<IRemoteObject> remoteObject = samgr->GetSystemAbility(saId, networkId);
   sptr<TestAbilityProxy> proxy(new TestAbilityProxy(remoteObject)); // Construct a proxy.
   ```

### **Using JS APIs**

1. Add dependencies.

   ```ts
   import rpc from "@ohos.rpc";
   // Import @ohos.ability.featureAbility only for the application developed based on the FA model.
   // import featureAbility from "@ohos.ability.featureAbility";
   ```

   If you use the stage model, you need to obtain the context. The sample code is as follows:

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

2. Bind the desired ability.

   Construct the **want** variable, and specify the bundle name and component name of the application where the ability is located. If cross-device communication is involved, also specify the network ID of the target device, which can be obtained through **deviceManager**. Then, construct the **connect** variable, and specify the callback that is called when the binding is successful, the binding fails, or the ability is disconnected. If you use the FA model, call the API provided by **featureAbility** to bind an ability. If you use the stage model, obtain a service instance through **Context**, and then call the API provided by **featureAbility** to bind an ability.

   ```ts
   import rpc from "@ohos.rpc";
   // Import @ohos.ability.featureAbility only for the application developed based on the FA model.
   // import featureAbility from "@ohos.ability.featureAbility";

   let proxy = null;
   let connectId = null;

   // Bind the ability on a single device.
   let want = {
       // Enter the bundle name and ability name.
       "bundleName": "ohos.rpc.test.server",
       "abilityName": "ohos.rpc.test.server.ServiceAbility",
   };
   let connect = {
       onConnect:function(elementName, remote) {
           proxy = remote;
       },
       onDisconnect:function(elementName) {
       },
       onFailed:function() {
           proxy = null;
       }
   };
   // Use this method to connect to the ability in the FA model.
   // connectId = featureAbility.connectAbility(want, connect);

   connectId = globalThis.context.connectServiceExtensionAbility(want,connect);

   // If you're binding the ability across devices, use deviceManager to obtain the network ID of the target device.
   import deviceManager from '@ohos.distributedHardware.deviceManager';
   function deviceManagerCallback(deviceManager) {
       let deviceList = deviceManager.getTrustedDeviceListSync();
       let networkId = deviceList[0].networkId;
       let want = {
           "bundleName": "ohos.rpc.test.server",
           "abilityName": "ohos.rpc.test.service.ServiceAbility",
           "networkId": networkId,
           "flags": 256
       };
       // The ID returned after the connection is set up must be saved. The ID will be passed for service disconnection.
       // Use this method to connect to the ability in the FA model.
       // connectId = featureAbility.connectAbility(want, connect);

       connectId = globalThis.context.connectServiceExtensionAbility(want,connect);
   }
   // The first parameter specifies the bundle name of the application, and the second parameter specifies the callback used to return the device ID obtained by using DeviceManager.
   deviceManager.createDeviceManager("ohos.rpc.test", deviceManagerCallback);
   ```


3. Process requests sent from the client.

   Call the **onConnect** API to return a proxy object inherited from **rpc.RemoteObject** after the ability is successfully bound. Implement the **onRemoteMessageRequest** API for the proxy object to process requests sent from the client.

   ```ts
   onConnect(want: Want) {
       var robj:rpc.RemoteObject = new Stub("rpcTestAbility");
       return robj;
   }
   class Stub extends rpc.RemoteObject {
       constructor(descriptor) {
           super(descriptor);
       }
       onRemoteMessageRequest(code, data, reply, option) {
           // Process requests sent from the client based on the code.
           return true;
       }
   }
   ```

4. Process responses sent from the server.

   Obtain the proxy object from the **onConnect** callback, call **sendRequest** to send a request, and receive the response using a callback or a promise (an object representing the eventual completion or failure of an asynchronous operation and its result value).

   ```ts
   // Use a promise.
   let option = new rpc.MessageOption();
   let data = rpc.MessageParcel.create();
   let reply = rpc.MessageParcel.create();
   // Write parameters to data.
   proxy.sendRequest(1, data, reply, option)
       .then(function(result) {
           if (result.errCode != 0) {
               console.error("send request failed, errCode: " + result.errCode);
               return;
           }
           // Read the result from result.reply.
       })
       .catch(function(e) {
           console.error("send request got exception: " + e);
       })
       .finally(() => {
           data.reclaim();
           reply.reclaim();
       })

   // Use a callback.
   function sendRequestCallback(result) {
       try {
           if (result.errCode != 0) {
               console.error("send request failed, errCode: " + result.errCode);
               return;
           }
           // Read the result from result.reply.
       } finally {
           result.data.reclaim();
           result.reply.reclaim();
       }
   }
   let option = new rpc.MessageOption();
   let data = rpc.MessageParcel.create();
   let reply = rpc.MessageParcel.create();
   // Write parameters to data.
   proxy.sendRequest(1, data, reply, option, sendRequestCallback);
   ```

5. Tear down the connection.

   If you use the FA model, call the API provided by **featureAbility** to tear down the connection when the communication is over. If you use the stage model, obtain a service instance through **Context**, and then call the API provided by **featureAbility** to tear down the connection.

   ```ts
   import rpc from "@ohos.rpc";
   // Import @ohos.ability.featureAbility only for the application developed based on the FA model.
   // import featureAbility from "@ohos.ability.featureAbility";
   function disconnectCallback() {
       console.info("disconnect ability done");
   }
   // Use this method to disconnect from the ability in the FA model.
   // featureAbility.disconnectAbility(connectId, disconnectCallback);

   globalThis.context.disconnectServiceExtensionAbility(connectId);
   ```
