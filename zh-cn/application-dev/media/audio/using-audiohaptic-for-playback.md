# 使用AudioHaptic开发音振协同播放功能(ArkTS)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @huyue57-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

从API版本11开始支持音振协同播放。

AudioHaptic提供音频与振动协同播放及管理的方法，适用于需要在播放音频时同步发起振动的场景，如来电铃声随振、键盘按键反馈、消息通知反馈等。

## 开发指导

使用AudioHaptic开发音频与振动协同播放功能，涉及到音频及振动资源的管理、音频时延模式及音频流使用类型的配置、音振播放器的创建及管理等。本文将以一次音振协同播放的过程为例，讲解如何使用AudioHaptic开发音振协同播放功能，建议结合[audioHaptic](../../reference/apis-audio-kit/js-apis-audioHaptic.md)API接口文档一起阅读。

### 权限申请

如果应用创建的AudioHapticPlayer需要触发振动，则需要校验应用是否拥有该权限：`ohos.permission.VIBRATE`。

1. 请参考[声明权限](../../security/AccessToken/declare-permissions.md)指导，声明该振动权限。
2. 由于该权限为用户授予类权限，需要拉起用户授权弹窗让用户使用时授权，否则无法获取该权限，代码开发请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 开发步骤及注意事项

1. 获取音振管理器实例，并注册音频及振动资源，单个应用最多支持同时注册128个资源，播放器支持的音频和振动资源格式，请查看[registerSource](../../reference/apis-audio-kit/js-apis-audioHaptic.md#registersource)文档中的描述。开发者可通过如下两种方式注册资源：
   - 方式1：使用[registerSource](../../reference/apis-audio-kit/js-apis-audioHaptic.md#registersource)接口，通过文件URI来注册资源。
   - 方式2（推荐）：从API版本20开始，支持使用[registerSourceFromFd](../../reference/apis-audio-kit/js-apis-audioHaptic.md#registersourcefromfd20)接口，通过文件描述符来注册资源。

   <!-- @[get_haptic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->
   
   ``` TypeScript
   import { audio, audioHaptic } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   
   let audioHapticManagerInstance: audioHaptic.AudioHapticManager = audioHaptic.getAudioHapticManager();
   
   // ...
     // 方法1：使用registerSource接口注册资源。
     let audioUri = 'data/audioTest.wav'; // 此处仅作示例，实际使用时需要将文件替换为应用目标音频资源的URI。
     let hapticUri = 'data/hapticTest.json'; // 此处仅作示例，实际使用时需要将文件替换为应用目标振动资源的URI。
     let idForUri = 0;
   
     audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
       console.info(`Succeeded in registering source, sourceId is ${value}.`);
       idForUri = value;
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to register source. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
     // 方法2：使用registerSourceFromFd接口注册资源。
     // 此处仅作示例，实际使用时需要将文件替换为应用rawfile目录下的对应文件。
     let audioFile = context.resourceManager.getRawFdSync('audioTest.ogg');
     let audioFd: audioHaptic.AudioHapticFileDescriptor = {
       fd: audioFile.fd,
       offset: audioFile.offset,
       length: audioFile.length,
     };
     // 此处仅作示例，实际使用时需要将文件替换为应用rawfile目录下的对应文件。
     let hapticFile = context.resourceManager.getRawFdSync('hapticTest.json');
     let hapticFd: audioHaptic.AudioHapticFileDescriptor = {
       fd: hapticFile.fd,
       offset: hapticFile.offset,
       length: hapticFile.length,
     };
     audioHapticManagerInstance.registerSourceFromFd(audioFd, hapticFd).then((value: number) => {
       console.info(`Succeeded in registering source from fd, sourceId is ${value}.`);
       idForFd = value;
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to register source from fd. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

2. 设置音振播放器音频时延模式和音频流使用类型，具体作用和类型可以查看[setAudioLatencyMode](../../reference/apis-audio-kit/js-apis-audioHaptic.md#setaudiolatencymode)和[setStreamUsage](../../reference/apis-audio-kit/js-apis-audioHaptic.md#setstreamusage)接口的文档，推荐短信、通知音等短提示音搭配FAST模式，来电铃声等长铃声搭配NORMAL模式。

   <!-- @[set_hapticparam](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->
   
   ``` TypeScript
   let latencyMode: audioHaptic.AudioLatencyMode = audioHaptic.AudioLatencyMode.AUDIO_LATENCY_MODE_NORMAL;
   audioHapticManagerInstance.setAudioLatencyMode(idForFd, latencyMode);
   
   let usage: audio.StreamUsage = audio.StreamUsage.STREAM_USAGE_NOTIFICATION;
   audioHapticManagerInstance.setStreamUsage(idForFd, usage);
   ```

3. 调用[createPlayer](../../reference/apis-audio-kit/js-apis-audioHaptic.md#createplayer)方法，创建AudioHapticPlayer实例，其中options参数控制是否将音频静音，是否禁止振动。参数为空时，播放器默认开启音频，允许振动。

   <!-- @[create_haptic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->
   
   ``` TypeScript
   let options: audioHaptic.AudioHapticPlayerOptions = {muteAudio: false, muteHaptics: false};
   let audioHapticPlayer: audioHaptic.AudioHapticPlayer | undefined = undefined;
   // ...
       audioHapticManagerInstance.createPlayer(idForFd, options).then((value: audioHaptic.AudioHapticPlayer) => {
         console.info('Succeeded in creating player.');
         audioHapticPlayer = value;
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to create player. Code: ${err.code}, message: ${err.message}`);
         // ...
       });
   ```

4. 调用[start](../../reference/apis-audio-kit/js-apis-audioHaptic.md#start)方法，开启音频播放并同步开启振动。

   <!-- @[haptic_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->
   
   ``` TypeScript
   audioHapticPlayer.start().then(() => {
     console.info('Succeeded in starting audio haptic player.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to start audio haptic player. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```

5. 调用[stop](../../reference/apis-audio-kit/js-apis-audioHaptic.md#stop)方法，停止音频播放并同步停止振动。

   <!-- @[haptic_stop](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->
   
   ``` TypeScript
   audioHapticPlayer.stop().then(() => {
     console.info('Succeeded in stopping audio haptic player.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to stop audio haptic player. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```

6. 应用在使用完音振协同播放器后应主动调用[release](../../reference/apis-audio-kit/js-apis-audioHaptic.md#release)方法，释放AudioHapticPlayer实例，防止播放器实例长期占用系统音振资源，产生严重的内存与系统资源泄漏，从而导致应用后续无法再创建音振协同播放器。

   <!-- @[haptic_release](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->
   
   ``` TypeScript
   audioHapticPlayer.release().then(() => {
     console.info('Succeeded in releasing audio haptic player.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to release audio haptic player. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```

7. 当资源不再使用时，应用必须调用[unregisterSource](../../reference/apis-audio-kit/js-apis-audioHaptic.md#unregistersource)方法，将已注册的音频及振动资源移除注册，若长期堆积未注销的无效资源，会快速耗尽应用128个资源注册配额，直接导致后续所有音振资源注册失败、播放器无法创建，音振协同播放功能不可用，同时会引发持续性资源泄漏问题。

   <!-- @[haptic_unregist](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleJS/entry/src/main/ets/pages/haptic.ets) -->
   
   ``` TypeScript
   audioHapticManagerInstance.unregisterSource(idForFd).then(() => {
     console.info('Succeeded in unregistering source.');
     // ...
   }).catch((err: BusinessError) => {
     console.error(`Failed to unregister source. Code: ${err.code}, message: ${err.message}`);
     // ...
   });
   ```
