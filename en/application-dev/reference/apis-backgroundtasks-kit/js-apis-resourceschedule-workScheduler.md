# @ohos.resourceschedule.workScheduler (Deferred Task Scheduling)

The **workScheduler** module provides the APIs for registering, canceling, and querying deferred tasks. You can use the APIs to register tasks that do not have high requirements on real-time performance as deferred tasks. The system schedules and executes the deferred tasks at an appropriate time, subject to the storage space, power consumption, and more.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>  The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { workScheduler } from '@kit.BackgroundTasksKit';
```

## workScheduler.startWork

startWork(work: WorkInfo): void

Starts a deferred task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                   | Mandatory  | Description            |
| ---- | --------------------- | ---- | -------------- |
| work | [WorkInfo](#workinfo) | Yes   | Deferred task to start.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |
| 9700004 | Check on workInfo failed. |
| 9700005 | Calling startWork failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let workInfo: workScheduler.WorkInfo = {
      workId: 1,
      batteryStatus:workScheduler.BatteryStatus.BATTERY_STATUS_LOW,
      isRepeat: false,
      isPersisted: true,
      bundleName: "com.example.myapplication",
      abilityName: "MyExtension",
      parameters: {
          mykey0: 1,
          mykey1: "string value",
          mykey2: true,
          mykey3: 1.5
      }
  }
  try{
    workScheduler.startWork(workInfo);
    console.info('workschedulerLog startWork success');
  } catch (error) {
    console.error(`workschedulerLog startwork failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
  }
```

## workScheduler.stopWork

stopWork(work: WorkInfo, needCancel?: boolean): void

Stops a deferred task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name       | Type                   | Mandatory  | Description        |
| ---------- | --------------------- | ---- | ---------- |
| work       | [WorkInfo](#workinfo) | Yes   | Deferred task to stop.|
| needCancel | boolean               | No   | Whether to clear the task while stopping it.<br>The value **true** means to clear the task while stopping it, and **false** means to stop the task only. The default value is **false**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |
| 9700004 | Check on workInfo failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let workInfo: workScheduler.WorkInfo = {
      workId: 1,
      batteryStatus:workScheduler.BatteryStatus.BATTERY_STATUS_LOW,
      isRepeat: false,
      isPersisted: true,
      bundleName: "com.example.myapplication",
      abilityName: "MyExtension",
      parameters: {
          mykey0: 1,
          mykey1: "string value",
          mykey2: true,
          mykey3: 1.5
      }
     }
  try{
    workScheduler.stopWork(workInfo, false);
    console.info('workschedulerLog stopWork success');
  } catch (error) {
    console.error(`workschedulerLog stopWork failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
  }
```

## workScheduler.getWorkStatus

getWorkStatus(workId: number, callback : AsyncCallback\<WorkInfo>): void

Obtains the information a deferred task. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                                   | Mandatory  | Description                                      |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| workId   | number                                | Yes   | ID of the deferred task.                                |
| callback | AsyncCallback\<[WorkInfo](#workinfo)> | Yes   | Callback used to return the result. If **workId** is valid, the task information obtained from WorkSchedulerService is returned. Otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: Parameter verification failed. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |
| 9700004 | Check on workInfo failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  workScheduler.getWorkStatus(50, (error: BusinessError, res: workScheduler.WorkInfo) => {
    if (error) {
      console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);
    } else {
      console.info(`workschedulerLog getWorkStatus success, ${JSON.stringify(res)}`);
    }
  });
```

## workScheduler.getWorkStatus

getWorkStatus(workId: number): Promise\<WorkInfo>

Obtains the information a deferred task. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name   | Type    | Mandatory  | Description      |
| ------ | ------ | ---- | -------- |
| workId | number | Yes   | ID of the deferred task.|

**Return value**

| Type                             | Description                                      |
| ------------------------------- | ---------------------------------------- |
| Promise\<[WorkInfo](#workinfo)> | Promise used to return the result. If **workId** is valid, the task information obtained from WorkSchedulerService is returned. Otherwise, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: Parameter verification failed. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |
| 9700004 | Check on workInfo failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  workScheduler.getWorkStatus(50).then((res: workScheduler.WorkInfo) => {
    console.info(`workschedulerLog getWorkStatus success, ${JSON.stringify(res)}`);
  }).catch((error: BusinessError) => {
    console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);
  })
