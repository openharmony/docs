# @ohos.vibrator (Vibrator)

The **vibrator** module provides APIs for starting or stopping vibration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import vibrator from '@ohos.vibrator';
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void

Starts vibration with the specified effect and attribute. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name   | Type                                               | Mandatory| Description                                                        |
| --------- | --------------------------------------------------- | ---- | :----------------------------------------------------------- |
| effect    | [VibrateEffect](#vibrateeffect9)<sup>9+</sup>       | Yes  | Vibration effect. The options are as follows:<br>- [VibrateTime](#vibratetime9): vibration with the specified duration.<br>- [VibratePreset](#vibratepreset9): vibration with a preset effect.<br>- [VibrateFromFile](#vibratefromfile10): vibration according to a custom vibration configuration file.|
| attribute | [VibrateAttribute](#vibrateattribute9)<sup>9+</sup> | Yes  | Vibration attribute.                                              |
| callback  | AsyncCallback&lt;void&gt;                           | Yes  | Callback used to return the result. If the vibration starts, **err** is **undefined**; otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Vibrator Error Codes](../errorcodes/errorcode-vibrator.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 14600101 | Device operation failed. |

**Example**

Trigger vibration with the specified duration.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm'
  }, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration');
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

Trigger vibration with a preset effect.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm'
  }, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration');
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

Trigger vibration according to a custom vibration configuration file.

```ts
import vibrator from '@ohos.vibrator';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';

const fileName: string = 'xxx.json';

let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);

try {
  vibrator.startVibration({
    type: "file",
    hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
  }, {
    id: 0,
    usage: 'alarm'
  }, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration');
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

getContext().resourceManager.closeRawFdSync(fileName);
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt;

Starts vibration with the specified effect and attribute. This API uses a promise to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name   | Type                                               | Mandatory| Description                                                        |
| --------- | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| effect    | [VibrateEffect](#vibrateeffect9)<sup>9+</sup>       | Yes  | Vibration effect. The options are as follows:<br>- [VibrateTime](#vibratetime9): vibration with the specified duration.<br>- [VibratePreset](#vibratepreset9): vibration with a preset effect.<br>- [VibrateFromFile](#vibratefromfile10): vibration according to a custom vibration configuration file.|
| attribute | [VibrateAttribute](#vibrateattribute9)<sup>9+</sup> | Yes  | Vibration attribute.                                              |

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Vibrator Error Codes](../errorcodes/errorcode-vibrator.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 14600101 | Device operation failed. |

**Example**

Trigger vibration with the specified duration.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  vibrator.startVibration({
    type: 'time',
    duration: 1000
  }, {
    id: 0,
    usage: 'alarm'
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

Trigger vibration with a preset effect.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm'
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

Trigger vibration according to a custom vibration configuration file.

```ts
import vibrator from '@ohos.vibrator';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';

const fileName: string = 'xxx.json';

let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);

