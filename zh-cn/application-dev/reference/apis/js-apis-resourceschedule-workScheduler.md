# 延迟任务调度

本模块提供延迟任务注册、取消、查询的能力。

开发者在开发应用时，通过调用延迟任务注册接口，注册对实时性要求不高的延迟任务，该任务默认由系统安排，在系统空闲时根据性能、功耗、热等情况进行调度执行。

>  **说明：**
>
>  - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。
>  - 延迟任务调度约束见[延迟任务调度约束](../../task-management/background-task-overview.md#延迟任务调度约束)。


## 导入模块

```js
import workScheduler from '@ohos.resourceschedule.workScheduler';
```

## workScheduler.startWork
startWork(work: WorkInfo): void

通知WorkSchedulerService将工作添加到执行队列。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名  | 类型                    | 必填   | 说明             |
| ---- | --------------------- | ---- | -------------- |
| work | [WorkInfo](#workinfo) | 是    | 指示要添加到执行队列的工作。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Check workInfo failed. |
| 9700005 | StartWork failed. |


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
  try{
    workScheduler.startWork(workInfo);
    console.info('workschedulerLog startWork success');
  } catch (error) {
    console.error(`workschedulerLog startwork failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.stopWork
stopWork(work: WorkInfo, needCancel?: boolean): void

通知WorkSchedulerService停止指定工作。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名        | 类型                    | 必填   | 说明         |
| ---------- | --------------------- | ---- | ---------- |
| work       | [WorkInfo](#workinfo) | 是    | 指示要停止的工作。  |
| needCancel | boolean               | 是    | 是否需要取消的工作。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Check workInfo failed. |

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
  try{
    workScheduler.stopWork(workInfo, false);
    console.info('workschedulerLog stopWork success');
  } catch (error) {
    console.error(`workschedulerLog stopWork failed. code is ${error.code} message is ${error.message}`);
  }
```

## workScheduler.getWorkStatus:callback
getWorkStatus(workId: number, callback : AsyncCallback\<WorkInfo>): void

获取工作的最新状态，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名      | 类型                                    | 必填   | 说明                                       |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| workId   | number                                | 是    | work的id。                                 |
| callback | AsyncCallback\<[WorkInfo](#workinfo)> | 是    | 指定的callback回调方法。如果指定的工作Id有效，则返回从WorkSchedulerService获取的有效工作状态；否则返回null。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Check workInfo failed. |

**示例**：

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

获取工作的最新状态，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名    | 类型     | 必填   | 说明       |
| ------ | ------ | ---- | -------- |
| workId | number | 是    | work的id。 |

**返回值**：

| 类型                              | 说明                                       |
| ------------------------------- | ---------------------------------------- |
| Promise\<[WorkInfo](#workinfo)> | 指定的Promise回调方法。如果指定的工作ID有效，则返回从WorkSchedulerService获取的有效工作状态；否则返回null。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |
| 9700004 | Check workInfo failed. |

**示例**：

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

获取与当前应用程序关联的所有工作，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名      | 类型                   | 必填   | 说明                              |
| -------- | -------------------- | ---- | ------------------------------- |
| callback | AsyncCallback\<void> | 是    | 指定的callback回调方法。返回与应用程序关联的所有工作。 |

**返回值**：

| 类型                            | 说明              |
| ----------------------------- | --------------- |
| Array\<[WorkInfo](#workinfo)> | 返回与应用程序关联的所有工作。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**示例**：

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

获取与当前应用程序关联的所有工作，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**返回值**：

| 类型                                     | 说明                             |
| -------------------------------------- | ------------------------------ |
| Promise<Array\<[WorkInfo](#workinfo)>> | 指定的Promise回调方法。返回与应用程序关联的所有工作。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**示例**：

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

停止和取消与当前应用程序关联的所有工作。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**示例**：

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

检查指定工作的最后一次执行是否为超时操作，使用Callback形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名      | 类型                   | 必填   | 说明                                       |
| -------- | -------------------- | ---- | ---------------------------------------- |
| workId   | number               | 是    | work的id。                                 |
| callback | AsyncCallback\<void> | 是    | 指定的callback回调方法。如果指定工作的最后一次执行是超时操作，则返回true；否则返回false。 |

**返回值**：

| 类型      | 说明                                       |
| ------- | ---------------------------------------- |
| boolean | 指定的callback回调方法。如果指定工作的最后一次执行是超时操作，则返回true；否则返回false。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**示例**：

```js
  try{
    workScheduler.isLastWorkTimeOut(500, (error, res) =>{
      if (error) {
        onsole.error(`workschedulerLog isLastWorkTimeOut failed. code is ${error.code} message is ${error.message}`);
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

检查指定工作的最后一次执行是否为超时操作，使用Promise形式返回。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

**参数**：

| 参数名    | 类型     | 必填   | 说明       |
| ------ | ------ | ---- | -------- |
| workId | number | 是    | work的id。 |

**返回值**：

| 类型                | 说明                                       |
| ----------------- | ---------------------------------------- |
| Promise\<boolean> | 指定的Promise回调方法。如果指定工作的最后一次执行是超时操作，则返回true；否则返回false。 |

**错误码**：

以下错误码的详细介绍请参见[@ohos.resourceschedule.workScheduler (延迟任务调度)](../errorcodes/errorcode-workScheduler.md)错误码。

| 错误码ID  | 错误码信息             |
| ---- | --------------------- |
| 9700001 | Memory operation failed. |
| 9700002 | Parcel operation failed. |
| 9700003 | System service operation failed. |

**示例**：

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
提供工作的具体信息。WorkInfo设置参数约束见[延迟任务调度概述](../../task-management/background-task-overview.md#延迟任务调度约束)

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 参数名             | 类型                                | 必填   | 说明               |
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

| 名称                     | 默认值  | 说明                      |
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

| 名称                        | 默认值  | 说明                   |
| ------------------------- | ---- | -------------------- |
| CHARGING_PLUGGED_ANY      | 0    | 表示这个触发条件是任何类型的充电器连接。 |
| CHARGING_PLUGGED_AC       | 1    | 表示这个触发条件是直流充电器连接。    |
| CHARGING_PLUGGED_USB      | 2    | 表示这个触发条件是USB充连接。     |
| CHARGING_PLUGGED_WIRELESS | 3    | 表示这个触发条件是无线充电器连接。    |

## BatteryStatus
触发工作的电池状态。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 名称                         | 默认值  | 说明                         |
| -------------------------- | ---- | -------------------------- |
| BATTERY_STATUS_LOW         | 0    | 表示这个触发条件是低电告警。             |
| BATTERY_STATUS_OKAY        | 1    | 表示这个触发条件是从低电恢复到正常电量。       |
| BATTERY_STATUS_LOW_OR_OKAY | 2    | 表示这个触发条件是从低电恢复到正常电量或者低电告警。 |

## StorageRequest
触发工作的存储状态。

**系统能力**：SystemCapability.ResourceSchedule.WorkScheduler

| 名称                        | 默认值  | 说明                             |
| ------------------------- | ---- | ------------------------------ |
| STORAGE_LEVEL_LOW         | 0    | 表示这个触发条件是存储空间不足。               |
| STORAGE_LEVEL_OKAY        | 1    | 表示这个触发条件是从存储空间不足恢复到正常。         |
| STORAGE_LEVEL_LOW_OR_OKAY | 2    | 表示这个触发条件是从存储空间不足恢复到正常或者存储空间不足。 |