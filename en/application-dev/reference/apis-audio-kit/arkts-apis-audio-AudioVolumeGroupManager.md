# Interface (AudioVolumeGroupManager)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 9.

This interface implements volume management for an audio group.

Before calling any API in AudioVolumeGroupManager, you must use [getVolumeGroupManager](arkts-apis-audio-AudioVolumeManager.md#getvolumegroupmanager9) to obtain an AudioVolumeGroupManager instance.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the volume of a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the stream volume obtained; otherwise, **err** is an error object. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the volume. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume is obtained.');
});
```

## getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the volume of a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the volume of the stream. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

**Example**

```ts
audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promise returned to indicate that the volume is obtained ${value}.`);
});
```

## getVolumeSync<sup>(deprecated)</sup>

getVolumeSync(volumeType: AudioVolumeType): number

Obtains the volume of a stream. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| number | Volume of the stream. The volume range of a specified stream can be obtained by calling [getMinVolume](#getminvolumedeprecated) and [getMaxVolume](#getmaxvolumedeprecated).|

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
  let value: number = audioVolumeGroupManager.getVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume, error ${error}.`);
}
```

## getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the minimum volume allowed for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description              |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.      |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the minimum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the minimum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the minimum volume is obtained. ${value}`);
});
```

## getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the minimum volume allowed for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the minimum volume.|

**Example**

```ts
audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value: number) => {
  console.info(`Promised returned to indicate that the minimum volume is obtained ${value}.`);
});
```

## getMinVolumeSync<sup>(deprecated)</sup>

getMinVolumeSync(volumeType: AudioVolumeType): number

Obtains the minimum volume allowed for a stream. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                     |
| --------------------- | ------------------------- |
| number | Minimum volume.|

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
  let value: number = audioVolumeGroupManager.getMinVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the minimum volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the minimum volume, error ${error}.`);
}
```

## getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum volume allowed for a stream. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                  |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.          |
| callback   | AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the maximum stream volume obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: number) => {
  if (err) {
    console.error(`Failed to obtain the maximum volume. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the maximum volume is obtained. ${value}`);
});
```

## getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

Obtains the maximum volume allowed for a stream. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum volume.|

**Example**

```ts
audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data: number) => {
  console.info('Promised returned to indicate that the maximum volume is obtained.');
});
```

## getMaxVolumeSync<sup>(deprecated)</sup>

getMaxVolumeSync(volumeType: AudioVolumeType): number

Obtains the maximum volume allowed for a stream. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                 | Description                         |
| --------------------- | ----------------------------- |
| number | Maximum volume.|

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
  let value: number = audioVolumeGroupManager.getMaxVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the maximum volume is obtained. ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the maximum volume, error ${error}.`);
}
```

## isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a stream is muted. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                           |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                   |
| callback   | AsyncCallback&lt;boolean&gt;        | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the stream is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA, (err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the stream is obtained ${value}.`);
});
```

## isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

Checks whether a stream is muted. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 20. You are advised to use [isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                  | Description                                                  |
| ---------------------- | ------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the stream is muted, and **false** means the opposite.|

**Example**

```ts
audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA).then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the stream is obtained ${value}.`);
});
```

## isMuteSync<sup>(deprecated)</sup>

isMuteSync(volumeType: AudioVolumeType): boolean

Checks whether a stream is muted. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description        |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.|

**Return value**

| Type                  | Description                                                  |
| ---------------------- | ------------------------------------------------------ |
| boolean | Check result. The value **true** means that the stream is muted, and **false** means the opposite.|

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
  let value: boolean = audioVolumeGroupManager.isMuteSync(audio.AudioVolumeType.MEDIA);
  console.info(`Indicate that the mute status of the stream is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the mute status of the stream, error ${error}.`);
}
```

## getRingerMode<sup>9+</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

