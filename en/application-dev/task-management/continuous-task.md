# Continuous Task (ArkTS)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @xufu7-->
<!--Designer: @zhouben25-->
<!--Tester: @leetestnady-->
<!--Adviser: @HelloCrease-->

## Overview

### Introduction

If an application has a perceivable task that needs to run in an extended period of time in the background, it can request a continuous task to prevent itself from being suspended. Examples of continuous tasks include music playback and navigation in the background. Within a continuous task, the application can concurrently request multiple types of tasks and update the task types. When the application operates in the background, the system performs consistency check to ensure that the application is executing the corresponding continuous task. Upon successful request for a continuous task, the notification panel displays the message associated with the task. If the user deletes the message, the system automatically terminates the task.

> **NOTE**
> 
> After an application is moved to the background, its lifecycle changes vary depending on the device type. For details, see [Differentiated Behavior of UIAbility Lifecycle on Different Devices](../windowmanager/window-lifecycle.md#differentiated-behavior-of-uiability-lifecycle-on-different-devices).

### Use Cases

The table below lists the types of continuous tasks, which are used in various scenarios. You can select a task type suitable for your case based on the description.

**Table 1** Continuous task types
| Name| Description| Item| Example Scenario|
| -------- | -------- | -------- | -------- |
| DATA_TRANSFER | Data transfer.| dataTransfer | Non-hosting uploading and downloading operations, like those occurring in the background of a web browser for data transfer.|
| AUDIO_PLAYBACK | Audio and video playback.<br> **Note:** Availble in atomic services since API version 12.| audioPlayback | Audio and video playback in the background; audio and video casting.|
| AUDIO_RECORDING | Recording.| audioRecording | Recording and screen capture in the background.|
| LOCATION | Positioning and navigation.<br>**Note:** Availble in atomic services since API version 26.0.0.| location | Positioning and navigation.|
| BLUETOOTH_INTERACTION | Bluetooth-related services.| bluetoothInteraction | An application transitions into the background during the process of file transfer using Bluetooth.|
| MULTI_DEVICE_CONNECTION | Multi-device connection.<br> **Note:** Availble in atomic services since API version 12.| multiDeviceConnection | Distributed service connection and casting.|
| <!--DelRow-->WIFI_INTERACTION | WLAN-related services (for system applications only).| wifiInteraction  | An application transitions into the background during the process of file transfer using WLAN.|
| VOIP | Audio and video calls.<br>**Note**: It is supported since API version 13.| voip  | Chat applications (with audio and video services) transition into the background during audio and video calls.|
| TASK_KEEPING | Computing tasks.<br>**Note**: Starting from API version 21, this capability is made available to applications on non‑PC/2‑in‑1 devices that have obtained the ACL permission [ohos.permission.KEEP_BACKGROUND_RUNNING_SYSTEM](../security/AccessToken/restricted-permissions.md#ohospermissionkeep_background_running_system). For PC/2‑in‑1 devices, applications are not required to apply for the ACL permission. In API version 20 and earlier versions, this task type is limited to PCs/2-in-1 devices only.| taskKeeping  | Antivirus software is running.|
| MODE_AV_PLAYBACK_AND_RECORD | Multimedia services.<br>**Note**: It is supported since API version 22.<br>It is availble in atomic services since API version 26.0.0.| avPlaybackAndRecord  | When an application is in the background during audio/video playback, recording, or audio/video calls, you can select either this task type or the corresponding continuous task type for these three scenarios. For example, in the audio/video playback scenario, you can choose either **AUDIOPLAYBACK** or **MODE_AVPLAYBACK_AND_RECORD**.|
| MODE_SPECIAL_SCENARIO_PROCESSING | Special scenarios (available only for smartphones, tablets, PCs/2-in-1 devices).<br>**Note**: It is supported since API version 22.| specialScenarioProcessing  | Exporting media files in the background, using a third‑party casting component to cast in the background, and providing indoor sports scenarios when the application is running in the background|
| MODE_NEARLINK | NearLink service.<br>**Since**: 26.0.0 | nearlink | An application transitions into the background during the process of file transfer using NearLink.|

Description of **DATA_TRANSFER**:

- During data transfer, if an application uses the [@ohos.request (Upload and Download)](../reference/apis-basic-services-kit/js-apis-request.md) to hand over tasks to the system, the application will be suspended in the background even if it has requested the continuous task of the **DATA_TRANSFER** type.

- During data transfer, the application needs to update the progress. If the progress is not updated for a long time (more than 10 minutes after the first update), the continuous task of the **DATA_TRANSFER** type will be canceled. The notification type of the progress update must be live view. For details, see the example in [startBackgroundRunning()](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning12).

Description of **AUDIO_PLAYBACK**:

- Casting audio and video involves transmitting content from one device to another for playback purposes. If the application transitions to the background while casting, the continuous task checks the audio and video playback and casting services. The task will persist as long as either the audio and video playback or casting service is running properly.

- If the application needs to play media (STREAM_USAGE_MUSIC, STREAM_USAGE_MOVIE, or STREAM_USAGE_AUDIOBOOK) or games (STREAM_USAGE_GAME) in the background, it must access the [AVSession](../media/avsession/avsession-overview.md) service and request a continuous task of the AUDIO_PLAYBACK type.

- In addition to the aforementioned playback types, when an application needs to run other user-perceptible tasks in the background for a long time, it must request continuous tasks of the **AUDIO_PLAYBACK** type, without accessing AVSession.

- If the application does not comply with the preceding access specifications, it will be muted and suspended by the system when switched to the background. It can resume playback only when it returns to the foreground.

- Starting from API version 20, if a continuous task of the **AUDIO_PLAYBACK** type is requested without being connected to AVSession, a notification will appear in the notification panel once the task is successfully requested. Once AVSession is connected, the background task module will no longer send notifications; instead, notifications will be sent by AVSession. For API version 19 and earlier versions, the background task module does not display notifications in the notification panel.

- The system may freeze an application that requests a continuous task of the **AUDIO_PLAYBACK** type if no audio is playing while the application is in the background.

- It is recommended that the application set up a listener for the audio pause event [on('pause')](../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#onpause10). If the audio pause event is reported and audio playback is no longer required afterwards, it is advisable to cancel the previously requested continuous task for audio/video playback.

Description of **BLUETOOTH_INTERACTION** (Bluetooth-related services):

If an application applies only for a Bluetooth continuous task, it will be canceled upon Bluetooth disconnection caused by device distance. To ensure a seamless Bluetooth connection experience, the system allows applications that meet the following conditions to keep alive for a period of time (depending on the system load, up to 10 minutes) after the connection is restored, so that the applications can run in the background for a long time.

1. Register the event of suspending the listening of a continuous task so that the task is marked as suspended instead of being immediately canceled by the system. For details, see [on('continuousTaskSuspend')](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanageroncontinuoustasksuspend20).
2. To enable timely reconnection after Bluetooth disconnection, subscribe to the Bluetooth connection state change event via [on('connectionStateChange')](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#onconnectionstatechange). After disconnection, initiate a BLE scan using [startScan](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#startscan15), subscribe to the BLE device scan result reporting event via [on('BLEDeviceFind')](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#onbledevicefind15), and check whether the device is back within the connectable range.
3. After successfully scanning the device, the application needs to proactively restore the Bluetooth connection via [connect](../reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#connect). The system then reactivates the suspended continuous task and keeps it alive.
4. Starting from API version 26.0.0, within a certain period after a [BR](../connectivity/bluetooth/terminology.md#br) Bluetooth disconnection (the exact duration depends on system load and can be up to ten minutes), you can use the [onAclStateChange](../reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectiononaclstatechange) API to listen for ACL connection state changes and re‑establish keep‑alive.

Description of the MODE_NEARLINK (NearLink service):

If an application applies only for a NearLink continuous task, it will be canceled upon NearLink disconnection caused by device distance. To ensure a seamless NearLink connection experience, within 1 to 10 minutes after disconnection (the exact duration depends on system load), the system allows applications that meet the following conditions to re‑establish keep‑alive upon reconnection, enabling them to run for an extended period in the background.
 
1. Register the event of suspending the listening of a continuous task so that the task is marked as suspended instead of being immediately canceled by the system. For details, see [on('continuousTaskSuspend')](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanageroncontinuoustasksuspend20).
2. To ensure timely connection recovery after a NearLink disconnection, the local device application subscribes to NearLink scan results after the connection is established. Upon disconnection, the local device actively initiates NearLink scanning, while the peer device sends NearLink advertisements.
3. After successfully scanning for the peer device, the local device needs to initiate a connection request to the peer device. If there are no other service scanning requirements, the local device can stop NearLink scanning.

Description of continuous task notifications:

After an application successfully applies for a continuous task, the system displays a continuous task notification dialog in the notification panel. The dialog lifecycle is bound to the application period of the continuous task. When the continuous task is canceled, the notification is also canceled. It is recommended that applications request and release continuous tasks according to their specific business needs. If the application does not want the notification to appear while it is in the foreground, it is advisable to defer the request for the continuous task until the [onBackground](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onbackground) lifecycle callback is triggered.

### Constraints

**Ability restrictions**: In the stage model, only the UIAbility can request continuous tasks. In the FA model, only the ServiceAbility can request continuous tasks. Continuous tasks can be requested by the current application on the current device or across devices or by other applications. However, the capability to make cross-device or cross-application requests is restricted to system applications.

**Quantity restrictions**:
- Since API version 21, a single UIAbility can request multiple continuous tasks simultaneously, with a maximum limit of 10. For details, see [startBackgroundRunning()](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning21). For API version 20 and earlier versions, a UIAbility (ServiceAbility in the FA model) can only request one continuous task at a time. If a UIAbility already has an ongoing continuous task, it can only submit a new request after the existing task is completed. If an application needs to request multiple continuous tasks simultaneously, it must create multiple UIAbilities.
- If an application has multiple UIAbilities, once one UIAbility successfully requests a continuous task, all processes of the entire application will not be suspended.

**Running restrictions**:

- If an application requests a continuous task but does not carry out the relevant service, the system imposes restrictions on the application. For example, if the system detects that an application has requested a continuous task of the AUDIO_PLAYBACK type but does not play audio, the application will be suspended when it returns to the background.

- If an application requests a continuous task but carries out a service that does not match the requested type, the system imposes restrictions on the application. The application will be suspended or terminated when it returns to the background. For example, if the system detects that an application requests a continuous task of the AUDIO_PLAYBACK type, but the application is playing audio (corresponding to the AUDIO_PLAYBACK type) and recording (corresponding to the AUDIO_RECORDING type), the system enforces management measures.

- If an application does not request a continuous task for audio/video playback or recording but still performs such operations in the background, the system will take control measures and kill the application when it is moved to the background. It is recommended that an application request a continuous task for audio/video playback or recording in advance if it needs to perform such operations in the background.

- When an application's operations are completed after a continuous task request, the system imposes restrictions on the application. The application will be suspended when it returns to the background.

- If the background load of the process that runs a continuous task is higher than the corresponding typical load for a long period of time, the system performs certain control. The application will be suspended or terminated when it is switched to the background.

> **NOTE**
>
> An application must proactively cancel a continuous task once the task is completed. Otherwise, the application will be suspended when moved to the background. For example, when a user taps the UI to pause music playback, the application must cancel the continuous task in a timely manner. When the user taps the UI again to continue music playback, the application needs to request a continuous task.
>
> If an application that plays an audio in the background is [interrupted](../media/audio/audio-playback-concurrency.md), the system automatically detects and stops the continuous task. The application must request a continuous task again to restart the playback.
>
> When an application that plays audio in the background stops a continuous task, it must suspend or stop the audio stream. Otherwise, the application will be forcibly terminated by the system.

## Available APIs

**Table 2** Main APIs for continuous tasks

The table below uses promise as an example to describe the APIs used for developing continuous tasks. For details about more APIs and their usage, see [Background Task Management](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md).

| API| Description|
| -------- | -------- |
| [startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt;](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning-1) | Requests a continuous task. A UIAbility can apply for only one continuous task at a time. If a UIAbility already has an ongoing continuous task, it can only submit a new request after the existing task is completed.|
| [stopBackgroundRunning(context: Context): Promise&lt;void&gt;](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning-1)  | Cancels a continuous task.|
| [startBackgroundRunning(context: Context, request: ContinuousTaskRequest): Promise&lt;ContinuousTaskNotification&gt;](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning21) | Requests multiple continuous tasks. This API enables a UIAbility to request multiple continuous tasks simultaneously, with a maximum limit of 10.|
| [stopBackgroundRunning(context: Context, continuousTaskId: number): Promise&lt;void&gt;](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstopbackgroundrunning21) | Cancels a continuous task with the specified ID.|

## How to Develop

The following walks you through how to request a continuous task for audio and video playback to implement the following functionalities:

- Click the **Request continuous task** button. The app successfully applies for a continuous task of the audio and video playback type, and the related notification is displayed in the notification bar.

- When a user touches **Cancel Continuous Task**, the application cancels the continuous task, and the notification message is removed.

### Stage Model

1. Declare the **ohos.permission.KEEP_BACKGROUND_RUNNING** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Declare the continuous task type.

   Declare the type of the continuous task for the target UIAbility under **abilities** in the [module.json5 file](../quick-start/module-configuration-file.md). Set the corresponding [configuration item](continuous-task.md#use-cases) in the configuration file.

   <!-- @[continuous_task_configure](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/BackGroundTasksKit/ContinuousTask/entry/src/main/module.json5) -->
   
   ``` JSON5
   "module": {
     // ...
     "abilities": [
       {
         // ...
         "backgroundModes": [
           // Configuration item of the continuous task type
           "audioRecording",
           "bluetoothInteraction",
           "audioPlayback"
         ],
         // ...
       }
     ],
     // ...
   }
   ```

3. Import the modules.
   
   Import the modules related to continuous tasks: @ohos.resourceschedule.backgroundTaskManager and @ohos.app.ability.wantAgent. Import other modules based on the project requirements.
    <!--RP1-->

    <!-- @[continuous_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/BackGroundTasksKit/ContinuousTask/entry/src/main/ets/pages/audioPlayback/AudioPlaybackIndex.ets) -->
    
    ``` TypeScript
    import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
    import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
    import { rpc } from '@kit.IPCKit'
    import { BusinessError } from '@kit.BasicServicesKit';
    import { wantAgent, WantAgent } from '@kit.AbilityKit';
    // In atomic services, please remove the WantAgent import.
    ```
    <!--RP1End-->

4. Request and cancel a continuous task.

   The code snippet below shows how an application requests and cancels a continuous task for itself.
   
   Since API version 15, you can use [on('continuousTaskCancel')](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanageroncontinuoustaskcancel15) to listen for the cancellation of a continuous task.
   
   Since API version 16, you can use [BackgroundSubMode](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundsubmode16) to implement the Bluetooth car key function.

   <!-- @[continuous_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/BackGroundTasksKit/ContinuousTask/entry/src/main/ets/pages/audioPlayback/AudioPlaybackIndex.ets) -->
   
   ``` TypeScript
   function callback(info: backgroundTaskManager.ContinuousTaskCancelInfo) {
     // ID of a continuous task.
     console.info('OnContinuousTaskCancel callback id ' + info.id);
     // Reason for canceling the continuous task.
     console.info('OnContinuousTaskCancel callback reason ' + info.reason);
   }
   
   @Entry
   @Component
   struct AudioPlaybackIndex {
     @State message: string = 'ContinuousTask';
     // Obtain the UIAbility context of the page by calling getUIContext().getHostContext().
     private context: Context | undefined = this.getUIContext().getHostContext();
   
     // ...
   
     OnContinuousTaskCancel() {
       try {
         backgroundTaskManager.on('continuousTaskCancel', callback);
         console.info(`Succeeded in operationing OnContinuousTaskCancel.`);
       } catch (error) {
         console.error(`Operation OnContinuousTaskCancel failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
       }
     }
   
     OffContinuousTaskCancel() {
       try {
         // If the callback parameter is not passed, all callbacks associated with the specified event are canceled.
         backgroundTaskManager.off('continuousTaskCancel', callback);
         console.info(`Succeeded in operationing OffContinuousTaskCancel.`);
       } catch (error) {
         console.error(`Operation OffContinuousTaskCancel failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
       }
     }
   
     // Request a continuous task using .then().
     startContinuousTask() {
       let wantAgentInfo: wantAgent.WantAgentInfo = {
         // List of operations to be executed after the notification is clicked.
         // Add the bundleName and abilityName of the application to start.
         wants: [
           {
             bundleName: 'ohos.samples.continuoustask',
             abilityName: 'MainAbility'
           }
         ],
         // Specify the action to perform (starting the ability) after the notification message is clicked.
         actionType: wantAgent.OperationType.START_ABILITY,
         // Custom request code.
         requestCode: 0,
         // Execution attribute of the operation to perform after the notification is clicked.
         actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
         // CAR_KEY subtype, which takes effect only when a continuous task of the bluetoothInteraction type is requested. This subtype is supported since API version 16.
         // Ensure that the key value in the extraInfo parameter is backgroundTaskManager.BackgroundModeType.SUB_MODE. Otherwise, the subtype does not take effect.
         // extraInfo: {
           // [backgroundTaskManager.BackgroundModeType.SUB_MODE] :backgroundTaskManager.BackgroundSubMode.CAR_KEY
         // }
       };
   
       try {
         // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
         // In atomic services, replace the following line of code with wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {.
         wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
           try {
             let list: string[] = ['audioPlayback'];
             // let list: string[] = ['bluetoothInteraction']; The bluetoothInteraction type is included in the continuous task, and the CAR_KEY subtype is valid.
             backgroundTaskManager.startBackgroundRunning(this.context, list, wantAgentObj).
               then((res: backgroundTaskManager.ContinuousTaskNotification) => {
               console.info('Operation startBackgroundRunning succeeded');
               // Execute the continuous task logic, for example, audio playback.
               // The system checks the authenticity of the service scenario. If the corresponding service is not executed, the system may cancel the continuous task and suspend the application.
               // ...
             }).catch((error: BusinessError) => {
               console.error(`Failed to Operation startBackgroundRunning. code is ${error.code} message is ${error.message}`);
             });
           } catch (error) {
             console.error(`Failed to Operation startBackgroundRunning. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
           }
         });
       } catch (error) {
         console.error(`Failed to Operation getWantAgent. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
       }
     }
   
     // Cancel a continuous task using .then().
     stopContinuousTask() {
       backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
         console.info(`Succeeded in operationing stopBackgroundRunning.`);
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
       });
     }
   
     build() {
       Row() {
         Column() {
           Text('Index')
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
   
           Button() {
             Text('Request continuous task').fontSize(25).fontWeight(FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({ top: 10 })
           .backgroundColor('#0D9FFB')
           .width(250)
           .height(40)
           .id('applyContinuousTask')
           .onClick(() => {
             // Request a continuous task by clicking a button.
             this.startContinuousTask();
           })
   
           Button() {
             Text ('Cancel continuous task').fontSize (25).fontWeight (FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({ top: 10 })
           .backgroundColor('#0D9FFB')
           .width(250)
           .height(40)
           .id('resetContinuousTask')
           .onClick(() => {
             // Stop the continuous task.
   
             // Cancel the continuous task through a button.
             this.stopContinuousTask();
           })
   
           Button() {
             Text('Register a callback for canceling a continuous task').fontSize (25).fontWeight(FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({ top: 10 })
           .backgroundColor('#0D9FFB')
           .width(250)
           .height(40)
           .onClick(() => {
             // Use a button to register a callback for canceling a continuous task.
             this.OnContinuousTaskCancel();
           })
   
           Button() {
             Text('Unregister a callback for canceling the continuous task').fontSize (25).fontWeight(FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({ top: 10 })
           .backgroundColor('#0D9FFB')
           .width(250)
           .height(40)
           .onClick(() => {
             // Use a button to unregister a callback for canceling a continuous task.
             this.OffContinuousTaskCancel();
           })
           // ...
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

5. Request and cancel a continuous task using **async**/**await**.

   The code snippet below shows how an application requests and cancels a continuous task using **async**/**await** for itself.
   
   Since API version 15, you can use [on('continuousTaskCancel')](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanageroncontinuoustaskcancel15) to listen for the cancellation of a continuous task.
   
   Since API version 16, you can use [BackgroundSubMode](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundsubmode16) to implement the Bluetooth car key function.

   <!-- @[continuous_task_await](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/BackGroundTasksKit/ContinuousTask/entry/src/main/ets/pages/audioPlayback/IndexAsyncAndAwait.ets) -->
   
   ``` TypeScript
   @Entry
   @Component
   struct IndexAsyncAndAwait {
     @State message: string = 'ContinuousTask';
     // Obtain the UIAbility context of the page by calling getUIContext().getHostContext().
     private context: Context | undefined = this.getUIContext().getHostContext();
   
     // ...
   
     // Request a continuous task using async/await.
     async startContinuousTask() {
       let wantAgentInfo: wantAgent.WantAgentInfo = {
         // List of operations to be executed after the notification is clicked.
         // Add the bundleName and abilityName of the application to start.
         wants: [
           {
             bundleName: 'ohos.samples.continuoustask',
             abilityName: 'MainAbility'
           }
         ],
         // Specify the action to perform (starting the ability) after the notification message is clicked.
         actionType: wantAgent.OperationType.START_ABILITY,
         // Custom request code.
         requestCode: 0,
         // Execution attribute of the operation to perform after the notification is clicked.
         actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
         // CAR_KEY subtype, which takes effect only when a continuous task of the bluetoothInteraction type is requested. This subtype is supported since API version 16.
         // Ensure that the key value in the extraInfo parameter is backgroundTaskManager.BackgroundModeType.SUB_MODE. Otherwise, the subtype does not take effect.
         // extraInfo: {
           // [backgroundTaskManager.BackgroundModeType.SUB_MODE] :backgroundTaskManager.BackgroundSubMode.CAR_KEY
         // }
       };
   
       try {
         // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
         // In atomic services, replace the following line of code with const wantAgentObj: object = await wantAgent.getWantAgent(wantAgentInfo);.
         const wantAgentObj: WantAgent = await wantAgent.getWantAgent(wantAgentInfo);
         try {
           let list: string[] = ['audioPlayback'];
           // let list: string[] = ['bluetoothInteraction']; The bluetoothInteraction type is included in the continuous task, and the CAR_KEY subtype is valid.
           // In atomic services, let list: Array<string> = ["audioPlayback"];
           const res: backgroundTaskManager.ContinuousTaskNotification =
             await backgroundTaskManager.startBackgroundRunning(this.context as Context, list, wantAgentObj);
           console.info(`Operation startBackgroundRunning succeeded, notificationId: ${res.notificationId}`);
           // Execute the continuous task logic, for example, audio playback.
           // ...
         } catch (error) {
           console.error(`Failed to Operation startBackgroundRunning. Code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
         }
       } catch (error) {
         console.error(`Failed to Operation getWantAgent. Code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
       }
     }
   
     // Cancel a continuous task using async/await.
     async stopContinuousTask() {
       try {
         await backgroundTaskManager.stopBackgroundRunning(this.context);
         console.info(`Succeeded in operationing stopBackgroundRunning.`);
         // ...
       } catch (error) {
         console.error(`Failed to operation stopBackgroundRunning. Code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`)
       }
     }
   
     build() {
       Row() {
         Column() {
           Text('Index')
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
   
           Button() {
             Text('Request continuous task').fontSize(25).fontWeight(FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({ top: 10 })
           .backgroundColor('#0D9FFB')
           .width(250)
           .height(40)
           .id('applyContinuousTask')
           .onClick(() => {
             // Request a continuous task by clicking a button.
             this.startContinuousTask();
           })
   
           Button() {
             Text ('Cancel continuous task').fontSize (25).fontWeight (FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({ top: 10 })
           .backgroundColor('#0D9FFB')
           .width(250)
           .height(40)
           .id('resetContinuousTask')
           .onClick(() => {
             // Stop the continuous task.
   
             // Cancel the continuous task through a button.
             this.stopContinuousTask();
           })
           // ...
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```
   <!--Del-->

   The code snippet below shows how an application requests a continuous task across devices or applications. When executing a continuous task in the background across devices or applications, you can create and run a **UIAbility** in the background via the **Call** method. For details, see [Using Cross-Device Call](../application-models/hop-multi-device-collaboration.md#using-cross-device-call).
   
   <!-- @[continuous_task_call](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/BackGroundTasksKit/ContinuousTask/entry/src/main/ets/MainAbility/BgTaskAbility.ets) -->
   
   ``` TypeScript
   const MSG_SEND_METHOD: string = 'CallSendMsg';
   
   let mContext: Context;
   
   function startContinuousTask() {
     let wantAgentInfo : wantAgent.WantAgentInfo = {
       // List of operations to be executed after the notification is clicked.
       wants: [
         {
           bundleName: 'ohos.samples.continuoustask',
           abilityName: 'MainAbility'
         }
       ],
       // Type of the operation to perform after the notification is clicked.
       actionType: wantAgent.OperationType.START_ABILITY,
       // Custom request code.
       requestCode: 0,
       // Execution attribute of the operation to perform after the notification is clicked.
       actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
     };
   
     // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
     // In atomic services, replace the following line of code with wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {.
     wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
       backgroundTaskManager.startBackgroundRunning(mContext,
         backgroundTaskManager.BackgroundMode.AUDIO_PLAYBACK, wantAgentObj).then(() => {
         console.info(`Succeeded in operationing startBackgroundRunning.`);
       }).catch((err: BusinessError) => {
         console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
       });
     });
   }
   
   function stopContinuousTask() {
     backgroundTaskManager.stopBackgroundRunning(mContext).then(() => {
       console.info(`Succeeded in operationing stopBackgroundRunning.`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
     });
   }
   
   class MyParcelable implements rpc.Parcelable {
     public num: number = 0;
     public str: string = '';
   
     constructor(num: number, str: string) {
       this.num = num;
       this.str = str;
     }
   
     marshalling(messageSequence: rpc.MessageSequence) {
       messageSequence.writeInt(this.num);
       messageSequence.writeString(this.str);
       return true;
     }
   
     unmarshalling(messageSequence: rpc.MessageSequence) {
       this.num = messageSequence.readInt();
       this.str = messageSequence.readString();
       return true;
     }
   }
   
   function sendMsgCallback(data: rpc.MessageSequence) {
     console.info('BgTaskAbility funcCallBack is called ' + data);
     let receivedData: MyParcelable = new MyParcelable(0, '');
     data.readParcelable(receivedData);
     console.info(`receiveData[${receivedData.num}, ${receivedData.str}]`);
     // You can execute different methods based on the str value in the sequenceable data sent by the caller object.
     if (receivedData.str === 'start_bgtask') {
       // Request a continuous task.
       startContinuousTask();
     } else if (receivedData.str === 'stop_bgtask') {
       // Cancel the continuous task.
       stopContinuousTask();
     }
     return new MyParcelable(10, 'Callee test');
   }
   
   export default class BgTaskAbility extends UIAbility {
     // Create an ability.
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       console.info('[Demo] BgTaskAbility onCreate');
       try {
         this.callee.on(MSG_SEND_METHOD, sendMsgCallback);
       } catch (error) {
         console.error(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`);
       }
       mContext = this.context;
     }
   
     // Destroy an ability.
     onDestroy() {
       console.info('[Demo] BgTaskAbility onDestroy');
     }
   
     onWindowStageCreate(windowStage: window.WindowStage) {
       console.info('[Demo] BgTaskAbility onWindowStageCreate');
   
       windowStage.loadContent('pages/Index', (error, data) => {
         if (error.code) {
           console.error(`load content failed with error ${JSON.stringify(error)}`);
           return;
         }
         console.info(`load content succeed with data ${JSON.stringify(data)}`);
       });
     }
   
     onWindowStageDestroy() {
       console.info('[Demo] BgTaskAbility onWindowStageDestroy');
     }
   
     onForeground() {
       console.info('[Demo] BgTaskAbility onForeground');
     }
   
     onBackground() {
       console.info('[Demo] BgTaskAbility onBackground');
     }
   };
   ```

   <!--DelEnd-->

<!--Del-->
### FA Model

1. Start and connect to a ServiceAbility.

   - If no user interaction is required, use **startAbility()** to start the ServiceAbility. For details, see [ServiceAbility Component](../application-models/serviceability-overview.md). In the **onStart** callback of the ServiceAbility, call the APIs to request and cancel continuous tasks.

   - If user interaction is required (for example, in music playback scenarios), use **connectAbility()** to start and connect to the ServiceAbility. For details, see [ServiceAbility Component](../application-models/serviceability-overview.md). After obtaining the agent of the ServiceAbility, the application can communicate with the ServiceAbility and control the request and cancellation of continuous tasks.

2. Configure permissions and declare the continuous task type.

   Declare the **ohos.permission.KEEP_BACKGROUND_RUNNING** permission in the **config.json** file. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md). In addition, declare the continuous task type for the ServiceAbility.
   
   ``` json5
   "module": {
       "package": "com.example.myapplication",
       "abilities": [
           {
               "backgroundModes": [
               "audioRecording"
               ], // Background mode
               "type": "service"  // The ability type is service.
           }
       ],
       "reqPermissions": [
           {
               "name": "ohos.permission.KEEP_BACKGROUND_RUNNING"  // Continuous task permission
           }
       ]
   }
   ```

3. Import the modules.
   
   ```js
    import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
    import { rpc } from '@kit.IPCKit'
    import { BusinessError } from '@kit.BasicServicesKit';
    import { wantAgent, WantAgent } from '@kit.AbilityKit';
   ```

4. Request and cancel a continuous task. In the ServiceAbility, call [startBackgroundRunning](#available-apis) and [stopBackgroundRunning](#available-apis) to request and cancel a continuous task. Use JavaScript code to implement this scenario.
  
   ```js
    function startContinuousTask() {
      let wantAgentInfo: wantAgent.WantAgentInfo = {
        // List of operations to be executed after the notification is clicked.
        wants: [
          {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
          }
        ],
        // Type of the operation to perform after the notification is clicked.
        actionType: wantAgent.OperationType.START_ABILITY,
        // Custom request code.
        requestCode: 0,
        // Execution attribute of the operation to perform after the notification is clicked.
        actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
      };

      // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
        backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
          backgroundTaskManager.BackgroundMode.AUDIO_RECORDING, wantAgentObj).then(() => {
          console.info(`Succeeded in operationing startBackgroundRunning.`);
        }).catch((err: BusinessError) => {
          console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
        });
      });
    }

    function stopContinuousTask() {
      backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
        console.info(`Succeeded in operationing stopBackgroundRunning.`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
      });
    }

    async function processAsyncJobs() {
      // Execute the continuous task.

      // After the continuous task is complete, call the API to release resources.
      stopContinuousTask();
    }

    let mMyStub: MyStub;

    // Start the service by calling connectAbility().
    class MyStub extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption) {
        console.info('ServiceAbility onRemoteRequest called');
        // Custom request code.
        if (code === 1) {
          // Receive the request code for requesting a continuous task.
          startContinuousTask();
          // Execute the continuous task.
        } else if (code === 2) {
          // Receive the request code for canceling the continuous task.
          stopContinuousTask();
        } else {
          console.info('ServiceAbility unknown request code');
        }
        return true;
      }
    }

    // Start the service by calling startAbility().
    class ServiceAbility {
      onStart(want: Want) {
        console.info('ServiceAbility onStart');
        mMyStub = new MyStub("ServiceAbility-test");
        // Call the API to start the task.
        startContinuousTask();
        processAsyncJobs();
      }

      onStop() {
        console.info('ServiceAbility onStop');
      }

      onConnect(want: Want) {
        console.info('ServiceAbility onConnect');
        return mMyStub;
      }

      onReconnect(want: Want) {
        console.info('ServiceAbility onReconnect');
      }

      onDisconnect() {
        console.info('ServiceAbility onDisconnect');
      }

      onCommand(want: Want, startId: number) {
        console.info('ServiceAbility onCommand');
      }
    }

    export default new ServiceAbility();
    ```
<!--DelEnd-->

## Samples

The following sample is provided to help you better understand how to develop continuous tasks:

- [Continuous Task (ArkTS, API version 9)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/BackGroundTasksKit/ContinuousTask)

<!--no_check-->