# vibrator.h


## Overview

The **vibrator.h** file declares the APIs for starting or stopping vibration.

**Library**: libohvibrator.z.so

**System capability**: SystemCapability.Sensors.MiscDevice

**Since**: 11

**Related module**: [Vibrator](_xe9_xa9_xac_xe8_xbe_xbe.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OHOS::Sensors::OH_Vibrator_PlayVibration](#oh_vibrator_playvibration) (int32_t duration, Vibrator_Attribute attribute) | int32_t<br>Controls the vibrator to vibrate continuously for a given duration. |
| [OHOS::Sensors::OH_Vibrator_PlayVibrationCustom](#oh_vibrator_playvibrationcustom) (Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute) | int32_t<br>Controls the vibrator to vibrate with the custom sequence. |
| [OHOS::Sensors::OH_Vibrator_Cancel](#oh_vibrator_cancel) () | int32_t<br>Stops the vibration. |


## Function Description


### OH_Vibrator_Cancel()

```
int32_t OHOS::Sensors::OH_Vibrator_Cancel ()
```
**Description**

Stops the vibration.

**Since**: 11

**Returns**

Returns **0** if the operation is successful; returns a non-zero value otherwise. For details, see **Vibrator_ErrorCode**.

**Required Permissions**

ohos.permission.VIBRATE


### OH_Vibrator_PlayVibration()

```
int32_t OHOS::Sensors::OH_Vibrator_PlayVibration (int32_t duration, Vibrator_Attribute attribute )
```
**Description**

Controls the vibrator to vibrate continuously for a given duration.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| duration | Vibration duration, in milliseconds. |
| attribute | Vibration attribute. For details, see **Vibrator_Attribute**. |

**Returns**

Returns **0** if the operation is successful; returns a non-zero value otherwise. For details, see **Vibrator_ErrorCode**.

**Required Permissions**

ohos.permission.VIBRATE


### OH_Vibrator_PlayVibrationCustom()

```
int32_t OHOS::Sensors::OH_Vibrator_PlayVibrationCustom (Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute )
```
**Description**

Controls the vibrator to vibrate with the custom sequence.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| fileDescription | File descriptor of the custom vibration effect. For details, see **Vibrator_FileDescription**. |
| vibrateAttribute | Vibration attribute. For details, see **Vibrator_Attribute**. |

**Returns**

Returns **0** if the operation is successful; returns a non-zero value otherwise. For details, see **Vibrator_ErrorCode**.

**Required Permissions**

ohos.permission.VIBRATE
