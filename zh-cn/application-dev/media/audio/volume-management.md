# 播放音量管理

本模块提供播放音量管理能力，包括对**系统音量**、**应用音量**和**音频流音量**的管理。

**系统音量**是由OpenHarmony系统全局管理的音量设置，适用于所有应用程序和设备。OpenHarmony系统将音频分为不同的流类型，每种流类型有独立的系统音量控制。

> **说明：**
>
> 系统音量可以通过物理音量按键或系统设置界面调节。在设置界面中，用户可以单独调整上述每种系统音量的大小。

常见的流类型以及对应的系统音量如下所示。

- 媒体音量：用于音乐、视频、游戏等媒体播放。
- 通话音量：用于语音通话。
- 铃声音量：用于来电铃声。
- 闹钟音量：用于闹钟提醒。

**应用音量**是OpenHarmony提供给三方应用用来控制该应用下所有音频流音量的一种音量类型。三方应用设置应用音量之后，该应用中起的所有音频流默认使用该音量大小。另外具有系统应用权限的应用可以通过UID单独调整指定应用的音量。

**音频流音量**是由应用独立控制的音量设置，仅影响该应用中指定的音频流输出音量大小。例如：媒体播放器可以独立控制其播放音量，而不影响系统音量以及该应用中的其他类型流音量。

系统音量、应用音量和音频流音量的关系如下所示。

- 层级关系：系统音量是全局的，应用音量和音频流音量是局部的。

  应用音量和音频流音量的调整范围受系统音量的限制。例如：系统媒体音量设置为50%，应用音量设置为100%，应用程序的最终输出音量只能达到50%。<br>
  音频流音量是对应用音量的更精细化控制。设置了应用音量的三方应用，还可以继续通过音频流音量对指定的音频流进行更加精细化的控制。
- 协同关系：应用最终的输出音量是由系统音量、应用音量和音频流音量共同决定的。例如：系统媒体音量设置为50%，应用音量设置为50%，应用程序中对媒体音频流设置音频流音量为100%，则该音频流最终输出的音量为25%。

OpenHarmony通过系统音量，应用音量和音频流音量协同的方式实现应用对音量的精确控制。

## 系统音量

管理系统音量的接口由AudioVolumeManager提供，在使用之前，需要使用[getVolumeManager()](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9)获取AudioVolumeManager实例。

