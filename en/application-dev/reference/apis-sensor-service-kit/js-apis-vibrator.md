# @ohos.vibrator (Vibrator)

The **vibrator** module provides APIs for starting or stopping vibration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { vibrator } from '@kit.SensorServiceKit';
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void

Starts vibration with the specified effect and attribute. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.VIBRATE

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name   | Type                                  | Mandatory| Description                                                        |
| --------- | -------------------------------------- | ---- | :----------------------------------------------------------- |
| effect    | [VibrateEffect](#vibrateeffect9)       | Yes  | Vibration effect. The options are as follows:<br>- [VibrateTime](#vibratetime9): vibration with the specified duration.<br>- [VibratePreset](#vibratepreset9): vibration with a preset effect.<br>- [VibrateFromFile](#vibratefromfile10): vibration according to a custom vibration configuration file.|
| attribute | [VibrateAttribute](#vibrateattribute9) | Yes  | Vibration attribute.                                              |
| callback  | AsyncCallback&lt;void&gt;              | Yes  | Callback used to return the result. If the vibration starts, **err** is **undefined**; otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Vibrator Error Codes](errorcode-vibrator.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 801      | Capability not supported.                                    |
| 14600101 | Device operation failed.                                     |

**Example**

Trigger vibration with the specified duration.

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name   | Type                                  | Mandatory| Description                                                        |
| --------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| effect    | [VibrateEffect](#vibrateeffect9)       | Yes  | Vibration effect. The options are as follows:<br>- [VibrateTime](#vibratetime9): vibration with the specified duration.<br>- [VibratePreset](#vibratepreset9): vibration with a preset effect.<br>- [VibrateFromFile](#vibratefromfile10): vibration according to a custom vibration configuration file.|
| attribute | [VibrateAttribute](#vibrateattribute9) | Yes  | Vibration attribute.                                              |

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Vibrator Error Codes](errorcode-vibrator.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 801      | Capability not supported.                                    |
| 14600101 | Device operation failed.                                     |

**Example**

Trigger vibration with the specified duration.

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

Stop fixed-duration vibration.

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

Stop fixed-duration vibration.

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result. If the vibration stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ------------------ |
| 201      | Permission denied. |

**Example**

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.MiscDevice

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message          |
| -------- | ------------------ |
| 201      | Permission denied. |

**Example**

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## vibrator.stopVibrationSync<sup>12+</sup>

stopVibrationSync(): void

Stops any form of motor vibration.

**Required permissions**: ohos.permission.VIBRATE

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Sensors.MiscDevice

**Error codes**

For details about the error codes, see [Vibrator Error Codes](errorcode-vibrator.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 201      | Permission denied.       |
| 14600101 | Device operation failed. |

**Example**

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // Stop any form of motor vibration.
    vibrator.stopVibrationSync()
    console.info('Succeed in stopping vibration');
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**Example**

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## vibrator.isSupportEffectSync<sup>12+</sup>

isSupportEffectSync(effectId: string): boolean

Checks whether the preset vibration effect is supported.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type  | Mandatory| Description                |
| -------- | ------ | ---- | -------------------- |
| effectId | string | Yes  | ID of the preset vibration effect.|

**Return value**

| Type   | Description                                                  |
| ------- | ------------------------------------------------------ |
| boolean | Returned object. The value **true** means that the effect ID is supported, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Vibrator Error Codes](errorcode-vibrator.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14600101 | Device operation failed.                                     |

**Example**

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // Check whether the preset 'haptic.clock.timer' is supported.
    let ret = vibrator.isSupportEffectSync('haptic.clock.timer');
    console.info(`The query result is ${ret}`);
} catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isHdHapticSupported<sup>12+</sup>

isHdHapticSupported(): boolean

Checks whether HD vibration is supported.

**System capability**: SystemCapability.Sensors.MiscDevice

**Return value**

| Type   | Description      |
| ------- | ---------- |
| boolean | Returned object.|

**Error codes**

For details about the error codes, see [Vibrator Error Codes](errorcode-vibrator.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 14600101 | Device operation failed. |

**Example**

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // Check whether HD vibration is supported.
    let ret = vibrator.isHdHapticSupported();
    console.info(`The query result is ${ret}`);
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
| EFFECT_CLOCK_TIMER | 'haptic.clock.timer' | Vibration effect when a user adjusts the timer.|

## HapticFeedback<sup>12+</sup>

Defines the vibration effect.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name        | Value                   | Description                        |
| ------------ | --------------------- | ---------------------------- |
| EFFECT_SOFT  | 'haptic.effect.soft'  | Soft vibration, low frequency.|
| EFFECT_HARD  | 'haptic.effect.hard'  | Hard vibration, medium frequency.|
| EFFECT_SHARP | 'haptic.effect.sharp' | Sharp vibration, high frequency.|

## VibratorStopMode

Enumerates the modes available to stop the vibration.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name                     | Value      | Description                          |
| ------------------------- | -------- | ------------------------------ |
| VIBRATOR_STOP_MODE_TIME   | 'time'   | The vibration to stop is in **duration** mode.|
| VIBRATOR_STOP_MODE_PRESET | 'preset' | The vibration to stop is in **EffectId** mode.|

## VibrateEffect<sup>9+</sup>

Describes the vibration effect.

**System capability**: SystemCapability.Sensors.MiscDevice

| Type                            | Description                          |
| -------------------------------- | ------------------------------ |
| [VibrateTime](#vibratetime9) | Vibration with the specified duration.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| [VibratePreset](#vibratepreset9) | Vibration with a preset effect.|
| [VibrateFromFile](#vibratefromfile10) | Vibration according to a custom vibration configuration file.|

## VibrateTime<sup>9+</sup>

Describes the fixed-duration vibration.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type   | Mandatory| Description                          |
| -------- | ------ | ----- | ------------------------------ |
| type     | 'time' |  Yes  | The value **time** means vibration with the specified duration.|
| duration | number |  Yes  | Vibration duration, in ms.        |

## VibratePreset<sup>9+</sup>

Describes the preset vibration.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type     | Mandatory| Description                          |
| -------- | -------- | ---- |------------------------------ |
| type     | 'preset' |  Yes | The value **preset** means vibration with the specified effect.|
| effectId | string   |  Yes | Preset vibration effect ID.            |
| count    | number   |  No | Number of repeated vibrations. The default value is **1**. This parameter is optional.|
| intensity<sup>12+</sup> | number | No| Vibration intensity. The value ranges from 0 to 100. The default value is **100**. This parameter is optional. If vibration intensity adjustment is not supported, the default vibration intensity will be used.|

## VibrateFromFile<sup>10+</sup>

Describes the custom vibration type, which is supported only by certain devices. If a device does not support this vibration type, [an error code indicating unsupported device](../errorcode-universal.md) is returned.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type      | Mandatory| Description                          |
| -------- | --------  | ---- | ------------------------------ |
| type     | 'file' |  Yes | The value **file** means vibration according to a vibration configuration file.|
| hapticFd | [HapticFileDescriptor](#hapticfiledescriptor10)<sup>10+</sup> | Yes| File descriptor (FD) of the vibration configuration file.|

## HapticFileDescriptor<sup>10+</sup>

Describes the FD of a custom vibration configuration file. Ensure that the file is available, and the parameters in it can be obtained from the sandbox path through the [file management API](../apis-core-file-kit/js-apis-file-fs.md#fsopen) or from the HAP resource through the [resource management API](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9). The use case is as follows: The system triggers vibration according to the sequence set in a configuration file, based on the specified offset and length. For details about the storage format of the vibration sequence, see [Custom Vibration](../../device/sensor/vibrator-guidelines.md#custom-vibration).

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Type     |  Mandatory | Description                          |
| -------- | -------- |--------| ------------------------------|
| fd       | number   |  Yes   | FD of the custom vibration configuration file.               |
| offset   | number   |  No   | Offset from the start position of the file, in bytes. The default value is the start position of the file, and the value cannot exceed the valid range of the file.|
| length   | number   |  No   | Resource length, in bytes. The default value is the length from the offset position to the end of the file, and the value cannot exceed the valid range of the file.|

## VibrateAttribute<sup>9+</sup>

Describes the vibration attribute.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name | Type| Mandatory| Description          |
| ----- | ------ | ---- | -------------- |
| id    | number      |  No| Vibrator ID. The default value is **0**.   |
| usage | [Usage](#usage9) | Yes| Vibration scenario.|

## Usage<sup>9+</sup>

type Usage = 'unknown' | 'alarm' | 'ring' | 'notification' | 'communication' | 'touch' | 'media' | 'physicalFeedback' | 'simulateReality'

Enumerates the vibration scenarios.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Sensors.MiscDevice
<!--RP1-->
| Type    | Description                          |
| ---------------- | ------------------------------ |
| 'unknown'     | Unknown scenario, with the lowest priority. This parameter has a fixed value of **unknown**.|
| 'alarm'      | Vibration for alarms. This parameter has a fixed value of **alarm**.|
| 'ring'         | Vibration for ringing. This parameter has a fixed value of **ring**.|
| 'notification' | Vibration for notification. This parameter has a fixed value of **notification**.|
| 'communication' | Vibration for communication. This parameter has a fixed value of **communication**.|
| 'touch'        | Vibration for touch. This parameter has a fixed value of **touch**.|
| 'media'        | Vibration for media. This parameter has a fixed value of **media**.|
| 'physicalFeedback' | Vibration for physical feedback. This parameter has a fixed value of **physicalFeedback**.|
| 'simulateReality' | Vibration for simulated reality. This parameter has a fixed value of **simulateReality**.|
<!--RP1End-->

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
