# Interface (AudioSpatializationManager)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 18.

This interface implements spatial audio management.

Before calling any API in AudioSpatializationManager, you must use [getSpatializationManager](arkts-apis-audio-AudioManager.md#getspatializationmanager18) to obtain an AudioSpatializationManager instance.

## Modules to Import

```ts
import { audio } from '@kit.AudioKit';
```

## isSpatializationEnabledForCurrentDevice<sup>18+</sup>

isSpatializationEnabledForCurrentDevice(): boolean

Checks whether spatial audio rendering is enabled for the current device. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Check result. The value **true** means that spatial audio rendering is enabled, and **false** means the opposite.|

**Example**

```ts
import { audio } from '@kit.AudioKit';

let isSpatializationEnabledForCurrentDevice: boolean = audioSpatializationManager.isSpatializationEnabledForCurrentDevice();
console.info(`AudioSpatializationManager isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
```

## on('spatializationEnabledChangeForCurrentDevice')<sup>18+</sup>

on(type: 'spatializationEnabledChangeForCurrentDevice', callback: Callback<boolean\>): void

Subscribes to the spatial audio rendering status change event of the current device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| :------- | :--------------------------------------------------- | :--- |:---------------------------------------------|
| type     | string | Yes  | Event type. The event **'spatializationEnabledChangeForCurrentDevice'** is triggered when the spatial audio rendering status is changed.|
| callback | Callback<boolean\> | Yes  | Callback used to return the result. The value **true** means that spatial audio rendering is enabled, and **false** means the opposite.  |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';

audioSpatializationManager.on('spatializationEnabledChangeForCurrentDevice', (isSpatializationEnabledForCurrentDevice: boolean) => {
  console.info(`isSpatializationEnabledForCurrentDevice: ${isSpatializationEnabledForCurrentDevice}`);
});
```

## off('spatializationEnabledChangeForCurrentDevice')<sup>18+</sup>

off(type: 'spatializationEnabledChangeForCurrentDevice', callback?: Callback<boolean\>): void

Unsubscribes from the spatial audio rendering status change event of the current device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Audio.Spatialization

**Parameters**

| Name  | Type                                               | Mandatory| Description                                      |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | Yes  | Event type. The event **'spatializationEnabledChangeForCurrentDevice'** is triggered when the spatial audio rendering status is changed.|
| callback | Callback<boolean\> | No  | Callback used to return the result. The value **true** means that spatial audio rendering is enabled, and **false** means the opposite.  |

**Error codes**

For details about the error codes, see [Audio Error Codes](errorcode-audio.md).

| ID| Error Message|
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**Example**

```ts
import { audio } from '@kit.AudioKit';
audioSpatializationManager.off('spatializationEnabledChangeForCurrentDevice');
```
