# Interface (AudioVolumeManager)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 9.

This interface implements audio volume management.

Before calling any API in AudioVolumeManager, you must use [getVolumeManager](arkts-apis-audio-AudioManager.md#getvolumemanager9) to obtain an AudioVolumeManager instance.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager\>\): void

Obtains the volume group manager. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- |-----------------------------------------------------------|
| groupId    | number                                    | Yes  | Volume group ID. The default value is **DEFAULT_VOLUME_GROUP_ID**.                        |
| callback   | AsyncCallback&lt;[AudioVolumeGroupManager](arkts-apis-audio-AudioVolumeGroupManager.md)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the volume group manager obtained; otherwise, **err** is an error object.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let groupId: number = audio.DEFAULT_VOLUME_GROUP_ID;

audioVolumeManager.getVolumeGroupManager(groupId, (err: BusinessError, value: audio.AudioVolumeGroupManager) => {
  if (err) {
    console.error(`Failed to obtain the volume group infos list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
});

```

## getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number\): Promise<AudioVolumeGroupManager\>

Obtains the volume group manager. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description                              |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| groupId    | number                                   | Yes  | Volume group ID. The default value is **DEFAULT_VOLUME_GROUP_ID**.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| Promise&lt; [AudioVolumeGroupManager](arkts-apis-audio-AudioVolumeGroupManager.md) &gt; | Promise used to return the volume group manager.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let groupId: number = audio.DEFAULT_VOLUME_GROUP_ID;
let audioVolumeGroupManager: audio.AudioVolumeGroupManager | undefined = undefined;

async function getVolumeGroupManager(){
  audioVolumeGroupManager = await audioVolumeManager.getVolumeGroupManager(groupId);
  console.info('Promise returned to indicate that the volume group infos list is obtained.');
}
```

## getVolumeGroupManagerSync<sup>10+</sup>

getVolumeGroupManagerSync(groupId: number\): AudioVolumeGroupManager

Obtains the volume group manager. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description                              |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| groupId    | number                                   | Yes  | Volume group ID. The default value is **DEFAULT_VOLUME_GROUP_ID**.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| [AudioVolumeGroupManager](arkts-apis-audio-AudioVolumeGroupManager.md) | Volume group manager.|

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
  let audioVolumeGroupManager: audio.AudioVolumeGroupManager = audioVolumeManager.getVolumeGroupManagerSync(audio.DEFAULT_VOLUME_GROUP_ID);
  console.info(`Get audioVolumeGroupManager success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get audioVolumeGroupManager, error: ${error}`);
}
```

## getAppVolumePercentage<sup>19+</sup>

getAppVolumePercentage(): Promise<number\>

Obtains the volume of the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Return value**

| Type               | Description                |
| ------------------- |--------------------|
| Promise&lt;number&gt; | Promise used to return the application volume (ranging from 0 to 100).|

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.getAppVolumePercentage().then((value: number) => {
  console.info(`app volume is ${value}.`);
});
```

## setAppVolumePercentage<sup>19+</sup>

setAppVolumePercentage(volume: number\): Promise<void\>

Sets the volume for the application. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name    | Type                                     | Mandatory| Description      |
| ---------- | ---------------------------------------- | ---- |----------|
| volume    | number                                   | Yes  | Volume to set.|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed.|
| 6800301 | Crash or blocking occurs in system process. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.setAppVolumePercentage(20).then(() => {
  console.info(`set app volume success.`);
});
```

## on('volumeChange')<sup>(deprecated)</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

Subscribes to the system volume change event, which is triggered when the system volume is changed. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 12 and deprecated since API version 20. You are advised to use [on('streamVolumeChange')](arkts-apis-audio-AudioVolumeManager.md#onstreamvolumechange20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'volumeChange'** is triggered when the system volume is changed.|
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | Yes  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

## off('volumeChange')<sup>(deprecated)</sup>

off(type: 'volumeChange', callback?: Callback\<VolumeEvent>): void

Unsubscribes from the system volume change event. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 12 and deprecated since API version 20. You are advised to use [off('streamVolumeChange')](arkts-apis-audio-AudioVolumeManager.md#offstreamvolumechange20) instead.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'volumeChange'** is triggered when the system volume is changed.|
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | No  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters missing; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioVolumeManager.off('volumeChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let volumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};

audioVolumeManager.on('volumeChange', volumeChangeCallback);

audioVolumeManager.off('volumeChange', volumeChangeCallback);
```

## on('appVolumeChange')<sup>19+</sup>

on(type: 'appVolumeChange', callback: Callback\<VolumeEvent>): void

Subscribes to the application-level volume change event of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'appVolumeChange'** is triggered when the application-level volume is changed.|
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | Yes  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeManager.on('appVolumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

## off('appVolumeChange')<sup>19+</sup>

off(type: 'appVolumeChange', callback?: Callback\<VolumeEvent>): void

Unsubscribes from the application-level volume change event of the application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'appVolumeChange'** is triggered when the application-level volume is changed.|
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | No  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Cancel all subscriptions to the event.
audioVolumeManager.off('appVolumeChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let appVolumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};

audioVolumeManager.on('appVolumeChange', appVolumeChangeCallback);

audioVolumeManager.off('appVolumeChange', appVolumeChangeCallback);
```

## getVolumeByStream<sup>20+</sup>

getVolumeByStream(streamUsage: StreamUsage): number

Obtains the volume of a specified audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](arkts-apis-audio-e.md#streamusage)                                 | Yes  | Audio stream for which the volume is to be obtained.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| number | Volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Obtain the volume of a specified audio stream.
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit'

try {
  let volume : number = audio.getAudioManager().getVolumeManager().getVolumeByStream(audio.StreamUsage.STREAM_USAGE_MUSIC);
  console.info(`Obtains the volume of a stream success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtains the volume of a stream, error: ${error}`);
}
```

## getMinVolumeByStream<sup>20+</sup>

getMinVolumeByStream(streamUsage: StreamUsage): number

Obtains the minimum volume of a specified audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](arkts-apis-audio-e.md#streamusage)                                 | Yes  | Audio stream for which the minimum volume is to be obtained.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| number | Volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Obtain the minimum volume of a specified audio stream.
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit'

try {
  let volume : number = audio.getAudioManager().getVolumeManager().getMinVolumeByStream(audio.StreamUsage.STREAM_USAGE_MUSIC);
  console.info(`Obtains the minimum volume allowed for a stream success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtains the minimum volume allowed for a stream, error: ${error}`);
}
```

## getMaxVolumeByStream<sup>20+</sup>

getMaxVolumeByStream(streamUsage: StreamUsage): number

Obtains the maximum volume of a specified audio stream.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](arkts-apis-audio-e.md#streamusage)                                 | Yes  | Audio stream for which the maximum volume is to be obtained.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| number | Volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Obtain the maximum volume of a specified audio stream.
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit'

try {
  let volume : number = audio.getAudioManager().getVolumeManager().getMaxVolumeByStream(audio.StreamUsage.STREAM_USAGE_MUSIC);
  console.info(`Obtains the maximum volume allowed for a stream success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtains the maximum volume allowed for a stream, error: ${error}`);
}
```

## isSystemMutedForStream<sup>20+</sup>

isSystemMutedForStream(streamUsage: StreamUsage): boolean

Checks whether a specified audio stream is muted.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](arkts-apis-audio-e.md#streamusage)                                 | Yes  | Audio stream to check.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| boolean | Check result. The value **true** means the audio stream is muted, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Check whether a specified audio stream is muted.
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit'

try {
  let isMuted : boolean = audio.getAudioManager().getVolumeManager().isSystemMutedForStream(audio.StreamUsage.STREAM_USAGE_MUSIC);
  console.info(`Checks whether the system is muted based on the stream success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to checks whether the system is muted based on the stream, error: ${error}`);
}

```
## getVolumeInUnitOfDbByStream<sup>20+</sup>

getVolumeInUnitOfDbByStream(streamUsage: StreamUsage, volumeLevel: number, device: DeviceType): number

Obtains the volume (in dB) calculated by the system based on the audio stream, volume level, and device type.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| streamUsage     | [StreamUsage](arkts-apis-audio-e.md#streamusage)                                 | Yes  | Audio stream.|
| volumeLevel     | number                                 | Yes  | Volume level.|
| device     | [DeviceType](arkts-apis-audio-e.md#devicetype)                                 | Yes  | Device type.|

**Return value**

| Type               | Description                         |
| ------------------- | ----------------------------- |
| number | Volume of the audio stream, in dB.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
// Obtain the volume (in dB) calculated by the system based on the audio stream, volume level, and device type.
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit'

try {
  let volumeInDb : number = audio.getAudioManager().getVolumeManager().getVolumeInUnitOfDbByStream(audio.StreamUsage.STREAM_USAGE_MUSIC, 5, audio.DeviceType.SPEAKER);
  console.info(`Gets the volume db value that system calculate by volume stream, volume level and device type.
 success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to gets the volume db value that system calculate by volume stream, volume level and device type., error: ${error}`);
}
```

## on('streamVolumeChange')<sup>20+</sup>

 on(type: 'streamVolumeChange', streamUsage: StreamUsage, callback: Callback\<StreamVolumeEvent>): void

Subscribes to the system audio volume change event, which is triggered when the system audio volume is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'streamVolumeChange'** is triggered when the system audio volume is changed.|
| streamUsage     | [StreamUsage](arkts-apis-audio-e.md#streamusage)                                 | Yes  | Audio stream usage.|
| callback | Callback<[StreamVolumeEvent](arkts-apis-audio-i.md#streamvolumeevent20)> | Yes  | Callback used to return the changed volume.|

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
audioVolumeManager.on('streamVolumeChange', audio.StreamUsage.STREAM_USAGE_MUSIC, (streamVolumeEvent: audio.StreamVolumeEvent) => {
  console.info(`StreamUsage of stream: ${streamVolumeEvent.streamUsage} `);
  console.info(`Volume level: ${streamVolumeEvent.volume} `);
  console.info(`Whether to updateUI: ${streamVolumeEvent.updateUi} `);
});
```

## off('streamVolumeChange')<sup>20+</sup>

off(type: 'streamVolumeChange', callback?: Callback\<StreamVolumeEvent>): void

Unsubscribes from the system audio volume change event, which is triggered when the system audio volume is changed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Volume

**Parameters**

| Name  | Type                                  | Mandatory| Description                                                        |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | Yes  | Event type. The event **'volumeChange'** is triggered when the system volume is changed.|
| callback | Callback<[StreamVolumeEvent](arkts-apis-audio-i.md#streamvolumeevent20)> | No  | Callback used to return the changed volume.|

**Example**

```ts
// Cancel all subscriptions to the event.
audioVolumeManager.off('streamVolumeChange');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let streamVolumeChangeCallback = (streamVolumeEvent: audio.StreamVolumeEvent) => {
  console.info(`StreamUsage of stream: ${streamVolumeEvent.streamUsage} `);
  console.info(`Volume level: ${streamVolumeEvent.volume} `);
  console.info(`Whether to updateUI: ${streamVolumeEvent.updateUi} `);
};

audioVolumeManager.on('streamVolumeChange', audio.StreamUsage.STREAM_USAGE_MUSIC, streamVolumeChangeCallback);

audioVolumeManager.off('streamVolumeChange', streamVolumeChangeCallback);
```
