# 长时任务


## 概述


### 功能介绍

应用退至后台后，在后台需要长时间运行用户可感知的任务，如播放音乐、导航等。为防止应用进程被挂起，导致对应功能异常，可以申请长时任务，使应用在后台长时间运行。
申请长时任务后，系统会做相应的校验，确保应用在执行相应的长时任务。同时，系统有与长时任务相关联的通知栏消息，用户删除通知栏消息时，系统会自动停止长时任务。


### 使用场景

下表给出了当前长时任务支持的类型，包含数据传输、音频播放、录音、定位导航、蓝牙相关、多设备互联、WLAN相关、音视频通话和计算任务。可以参考下表中的场景举例，选择合适的长时任务类型。

**表1** 长时任务类型
| 参数名 | 描述 | 场景举例 |
| -------- | -------- | -------- |
| DATA_TRANSFER | 数据传输 | 后台下载大文件，如浏览器后台下载等。 |
| AUDIO_PLAYBACK | 音频播放 | 音乐类应用在后台播放音乐。 |
| AUDIO_RECORDING | 录音 | 录音机在后台录音。 |
| LOCATION | 定位导航 | 导航类应用后台导航。 |
| BLUETOOTH_INTERACTION | 蓝牙相关 | 通过蓝牙传输分享的文件。 |
| MULTI_DEVICE_CONNECTION | 多设备互联 | 分布式业务连接。 |
| WIFI_INTERACTION | WLAN相关（仅对系统应用开放） | 通过WLAN传输分享的文件。 |
| VOIP | 音视频通话（仅对系统应用开放） | 系统聊天类应用后台音频电话。 |
| TASK_KEEPING | 计算任务（仅对特定设备开放） | 杀毒软件 |


- 申请了DATA_TRANSFER（数据传输）的长时任务，系统仅会提升应用进程的优先级，降低系统终止应用进程的概率，但仍然会挂起对应的应用进程。对于上传下载对应的功能，需要调用系统[上传下载代理接口](../reference/apis/js-apis-request.md)托管给系统执行。
- 申请了AUDIO_PLAYBACK（音频播放）的长时任务，要实现后台播放的功能，需要同时申请[媒体会话](../media/avsession-overview.md)。


### 约束与限制

- **申请限制**：Stage模型中，长时任务仅支持UIAbility申请；FA模型中，长时任务仅支持ServiceAbility申请。

- **数量限制**：一个UIAbility（FA模型则为ServiceAbility）同一时刻仅支持申请一个长时任务，即在一个长时任务结束后才可能继续申请。如果一个应用同时需要申请多个长时任务，需要创建多个UIAbility；一个应用的一个UIAbility申请长时任务后，整个应用下的所有进程均不会被挂起。

- **运行限制**：系统会进行长时任务校验。若应用申请了长时任务，但未真正执行申请类型的长时任务或申请类型的任务已结束，系统会对应用进行管控。例如系统检测到应用申请了AUDIO_PLAYBACK（音频播放），但实际未播放音乐，系统则会终止对应的进程。

> **说明：**
> 
> 应用按需求申请长时任务，当应用无需在后台运行（任务结束）时，要及时主动取消长时任务，否则系统会强行取消。例如用户点击音乐暂停播放时，应用需及时取消对应的长时任务；用户再次点击音乐播放时，需重新申请长时任务。

## 接口说明

**表2** 主要接口

以下是长时任务开发使用的相关接口，下表均以Promise形式为例，更多接口及使用方式请见[后台任务管理](../reference/apis/js-apis-resourceschedule-backgroundTaskManager.md)。

| 接口名 | 描述 |
| -------- | -------- |
| startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: [WantAgent](../reference/apis/js-apis-app-ability-wantAgent.md)): Promise&lt;void&gt; | 申请长时任务 |
| stopBackgroundRunning(context: Context): Promise&lt;void&gt; | 取消长时任务 |

## 开发步骤

### Stage模型

