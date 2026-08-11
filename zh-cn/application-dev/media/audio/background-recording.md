# 实现后台录音
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ZhengYong21-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

从API version 9开始，支持后台长时任务开发功能。应用配置后台长时任务可以支持应用后台录音。

后台录音是指应用在前台启动录音任务后，退至后台仍持续采集音频的场景。典型场景包括会议记录、语音备忘、采访录音等需要长时间录制的业务。

后台录音涉及麦克风采集和后台运行。应用需要同时满足麦克风权限、录音能力实现、后台长时任务声明和系统管控要求，不应在用户无感知或未授权的情况下启动录音。


## 约束与限制

- 用户授权：录音前必须获得麦克风权限。用户撤销权限后，应用应立即停止录音并释放资源。
- 用户可感知：后台录音期间应保持明确的用户感知方式。例如展示正在录音的通知、状态提示。
- 场景匹配：后台模式声明应与真实业务一致。应用申请录音类型长时任务后，需要实际执行录音业务。仅存在播放、播控或媒体会话控制诉求时，不需要声明后台录音模式。
- 最小化采集：应用只在用户触发录音任务期间采集音频，任务结束后及时停止，避免长期占用麦克风。
- 资源释放：应用进入后台、应用退出、应用崩溃或录音完成后，必须要确保录音器、文件句柄和后台任务状态一致，避免出现录音已停止但后台任务仍存在的情况。
- 隐私合规：不应在后台自动上传用户未确认的录音内容，录音文件的保存、上传、分享和删除应遵循用户授权。

## 开发步骤

应用实现录音功能的具体内容请参考[使用AudioCapturer开发音频录制功能(ArkTS)](using-audiocapturer-for-recording.md)、[推荐使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)或[使用AVRecorder录制音频(ArkTS)](../media/using-avrecorder-for-recording.md)。当应用需要退至后台持续录音时，还需要申请录音类型的[长时任务(ArkTS)](../../task-management/continuous-task.md)。

1. 声明后台录音模式。

   在[module.json5配置文件](../../quick-start/module-configuration-file.md)中，为需要执行后台录音的UIAbility声明`audioRecording`后台模式。

   ```json
   {
     "abilities": [
       {
         "name": "EntryAbility",
         "backgroundModes": [
           "audioRecording"
         ]
       }
     ]
   }
   ```

2. 启动录音任务。

   应用需要在前台启动录音任务，启动后可以退至后台继续录音。在后台直接启动录音会失败。

   录音开始前，应用需要确认用户已经明确触发录音操作，并处理麦克风权限未授权、设备被占用、存储路径不可用等异常场景。录音开发方式请参考[音频录制开发概述](audio-recording-overview.md)。

   针对应用在后台录音被其他音频流打断后无法恢复的场景，推荐使用以下解决方案：

   - 应用录音在后台被打断，收到焦点恢复通知时出现start失败，可以弹窗提醒用户再次打开应用手动重新开始录音。
   - 使用音频录制接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用MUTE_WHEN_INTERRUPTED，录音流焦点策略被设置成静音打断模式，被其他应用打断导致停止或暂停录制时会进入静音录制状态，在此状态下录制的音频没有声音，其他应用录制动作完成后恢复录制有声数据。

3. 申请录音类型长时任务。

   当录音需要退至后台持续运行时，应用需要申请`AUDIO_RECORDING`类型长时任务，使系统识别该后台任务与录音业务匹配。

   <!-- @[background_task](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioVoIPCallSampleC/entry/src/main/ets/pages/AudioPlayer.ets) -->
   
   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   import { backgroundTaskManager } from '@kit.BackgroundTasksKit'
   import { wantAgent, WantAgent } from '@kit.AbilityKit'
   // ...
   
     // 开启长时任务。
     startContinuousTask(context: Context) {
       let wantAgentInfo: wantAgent.WantAgentInfo = {
         // 点击通知后，将要执行的动作列表。
         // 添加需要被拉起应用的bundleName和abilityName。
         wants: [
           {
             bundleName: 'com.example.backgroundmusic',
             abilityName: 'MainAbility'
           }
         ],
         // 指定点击通知栏消息后的动作是拉起ability。
         actionType: wantAgent.OperationType.START_ABILITY,
         // 使用者自定义的一个私有值。
         requestCode: 0,
         // 点击通知后，动作执行属性。
         actionFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
       };
   
       try {
         // 通过wantAgent模块下getWantAgent方法获取WantAgent对象。
         wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj: WantAgent) => {
           try {
             let list: string[] = ['audioPlayback'];
             backgroundTaskManager.startBackgroundRunning(context, list, wantAgentObj)
               .then(() => {
                 console.info('Operate startBackgroundRunning succeeded');
               })
               .catch((error: BusinessError) => {
                 console.error(`Failed to operate startBackgroundRunning. code is ${error.code} message is ${error.message}`);
               });
           } catch (error) {
             console.error(`Failed to operate startBackgroundRunning. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
           };
         });
       } catch (error) {
         console.error(`Failed to operate getWantAgent. code is ${(error as BusinessError).code} message is ${(error as BusinessError).message}`);
       }
     }
   ```

   长时任务启动失败时，应用需避免继续以后台录音方式运行，应停止录音或引导用户回到前台处理。长时任务的完整申请和取消流程请参考[长时任务(ArkTS)](../../task-management/continuous-task.md)。

4. 停止录音并释放资源。

   用户停止录音、录音异常中断或业务结束时，应用需要调用AudioCapturer的[release](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#release8)接口停止录音、释放音频采集资源，并同步取消录音类型长时任务。

   <!-- @[background_task_cancel](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioVoIPCallSampleC/entry/src/main/ets/pages/AudioPlayer.ets) -->
   
   ``` TypeScript
   // 取消长时任务。
   stopContinuousTask(context: Context) {
     backgroundTaskManager.stopBackgroundRunning(context).then(() => {
       console.info(`Succeeded in operating stopBackgroundRunning.`);
     }).catch((err: BusinessError) => {
       console.error(`Failed to operate stopBackgroundRunning. Code is ${err.code}, message is ${err.message}`);
     });
   }
   ```
