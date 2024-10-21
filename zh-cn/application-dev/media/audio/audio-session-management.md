# 音频会话管理(ArkTS)

**对于多个音频流并发的场景，系统预设了默认的[音频焦点策略](./audio-playback-concurrency.md#音频焦点策略)，会对所有音频流（包含播放和录制）进行统一的焦点管理。**

**应用可以使用音频会话管理（AudioSessionManager）的相关接口，通过AudioSession主动管理本应用音频流的焦点，定制本应用音频流的焦点策略，修改本应用音频流释放音频焦点的时机，以满足应用特定的使用场景。**

本文主要介绍AudioSession相关ArkTs接口的使用方法和注意事项，更多音频焦点及音频会话的信息，可参考：[音频焦点和音频会话介绍](./audio-playback-concurrency.md)

## 获取音频会话管理器

创建AudioSessionManager实例。在使用AudioSessionManager的API前，需要先通过[getSessionManager](../../reference/apis-audio-kit/js-apis-audio.md#getsessionmanager12)创建实例。

  ```ts
  import { audio } from '@kit.AudioKit';

  let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
  ```

## 激活音频会话

应用可以通过[activateAudioSession](../../reference/apis-audio-kit/js-apis-audio.md#activateaudiosession12)接口激活当前应用的音频会话。

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

## 停用音频会话

应用可以通过[deactivateAudioSession](../../reference/apis-audio-kit/js-apis-audio.md#deactivateaudiosession12)接口停用当前应用的音频会话。

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });
  ```

## 音频会话策略

应用在[激活音频会话](#激活音频会话)时，需指定[音频会话策略（AudioSessionStrategy）](../../reference/apis-audio-kit/js-apis-audio.md#audiosessionstrategy12)，其中包含[音频并发模式（AudioConcurrencyMode）](../../reference/apis-audio-kit/js-apis-audio.md#audioconcurrencymode12)参数，用于声明不同的音频并发策略。

系统预设了以下4种音频并发模式：

- 默认模式（CONCURRENCY_DEFAULT）：即系统默认的[音频焦点策略](./audio-playback-concurrency.md#音频焦点策略)。

- 并发模式（CONCURRENCY_MIX_WITH_OTHERS）：和其它音频流并发。

- 降低音量模式（CONCURRENCY_DUCK_OTHERS）：和其他音频流并发，并且降低其他音频流的音量。

- 暂停模式（CONCURRENCY_PAUSE_OTHERS）：暂停其他音频流，待释放焦点后通知其他音频流恢复。

注意：AudioSession使用以上各模式时，系统会最大程度满足其焦点策略，但并不一定能在所有场景都能满足。

例如：使用CONCURRENCY_PAUSE_OTHERS模式时，Movie流申请音频焦点，如果Music流正在播放，则Music流会被暂停。但是如果VoiceCommunication流正在播放，则VoiceCommunication流不会被暂停。

## 查询音频会话是否已激活

应用可以通过[isAudioSessionActivated](../../reference/apis-audio-kit/js-apis-audio.md#isaudiosessionactivated12)接口检查当前应用的音频会话是否已激活。

  ```ts
  let isActivated = audioSessionManager.isAudioSessionActivated();
  ```

## 监听音频会话停用事件

应用可以通过[on('audioSessionDeactivated')](../../reference/apis-audio-kit/js-apis-audio.md#onaudiosessiondeactivated12)接口监听[音频会话停用事件（AudioSessionDeactivatedEvent）](../../reference/apis-audio-kit/js-apis-audio.md#audiosessiondeactivatedevent12)。

当AudioSession被停用（非主动停用）时，应用会收到[音频会话停用事件（AudioSessionDeactivatedEvent）](../../reference/apis-audio-kit/js-apis-audio.md#audiosessiondeactivatedevent12)，其中包含[音频会话停用原因（AudioSessionDeactivatedReason）](../../reference/apis-audio-kit/js-apis-audio.md#audiosessiondeactivatedreason12)。

系统预设了以下2种音频会话停用原因：

- 应用焦点被抢占（DEACTIVATED_LOWER_PRIORITY）：该应用所有的音频流全部被其他音频流打断，丢失焦点，AudioSession被同时停用。

- 超时（DEACTIVATED_TIMEOUT）：若AudioSession处于激活状态，但该应用没有音频流在运行状态，则AudioSession会在1分钟之后被超时停用。

  注意：当AudioSession因超时而停用时，被其压低音量（Duck）的音频会触发恢复音量（Unduck）操作，被其暂停（Pause）的音频流会触发停止（Stop）操作。

在收到AudioSessionDeactivatedEvent时，应用可根据自身业务需求，做相应的处理，例如释放相应资源、重新激活AudioSession等。

  ```ts
  import { audio } from '@kit.AudioKit';

  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
  });
  ```

## 取消监听音频会话停用事件

应用可以通过[off('audioSessionDeactivated')](../../reference/apis-audio-kit/js-apis-audio.md#offaudiosessiondeactivated12)接口取消监听音频会话停用事件。

  ```ts
  audioSessionManager.off('audioSessionDeactivated');
  ```

## 完整示例

参考以下示例，完成音频会话从创建到激活并监听的过程。

  ```ts
  import { audio } from '@kit.AudioKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let audioManager = audio.getAudioManager();
  // 创建音频会话管理器
  let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
  // 设置音频并发模式
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // 激活音频会话
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('activateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });

  // 查询音频会话是否已激活。
  let isActivated = audioSessionManager.isAudioSessionActivated();

  // 监听音频会话停用事件
  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    console.info(`reason of audioSessionDeactivated: ${audioSessionDeactivatedEvent.reason} `);
  });

  // 音频会话激活后，应用在此处正常执行音频播放、暂停、停止、释放等操作即可。 

  // 停用音频会话
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('deactivateAudioSession SUCCESS');
  }).catch((err: BusinessError) => {
    console.error(`ERROR: ${err}`);
  });

  // 取消监听音频会话停用事件
  audioSessionManager.off('audioSessionDeactivated');
  ```
