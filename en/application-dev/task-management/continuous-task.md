# Continuous Task (ArkTS)

## Overview

### Introduction

If an application has a perceivable task that needs to run in an extended period of time in the background, it can request a continuous task to prevent itself from being suspended. Examples of continuous tasks include music playback and navigation in the background. Within a continuous task, the application can concurrently request multiple types of tasks and update the task types. When the application operates in the background, the system performs consistency check to ensure that the application is executing the corresponding continuous task. Upon successful request for a continuous task, the notification panel displays the message associated with the task. If the user deletes the message, the system automatically terminates the task.

### Use Cases

The table below lists the types of continuous tasks, which are used in various scenarios. You can select a task type suitable for your case based on the description.

**Table 1** Continuous task types
| Name| Description| Item| Example Scenario|
| -------- | -------- | -------- | -------- |
| DATA_TRANSFER | Data transfer| dataTransfer | Non-hosting uploading and downloading operations, like those occurring in the background of a web browser for data transfer.|
| AUDIO_PLAYBACK | Audio and video playback| audioPlayback | Audio and video playback in the background; audio and video casting.<br> **Note**: It can be used in atomic services.|
| AUDIO_RECORDING | Audio recording| audioRecording | Recording and screen capture in the background.|
| LOCATION | Positioning and navigation| location | Positioning and navigation.|
| BLUETOOTH_INTERACTION | Bluetooth-related services| bluetoothInteraction | An application transitions into the background during the process of file transfer using Bluetooth.|
| MULTI_DEVICE_CONNECTION | Multi-device connection| multiDeviceConnection | Distributed service connection and casting.<br> **Note**: It can be used in atomic services.|
| <!--DelRow-->WIFI_INTERACTION | WLAN-related services (for system applications only)| wifiInteraction  | An application transitions into the background during the process of file transfer using WLAN.|
| VOIP<sup>13+</sup> | Audio and video calls| voip  | Chat applications (with audio and video services) transition into the background during audio and video calls.|
| TASK_KEEPING | Computing task (for 2-in-1 devices only).| taskKeeping  | Antivirus software is running.|

Description of **DATA_TRANSFER**:

- During data transfer, if an application uses the [upload and download agent API](../reference/apis-basic-services-kit/js-apis-request.md) to hand over tasks to the system, the application will be suspended in the background even if it has requested the continuous task of the DATA_TRANSFER type.

- During data transfer, the application needs to update the progress. If the progress is not updated for more than 10 minutes, the continuous task of the DATA_TRANSFER type will be canceled. For details about how to update the progress, see the example in [startBackgroundRunning()](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning12).

Description of **AUDIO_PLAYBACK**:

- Casting audio and video involves transmitting content from one device to another for playback purposes. If the application transitions to the background while casting, the continuous task checks the audio and video playback and casting services. The task will persist as long as either the audio and video playback or casting service is running properly.

- If the application needs to play media (STREAM_USAGE_MUSIC, STREAM_USAGE_MOVIE, or STREAM_USAGE_AUDIOBOOK) or games (STREAM_USAGE_GAME) in the background, it must access the [AVSession](../media/avsession/avsession-overview.md) service and request a continuous task of the AUDIO_PLAYBACK type.

- If the application is required to run other background playback tasks that can be perceived by users for a long time, it must request a continuous task of the AUDIO_PLAYBACK type, without accessing the AVSession service.

- If the application does not comply with the preceding access specifications, it will be muted and suspended by the system when switched to the background. It can resume playback only when it returns to the foreground.

### Constraints

**Ability restrictions**: In the stage model, only the UIAbility can request continuous tasks. In the FA model, only the ServiceAbility can request continuous tasks. Continuous tasks can be requested by the current application on the current device or across devices or by other applications. However, the capability to make cross-device or cross-application requests is restricted to system applications.

**Quantity restrictions**: A UIAbility (ServiceAbility in the FA model) can request only one continuous task at a time. If a UIAbility has a running continuous task, it can request another one only after the running task is finished. If an application needs to request multiple continuous tasks at the same time, it must create multiple UIAbilities. After a UIAbility requests a continuous task, all the processes of the application are not suspended.

**Running restrictions**:

- If an application requests a continuous task but does not carry out the relevant service, the system imposes restrictions on the application. For example, if the system detects that an application has requested a continuous task of the AUDIO_PLAYBACK type but does not play audio, the application will be suspended when it returns to the background.

- If an application requests a continuous task but carries out a service that does not match the requested type, the system imposes restrictions on the application. The application will be suspended when it returns to the background. For example, if the system detects that an application requests a continuous task of the AUDIO_PLAYBACK type, but the application is playing audio (corresponding to the AUDIO_PLAYBACK type) and recording (corresponding to the AUDIO_RECORDING type), the system enforces management measures.

- When an application's operations are completed after a continuous task request, the system imposes restrictions on the application. The application will be suspended when it returns to the background.

