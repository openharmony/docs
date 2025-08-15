# Subscribing to State Changes of a Remote Object
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--SE: @zhaopeng_gitee-->
<!--TSE: @maxiaorong2-->

IPC/RPC allows you to subscribe to the state changes of a remote stub object. When the remote stub object dies, a death notification will be sent to your local proxy. To subscribe to death notifications, you need to call the [registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1) API. To unsubscribe from death notifications, call the [unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1) API.

To be specific, you need to inherit the death notification class [DeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#deathrecipient) and implement the [onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied) method to clear resources. This callback is invoked when the process accommodating the remote stub object exits or the DSoftBus connection on which RPC depends is disabled.

> **NOTE**
> - The proxy object must first subscribe to death notifications of the stub object. If the stub object is in the normal state, the proxy object can cancel the subscription as required.
> - If the process of the stub object exits or the DSoftBus connection on which RPC depends is disabled, the [onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied) method customized by the proxy object will be automatically triggered.

## When to Use

IPC/RPC subscription is applicable to the following scenarios:<br>
1. In IPC, the proxy object needs to detect the status of the process hosting the remote stub object.
2. In RPC, the proxy object needs to detect the status of the process hosting the remote stub object, or the DSoftBus connection status on which RPC depends.
When the proxy detects the death of the remote stub object, proxy objects and clear local resources should be cleared.
> **NOTE**
> 
> Subscription to death notifications of anonymous stub objects (not registered with SAMgr) is supported in IPC, but not in RPC.

## **Development Using ArkTS APIs**

> **NOTE**
>
> - The sample code in this topic implements communication between system applications across processes.
>
> - Application scenario constraints: The client is a third-party or system application, and the server is a system application or service.

| API                                                      | Return Value Type| Description                                                    |
| ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| [registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1) | void       | Registers a callback for receiving death notifications of the remote object. This method should be called on the proxy side.|
| [unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1) | void       | Unregisters from the callback used to receive death notifications of the remote object.                        |
| [onRemoteDied](../reference/apis-ipc-kit/js-apis-rpc.md#onremotedied) | void       | Called when the process accommodating the remote stub object dies after the proxy successfully registers the death notification.|

### Sample Code

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
    }
  ```

  In the FA model, the [connectAbility](../reference/apis-ability-kit/js-apis-ability-featureAbility.md#featureabilityconnectability7) API is used to connect to an ability.

  <!--code_no_check_fa-->
  ```ts
    import { featureAbility } from '@kit.AbilityKit';

    // Save the connection ID, which will be used for the subsequent service disconnection.
    let connectId = featureAbility.connectAbility(want, connect);
  ```

  In the stage model, the [connectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability) API of **common.UIAbilityContext** is used to connect to an ability.
  In the sample code provided in this topic, **this.context** is used to obtain **UIAbilityContext**, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

  <!--code_no_check-->
  ```ts
    let context: common.UIAbilityContext = this.getUIContext().getHostContext(); // UIAbilityContext
    // Save the connection ID, which will be used for the subsequent service disconnection.
    let connectId = context.connectServiceExtensionAbility(want,connect);
   ```

  After the service is successfully connected, the proxy object in the **onConnect** callback can be assigned a value You can call the [registerDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#registerdeathrecipient9-1) method of the proxy object to register the death callback. When the proxy object is no longer used, you can call the [unregisterDeathRecipient](../reference/apis-ipc-kit/js-apis-rpc.md#unregisterdeathrecipient9-1) method to deregister the death callback.

  ```ts
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let proxy: rpc.IRemoteObject | undefined;

  class MyDeathRecipient implements rpc.DeathRecipient{
    onRemoteDied() {
      hilog.info(0x0000, 'testTag', 'server died');
    }
  }
  let deathRecipient = new MyDeathRecipient();
  if (proxy != undefined) {
    // The value 0 is a reserved flag for the death notification of the death listener. It has no actual meaning.
    proxy.registerDeathRecipient(deathRecipient, 0);
    proxy.unregisterDeathRecipient(deathRecipient, 0);
  }
  ```

## Reverse Death Notification (Anonymous Stub)

Forward dead notification is a mechanism that allows the proxy to detect death notifications of the stub. To achieve reverse dead notification, you can leverage the forward dead notification mechanism. Suppose there are two processes, A (the process hosting the original stub) and B (the process hosting the original proxy). After obtaining the proxy object of process A, process B creates an anonymous stub object (that is, a stub object not registered with SAMgr), which can be called a callback stub. Then, process B calls [sendMessageRequest](../reference/apis-ipc-kit/js-apis-rpc.md#sendmessagerequest9-2) to send the callback stub to the original stub of process A. Then, process A obtains the callback proxy of process B. As long as the death notification is registered with the callback proxy, when process B (callback stub) dies or the DSoftBus connection on which RPC depends is disabled, the callback proxy can detect the death and notify process A (original stub). In this way, the reverse death notification is implemented.

> **NOTE**
> - Reverse death notification can only be used for cross-process communication within a device.
> - When an anonymous stub object is not referenced by any proxy, the object is automatically released.
