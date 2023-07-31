# Deferred Task

## Overview

### Introduction

If an application needs to execute a non-real-time task after switching to the background, for example, if the application wants to obtain emails irregularly when the network is available, the application can request deferred tasks. When the specified conditions (including the network type, charging type, storage status, battery status, and timing status) are met, the system adds the task to the execution queue. Then the system starts the application to execute the task based on the memory, power consumption, device temperature, and user habits.

### Working Principle

**Figure 1** Working principle of deferred task scheduling

![WorkScheduler](figures/WorkScheduler.png)

An application calls the **WorkScheduler** APIs to register, delete, and query deferred tasks. Based on the task-specific conditions (specified by **WorkInfo**, including the network type, charging type, and storage status) and system status (including the memory, power consumption, device temperature, and user habits), the WorkSchedulerService determines the time to schedule the tasks.

When the scheduling conditions are met or the task scheduling ends, the system calls back **onWorkStart()** or **onWorkStop()** in [WorkSchedulerExtensionAbility](../reference/apis/js-apis-WorkSchedulerExtensionAbility.md). The system also creates an independent process for the **WorkSchedulerExtensionAbility** and provides a duration for the **WorkSchedulerExtensionAbility** to run. You can implement your own service logic in the callback functions.


### Constraints

- **Quantity limit**: An application can request a maximum of 10 deferred tasks during a time segment.

- **Execution frequency limit**: The system controls the execution frequency of deferred tasks based on the [application activity group](../reference/apis/js-apis-resourceschedule-deviceUsageStatistics.md). Applications that request the WORK_SCHEDULER resource are placed in the efficiency resource exemption group.

  **Table 1** Application activity groups
  
  | Group| Deferred Task Execution Frequency|
  | -------- | -------- |
  | Group of active applications| At a minimum interval of 2 hours|
  | Group of frequently used applications| At a minimum interval of 4 hours|
  | Group of applications that are used neither frequently nor rarely| At a minimum interval of 24 hours|
  | Group of rarely used applications| At a minimum interval of 48 hours|
  | Group of restricted applications| Forbidden|
  | Group of applications never used| Forbidden|
  | Efficiency resource exemption group| No restriction|
  
- **Timeout**: The WorkSchedulerExtensionAbility can run for a maximum of 2 minutes for a single callback. If the application does not cancel the deferred task upon a timeout, the system forcibly terminates the process for the WorkSchedulerExtensionAbility. Privileged system applications can request the WORK_SCHEDULER resource to extend the duration to 20 minutes in the charging state and 10 minutes in the non-charging state.

- **Scheduling delay**: The system schedules deferred tasks in a unified manner based on the memory, power consumption, device temperature, and user habits. For example, when the system memory resources are insufficient or the temperature reaches a certain level, the system delays task scheduling.

- **Restrictions for WorkSchedulerExtensionAbility**: The following APIs cannot be called in the WorkSchedulerExtensionAbility:

  [@ohos.resourceschedule.backgroundTaskManager (Background Task Management)](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md)

  [@ohos.backgroundTaskManager (Background Task Management)](../reference/apis/js-apis-backgroundTaskManager.md)

  [@ohos.multimedia.camera (Camera Management)](../reference/apis/js-apis-camera.md)

  [@ohos.multimedia.audio (Audio Management)](../reference/apis/js-apis-audio.md)

  [@ohos.multimedia.media (Media)](../reference/apis/js-apis-media.md)


## Available APIs

The table below lists the APIs used for developing deferred tasks. For details about more APIs and their usage, see [@ohos.resourceschedule.workScheduler (Deferred Task Scheduling)](../reference/apis/js-apis-resourceschedule-workScheduler.md).

**Table 2** Main APIs for deferred tasks

| API| Description|
| -------- | -------- |
| startWork(work: WorkInfo): void; | Starts a deferred task.|
| stopWork(work: WorkInfo, needCancel?: boolean): void; | Stops a deferred task.|
| getWorkStatus(workId: number, callback: AsyncCallback&lt;WorkInfo&gt;): void; | Obtains the status of a deferred task. This API uses an asynchronous callback to return the result.|
| getWorkStatus(workId: number): Promise&lt;WorkInfo&gt;; | Obtains the status of a deferred task. This API uses a promise to return the result.|
| obtainAllWorks(callback: AsyncCallback&lt;void&gt;): Array&lt;WorkInfo&gt;; | Obtains all the deferred tasks. This API uses an asynchronous callback to return the result.|
| obtainAllWorks(): Promise&lt;Array&lt;WorkInfo&gt;&gt;; | Obtains all the deferred tasks. This API uses a promise to return the result.|
| stopAndClearWorks(): void; | Stops and clears all the deferred tasks.|
| isLastWorkTimeOut(workId: number, callback: AsyncCallback&lt;void&gt;): boolean; | Checks whether the last execution of a deferred task has timed out. This API uses an asynchronous callback to return the result. It is applicable to repeated tasks.|
| isLastWorkTimeOut(workId: number): Promise&lt;boolean&gt;; | Checks whether the last execution of a deferred task has timed out. This API uses a promise to return the result. It is applicable to repeated tasks.|

