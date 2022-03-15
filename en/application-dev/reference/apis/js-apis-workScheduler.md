# Work Scheduler

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import workScheduler from '@ohos.workScheduler' 
```

## workScheduler.startWork
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
workScheduler.startWork(work: WorkInfo): boolean

- **Description**
Instructs the **WorkSchedulerService** to add the specified task to the execution queue.

- **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | work | WorkInfo | Yes| Task to be added to the execution queue.|

- **Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the task is added to the execution queue; returns **false** otherwise.|

- **Example**

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
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
stopWork(work: WorkInfo, needCancel?: boolean): boolean

- **Description**
Instructs the **WorkSchedulerService** to stop the specified task.

- **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | work | WorkInfo | Yes| Task to stop.|
  |needCancel|boolean|    Yes|    Whether to cancel the task.|

- **Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

- **Example**

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
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
getWorkStatus(workId: number, callback : AsyncCallback<WorkInfo>): void

- **Description**
Obtains the latest task status. This method uses an asynchronous callback to return the result.

- **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | workId | number | Yes| Task ID.|
  |callback|AsyncCallback<WorkInfo>|    Yes|    Callback used to return the result. Returns the task status obtained from the **WorkSchedulerService** if the specified task ID is valid; returns **null** otherwise.|


- **Example**

  ```
    workScheduler.getWorkStatus(50, (err, res) => {
      if (err) {
        console.info('workschedulerLog getWorkStatus failed, because:' + err.data);
      } else {
        for (let item in res) {
          console.info('workschedulerLog getWorkStatus success,' + item + ' is:' + res[item]);
        }
      }
    });
  ```

## workScheduler.getWorkStatus
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
getWorkStatus(workID: number): Promise<WorkInfo>

- **Description**
Obtains the latest task status. This method uses a promise to return the result.

- **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | workId | number | Yes| Task ID.|

- **Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise<WorkInfo> | Promise used to return the result. Returns the task status obtained from the **WorkSchedulerService** if the specified task ID is valid; returns **null** otherwise.|

- **Example**

  ```
    workScheduler.getWorkStatus(50).then((res) => {
      for (let item in res) {
        console.info('workschedulerLog getWorkStatus success,' + item + ' is:' + res[item]);
      }
    }).catch((err) => {
      console.info('workschedulerLog getWorkStatus failed, because:' + err.data);
    })
  ```

## workScheduler.obtainAllWorks
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
obtainAllWorks(callback : AsyncCallback<void>): Array<WorkInfo>

- **Description**
Obtains all tasks associated with this application. This method uses an asynchronous callback to return the result.

- **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  |callback|AsyncCallback<WorkInfo>|    Yes|    Callback used to return all tasks associated with the current application.|


- **Return value**

  | Type| Description|
  | -------- | -------- |
  | Array<WorkInfo> | All tasks associated with the current application.|

- **Example**

  ```
    workScheduler.obtainAllWorks((err, res) =>{
      if (err) {
        console.info('workschedulerLog obtainAllWorks failed, because:' + err.data);
      } else {
        console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
      }
    });
  ```

## workScheduler.obtainAllWorks
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
obtainAllWorks(): Promise<Array<WorkInfo>>

- **Description**
Obtains all tasks associated with this application. This method uses a promise to return the result.

- **Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise<Array<WorkInfo>> |    Promise used to return all tasks associated with the current application.|

- **Example**

  ```
    workScheduler.obtainAllWorks().then((res) => {
      console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
    }).catch((err) => {
      console.info('workschedulerLog obtainAllWorks failed, because:' + err.data);
    })
  ```

## workScheduler.stopAndClearWorks
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
stopAndClearWorks(): boolean

- **Description**
Stops and cancels all tasks associated with the current application.

- **Example**

  ```
    let res = workScheduler.stopAndClearWorks();
    console.info("workschedulerLog res:" + res);
  ```

## workScheduler.isLastWorkTimeOut
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
isLastWorkTimeOut(workId: number, callback : AsyncCallback<void>): boolean

- **Description**
Checks whether the last execution of the specified task timed out. This method uses an asynchronous callback to return the result.

- **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | workId | number | Yes| Task ID.|
  |callback|AsyncCallback<WorkInfo>|    Yes|    Callback used to return the result.|

- **Return value**

  | Type| Description|
  | -------- | -------- |
  | boolean | Returns **true** if the last execution of the specified task timed out; returns **false** otherwise.|

- **Example**

  ```
    workScheduler.isLastWorkTimeOut(500, (err, res) =>{
      if (err) {
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.data);
      } else {
        console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
      }
    });
  ```

## workScheduler.isLastWorkTimeOut
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

- **API**
isLastWorkTimeOut(workId: number): Promise<boolean>

- **Description**
Checks whether the last execution of the specified task timed out. This method uses a promise to return the result.

- **Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | workId | number | Yes| Task ID.|

- **Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise<boolean> | Promise used to return the result. Returns **true** if the last execution of the specified task timed out; returns **false** otherwise.|

- **Example**

  ```
    workScheduler.isLastWorkTimeOut(500)
      .then(res => {
        console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
      })
      .catch(err =>  {
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.data);
      });
    })
  ```

## workScheduler.WorkInfo
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

Provides detailed information about the task.

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|workId    |number    |Yes|Task ID.|
|bundleName    |string    |Yes|    Name of the Work Scheduler task bundle.|
|abilityName | string| Yes| Name of the component to be notified by a Work Scheduler callback.|
|networkType | NetworkType| No| Network type.|
|isCharging | bool| No|Whether the device is charging.|
|chargerType | ChargingType| No|Charging type.|
|batteryLevel | number| No|Battery level.|
|batteryStatus| BatteryStatus| No|Battery status.|
|storageRequest|StorageRequest| No|Storage status.|
|isRepeat|boolean|No|Whether the task is repeated.|
|repeatCycleTime |number|No|Repeat interval.|
|repeatCount    |number|No|Number of repeat times.|

## workScheduler.NetworkType
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

Enumerates the network types that can trigger the task.

|Name|Default Value|Description|
| -------- | -------- | -------- |
|NETWORK_TYPE_ANY    |0    |Any network type.|
|NETWORK_TYPE_MOBILE    |1|    Mobile network.|
|NETWORK_TYPE_WIFI    |2    |Wi-Fi network.|
|NETWORK_TYPE_BLUETOOTH    |3    |Bluetooth network.|
|NETWORK_TYPE_WIFI_P2P    |4    |Wi-Fi P2P network.|
|NETWORK_TYPE_ETHERNET    |5    |Ethernet.|

## workScheduler.ChargingType
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

Enumerates the charging types that can trigger the task.

|Name|Default Value|Description|
| -------- | -------- | -------- |
|CHARGING_PLUGGED_ANY    |0|    Any charging type.|
|CHARGING_PLUGGED_AC    |1    |DC charging.|
|CHARGING_PLUGGED_USB    |2    |USB charging.|
|CHARGING_PLUGGED_WIRELESS    |3|    Wireless charging.|

## workScheduler.BatteryStatus
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

Enumerates the battery status that can trigger the task.

|Name|Default Value|Description|
| -------- | -------- | -------- |
|BATTERY_STATUS_LOW    |0    |A low battery alert is displayed.|
|BATTERY_STATUS_OKAY    |1|    The battery level is restored from low to normal.|
|BATTERY_STATUS_LOW_OR_OKAY    |2    |The battery level is restored from low to normal, or a low battery alert is displayed.|

## workScheduler.StorageRequest
- **System capability**
SystemCapability.ResourceSchedule.WorkScheduler

Enumerates the storage status that can trigger the task.

  |Name|Default Value|Description|
  | -------- | -------- | -------- |
  |STORAGE_LEVEL_LOW    |0    |The storage space is insufficient.
  |STORAGE_LEVEL_OKAY    |1    |The storage space is restored from insufficient to normal.
  |STORAGE_LEVEL_LOW_OR_OKAY    |2    |The storage space is restored from insufficient to normal, or the storage space is insufficient.