# Interface (AudioRenderer)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 8.

This interface provides APIs for audio rendering.

Before calling any API in AudioRenderer, you must use [createAudioRenderer](arkts-apis-audio-f.md#audiocreateaudiorenderer8) to create an AudioRenderer instance.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Audio.Renderer

| Name | Type                    | Read-Only| Optional| Description              |
| ----- | -------------------------- | ---- | ---- | ------------------ |
| state<sup>8+</sup> | [AudioState](arkts-apis-audio-e.md#audiostate8) | Yes  | No  | Audio renderer state.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let state: audio.AudioState = audioRenderer.state;
```

## getRendererInfo<sup>8+</sup>

getRendererInfo(callback: AsyncCallback<AudioRendererInfo\>): void

Obtains the information about this audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                    | Mandatory| Description                  |
| :------- | :------------------------------------------------------- | :--- | :--------------------- |
| callback | AsyncCallback<[AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio renderer information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRendererInfo((err: BusinessError, rendererInfo: audio.AudioRendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`);
});
```

## getRendererInfo<sup>8+</sup>

getRendererInfo(): Promise<AudioRendererInfo\>

Obtains the information about this audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                              | Description                           |
| -------------------------------------------------- | ------------------------------- |
| Promise<[AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)\> | Promise used to return the audio renderer information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRendererInfo().then((rendererInfo: audio.AudioRendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`)
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: RendererInfo :ERROR: ${err}`);
});
```

## getRendererInfoSync<sup>10+</sup>

getRendererInfoSync(): AudioRendererInfo

Obtains the information about this audio renderer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                              | Description                           |
| -------------------------------------------------- | ------------------------------- |
| [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8) | Audio renderer information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rendererInfo: audio.AudioRendererInfo = audioRenderer.getRendererInfoSync();
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`)
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRenderLog: RendererInfo :ERROR: ${error}`);
}
```

## getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

Obtains the stream information of this audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                | Mandatory| Description                |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<[AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8)\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getStreamInfo((err: BusinessError, streamInfo: audio.AudioStreamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
});
```

## getStreamInfo<sup>8+</sup>

getStreamInfo(): Promise<AudioStreamInfo\>

