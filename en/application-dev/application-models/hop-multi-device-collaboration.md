# Multi-device Collaboration


## When to Use

Multi-device collaboration involves the following scenarios:

- [Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)](#starting-uiability-or-serviceextensionability-across-devices-no-data-returned)

- [Starting UIAbility Across Devices (Data Returned)](#starting-uiability-across-devices-data-returned)

- [Connecting to ServiceExtensionAbility Across Devices](#connecting-to-serviceextensionability-across-devices)

- [Using Cross-Device Call](#using-cross-device-call)


## Multi-Device Collaboration Process

The figure below shows the multi-device collaboration process.

**Figure 1** Multi-device collaboration process

![hop-multi-device-collaboration](figures/hop-multi-device-collaboration.png)


## Constraints

- Since multi-device collaboration mission management is not available, you can obtain the device list by developing system applications. Third-party applications cannot access the device list.

- Multi-device collaboration must comply with [Inter-Device Component Startup Rules](component-startup-rules.md#inter-device-component-startup-rules).

- For better user experience, you are advised to use the [want](../reference/apis-ability-kit/js-apis-app-ability-want.md) parameter to transmit data smaller than 100 KB.


## Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)

On device A, touch the **Start** button provided by the initiator application to start a specified [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) or [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md) on device B.


### Available APIs

**Table 1** Cross-device startup APIs

| **API**| **Description**|
| -------- | -------- |
| startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void; | Starts a UIAbility or ServiceExtensionAbility. This API uses an asynchronous callback to return the result.|
| stopServiceExtensionAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void; | Stops a ServiceExtensionAbility. This API uses an asynchronous callback to return the result.|
| stopServiceExtensionAbility(want: Want): Promise&lt;void&gt;; | Stops a ServiceExtensionAbility. This API uses a promise to return the result.|


### How to Develop

1. Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

3. Obtain the device ID of the target device.

    ```ts
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const TAG: string = '[Page_CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    let dmClass: distributedDeviceManager.DeviceManager;

    function initDmClass(): void {
      // createDeviceManager is a system API.
      try {
        dmClass = distributedDeviceManager.createDeviceManager('com.samples.stagemodelabilitydevelop');
        hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass) ?? '');
      } catch (err) {
        hilog.error(DOMAIN_NUMBER, TAG, 'createDeviceManager err: ' + JSON.stringify(err));
      }
    }

    function getRemoteDeviceId(): string | undefined {
      if (typeof dmClass === 'object' && dmClass !== null) {
        let list = dmClass.getAvailableDeviceListSync();
        hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
        if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
          hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
          return;
        }
        if (list.length === 0) {
          hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
          return;
        }
        return list[0].networkId;
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
        return;
      }
    }
    ```

4. Set the target component parameters, and call [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) to start a [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) or [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md).

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { Want, common } from '@kit.AbilityKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { PromptAction } from '@kit.ArkUI';

    const TAG: string = '[Page_CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;
    let dmClass: distributedDeviceManager.DeviceManager;

    function getRemoteDeviceId(): string | undefined {
      if (typeof dmClass === 'object' && dmClass !== null) {
        let list = dmClass.getAvailableDeviceListSync();
        hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
        if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
          hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
          return;
        }
        if (list.length === 0) {
          hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
          return;
        }
        return list[0].networkId;
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
        return;
      }
    };

    @Entry
    @Component
    struct Page_CollaborateAbility {
      private context = this.getUIContext().getHostContext();
      let promptAction: promptAction = uiContext.getPromptAction;
      build() {
        Column() {
          //...
          List({ initialIndex: 0 }) {
            //...
            ListItem() {
              Row() {
                //...
              }
              .onClick(() => {
                let want: Want = {
                  deviceId: getRemoteDeviceId(),
                  bundleName: 'com.samples.stagemodelabilityinteraction',
                  abilityName: 'CollaborateAbility',
                  moduleName: 'entry', // moduleName is optional.
                };
                // context is the AbilityContext of the initiator UIAbility.
                this.context.startAbility(want).then(() => {
                  promptAction.showToast({
                    message: 'SuccessfulCollaboration'
                  });
                }).catch((err: BusinessError) => {
                  hilog.error(DOMAIN_NUMBER, TAG, `startAbility err: ` + JSON.stringify(err));
                });
              })
            }
            //...
          }
          //...
        }
        //...
      }
    }
    ```

5. Call [stopServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextstopserviceextensionability-1) to stop the [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md) when it is no longer required on device B. (This API cannot be used to stop a [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md). Users must manually stop a UIAbility through mission management.)

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { Want, common } from '@kit.AbilityKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';

    const TAG: string = '[Page_CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;
    let dmClass: distributedDeviceManager.DeviceManager;

    function getRemoteDeviceId(): string | undefined {
      if (typeof dmClass === 'object' && dmClass !== null) {
        let list = dmClass.getAvailableDeviceListSync();
        hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
        if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
          hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
          return;
        }
        if (list.length === 0) {
          hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
          return;
        }
        return list[0].networkId;
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
        return;
      }
    };

    @Entry
    @Component
    struct Page_CollaborateAbility {
      private context = this.getUIContext().getHostContext();

      build() {
        // ...
        Button('stopServiceExtensionAbility')
          .onClick(() => {
            let want: Want = {
              deviceId: getRemoteDeviceId(),
              bundleName: 'com.example.myapplication',
              abilityName: 'FuncAbility',
              moduleName: 'module1', // moduleName is optional.
            }
            // Stop the ServiceExtensionAbility started by calling startAbility().
            this.context.stopServiceExtensionAbility(want).then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, "stop service extension ability success")
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `stop service extension ability err is ` + JSON.stringify(err));
            })
          })
      }
    }
    ```

## Starting UIAbility Across Devices (Data Returned)

On device A, touch the Start button provided by the initiator application to start a specified [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) on device B. When the UIAbility on device B exits, a value is returned to the initiator application.


### Available APIs

**Table 2** APIs for starting a UIAbility across devices and returning the result data

| API| Description|
| -------- | -------- |
| startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void; | Starts a UIAbility. This API uses an asynchronous callback to return the result when the UIAbility is terminated.|
| terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;| Terminates this UIAbility. This API uses an asynchronous callback to return the result. It is used together with **startAbilityForResult**.|
| terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;; | Terminates this UIAbility. This API uses a promise to return the result. It is used together with **startAbilityForResult**.|


### How to Develop

1. Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

3. Set the target component parameters on the initiator, and call [startAbilityForResult()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilityforresult) to start the target UIAbility. **data** in the asynchronous callback is used to receive the information returned by the target UIAbility to the initiator UIAbility after the target UIAbility terminates itself. For details about how to implement **getRemoteDeviceId()**, see [Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)](#starting-uiability-or-serviceextensionability-across-devices-no-data-returned).

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { Want, common } from '@kit.AbilityKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { PromptAction } from '@kit.ArkUI';

    const DOMAIN_NUMBER: number = 0xFF00;
    const TAG: string = '[Page_CollaborateAbility]';
    let dmClass: distributedDeviceManager.DeviceManager;

    function getRemoteDeviceId(): string | undefined {
      if (typeof dmClass === 'object' && dmClass !== null) {
        let list = dmClass.getAvailableDeviceListSync();
        hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
        if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
          hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
          return;
        }
        if (list.length === 0) {
          hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
          return;
        }
        return list[0].networkId;
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
        return;
      }
    };

    @Entry
    @Component
    struct Page_CollaborateAbility {
      private context = this.getUIContext().getHostContext();
      let promptAction: promptAction = uiContext.getPromptAction;
      build() {
        Column() {
          //...
          List({ initialIndex: 0 }) {
            //...
            ListItem() {
              Row() {
                //...
              }
              .onClick(() => {
                let want: Want = {
                  deviceId: getRemoteDeviceId(),
                  bundleName: 'com.samples.stagemodelabilityinteraction',
                  abilityName: 'ServiceExtAbility',
                  moduleName: 'entry', // moduleName is optional.
                };
                // Stop the ServiceExtensionAbility started by calling startAbility().
                this.context.stopServiceExtensionAbility(want).then(() => {
                  hilog.info(DOMAIN_NUMBER, TAG, 'stop service extension ability success')
                  promptAction.showToast({
                    message: 'SuccessfullyStop'
                  });
                }).catch((err: BusinessError) => {
                  hilog.error(DOMAIN_NUMBER, TAG, `stop service extension ability err is ` + JSON.stringify(err));
                });
              })
            }
            //...
          }
          //...
        }
        //...
      }
    }
    ```

4. After the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) mission on the target device is complete, call [terminateSelfWithResult()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextterminateselfwithresult) to return the data to the initiator UIAbility.

    ```ts
    import { common } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    const TAG: string = '[Page_CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Page_CollaborateAbility {
      private context = this.getUIContext().getHostContext();

      build() {
        Column() {
          //...
          List({ initialIndex: 0 }) {
            //...
            ListItem() {
              Row() {
                //...
              }
              .onClick(() => {
                const RESULT_CODE: number = 1001;
                // context is the AbilityContext of the target UIAbility.
                this.context.terminateSelfWithResult(
                  {
                    resultCode: RESULT_CODE,
                    want: {
                      bundleName: 'ohos.samples.stagemodelabilitydevelop',
                      abilityName: 'CollaborateAbility',
                      moduleName: 'entry',
                      parameters: {
                        info: 'From Page_CollaborateAbility'
                      }
                    }
                  },
                  (err: BusinessError) => {
                    hilog.info(DOMAIN_NUMBER, TAG, `terminateSelfWithResult err: ` + JSON.stringify(err));
                  });
              })
            }
            //...
          }
          //...
        }
        //...
      }
    }
    ```

5. The initiator [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) receives the information returned by the target UIAbility and processes the information.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { Want, common } from '@kit.AbilityKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { PromptAction } from '@kit.ArkUI';

    const TAG: string = '[Page_CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;
    let dmClass: distributedDeviceManager.DeviceManager;

    function getRemoteDeviceId(): string | undefined {
      if (typeof dmClass === 'object' && dmClass !== null) {
        let list = dmClass.getAvailableDeviceListSync();
        hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
        if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
          hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
          return;
        }
        if (list.length === 0) {
          hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
          return;
        }
        return list[0].networkId;
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
        return;
      }
    };

    @Entry
    @Component
    struct Page_CollaborateAbility {
      private context = this.getUIContext().getHostContext();
      let promptAction: promptAction = uiContext.getPromptAction;
      build() {
        Column() {
          //...
          List({ initialIndex: 0 }) {
            //...
            ListItem() {
              Row() {
                //...
              }
              .onClick(() => {
                let want: Want = {
                  deviceId: getRemoteDeviceId(),
                  bundleName: 'com.samples.stagemodelabilityinteraction',
                  abilityName: 'CollaborateAbility',
                  moduleName: 'entry', // moduleName is optional.
                };
                const RESULT_CODE: number = 1001;
                // context is the UIAbilityContext of the initiator UIAbility.
                this.context.startAbilityForResult(want).then((data) => {
                  if (data?.resultCode === RESULT_CODE) {
                    // Parse the information returned by the target UIAbility.
                    let info = data.want?.parameters?.info;
                    hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(info) ?? '');
                    if (info !== null) {
                      promptAction.showToast({
                        message: JSON.stringify(info)
                      });
                    }
                  }
                }).catch((error: BusinessError) => {
                  hilog.error(DOMAIN_NUMBER, TAG, `startAbilityForResult err: ` + JSON.stringify(error));
                });
              })
            }
            //...
          }
          //...
        }
        //...
      }
    }
    ```


## Connecting to ServiceExtensionAbility Across Devices

A system application can connect to a service on another device by calling [connectServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextconnectserviceextensionability). For example, in the distributed game scenario, a tablet is used as the remote control and a smart TV is used as the display.


### Available APIs

**Table 3** APIs for cross-device connection

| API| Description|
| -------- | -------- |
| connectServiceExtensionAbility(want: Want, options: ConnectOptions): number; | Connects to a ServiceExtensionAbility.|
| disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback&lt;void&gt;): void; | Disconnects a connection. This API uses an asynchronous callback to return the result.|
| disconnectServiceExtensionAbility(connection: number): Promise&lt;void&gt;; | Disconnects a connection. This API uses a promise to return the result.|


### How to Develop

1. Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

3. (Optional) [Implement a background service](serviceextensionability.md#implementing-a-background-service-for-system-applications-only). Perform this operation only if no background service is available. This operation is available only for system applications.

4. Connect to the background service.
   - Implement the **IAbilityConnection** class. **IAbilityConnection** provides the following callbacks that you should implement: [onConnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onconnect), [onDisconnect()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#ondisconnect), and [onFailed()](../reference/apis-ability-kit/js-apis-inner-ability-connectOptions.md#onfailed). The **onConnect()** callback is invoked when a service is connected, **onDisconnect()** is invoked when a service is unexpectedly disconnected, and **onFailed()** is invoked when the connection to a service fails.
   - Set the target component parameters, including the target device ID, bundle name, and ability name.
   - Call **connectServiceExtensionAbility()** to initiate a connection.
   - Receive the service handle returned by the target device when the connection is successful.
   - Perform cross-device call and obtain the result returned by the target service.
     
    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { Want, common } from '@kit.AbilityKit';
    import { distributedDeviceManager } from '@kit.DistributedServiceKit';
    import { rpc } from '@kit.IPCKit';

    const TAG: string = '[Page_CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;
    const REQUEST_CODE = 1;
    let dmClass: distributedDeviceManager.DeviceManager;
    let connectionId: number;
    let options: common.ConnectOptions = {
      onConnect(elementName, remote): void {
        hilog.info(DOMAIN_NUMBER, TAG, 'onConnect callback');
        if (remote === null) {
          hilog.info(DOMAIN_NUMBER, TAG, `onConnect remote is null`);
          return;
        }
        let option = new rpc.MessageOption();
        let data = new rpc.MessageSequence();
        let reply = new rpc.MessageSequence();
        data.writeInt(99); // You can send data to the target application for corresponding operations.
        // @param code Indicates the service request code sent by the client.
        // @param data Indicates the {@link MessageSequence} object sent by the client.
        // @param reply Indicates the response message object sent by the remote service.
        // @param options Specifies whether the operation is synchronous or asynchronous.
        //
        // @return Returns {@code true} if the operation is successful; returns {@code false} otherwise.
        remote.sendMessageRequest(REQUEST_CODE, data, reply, option).then((ret: rpc.RequestResult) => {
          let errCode = reply.readInt(); // Receive the information (100) returned by the target device if the connection is successful.
          let msg: number = 0;
          if (errCode === 0) {
            msg = reply.readInt();
          }
          // The background service is connected.
          hilog.info(DOMAIN_NUMBER, TAG, `sendRequest msg:${msg}`);
        }).catch((error: BusinessError) => {
          hilog.info(DOMAIN_NUMBER, TAG, `sendRequest failed, ${JSON.stringify(error)}`);
        });
      },
      onDisconnect(elementName): void {
        hilog.info(DOMAIN_NUMBER, TAG, 'onDisconnect callback');
      },
      onFailed(code): void {
        hilog.info(DOMAIN_NUMBER, TAG, 'onFailed callback');
      }
    };

    function getRemoteDeviceId(): string | undefined {
      if (typeof dmClass === 'object' && dmClass !== null) {
        let list = dmClass.getAvailableDeviceListSync();
        hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
        if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
          hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
          return;
        }
        if (list.length === 0) {
          hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
          return;
        }
        return list[0].networkId;
      } else {
        hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
        return;
      }
    }

    @Entry
    @Component
    struct Page_CollaborateAbility {
      private context = this.getUIContext().getHostContext();

      build() {
        Column() {
          //...
          List({ initialIndex: 0 }) {
            //...
            ListItem() {
              Row() {
                //...
              }
              .onClick(() => {
                let want: Want = {
                  'deviceId': getRemoteDeviceId(),
                  'bundleName': 'com.samples.stagemodelabilityinteraction',
                  'abilityName': 'ServiceExtAbility'
                };
                // The ID returned after the connection is set up must be saved. The ID will be passed for service disconnection.
                connectionId = this.context.connectServiceExtensionAbility(want, options);
              })
            }
            //...
          }
          //...
        }
        //...
      }
    }
    ```

    For details about how to implement **getRemoteDeviceId()**, see [Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)](#starting-uiability-or-serviceextensionability-across-devices-no-data-returned).

5. Disconnect the connection. Use [disconnectServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextdisconnectserviceextensionability) to disconnect from the background service.

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { common } from '@kit.AbilityKit';
    import { PromptAction } from '@kit.ArkUI';

    let connectionId: number;
    const TAG: string = '[Page_CollaborateAbility]';
    const DOMAIN_NUMBER: number = 0xFF00;

    @Entry
    @Component
    struct Page_CollaborateAbility {
      private context = this.getUIContext().getHostContext();
      let promptAction: promptAction = uiContext.getPromptAction;
      build() {
        Column() {
          //...
          List({ initialIndex: 0 }) {
            //...
            ListItem() {
              Row() {
                //...
              }
              .onClick(() => {
                this.context.disconnectServiceExtensionAbility(connectionId).then(() => {
                  hilog.info(DOMAIN_NUMBER, TAG, 'disconnectServiceExtensionAbility success');
                  // The background service is disconnected.
                  promptAction.showToast({
                    message: 'SuccessfullyDisconnectBackendService'
                  })
                }).catch((error: BusinessError) => {
                  hilog.error(DOMAIN_NUMBER, TAG, 'disconnectServiceExtensionAbility failed');
                });
              })
            }
            //...
          }
          //...
        }
        //...
      }
    }
    ```


## Using Cross-Device Call

The basic principle of cross-device call is the same as that of intra-device call. For details, see [Using Call to Implement UIAbility Interaction (for System Applications Only)](uiability-intra-device-interaction.md#using-call-to-implement-uiability-interaction-for-system-applications-only).

The following describes how to implement multi-device collaboration through cross-device call.


### Available APIs

**Table 4** Call APIs

| API| Description|
| -------- | -------- |
| startAbilityByCall(want: Want): Promise&lt;Caller&gt;; | Starts a UIAbility in the foreground or background and obtains the caller object for communicating with the UIAbility.|
| on(method: string, callback: CalleeCallBack): void | Callback invoked when the CalleeAbility registers a method.|
| off(method: string): void | Callback invoked when the CalleeAbility deregisters a method.|
| call(method: string, data: rpc.Parcelable): Promise&lt;void&gt; | Sends agreed parcelable data to the CalleeAbility.|
| callWithResult(method: string, data: rpc.Parcelable): Promise&lt;rpc.MessageSequence&gt;| Sends agreed parcelable data to the CalleeAbility and obtains the agreed parcelable data returned by the CalleeAbility.|
| release(): void | Releases the caller object.|
| on(type:&nbsp;"release",&nbsp;callback:&nbsp;OnReleaseCallback):&nbsp;void | Callback invoked when the caller object is released.|


### How to Develop

1. Declare the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/AccessToken/request-user-authorization.md).

3. Create the CalleeAbility.

   For the CalleeAbility, implement the callback to receive data and the methods to marshal and unmarshal data. When data needs to be received, use [on](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#calleeon) to register a listener. When data does not need to be received, use [off](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#calleeoff) to deregister the listener.

    1. Configure the launch type of the UIAbility.

        Set **launchType** of the CalleeAbility to **singleton** in the [module.json5](../quick-start/module-configuration-file.md) file.

        | JSON Field| Description|
        | -------- | -------- |
        | "launchType"| UIAbility launch type. Set this parameter to **singleton**.|

        An example of the UIAbility configuration is as follows:

        ```json
        "abilities":[{
            "name": ".CalleeAbility",
            "srcEntry": "./ets/CalleeAbility/CalleeAbility.ets",
            "launchType": "singleton",
            "description": "$string:CalleeAbility_desc",
            "icon": "$media:icon",
            "label": "$string:CalleeAbility_label",
            "exported": true
        }]
        ```
    2. Import the **UIAbility** module.

        ```ts
        import { UIAbility } from '@kit.AbilityKit';
        ```
    3. Define the agreed parcelable data.

        The data formats sent and received by the CallerAbility and CalleeAbility must be consistent. In the following example, the data formats are number and string.

         
        ```ts
        import { rpc } from '@kit.IPCKit';

        class MyParcelable {
          num: number = 0;
          str: string = '';

          constructor(num: number, string: string) {
            this.num = num;
            this.str = string;
          }

          mySequenceable(num: number, string: string): void {
            this.num = num;
            this.str = string;
          }

          marshalling(messageSequence: rpc.MessageSequence): boolean {
            messageSequence.writeInt(this.num);
            messageSequence.writeString(this.str);
            return true;
          };

          unmarshalling(messageSequence: rpc.MessageSequence): boolean {
            this.num = messageSequence.readInt();
            this.str = messageSequence.readString();
            return true;
          };
        }
        ```
    4. Implement [Callee.on](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#calleeon) and [Callee.off](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#calleeoff).

        In the following example, the **MSG_SEND_METHOD** listener is registered in [onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityoncreate) of the UIAbility and deregistered in [onDestroy](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityondestroy). After receiving parcelable data, the application processes the data and returns the data result. You need to implement processing based on service requirements.
           
        ```ts
        import { AbilityConstant, UIAbility, Want, Caller } from '@kit.AbilityKit';
        import { hilog } from '@kit.PerformanceAnalysisKit';
        import { rpc } from '@kit.IPCKit';


        const TAG: string = '[CalleeAbility]';
        const MSG_SEND_METHOD: string = 'CallSendMsg';
        const DOMAIN_NUMBER: number = 0xFF00;

        class MyParcelable {
          num: number = 0;
          str: string = '';

          constructor(num: number, string: string) {
            this.num = num;
            this.str = string;
          };

          mySequenceable(num: number, string: string): void {
            this.num = num;
            this.str = string;
          };

          marshalling(messageSequence: rpc.MessageSequence): boolean {
            messageSequence.writeInt(this.num);
            messageSequence.writeString(this.str);
            return true;
          };

          unmarshalling(messageSequence: rpc.MessageSequence): boolean {
            this.num = messageSequence.readInt();
            this.str = messageSequence.readString();
            return true;
          };
        }

        function sendMsgCallback(data: rpc.MessageSequence): rpc.Parcelable {
          hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'CalleeSortFunc called');

          // Obtain the parcelable data sent by the CallerAbility.
          let receivedData: MyParcelable = new MyParcelable(0, '');
          data.readParcelable(receivedData);
          hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', `receiveData[${receivedData.num}, ${receivedData.str}]`);
          let num: number = receivedData.num;

          // Process the data.
          // Return the parcelable data result to the CallerAbility.
          return new MyParcelable(num + 1, `send ${receivedData.str} succeed`) as rpc.Parcelable;
        };

        export default class CalleeAbility extends UIAbility {
          caller: Caller | undefined;

          onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
            try {
              this.callee.on(MSG_SEND_METHOD, sendMsgCallback);
            } catch (error) {
              hilog.error(DOMAIN_NUMBER, TAG, '%{public}s', `Failed to register. Error is ${error}`);
            }
          }

          //...
          releaseCall(): void {
            try {
              if (this.caller) {
                this.caller.release();
                this.caller = undefined;
              }
              hilog.info(DOMAIN_NUMBER, TAG, 'caller release succeed');
            } catch (error) {
              hilog.info(DOMAIN_NUMBER, TAG, `caller release failed with ${error}`);
            }
          }

          //...
          onDestroy(): void {
            try {
              this.callee.off(MSG_SEND_METHOD);
              hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Callee OnDestroy');
              this.releaseCall();
            } catch (error) {
              hilog.error(DOMAIN_NUMBER, TAG, '%{public}s', `Failed to register. Error is ${error}`);
            }
          }
        }
        ```
     
4. Obtain the caller object and access the CalleeAbility.
    1. Import the [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) module.
      
        ```ts
        import { UIAbility } from '@kit.AbilityKit';
        ```
    2. Obtain the caller object.

        The **context** attribute of the UIAbility implements [startAbilityByCall](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall) to obtain the [Caller](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#caller) object for communication. The following example uses **this.context** to obtain the **context** attribute of the UIAbility, uses **startAbilityByCall** to start [Callee](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#callee), obtain the Caller object, and register the [onRelease](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#calleronrelease) and [onRemoteStateChange](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#calleronremotestatechange10) listeners of the CallerAbility. You need to implement processing based on service requirements.

        ```ts
        import { BusinessError } from '@kit.BasicServicesKit';
        import { Caller, common } from '@kit.AbilityKit';
        import { hilog } from '@kit.PerformanceAnalysisKit';
        import { distributedDeviceManager } from '@kit.DistributedServiceKit';
        import { PromptAction } from '@kit.ArkUI';


        const TAG: string = '[Page_CollaborateAbility]';
        const DOMAIN_NUMBER: number = 0xFF00;
        let caller: Caller | undefined;
        let dmClass: distributedDeviceManager.DeviceManager;

        function getRemoteDeviceId(): string | undefined {
          if (typeof dmClass === 'object' && dmClass !== null) {
            let list = dmClass.getAvailableDeviceListSync();
            hilog.info(DOMAIN_NUMBER, TAG, JSON.stringify(dmClass), JSON.stringify(list));
            if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
              hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: list is null');
              return;
            }
            if (list.length === 0) {
              hilog.info(DOMAIN_NUMBER, TAG, `getRemoteDeviceId err: list is empty`);
              return;
            }
            return list[0].networkId;
          } else {
            hilog.info(DOMAIN_NUMBER, TAG, 'getRemoteDeviceId err: dmClass is null');
            return;
          }
        };

        @Entry
        @Component
        struct Page_CollaborateAbility {
          private context = this.getUIContext().getHostContext();
          let promptAction: promptAction = uiContext.getPromptAction;
          build() {
            Column() {
              //...
              List({ initialIndex: 0 }) {
                //...
                ListItem() {
                  Row() {
                    //...
                  }
                  .onClick(() => {
                    let caller: Caller | undefined;
                    let context = this.context;

                    context.startAbilityByCall({
                      deviceId: getRemoteDeviceId(),
                      bundleName: 'com.samples.stagemodelabilityinteraction',
                      abilityName: 'CalleeAbility'
                    }).then((data) => {
                      if (data !== null) {
                        caller = data;
                        hilog.info(DOMAIN_NUMBER, TAG, 'get remote caller success');
                        // Register the onRelease listener of the CallerAbility.
                        caller.onRelease((msg) => {
                          hilog.info(DOMAIN_NUMBER, TAG, `remote caller onRelease is called ${msg}`);
                        });
                        hilog.info(DOMAIN_NUMBER, TAG, 'remote caller register OnRelease succeed');
                        promptAction.showToast({
                          message: 'CallerSuccess'
                        });
                        // Register the onRemoteStateChange listener of the CallerAbility.
                        try {
                          caller.onRemoteStateChange((str) => {
                            hilog.info(DOMAIN_NUMBER, TAG, 'Remote state changed ' + str);
                          });
                        } catch (error) {
                          hilog.info(DOMAIN_NUMBER, TAG, `Caller.onRemoteStateChange catch error, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
                        }
                      }
                    }).catch((error: BusinessError) => {
                      hilog.error(DOMAIN_NUMBER, TAG, `get remote caller failed with ${error}`);
                    });
                  })
                }
                //...
              }
              //...
            }
            //...
          }
        }
        ```
       
        For details about how to implement **getRemoteDeviceId()**, see [Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)](#starting-uiability-or-serviceextensionability-across-devices-no-data-returned).
   
5. Sends agreed parcelable data to the CalleeAbility.
    1. The parcelable data can be sent to the CalleeAbility with or without a return value. The method and parcelable data must be consistent with those of the CalleeAbility. The following example describes how to use [Call](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#callercall) to send data to [Callee](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#callee).
      
        ```ts
        import { UIAbility, Caller } from '@kit.AbilityKit';
        import { rpc } from '@kit.IPCKit';
        import { hilog } from '@kit.PerformanceAnalysisKit';

        const TAG: string = '[CalleeAbility]';
        const DOMAIN_NUMBER: number = 0xFF00;
        const MSG_SEND_METHOD: string = 'CallSendMsg';

        class MyParcelable {
          num: number = 0;
          str: string = '';

          constructor(num: number, string: string) {
            this.num = num;
            this.str = string;
          };

          mySequenceable(num: number, string: string): void {
            this.num = num;
            this.str = string;
          };

          marshalling(messageSequence: rpc.MessageSequence): boolean {
            messageSequence.writeInt(this.num);
            messageSequence.writeString(this.str);
            return true;
          };

          unmarshalling(messageSequence: rpc.MessageSequence): boolean {
            this.num = messageSequence.readInt();
            this.str = messageSequence.readString();
            return true;
          };
        }

        export default class EntryAbility extends UIAbility {
          // ...
          caller: Caller | undefined;

          async onButtonCall(): Promise<void> {
            try {
              let msg: MyParcelable = new MyParcelable(1, 'origin_Msg');
              if (this.caller) {
                await this.caller.call(MSG_SEND_METHOD, msg);
              }
            } catch (error) {
              hilog.info(DOMAIN_NUMBER, TAG, `caller call failed with ${error}`);
            }
          }
          // ...
        }
        ```
    2. In the following, [CallWithResult](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#callercallwithresult) is used to send data **originMsg** to the CalleeAbility and assign the data processed by the **CallSendMsg** method to **backMsg**.
      
        ```ts
        import { UIAbility, Caller } from '@kit.AbilityKit';
        import { rpc } from '@kit.IPCKit';
        import { hilog } from '@kit.PerformanceAnalysisKit';

        const TAG: string = '[CalleeAbility]';
        const DOMAIN_NUMBER: number = 0xFF00;

        const MSG_SEND_METHOD: string = 'CallSendMsg';
        let originMsg: string = '';
        let backMsg: string = '';

        class MyParcelable {
          num: number = 0;
          str: string = '';

          constructor(num: number, string: string) {
            this.num = num;
            this.str = string;
          };

          mySequenceable(num: number, string: string): void {
            this.num = num;
            this.str = string;
          };

          marshalling(messageSequence: rpc.MessageSequence): boolean {
            messageSequence.writeInt(this.num);
            messageSequence.writeString(this.str);
            return true;
          };

          unmarshalling(messageSequence: rpc.MessageSequence): boolean {
            this.num = messageSequence.readInt();
            this.str = messageSequence.readString();
            return true;
          };
        }

        export default class EntryAbility extends UIAbility {
          // ...
          caller: Caller | undefined;

          async onButtonCallWithResult(originMsg: string, backMsg: string): Promise<void> {
            try {
              let msg: MyParcelable = new MyParcelable(1, originMsg);
              if (this.caller) {
                const data = await this.caller.callWithResult(MSG_SEND_METHOD, msg);
                hilog.info(DOMAIN_NUMBER, TAG, 'caller callWithResult succeed');
                let result: MyParcelable = new MyParcelable(0, '');
                data.readParcelable(result);
                backMsg = result.str;
                hilog.info(DOMAIN_NUMBER, TAG, `caller result is [${result.num}, ${result.str}]`);
              }
            } catch (error) {
              hilog.info(DOMAIN_NUMBER, TAG, `caller callWithResult failed with ${error}`);
            }
          }
          // ...
        }
        ```
   
6. Release the caller object.

    When the [Caller](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#caller) object is no longer required, use [release](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#callerrelease) to release it.

      ```ts
      import { UIAbility, Caller } from '@kit.AbilityKit';
      import { hilog } from '@kit.PerformanceAnalysisKit';

      const TAG: string = '[CalleeAbility]';
      const DOMAIN_NUMBER: number = 0xFF00;

      export default class EntryAbility extends UIAbility {
        caller: Caller | undefined;

        releaseCall(): void {
          try {
            if (this.caller) {
              this.caller.release();
              this.caller = undefined;
            }
            hilog.info(DOMAIN_NUMBER, TAG, 'caller release succeed');
          } catch (error) {
            hilog.info(DOMAIN_NUMBER, TAG, `caller release failed with ${error}`);
          }
        }
      }
      ```
<!--no_check-->
