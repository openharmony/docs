# IPC and RPC Development (ArkTS)
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong2-->
<!--Adviser: @zhang_yixin13-->

## When to Use

IPC/RPC is used to implement object communication across processes (one-to-one mapping between the client proxy and the server stub).

## How to Develop

> **NOTE**
>
> - Currently, third-party applications cannot implement ServiceExtensionAbility. The UIAbility component of a third-party application can connect to the ServiceExtensionAbility provided by the system through [Context](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).
>
> - Application scenario constraints: The client is a third-party or system application, and the server is a system application or service.

### Creating ServiceExtensionAbility to Implement the Server

Create a ServiceExtensionAbility as follows:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **ServiceExtAbility**.

2. In the **ServiceExtAbility** directory, right-click and choose **New > ArkTS File** to create a file named **ServiceExtAbility.ets**.

    ```
      ├── ets
      │ ├── ServiceExtAbility
      │ │   ├── ServiceExtAbility.ets
      └
    ```

3. In the **ServiceExtAbility.ets** file, import the dependency package of the ServiceExtensionAbility. The custom class inherits the ServiceExtensionAbility and implements lifecycle callbacks. Define a stub class that inherits from [rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject) and implement the [onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9) method to process requests from the client. In the **onConnect** lifecycle callback, create the defined stub object and return it.

   ```ts
    import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // Define the server.
    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      // The service overrides the onRemoteMessageRequest method to process the client request.
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // Process requests sent from the client based on the code.
        switch (code) {
          case 1:
            {
              // Read data based on the client write sequence. For details, see the service logic.
              // This is an example of sending information from the client to the server.
              data.readString();
              reply.writeString('huichuanxinxi');
            }
        }
        return true;
      }
    }

    // Define the background service.
    export default class ServiceAbility extends ServiceExtensionAbility {
      onCreate(want: Want): void {
        hilog.info(0x0000, 'testTag', 'onCreate');
      }

      onRequest(want: Want, startId: number): void {
        hilog.info(0x0000, 'testTag', 'onRequest');
      }

      onConnect(want: Want): rpc.RemoteObject {
        hilog.info(0x0000, 'testTag', 'onConnect');
        // Return a stub object, through which the client can communicate with the ServiceExtensionAbility.
        return new Stub('rpcTestAbility');
      }

      onDisconnect(want: Want): void {
        hilog.info(0x0000, 'testTag', 'onDisconnect');
      }

      onDestroy(): void {
        hilog.info(0x0000, 'testTag', 'onDestroy');
      }
    }
   ```

### Connecting to the Service and Obtaining the Service Proxy

**Creating want and connect**

1. Create a **want** variable, and specify the bundle name and component name of the application where the ability is located. If cross-device communication is involved, also specify the network ID of the target device, which can be obtained through distributedDeviceManager.

2. Create a **connect** variable, and specify the callback that is called when the binding is successful, the binding fails, or the ability is disconnected.

  In IPC, create the variables **want** and **connect**.
  ```ts
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    let proxy: rpc.IRemoteObject | undefined;

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
  ```

  In RPC, create the variables **want** and **connect**.
  ```ts 
    import { Want, common } from '@kit.AbilityKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let dmInstance: distributedDeviceManager.DeviceManager | undefined;
    let proxy: rpc.IRemoteObject | undefined;
    let deviceList: Array<distributedDeviceManager.DeviceBasicInfo> | undefined;
    let networkId: string | undefined;
    let want: Want | undefined;
    let connect: common.ConnectOptions | undefined;

    try{
      dmInstance = distributedDeviceManager.createDeviceManager("ohos.rpc.test");
    } catch(error) {
      let err: BusinessError = error as BusinessError;
      hilog.error(0x0000, 'testTag', 'createDeviceManager errCode:' + err.code + ', errMessage:' + err.message);
    }

    // Use distributedDeviceManager to obtain the network ID of the target device.
    if (dmInstance != undefined) {
      try {
        deviceList = dmInstance.getAvailableDeviceListSync();
        if (deviceList.length !== 0) {
          networkId = deviceList[0].networkId;
          want = {
            bundleName: "ohos.rpc.test.server",
            abilityName: "ohos.rpc.test.service.ServiceAbility",
            deviceId: networkId,
          };
          connect = {
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
        }
      }catch(error) {
        let err: BusinessError = error as BusinessError;
        hilog.error(0x0000, 'testTag', 'createDeviceManager err:' + err);
      }
    }
  ```