1. 需要申请ohos.permission.KEEP_BACKGROUND_RUNNING权限，配置方式请参见[配置文件声明](../security/accesstoken-guidelines.md#配置文件权限声明)。

2. 声明后台模式类型。
   在module.json5配置文件中为需要使用长时任务的UIAbility声明相应的长时任务类型。

   
   ```ts
   "module": {
       "abilities": [
           {
               "backgroundModes": [
               "audioRecording"
               ], // 后台模式类型
           }
       ],
       ...
   }
   ```

3. 导入模块。
   
   ```ts
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';
   import wantAgent from '@ohos.app.ability.wantAgent';
   ```

4. 申请和取消长时任务。

   - 在Stage模型中，长时任务支持设备本应用申请，也支持跨设备或跨应用申请。

   - 跨设备或者跨应用在后台执行长时任务时，可以通过Call的方式在后台创建并运行UIAbility，具体使用请参考[Call调用开发指南（同设备）](../application-models/uiability-intra-device-interaction.md#通过call调用实现uiability交互仅对系统应用开放)和[Call调用开发指南（跨设备）](../application-models/hop-multi-device-collaboration.md#通过跨设备call调用实现多端协同)。

   **设备本应用**申请长时任务示例代码如下：

   ```ts
   @Entry
   @Component
   struct Index {
     @State message: string = 'ContinuousTask';
     // 通过getContext方法，来获取page所在的UIAbility上下文。
     private context = getContext(this);
   
     startContinuousTask() {
       let wantAgentInfo = {
         // 点击通知后，将要执行的动作列表
         wants: [
           {
             bundleName: "com.example.myapplication",
             abilityName: "com.example.myapplication.MainAbility"
           }
         ],
         // 点击通知后，动作类型
         operationType: wantAgent.OperationType.START_ABILITY,
         // 使用者自定义的一个私有值
         requestCode: 0,
         // 点击通知后，动作执行属性
         wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
       };
   
       // 通过wantAgent模块下getWantAgent方法获取WantAgent对象
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
   
             // 此处执行具体的长时任务逻辑，如放音等。
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

   **跨设备或跨应用**申请长时任务示例代码如下：
   
   ```ts
   import UIAbility from '@ohos.app.ability.UIAbility';
   
   const MSG_SEND_METHOD: string = 'CallSendMsg'
   
   let mContext = null;
   
   function startContinuousTask() {
     let wantAgentInfo = {
       // 点击通知后，将要执行的动作列表
       wants: [
         {
           bundleName: "com.example.myapplication",
           abilityName: "com.example.myapplication.MainAbility",
         }
       ],
       // 点击通知后，动作类型
       operationType: wantAgent.OperationType.START_ABILITY,
       // 使用者自定义的一个私有值
       requestCode: 0,
       // 点击通知后，动作执行属性
       wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
     };
   
     // 通过wantAgent模块的getWantAgent方法获取WantAgent对象
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
     // 可以根据Caller端发送的序列化数据的str值，执行不同的方法。
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


### FA模型

1. 启动并连接ServiceAbility。

   - 不需要与用户进行交互时，采用startAbility()方法启动ServiceAbility（具体使用请参考[ServiceAbility组件](../application-models/serviceability-overview.md)，并在ServiceAbility的onStart回调方法中，调用长时任务的申请和取消接口。

   - 需要与用户进行交互时（如播放音乐），采用connectAbility()方法启动并连接ServiceAbility（具体使用请参考[ServiceAbility组件](../application-models/serviceability-overview.md)，在获取到服务的代理对象后，与服务进行通信，控制长时任务的申请和取消。

2. 配置权限和声明后台模式类型。

   在config.json文件中配置长时任务权限ohos.permission.KEEP_BACKGROUND_RUNNING，配置方式请参见[配置文件声明](../security/accesstoken-guidelines.md#配置文件权限声明)。同时，为需要使用长时任务的ServiceAbility声明相应的长时任务类型。

   
   ```js
   "module": {
       "package": "com.example.myapplication",
       "abilities": [
           {
               "backgroundModes": [
               "audioRecording",
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
   import backgroundTaskManager from '@ohos.resourceschedule.backgroundTaskManager';  
   import featureAbility from '@ohos.ability.featureAbility';
   import wantAgent from '@ohos.app.ability.wantAgent';
   import rpc from "@ohos.rpc";
   ```

4. 申请和取消长时任务。在 ServiceAbility 中，调用 startBackgroundRunning() 接口和 startBackgroundRunning() 接口实现长时任务的申请和取消。
   
   ```js
   function startContinuousTask() {
     let wantAgentInfo = {
       // 点击通知后，将要执行的动作列表
       wants: [
         {
           bundleName: "com.example.myapplication",
           abilityName: "com.example.myapplication.MainAbility"
         }
       ],
       // 点击通知后，动作类型
       operationType: wantAgent.OperationType.START_ABILITY,
       // 使用者自定义的一个私有值
       requestCode: 0,
       // 点击通知后，动作执行属性
       wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
     };
   
     // 通过wantAgent模块的getWantAgent方法获取WantAgent对象
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
     // 此处执行具体的长时任务。
   
     // 长时任务执行完，调用取消接口，释放资源。
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
       // code 的具体含义用户自定义
       if (code === 1) {
         // 接收到申请长时任务的请求码
         startContinuousTask();
         // 此处执行具体长时任务
       } else if (code === 2) {
         // 接收到取消长时任务的请求码
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
       // 在执行长时任务前，调用申请接口。
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