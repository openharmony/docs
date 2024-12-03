# Continuous Task (ArkTS)


## Overview


### Introduction

If an application has a perceivable task that needs to run in an extended period of time in the background, it can request a continuous task to prevent itself from being suspended. Examples of continuous tasks include music playback and navigation in the background.
After an application requests a continuous task, the system verifies whether the application is actually executing the continuous task. It also attaches a notification to the continuous task. If the user deletes the notification, the system automatically stops the task.


### Use Cases

The table below lists the types of continuous tasks, which are used in various scenarios. You can select a task type suitable for your case based on the description.

**Table 1** Continuous task types
| Name| Description| Item| Example Scenario|
| -------- | -------- | -------- | -------- |
| DATA_TRANSFER | Data transfer| dataTransfer | The browser downloads a large file in the background.|
| AUDIO_PLAYBACK | Audio and video playback| audioPlayback | Music applications play music in the background. Users cast a video application to a large screen.<br>It can be used in atomic services.|
| AUDIO_RECORDING | Audio recording| audioRecording | A recorder records audio in the background.|
| LOCATION | Positioning and navigation| location | A navigation application provides navigation in the background.|
| BLUETOOTH_INTERACTION | Bluetooth-related task| bluetoothInteraction | Transfer a file through Bluetooth.|
| MULTI_DEVICE_CONNECTION | Multi-device connection| multiDeviceConnection | Carry out distributed service connection.<br>It can be used in atomic services.|
| <!--DelRow-->WIFI_INTERACTION | WLAN-related task (for system applications only)| wifiInteraction  | Transfer a file over WLAN.|
| VOIP | Audio and video calls| voip  | Use a chat application to make an audio and video call in the background.|
| TASK_KEEPING | <!--RP1-->Computing task (for specific devices only)<!--RP1End--> | taskKeeping  | Run antivirus software.|

- If an application calls the [upload and download agent API](../reference/apis-basic-services-kit/js-apis-request.md) to delegate the upload and download task to the system, the application will be suspended regardless of whether it has requested such a continuous task. For a continuous task used for download, the application needs to update the download progress. If the progress is not updated for more than 10 minutes, the continuous task will be canceled. You are advised to use the [new API](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning12) to request a continuous task of the DATA_TRANSFER type and update the notification progress.
- Only audio and video applications that use [AVSession](../media/avsession/avsession-overview.md) can request a continuous task of the AUDIO_PLAYBACK type to implement background playback.

### Constraints

- **Ability restrictions**: In the stage model, only the UIAbility can request continuous tasks. In the FA model, only the ServiceAbility can request continuous tasks.

- **Quantity restrictions**: A UIAbility (ServiceAbility in the FA model) can request only one continuous task at a time. If a UIAbility has a running continuous task, it can request another one only after the running task is finished. If an application needs to request multiple continuous tasks at the same time, it must create multiple UIAbilities. After a UIAbility requests a continuous task, all the processes of the application are not suspended.

- **Running restrictions**: The system verifies continuous tasks on mobile phones.
   - Scenario 1: If an application requests a continuous task but does not execute or has finished the task of the requested type, the system performs certain control. For example, if the system detects that an application has requested a continuous task of the AUDIO_PLAYBACK type but does not play audio, the system cancels the continuous task.
   - Scenario 2: If an application does not request a continuous task of a given type but executes such a continuous task, the system performs certain control. For example, if the system detects that an application requests a continuous task of the AUDIO_PLAYBACK type, but the application is playing audio (corresponding to the AUDIO_PLAYBACK type) and recording (corresponding to the AUDIO_RECORDING type), the system performs control on the application.
   - Scenario 3: If the background load of the process that runs a continuous task is higher than the corresponding typical load for a long period of time, the system performs certain control.

> **NOTE**
>
> The application shall proactively cancel a continuous task when it is finished. Otherwise, the system will forcibly cancel the task. For example, when a user taps the UI to pause music playback, the application must cancel the continuous task in a timely manner. When the user taps the UI again to continue music playback, the application needs to request a continuous task.
>
> If an application that plays an audio in the background is [interrupted](../media/audio/audio-playback-concurrency.md), the system automatically detects and stops the continuous task. The application must request a continuous task again to restart the playback.
>
> When an application that plays audio stops a continuous task in the background, it must suspend or stop the audio stream. Otherwise, the application will be forcibly terminated by the system.

## Available APIs

The table below uses promise as an example to describe the APIs used for developing continuous tasks. For details about more APIs and their usage, see [Background Task Management](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md).

**Table 2** Main APIs for continuous tasks