**Table 3** Options of WorkInfo
| Name| Type| Description.|
| -------- | -------- | -------- |
| workId | number | ID of a deferred task. This parameter is mandatory.|
| bundleName | string | Bundle name of the application that requests the deferred task.|
| abilityName | string | Name of the ability to be notified by a deferred task scheduling callback. This parameter is mandatory.|
| networkType | [NetworkType](../reference/apis/js-apis-resourceschedule-workScheduler.md#networktype) | Network type.|
| isCharging | boolean | Whether the device is charging.|
| chargerType | [ChargingType](../reference/apis/js-apis-resourceschedule-workScheduler.md#chargingtype) | Charging type.|
| batteryLevel | number | Battery level.|
| batteryStatus | [BatteryStatus](../reference/apis/js-apis-resourceschedule-workScheduler.md#batterystatus) | Battery status.|
| storageRequest | [StorageRequest](../reference/apis/js-apis-resourceschedule-workScheduler.md#storagerequest) | Storage status.|
| isRepeat | boolean | Whether the deferred task is repeated.|
| repeatCycleTime | number | Repeat interval.|
| repeatCount | number | Number of repeat times.|
| parameters | [key: string]: number | Carried parameters.|

The **WorkInfo** parameter is used to set conditions for triggering task scheduling. Its setting must comply with the following rules:

- **workId**, **bundleName**, and **abilityName** are mandatory. **bundleName** must be set to the bundle name of the current application.

- The carried parameters can be of the number, string, or boolean type.

- At least one condition must be set, including the network type, charging type, storage status, battery status, and timing status.

- For repeated tasks, **repeatCycleTime** must be at least 20 minutes. When **isRepeat** is set, you must set **repeatCycleTime** or **repeatCount**.

The table below lists the APIs used for developing deferred task scheduling callbacks. For details about more APIs and their usage, see [@ohos.WorkSchedulerExtensionAbility (Deferred Task Scheduling Callbacks)](../reference/apis/js-apis-WorkSchedulerExtensionAbility.md).

**Table 4** Deferred task scheduling callbacks

| API| Description|
| -------- | -------- |
| onWorkStart(work: WorkInfo): void | Called when the system starts scheduling the deferred task.|
| onWorkStop(work: WorkInfo): void | Called when the system stops scheduling the deferred task.|


## How to Develop

The development of deferred task scheduling consists of two steps: implementing the deferred task scheduling capability and implementing deferred task scheduling.

1. **Implementing the deferred task scheduling capability**: Implement the callbacks for starting and stopping the WorkSchedulerExtensionAbility.

2. **Implementing deferred task scheduling**: Call the **WorkScheduler** APIs to start and stop delayed tasks.

### Implementing Deferred Task Scheduling Callbacks

1. Create a project directory.

   In the **./entry/src/main/ets** directory of the project, create a directory and an ArkTS file. For example, create a directory and name it **extension**. In the **extension** directory, create an ArkTS file named **WorkSchedulerExtension.ets** and implement the callbacks for deferred task scheduling.

2. Import the module.
   
   ```ts
   import WorkSchedulerExtensionAbility from '@ohos.WorkSchedulerExtensionAbility';
   ```

3. Implement the lifecycle callbacks for the WorkSchedulerExtensionAbility.
   
   ```ts
   export default class MyWorkSchedulerExtensionAbility extends WorkSchedulerExtensionAbility {
     // Callback invoked when the system starts scheduling the deferred task.
     onWorkStart(workInfo) {
       console.info(`onWorkStart, workInfo = ${JSON.stringify(workInfo)}`);
     }
   
     // Callback invoked when the system stops scheduling the deferred task.
     onWorkStop(workInfo) {
       console.info(`onWorkStop, workInfo is ${JSON.stringify(workInfo)}`);
     }
   }
   ```

4. Register the WorkSchedulerExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) and set the tags as follows:

   - Set **type** to **workScheduler**.

   - Set **srcEntry** to the code path of the WorkSchedulerExtensionAbility component.

   ```json
   {
     "module": {
         "extensionAbilities": [
           {
             "name": "MyWorkSchedulerExtensionAbility",
             "srcEntry": "./ets/WorkSchedulerExtension/WorkSchedulerExtension.ts",
             "label": "$string:WorkSchedulerExtensionAbility_label",
             "description": "$string:WorkSchedulerExtensionAbility_desc",
             "type": "workScheduler"
           }
         ]
     }
   }
   ```


### Implementing Deferred Task Scheduling

1. Import the module.
   
   ```ts
   import workScheduler from '@ohos.resourceschedule.workScheduler';
   ```

2. Start a deferred task.
   
   ```ts
   private workInfo = {
     workId: 1,
     networkType: workScheduler.NetworkType.NETWORK_TYPE_WIFI,
     bundleName: 'com.example.application',
     abilityName: 'MyWorkSchedulerExtensionAbility'
   }
   
   try {
     workScheduler.startWork(this.workInfo);
     console.info(`startWork success`);
   } catch (error) {
     console.error(`startWork failed. code is ${error.code} message is ${error.message}`);
   }
   ```

3. Cancel the deferred task.
   
   ```ts
   private workInfo = {
     workId: 1,
     networkType: workScheduler.NetworkType.NETWORK_TYPE_WIFI,
     bundleName: 'com.example.application', 
     abilityName: 'MyWorkSchedulerExtensionAbility' 
   }
   
   try {
     workScheduler.stopWork(this.workInfo);
     console.info(`stopWork success`);
   } catch (error) {
     console.error(`stopWork failed. code is ${error.code} message is ${error.message}`);
   }
   ```

