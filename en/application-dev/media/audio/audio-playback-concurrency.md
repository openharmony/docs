# Processing Audio Interruption Events

## Audio Interruption Policy

If multiple audio streams are played at the same time, the user may feel uncomfortable or even painful. To address this issue, the system presets the audio interruption strategy so that only the audio stream holding audio focus can be played.

When an application attempts to play an audio, the system requests audio focus for the audio stream. The audio stream that gains the focus can be played. If the request is rejected, the audio stream cannot be played. If the audio stream is interrupted by another, it loses the focus and therefore the playback is paused. All these actions are automatically performed by the system and do not require additional operations on the application. However, to maintain state consistency between the application and the system and ensure good user experience, it is recommended that the application [listen for audio interruption events](#listening-for-audio-interruption-events) and perform the corresponding processing when receiving such an event (specified by [InterruptEvent](../../reference/apis-audio-kit/js-apis-audio.md#interruptevent9)).

The system presets two [audio interruption modes](#audio-interruption-mode) to specify whether audio concurrency is controlled by the application or system. You can choose a mode for every audio stream created by the application.

The audio interruption strategy determines the operations (for example, pause, resume, duck, or unduck) to be performed on the audio stream. These operations can be performed by the system or application. To distinguish the body that executes the operations, the [audio interruption type](#audio-interruption-type) is introduced, and two audio interruption types are preset.

### Audio Interruption Mode

Two audio interruption modes, specified by [InterruptMode](../../reference/apis-audio-kit/js-apis-audio.md#interruptmode9), are preset in the audio interruption strategy:

- **SHARE_MODE**: Multiple audio streams created by an application share one audio focus. The concurrency rules between these audio streams are determined by the application, without the use of the audio interruption strategy. However, if another application needs to play audio while one of these audio streams is being played, the audio interruption strategy is triggered.

- **INDEPENDENT_MODE**: Each audio stream created by an application has an independent audio focus. When multiple audio streams are played concurrently, the audio interruption strategy is triggered.

The application can select an audio interruption mode as required. By default, the **SHARED_MODE** is used.

You can set the audio interruption mode in either of the following ways:

- If you [use the AVPlayer to develop audio playback](../media/using-avplayer-for-playback.md), set the [audioInterruptMode](../../reference/apis-media-kit/js-apis-media.md#avplayer9) attribute of the AVPlayer to set the audio interruption mode.

- If you [use the AudioRenderer to develop audio playback](using-audiorenderer-for-playback.md), call [setInterruptMode](../../reference/apis-audio-kit/js-apis-audio.md#setinterruptmode9) of the AudioRenderer to set the audio interruption mode.

- If you [use OHAudio to develop audio playback](using-ohaudio-for-playback.md), call [OH_AudioStreamBuilder_SetRendererInterruptMode](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setrendererinterruptmode) to set the audio interruption mode.


### Audio Interruption Type

The audio interruption strategy (containing two audio interruption modes) determines the operation to be performed on each audio stream. These operations can be carried out by the system or application. To distinguish the executors, the audio interruption type, specified by [InterruptForceType](../../reference/apis-audio-kit/js-apis-audio.md#interruptforcetype9), is introduced.

- **INTERRUPT_FORCE**: The operation is performed by the system. The system forcibly interrupts audio playback.

- **INTERRUPT_SHARE**: The operation is performed by the application. The application can take action or ignore as required.

For the pause operation, the **INTERRUPT_FORCE** type is always used and cannot be changed by the application. However, the application can choose to use **INTERRUPT_SHARE** for other operations, such as the resume operation. The application can obtain the audio interruption type based on the value of the member variable **forceType** in the audio interruption event.

During audio playback, the system automatically requests, holds, and releases the focus for the audio stream. When audio interruption occurs, the system forcibly pauses or stops playing or ducks the volume down for the audio stream, and sends an audio interruption event callback to the application. To maintain state consistency between the application and the system and ensure good user experience, it is recommended that the application [listen for audio interruption events](#listening-for-audio-interruption-events) and perform processing when receiving such an event.

For operations that cannot be forcibly performed by the system (for example, resume), the system sends the audio interruption event containing **INTERRUPT_SHARE**, and the application can choose to take action or ignore.

## Listening for Audio Interruption Events

Your application are advised to listen for audio interruption events when playing audio. When audio interruption occurs, the system performs processing on the audio stream according to the preset strategy, and sends an audio interruption event to the application.

Upon the receipt of the event, the application carries out processing based on the event content to ensure that the application state is consistent with the expected effect.

You can use either of the following methods to listen for audio interruption events:

- If you [use the AVPlayer to develop audio playback](../media/using-avplayer-for-playback.md), call [on('audioInterrupt')](../../reference/apis-media-kit/js-apis-media.md#onaudiointerrupt9) of the AVPlayer to listen for the event.

- If you [use the AudioRenderer to develop audio playback](using-audiorenderer-for-playback.md), call [on('audioInterrupt')](../../reference/apis-audio-kit/js-apis-audio.md#onaudiointerrupt9) of the AudioRenderer to listen for the event.

- If you [use OHAudio to develop audio playback](using-ohaudio-for-playback.md), call [OH_AudioStreamBuilder_SetRendererCallback](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setrenderercallback) to listen for the event, which is **OH_AudioRenderer_OnInterruptEvent**.

To deliver an optimal user experience, the application needs to perform processing based on the event content. The following uses the AudioRenderer as an example to describe the recommended application processing. (The recommended processing is similar if the AVPlayer or OHAudio is used to develop audio playback.) You can customize the code to implement your own audio playback functionality or application processing based on service requirements.

```ts
import { audio } from '@kit.AudioKit';  // Import the audio module.
import { BusinessError } from '@kit.BasicServicesKit'; // Import BusinessError.

let isPlay: boolean; // An identifier specifying whether the audio stream is being played. In actual development, this parameter corresponds to the module related to the audio playback state.
let isDucked: boolean; // An identifier specifying whether to duck the volume down. In actual development, this parameter corresponds to the module related to the audio volume.
let started: boolean; // An identifier specifying whether the start operation is successful.

async function onAudioInterrupt(): Promise<void> {
  // The AudioRenderer is used as an example to describe how to develop audio playback. The audioRenderer variable is the AudioRenderer instance created for playback.
  audioRenderer.on('audioInterrupt', async(interruptEvent: audio.InterruptEvent) => {
    // When an audio interruption event occurs, the AudioRenderer receives the interruptEvent callback and performs processing based on the content in the callback.
    // 1. (Optional) The AudioRenderer reads the value of interruptEvent.forceType to see whether the system has forcibly performed the operation.
    // Note: In the default focus policy, INTERRUPT_HINT_RESUME maps to the force type INTERRUPT_SHARE, and others map to INTERRUPT_FORCE. Therefore, the value of forceType does not need to be checked.
    // 2. (Mandatory) The AudioRenderer then reads the value of interruptEvent.hintType and performs corresponding processing.
    if (interruptEvent.forceType === audio.InterruptForceType.INTERRUPT_FORCE) {
      // If the value of interruptEvent.forceType is INTERRUPT_FORCE, the system has performed audio-related processing, and the application needs to update its state and make adjustments accordingly.
       switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
          // The system has paused the audio stream (the focus is temporarily lost). To ensure state consistency, the application needs to switch to the audio paused state.
          // Temporarily losing the focus: After the other audio stream releases the focus, the current audio stream will receive the audio interruption event corresponding to resume and automatically resume the playback.
          isPlay = false; // A simplified processing indicating several operations for switching the application to the audio paused state.
          break;
        case audio.InterruptHint.INTERRUPT_HINT_STOP:
          // The system has stopped the audio stream (the focus is permanently lost). To ensure state consistency, the application needs to switch to the audio paused state.
          // Permanently losing the focus: No audio interruption event will be received. The user must manually trigger the operation to resume playback.
          isPlay = false; // A simplified processing indicating several operations for switching the application to the audio paused state.
          break;
        case audio.InterruptHint.INTERRUPT_HINT_DUCK:
          // The system has ducked the volume down (to 20% of the normal volume by default).
          isDucked = true; // A simplified processing indicating several operations for switching the application to the volume decreased state.
          break;
        case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
          // The system has restored the audio volume to normal.
          isDucked = false; // A simplified processing indicating several operations for switching the application to the normal volume state.
          break;
        default:
          break;
      }
    } else if (interruptEvent.forceType === audio.InterruptForceType.INTERRUPT_SHARE) {
      // If the value of interruptEvent.forceType is INTERRUPT_SHARE, the application can take action or ignore as required.
      switch (interruptEvent.hintType) {
        case audio.InterruptHint.INTERRUPT_HINT_RESUME:
          // The paused audio stream can be played. It is recommended that the application continue to play the audio stream and switch to the audio playing state.
          // If the application does not want to continue the playback, it can ignore the event.
          // To continue the playback, the application needs to call start(), and use the identifier variable started to record the execution result of start().
          await audioRenderer.start().then(() => {
            started = true; // Calling start() is successful.
          }).catch((err: BusinessError) => {
            started = false; // Calling start() fails.
          });
          // If calling start() is successful, the application needs to switch to the audio playing state.
          if (started) {
            isPlay = true; // A simplified processing indicating several operations for switching the application to the audio playing state.
          } else {
            // Resuming the audio playback fails.
          }
          break;
        default:
          break;
      }
   }
  });
}
```

## Typical Scenarios

The following lists typical adaptation scenarios for audio focus, where application A plays audio streams first and application B plays audio streams at a later time.

| Type of Application A| Recommended Stream Type        | Type of Application B| Recommended Stream Type           | Recommended User Experience                                                    | Adaptation Solution                                                    |
| ------------ | ------------------ | ------------ | --------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Video        | STREAM_USAGE_MOVIE | Alarm        | STREAM_USAGE_ALARM    | When the alarm rings, the video playback pauses. When the alarm ends, the video playback resumes.        | Application A listens for audio interruption events. When it receives the **INTERRUPT_HINT_PAUSE** event, it pauses video playback and updates its UI. When the alarm ends, application A receives the **INTERRUPT_HINT_RESUME** event and restarts the playback.|
| Music        | STREAM_USAGE_MUSIC | Ringtone    | STREAM_USAGE_RINGTONE | When the phone rings, the music playback pauses. When the call is not connected or the call is connected and then ended, the music playback resumes.| Application A listens for audio interruption events. When it receives the **INTERRUPT_HINT_PAUSE** event, it pauses music playback and updates its UI. When the call ends, application A receives the **INTERRUPT_HINT_RESUME** event and restarts the playback.|
| Music        | STREAM_USAGE_MUSIC | Music        | STREAM_USAGE_MUSIC    | Application A stops playing the music, and the UI displays the stopped state. Application B plays music normally.| Application A listens for audio interruption events. When it receives the **INTERRUPT_HINT_STOP** event, it stops music playback and updates its UI.|