Obtains the ringer mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                                | Mandatory| Description                    |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the ringer mode obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getRingerMode((err: BusinessError, value: audio.AudioRingMode) => {
  if (err) {
    console.error(`Failed to obtain the ringer mode. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the ringer mode is obtained ${value}.`);
});
```

## getRingerMode<sup>9+</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

Obtains the ringer mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                                          | Description                           |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | Promise used to return the ringer mode.|

**Example**

```ts
audioVolumeGroupManager.getRingerMode().then((value: audio.AudioRingMode) => {
  console.info(`Promise returned to indicate that the ringer mode is obtained ${value}.`);
});
```

## getRingerModeSync<sup>10+</sup>

getRingerModeSync(): AudioRingMode

Obtains the ringer mode. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                                          | Description                           |
| ---------------------------------------------- | ------------------------------- |
| [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | Ringer mode.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: audio.AudioRingMode = audioVolumeGroupManager.getRingerModeSync();
  console.info(`Indicate that the ringer mode is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the ringer mode, error ${error}.`);
}
```

## on('ringerModeChange')<sup>9+</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

Subscribes to the ringer mode change event, which is triggered when [audioringmode](arkts-apis-audio-e.md#audioringmode) is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                     | Mandatory| Description                                                        |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | Yes  | Event type. The event **'ringerModeChange'** is triggered when the ringer mode is changed.|
| callback | Callback<[AudioRingMode](arkts-apis-audio-e.md#audioringmode)> | Yes  | Callback used to return the changed ringer mode.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeGroupManager.on('ringerModeChange', (ringerMode: audio.AudioRingMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
});
```

## off('ringerModeChange')<sup>18+</sup>

off(type: 'ringerModeChange', callback?: Callback&lt;AudioRingMode&gt;): void

Subscribes to the ringer mode change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- |----| ------------------------------------------------------------ |
| type     | string                                 | Yes | Event type. The event **'ringerModeChange'** is triggered when the ringer mode is changed.|
| callback |Callback&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | No | Callback used to return the changed ringer mode.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioVolumeGroupManager.off('ringerModeChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let ringerModeChangeCallback = (ringerMode: audio.AudioRingMode) => {
  console.info(`Updated ringermode: ${ringerMode}`);
};

audioVolumeGroupManager.on('ringerModeChange', ringerModeChangeCallback);

audioVolumeGroupManager.off('ringerModeChange', ringerModeChangeCallback);
```

## isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the microphone is muted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                        | Mandatory| Description                                                   |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is **true** if the microphone is muted or **false** if not muted; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMicrophoneMute((err: BusinessError, value: boolean) => {
  if (err) {
    console.error(`Failed to obtain the mute status of the microphone. ${err}`);
    return;
  }
  console.info(`Callback invoked to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

## isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

Checks whether the microphone is muted. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the microphone is muted, and **false** means the opposite.|

**Example**

```ts
audioVolumeGroupManager.isMicrophoneMute().then((value: boolean) => {
  console.info(`Promise returned to indicate that the mute status of the microphone is obtained ${value}.`);
});
```

## isMicrophoneMuteSync<sup>10+</sup>

isMicrophoneMuteSync(): boolean

Checks whether the microphone is muted. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result. The value **true** means that the microphone is muted, and **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: boolean = audioVolumeGroupManager.isMicrophoneMuteSync();
  console.info(`Indicate that the mute status of the microphone is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the mute status of the microphone, error ${error}.`);
}
```

## on('micStateChange')<sup>9+</sup>

on(type: 'micStateChange', callback: Callback&lt;MicStateChangeEvent&gt;): void

Subscribes to the microphone state change event, which is triggered when the microphone state is changed. This API uses an asynchronous callback to return the result.

Currently, when multiple AudioManager instances are used in a single process, only the subscription of the last instance takes effect, and the subscription of other instances is overwritten (even if the last instance does not initiate a subscription). Therefore, you are advised to use a single AudioManager instance.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'micStateChange'** is triggered when the microphone state is changed.|
| callback | Callback<[MicStateChangeEvent](arkts-apis-audio-i.md#micstatechangeevent9)> | Yes  | Callback used to return the changed microphone state.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeGroupManager.on('micStateChange', (micStateChange: audio.MicStateChangeEvent) => {
  console.info(`Current microphone status is: ${micStateChange.mute} `);
});
```

## off('micStateChange')<sup>12+</sup>

off(type: 'micStateChange', callback?: Callback&lt;MicStateChangeEvent&gt;): void

Unsubscribes from the microphone state change event. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- |----| ------------------------------------------------------------ |
| type     | string                                 | Yes | Event type. The event **'micStateChange'** is triggered when the microphone state is changed.|
| callback | Callback<[MicStateChangeEvent](arkts-apis-audio-i.md#micstatechangeevent9)> | No | Callback used to return the changed microphone state.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters missing; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioVolumeGroupManager.off('micStateChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let micStateChangeCallback = (micStateChange: audio.MicStateChangeEvent) => {
  console.info(`Current microphone status is: ${micStateChange.mute} `);
};

audioVolumeGroupManager.on('micStateChange', micStateChangeCallback);

audioVolumeGroupManager.off('micStateChange', micStateChangeCallback);
```

## isVolumeUnadjustable<sup>10+</sup>

isVolumeUnadjustable(): boolean

Checks whether the fixed volume mode is enabled. When the fixed volume mode is enabled, the volume cannot be adjusted. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type                  | Description                                                  |
| ---------------------- | ------------------------------------------------------ |
| boolean            | Check result. The value **true** means that the fixed volume mode is enabled, and **false** means the opposite.|

**Example**

```ts
let volumeAdjustSwitch: boolean = audioVolumeGroupManager.isVolumeUnadjustable();
console.info(`Whether it is volume unadjustable: ${volumeAdjustSwitch}.`);
```

## getSystemVolumeInDb<sup>(deprecated)</sup>

getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback&lt;number&gt;): void

