# Interface (AudioStreamManager)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 9.

This interface implements audio stream management.

Before calling any API in AudioStreamManager, you must use [getStreamManager](arkts-apis-audio-AudioManager.md#getstreammanager9) to obtain an AudioStreamManager instance.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## getCurrentAudioRendererInfoArray<sup>9+</sup>

getCurrentAudioRendererInfoArray(callback: AsyncCallback&lt;AudioRendererChangeInfoArray&gt;): void

Obtains the information about this audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type                                | Mandatory    | Description                        |
| -------- | ----------------------------------- | -------- | --------------------------- |
| callback | AsyncCallback<[AudioRendererChangeInfoArray](arkts-apis-audio-t.md#audiorendererchangeinfoarray9)> | Yes    | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio renderer information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getCurrentAudioRendererInfoArray(async (err: BusinessError, AudioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray) => {
  console.info('getCurrentAudioRendererInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getCurrentAudioRendererInfoArray :ERROR: ${err}`);
  } else {
    if (AudioRendererChangeInfoArray != null) {
      for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
        let AudioRendererChangeInfo: audio.AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
        console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
        console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
        console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
        console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`);
        for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }
});
```

## getCurrentAudioRendererInfoArray<sup>9+</sup>

getCurrentAudioRendererInfoArray(): Promise&lt;AudioRendererChangeInfoArray&gt;

Obtains the information about this audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                                                             | Description                                   |
| ---------------------------------------------------------------------------------| --------------------------------------- |
| Promise<[AudioRendererChangeInfoArray](arkts-apis-audio-t.md#audiorendererchangeinfoarray9)>          | Promise used to return the audio renderer information.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function getCurrentAudioRendererInfoArray(){
  await audioStreamManager.getCurrentAudioRendererInfoArray().then((AudioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray) => {
    console.info(`getCurrentAudioRendererInfoArray ######### Get Promise is called ##########`);
    if (AudioRendererChangeInfoArray != null) {
      for (let i = 0; i < AudioRendererChangeInfoArray.length; i++) {
        let AudioRendererChangeInfo: audio.AudioRendererChangeInfo = AudioRendererChangeInfoArray[i];
        console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
        console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
        console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
        console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`);
        for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }).catch((err: BusinessError) => {
    console.error(`getCurrentAudioRendererInfoArray :ERROR: ${err}`);
  });
}
```
## getCurrentAudioRendererInfoArraySync<sup>10+</sup>

getCurrentAudioRendererInfoArraySync(): AudioRendererChangeInfoArray

Obtains the information about this audio renderer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                                                             | Description                                   |
| ---------------------------------------------------------------------------------| --------------------------------------- |
| [AudioRendererChangeInfoArray](arkts-apis-audio-t.md#audiorendererchangeinfoarray9)          | Audio renderer information.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray = audioStreamManager.getCurrentAudioRendererInfoArraySync();
  console.info(`getCurrentAudioRendererInfoArraySync success.`);
  if (audioRendererChangeInfoArray != null) {
    for (let i = 0; i < audioRendererChangeInfoArray.length; i++) {
      let AudioRendererChangeInfo: audio.AudioRendererChangeInfo = audioRendererChangeInfoArray[i];
      console.info(`StreamId for ${i} is: ${AudioRendererChangeInfo.streamId}`);
      console.info(`Content ${i} is: ${AudioRendererChangeInfo.rendererInfo.content}`);
      console.info(`Stream ${i} is: ${AudioRendererChangeInfo.rendererInfo.usage}`);
      console.info(`Flag ${i} is: ${AudioRendererChangeInfo.rendererInfo.rendererFlags}`);
      for (let j = 0;j < AudioRendererChangeInfo.deviceDescriptors.length; j++) {
        console.info(`Id: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].id}`);
        console.info(`Type: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
        console.info(`Role: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
        console.info(`Name: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].name}`);
        console.info(`Address: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].address}`);
        console.info(`SampleRate: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
        console.info(`ChannelCount: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
        console.info(`ChannelMask: ${i} : ${AudioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
      }
    }
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`getCurrentAudioRendererInfoArraySync :ERROR: ${error}`);
}
```

## getCurrentAudioCapturerInfoArray<sup>9+</sup>

getCurrentAudioCapturerInfoArray(callback: AsyncCallback&lt;AudioCapturerChangeInfoArray&gt;): void

Obtains the information about this audio capturer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name       | Type                                | Mandatory     | Description                                                     |
| ---------- | ----------------------------------- | --------- | -------------------------------------------------------- |
| callback   | AsyncCallback<[AudioCapturerChangeInfoArray](arkts-apis-audio-t.md#audiocapturerchangeinfoarray9)> | Yes   | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio capturer information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getCurrentAudioCapturerInfoArray(async (err: BusinessError, AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) => {
  console.info('getCurrentAudioCapturerInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getCurrentAudioCapturerInfoArray :ERROR: ${err}`);
  } else {
    if (AudioCapturerChangeInfoArray != null) {
      for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
        console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
        console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
        console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
        for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }
});
```

## getCurrentAudioCapturerInfoArray<sup>9+</sup>

getCurrentAudioCapturerInfoArray(): Promise&lt;AudioCapturerChangeInfoArray&gt;

Obtains the information about this audio capturer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                                                        | Description                                |
| -----------------------------------------------------------------------------| ----------------------------------- |
| Promise<[AudioCapturerChangeInfoArray](arkts-apis-audio-t.md#audiocapturerchangeinfoarray9)>      | Promise used to return the audio capturer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function getCurrentAudioCapturerInfoArray(){
  await audioStreamManager.getCurrentAudioCapturerInfoArray().then((AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) => {
    console.info('getCurrentAudioCapturerInfoArray **** Get Promise Called ****');
    if (AudioCapturerChangeInfoArray != null) {
      for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
        console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
        console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
        console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
        for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
          console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
          console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
          console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
          console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
          console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
          console.info(`SampleRate: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
          console.info(`ChannelCount: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
          console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
        }
      }
    }
  }).catch((err: BusinessError) => {
    console.error(`getCurrentAudioCapturerInfoArray :ERROR: ${err}`);
  });
}
```

## getCurrentAudioCapturerInfoArraySync<sup>10+</sup>

getCurrentAudioCapturerInfoArraySync(): AudioCapturerChangeInfoArray

Obtains the information about this audio capturer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Return value**

| Type                                                                        | Description                                |
| -----------------------------------------------------------------------------| ----------------------------------- |
| [AudioCapturerChangeInfoArray](arkts-apis-audio-t.md#audiocapturerchangeinfoarray9)      | Audio capturer information. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray = audioStreamManager.getCurrentAudioCapturerInfoArraySync();
  console.info('getCurrentAudioCapturerInfoArraySync success.');
  if (audioCapturerChangeInfoArray != null) {
    for (let i = 0; i < audioCapturerChangeInfoArray.length; i++) {
      console.info(`StreamId for ${i} is: ${audioCapturerChangeInfoArray[i].streamId}`);
      console.info(`Source for ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.source}`);
      console.info(`Flag  ${i} is: ${audioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
      for (let j = 0; j < audioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
        console.info(`Id: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
        console.info(`Type: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
        console.info(`Role: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
        console.info(`Name: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
        console.info(`Address: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
        console.info(`SampleRate: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
        console.info(`ChannelCount: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
        console.info(`ChannelMask: ${i} : ${audioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
      }
    }
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`getCurrentAudioCapturerInfoArraySync ERROR: ${error}`);
}
```

## on('audioRendererChange')<sup>9+</sup>

on(type: 'audioRendererChange', callback: Callback&lt;AudioRendererChangeInfoArray&gt;): void

Subscribes to the audio renderer change event, which is triggered when the audio playback stream status or device is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name     | Type       | Mandatory     | Description                                                                    |
| -------- | ---------- | --------- | ------------------------------------------------------------------------ |
| type     | string     | Yes       | Event type. The event **'audioRendererChange'** is triggered when the audio playback stream status or device is changed.|
| callback | Callback<[AudioRendererChangeInfoArray](arkts-apis-audio-t.md#audiorendererchangeinfoarray9)> | Yes |  Callback used to return the audio renderer information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioStreamManager.on('audioRendererChange',  (audioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray) => {
  for (let i = 0; i < audioRendererChangeInfoArray.length; i++) {
    let audioRendererChangeInfo: audio.AudioRendererChangeInfo = audioRendererChangeInfoArray[i];
    console.info(`## RendererChange on is called for ${i} ##`);
    console.info(`StreamId for ${i} is: ${audioRendererChangeInfo.streamId}`);
    console.info(`Content ${i} is: ${audioRendererChangeInfo.rendererInfo.content}`);
    console.info(`Stream ${i} is: ${audioRendererChangeInfo.rendererInfo.usage}`);
    console.info(`Flag ${i} is: ${audioRendererChangeInfo.rendererInfo.rendererFlags}`);
    for (let j = 0;j < audioRendererChangeInfo.deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].address}`);
      console.info(`SampleRate: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCount: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
    }
  }
});
```

## off('audioRendererChange')<sup>9+</sup>

off(type: 'audioRendererChange', callback?: Callback&lt;AudioRendererChangeInfoArray&gt;): void

Unsubscribes from the audio renderer change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type    | Mandatory| Description             |
| -------- | ------- |----| ---------------- |
| type     | string  | Yes | Event type. The event **'audioRendererChange'** is triggered when the audio playback stream status or device is changed.|
| callback<sup>18+</sup> | Callback<[AudioRendererChangeInfoArray](arkts-apis-audio-t.md#audiorendererchangeinfoarray9)> | No |  Callback used to return the audio renderer information.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message                    |
| ------- |--------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioStreamManager.off('audioRendererChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let audioRendererChangeCallback = (audioRendererChangeInfoArray: audio.AudioRendererChangeInfoArray) => {
  for (let i = 0; i < audioRendererChangeInfoArray.length; i++) {
    let audioRendererChangeInfo: audio.AudioRendererChangeInfo = audioRendererChangeInfoArray[i];
    console.info(`## RendererChange on is called for ${i} ##`);
    console.info(`StreamId for ${i} is: ${audioRendererChangeInfo.streamId}`);
    console.info(`Content ${i} is: ${audioRendererChangeInfo.rendererInfo.content}`);
    console.info(`Stream ${i} is: ${audioRendererChangeInfo.rendererInfo.usage}`);
    console.info(`Flag ${i} is: ${audioRendererChangeInfo.rendererInfo.rendererFlags}`);
    for (let j = 0;j < audioRendererChangeInfo.deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].address}`);
      console.info(`SampleRate: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCount: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${audioRendererChangeInfo.deviceDescriptors[j].channelMasks[0]}`);
    }
  }
};

audioStreamManager.on('audioRendererChange', audioRendererChangeCallback);

audioStreamManager.off('audioRendererChange', audioRendererChangeCallback);
```

## on('audioCapturerChange')<sup>9+</sup>

on(type: 'audioCapturerChange', callback: Callback&lt;AudioCapturerChangeInfoArray&gt;): void

Subscribes to the audio capturer change event, which is triggered when the audio recording stream status or device is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name    | Type    | Mandatory     | Description                                                                                         |
| -------- | ------- | --------- | ---------------------------------------------------------------------- |
| type     | string  | Yes       | Event type. The event **'audioCapturerChange'** is triggered when the audio recording stream status or device is changed.|
| callback | Callback<[AudioCapturerChangeInfoArray](arkts-apis-audio-t.md#audiocapturerchangeinfoarray9)> | Yes    | Callback used to return the audio capturer information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioStreamManager.on('audioCapturerChange', (AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) =>  {
  for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
    console.info(`## CapChange on is called for element ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
    console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
    console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
    for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
      console.info(`SampleRate: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCount: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
    }
  }
});
```

## off('audioCapturerChange')<sup>9+</sup>

off(type: 'audioCapturerChange', callback?: Callback&lt;AudioCapturerChangeInfoArray&gt;): void

Unsubscribes from the audio capturer change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name      | Type    | Mandatory| Description                                                         |
| -------- | -------- | --- | ------------------------------------------------------------- |
| type     | string   |Yes  | Event type. The event **'audioCapturerChange'** is triggered when the audio capturer is changed.|
| callback<sup>18+</sup> | Callback<[AudioCapturerChangeInfoArray](arkts-apis-audio-t.md#audiocapturerchangeinfoarray9)> | No| Callback used to return the audio capturer information.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioStreamManager.off('audioCapturerChange');
// Cancel all subscriptions to the event.
audioStreamManager.off('audioCapturerChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let audioCapturerChangeCallback = (AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) =>  {
  for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
    console.info(`## CapChange on is called for element ${i} ##`);
    console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
    console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
    console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
    for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
      console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
      console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
      console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
      console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
      console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
      console.info(`SampleRate: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
      console.info(`ChannelCount: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
      console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks[0]}`);
    }
  }
};

audioStreamManager.on('audioCapturerChange', audioCapturerChangeCallback);

audioStreamManager.off('audioCapturerChange', audioCapturerChangeCallback);
```

## isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is active. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [isStreamActive](arkts-apis-audio-AudioStreamManager.md#isstreamactive20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type                               | Mandatory| Description                                             |
| ---------- | ----------------------------------- | ---- | ------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream types.                                     |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is active or **false** if not active; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.isActive(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
if (err) {
  console.error(`Failed to obtain the active status of the stream. ${err}`);
  return;
}
  console.info(`Callback invoked to indicate that the active status of the stream is obtained ${value}.`);
});
```

## isActive<sup>(deprecated)</sup>

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is active. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [isStreamActive](arkts-apis-audio-AudioStreamManager.md#isstreamactive20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream types.|

**Return value**

| Type                  | Description                                                    |
| ---------------------- | -------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the stream is active, and **false** means the opposite.|

**Example**

```ts
audioStreamManager.isActive(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the active status of the stream is obtained ${value}.`);
});
```

## isActiveSync<sup>(deprecated)</sup>

isActiveSync(volumeType: AudioVolumeType): boolean

Checks whether a stream is active. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [isStreamActive](arkts-apis-audio-AudioStreamManager.md#isstreamactive20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream types.|

**Return value**

| Type                  | Description                                                    |
| ---------------------- | -------------------------------------------------------- |
| boolean | Check result. The value **true** means that the stream is active, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioStreamManager.isActiveSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the active status of the stream is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the active status of the stream ${error}.`);
}
```

## isStreamActive<sup>20+</sup>

isStreamActive(streamUsage: StreamUsage): boolean

Checks whether a stream is active. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| streamUsage | [StreamUsage](arkts-apis-audio-e.md#streamusage) | Yes  | Audio stream usage.|

**Return value**

| Type                  | Description                                                    |
| ---------------------- | -------------------------------------------------------- |
| boolean | Check result. The value **true** means that the stream is active, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioStreamManager.isStreamActive(audio.StreamUsage.STREAM_USAGE_MUSIC);
  console.info(`Indicate that the active status of the stream is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the active status of the stream ${error}.`);
}
```

## getAudioEffectInfoArray<sup>10+</sup>

getAudioEffectInfoArray(usage: StreamUsage, callback: AsyncCallback&lt;AudioEffectInfoArray&gt;): void

Obtains information about the audio effect mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                               | Mandatory    | Description                        |
| -------- | ----------------------------------- | -------- | --------------------------- |
| usage    | [StreamUsage](arkts-apis-audio-e.md#streamusage)                                    | Yes    |  Audio stream usage.               |
| callback | AsyncCallback<[AudioEffectInfoArray](arkts-apis-audio-AudioStreamManager.md#getaudioeffectinfoarray10)> | Yes    | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the information about the audio effect mode obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getAudioEffectInfoArray(audio.StreamUsage.STREAM_USAGE_MUSIC, async (err: BusinessError, audioEffectInfoArray: audio.AudioEffectInfoArray) => {
  console.info('getAudioEffectInfoArray **** Get Callback Called ****');
  if (err) {
    console.error(`getAudioEffectInfoArray :ERROR: ${err}`);
    return;
  } else {
    console.info(`The effect modes are: ${audioEffectInfoArray}`);
  }
});
```

## getAudioEffectInfoArray<sup>10+</sup>

getAudioEffectInfoArray(usage: StreamUsage): Promise&lt;AudioEffectInfoArray&gt;

Obtains information about the audio effect mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                               | Mandatory    | Description                        |
| -------- | ----------------------------------- | -------- | --------------------------- |
| usage    | [StreamUsage](arkts-apis-audio-e.md#streamusage)         | Yes    |  Audio stream usage.              |

**Return value**

| Type                                                                     | Description                                   |
| --------------------------------------------------------------------------| --------------------------------------- |
| Promise<[AudioEffectInfoArray](arkts-apis-audio-AudioStreamManager.md#getaudioeffectinfoarray10)>                  | Promise used to return the information about the audio effect mode obtained.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioStreamManager.getAudioEffectInfoArray(audio.StreamUsage.STREAM_USAGE_MUSIC).then((audioEffectInfoArray: audio.AudioEffectInfoArray) => {
  console.info('getAudioEffectInfoArray ######### Get Promise is called ##########');
  console.info(`The effect modes are: ${audioEffectInfoArray}`);
}).catch((err: BusinessError) => {
  console.error(`getAudioEffectInfoArray :ERROR: ${err}`);
});
```

## getAudioEffectInfoArraySync<sup>10+</sup>

getAudioEffectInfoArraySync(usage: StreamUsage): AudioEffectInfoArray

Obtains information about the audio effect mode in use. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name   | Type                               | Mandatory    | Description                        |
| -------- | ----------------------------------- | -------- | --------------------------- |
| usage    | [StreamUsage](arkts-apis-audio-e.md#streamusage)         | Yes    |  Audio stream usage.              |

**Return value**

| Type                                                                     | Description                                   |
| --------------------------------------------------------------------------| --------------------------------------- |
| [AudioEffectInfoArray](arkts-apis-audio-AudioStreamManager.md#getaudioeffectinfoarray10)                  | Information about the audio effect mode.     |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioEffectInfoArray: audio.AudioEffectInfoArray = audioStreamManager.getAudioEffectInfoArraySync(audio.StreamUsage.STREAM_USAGE_MUSIC);
  console.info(`The effect modes are: ${audioEffectInfoArray}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`getAudioEffectInfoArraySync ERROR: ${error}`);
}
```

## isAcousticEchoCancelerSupported<sup>20+</sup>

isAcousticEchoCancelerSupported(sourceType: SourceType): boolean

Checks whether the specified audio source type supports echo cancellation.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name   | Type                               | Mandatory    | Description                        |
| -------- | ----------------------------------- | -------- | --------------------------- |
| sourceType    | [SourceType](arkts-apis-audio-e.md#sourcetype8)         | Yes    |  Audio source type.              |

**Return value**

| Type                                                                     | Description                                   |
| --------------------------------------------------------------------------| --------------------------------------- |
|  boolean     | Check result. The value **true** means that echo cancellation is supported, and **false** means the opposite.       |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isSupportAEC = audioStreamManager.isAcousticEchoCancelerSupported(audio.SourceType.SOURCE_TYPE_LIVE);
  console.info(`[AEC Support] SourceType: ${audio.SourceType.SOURCE_TYPE_LIVE}, Status: ${isSupportAEC}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`isAcousticEchoCancelerSupported ERROR: ${error}`);
}
```

## isAudioLoopbackSupported<sup>20+</sup>

isAudioLoopbackSupported(mode: AudioLoopbackMode): boolean

Checks whether the current system supports the specified audio loopback mode.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name   | Type                               | Mandatory    | Description                        |
| -------- | ----------------------------------- | -------- | --------------------------- |
| mode     | [AudioLoopbackMode](arkts-apis-audio-e.md#audioloopbackmode20)         | Yes    |  Audio loopback mode.              |

**Return value**

| Type                                                                     | Description                                   |
| --------------------------------------------------------------------------| --------------------------------------- |
|  boolean     | Check result. The value **true** is returned if the audio loopback mode is supported, and **false** is returned otherwise.       |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isSupported = audioStreamManager.isAudioLoopbackSupported(audio.AudioLoopbackMode.HARDWARE);
  console.info(`[Audio loopback Support] mode: ${audio.AudioLoopbackMode.HARDWARE}, Status: ${isSupported}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`isAudioLoopbackSupported ERROR: ${error}`);
}
```

## isRecordingAvailable<sup>20+</sup>

isRecordingAvailable(capturerInfo: AudioCapturerInfo): boolean

Checks whether recording can be started based on the audio source type in the audio capturer information.

**System capability**: SystemCapability.Multimedia.Audio.Capturer

**Parameters**

| Name   | Type                               | Mandatory    | Description                        |
| -------- | ----------------------------------- | -------- | --------------------------- |
| capturerInfo | [AudioCapturerInfo](arkts-apis-audio-i.md#audiocapturerinfo8) | Yes| Audio capturer information.|

**Return value**

| Type         | Description                                   |
| ------------ | --------------------------------------- |
|  boolean     | Check result. The value **true** is returned if recording can be started, and **false** is returned otherwise.<br>This API checks whether the specified audio source type in the capturer information can acquire focus. It should be called before starting audio recording to avoid conflicts with existing recording streams.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed.              |

**Example**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000,
  channels: audio.AudioChannel.CHANNEL_2,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
};

let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC,
  capturerFlags: 0
};

let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};

audio.createAudioCapturer(audioCapturerOptions, (err, data) => {
  if (err) {
    console.error(`AudioCapturer Created : Error: ${err}`);
  } else {
    console.info('AudioCapturer Created : Success : SUCCESS');
    let audioCapturer = data;
    try {
      let isAvailable = audioStreamManager.isRecordingAvailable(audioCapturerInfo);
      console.info(`[Recording Available] Status: ${isAvailable}`);
    } catch (err) {
      let error = err as BusinessError;
      console.error(`isRecordingAvailable ERROR: ${error}`);
    }
  }
});
```