| API| Description|
| -------- | -------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: [WantAgent](../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)): Promise&lt;void&gt; | Requests a continuous task.|
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | Cancels a continuous task.|

## How to Develop

The following walks you through how to request a continuous task for recording. In this example, the application provides two buttons: **Request Continuous Task** and **Cancel Continuous Task**.
- When a user touches **Request Continuous Task**, the application requests a continuous task for recording, and a message is displayed in the notification bar, indicating that a recording task is running.
- When a user touches **Cancel Continuous Task**, the application cancels the continuous task, and the notification message is removed.

### Stage Model

1. Declare the **ohos.permission.KEEP_BACKGROUND_RUNNING** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Declare the continuous task type.

   Declare the type of the continuous task for the target UIAbility in the **module.json5** file. (Set the corresponding [configuration item](#use-cases) in the configuration file.)
   
   ```json
    "module": {
        "abilities": [
            {
                "backgroundModes": [
                 // Configuration item of the continuous task type
                "audioRecording"
                ]
            }
        ],
        ...
    }
   ```

3. Import the modules.
   
   Import the modules related to continuous tasks: @ohos.resourceschedule.backgroundTaskManager and @ohos.app.ability.wantAgent. Import other modules based on the project requirements.

   ```ts
    import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
    import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
    import { rpc } from '@kit.IPCKit'
    import { BusinessError } from '@kit.BasicServicesKit';
    import { wantAgent, WantAgent } from '@kit.AbilityKit';
   ```

4. Request and cancel a continuous task.

   - In the stage model, an application can request a continuous task for itself or another application either on the local device or on a remote device.<!--RP2--><!--RP2End-->
   <!--Del-->
   - When a continuous task is executed across devices or applications in the background, the UIAbility can be created and run in the background in call mode. For details, see [Using Call to Implement UIAbility Interaction (for System Applications Only)](../application-models/uiability-intra-device-interaction.md#using-call-to-implement-uiability-interaction-for-system-applications-only) and [Using Cross-Device Call](../application-models/hop-multi-device-collaboration.md#using-cross-device-call).<!--DelEnd-->

   The code snippet below shows how an application requests a continuous task for itself.

   ```ts
    @Entry
    @Component
    struct Index {
      @State message: string = 'ContinuousTask';
     // Use getContext to obtain the context of the UIAbility for the page.
      private context: Context = getContext(this);
   
      startContinuousTask() {
        let wantAgentInfo: wantAgent.WantAgentInfo = {
          // List of operations to be executed after the notification is clicked.
          // Add the bundleName and abilityName of the application to start.
          wants: [
            {
              bundleName: "com.example.myapplication",
              abilityName: "MainAbility"
            }
          ],
          // Specify the action to perform (starting the ability) after the notification message is clicked.
          actionType: wantAgent.OperationType.START_ABILITY,
          // Custom request code.
          requestCode: 0,
          // Execution attribute of the operation to perform after the notification is clicked.
          actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
        };
   
        // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
        wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
          backgroundTaskManager.startBackgroundRunning(this.context,
            backgroundTaskManager.BackgroundMode.AUDIO_RECORDING, wantAgentObj).then(() => {
            // Execute the continuous task logic, for example, music playback.
            console.info(`Succeeded in operationing startBackgroundRunning.`);
          }).catch((err: BusinessError) => {
            console.error(`Failed to operation startBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
          });
        });
      }
   
      stopContinuousTask() {
         backgroundTaskManager.stopBackgroundRunning(this.context).then(() => {
           console.info(`Succeeded in operationing stopBackgroundRunning.`);
         }).catch((err: BusinessError) => {
           console.error(`Failed to operation stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
         });
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
            })
   
            Button() {
              Text('Cancel continuous task').fontSize (25).fontWeight (FontWeight.Bold)
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
   <!--Del-->

   The code snippet below shows how an application requests a continuous task across devices or applications.
   
   ```ts
    const MSG_SEND_METHOD: string = 'CallSendMsg'
 
    let mContext: Context;

    function startContinuousTask() {
      let wantAgentInfo : wantAgent.WantAgentInfo = {
        // List of operations to be executed after the notification is clicked.
        wants: [
          {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility",
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
      wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj : WantAgent) => {
        backgroundTaskManager.startBackgroundRunning(mContext,
          backgroundTaskManager.BackgroundMode.AUDIO_RECORDING, wantAgentObj).then(() => {
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
      num: number = 0;
      str: string = '';

      constructor(num: number, string: string) {
        this.num = num;
        this.str = string;
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
        console.info("[Demo] BgTaskAbility onCreate");
        try {
          this.callee.on(MSG_SEND_METHOD, sendMsgCallback)
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
   
   ```json
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
    import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
    import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
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
