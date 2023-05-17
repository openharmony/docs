# Using TonePlayer for Audio Playback (for System Applications Only)

TonePlayer<sup>9+</sup> provides APIs for playing and managing Dual Tone Multi Frequency (DTMF) tones, such as dial tones, ringback tones, supervisory tones, and proprietary tones. The main task of the TonePlayer is to generate sine waves of different frequencies by using the built-in algorithm based on the [ToneType](../reference/apis/js-apis-audio.md#tonetype9)s and add the sine waves to create a sound. The sound can then be played by using the [AudioRenderer](../reference/apis/js-apis-audio.md#audiorenderer8), and the playback task can also be managed by using the [AudioRenderer](../reference/apis/js-apis-audio.md#audiorenderer8). The full process includes loading the DTMF tone configuration, starting DTMF tone playing, stopping the playback, and releasing the resources associated with the **TonePlayer** object. For details about the APIs, see the [TonePlayer API Reference](../reference/apis/js-apis-audio.md#toneplayer9).


## Supported Tone Types

The table below lists the supported [ToneType](../reference/apis/js-apis-audio.md#tonetype9)s. You can call **load()** with **audio.ToneType.*type*** as a parameter to load the tone resource of the specified type.

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
| TONE_TYPE_DIAL_S | 10 | DTMF tone of the star key (*).| 
| TONE_TYPE_DIAL_P | 11 | DTMF tone of the pound key (#).| 
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
| TONE_TYPE_COMMON_PROPRIETARY_BEEP | 200 | Proprietary tone - beep tone.| 
| TONE_TYPE_COMMON_PROPRIETARY_ACK | 201 | Proprietary tone - ACK.| 
| TONE_TYPE_COMMON_PROPRIETARY_PROMPT | 203 | Proprietary tone - PROMPT.| 
| TONE_TYPE_COMMON_PROPRIETARY_DOUBLE_BEEP | 204 | Proprietary tone - double beep tone.| 


## How to Develop

To implement audio playback with the TonePlayer, perform the following steps:

1. Create a **TonePlayer** instance.
     
   ```ts
   import audio from '@ohos.multimedia.audio';
   let audioRendererInfo = {
     content : audio.ContentType.CONTENT_TYPE_SONIFICATION,
     usage : audio.StreamUsage.STREAM_USAGE_MEDIA,
     rendererFlags : 0
   };
   tonePlayerPromise = audio.createTonePlayer(audioRendererInfo);
   ```

2. Load the DTMF tone configuration of the specified type.
     
   ```ts
   tonePlayerPromise.load(audio.ToneType.TONE_TYPE_DIAL_0);
   ```

3. Start DTMF tone playing.
     
   ```ts
   tonePlayerPromise.start();
   ```

4. Stop the tone that is being played.
     
   ```ts
   tonePlayerPromise.stop();
   ```

5. Release the resources associated with the **TonePlayer** instance.
     
   ```ts
   tonePlayerPromise.release();
   ```

If the APIs are not called in the preceding sequence, the error code **6800301 NAPI_ERR_SYSTEM** is returned.


## Sample Code

Refer to the following code to play the DTMF tone when the dial key on the keyboard is pressed.

To prevent the UI thread from being blocked, most **TonePlayer** calls are asynchronous. Each API provides the callback and promise functions. The following examples use the promise functions. For more information, see [TonePlayer](../reference/apis/js-apis-audio.md#toneplayer9).

  
```ts
import audio from '@ohos.multimedia.audio';

export class TonelayerDemo {
  private timer : number;
  private timerPro : number;
  // Promise mode.
  async testTonePlayerPromise(type) {
    console.info('testTonePlayerPromise start');
    if (this.timerPro) clearTimeout(this.timerPro);
    let tonePlayerPromise;
    let audioRendererInfo = {
      content : audio.ContentType.CONTENT_TYPE_SONIFICATION,
      usage : audio.StreamUsage.STREAM_USAGE_MEDIA,
      rendererFlags : 0
    };
    this.timerPro = setTimeout(async () => {
      try {
        console.info('testTonePlayerPromise: createTonePlayer');
        // Create a DTMF player.     
        tonePlayerPromise = await audio.createTonePlayer(audioRendererInfo);
        console.info('testTonePlayerPromise: createTonePlayer-success');
        console.info(`testTonePlayerPromise: load type: ${type}`);
        // Load the tone configuration of the specified type.
        await tonePlayerPromise.load(type);
        console.info('testTonePlayerPromise: load-success');
        console.info(`testTonePlayerPromise: start type: ${type}`);
        // Start DTMF tone playing.
        await tonePlayerPromise.start();
        console.info('testTonePlayerPromise: start-success');
        console.info(`testTonePlayerPromise: stop type: ${type}`);
        setTimeout(async()=>{
          // Stop the tone that is being played.
          await tonePlayerPromise.stop();
          console.info('testTonePlayerPromise: stop-success');
          console.info(`testTonePlayerPromise: release type: ${type}`);
          // Release the resources associated with the TonePlayer instance.
          await tonePlayerPromise.release();
          console.info('testTonePlayerPromise: release-success');
        }, 30)
      } catch(err) {
        console.error(`testTonePlayerPromise err : ${err}`);
      }
    }, 200)
  };
  async testTonePlayer() {
    this.testTonePlayerPromise(audio.ToneType.TONE_TYPE_DIAL_0);
  }
}
```
