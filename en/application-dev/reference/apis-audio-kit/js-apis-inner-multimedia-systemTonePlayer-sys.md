# systemTonePlayer (System Alert Tone Player) (System API)

The systemTonePlayer module provides APIs for playing and configuring SMS alert tones and notification alert tones and obtaining related information.

This module must work with [@ohos.multimedia.systemSoundManager](js-apis-systemSoundManager-sys.md) to manage system alert tones.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { systemSoundManager } from '@kit.AudioKit';
```

## SystemToneOptions

Describes the options of system alert tones.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

| Name       | Type   | Mandatory| Description                                         |
| ----------- | ------- | ---- | --------------------------------------------- |
| muteAudio   | boolean | No  | Whether the sound is muted. The value **true** means that the sound is muted, and **false** means the opposite.  |
| muteHaptics | boolean | No  | Whether haptics feedback is turned off. The value **true** means that haptics feedback is turned off, and **false** means the opposite.|

## SystemTonePlayer

Implements APIs for playing and configuring SMS alert tones and notification alert tones and obtaining related information. Before calling any API in **SystemTonePlayer**, you must use [getSystemTonePlayer](js-apis-systemSoundManager-sys.md#getsystemtoneplayer11) to create a **SystemTonePlayer** instance.

### getTitle

getTitle(): Promise&lt;string&gt;

Obtains the title of a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type   | Description                                 |
| ------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the title obtained.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 5400103  | I/O error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.getTitle().then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system tone player title is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone player title ${err}`);
});
```

### prepare

prepare(): Promise&lt;void&gt;

Prepares to play a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 5400102  | Operation not allowed.              |
| 5400103  | I/O error.                          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.prepare().then(() => {
  console.info(`Promise returned to indicate a successful prepareing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to prepareing system tone player. ${err}`);
});
```

### start

start(toneOptions?: SystemToneOptions): Promise&lt;number&gt;

Starts playing a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Required permissions**: ohos.permission.VIBRATE

**Parameters**

| Name     | Type                                   | Mandatory| Description            |
| ----------- | --------------------------------------- | ---- | ---------------- |
| toneOptions | [SystemToneOptions](#systemtoneoptions) | No  | Options of the system alert tone.|

**Return value**

| Type   | Description                     |
| ------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the stream ID.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

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
  console.info(`Promise returned to indicate that the value of the system tone player streamID is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to start system tone player. ${err}`);
});
```

### stop

stop(id: number): Promise&lt;void&gt;

Stops playing a system alert tone. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name| Type  | Mandatory| Description                     |
| ------ | ------ | ---- | ------------------------- |
| id     | number | Yes  | Stream ID returned by **start()**.|

**Return value**

| Type   | Description                               |
| ------- | ----------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

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
  console.info(`Promise returned to indicate a successful stopping of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to stop system tone player. ${err}`);
});
```

### release

release(): Promise&lt;void&gt;

Releases the system alert tone player. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**

| Type   | Description                           |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.release().then(() => {
  console.info(`Promise returned to indicate a successful releasing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to release system tone player. ${err}`);
});
```

### setAudioVolumeScale<sup>12+</sup>

setAudioVolumeScale(scale: number): void

Sets the scale of the audio volume. No result is returned.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Parameters**

| Name| Type  | Mandatory| Description                                |
| ------ | ------ | ---- | ------------------------------------ |
| scale  | number | Yes  | Scale of the audio volume. The value is in the range [0, 1].|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID| Error Message                                                                                                   |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |
| 20700002 | Parameter check error, For example, value is out side [0, 1]                                                |

**Example**

```ts
let scale: number = 0.5;
try {
  systemTonePlayer.setAudioVolumeScale(scale);
} catch (err) {
  console.error(`Failed to set audio volume scale. ${err}`);
}
```

### getAudioVolumeScale<sup>12+</sup>

getAudioVolumeScale(): number;

Obtains the scale of the audio volume. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**


| Type  | Description        |
| ------ | ------------ |
| number | Scale of the audio volume.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).


| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |

**Example**

```ts
try {
  let scale: number = systemTonePlayer.getAudioVolumeScale();
  console.info(` get audio volume scale. ${scale}`);
} catch (err) {
  console.error(`Failed to get audio volume scale. ${err}`);
}
```

### getSupportedHapticsFeatures<sup>12+</sup>

getSupportedHapticsFeatures(): Promise&lt;Array&lt;systemSoundManager.ToneHapticsFeature&gt;&gt;

Obtains the supported haptics styles. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**


| Type   | Description                                                                                                                 |
| ------- | --------------------------------------------------------------------------------------------------------------------- |
| Promise&lt;Array&lt;[systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature12)&gt;&gt; | Promise used to return an array of the supported haptics styles.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).


| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 20700003 | Unsupported operation.              |

**Example**

```ts
try {
  let features: Array<systemSoundManager.ToneHapticsFeature> = await systemTonePlayer.getSupportedHapticsFeatures();
  console.info(` get supported haptics features. ${features}`);
} catch (err) {
  console.error(`Failed to get supported haptics features. ${err}`);
}
```

### setHapticsFeature<sup>12+</sup>

setHapticsFeature(hapticsFeature: systemSoundManager.ToneHapticsFeature): void

Sets a haptics style of the ringtone.

Before calling this API, call [getSupportedHapticsFeatures](#getsupportedhapticsfeatures12) to obtain the supported haptics styles. The setting fails if the haptics style to set is not supported.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core
**Parameters**


| Name        | Type                                                                                         | Mandatory| Description            |
| -------------- | --------------------------------------------------------------------------------------------- | ---- | ---------------- |
| hapticsFeature | [systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature12) | Yes  | Haptics style.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).


| ID| Error Message                                                                                                   |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |
| 20700003 | Unsupported operation.                                                                                      |

**Example**

```ts
try {
  let features: Array<systemSoundManager.ToneHapticsFeature> = await systemTonePlayer.getSupportedHapticsFeatures();
  if (features.lenght == 0) {
    return;
  }
  let feature: systemSoundManager.ToneHapticsFeature = features[0];
  systemTonePlayer.setHapticsFeature(feature);
  console.info(` set haptics feature success`);
} catch (err) {
  console.error(`Failed to set haptics feature. ${err}`);
}
```

### getHapticsFeature<sup>12+</sup>

getHapticsFeature(): systemSoundManager.ToneHapticsFeature

Obtains the haptics style of the ringtone. This API returns the result synchronously.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.SystemSound.Core

**Return value**


| Type                                                                                         | Description    |
| --------------------------------------------------------------------------------------------- | -------- |
| [systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature12) | Haptics style.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).


| ID| Error Message                           |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 20700003 | Unsupported operation.              |

**Example**

```ts
try {
  let feature: systemSoundManager.ToneHapticsFeature = systemTonePlayer.getHapticsFeature();
  console.info(` get haptics feature success. ${features}`);
} catch (err) {
  console.error(`Failed to get haptics feature. ${err}`);
}
```
