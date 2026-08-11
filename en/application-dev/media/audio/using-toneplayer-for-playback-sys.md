# Using TonePlayer for Audio Playback (for System Applications Only)

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ff9e9cd1ebb6561090ad32be99073f8301559bf translatedAt=2026-08-06T01:56:58.472Z pushedAt=2026-08-06T10:31:39.770Z -->

TonePlayer<sup>9+</sup> provides methods for playing and managing DTMF (Dual Tone Multi Frequency) tones, including various system supervision tones and proprietary tones, such as dial tones and call ringback tones. It works by converting a specified [ToneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#tonetype9) into audio data formed by superimposing multiple sine waves of different frequencies through a built-in algorithm, playing the data through [AudioRenderer](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md), and managing playback tasks. The workflow includes loading DTMF tone configurations, starting DTMF tone playback, stopping the currently playing tone, and releasing resources associated with this TonePlayer object. For detailed API descriptions, see [TonePlayer](../../reference/apis-audio-kit/js-apis-audio-sys.md#toneplayer9).

## Supported Tone Types

The playback tone type [ToneType](../../reference/apis-audio-kit/js-apis-audio-sys.md#tonetype9) information is shown in the following table. You can call the [load](../../reference/apis-audio-kit/js-apis-audio-sys.md#load9) method with `audio.ToneType.<specified_type>` as a parameter to load tone resources of the specified type.

| Tone Type| Value| Description|
| -------- | -------- | -------- |
| TONE_TYPE_DIAL_0 | 0 | DTMF tone of key 0.|
| TONE_TYPE_DIAL_1 | 1 | DTMF tone of key 1.|
| TONE_TYPE_DIAL_2 | 2 | DTMF tone of key 2.|
| TONE_TYPE_DIAL_3 | 3 | DTMF tone of key 3.|
| TONE_TYPE_DIAL_4 | 4 | DTMF tone of key 4.|
| TONE_TYPE_DIAL_5 | 5 | DTMF tone of key 5.|
| TONE_TYPE_DIAL_6 | 6 | DTMF tone of key 6.|
| TONE_TYPE_DIAL_7 | 7 | DTMF tone of key 7.|
| TONE_TYPE_DIAL_8 | 8 | DTMF tone of key 8.|
| TONE_TYPE_DIAL_9 | 9 | DTMF tone of key 9.|
| TONE_TYPE_DIAL_S | 10 | DTMF tone for the star (*) key. |
| TONE_TYPE_DIAL_P | 11 | DTMF tone for the pound (#) key. |
| TONE_TYPE_DIAL_A | 12 | DTMF tone of key A.|
| TONE_TYPE_DIAL_B | 13 | DTMF tone of key B.|
| TONE_TYPE_DIAL_C | 14 | DTMF tone of key C.|
| TONE_TYPE_DIAL_D | 15 | DTMF tone of key D.|
| TONE_TYPE_COMMON_SUPERVISORY_DIAL | 100 | Supervisory tone - dial tone.|
| TONE_TYPE_COMMON_SUPERVISORY_BUSY | 101 | Supervisory tone - busy.|
| TONE_TYPE_COMMON_SUPERVISORY_CONGESTION | 102 | Supervisory tone - congestion.|
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_ACK | 103 | Supervisory tone - radio path acknowledgment.|
| TONE_TYPE_COMMON_SUPERVISORY_RADIO_NOT_AVAILABLE | 104 | Supervisory tone - radio path not available.|
| TONE_TYPE_COMMON_SUPERVISORY_CALL_WAITING | 106 | Supervisory tone - call waiting tone.|
| TONE_TYPE_COMMON_SUPERVISORY_RINGTONE | 107 | Supervisory tone - ringing tone.|
| TONE_TYPE_COMMON_SUPERVISORY_CALL_HOLDING<sup>18+</sup> | 108 | Call hold tone.|
| TONE_TYPE_COMMON_PROPRIETARY_BEEP | 200 | Proprietary tone - beep tone.|
| TONE_TYPE_COMMON_PROPRIETARY_ACK | 201 | Proprietary tone - ACK.|
| TONE_TYPE_COMMON_PROPRIETARY_PROMPT | 203 | Proprietary tone - PROMPT.|
| TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP | 204 | Proprietary tone - double beep tone.|

## How to Develop

To implement audio playback with the TonePlayer, perform the following steps:

1. Create a TonePlayer instance.

   ```ts
   import { audio } from '@kit.AudioKit';

   let audioRendererInfo: audio.AudioRendererInfo = {
     usage: audio.StreamUsage.STREAM_USAGE_DTMF, // Audio stream usage type: DTMF. Set this parameter based on the service scenario.
     rendererFlags: 0 // Playback stream behavior flag. Set to 0.
   };

   async function createTonePlayer() {
     let tonePlayerPromise = await audio.createTonePlayer(audioRendererInfo);
   }
   ```

2. Load the DTMF tone configuration of the specified type.

   ```ts
   async function load() {
     await tonePlayerPromise.load(audio.ToneType.TONE_TYPE_DIAL_0);
   }
   ```

3. Start DTMF tone playing.

   ```ts
   async function start() {
     await tonePlayerPromise.start();
   }
   ```

4. Stop the tone that is being played.

   ```ts
   async function stop() {
     await tonePlayerPromise.stop();
   }
   ```

5. Release the resources associated with the TonePlayer instance.

   ```ts
   async function release() {
     await tonePlayerPromise.release();
   }
   ```

If the API call sequence is abnormal, error code ·6800301 NAPI_ERR_SYSTEM· is returned.

## Complete Sample Code

Refer to the following example: tap a dial pad key to start the corresponding DTMF tone playback.

To prevent the UI thread from being blocked, most TonePlayer calls are asynchronous. Each API provides the callback and promise functions. The following examples use the promise functions. For more information, see [TonePlayer](../../reference/apis-audio-kit/js-apis-audio-sys.md#toneplayer9).

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let timerPro : number |  undefined = undefined;
let audioRendererInfo: audio.AudioRendererInfo = {
     usage: audio.StreamUsage.STREAM_USAGE_DTMF, // Audio stream usage type: DTMF tone. Configure based on the service scenario. See StreamUsage.
     rendererFlags: 0 // Renderer behavior flag. Set it to 0.
   };
// Promise call mode.
async function playTone(type: audio.ToneType): Promise<void> {

  let tonePlayerPromise: audio.TonePlayer | undefined = undefined;
  try {
    // Create a DTMF player.
    tonePlayerPromise = await audio.createTonePlayer(audioRendererInfo);
    // Load the tone of the specified type.
    await tonePlayerPromise.load(type);
    // Start DTMF tone playback.
    await tonePlayerPromise.start();
    await new Promise<void>((resolve) => setTimeout(resolve, 300));
    // Stop the currently playing tone.
    await tonePlayerPromise.stop();
  } catch (err) {
    console.error(`TonePlayerPromise err : ${err}`);
  } finally {
    if (tonePlayerPromise) {
      tonePlayerPromise.release().catch(() => console.error(`release error`));
    }
  }
}

function TonePlayerPromise(): void {
  timerPro = setTimeout(() => {
    playTone(audio.ToneType.TONE_TYPE_DIAL_0).catch(() => console.error(`playTone unhandled error`));
  }, 200) as number;
}
```