Obtains the volume gain. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [getVolumeInUnitOfDbByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumeinunitofdbbystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                            |
| volumeLevel | number                         | Yes  | Volume level.                                              |
| device     | [DeviceType](arkts-apis-audio-e.md#devicetype)           | Yes  | Device type.                                              |
| callback   | AsyncCallback&lt;number&gt;           | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the volume gain obtained; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getSystemVolumeInDb(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER, (err: BusinessError, dB: number) => {
  if (err) {
    console.error(`Failed to get the volume DB. ${err}`);
  } else {
    console.info(`Success to get the volume DB. ${dB}`);
  }
});
```

## getSystemVolumeInDb<sup>(deprecated)</sup>

getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise&lt;number&gt;

Obtains the volume gain. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [getVolumeInUnitOfDbByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumeinunitofdbbystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                            |
| volumeLevel | number                              | Yes  | Volume level.                                            |
| device     | [DeviceType](arkts-apis-audio-e.md#devicetype)           | Yes  | Device type.                                              |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the volume gain (in dB).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getSystemVolumeInDb(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER).then((value: number) => {
  console.info(`Success to get the volume DB. ${value}`);
}).catch((error: BusinessError) => {
  console.error(`Fail to adjust the system volume by step. ${error}`);
});
```

## getSystemVolumeInDbSync<sup>(deprecated)</sup>

getSystemVolumeInDbSync(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): number

Obtains the volume gain. This API returns the result synchronously.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 20. You are advised to use [getVolumeInUnitOfDbByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumeinunitofdbbystream20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | Yes  | Audio stream type.                                            |
| volumeLevel | number                              | Yes  | Volume level.                                            |
| device     | [DeviceType](arkts-apis-audio-e.md#devicetype)           | Yes  | Device type.                                              |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| number | Volume gain (in dB).|

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
  let value: number = audioVolumeGroupManager.getSystemVolumeInDbSync(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER);
  console.info(`Success to get the volume DB. ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Fail to adjust the system volume by step. ${error}`);
}
```

## getMaxAmplitudeForInputDevice<sup>12+</sup>

getMaxAmplitudeForInputDevice(inputDevice: AudioDeviceDescriptor): Promise&lt;number&gt;

Obtains the maximum amplitude (in the range [0, 1]) of the audio stream for an input device. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ----------- | ------------------------------------- | ---- | --------------------------------------------------- |
| inputDevice |[AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | Yes  | Descriptor of the target device.                                |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum amplitude, which is in the range [0, 1].|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // Audio source type: microphone. Set this parameter based on the service scenario.
  capturerFlags: 0 // AudioCapturer flag.
};

audio.getAudioManager().getRoutingManager().getPreferredInputDeviceForCapturerInfo(capturerInfo).then((data) => {
  audioVolumeGroupManager.getMaxAmplitudeForInputDevice(data[0]).then((value) => {
    console.info(`mic volatileume amplitude is: ${value}`);
  }).catch((err: BusinessError) => {
    console.error("getMaxAmplitudeForInputDevice error" + JSON.stringify(err));
  })
}).catch((err: BusinessError) => {
  console.error("get outputDeviceId error" + JSON.stringify(err));
})
```

## getMaxAmplitudeForOutputDevice<sup>12+</sup>

getMaxAmplitudeForOutputDevice(outputDevice: AudioDeviceDescriptor): Promise&lt;number&gt;

Obtains the maximum amplitude (in the range [0, 1]) of the audio stream for an output device. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                               | Mandatory| Description                                                    |
| ------------ | --------------------------------------- | ---- | -------------------------------------------------------- |
| outputDevice |[AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | Yes  | Descriptor of the target device.                                            |

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum amplitude, which is in the range [0, 1].|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
  rendererFlags: 0 // AudioRenderer flag.
};

audio.getAudioManager().getRoutingManager().getPreferOutputDeviceForRendererInfo(rendererInfo).then((data) => {
  audioVolumeGroupManager.getMaxAmplitudeForOutputDevice(data[0]).then((value) => {
    console.info(`mic volatileume amplitude is: ${value}`);
  }).catch((err: BusinessError) => {
    console.error("getMaxAmplitudeForOutputDevice error" + JSON.stringify(err));
  })
}).catch((err: BusinessError) => {
  console.error("getPreferOutputDeviceForRendererInfo error" + JSON.stringify(err));
})
```
## setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

Mutes or unmutes the microphone. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. Its substitute is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG (available only for system applications)

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                     | Mandatory| Description                                         |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | Yes  | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.setMicrophoneMute(true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the microphone. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the microphone is muted.');
});
```

## setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

Mutes or unmutes the microphone. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. Its substitute is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_AUDIO_CONFIG (available only for system applications)

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name| Type   | Mandatory| Description                                         |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | Yes  | Mute status to set. The value **true** means to the microphone, and **false** means the opposite.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
audioVolumeGroupManager.setMicrophoneMute(true).then(() => {
  console.info('Promise returned to indicate that the microphone is muted.');
});
```
