# @ohos.resourceschedule.backgroundTaskManager (Background Task Management) (System API)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=f535fa3e6a7c6dc24401768a57ccb365b67fee65 translatedAt=2026-08-11T01:56:10.825Z pushedAt=2026-08-11T03:04:38.325Z -->

The **backgroundTaskManager** module provides APIs to request background tasks. You can use the APIs to request transient tasks, continuous tasks, or efficiency resources to prevent the application process from being terminated or suspended when your application is switched to the background.

>  **NOTE**
> 
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](js-apis-resourceschedule-backgroundTaskManager.md).

## Modules to Import

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';  
```

## backgroundTaskManager.applyEfficiencyResources

applyEfficiencyResources(request: EfficiencyResourcesRequest): void

Requests efficiency resources.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

**Parameters**

| Name    | Type     | Mandatory  | Description                                      |
| ------- | ------- | ---- | ---------------------------------------- |
| request | [EfficiencyResourcesRequest](#efficiencyresourcesrequest) | Yes   | Necessary information carried in the request, including the resource type and timeout interval.|

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
| 18700001 | Caller information verification failed for an energy resource request. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';  
import { BusinessError } from '@kit.BasicServicesKit';

let request: backgroundTaskManager.EfficiencyResourcesRequest = {
    resourceTypes: backgroundTaskManager.ResourceType.CPU,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true,
    isProcess: false,
    cpuLevel: backgroundTaskManager.EfficiencyResourcesCpuLevel.SMALL_CPU // The application's background task runs on the small CPU core. This parameter is supported since API version 23.
};
try {
    backgroundTaskManager.applyEfficiencyResources(request);
    console.info("applyEfficiencyResources success. ");
} catch (error) {
    console.error(`applyEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.resetAllEfficiencyResources

resetAllEfficiencyResources(): void

Releases all efficiency resources.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 401 | Parameter error. Possible causes: 1. Parameter verification failed. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed for an energy resource request. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';  
import { BusinessError } from '@kit.BasicServicesKit';

