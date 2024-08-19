# @ohos.multimedia.audioHaptic (Audio-Haptic)

Audio-haptic enables users to get rhythmic auditory and haptic feedback while having incoming calls or messages.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```ts
import { audioHaptic } from '@kit.AudioKit';
```

## audioHaptic.getAudioHapticManager

getAudioHapticManager(): AudioHapticManager

Obtains an **AudioHapticManager** instance.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type                         | Description        |
| ----------------------------- | ------------ |
| [AudioHapticManager](#audiohapticmanager) | **AudioHapticManager** instance. |

**Example**
```ts
let audioHapticManagerInstance: audioHaptic.AudioHapticManager = audioHaptic.getAudioHapticManager();
```

## AudioLatencyMode

Enumerates the audio latency modes.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

| Name                           |  Value    | Description                                        |
| ------------------------------- | ------ | -------------------------------------------- |
| AUDIO_LATENCY_MODE_NORMAL       | 0      | Normal latency mode.                               |
| AUDIO_LATENCY_MODE_FAST         | 1      | Low latency mode. This mode is applicable to short audio files. A long audio file may be truncated in this mode. It functions the same as [SoundPool](../apis-media-kit/js-apis-inner-multimedia-soundPool.md#soundpool). |

## AudioHapticPlayerOptions

Describes the options for the audio-haptic player.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

| Name     | Type           |Mandatory  | Description                             |
| --------- | -------------- | ---- | --------------------------------- |
| muteAudio   | boolean      | No  | Whether to mute the audio. The value **true** means to mute the audio, and **false** means the opposite. If this parameter is not specified, the default value **false** is used. |
| muteHaptics | boolean      | No  | Whether to mute haptics feedback. The value **true** means to mute haptics feedback, and **false** means the opposite. If this parameter is not specified, the default value **false** is used. |

## AudioHapticManager

Manages the audio-haptic feature. Before calling any API in **AudioHapticManager**, you must use [getAudioHapticManager](#audiohapticgetaudiohapticmanager) to create an **AudioHapticManager** instance.

### registerSource

registerSource(audioUri: string, hapticUri: string): Promise&lt;number&gt;

Registers an audio-haptic source. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory | Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| audioUri  | string                                  | Yes  | URI of the audio source. In normal latency mode, the supported audio resource formats and path formats are defined in [media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9). In low latency mode, the supported audio resource formats are defined in [SoundPool](../apis-media-kit/js-apis-inner-multimedia-soundPool.md#soundpool), and the path format must meet the requirements of [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen). In both modes, you are advised to pass in the absolute path of the file.          |
| hapticUri | string                                  | Yes  | URI of the haptic source. The supported haptic resource formats are defined in [vibrator](../apis-sensor-service-kit/js-apis-vibrator.md#hapticfiledescriptor10). The path format must meet the requirements of [fs.open](../apis-core-file-kit/js-apis-file-fs.md#fsopen). You are advised to pass in the absolute path of the file.        |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the source ID. |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID | Error Message                             |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // Change it to the URI of the target audio source.
let hapticUri = 'data/hapticTest.json'; // Change it to the URI of the target haptic source.
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});
```

### unregisterSource

unregisterSource(id: number): Promise&lt;void&gt;

Unregisters an audio-haptic source. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory | Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id       | number                                   | Yes  | Source ID.   |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID | Error Message                             |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // Change it to the URI of the target audio source.
let hapticUri = 'data/hapticTest.json'; // Change it to the URI of the target haptic source.
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

audioHapticManagerInstance.unregisterSource(id).then(() => {
  console.info(`Promise returned to indicate that unregister source successfully`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to unregistere source ${err}`);
});
```

### setAudioLatencyMode

setAudioLatencyMode(id:number, latencyMode: AudioLatencyMode): void

Sets the latency mode for an audio-haptic source.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory | Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id          | number                                | Yes  | Source ID.   |
| latencyMode | [AudioLatencyMode](#audiolatencymode) | Yes  | Audio latency mode.            |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID | Error Message                             |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102 | Operation not allowed.            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // Change it to the URI of the target audio source.
let hapticUri = 'data/hapticTest.json'; // Change it to the URI of the target haptic source.
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

let latencyMode: audioHaptic.AudioLatencyMode = audioHaptic.AudioLatencyMode.AUDIO_LATENCY_MODE_FAST;

audioHapticManagerInstance.setAudioLatencyMode(id, latencyMode);
```

### setStreamUsage

setStreamUsage(id: number, usage: audio.StreamUsage): void

