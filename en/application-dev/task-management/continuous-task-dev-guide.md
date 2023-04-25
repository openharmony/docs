# Continuous Task Development

## When to Use

If an application has a perceivable task that needs to run in an extended period of time in the background, it can request a continuous task so that it will not be suspended. Examples of continuous tasks include music playback, navigation, device connection, and VoIP.
There is no time limit for a continuous task running in the background. To prevent abuse, the system limits the number of continuous tasks that can be requested. It also attaches a notification to each of the tasks so that the tasks are perceivable. In addition, the system verifies whether the application is actually executing a continuous task.

## Available APIs

**Table 1** Main APIs for continuous tasks

| API                                     | Description                          |
| ---------------------------------------- | ---------------------------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise&lt;void&gt; | Requests a continuous task from the system so that the application keeps running in the background.|
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | Cancels the continuous task.                |


For details about **wantAgent**, see [WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md).

**Table 2** Background modes

| Name                    | Description            | Item                  |
| ----------------------- | -------------- | --------------------- |
| DATA_TRANSFER           | Data transfer.          | dataTransfer          |
| AUDIO_PLAYBACK          | Audio playback.          | audioPlayback         |
| AUDIO_RECORDING         | Audio recording.            | audioRecording        |
| LOCATION                | Positioning and navigation.          | location              |
| BLUETOOTH_INTERACTION   | Bluetooth-related task.          | bluetoothInteraction  |
| MULTI_DEVICE_CONNECTION | Multi-device connection.         | multiDeviceConnection |
| WIFI_INTERACTION        | WLAN-related task (reserved).  | wifiInteraction       |
| VOIP                    | Voice and video call (reserved).   | voip                  |
| TASK_KEEPING            | Computing task (for specific devices only).| taskKeeping           |


## How to Develop

### Development in the Stage Model

For details about the stage model, see [Stage Model Development Overview](../application-models/stage-model-development-overview.md).

1. Configure the continuous task permission **ohos.permission.KEEP_BACKGROUND_RUNNING** in the **module.json5** file, and declare the corresponding background mode type for the ability that needs to use the task.

   ```
   "module": {
       "abilities": [
           {
               "backgroundModes": [
               "dataTransfer",
               "location"
               ], // Background mode
           }
       ],
       "requestPermissions": [
           {
               "name": "ohos.permission.KEEP_BACKGROUND_RUNNING" // Continuous task permission
           }
       ]
   }
   ```

