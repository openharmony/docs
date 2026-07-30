# 音频焦点介绍
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

在应用播放或录制声音时，常出现与其他音频流的并发或中断情况，这对用户体验构成显著影响。例如，当应用启动视频播放时，若后台正在播放音乐，用户会期望音乐能自动暂停，以确保视频音频优先播放，这正是音频焦点功能的体现。对于涉及音频服务的应用而言，妥善地管理音频焦点非常重要，它可以显著提升用户的音频体验。

本文档将介绍系统的音频焦点策略，以及应对焦点变化的方法。同时，系统提供了[音频会话管理](audio-session-management.md)机制，允许应用自定义其音频流的焦点策略。

## 音频焦点

系统预设了默认的[音频焦点策略](#音频焦点策略)，根据音频流的类型及启动的先后顺序，对所有播放和录制音频流进行统一管理。

在启动播放或录制功能时，系统会自动为相应的音频流[申请音频焦点](#申请音频焦点)；而在播放或录制结束后，系统也会自动[释放音频焦点](#释放音频焦点)。在播放或录制的过程中，可能会因其他音频流的介入而失去焦点，此时，应用需依据焦点变化采取相应措施[处理音频焦点变化](#处理音频焦点变化)。

对于应用而言，为了确保为用户提供优质的音频焦点体验，应当注意以下几点：

- 在启动播放操作前，应根据音频的具体用途[选择合适的播放流类型](using-right-streamusage-for-playback.md)，即准确设置[StreamUsage](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)。

- 在播放或录制的过程中，需通过监听音频焦点来[处理音频焦点变化](#处理音频焦点变化)事件，并在接收到音频焦点中断事件（[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)）时，采取相应的处理措施。

- 如果应用程序有意主动管理音频焦点，可使用[音频会话管理](audio-session-management.md)相关的接口进行操作。

### 申请音频焦点

**当应用开始播放或录制音频时，系统将自动为相应的音频流申请音频焦点。**

例如，应用[使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)，当调用AudioRenderer的[start](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#start8)时，系统会自动为应用请求音频焦点。

若音频焦点请求成功，音频流将正常启动；反之，若音频焦点请求被拒绝，音频流将无法开始播放或录制。

建议应用主动通过监听音频焦点来[处理音频焦点变化](#处理音频焦点变化)事件，一旦音频焦点请求被拒绝，应用将接收到音频焦点事件（[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)）。

如果应用希望只申请一次焦点，连续播放多条音频流不被中断，可使用[音频会话管理](audio-session-management.md)相关的接口进行操作。

**特殊场景：**

1. **短音播放**：若应用[使用SoundPool播放短音频(ArkTS)](../media/using-soundpool-for-playback.md)，且[StreamUsage](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)指定为Music、Movie、AudioBook等类型播放短音时，则申请焦点时默认为并发模式，不会影响其他音频。

2. **静音播放**：若应用以静音状态开始播放音频（或视频），并且希望静音阶段不影响其他音频，当后续解除静音的时候，再以正常策略申请音频焦点，则可以调用静音并发播放模式的相关接口。具体可参考：

   - [使用AVPlayer播放音频(ArkTS)](../media/using-avplayer-for-playback.md)，可以调用[setMediaMuted](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#setmediamuted12)函数。

   - [使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)，可调用[setSilentModeAndMixWithOthers](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setsilentmodeandmixwithothers12)函数。

   - [使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)，可调用[OH_AudioRenderer_SetSilentModeAndMixWithOthers](../../reference/apis-audio-kit/capi-native-audiorenderer-h.md#oh_audiorenderer_setsilentmodeandmixwithothers)函数。

### 释放音频焦点

**当应用结束播放或录制音频时，系统会自动为相应的音频流释放音频焦点。**

例如，应用[使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)，当调用AudioRenderer的[pause](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#pause8)、[stop](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#stop8)、[release](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#release8)等时，系统会为其释放音频焦点。

当音频流释放音频焦点时，若存在受其影响的其他音频流（如音量被调低或被暂停的流），将触发恢复操作。

如果应用不希望在音频流停止时立即释放音频焦点，可使用[音频会话管理](audio-session-management.md)的相关接口，实现音频焦点释放的延迟效果。

如果应用通过激活[音频会话管理](audio-session-management.md)申请过焦点，需要结束AudioSession以释放焦点。

### 音频焦点策略

当音频流申请或释放音频焦点时，系统依据音频焦点策略，对所有音频流（包括播放和录制）实施焦点管理，决定哪些音频流可正常运行，哪些需被打断或执行其他操作。

系统预设的默认音频焦点策略，主要依据音频流类型（即播放流的[StreamUsage](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)和录制流的[SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8)）及音频流启动的顺序进行决策。

为防止焦点变化不符合预期，应用在启动播放前，应根据音频流的用途准确设置StreamUsage。关于各类型的详细说明，请参考[选择合适的播放流类型](using-right-streamusage-for-playback.md)。

常见的音频焦点场景示例如下：

- 开始播放Movie音频流时，将导致正在播放的Music音频流暂停，但Movie播放停止后，Music不会收到恢复播放的通知。
- 开始Navigation音频流时，会自动降低正在播放的Music音频流音量，Navigation停止后，Music音量将恢复至原样。
- Music音频流与Game音频流可并发混音播放，相互之间不会影响音量或播放状态。
- 开始播放VoiceCommunication音频流时，将暂停正在播放的Music音频流，VoiceCommunication停止后，Music将收到恢复播放的通知。
- 开始录制VoiceMessage音频流时，Music音频流会被暂停，VoiceMessage录制停止后，Music将收到恢复播放的通知。

若默认的音频焦点策略无法满足特定场景的需求，应用程序可利用[音频会话管理](audio-session-management.md)，调整本应用音频流所采用的音频焦点策略。

### 处理音频焦点变化

在应用播放或录制音频的过程中，若有其他音频流申请焦点，系统会根据[音频焦点策略](#音频焦点策略)进行焦点处理。若判定本音频流的焦点有变化，需要执行暂停、继续、降低音量、恢复音量等操作，则系统会自动执行一些必要的操作，并通过音频焦点事件（[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)）通知应用。

因此，为了维持应用和系统的状态一致性，保证良好的用户体验，推荐应用监听音频焦点事件，并在焦点发生变化时，根据[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)做出必要的响应。

**使用不同方式开发时，如何监听音频焦点事件：**

- 若[使用AVPlayer播放音频(ArkTS)](../media/using-avplayer-for-playback.md)，可以调用[on('audioInterrupt')](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#onaudiointerrupt9)接口，监听音频焦点事件[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)。

- 若[使用AVPlayer播放音频(C/C++)](../media/using-ndk-avplayer-for-playback.md)，可以调用[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setoninfocallback)接口，监听音频焦点事件[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/capi-avplayer-base-h.md#oh_avplayeroninfocallback)。

- 若[使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)，可以调用[on('audioInterrupt')](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#onaudiointerrupt9)接口，监听音频焦点事件[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)。

- 若[使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)，可以调用[OH_AudioStreamBuilder_SetRendererCallback](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setrenderercallback)接口，监听音频焦点事件[OH_AudioRenderer_OnInterruptEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiorenderer-callbacks-struct.md#oh_audiorenderer_oninterruptevent)。

- 若[使用AudioCapturer开发音频录制功能(ArkTS)](using-audiocapturer-for-recording.md)，可以调用[on('audioInterrupt')](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#onaudiointerrupt10)接口，监听音频焦点事件[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)。

- 若[使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)，可以调用[OH_AudioStreamBuilder_SetCapturerCallback](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setcapturercallback)接口，监听音频焦点事件[OH_AudioCapturer_OnInterruptEvent](../../reference/apis-audio-kit/capi-ohaudio-oh-audiocapturer-callbacks-struct.md#oh_audiocapturer_oninterruptevent)。

应用在收到音频焦点事件（[InterruptEvent](../../reference/apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)）时，需要根据其中信息，做出相应的处理，以保持应用与系统状态一致，带给用户良好的音频体验。

在音频焦点事件中，应用应重点关注两个信息：打断类型（InterruptForceType）和打断提示（InterruptHint）。

- 打断类型（[InterruptForceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#interruptforcetype9)）：

  InterruptForceType参数提示应用该焦点变化是否已由系统强制操作：

  - 强制打断类型（INTERRUPT_FORCE）：由系统进行操作，强制执行。应用收到打断提示后无需再调用系统相关接口，只需做一些必要的处理，例如更新状态、更新界面显示等。

  - 共享打断类型（INTERRUPT_SHARE）：由应用进行操作，应用可以选择响应或忽略，系统不会干涉。

  系统默认优先采用强制打断类型（INTERRUPT_FORCE），应用无法更改。

  > **注意：**
  >
  > 对于一些系统无法强制执行的操作（例如INTERRUPT_HINT_RESUME），会采用共享打断类型（INTERRUPT_SHARE）。

- 打断提示（[InterruptHint](../../reference/apis-audio-kit/arkts-apis-audio-e.md#interrupthint)）：

  InterruptHint参数用于提示应用音频流的状态：

  - 继续（INTERRUPT_HINT_RESUME）：音频流可恢复播放或录制，仅在接收到PAUSE（暂停提示）事件后才会收到。

    此操作无法由系统强制执行，其对应的InterruptForceType一定为INTERRUPT_SHARE类型。

  - 暂停（INTERRUPT_HINT_PAUSE）：音频暂停，暂时失去音频焦点。后续待焦点可用时，会再收到INTERRUPT_HINT_RESUME。
  - 停止（INTERRUPT_HINT_STOP）：音频停止，彻底失去音频焦点。
  - 降低音量（INTERRUPT_HINT_DUCK）：音频降低音量播放，而不会停止。默认降低至正常音量的20%。
  - 恢复音量（INTERRUPT_HINT_UNDUCK）：音频恢复正常音量。

### 同应用内焦点管理

针对同一应用创建的多个音频流，应用可通过设置焦点模式（[InterruptMode](../../reference/apis-audio-kit/arkts-apis-audio-e.md#interruptmode9)），选择由应用自主管控，或由系统统一管理。

推荐使用共享焦点模式（SHARE_MODE），由应用自行管控各流的播放与恢复。

系统预设了两种焦点模式：

| 焦点模式 | 说明 | 同应用内焦点策略 |
|---------|------|-------------------|
| SHARE_MODE（默认，推荐） | 与同应用内其他SHARE_MODE流不触发焦点策略，应用自行管控；<br>与同应用内INDEPENDENT_MODE流触发焦点策略。 | 不触发焦点策略，应用自行决定各流的播放、暂停、停止等操作，系统不发送DUCK/PAUSE/STOP/RESUME事件。 |
| INDEPENDENT_MODE | 与同应用内所有流（无论SHARE_MODE或INDEPENDENT_MODE）均触发焦点策略。 | 触发焦点策略，按跨应用焦点策略管理 |

设置焦点模式的方法：

- 若[使用AVPlayer播放音频(ArkTS)](../media/using-avplayer-for-playback.md)，则可以通过修改AVPlayer的[audioInterruptMode](../../reference/apis-media-kit/arkts-apis-media-AVPlayer.md#属性)属性进行设置。

- 若[使用AVPlayer播放音频(C/C++)](../media/using-ndk-avplayer-for-playback.md)，则可以调用[OH_AVPlayer_SetAudioInterruptMode](../../reference/apis-media-kit/capi-avplayer-h.md#oh_avplayer_setaudiointerruptmode)函数进行设置。

- 若[使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)，则可以调用[setInterruptMode](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setinterruptmode9)函数进行设置。

- 若[使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)，则可以调用[OH_AudioStreamBuilder_SetRendererInterruptMode](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setrendererinterruptmode)函数进行设置。

同应用内常见焦点管理实践如下，同应用其他场景均可参考该实践自行进行各流的管控：

***实践：同应用内音乐与音乐互相打断***

流A播放音乐（STREAM_USAGE_MUSIC），流B播放音乐（STREAM_USAGE_MUSIC）。

推荐做法：采用默认焦点模式（SHARE_MODE），应用自行管控各流的播放与恢复——流B开始播放时，应用主动暂停流A；流B停止播放时，应用主动恢复流A。这就是PAUSE→RESUME策略，比INDEPENDENT_MODE的STOP（不恢复）更好。

<!-- @[toggle_stream_b](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioIntraAppFocusSample/entry/src/main/ets/pages/MusicVsMusicPage.ets) -->

INDEPENDENT_MODE下，音乐与音乐之间为STOP策略——后播的流会STOP前播的流，且前播的流不会收到RESUME，无法自动恢复。

### 典型场景

典型焦点的适配场景如下表所示。

| 先播放的音频类型       | 推荐流类型         | 后播放的音频类型 | 推荐流类型            | 推荐体验                                                     | 适配方案                                                     |
| ---------------- | ------------------ | ------------ | --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 音乐         | STREAM_USAGE_MUSIC | 音乐         | STREAM_USAGE_MUSIC    | 后播音乐正常播放，先播音乐停止播放，UI变成停止播放状态。 | 先播音乐应用注册焦点事件监听，接收到`INTERRUPT_HINT_STOP`事件时，停止音乐播放，并更新UI界面。 |
| 音乐         | STREAM_USAGE_MUSIC | 导航         | STREAM_USAGE_NAVIGATION    | 导航正常播放，音乐降低音量播放。<br>导航结束后，音乐恢复正常音量。 | 音乐应用注册焦点事件监听，接收到`INTERRUPT_HINT_DUCK`和`INTERRUPT_HINT_UNDUCK`事件时，可以选择更新UI界面。 |
| 视频           | STREAM_USAGE_MOVIE | 闹铃         | STREAM_USAGE_ALARM    | 闹铃响起后，视频暂停播放。<br>闹钟结束后，视频继续播放。         | 视频应用注册焦点事件监听。接收到`INTERRUPT_HINT_PAUSE`事件时，直接暂停视频播放，并更新UI界面。<br>当闹铃结束后，视频应用接收到`INTERRUPT_HINT_RESUME`事件，重新启动播放。 |
| 音乐         | STREAM_USAGE_MUSIC | 来电铃声     | STREAM_USAGE_RINGTONE | 开始响铃，音乐暂停播放。<br>不接通或者接通再挂断后，音乐恢复播放。 | 音乐应用注册焦点事件监听。接收到`INTERRUPT_HINT_PAUSE`事件时，直接暂停音乐播放，并更新UI界面。<br>当电话结束后，音频应用接收到`INTERRUPT_HINT_RESUME`事件，重新启动播放。 |
| 音乐         | STREAM_USAGE_MUSIC | VoIP通话     | STREAM_USAGE_VOICE_COMMUNICATION | 通话接通时，音乐暂停播放。<br>通话挂断后，音乐恢复播放。 | 音乐应用注册焦点事件监听。<br>接收到`INTERRUPT_HINT_PAUSE`事件时，直接暂停音乐播放，并更新UI界面。<br>当通话结束后，音乐应用接收到`INTERRUPT_HINT_RESUME`事件，重新启动播放。 |

**处理音频焦点示例:**

为了带给用户更好的音频体验，针对不同的音频焦点事件内容，应用需要做出相应的处理操作。此处以[使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)为例，展示推荐应用采取的处理方法，提供伪代码供开发者参考。

在监听音频播放焦点变化事件之前，需要先获取[AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiorenderer8)实例。若使用其他接口开发音频播放或音频录制功能，处理方法类似，具体的代码实现，开发者可结合实际情况编写，处理方法也可自行调整。

<!-- @[renderer_interrupt](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->  

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...

let isPlaying: boolean; // 是否正在播放，实际开发中，对应与音频播放状态相关的模块。
let isDucked: boolean; // 是否降低音量，实际开发中，对应与音频音量相关的模块。
let started: boolean; // 标识符，记录“开始播放（start）”操作是否成功。

async function onAudioInterrupt(): Promise<void> {
  if (audioRenderer == undefined) {
    return;
  }
  // 此处以使用AudioRenderer开发音频播放功能举例，变量audioRenderer即为播放时创建的AudioRenderer实例。
  audioRenderer.on('audioInterrupt', async(interruptEvent: audio.InterruptEvent) => {
    // ...
    // 在发生音频焦点变化时，audioRenderer收到interruptEvent回调，此处根据其内容做相应处理。
    // 1. 可选：读取interruptEvent.forceType的类型，判断系统是否已强制执行相应操作。
    // 注：默认焦点策略下，INTERRUPT_HINT_RESUME为INTERRUPT_SHARE类型，其余hintType均为INTERRUPT_FORCE类型。因此对forceType可不做判断。
    // 2. 必选：读取interruptEvent.hintType的类型，做出相应的处理。
    if (interruptEvent.forceType === audio.InterruptForceType.INTERRUPT_FORCE) {
      // 强制打断类型（INTERRUPT_FORCE）：音频相关处理已由系统执行，应用需更新自身状态，做相应调整。
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
          // 此分支表示系统已将音频流暂停（临时失去焦点），为保持状态一致，应用需切换至音频暂停状态。
          // 临时失去焦点：待其他音频流释放音频焦点后，本音频流会收到resume对应的音频焦点事件，到时可自行继续播放。
          isPlaying = false; // 此句为简化处理，代表应用切换至音频暂停状态的若干操作。
          break;
        case audio.InterruptHint.INTERRUPT_HINT_STOP:
          // 此分支表示系统已将音频流停止（永久失去焦点），为保持状态一致，应用需切换至音频暂停状态。
          // 永久失去焦点：后续不会再收到任何音频焦点事件，若想恢复播放，需要用户主动触发。
          isPlaying = false; // 此句为简化处理，代表应用切换至音频暂停状态的若干操作。
          break;
        case audio.InterruptHint.INTERRUPT_HINT_DUCK:
          // 此分支表示系统已将音频音量降低（默认降到正常音量的20%）。
          isDucked = true; // 此句为简化处理，代表应用切换至降低音量播放状态的若干操作。
          break;
        case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
          // 此分支表示系统已将音频音量恢复正常。
          isDucked = false; // 此句为简化处理，代表应用切换至正常音量播放状态的若干操作。
          break;
        default:
          break;
      }
    } else if (interruptEvent.forceType === audio.InterruptForceType.INTERRUPT_SHARE) {
      // 共享打断类型（INTERRUPT_SHARE）：应用可自主选择执行相关操作或忽略音频焦点事件。
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_RESUME:
          // 此分支表示临时失去焦点后被暂停的音频流此时可以继续播放，建议应用继续播放，切换至音频播放状态。
          // 若应用此时不想继续播放，可以忽略此音频焦点事件，不进行处理即可。
          // 继续播放，此处主动执行start()，以标识符变量started记录start()的执行结果。
          if (audioRenderer == undefined) {
            return;
          }
          try {
            await audioRenderer.start();
            started = true;
          } catch (err) {
            let error = err as BusinessError;
            console.error(`Failed to start audio renderer. Code: ${error.code}, message: ${error.message}`);
            started = false;
          }
          // 若start()执行成功，则切换至音频播放状态。
          if (started) {
            isPlaying = true; // 此句为简化处理，代表应用切换至音频播放状态的若干操作。
          } else {
            // 音频继续播放的操作执行失败。
          }
          break;
        default:
          break;
      }
    }
  });
}
```