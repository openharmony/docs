# 使用AudioHaptic开发音振协同播放功能

AudioHaptic<sup>11+</sup>提供音频与振动协同播放及管理的方法，适用于需要在播放音频时同步发起振动的场景，如来电铃声随振、键盘按键反馈、消息通知反馈等。

## 开发指导

使用AudioHaptic播放音频并同步开启振动，涉及到音频及振动资源的管理、音频时延模式及音频流使用类型的配置、音振播放器的创建及管理等。本开发指导将以一次音振协同播放的过程为例，向开发者讲解如何使用AudioHaptic进行音振协同播放，建议配合[AudioHaptic的API说明](../../reference/apis-audio-kit/js-apis-audioHaptic.md#audiohapticmanager)阅读。

### 权限申请

如果应用创建的AudioHapticPlayer需要触发振动，则需要校验应用是否拥有该权限：`ohos.permission.VIBRATE`。

1. [声明权限](../../security/AccessToken/declare-permissions.md)。
2. [向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 开发步骤及注意事项

1. 获取音振管理器实例，并注册音频及振动资源，资源支持情况可以查看[AudioHapticManager](../../reference/apis-audio-kit/js-apis-audioHaptic.md#audiohapticmanager)。

   ```ts
   import { audio, audioHaptic } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let audioHapticManagerInstance: audioHaptic.AudioHapticManager = audioHaptic.getAudioHapticManager();

   let audioUri = 'data/audioTest.wav'; // 需更改为目标音频资源的Uri
   let hapticUri = 'data/hapticTest.json'; // 需更改为目标振动资源的Uri
   let id = 0;

   audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
     console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
     id = value;
   }).catch ((err: BusinessError) => {
     console.error(`Failed to register source ${err}`);
   });
   ```

2. 设置音振播放器参数，各参数作用可以查看[AudioHapticManager](../../reference/apis-audio-kit/js-apis-audioHaptic.md#audiohapticmanager)。

   ```ts
   let latencyMode: audioHaptic.AudioLatencyMode = audioHaptic.AudioLatencyMode.AUDIO_LATENCY_MODE_FAST;
   audioHapticManagerInstance.setAudioLatencyMode(id, latencyMode);

   let usage: audio.StreamUsage = audio.StreamUsage.STREAM_USAGE_NOTIFICATION;
   audioHapticManagerInstance.setStreamUsage(id, usage);
   ```

3. 创建AudioHapticPlayer实例。

   ```ts
   let options: audioHaptic.AudioHapticPlayerOptions = {muteAudio: false, muteHaptics: false};
   let audioHapticPlayer: audioHaptic.AudioHapticPlayer | undefined = undefined;

   audioHapticManagerInstance.createPlayer(id, options).then((value: audioHaptic.AudioHapticPlayer) => {
     console.info(`Promise returned to indicate that the audio haptic player instance.`);
     audioHapticPlayer = value;
   }).catch ((err: BusinessError) => {
     console.error(`Failed to create player ${err}`);
   });
   console.info(`Create the audio haptic player successfully.`);
   ```

4. 调用start()方法，开启音频播放并同步开启振动。

   ```ts
   audioHapticPlayer.start().then(() => {
     console.info(`Promise returned to indicate that start playing successfully.`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to start playing. ${err}`);
   });
   ```

5. 调用stop()方法，停止音频播放并同步停止振动。

   ```ts
   audioHapticPlayer.stop().then(() => {
     console.info(`Promise returned to indicate that stop playing successfully.`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to stop playing. ${err}`);
   });
   ```

6. 释放AudioHapticPlayer实例。

   ```ts
   audioHapticPlayer.release().then(() => {
     console.info(`Promise returned to indicate that release the audio haptic player successfully.`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to release the audio haptic player. ${err}`);
   });
   ```

7. 将已注册的音频及振动资源移除注册

   ```ts
   audioHapticManagerInstance.unregisterSource(id).then(() => {
     console.info(`Promise returned to indicate that unregister source successfully`);
   }).catch ((err: BusinessError) => {
     console.error(`Failed to unregistere source ${err}`);
   });
   ```

## 相关实例

针对音振协同开发，有以下相关实例可供参考：

- [音振协同示例（ArkTS）（API11）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/BasicFeature/Media/AudioHaptic)