```

## workScheduler.obtainAllWorks<sup>deprecated<sup>

obtainAllWorks(callback : AsyncCallback\<void>) : Array\<WorkInfo>
> This API is deprecated since API version 10. You are advised to use [workScheduler.obtainAllWorks<sup>10+<sup>](#workschedulerobtainallworks10) instead.

Obtains all the deferred tasks. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                  | Mandatory  | Description                             |
| -------- | -------------------- | ---- | ------------------------------- |
| callback |  AsyncCallback\<void> | Yes   | Callback used to return the result. If all the deferred tasks are obtained, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |

## workScheduler.obtainAllWorks<sup>10+<sup>

obtainAllWorks(callback : AsyncCallback&lt;Array&lt;WorkInfo&gt;&gt;): void

Obtains all the deferred tasks. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                  | Mandatory  | Description                             |
| -------- | -------------------- | ---- | ------------------------------- |
| callback |  AsyncCallback&lt;Array&lt;WorkInfo&gt;&gt; | Yes   | Callback used to return the result. If all the deferred tasks are obtained, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  workScheduler.obtainAllWorks((error: BusinessError, res: Array<workScheduler.WorkInfo>) =>{
    if (error) {
      console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);
    } else {
      console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);
    }
  });
```

## workScheduler.obtainAllWorks

obtainAllWorks(): Promise\<Array\<WorkInfo>>

Obtains all the deferred tasks. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Return value**

| Type                                    | Description                            |
| -------------------------------------- | ------------------------------ |
| Promise<Array\<[WorkInfo](#workinfo)>> | Promise used to return all the deferred tasks.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  workScheduler.obtainAllWorks().then((res: Array<workScheduler.WorkInfo>) => {
    console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);
  }).catch((error: BusinessError) => {
    console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);
  })
```

## workScheduler.stopAndClearWorks

stopAndClearWorks(): void

Stops and clears all the deferred tasks.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  try{
    workScheduler.stopAndClearWorks();
    console.info(`workschedulerLog stopAndClearWorks success`);
  } catch (error) {
    console.error(`workschedulerLog stopAndClearWorks failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
  }
```

## workScheduler.isLastWorkTimeOut<sup>deprecated<sup>

isLastWorkTimeOut(workId: number, callback : AsyncCallback\<void>): boolean

> This API is deprecated since API version 10. You are advised to use [workScheduler.isLastWorkTimeOut<sup>10+<sup>](#workschedulerislastworktimeout10) instead.

Checks whether the last execution of a task timed out. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| workId   | number               | Yes   | ID of the deferred task.                                |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: Parameter verification failed. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |
| 9700004 | Check on workInfo failed. |

## workScheduler.isLastWorkTimeOut<sup>10+<sup>

isLastWorkTimeOut(workId: number, callback : AsyncCallback\<boolean>): void

Checks whether the last execution of a task timed out. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| workId   | number               | Yes   | ID of the deferred task.                                |
| callback | AsyncCallback\<boolean> | Yes   | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: Parameter verification failed. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |
| 9700004 | Check on workInfo failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  workScheduler.isLastWorkTimeOut(500, (error: BusinessError, res: boolean) =>{
    if (error) {
      console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);
    } else {
      console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);
    }
  });
```

## workScheduler.isLastWorkTimeOut

isLastWorkTimeOut(workId: number): Promise\<boolean>

Checks whether the last execution of a task timed out. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name   | Type    | Mandatory  | Description      |
| ------ | ------ | ---- | -------- |
| workId | number | Yes   | ID of the deferred task.|

**Return value**

