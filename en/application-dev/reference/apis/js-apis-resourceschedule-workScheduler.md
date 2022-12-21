# @ohos.resourceschedule.workScheduler

The **workScheduler** module provides the APIs for registering, canceling, and querying Work Scheduler tasks, which do not have real-time constraints.

The system executes Work Scheduler tasks at an appropriate time, subject to the storage space, power consumption, temperature, and more.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.
>  - For details about the restrictions, see [Restrictions on Using Work Scheduler Tasks](../../task-management/background-task-overview.md#restrictions-on-using-work-scheduler-tasks).


## Modules to Import

```js
import workScheduler from '@ohos.resourceschedule.workScheduler';
```

## workScheduler.startWork
startWork(work: WorkInfo): void

Instructs the **WorkSchedulerService** to add the specified task to the execution queue.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                   | Mandatory  | Description            |
| ---- | --------------------- | ---- | -------------- |
| work | [WorkInfo](#workinfo) | Yes   | Task to be added to the execution queue.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Checking workInfo failed. |
| 9700005 | StartWork failed. |


**Example**

```js
  let workInfo = {
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
    console.error(`workschedulerLog startwork failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.stopWork
stopWork(work: WorkInfo, needCancel?: boolean): void

Instructs the **WorkSchedulerService** to stop the specified task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name       | Type                   | Mandatory  | Description        |
| ---------- | --------------------- | ---- | ---------- |
| work       | [WorkInfo](#workinfo) | Yes   | Task to stop. |
| needCancel | boolean               | Yes   | Whether to cancel the task.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Checking workInfo failed. |

**Example**

```js
  let workInfo = {
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
    console.error(`workschedulerLog stopWork failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.getWorkStatus:callback
getWorkStatus(workId: number, callback : AsyncCallback\<WorkInfo>): void

Obtains the latest task status. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                                   | Mandatory  | Description                                      |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| workId   | number                                | Yes   | Task ID.                                |
| callback | AsyncCallback\<[WorkInfo](#workinfo)> | Yes   | Callback used to return the result. Returns the task status obtained from the **WorkSchedulerService** if the specified task ID is valid; returns **null** otherwise.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Checking workInfo failed. |

**Example**

```js
  try{
    workScheduler.getWorkStatus(50, (error, res) => {
      if (error) {
        console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);
      } else {
        for (let item in res) {
          console.info(`workschedulerLog getWorkStatus success, ${item} is: ${res[item]}`);
        }
      }
    });
  } catch (error) {
    console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.getWorkStatus:promise
getWorkStatus(workId: number): Promise\<WorkInfo>

Obtains the latest task status. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name   | Type    | Mandatory  | Description      |
| ------ | ------ | ---- | -------- |
| workId | number | Yes   | Task ID.|

**Return value**

| Type                             | Description                                      |
| ------------------------------- | ---------------------------------------- |
| Promise\<[WorkInfo](#workinfo)> | Promise used to return the result. Returns the task status obtained from the **WorkSchedulerService** if the specified task ID is valid; returns **null** otherwise.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Checking workInfo failed. |

**Example**

```js
  try{
    workScheduler.getWorkStatus(50).then((res) => {
      for (let item in res) {
        console.info(`workschedulerLog getWorkStatus success, ${item} is: ${res[item]}`);
      }
    }).catch((error) => {
      console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);
    })
  } catch (error) {
    console.error(`workschedulerLog getWorkStatus failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.obtainAllWorks:callback
obtainAllWorks(callback : AsyncCallback\<void>): Array\<WorkInfo>

Obtains all tasks associated with this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                  | Mandatory  | Description                             |
| -------- | -------------------- | ---- | ------------------------------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. All tasks associated with the current application.|

**Return value**

| Type                           | Description             |
| ----------------------------- | --------------- |
| Array\<[WorkInfo](#workinfo)> | All tasks associated with the current application.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**Example**

```js
  try{
    workScheduler.obtainAllWorks((error, res) =>{
      if (error) {
        console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);
      } else {
        console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);
      }
    });
  } catch (error) {
    console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.obtainAllWorks:promise
obtainAllWorks(): Promise<Array\<WorkInfo>>

Obtains all tasks associated with this application. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Return value**

| Type                                    | Description                            |
| -------------------------------------- | ------------------------------ |
| Promise<Array\<[WorkInfo](#workinfo)>> | Promise used to return the result. All tasks associated with the current application.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**Example**

```js
  try{
    workScheduler.obtainAllWorks().then((res) => {
      console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);
    }).catch((error) => {
      console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);
    })
  } catch (error) {
    console.error(`workschedulerLog obtainAllWorks failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.stopAndClearWorks
stopAndClearWorks(): void

Stops and cancels all tasks associated with the current application.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**Example**

```js
  try{
    workScheduler.stopAndClearWorks();
    console.info(`workschedulerLog stopAndClearWorks success`);
  } catch (error) {
    console.error(`workschedulerLog stopAndClearWorks failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.isLastWorkTimeOut:callback
isLastWorkTimeOut(workId: number, callback : AsyncCallback\<void>): boolean

Checks whether the last execution of the specified task timed out. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| workId   | number               | Yes   | Task ID.                                |
| callback | AsyncCallback\<void> | Yes   | Callback used to return the result. Returns **true** if the last execution of the specified task timed out; returns **false** otherwise.|

**Return value**

| Type     | Description                                      |
| ------- | ---------------------------------------- |
| boolean | Callback used to return the result. Returns **true** if the last execution of the specified task timed out; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**Example**

```js
  try{
    workScheduler.isLastWorkTimeOut(500, (error, res) =>{
      if (error) {
        console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);
      } else {
        console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);
      }
    });
  } catch (error) {
    console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.isLastWorkTimeOut:promise
isLastWorkTimeOut(workId: number): Promise\<boolean>

Checks whether the last execution of the specified task timed out. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name   | Type    | Mandatory  | Description      |
| ------ | ------ | ---- | -------- |
| workId | number | Yes   | Task ID.|

**Return value**

| Type               | Description                                      |
| ----------------- | ---------------------------------------- |
| Promise\<boolean> | Promise used to return the result. Returns **true** if the last execution of the specified task timed out; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [workScheduler Error Codes](../errorcodes/errorcode-workScheduler.md).

| ID | Error Message            |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**Example**

```js
  try{
    workScheduler.isLastWorkTimeOut(500)
      .then(res => {
        console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);
      })
      .catch(error =>  {
        console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);
      });
  } catch (error) {
    console.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);
  }
```

## WorkInfo
Provides detailed information about the task. For details about the constraints on configuring **WorkInfo**, see [Restrictions on Using Work Scheduler Tasks](../../task-management/background-task-overview.md#restrictions-on-using-work-scheduler-tasks).

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name            | Type                               | Mandatory  | Description              |
| --------------- | --------------------------------- | ---- | ---------------- |
| workId          | number                            | Yes   | Task ID.         |
| bundleName      | string                            | Yes   | Name of the Work Scheduler task bundle.          |
| abilityName     | string                            | Yes   | Name of the component to be notified by a Work Scheduler callback.|
| networkType     | [NetworkType](#networktype)       | No   | Network type.            |
| isCharging      | boolean                           | No   | Whether the device is charging.            |
| chargerType     | [ChargingType](#chargingtype)     | No   | Charging type.            |
| batteryLevel    | number                            | No   | Battery level.              |
| batteryStatus   | [BatteryStatus](#batterystatus)   | No   | Battery status.            |
| storageRequest  | [StorageRequest](#storagerequest) | No   | Storage status.            |
| isRepeat        | boolean                           | No   | Whether the task is repeated.          |
| repeatCycleTime | number                            | No   | Repeat interval.            |
| repeatCount     | number                            | No   | Number of repeat times.            |
| isPersisted     | boolean                           | No   | Whether to enable persistent storage for the task.       |
| isDeepIdle      | boolean                           | No   | Whether the device needs to enter the idle state.    |
| idleWaitTime    | number                            | No   | Time to wait in the idle state.          |
| parameters      | {[key: string]: any}              | No   | Carried parameters.          |

## NetworkType
Enumerates the network types that can trigger the task.

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
Enumerates the charging types that can trigger the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                       | Value | Description                  |
| ------------------------- | ---- | -------------------- |
| CHARGING_PLUGGED_ANY      | 0    | Any charging type.|
| CHARGING_PLUGGED_AC       | 1    | DC charging.   |
| CHARGING_PLUGGED_USB      | 2    | USB charging.    |
| CHARGING_PLUGGED_WIRELESS | 3    | Wireless charging.   |

## BatteryStatus
Enumerates the battery states that can trigger the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                        | Value | Description                        |
| -------------------------- | ---- | -------------------------- |
| BATTERY_STATUS_LOW         | 0    | A low battery alert is displayed.            |
| BATTERY_STATUS_OKAY        | 1    | The battery level is restored from low to normal.      |
| BATTERY_STATUS_LOW_OR_OKAY | 2    | The battery level is restored from low to normal, or a low battery alert is displayed.|

## StorageRequest
Enumerates the storage states that can trigger the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                       | Value | Description                            |
| ------------------------- | ---- | ------------------------------ |
| STORAGE_LEVEL_LOW         | 0    | The storage space is insufficient.              |
| STORAGE_LEVEL_OKAY        | 1    | The storage space is restored from insufficient to normal.        |
| STORAGE_LEVEL_LOW_OR_OKAY | 2    | The storage space is restored from insufficient to normal, or the storage space is insufficient.|
