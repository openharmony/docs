# systemTonePlayer (System Tone Player) (System API)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

The module provides APIs for playing and configuring SMS tones and notification tones and obtaining related information.

This module must work with [@ohos.multimedia.systemSoundManager](js-apis-systemSoundManager-sys.md) to manage system tones.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { systemSoundManager } from '@kit.AudioKit';
```

## SystemToneOptions

Describes the options of system tones.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

| Name       | Type   | Mandatory| Description                                         |
| ----------- | ------- | ---- | --------------------------------------------- |
| muteAudio   | boolean | No  | Whether the sound is muted. **true** if muted, **false** otherwise.  |
| muteHaptics | boolean | No  | Whether haptics feedback is turned off. **true** if turned off, **false** otherwise.|

## SystemTonePlayer

Implements APIs for playing and configuring SMS tones and notification tones and obtaining related information. Before calling any API in SystemTonePlayer, you must use [getSystemTonePlayer](js-apis-systemSoundManager-sys.md#getsystemtoneplayer11) to create a SystemTonePlayer instance.

### getTitle

getTitle(): Promise&lt;string&gt;

Obtains the title of a system tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the title obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 5400103  | I/O error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.getTitle().then((value: string) => {
  console.info('Succeeded in doing getTitle.');
}).catch((err: BusinessError) => {
  console.error(`Failed to getTitle. Code: ${err.code}, message: ${err.message}`);
});
```

### prepare

prepare(): Promise&lt;void&gt;

Prepares to play a system tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 5400102  | Operation not allowed.              |
| 5400103  | I/O error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.prepare().then(() => {
  console.info('Succeeded in doing prepare.');
}).catch((err: BusinessError) => {
  console.error(`Failed to prepare. Code: ${err.code}, message: ${err.message}`);
});
```

### start

start(toneOptions?: SystemToneOptions): Promise&lt;number&gt;

Starts playing a system tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Required permissions**: ohos.permission.VIBRATE

**Parameters**

| Name     | Type                                   | Mandatory| Description            |
| ----------- | --------------------------------------- | ---- | ---------------- |
| toneOptions | [SystemToneOptions](#systemtoneoptions) | No  | Options of the system tone.|

**Return value**

| Type   | Description                     |
| ------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the stream ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                                                                                                   |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied.                                                                                          |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class SystemToneOptions {
  muteAudio: boolean = false;
  muteHaptics: boolean = false;
}
let systemToneOptions: SystemToneOptions = {muteAudio: true, muteHaptics: false};

systemTonePlayer.start(systemToneOptions).then((value: number) => {
  console.info('Succeeded in doing start.');
}).catch((err: BusinessError) => {
  console.error(`Failed to start. Code: ${err.code}, message: ${err.message}`);
});
```

### stop

stop(id: number): Promise&lt;void&gt;

Stops playing a system tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | ------------------------- |
| id     | number | Yes  | Stream ID.|

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                                                                                                   |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let streamID: number = 0; // streamID is the stream ID returned by start(). Only initialization is performed here.
systemTonePlayer.stop(streamID).then(() => {
  console.info('Succeeded in doing stop.');
}).catch((err: BusinessError) => {
  console.error(`Failed to stop. Code: ${err.code}, message: ${err.message}`);
});
```

### release

release(): Promise&lt;void&gt;

Releases the system tone player. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.release().then(() => {
  console.info('Succeeded in doing release.');
}).catch((err: BusinessError) => {
  console.error(`Failed to release. Code: ${err.code}, message: ${err.message}`);
});
```

### setAudioVolumeScale<sup>13+</sup>

setAudioVolumeScale(scale: number): void

Sets the scale of the audio volume. No result is returned.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name| Type  | Mandatory| Description                                |
| ------ | ------ | ---- | ------------------------------------ |
| scale  | number | Yes  | Scale of the audio volume. The value is in the range [0, 1].|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md), [Media Error Codes](../apis-media-kit/errorcode-media.md), and [Ringtone Error Codes](./errorcode-ringtone.md).

