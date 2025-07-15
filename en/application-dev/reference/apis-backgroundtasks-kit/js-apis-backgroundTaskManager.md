# @ohos.backgroundTaskManager (Background Task Management)

The **BackgroundTaskManager** module provides APIs to manage background tasks.

If a service needs to be continued when the application or service module is running in the background (not visible to users), the application or service module can request a transient task to delay the suspension or a continuous task to prevent the suspension.

If an application has a task that needs to be continued when the application is switched to the background and can be completed within a short period of time, the application can request a transient task. For example, if a user chooses to clear junk files in the **Files** application and exits the application, the application can request a transient task to complete the cleanup.

If an application has a service that can be intuitively perceived by users and needs to run in the background for a long period of time (for example, music playback in the background), the application can request a continuous task.


>  **NOTE**
>
> - This module is deprecated since API version 9. You are advised to use [@ohos.resourceschedule.backgroundTaskManager](js-apis-resourceschedule-backgroundTaskManager.md) instead.
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import backgroundTaskManager from '@ohos.backgroundTaskManager';  
```


## backgroundTaskManager.requestSuspendDelay<sup>(deprecated)</sup>

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

Requests delayed suspension after the application switches to the background.

The default duration of delayed suspension is 3 minutes when the battery level is higher than or equal to the broadcast low battery level and 1 minute when the battery level is lower than the broadcast low battery level.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [backgroundTaskManager.requestSuspendDelay](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerrequestsuspenddelay) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name     | Type                  | Mandatory  | Description                            |
| -------- | -------------------- | ---- | ------------------------------ |
| reason   | string               | Yes   | Reason for delayed transition to the suspended state.                    |
| callback | Callback&lt;void&gt; | Yes   | Invoked when a delay is about to time out. Generally, this callback is used to notify the application 6 seconds before the delay times out.|

**Return value**

| Type                                   | Description       |
| ------------------------------------- | --------- |
| [DelaySuspendInfo](#delaysuspendinfodeprecated) | Information about the suspension delay.|

**Example**

  ```ts
  import backgroundTaskManager from '@ohos.backgroundTaskManager';
  import { BusinessError } from '@ohos.base';
  
  // Set the reason for delayed suspension.
  let myReason = 'test requestSuspendDelay';
  // Request delayed suspension.
  let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
      console.info("Request suspension delay will time out.");
  })
  // Print the delayed suspension information.
  let id = delayInfo.requestId;
  let time = delayInfo.actualDelayTime;
  console.info("The requestId is: " + id);
  console.info("The actualDelayTime is: " + time);
  ```


## backgroundTaskManager.getRemainingDelayTime<sup>(deprecated)</sup>

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the remaining duration before the application is suspended. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [backgroundTaskManager.getRemainingDelayTime](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagergetremainingdelaytime) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name      | Type                         | Mandatory  | Description                                      |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | Yes   | ID of the suspension delay request. The value is obtained by calling [requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelaydeprecated).|
| callback  | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the remaining duration before the application is suspended, in milliseconds.|

**Example**

  ```ts
  import backgroundTaskManager from '@ohos.backgroundTaskManager';
  import { BusinessError } from '@ohos.base';

  let delayInfo = backgroundTaskManager.requestSuspendDelay("test", () => {});
  backgroundTaskManager.getRemainingDelayTime(delayInfo.requestId, (err: BusinessError, res: number) => {
      if(err) {
          console.log('callback => Operation getRemainingDelayTime failed. Cause: ' + err.code);
      } else {
          console.log('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
      }
  })
  ```


## backgroundTaskManager.getRemainingDelayTime<sup>(deprecated)</sup>

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

Obtains the remaining duration before the application is suspended. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [backgroundTaskManager.getRemainingDelayTime](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagergetremainingdelaytime-1) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name      | Type    | Mandatory  | Description        |
| --------- | ------ | ---- | ---------- |
| requestId | number | Yes   | ID of the suspension delay request. The value is obtained by calling [requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelaydeprecated).|

**Return value**

| Type                   | Description                                      |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the remaining duration before the application is suspended, in milliseconds.|

**Example**

```ts
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import { BusinessError } from '@ohos.base';

let delayInfo = backgroundTaskManager.requestSuspendDelay("test", () => {});
    backgroundTaskManager.getRemainingDelayTime(delayInfo.requestId).then((res:number) => {
    console.log('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
}).catch((err : BusinessError) => {
    console.log('promise => Operation getRemainingDelayTime failed. Cause: ' + err.code);
})
```


## backgroundTaskManager.cancelSuspendDelay<sup>(deprecated)</sup>

cancelSuspendDelay(requestId: number): void

Cancels the suspension delay.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [backgroundTaskManager.cancelSuspendDelay](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagercancelsuspenddelay) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name      | Type    | Mandatory  | Description        |
| --------- | ------ | ---- | ---------- |
| requestId | number | Yes   | ID of the suspension delay request. The value is obtained by calling [requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelaydeprecated).|

**Example**

  ```ts
  let delayInfo = backgroundTaskManager.requestSuspendDelay("test", () => {});
  backgroundTaskManager.cancelSuspendDelay(delayInfo.requestId);
  ```


## backgroundTaskManager.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

Requests a continuous task from the system. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [backgroundTaskManager.startBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning) instead.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name   | Type                                         | Mandatory| Description                                                        |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| context   | Context                                       | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| bgMode    | [BackgroundMode](#backgroundmodedeprecated)            | Yes  | Background mode requested.                                      |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes  | Notification parameter, which is used to specify the target page that is redirected to when a continuous task notification is clicked.            |
| callback  | AsyncCallback&lt;void&gt;                     | Yes  | Callback used to return the result.                        |

**Example**

FA model:

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation startBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation startBackgroundRunning succeeded");
  }
}

let wantAgentInfo : wantAgent.WantAgentInfo = {
  wants: [
    {
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility"
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
  backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
    backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj, callback)
});

```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation startBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation startBackgroundRunning succeeded");
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo : wantAgent.WantAgentInfo = {
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
      backgroundTaskManager.startBackgroundRunning(this.context,
        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj, callback)
    });
  }
};
```

## backgroundTaskManager.startBackgroundRunning<sup>(deprecated)</sup>

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;

Requests a continuous task from the system. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [backgroundTaskManager.startBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning-1) instead.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name   | Type                                         | Mandatory| Description                                                        |
| --------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| context   | Context                                       | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| bgMode    | [BackgroundMode](#backgroundmodedeprecated)            | Yes  | Background mode requested.                                      |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes  | Notification parameter, which is used to specify the target page that is redirected to when a continuous task notification is clicked.              |

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

FA model (JS code is required for development):

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import { BusinessError } from '@ohos.base';

let wantAgentInfo : wantAgent.WantAgentInfo = {
  wants: [
    {
      bundleName: "com.example.myapplication",
      abilityName: "EntryAbility"
    }
  ],
  operationType: wantAgent.OperationType.START_ABILITY,
  requestCode: 0,
  wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
};

wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
  backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
    backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj).then(() => {
    console.info("Operation startBackgroundRunning succeeded");
  }).catch((err: BusinessError) => {
    console.error("Operation startBackgroundRunning failed Cause: " + err);
  });
});
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import wantAgent, { WantAgent } from '@ohos.app.ability.wantAgent';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo : wantAgent.WantAgentInfo = {
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      // Type of the operation to perform after the notification is clicked.
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      // Execution attribute of the operation to perform after the notification is clicked.
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
      backgroundTaskManager.startBackgroundRunning(this.context,
        backgroundTaskManager.BackgroundMode.LOCATION, wantAgentObj).then(() => {
        console.info("Operation startBackgroundRunning succeeded");
      }).catch((err: BusinessError) => {
        console.error("Operation startBackgroundRunning failed Cause: " + err);
      });
    });
  }
};
```