try {
    backgroundTaskManager.resetAllEfficiencyResources();
} catch (error) {
    console.error(`resetAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.getAllEfficiencyResources<sup>20+</sup>

getAllEfficiencyResources(): Promise&lt;EfficiencyResourcesInfo[]&gt;

Obtains all information about the requested efficiency resources, including the resource type. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

**Return value**

| Type                                           | Description         |
|-----------------------------------------------|-------------|
|  Promise&lt;[EfficiencyResourcesInfo](#efficiencyresourcesinfo20)[]&gt; | Promise used to return all information about efficiency resources.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 202 | Not System App. |
| 18700001 | Caller information verification failed for an energy resource request. |
| 18700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 18700004 | System service operation failed. |

**Example**

```js
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    backgroundTaskManager.getAllEfficiencyResources().then((res: backgroundTaskManager.EfficiencyResourcesInfo[]) => {
        console.info(`Operation getAllEfficiencyResources succeeded. data: ` + JSON.stringify(res));
    }).catch((error : BusinessError) => {
        console.error(`Operation getAllEfficiencyResources failed. code is ${error.code} message is ${error.message}`);
    });
} catch (error) {
    console.error(`Operation getAllEfficiencyResources failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.setBackgroundTaskState<sup>22+</sup>

setBackgroundTaskState(stateInfo: BackgroundTaskStateInfo): void

Sets the authorization information of a continuous task.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.SET_BACKGROUND_TASK_STATE

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Parameters**

| Name    | Type     | Mandatory  | Description                   |
| ------- | ------- | ---- |-----------------------|
| stateInfo | [BackgroundTaskStateInfo](#backgroundtaskstateinfo22) | Yes   | Required authorization information, including the user ID, application bundle name, and application clone ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // Update the parameters based on the actual situation.
    let backgroundTaskStateInfo: backgroundTaskManager.BackgroundTaskStateInfo = {
        userId: 100,
        bundleName: 'com.example.continuoustask',
        appIndex: 0,
        authResult: backgroundTaskManager.UserAuthResult.DENIED
    };
    backgroundTaskManager.setBackgroundTaskState(backgroundTaskStateInfo);
    console.info('Operation setBackgroundTaskState succeeded.');
} catch (error) {
    console.error(`Operation setBackgroundTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.getBackgroundTaskState<sup>22+</sup>

getBackgroundTaskState(stateInfo: BackgroundTaskStateInfo): UserAuthResult

Obtains the authorization information of a continuous task.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.SET_BACKGROUND_TASK_STATE

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Parameters**

| Name    | Type     | Mandatory  | Description                   |
| ------- | ------- | ---- |-----------------------|
| stateInfo | [BackgroundTaskStateInfo](#backgroundtaskstateinfo22) | Yes   | Required authorization information, including the user ID, application bundle name, and application clone ID.|

**Return value**

| Type                                           | Description         |
|-----------------------------------------------|-------------|
|  [UserAuthResult](./js-apis-resourceschedule-backgroundTaskManager.md#userauthresult22) | Authorization result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID | Error Message            |
| ---- | --------------------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // Update the parameters based on the actual situation.
    let backgroundTaskStateInfo: backgroundTaskManager.BackgroundTaskStateInfo = {
        userId: 100,
        bundleName: 'com.example.continuoustask',
        appIndex: 0
    };
    let auth = backgroundTaskManager.getBackgroundTaskState(backgroundTaskStateInfo);
    console.info('Operation getBackgroundTaskState succeeded. data: ' + JSON.stringify(auth));
} catch (error) {
    console.error(`Operation getBackgroundTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.obtainAllContinuousTasks<sup>23+</sup>

obtainAllContinuousTasks(): Promise&lt;ContinuousTaskInfo[]&gt;

Obtains all continuous task information, including the task ID and type. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BACKGROUND_TASK_INFO

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Return value**

| Type                                           | Description         |
|-----------------------------------------------|-------------|
|  Promise&lt;[ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20)[]&gt; | Promise that returns all continuous task information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
| --------- | ------- |
| 201 | Permission denied. |
| 202 | Not System App. |
| 9800004 | System service operation failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // If no continuous task is requested, an empty array is obtained.
    backgroundTaskManager.obtainAllContinuousTasks().then((res: backgroundTaskManager.ContinuousTaskInfo[]) => {
        console.info(`Operation obtainAllContinuousTasks succeeded. data: ` + JSON.stringify(res));
    }).catch((error: BusinessError) => {
        console.error(`Operation obtainAllContinuousTasks failed. code is ${error.code} message is ${error.message}`);
    });
} catch (error) {
    console.error(`Operation obtainAllContinuousTasks failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.subscribeContinuousTaskState<sup>23+</sup>

subscribeContinuousTaskState(subscriber: BackgroundTaskSubscriber): void

Registers a callback to listen for the continuous task change events.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BACKGROUND_TASK_INFO

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Parameters**

| Name    | Type     | Mandatory  | Description                   |
| ------- | ------- | ---- |-----------------------|
| subscriber | [BackgroundTaskSubscriber](#backgroundtasksubscriber23) | Yes   | Background task listener that listens for continuous task state changes, including start, update and stop events.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
|---------| ------- |
| 201     | Permission denied. |
| 202     | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}

try {
    backgroundTaskManager.subscribeContinuousTaskState(backgroundTaskSubscriber);
    console.info('Operation subscribeContinuousTaskState succeeded');
} catch (error) {
    console.error(`Operation subscribeContinuousTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## backgroundTaskManager.unsubscribeContinuousTaskState<sup>23+</sup>

unsubscribeContinuousTaskState(subscriber: BackgroundTaskSubscriber): void

Unregisters the callback for continuous task changes.

**Model restriction**: This API can be used only in the stage model.

**Required permissions**: ohos.permission.GET_BACKGROUND_TASK_INFO

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Parameters**

| Name    | Type     | Mandatory  | Description                   |
| ------- | ------- | ---- |-----------------------|
| subscriber | [BackgroundTaskSubscriber](#backgroundtasksubscriber23) | Yes   | Background task listener that listens for continuous task state changes, including start, update and stop events.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [backgroundTaskManager Error Codes](errorcode-backgroundTaskMgr.md).

| ID  | Error Message|
|---------| ------- |
| 201     | Permission denied. |
| 202     | Not System App. |
| 9800004 | System service operation failed. |
| 9800005 | Continuous task verification failed. |

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
import { BusinessError } from '@kit.BasicServicesKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}

try {
    backgroundTaskManager.unsubscribeContinuousTaskState(backgroundTaskSubscriber);
    console.info('Operation unsubscribeContinuousTaskState succeeded');
} catch (error) {
    console.error(`Operation unsubscribeContinuousTaskState failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
}
```

## BackgroundMode

Enumerates the continuous task modes.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| WIFI_INTERACTION        | 7    | WLAN-related.<br>**System API**: This is a system API.|

## EfficiencyResourcesRequest

Describes the parameters for requesting efficiency resources.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

| Name            | Type    | Read-Only  | Optional  | Description                                      |
| --------------- | ------ | ---- | ---- | ---------------------------------------- |
| resourceTypes   | number  | No   | No   | Type of the resource to request.                              |
| isApply         | boolean | No   | No   | Whether the request is used to apply for resources.<br>- **true**: The request is used to apply for resources.<br>- **false**: The request is used to release resources.|
| timeOut         | number  | No   | No   | Duration for which the resource will be used, in milliseconds.               |
| isPersist       | boolean | No   | Yes   | Whether the resource is permanently held. The default value is **false**.<br>- **true**: The resource is permanently held.<br>- **false**: The resource is held for a limited period of time.|
| isProcess       | boolean | No   | Yes   | Whether the request is initiated by a process. The default value is **false**.<br>- **true**: The request is initiated by a process.<br>- **false**: The request is initiated by an application.        |
| reason          | string  | No   | No   | Reason for requesting the resource.               |
| cpuLevel<sup>23+</sup> | [EfficiencyResourcesCpuLevel](#efficiencyresourcescpulevel23) | No   | Yes   | CPU level. If **resourceTypes** is set to **CPU**, this parameter specifies the CPU resource size. The system allocates the specified CPU resources to the application during the idle time of load (for example, when the screen is off).|

## ResourceType

Enumerates the efficiency resource types.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

| Name                    | Value | Description                   |
| ----------------------- | ---- | --------------------- |
| CPU                     | 1    | CPU resource. Such type of resource prevents an application from being suspended.            |
| COMMON_EVENT            | 2    | Common event resource. Such type of resource ensures that an application in the suspended state can receive common events.|
| TIMER                   | 4    | Timer resource. Such type of resource ensures that an application in the suspended state can be woken up by system timers.|
| WORK_SCHEDULER          | 8    | Deferred task resource. Such type of resource provides a loose control policy for an application.|
| BLUETOOTH               | 16   | Bluetooth resource. Such type of resource ensures that an application in the suspended state can be woken up by Bluetooth-related events.|
| GPS                     | 32   | GPS resource. Such type of resource ensures that an application in the suspended state can be woken up by GPS-related events.|
| AUDIO                   | 64   | Audio resource. Such type of resource prevents an application from being suspended when the application has an audio being played.|
| RUNNING_LOCK<sup>10+</sup> | 128 | RUNNING_LOCK resources are not proxied when the application is suspended.|
| SENSOR<sup>10+</sup> | 256 | Sensor callbacks are not intercepted. |

## EfficiencyResourcesInfo<sup>20+</sup>

Defines the efficiency resource information.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

| Name                            | Type     | Read-Only  | Optional  | Description         |
|--------------------------------|---------| ---- | ---- |-------------|
| [resourceTypes](#resourcetype) | number  | No   | No   | Enumerates the efficiency resource types.    |
| timeout                        | number  | No   | No   | Timeout, in milliseconds.|
| isPersistent                   | boolean | No   | No   | Whether the resource is permanently held. The default value is **false**. The value **true** indicates the resource is permanently held. The value **false** indicates that the resource is held within a limited time.     |
| isForProcess                   | boolean | No   | No   | Whether the resource is requested by a process or an application. The value **true** indicates that the resource is requested by a process. The value **false** indicates that the resource is requested by an application.  |
| reason                         | string  | No   | No   | Reason for requesting the resource.      |
| uid                            | number  | No   | No   | Application UID.    |
| pid                            | number  | No   | No   | Application PID.  |
| cpuLevel<sup>23+</sup>         | [EfficiencyResourcesCpuLevel](#efficiencyresourcescpulevel23)  | No   | Yes   |  CPU level. If **resourceTypes** is set to **CPU**, this parameter specifies the CPU resource size. The system allocates the specified CPU resources to the application during the idle time of load (for example, when the screen is off).|

## EfficiencyResourcesCpuLevel<sup>23+</sup>

Defines the CPU level of the efficiency resource.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.EfficiencyResourcesApply

**System API**: This is a system API.

| Name                     | Value | Description                   |
| ------------------------ | ---- | ---------------------  |
| SMALL_CPU | 0 | The background task runs on small CPU cores. This level caters to lightweight background tasks with a relatively low CPU frequency.|
| MEDIUM_CPU | 1 | The background task can run on medium CPU cores at maximum. The system determines whether to run the task on small or medium CPU cores based on load. This level balances performance and energy efficiency, and is applicable to scenarios requiring complex task processing with a high CPU frequency.|
| LARGE_CPU | 2 | The background task can run on large CPU cores at maximum. The system determines whether to run the task on small, medium, or large CPU cores based on load. This level delivers ultimate performance, and is applicable to scenarios requiring heavy-load task processing with the highest CPU frequency.|

## BackgroundTaskMode<sup>21+</sup>

Defines the main type of a continuous task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

| Name                    | Value | Description                   |
| ------------------------ | ---- | --------------------- |
| MODE_ALLOW_WIFI_AWARE           | 7         | WLAN-related services.           |

## BackgroundTaskStateInfo<sup>22+</sup>

Defines the authorization information of a continuous task.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

| Name| Type                                 | Read-Only  | Optional| Description     |
|--|-------------------------------------| ---- |----|---------|
| userId | number                              | No   | No | User ID.  |
| bundleName | string                              | No   | No | Application bundle name.  |
| appIndex | number                              | No   | No | Index of an application clone.|
| authResult | [UserAuthResult](./js-apis-resourceschedule-backgroundTaskManager.md#userauthresult22) | No   | Yes | Authorization result.  |

## BackgroundTaskSubscriber<sup>23+</sup>

Represents a listener object used to listen for background task state changes.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

### onContinuousTaskStart<sup>23+</sup>

onContinuousTaskStart(info: ContinuousTaskInfo): void

Called when a continuous task starts.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Parameters**

| Name | Type     | Mandatory  | Description               |
|------| ------- | ---- |-------------------|
| info | [ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20) | Yes   | Continuous task callback information, including the task ID and type.|

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}
```

### onContinuousTaskUpdate<sup>23+</sup>

onContinuousTaskUpdate(info: ContinuousTaskInfo): void

Called when a continuous task is updated.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Parameters**

| Name | Type     | Mandatory  | Description               |
|------| ------- | ---- |-------------------|
| info | [ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20) | Yes   | Continuous task callback information, including the task ID and type.|

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}
```

### onContinuousTaskStop<sup>23+</sup>

onContinuousTaskStop(info: ContinuousTaskInfo): void

Called when a continuous task stops.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.ContinuousTask

**System API**: This is a system API.

**Parameters**

| Name | Type     | Mandatory  | Description               |
|------| ------- | ---- |-------------------|
| info | [ContinuousTaskInfo](./js-apis-resourceschedule-backgroundTaskManager.md#continuoustaskinfo20) | Yes   | Continuous task callback information, including the task ID and type.|

**Example**

```ts
import { backgroundTaskManager } from '@kit.BackgroundTasksKit';

let backgroundTaskSubscriber : backgroundTaskManager.BackgroundTaskSubscriber = {
    onContinuousTaskStart: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStart succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskUpdate: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskUpdate succeeded. data: ' + JSON.stringify(info));
    },
    onContinuousTaskStop: (info: backgroundTaskManager.ContinuousTaskInfo): void => {
        console.info('Operation onContinuousTaskStop succeeded. data: ' + JSON.stringify(info));
    }
}
```