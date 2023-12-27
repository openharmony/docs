# vibrator_type.h


## Overview

The **vibrator_type.h** file declares the APIs for starting or stopping vibration.

**Library**: libohvibrator.z.so

**System capability**: SystemCapability.Sensors.MiscDevice

**Since**: 11

**Related module**: [Vibrator](_xe9_xa9_xac_xe8_xbe_xbe.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [Vibrator_Attribute](_vibrator___attribute.md) | struct<br>Defines the vibrator attribute. | 
| [Vibrator_FileDescription](_vibrator___file_description.md) | struct<br>Defines the vibration file description. | 


### Types

| Name| Description| 
| -------- | -------- |
| [Vibrator_ErrorCode](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_errorcode) | typedef enum [Vibrator_ErrorCode](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_errorcode)<br>Defines an enum that enumerates the vibrator error codes. | 
| [Vibrator_Usage](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_usage) | typedef enum [Vibrator_Usage](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_usage)<br>Defines an enum that enumerates the vibration scenarios. | 
| [Vibrator_Attribute](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_attribute) | typedef struct [Vibrator_Attribute](_vibrator___attribute.md)<br>Defines the vibrator attribute. | 
| [Vibrator_FileDescription](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_filedescription) | typedef struct [Vibrator_FileDescription](_vibrator___file_description.md)<br>Defines the vibration file description. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [Vibrator_ErrorCode](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_errorcode) : int32_t { [PERMISSION_DENIED](_xe9_xa9_xac_xe8_xbe_xbe.md) = 201, [PARAMETER_ERROR](_xe9_xa9_xac_xe8_xbe_xbe.md) = 401, [UNSUPPORTED](_xe9_xa9_xac_xe8_xbe_xbe.md) = 801, **DEVICE_OPERATION_FAILED** = 14600101 } | Enumerates the vibrator error codes. | 
| [Vibrator_Usage](_xe9_xa9_xac_xe8_xbe_xbe.md#vibrator_usage) {<br>[USAGE_UNKNOWN](_xe9_xa9_xac_xe8_xbe_xbe.md) = 0, [USAGE_ALARM](_xe9_xa9_xac_xe8_xbe_xbe.md) = 1, [USAGE_RING](_xe9_xa9_xac_xe8_xbe_xbe.md) = 2, [USAGE_NOTIFICATION](_xe9_xa9_xac_xe8_xbe_xbe.md) = 3,<br>[USAGE_COMMUNICATION](_xe9_xa9_xac_xe8_xbe_xbe.md) = 4, [USAGE_TOUCH](_xe9_xa9_xac_xe8_xbe_xbe.md) = 5, [USAGE_MEDIA](_xe9_xa9_xac_xe8_xbe_xbe.md) = 6, [USAGE_PHYSICAL_FEEDBACK](_xe9_xa9_xac_xe8_xbe_xbe.md) = 7,<br>**USAGE_SIMULATE_REALITY** = 8, **USAGE_MAX** = 9<br>} | Enumerates the vibration scenarios. | 
