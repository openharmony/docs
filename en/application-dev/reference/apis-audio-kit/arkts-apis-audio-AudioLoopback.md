# Interface (AudioLoopback)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 20.

This interface provides APIs for audio monitoring.

Before calling any API in AudioLoopback, you must use [audio.createAudioLoopback](arkts-apis-audio-f.md#audiocreateaudioloopback20) to create an AudioLoopback instance.

When audio loopback is enabled, the system creates a low-latency renderer and capturer to implement low-latency in-ear monitoring. The audio captured is routed back to the renderer through an internal path. The renderer follows the audio focus strategy for [STREAM_USAGE_MUSIC](arkts-apis-audio-e.md#streamusage), whereas the capturer follows the strategy for [SOURCE_TYPE_MIC](arkts-apis-audio-e.md#sourcetype8).

The system automatically chooses the input and output devices. If these devices do not support low latency, audio loopback does not work. If another audio stream takes over the audio focus or if the input or output device changes to the one that does not support low latency, the system disables audio loopback automatically.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## getStatus<sup>20+</sup>

getStatus(): Promise<AudioLoopbackStatus\>

Obtains the audio loopback status. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                             | Description                               |
| :------------------------------------------------ | :---------------------------------- |
| Promise<[AudioLoopbackStatus](arkts-apis-audio-e.md#audioloopbackstatus20)\> | Promise used to return the audio loopback status.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioLoopback.getStatus().then((status: audio.AudioLoopbackStatus) => {
  console.info(`AudioLoopback: Status: ${status}`);
}).catch((err: BusinessError) => {
  console.error(`AudioLoopback: Status :ERROR: ${err}`);
})
```

## setVolume<sup>20+</sup>

setVolume(volume: number): Promise&lt;void&gt;

Sets the volume for audio loopback. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name    | Type   | Mandatory  | Description                |
| ---------- | ------- | ------ | ------------------- |
| volume     | number  | Yes    | Volume to set, which is in the range [0.0, 1.0].|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed, form 0.0 to 1.0. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioLoopback.setVolume(0.5).then(() => {
  console.info('setVolume Success!');
}).catch((err: BusinessError) => {
  console.error(`setVolume Fail: ${err}`);
});
```

## on('statusChange')<sup>20+</sup>

on(type: 'statusChange', callback: Callback<AudioLoopbackStatus\>): void

Subscribes to the audio loopback status change event, which is triggered when the status of the audio loopback is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'statusChange'** is triggered when the status of the audio loopback is changed.|
| callback | Callback\<[AudioLoopbackStatus](arkts-apis-audio-e.md#audioloopbackstatus20)> | Yes  | Callback used to return the audio loopback status.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioLoopback.on('statusChange', (status: audio.AudioLoopbackStatus) => {
  if (status == audio.AudioLoopbackStatus.UNAVAILABLE_DEVICE) {
    console.info('audio loopback status is: UNAVAILABLE_DEVICE');
  } else if (status == audio.AudioLoopbackStatus.UNAVAILABLE_SCENE) {
    console.info('audio loopback status is: UNAVAILABLE_SCENE');
  } else if (status == audio.AudioLoopbackStatus.AVAILABLE_IDLE) {
    console.info('audio loopback status is: AVAILABLE_IDLE');
  } else if (status == audio.AudioLoopbackStatus.AVAILABLE_RUNNING) {
    console.info('audio loopback status is: AVAILABLE_RUNNING');
  }
});
```

## off('statusChange')<sup>20+</sup>

off(type: 'statusChange', callback?: Callback&lt;AudioLoopbackStatus&gt;): void

Unsubscribes from the audio loopback status event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| :----- | :----- | :--- | :-------------------------------------------------- |
| type   | string | Yes  | Event type. The event **'statusChange'** is triggered when the status of the audio loopback is changed.|
| callback | Callback\<[AudioLoopbackStatus](arkts-apis-audio-e.md#audioloopbackstatus20)> | No| Callback used to return the audio loopback status.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioLoopback.off('statusChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let statusChangeCallback = (status: audio.AudioLoopbackStatus) => {
  if (status == audio.AudioLoopbackStatus.UNAVAILABLE_DEVICE) {
    console.info('audio loopback status is: UNAVAILABLE_DEVICE');
  } else if (status == audio.AudioLoopbackStatus.UNAVAILABLE_SCENE) {
    console.info('audio loopback status is: UNAVAILABLE_SCENE');
  } else if (status == audio.AudioLoopbackStatus.AVAILABLE_IDLE) {
    console.info('audio loopback status is: AVAILABLE_IDLE');
  } else if (status == audio.AudioLoopbackStatus.AVAILABLE_RUNNING) {
    console.info('audio loopback status is: AVAILABLE_RUNNING');
  }
};

audioLoopback.on('statusChange', statusChangeCallback);

audioLoopback.off('statusChange', statusChangeCallback);
```

