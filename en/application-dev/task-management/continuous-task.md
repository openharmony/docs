# Continuous Task


## Overview


### Introduction

If an application has a perceivable task that needs to run in an extended period of time in the background, it can request a continuous task to prevent itself from being suspended. Examples of continuous tasks include music playback and navigation in the background.

After an application requests a continuous task, the system verifies whether the application is actually executing the continuous task. It also attaches a notification to the continuous task. If the user deletes the notification, the system automatically stops the task.


### Use Cases

The table below lists the types of continuous tasks, which are used in various scenarios. You can select a task type suitable for your case based on the description.

**Table 1** Continuous task types
| Name| Description| Example Scenario|
| -------- | -------- | -------- |
| DATA_TRANSFER | Data transfer| The browser downloads a large file in the background.|
| AUDIO_PLAYBACK | Audio playback| A music application plays music in the background.|
| AUDIO_RECORDING | Audio recording| A recorder records audio in the background.|
| LOCATION | Positioning and navigation| A navigation application provides navigation in the background.|
| BLUETOOTH_INTERACTION | Bluetooth-related task| Transfer a file through Bluetooth.|
| MULTI_DEVICE_CONNECTION | Multi-device connection| Carry out distributed service connection.|
| WIFI_INTERACTION | WLAN-related task (for system applications only)| Transfer a file over Wi-Fi.|
| VOIP | Voice and video calls (for system applications only)| Use a system chat application to make an audio call in the background.|
| TASK_KEEPING | Computing task (for specific devices only)| Run antivirus software.|


- When an application requests a continuous task of the DATA_TRANSFER type, the system increases the priority of the application process to reduce the probability of terminating the process. However, it still suspends the process. To use the upload and download feature, the application must call the [upload and download agent API](../reference/apis/js-apis-request.md) so that the system functions as the agent.
- To implement background playback, the application must request an [AV session](../media/avsession-overview.md) in addition to a continuous task of the AUDIO_PLAYBACK type.


### Constraints

- **Ability limit**: In the stage model, only the UIAbility can request continuous tasks. In the FA model, only the ServiceAbility can request continuous tasks.

- **Quantity limit**: A UIAbility (ServiceAbility in the FA model) can request only one continuous task at a time. If a UIAbility has a running continuous task, it can request another one only after the running task is finished. If an application needs to request multiple continuous tasks at the same time, it must create multiple UIAbilities. After a UIAbility requests a continuous task, all the processes of the application are not suspended.

- **Running verification**: The system performs continuous task verification. If an application requests a continuous task but does not execute the task of the requested type or finishes the task, the system performs certain control. For example, if the system detects that an application has requested a continuous task of the AUDIO_PLAYBACK type but does not play audio, the system terminates the application process.

> **NOTE**
> 
> The application shall proactively cancel a continuous task when it is finished. Otherwise, the system will forcibly cancel the task. For example, when a user taps the UI to pause music playback, the application must cancel the continuous task in a timely manner. When the user taps the UI again to continue music playback, the application needs to request a continuous task.

## Available APIs

The table below uses promise as an example to describe the APIs used for developing continuous tasks. For details about more APIs and their usage, see [Background Task Management](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md).

**Table 2** Main APIs for continuous tasks

| API| Description|
| -------- | -------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: [WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md)): Promise&lt;void&gt; | Requests a continuous task.|
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | Cancels a continuous task.|

## How to Develop

### Stage Model

1. Request the **ohos.permission.KEEP_BACKGROUND_RUNNING** permission. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file).

2. Declare the continuous task type.

   Declare the continuous task type for the target UIAbility in the **module.json5** file.

   
   ```ts
   "module": {
       "abilities": [
           {
               "backgroundModes": [
               "audioRecording"
               ], // Background mode
           }
       ],
       ...
   }
   ```

3. Import the modules.
   
   ```ts
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';
   import wantAgent from '@ohos.app.ability.wantAgent';
   ```

