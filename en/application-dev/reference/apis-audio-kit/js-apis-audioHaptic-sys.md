# @ohos.multimedia.audioHaptic (Audio-Haptic) (System API)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

Audio-haptic enables users to get rhythmic auditory and haptic feedback while having incoming calls or messages.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Module to Import

```ts
import { audioHaptic } from '@kit.AudioKit';
```

## AudioHapticPlayer

Implements audio-haptic playback. Before calling any API in AudioHapticPlayer, you must use [createPlayer](./js-apis-audioHaptic.md#createplayer) to create an AudioHapticPlayer instance.

### isHapticsIntensityAdjustmentSupported<sup>20+</sup>

isHapticsIntensityAdjustmentSupported(): boolean

Checks whether the device supports adjusting the intensity of haptic feedback.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| boolean             | Check result for the support of intensity adjustment. **true** if supported, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                             |
|---------|-----------------------------------|
| 202 | Caller is not a system application. |

**Example**

```ts
const result: boolean = audioHapticPlayerInstance.isHapticsIntensityAdjustmentSupported();
```

### isHapticsRampSupported<sup>20+</sup>

isHapticsRampSupported(): boolean

Checks whether the device supports gradually adjusting the intensity of haptic feedback, also known as haptic ramping.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| boolean             | Check result for the support of haptic ramping. **true** if supported, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code  | Error Message                             |
|---------|-----------------------------------|
| 202 | Caller is not a system application. |

**Example**

```ts
const result: boolean = audioHapticPlayerInstance.isHapticsRampSupported();
```

### enableHapticsInSilentMode<sup>20+</sup>

enableHapticsInSilentMode(enable: boolean): void

Enables the audio-haptic player to provide haptic feedback even when the device is in silent mode.

> **NOTE**
>
> This API must be called before the audio-haptic player is released. It cannot be called during playback.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name | Type                                    | Mandatory| Description                   |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| enable     | boolean                                | Yes | Whether to enable haptic feedback in silent mode. **true** to enable, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](../apis-media-kit/errorcode-media.md).

| Error Code | Error Message                            |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 5400102  | Operate not permit in current state. |

**Example**

```ts
audioHapticPlayerInstance.enableHapticsInSilentMode(true);
```

### setHapticsIntensity<sup>20+</sup>

setHapticsIntensity(intensity: number): Promise&lt;void&gt;

Sets the intensity of haptic feedback for this audio-haptic player. This API uses a promise to return the result.

> **NOTE**
>
>This API must be called before the audio-haptic player is released. It can be called only once during a single playback.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name | Type                                    | Mandatory| Description                   |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| intensity     | number                              | Yes | Intensity, in the range [0.00, 1.00], where 1.00 indicates the maximum intensity (100%).|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&amp;lt;void&amp;gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](../apis-media-kit/errorcode-media.md).

| Error Code  | Error Message                             |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 801      | Function is not supported in current device. |
| 5400102  | Operate not permit in current state. |
| 5400108  | Parameter out of range. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.setHapticsIntensity(0.5).then(() => {
  console.info('Promise returned to indicate that set intensity successfully.');
}).catch ((err: BusinessError) => {
  console.error(`Failed to set intensity. ${err}`);
});
```

### setHapticsRamp<sup>20+</sup>

setHapticsRamp(duration: number, startIntensity: number, endIntensity: number): Promise&lt;void&gt;

Sets the haptic ramp for this audio-haptic player. This API uses a promise to return the result.

> **NOTE**
>
>- This API must be called before and after the audio-haptic player plays and before the player is released.
>- This API can be called only once.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name | Type                                    | Mandatory| Description                   |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| duration | number                           | Yes | Duration of the ramp, in ms. The value must be an integer and cannot be less than 100 ms.|
| startIntensity | number                     | Yes | Start intensity. The value is in the range [0.00, 1.00], where 1.00 indicates the maximum intensity (100%).|
| endIntensity   | number                     | Yes | End intensity. The value is in the range [0.00, 1.00], where 1.00 indicates the maximum intensity (100%).|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&amp;lt;void&amp;gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Error Codes](../apis-media-kit/errorcode-media.md).

| Error Code  | Error Message                             |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 801      | Function is not supported in current device. |
| 5400102  | Operate not permit in current state. |
| 5400108  | Parameter out of range. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const duration = 10000;
const startIntensity = 0.5;
const endIntensity = 1;

audioHapticPlayerInstance.setHapticsRamp(duration, startIntensity, endIntensity).then(() => {
  console.info('Promise returned to indicate that set haptics ramp successfully.');
}).catch ((err: BusinessError) => {
  console.error(`Failed to set haptics ramp. ${err}`);
});
```