Sets the stream usage for an audio-haptic source.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory | Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id       | number                                   | Yes  | Source ID.   |
| usage    | [audio.StreamUsage](js-apis-audio.md#streamusage) | Yes  | Stream usage.   |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID | Error Message                             |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 5400102 | Operation not allowed.            |

**Example**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // Change it to the URI of the target audio source.
let hapticUri = 'data/hapticTest.json'; // Change it to the URI of the target haptic source.
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

let usage: audio.StreamUsage = audio.StreamUsage.STREAM_USAGE_NOTIFICATION;

audioHapticManagerInstance.setStreamUsage(id, usage);
```

### createPlayer

createPlayer(id: number, options?: AudioHapticPlayerOptions): Promise&lt;AudioHapticPlayer&gt;

Creates an audio-haptic player. This API uses a promise to return the result.

**Required permissions**: ohos.permission.VIBRATE

If the audio-haptic player needs to trigger vibration, check whether the application has the permission.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory | Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id       | number                                   | Yes  | Source ID.   |
| options  | [AudioHapticPlayerOptions](#audiohapticplayeroptions) | No  | Options of the audio-haptic player. |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;[AudioHapticPlayer](#audiohapticplayer)&gt; | Promise used to return the audio-haptic player. |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID | Error Message                             |
| ------- |-----------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102 | Operation not allowed. |
| 5400103 | I/O error. |
| 5400106 | Unsupport format. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // Change it to the URI of the target audio source.
let hapticUri = 'data/hapticTest.json'; // Change it to the URI of the target haptic source.
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

let options: audioHaptic.AudioHapticPlayerOptions = {muteAudio: false, muteHaptics: false};
let audioHapticPlayerInstance: audioHaptic.AudioHapticPlayer | undefined = undefined;

audioHapticManagerInstance.createPlayer(id, options).then((value: audioHaptic.AudioHapticPlayer) => {
  audioHapticPlayerInstance = value;
  console.info(`Create the audio haptic player successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to create the audio haptic player. ${err}`);
});
```

## AudioHapticType

Enumerates the audio haptic types.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

| Name                           |  Value    | Description                                        |
| ------------------------------- | ------ | -------------------------------------------- |
| AUDIO_HAPTIC_TYPE_AUDIO         | 0      | Audio.                                   |
| AUDIO_HAPTIC_TYPE_HAPTIC        | 1      | Haptic.                                   |

## AudioHapticPlayer

Implements audio-haptic playback. Before calling any API in **AudioHapticPlayer**, you must use [createPlayer](#createplayer) to create an **AudioHapticPlayer** instance.

### isMuted

isMuted(type: AudioHapticType): boolean

Checks whether an audio-haptic type is muted.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory | Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| type     | [AudioHapticType](#audiohaptictype)      | Yes  | Audio-haptic type.               |

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| boolean             | Whether the audio-haptic type is muted.       |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID | Error Message                             |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Parameter verification failed. |

**Example**

```ts
let audioHapticType: audioHaptic.AudioHapticType = audioHaptic.AudioHapticType.AUDIO_HAPTIC_TYPE_AUDIO;

let result: boolean = audioHapticPlayerInstance.isMuted(audioHapticType);
```

### start

start(): Promise&lt;void&gt;

Starts playing the audio and haptic source. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
|---------|-----------------------------------|
| 5400102 | Operate not permit. |
| 5400103 | IO error. |
| 5400105 | Service died. |


**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.start().then(() => {
  console.info(`Promise returned to indicate that start playing successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to start playing. ${err}`);
});
```

### stop

stop(): Promise&lt;void&gt;

Stops playing the audio-haptic source. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result. |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
|---------|-----------------------------------|
| 5400102 | Operate not permit. |
| 5400105 | Service died. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.stop().then(() => {
  console.info(`Promise returned to indicate that stop playing successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to stop playing. ${err}`);
});
```

### release

release(): Promise&lt;void&gt;

Releases this audio-haptic player. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.  |

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
|---------|-----------------------------------|
| 5400105 | Service died. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.release().then(() => {
  console.info(`Promise returned to indicate that release the audio haptic player successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to release the audio haptic player. ${err}`);
});
```

### on('endOfStream')

on(type: 'endOfStream', callback: Callback&lt;void&gt;): void

Subscribes to end of stream (EOS) events. This API uses a callback to obtain the events.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                    | Mandatory | Description                                                                      |
| -------- | ----------------------- | ---- | -------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The value is fixed at **'endOfStream'**. |
| callback | Callback&lt;void&gt;    | Yes  | Callback triggered when the event is received.                          |

**Example**

```ts
audioHapticPlayerInstance.on('endOfStream', () => {
  console.info(`Receive the callback of endOfStream.`);
});
```

### off('endOfStream')

off(type: 'endOfStream', callback?: Callback&lt;void&gt;): void

Unsubscribes from EOS events.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name | Type  | Mandatory | Description                                             |
| ----- | ----- | ---- | ------------------------------------------------ |
| type   | string | Yes  | Event type. The value is fixed at **'endOfStream'**. |
| callback | Callback&lt;void&gt;    | No  | Callback used for unsubscription.         |

**Example**

```ts
audioHapticPlayerInstance.off('endOfStream');
```

### on('audioInterrupt')

on(type: 'audioInterrupt', callback: Callback&lt;audio.InterruptEvent&gt;): void

Subscribes to audio interruption events. This API uses a callback to obtain the events.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                    | Mandatory | Description                                                                      |
| -------- | ----------------------- | ---- | -------------------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The value is fixed at **'audioInterrupt'**.                    |
| callback | Callback&lt;[audio.InterruptEvent](js-apis-audio.md#interruptevent9)&gt; | Yes  | Callback triggered when the event is received.   |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let isPlaying: boolean; // An identifier specifying whether rendering is in progress.
let isDucked: boolean; // An identifier specifying whether the audio volume is reduced.

audioHapticPlayerInstance.on('audioInterrupt', (interruptEvent: audio.InterruptEvent) => {
  // When an audio interruption event occurs, the audioHapticPlayerInstance receives the interruptEvent callback and performs processing based on the content in the callback.
  // 1. (Optional) The audioHapticPlayerInstance reads the value of interruptEvent.forceType to see whether the system has forcibly performed the operation.
  // Note: In the default focus policy, INTERRUPT_HINT_RESUME maps to the force type INTERRUPT_SHARE, and others map to INTERRUPT_FORCE. Therefore, the value of forceType does not need to be checked.
  // 2. (Mandatory) The audioHapticPlayerInstance then reads the value of interruptEvent.hintType and performs corresponding processing.
  if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
    // The audio focus event has been forcibly executed by the system. The application needs to update its status and displayed content.
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
        // The audio stream has been paused and temporarily loses the focus. It will receive the interruptEvent corresponding to resume when it is able to regain the focus.
        console.info('Force paused. Update playing status and stop writing');
        isPlaying = false; // A simplified processing indicating several operations for switching the application to the paused state.
        break;
      case audio.InterruptHint.INTERRUPT_HINT_STOP:
        // The audio stream has been stopped and permanently loses the focus. The user must manually trigger the operation to resume rendering.
        console.info('Force stopped. Update playing status and stop writing');
        isPlaying = false; // A simplified processing indicating several operations for switching the application to the paused state.
        break;
      case audio.InterruptHint.INTERRUPT_HINT_DUCK:
        // The audio stream is rendered at a reduced volume.
        console.info('Force ducked. Update volume status');
        isDucked = true; // A simplified processing indicating several operations for updating the volume status.
        break;
      case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
        // The audio stream is rendered at the normal volume.
        console.info('Force ducked. Update volume status');
        isDucked = false; // A simplified processing indicating several operations for updating the volume status.
        break;
      default:
        break;
    }
  } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
    // The audio focus event needs to be operated by the application, which can choose the processing mode. It is recommended that the application process the event according to the value of InterruptHint.
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_RESUME:
        // It is recommended that the application continue rendering. (The audio stream has been forcibly paused and temporarily lost the focus. It can resume rendering now.)
        // The INTERRUPT_HINT_RESUME operation must be proactively executed by the application and cannot be forcibly executed by the system. Therefore, the INTERRUPT_HINT_RESUME event must map to INTERRUPT_SHARE.
        console.info('Resume force paused renderer or ignore');
        // To continue rendering, the application must perform the required operations.
        break;
      default:
        break;
    }
  }
});
```

### off('audioInterrupt')

off(type: 'audioInterrupt', callback?: Callback&lt;audio.InterruptEvent&gt;): void

Unsubscribes from audio interruption events.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name | Type  | Mandatory | Description                                             |
| ----- | ----- | ---- | ------------------------------------------------- |
| type   | string | Yes  | Event type. The value is fixed at **'audioInterrupt'**. |
| callback | Callback&lt;void&gt;    | No  | Callback used for unsubscription.           |

**Example**

```ts
audioHapticPlayerInstance.off('audioInterrupt');
```