| Type               | Description                                      |
| ----------------- | ---------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the last execution of the specified task times out, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [workScheduler Error Codes](errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 401 | Parameter error. Possible causes: Parameter verification failed. |
| 9700001 | Memory operation failed. |
| 9700002 | Failed to write data into parcel. Possible reasons: 1. Invalid parameters; 2. Failed to apply for memory. |
| 9700003 | System service operation failed. |
| 9700004 | Check on workInfo failed. |

**Example**

```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  workScheduler.isLastWorkTimeOut(500)
    .then((res: boolean) => {
      console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);
    })
    .catch((error: BusinessError) =>  {
      console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);
    });
```

## WorkInfo

Defines the information about the deferred task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name            | Type                               | Mandatory  | Description              |
| --------------- | --------------------------------- | ---- | ---------------- |
| workId          | number                            | Yes   | ID of the deferred task.         |
| bundleName      | string                            | Yes   | Bundle name of the application where the deferred task is located.          |
| abilityName     | string                            | Yes   | Ability name in the bundle.|
| networkType     | [NetworkType](#networktype)       | No   | Network type.            |
| isCharging      | boolean                           | No   | Whether the device needs to enter the charging state.<br>- **true**: The device needs to enter the charging state to trigger deferred task scheduling.<br>- **false** (default): The device does not need to enter the charging state to trigger deferred task scheduling.|
| chargerType     | [ChargingType](#chargingtype)     | No   | Charging type.            |
| batteryLevel    | number                            | No   | Battery level.             |
| batteryStatus   | [BatteryStatus](#batterystatus)   | No   | Battery status.            |
| storageRequest  | [StorageRequest](#storagerequest) | No   | Storage status.            |
| isRepeat        | boolean                           | No   | Whether the task is repeated.<br>- **true**: The task is repeated.<br>- **false** (default): The task is not repeated.|
| repeatCycleTime | number                            | No   | Repeat interval, in milliseconds.            |
| repeatCount     | number                            | No   | Number of repeat times.            |
| isPersisted     | boolean                           | No   | Whether the registered deferred task can be saved in the system.<br>- **true**: The task can be saved. That is, the task can be restored after the system restarts.<br>- **false** (default): The task cannot be saved.|
| isDeepIdle      | boolean                           | No   | Whether the device needs to enter the idle state to trigger deferred task scheduling.<br>- **true**: The device needs to enter the idle state to trigger deferred task scheduling.<br>- **false** (default): The device does not need to enter the idle state to trigger deferred task scheduling.  |
| idleWaitTime    | number                            | No   | Time to wait in the idle state before triggering deferred task scheduling, in milliseconds.          |
| parameters      | Record<string, number \| string \| boolean>  | No   | Carried parameters.|

## NetworkType

Enumerates the network types that can trigger deferred task scheduling.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                    | Value | Description                     |
| ---------------------- | ---- | ----------------------- |
| NETWORK_TYPE_ANY       | 0    | Any network type.    |
| NETWORK_TYPE_MOBILE    | 1    | Mobile network.   |
| NETWORK_TYPE_WIFI      | 2    | Wi-Fi network.  |
| NETWORK_TYPE_BLUETOOTH | 3    | Bluetooth network.|
| NETWORK_TYPE_WIFI_P2P  | 4    | Wi-Fi P2P network. |
| NETWORK_TYPE_ETHERNET  | 5    | Ethernet.       |

## ChargingType

Enumerates the charging types that can trigger deferred task scheduling.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                       | Value | Description                  |
| ------------------------- | ---- | -------------------- |
| CHARGING_PLUGGED_ANY      | 0    | Any charging type.|
| CHARGING_PLUGGED_AC       | 1    | DC charging.   |
| CHARGING_PLUGGED_USB      | 2    | USB charging.    |
| CHARGING_PLUGGED_WIRELESS | 3    | Wireless charging.   |

## BatteryStatus

Enumerates the battery statuses that can trigger deferred task scheduling.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                        | Value | Description                        |
| -------------------------- | ---- | -------------------------- |
| BATTERY_STATUS_LOW         | 0    | A low battery alert is displayed.            |
| BATTERY_STATUS_OKAY        | 1    | The battery level is restored from low to normal.      |
| BATTERY_STATUS_LOW_OR_OKAY | 2    | The battery level is restored from low to normal, or a low battery alert is displayed.|

## StorageRequest

Enumerates the storage statuses that can trigger deferred task scheduling.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                       | Value | Description                            |
| ------------------------- | ---- | ------------------------------ |
| STORAGE_LEVEL_LOW         | 0    | The storage space is insufficient.              |
| STORAGE_LEVEL_OKAY        | 1    | The storage space is restored from insufficient to normal.        |
| STORAGE_LEVEL_LOW_OR_OKAY | 2    | The storage space is insufficient, or the storage space is restored from insufficient to normal.|
