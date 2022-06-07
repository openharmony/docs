# Work Scheduler

> **NOTE**<br/>
> The initial APIs of this module are supported since API version 9. API version 9 is a canary version for trial use. The APIs of this version may be unstable.


## Modules to Import

```
import workScheduler from '@ohos.workScheduler' 
```

## workScheduler.startWork
startWork(work: WorkInfo): boolean

Instructs the **WorkSchedulerService** to add the specified task to the execution queue.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name | Type                   | Mandatory  | Description            |
| ---- | --------------------- | ---- | -------------- |
| work | [WorkInfo](#workinfo) | Yes   | Task to be added to the execution queue.|

**Return value**

| Type     | Description                              |
| ------- | -------------------------------- |
| boolean | Returns **true** if the task is added to the execution queue; returns **false** otherwise.|

**Example**

```
  let workInfo = {
      workId: 1,
      batteryLevel:50,
      batteryStatus:workScheduler.BatteryStatus.BATTERY_STATUS_LOW,
      isRepeat: false,
      isPersisted: true,
      bundleName: "com.example.myapplication",
      abilityName: "MyExtension"
  }
  var res = workScheduler.startWork(workInfo);
  console.info("workschedulerLog res:" + res);
```

## workScheduler.stopWork
stopWork(work: WorkInfo, needCancel?: boolean): boolean

Instructs the **WorkSchedulerService** to stop the specified task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name       | Type                   | Mandatory  | Description        |
| ---------- | --------------------- | ---- | ---------- |
| work       | [WorkInfo](#workinfo) | Yes   | Task to stop. |
| needCancel | boolean               | Yes   | Whether to cancel the task.|

**Return value**

| Type     | Description                     |
| ------- | ----------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```
  let workInfo = {
      workId: 1,
      batteryLevel:50,
      batteryStatus:workScheduler.BatteryStatus.BATTERY_STATUS_LOW,
      isRepeat: false,
      isPersisted: true,
      bundleName: "com.example.myapplication",
      abilityName: "MyExtension"
     }
  var res = workScheduler.stopWork(workInfo, false);
  console.info("workschedulerLog res:" + res);
```

## workScheduler.getWorkStatus
getWorkStatus(workId: number, callback : AsyncCallback\<WorkInfo>): void

Obtains the latest task status. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                                   | Mandatory  | Description                                      |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| workId   | number                                | Yes   | Task ID.                                |
| callback | AsyncCallback\<[WorkInfo](#workinfo)> | Yes   | Callback used to return the result. Returns the task status obtained from the **WorkSchedulerService** if the specified task ID is valid; returns **null** otherwise.|

**Example**

```
  workScheduler.getWorkStatus(50, (err, res) => {
    if (err) {
      console.info('workschedulerLog getWorkStatus failed, because:' + err.code);
    } else {
      for (let item in res) {
        console.info('workschedulerLog getWorkStatus success,' + item + ' is:' + res[item]);
      }
    }
  });
```

## workScheduler.getWorkStatus
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

**Example**

```
  workScheduler.getWorkStatus(50).then((res) => {
    for (let item in res) {
      console.info('workschedulerLog getWorkStatus success,' + item + ' is:' + res[item]);
    }
  }).catch((err) => {
    console.info('workschedulerLog getWorkStatus failed, because:' + err.code);
  })
```

## workScheduler.obtainAllWorks
obtainAllWorks(callback : AsyncCallback\<void>): Array\<WorkInfo>

Obtains all tasks associated with this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Parameters**

| Name     | Type                  | Mandatory  | Description                             |
| -------- | -------------------- | ---- | ------------------------------- |
| callback | AsyncCallback\<void> | Yes   | Callback used to return all tasks associated with the current application. |

**Return value**

| Type                           | Description             |
| ----------------------------- | --------------- |
| Array\<[WorkInfo](#workinfo)> | All tasks associated with the current application.|

**Example**

```
  workScheduler.obtainAllWorks((err, res) =>{
    if (err) {
      console.info('workschedulerLog obtainAllWorks failed, because:' + err.code);
    } else {
      console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
    }
  });
```

## workScheduler.obtainAllWorks
obtainAllWorks(): Promise<Array\<WorkInfo>>

Obtains all tasks associated with this application. This API uses a promise to return the result.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Return value**

| Type                                    | Description                            |
| -------------------------------------- | ------------------------------ |
| Promise<Array\<[WorkInfo](#workinfo)>> | Promise used to return all tasks associated with the current application. |

**Example**

```
  workScheduler.obtainAllWorks().then((res) => {
    console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
  }).catch((err) => {
    console.info('workschedulerLog obtainAllWorks failed, because:' + err.code);
  })
```

## workScheduler.stopAndClearWorks
stopAndClearWorks(): boolean

Stops and cancels all tasks associated with the current application.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

**Example**

```
  let res = workScheduler.stopAndClearWorks();
  console.info("workschedulerLog res:" + res);
```

## workScheduler.isLastWorkTimeOut
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

**Example**

```
  workScheduler.isLastWorkTimeOut(500, (err, res) =>{
    if (err) {
      console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.code);
    } else {
      console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
    }
  });
```

## workScheduler.isLastWorkTimeOut
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

**Example**

```
  workScheduler.isLastWorkTimeOut(500)
    .then(res => {
      console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
    })
    .catch(err =>  {
      console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.code);
    });
```

## WorkInfo
Provides detailed information about the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name         | Type                             | Mandatory| Description                            |
| --------------- | --------------------------------- | ---- | -------------------------------- |
| workId          | number                            | Yes  | Task ID.                    |
| bundleName      | string                            | Yes  | Name of the Work Scheduler task bundle.                    |
| abilityName     | string                            | Yes  | Name of the component to be notified by a Work Scheduler callback.|
| networkType     | [NetworkType](#networktype)       | No  | Network type.                        |
| isCharging      | boolean                           | No  | Whether the device is charging.                        |
| chargerType     | [ChargingType](#chargingtype)     | No  | Charging type.                        |
| batteryLevel    | number                            | No  | Battery level.                            |
| batteryStatus   | [BatteryStatus](#batterystatus)   | No  | Battery status.                        |
| storageRequest  | [StorageRequest](#storagerequest) | No  | Storage status.                        |
| isRepeat        | boolean                           | No  | Whether the task is repeated.                    |
| repeatCycleTime | number                            | No  | Repeat interval.                        |
| repeatCount     | number                            | No  | Number of repeat times.                        |
| isPersisted     | boolean                           | No  | Whether to enable persistent storage for the task.              |
| isDeepIdle      | boolean                           | No  | Whether the device needs to enter the idle state.        |
| idleWaitTime    | number                            | No  | Time to wait in the idle state.                    |

## NetworkType
Enumerates the network types that can trigger the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                    | Default Value | Description                     |
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

| Name                       | Default Value | Description                  |
| ------------------------- | ---- | -------------------- |
| CHARGING_PLUGGED_ANY      | 0    | Any charging type.|
| CHARGING_PLUGGED_AC       | 1    | DC charging.   |
| CHARGING_PLUGGED_USB      | 2    | USB charging.    |
| CHARGING_PLUGGED_WIRELESS | 3    | Wireless charging.   |

## BatteryStatus
Enumerates the battery states that can trigger the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

| Name                        | Default Value | Description                        |
| -------------------------- | ---- | -------------------------- |
| BATTERY_STATUS_LOW         | 0    | A low battery alert is displayed.            |
| BATTERY_STATUS_OKAY        | 1    | The battery level is restored from low to normal.      |
| BATTERY_STATUS_LOW_OR_OKAY | 2    | The battery level is restored from low to normal, or a low battery alert is displayed.|

## StorageRequest
Enumerates the storage states that can trigger the task.

**System capability**: SystemCapability.ResourceSchedule.WorkScheduler

  |Name   |Default Value   |Description|
  | -------- | -------- | -------- |
  |STORAGE_LEVEL_LOW    |0    |The storage space is insufficient.
  |STORAGE_LEVEL_OKAY    |1    |The storage space is restored from insufficient to normal.
  |STORAGE_LEVEL_LOW_OR_OKAY    |2    |The storage space is restored from insufficient to normal, or the storage space is insufficient.