| ID| Error Message                                                                                                   |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |
| 20700002 | Parameter check error, For example, value is out side [0, 1].                                                |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let scale: number = 0.5;
try {
  systemTonePlayer.setAudioVolumeScale(scale);
  console.info('Succeeded in doing setAudioVolumeScale.');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to setAudioVolumeScale. Code: ${error.code}, message: ${error.message}`);
}
```

### getAudioVolumeScale<sup>13+</sup>

getAudioVolumeScale(): number

Obtains the scale of the audio volume. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**


| Type  | Description        |
| ------ | ------------ |
| number | Scale of the audio volume.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let scale: number = systemTonePlayer.getAudioVolumeScale();
  console.info('Succeeded in doing getAudioVolumeScale.');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to getAudioVolumeScale. Code: ${error.code}, message: ${error.message}`);
}
```

### getSupportedHapticsFeatures<sup>13+</sup>

getSupportedHapticsFeatures(): Promise&lt;Array&lt;systemSoundManager.ToneHapticsFeature&gt;&gt;

Obtains the supported haptics styles. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type                                                                                                                         | Description                                                                                                                 |
|-----------------------------------------------------------------------------------------------------------------------------| --------------------------------------------------------------------------------------------------------------------- |
| Promise&lt;Array&lt;[systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature13)&gt;&gt; | Promise used to return an array of the supported haptics styles.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ringtone Error Codes](./errorcode-ringtone.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 20700003 | Unsupported operation.              |

**Example**

```ts
systemTonePlayer.getSupportedHapticsFeatures().then((features: Array<systemSoundManager.ToneHapticsFeature>) => {
  console.info('Succeeded in doing getSupportedHapticsFeatures.');
}).catch((err: BusinessError) => {
  console.error(`Failed to getSupportedHapticsFeatures. Code: ${err.code}, message: ${err.message}`);
});
```

### setHapticsFeature<sup>13+</sup>

setHapticsFeature(hapticsFeature: systemSoundManager.ToneHapticsFeature): void

Sets a haptics style of the ringtone.

Before calling this API, call [getSupportedHapticsFeatures](#getsupportedhapticsfeatures13) to obtain the supported haptics styles. The setting fails if the haptics style to set is not supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name        | Type                                                                                             | Mandatory| Description            |
| -------------- |-------------------------------------------------------------------------------------------------| ---- | ---------------- |
| hapticsFeature | [systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature13) | Yes  | Haptics style.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md), [Media Error Codes](../apis-media-kit/errorcode-media.md), and [Ringtone Error Codes](./errorcode-ringtone.md).

| ID| Error Message                                                                                                   |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |
| 20700003 | Unsupported operation.                                                                                      |

**Example**

```ts
systemTonePlayer.getSupportedHapticsFeatures().then((features: Array<systemSoundManager.ToneHapticsFeature>) => {
  console.info('Succeeded in doing getSupportedHapticsFeatures.');
  if (features.length > 0) {
    let feature: systemSoundManager.ToneHapticsFeature = features[0];
    systemTonePlayer.setHapticsFeature(feature);
    console.info('Succeeded in doing setHapticsFeature.');
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to getSupportedHapticsFeatures. Code: ${err.code}, message: ${err.message}`);
});
```

### getHapticsFeature<sup>13+</sup>

getHapticsFeature(): systemSoundManager.ToneHapticsFeature

Obtains the haptics style of the ringtone. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type                                                                                             | Description    |
|-------------------------------------------------------------------------------------------------| -------- |
| [systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature13) | Haptics style.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ringtone Error Codes](./errorcode-ringtone.md).


| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 20700003 | Unsupported operation.              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let feature: systemSoundManager.ToneHapticsFeature = systemTonePlayer.getHapticsFeature();
  console.info('Succeeded in doing getHapticsFeature.');
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to getHapticsFeature. Code: ${error.code}, message: ${error.message}`);
}
```

### on('playFinished')<sup>18+</sup>

on(type: 'playFinished', streamId: number, callback: Callback\<number>): void

Subscribes to the event indicating that the ringtone playback is finished. This API uses an asynchronous callback to return the result.

The object to listen for is an audio stream specified by **streamId**. If **streamId** is set to **0**, this API subscribes to the playback complete event of all audio streams of the player.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | --------------------------------------------------------------- |
| type     | string                  | Yes  | Event type. The event **'playFinished'** is triggered when the playback is finished.|
| streamId | number                  | Yes  | ID of the audio stream. **streamId** is obtained through [start](#start). If **streamId** is set to **0**, the playback complete event of all audio streams of the player is subscribed to.|
| callback | Callback\<number>  | Yes  | Callback used to return the stream ID of the audio stream that finishes playing.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ringtone Error Codes](./errorcode-ringtone.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Subscribe to the playback complete events of all audio streams.
systemTonePlayer.on('playFinished', 0, (streamId: number) => {
  console.info(`Receive the callback of playFinished, streamId: ${streamId}.`);
});

// Subscribe to the playback complete event of a specified audio stream.
systemTonePlayer.start().then((value: number) => {
  systemTonePlayer.on('playFinished', value, (streamId: number) => {
    console.info(`Receive the callback of playFinished, streamId: ${streamId}.`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to start system tone player. ${err}`);
});
```

### off('playFinished')<sup>18+</sup>

off(type: 'playFinished', callback?: Callback\<number>): void

Unsubscribes from the event indicating that the ringtone playback is finished. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name| Type  | Mandatory| Description                                             |
| ----- | ----- | ---- | ------------------------------------------------ |
| type   | string | Yes  | Event type. The event **'playFinished'** is triggered when the playback is finished.|
| callback | Callback\<number>    | No  | Callback used to return the ID of the audio stream. If this parameter is not specified, all the subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ringtone Error Codes](./errorcode-ringtone.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**Example**

```ts
// Cancel all subscriptions to the event.
systemTonePlayer.off('playFinished');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let playFinishedCallback = (streamId: number) => {
  console.info(`Receive the callback of playFinished, streamId: ${streamId}.`);
};

systemTonePlayer.on('playFinished', 0, playFinishedCallback);

systemTonePlayer.off('playFinished', playFinishedCallback);
```

### on('error')<sup>18+</sup>

on(type: 'error', callback: ErrorCallback): void

Subscribes to error events that occur during ringtone playback. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type. The event **'error'** is triggered when an error occurs during ringtone playback.|
| callback | ErrorCallback | Yes  | Callback used to return the error code and error information. For details about the error codes, see [on('error')](../apis-media-kit/arkts-apis-media-AVPlayer.md#onerror9) of the AVPlayer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ringtone Error Codes](./errorcode-ringtone.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
});
```

### off('error')<sup>18+</sup>

off(type: 'error', callback?: ErrorCallback): void

Unsubscribes from error events that occur during ringtone playback. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name  | Type         | Mandatory| Description                                |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | Yes  | Event type. The event **'error'** is triggered when an error occurs during ringtone playback.|
| callback | ErrorCallback | No  | Callback used to return the error code and error information. If this parameter is not specified, all the subscriptions to the specified event are canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ringtone Error Codes](./errorcode-ringtone.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Cancel all subscriptions to the event.
systemTonePlayer.off('error');

// For the same event, if the callback parameter passed to the off API is the same as that passed to the on API, the off API cancels the subscription registered with the specified callback parameter.
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
};

systemTonePlayer.on('error', callback);

systemTonePlayer.off('error', callback);
```
