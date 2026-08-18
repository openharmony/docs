# @ohos.resourceschedule.backgroundTaskManager (Background Task Management)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=024caec7fad677e2dd0da703ca632c95f71d3579 translatedAt=2026-08-11T01:59:07.476Z pushedAt=2026-08-11T06:14:20.715Z -->

The **backgroundTaskManager** module provides APIs to request background tasks. You can use the APIs to request transient tasks, continuous tasks, or efficiency resources to prevent the application process from being terminated or suspended when your application is switched to the background. For details, see [Continuous Task](../../task-management/continuous-task.md) and [Transient Task](../../task-management/transient-task.md).

>  **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
```

## backgroundTaskManager.requestSuspendDelay

requestSuspendDelay(reason: string, callback: Callback&lt;void&gt;): DelaySuspendInfo

Requests a transient task. This API is applicable when an application is about to be moved to the background and needs to delay its suspension for a short period of time to complete key operations such as saving data or upload progress.

>  **NOTE**
>
> For details about the constraints on requesting and using a transient task, see [Transient Task (ArkTS)](../../task-management/transient-task.md#constraints).

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name     | Type                  | Mandatory  | Description                            |
| -------- | -------------------- | ---- | ------------------------------ |
| reason   | string               | Yes   | Reason for requesting the transient task.                    |
| callback | Callback&lt;void&gt; | Yes   | Callback used to notify the application that the transient task is about to time out. Generally, the callback is invoked 6 seconds before the timeout.|

**Return value**

| Type                                   | Description       |
| ------------------------------------- | --------- |
| [DelaySuspendInfo](#delaysuspendinfo) | Information about the transient task.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

// Reason for requesting the transient task
let myReason = 'test requestSuspendDelay';
try {
  let delayInfo = backgroundTaskManager.requestSuspendDelay(myReason, () => {
  // Callback function, which is triggered when the transient task is about to time out. The application can carry out data clear and annotation, and cancel the task in the callback.
  // The callback is independent of the service of the application. After the request for the transient task is successful, the application normally executes its own service logic.
    console.info("Request suspension delay will time out.");
  })
  let id = delayInfo.requestId;
  let time = delayInfo.actualDelayTime;
  console.info("The requestId is: " + id);
  console.info("The actualDelayTime is: " + time);
} catch (error) {
  console.error(`requestSuspendDelay failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the remaining time of a transient task. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name      | Type                         | Mandatory  | Description                                      |
| --------- | --------------------------- | ---- | ---------------------------------------- |
| requestId | number                      | Yes   | Request ID of the transient task. It is obtained by calling the [requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelay) API. |
| callback  | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the remaining time of the transient task, in milliseconds.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

