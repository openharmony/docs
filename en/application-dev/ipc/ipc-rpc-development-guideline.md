# IPC and RPC Development

## When to Use

IPC/RPC enables a proxy and a stub that run on different processes to communicate with each other, regardless of whether they run on the same or different devices.

<!--Del-->
## Available APIs

**Table 1** Native IPC APIs

| Class/Interface| API                              | Description                                                            |
|----------|  ------------------------------------ | ---------------------------------------------------------------- |
| IRemoteBroker | sptr&lt;IRemoteObject&gt; AsObject() | Obtains the holder of a remote proxy object. If you call this API on the stub, the **RemoteObject** is returned; if you call this API on the proxy, the proxy object is returned.|
| IRemoteStub | virtual int OnRemoteRequest(uint32_t code, MessageParcel &amp;data, MessageParcel &amp;reply, MessageOption &amp;option) | Called to process a request from the proxy and return the result. Derived classes need to override this API.|
| IRemoteProxy | Remote()->SendRequest(code, data, reply, option)  | Sends a request to the peer end. Service proxy classes are derived from the **IRemoteProxy** class.|
<!--DelEnd-->

## How to Develop

<!--Del-->
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

   The refbase implementation on which IPC/RPC depends is in **//utils**. Add the dependency on Utils.

   ```
   external_deps = [
     "c_utils:utils",
   ]
   ```

2. Define the IPC interface **ITestAbility**.

   **ITestAbility** inherits from the IPC base class **IRemoteBroker** and defines descriptors, functions, and message code. The functions need to be implemented on both the proxy and stub.

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

3. Define and implement the service provider **TestAbilityStub**.

   This class is related to the IPC framework and inherits from **IRemoteStub&lt;ITestAbility&gt;**. You need to override **OnRemoteRequest** on the stub to receive requests from the proxy.

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

   This class is implemented on the proxy and inherits from **IRemoteProxy&lt;ITestAbility&gt;**. You can call **SendRequest** to send a request to the stub and expose the capabilities provided by the stub.

   ```c++
   #include "iability_test.h"
   #include "iremote_proxy.h"
   #include "iremote_object.h"

   class TestAbilityProxy : public IRemoteProxy<ITestAbility> {
   public:
       explicit TestAbilityProxy(const sptr<IRemoteObject> &impl);
       int TestPingAbility(const std::u16string &dummy) override;
   private:
       static inline BrokerDelegator<TestAbilityProxy> delegator_; // For use of the iface_cast macro at a later time
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

   Call **AddSystemAbility** to register the **TestAbilityStub** instance of an SA with **SystemAbilityManager**. The registration parameters vary depending on whether the **SystemAbilityManager** resides on the same device as the SA.

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
<!--DelEnd-->
### **Using ArkTS APIs**

> **NOTE**
>
> - The sample code in this topic implements communication between system applications across processes.
>
> - Currently, third-party applications cannot implement ServiceExtensionAbility. The UIAbility components of a third-party application can connect to the ServiceExtensionAbility provided by the system via **Context**.
>
> - The development applies only to the scenario, in which the client is a third-party application and the server is a system application.

1. Add dependencies.

   ```ts
    // If the FA model is used, import featureAbility from @kit.AbilityKit.
    // import { featureAbility } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    ```