## backgroundTaskManager.stopBackgroundRunning<sup>(deprecated)</sup>

stopBackgroundRunning(context: Context, callback: AsyncCallback&lt;void&gt;): void

Requests to cancel a continuous task. This API uses an asynchronous callback to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [backgroundTaskManager.stopBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| context  | Context                   | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.                  |

**Example**

FA model (JS code is required for development):

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation stopBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation stopBackgroundRunning succeeded");
  }
}

backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext(), callback);

```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, data: void) {
  if (err) {
    console.error("Operation stopBackgroundRunning failed Cause: " + err);
  } else {
    console.info("Operation stopBackgroundRunning succeeded");
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    backgroundTaskManager.stopBackgroundRunning(this.context, callback);
  }
};
```

## backgroundTaskManager.stopBackgroundRunning<sup>(deprecated)</sup>

stopBackgroundRunning(context: Context): Promise&lt;void&gt;

Requests to cancel a continuous task. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [backgroundTaskManager.stopBackgroundRunning](js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning-1) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name    | Type     | Mandatory  | Description                                      |
| ------- | ------- | ---- | ---------------------------------------- |
| context | Context | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).|

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

FA model:

```js
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

// Cancel a continuous task.
backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
  console.info("Operation stopBackgroundRunning succeeded");
}).catch((err: BusinessError) => {
  console.error("Operation stopBackgroundRunning failed Cause: " + err);
});

```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import backgroundTaskManager from '@ohos.backgroundTaskManager';
import Want from '@ohos.app.ability.Want';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import { BusinessError } from '@ohos.base';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // Cancel a continuous task.
    backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
      console.info("Operation stopBackgroundRunning succeeded");
    }).catch((err: BusinessError) => {
      console.error("Operation stopBackgroundRunning failed Cause: " + err);
    });
  }
};
```

## DelaySuspendInfo<sup>(deprecated)</sup>

Provides the information about the suspension delay.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [DelaySuspendInfo](js-apis-resourceschedule-backgroundTaskManager.md#delaysuspendinfo) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| Name            | Type    | Mandatory  | Description                                      |
| --------------- | ------ | ---- | ---------------------------------------- |
| requestId       | number | Yes   | ID of the suspension delay request.                              |
| actualDelayTime | number | Yes   | Actual suspension delay duration of the application, in milliseconds.<br>The default duration is 180000 when the battery level is higher than or equal to the broadcast low battery level and 60000 when the battery level is lower than the broadcast low battery level.|


## BackgroundMode<sup>(deprecated)</sup>

Defines the type of a continuous task.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [BackgroundMode](js-apis-resourceschedule-backgroundTaskManager.md#backgroundmode) instead.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| DATA_TRANSFER           | 1    | Data transfer.                 |
| AUDIO_PLAYBACK          | 2    | Audio playback.                 |
| AUDIO_RECORDING         | 3    | Audio recording.                   |
| LOCATION                | 4    | Positioning and navigation.                 |
| BLUETOOTH_INTERACTION   | 5    | Bluetooth-related task.                 |
| MULTI_DEVICE_CONNECTION | 6    | Multi-device connection.                |
| TASK_KEEPING            | 9    | Computing task (effective only for specific devices).       |
