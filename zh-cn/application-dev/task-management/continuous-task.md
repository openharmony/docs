# 长时任务(ArkTS)

<!--Kit: Background Tasks Kit-->
<!--Subsystem: ResourceSchedule-->
<!--Owner: @cheng-shichang-->
<!--Designer: @zhouben25-->
<!--Tester: @fenglili18-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

### 功能介绍

应用退至后台后，在后台需要长时间运行用户可感知的任务，如播放音乐、导航等。为防止应用进程被挂起，导致对应功能异常，可以申请长时任务，使应用在后台长时间运行。在长时任务中，支持同时申请多种类型的任务，也可以对任务类型进行更新。应用退至后台执行业务时，系统会做一致性校验，确保应用在执行相应的长时任务。应用在申请长时任务成功后，通知栏会显示与长时任务相关联的消息，用户删除通知栏消息时，系统会自动停止长时任务。

### 使用场景

下表给出了当前长时任务支持的类型，包含数据传输、音视频播放、录制、定位导航、蓝牙相关业务、多设备互联、<!--Del-->WLAN相关业务、<!--DelEnd-->音视频通话和计算任务。可以参考下表中的场景举例，选择合适的长时任务类型。

**表1** 长时任务类型
| 参数名 | 描述 | 配置项 | 场景举例 |
| -------- | -------- | -------- | -------- |
| DATA_TRANSFER | 数据传输 | dataTransfer | 非托管形式的上传、下载，如在浏览器后台上传或下载数据。 |
| AUDIO_PLAYBACK | 音视频播放 | audioPlayback | 音频、视频在后台播放，音视频投播。 <br> **说明：** 支持在原子化服务中使用。|
| AUDIO_RECORDING | 录制 | audioRecording | 录音、录屏退后台。 |
| LOCATION | 定位导航 | location | 定位、导航。 |
| BLUETOOTH_INTERACTION | 蓝牙相关业务 | bluetoothInteraction | 通过蓝牙传输文件时退后台。 |
| MULTI_DEVICE_CONNECTION | 多设备互联 | multiDeviceConnection | 分布式业务连接、投播。<br> **说明：** 支持在原子化服务中使用。 |
| <!--DelRow-->WIFI_INTERACTION | WLAN相关业务（仅对系统应用开放） | wifiInteraction  | 通过WLAN传输文件时退后台。 |
| VOIP<sup>13+</sup> | 音视频通话 | voip  | 某些聊天类应用（具有音视频业务）音频、视频通话时退后台。|
| TASK_KEEPING | 计算任务（仅对2in1设备开放） | taskKeeping  | 如杀毒软件。 |

关于DATA_TRANSFER（数据传输）说明：

- 在数据传输时，若应用使用[上传下载代理接口](../reference/apis-basic-services-kit/js-apis-request.md)托管给系统，即使申请DATA_TRANSFER的后台任务，应用退后台时还是会被挂起。

- 在数据传输时，应用需要更新进度，如果进度长时间（超过10分钟）未更新，数据传输的长时任务会被取消。更新进度的通知类型必须为实况窗，具体实现可参考[startBackgroundRunning()](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning12)中的示例。

关于AUDIO_PLAYBACK（音视频播放）说明：

- 音视频投播，是指将一台设备的音视频投至另一台设备播放。投播退至后台，长时任务会检测音视频播放和投屏两个业务，只要有其一正常运行，长时任务就不会终止。

- 当应用需要在后台播放媒体类型（流类型为STREAM_USAGE_MUSIC、STREAM_USAGE_MOVIE和STREAM_USAGE_AUDIOBOOK）和游戏类型（流类型为STREAM_USAGE_GAME）时，必须接入媒体会话服务（[AVSession](../media/avsession/avsession-overview.md)）并申请AUDIO_PLAYBACK类型长时任务。

- 除了上述播放类型，针对用户可感知的其他播放任务，如果应用需要在后台长时间运行该任务，必须申请AUDIO_PLAYBACK类型长时任务，无需接入AVSession。

- 如果应用不满足上述接入规范，退至后台播放时会被系统静音并冻结，无法在后台正常播放，直到应用重新切回前台时，才会解除静音并恢复播放。

- 从API version 20开始，申请AUDIO_PLAYBACK类型长时任务但不接入AVSession，申请长时任务成功后会在通知栏显示通知；接入AVSession后，后台任务模块不会发送通知栏通知，由AVSession发送通知。对于API version 19及之前的版本，后台任务模块不会在通知栏显示通知。

