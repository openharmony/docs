# 延迟任务调度

本模块提供延迟任务注册、取消、查询的能力。

开发者在开发应用时，通过调用延迟任务注册接口，注册对实时性要求不高的延迟任务，该任务默认由系统安排，在系统空闲时根据性能、功耗、热等情况进行调度执行。

>  **说明：**
>
>  - 从API Version 9 开始，该接口不再维护，推荐使用新接口[@ohos.resourceschedule.workScheduler (延迟任务调度)](js-apis-resourceschedule-workScheduler.md)。
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 延迟任务调度约束见[延迟任务调度概述](../../task-management/work-scheduler-overview.md)。


## 导入模块

```js
import workScheduler from '@ohos.workScheduler';
```

## workScheduler.startWork
startWork(work: WorkInfo): boolean

通知WorkSchedulerService将工作添加到执行队列。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 名称  | 类型                    | 必填   | 说明             |
| ---- | --------------------- | ---- | -------------- |
| work | [WorkInfo](#workinfo) | 是    | 指示要添加到执行队列的工作。 |

**返回值**：

| 类型      | 说明                               |
| ------- | -------------------------------- |
| boolean | 如果工作成功添加到执行队列，则返回true，否则返回false。 |

**示例**：

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
  let res = workScheduler.startWork(workInfo);
  console.info(`workschedulerLog res: ${res}`);
```

## workScheduler.stopWork
stopWork(work: WorkInfo, needCancel?: boolean): boolean

通知WorkSchedulerService停止指定工作。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 名称        | 类型                    | 必填   | 说明         |
| ---------- | --------------------- | ---- | ---------- |
| work       | [WorkInfo](#workinfo) | 是    | 指示要停止的工作。  |
| needCancel | boolean               | 是    | 是否需要取消的工作。 |

**返回值**：

| 类型      | 说明                      |
| ------- | ----------------------- |
| boolean | 如果成功，则返回true，否则返回false。 |

**示例**：

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
  let res = workScheduler.stopWork(workInfo, false);
  console.info(`workschedulerLog res: ${res}`);
```

## workScheduler.getWorkStatus
getWorkStatus(workId: number, callback : AsyncCallback\<WorkInfo>): void

获取工作的最新状态，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名      | 类型                                    | 必填   | 说明                                       |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| workId   | number                                | 是    | work的id。                                 |
| callback | AsyncCallback\<[WorkInfo](#workinfo)> | 是    | 指定的callback回调方法。如果指定的工作Id有效，则返回从WorkSchedulerService获取的有效工作状态；否则返回null。 |

**示例**：

```js
  workScheduler.getWorkStatus(50, (err, res) => {
    if (err) {
      console.info(`workschedulerLog getWorkStatus failed, because: ${err.code}`);
    } else {
      for (let item in res) {
        console.info(`workschedulerLog getWorkStatus success, ${item} is: ${res[item]}`);
      }
    }
  });
```

## workScheduler.getWorkStatus
getWorkStatus(workId: number): Promise\<WorkInfo>

获取工作的最新状态，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 名称    | 类型     | 必填   | 说明       |
| ------ | ------ | ---- | -------- |
| workId | number | 是    | work的id。 |

**返回值**：

| 类型                              | 说明                                       |
| ------------------------------- | ---------------------------------------- |
| Promise\<[WorkInfo](#workinfo)> | 指定的Promise回调方法。如果指定的工作ID有效，则返回从WorkSchedulerService获取的有效工作状态；否则返回null。 |

**示例**：

```js
  workScheduler.getWorkStatus(50).then((res) => {
    for (let item in res) {
      console.info(`workschedulerLog getWorkStatus success, ${item} is: ${res[item]}`);
    }
  }).catch((err) => {
    console.info(`workschedulerLog getWorkStatus failed, because: ${err.code}`);
  })
```

## workScheduler.obtainAllWorks
obtainAllWorks(callback : AsyncCallback\<void>): Array\<WorkInfo>

获取与当前应用程序关联的所有工作，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 名称      | 类型                   | 必填   | 说明                              |
| -------- | -------------------- | ---- | ------------------------------- |
| callback | AsyncCallback\<void> | 是    | 指定的callback回调方法。返回与应用程序关联的所有工作。 |

**返回值**：

| 类型                            | 说明              |
| ----------------------------- | --------------- |
| Array\<[WorkInfo](#workinfo)> | 返回与应用程序关联的所有工作。 |

**示例**：

```js
  workScheduler.obtainAllWorks((err, res) =>{
    if (err) {
      console.info(`workschedulerLog obtainAllWorks failed, because: ${err.code}`);
    } else {
      console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);
    }
  });
```

## workScheduler.obtainAllWorks
obtainAllWorks(): Promise<Array\<WorkInfo>>

获取与当前应用程序关联的所有工作，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**返回值**：

| 类型                                     | 说明                             |
| -------------------------------------- | ------------------------------ |
| Promise<Array\<[WorkInfo](#workinfo)>> | 指定的Promise回调方法。返回与应用程序关联的所有工作。 |

**示例**：

```js
  workScheduler.obtainAllWorks().then((res) => {
    console.info(`workschedulerLog obtainAllWorks success, data is: ${JSON.stringify(res)}`);
  }).catch((err) => {
    console.info(`workschedulerLog obtainAllWorks failed, because: ${err.code}`);
  })
```

## workScheduler.stopAndClearWorks
stopAndClearWorks(): boolean

停止和取消与当前应用程序关联的所有工作。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**示例**：

```js
  let res = workScheduler.stopAndClearWorks();
  console.info(`workschedulerLog res: ${res}`);
```

## workScheduler.isLastWorkTimeOut
isLastWorkTimeOut(workId: number, callback : AsyncCallback\<void>): boolean

检查指定工作的最后一次执行是否为超时操作，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 名称      | 类型                   | 必填   | 说明                                       |
| -------- | -------------------- | ---- | ---------------------------------------- |
| workId   | number               | 是    | work的id。                                 |
| callback | AsyncCallback\<void> | 是    | 指定的callback回调方法。如果指定工作的最后一次执行是超时操作，则返回true；否则返回false。 |

**返回值**：

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 指定的callback回调方法。如果指定工作的最后一次执行是超时操作，则返回true；否则返回false。 |

**示例**：

```js
  workScheduler.isLastWorkTimeOut(500, (err, res) =>{
    if (err) {
      console.info(`workschedulerLog isLastWorkTimeOut failed, because: ${err.code}`);
    } else {
      console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);
    }
  });
```

## workScheduler.isLastWorkTimeOut
isLastWorkTimeOut(workId: number): Promise\<boolean>

检查指定工作的最后一次执行是否为超时操作，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 名称    | 类型     | 必填   | 说明       |
| ------ | ------ | ---- | -------- |
| workId | number | 是    | work的id。 |

**返回值**：

| 类型                | 说明                                       |
| ----------------- | ---------------------------------------- |
| Promise\<boolean> | 指定的Promise回调方法。如果指定工作的最后一次执行是超时操作，则返回true；否则返回false。 |

**示例**：

```js
  workScheduler.isLastWorkTimeOut(500)
    .then(res => {
      console.info(`workschedulerLog isLastWorkTimeOut success, data is: ${res}`);
    })
    .catch(err =>  {
      console.info(`workschedulerLog isLastWorkTimeOut failed, because: ${err.code}`);
    });
```

## WorkInfo
提供工作的具体信息。WorkInfo设置参数约束见[延迟任务调度概述](../../task-management/work-scheduler-overview.md)

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 名称             | 类型                                | 必填   | 说明               |
| --------------- | --------------------------------- | ---- | ---------------- |
| workId          | number                            | 是    | 当前工作的ID          |
| bundleName      | string                            | 是    | 延迟任务包名           |
| abilityName     | string                            | 是    | 延迟任务回调通知的组件名（必填） |
| networkType     | [NetworkType](#networktype)       | 否    | 网络类型             |
| isCharging      | boolean                           | 否    | 是否充电             |
| chargerType     | [ChargingType](#chargingtype)     | 否    | 充电类型             |
| batteryLevel    | number                            | 否    | 电量               |
| batteryStatus   | [BatteryStatus](#batterystatus)   | 否    | 电池状态             |
| storageRequest  | [StorageRequest](#storagerequest) | 否    | 存储状态             |
| isRepeat        | boolean                           | 否    | 是否循环任务           |
| repeatCycleTime | number                            | 否    | 循环间隔             |
| repeatCount     | number                            | 否    | 循环次数             |
| isPersisted     | boolean                           | 否    | 是否持久化保存工作        |
| isDeepIdle      | boolean                           | 否    | 是否要求设备进入空闲状态     |
| idleWaitTime    | number                            | 否    | 空闲等待时间           |
| parameters      | {[key: string]: any}              | 否    | 携带参数信息           |

## NetworkType
触发工作的网络类型。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 名称                     | 值  | 说明                      |
| ---------------------- | ---- | ----------------------- |
| NETWORK_TYPE_ANY       | 0    | 表示这个触发条件是任何类型的网络连接。     |
| NETWORK_TYPE_MOBILE    | 1    | 表示这个触发条件是Mobile网络连接。    |
| NETWORK_TYPE_WIFI      | 2    | 表示这个触发条件是Wifi类型的网络连接。   |
| NETWORK_TYPE_BLUETOOTH | 3    | 表示这个触发条件是Bluetooth网络连接。 |
| NETWORK_TYPE_WIFI_P2P  | 4    | 表示这个触发条件是Wifi P2P网络连接。  |
| NETWORK_TYPE_ETHERNET  | 5    | 表示这个触发条件是有线网络连接。        |

## ChargingType
触发工作的充电类型。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 名称                        | 值  | 说明                   |
| ------------------------- | ---- | -------------------- |
| CHARGING_PLUGGED_ANY      | 0    | 表示这个触发条件是任何类型的充电器连接。 |
| CHARGING_PLUGGED_AC       | 1    | 表示这个触发条件是直流充电器连接。    |
| CHARGING_PLUGGED_USB      | 2    | 表示这个触发条件是USB充连接。     |
| CHARGING_PLUGGED_WIRELESS | 3    | 表示这个触发条件是无线充电器连接。    |

## BatteryStatus
触发工作的电池状态。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 名称                         | 值  | 说明                         |
| -------------------------- | ---- | -------------------------- |
| BATTERY_STATUS_LOW         | 0    | 表示这个触发条件是低电告警。             |
| BATTERY_STATUS_OKAY        | 1    | 表示这个触发条件是从低电恢复到正常电量。       |
| BATTERY_STATUS_LOW_OR_OKAY | 2    | 表示这个触发条件是从低电恢复到正常电量或者低电告警。 |

## StorageRequest
触发工作的存储状态。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 名称                        | 值  | 说明                             |
| ------------------------- | ---- | ------------------------------ |
| STORAGE_LEVEL_LOW         | 0    | 表示这个触发条件是存储空间不足。               |
| STORAGE_LEVEL_OKAY        | 1    | 表示这个触发条件是从存储空间不足恢复到正常。         |
| STORAGE_LEVEL_LOW_OR_OKAY | 2    | 表示这个触发条件是从存储空间不足恢复到正常或者存储空间不足。 |