2. If an application needs to execute a continuous task for its own, include the execution logic in the Page ability. This is because an application cannot use **startAbilityByCall** to create and run its own ability in the background due to the restriction of ability startup controls.  For details, see [UIAbility Component Overview](../application-models/uiability-overview.md).

   ```ts
   import wantAgent from '@ohos.app.ability.wantAgent';
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'test'
     // Use getContext to obtain the context of the Page ability.
     private context: any = getContext(this)
   
     startContinuousTask() {
       let wantAgentInfo = {
         // List of operations to be executed after the notification is clicked.
         wants: [
           {
             bundleName: "com.example.myapplication",
             abilityName: "EntryAbility",
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
       try {
           wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
               try {
                   backgroundTaskManager.startBackgroundRunning(this.context,
                       backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
                       console.info("Operation startBackgroundRunning succeeded");
                   }).catch((err) => {
                       console.error("Operation startBackgroundRunning failed Cause: " + err);
                   });
               } catch (error) {
                   console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
               }
           });
       } catch (error) {
           console.error(`Operation getWantAgent failed. code is ${error.code} message is ${error.message}`);
       }
     }
   
     stopContinuousTask() {
       try {
           backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
           console.info("Operation stopBackgroundRunning succeeded");
           }).catch((err) => {
           console.error("Operation stopBackgroundRunning failed Cause: " + err);
           });
       } catch (error) {
           console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
       }
     }
   
     build() {
       Row() {
         Column() {
           Text("Index")
             .fontSize(50)
             .fontWeight(FontWeight.Bold)
   
           Button() { Text('Request continuous task').fontSize(25).fontWeight(FontWeight.Bold) }.type(ButtonType.Capsule)
           .margin({ top: 10 }).backgroundColor('#0D9FFB').width(250).height(40)
           .onClick(() => {
             // Request a continuous task by clicking a button.
             this.startContinuousTask();
   
             // Execute the continuous task logic, for example, music playback.
           })
   
           Button() {Text('Cancel continuous task') .fontSize(25).fontWeight(FontWeight.Bold) }.type(ButtonType.Capsule)
           .margin({ top: 10 }).backgroundColor('#0D9FFB').width(250).height(40)
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

3. If a continuous task needs to be executed in the background for another application or on another device, you can create and run an ability in the background in Call mode. For details, see [Using Ability Call (Intra-Device)](../application-models/uiability-intra-device-interaction.md#using-call-to-implement-uiability-interaction-for-system-applications-only) and [Using Ability Call (Inter-Device)](../application-models/hop-multi-device-collaboration.md#using-cross-device-call).

   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';
   import wantAgent from '@ohos.app.ability.wantAgent';
   
   const MSG_SEND_METHOD: string = 'CallSendMsg';
   
   let mContext = null;
   
   function startContinuousTask() {
       let wantAgentInfo = {
           // List of operations to be executed after the notification is clicked.
           wants: [
               {
                   bundleName: "com.example.myapplication",
                   abilityName: "EntryAbility",
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
       try {
           wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
               try {
                   backgroundTaskManager.startBackgroundRunning(mContext,
                       backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
                       console.info("Operation startBackgroundRunning succeeded");
                   }).catch((error) => {
                       console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
                   });
               } catch (error) {
                   console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
               }
           });
       } catch (error) {
           console.error(`Operation getWantAgent failed. code is ${error.code} message is ${error.message}`);
       }
   }
   
   function stopContinuousTask() {
       try {
           backgroundTaskManager.stopBackgroundRunning(mContext).then(() => {
               console.info("Operation stopBackgroundRunning succeeded");
           }).catch((error) => {
               console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
           });
       } catch (error) {
           console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
       }
   }
   
   class MyParcelable {
       num: number = 0;
       str: String = "";
   
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
       let receivedData = new MyParcelable(0, "")
       data.readParcelable(receivedData)
       console.info(`receiveData[${receivedData.num}, ${receivedData.str}]`)
       // You can execute different methods based on the str value in the sequenceable data sent by the caller.
       if (receivedData.str === 'start_bgtask') {
           startContinuousTask()
       } else if (receivedData.str === 'stop_bgtask') {
           stopContinuousTask();
       }
       return new MyParcelable(10, "Callee test");
   }
   
   export default class BgTaskAbility extends UIAbility {
       onCreate(want, launchParam) {
           console.info("[Demo] BgTaskAbility onCreate")
           this.callee.on("test", sendMsgCallback);
   
           try {
               this.callee.on(MSG_SEND_METHOD, sendMsgCallback)
           } catch (error) {
               console.error(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`)
           }
           mContext = this.context;
       }
   
       onDestroy() {
           console.info("[Demo] BgTaskAbility onDestroy")
       }
   
       onWindowStageCreate(windowStage) {
           console.info("[Demo] BgTaskAbility onWindowStageCreate")
   
           windowStage.loadContent("pages/index").then((data)=> {
               console.info(`load content succeed with data ${JSON.stringify(data)}`)
           }).catch((error)=>{
               console.error(`load content failed with error ${JSON.stringify(error)}`)
           })
       }
   
       onWindowStageDestroy() {
           console.info("[Demo] BgTaskAbility onWindowStageDestroy")
       }
   
       onForeground() {
           console.info("[Demo] BgTaskAbility onForeground")
       }
   
       onBackground() {
           console.info("[Demo] BgTaskAbility onBackground")
       }
   };
   ```

### Development in the FA Model

For details about how to use the ServiceAbility in the FA model, see [ServiceAbility Component Overview](../application-models/serviceability-overview.md).

If an application does not need to interact with a continuous task in the background, you can use **startAbility()** to start the ServiceAbility. In the **onStart** callback of the ServiceAbility, call **startBackgroundRunning()** to declare that the ServiceAbility needs to run in the background for a long time. After the task execution is complete, call **stopBackgroundRunning()** to release resources.

If an application needs to interact with a continuous task in the background (for example, an application related to music playback), you can use **connectAbility()** to start and connect to the ServiceAbility. After obtaining the proxy of the ServiceAbility, the application can communicate with the ServiceAbility and control the request and cancellation of continuous tasks.

1. Configure the continuous task permission **ohos.permission.KEEP_BACKGROUND_RUNNING** in the **config.json** file, and declare the corresponding background mode type for the ServiceAbility that needs to use the task.

   ```json
   "module": {
       "package": "com.example.myapplication",
       "abilities": [
           {
               "backgroundModes": [
               "dataTransfer",
               "location"
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

2. Call the APIs for requesting and canceling a continuous task in the ServiceAbility.

   ```js
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';
   import featureAbility from '@ohos.ability.featureAbility';
   import wantAgent from '@ohos.app.ability.wantAgent';
   import rpc from "@ohos.rpc";
   
   function startContinuousTask() {
       let wantAgentInfo = {
           // List of operations to be executed after the notification is clicked.
           wants: [
               {
                   bundleName: "com.example.myapplication",
                   abilityName: "EntryAbility"
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
       try {
           wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
               try {
                   backgroundTaskManager.startBackgroundRunning(featureAbility.getContext(),
                       backgroundTaskManager.BackgroundMode.DATA_TRANSFER, wantAgentObj).then(() => {
                       console.info("Operation startBackgroundRunning succeeded");
                   }).catch((err) => {
                       console.error("Operation startBackgroundRunning failed Cause: " + err);
                   });
               } catch (error) {
                   console.error(`Operation startBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
               }
           });
       } catch (error) {
           console.error(`Operation getWantAgent failed. code is ${error.code} message is ${error.message}`);
       }
   }
   
   function stopContinuousTask() {
       try {
           backgroundTaskManager.stopBackgroundRunning(featureAbility.getContext()).then(() => {
               console.info("Operation stopBackgroundRunning succeeded");
           }).catch((err) => {
               console.error("Operation stopBackgroundRunning failed Cause: " + err);
           });
       } catch (error) {
           console.error(`Operation stopBackgroundRunning failed. code is ${error.code} message is ${error.message}`);
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
           // The meaning of code is user-defined.
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
       onStart() {
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
       onCommand(want, startId) {
           console.info('ServiceAbility onCommand');
       }
   };
   ```