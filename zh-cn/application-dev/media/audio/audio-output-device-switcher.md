# 实现音频输出设备路由切换
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @zhanganxiang1-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

当应用进行音频输出时，系统将依据音频流类型自动匹配对应的输出设备。如果系统输出设备不满足应用需求，应用可通过`AVCastPicker`或`setDefaultOutputDevice`实现音频输出设备路由切换。在连接音频外设（如蓝牙耳机、有线耳机）的情况下，应用还可通过`setMediaOutputDevice`强制将媒体输出切换到扬声器。

## 使用场景

1. 若应用需要为用户提供可视化、可交互的音频输出设备切换入口时，可以使用`AVCastPicker`组件，开发者只需在布局中放置该组件，系统会自动检测当前可用的音频输出设备列表，用户点击后即可完成路由切换。
2. 应用在不同场景下对默认输出设备存在不同要求。例如，语音消息流通常默认从扬声器播放，以便用户直接收听；但在某些私密场景下，应用可能希望将语音消息设置为默认从听筒播放，以保护用户隐私。此时，开发者可使用`setDefaultOutputDevice`接口，灵活更改语音消息的默认输出设备，满足特定业务需求。
3. 连接蓝牙耳机或有线耳机等外设时，系统优先从外设播放。但某些场景下，应用希望即使外设已连接，仍将媒体音频强制切换到扬声器播放（如实时翻译对话给对方）。从API版本26.0.0开始，开发者可调用`setMediaOutputDevice`接口，在连接外设的情况下通过将参数设为`audio.DeviceType.SPEAKER`强制将媒体输出设备切换为扬声器；需要恢复系统默认路由时，可再次调用`setMediaOutputDevice`接口，将参数设为`audio.DeviceType.DEFAULT`即可。

## 实现媒体流输出设备路由切换