// Request ID of the transient task, which is used to query the remaining time.
let id = 1;
backgroundTaskManager.getRemainingDelayTime(id, (error: BusinessError, res: number) => {
  if(error) {
    console.error(`callback => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
  } else {
    console.info('callback => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
  }
})
```

## backgroundTaskManager.getRemainingDelayTime

getRemainingDelayTime(requestId: number): Promise&lt;number&gt;

Obtains the remaining time of a transient task. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name      | Type    | Mandatory  | Description        |
| --------- | ------ | ---- | ---------- |
| requestId | number | Yes   | Request ID of the transient task. It is obtained by calling the [requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelay) API.|

**Return value**

| Type                   | Description                                      |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise that returns the remaining time of the transient task, in milliseconds.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

let id = 1;
backgroundTaskManager.getRemainingDelayTime(id).then((res: number) => {
  console.info('promise => Operation getRemainingDelayTime succeeded. Data: ' + JSON.stringify(res));
}).catch((error: BusinessError) => {
  console.error(`promise => Operation getRemainingDelayTime failed. code is ${error.code} message is ${error.message}`);
})
```

## backgroundTaskManager.cancelSuspendDelay

cancelSuspendDelay(requestId: number): void

Cancels a transient task. This API is applicable when the application task is complete and background resources need to be released in advance.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Parameters**

| Name      | Type    | Mandatory  | Description        |
| --------- | ------ | ---- | ---------- |
| requestId | number | Yes   | Request ID of the transient task. It is obtained by calling the [requestSuspendDelay](#backgroundtaskmanagerrequestsuspenddelay) API.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9900001 | Caller information verification failed for a transient task. |
| 9900002 | Transient task verification failed. |

**Example**

  ```js
  import { BusinessError } from '@kit.BasicServicesKit';
  import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

  let id = 1;
  try {
    backgroundTaskManager.cancelSuspendDelay(id);
  } catch (error) {
    console.error(`cancelSuspendDelay failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
  }
  ```

## backgroundTaskManager.getTransientTaskInfo<sup>20+</sup>

getTransientTaskInfo(): Promise&lt;TransientTaskInfo&gt;

Obtains all transient task information, including the remaining quota of the current day. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Return value**

| Type                                     | Description         |
|-----------------------------------------|-------------|
|  Promise&lt;[TransientTaskInfo](#transienttaskinfo20)&gt; | Promise that returns all transient task information.|

**Error codes**

For details about the error codes, see [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 9900001 | Caller information verification failed for a transient task. |
| 9900003 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9900004 | System service operation failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  backgroundTaskManager.getTransientTaskInfo().then((res: backgroundTaskManager.TransientTaskInfo) => {
    console.info(`Operation getTransientTaskInfo succeeded. data: ` + JSON.stringify(res));
  }).catch((error : BusinessError) => {
    console.error(`Operation getTransientTaskInfo failed. code is ${error.code} message is ${error.message}`);
  });
} catch (error) {
  console.error(`Operation getTransientTaskInfo failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.startBackgroundRunning

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void

Requests a continuous task of a specific type. This API uses an asynchronous callback to return the result. After a continuous task is successfully requested, there will be a notification message without prompt tone. A UIAbility (ServiceAbility in the FA model) can request only one continuous task at a time through this API. You can request multiple continuous tasks by calling [startBackgroundRunning](#backgroundtaskmanagerstartbackgroundrunning21) added in API version 21.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| bgMode    | [BackgroundMode](#backgroundmode) | Yes   | Type of the continuous task.                          |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes   | Notification parameters, which are used to specify the target page that is redirected to when a continuous task notification is clicked.          |
| callback  | AsyncCallback&lt;void&gt;          | Yes   | Callback used to return the result. If the continuous task is requested, **err** is **undefined**. Otherwise, **err** is an error object.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
// In atomic services, please remove the WantAgent import.

function callback(error: BusinessError, data: void) {
  if (error) {
    console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
  } else {
    console.info("Operation startBackgroundRunning succeeded");
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo: wantAgent.WantAgentInfo = {
      // List of operations to be executed after the notification is clicked.
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      // Type of the operation to perform after the notification is clicked.
      actionType: wantAgent.OperationType.START_ABILITY,
      // Custom request code.
      requestCode: 0,
      // Execution attribute of the operation to perform after the notification is clicked.
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    try {
      // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
      // In atomic services, please replace the following line of code with wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {.
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
        try {
          backgroundTaskManager.startBackgroundRunning(this.context,
            backgroundTaskManager.BackgroundMode.AUDIO_PLAYBACK, wantAgentObj, callback)
        } catch (error) {
          console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      });
    } catch (error) {
      console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.startBackgroundRunning

startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;

Requests a continuous task of a specific type. This API uses a promise to return the result. After a continuous task is successfully requested, there will be a notification message without prompt tone. A UIAbility (ServiceAbility in the FA model) can request only one continuous task at a time through this API. You can request multiple continuous tasks by calling [startBackgroundRunning](#backgroundtaskmanagerstartbackgroundrunning21) added in API version 21.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | Context                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| bgMode    | [BackgroundMode](#backgroundmode) | Yes   | Type of the continuous task.                         |
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes   | Notification parameters, which are used to specify the target page that is redirected to when a continuous task notification is clicked.                |

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
// In atomic services, please remove the WantAgent import.

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo: wantAgent.WantAgentInfo = {
      // List of operations to be executed after the notification is clicked.
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      // Type of the operation to perform after the notification is clicked.
      actionType: wantAgent.OperationType.START_ABILITY,
      // Custom request code.
      requestCode: 0,
      // Execution attribute of the operation to perform after the notification is clicked.
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    try {
      // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
      // In atomic services, please replace the following line of code with wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {.
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
        try {
          backgroundTaskManager.startBackgroundRunning(this.context,
            backgroundTaskManager.BackgroundMode.AUDIO_PLAYBACK, wantAgentObj).then(() => {
              console.info("Operation startBackgroundRunning succeeded");
            }).catch((error: BusinessError) => {
              console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
            });
        } catch (error) {
          console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      });
    } catch (error) {
      console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.startBackgroundRunning<sup>12+</sup>

startBackgroundRunning(context: Context, bgModes: string[], wantAgent: WantAgent): Promise&lt;ContinuousTaskNotification&gt;

Requests continuous tasks of multiple types. This API uses a promise to return the result. After a continuous task is successfully requested, there will be a notification message without prompt tone. A UIAbility (ServiceAbility in the FA model) can request only one continuous task at a time through this API. You can request multiple continuous tasks by calling [startBackgroundRunning](#backgroundtaskmanagerstartbackgroundrunning21) added in API version 21.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| bgModes    | string[] | Yes   | Types of continuous tasks. For details about the available options, see [Item](../../task-management/continuous-task.md#use-cases).<br> Note: One or more types can be passed.|
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md) | Yes   | Notification parameters, which are used to specify the target page that is redirected to when a continuous task notification is clicked.                |

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<[ContinuousTaskNotification](#continuoustasknotification12)> | Promise that returns an object of the [ContinuousTaskNotification](#continuoustasknotification12) type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { notificationManager } from '@kit.NotificationKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
// In atomic services, please remove the WantAgent import.

export default class EntryAbility extends UIAbility {
  id: number = 0; // Save the notification ID.

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo: wantAgent.WantAgentInfo = {
      // List of operations to be executed after the notification is clicked.
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      // Type of the operation to perform after the notification is clicked.
      actionType: wantAgent.OperationType.START_ABILITY,
      // Custom request code.
      requestCode: 0,
      // Execution attribute of the operation to perform after the notification is clicked.
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    try {
      // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
      // In atomic services, please replace the following line of code with wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {.
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
        try {
          // The application needs to update the progress only for continuous tasks of the dataTransfer type.
          let list: Array<string> = ["dataTransfer"];
          // In atomic services, let list: Array<string> = ["audioPlayback"];
          backgroundTaskManager.startBackgroundRunning(this.context, list, wantAgentObj).then((res: backgroundTaskManager.ContinuousTaskNotification) => {
            console.info("Operation startBackgroundRunning succeeded");
            // For a continuous task of the upload and download type, the application can use the notification ID returned in res to update the notification, for example, sending a template notification with a progress bar.
            this.id = res.notificationId;
          }).catch((error: BusinessError) => {
            console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
          });
        } catch (error) {
          console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      });
    } catch (error) {
      console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }

  // The application needs to update the progress only for continuous tasks of the dataTransfer type.
  updateProcess(process: number) {
    // Define the notification type. The notification type of the progress update must be live view.
    let downLoadTemplate: notificationManager.NotificationTemplate = {
      name: 'downloadTemplate', // Currently, only downloadTemplate is supported. Retain the value.
      data: {
        title: 'File download: music.mp4', // Mandatory.
        fileName: 'senTemplate', // Mandatory.
        progressValue: process, // The application updates the progress, which is user-defined.
      }
    };
    let request: notificationManager.NotificationRequest = {
      content: {
        // System live view type, which remains unchanged.
        notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW,
        systemLiveView: {
          typeCode: 8, // Set this parameter to 8 for the dataTransfer type. Currently, only the dataTransfer type is supported. Retain the value.
          title: "test", // Customized by the application.
          text: "test", // Customized by the application.
        }
      },
      id: this.id, // The value must be the ID returned for a continuous-task request. Otherwise, the application fails to update the notification.
      notificationSlotType: notificationManager.SlotType.LIVE_VIEW, // Live view type. Retain the value.
      template: downLoadTemplate // Name of the template to be set for the application.
    };

    try {
      notificationManager.publish(request).then(() => {
        console.info("publish success, id= " + this.id);
      }).catch((err: BusinessError) => {
        console.error(`publish fail: ${JSON.stringify(err)}`);
      });
    } catch (err) {
      console.error(`publish fail: ${JSON.stringify(err)}`);
    }
  }
};
```

## backgroundTaskManager.startBackgroundRunning<sup>21+</sup>

startBackgroundRunning(context: Context, request: ContinuousTaskRequest): Promise&lt;ContinuousTaskNotification&gt;

Requests a continuous task. This API allows a UIAbility (ServiceAbility in the FA model) to request multiple continuous tasks and uses a promise to return the result. When using this API to request a continuous task, its notification can be combined with that of an existing continuous task. For details, see [ContinuousTaskRequest](#continuoustaskrequest21).<br>A maximum of 10 continuous tasks can be created simultaneously. Upon successful creation of a continuous task, a notification will be sent without a prompt tone.<br>If a continuous task requested via this API includes multiple task types (including data transmission tasks), two notifications will appear in the notification panel: one for the data transmission task and the other for the remaining tasks. Removing either notification will cancel the continuous task and remove the other notification. The continuous task notification ID returned by the API is the ID of the data transmission type, which is used to update the data transmission progress.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| request   | [ContinuousTaskRequest](#continuoustaskrequest21) | Yes   | Request information of a continuous task, including the main type and subtype.|

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<[ContinuousTaskNotification](#continuoustasknotification12)> | Promise used to return the continuous task notification information, including the continuous task ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800001 | Memory operation failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
// In atomic services, please remove the WantAgent import.

export default class EntryAbility extends UIAbility {
  notificationId: number = 0; // Save the notification ID.
  continuousTaskId: number | undefined = -1;
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo: wantAgent.WantAgentInfo = {
      // Replace the bundleName and abilityName of the application with the actual ones.
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      // Set the operation type after the notification is tapped.
      actionType: wantAgent.OperationType.START_ABILITY,
      // Custom request code, which is used to identify the operation to execute.
      requestCode: 0,
      // Set the operation properties after the notification is tapped.
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    try {
      // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
      // In atomic services, please replace the following line of code with wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {.
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
        try {
          // If notifications need to be combined, the main type and subtype must be the same, combinedTaskNotification must be set to true, and continuousTaskId must exist and be valid.
          // Request a continuous task whose main type is MODE_LOCATION.
          let modeList: Array<number> = [backgroundTaskManager.BackgroundTaskMode.MODE_LOCATION];
          let subModeList: Array<number> = [backgroundTaskManager.BackgroundTaskSubmode.SUBMODE_NORMAL_NOTIFICATION];
          // Create a continuous task request object.
          let continuousTaskRequest = new backgroundTaskManager.ContinuousTaskRequest();
          continuousTaskRequest.backgroundTaskModes =  modeList;
          continuousTaskRequest.backgroundTaskSubmodes = subModeList;
          continuousTaskRequest.wantAgent = wantAgentObj;
          continuousTaskRequest.combinedTaskNotification = false;
          continuousTaskRequest.continuousTaskId = this.continuousTaskId;
          backgroundTaskManager.startBackgroundRunning(this.context, continuousTaskRequest).then((res: backgroundTaskManager.ContinuousTaskNotification) => {
            console.info(`Operation startBackgroundRunning succeeded. notificationId is ${res.notificationId} continuousTaskId is ${res.continuousTaskId}`);
            this.notificationId = res.notificationId;
            this.continuousTaskId = res.continuousTaskId;
          }).catch((error: BusinessError) => {
            console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
          });
        } catch (error) {
          console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      });
    } catch (error) {
      console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.stopBackgroundRunning

stopBackgroundRunning(context: Context, callback: AsyncCallback&lt;void&gt;): void

Cancels all continuous tasks in the current UIAbility (ServiceAbility in the FA model). This API uses an asynchronous callback to return the result. You can also call the [stopBackgroundRunning](#backgroundtaskmanagerstopbackgroundrunning21) API to cancel a continuous task with the specified ID. This API is applicable when the application functions are complete and the application is about to exit.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| context  | Context                   | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result. If the continuous task is canceled, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied.<br>Applicable versions: 9-18 |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

function callback(error: BusinessError, data: void) {
  if (error) {
    console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
  } else {
    console.info("Operation stopBackgroundRunning succeeded");
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.stopBackgroundRunning(this.context, callback);
    } catch (error) {
      console.error(`Operation stopBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.stopBackgroundRunning

stopBackgroundRunning(context: Context): Promise&lt;void&gt;

Cancels all continuous tasks in the current UIAbility (ServiceAbility in the FA model). This API uses a promise to return the result. You can also call the [stopBackgroundRunning](#backgroundtaskmanagerstopbackgroundrunning21) API to cancel a continuous task with the specified ID. This API is applicable when the application functions are complete and the application is about to exit.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name    | Type     | Mandatory  | Description                                      |
| ------- | ------- | ---- | ---------------------------------------- |
| context | Context | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied.<br>Applicable versions: 9-18 |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
        console.info("Operation stopBackgroundRunning succeeded");
      }).catch((error: BusinessError) => {
        console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
      });
    } catch (error) {
      console.error(`Operation stopBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.stopBackgroundRunning<sup>21+</sup>

stopBackgroundRunning(context: Context, continuousTaskId: number): Promise&lt;void&gt;

Cancels a continuous task with the specified ID. This API uses a promise to return the result. You can also call the [stopBackgroundRunning](#backgroundtaskmanagerstopbackgroundrunning) API to cancel all continuous tasks in the current UIAbility.

This API is applicable when the application functions are complete and the application is about to exit.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| continuousTaskId   | number | Yes   | Continuous task ID.<br>Note: You can obtain the ID of the current continuous task through the return value of the [startBackgroundRunning](#backgroundtaskmanagerstartbackgroundrunning21) API, or obtain information about all continuous tasks through the [getAllContinuousTasks](#backgroundtaskmanagergetallcontinuoustasks20-1) API. |

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9800001 | Memory operation failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  continuousTaskId: number = 0;
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.stopBackgroundRunning(this.context, this.continuousTaskId).then(() => {
        console.info("Operation stopBackgroundRunning succeeded");
      }).catch((error: BusinessError) => {
        console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
      });
    } catch (error) {
      console.error(`Operation stopBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.updateBackgroundRunning<sup>12+</sup>

updateBackgroundRunning(context: Context, bgModes: string[]): Promise&lt;ContinuousTaskNotification&gt;

Updates a continuous task. This API uses a promise to return the result. After the update is successful, only a notification message is displayed, and no prompt tone is played. This API is applicable to scenarios where continuous tasks need to be adjusted to match new services, such as when an application switches from audio/video playback to recording.

Before updating a continuous task, you can call [getAllContinuousTasks](#backgroundtaskmanagergetallcontinuoustasks20) to retrieve information about all existing continuous tasks. If there are no continuous tasks, the update will fail.<br>This API can only be used to update continuous tasks that were requested via the following APIs:<br>[startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback&lt;void&gt;): void](#backgroundtaskmanagerstartbackgroundrunning)<br>[startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;](#backgroundtaskmanagerstartbackgroundrunning-1)<br>[startBackgroundRunning(context: Context, bgModes: string[], wantAgent: WantAgent): Promise&lt;ContinuousTaskNotification&gt;](#backgroundtaskmanagerstartbackgroundrunning12)

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| bgModes    | string[] | Yes   | Types of continuous tasks after the update. For details about the available options, see [Item](../../task-management/continuous-task.md#use-cases).<br> Note: One or more types can be passed.|

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<[ContinuousTaskNotification](#continuoustasknotification12)> | Promise that returns an object of the [ContinuousTaskNotification](#continuoustasknotification12) type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      // You must call startBackgroundRunning before updateBackgroundRunning. Here it is assumed that you have called startBackgroundRunning.
      let list: Array<string> = ["audioPlayback"];
      backgroundTaskManager.updateBackgroundRunning(this.context, list).then((res: backgroundTaskManager.ContinuousTaskNotification) => {
        console.info('Operation updateBackgroundRunning succeeded. Data: ' + JSON.stringify(res));
      }).catch((error: BusinessError) => {
        console.error(`Operation updateBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
      });
    } catch (error) {
      console.error(`Operation updateBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.updateBackgroundRunning<sup>21+</sup>

updateBackgroundRunning(context: Context, request: ContinuousTaskRequest): Promise&lt;ContinuousTaskNotification&gt;

Updates a continuous task. This API uses a promise to return the result. After the update is successful, only a notification message is displayed, and no prompt tone is played. This API is applicable to scenarios where continuous tasks need to be adjusted to match new services, such as when an application switches from audio/video playback to recording.

The following restrictions apply when updating a continuous task:

1. This API can only update continuous tasks requested via [startBackgroundRunning(context: Context, request: ContinuousTaskRequest): Promise&lt;ContinuousTaskNotification&gt;](#backgroundtaskmanagerstartbackgroundrunning21).

2. If the main type and subtype of the background tasks are the same, only the wants information (such as **abilityName**) in **ContinuousTaskRequest.wantAgent** can be updated. If the types are different, the update fails.

3. If the continuous task to be updated or the specified update type contains the data transmission type, a failure message is returned.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| request   | [ContinuousTaskRequest](#continuoustaskrequest21) | Yes   | Continuous task request information, including the ID of the continuous task to be updated.|

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| Promise\<[ContinuousTaskNotification](#continuoustasknotification12)> | Promise used to return the updated continuous task notification information, including the continuous task ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800001 | Memory operation failed. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |
| 9800006 | Notification verification failed for a continuous task. |
| 9800007 | Continuous task storage failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { wantAgent, WantAgent } from '@kit.AbilityKit';
// In atomic services, please remove the WantAgent import.

export default class EntryAbility extends UIAbility {
  notificationId: number = 0; // Save the notification ID.
  continuousTaskId: number | undefined = -1; // Continuous task ID.
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let wantAgentInfo: wantAgent.WantAgentInfo = {
      // Add the bundleName and abilityName of the application to be started. Replace them with the actual ones.
      wants: [
        {
          bundleName: "com.example.myapplication",
          abilityName: "EntryAbility"
        }
      ],
      // Set the operation type after the notification is tapped.
      actionType: wantAgent.OperationType.START_ABILITY,
      // Custom request code, which is used to identify the operation to execute.
      requestCode: 0,
      // Set the operation properties after the notification is tapped.
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
    };

    try {
      // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
      // In atomic services, please replace the following line of code with wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {.
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
        try {
          // You must call startBackgroundRunning before updateBackgroundRunning. Apply for a continuous task in advance.
          let modeList: Array<number> = [backgroundTaskManager.BackgroundTaskMode.MODE_LOCATION];
          let subModeList: Array<number> = [backgroundTaskManager.BackgroundTaskSubmode.SUBMODE_NORMAL_NOTIFICATION];
          // Create a continuous task request object.
          let continuousTaskRequest = new backgroundTaskManager.ContinuousTaskRequest();
          continuousTaskRequest.backgroundTaskModes = modeList;
          continuousTaskRequest.backgroundTaskSubmodes = subModeList;
          continuousTaskRequest.wantAgent = wantAgentObj;
          continuousTaskRequest.combinedTaskNotification = false;
          continuousTaskRequest.continuousTaskId = this.continuousTaskId; // For the update API, the continuous task ID must be passed and the ID must exist. Otherwise, the update fails.
          backgroundTaskManager.updateBackgroundRunning(this.context, continuousTaskRequest).then((res: backgroundTaskManager.ContinuousTaskNotification) => {
            console.info('Operation updateBackgroundRunning succeeded. Data: ' + JSON.stringify(res));
            this.notificationId = res.notificationId;
          }).catch((error: BusinessError) => {
            console.error(`Operation updateBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
          });
        } catch (error) {
          console.error(`Operation updateBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      });
    } catch (error) {
      console.error(`Operation getWantAgent failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.getAllContinuousTasks<sup>20+</sup>

getAllContinuousTasks(context: Context): Promise&lt;ContinuousTaskInfo[]&gt;

Obtains all continuous task information, including the task ID and type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|

**Return value**

| Type                                           | Description         |
|-----------------------------------------------|-------------|
|  Promise&lt;[ContinuousTaskInfo](#continuoustaskinfo20)[]&gt; | Promise that returns all continuous task information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 201 | Permission denied. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      // If no continuous task is requested, an empty array is obtained.
      backgroundTaskManager.getAllContinuousTasks(this.context).then((res: backgroundTaskManager.ContinuousTaskInfo[]) => {
        console.info(`Operation getAllContinuousTasks succeeded. data: ` + JSON.stringify(res));
      }).catch((error: BusinessError) => {
        console.error(`Operation getAllContinuousTasks failed. code is ${error.code} message is ${error.message}`);
      });
    } catch (error) {
      console.error(`Operation getAllContinuousTasks failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.getAllContinuousTasks<sup>20+</sup>

getAllContinuousTasks(context: Context, includeSuspended: boolean): Promise&lt;ContinuousTaskInfo[]&gt;

Obtains all continuous task information, including the task ID and type. It supports specifying whether to include suspended tasks and uses a promise to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| context   | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                            | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| includeSuspended   | boolean                            | Yes   | Whether to obtain the information about the suspended continuous task. The value **true** means to obtain the information, and the value **false** means the opposite.|

**Return value**

| Type                                           | Description         |
|-----------------------------------------------|-------------|
|  Promise&lt;[ContinuousTaskInfo](#continuoustaskinfo20)[]&gt; | Promise that returns all continuous task information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 201 | Permission denied. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      // If no continuous task is requested, an empty array is obtained.
      backgroundTaskManager.getAllContinuousTasks(this.context, false).then((res: backgroundTaskManager.ContinuousTaskInfo[]) => {
        console.info(`Operation getAllContinuousTasks succeeded. data: ` + JSON.stringify(res));
      }).catch((error: BusinessError) => {
        console.error(`Operation getAllContinuousTasks failed. code is ${error.code} message is ${error.message}`);
      });
    } catch (error) {
      console.error(`Operation getAllContinuousTasks failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.on('continuousTaskCancel')<sup>15+</sup>

on(type: 'continuousTaskCancel', callback: Callback&lt;ContinuousTaskCancelInfo&gt;): void

Subscribes to continuous task cancellation events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| type   | string                            | Yes   | Event type. The value is fixed at **'continuousTaskCancel'**, indicating that a continuous task is canceled.|
| callback   | Callback\<[ContinuousTaskCancelInfo](#continuoustaskcancelinfo15)>       | Yes    | Callback used to return information such as the reason for canceling a continuous task. This callback is triggered when a continuous task is canceled. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible cause: 1. Callback parameter error; 2. Register a exist callback type; 3. Parameter verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

function callback(info: backgroundTaskManager.ContinuousTaskCancelInfo) {
  console.info('continuousTaskCancel callback id ' + info.id);
  console.info('continuousTaskCancel callback reason ' + info.reason);
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.on("continuousTaskCancel", callback);
    } catch (error) {
      console.error(`Operation onContinuousTaskCancel failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.off('continuousTaskCancel')<sup>15+</sup>

off(type: 'continuousTaskCancel', callback?: Callback&lt;ContinuousTaskCancelInfo&gt;): void

Unsubscribes from continuous task cancellation events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| type   | string                            | Yes    | Event type. The value is fixed at **'continuousTaskCancel'**, indicating that a continuous task is canceled. |
| callback   | Callback\<[ContinuousTaskCancelInfo](#continuoustaskcancelinfo15)>       | No   | Callback for which listening is cancelled. If this parameter is left unspecified, all registered callbacks are cancelled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible cause: 1. Callback parameter error; 2. Unregister type has not register; 3. Parameter verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

function callback(info: backgroundTaskManager.ContinuousTaskCancelInfo) {
  console.info('continuousTaskCancel callback id ' + info.id);
  console.info('continuousTaskCancel callback reason ' + info.reason);
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.off("continuousTaskCancel", callback);
    } catch (error) {
      console.error(`Operation onContinuousTaskCancel failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.on('continuousTaskSuspend')<sup>20+</sup>

on(type: 'continuousTaskSuspend', callback: Callback&lt;ContinuousTaskSuspendInfo&gt;): void

Registers a listener for continuous task suspension. This API uses an asynchronous callback to return the result. After the callback is registered, if the system detects for the first time that the application does not execute the corresponding service, the system does not directly cancel the continuous task. Instead, it will mark the task as suspended. If the detection failures persist, the system will cancel the continuous task.<br>When a continuous task is suspended, the application will be suspended when switched to the background and automatically activated when brought back to the foreground.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| type   | string                            | Yes   | Event type. The value is fixed at **'continuousTaskSuspend'**, indicating that the continuous task is suspended.|
| callback   | Callback\<[ContinuousTaskSuspendInfo](#continuoustasksuspendinfo20)>       | Yes    | Callback used to return information such as the reason for suspending a continuous task. This callback is triggered when a continuous task is suspended. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

function callback(info: backgroundTaskManager.ContinuousTaskSuspendInfo) {
  console.info('continuousTaskSuspend callback continuousTaskId: ' + info.continuousTaskId);
  console.info('continuousTaskSuspend callback suspendState: ' + info.suspendState);
  console.info('continuousTaskSuspend callback suspendReason: ' + info.suspendReason);
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.on("continuousTaskSuspend", callback);
    } catch (error) {
      console.error(`Operation onContinuousTaskSuspend failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.off('continuousTaskSuspend')<sup>20+</sup>

off(type: 'continuousTaskSuspend', callback?: Callback&lt;ContinuousTaskSuspendInfo&gt;): void

Unregisters from the listener for continuous task suspension. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| type   | string                            | Yes   | Event type. The value is fixed at **'continuousTaskSuspend'**, indicating that the continuous task is suspended.|
| callback   | Callback\<[ContinuousTaskSuspendInfo](#continuoustasksuspendinfo20)>       | No   | Callback used to unregister from the listener for continuous task suspension. If this parameter is not passed, all listeners are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

function callback(info: backgroundTaskManager.ContinuousTaskSuspendInfo) {
  console.info('continuousTaskSuspend callback continuousTaskId: ' + info.continuousTaskId);
  console.info('continuousTaskSuspend callback suspendState: ' + info.suspendState);
  console.info('continuousTaskSuspend callback suspendReason: ' + info.suspendReason);
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.off("continuousTaskSuspend", callback);
    } catch (error) {
      console.error(`Operation offContinuousTaskSuspend failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.on('continuousTaskActive')<sup>20+</sup>

on(type: 'continuousTaskActive', callback: Callback&lt;ContinuousTaskActiveInfo&gt;): void

Registers a listener for continuous task activation. This API uses an asynchronous callback to return the result. The application returns to the foreground to activate the suspended continuous task.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| type   | string                            | Yes   | Event type. The value is fixed at **'continuousTaskActive'**, indicating that the continuous task is activated.|
| callback   | Callback\<[ContinuousTaskActiveInfo](#continuoustaskactiveinfo20)>       | Yes    | Callback used to return the activation information about a continuous task. This callback is triggered when a suspended continuous task is activated. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

function callback(info: backgroundTaskManager.ContinuousTaskActiveInfo) {
  console.info('continuousTaskActive callback id: ' + info.id);
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.on("continuousTaskActive", callback);
    } catch (error) {
      console.error(`Operation onContinuousTaskActive failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## backgroundTaskManager.off('continuousTaskActive')<sup>20+</sup>

off(type: 'continuousTaskActive', callback?: Callback&lt;ContinuousTaskActiveInfo&gt;): void

Unregisters from the listener for continuous task activation. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Parameters**

| Name      | Type                                | Mandatory  | Description                                      |
| --------- | ---------------------------------- | ---- | ---------------------------------------- |
| type   | string                            | Yes   | Event type. The value is fixed at **'continuousTaskActive'**, indicating that the continuous task is activated.|
| callback   | Callback\<[ContinuousTaskActiveInfo](#continuoustaskactiveinfo20)>       | No   | Callback used to unregister from the listener for continuous task activation. If this parameter is not passed, all listeners are unsubscribed from.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

function callback(info: backgroundTaskManager.ContinuousTaskActiveInfo) {
  console.info('continuousTaskActive callback id: ' + info.id);
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      backgroundTaskManager.off("continuousTaskActive", callback);
    } catch (error) {
      console.error(`Operation offContinuousTaskActive failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## DelaySuspendInfo

Defines the information about the transient task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| Name            | Type    | Read-Only  | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| requestId       | number | No   | No   | Request ID of the transient task.                              |
| actualDelayTime | number | No   | No   | Actual duration of the transient task requested by the application, in milliseconds.<br> Note: The maximum duration of a transient task is 3 minutes in normal cases. In the case of a low battery ([BatteryCapacityLevel](../apis-basic-services-kit/js-apis-battery-info.md#batterycapacitylevel9) set to **LEVEL_LOW**), the maximum duration is decreased to 1 minute.|

## TransientTaskInfo<sup>20+</sup>

Describes all transient task information.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

| Name            | Type                                     | Read-Only  | Optional  | Description             |
| --------------- |-----------------------------------------| ---- | ---- |-----------------|
| remainingQuota       | number                                  | No   | No   | Remaining quota of the application on the current day, in ms.    |
| transientTasks | [DelaySuspendInfo](#delaysuspendinfo)[] | No   | No   | All information about the requested transient task.|

## BackgroundMode

Defines the type of a continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

<!--Table: 30%; 10%; 60%-->

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| DATA_TRANSFER           | 1    | Data transfer.<br>Use scenario: upload and download in non-hosting mode, for example, uploading or downloading data in the background of a browser.<br>Note: During data transfer, the application needs to update the progress. If the progress is not updated for more than 10 minutes, the continuous task of the **DATA_TRANSFER** type will be canceled.<br>The notification type of the progress update must be live view. For details, see the example in [startBackgroundRunning()](#backgroundtaskmanagerstartbackgroundrunning12).      |
| AUDIO_PLAYBACK          | 2    | Audio and video playback.<br>Use scenario: audio/video playback in the background and audio/video casting.<br>**Atomic service API**: This API can be used in atomic services since API version 12.<br>Note: Since API version 20, if an application requests or updates a continuous task of the **AUDIO_PLAYBACK** type without connecting to AVSession, a notification will appear in the notification panel once the task is successfully requested or updated.<br>Once AVSession is connected, notifications will be sent by AVSession instead of the background task module.<br>For API version 19 and earlier versions, the background task module does not display notifications in the notification panel.                |
| AUDIO_RECORDING         | 3    | Audio recording.<br>Use scenario: recording and screen capture in the background.<!--Del--><br>Note: No notification is displayed if a system application requests or updates a continuous task.<!--DelEnd-->                    |
| LOCATION                | 4    | Positioning and navigation.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.                  |
| BLUETOOTH_INTERACTION   | 5    | Bluetooth-related services.<br>Use scenario: An application moves to the background while transferring files via Bluetooth.                 |
| MULTI_DEVICE_CONNECTION | 6    | Multi-device connection.<br>Use scenario: distributed service connection and casting.<br>**Atomic service API**: This API can be used in atomic services since API version 12.                |
| VOIP<sup>13+</sup> | 8    | Audio and video calls.<br>Use scenario: Chat applications (with audio and video services) transition into the background during audio and video calls.<!--Del--><br>Note: No notification is displayed if a system application requests or updates a continuous task.<!--DelEnd-->                 |
| TASK_KEEPING            | 9    | Computing tasks.<br>Use scenario: antivirus software.<br>Note: Starting from API version 21, this capability is available for PCs/2-in-1 devices, and non-PCs/2-in-1 devices that have obtained the ACL permission [ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM](../../../application-dev/security/AccessToken/restricted-permissions.md#ohospermissionkeep_background_running_system). In API version 20 and earlier versions, this task type is limited to PCs/2-in-1 devices only.       |

## ContinuousTaskNotification<sup>12+</sup>

Describes the information about a continuous-task notification.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name            | Type    | Read-Only    | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| slotType       | [notificationManager.SlotType](../apis-notification-kit/js-apis-notificationManager.md#slottype) | No   | No   | Slot type of a continuous-task notification.<br>Note: After a continuous task is successfully requested or updated, no prompt tone is played.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| contentType | [notificationManager.ContentType](../apis-notification-kit/js-apis-notificationManager.md#contenttype) | No   | No   | Content type of a continuous-task notification.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| notificationId | number | No   | No   | ID of the continuous-task notification.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| continuousTaskId<sup>15+</sup> | number | No   | Yes   | ID of a continuous task.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.|

## ContinuousTaskCancelInfo<sup>15+</sup>

Describes the information about the cancellation of a continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name            | Type    | Read-Only  | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| reason | [ContinuousTaskCancelReason](#continuoustaskcancelreason15) | No   | No   | Reason for canceling the continuous task.|
| id | number | No   | No   | ID of the continuous task canceled.|
| detailedReason | [ContinuousTaskDetailedCancelReason](#continuoustaskdetailedcancelreason) | No   | Yes   | Detailed reason for canceling the continuous task.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## ContinuousTaskCancelReason<sup>15+</sup>

Describes the reason for canceling a continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

<!--Table: 40%; 10%; 50%-->

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| USER_CANCEL             | 1    | The task is canceled by the user.                 |
| SYSTEM_CANCEL           | 2    | The task is canceled by the system.                 |
| USER_CANCEL_REMOVE_NOTIFICATION         | 3    | User removal notification. This value is reserved.                   |
| SYSTEM_CANCEL_DATA_TRANSFER_LOW_SPEED                | 4    | A continuous task of the DATA_TRANSFER type is requested, but the data transmission rate is low. This value is reserved.                 |
| SYSTEM_CANCEL_AUDIO_PLAYBACK_NOT_USE_AVSESSION   | 5    | A continuous task of the AUDIO_PLAYBACK type is requested, but the [AVSession](../../media/avsession/avsession-overview.md) is not accessed. This value is reserved.                 |
| SYSTEM_CANCEL_AUDIO_PLAYBACK_NOT_RUNNING | 6    | A continuous task of the AUDIO_PLAYBACK type is requested, but the audio and video are not played. This value is reserved.                |
| SYSTEM_CANCEL_AUDIO_RECORDING_NOT_RUNNING | 7    | A continuous task of the AUDIO_RECORDING type is requested, but audio recording is not in progress. This value is reserved.                |
| SYSTEM_CANCEL_NOT_USE_LOCATION            | 8    | A continuous task of the **LOCATION** type is requested, but the location service is not in use. This value is reserved.       |
| SYSTEM_CANCEL_NOT_USE_BLUETOOTH            | 9    | A continuous task of the BLUETOOTH_INTERACTION type is requested, but Bluetooth-related services are not used. This value is reserved.       |
| SYSTEM_CANCEL_NOT_USE_MULTI_DEVICE            | 10    | A continuous task of the MULTI_DEVICE_CONNECTION type is requested, but multi-device connection is not used. This value is reserved.       |
| SYSTEM_CANCEL_USE_ILLEGALLY            | 11    | A continuous task of an invalid type is used. For example, a continuous task of the **AUDIO_PLAYBACK** type is requested, but the audio playback and location services are in use. This value is reserved.       |

## ContinuousTaskDetailedCancelReason

Describes the detailed reason for canceling a continuous task.

**Since**: 26.0.0

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Model restriction**: This API can be used only in the stage model.

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| USER_CANCEL_REMOVE_NOTIFICATION           | 3    | User removal notification.|
| SYSTEM_CANCEL_DATA_TRANSFER_LOW_SPEED     | 4    | A continuous task of the **DATA_TRANSFER** type is requested, but the data transmission rate is low.|
| SYSTEM_CANCEL_AUDIO_PLAYBACK_NOT_RUNNING  | 6    | A continuous task of the **AUDIO_PLAYBACK** type is requested, but the audio and video are not played. <br/>Note: You need to register [on('continuousTaskSuspend')](#backgroundtaskmanageroncontinuoustasksuspend20) first. When the continuous detection fails, the system cancels the corresponding continuous task and returns the cancellation reason.   |
| SYSTEM_CANCEL_AUDIO_RECORDING_NOT_RUNNING | 7    | A continuous task of the **AUDIO_RECORDING** type is requested, but audio recording is not in progress.      |
| SYSTEM_CANCEL_NOT_USE_LOCATION            | 8    | A continuous task of the **LOCATION** type is requested, but the location service is not in use.     |
| SYSTEM_CANCEL_NOT_USE_BLUETOOTH           | 9    | A continuous task of the **BLUETOOTH_INTERACTION** type is requested, but Bluetooth is not in use.|
| SYSTEM_CANCEL_NOT_USE_MULTI_DEVICE        | 10   | A continuous task of the **MULTI_DEVICE_CONNECTION** type is requested, but the multi-device connection service is not in use.|
| SYSTEM_CANCEL_USE_ILLEGALLY               | 11   | A continuous task of an invalid type is used. For example, a continuous task of the **AUDIO_PLAYBACK** type is requested, but the audio playback and location services are in use. |
| SYSTEM_CANCEL_DATA_TRANSFER_NOT_UPDATE    | 12   | A continuous task of the **DATA_TRANSFER** type is requested, but the progress is not updated for a long time (the first update takes more than 10 minutes). |
| SYSTEM_CANCEL_VOIP_NOT_RUNNING            | 13   | A continuous task of the **VOIP** type is requested, but no audio stream or recording stream is in progress. |
| SYSTEM_CANCEL_USER_UNAUTHORIZED           | 14   | A continuous task of the special scenario type is requested, but the user is not authorized. |

## BackgroundSubMode<sup>16+</sup>

Defines the subtype of a continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| CAR_KEY           | 1    | Car key.<br>**NOTE**<br>1. The car key subtype takes effect only when a continuous task of the BLUETOOTH_INTERACTION type is requested.<br>2. Continuous tasks of this type cannot be updated through the [updateBackgroundRunning](#backgroundtaskmanagerupdatebackgroundrunning12) API.                 |

## BackgroundModeType<sup>16+</sup>

Defines the type of a continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| SUB_MODE           | 'subMode'    | Subtype.                 |

## ContinuousTaskSuspendInfo<sup>20+</sup>

Describes the information about a suspended continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name            | Type    | Read-Only  | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| continuousTaskId | number | No   | No   | ID of the suspended continuous task.|
| suspendState | boolean | No   | No   | Continuous task state. The value **false** indicates that the task is activated, and the value **true** indicates that the task is suspended.|
| suspendReason | [ContinuousTaskSuspendReason](#continuoustasksuspendreason20) | No   | No   | Reason why the continuous task is suspended.|
| suspendMessage | [SuspendMessage](#suspendmessage) | No   | Yes   | Describes the information about a suspended continuous task.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## SuspendMessage

Describes the reason why a continuous task is suspended.

**Since**: 26.0.0

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Model restriction**: This API can be used only in the stage model.

| Name            | Type    | Read-Only  | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| message       | string | No   | No   | Suspension message.    |
| reason       | [ContinuousTaskSuspendReason](#continuoustasksuspendreason20) | No   | No   | Reason why the continuous task is suspended.    |

## ContinuousTaskSuspendReason<sup>20+</sup>

Describes the reason why a continuous task is suspended.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| SYSTEM_SUSPEND_DATA_TRANSFER_LOW_SPEED     | 4    | A continuous task of the **DATA_TRANSFER** type is requested, but the data transmission rate is low.                |
| SYSTEM_SUSPEND_AUDIO_PLAYBACK_NOT_USE_AVSESSION   | 5    | A continuous task of the **AUDIO_PLAYBACK** type is requested, but [AVSession](../../media/avsession/avsession-overview.md) is not accessed.                 |
| SYSTEM_SUSPEND_AUDIO_PLAYBACK_NOT_RUNNING  | 6    | A continuous task of the **AUDIO_PLAYBACK** type is requested, but audio playback is not in progress. |
| SYSTEM_SUSPEND_AUDIO_RECORDING_NOT_RUNNING | 7    | A continuous task of the **AUDIO_RECORDING** type is requested, but audio recording is not in progress. |
| SYSTEM_SUSPEND_LOCATION_NOT_USED           | 8    | A continuous task of the **LOCATION** type is requested, but the location service is not in use.|
| SYSTEM_SUSPEND_BLUETOOTH_NOT_USED          | 9    | A continuous task of the **BLUETOOTH_INTERACTION** type is requested, but Bluetooth is not in use.|
| SYSTEM_SUSPEND_MULTI_DEVICE_NOT_USED       | 10   | A continuous task of the **MULTI_DEVICE_CONNECTION** type is requested, but the multi-device connection service is not in use. |
| SYSTEM_SUSPEND_USED_ILLEGALLY              | 11    | A continuous task of an invalid type is used. For example, a continuous task of the **AUDIO_PLAYBACK** type is requested, but the audio playback and location services are in use. This value is reserved.       |
| SYSTEM_SUSPEND_SYSTEM_LOAD_WARNING         | 12    | A continuous task is suspended due to high system load. This value is reserved.       |
| SYSTEM_SUSPEND_VOIP_NOT_USED               | 13   | A continuous task of the **VOIP** type is requested, but no audio stream or recording stream is in progress.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SYSTEM_SUSPEND_BLUETOOTH_DATA_NOT_EXIST    | 14   | A continuous task of the **BLUETOOTH_INTERACTION** type is requested, but there is no Bluetooth data flow for a period of time.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SYSTEM_SUSPEND_POSITION_NOT_MOVED          | 15   | A continuous task of the **LOCATION** type is requested, but the device is absolutely still for a period of time.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SYSTEM_SUSPEND_AUDIO_PLAYBACK_MUTE         | 16   | A continuous task of the **AUDIO_PLAYBACK** type is requested, but the device is muted for a period of time.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SYSTEM_SUSPEND_NEARLINK_NOT_USED         | 17   | A continuous task of the **NEARLINK** type is requested, but there is no NearLink connection for a period of time.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SYSTEM_SUSPEND_NEARLINK_DATA_NOT_EXIST           | 18   | A continuous task of the **NEARLINK** type is requested, but there is no NearLink data flow for a period of time.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| SYSTEM_SUSPEND_USER_UNAUTHORIZED           | 19   | A continuous task of the special type is requested, but the user is not authorized.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## ContinuousTaskActiveInfo<sup>20+</sup>

Describes the activation information of a continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name            | Type    | Read-Only  | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| id | number | No   | No   | ID of the activated continuous task.|

## ContinuousTaskInfo<sup>20+</sup>

Describes the continuous task information.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

<!--Table: 25%; 15%; 8%; 8%; 44%-->

| Name         | Type      | Read-Only  | Optional  | Description                   |
|-------------|----------| ---- | ---- |-----------------------|
| abilityName | string   | No   | No   | UIAbility name.         |
| uid         | number   | No   | No   | Application UID.              |
| pid         | number   | No   | No   | Application PID.              |
| isFromWebView | boolean  | No   | No   | Whether to request a continuous task in WebView mode, that is, whether to request a continuous task through the system proxy application. The value **true** indicates that the Webview mode is used, and the value **false** indicates that the Webview mode is not used.|
| backgroundModes | string[] | No   | No   | [Type of a continuous task](#backgroundmode).              |
| backgroundSubModes | string[] | No   | No   | [Subtype of a continuous task](#backgroundsubmode16).             |
| notificationId | number   | No   | No   | Notification ID.               |
| continuousTaskId | number   | No   | No   | Continuous task ID.             |
| abilityId | number   | No   | No   | UIAbility ID.        |
| wantAgentBundleName | string   | No   | No   |  Bundle name configured in [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md). **WantAgent** is a notification parameter used to specify the target page when a continuous task notification is tapped.       |
| wantAgentAbilityName | string   | No   | No   |  Ability name configured in [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md). **WantAgent** is a notification parameter used to specify the target page when a continuous task notification is tapped.|
| suspendState | boolean   | No   | No   | Whether the requested continuous task is suspended. The value **true** indicates that the task is suspended, and the value **false** indicates that the task is activated.|
| bundleName<sup>23+</sup> | string   | No   | Yes   | Application bundle name.         |
| appIndex<sup>23+</sup>   | number   | No   | Yes   | Index of an application clone.              |

## ContinuousTaskRequest<sup>21+</sup>

Specifies details of the continuous task being requested or updated. It is typically used as input for the [startBackgroundRunning()](#backgroundtaskmanagerstartbackgroundrunning21) and [updateBackgroundRunning()](#backgroundtaskmanagerupdatebackgroundrunning21) APIs. Note that:

1. When requesting a continuous task via [startBackgroundRunning()](#backgroundtaskmanagerstartbackgroundrunning21), notifications will be combined if the main type and subtype of the continuous task to be requested are the same as those of the existing continuous task in the current application, and the **combinedTaskNotification** value is **true** for both tasks. Otherwise, notifications will not be combined.

2. Notifications will not be combined if the continuous task has no notification. For details about whether notifications are sent for the continuous task, see [BackgroundTaskMode](#backgroundtaskmode21).

3. Notifications cannot be combined if the continuous task includes data transmission.

4. Notifications that have been combined cannot be canceled. If notifications have been combined, they cannot be updated to uncombined.

5. After notifications are combined, tapping the notification will redirect to the UIAbility corresponding to the first requested continuous task. If the update API is called, the redirection will target the UIAbility corresponding to the last updated continuous task.

6. When the [updateBackgroundRunning()](#backgroundtaskmanagerupdatebackgroundrunning21) API is called to update a continuous task, the input **continuousTaskId** must exist. Otherwise, the update fails.

7. Continuous tasks of the [MODE_SPECIAL_SCENARIO_PROCESSING](#backgroundtaskmode21) type are supported since API version 22. This task type must be used independently and notifications cannot be combined. Specifically, when you request or update a continuous task, it must be of the **MODE_SPECIAL_SCENARIO_PROCESSING** type. Otherwise, an error is returned.

### Properties

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

<!--Table: 25%; 25%; 8%; 8%; 44%-->

| Name            | Type    | Read-Only  | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| backgroundTaskModes       | [BackgroundTaskMode](#backgroundtaskmode21)[] | No   | No   | Main type of a continuous task.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>Note: The main type must match the subtype.    |
| backgroundTaskSubmodes | [BackgroundTaskSubmode](#backgroundtasksubmode21)[] | No   | No   | Subtype of a continuous task.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>Note: The main type must match the subtype.|
| wantAgent | [WantAgent](../apis-ability-kit/js-apis-app-ability-wantAgent.md#wantagent) | No   | No   | Notification parameters, which are used to specify the target page that is redirected to when a continuous task notification is clicked.<br>**Model restriction**: This API can be used only in the stage model.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.|
| combinedTaskNotification | boolean   | No   | Yes   | Whether to combine notifications. The value **true** means to combine notifications, and the value **false** (default) means the opposite.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>Note: This property does not take effect in [updateBackgroundRunning](#backgroundtaskmanagerupdatebackgroundrunning21) API. If notifications need to be combined for an existing task, request the task again and set the value to **true**.|
| continuousTaskId | number   | No   | Yes   | Continuous task ID. The default value is **-1**.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>Note: If **combinedTaskNotification** is set to true, this property is mandatory and the corresponding ID must exist.<br>Additionally, this property is mandatory (with the corresponding ID required) when used as an input parameter for the [updateBackgroundRunning](#backgroundtaskmanagerupdatebackgroundrunning21) API.<br>You can call the [getAllContinuousTasks](#backgroundtaskmanagergetallcontinuoustasks20-1) API to view information about all continuous tasks.  |

### isModeSupported<sup>21+</sup>

isModeSupported(): boolean

Checks whether **BackgroundTaskMode** specified in [ContinuousTaskRequest](#continuoustaskrequest21) is supported. For details, see [BackgroundTaskMode](#backgroundtaskmode21).

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Return value**

| Type            | Description              |
| -------------- | ---------------- |
| boolean | Whether **BackgroundTaskMode** is supported. The value **true** means it is supported, and the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    let isModeSupported: boolean = false; 
    // Create a continuous task request object.
    let continuousTaskRequest = new backgroundTaskManager.ContinuousTaskRequest();
    let modeList: Array<number> = [backgroundTaskManager.BackgroundTaskMode.MODE_TASK_KEEPING];
    continuousTaskRequest.backgroundTaskModes = modeList;
    try {
      isModeSupported = continuousTaskRequest.isModeSupported();
      console.info(`Operation isModeSupported succeeded. isModeSupported is ${isModeSupported}`);
    } catch (error) {
      console.error(`Operation startBackgroundRunning failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

### requestAuthFromUser<sup>22+</sup>

requestAuthFromUser(context: Context, callback: Callback&lt;UserAuthResult&gt;): void

Requests user authorization to run tasks continuously in the background. This API uses an asynchronous callback to return the result. If the API call is successful, a banner notification with a sound is sent to request user authorization. The user can choose to grant authorization once or grant authorization always. When the app requests authorization again, the previous authorization result will be directly returned, and no banner notification will be displayed. It is recommended that this API be called when the application is running in the foreground to prompt the user to grant authorization. This API is applicable only to continuous tasks of the [MODE_SPECIAL_SCENARIO_PROCESSING](#backgroundtaskmode21) type.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Device behavior differences**: This API can be properly called on smartphones, tablets, and PCs/2-in-1 devices. If it is called on other devices, error code 9800005 is returned.

**Parameters**

| Name     | Type                                                 | Mandatory  | Description          |
| -------- |-----------------------------------------------------| ---- |--------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| callback | Callback&lt;[UserAuthResult](#userauthresult22)&gt; | Yes   | Callback used to return the user authorization result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

function callbackAuth(authResult: backgroundTaskManager.UserAuthResult) {
  console.info('Operation requestAuthFromUser success. auth result: ' + JSON.stringify(authResult));
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // Create a continuous task request object.
    let continuousTaskRequest = new backgroundTaskManager.ContinuousTaskRequest();
    let modeList: Array<number> = [backgroundTaskManager.BackgroundTaskMode.MODE_SPECIAL_SCENARIO_PROCESSING];
    continuousTaskRequest.backgroundTaskModes = modeList;
    let subModeList: Array<number> = [backgroundTaskManager.BackgroundTaskSubmode.SUBMODE_MEDIA_PROCESS_NORMAL_NOTIFICATION];
    continuousTaskRequest.backgroundTaskSubmodes = subModeList;
    try {
      continuousTaskRequest.requestAuthFromUser(this.context, callbackAuth);
      console.info('Operation requestAuthFromUser succeeded.');
    } catch (error) {
      console.error(`Operation requestAuthFromUser failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

### requestAuthFromUserByDialog

requestAuthFromUserByDialog(context: Context, callback: Callback&lt;UserAuthResult&gt;): void

Requests user authorization to run tasks continuously in the background. This API uses an asynchronous callback to return the result. If the API call is successful, a dialog box is displayed for authorization. The user can choose to grant authorization once, grant authorization always, or not to grant authorization. When the app requests authorization again, the previous authorization result will be directly returned, and no dialog box will be displayed. It is recommended that this API be called when the application is running in the foreground to prompt the user to grant authorization. This API is applicable only to continuous tasks of the [MODE_SPECIAL_SCENARIO_PROCESSING](#backgroundtaskmode21) type.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Device behavior differences**: This API can be properly called on smartphones, tablets, and PCs/2-in-1 devices. If it is called on other devices, error code 9800005 is returned.

**Parameters**

| Name     | Type                                                 | Mandatory  | Description          |
| -------- |-----------------------------------------------------| ---- |--------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|
| callback | Callback&lt;[UserAuthResult](#userauthresult22)&gt; | Yes   | Callback used to return the user authorization result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

function callbackAuth(authResult: backgroundTaskManager.UserAuthResult) {
  console.info('Operation requestAuthFromUserByDialog success. auth result: ' + JSON.stringify(authResult));
}

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        return;
      }
      try {
        // Create a continuous task request object.
        let continuousTaskRequest = new backgroundTaskManager.ContinuousTaskRequest();
        let modeList: Array<number> = [backgroundTaskManager.BackgroundTaskMode.MODE_SPECIAL_SCENARIO_PROCESSING];
        continuousTaskRequest.backgroundTaskModes = modeList;
        let subModeList: Array<number> = [backgroundTaskManager.BackgroundTaskSubmode.SUBMODE_MEDIA_PROCESS_NORMAL_NOTIFICATION];
        continuousTaskRequest.backgroundTaskSubmodes = subModeList;
        continuousTaskRequest.requestAuthFromUserByDialog(this.context, callbackAuth);
        console.info('Operation requestAuthFromUserByDialog succeeded.');
      } catch (error) {
        console.error(`Operation requestAuthFromUserByDialog failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
      }
    });
  }
};
```

### checkSpecialScenarioAuth<sup>22+</sup>

checkSpecialScenarioAuth(context: Context): Promise&lt;UserAuthResult&gt;

Checks whether the user has authorized tasks to run continuously in the background. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Device behavior differences**: This API can be properly called on smartphones, tablets, and PCs/2-in-1 devices. If it is called on other devices, error code 9800005 is returned.

**Parameters**

| Name     | Type                                                 | Mandatory  | Description          |
| -------- |-----------------------------------------------------| ---- |--------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|

**Return value**

| Type            | Description               |
| -------------- |-------------------|
| Promise&lt;[UserAuthResult](#userauthresult22)&gt; | Promise used to return the user authorization result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      // Create a continuous task request object.
      let continuousTaskRequest = new backgroundTaskManager.ContinuousTaskRequest();
      continuousTaskRequest.checkSpecialScenarioAuth(this.context).then((res: backgroundTaskManager.UserAuthResult) => {
        console.info('Operation checkSpecialScenarioAuth succeeded. data: ' + JSON.stringify(res));
      }).catch((error: BusinessError) => {
        console.error(`Operation checkSpecialScenarioAuth failed. code is ${error.code} message is ${error.message}`);
      });
    } catch (error) {
      console.error(`Operation checkSpecialScenarioAuth failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

### checkSpecialScenarioAuthResult

checkSpecialScenarioAuthResult(context: Context): Promise&lt;UserAuthResult&gt;

Checks whether the user has authorized tasks to run continuously in the background. This API uses a promise to return the result. If the user has not granted authorization, [NOT_DETERMINED](#userauthresult22) is returned. If no continuous task of the [MODE_SPECIAL_SCENARIO_PROCESSING](#backgroundtaskmode21) type is configured, [NOT_SUPPORTED](#userauthresult22) is returned.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.KEEP_BACKGROUND_RUNNING

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**Device behavior differences**: This API can be properly called on smartphones, tablets, and PCs/2-in-1 devices. If it is called on other devices, error code 9800005 is returned.

**Parameters**

| Name     | Type                                                 | Mandatory  | Description          |
| -------- |-----------------------------------------------------| ---- |--------------|
| context  | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-context.md).<br> Note: Continuous tasks can be requested only by the UIAbility in the stage model and the ServiceAbility in the FA model.|

**Return value**

| Type            | Description               |
| -------------- |-------------------|
| Promise&lt;[UserAuthResult](#userauthresult22)&gt; | Promise used to return the user authorization result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    try {
      // Create a continuous task request object.
      let continuousTaskRequest = new backgroundTaskManager.ContinuousTaskRequest();
      continuousTaskRequest.checkSpecialScenarioAuthResult(this.context).then((res: backgroundTaskManager.UserAuthResult) => {
        console.info('Operation checkSpecialScenarioAuthResult succeeded. data: ' + JSON.stringify(res));
      }).catch((error: BusinessError) => {
        console.error(`Operation checkSpecialScenarioAuthResult failed. code is ${error.code} message is ${error.message}`);
      });
    } catch (error) {
      console.error(`Operation checkSpecialScenarioAuthResult failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
    }
  }
};
```

## BackgroundTaskMode<sup>21+</sup>

Main type of a continuous task. It is usually used together with the subtype [BackgroundTaskSubmode](#backgroundtasksubmode21). For details, see the mapping table. They are used as the input parameters of [startBackgroundRunning](#backgroundtaskmanagerstartbackgroundrunning21) and [updateBackgroundRunning](#backgroundtaskmanagerupdatebackgroundrunning21) newly added in API version 21, which are used to specify the type of a continuous task.<br>When the main type of the continuous task is **MODE_SPECIAL_SCENARIO_PROCESSING**, or that of a non-PC/2-in-1 device is **MODE_TASK_KEEPING**, you need to request the ACL permission [ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM](../../../application-dev/security/AccessToken/restricted-permissions.md#ohospermissionkeep_background_running_system) before calling APIs related to continuous tasks. In other scenarios, this permission is not required.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

<!--Table: 40%; 10%; 50%-->

| Name                    | Value | Description                   |
| ------------------------ | ---- | --------------------- |
| MODE_DATA_TRANSFER              | 1         | Data transfer.<br>Use scenario: upload and download in non-hosting mode, for example, uploading or downloading data in the background of a browser.<br>**NOTE**<br>1. During data transfer, the application needs to update the progress. If the progress is not updated for more than 10 minutes, the continuous task of the **DATA_TRANSFER** type will be canceled.<br>2. The notification type of the progress update must be live view. For details, see the example in [startBackgroundRunning()](#backgroundtaskmanagerstartbackgroundrunning12).                |
| MODE_AUDIO_PLAYBACK             | 2         | Audio and video playback.<br>Use scenario: audio/video playback in the background and audio/video casting.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.<br>Note: If a continuous task of the **MODE_AUDIO_PLAYBACK** type is requested or updated without connecting to AVSession, a notification will appear in the notification panel once the task is successfully requested or updated. Once AVSession is connected, notifications will be sent by AVSession instead of the background task module.             |
| MODE_AUDIO_RECORDING            | 3         | Audio recording.<br>Use scenario: recording and screen capture in the background.<!--Del--><br>Note: No notification is displayed if a system application requests or updates a continuous task.<!--DelEnd-->                 |
| MODE_LOCATION                   | 4         | Positioning and navigation.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.                  |
| MODE_BLUETOOTH_INTERACTION      | 5         | Bluetooth-related services.<br>Use scenario: An application moves to the background while transferring files via Bluetooth.           |
| MODE_MULTI_DEVICE_CONNECTION    | 6         | Multi-device connection.<br>Use scenario: distributed service connection and casting.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.          |
| MODE_VOIP                       | 8         | Audio and video calls.<br>Use scenario: Chat applications (with audio and video services) transition into the background during audio and video calls. <!--Del--><br>Note: No notification is displayed if a system application requests or updates a continuous task.<!--DelEnd-->            |
| MODE_TASK_KEEPING               | 9         | Computing tasks.<br>Use scenario: antivirus software.<br>Note: This capability is available only to PCs/2-in-1 devices, or non-PCs/2-in-1 devices that have obtained the ACL permission [ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM](../../../application-dev/security/AccessToken/restricted-permissions.md#ohospermissionkeep_background_running_system).|
| MODE_AV_PLAYBACK_AND_RECORD<sup>22+</sup>    | 12         | Multimedia services.<br>Use scenarios: audio/video playback, recording, and audio/video calls. The scenario must match that of the subtype. You can select this task type or the corresponding main type for preceding scenarios. For example, you can request a continuous task of the **MODE_AUDIO_PLAYBACK** or **MODE_AV_PLAYBACK_AND_RECORD** type for audio/video playback.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.            |
| MODE_SPECIAL_SCENARIO_PROCESSING<sup>22+</sup> | 13 | Special scenarios (available only for smartphones, tablets, PCs/2-in-1 devices).<br/>Use scenarios: An application exports media files in the background, uses a third-party component to cast content in the background, or has an indoor workout scenario in the background. The scenario must match that of the subtype.<br/>**NOTE**<br/>1. If an app needs to run in the background for a long time, it can request user authorization through the [requestAuthFromUser](#requestauthfromuser22) API and check the authorization result via [checkSpecialScenarioAuth](#checkspecialscenarioauth22).<br/>2. Since API version 24, this capability is available only to apps that have obtained the ACL permission [ohos.permission.KEEP_BACKGROUND_RUNNING_SPECIAL_SCENARIO](../../../application-dev/security/AccessToken/restricted-permissions.md#ohospermissionkeep_background_running_special_scenario). For API version 23 and earlier, this capability is available only to apps that have obtained the ACL permission [ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM](../../../application-dev/security/AccessToken/restricted-permissions.md#ohospermissionkeep_background_running_system). Apps that have obtained this permission are not affected for API version 24 and later.<br/>3. This task type must be used independently and notifications cannot be combined. Specifically, when you request or update a continuous task, it must be of the **MODE_SPECIAL_SCENARIO_PROCESSING** type. Otherwise, an error is returned. |
| MODE_NEARLINK | 14 | NearLink service.<br>Use scenario: An application transitions into the background during the process of file transfer using NearLink.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## BackgroundTaskSubmode<sup>21+</sup>

Defines the subtype of a continuous task. It is usually used together with the main type [BackgroundTaskMode](#backgroundtaskmode21). For details, see the mapping table. The two types are newly added in API version 21 for requesting and updating continuous tasks.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

<!--Table: 40%; 10%; 50%-->

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| SUBMODE_CAR_KEY_NORMAL_NOTIFICATION     | 1    | **CAR_KEY** type. It is of the normal text notification type.      |
| SUBMODE_NORMAL_NOTIFICATION    | 2    | Normal text notification.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.                  |
| SUBMODE_LIVE_VIEW_NOTIFICATION  | 3    | Live view notification.           |
| SUBMODE_AUDIO_PLAYBACK_NORMAL_NOTIFICATION<sup>22+</sup>  | 4    | Audio and video playback. It is of the normal text notification type. You can access [AVSession](../../media/avsession/avsession-overview.md) as needed.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.            |
| SUBMODE_AVSESSION_AUDIO_PLAYBACK<sup>22+</sup>  | 5    | Audio and video playback scenario where [AVSession](../../media/avsession/avsession-overview.md) is accessed. No notification is sent.<br>**Atomic service API**: This API can be used in atomic services since API version 26.0.0.            |
| SUBMODE_AUDIO_RECORD_NORMAL_NOTIFICATION<sup>22+</sup>  | 6    | Recording. It is of the normal text notification type.           |
| SUBMODE_SCREEN_RECORD_NORMAL_NOTIFICATION<sup>22+</sup>  | 7    | Recording. It is of the normal text notification type.           |
| SUBMODE_VOICE_CHAT_NORMAL_NOTIFICATION<sup>22+</sup>  | 8    | Call. It is of the normal text notification type.           |
| SUBMODE_MEDIA_PROCESS_NORMAL_NOTIFICATION<sup>22+</sup>  | 9 | Media processing. For example, an application exports media files in the background. It is of the normal text notification type.   |
| SUBMODE_VIDEO_BROADCAST_NORMAL_NOTIFICATION<sup>22+</sup>  | 10 | Video casting. For example, an application uses a third-party casting component to cast a video in the background, and the notification type is common text notification. |
| SUBMODE_WORK_OUT_NORMAL_NOTIFICATION<sup>23+</sup>  | 11 | Exercise. For example, an application has an indoor running scenario in the background, and the notification type is common text notification.<br>**Model restriction**: This API can be used only in the stage model.|

Mapping table of main types and subtypes of continuous tasks

| [BackgroundTaskMode](#backgroundtaskmode21)| [BackgroundTaskSubmode](#backgroundtasksubmode21)  |
| --------------------------------- | ----------------------------------- |
| MODE_DATA_TRANSFER                | SUBMODE_LIVE_VIEW_NOTIFICATION      |
| MODE_AUDIO_PLAYBACK               | SUBMODE_NORMAL_NOTIFICATION         |
| MODE_AUDIO_RECORDING              | SUBMODE_NORMAL_NOTIFICATION         |
| MODE_LOCATION                     | SUBMODE_NORMAL_NOTIFICATION         |
| MODE_BLUETOOTH_INTERACTION        | SUBMODE_NORMAL_NOTIFICATION <br>SUBMODE_CAR_KEY_NORMAL_NOTIFICATION         |
| MODE_MULTI_DEVICE_CONNECTION      | SUBMODE_NORMAL_NOTIFICATION         |
| MODE_VOIP                         | SUBMODE_NORMAL_NOTIFICATION         |
| MODE_TASK_KEEPING                 | SUBMODE_NORMAL_NOTIFICATION         |
| MODE_AV_PLAYBACK_AND_RECORD  | SUBMODE_AUDIO_PLAYBACK_NORMAL_NOTIFICATION<br>SUBMODE_AVSESSION_AUDIO_PLAYBACK<br>SUBMODE_AUDIO_RECORD_NORMAL_NOTIFICATION<br>SUBMODE_SCREEN_RECORD_NORMAL_NOTIFICATION<br>SUBMODE_VOICE_CHAT_NORMAL_NOTIFICATION  |
| MODE_SPECIAL_SCENARIO_PROCESSING  | SUBMODE_MEDIA_PROCESS_NORMAL_NOTIFICATION <br>SUBMODE_VIDEO_BROADCAST_NORMAL_NOTIFICATION  <br>SUBMODE_WORK_OUT_NORMAL_NOTIFICATION |
| MODE_NEARLINK                   | SUBMODE_NORMAL_NOTIFICATION         |

## UserAuthResult<sup>22+</sup>

Represents the user authorization result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

<!--Table: 30%; 10%; 60%-->

| Name          | Value| Description    |
| ------------ |---|--------|
| NOT_SUPPORTED | 0 | The authorization is not supported. For example, if the main type of the requested continuous task is not **MODE_SPECIAL_SCENARIO_PROCESSING**, continuous task running in the background is not supported.|
| NOT_DETERMINED | 1 | No user operation.|
| DENIED  | 2 | The authorization is denied.   |
| GRANTED_ONCE | 3 | The authorization is granted this time.<br>Note: The authorization record will be cleared when the application exits. |
| GRANTED_ALWAYS | 4 | The authorization is granted always.<br>**NOTE**<br>When the following common events are received, the related authorization records will be cleared:<br>[COMMON_EVENT_PACKAGE_ADDED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_added), [COMMON_EVENT_PACKAGE_REMOVED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_removed), [COMMON_EVENT_BUNDLE_REMOVED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_bundle_removed), [COMMON_EVENT_PACKAGE_FULLY_REMOVED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_fully_removed), [COMMON_EVENT_PACKAGE_CHANGED](../../../application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md#common_event_package_changed). |