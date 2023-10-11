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

- For better user experience, you are advised to use the **want** parameter to transmit data smaller than 100 KB.


## Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)

On device A, touch the **Start** button provided by the initiator application to start a specified UIAbility or ServiceExtensionAbility on device B.


### Available APIs

**Table 1** Cross-device startup APIs

| **API**| **Description**|
| -------- | -------- |
| startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void; | Starts a UIAbility or ServiceExtensionAbility. This API uses an asynchronous callback to return the result.|
| stopServiceExtensionAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void; | Stops a ServiceExtensionAbility. This API uses an asynchronous callback to return the result.|
| stopServiceExtensionAbility(want: Want): Promise&lt;void&gt;; | Stops a ServiceExtensionAbility. This API uses a promise to return the result.|


### How to Develop

1. Request the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. Obtain the device ID of the target device.

   ```ts
   import deviceManager from '@ohos.distributedDeviceManager';

   let dmClass: deviceManager.DeviceManager;
   function initDmClass() {
        // createDeviceManager is a system API.
        try{
            dmClass = deviceManager.createDeviceManager('ohos.samples.demo');
        } catch(err) {
            console.error("createDeviceManager err: " + JSON.stringify(err));
        }
   }
   function getRemoteDeviceId(): string | undefined {
       if (typeof dmClass === 'object' && dmClass !== null) {
           let list = dmClass.getAvailableDeviceListSync();
           if (typeof (list) === 'undefined' || typeof (list.length) === 'undefined') {
                console.info('getRemoteDeviceId err: list is null');
                return;
           }
           if (list.length === 0) {
               console.info("getRemoteDeviceId err: list is empty");
               return;
           }
       	return list[0].networkId;
       } else {
           console.info('getRemoteDeviceId err: dmClass is null');
           return;
       }
   }
   ```

4. Set the target component parameters, and call [startAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability) to start a UIAbility or ServiceExtensionAbility.

   ```ts
   import { BusinessError } from '@ohos.base';
   import Want from '@ohos.app.ability.Want';
   let want: Want = {
       deviceId: getRemoteDeviceId(),
       bundleName: 'com.example.myapplication',
       abilityName: 'EntryAbility',
       moduleName: 'entry', // moduleName is optional.
   }
   // context is the AbilityContext of the initiator UIAbility.
   this.context.startAbility(want).then(() => {
       // ...
   }).catch((err: BusinessError) => {
       // ...
       console.error("startAbility err: " + JSON.stringify(err));
   })
   ```

5. Call [stopServiceExtensionAbility](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstopserviceextensionability) to stop the ServiceExtensionAbility when it is no longer required on device B. (This API cannot be used to stop a UIAbility. Users must manually stop a UIAbility through mission management.)

   ```ts
   import Want from '@ohos.app.ability.Want';
   import { BusinessError } from '@ohos.base';
   let want: Want = {
       deviceId: getRemoteDeviceId(),
       bundleName: 'com.example.myapplication',
       abilityName: 'FuncAbility',
       moduleName: 'module1', // moduleName is optional.
   }
   // Stop the ServiceExtensionAbility started by calling startAbility().
   this.context.stopServiceExtensionAbility(want).then(() => {
       console.info("stop service extension ability success")
   }).catch((err: BusinessError) => {
       console.info("stop service extension ability err is " + JSON.stringify(err))
   })
   ```

## Starting UIAbility Across Devices (Data Returned)

On device A, touch the **Start** button provided by the initiator application to start a specified UIAbility on device B. When the UIAbility on device B exits, a value is returned to the initiator application.


### Available APIs

**Table 2** APIs for starting a UIAbility across devices and returning the result data

| API| Description|
| -------- | -------- |
| startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void; | Starts a UIAbility. This API uses an asynchronous callback to return the result when the UIAbility is terminated.|
| terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void;| Terminates this UIAbility. This API uses an asynchronous callback to return the result information. It is used together with **startAbilityForResult**.|
| terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;; | Terminates this UIAbility. This API uses a promise to return the result information. It is used together with **startAbilityForResult**.|


