# 延迟任务调度开发指导

## 场景介绍

应用要执行对实时性要求不高的任务或持久性任务的时候，比如设备空闲时候做一次数据学习等场景，可以使用延迟调度任务，该机制在满足应用设定条件的时候，会根据系统当前状态，如内存、功耗、温度等统一决策调度时间。延迟任务调度约束见[延迟任务调度约束](./background-task-overview.md#延迟任务调度约束)。

## 接口说明

**表1** workScheduler主要接口

接口名                                                    |     接口描述                            
---------------------------------------------------------|-----------------------------------------
startWork(work: WorkInfo): void; | 延迟调度任务申请 
stopWork(work: WorkInfo, needCancel?: boolean): void;        | 延迟调度任务取消 
getWorkStatus(workId: number, callback: AsyncCallback\<WorkInfo>): void;| 获取延迟调度任务状态（Callback形式） 
getWorkStatus(workId: number): Promise\<WorkInfo>; | 获取延迟调度任务状态（Promise形式） 
obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;| 获取所有延迟调度任务（Callback形式） 
obtainAllWorks(): Promise<Array\<WorkInfo>>;| 获取所有延迟调度任务（Promise形式） 
stopAndClearWorks(): void;| 停止并清除任务
isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;| 获取上次任务是否超时（针对RepeatWork，Callback形式）
isLastWorkTimeOut(workId: number): Promise\<boolean>;| 获取上次任务是否超时（针对RepeatWork，Promise形式）

**表2** WorkInfo包含参数

WorkInfo设置参数约束见[延迟任务调度约束](./background-task-overview.md#延迟任务调度约束)

参数名| 类型 |描述                       
---------------------------------------------------------|-----------------------------------------|---------------------------------------------------------
workId| number | 延迟任务ID（必填） 
bundleName| string | 延迟任务Bundle名称（必填） 
abilityName| string | 延迟任务回调通知的组件名（必填）
networkType  | [NetworkType](../reference/apis/js-apis-resourceschedule-workScheduler.md#networktype) | 网络类型
isCharging| boolean | 是否充电 
chargerType| [ChargingType](../reference/apis/js-apis-resourceschedule-workScheduler.md#chargingtype) | 充电类型
batteryLevel| number | 电量
batteryStatus| [BatteryStatus](../reference/apis/js-apis-resourceschedule-workScheduler.md#batterystatus) | 电池状态
storageRequest| [StorageRequest](../reference/apis/js-apis-resourceschedule-workScheduler.md#storagerequest) |存储状态
isRepeat| boolean |是否循环任务
repeatCycleTime| number |循环间隔
repeatCount | number|循环次数
parameters | {[key: string]: any} |携带参数信息

**表3** 延迟任务回调接口

接口名                                                    |     接口描述                            
---------------------------------------------------------|-----------------------------------------
onWorkStart(work: WorkInfo): void | 延迟调度任务开始回调
onWorkStop(work: WorkInfo): void | 延迟调度任务结束回调

### 开发步骤

1、导入模块。

注册相关接口包导入：
```js
import workScheduler from '@ohos.resourceschedule.workScheduler';
```

回调相关接口包导入：
```js
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';
```

2、开发对应的ExtensionAbility，用于回调执行具体的延迟任务。关于ExtensionAbility的介绍，参考[ExtensionAbility机制](../application-models/extensionability-overview.md)。

```ts
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';

export default class MyExtension extends WorkSchedulerExtensionAbility {
    onWorkStart(workInfo) {
        console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
    }
    onWorkStop(workInfo) {
        console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
    }
}
```


3、注册延迟任务

```ts
import workScheduler from '@ohos.resourceschedule.workScheduler';
    
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


4、取消延迟任务

```ts
import workScheduler from '@ohos.resourceschedule.workScheduler';

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


5、获取指定延迟任务

```ts
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


6、获取所有延迟任务

```ts
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

7、停止并清除任务

```ts
try{
  workScheduler.stopAndClearWorks();
  console.info(`workschedulerLog stopAndClearWorks success`);
} catch (error) {
  console.error(`workschedulerLog stopAndClearWorks failed. code is ${error.code} message is ${error.message}`);
}
```

8、判断上次执行是否超时

```ts
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

## 相关实例

基于延迟任务调度，有以下相关实例可供参考：

- [`WorkScheduler`：延迟任务调度（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/ResourcesSchedule/WorkScheduler)