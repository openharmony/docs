# @ohos.vibrator (Vibrator)

The **vibrator** module provides APIs for starting or stopping vibration.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import vibrator from '@ohos.vibrator';
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void

Starts vibration with the specified effect and attribute. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name   | Type                                  | Mandatory| Description                                                      |
| --------- | -------------------------------------- | ---- | :--------------------------------------------------------- |
| effect    | [VibrateEffect](#vibrateeffect9)       | Yes  | Vibration effect.                                            |
| attribute | [VibrateAttribute](#vibrateattribute9) | Yes  | Vibration attribute.                                            |
| callback  | AsyncCallback&lt;void&gt;              | Yes  | Callback used to return the result. If the vibration starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Vibrator Error Codes](../errorcodes/errorcode-vibrator.md).

| ID| Error Message                |
| -------- | ------------------------ |
| 14600101 | Device operation failed. |

**Example**

```js
import vibrator from '@ohos.vibrator';
try {
    vibrator.startVibration({
        type: 'time',
        duration: 1000,
    }, {
        id: 0,
        usage: 'alarm'
    }, (error) => {
        if (error) {
            console.error('Vibrate fail, error.code: ' + error.code + 'error.message: ', + error.message);
            return;
        }
        console.log('Callback returned to indicate a successful vibration.');
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt;

Starts vibration with the specified effect and attribute. This API uses a promise to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name   | Type                                  | Mandatory| Description          |
| --------- | -------------------------------------- | ---- | -------------- |
| effect    | [VibrateEffect](#vibrateeffect9)       | Yes  | Vibration effect.|
| attribute | [VibrateAttribute](#vibrateattribute9) | Yes  | Vibration attribute.|

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

  ```js
import vibrator from '@ohos.vibrator';
try {
    vibrator.startVibration({
        type: 'time',
        duration: 1000
    }, {
        id: 0,
        usage: 'alarm'
    }).then(() => {
        console.log('Promise returned to indicate a successful vibration');
    }, (error) => {
        console.error('error.code' + error.code + 'error.message' + error.message);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}
  ```

## vibrator.stopVibration<sup>9+</sup>

stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void

Stops vibration in the specified mode. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Mode to stop the vibration.                                    |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result. If the vibration stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```js
import vibrator from '@ohos.vibrator';
try {
    // Start vibration at a fixed duration.
    vibrator.startVibration({
        type: 'time',
        duration: 1000,
    }, {
        id: 0,
        usage: 'alarm'
    }, (error) => {
        if (error) {
            console.error('Vibrate fail, error.code: ' + error.code + 'error.message: ', + error.message);
            return;
        }
        console.log('Callback returned to indicate a successful vibration.');
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}

try {
    // Stop vibration in VIBRATOR_STOP_MODE_TIME mode.
    vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, function (error) {
        if (error) {
            console.log('error.code' + error.code + 'error.message' + error.message);
            return;
        }
        console.log('Callback returned to indicate successful.');
    })
} catch (err) {
    console.info('errCode: ' + err.code + ' ,msg: ' + err.message);
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
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Mode to stop the vibration.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
import vibrator from '@ohos.vibrator';
try {
    // Start vibration at a fixed duration.
    vibrator.startVibration({
        type: 'time',
        duration: 1000
    }, {
        id: 0,
        usage: 'alarm'
    }).then(() => {
        console.log('Promise returned to indicate a successful vibration');
    }, (error) => {
        console.error('error.code' + error.code + 'error.message' + error.message);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}

try {
    // Stop vibration in VIBRATOR_STOP_MODE_TIME mode.
    vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
        console.log('Promise returned to indicate a successful vibration.');
    }, (error) => {
        console.log('error.code' + error.code + 'error.message' + error.message);
    });
} catch (err) {
    console.info('errCode: ' + err.code + ' ,msg: ' + err.message);
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

  ```js
import vibrator from '@ohos.vibrator';
try {
    // Start vibration at a fixed duration.
    vibrator.startVibration({
        type: 'time',
        duration: 1000,
    }, {
        id: 0,
        usage: 'alarm'
    }, (error) => {
        if (error) {
            console.error('Vibrate fail, error.code: ' + error.code + 'error.message: ', + error.message);
            return;
        }
        console.log('Callback returned to indicate a successful vibration.');
    });
} catch (error) {
    console.error('errCode: ' + error.code + ' ,msg: ' + error.message);
}

try {
    // Stop vibration in all modes.
    vibrator.stopVibration(function (error) {
        if (error) {
            console.log('error.code' + error.code + 'error.message' + error.message);
            return;
        }
        console.log('Callback returned to indicate successful.');
    })
} catch (error) {
    console.info('errCode: ' + error.code + ' ,msg: ' + error.message);
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

  ```js
import vibrator from '@ohos.vibrator';
try {
    // Start vibration at a fixed duration.
    vibrator.startVibration({
        type: 'time',
        duration: 1000
    }, {
        id: 0,
        usage: 'alarm'
    }).then(() => {
        console.log('Promise returned to indicate a successful vibration');
    }, (error) => {
        console.error('error.code' + error.code + 'error.message' + error.message);
    });
} catch (error) {
    console.error('errCode: ' + error.code + ' ,msg: ' + error.message);
}

try {
    // Stop vibration in all modes.
    vibrator.stopVibration().then(() => {
        console.log('Promise returned to indicate a successful vibration.');
    }, (error) => {
        console.log('error.code' + error.code + 'error.message' + error.message);
    });
} catch (error) {
    console.info('errCode: ' + error.code + ' ,msg: ' + error.message);
}
  ```

## vibrator.isSupportEffect<sup>10+</sup>

isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the passed effect ID is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                        | Mandatory| Description                                                  |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| effectId | string                       | Yes  | Vibration effect ID.                                            |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means that the passed effect ID is supported, and **false** means the opposite.|

**Example**

  ```js
import vibrator from '@ohos.vibrator';
try {
    // Check whether 'haptic.clock.timer' is supported.
    vibrator.isSupportEffect('haptic.clock.timer', function (err, state) {
        if (err) {
            console.error('isSupportEffect failed, error:' + JSON.stringify(err));
            return;
        }
        console.log('The effectId is ' + (state ? 'supported' : 'unsupported'));
        if (state) {
            try {
                vibrator.startVibration({ // To use startVibration, you must configure the ohos.permission.VIBRATE permission.
                    type: 'preset',
                    effectId: 'haptic.clock.timer',
                    count: 1,
                }, {
                    usage: 'unknown'
                }, (error) => {
                    if(error) {
                        console.error('haptic.clock.timer vibrator error:'  + JSON.stringify(error));
                    } else {
                        console.log('haptic.clock.timer vibrator success');
                    }
                });
            } catch (error) {
                console.error('Exception in, error:' + JSON.stringify(error));
            }
        }
    })
} catch (error) {
    console.error('Exception in, error:' + JSON.stringify(error));
}
  ```

## vibrator.isSupportEffect<sup>10+</sup>

isSupportEffect(effectId: string): Promise&lt;boolean&gt;

Checks whether the passed effect ID is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type  | Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| effectId | string | Yes  | Vibration effect ID.|

**Return value**

| Type                  | Description                                                     |
| ---------------------- | --------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise that returns the result. The value **true** means that the passed effect ID is supported, and **false** means the opposite.|

**Example**

  ```js
import vibrator from '@ohos.vibrator';
try {
    // Check whether 'haptic.clock.timer' is supported.
    vibrator.isSupportEffect('haptic.clock.timer').then((state) => {
        console.log('The effectId is ' + (state ? 'supported' : 'unsupported'));
        if (state) {
            try {
                vibrator.startVibration({
                    type: 'preset',
                    effectId: 'haptic.clock.timer',
                    count: 1,
                }, {
                    usage: 'unknown'
                }).then(()=>{
                    console.log('Promise returned to indicate a successful vibration');
                }).catch((error)=>{
                    console.error('Promise returned to indicate a failed vibration:' + JSON.stringify(error));
                });
            } catch (error) {
                console.error('Exception in, error:' + JSON.stringify(error));
            }
        }
    }, (error) => {
        console.error('isSupportEffect failed, error:' + JSON.stringify(error));
    })
} catch (error) {
    console.error('Exception in, error:' + JSON.stringify(error));
}
  ```

## EffectId

Describes the preset vibration effect ID.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name              | Value                  | Description                            |
| ------------------ | -------------------- | -------------------------------- |
| EFFECT_CLOCK_TIMER | "haptic.clock.timer" | Vibration effect of the vibrator when a user adjusts the timer.|


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
| [VibrateTime](#vibratetime9)     | Triggers vibration with the specified duration. This API uses a promise to return the result.|
| [VibratePreset](#vibratepreset9) | Vibration with a preset effect.|

## VibrateTime<sup>9+</sup>

Describes the vibration with the specified duration.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Value| Description                          |
| -------- | ------ | ------------------------------ |
| type     | "time" | Vibration with the specified duration.|
| duration | -      | Vibration duration, in ms.        |

## VibratePreset<sup>9+</sup>

Describes the vibration with a preset effect.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name    | Value      | Description                          |
| -------- | -------- | ------------------------------ |
| type     | "preset" | Vibration with the specified effect.|
| effectId | -        | Preset vibration effect ID.            |
| count    | -        | Number of vibrations to repeat.              |

## VibrateAttribute<sup>9+</sup>

Describes the vibration attribute.

**System capability**: SystemCapability.Sensors.MiscDevice

| Name | Value| Description          |
| ----- | ------ | -------------- |
| id    | 0      | Vibrator ID.    |
| usage | -      | Vibration scenario.|

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

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9-1) instead.

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

  ```js
vibrator.vibrate(1000).then(() => {
    console.log('Promise returned to indicate a successful vibration.');
}, (error) => {
    console.log('error.code' + error.code + 'error.message' + error.message);
});
  ```

## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(duration: number, callback?: AsyncCallback&lt;void&gt;): void

Triggers vibration with the specified duration. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9) instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                     | Mandatory| Description                                                      |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| duration | number                    | Yes  | Vibration duration, in ms.                                    |
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to return the result. If the vibration starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```js
vibrator.vibrate(1000, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
  ```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId): Promise&lt;void&gt;

Triggers vibration with the specified effect. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9-1) instead.

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

  ```js
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(() => {
    console.log('Promise returned to indicate a successful vibration.');
}, (error) => {
    console.log('error.code' + error.code + 'error.message' + error.message);
});
  ```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId, callback?: AsyncCallback&lt;void&gt;): void

Triggers vibration with the specified effect. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.startVibration](#vibratorstartvibration9) instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                     | Mandatory| Description                                                      |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| effectId | [EffectId](#effectid)     | Yes  | Preset vibration effect ID.                                        |
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to return the result. If the vibration starts, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```js
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
  ```

## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode): Promise&lt;void&gt;

Stops vibration in the specified mode. This API uses a promise to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.stopVibration](#vibratorstopvibration9-1) instead.

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

  ```js
// Start vibration based on the specified effect ID.
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
// Stop vibration in VIBRATOR_STOP_MODE_PRESET mode.
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
    console.log('Promise returned to indicate a successful vibration.');
}, (error) => {
    console.log('error.code' + error.code + 'error.message' + error.message);
});
  ```


## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode, callback?: AsyncCallback&lt;void&gt;): void

Stops vibration in the specified mode. This API uses an asynchronous callback to return the result.

This API is deprecated since API version 9. You are advised to use [vibrator.stopVibration](#vibratorstopvibration9) instead.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | Yes  | Mode to stop the vibration.                                    |
| callback | AsyncCallback&lt;void&gt;             | No  | Callback used to return the result. If the vibration stops, **err** is **undefined**; otherwise, **err** is an error object.|

**Example**

  ```js
// Start vibration based on the specified effect ID.
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
// Stop vibration in VIBRATOR_STOP_MODE_PRESET mode.
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate successful.');
    }
})
  ```
