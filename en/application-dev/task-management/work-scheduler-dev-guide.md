# Work Scheduler Development

## When to Use

If your application needs to execute a non-real-time task, for example, data learning, you can harness the Work Scheduler mechanism, which will schedule the task based on the storage space, power consumption, temperature, and more when the preset conditions are met. For details about the constraints on the Work Scheduler usage, see [Work Scheduler Overview](./work-scheduler-overview.md).


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

 API                                                          | Description                                                  
 ------------------------------------------------------------ | ------------------------------------------------------------ 
 startWork(work: WorkInfo): boolean                           | Starts a Work Scheduler task.                                
 stopWork(work: WorkInfo, needCancel?: boolean): boolean      | Stops a Work Scheduler task.                                 
 getWorkStatus(workId: number, callback: AsyncCallback\<WorkInfo>): void | Obtains the status of a Work Scheduler task. This API uses an asynchronous callback to return the result. 
 getWorkStatus(workId: number): Promise\<WorkInfo>            | Obtains the status of a Work Scheduler task. This API uses a promise to return the result. 
 obtainAllWorks(callback: AsyncCallback\<void>): Array\<WorkInfo> | Obtains Work Scheduler tasks. This API uses an asynchronous callback to return the result. 
 obtainAllWorks(): Promise<Array\<WorkInfo>>                  | Obtains Work Scheduler tasks. This API uses a promise to return the result. 
 stopAndClearWorks(): boolean                                 | Stops and clears Work Scheduler tasks.                       
 isLastWorkTimeOut(workId: number, callback: AsyncCallback\<void>): boolean | Checks whether the last execution of the specified task has timed out. This API uses an asynchronous callback to return the result. It is applicable to repeated tasks. 
 isLastWorkTimeOut(workId: number): Promise\<boolean>         | Checks whether the last execution of the specified task has timed out. This API uses a promise to return the result. It is applicable to repeated tasks. 

**Table 2** WorkInfo parameters

> **NOTE**
>
> For details about the constraints on configuring **WorkInfo**, see [Work Scheduler Overview](./work-scheduler-overview.md).

Name| Type|Description                      
---------------------------------------------------------|-----------------------------------------|---------------------------------------------------------
workId| number | Work ID. Mandatory.
bundleName| string | Name of the Work Scheduler task bundle. Mandatory.
abilityName| string | Name of the component to be notified by a Work Scheduler callback. Mandatory.
networkType  | [NetworkType](../reference/apis/js-apis-workScheduler.md#networktype) | Network type.
isCharging| boolean | Whether the device is charging.
chargerType| [ChargingType](../reference/apis/js-apis-workScheduler.md#chargingtype) | Charging type.
batteryLevel| number | Battery level.
batteryStatus| [BatteryStatus](../reference/apis/js-apis-workScheduler.md#batterystatus) | Battery status.
storageRequest| [StorageRequest](../reference/apis/js-apis-workScheduler.md#storagerequest) |Storage status.
isRepeat| boolean |Whether the task is repeated.
repeatCycleTime| number |Repeat interval.
repeatCount | number|Number of repeat times.

**Table 3** Work Scheduler callbacks

Name                                                   |     Description                           
---------------------------------------------------------|-----------------------------------------
onWorkStart(work: WorkInfo): void | Triggered when the Work Scheduler task starts.
onWorkStop(work: WorkInfo): void | Triggered when the Work Scheduler task stops.

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
        console.info('workschedulerLog getWorkStatus failed, because:' + err.data);
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
      console.info('workschedulerLog getWorkStatus failed, because:' + err.data);
    })


**Obtaining All Work Scheduler Tasks**

1. Callback syntax

    workScheduler.obtainAllWorks((err, res) =>{
      if (err) {
        console.info('workschedulerLog obtainAllWorks failed, because:' + err.data);
      } else {
        console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
      }
    });

2. Promise syntax

    workScheduler.obtainAllWorks().then((res) => {
      console.info('workschedulerLog obtainAllWorks success, data is:' + JSON.stringify(res));
    }).catch((err) => {
      console.info('workschedulerLog obtainAllWorks failed, because:' + err.data);
    })

**Stopping and Clearing Work Scheduler Tasks**

    let res = workScheduler.stopAndClearWorks();
    console.info("workschedulerLog res:" + res);

**Checking Whether the Last Execution Has Timed Out**

1. Callback syntax

    workScheduler.isLastWorkTimeOut(500, (err, res) =>{
      if (err) {
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.data);
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
        console.info('workschedulerLog isLastWorkTimeOut failed, because:' + err.data);
      });
    })
