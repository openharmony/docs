# 播放音量管理

播放音量的管理主要包括对系统音量的管理和对音频流音量的管理。系统音量与音频流音量分别是指OpenHarmony系统的总音量和指定音频流的音量，其中音频流音量的大小受制于系统音量，管理两者的接口不同。

## 系统音量

管理系统音量的接口是AudioVolumeManager，在使用之前，需要使用getVolumeManager()获取AudioVolumeManager实例。

通过AudioVolumeManager只能获取音量信息及监听音量变化，不能主动调节系统音量。如果应用需要调节系统音量，可以[使用音量面板调节系统音量](#使用音量面板调节系统音量)。

```ts
import { audio } from '@kit.AudioKit';

let audioManager = audio.getAudioManager();
let audioVolumeManager = audioManager.getVolumeManager();
```

### 监听系统音量变化

通过设置监听事件，可以监听系统音量的变化：

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

<!--Del-->
### 调节系统音量（仅对系统应用开放）

目前调节系统音量主要是靠SystemAPI，具体服务于物理音量按键和设置。通过音量按键可以调节系统音量的大小，根据按下的具体按键调用系统接口，实现系统音量的大小调节。调节的音量类型包括媒体、铃声和通知。
<!--DelEnd-->

### 使用音量面板调节系统音量

应用无法直接调节系统音量，可以通过系统音量面板，让用户通过界面操作来调节音量。当用户通过应用内音量面板调节音量时，系统会展示音量提示界面，显性地提示用户系统音量发生改变。

系统提供了ArkTS组件AVVolumePanel（音量面板），应用可以创建该组件，具样例和介绍请查看[AVVolumePanel参考文档](../../reference/apis-audio-kit/ohos-multimedia-avvolumepanel.md)。

## 音频流音量

管理音频流音量的接口是AVPlayer或AudioRenderer的setVolume()方法，使用[AVPlayer](../../reference/apis-media-kit/js-apis-media.md#mediacreateavplayer9)设置音频流音量的示例代码如下：

```ts
let volume = 1.0;  // 指定的音量大小，取值范围为[0.00-1.00]，1表示最大音量
avPlayer.setVolume(volume);
```

使用[AudioRenderer](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiorenderer8)设置音频流音量的示例代码如下：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5).then(() => {  // 音量范围为[0.0-1.0]
  console.info('Invoke setVolume succeeded.');
}).catch((err: BusinessError) => {  
  console.error(`Invoke setVolume failed, code is ${err.code}, message is ${err.message}`);
});
```
