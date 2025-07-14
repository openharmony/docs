# @ohos.multimedia.audioHaptic (Audio-Haptic) (System API)

Audio-haptic enables users to get rhythmic auditory and haptic feedback while having incoming calls or messages.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```ts
import { audioHaptic } from '@kit.AudioKit';
```

## AudioHapticPlayer

Implements audio-haptic playback. Before calling any API in **AudioHapticPlayer**, you must use [createPlayer](./js-apis-audioHaptic.md#createplayer) to create an **AudioHapticPlayer** instance.

### isHapticsIntensityAdjustmentSupported

isHapticsIntensityAdjustmentSupported(): boolean

Check if the device supports adjusting haptics intensity.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| boolean | The value **true** indicates that the device supports haptics intensity adjustment; **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
|---------|-----------------------------------|
| 202 | Caller is not a system application. |

**Example**

```ts
const result: boolean = audioHapticPlayerInstance.isHapticsIntensityAdjustmentSupported();
```

### isHapticsRampSupported

isHapticsRampSupported(): boolean

Check if the device supports the haptics intensity ramp effect.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| boolean | The value **true** indicates that the device supports haptics intensity ramp effect; **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
|---------|-----------------------------------|
| 202 | Caller is not a system application. |

**Example**

```ts
const result: boolean = audioHapticPlayerInstance.isHapticsRampSupported();
```

### enableHapticsInSilentMode

enableHapticsInSilentMode(enable: boolean): void

Enables haptics when the ringer mode is set to silent mode.
This API can be called before the player starts or after it stops, but before it is released.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| enable     | boolean                                | Yes  | Whether to enable or disable haptics. The value **true** means to enable.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 5400102  | Operate not permit in current state. |

**Example**

```ts
audioHapticPlayerInstance.enableHapticsInSilentMode(true);
```

### setHapticsIntensity

setHapticsIntensity(intensity: number): Promise&lt;void&gt;

This method sets the haptics intensity for the player and returns the result using a promise.
Call this API before the player is released, setting it only once per playback.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                     | Mandatory| Description                    |
| -------- | --------------------------------------| ---- | ------------------------ |
| intensity | number                           | Yes  | Target haptics intensity. The value ranges from 0.00 to 1.00, where 1.00 indicates the maximum intensity (100%).|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
|---------|-----------------------------------|
| 202      | Caller is not a system application. |
| 801      | Function is not supported in current device. |
| 5400102  | Operate not permit in current state. |
| 5400108  | Parameter out of range. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.setHapticsIntensity(0.5).then(() => {
  console.info(`Promise returned to indicate that set intensity successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set intensity. ${err}`);
});
```

### setHapticsRamp

setHapticsRamp(duration: number, startIntensity: number, endIntensity: number): Promise&lt;void&gt;

This player sets the haptics intensity ramp effect using a promise to return the result.
Call this API before the player starts or after it stops, but before it is released.
This API must be called only once.

**System capability**: SystemCapability.Multimedia.AudioHaptic.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                    |
| -------- | ---------------------------------| ---- | ------------------------ |
| duration | number                           | Yes  | Ramp duration, measured in milliseconds. The value should be an integer that is not less than 100.|
| startIntensity | number                     | Yes  | Start intensity of the haptics ramp. The value ranges from 0.00 to 1.00, where 1.00 indicates the maximum intensity (100%).|
| endIntensity   | number                     | Yes  | End intensity of the haptics ramp. The value ranges from 0.00 to 1.00, where 1.00 indicates the maximum intensity (100%).|

**Return value**

| Type               | Description                           |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Media Error Codes](../apis-media-kit/errorcode-media.md).

| ID  | Error Message                             |
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
  console.info(`Promise returned to indicate that set haptics ramp successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to set haptics ramp. ${err}`);
});
```