try {
  vibrator.startVibration({
    type: "file",
    hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
  }, {
    id: 0,
    usage: 'alarm'
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

getContext().resourceManager.closeRawFdSync(fileName);
```

## vibrator.stopVibration<sup>9+</sup>

stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void

Stops vibration in the specified mode. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Mode to stop the vibration. The options are as follows:<br>- **VIBRATOR_STOP_MODE_TIME**: used to stop fixed-duration vibration.<br>- **VIBRATOR_STOP_MODE_PRESET**: used to stop preset vibration.<br>To stop custom vibration, use [vibrator.stopVibration<sup>10+</sup>](#vibratorstopvibration10).                                 |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result. If the vibration stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

Stop fixed-duration vibration.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Start vibration at a fixed duration.
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm'
  }, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration');
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

try {
  // Stop vibration in VIBRATOR_STOP_MODE_TIME mode.
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in stopping vibration');
  })
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

Stop preset vibration.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Start vibration with a preset effect.
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm'
  }, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration');
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

try {
  // Stop vibration in VIBRATOR_STOP_MODE_PRESET mode.
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {
    if (error) {
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in stopping vibration');
  })
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.stopVibration<sup>9+</sup>

stopVibration(stopMode: VibratorStopMode): Promise&lt;void&gt;

Stops vibration in the specified mode. This API uses a promise to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                                 | Mandatory| Description                    |
| -------- | ------------------------------------- | ---- | ------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Mode to stop the vibration. The options are as follows:<br>- **VIBRATOR_STOP_MODE_TIME**: used to stop fixed-duration vibration.<br>- **VIBRATOR_STOP_MODE_PRESET**: used to stop preset vibration.<br>To stop custom vibration, use [vibrator.stopVibration<sup>10+</sup>](#vibratorstopvibration10-1).|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

Stop fixed-duration vibration.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Start vibration at a fixed duration.
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm'
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

try {
  // Stop vibration in VIBRATOR_STOP_MODE_TIME mode.
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME).then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

Stop preset vibration.

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Start vibration with a preset effect.
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm'
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

try {
  // Stop vibration in VIBRATOR_STOP_MODE_PRESET mode.
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.stopVibration<sup>10+</sup>

stopVibration(callback: AsyncCallback&lt;void&gt;): void

Stops vibration in all modes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the vibration stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Stop vibration in all modes.
  vibrator.stopVibration((error: BusinessError) => {
    if (error) {
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in stopping vibration');
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.stopVibration<sup>10+</sup>

stopVibration(): Promise&lt;void&gt;

Stops vibration in all modes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Stop vibration in all modes.
  vibrator.stopVibration().then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isSupportEffect<sup>10+</sup>

isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an effect ID is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                        | Mandatory| Description                                                  |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| effectId | string                       | Yes  | Vibration effect ID.                                          |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the effect ID is supported, and **false** means the opposite.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Check whether 'haptic.clock.timer' is supported.
  vibrator.isSupportEffect('haptic.clock.timer', (err: BusinessError, state: boolean) => {
    if (err) {
      console.error(`Failed to query effect. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeed in querying effect');
    if (state) {
      try {
        // To use startVibration, you must configure the ohos.permission.VIBRATE permission.
        vibrator.startVibration({
          type: 'preset',
          effectId: 'haptic.clock.timer',
          count: 1,
        }, {
          usage: 'unknown'
        }, (error: BusinessError) => {
          if (error) {
            console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          } else {
            console.info('Succeed in starting vibration');
          }
        });
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
      }
    }
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isSupportEffect<sup>10+</sup>

isSupportEffect(effectId: string): Promise&lt;boolean&gt;

Checks whether an effect ID is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type  | Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| effectId | string | Yes  | Vibration effect ID.|

**Return value**

| Type                  | Description                                                     |
| ---------------------- | --------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise that returns the result. The value **true** means that the effect ID is supported, and **false** means the opposite.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // Check whether 'haptic.clock.timer' is supported.
  vibrator.isSupportEffect('haptic.clock.timer').then((state: boolean) => {
    console.info(`The query result is ${state}`);
    if (state) {
      try {
        vibrator.startVibration({
          type: 'preset',
          effectId: 'haptic.clock.timer',
          count: 1,
        }, {
          usage: 'unknown'
        }).then(() => {
          console.info('Succeed in starting vibration');
        }).catch((error: BusinessError) => {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
        });
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
      }
    }
  }, (error: BusinessError) => {
    console.error(`Failed to query effect. Code: ${error.code}, message: ${error.message}`);
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## EffectId

Enumerates the preset vibration effect IDs.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name              | Value                  | Description                            |
| ------------------ | -------------------- | -------------------------------- |
| EFFECT_CLOCK_TIMER | "haptic.clock.timer" | Vibration effect when a user adjusts the timer.|


## VibratorStopMode

Enumerates the modes available to stop the vibration.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name                     | Value      | Description                          |
| ------------------------- | -------- | ------------------------------ |
| VIBRATOR_STOP_MODE_TIME   | "time"   | The vibration to stop is in **duration** mode.|
| VIBRATOR_STOP_MODE_PRESET | "preset" | The vibration to stop is in **EffectId** mode.|

## VibrateEffect<sup>9+</sup>

Describes the vibration effect.

**System capability**: SystemCapability.Sensors.MiscDevice

| Type                            | Description                          |
| -------------------------------- | ------------------------------ |
| [VibrateTime](#vibratetime9)<sup>9+</sup> | Vibration with the specified duration.|
| [VibratePreset](#vibratepreset9)<sup>9+</sup> | Vibration with a preset effect.|
| [VibrateFromFile](#vibratefromfile10)<sup>10+</sup> | Vibration according to a custom vibration configuration file.|

## VibrateTime<sup>9+</sup>

Describes the fixed-duration vibration.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type   | Mandatory| Description                          |
| -------- | ------ | ----- | ------------------------------ |
| type     | string |  Yes  | The value **time** means vibration with the specified duration.|
| duration | number |  Yes  | Vibration duration, in ms.        |

## VibratePreset<sup>9+</sup>

Describes the preset vibration.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type     | Mandatory| Description                          |
| -------- | -------- | ---- |------------------------------ |
| type     | string   |  Yes | The value **preset** means vibration with the specified effect.|
| effectId | string   |  Yes | Preset vibration effect ID.            |
| count    | number   |  Yes | Number of vibrations to repeat.              |

## VibrateFromFile<sup>10+</sup>

Describes the custom vibration type, which is supported only by certain devices. If a device does not support this vibration type, [an error code indicating unsupported device](../errorcodes/errorcode-universal.md) is returned.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type      | Mandatory| Description                          |
| -------- | --------  | ---- | ------------------------------ |
| type     | string    |  Yes | The value **file** means vibration according to a vibration configuration file.|
| hapticFd | [HapticFileDescriptor](#hapticfiledescriptor10)<sup>10+</sup> | Yes| File descriptor (FD) of the vibration configuration file.|

## HapticFileDescriptor<sup>10+</sup>

Describes the FD of a custom vibration configuration file. Ensure that the file is available, and the parameters in it can be obtained from the sandbox path through the [file management API](js-apis-file-fs.md#fsopen) or from the HAP resource through the [resource management API](js-apis-resource-manager.md#getrawfd9). The use case is as follows: The system triggers vibration according to the sequence set in a configuration file, based on the specified offset and length. For details about the storage format of the vibration sequence, see [Custom Vibration](../../device/vibrator-guidelines.md#custom-vibration).

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type     |  Mandatory | Description                          |
| -------- | -------- |--------| ------------------------------|
| fd       | number   |  Yes   | FD of the custom vibration configuration file.               |
| offset   | number   |  No   | Offset from the start position of the file, in bytes. The default value is the start position of the file, and the value cannot exceed the valid range of the file.|
| length   | number   |  No   | Resource length, in bytes. The default value is the length from the offset position to the end of the file, and the value cannot exceed the valid range of the file.|

## VibrateAttribute<sup>9+</sup>

Describes the vibration attribute.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name | Type| Mandatory| Description          |
| ----- | ------ | ---- | -------------- |
| id    | number      |  No| Vibrator ID. The default value is **0**.   |
| usage | [Usage](#usage9)<sup>9+</sup> | Yes| Vibration scenario.|

## Usage<sup>9+</sup>

Enumerates the vibration scenarios.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name            | Type  | Description                          |
| ---------------- | ------ | ------------------------------ |
| unknown          | string | Unknown scenario, with the lowest priority.|
| alarm            | string | Vibration for alarms.          |
| ring             | string | Vibration for incoming calls.          |
| notification     | string | Vibration for notifications.          |
| communication    | string | Vibration for communication.          |
| touch            | string | Touch vibration scenario.          |
| media            | string | Multimedia vibration scenario.        |
| physicalFeedback | string | Physical feedback vibration scenario.      |
| simulateReality  | string | Simulated reality vibration scenario.      |

## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(duration: number): Promise&lt;void&gt;

Triggers vibration with the specified duration. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type  | Mandatory| Description                  |
| -------- | ------ | ---- | ---------------------- |
| duration | number | Yes  | Vibration duration, in ms.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

vibrator.vibrate(1000).then(() => {
  console.info('Succeed in vibrating');
}, (error: BusinessError) => {
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
});
```

## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(duration: number, callback?: AsyncCallback&lt;void&gt;): void

Triggers vibration with the specified duration. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                     | Mandatory| Description                                                      |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| duration | number                    | Yes  | Vibration duration, in ms.                                    |
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to return the result. If the vibration starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

vibrator.vibrate(1000, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId): Promise&lt;void&gt;

Triggers vibration with the specified effect. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| effectId | [EffectId](#effectid) | Yes  | Preset vibration effect ID.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(() => {
  console.info('Succeed in vibrating');
}, (error: BusinessError) => {
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
});
```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId, callback?: AsyncCallback&lt;void&gt;): void

Triggers vibration with the specified effect. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                     | Mandatory| Description                                                      |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| effectId | [EffectId](#effectid)     | Yes  | Preset vibration effect ID.                                        |
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to return the result. If the vibration starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
```

## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode): Promise&lt;void&gt;

Stops vibration in the specified mode. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.stopVibration](#vibratorstopvibration9-1)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                                 | Mandatory| Description                    |
| -------- | ------------------------------------- | ---- | ------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Mode to stop the vibration.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

// Start vibration based on the specified effect ID.
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
// Stop vibration in VIBRATOR_STOP_MODE_PRESET mode.
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
  console.info('Succeed in stopping');
}, (error: BusinessError) => {
  console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);
});
```


## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode, callback?: AsyncCallback&lt;void&gt;): void

Stops vibration in the specified mode. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.stopVibration](#vibratorstopvibration9)<sup>9+</sup> instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Mode to stop the vibration.                                    |
| callback | AsyncCallback&lt;void&gt;             | No  | Callback used to return the result. If the vibration stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

// Start vibration based on the specified effect ID.
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
// Stop vibration in VIBRATOR_STOP_MODE_PRESET mode.
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in stopping');
  }
})
```
