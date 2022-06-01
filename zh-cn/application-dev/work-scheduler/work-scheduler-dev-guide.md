# 延迟任务调度开发指导

## 场景介绍

应用要执行对实时性要求不高的任务的时候，比如设备空闲时候做一次数据学习等场景，可以使用延迟调度任务，该机制在满足应用设定条件的时候，会根据系统当前状态，如内存、功耗、温度等统一决策调度时间。


## 接口说明
注册相关接口包导入：
```js
import workScheduler from '@ohos.workScheduler';
```

回调相关接口包导入：
```js
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';
```

### 延迟任务调度

**表1** workScheduler主要接口

接口名                                                    |     接口描述                            
---------------------------------------------------------|-----------------------------------------
function startWork(work: WorkInfo): boolean; | 延迟调度任务申请 
function stopWork(work: WorkInfo, needCancel?: boolean): boolean;        | 延迟调度任务取消 
function getWorkStatus(workId: number, callback: AsyncCallback<WorkInfo>): void;| 获取延迟调度任务状态（Callback形式） 
function getWorkStatus(workId: number): Promise<WorkInfo>; | 获取延迟调度任务状态（Promise形式） 
function obtainAllWorks(callback: AsyncCallback<void>): Array<WorkInfo>;| 获取所有延迟调度任务（Callback形式） 
function obtainAllWorks(): Promise<Array<WorkInfo>>;| 获取所有延迟调度任务（Promise形式） 
function stopAndClearWorks(): boolean;| 停止并清除任务
function isLastWorkTimeOut(workId: number, callback: AsyncCallback<void>): boolean;| 获取上次任务是否超时（针对RepeatWork，Callback形式）
function isLastWorkTimeOut(workId: number): Promise<boolean>;| 获取上次任务是否超时（针对RepeatWork，Promise形式）

**表2** WorkInfo包含参数

接口名|描述|类型                           
---------------------------------------------------------|-----------------------------------------|---------------------------------------------------------
workId | 延迟任务Id（必填）|number
bundleName | 延迟任务包名（必填）|string
abilityName | 延迟任务回调通知的组件名（必填）|string
networkType | 网络类型 | NetworkType
isCharging | 是否充电 | boolean
chargerType | 充电类型 | ChargingType
batteryLevel | 电量| number
batteryStatus| 电池状态|    BatteryStatus
storageRequest|存储状态|    StorageRequest
isRepeat|是否循环任务|    boolean
repeatCycleTime |循环间隔|    number
repeatCount    |循环次数| number

**表3** 延迟任务回调接口

接口名                                                    |     接口描述                            
---------------------------------------------------------|-----------------------------------------
function onWorkStart(work: WorkInfo): void; | 延迟调度任务开始回调
function onWorkStop(work: WorkInfo): void; | 延迟调度任务结束回调

### 开发步骤

**开发对应的Extension**

    import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';

    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStart(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
        }
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
        }
    }


**注册延迟任务**



    import workScheduler from '@ohos.workScheduler';

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


**取消延迟任务**


    import workScheduler from '@ohos.workScheduler';

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


**获取指定延迟任务**

1.Callback写法

    workScheduler.getWorkStatus(50, (err, res) => {
      if (err) {
        console.info('workschedulerLog getWorkStatus failed, because:' + err.code);
      } else {
        for (let item in res) {
          console.info('workschedulerLog getWorkStatuscallback success,' + item + ' is:' + res[item]);
        }
      }
    });


2.Promise写法

    workScheduler.getWorkStatus(50).then((res) => {
      for (let item in res) {
        console.info('workschedulerLog getWorkStatus success,' + item + ' is:' + res[item]);
      }
    }).catch((err) => {
      console.info('workschedulerLog getWorkStatus failed, because:' + err.code);
    })


**获取所有延迟任务**

1.Callback写法

    workScheduler.obtainAllWorks((err, res) =>{
      if (err) {
        console.info('workschedulerLog obtainAllWorks failed, because:' + err.code);
      } else {
        console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
      }
    });

2.Promise写法

    workScheduler.obtainAllWorks().then((res) => {
      console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
    }).catch((err) => {
      console.info('workschedulerLog obtainAllWorks failed, because:' + err.code);
    })

**停止并清除任务**

    let res = workScheduler.stopAndClearWorks();
    console.info("workschedulerLog res:" + res);

**判断上次执行是否超时**

1.Callback写法

    workScheduler.isLastWorkTimeOut(500, (err, res) =>{
      if (err) {
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.code);
      } else {
        console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
      }
    });

2.Promise写法

    workScheduler.isLastWorkTimeOut(500)
      .then(res => {
        console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
      })
      .catch(err =>  {
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.code);
      });
    })