## enable<sup>20+</sup>

enable(enable: boolean): Promise<boolean\>

Enables or disables audio loopback. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Required permissions**: ohos.permission.MICROPHONE

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| :----- | :----- | :--- | :-------------------------------------------------- |
| enable   | boolean | Yes  | Whether to enable or disable audio loopback. **true** to enable, **false** otherwise.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<boolean> | Promise used to return the result, indicating whether the API call is successful. **true** is successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | -------------------------------|
|     201 | Permission denied.             |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioLoopback.enable(true).then((isSuccess) => {
  if (isSuccess) {
    console.info('audio loopback enable success');
  } else {
    console.info('audio loopback enable fail');
  }
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## setReverbPreset<sup>21+</sup>

setReverbPreset(preset: AudioLoopbackReverbPreset): boolean

Sets the reverb mode for audio loopback.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| :----- | :----- | :--- | :-------------------------------------------------- |
| preset   | [AudioLoopbackReverbPreset](arkts-apis-audio-e.md#audioloopbackreverbpreset21) | Yes  | Reverb mode.|

**Return value**

| Type                                             | Description                               |
| :------------------------------------------------ | :---------------------------------- |
| boolean | Setting result. **true** if successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | -------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  audioLoopback.setReverbPreset(audio.AudioLoopbackReverbPreset.THEATER);
} catch (err) {
  console.error(`setReverbPreset :ERROR: ${err}`);
}
```

## getReverbPreset<sup>21+</sup>

getReverbPreset(): AudioLoopbackReverbPreset

Obtains the reverb mode of audio loopback.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                             | Description                               |
| :------------------------------------------------ | :---------------------------------- |
| [AudioLoopbackReverbPreset](arkts-apis-audio-e.md#audioloopbackreverbpreset21) | Reverb mode.<br>If no reverb mode has been set, the default reverb mode is **THEATER**.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let reverbPreset = audioLoopback.getReverbPreset();
} catch (err) {
  console.error(`getReverbPreset:ERROR: ${err}`);
}
```

## setEqualizerPreset<sup>21+</sup>

setEqualizerPreset(preset: AudioLoopbackEqualizerPreset): boolean

Sets the equalizer type for audio loopback.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| :----- | :----- | :--- | :-------------------------------------------------- |
| preset   | [AudioLoopbackEqualizerPreset](arkts-apis-audio-e.md#audioloopbackequalizerpreset21) | Yes  | Equalizer type.|

**Return value**

| Type                                             | Description                               |
| :------------------------------------------------ | :---------------------------------- |
| boolean | Setting result. **true** if successful, **false** otherwise.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | -------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  audioLoopback.setEqualizerPreset(audio.AudioLoopbackEqualizerPreset.FULL);
} catch (err) {
  console.error(`setEqualizerPreset :ERROR: ${err}`);
}
```

## getEqualizerPreset<sup>21+</sup>

getEqualizerPreset(): AudioLoopbackEqualizerPreset

Obtains the equalizer type of audio loopback.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                             | Description                               |
| :------------------------------------------------ | :---------------------------------- |
| [AudioLoopbackEqualizerPreset](arkts-apis-audio-e.md#audioloopbackequalizerpreset21) | Equalizer type.<br>If no equalizer type has been set, the default equalizer type is **FULL**.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let reverbPreset = audioLoopback.getEqualizerPreset();
} catch (err) {
  console.error(`getEqualizerPreset:ERROR: ${err}`);
}
```