2. Bind the desired ability.

   Construct the **want** variable, and specify the bundle name and component name of the application where the ability is located. If cross-device communication is involved, also specify the network ID of the target device, which can be obtained through **distributedDeviceManager**. <br>Then, construct the **connect** variable, and specify the callback to be invoked when the binding is successful, the binding fails, or the ability is disconnected. If you use the FA model, call the API provided by **featureAbility** to bind an ability. If you use the stage model, obtain a service instance through **Context**, and then call the API provided by **featureAbility** to bind an ability.

   ```ts
    // If the FA model is used, import featureAbility from @kit.AbilityKit.
    // import { featureAbility } from "@kit.AbilityKit";
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let dmInstance: distributedDeviceManager.DeviceManager | undefined;
    let proxy: rpc.IRemoteObject | undefined;
    let connectId: number;

    // Bind an ability on a single device.
    let want: Want = {
      // Enter the bundle name and ability name.
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
    // Use this method to connect to the ability in the FA model.
    // connectId = featureAbility.connectAbility(want, connect);

    let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext; // UIAbilityContext
    // Save the connection ID, which will be used when the ability is disconnected.
    connectId = context.connectServiceExtensionAbility(want,connect);

    // Bind an ability across devices.
    try{
      dmInstance = distributedDeviceManager.createDeviceManager("ohos.rpc.test");
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'createDeviceManager errCode:' + err.code + ', errMessage:' + err.message);
    }

    // Use distributedDeviceManager to obtain the network ID of the target device.
    if (dmInstance != undefined) {
      let deviceList = dmInstance.getAvailableDeviceListSync();
      let networkId = deviceList[0].networkId;
      let want: Want = {
        bundleName: "ohos.rpc.test.server",
        abilityName: "ohos.rpc.test.service.ServiceAbility",
        deviceId: networkId,
        flags: 256
      };
      // Save the connection ID, which will be used when the ability is disconnected.
      // Use this method to connect to the ability in the FA model.
      // connectId = featureAbility.connectAbility(want, connect);

      // The first parameter specifies the bundle name of the application, and the second parameter specifies the callback used to return the network ID obtained by using distributedDeviceManager.
      connectId = context.connectServiceExtensionAbility(want,connect);
    }
   ```

3. Process requests sent from the client.

   Call **onConnect()** to return a proxy object inherited from [rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject) after the ability is successfully connected. Implement [onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9) for the proxy object to process requests sent from the client.

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { Want } from '@kit.AbilityKit';
    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // Process requests sent from the client based on the code.
        return true;
      }

      onConnect(want: Want) {
        const robj: rpc.RemoteObject = new Stub("rpcTestAbility");
        return robj;
      }
    }
   ```

4. Process responses sent from the server.

   Receive the proxy object in the **onConnect** callback, call [sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9-2) to send a request, and receive the response using a callback or a promise (an object representing the eventual completion or failure of an asynchronous operation and its result value).

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // Use a promise.
    let option = new rpc.MessageOption();
    let data = rpc.MessageSequence.create();
    let reply = rpc.MessageSequence.create();
    // Write parameters to data.
    let proxy: rpc.IRemoteObject | undefined;
    if (proxy != undefined) {
      proxy.sendMessageRequest(1, data, reply, option)
        .then((result: rpc.RequestResult) => {
          if (result.errCode != 0) {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
            return;
          }
          // Read the result from result.reply.
        })
        .catch((e: Error) => {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest got exception: ' + e);
        })
        .finally(() => {
          data.reclaim();
          reply.reclaim();
        })
    }

    // Use a callback.
    function sendRequestCallback(err: Error, result: rpc.RequestResult) {
      try {
        if (result.errCode != 0) {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
          return;
        }
        // Read the result from result.reply.
      } finally {
          result.data.reclaim();
          result.reply.reclaim();
      }
    }
    let options = new rpc.MessageOption();
    let datas = rpc.MessageSequence.create();
    let replys = rpc.MessageSequence.create();
    // Write parameters to data.
    if (proxy != undefined) {
      proxy.sendMessageRequest(1, datas, replys, options, sendRequestCallback);
    }
   ```

5. Tear down the connection.

   If you use the FA model, call the API provided by **featureAbility** to tear down the connection when the communication is over. If you use the stage model, obtain a service instance through **Context**, and then call the API provided by **featureAbility** to tear down the connection.

   ```ts
    // If the FA model is used, import featureAbility from @kit.AbilityKit.
    // import { featureAbility } from "@kit.AbilityKit";
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    function disconnectCallback() {
      hilog.info(0x0000, 'testTag', 'disconnect ability done');
    }
    // Use this method to disconnect from the ability in the FA model.
    // featureAbility.disconnectAbility(connectId, disconnectCallback);

    let proxy: rpc.IRemoteObject | undefined;
    let connectId: number;

    // Bind an ability on a single device.
    let want: Want = {
      // Enter the bundle name and ability name.
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
    // Use this method to connect to the ability in the FA model.
    // connectId = featureAbility.connectAbility(want, connect);

    connectId = this.context.connectServiceExtensionAbility(want,connect);

    this.context.disconnectServiceExtensionAbility(connectId);
   ```

##  

 

-  
