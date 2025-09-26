# vibrator.h
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @butterls-->
<!--Tester: @murphy84-->
<!--Adviser: @hu-zhiqiong-->

## Overview

The **vibrator.h** file declares the APIs for starting or stopping vibration.

**Library**: libohvibrator.z.so

**System capability**: SystemCapability.Sensors.MiscDevice

**Since**: 11

**Related module**: [Vibrator](_vibrator.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [OHOS::Sensors::OH_Vibrator_PlayVibration](#oh_vibrator_playvibration)(int32_t duration, Vibrator_Attribute attribute) | Controls the vibrator to vibrate continuously for a given duration.|
| [OHOS::Sensors::OH_Vibrator_PlayVibrationCustom](#oh_vibrator_playvibrationcustom)(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute) | Controls the vibrator to vibrate with the custom sequence.          |
| [OHOS::Sensors::OH_Vibrator_Cancel](#oh_vibrator_cancel)() | Stops the vibration. |


## Function Description


### OH_Vibrator_Cancel()

```
int32_t OHOS::Sensors::OH_Vibrator_Cancel()
```
**Description**

Stops the vibration.

**Since**: 11

**Returns**

Returns **0** if the operation is successful; returns a non-zero value otherwise. For details, see [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode).

**Required Permissions**

ohos.permission.VIBRATE


### OH_Vibrator_PlayVibration()

```
int32_t OHOS::Sensors::OH_Vibrator_PlayVibration(int32_t duration, Vibrator_Attribute attribute)
```
**Description**

Controls the vibrator to vibrate continuously for a given duration.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| duration | Vibration duration, in milliseconds. The value range is (0,1800000]. |
| attribute | Vibration attribute. For details, see [Vibrator_Attribute](_vibrator.md#vibrator_attribute).|

**Returns**

Returns **0** if the operation is successful; returns a non-zero value otherwise. For details, see [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode).

**Required Permissions**

ohos.permission.VIBRATE


### OH_Vibrator_PlayVibrationCustom()

```
int32_t OHOS::Sensors::OH_Vibrator_PlayVibrationCustom(Vibrator_FileDescription fileDescription, Vibrator_Attribute vibrateAttribute)
```
**Description**

Controls the vibrator to vibrate with the custom sequence.

**Since**: 11

**Parameters**

| Name| Description|
| -------- | -------- |
| fileDescription | File descriptor of the custom vibration effect. For details, see [Vibrator_FileDescription](_vibrator.md#vibrator_filedescription).|
| vibrateAttribute | Vibration attribute. For details, see [Vibrator_Attribute](_vibrator.md#vibrator_attribute).|

**Returns**

Returns **0** if the operation is successful; returns a non-zero value otherwise. For details, see [Vibrator_ErrorCode](_vibrator.md#vibrator_errorcode).

**Required Permissions**

ohos.permission.VIBRATE
