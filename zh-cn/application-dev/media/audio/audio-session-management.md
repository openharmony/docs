# 使用AudioSession管理应用音频焦点(ArkTS)

对于涉及多个音频流并发播放的场景，系统已预设了默认的[音频焦点策略](audio-playback-concurrency.md#音频焦点策略)，该策略将对所有音频流（包括播放和录制）实施统一的焦点管理。

应用可利用音频会话管理（AudioSessionManager）提供的接口，通过AudioSession主动管理应用内音频流的焦点，自定义本应用音频流的焦点策略，调整本应用音频流释放音频焦点的时机，从而贴合应用特定的使用需求。

本文档主要介绍AudioSession相关ArkTS API的使用方法和注意事项，更多音频焦点及音频会话的信息，可参考：[音频焦点和音频会话介绍](audio-playback-concurrency.md)。

## 获取音频会话管理器

创建AudioSessionManager实例。在使用AudioSessionManager的API前，需要先通过[getSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getsessionmanager12)创建实例。

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
  ```

## 激活音频会话

应用可以通过[AudioSessionManager.activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12)接口激活当前应用的音频会话。

应用在激活AudioSession时，需指定[音频会话策略（AudioSessionStrategy）](audio-playback-concurrency.md#音频会话策略audiosessionstrategy)。策略中包含参数concurrencyMode，其类型为[AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12)，用于声明音频并发策略。

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };
  
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('activateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });
  ```

## 查询音频会话是否已激活

应用可以通过[isAudioSessionActivated](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#isaudiosessionactivated12)接口检查当前应用的音频会话是否已激活。

  ```ts
  let isActivated = audioSessionManager.isAudioSessionActivated();
  ```

## 停用音频会话

应用可以通过[deactivateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#deactivateaudiosession12)接口停用当前应用的音频会话。

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });
  ```

## 监听音频会话停用事件

应用可以通过[on('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessiondeactivated12)接口监听[音频会话停用事件（AudioSessionDeactivatedEvent）](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12)。

当AudioSession被停用（非主动停用）时，应用会收到[音频会话停用事件（AudioSessionDeactivatedEvent）](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12)，其中包含[音频会话停用原因（AudioSessionDeactivatedReason）](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosessiondeactivatedreason12)。

在收到AudioSessionDeactivatedEvent时，应用可根据自身业务需求，做相应的处理，例如释放相应资源、重新激活AudioSession等。

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
  });
  ```

## 取消监听音频会话停用事件

应用可以通过[off('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#offaudiosessiondeactivated12)接口取消监听音频会话停用事件。

  ```ts
  audioSessionManager.off('audioSessionDeactivated');
  ```

## 完整示例

参考以下示例，完成音频会话从创建到激活并监听的过程。

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let audioManager = audio.getAudioManager();
  // 创建音频会话管理器。
  let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
  // 设置音频并发模式。
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // 激活音频会话。
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('activateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });

  // 查询音频会话是否已激活。
  let isActivated = audioSessionManager.isAudioSessionActivated();

  // 监听音频会话停用事件。
  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
  });

  // 音频会话激活后，应用在此处正常执行音频播放、暂停、停止、释放等操作即可。 

  // 停用音频会话。
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });

  // 取消监听音频会话停用事件。
  audioSessionManager.off('audioSessionDeactivated');
  ```
