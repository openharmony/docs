# 音频会话管理(ArkTS)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

对于涉及多个音频流并发的场景，系统已预设了默认的[音频焦点策略](audio-playback-concurrency.md#音频焦点策略)，该策略将对所有音频流（包括播放和录制）实施统一的焦点管理。

当系统提供的默认焦点策略不能满足应用需求时，应用可利用音频会话管理提供的接口，管理应用内音频流的焦点，自定义音频流的焦点策略，调整音频流释放焦点的时机，以满足特定需求。本文档的示例代码均为ArkTS，如果需要使用OHAudio开发请参考[使用OHAudio开发音频会话功能(C/C++)](using-ohaudio-for-session.md)。

音频会话管理提供了两种焦点管理方式：[音频流独立持有焦点](#音频流独立持有焦点)和[音频会话统一持有焦点](#音频会话统一持有焦点)，应用可根据自身业务需求选择合适的焦点管理方式。

两种方式设置的[音频会话策略](#音频会话策略)对所有流均生效，激活与释放时机相同，即音频流播放前激活，停止后释放。

| 对比项 | 音频流独立持有焦点 | 音频会话统一持有焦点 |
|:---|:---|:---|
| 焦点管理方式 | AudioSession不持有焦点，各音频流独立申请和释放焦点。 | AudioSession统一持有焦点，管理音频流的焦点申请与释放。 |
| 适用音频流类型 | 播放流和录音流均适用。 | 适用于播放流（STREAM_USAGE_ALARM、STREAM_USAGE_NOTIFICATION、STREAM_USAGE_ACCESSIBILITY等除外），录音流不适用。 |

使用音频会话相关接口，可以实现以下功能：

- [音频流独立持有焦点](#音频流独立持有焦点)：系统默认焦点策略不能满足应用当前需求，仅需调整音频流的焦点策略。

  **典型场景：** 应用播放短视频时，会打断后台音乐，应用希望自身的音频流停止后，后台的音乐可以自动恢复。该场景需要应用在音频流启动前激活音频会话，音频流停止后停用音频会话。

- [音频会话统一持有焦点](#音频会话统一持有焦点)：需要启动多个音频流并保证播放流程的连续性，避免音频流切换时因焦点释放导致其他应用音频恢复。

  **典型场景：** 应用连续播放多个音频时，在多个音频衔接的间隙，不希望后台被影响的其他音频自动恢复，希望整个播放过程保持音频焦点的连贯性。该场景需要应用在整个播放过程开始前激活音频会话，整个播放过程结束后停用音频会话。

> **注意：**
>
> - 音频并发策略优先级为：STOP > PAUSE > DUCK > PLAYBOTH。当指定的音频会话策略优先级高于默认并发策略时，指定的音频会话策略不会生效。
> - 应用在开始音频播放或录制之前需要确保音频会话已经处于激活状态，否则音频会话的自定义焦点策略不会生效。若应用使用了异步接口，则需要格外注意异步操作执行的时序。

## 获取音频会话管理器

在使用AudioSessionManager的API前，需要先通过[getSessionManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getsessionmanager12)获取一个单例AudioSessionManager对象。

使用OHAudio开发请参考：[获取音频会话管理器](using-ohaudio-for-session.md#获取音频会话管理器)。

<!-- @[get_session_manager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { audio } from '@kit.AudioKit';
// ...

let audioManager = audio.getAudioManager();
// 创建音频会话管理器。
let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
```

## 音频会话策略

应用在激活AudioSession时，需先指定音频会话策略（[AudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessionstrategy12)）。可通过设置音频并发模式（[AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12)）来指定不同的音频会话策略。

使用OHAudio开发请参考：音频会话策略（[OH_AudioSession_Strategy](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-strategy.md)）。

系统预设的音频并发模式如下所示：

- 默认模式（CONCURRENCY_DEFAULT）：即系统默认的[音频焦点策略](audio-playback-concurrency.md#音频焦点策略)。

- 并发模式（CONCURRENCY_MIX_WITH_OTHERS）：和其他音频流并发。

  **典型场景：**
  - 应用播放音乐时，会被后起的音乐或视频打断，应用希望自身的音频流和后起的音乐或视频并发（该场景需要应用在音频流启动前激活AudioSession）。

  - 应用录音时，会打断后台正在播放的音乐或视频，应用希望自身的音频流和后台正在播放的音乐或视频并发（该场景需要应用在音频流启动前激活AudioSession）。

- 降低音量模式（CONCURRENCY_DUCK_OTHERS）：和其他音频流并发，并且降低其他音频流的音量。

  **典型场景：** 应用播放游戏音效时，会和后台正在播放的音乐并发，应用希望自身的音频流和后台正在播放的音乐并发时压低后台音乐音量（该场景需要应用在音频流启动前激活AudioSession）。

- 暂停模式（CONCURRENCY_PAUSE_OTHERS）：暂停其他音频流，待释放焦点后通知其他音频流恢复。

  **典型场景：** 应用播放短视频时，会打断后台正在播放的音乐，应用希望自身的音频流停止后，后台的音乐可以自动恢复（该场景需要应用在音频流启动前激活AudioSession，音频流停止后停用AudioSession）。

> **注意：**
>
> - 当应用通过AudioSession使用上述各种模式时，系统将尽量满足其焦点策略，但可能无法保证在所有场景下完全满足。
> - 并发模式（CONCURRENCY_MIX_WITH_OTHERS）在本应用申请焦点和后续其他应用申请焦点时均会生效；降低音量模式（CONCURRENCY_DUCK_OTHERS）和暂停模式（CONCURRENCY_PAUSE_OTHERS）仅在本应用申请焦点时生效，后续其他应用申请焦点时，优先遵循其他应用的并发模式。

## 音频流独立持有焦点

系统默认焦点策略不能满足应用当前需求时，应用可通过指定[音频会话策略](#音频会话策略)后激活AudioSession来完成焦点策略修改。

AudioSession激活成功后，应用新起的音频流将会按照修改后的焦点策略起流。

使用OHAudio开发请参考：[使用OHAudio开发音频会话功能(C/C++)](using-ohaudio-for-session.md)。

> **注意：**
> 
> 当AudioSession因超时而停用时，被其压低音量（Duck）的音频会触发恢复音量（Unduck）操作，被其暂停（Pause）的音频流会触发停止（Stop）操作。

### AudioSession停用事件

应用在使用AudioSession的过程中，推荐应用监听音频会话停用事件（AudioSessionDeactivatedEvent）。当AudioSession被停用（非主动停用）时，应用会收到此事件通知。应用可根据自身业务需求，做相应的处理，例如释放相应资源、重新激活AudioSession等。

音频会话停用事件（AudioSessionDeactivatedEvent）包含`AudioSessionDeactivatedReason`参数，用于标识会话停用的具体原因（如焦点被抢占或超时）。

1. 应用焦点被抢占（DEACTIVATED_LOWER_PRIORITY）：该应用所有的音频流持有的焦点全部被其他应用抢占时，AudioSession被同时停用。

2. 超时（DEACTIVATED_TIMEOUT）：若AudioSession处于激活状态，但该应用没有音频流在运行状态，则AudioSession会在规定时间后被超时停用。

### 开发步骤

1. 指定音频会话策略（AudioSessionStrategy）并激活音频会话。

   应用可以通过[activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12)接口激活当前应用的音频会话。

   应用在激活AudioSession时，需指定[音频会话策略](#音频会话策略)。策略中包含参数concurrencyMode，其类型为[AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12)，用于声明音频并发策略。

   <!-- @[activate_audio_session_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // 设置音频并发模式。
     let strategy: audio.AudioSessionStrategy = {
       concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
     };
   
     // 激活音频会话。
     audioSessionManager.activateAudioSession(strategy).then(() => {
       console.info('Succeeded in activating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

2. 查询音频会话是否已激活（可选）。

   应用可以通过[isAudioSessionActivated](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#isaudiosessionactivated12)接口检查当前应用的音频会话是否已激活。

   <!-- @[is_audio_session_activated](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 查询音频会话是否已激活。
   let isActivated = audioSessionManager.isAudioSessionActivated();
   ```

3. 监听音频会话停用事件（可选）。

   应用可以通过[on('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessiondeactivated12)接口监听音频会话停用事件（[AudioSessionDeactivatedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12)）。

   当AudioSession被停用（非主动停用）时，应用会收到音频会话停用事件（[AudioSessionDeactivatedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessiondeactivatedevent12)），其中包含音频会话停用原因（[AudioSessionDeactivatedReason](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosessiondeactivatedreason12)）。

   在收到AudioSessionDeactivatedEvent时，应用可根据自身业务需求，做相应的处理，例如释放相应资源、重新激活AudioSession等。

   应用可以通过[off('audioSessionDeactivated')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#offaudiosessiondeactivated12)接口取消监听音频会话停用事件。

   <!-- @[on_audio_session_deactivated](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   // ...
   
     // 监听音频会话停用事件。
     audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
       // ...
       console.info(`Succeeded in using on function. AudioSessionDeactivatedEvent: ${JSON.stringify(audioSessionDeactivatedEvent)}`);
     });
   ```

4. 停用音频会话。

   应用可以通过[deactivateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#deactivateaudiosession12)接口停用当前应用的音频会话。

   > **说明：**
   >
   > AudioSession停用后，应用新起的音频流将会按照默认焦点策略起流。

   <!-- @[deactivate_audio_session_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // 停用音频会话。
     // ...
     audioSessionManager.deactivateAudioSession().then(() => {
       console.info('Succeeded in deactivating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

### 完整示例

下面展示了音频流独立持有焦点的示例代码。

<!-- @[audio_session_v1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let audioManager = audio.getAudioManager();
// 创建音频会话管理器。
let audioSessionManager: audio.AudioSessionManager = audioManager.getSessionManager();
// ...
  // 设置音频并发模式。
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };

  // 激活音频会话。
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in activating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });

  // 查询音频会话是否已激活。
  let isActivated = audioSessionManager.isAudioSessionActivated();

  // 监听音频会话停用事件。
  audioSessionManager.on('audioSessionDeactivated', (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
    // ...
    console.info(`Succeeded in using on function. AudioSessionDeactivatedEvent: ${JSON.stringify(audioSessionDeactivatedEvent)}`);
  });

  if (isActivated) {
    // 音频会话激活后，应用在此处正常执行音频播放、暂停、停止、释放等操作即可。
  }
  // ...

  // 取消监听音频会话停用事件。
  audioSessionManager.off('audioSessionDeactivated');

  // ...
  // 停用音频会话。
  // ...
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('Succeeded in deactivating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

## 音频会话统一持有焦点

当应用需要启动多个音频流并保证流程连续性时，可通过AudioSession申请焦点，确保多音频流播放的连续性。

激活AudioSession时系统会根据应用选择的[音频会话场景](#音频会话场景)申请对应的音频焦点并由AudioSession持有该焦点，后续应用通过AudioRenderer启动的播放流将不再申请音频焦点。

使用OHAudio开发请参考：[使用OHAudio开发音频会话功能(C/C++)](using-ohaudio-for-session.md)。

典型使用场景如下：
- 在多个小视频滑动播放时，多个音频流频繁申请和释放焦点可能导致漏音。使用AudioSession申请一次焦点，可以避免中间多个音频流播放时频繁申请和释放焦点，从而防止漏音。
- 在VoIP通话场景下，可能需要启动铃声流、录音流和播放流，这些音频流的焦点优先级不同，部分音频流可能被其他应用的音频流中断。为了保持业务体验的连续性，可以使用AudioSession申请焦点，避免音频流被中断。
- 应用使用播放器的SDK播放音频流，不持有AudioRenderer对象，但希望监听焦点变化。

> **注意：**
>
> - AudioSession申请的焦点是应用级别的，如果应用内部包含不同的模块，各个模块间要做好协调处理，避免其中一个模块使用AudioSession申请了焦点，另一个模块的音频流被AudioSession的焦点管控而产生非预期的效果。
> - 通过AudioSession申请焦点，仅对播放流有效，对录音流及部分播放音频流（如STREAM_USAGE_ALARM、STREAM_USAGE_NOTIFICATION、STREAM_USAGE_ACCESSIBILITY等）无效。
> - 在AudioSession激活过程中，如果动态修改AudioSessionScene，需要重新调用activateAudioSession才能生效。
> - 通过AudioSession申请焦点后，焦点由AudioSession持有。应用当前播放场景结束后，需要主动停用AudioSession才会释放焦点。避免出现播放流停止后，焦点未释放导致的焦点异常持有。

### 音频会话场景

音频会话统一持有焦点时，系统提供了三种音频会话场景。激活AudioSession前需要先通过[setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20)设置对应的音频会话场景，后续激活时系统会根据应用选择的音频会话场景申请对应的音频焦点。

| 名称                   | 值 | 说明      |
| :--------------------- |:--|:--------|
| AUDIO_SESSION_SCENE_MEDIA | 0 | 媒体音频会话场景。     |
| AUDIO_SESSION_SCENE_GAME | 1 | 游戏音频会话场景。     |
| AUDIO_SESSION_SCENE_VOICE_COMMUNICATION  | 2 | VoIP语音通话音频会话场景。 |

### 监听AudioSession焦点和状态变化事件

AudioSession申请的焦点和AudioRenderer申请的焦点是同等地位。

应用可以通过[on('audioSessionStateChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessionstatechanged20)来监听AudioSession的焦点和状态变化。为了维持应用和系统的状态一致性，确保良好的用户体验，应用应监听AudioSession焦点状态事件，并在焦点变化时做出必要响应。

[on('audioSessionStateChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessionstatechanged20)包含了[AudioSession停用事件](#audiosession停用事件)的信息，当使用[音频会话统一持有焦点](#音频会话统一持有焦点)的方式时无需再额外监听音频会话停用事件（AudioSessionDeactivatedEvent）。

> **说明：**
>
> 如果应用同时注册了AudioRenderer的焦点事件监听，需要注意以下两点：
> - 应用会收到AudioSession焦点状态变化和AudioRenderer焦点变化的回调（[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)），根据需要处理这些回调即可。
> - 当AudioSession的焦点由暂停转为恢复时，系统仅向AudioSession发送焦点恢复事件，不会同步向AudioRenderer发送该事件。此时应用如需恢复播放，必须按以下顺序操作：
>    1. 调用[setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20)设置对应的音频会话场景。
>    2. 调用[activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12)激活AudioSession。
>    3. 调用[start](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#start8)恢复播放。

### 开发步骤

1. 指定音频会话场景（AudioSessionScene）和策略（AudioSessionStrategy）并激活音频会话。

   应用通过AudioSession申请焦点。首先要调用接口[setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20)设置场景参数，然后调用[activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12)接口激活AudioSession。激活AudioSession时系统会根据应用选择的音频会话场景申请对应的音频焦点。

   > **说明：**
   >
   > - 激活AudioSession时系统会根据应用选择的音频会话场景申请对应的音频焦点，后续应用通过AudioRenderer启动的播放流不再申请音频焦点。
   > - 如果激活AudioSession时应用已存在启动的音频播放流，系统会释放该音频播放流持有的焦点，并由AudioSession统一管理。

   <!-- @[activate_audio_session_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // 应用根据业务场景设置适合自己的音频会话场景，激活AudioSession时，系统会根据应用选择的音频会话场景申请对应的音频焦点。
     audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);
     // ...
   
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
   ```

2. 查询音频会话是否已激活（可选）。

   应用可以通过[isAudioSessionActivated](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#isaudiosessionactivated12)接口检查当前应用的音频会话是否已激活。

   <!-- @[is_audio_session_activated](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 查询音频会话是否已激活。
   let isActivated = audioSessionManager.isAudioSessionActivated();
   ```

3. 监听AudioSession焦点状态变化事件。

   应用可以通过[on('audioSessionStateChanged')](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#onaudiosessionstatechanged20)来监听AudioSession的焦点和状态变化。

   <!-- @[on_audio_session_state_changed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->  
   
   ``` TypeScript
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // 监听AudioSession焦点和状态变化事件。
     let audioSessionStateChangedCallback = (audioSessionStateChangedEvent: audio.AudioSessionStateChangedEvent) => {
       // ...
       console.info(`hint of audioSessionStateChanged: ${audioSessionStateChangedEvent.stateChangeHint} `);
   
       switch (audioSessionStateChangedEvent.stateChangeHint) {
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE:
           // 此分支表示系统已将音频流暂停，应用需切换至音频暂停状态。
           // 临时失去焦点：AudioSession会停用并释放焦点，同时停止应用所有音频流的播放。因此，当应用收到Resume回调后，需要重新激活AudioSession并恢复需要继续播放的音频流。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_RESUME:
           // 此分支表示系统解除AudioSession焦点的暂停操作。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_STOP:
           // 此分支表示系统已将音频流停止（永久失去焦点），为保持状态一致，应用需切换至音频暂停状态。
           // 永久失去焦点：AudioSession会停用并释放焦点，同时停止应用所有音频流的播放。后续不会再收到音频焦点事件，恢复播放需用户主动触发。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP:
           // 此分支表示由于长时间无音频流播放，系统已将AudioSession停止（永久失去焦点），应用需切换至音频停止状态。
           // 永久失去焦点：后续不会再收到音频焦点事件，恢复播放需用户主动触发。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
           // 此分支表示系统已将应用所有播放音频流音量降低（默认降到正常音量的20%）。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
           // 此分支表示系统已将应用所有播放音频流音量恢复正常。
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE_SUGGESTION:
           // 此分支表示其他应用开始播放非混音音频，系统可自行决定是否静音。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE_SUGGESTION:
           // 此分支表示其他应用的非混音音频播放结束，系统可自行决定是否取消静音。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE:
           // 此分支表示系统已将应用所有播放音频流静音。
           break;
         case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE:
           // 此分支表示系统已将应用所有播放音频流解除静音。
           break;           
         default:
           break;
       }
     };
   
     audioSessionManager.on('audioSessionStateChanged', audioSessionStateChangedCallback);
   ```

4. 停用音频会话。

   应用可以通过[deactivateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#deactivateaudiosession12)接口停用当前应用的音频会话。

   > **说明：**
   >
   > 停用AudioSession时系统会释放AudioSession申请的焦点，并停用该应用正在播放的所有音频流。

   <!-- @[deactivate_audio_session_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->  
   
   ``` TypeScript
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
     // 停用AudioSession，即释放焦点并停用该应用正在播放的所有音频流。
     audioSessionManager.deactivateAudioSession().then(() => {
       console.info('Succeeded in deactivating audio session.');
       // ...
     }).catch((err: BusinessError) => {
       console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
       // ...
     });
   ```

### 完整示例

下面展示了音频会话统一持有焦点的示例代码。

<!-- @[audio_session_v2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  // 应用根据业务场景设置适合自己的音频会话场景，激活AudioSession时，系统会根据应用选择的音频会话场景申请对应的音频焦点。
  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);
  // ...

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

  // 监听AudioSession焦点和状态变化事件。
  let audioSessionStateChangedCallback = (audioSessionStateChangedEvent: audio.AudioSessionStateChangedEvent) => {
    // ...
    console.info(`hint of audioSessionStateChanged: ${audioSessionStateChangedEvent.stateChangeHint} `);

    switch (audioSessionStateChangedEvent.stateChangeHint) {
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE:
        // 此分支表示系统已将音频流暂停，应用需切换至音频暂停状态。
        // 临时失去焦点：AudioSession会停用并释放焦点，同时停止应用所有音频流的播放。因此，当应用收到Resume回调后，需要重新激活AudioSession并恢复需要继续播放的音频流。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_RESUME:
        // 此分支表示系统解除AudioSession焦点的暂停操作。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_STOP:
        // 此分支表示系统已将音频流停止（永久失去焦点），为保持状态一致，应用需切换至音频暂停状态。
        // 永久失去焦点：AudioSession会停用并释放焦点，同时停止应用所有音频流的播放。后续不会再收到音频焦点事件，恢复播放需用户主动触发。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP:
        // 此分支表示由于长时间无音频流播放，系统已将AudioSession停止（永久失去焦点），应用需切换至音频停止状态。
        // 永久失去焦点：后续不会再收到音频焦点事件，恢复播放需用户主动触发。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
        // 此分支表示系统已将应用所有播放音频流音量降低（默认降到正常音量的20%）。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
        // 此分支表示系统已将应用所有播放音频流音量恢复正常。
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE_SUGGESTION:
        // 此分支表示其他应用开始播放非混音音频，系统可自行决定是否静音。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE_SUGGESTION:
        // 此分支表示其他应用的非混音音频播放结束，系统可自行决定是否取消静音。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_MUTE:
        // 此分支表示系统已将应用所有播放音频流静音。
        break;
      case audio.AudioSessionStateChangeHint.AUDIO_SESSION_STATE_CHANGE_HINT_UNMUTE:
        // 此分支表示系统已将应用所有播放音频流解除静音。
        break;        
      default:
        break;
    }
  };

  audioSessionManager.on('audioSessionStateChanged', audioSessionStateChangedCallback);

  // 查询音频会话是否已激活。
  let isActivated = audioSessionManager.isAudioSessionActivated();

  if (isActivated) {
    // 音频会话激活后，应用在此处正常执行音频播放、暂停、停止、释放等操作即可。
    // 根据实际业务，应用可以启动多个AudioRenderer音频播放流。此处启动的音频播放流不再持有焦点，统一由AudioSession管理。
    // 如果存在多条音频流同时播放，需要特别注意AudioSession停用时机（停用AudioSession时会同时释放应用所有音频播放流）。
  }
  // ...

  // 业务结束，取消监听AudioSession焦点和状态变化事件。
  audioSessionManager.off('audioSessionStateChanged');
  // ...

  // 停用AudioSession，即释放焦点并停用该应用正在播放的所有音频流。
  audioSessionManager.deactivateAudioSession().then(() => {
    console.info('Succeeded in deactivating audio session.');
    // ...
  }).catch((err: BusinessError) => {
    console.error(`Failed to deactivate audio session. Code: ${err.code}, message: ${err.message}`);
    // ...
  });
```

## 设置会话级录音流静音提示

从API version 24开始，当应用已在业务侧将当前音频会话内的录音流静音时，可以调用[setCapturerMuteHint](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setcapturermutehint24)接口将该状态上报给系统音频模块，系统音频模块会基于上报的状态调整策略以降低功耗。注意，此功能当前仅在部分PC/2in1设备上生效。该接口不会实际触发静音，也不会对录音数据做静音处理。它只是告知系统音频模块，应用已将当前音频会话内的录音流静音。应用仍需自行处理录音数据，例如不发送采集数据或发送静音数据。

该接口仅允许在当前音频会话存在运行中的录音流时调用，否则会返回错误码`6800103`。若某条录音流同时调用了流级静音提示接口[AudioCapturer.setMuteHint](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setmutehint24)和会话级静音提示接口，流级设置优先级更高，以流级设置值为准。因此，当应用内多条录音流的静音状态一致时，可以使用会话级接口统一上报；当不同录音流静音状态不一致时，建议对具体录音流使用流级接口。若为了调用会话级接口而创建Mic音频源录音流，需要申请麦克风权限`ohos.permission.MICROPHONE`。当前未提供系统查询接口，如需在界面展示静音提示状态，应用需要自行维护最近一次设置成功的状态。以下示例中，`muteHint`为`true`表示上报静音提示，`false`表示解除静音提示。

<!-- @[set_capturer_mute_hint](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
try {
  await audioSessionManager.setCapturerMuteHint(muteHint);
  console.info(`setCapturerMuteHint ${muteHint} success.`);
  // ...
} catch (err) {
  let error = err as BusinessError;
  console.error(`setCapturerMuteHint ${muteHint} failed. Code: ${error.code}, message: ${error.message}`);
  // ...
}
```

## 启用混音播放下静音建议通知

从API version 23开始，当本应用在并发模式为CONCURRENCY_MIX_WITH_OTHERS下进行播放时，如果有其他应用的音频同时播放，此时两者会混合播放。部分场景下（如游戏或广播），应用可以通过启用静音建议通知，以给用户提供更好的体验。

启用静音建议通知后，本应用播放音频的同时，其他应用播放了不可与本应用并发播放的音频，本应用会收到静音建议通知，此时本应用可以选择不做处理，让本应用和其他应用进行并发播放；也可以选择将自身静音播放，让其他应用单独播放音频。

启用混音播放下静音建议通知，需要先调用接口[setAudioSessionScene](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionscene20)设置场景参数，并调用[enableMuteSuggestionWhenMixWithOthers](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#enablemutesuggestionwhenmixwithothers23)开启功能，同时订阅音频会话状态更改事件[AudioSessionStateChangedEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#audiosessionstatechangedevent20)，最后调用[activateAudioSession](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#activateaudiosession12)接口激活AudioSession。启用静音建议通知的前提是[AudioConcurrencyMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audioconcurrencymode12)模式必须为CONCURRENCY_MIX_WITH_OTHERS。

<!-- @[enable_mute_suggestion](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  // 应用根据业务场景设置适合自己的音频会话场景，激活AudioSession时，系统会根据应用选择的音频会话场景申请对应的音频焦点。
  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);

  // 本接口必须在激活音频会话前调用才会生效。
  audioSessionManager.enableMuteSuggestionWhenMixWithOthers(true);

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
```

## 设置音频会话行为

从API version 24开始，应用可以通过[setAudioSessionBehavior](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionbehavior24)接口设置音频会话行为参数，在特定场景下获得更优的音频焦点体验。

在用户观看直播的场景中，当其他应用启动音频流（如使用键盘录音转文字）打断直播时，会导致直播的音频和画面暂停，影响用户的观看体验。直播应用可以通过设置[AudioSessionBehaviorFlags](../../reference/apis-audio-kit/arkts-apis-audio-e.md#audiosessionbehaviorflags24).MUTE_WHEN_INTERRUPTED会话行为，使直播在被打断时保持静音播放而非暂停，避免画面中断。

如果本应用未使用音频会话管理，也可以针对单条音频流设置独立的音频会话行为。对于播放流，详情请参考[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setindependentaudiosessionstrategy24)。对于录音流，详情请参考[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24)。

<!-- @[set_session_behavior](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

  // 应用根据业务场景设置适合自己的音频会话场景，激活AudioSession时，系统会根据应用选择的音频会话场景申请对应的音频焦点。
  audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);

  // 本接口应在激活音频会话前调用。
  // 若音频会话在激活状态时调用此接口后，必须重新激活音频会话使其生效。
  let behavior = audio.AudioSessionBehaviorFlags.MUTE_WHEN_INTERRUPTED;
  audioSessionManager.setAudioSessionBehavior(behavior);

  // 设置音频会话策略。
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_PAUSE_OTHERS
  };

  // 激活AudioSession。
  audioSessionManager.activateAudioSession(strategy).then(() => {
    console.info('Succeeded in activating audio session.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to activate audio session. Code: ${err.code}, message: ${err.message}`);
  });
```
