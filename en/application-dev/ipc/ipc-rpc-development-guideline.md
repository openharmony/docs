# IPC and RPC Development (ArkTS)

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=a058faf9554a4e15f6e3d83e8300a629fbc557db translatedAt=2026-08-04T13:29:15.897Z pushedAt=2026-08-05T06:56:22.419Z -->

## When to Use

IPC/RPC is used to implement object communication across processes (one-to-one mapping between the client proxy and the server stub).

## How to Develop

> **NOTE**
>
> - Before performing IPC & RPC inter-process communication, you need to obtain the proxy object of the server through Ability Kit.
>
> - Third-party applications do not support implementing inter-process communication on their own. A third-party application can only connect to the **ServiceExtensionAbility** provided by the system through [connectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability), and communicate with the [ServiceExtensionAbility](../application-models/extensionability-overview.md) through the returned proxy, thereby achieving communication between the third-party application and the system service.
>
> - Starting from API version 20, on 2-in-1 devices, you can use the **AppServiceExtensionAbility** component to provide background service capabilities for applications. Third-party applications can connect to **AppServiceExtensionAbility** through [connectAppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20), and communicate with [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) through the returned proxy object, thereby achieving communication between two third-party applications. For detailed development steps, see [AppServiceExtensionAbility](../application-models/app-service-extension-ability.md#connecting-to-a-background-service).
>
> - Third-party applications can also implement inter-process communication by [subscribing to common events in dynamic mode](../basic-services/common-event/common-event-subscription.md).
>
> - The complete IPC & RPC communication development process involves the implementation of the system **ServiceExtensionAbility**, so this guide only provides sample code for the client.

<!--Del-->

### Server Implementation

Create a ServiceExtensionAbility as follows:

1. In the **ets** directory of a module in the project, right-click and choose **New > Directory** to create a directory named **ServiceExtAbility**.

2. In the **ServiceExtAbility** directory, right-click and choose **New > ArkTS File** to create a file named **ServiceExtAbility.ets**.

    ```txt
    ├── ets
    │ ├── ServiceExtAbility
    │ │   ├── ServiceExtAbility.ets
    └
    ```

3. In the **ServiceExtAbility.ets** file, import the dependency package of the ServiceExtensionAbility. The custom class inherits the ServiceExtensionAbility and implements lifecycle callbacks. Define a stub class that inherits from [rpc.RemoteObject](../reference/apis-ipc-kit/js-apis-rpc.md#remoteobject) and implement the [onRemoteMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#onremotemessagerequest9) method to process requests from the client. In the **onConnect** lifecycle callback, create the defined stub object and return it.

> **NOTE**
>
> - The **ServiceExtensionAbility** module is only open to system applications. When using this module, you need to manually replace the SDK in the current project with the full SDK. To use the full SDK, you need to manually obtain it from the image site and replace it in DevEco Studio. For details, see [Switching to Full SDK](../faqs/full-sdk-switch-guide.md).

  <!-- @[service_impl](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/IPC/IPC_sendMessage/IPC_Stub/entry/src/main/ets/ServiceExtAbility/ServiceExtAbility.ets) -->

  ``` TypeScript
  import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  // Define the server.
  class Stub extends rpc.RemoteObject {
    constructor(descriptor: string) {
      super(descriptor);
    }
    onRemoteMessageRequest(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence,
      option: rpc.MessageOption): boolean | Promise<boolean> {
      // The server stub executes the corresponding processing based on the request code.
      if (code == 1) {
        let str = data.readString();
        hilog.info(0x0000, 'testTag', 'stub receive str is ' + str);
        // The server sends the request processing result to the client.
        reply.writeString('hello rpc');
        return true;
      } else {
        hilog.info(0x0000, 'testTag', 'stub unknown code is ' + code);
        return false;
      }
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
      return new Stub('IPCStubTest');
    }
  
    onDisconnect(want: Want): void {
      hilog.info(0x0000, 'testTag', 'onDisconnect');
    }
  
    onDestroy(): void {
      hilog.info(0x0000, 'testTag', 'onDestroy');
    }
  }
  ```

<!--DelEnd-->

### Client Implementation

1. Create a **want** variable, and specify the bundle name and component name of the application where the ability is located.

2. Create a **connect** variable, and specify the callback that is called when the binding is successful, the binding fails, or the ability is disconnected.

3. Connect to the service, obtain the service proxy, and register the death listener.

4. Send a message from the client to the server.

5. Tear down the connection and remove the death listener of the service proxy when the communication is over.

> **NOTE**
>
> - In the sample code provided in this topic, **this.getUIContext().getHostContext()** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

  In the IPC (inter-process communication on the same device) scenario, the following is an example of the client:

  Import dependencies and define required variables.

  <!-- @[front-end_dependencies](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/IPC/IPC_sendMessage/IPC_Client/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  import { BusinessError } from '@kit.BasicServicesKit';
  import { Want, common } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { PromptAction  } from '@kit.ArkUI';
  import { JSON } from '@kit.ArkTS';
  
  let proxy: rpc.IRemoteObject | undefined;
  let connectId: number | undefined;
  
  // Death notification
  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server is dead');
    }
  }
  let deathRecipient = new MyDeathRecipient();
  ```

  Connect to the service, obtain the proxy object, send information to the server, and tear down the connection when the communication is over.

  <!-- @[function_implement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/IPC/IPC_sendMessage/IPC_Client/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  // Connect to the service.
  function connectAbility(context:common.UIAbilityContext, promptAction: PromptAction) {
    hilog.info(0x00000, 'testTag', 'begin to connect Ability');
    let want: Want = {
      bundleName: 'com.example.ipc_stub',
      abilityName: 'ServiceAbility',
    };
    let connect: common.ConnectOptions = {
      onConnect: (elementName, remoteProxy) => {
        hilog.info(0x00000, 'testTag', 'onConnect. elementName is :' + JSON.stringify(elementName));
        proxy = remoteProxy;
        // Register a death listener on the client.
        try {
          proxy.registerDeathRecipient(deathRecipient, 0);
          hilog.info(0x00000, 'testTag', 'registerDeathRecipient success');
        } catch (err) {
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          hilog.error(0x0000, 'testTag', 'register failed, code is ' + code + ', message is ' + message);
        }
        // ...
      },
  
      onDisconnect: (elementName) => {
        hilog.info(0x0000, 'testTag', 'onDisconnect. elementName is ' + JSON.stringify(elementName));
        // Remove the death listener from the client.
        try {
          proxy?.unregisterDeathRecipient(deathRecipient, 0);
          hilog.info(0x00000, 'testTag', 'unregisterDeathRecipient success');
        } catch (err) {
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          hilog.error(0x0000, 'testTag', 'unregister failed, code is ' + code + ', message is ' + message);
        }
        proxy = undefined;
        // ...
      },
  
      onFailed: (code: number) => {
        hilog.info(0x0000, 'testTag', 'onFailed. code is ' + code);
        // ...
      },
    }
  
    try {
      connectId = context.connectServiceExtensionAbility(want, connect);
      hilog.info(0x00000, 'testTag', 'begin to connect Ability end');
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', 'connectAbility failed, code is ' + code + ', message is ' + message);
    }
  }
  
  // Close the connection.
  function disconnectAbility(context: common.UIAbilityContext) {
    hilog.info(0x00000, 'testTag', 'begin to disconnect Ability. connectId is ' + connectId);
    if (connectId != undefined) {
      try {
        context.disconnectServiceExtensionAbility(connectId);
      } catch (err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        hilog.error(0x0000, 'testTag', 'disconnect failed, code is ' + code + ', message is ' + message);
      }
    }
  }
  
  // Send a message.
  async function sendString(promptAction: PromptAction) : Promise <void> {
    hilog.info(0x00000, 'testTag', 'begin to send String');
    let option = new rpc.MessageOption();
    let data = rpc.MessageSequence.create();
    let reply = rpc.MessageSequence.create();
    // Write parameters in data. The following uses the string as an example.
    data.writeString('hello world');
    if (proxy != undefined) {
      await proxy.sendMessageRequest(1, data, reply, option)
        .then((result: rpc.RequestResult) => {
          if (result.errCode != 0) {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode is ' + result.errCode);
          }
          // Read the result from result.reply.
          let str = result.reply.readString();
          hilog.info(0x0000, 'testTag', 'sendMessageRequest receive str is ' + str);
          // ...
        })
        .catch((e: Error) => {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, error is ' + JSON.stringify(e));
          // ...
        })
        .finally(() => {
          data.reclaim();
          reply.reclaim();
        })
    } else {
      hilog.error(0x0000, 'testTag', 'proxy is invalid');
      // ...
    }
    hilog.info(0x0000, 'testTag', 'sendString end');
  }
  ```

  In the RPC (inter-process communication across devices) scenario, the following is an example of a client:

  Import dependencies and define required variables.

  <!-- @[rpc_front-end_dependencies](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/IPC/RPC_sendMessage/RPC_Client/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  import { BusinessError } from '@kit.BasicServicesKit';
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { distributedDeviceManager } from '@kit.DistributedServiceKit';
  import { abilityAccessCtrl, PermissionRequestResult, common, Want} from '@kit.AbilityKit';
  import { JSON } from '@kit.ArkTS';
  import { PromptAction  } from '@kit.ArkUI';
  
  let proxy: rpc.IRemoteObject | undefined;
  let connectId: number | undefined;
  let dmInstance: distributedDeviceManager.DeviceManager;
  let deviceList: Array<distributedDeviceManager.DeviceBasicInfo> | undefined;
  let deviceId: string| undefined;
  
  // Death notification
  class MyDeathRecipient implements rpc.DeathRecipient {
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server is dead');
    }
  };
  let deathRecipient = new MyDeathRecipient();
  ```

Obtain the [permission for multi-device collaboration](../security/AccessToken/permissions-for-all-user.md#ohospermissiondistributed_datasync), obtain the peer device ID (unique network identifier of the device, which can be retrieved via **distributedDeviceManager**) in the networking scenario, connect to the service, acquire the proxy object, and send messages to the server. Disconnect once the communication between the proxy object and server ends.

  <!-- @[rpc_function_implement](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/IPC/RPC_sendMessage/RPC_Client/entry/src/main/ets/pages/Index.ets) -->

  ``` TypeScript
  // Obtain the permission.
  function getPermission(context:common.UIAbilityContext) {
    hilog.info(0x00000, 'testTag', 'begin to requestPermissions');
    try {
      let atManager: abilityAccessCtrl.AtManager = abilityAccessCtrl.createAtManager();
      atManager.requestPermissionsFromUser(context, ['ohos.permission.DISTRIBUTED_DATASYNC'],
        (err: BusinessError, data: PermissionRequestResult) => {
        if (err) {
          hilog.error(0x0000, 'testTag', 'requestPermissions failed, code is ' + err.code);
          hilog.error(0x0000, 'testTag', 'requestPermissions failed, message is ' + err.message);
        } else {
          hilog.info(0x0000, 'testTag', 'requestPermissions success, result is ' + JSON.stringify(data));
          hilog.info(0x0000, 'testTag', 'data permissions is ' + data.permissions);
          hilog.info(0x0000, 'testTag', 'data authResults is ' + data.authResults);
          hilog.info(0x0000, 'testTag', 'data dialogShownResults is ' + data.dialogShownResults);
        }
      });
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', 'getPermission failed, code is ' + code + ', message is ' + message);
    }
  }
  
  // Obtain the peer device information.
  function getDeviceId(promptAction: PromptAction) {
    hilog.info(0x00000, 'testTag', 'begin to getDeviceId');
    try {
      dmInstance = distributedDeviceManager.createDeviceManager('com.example.rpc_client');
      hilog.info(0x0000, 'testTag', 'createDeviceManager success');
      deviceList = dmInstance.getAvailableDeviceListSync();
      hilog.info(0x0000, 'testTag', 'deviceList is ' + JSON.stringify(deviceList));
      if (deviceList.length !== 0) {
        deviceId = deviceList[0].networkId;
        hilog.info(0x0000, 'testTag', 'networkId is ' + deviceId);
        // ...
      }
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', 'getDeviceId failed, code is ' + code + ', message is ' + message);
      // ...
    }
  }
  
  // Connect to the service.
  function connectAbility(context:common.UIAbilityContext, promptAction: PromptAction) {
    hilog.info(0x00000, 'testTag', 'begin to connect Ability');
    let want: Want = {
      bundleName: 'com.example.rpc_stub',
      abilityName: 'ServiceAbility',
      deviceId: deviceId,
    }
  
    let connect: common.ConnectOptions = {
      onConnect: (elementName, remoteProxy) => {
        hilog.info(0x00000, 'testTag', 'onConnect. elementName is ' + JSON.stringify(elementName));
        proxy = remoteProxy;
        // Register a death listener on the client.
        try {
          proxy.registerDeathRecipient(deathRecipient, 0);
          hilog.info(0x00000, 'testTag', 'registerDeathRecipient success');
        } catch (err) {
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          hilog.error(0x0000, 'testTag', 'register failed, code is ' + code + ', message is ' + message);
        };
        // ...
      },
      onDisconnect: (elementName) => {
        hilog.info(0x0000, 'testTag', 'onDisconnect. elementName is ' + JSON.stringify(elementName));
        // Remove the death listener from the client.
        try {
          proxy?.unregisterDeathRecipient(deathRecipient, 0);
          hilog.info(0x00000, 'testTag', 'unregisterDeathRecipient success');
        } catch (err) {
          let code = (err as BusinessError).code;
          let message = (err as BusinessError).message;
          hilog.error(0x0000, 'testTag', 'unregister failed, code is ' + code + ', message is ' + message);
        }
        proxy = undefined;
        // ...
      },
      onFailed: (code: number) => {
        hilog.info(0x0000, 'testTag', 'onFailed. code is ' + code);
        // ...
      },
    }
  
    try {
      connectId = context.connectServiceExtensionAbility(want, connect);
    } catch (err) {
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      hilog.error(0x0000, 'testTag', 'connectService failed, code is ' + code + ', message is ' + message);
    }
  }
  
  // Close the connection.
  function disconnectAbility(context: common.UIAbilityContext) {
    hilog.info(0x00000, 'testTag', 'begin to disconnect Ability');
    if (connectId != undefined) {
      try {
        context.disconnectServiceExtensionAbility(connectId);
      } catch (err) {
        let code = (err as BusinessError).code;
        let message = (err as BusinessError).message;
        hilog.error(0x0000, 'testTag', 'disconnectService failed, code is ' + code + ', message is ' + message);
      }
    }
  }
  
  // Send a message.
  async function sendString(promptAction: PromptAction) : Promise <void> {
    hilog.info(0x00000, 'testTag', 'begin to send string');
    let option = new rpc.MessageOption();
    let data = rpc.MessageSequence.create();
    let reply = rpc.MessageSequence.create();
    // Write parameters in data. The following uses the string as an example.
    data.writeString('hello world');
  
    if (proxy != undefined) {
      await proxy.sendMessageRequest(1, data, reply, option)
        .then((result: rpc.RequestResult) => {
          if (result.errCode != 0) {
            hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, errCode is ' + result.errCode);
          }
          // Read the result from result.reply.
          let str = result.reply.readString();
          hilog.info(0x0000, 'testTag', 'sendMessageRequest receive str is ' + str);
          // A dialog box is displayed, indicating that the message is sent successfully.
          // ...
        })
        .catch((e: Error) => {
          hilog.error(0x0000, 'testTag', 'sendMessageRequest failed, error is ' + JSON.stringify(e));
          // A dialog box is displayed, indicating that the message fails to be sent.
          // ...
        })
        .finally(() => {
          data.reclaim();
          reply.reclaim();
        })
    } else {
      hilog.error(0x0000, 'testTag', 'proxy is invalid');
      // A dialog box is displayed, indicating that the message fails to be sent.
      // ...
    }
  }
  ```

<!--Del-->

In the FA model, the [connectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilityconnectability7) API is used to connect to an ability.

After IPC is complete, call [disconnectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilitydisconnectability7) to disable the connection. The **connectId** is saved when the service is connected.

<!--code_no_check_fa-->

``` TypeScript
import { featureAbility } from '@kit.AbilityKit';

// Save the connection ID, which will be used when the ability is disconnected.
let connectId = featureAbility.connectAbility(want, connect);

function disconnectCallback() {
  hilog.info(0x0000, 'testTag', 'disconnect ability done');
}
// Use the connectId saved when the service is successfully connected to disable the connection.
featureAbility.disconnectAbility(connectId, disconnectCallback);
```

<!--DelEnd-->

## Sample

> **NOTE**
>
> - The following complete examples involve **ServiceExtensionAbility** and require the use of the full SDK. Before referencing an example, read the README of the example to complete the corresponding configuration before compiling.

For the end-to-end complete example of IPC and RPC development, see the following:

- [Complete IPC Example - Using Parcelable/ArrayBuffer](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/SystemFeature/IPC/ObjectTransfer)

- [Complete IPC Example - Passing Strings and Using Death Listener](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/IPC/IPC_sendMessage)

- [Complete RPC Example - Passing Strings and Using Death Listener](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/IPC/RPC_sendMessage)