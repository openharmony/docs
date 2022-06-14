# Work Scheduler Development

## When to Use

If your application needs to execute a non-real-time task, for example, data learning, you can harness the Work Scheduler mechanism, which will schedule the task based on the storage space, power consumption, temperature, and more when the preset conditions are met.


## Available APIs
Import the **workScheduler** package to implement registration:
```js
import workScheduler from '@ohos.workScheduler';
```

Import the **WorkSchedulerExtensionAbility** package to implement callback:
```js
import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';
```

### Work Scheduler

**Table 1** Major workScheduler APIs

API                                                   |     Description                           
---------------------------------------------------------|-----------------------------------------
function startWork(work: WorkInfo): boolean; | Starts a Work Scheduler task.
function stopWork(work: WorkInfo, needCancel?: boolean): boolean;        | Stops a Work Scheduler task.
function getWorkStatus(workId: number, callback: AsyncCallback\<WorkInfo>): void;| Obtains the status of a Work Scheduler task. This method uses an asynchronous callback to return the result.
function getWorkStatus(workId: number): Promise\<WorkInfo>; | Obtains the status of a Work Scheduler task. This method uses a promise to return the result.
function obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo>;| Obtains Work Scheduler tasks. This method uses an asynchronous callback to return the result.
function obtainAllWorks(): Promise<Array\<WorkInfo>>;| Obtains Work Scheduler tasks. This method uses a promise to return the result.
function stopAndClearWorks(): boolean;| Stops and clears Work Scheduler tasks.
function isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean;| Checks whether the last execution of the specified task has timed out. This method uses an asynchronous callback to return the result. It is applicable to repeated tasks.
function isLastWorkTimeOut(workId: number): Promise\<boolean>;| Checks whether the last execution of the specified task has timed out. This method uses a promise to return the result. It is applicable to repeated tasks.

**Table 2** WorkInfo parameters

API|Description|Type                          
---------------------------------------------------------|-----------------------------------------|---------------------------------------------------------
workId | Work ID. Mandatory.|number
bundleName | Name of the Work Scheduler task bundle. Mandatory.|string
abilityName | Name of the component to be notified by a Work Scheduler callback.|string
networkType | Network type.| NetworkType
isCharging | Whether the device is charging.| boolean
chargerType | Charging type.| ChargingType
batteryLevel | Battery level.| number
batteryStatus| Battery status.|    BatteryStatus
storageRequest|Storage status.|    StorageRequest
isRepeat|Whether the task is repeated.|    boolean
repeatCycleTime |Repeat interval.|    number
repeatCount    |Number of repeat times.| number

**Table 3** Work Scheduler callbacks

API                                                   |     Description                           
---------------------------------------------------------|-----------------------------------------
function onWorkStart(work: WorkInfo): void; | Triggered when the Work Scheduler task starts.
function onWorkStop(work: WorkInfo): void; | Triggered when the Work Scheduler task stops.

### How to Develop

**Implementing WorkSchedulerExtensionAbility**

    import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';
    
    export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
        onWorkStart(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStart' + JSON.stringify(workInfo));
        }
        onWorkStop(workInfo) {
            console.log('MyWorkSchedulerExtensionAbility onWorkStop' + JSON.stringify(workInfo));
        }
    }


**Registering a Work Scheduler Task**



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


**Canceling the Work Scheduler Task**


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


**Obtaining a Specified Work Scheduler Task**

1. Callback syntax

    workScheduler.getWorkStatus(50, (err, res) => {
      if (err) {
        console.info('workschedulerLog getWorkStatus failed, because:' + err.code);
      } else {
        for (let item in res) {
          console.info('workschedulerLog getWorkStatuscallback success,' + item + ' is:' + res[item]);
        }
      }
    });


2. Promise syntax

    workScheduler.getWorkStatus(50).then((res) => {
      for (let item in res) {
        console.info('workschedulerLog getWorkStatus success,' + item + ' is:' + res[item]);
      }
    }).catch((err) => {
      console.info('workschedulerLog getWorkStatus failed, because:' + err.code);
    })


**Obtaining All Work Scheduler Tasks**

1. Callback syntax

    workScheduler.obtainAllWorks((err, res) =>{
      if (err) {
        console.info('workschedulerLog obtainAllWorks failed, because:' + err.code);
      } else {
        console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
      }
    });

2. Promise syntax

    workScheduler.obtainAllWorks().then((res) => {
      console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
    }).catch((err) => {
      console.info('workschedulerLog obtainAllWorks failed, because:' + err.code);
    })

**Stopping and Clearing Work Scheduler Tasks**

    let res = workScheduler.stopAndClearWorks();
    console.info("workschedulerLog res:" + res);

**Checking Whether the Last Execution Has Timed Out**

1. Callback syntax

    workScheduler.isLastWorkTimeOut(500, (err, res) =>{
      if (err) {
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.code);
      } else {
        console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
      }
    });

2. Promise syntax

    workScheduler.isLastWorkTimeOut(500)
      .then(res => {
        console.info('workschedulerLog isLastWorkTimeOut success, data is:' + res);
      })
      .catch(err =>  {
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.code);
      });
    })