### 约束与限制

**申请限制**：Stage模型中，长时任务仅支持UIAbility申请；FA模型中，长时任务仅支持ServiceAbility申请。长时任务支持设备当前应用申请，也支持跨设备或跨应用申请，跨设备或跨应用仅对系统应用开放。

**数量限制**：
- 从API version 21开始，支持一个UIAbility同一时刻申请多个长时任务，最多可申请10个，具体实现可参考[startBackgroundRunning()](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanagerstartbackgroundrunning21)。对于API version 20及之前版本，一个UIAbility（FA模型则为ServiceAbility）同一时刻仅支持申请一个长时任务，即在一个长时任务结束后才能继续申请。如果一个应用同时需要申请多个长时任务，需要创建多个UIAbility。
- 如果一个应用创建了多个UIAbility，一个UIAbility申请长时任务后，整个应用下的所有进程均不会被挂起。

**运行限制**：

- 申请长时任务后，应用未执行相应的业务，系统会对应用进行管控，即应用退至后台会被挂起。如系统检测到应用申请了AUDIO_PLAYBACK（音视频播放），但实际未播放音乐。

- 申请长时任务后，应用执行的业务类型与申请的不一致，系统会对应用进行管控，即应用退至后台会被挂起。如系统检测到应用只申请了AUDIO_PLAYBACK（音视频播放），但实际上除了播放音乐（对应AUDIO_PLAYBACK类型），还在进行录制（对应AUDIO_RECORDING类型）。

- 申请长时任务后，应用的业务已执行完，系统会对应用进行管控，即应用退至后台会被挂起。

- 若运行长时任务的进程后台负载持续高于所申请类型的典型负载，系统会对应用进行管控，即应用退至后台会被挂起或终止。

> **说明：**
>
> 应用按需求申请长时任务，当应用无需在后台运行（任务结束）时，要及时主动取消长时任务，否则应用退至后台会被系统挂起。例如用户主动点击音乐暂停播放时，应用需及时取消对应的长时任务；用户再次点击音乐播放时，需重新申请长时任务。
>
> 若音频在后台播放时被[打断](../media/audio/audio-playback-concurrency.md)，系统会自行检测和停止长时任务，音频重启播放时，需要再次申请长时任务。
>
> 后台播放音频的应用，在停止长时任务的同时，需要暂停或停止音频流，否则应用会被系统强制终止。

## 接口说明

**表2** 主要接口

以下是长时任务开发使用的相关接口，下表均以Promise形式为例，更多接口及使用方式请见[后台任务管理](../reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md)。

| 接口名 | 描述 |
| -------- | -------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: [WantAgent](../reference/apis-ability-kit/js-apis-app-ability-wantAgent.md)): Promise&lt;void&gt; | 申请长时任务 |
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | 取消长时任务 |

## 开发步骤

本文以申请录制长时任务为例，实现如下功能：

- 点击“申请长时任务”按钮，应用申请录制长时任务成功，通知栏显示“正在运行录制任务”通知。

- 点击“取消长时任务”按钮，取消长时任务，通知栏撤销相关通知。

### Stage模型

1. 需要申请ohos.permission.KEEP_BACKGROUND_RUNNING权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。