**Connection Service**

  In the FA model, the [connectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilityconnectability7) API is used to connect to an ability.

  <!--code_no_check_fa-->
  ```ts
    import { featureAbility } from '@kit.AbilityKit';

    // Save the connection ID, which will be used when the ability is disconnected.
    let connectId = featureAbility.connectAbility(want, connect);
  ```

  In the stage model, the [connectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability) API of **common.UIAbilityContext** is used to connect to an ability.
  In the sample code provided in this topic, **this.getUIContext().getHostContext()** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

  <!--code_no_check-->
  ```ts

    let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
    // Save the connection ID, which will be used when the ability is disconnected.
    let connectId = context.connectServiceExtensionAbility(want,connect);
   ```

### Sending Information from Client to Server

   After the service is successfully connected, you can use the **onConnect** callback to obtain the proxy object of the server. Then, use the proxy to call the [sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9-2) method to initiate a request. When the server processes the request and returns data, you can receive the result returned by a promise contract (used to indicate the success or failure result value of an asynchronous operation).

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    // The proxy in this code snippet is obtained from the onConnect callback after the service is successfully connected.
    let proxy: rpc.IRemoteObject | undefined;

    // Use the promise contract.
    let option = new rpc.MessageOption();
    let data = rpc.MessageSequence.create();
    let reply = rpc.MessageSequence.create();
    // Write parameters in data. The following uses the string as an example.
    data.writeString("hello world");

    if (proxy != undefined) {
      proxy.sendMessageRequest(1, data, reply, option)
        .then((result: rpc.RequestResult) => {
          if (result.errCode != 0) {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode: ' + result.errCode);
            return;
          }
          // Read the result from result.reply.
          // The following is an example of creating a ServiceExtensionAbility on the server.
          result.reply.readString();
        })
        .catch((e: Error) => {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest got exception: ' + e);
        })
        .finally(() => {
          data.reclaim();
          reply.reclaim();
        })
    }
   ```

### Server Handling of Client Requests

   Call **onConnect()** to return a stub object inherited from [rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject), and implement [onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9) for the object to process requests sent from the client.

   ```ts
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    class Stub extends rpc.RemoteObject {
      constructor(descriptor: string) {
        super(descriptor);
      }
      onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption): boolean | Promise<boolean> {
        // The server stub executes the corresponding processing based on the request code.
        if (code == 1) {
          let str = data.readString();
          hilog.info(0x0000, 'testTag', 'stub receive str : ' + str);
          // The server sends the request processing result to the client.
          reply.writeString("hello rpc");
          return true;
        } else {
            hilog.info(0x0000, 'testTag', 'stub unknown code: ' + code);
            return false;
        }
      }
    }
   ```

### Terminating the Connection

   After IPC is complete, the FA model calls [disconnectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilitydisconnectability7) to disable the connection. The **connectId** is saved when the service is connected.

  <!--code_no_check_fa-->
  ```ts
    import { featureAbility } from "@kit.AbilityKit";
    import { hilog } from '@kit.PerformanceAnalysisKit';

    function disconnectCallback() {
      hilog.info(0x0000, 'testTag', 'disconnect ability done');
    }
    // Use the connectId saved when the service is successfully connected to disable the connection.
    featureAbility.disconnectAbility(connectId, disconnectCallback);
   ```

   The **common.UIAbilityContext** provides the [disconnectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#disconnectserviceextensionability-1) API to disconnect from the service. The **connectId** is saved when the service is connected.
   In the sample code provided in this topic, **this.getUIContext().getHostContext()** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

  <!--code_no_check-->
  ```ts
    let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
    
    // Use the connectId saved when the service is successfully connected to disable the connection.
    context.disconnectServiceExtensionAbility(connectId);
   ```

## Sample

For the end-to-end complete example of IPC and RPC development, see the following:

- [Complete IPC Example - Using Parcelable/ArrayBuffer](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/IPC/ObjectTransfer)