- If the background load of the process that runs a continuous task is higher than the corresponding typical load for a long period of time, the system performs certain control. The application will be suspended or terminated when it is switched to the background.

> **NOTE**
>
> The application shall proactively cancel a continuous task when it is finished. Otherwise, the system will forcibly cancel the task. For example, when a user taps the UI to pause music playback, the application must cancel the continuous task in a timely manner. When the user taps the UI again to continue music playback, the application needs to request a continuous task.
>
> If an application that plays an audio in the background is [interrupted](../media/audio/audio-playback-concurrency.md), the system automatically detects and stops the continuous task. The application must request a continuous task again to restart the playback.
>
> When an application that plays audio in the background stops a continuous task, it must suspend or stop the audio stream. Otherwise, the application will be forcibly terminated by the system.

## Available APIs

**Table 2** Main APIs for continuous tasks

The table below uses promise as an example to describe the APIs used for developing continuous tasks. For details about more APIs and their usage, see [Background Task Management](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md).

| API| Description|
| -------- | -------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: [WantAgent](../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)): Promise&lt;void&gt; | Requests a continuous task.|
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | Cancels a continuous task.|

## How to Develop

The following walks you through how to request a continuous task for recording to implement the following functions:

- When a user touches **Request Continuous Task**, the application requests a continuous task for recording, and a message is displayed in the notification bar, indicating that a recording task is running.

- When a user touches **Cancel Continuous Task**, the application cancels the continuous task, and the notification message is removed.

### Stage Model

1. Declare the **ohos.permission.KEEP_BACKGROUND_RUNNING** permission. For details, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

2. Declare the continuous task type.
   Declare the type of the continuous task for the target UIAbility in the **module.json5** file. Set the corresponding [configuration item](continuous-task.md#use-cases) in the configuration file.
   
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
        // ...
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

   The code snippet below shows how an application requests a continuous task for itself.  
      
   ```ts
    function callback(info: backgroundTaskManager.ContinuousTaskCancelInfo) {
      // ID of a continuous task.
      console.info('OnContinuousTaskCancel callback id ' + info.id);
      // Reason for canceling the continuous task.
      console.info('OnContinuousTaskCancel callback reason ' + info.reason);
    }

    @Entry
    @Component
    struct Index {
      @State message: string = 'ContinuousTask';
     // Obtain the UIAbility context of the page by calling getUIContext().getHostContext().
      private context: Context | undefined = this.getUIContext().getHostContext();

      OnContinuousTaskCancel() {
        try {
           backgroundTaskManager.on("continuousTaskCancel", callback);
           console.info(`Succeeded in operationing OnContinuousTaskCancel.`);
        } catch (error) {
           console.error(`Operation OnContinuousTaskCancel failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      }

      OffContinuousTaskCancel() {
        try {
           // If the callback parameter is not passed, all callbacks associated with the specified event are canceled.
           backgroundTaskManager.off("continuousTaskCancel", callback);
           console.info(`Succeeded in operationing OffContinuousTaskCancel.`);
        } catch (error) {
           console.error(`Operation OffContinuousTaskCancel failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      }

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
          actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
          // CAR_KEY subtype, which takes effect only when a continuous task of the bluetoothInteraction type is requested.
          // Ensure that the key value in the extraInfo parameter is backgroundTaskManager.BackgroundModeType.SUB_MODE. Otherwise, the subtype does not take effect.
          // extraInfo: { [backgroundTaskManager.BackgroundModeType.SUB_MODE] : backgroundTaskManager.BackgroundSubMode.CAR_KEY }
        };

        try {
          // Obtain the WantAgent object by using the getWantAgent API of the wantAgent module.
          wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
            try {
              let list: Array<string> = ["audioRecording"];
              // let list: Array<string> = ["bluetoothInteraction"]; The bluetoothInteraction type is included in the continuous task, and the CAR_KEY subtype is valid.
              backgroundTaskManager.startBackgroundRunning(this.context, list, wantAgentObj).then((res: backgroundTaskManager.ContinuousTaskNotification) => {
                console.info("Operation startBackgroundRunning succeeded");
                // Execute the continuous task logic, for example, recording.
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
              Text('Unregister a callback for canceling a continuous task').fontSize (25).fontWeight(FontWeight.Bold)
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
          }
          .width('100%')
        }
        .height('100%')
      }
    }
   ```
   <!--Del-->

   The code snippet below shows how an application requests a continuous task across devices or applications. When a continuous task is executed across devices or applications in the background, the UIAbility can be created and run in the background in call mode. For details, see [Using Call to Implement UIAbility Interaction (for System Applications Only)](../application-models/uiability-intra-device-interaction.md#using-call-to-implement-uiability-interaction-for-system-applications-only) and [Using Cross-Device Call](../application-models/hop-multi-device-collaboration.md#using-cross-device-call).
   
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
               "audioRecording"
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