### How to Develop

1. Request the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. Set the target component parameters on the initiator, and call **startAbilityForResult()** to start the target UIAbility. **data** in the asynchronous callback is used to receive the information returned by the target UIAbility to the initiator UIAbility after the target UIAbility terminates itself. For details about how to implement **getRemoteDeviceId()**, see [Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)](#starting-uiability-or-serviceextensionability-across-devices-no-data-returned).

   ```ts
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   import Want from '@ohos.app.ability.Want';
   @Entry
   @Component
   struct PageName {
      private context = getContext(this) as common.UIAbilityContext;
      build() {
        // ...
        Button('StartAbilityForResult')
          .onClick(()=>{
           let want: Want = {
               deviceId: getRemoteDeviceId(),
               bundleName: 'com.example.myapplication',
               abilityName: 'FuncAbility',
               moduleName: 'module1', // moduleName is optional.
           }
           // context is the AbilityContext of the initiator UIAbility.
           this.context.startAbilityForResult(want).then((data) => {
               // ...
           }).catch((error: BusinessError) => {
               console.info("startAbilityForResult err: " + JSON.stringify(error));
           })
          }
        )
      }
   }
   ```

4. After the UIAbility mission on the target device is complete, call **terminateSelfWithResult()** to return the data to the initiator UIAbility.

   ```ts
   import { BusinessError } from '@ohos.base';
   import common from '@ohos.app.ability.common';
   @Entry
   @Component
   struct PageName {
      private context = getContext(this) as common.UIAbilityContext;
      build() {
        // ...
        Button('terminateSelfWithResult')
          .onClick(()=>{
               const RESULT_CODE: number = 1001;
               // context is the AbilityContext of the target UIAbility.
               this.context.terminateSelfWithResult(
                {
                   resultCode: RESULT_CODE,
                   want: {
                       bundleName: 'com.example.myapplication',
                       abilityName: 'FuncAbility',
                       moduleName: 'module1',
                   },
               },
               (err: BusinessError) => {
                   // ...
                   console.info("terminateSelfWithResult err: " + JSON.stringify(err));
               });
          }
        // ...
        )
      }
   }
   ```

5. The initiator UIAbility receives the information returned by the target UIAbility and processes the information.

   ```ts
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   import Want from '@ohos.app.ability.Want';
   @Entry
   @Component
   struct PageName {
      private context = getContext(this) as common.UIAbilityContext;
      build() {
        // ...
        Button('StartAbilityForResult')
          .onClick(()=>{
            let want: Want = {
                deviceId: getRemoteDeviceId(),
                bundleName: 'com.example.myapplication',
                abilityName: 'FuncAbility',
                moduleName: 'module1', // moduleName is optional.
            }
            const RESULT_CODE: number = 1001;
            // ...
            // context is the UIAbilityContext of the initiator UIAbility.
            this.context.startAbilityForResult(want).then((data) => {
                if (data?.resultCode === RESULT_CODE) {
                    // Parse the information returned by the target UIAbility.
                    let info = data.want?.parameters?.info;
                    // ...
                }
            }).catch((error: BusinessError) => {
                // ...
            })
          }
        )
      }
   }
   ```


## Connecting to ServiceExtensionAbility Across Devices

A system application can connect to a service on another device by calling [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextconnectserviceextensionability). For example, in the distributed game scenario, a tablet is used as the remote control and a smart TV is used as the display.


### Available APIs

**Table 3** APIs for cross-device connection

| API| Description|
| -------- | -------- |
| connectServiceExtensionAbility(want: Want, options: ConnectOptions): number; | Connects to a ServiceExtensionAbility.|
| disconnectServiceExtensionAbility(connection: number, callback: AsyncCallback&lt;void&gt;): void; | Disconnects a connection. This API uses an asynchronous callback to return the result.|
| disconnectServiceExtensionAbility(connection: number): Promise&lt;void&gt;; | Disconnects a connection. This API uses a promise to return the result.|


### How to Develop

1. Request the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. (Optional) [Implement a background service](serviceextensionability.md#implementing-a-background-service-for-system-applications-only). Perform this operation only if no background service is available.

4. Connect to the background service.
   - Implement the **IAbilityConnection** class. **IAbilityConnection** provides the following callbacks that you should implement: **onConnect()**, **onDisconnect()**, and **onFailed()**. The **onConnect()** callback is invoked when a service is connected, **onDisconnect()** is invoked when a service is unexpectedly disconnected, and **onFailed()** is invoked when the connection to a service fails.
   - Set the target component parameters, including the target device ID, bundle name, and ability name.
   - Call **connectServiceExtensionAbility** to initiate a connection.
   - Receive the service handle returned by the target device when the connection is successful.
   - Perform cross-device call and obtain the result returned by the target service.
     
      ```ts
      import rpc from '@ohos.rpc';
      import Want from '@ohos.app.ability.Want';
      import common from '@ohos.app.ability.common';
      import { BusinessError } from '@ohos.base';
      @Entry
      @Component
      struct PageName {
          private context = getContext(this) as common.UIAbilityContext;
          build() {
            // ...
            Button('connectServiceExtensionAbility')
              .onClick(()=>{
                const REQUEST_CODE = 99;
                let want: Want = {
                    "deviceId": getRemoteDeviceId(),
                    "bundleName": "com.example.myapplication",
                    "abilityName": "ServiceExtAbility"
                };
                // The ID returned after the connection is set up must be saved. The ID will be passed for service disconnection.
                let connectionId = this.context.connectServiceExtensionAbility(want,
                {
                    onConnect(elementName, remote) {
                        console.info('onConnect callback');
                        if (remote === null) {
                            console.info(`onConnect remote is null`);
                            return;
                        }
                        let option = new rpc.MessageOption();
                        let data = new rpc.MessageSequence();
                        let reply = new rpc.MessageSequence();
                        data.writeInt(1);
                        data.writeInt(99); // You can send data to the target application for corresponding operations.
                        // @param code Indicates the service request code sent by the client.
                        // @param data Indicates the {@link MessageSequence} object sent by the client.
                        // @param reply Indicates the response message object sent by the remote service.
                        // @param options Specifies whether the operation is synchronous or asynchronous.
                        //
                        // @return Returns {@code true} if the operation is successful; returns {@code false} otherwise.
                        remote.sendMessageRequest(REQUEST_CODE, data, reply, option).then((ret: rpc.RequestResult) => {
                            let msg = reply.readInt();   // Receive the information (100) returned by the target device if the connection is successful.
                            console.info(`sendRequest ret:${ret} msg:${msg}`);
                        }).catch((error: BusinessError) => {
                            console.info('sendRequest failed');
                        });
                    },
                    onDisconnect(elementName) {
                        console.info('onDisconnect callback');
                    },
                    onFailed(code) {
                        console.info('onFailed callback');
                    }
                });
              })
          }
      }
      ```

      For details about how to implement **getRemoteDeviceId()**, see [Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)](#starting-uiability-or-serviceextensionability-across-devices-no-data-returned).

5. Disconnect the connection. Use **disconnectServiceExtensionAbility()** to disconnect from the background service.

   ```ts
   import common from '@ohos.app.ability.common';
   import { BusinessError } from '@ohos.base';
   @Entry
   @Component
   struct PageName {
       private context = getContext(this) as common.UIAbilityContext;
       build() {
         // ...
         Button('disconnectServiceExtensionAbility')
           .onClick(()=>{
                let connectionId: number = 1 // ID returned when the service is connected through connectServiceExtensionAbility.
                this.context.disconnectServiceExtensionAbility(connectionId).then(() => {
                    console.info('disconnectServiceExtensionAbility success');
                }).catch((error: BusinessError) => {
                    console.error('disconnectServiceExtensionAbility failed');
                })
           })
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
| on(type: "release", callback: OnReleaseCallback): void | Callback invoked when the caller object is released.|


### How to Develop

1. Request the **ohos.permission.DISTRIBUTED_DATASYNC** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Display a dialog box to ask for authorization from the user when the application is started for the first time. For details, see [Requesting User Authorization](../security/accesstoken-guidelines.md#requesting-user-authorization).

3. Create the CalleeAbility.
   
     For the CalleeAbility, implement the callback to receive data and the methods to marshal and unmarshal data. When data needs to be received, use **on()** to register a listener. When data does not need to be received, use **off()** to deregister the listener.

     1. Configure the launch type of the UIAbility.

         Set **launchType** of the CalleeAbility to **singleton** in the **module.json5** file.

         | JSON Field| Description|
         | -------- | -------- |
         | "launchType"| UIAbility launch type. Set this parameter to **singleton**.|

         An example of the UIAbility configuration is as follows:

         
         ```json
         "abilities":[{
             "name": ".CalleeAbility",
             "srcEntry": "./ets/CalleeAbility/CalleeAbility.ts",
             "launchType": "singleton",
             "description": "$string:CalleeAbility_desc",
             "icon": "$media:icon",
             "label": "$string:CalleeAbility_label",
             "exported": true
         }]
         ```
     2. Import the **UIAbility** module.
        
         ```ts
         import UIAbility from '@ohos.app.ability.UIAbility';
         ```
     3. Define the agreed parcelable data.

         The data formats sent and received by the CallerAbility and CalleeAbility must be consistent. In the following example, the data formats are number and string.

         
         ```ts
         import rpc from '@ohos.rpc'
         class MyParcelable {
             num: number = 0;
             str: string = "";
         
             constructor(num: number, string: string) {
                 this.num = num;
                 this.str = string;
             }
         
             marshalling(messageSequence: rpc.MessageSequence) {
                 messageSequence.writeInt(this.num);
                 messageSequence.writeString(this.str);
                 return true;
             }
         
             unmarshalling(messageSequence: rpc.MessageSequence) {
                 this.num = messageSequence.readInt();
                 this.str = messageSequence.readString();
                 return true;
             }
         }
         ```
     4. Implement **Callee.on** and **Callee.off**.

           In the following example, the **MSG_SEND_METHOD** listener is registered in **onCreate()** of the UIAbility and deregistered in **onDestroy()**. After receiving parcelable data, the application processes the data and returns the data result. You need to implement processing based on service requirements.
           
         ```ts
         import rpc from '@ohos.rpc';
         import Want from '@ohos.app.ability.Want';
         import UIAbility from '@ohos.app.ability.UIAbility';
         import AbilityConstant from '@ohos.app.ability.AbilityConstant';
         const TAG: string = '[CalleeAbility]';
         const MSG_SEND_METHOD: string = 'CallSendMsg';
         
         function sendMsgCallback(data: rpc.MessageSequence): MyParcelable {
             console.info('CalleeSortFunc called');
         
             // Obtain the parcelable data sent by the CallerAbility.
             let receivedData: MyParcelable = new MyParcelable(0, '');
             data.readParcelable(receivedData);
             console.info(`receiveData[${receivedData.num}, ${receivedData.str}]`);
         
             // Process the data.
             // Return the parcelable data result to the CallerAbility.
             return new MyParcelable(Number(receivedData.num) + 1, `send ${receivedData.str} succeed`);
         }
         
         export default class CalleeAbility extends UIAbility {
             onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
                 try {
                     this.callee.on(MSG_SEND_METHOD, sendMsgCallback);
                 } catch (error) {
                     console.info(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`);
                 }
             }
         
             onDestroy() {
                 try {
                     this.callee.off(MSG_SEND_METHOD);
                 } catch (error) {
                     console.error(TAG, `${MSG_SEND_METHOD} unregister failed with error ${JSON.stringify(error)}`);
                 }
             }
         }
         ```

4. Obtain the caller object and access the CalleeAbility.
   1. Import the **UIAbility** module.
      
       ```ts
       import UIAbility from '@ohos.app.ability.UIAbility';
       ```
   2. Obtain the caller object.

       The **context** attribute of the UIAbility implements **startAbilityByCall** to obtain the caller object for communication. The following example uses **this.context** to obtain the **context** attribute of the UIAbility, uses **startAbilityByCall** to start the CalleeAbility, obtain the caller object, and register the **onRelease** and **onRemoteStateChange** listeners of the CallerAbility. You need to implement processing based on service requirements.

       
       ```ts
       import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
       import { BusinessError } from '@ohos.base';
       export default class EntryAbility extends UIAbility {
            // ...
            async onButtonGetRemoteCaller() {
                let caller: Caller | undefined;
                let context = this.context;

                context.startAbilityByCall({
                    deviceId: getRemoteDeviceId(),
                    bundleName: 'com.samples.CallApplication',
                    abilityName: 'CalleeAbility'
                }).then((data) => {
                    if (data != null) {
                        caller = data;
                        console.info('get remote caller success');
                        // Register the onRelease listener of the CallerAbility.
                        caller.onRelease((msg) => {
                            console.info(`remote caller onRelease is called ${msg}`);
                        })
                        console.info('remote caller register OnRelease succeed');
                        // Register the onRemoteStateChange listener of the CallerAbility.
                        try {
                                caller.onRemoteStateChange((str) => {
                                    console.info('Remote state changed ' + str);
                                });
                            } catch (error) {
                                console.info('Caller.onRemoteStateChange catch error, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}');
                            }
                    }
                }).catch((error: BusinessError) => {
                    console.error(`get remote caller failed with ${error}`);
                })
            }
            // ...
       }
       ```

       For details about how to implement **getRemoteDeviceId()**, see [Starting UIAbility or ServiceExtensionAbility Across Devices (No Data Returned)](#starting-uiability-or-serviceextensionability-across-devices-no-data-returned).

5. Sends agreed parcelable data to the CalleeAbility.
   1. The parcelable data can be sent to the CalleeAbility with or without a return value. The method and parcelable data must be consistent with those of the CalleeAbility. The following example describes how to send data to the CalleeAbility.
      
       ```ts
       import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
       import { BusinessError } from '@ohos.base';
       const MSG_SEND_METHOD: string = 'CallSendMsg';
       export default class EntryAbility extends UIAbility {
        // ...
        caller: Caller | undefined;
        async onButtonCall() {
            try {
                let msg: MyParcelable = new MyParcelable(1, 'origin_Msg');
                if (this.caller) {
                    await this.caller.call(MSG_SEND_METHOD, msg);
                }
            } catch (error) {
                console.info(`caller call failed with ${error}`);
            }
        }
        // ...
       }
       ```
   2. In the following, **CallWithResult** is used to send data **originMsg** to the CalleeAbility and assign the data processed by the **CallSendMsg** method to **backMsg**.
      
        ```ts
        import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
        import rpc from '@ohos.rpc';
        const MSG_SEND_METHOD: string = 'CallSendMsg';
        let originMsg: string = '';
        let backMsg: string = '';
        export default class EntryAbility extends UIAbility {
            // ...
            caller: Caller | undefined;
            async onButtonCallWithResult(originMsg: string, backMsg: string) {
                try {
                    let msg: MyParcelable = new MyParcelable(1, originMsg);
                    if (this.caller) {
                        const data = await this.caller.callWithResult(MSG_SEND_METHOD, msg);
                        console.info('caller callWithResult succeed');
                        let result: MyParcelable = new MyParcelable(0, '');
                        data.readParcelable(result);
                        backMsg = result.str;
                        console.info(`caller result is [${result.num}, ${result.str}]`);
                    }
                } catch (error) {
                    console.info(`caller callWithResult failed with ${error}`);
                }
            }
            // ...
        }
        ```

6. Release the caller object.

   When the caller object is no longer required, use **release()** to release it.

   ```ts
   import UIAbility, { Caller } from '@ohos.app.ability.UIAbility';
   export default class EntryAbility extends UIAbility {
    caller: Caller | undefined;
    releaseCall() {
        try {
            if (this.caller) {
                this.caller.release();
                this.caller = undefined;
            }
            console.info('caller release succeed');
        } catch (error) {
            console.info(`caller release failed with ${error}`);
        }
    }
   }
   ```