2. 声明后台模式类型。
   在module.json5文件中为需要使用长时任务的UIAbility声明相应的长时任务类型，配置文件中填写长时任务类型的[配置项](continuous-task.md#使用场景)。
   
   ```json
    "module": {
        "abilities": [
            {
                "backgroundModes": [
                 // 长时任务类型的配置项
                "audioRecording",
                "bluetoothInteraction",
                "audioPlayback"
                ]
            }
        ],
        // ...
    }
   ```

3. 导入模块。
   
   长时任务相关的模块为@ohos.resourceschedule.backgroundTaskManager和@ohos.app.ability.wantAgent，其余模块按实际需要导入。
    <!--RP1-->
    
    ```ts
    import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
    import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
    import { rpc } from '@kit.IPCKit'
    import { BusinessError } from '@kit.BasicServicesKit';
    import { wantAgent, WantAgent } from '@kit.AbilityKit';
    // 在原子化服务中，请删除WantAgent导入
    ```
    <!--RP1End-->

4. 申请和取消长时任务。

   **设备当前应用**申请和取消长时任务示例代码如下：   
      
   ```ts
    function callback(info: backgroundTaskManager.ContinuousTaskCancelInfo) {
      // 长时任务id
      console.info('OnContinuousTaskCancel callback id ' + info.id);
      // 长时任务取消原因
      console.info('OnContinuousTaskCancel callback reason ' + info.reason);
    }

    @Entry
    @Component
    struct Index {
      @State message: string = 'ContinuousTask';
     // 通过getUIContext().getHostContext()方法，来获取page所在的UIAbility上下文
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
           // callback参数不传，则取消所有已注册的回调
           backgroundTaskManager.off("continuousTaskCancel", callback);
           console.info(`Succeeded in operationing OffContinuousTaskCancel.`);
        } catch (error) {
           console.error(`Operation OffContinuousTaskCancel failed. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
        }
      }

      // 申请长时任务.then()写法
      startContinuousTask() {
        let wantAgentInfo: wantAgent.WantAgentInfo = {
          // 点击通知后，将要执行的动作列表
          // 添加需要被拉起应用的bundleName和abilityName
          wants: [
            {
              bundleName: "com.example.myapplication",
              abilityName: "MainAbility"
            }
          ],
          // 指定点击通知栏消息后的动作是拉起ability
          actionType: wantAgent.OperationType.START_ABILITY,
          // 使用者自定义的一个私有值
          requestCode: 0,
          // 点击通知后，动作执行属性
          actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
          // 车钥匙长时任务子类型，从API version 16开始支持。只有申请bluetoothInteraction类型的长时任务，车钥匙子类型才能生效。
          // 确保extraInfo参数中的Key值为backgroundTaskManager.BackgroundModeType.SUB_MODE，否则子类型不生效。
          // extraInfo: { [backgroundTaskManager.BackgroundModeType.SUB_MODE] : backgroundTaskManager.BackgroundSubMode.CAR_KEY }
        };

        try {
          // 通过wantAgent模块下getWantAgent方法获取WantAgent对象
          // 在原子化服务中，使用wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {替换下面一行代码
          wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
            try {
              let list: Array<string> = ["audioRecording"];
              // let list: Array<string> = ["bluetoothInteraction"]; 长时任务类型包含bluetoothInteraction，CAR_KEY子类型合法
              // 在原子化服务中，let list: Array<string> = ["audioPlayback"];
              backgroundTaskManager.startBackgroundRunning(this.context, list, wantAgentObj).then((res: backgroundTaskManager.ContinuousTaskNotification) => {
                console.info("Operation startBackgroundRunning succeeded");
                // 此处执行具体的长时任务逻辑，如录音，录制等。
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

      // 取消长时任务.then()写法
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
              Text('申请长时任务').fontSize(25).fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .margin({ top: 10 })
            .backgroundColor('#0D9FFB')
            .width(250)
            .height(40)
            .onClick(() => {
              // 通过按钮申请长时任务
              this.startContinuousTask();
            })
   
            Button() {
              Text('取消长时任务').fontSize(25).fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .margin({ top: 10 })
            .backgroundColor('#0D9FFB')
            .width(250)
            .height(40)
            .onClick(() => {
              // 此处结束具体的长时任务的执行
   
              // 通过按钮取消长时任务
              this.stopContinuousTask();
            })

            Button() {
              Text('注册长时任务取消回调').fontSize(25).fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .margin({ top: 10 })
            .backgroundColor('#0D9FFB')
            .width(250)
            .height(40)
            .onClick(() => {
              // 通过按钮注册长时任务取消回调
              this.OnContinuousTaskCancel();
            })

            Button() {
              Text('取消注册长时任务取消回调').fontSize(25).fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .margin({ top: 10 })
            .backgroundColor('#0D9FFB')
            .width(250)
            .height(40)
            .onClick(() => {
              // 通过按钮取消注册长时任务取消回调
              this.OffContinuousTaskCancel();
            })
          }
          .width('100%')
        }
        .height('100%')
      }
    }
   ```

5. 申请和取消长时任务async/await写法。

   **设备当前应用**申请和取消长时任务async/await写法示例代码如下：   
      
   ```ts
    @Entry
    @Component
    struct Index {
      @State message: string = 'ContinuousTask';
     // 通过getUIContext().getHostContext()方法，来获取page所在的UIAbility上下文
      private context: Context | undefined = this.getUIContext().getHostContext();

      // 申请长时任务async/await写法
      async startContinuousTask() {
        let wantAgentInfo: wantAgent.WantAgentInfo = {
          // 点击通知后，将要执行的动作列表
          // 添加需要被拉起应用的bundleName和abilityName
          wants: [
            {
              bundleName: "com.example.myapplication",
              abilityName: "MainAbility"
            }
          ],
          // 指定点击通知栏消息后的动作是拉起ability
          actionType: wantAgent.OperationType.START_ABILITY,
          // 使用者自定义的一个私有值
          requestCode: 0,
          // 点击通知后，动作执行属性
          actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
          // 车钥匙长时任务子类型，从API version 16开始支持。只有申请bluetoothInteraction类型的长时任务，车钥匙子类型才能生效。
          // 确保extraInfo参数中的Key值为backgroundTaskManager.BackgroundModeType.SUB_MODE，否则子类型不生效。
          // extraInfo: { [backgroundTaskManager.BackgroundModeType.SUB_MODE] : backgroundTaskManager.BackgroundSubMode.CAR_KEY }
        };

        try {
          // 通过wantAgent模块下getWantAgent方法获取WantAgent对象
          // 在原子化服务中，使用const wantAgentObj: object = await wantAgent.getWantAgent(wantAgentInfo);替换下面一行代码
          const wantAgentObj: WantAgent = await wantAgent.getWantAgent(wantAgentInfo);
          try {
            let list: Array<string> = ["audioRecording"];
            // let list: Array<string> = ["bluetoothInteraction"]; 长时任务类型包含bluetoothInteraction，CAR_KEY子类型合法
            // 在原子化服务中，let list: Array<string> = ["audioPlayback"];
            const res: backgroundTaskManager.ContinuousTaskNotification = await backgroundTaskManager.startBackgroundRunning(this.context as Context, list, wantAgentObj);
            console.info(`Operation startBackgroundRunning succeeded, notificationId: ${res.notificationId}`);
            // 此处执行具体的长时任务逻辑，如录音，录制等。
          } catch (error) {
            console.error(`Failed to Operation startBackgroundRunning. Code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
          }
        } catch (error) {
          console.error(`Failed to Operation getWantAgent. Code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`);
        }
      }

      // 取消长时任务async/await写法
      async stopContinuousTask() {
        try {
          await backgroundTaskManager.stopBackgroundRunning(this.context);
          console.info(`Succeeded in operationing stopBackgroundRunning.`);
        } catch (error) {
          console.error(`Failed to operation stopBackgroundRunning. Code is ${(error as BusinessError).code}, message is ${(error as BusinessError).message}`)
        }
      }

      build() {
        Row() {
          Column() {
            Text("Index")
              .fontSize(50)
              .fontWeight(FontWeight.Bold)
   
           Button() {
              Text('申请长时任务').fontSize(25).fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .margin({ top: 10 })
            .backgroundColor('#0D9FFB')
            .width(250)
            .height(40)
            .onClick(() => {
              // 通过按钮申请长时任务
              this.startContinuousTask();
            })
   
            Button() {
              Text('取消长时任务').fontSize(25).fontWeight(FontWeight.Bold)
            }
            .type(ButtonType.Capsule)
            .margin({ top: 10 })
            .backgroundColor('#0D9FFB')
            .width(250)
            .height(40)
            .onClick(() => {
              // 此处结束具体的长时任务的执行

              // 通过按钮取消长时任务
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

   **跨设备或跨应用**申请长时任务示例代码如下。跨设备或跨应用在后台执行长时任务时，可以通过Call的方式在后台创建并运行UIAbility，具体使用请参考[Call调用开发指南（同设备）](../application-models/uiability-intra-device-interaction.md#通过call调用实现uiability交互仅对系统应用开放)和[Call调用开发指南（跨设备）](../application-models/hop-multi-device-collaboration.md#通过跨设备call调用实现多端协同)。
   
   ```ts
    const MSG_SEND_METHOD: string = 'CallSendMsg'
 
    let mContext: Context;

    function startContinuousTask() {
      let wantAgentInfo : wantAgent.WantAgentInfo = {
        // 点击通知后，将要执行的动作列表
        wants: [
          {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility",
          }
        ],
        // 点击通知后，动作类型
        actionType: wantAgent.OperationType.START_ABILITY,
        // 使用者自定义的一个私有值
        requestCode: 0,
        // 点击通知后，动作执行属性
        actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
      };

      // 通过wantAgent模块的getWantAgent方法获取WantAgent对象
      // 在原子化服务中，使用wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: object) => {替换下面一行代码
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
      num: number = 0;
      str: string = '';

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
      // 可以根据Caller端发送的序列化数据的str值，执行不同的方法。
      if (receivedData.str === 'start_bgtask') {
        // 申请长时
        startContinuousTask();
      } else if (receivedData.str === 'stop_bgtask') {
        // 取消长时
        stopContinuousTask();
      }
      return new MyParcelable(10, 'Callee test');
    }

    export default class BgTaskAbility extends UIAbility {
      // Ability创建
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.info("[Demo] BgTaskAbility onCreate");
        try {
          this.callee.on(MSG_SEND_METHOD, sendMsgCallback)
        } catch (error) {
          console.error(`${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`);
        }
        mContext = this.context;
      }
     
      // Ability销毁
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
### FA模型

1. 启动并连接ServiceAbility。

   - 不需要与用户进行交互时，采用startAbility()方法启动ServiceAbility（具体使用请参考[ServiceAbility组件](../application-models/serviceability-overview.md)，并在ServiceAbility的onStart回调方法中，调用长时任务的申请和取消接口。

   - 需要与用户进行交互时（如播放音乐），采用connectAbility()方法启动并连接ServiceAbility（具体使用请参考[ServiceAbility组件](../application-models/serviceability-overview.md)，在获取到服务的代理对象后，与服务进行通信，控制长时任务的申请和取消。

2. 配置权限和声明后台模式类型。

   在config.json文件中配置长时任务权限ohos.permission.KEEP_BACKGROUND_RUNNING，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。同时，为需要使用长时任务的ServiceAbility声明相应的长时任务类型。
   
   ```json
   "module": {
       "package": "com.example.myapplication",
       "abilities": [
           {
               "backgroundModes": [
               "audioRecording"
               ], // 后台模式类型
               "type": "service"  // ability类型为service
           }
       ],
       "reqPermissions": [
           {
               "name": "ohos.permission.KEEP_BACKGROUND_RUNNING"  // 长时任务权限
           }
       ]
   }
   ```

3. 导入模块。
   
   ```js
    import { backgroundTaskManager } from '@kit.BackgroundTasksKit';
    import { rpc } from '@kit.IPCKit'
    import { BusinessError } from '@kit.BasicServicesKit';
    import { wantAgent, WantAgent } from '@kit.AbilityKit';
   ```

4. 申请和取消长时任务。在 ServiceAbility 中，调用 [startBackgroundRunning](#接口说明) 接口和 [stopBackgroundRunning](#接口说明) 接口实现长时任务的申请和取消，通过js代码实现。
  
   ```js
    function startContinuousTask() {
      let wantAgentInfo: wantAgent.WantAgentInfo = {
        // 点击通知后，将要执行的动作列表
        wants: [
          {
            bundleName: "com.example.myapplication",
            abilityName: "com.example.myapplication.MainAbility"
          }
        ],
        // 点击通知后，动作类型
        actionType: wantAgent.OperationType.START_ABILITY,
        // 使用者自定义的一个私有值
        requestCode: 0,
        // 点击通知后，动作执行属性
        actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
      };

      // 通过wantAgent模块的getWantAgent方法获取WantAgent对象
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
      // 此处执行具体的长时任务。

      // 长时任务执行完，调用取消接口，释放资源。
      stopContinuousTask();
    }

    let mMyStub: MyStub;

    // 采用connectAbility的方式启动服务
    class MyStub extends rpc.RemoteObject {
      constructor(des: string) {
        super(des);
      }

      onRemoteRequest(code: number, data: rpc.MessageParcel, reply: rpc.MessageParcel, option: rpc.MessageOption) {
        console.info('ServiceAbility onRemoteRequest called');
        // code 的具体含义用户自定义
        if (code === 1) {
          // 接收到申请长时任务的请求码
          startContinuousTask();
          // 此处执行具体长时任务
        } else if (code === 2) {
          // 接收到取消长时任务的请求码
          stopContinuousTask();
        } else {
          console.info('ServiceAbility unknown request code');
        }
        return true;
      }
    }

    // 采用startAbility的方式启动服务
    class ServiceAbility {
      onStart(want: Want) {
        console.info('ServiceAbility onStart');
        mMyStub = new MyStub("ServiceAbility-test");
        // 在执行长时任务前，调用申请接口。
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

## 相关实例

针对长时任务开发，有以下相关实例可供参考：

- [长时任务（ArkTS）（API9）](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/TaskManagement/ContinuousTask)