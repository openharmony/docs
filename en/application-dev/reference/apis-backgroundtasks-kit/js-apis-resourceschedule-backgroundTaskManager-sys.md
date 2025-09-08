# @ohos.resourceschedule.backgroundTaskManager (Background Task Management) (System API)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @cheng-shichang-->
<!--Designer: @zhouben25-->
<!--Tester: @fenglili18-->
<!--Adviser: @Brilliantry_Rui-->

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
import { BusinessError } from '@kit.BasicServicesKit';

let request: backgroundTaskManager.EfficiencyResourcesRequest = {
    resourceTypes: backgroundTaskManager.ResourceType.CPU,
    isApply: true,
    timeOut: 0,
    reason: "apply",
    isPersist: true,
    isProcess: false,
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
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |
| 9800001 | Memory operation failed. |
| 9800002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9800003 | Internal transaction failed. |
| 9800004 | System service operation failed. |
| 18700001 | Caller information verification failed for an energy resource request. |

**Example**

```js
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
| SENSOR<sup>10+</sup> | 256 | Sensor callbacks are not intercepted.|

## EfficiencyResourcesInfo<sup>20+</sup>

Efficiency resource information.

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