应用可以通过使用[AVCastPicker](../../reference/apis-avsession-kit/ohos-multimedia-avcastpicker.md#avcastpicker)组件为用户提供选择设备的入口。

该组件集成了设备发现、连接、认证等能力，可嵌入应用界面。用户点击后，系统自动识别并展示当前可切换的设备列表，支持在扬声器、耳机、智能音箱等输出设备间自由切换。

## 实现通话流输出设备路由切换

`AVCastPicker`组件也适用于通话场景，应用可使用[通话设备切换组件](../avsession/using-switch-call-devices.md)为用户提供听筒、扬声器、耳机等通话设备的切换入口，方便用户在通话过程中灵活调整音频输出设备。

## 设置默认输出设备

如果系统未连接外设（如蓝牙耳机），语音通话场景音频默认听筒播放，其他场景音频默认扬声器播放；外设接入后，系统优先从外设播放。应用可通过`setDefaultOutputDevice`更改默认输出设备，但仅对以下三种[StreamUsage](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)生效：

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| STREAM_USAGE_VOICE_MESSAGE | 5 | 语音消息。 |
| STREAM_USAGE_VOICE_COMMUNICATION | 2 | VoIP语音通话。 |
| STREAM_USAGE_VIDEO_COMMUNICATION | 17 | VoIP视频通话。 |

支持的设备类型:

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| EARPIECE | 1 | 听筒。 |
| SPEAKER | 2 | 扬声器。 |
| DEFAULT | 1000 | 跟随系统。 |

调用此接口后，系统会记录指定的默认输出设备。当无外接设备连接时，音频流将路由至指定默认输出设备播放；当外设接入时，系统优先从外设播放，外设断开后自动切换至设置的默认输出设备。

### 开发步骤

`AudioRenderer`和`AudioSessionManager`都提供了`setDefaultOutputDevice`接口，用于设置通话或语音的默认输出设备。

- 音频流级：`AudioRenderer`接口生效范围为单流级别，仅对当前`AudioRenderer`实例对应的音频流生效。
- 应用级：`AudioSessionManager`接口对当前应用内所有语音和通话音频流生效，不限于单个`AudioRenderer`实例。

应用级接口优先级高于音频流级，如果同时调用了两个接口，`AudioSessionManager`的设置会覆盖`AudioRenderer`，`AudioRenderer`的设置将不再生效。

**音频流级设置接口**

从API version 12开始，应用可使用AudioRenderer的[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setdefaultoutputdevice12)设置默认设备为听筒和扬声器，调用前需要先获取[AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8)实例，设置默认设备的生命周期跟随音频流。调用`setDefaultOutputDevice`设置音频输出设备后，如需取消，可将参数设为`audio.DeviceType.DEFAULT`，将音频输出设备选择权交还给系统。

   > **说明：**
   >
   > - 由于AudioRenderer是流级别，调用本接口设置的默认音频输出设备仅对当前流生效。
   > - 本接口优先级低于AudioSessionManager的[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20)。如果使用AudioSessionManager的[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20)设置了默认音频输出设备，本接口的设置将不会生效。

   <!-- @[audioRenderer_setDefaultOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceSwitcher.ets) -->  
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
       // 设置默认输出设备为扬声器。
       audioRenderer.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
         console.info('Succeeded in setting default output device.');
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
         // ...
       });
       // ...
   
       // 设置默认输出设备为听筒。
       audioRenderer.setDefaultOutputDevice(audio.DeviceType.EARPIECE).then(() => {
         console.info('Succeeded in setting default output device.');
         // ...
       }).catch((err: BusinessError) => {
         console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
         // ...
       });
   ```

**应用级设置接口**

从API version 20开始，应用激活[AudioSession](../audio/audio-session-management.md)后，可使用AudioSessionManager的[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setdefaultoutputdevice20)设置默认输出设备，并通过`AudioSessionManager.getDefaultOutputDevice`查看默认设备是否设置成功，设置默认设备的生命周期跟随`AudioSession`。调用`setDefaultOutputDevice`设置音频输出设备后，如需取消，可将参数设为`audio.DeviceType.DEFAULT`，将音频输出设备选择权交还给系统。

   > **说明：**
   >
   > 由于AudioSessionManager是应用级设置，调用本接口设置默认音频输出设备，会对当前应用所有适用范围内的音频流生效，且会覆盖AudioRenderer的[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setdefaultoutputdevice12)接口设置的默认音频输出设备信息。

   <!-- @[audioSessionManager_setDefaultOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceSwitcher.ets) -->  
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
   let audioManager = audio.getAudioManager();
   let audioSessionManager = audioManager.getSessionManager();
   // ...
   
     // 应用根据业务场景设置适合自己的音频会话场景，激活AudioSession时，系统会根据应用选择的音频会话场景申请对应的音频焦点。
     audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_VOICE_COMMUNICATION);
   
     // 设置音频会话策略。
     let strategy: audio.AudioSessionStrategy = {
       concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
     };
   
     // 激活AudioSession。
     audioSessionManager.activateAudioSession(strategy).then(() => {
       console.info('Succeeded in activating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
   
     // 设置默认输出设备为扬声器。
     audioSessionManager.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
       console.info('Succeeded in setting default output device.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
   
     // 设置默认输出设备为听筒。
     audioSessionManager.setDefaultOutputDevice(audio.DeviceType.EARPIECE).then(() => {
       console.info('Succeeded in setting default output device.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set default output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

## 连接外设时强制切换媒体输出设备

当系统连接蓝牙耳机或有线耳机等外设时，系统优先从外设播放。从API版本26.0.0开始，应用可使用`AudioSessionManager`的[setMediaOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setmediaoutputdevice)接口，强制将媒体输出设备切换为扬声器，使音频在连接外设的情况下仍从扬声器播放。

   > **说明：**
   >
   > - 本接口仅对媒体流生效，作用于应用内所有媒体流，通话流不受影响。应用需处于前台且有正在运行的媒体流，否则设置不生效且应用退出后自动清除。
   > - 本接口设置的输出设备与[实现媒体流输出设备路由切换](#实现媒体流输出设备路由切换)设置的输出设备会相互覆盖（后调用者会覆盖先调用者设置的输出设备）。但不会覆盖[设置默认输出设备](#设置默认输出设备)设置的输出设备，也不清除系统强选设备。应用可通过监听[CurrentOutputDeviceChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#currentoutputdevicechangedevent20)事件获取当前输出设备信息。
   > - 无内置扬声器的设备（如智慧屏）上调用本接口强切到扬声器不会生效，但接口调用仍会返回成功，不会抛出错误或触发错误回调。

### 开发步骤

应用可使用`AudioSessionManager`的[setMediaOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setmediaoutputdevice)接口强制将媒体输出设备切换为扬声器。调用`setMediaOutputDevice`后，如需取消强制切换、恢复系统默认路由规则，可将参数设为`audio.DeviceType.DEFAULT`。

支持的设备类型：

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| SPEAKER | 2 | 扬声器，强制将媒体输出切换到扬声器。 |
| DEFAULT | 1000 | 系统默认设备，清除强制切换，恢复系统默认路由规则。 |

   <!-- @[audioSessionManager_setMediaOutputDevice](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample/entry/src/main/ets/pages/AudioOutputDeviceSwitcher.ets) -->
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
   let audioManager = audio.getAudioManager();
   let audioSessionManager = audioManager.getSessionManager();
   // ...
   
     // 连接蓝牙耳机后，强制将媒体输出设备切换为扬声器。
     audioSessionManager.setMediaOutputDevice(audio.DeviceType.SPEAKER).then(() => {
       console.info('Succeeded in setting media output device to speaker.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set media output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
     // ...
   
     // 取消强制切换，将媒体输出设备选择权交还给系统默认路由规则。
     audioSessionManager.setMediaOutputDevice(audio.DeviceType.DEFAULT).then(() => {
       console.info('Succeeded in setting media output device to default.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to set media output device. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

以上为各功能实现的代码片段，可通过示例代码右下方链接获取[完整示例](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRoutingAndVolumeSample)。