4. Request and cancel a continuous task.

   - In the stage model, an application can request a continuous task for itself or another application either on the local device or on a remote device.

   - When a continuous task is executed across devices or applications in the background, the UIAbility can be created and run in the background in call mode. For details, see [Using Call to Implement UIAbility Interaction (for System Applications Only)](../application-models/uiability-intra-device-interaction.md#using-call-to-implement-uiability-interaction-for-system-applications-only) and [Using Cross-Device Call](../application-models/hop-multi-device-collaboration.md#using-cross-device-call).

   The code snippet below shows how an application requests a continuous task for itself.

   ```ts
   @Entry
   @Component
   struct Index {
     @State message: string = 'ContinuousTask';
     // Use getContext to obtain the context of the UIAbility for the page.
     private context = getContext(this);
   
     startContinuousTask() {
       let wantAgentInfo = {
         // List of operations to be executed after the notification is clicked.
         wants: [
           {
             bundleName: "com.example.myapplication",
             abilityName: "com.example.myapplication.MainAbility"
           }
         ],
         // Type of the operation to perform after the notification is clicked.
         operationType: wantAgent.OperationType.START_ABILITY,
         // Custom request code.
         requestCode: 0,
         // Execution attribute of the operation to perform after the notification is clicked.
         wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
       };
   
       // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
       wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
         try {
           backgroundTaskManager.startBackgroundRunning(this.context,
           backgroundTaskManager.BackgroundMode.AUDIO_RECORDING, wantAgentObj).then(() => {
             console.info(`Succeeded in operationing startBackgroundRunning.`);
           }).catch((err) => {
             console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
           });
         } catch (error) {
           console.error(`Failed to start background running. Code is ${error.code} message is ${error.message}`);
         }
       });
     }
   
     stopContinuousTask() {
       try {
         backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
           console.info(`Succeeded in operationing stopBackgroundRunning.`);
         }).catch((err) => {
           console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
         });
       } catch (error) {
         console.error(`Failed to stop background running. Code is ${error.code} message is ${error.message}`);
       }
     }
   
     build() {
       Row() {
         Column() {
           Text("Index")
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
           .onClick(() => {
             // Request a continuous task by clicking a button.
             this.startContinuousTask();
   
             // Execute the continuous task logic, for example, music playback.
           })
   
           Button() {
             Text ('Cancel continuous task').fontSize (25).fontWeight (FontWeight.Bold)
           }
           .type(ButtonType.Capsule)
           .margin({ top: 10 })
           .backgroundColor('#0D9FFB')
           .width(250)
           .height(40)
           .onClick(() => {
             // Stop the continuous task.
   
             // Cancel the continuous task by clicking a button.
             this.stopContinuousTask();
           })
         }
         .width('100%')
       }
       .height('100%')
     }
   }
   ```

   The code snippet below shows how an application requests a continuous task across devices or applications.
   
   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   const MSG_SEND_METHOD: string = 'CallSendMsg'
   
   let mContext = null;
   
   function startContinuousTask() {
     let wantAgentInfo = {
       // List of operations to be executed after the notification is clicked.
       wants: [
         {
           bundleName: "com.example.myapplication",
           abilityName: "com.example.myapplication.MainAbility",
         }
       ],
       // Type of the operation to perform after the notification is clicked.
       operationType: wantAgent.OperationType.START_ABILITY,
       // Custom request code.
       requestCode: 0,
       // Execution attribute of the operation to perform after the notification is clicked.
       wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
     };
   
     // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
     wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
       try {
         backgroundTaskManager.startBackgroundRunning(mContext,
         backgroundTaskManager.BackgroundMode.AUDIO_RECORDING, wantAgentObj).then(() => {
           console.info(`Succeeded in operationing startBackgroundRunning.`);
         }).catch((err) => {
           console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
         });
       } catch (err) {
         console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
       }
     });
   }
   
   function stopContinuousTask() {
     try {
       backgroundTaskManager.stopBackgroundRunning(mContext).then(() => {
         console.info(`Succeeded in operationing stopBackgroundRunning.`);
       }).catch((err) => {
         console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
       });
     } catch (err) {
       console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
     }
   }
   
   class MyParcelable {
     num: number = 0;
     str: String = '';
   
     constructor(num, string) {
       this.num = num;
       this.str = string;
     }
   
     marshalling(messageSequence) {
       messageSequence.writeInt(this.num);
       messageSequence.writeString(this.str);
       return true;
     }
   
     unmarshalling(messageSequence) {
       this.num = messageSequence.readInt();
       this.str = messageSequence.readString();
       return true;
     }
   }
   
   function sendMsgCallback(data) {
     console.info('BgTaskAbility funcCallBack is called ' + data)
     let receivedData = new MyParcelable(0, '')
     data.readParcelable(receivedData)
     console.info(`receiveData[${receivedData.num}, ${receivedData.str}]`)
     // You can execute different methods based on the str value in the sequenceable data sent by the caller object.
     if (receivedData.str === 'start_bgtask') {
       startContinuousTask()
     } else if (receivedData.str === 'stop_bgtask') {
       stopContinuousTask();
     }
     return new MyParcelable(10, 'Callee test');
   }
   
   export default class BgTaskAbility extends UIAbility {
     onCreate(want, launchParam) {
       console.info("[Demo] BgTaskAbility onCreate")
       this.callee.on('test', sendMsgCallback);
   
       try {
         this.callee.on(MSG_SEND_METHOD, sendMsgCallback)
       } catch (error) {
         console.error(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`)
       }
       mContext = this.context;
     }
   
     onDestroy() {
       console.info('[Demo] BgTaskAbility onDestroy')
     }
   
     onWindowStageCreate(windowStage) {
       console.info('[Demo] BgTaskAbility onWindowStageCreate')
   
       windowStage.loadContent("pages/index").then((data) => {
         console.info(`load content succeed with data ${JSON.stringify(data)}`)
       }).catch((error) => {
         console.error(`load content failed with error ${JSON.stringify(error)}`)
       })
     }
   
     onWindowStageDestroy() {
       console.info('[Demo] BgTaskAbility onWindowStageDestroy')
     }
   
     onForeground() {
       console.info('[Demo] BgTaskAbility onForeground')
     }
   
     onBackground() {
       console.info('[Demo] BgTaskAbility onBackground')
     }
   };
   ```


### FA Model

1. Start and connect to a ServiceAbility.

   - If no user interaction is required, use **startAbility()** to start the ServiceAbility. For details, see [ServiceAbility Component](../application-models/serviceability-overview.md). In the **onStart** callback of the ServiceAbility, call the APIs to request and cancel continuous tasks.

   - If user interaction is required (for example, in music playback scenarios), use **connectAbility()** to start and connect to the ServiceAbility. For details, see [ServiceAbility Component](../application-models/serviceability-overview.md). After obtaining the agent of the ServiceAbility, the application can communicate with the ServiceAbility and control the request and cancellation of continuous tasks.

2. Configure permissions and declare the continuous task type.

   Configure the **ohos.permission.KEEP_BACKGROUND_RUNNING** permission in the **config.json** file. For details, see [Declaring Permissions in the Configuration File](../security/accesstoken-guidelines.md#declaring-permissions-in-the-configuration-file). In addition, declare the continuous task type for the ServiceAbility.

   
   ```js
   "module": {
       "package": "com.example.myapplication",
       "abilities": [
           {
               "backgroundModes": [
               "audioRecording",
               ], // Background mode
               "type": "service"  // The ability type is Service.
           }
       ],
       "reqPermissions": [
           {
               "name": "ohos.permission.KEEP_BACKGROUND_RUNNING" // Continuous task permission
           }
       ]
   }
   ```

3. Import the modules.
   
   ```js
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
   import featureAbility from '@ohos.ability.featureAbility';
   import wantAgent from '@ohos.app.ability.wantAgent';
   import rpc from "@ohos.rpc";
   ```

4. Request and cancel a continuous task. In the ServiceAbility, call **startBackgroundRunning()** and **startBackgroundRunning()** to request and cancel a continuous task.
   
   ```js
   function startContinuousTask() {
     let wantAgentInfo = {
       // List of operations to be executed after the notification is clicked.
       wants: [
         {
           bundleName: "com.example.myapplication",
           abilityName: "com.example.myapplication.MainAbility"
         }
       ],
       // Type of the operation to perform after the notification is clicked.
       operationType: wantAgent.OperationType.START_ABILITY,
       // Custom request code.
       requestCode: 0,
       // Execution attribute of the operation to perform after the notification is clicked.
       wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
     };
   
     // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
     wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
       try {
         backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
         backgroundTaskManager.BackgroundMode.AUDIO_RECORDING, wantAgentObj).then(() => {
           console.info(`Succeeded in operationing startBackgroundRunning.`);
         }).catch((err) => {
           console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
         });
       } catch (error) {
         console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
       }
     });
   }
   
   function stopContinuousTask() {
     try {
       backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
         console.info(`Succeeded in operationing stopBackgroundRunning.`);
       }).catch((err) => {
         console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
       });
     } catch (error) {
       console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
     }
   }
   
   async function processAsyncJobs() {
     // Execute the continuous task.
   
     // After the continuous task is complete, call the API to release resources.
     stopContinuousTask();
   }
   
   let mMyStub;
   
   class MyStub extends rpc.RemoteObject {
     constructor(des) {
       if (typeof des === 'string') {
         super(des);
       } else {
         return null;
       }
     }
   
     onRemoteRequest(code, data, reply, option) {
       console.log('ServiceAbility onRemoteRequest called');
       // Custom request code.
       if (code === 1) {
         // Receive the request code for requesting a continuous task.
         startContinuousTask();
         // Execute the continuous task.
       } else if (code === 2) {
         // Receive the request code for canceling the continuous task.
         stopContinuousTask();
       } else {
         console.log('ServiceAbility unknown request code');
       }
       return true;
     }
   }
   
   export default {
     onStart(want) {
       console.info('ServiceAbility onStart');
       mMyStub = new MyStub("ServiceAbility-test");
       // Call the API to start the task.
       startContinuousTask();
       processAsyncJobs();
     },
     onStop() {
       console.info('ServiceAbility onStop');
     },
     onConnect(want) {
       console.info('ServiceAbility onConnect');
       return mMyStub;
     },
     onReconnect(want) {
       console.info('ServiceAbility onReconnect');
     },
     onDisconnect() {
       console.info('ServiceAbility onDisconnect');
     },
     onCommand(want, restart, startId) {
       console.info('ServiceAbility onCommand');
     }
   };
   ```

