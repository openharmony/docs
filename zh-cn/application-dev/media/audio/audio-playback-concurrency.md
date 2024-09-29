# 处理音频焦点事件

## 音频打断策略

多音频并发，即多个音频流同时播放。此场景下，如果系统不加管控，会造成多个音频流混音播放，容易让用户感到嘈杂，造成不好的用户体验。为了解决这个问题，系统预设了音频打断策略，对多音频播放的并发进行管控，只有持有音频焦点的音频流才可以正常播放，避免多个音频流无序并发播放的现象出现。

当应用开始播放音频时，系统首先为相应的音频流申请音频焦点，获得焦点的音频流可以播放；若焦点申请被拒绝，则不能播放。在音频流播放的过程中，若被其他音频流打断，则会失去音频焦点。当音频流失去音频焦点时，只能暂停播放。在应用播放音频的过程中，这些动作均由系统自行完成，无需应用主动触发。但为了维持应用和系统的状态一致性，保证良好的用户体验，推荐应用[监听音频打断事件](#监听音频打断事件)，并在收到音频打断事件（[InterruptEvent](../../reference/apis-audio-kit/js-apis-audio.md#interruptevent9)）时做出相应处理。

为满足应用对多音频并发策略的不同需求，音频打断策略预设了两种焦点模式，针对同一应用创建的多个音频流，应用可通过设置[焦点模式](#焦点模式)，选择由应用自主管控或由系统统一管控。

音频打断策略决定了应该对音频流采取何种操作，如暂停播放、继续播放、降低音量播放、恢复音量播放等，这些操作可能由系统或应用来执行。音频打断策略预置了两种[打断类型](#打断类型)，用于区分音频打断事件（InterruptEvent）的执行者。

### 焦点模式

音频打断策略预设了两种焦点模式（[InterruptMode](../../reference/apis-audio-kit/js-apis-audio.md#interruptmode9)）：

- 共享焦点模式（SHARE_MODE）：由同一应用创建的多个音频流，共享一个音频焦点。这些音频流之间的并发规则由应用自主决定，音频打断策略不会介入。当其他应用创建的音频流与该应用的音频流并发播放时，才会触发音频打断策略的管控。

- 独立焦点模式（INDEPENDENT_MODE）：应用创建的每一个音频流均会独立拥有一个音频焦点，当多个音频流并发播放时，会触发音频打断策略的管控。

应用可以按需选择合适的焦点模式，在创建音频流时，系统默认采用共享焦点模式，应用可主动设置所需的模式。

设置焦点模式的方法：

- 若[使用AVPlayer开发音频播放功能(ArkTS)](../media/using-avplayer-for-playback.md)，则可以通过修改AVPlayer的[audioInterruptMode](../../reference/apis-media-kit/js-apis-media.md#avplayer9)属性进行设置。

- 若[使用AVPlayer开发音频播放功能(C/C++)](../media/using-ndk-avplayer-for-playerback.md)，则可以调用AVPlayer的[OH_AVPlayer_SetAudioInterruptMode](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudiointerruptmode)函数进行设置。

- 若[使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)，则可以调用AudioRenderer的[setInterruptMode](../../reference/apis-audio-kit/js-apis-audio.md#setinterruptmode9)函数进行设置。

- 若[使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)，则可以调用[OH_AudioStreamBuilder_SetRendererInterruptMode](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setrendererinterruptmode)函数进行设置。


### 打断类型

音频打断策略（包括两种焦点模式）决定了应该对各个音频流采取何种操作，如暂停播放、继续播放、降低音量播放、恢复音量播放等。而针对这些操作的执行过程，根据执行者的不同，可以分为两种打断类型（[InterruptForceType](../../reference/apis-audio-kit/js-apis-audio.md#interruptforcetype9)）：

- 强制打断类型（INTERRUPT_FORCE）：由系统进行操作，强制打断音频播放。

- 共享打断类型（INTERRUPT_SHARE）：由应用进行操作，可以选择打断或忽略。

对于音频打断策略的执行，系统默认采用强制打断类型（INTERRUPT_FORCE），应用无法更改。但对于一些策略（如继续播放等），系统无法强制执行，所以这两种打断类型均可能出现。应用可根据音频打断事件（InterruptEvent）的成员变量forceType的值，获取该事件采用的打断类型。

在应用播放音频的过程中，系统自动为音频流执行申请焦点、持有焦点、释放焦点等动作，当发生音频打断事件时，系统强制对音频流执行暂停、停止、降低音量、恢复音量等操作，并向应用发送音频打断事件（InterruptEvent）回调。由于系统会强制改变音频流状态，为了维持应用和系统的状态一致性，保证良好的用户体验，推荐应用[监听音频打断事件](#监听音频打断事件)，并在收到音频打断事件（InterruptEvent）时做出相应处理。

对于一些系统无法强制执行的操作（例如音频流继续播放的场景），会向应用发送包含了共享打断类型的音频打断事件，由应用自行执行相应操作，此时应用可以选择执行或忽略，系统不会干涉。

## 监听音频打断事件

在应用播放音频时，推荐应用监听音频打断事件，当音频打断事件发生时，系统会根据预设策略，对音频流做出相应的操作，并针对状态发生改变的音频流，向所属的应用发送音频打断事件。

应用收到音频打断事件后，需根据其内容提示，做出相应的处理，避免出现应用状态与预期效果不一致的问题。

监听音频打断事件的方法：

- 若[使用AVPlayer开发音频播放功能(ArkTS)](../media/using-avplayer-for-playback.md)，则可以调用AVPlayer的[on('audioInterrupt')](../../reference/apis-media-kit/js-apis-media.md#onaudiointerrupt9)函数进行监听，当收到音频打断事件[InterruptEvent](../../reference/apis-audio-kit/js-apis-audio.md#interruptevent9)时，应用需根据其内容，做出相应的调整。

- 若[使用AVPlayer开发音频播放功能(C/C++)](../media/using-ndk-avplayer-for-playerback.md)，则可以调用AVPlayer的[OH_AVPlayer_SetOnInfoCallback()](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setoninfocallback)接口注册监听焦点回调事件，当收到音频打断事件[OH_AVPlayerOnInfoCallback](../../reference/apis-media-kit/_a_v_player.md#oh_avplayeroninfocallback)时，应用需根据其内容，做出相应的调整。

- 若[使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)，则可以调用AudioRenderer的[on('audioInterrupt')](../../reference/apis-audio-kit/js-apis-audio.md#onaudiointerrupt9)函数进行监听，当收到音频打断事件[InterruptEvent](../../reference/apis-audio-kit/js-apis-audio.md#interruptevent9)时，应用需根据其内容，做出相应的调整。

- 若[使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)，则可以调用[OH_AudioStreamBuilder_SetRendererCallback](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setrenderercallback)接口注册监听焦点回调事件，当收到音频打断事件[OH_AudioRenderer_OnInterruptEvent](../../reference/apis-audio-kit/_o_h___audio_renderer___callbacks___struct.md#oh_audiorenderer_oninterruptevent)时，应用需根据其内容，做出相应的调整。

为了带给用户更好的体验，针对不同的音频打断事件内容，应用需要做出相应的处理操作。此处以使用AudioRenderer开发音频播放功能为例，展示推荐应用采取的处理方法，提供伪代码供开发者参考（若使用AVPlayer开发音频播放功能或者使用OHAudio接口开发音频播放器功能，处理方法类似），具体的代码实现，开发者可结合实际情况编写，处理方法也可自行调整。

```ts
import { audio } from '@kit.AudioKit';  // 导入audio模块
import { BusinessError } from '@kit.BasicServicesKit'; // 导入BusinessError

let isPlay: boolean; // 是否正在播放，实际开发中，对应与音频播放状态相关的模块
let isDucked: boolean; //是否降低音量，实际开发中，对应与音频音量相关的模块
let started: boolean; // 标识符，记录“开始播放（start）”操作是否成功

async function onAudioInterrupt(): Promise<void> {
  // 此处以使用AudioRenderer开发音频播放功能举例，变量audioRenderer即为播放时创建的AudioRenderer实例。
  audioRenderer.on('audioInterrupt', async(interruptEvent: audio.InterruptEvent) => {
    // 在发生音频打断事件时，audioRenderer收到interruptEvent回调，此处根据其内容做相应处理
    // 1. 可选：读取interruptEvent.forceType的类型，判断系统是否已强制执行相应操作。
    // 注：默认焦点策略下，INTERRUPT_HINT_RESUME为INTERRUPT_SHARE类型，其余hintType均为INTERRUPT_FORCE类型。因此对forceType可不做判断。
    // 2. 必选：读取interruptEvent.hintType的类型，做出相应的处理。
    if (interruptEvent.forceType === audio.InterruptForceType.INTERRUPT_FORCE) {
      // 强制打断类型（INTERRUPT_FORCE）：音频相关处理已由系统执行，应用需更新自身状态，做相应调整
       switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
          // 此分支表示系统已将音频流暂停（临时失去焦点），为保持状态一致，应用需切换至音频暂停状态
          // 临时失去焦点：待其他音频流释放音频焦点后，本音频流会收到resume对应的音频打断事件，到时可自行继续播放
          isPlay = false; // 此句为简化处理，代表应用切换至音频暂停状态的若干操作
          break;
        case audio.InterruptHint.INTERRUPT_HINT_STOP:
          // 此分支表示系统已将音频流停止（永久失去焦点），为保持状态一致，应用需切换至音频暂停状态
          // 永久失去焦点：后续不会再收到任何音频打断事件，若想恢复播放，需要用户主动触发。
          isPlay = false; // 此句为简化处理，代表应用切换至音频暂停状态的若干操作
          break;
        case audio.InterruptHint.INTERRUPT_HINT_DUCK:
          // 此分支表示系统已将音频音量降低（默认降到正常音量的20%）
          isDucked = true; // 此句为简化处理，代表应用切换至降低音量播放状态的若干操作
          break;
        case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
          // 此分支表示系统已将音频音量恢复正常
          isDucked = false; // 此句为简化处理，代表应用切换至正常音量播放状态的若干操作
          break;
        default:
          break;
      }
    } else if (interruptEvent.forceType === audio.InterruptForceType.INTERRUPT_SHARE) {
      // 共享打断类型（INTERRUPT_SHARE）：应用可自主选择执行相关操作或忽略音频打断事件
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_RESUME:
          // 此分支表示临时失去焦点后被暂停的音频流此时可以继续播放，建议应用继续播放，切换至音频播放状态
          // 若应用此时不想继续播放，可以忽略此音频打断事件，不进行处理即可
          // 继续播放，此处主动执行start()，以标识符变量started记录start()的执行结果
          await audioRenderer.start().then(() => {
            started = true; // start()执行成功
          }).catch((err: BusinessError) => {
            started = false; // start()执行失败
          });
          // 若start()执行成功，则切换至音频播放状态
          if (started) {
            isPlay = true; // 此句为简化处理，代表应用切换至音频播放状态的若干操作
          } else {
            // 音频继续播放执行失败
          }
          break;
        default:
          break;
      }
   }
  });
}
```

## 典型场景

以下列举一些典型的焦点适配场景。

| 先播应用类型 | 推荐流类型         | 后播应用类型 | 推荐流类型            | 推荐体验                                                     | 适配方案                                                     |
| ------------ | ------------------ | ------------ | --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 视频         | STREAM_USAGE_MOVIE | 闹铃         | STREAM_USAGE_ALARM    | 闹铃响起后，视频暂停播放；闹钟结束后，视频继续播放。         | 注册焦点事件监听，接收到`INTERRUPT_HINT_PAUSE`事件时，直接暂停视频播放，并更新UI界面。当闹铃结束后，视频应用接收到`INTERRUPT_HINT_RESUME`事件，重新启动播放。 |
| 音乐         | STREAM_USAGE_MUSIC | 电话铃声     | STREAM_USAGE_RINGTONE | 电话响铃后，音乐暂停播放；不接通或者接通再挂断后，音乐恢复播放。 | 注册焦点事件监听，接收到`INTERRUPT_HINT_PAUSE`事件时，直接暂停音乐播放，并更新UI界面。当电话结束后，视频应用接收到`INTERRUPT_HINT_RESUME`事件，重新启动播放。 |
| 音乐         | STREAM_USAGE_MUSIC | 音乐         | STREAM_USAGE_MUSIC    | 后播音乐正常播放，先播音乐应用停止播放，UI变成停止播放状态。 | 先播应用注册焦点事件监听，接收到`INTERRUPT_HINT_STOP`事件时，停止音乐播放，并更新UI界面。 |