通过AudioVolumeManager只能获取音量信息及监听音量变化，不能主动调节系统音量。如果应用需要调节系统音量，可以[使用音量面板调节系统音量](#使用音量面板调节系统音量)。

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

### 获取音量信息

管理系统音量的接口由AudioVolumeManager提供，在使用之前，需要使用[getVolumeManager()](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9)获取AudioVolumeManager实例。

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

使用[AudioVolumeManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioVolumeManager.md)获取指定流类型的音量信息。

示例代码如下所示：

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 获取指定流的音量。
audioVolumeManager.getVolumeByStream(audio.StreamUsage.STREA_USAGE_MUSIC);

// 获取指定流的最小音量。
audioVolumeManager.getMinVolumeByStream(audio.StreamUsage.STREA_USAGE_MUSIC);

// 获取指定流的最大音量。
audioVolumeManager.getMaxVolumeByStream(audio.StreamUsage.STREA_USAGE_MUSIC);
```

### 监听系统音量变化

通过设置监听事件，可以监听系统音量的变化：

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.on('streamVolumeChange', audio.StreamUsage.STREAM_USAGE_MUSIC, (streamVolumeEvent: audio.StreamVolumeEvent) => {
  console.info(`StreamUsagem: ${streamVolumeEvent.streamUsage} `);
  console.info(`Volume level: ${streamVolumeEvent.volume} `);
  console.info(`Whether to updateUI: ${streamVolumeEvent.updateUi} `);
});
```

<!--Del-->
### 调节系统音量（仅对系统应用开放）

目前调节系统音量主要是靠SystemAPI，具体服务于物理音量按键和设置。通过音量按键可以调节系统音量的大小，根据按下的具体按键调用系统接口，实现系统音量的大小调节。调节的音量类型包括媒体、铃声和通知。
<!--DelEnd-->

### 使用音量面板调节系统音量

应用无法直接调节系统音量，可以通过系统音量面板，让用户通过界面操作来调节音量。当用户通过应用内音量面板调节音量时，系统会展示音量提示界面，显性地提示用户系统音量发生改变。

系统提供了ArkTS组件AVVolumePanel（音量面板），应用可以创建该组件，具体样例和介绍请查看[AVVolumePanel参考文档](../../reference/apis-audio-kit/ohos-multimedia-avvolumepanel.md)。

## 应用音量

管理应用音量的接口由AudioVolumeManager提供，在使用之前，需要使用[getVolumeManager()](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getvolumemanager9)获取AudioVolumeManager实例。

当[音量模式](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiovolumemode19)设置为APP_INDIVIDUAL时，可通过下面示例接口设置、查询应用音量。

### 调节应用音量

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();

// 设置应用的音量（范围为0到100）。
audioVolumeManager.setAppVolumePercentage(20).then(() => {
  console.info(`set app volume success.`);
});

// 查询应用音量。
audioVolumeManager.getAppVolumePercentage().then((value: number) => {
  console.info(`app volume is ${value}.`);
});

// 监听应用音量变化，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let appVolumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};
audioVolumeManager.on('appVolumeChange', appVolumeChangeCallback);
audioVolumeManager.off('appVolumeChange', appVolumeChangeCallback);

// 取消该事件的所有监听。
audioVolumeManager.off('appVolumeChange');
```

<!--Del-->
### 根据UID调节应用音量（仅对系统应用开放）

```ts
import { audio } from '@kit.AudioKit';

let uid: number = 20010041; // 应用ID。
let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();

// 设置指定应用的音量（范围为0到100）。
let volume: number = 20;    // 要设置的音量值。
audioVolumeManager.setAppVolumePercentageForUid(uid, volume).then(() => {
  console.info(`set app volume success.`);
});

// 获取指定应用的音量（范围为0到100）。
audioVolumeManager.getAppVolumePercentageForUid(uid).then((value: number) => {
  console.info(`app volume is ${value}.`);
});

// 查询应用音量是否已静音。
audioVolumeManager.isAppVolumeMutedForUid(uid, true).then((value: boolean) => {
  console.info(`app muted state is ${value}.`);
});

// 设置应用静音状态。
audioVolumeManager.setAppVolumeMutedForUid(uid, true).then(() => {
  console.info(`set app mute state success.`);
});

// 监听应用音量变化，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let appVolumeChangeForUidCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};
audioVolumeManager.on('appVolumeChangeForUid', uid, appVolumeChangeForUidCallback);
audioVolumeManager.off('appVolumeChangeForUid', appVolumeChangeForUidCallback);

// 取消该事件的所有监听。
audioVolumeManager.off('appVolumeChangeForUid');
```
<!--DelEnd-->

## 音频流音量

管理音频流音量的接口是AVPlayer或AudioRenderer的setVolume()方法，使用[AVPlayer](../../reference/apis-media-kit/arkts-apis-media-f.md#mediacreateavplayer9)设置音频流音量的示例代码如下：

```ts
let volume = 1.0;  // 指定的音量大小，取值范围为[0.00-1.00]，1表示最大音量。
avPlayer.setVolume(volume);
```

使用[AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8)的[setVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setvolume9)和[getVolume](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#getvolume12)接口分别完成音频流音量的设置和获取。

示例代码如下所示：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置音频流音量。
audioRenderer.setVolume(0.5).then(() => {  // 音量范围为[0.0-1.0]。
  console.info('Invoke setVolume succeeded.');
}).catch((err: BusinessError) => {
  console.error(`Invoke setVolume failed, code is ${err.code}, message is ${err.message}`);
});

// 获取音频流音量。
try {
  let value: number = audioRenderer.getVolume();
  console.info(`Indicate that the volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume, error ${error}.`);
}
```

### 监听活跃流变化

通过设置监听事件，可以监听活跃流的变化。

```ts
import { audio } from '@kit.AudioKit';

// 监听活跃流变化，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let activeVolumeTypeChangeCallback = (volumeType: audio.AudioVolumeType) => {
  console.info(`VolumeType of stream: ${volumeType} `);
};
audioVolumeManager.on('activeVolumeTypeChange', activeVolumeTypeChangeCallback);
audioVolumeManager.off('activeVolumeTypeChange', activeVolumeTypeChangeCallback);

// 取消该事件的所有监听。
audioVolumeManager.off('activeVolumeTypeChange');
```