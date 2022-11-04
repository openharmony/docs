# Background Task Management

The **BackgroundTaskManager** module provides APIs to manage background tasks.

If a service needs to be continued when the application or service module is running in the background (not visible to users), the application or service module can request a transient task to delay the suspension or a continuous task to prevent the suspension.

If an application has a task that needs to be continued when the application is switched to the background and can be completed within a short period of time, the application can request a transient task. For example, if a user chooses to clear junk files in the **Files** application and exits the application, the application can request a transient task to complete the cleanup.

If an application has a service that can be intuitively perceived by users and needs to run in the background for a long period of time (for example, music playback in the background), the application can request a continuous task.

If a privileged system application needs to use certain system resources (for example, resources required to receive common events) when suspended, it can request efficiency resources.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```


## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

Requests delayed suspension after the application switches to the background.

The default duration of delayed suspension is 180000 when the battery level is higher than or equal to the broadcast low battery level and 60000 when the battery level is lower than the broadcast low battery level.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**
| Name     | Type                  | Mandatory  | Description                            |
| -------- | -------------------- | ---- | ------------------------------ |
| reason   | string               | Yes   | Reason for delayed transition to the suspended state.                    |
| callback | Callback&lt;void&gt; | Yes   | Invoked when a delay is about to time out. Generally, this callback is used to notify the application 6 seconds before the delay times out.|

**Return value**
| Type                                   | Description       |
| ------------------------------------- | --------- |
| [DelaySuspendInfo](#delaysuspendinfo) | Information about the suspension delay.|

**Example**

  ```js
  let myReason = 'test requestSuspendDelay';
  let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
      console.info("Request suspension delay will time out.");
  })
  
  var id = delayInfo.requestId;
  var time = delayInfo.actualDelayTime;
  console.info("The requestId is: " + id);
  console.info("The actualDelayTime is: " + time);
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the remaining duration before the application is suspended. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**
| Name      | Type                         | Mandatory  | Description                                      |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | Yes   | ID of the suspension delay request.                              |
| callback  | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the remaining duration before the application is suspended, in milliseconds.|

**Example**

  ```js
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id, (err, res) => {
      if(err) {
          console.log('callback => Operation getRemainingDelayTime failed. Cause: ' + err.code);
      } else {
          console.log('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
      }
  })
  ```


## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

Obtains the remaining duration before the application is suspended. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**
| Name      | Type    | Mandatory  | Description        |
| --------- | ------ | ---- | ---------- |
| requestId | number | Yes   | ID of the suspension delay request.|

**Return value**
| Type                   | Description                                      |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the remaining duration before the application is suspended, in milliseconds.|

**Example**
  ```js
  let id = 1;
  backgroundTaskManager.getRemainingDelayTime(id).then( res => {
      console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
  }).catch( err => {
      console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.code);
  })
  ```


## backgroundTaskManager.cancelSuspendDelay

cancelSuspendDelay(requestId: number): void

Cancels the suspension delay.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**
| Name      | Type    | Mandatory  | Description        |
| --------- | ------ | ---- | ---------- |
| requestId | number | Yes   | ID of the suspension delay request.|

**Example**
  ```js
  let id = 1;
  backgroundTaskManager.cancelSuspendDelay(id);
  ```


## backgroundTaskManager.startBackgroundRunning<sup>8+</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

Requests a continuous task from the system. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**
| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | Yes   | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).|
| bgMode    | [BackgroundMode](#backgroundmode8) | Yes   | Background mode requested.                             |
| wantAgent | [WantAgent](js-apis-wantAgent.md)  | Yes   | Notification parameter, which is used to specify the target page that is redirected to when a continuous task notification is clicked.                |
| callback  | AsyncCallback&lt;void&gt;          | Yes   | Callback used to return the result.                  |

**Example**
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent from '@ohos.wantAgent';

function callback(err, data) {
    if (err) {
        console.error("Operation startBackgroundRunning failed Cause: " + err);
    } else {
        console.info("Operation startBackgroundRunning succeeded");
    }
}

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
        backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj, callback)
});

```

## backgroundTaskManager.startBackgroundRunning<sup>8+</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;

Requests a continuous task from the system. This API uses a promise to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | Yes   | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).|
| bgMode    | [BackgroundMode](#backgroundmode8) | Yes   | Background mode requested.                             |
| wantAgent | [WantAgent](js-apis-wantAgent.md)  | Yes   | Notification parameter, which is used to specify the target page that is redirected to when a continuous task notification is clicked.                 |

**Return value**
| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Example**
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent from '@ohos.wantAgent';

let wantAgentInfo = {
    wants: [
        {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
        }
    ],
    operationType: wantAgent.OperationType.START_ABILITY,
    requestCode: 0,
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
        backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
        console.info("Operation startBackgroundRunning succeeded");
    }).catch((err) => {
        console.error("Operation startBackgroundRunning failed Cause: " + err);
    });
});

```

## backgroundTaskManager.stopBackgroundRunning<sup>8+</sup>

stopBackgroundRunning(context: Context, callback: AsyncCallback&lt;void&gt;): void

Requests to cancel a continuous task. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**
| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| context  | Context                   | Yes   | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.                  |

**Example**
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';

function callback(err, data) {
    if (err) {
        console.error("Operation stopBackgroundRunning failed Cause: " + err);
    } else {
        console.info("Operation stopBackgroundRunning succeeded");
    }
}

backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext(), callback);

```

## backgroundTaskManager.stopBackgroundRunning<sup>8+</sup>

stopBackgroundRunning(context: Context): Promise&lt;void&gt;

Requests to cancel a continuous task. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**
| Name    | Type     | Mandatory  | Description                                      |
| ------- | ------- | ---- | ---------------------------------------- |
| context | Context | Yes   | Application context.<br>For the application context of the FA model, see [Context](js-apis-Context.md).<br>For the application context of the stage model, see [Context](js-apis-ability-context.md).|

**Return value**
| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Example**
```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';

backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
    console.info("Operation stopBackgroundRunning succeeded");
}).catch((err) => {
    console.error("Operation stopBackgroundRunning failed Cause: " + err);
});

```

## backgroundTaskManager.applyEfficiencyResources<sup>9+</sup>

applyEfficiencyResources(request: [EfficiencyResourcesRequest](#efficiencyresourcesrequest9)): boolean

Requests efficiency resources from the system.
A process and its application can request the same type of resources at the same time, for example, CPU resources. When the application releases the resources, the same type of resources requested by the process are also released.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

**Parameters**

| Name    | Type     | Mandatory  | Description                                      |
| ------- | ------- | ---- | ---------------------------------------- |
| request | [EfficiencyResourcesRequest](#efficiencyresourcesrequest9) | Yes   | Necessary information carried in the request, including the resource type and timeout interval. For details, see [EfficiencyResourcesRequest](#efficiencyresourcesrequest9).|

**Return value**
| Type            | Description              |
| -------------- | ---------------- |
| boolean | Returns **true** if the request for the resources is successful; returns **false** otherwise.|

**Example**

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';

let request = {
    resourceTypes: backgroundTaskManager.ResourceType.CPU,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true,
    isProcess: false,
};
let res = backgroundTaskManager.applyEfficiencyResources(request);
console.info("result of applyEfficiencyResources is: " + res)
```

## backgroundTaskManager.resetAllEfficiencyResources<sup>9+</sup>

resetAllEfficiencyResources(): void

Releases all resources that have been requested.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

**Example**

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';

backgroundTaskManager.backgroundTaskManager.resetAllEfficiencyResources();

```

## DelaySuspendInfo

Provides the information about the suspension delay.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| Name            | Type    | Mandatory  | Description                                      |
| --------------- | ------ | ---- | ---------------------------------------- |
| requestId       | number | Yes   | ID of the suspension delay request.                              |
| actualDelayTime | number | Yes   | Actual suspension delay duration of the application, in milliseconds.<br>The default duration is 180000 when the battery level is higher than or equal to the broadcast low battery level and 60000 when the battery level is lower than the broadcast low battery level.|


## BackgroundMode<sup>8+</sup>

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| DATA_TRANSFER           | 1    | Data transfer.                 |
| AUDIO_PLAYBACK          | 2    | Audio playback.                 |
| AUDIO_RECORDING         | 3    | Audio recording.                   |
| LOCATION                | 4    | Positioning and navigation.                 |
| BLUETOOTH_INTERACTION   | 5    | Bluetooth-related task.                 |
| MULTI_DEVICE_CONNECTION | 6    | Multi-device connection.                |
| WIFI_INTERACTION        | 7    | WLAN-related.<br>This is a system API.|
| VOIP                    | 8    | Audio and video calls.<br>This is a system API. |
| TASK_KEEPING            | 9    | Computing task (effective only for specific devices).       |

## EfficiencyResourcesRequest<sup>9+</sup>

Describes the parameters for requesting efficiency resources.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

| Name            | Type    | Mandatory  | Description                                      |
| --------------- | ------ | ---- | ---------------------------------------- |
| resourceTypes   | number  | Yes   | Type of the resource to request.                              |
| isApply         | boolean | Yes   | Whether the request is used to apply for resources. The value **true** means that the request is used to apply for resources, and **false** means that the request is used to release resources.         |
| timeOut         | number  | Yes   | Duration for which the resource will be used, in milliseconds.               |
| isPersist       | boolean | No   | Whether the resource is permanently held. If the value is **true**, **timeOut** is invalid.   |
| isProcess       | boolean | No   | Whether the request is initiated by a process. The value **true** means that the request is initiated by a process, and **false** means that the request is initiated by an application.         |
| reason          | string  | Yes   | Reason for requesting the resource.               |

## ResourceType<sup>9+</sup>

Enumerates the efficiency resource types.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| CPU                     | 1    | CPU resources, which prevent the application from being suspended.            |
| COMMON_EVENT            | 2    | A type of software resources, which prevent common events from being proxied when the application is suspended. |
| TIMER                   | 4    | A type of software resources, which prevent timers from being proxied when the application is suspended.   |
| WORK_SCHEDULER          | 8    | WORK_SCHEDULER resources, which ensure that the application has more time to execute the task.     |
| BLUETOOTH               | 16   | A type of hardware resources, which prevent Bluetooth resources from being proxied when the application is suspended. |
| GPS                     | 32   | A type of hardware resources, which prevent GPS resources from being proxied when the application is suspended. |
| AUDIO                   | 64   | A type of hardware resources, which prevent audio resources from being proxied when the application is suspended.|