Obtains the stream information of this audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                          | Description                  |
| :--------------------------------------------- | :--------------------- |
| Promise<[AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8)\> | Promise used to return the stream information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getStreamInfo().then((streamInfo: audio.AudioStreamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getStreamInfoSync<sup>10+</sup>

getStreamInfoSync(): AudioStreamInfo

Obtains the stream information of this audio renderer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                          | Description                  |
| :--------------------------------------------- | :--------------------- |
| [AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8) | Stream information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let streamInfo: audio.AudioStreamInfo = audioRenderer.getStreamInfoSync();
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## getAudioStreamId<sup>9+</sup>

getAudioStreamId(callback: AsyncCallback<number\>): void

Obtains the stream ID of this audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                | Mandatory| Description                |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<number\> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream ID obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioStreamId((err: BusinessError, streamId: number) => {
  console.info(`Renderer GetStreamId: ${streamId}`);
});
```

## getAudioStreamId<sup>9+</sup>

getAudioStreamId(): Promise<number\>

Obtains the stream ID of this audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                          | Description                  |
| :--------------------------------------------- | :--------------------- |
| Promise<number\> | Promise used to return the stream ID.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioStreamId().then((streamId: number) => {
  console.info(`Renderer getAudioStreamId: ${streamId}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioStreamIdSync<sup>10+</sup>

getAudioStreamIdSync(): number

Obtains the stream ID of this audio renderer. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                          | Description                  |
| :--------------------------------------------- | :--------------------- |
| number | Stream ID.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let streamId: number = audioRenderer.getAudioStreamIdSync();
  console.info(`Renderer getAudioStreamIdSync: ${streamId}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## setAudioEffectMode<sup>10+</sup>

setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void

Sets an audio effect mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                    | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| mode     | [AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)    | Yes  | Audio effect mode to set.              |
| callback | AsyncCallback\<void>                     | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | ----------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set params');
  } else {
    console.info('Callback invoked to indicate a successful audio effect mode setting.');
  }
});
```

## setAudioEffectMode<sup>10+</sup>

setAudioEffectMode(mode: AudioEffectMode): Promise\<void>

Sets an audio effect mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type                                    | Mandatory| Description        |
| ------ | ---------------------------------------- | ---- | ------------ |
| mode   | [AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)   | Yes  | Audio effect mode to set.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | ---------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT).then(() => {
  console.info('setAudioEffectMode SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioEffectMode<sup>10+</sup>

getAudioEffectMode(callback: AsyncCallback\<AudioEffectMode>): void

Obtains the audio effect mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                   | Mandatory| Description              |
| -------- | ------------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback<[AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the audio effect mode obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioEffectMode((err: BusinessError, effectMode: audio.AudioEffectMode) => {
  if (err) {
    console.error('Failed to get params');
  } else {
    console.info(`getAudioEffectMode: ${effectMode}`);
  }
});
```

## getAudioEffectMode<sup>10+</sup>

getAudioEffectMode(): Promise\<AudioEffectMode>

Obtains the audio effect mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                             | Description                     |
| ------------------------------------------------- | ------------------------- |
| Promise<[AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)> | Promise used to return the audio effect mode.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioEffectMode().then((effectMode: audio.AudioEffectMode) => {
  console.info(`getAudioEffectMode: ${effectMode}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

Starts this audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object. If the operation fails, an error object with one of the following error codes is returned:<br>Error code 6800301: indicates abnormal status, focus preemption failure, and abnormal system processing. For details, see system logs.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.start((err: BusinessError) => {
  if (err) {
    console.error('Renderer start failed.');
  } else {
    console.info('Renderer start success.');
  }
});
```

## start<sup>8+</sup>

start(): Promise<void\>

Starts this audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise object, which indicates that the renderer is started successfully. If the operation fails, an error object with one of the following error codes is returned:<br>Error code 6800301: indicates abnormal status, focus preemption failure, and abnormal system processing. For details, see system logs.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.start().then(() => {
  console.info('Renderer started');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

Pauses this audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.pause((err: BusinessError) => {
  if (err) {
    console.error('Renderer pause failed');
  } else {
    console.info('Renderer paused.');
  }
});
```

## pause<sup>8+</sup>

pause(): Promise\<void>

Pauses this audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.pause().then(() => {
  console.info('Renderer paused');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## drain<sup>8+</sup>

drain(callback: AsyncCallback\<void>): void

Drains the playback buffer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.drain((err: BusinessError) => {
  if (err) {
    console.error('Renderer drain failed');
  } else {
    console.info('Renderer drained.');
  }
});
```

## drain<sup>8+</sup>

drain(): Promise\<void>

Drains the playback buffer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.drain().then(() => {
  console.info('Renderer drained successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## flush<sup>11+</sup>

flush(): Promise\<void>

Flushes the buffer. This API is available when [AudioState](arkts-apis-audio-e.md#audiostate8) is **STATE_RUNNING**, **STATE_PAUSED**, or **STATE_STOPPED**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800103 | Operation not permit at current state. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.flush().then(() => {
  console.info('Renderer flushed successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

Stops this audio renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.stop((err: BusinessError) => {
  if (err) {
    console.error('Renderer stop failed');
  } else {
    console.info('Renderer stopped.');
  }
});
```

## stop<sup>8+</sup>

stop(): Promise\<void>

Stops this audio renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.stop().then(() => {
  console.info('Renderer stopped successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

Releases the renderer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.release((err: BusinessError) => {
  if (err) {
    console.error('Renderer release failed');
  } else {
    console.info('Renderer released.');
  }
});
```

## release<sup>8+</sup>

release(): Promise\<void>

Releases the renderer. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.release().then(() => {
  console.info('Renderer released successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback\<number>): void

Obtains the timestamp of the current playback position, measured in nanoseconds from the Unix epoch (January 1, 1970). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                  | Mandatory| Description            |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of nanoseconds obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTime((err: BusinessError, timestamp: number) => {
  console.info(`Current timestamp: ${timestamp}`);
});
```

## getAudioTime<sup>8+</sup>

getAudioTime(): Promise\<number>

Obtains the timestamp of the current playback position, measured in nanoseconds from the Unix epoch (January 1, 1970). This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                   |
| ---------------- | ----------------------- |
| Promise\<number> | Promise used to return the timestamp.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTime().then((timestamp: number) => {
  console.info(`Current timestamp: ${timestamp}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioTimeSync<sup>10+</sup>

getAudioTimeSync(): number

Obtains the timestamp of the current playback position, measured in nanoseconds from the Unix epoch (January 1, 1970). This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                   |
| ---------------- | ----------------------- |
| number | Timestamp.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let timestamp: number = audioRenderer.getAudioTimeSync();
  console.info(`Current timestamp: ${timestamp}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## getAudioTimestampInfo<sup>19+</sup>

getAudioTimestampInfo(): Promise\<AudioTimestampInfo>

Obtains the timestamp and position information of an output audio stream. It adapts to the speed adjustment interface. This API uses a promise to return the result.

This information is commonly used for audio and video synchronization.

Note that when the actual playback position (**framePosition**) is 0, the timestamp remains fixed until the stream begins to play. The playback position is also reset when **Flush** is called.

Additionally, changes in the audio stream route, such as switching devices or output types, will reset the playback position, whereas the timestamp keeps increasing. You are advised to call this API to obtain the corresponding value only when the actual playback position and timestamp are stable. This API adapts to the speed adjustment interface. For example, if the playback speed is set to 2x, the rate at which the playback position increases is also twice the normal speed.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                                   | Description                   |
|-------------------------------------------------------| ----------------------- |
| Promise\<[AudioTimestampInfo](arkts-apis-audio-i.md#audiotimestampinfo19)> | Promise used to return the audio stream timestamp and the current data frame position.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800103 | Operation not permit at current state. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTimestampInfo().then((audioTimestampInfo: audio.AudioTimestampInfo) => {
  console.info(`Current timestamp: ${audioTimestampInfo.timestamp}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioTimestampInfoSync<sup>19+</sup>

getAudioTimestampInfoSync(): AudioTimestampInfo

Obtains the information about the audio stream timestamp and the current data frame position. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                   |
| ---------------- | ----------------------- |
| [AudioTimestampInfo](arkts-apis-audio-i.md#audiotimestampinfo19) | Information about the audio stream timestamp and the current data frame position.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800103 | Operation not permit at current state. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioTimestampInfo: audio.AudioTimestampInfo = audioRenderer.getAudioTimestampInfoSync();
  console.info(`Current timestamp: ${audioTimestampInfo.timestamp}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback\<number>): void

Obtains a reasonable minimum buffer size in bytes for rendering. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum buffer size obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number;

audioRenderer.getBufferSize((err: BusinessError, data: number) => {
  if (err) {
    console.error('getBufferSize error');
  } else {
    console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
    bufferSize = data;
  }
});
```

## getBufferSize<sup>8+</sup>

getBufferSize(): Promise\<number>

Obtains a reasonable minimum buffer size in bytes for rendering. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise\<number> | Promise used to return the buffer size.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number;

audioRenderer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});
```

## getBufferSizeSync<sup>10+</sup>

getBufferSizeSync(): number

Obtains a reasonable minimum buffer size in bytes for rendering. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| number | Buffer size.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number = 0;

try {
  bufferSize = audioRenderer.getBufferSizeSync();
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${bufferSize}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${error}`);
}
```

## setSpeed<sup>11+</sup>

setSpeed(speed: number): void

Sets the playback speed.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type                                    | Mandatory| Description                  |
| ------ | ---------------------------------------- | ---- |----------------------|
| speed | number | Yes  | Playback speed, which ranges from 0.25 to 4.0.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioRenderer.setSpeed(1.5);
```

## getSpeed<sup>11+</sup>

getSpeed(): number

Obtains the playback speed.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                             | Description       |
| ------------------------------------------------- |-----------|
| number | Playback speed.|

**Example**

```ts
let speed = audioRenderer.getSpeed();
```

## setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode): Promise&lt;void&gt;

Sets the audio interruption mode for the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name    | Type                               | Mandatory  | Description       |
| ---------- | ---------------------------------- | ------ | ---------- |
| mode       | [InterruptMode](arkts-apis-audio-e.md#interruptmode9)    | Yes    | Audio interruption mode. |

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mode = 0;

audioRenderer.setInterruptMode(mode).then(() => {
  console.info('setInterruptMode Success!');
}).catch((err: BusinessError) => {
  console.error(`setInterruptMode Fail: ${err}`);
});
```
## setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void

Sets the audio interruption mode for the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name  | Type                               | Mandatory  | Description           |
| ------- | ----------------------------------- | ------ | -------------- |
|mode     | [InterruptMode](arkts-apis-audio-e.md#interruptmode9)     | Yes    | Audio interruption mode.|
|callback | AsyncCallback\<void>                 | Yes    |Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mode = 1;

audioRenderer.setInterruptMode(mode, (err: BusinessError) => {
  if(err){
    console.error(`setInterruptMode Fail: ${err}`);
  }
  console.info('setInterruptMode Success!');
});
```

## setInterruptModeSync<sup>10+</sup>

setInterruptModeSync(mode: InterruptMode): void

Sets the audio interruption mode for the application. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name    | Type                               | Mandatory  | Description       |
| ---------- | ---------------------------------- | ------ | ---------- |
| mode       | [InterruptMode](arkts-apis-audio-e.md#interruptmode9)    | Yes    | Audio interruption mode. |

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
  audioRenderer.setInterruptModeSync(0);
  console.info('setInterruptMode Success!');
} catch (err) {
  let error = err as BusinessError;
  console.error(`setInterruptMode Fail: ${error}`);
}
```

## setVolume<sup>9+</sup>

setVolume(volume: number): Promise&lt;void&gt;

Sets the volume for the audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type   | Mandatory  | Description                |
| ---------- | ------- | ------ | ------------------- |
| volume     | number  | Yes    | Volume to set, which is in the range [0.0, 1.0].|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5).then(() => {
  console.info('setVolume Success!');
}).catch((err: BusinessError) => {
  console.error(`setVolume Fail: ${err}`);
});
```
## setVolume<sup>9+</sup>

setVolume(volume: number, callback: AsyncCallback\<void>): void

Sets the volume for the audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type      | Mandatory  | Description                |
| ------- | -----------| ------ | ------------------- |
|volume   | number     | Yes    | Volume to set, which is in the range [0.0, 1.0].|
|callback | AsyncCallback\<void> | Yes    |Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5, (err: BusinessError) => {
  if(err){
    console.error(`setVolume Fail: ${err}`);
    return;
  }
  console.info('setVolume Success!');
});
```
## getVolume<sup>12+</sup>

getVolume(): number

Obtains the volume of the audio stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| number | Volume, in the range [0.0, 1.0].|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getVolume();
  console.info(`Indicate that the volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume, error ${error}.`);
}
```

## getMinStreamVolume<sup>10+</sup>

getMinStreamVolume(callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum volume of the audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type      | Mandatory  | Description                |
| ------- | -----------| ------ | ------------------- |
|callback |AsyncCallback&lt;number&gt; | Yes    |Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum volume (range [0, 1]) obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMinStreamVolume((err: BusinessError, minVolume: number) => {
  if (err) {
    console.error(`getMinStreamVolume error: ${err}`);
  } else {
    console.info(`getMinStreamVolume Success! ${minVolume}`);
  }
});
```
## getMinStreamVolume<sup>10+</sup>

getMinStreamVolume(): Promise&lt;number&gt;

Obtains the minimum volume of the audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt;| Promise used to return the minimum volume, which is in the range [0, 1].|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMinStreamVolume().then((value: number) => {
  console.info(`Get min stream volume Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get min stream volume Fail: ${err}`);
});
```

## getMinStreamVolumeSync<sup>10+</sup>

getMinStreamVolumeSync(): number

Obtains the minimum volume of the audio stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| number| Minimum volume, which is in the range [0, 1].|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getMinStreamVolumeSync();
  console.info(`Get min stream volume Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get min stream volume Fail: ${error}`);
}
```

## getMaxStreamVolume<sup>10+</sup>

getMaxStreamVolume(callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum volume of the audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type      | Mandatory  | Description                |
| ------- | -----------| ------ | ------------------- |
|callback | AsyncCallback&lt;number&gt; | Yes    |Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the maximum volume (range [0, 1]) obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMaxStreamVolume((err: BusinessError, maxVolume: number) => {
  if (err) {
    console.error(`getMaxStreamVolume Fail: ${err}`);
  } else {
    console.info(`getMaxStreamVolume Success! ${maxVolume}`);
  }
});
```
## getMaxStreamVolume<sup>10+</sup>

getMaxStreamVolume(): Promise&lt;number&gt;

Obtains the maximum volume of the audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt;| Promise used to return the maximum volume, which is in the range [0, 1].|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMaxStreamVolume().then((value: number) => {
  console.info(`Get max stream volume Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get max stream volume Fail: ${err}`);
});
```

## getMaxStreamVolumeSync<sup>10+</sup>

getMaxStreamVolumeSync(): number

Obtains the maximum volume of the audio stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| number| Maximum volume, which is in the range [0, 1].|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getMaxStreamVolumeSync();
  console.info(`Get max stream volume Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get max stream volume Fail: ${error}`);
}
```

## getUnderflowCount<sup>10+</sup>

getUnderflowCount(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of underflow audio frames in the audio stream that is being played. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name | Type      | Mandatory  | Description                |
| ------- | -----------| ------ | ------------------- |
|callback | AsyncCallback&lt;number&gt; | Yes    |Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of underloaded audio frames obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getUnderflowCount((err: BusinessError, underflowCount: number) => {
  if (err) {
    console.error(`getUnderflowCount Fail: ${err}`);
  } else {
    console.info(`getUnderflowCount Success! ${underflowCount}`);
  }
});
```
## getUnderflowCount<sup>10+</sup>

getUnderflowCount(): Promise&lt;number&gt;

Obtains the number of underflow audio frames in the audio stream that is being played. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt;| Promise used to return the number of underflow audio frames.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getUnderflowCount().then((value: number) => {
  console.info(`Get underflow count Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get underflow count Fail: ${err}`);
});
```

## getUnderflowCountSync<sup>10+</sup>

getUnderflowCountSync(): number

Obtains the number of underflow audio frames in the audio stream that is being played. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| number| Number of underflow audio frames.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getUnderflowCountSync();
  console.info(`Get underflow count Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get underflow count Fail: ${error}`);
}
```

## getCurrentOutputDevices<sup>10+</sup>

getCurrentOutputDevices(callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

Obtains the output device information of the audio stream. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name | Type      | Mandatory  | Description                |
| ------- | -----------| ------ | ------------------- |
|callback | AsyncCallback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)>| Yes    |Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the output device information obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getCurrentOutputDevices((err: BusinessError, deviceInfo: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`getCurrentOutputDevices Fail: ${err}`);
  } else {
    for (let i = 0; i < deviceInfo.length; i++) {
      console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
      console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
      console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
      console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
      console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
      console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
      console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
      console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
    }
  }
});
```
## getCurrentOutputDevices<sup>10+</sup>

getCurrentOutputDevices(): Promise&lt;AudioDeviceDescriptors&gt;

Obtains the output device information of the audio stream. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt;| Promise used to return the output device information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getCurrentOutputDevices().then((deviceInfo: audio.AudioDeviceDescriptors) => {
  for (let i = 0; i < deviceInfo.length; i++) {
    console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
    console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
    console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
    console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
    console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
    console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
    console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
    console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Get current output devices Fail: ${err}`);
});
```

## getCurrentOutputDevicesSync<sup>10+</sup>

getCurrentOutputDevicesSync(): AudioDeviceDescriptors

Obtains the output device information of the audio stream. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | Output device information.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let deviceInfo: audio.AudioDeviceDescriptors = audioRenderer.getCurrentOutputDevicesSync();
  for (let i = 0; i < deviceInfo.length; i++) {
    console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
    console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
    console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
    console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
    console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
    console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
    console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
    console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get current output devices Fail: ${error}`);
}
```
## setChannelBlendMode<sup>11+</sup>

setChannelBlendMode(mode: ChannelBlendMode): void

Sets the audio channel blending mode. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| mode | [ChannelBlendMode](arkts-apis-audio-e.md#channelblendmode11) | Yes  | Audio channel blending mode.                                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permit at current state.    |

**Example**

```ts
let mode = audio.ChannelBlendMode.MODE_DEFAULT;

audioRenderer.setChannelBlendMode(mode);
console.info(`BlendMode: ${mode}`);
```
## setVolumeWithRamp<sup>11+</sup>

setVolumeWithRamp(volume: number, duration: number): void

Sets a volume ramp. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volume     | number | Yes  | Target volume, within the range [0.0, 1.0].                                            |
| duration     | number | Yes  | Time range during which the ramp applies, in ms.                                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
let volume = 0.5;
let duration = 1000;

audioRenderer.setVolumeWithRamp(volume, duration);
console.info(`setVolumeWithRamp: ${volume}`);
```

## setSilentModeAndMixWithOthers<sup>12+</sup>

setSilentModeAndMixWithOthers(on: boolean): void

Sets the silent mode in concurrent playback for the audio stream.

If the silent mode in concurrent playback is enabled, the system mutes the audio stream and does not interrupt other audio streams. If the silent mode in concurrent playback is disabled, the audio stream can gain focus based on the system focus policy.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type                                    | Mandatory| Description                  |
| ------ | ---------------------------------------- | ---- |----------------------|
| on | boolean | Yes  | Whether to enable or disable the silent mode in concurrent playback for the audio stream. The value **true** means to enable the silent mode in concurrent playback, and **false** means the opposite.|

**Example**

```ts
audioRenderer.setSilentModeAndMixWithOthers(true);
```

## getSilentModeAndMixWithOthers<sup>12+</sup>

getSilentModeAndMixWithOthers(): boolean

Obtains the silent mode in concurrent playback for the audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                             | Description       |
| ------------------------------------------------- |-----------|
| boolean | Enabled status. The value **true** means that the silent mode in concurrent playback is enabled, and **false** means the opposite.|

**Example**

```ts
let on = audioRenderer.getSilentModeAndMixWithOthers();
```

## setDefaultOutputDevice<sup>12+</sup>

setDefaultOutputDevice(deviceType: DeviceType): Promise&lt;void&gt;

Sets the default audio output device. This API uses a promise to return the result.

> **NOTE**
>
> - This API applies only to the scenarios where [StreamUsage](arkts-apis-audio-e.md#streamusage) is set to voice message, VoIP voice calls, or VoIP video calls. It supports only receivers, speakers, and system default devices.
>
> - This API can be called at any time after an AudioRenderer instance is created. The system records the device set by the application. When the application is started, if an external device such as a Bluetooth or wired headset is connected, the system preferentially uses the external device to play sound. Otherwise, the system uses this default device to play sound.
>
> - This API has a lower priority than [AVCastPicker](../apis-avsession-kit/ohos-multimedia-avcastpicker.md#avcastpicker). If you have already switched the audio device using AVCastPicker, using this API to switch devices again does not take effect.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name    | Type            | Mandatory  | Description                                                     |
| ---------- |----------------| ------ |---------------------------------------------------------|
| deviceType | [DeviceType](arkts-apis-audio-e.md#devicetype) | Yes    | Device type.<br>The options are **EARPIECE**, **SPEAKER**, and **DEFAULT**.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permit at current state.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// This API can be called at any time after an AudioRenderer instance is created.
// If the API is called when no audio is being played, the system records the default device set by the application. When the application starts playing, the sound is played from this default device.
// If the API is called when audio is being played and no external device, such as a Bluetooth or wired headset, is connected, the system immediately switches to the default device. If an external device is connected, the system records the default device and switches to it once the external device is disconnected.
audioRenderer.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
  console.info('setDefaultOutputDevice Success!');
}).catch((err: BusinessError) => {
  console.error(`setDefaultOutputDevice Fail: ${err}`);
});
```

## on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void

Subscribes to the audio interruption event, which is triggered when the audio focus is changed. This API uses an asynchronous callback to return the result.

The AudioRenderer instance proactively gains the focus when the **start** event occurs and releases the focus when the **pause** or **stop** event occurs. Therefore, you do not need to request to gain or release the focus.

After this API is called, an [InterruptEvent](arkts-apis-audio-i.md#interruptevent9) is received when the AudioRenderer instance fails to obtain the focus or an audio interruption event occurs (for example, the audio stream is interrupted by others). It is recommended that the application perform further processing based on the **InterruptEvent** information. For details, see [Introduction to Audio Focus and Audio Sessions](../../media/audio/audio-playback-concurrency.md).

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                       |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | string                                       | Yes  | Event type. The event **'audioInterrupt'** is triggered when the audio focus is changed.|
| callback | Callback\<[InterruptEvent](arkts-apis-audio-i.md#interruptevent9)\> | Yes  | Callback used to return the event information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

let isPlaying: boolean; // An identifier specifying whether rendering is in progress.
let isDucked: boolean; // An identifier specifying whether the audio volume is reduced.
onAudioInterrupt();

async function onAudioInterrupt(){
  audioRenderer.on('audioInterrupt', (interruptEvent: audio.InterruptEvent) => {
    // When an audio interruption event occurs, the AudioRenderer receives the interruptEvent callback and performs processing based on the content in the callback.
    // 1. (Optional) The AudioRenderer reads the value of interruptEvent.forceType to see whether the system has forcibly performed the operation.
    // Note: In the default focus policy, INTERRUPT_HINT_RESUME maps to the force type INTERRUPT_SHARE, and others map to INTERRUPT_FORCE. Therefore, the value of forceType does not need to be checked.
    // 2. (Mandatory) The AudioRenderer then reads the value of interruptEvent.hintType and performs corresponding processing.
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
          console.info('Invalid interruptEvent');
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
          console.info('Invalid interruptEvent');
          break;
      }
    }
  });
}
```

## off('audioInterrupt')<sup>18+</sup>

off(type: 'audioInterrupt', callback?: Callback&lt;InterruptEvent&gt;): void

Unsubscribes from the audio interruption event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Interrupt

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | Yes  | Event type. The event **'audioInterrupt'** is triggered when the audio focus is changed.|
| callback | Callback\<[InterruptEvent](arkts-apis-audio-i.md#interruptevent9)\> | No|  Callback used to return the event information.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioRenderer.off('audioInterrupt');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let isPlaying: boolean; // An identifier specifying whether rendering is in progress.
let isDucked: boolean; // An identifier specifying whether the audio volume is reduced.

let audioInterruptCallback = (interruptEvent: audio.InterruptEvent) => {
  // When an audio interruption event occurs, the AudioRenderer receives the interruptEvent callback and performs processing based on the content in the callback.
  // 1. (Optional) The AudioRenderer reads the value of interruptEvent.forceType to see whether the system has forcibly performed the operation.
  // Note: In the default focus policy, INTERRUPT_HINT_RESUME maps to the force type INTERRUPT_SHARE, and others map to INTERRUPT_FORCE. Therefore, the value of forceType does not need to be checked.
  // 2. (Mandatory) The AudioRenderer then reads the value of interruptEvent.hintType and performs corresponding processing.
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
        console.info('Invalid interruptEvent');
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
        console.info('Invalid interruptEvent');
        break;
    }
  }
};

audioRenderer.on('audioInterrupt', audioInterruptCallback);

audioRenderer.off('audioInterrupt', audioInterruptCallback);
```

## on('markReach')<sup>8+</sup>

on(type: 'markReach', frame: number, callback: Callback&lt;number&gt;): void

Subscribes to the mark reached event, which is triggered (only once) when the number of frames rendered reaches the value of the **frame** parameter. This API uses an asynchronous callback to return the result.

For example, if **frame** is set to **100**, the callback is invoked when the number of rendered frames reaches the 100th frame.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                    | Mandatory| Description                                     |
| :------- | :----------------------- | :--- | :---------------------------------------- |
| type     | string                   | Yes  | Event type. The event **'markReach'** is triggered when the number of frames rendered reaches the value of the **frame** parameter.|
| frame    | number                   | Yes  | Number of frames to trigger the event. The value must be greater than **0**.        |
| callback | Callback\<number>         | Yes  | Callback used to return the value of the **frame** parameter.|

**Example**

```ts
audioRenderer.on('markReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```


## off('markReach')<sup>8+</sup>

off(type: 'markReach', callback?: Callback&lt;number&gt;): void

Unsubscribes from the mark reached event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type  | Mandatory| Description                                             |
| :----- | :----- | :--- | :------------------------------------------------ |
| type   | string | Yes  | Event type. The event **'markReach'** is triggered when the number of frames rendered reaches the value of the **frame** parameter.|
| callback<sup>18+</sup> | Callback\<number>         | No | Callback used to return the value of the **frame** parameter.|

**Example**

```ts
// Cancel all subscriptions to the event.
audioRenderer.off('markReach');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let markReachCallback = (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
};

audioRenderer.on('markReach', 1000, markReachCallback);

audioRenderer.off('markReach', markReachCallback);
```

## on('periodReach')<sup>8+</sup>

on(type: 'periodReach', frame: number, callback: Callback&lt;number&gt;): void

Subscribes to the period reached event, which is triggered each time the number of frames rendered reaches the value of the **frame** parameter. In other words, the information is reported periodically. This API uses an asynchronous callback to return the result.

For example, if **frame** is set to **10**, the callback is invoked each time 10 frames are rendered, for example, when the number of frames rendered reaches the 10th frame, 20th frame, and 30th frame.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                    | Mandatory| Description                                       |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | Yes  | Event type. The event **'periodReach'** is triggered each time the number of frames rendered reaches the value of the **frame** parameter.|
| frame    | number                   | Yes  | Number of frames to trigger the event. The value must be greater than **0**.          |
| callback | Callback\<number>         | Yes  | Callback used to return the value of the **frame** parameter.|

**Example**

```ts
audioRenderer.on('periodReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```

## off('periodReach')<sup>8+</sup>

off(type: 'periodReach', callback?: Callback&lt;number&gt;): void

Unsubscribes from the period reached event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| :----- | :----- | :--- | :-------------------------------------------------- |
| type   | string | Yes  | Event type. The event **'periodReach'** is triggered each time the number of frames rendered reaches the value of the **frame** parameter.|
| callback<sup>18+</sup> | Callback\<number>         | No | Callback used to return the value of the **frame** parameter.|

**Example**

```ts
// Cancel all subscriptions to the event.
audioRenderer.off('periodReach');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let periodReachCallback = (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
};

audioRenderer.on('periodReach', 1000, periodReachCallback);

audioRenderer.off('periodReach', periodReachCallback);
```

## on('stateChange')<sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

Subscribes to the audio renderer state change event, which is triggered when the state of the audio renderer is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'stateChange'** is triggered when the state of the audio renderer is changed.|
| callback | Callback\<[AudioState](arkts-apis-audio-e.md#audiostate8)> | Yes  | Callback used to return the audio status.|

**Example**

```ts
audioRenderer.on('stateChange', (state: audio.AudioState) => {
  if (state == 1) {
    console.info('audio renderer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio renderer state is: STATE_RUNNING');
  }
});
```

## off('stateChange')<sup>18+</sup>

off(type: 'stateChange', callback?: Callback&lt;AudioState&gt;): void

Unsubscribes from the audio renderer state change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type  | Mandatory| Description                                               |
| :----- | :----- | :--- | :-------------------------------------------------- |
| type   | string | Yes  | Event type. The event **'stateChange'** is triggered when the state of the audio renderer is changed.|
| callback | Callback\<[AudioState](arkts-apis-audio-e.md#audiostate8)> | No| Callback used to return the audio status.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioRenderer.off('stateChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let stateChangeCallback = (state: audio.AudioState) => {
  if (state == 1) {
    console.info('audio renderer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio renderer state is: STATE_RUNNING');
  }
};

audioRenderer.on('stateChange', stateChangeCallback);

audioRenderer.off('stateChange', stateChangeCallback);
```

## on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void

Subscribes to the audio output device change event, which is triggered when an audio output device is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'outputDeviceChange'** is triggered when an audio output device is changed.|
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | Yes  | Callback used to return the output device descriptor of the current audio stream.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioRenderer.on('outputDeviceChange', (deviceInfo: audio.AudioDeviceDescriptors) => {
  console.info(`DeviceInfo id: ${deviceInfo[0].id}`);
  console.info(`DeviceInfo name: ${deviceInfo[0].name}`);
  console.info(`DeviceInfo address: ${deviceInfo[0].address}`);
});
```

## off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void

Unsubscribes from the audio output device change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                      | Mandatory| Description                                       |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | Yes  | Event type. The event **'outputDeviceChange'** is triggered when an audio output device is changed.|
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | No  | Callback used to return the output device descriptor of the current audio stream.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioRenderer.off('outputDeviceChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let outputDeviceChangeCallback = (deviceInfo: audio.AudioDeviceDescriptors) => {
  console.info(`DeviceInfo id: ${deviceInfo[0].id}`);
  console.info(`DeviceInfo name: ${deviceInfo[0].name}`);
  console.info(`DeviceInfo address: ${deviceInfo[0].address}`);
};

audioRenderer.on('outputDeviceChange', outputDeviceChangeCallback);

audioRenderer.off('outputDeviceChange', outputDeviceChangeCallback);
```

## on('outputDeviceChangeWithInfo')<sup>11+</sup>

on(type: 'outputDeviceChangeWithInfo', callback: Callback\<AudioStreamDeviceChangeInfo>): void

Subscribes to the change event of audio output devices and reasons, which is triggered when an audio output device is changed, and the change reason is reported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                                                      | Mandatory| Description                                         |
| :------- |:-------------------------------------------------------------------------| :--- |:--------------------------------------------|
| type     | string                                                                   | Yes  | Event type. The event **'outputDeviceChangeWithInfo'** is triggered when an audio output device is changed, and the change reason is reported.|
| callback | Callback\<[AudioStreamDeviceChangeInfo](arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | Yes  | Callback used to return the output device descriptor of the current audio stream and the change reason.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioRenderer.on('outputDeviceChangeWithInfo', (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`DeviceInfo id: ${deviceChangeInfo.devices[0].id}`);
  console.info(`DeviceInfo name: ${deviceChangeInfo.devices[0].name}`);
  console.info(`DeviceInfo address: ${deviceChangeInfo.devices[0].address}`);
  console.info(`Device change reason: ${deviceChangeInfo.changeReason}`);
});
```

## off('outputDeviceChangeWithInfo')<sup>11+</sup>

off(type: 'outputDeviceChangeWithInfo', callback?: Callback\<AudioStreamDeviceChangeInfo>): void

Unsubscribes from the change event of audio output devices and reasons. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Device

**Parameters**

| Name  | Type                                                                      | Mandatory| Description                                         |
| :------- |:-------------------------------------------------------------------------| :--- |:--------------------------------------------|
| type     | string | Yes  | Event type. The event **'outputDeviceChangeWithInfo'** is triggered when an audio output device is changed, and the change reason is reported.|
| callback | Callback\<[AudioStreamDeviceChangeInfo](arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | No  | Callback used to return the output device descriptor of the current audio stream and the change reason.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioRenderer.off('outputDeviceChangeWithInfo');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let outputDeviceChangeWithInfoCallback = (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`DeviceInfo id: ${deviceChangeInfo.devices[0].id}`);
  console.info(`DeviceInfo name: ${deviceChangeInfo.devices[0].name}`);
  console.info(`DeviceInfo address: ${deviceChangeInfo.devices[0].address}`);
  console.info(`Device change reason: ${deviceChangeInfo.changeReason}`);
};

audioRenderer.on('outputDeviceChangeWithInfo', outputDeviceChangeWithInfoCallback);

audioRenderer.off('outputDeviceChangeWithInfo', outputDeviceChangeWithInfoCallback);
```

## on('writeData')<sup>11+</sup>

on(type: 'writeData', callback: AudioRendererWriteDataCallback): void

Subscribes to the audio data write event, which is triggered when audio data needs to be written. This API uses an asynchronous callback to return the result.

The callback function is used only to write audio data. Do not call AudioRenderer APIs in it.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                            | Mandatory| Description                                 |
| :------- |:--------------------------------| :--- |:--------------------------------------|
| type     | string                           | Yes  | Event type. The event **'writeData'** is triggered when audio data needs to be written.|
| callback | [AudioRendererWriteDataCallback](arkts-apis-audio-t.md#audiorendererwritedatacallback12)   | Yes  | Callback used to write the data to the buffer.<br>API version 11 does not support the return of the callback result. API version 12 and later support the return of the callback result [AudioDataCallbackResult](arkts-apis-audio-e.md#audiodatacallbackresult12).       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import {fileIo as fs} from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let path = context.cacheDir;
// Ensure that the resource exists in the path.
let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
let writeDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  };

  try {
    fs.readSync(file.fd, buffer, options);
    bufferSize += buffer.byteLength;
    // This API does not return a callback result in API version 11, but does so in API version 12 and later versions.
    return audio.AudioDataCallbackResult.VALID;
  } catch (error) {
    console.error('Error reading file:', error);
    // This API does not return a callback result in API version 11, but does so in API version 12 and later versions.
    return audio.AudioDataCallbackResult.INVALID;
  }
};

audioRenderer.on('writeData', writeDataCallback);
audioRenderer.start().then(() => {
  console.info('Renderer started');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## off('writeData')<sup>11+</sup>

off(type: 'writeData', callback?: AudioRendererWriteDataCallback): void

Unsubscribes from the audio data write event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                            | Mandatory| Description                                 |
| :------- |:--------------------------------| :--- |:--------------------------------------|
| type     | string                           | Yes  | Event type. The event **'writeData'** is triggered when audio data needs to be written.|
| callback | [AudioRendererWriteDataCallback](arkts-apis-audio-t.md#audiorendererwritedatacallback12)   | No  | Callback used to write the data to the buffer.<br>API version 11 does not support the return of the callback result. API version 12 and later support the return of the callback result [AudioDataCallbackResult](arkts-apis-audio-e.md#audiodatacallbackresult12).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioRenderer.off('writeData');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let writeDataCallback = (data: ArrayBuffer) => {
    console.info(`write data: ${data}`);
};

audioRenderer.on('writeData', writeDataCallback);

audioRenderer.off('writeData', writeDataCallback);
```
## write<sup>(deprecated)</sup>

write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void

Writes the buffer. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [on('writeData')](#onwritedata11) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| buffer   | ArrayBuffer            | Yes  | Data to be written to the buffer.                               |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of bytes written; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

let bufferSize: number;
class Options {
  offset?: number;
  length?: number;
}
audioRenderer.getBufferSize().then((data: number)=> {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  console.info(`Buffer size: ${bufferSize}`);
  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.cacheDir;
  let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
  let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  fs.stat(filePath).then(async (stat: fs.Stat) => {
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize == 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    for (let i = 0;i < len; i++) {
      let options: Options = {
        offset: i * bufferSize,
        length: bufferSize
      };
      let readSize: number = await fs.read(file.fd, buf, options);
      let writeSize: number = await new Promise((resolve,reject)=>{
        audioRenderer.write(buf,(err: BusinessError, writeSize: number)=>{
          if(err){
            reject(err)
          }else{
            resolve(writeSize)
          }
        })
      })
    }
  });
  }).catch((err: BusinessError) => {
    console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});
```

## write<sup>(deprecated)</sup>

write(buffer: ArrayBuffer): Promise\<number>

Writes the buffer. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [on('writeData')](#onwritedata11) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| buffer   | ArrayBuffer            | Yes  | Data to be written to the buffer.                               |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise used to return the number of written bytes.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

let bufferSize: number;
class Options {
  offset?: number;
  length?: number;
}
audioRenderer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  console.info(`BufferSize: ${bufferSize}`);
  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.cacheDir;
  let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
  let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  fs.stat(filePath).then(async (stat: fs.Stat) => {
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize == 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    for (let i = 0;i < len; i++) {
      let options: Options = {
        offset: i * bufferSize,
        length: bufferSize
      };
      let readSize: number = await fs.read(file.fd, buf, options);
      try{
        let writeSize: number = await audioRenderer.write(buf);
      } catch(err) {
        let error = err as BusinessError;
        console.error(`audioRenderer.write err: ${error}`);
      }
    }
  });
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});
```

## setRenderRate<sup>(deprecated)</sup>

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void

Sets the render rate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [uninitialize][setSpeed](#setspeed11) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                    | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| rate     | [AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8) | Yes  | Audio render rate.            |
| callback | AsyncCallback\<void>                     | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set params');
  } else {
    console.info('Callback invoked to indicate a successful render rate setting.');
  }
});
```

## setRenderRate<sup>(deprecated)</sup>

setRenderRate(rate: AudioRendererRate): Promise\<void>

Sets the render rate. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [uninitialize][setSpeed](#setspeed11) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name| Type                                    | Mandatory| Description        |
| ------ | ---------------------------------------- | ---- | ------------ |
| rate   | [AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8) | Yes  | Audio render rate.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL).then(() => {
  console.info('setRenderRate SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getRenderRate<sup>(deprecated)</sup>

getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void

Obtains the audio renderer rate. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [getSpeed](#getspeed11) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name  | Type                                                   | Mandatory| Description              |
| -------- | ------------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback<[AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8)> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the render rate obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRenderRate((err: BusinessError, renderRate: audio.AudioRendererRate) => {
  console.info(`getRenderRate: ${renderRate}`);
});
```

## getRenderRate<sup>(deprecated)</sup>

getRenderRate(): Promise\<AudioRendererRate>

Obtains the audio renderer rate. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 11. You are advised to use [getSpeed](#getspeed11) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                             | Description                     |
| ------------------------------------------------- | ------------------------- |
| Promise<[AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8)> | Promise used to return the render rate.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRenderRate().then((renderRate: audio.AudioRendererRate) => {
  console.info(`getRenderRate: ${renderRate}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getRenderRateSync<sup>(deprecated)</sup>

getRenderRateSync(): AudioRendererRate

Obtains the audio renderer rate. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [getSpeed](#getspeed11) instead.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type                                             | Description                     |
| ------------------------------------------------- | ------------------------- |
| [AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8) | Audio render rate.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let renderRate: audio.AudioRendererRate = audioRenderer.getRenderRateSync();
  console.info(`getRenderRate: ${renderRate}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## setLoudnessGain<sup>20+</sup>

setLoudnessGain(loudnessGain: number): Promise\<void>

Sets the playback loudness. This API uses a promise to return the result.

> **NOTE**
>
> - This API applies only to audio streams of the [STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), [STREAM_USAGE_MOVIE](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), or [STREAM_USAGE_AUDIOBOOK](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage) type.
> - Loudness settings are not supported for high-definition channels.
> - Due to the buffer between the audio framework and hardware, there may be a delay in the actual effect of loudness adjustment. The delay duration depends on the buffer length.
> - You are advised to set the loudness before starting playback of different audio streams to achieve the optimal balance effect.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Parameters**

| Name      | Type   | Mandatory| Description                                     |
| ------------ | -------| ---- |------------------------------------------ |
| loudnessGain | number | Yes  | Loudness, in the range [-90.0, 24.0], in dB. The default value is 0.0 dB. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800104 | Operation is not supported on this renderer, e.g. the stream usage of this renderer is not one of [STREAM_USAGE_MUSIC](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), <br>[STREAM_USAGE_MOVIE](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), or [STREAM_USAGE_AUDIOBOOK](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage), or this renderer is routed through the high-resolution playback path. |

**Example**

```ts
audioRenderer.setLoudnessGain(1.0);
```

## getLoudnessGain<sup>20+</sup>

getLoudnessGain(): number

Obtains the playback loudness.

**System capability**: SystemCapability.Multimedia.Audio.Renderer

**Return value**

| Type   | Description            |
|------- |-----------------  |
| number | Playback loudness.|

**Example**

```ts
let loudnessGain = audioRenderer.getLoudnessGain();
```
