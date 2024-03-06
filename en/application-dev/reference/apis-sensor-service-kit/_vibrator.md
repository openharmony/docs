# Vibrator


## Overview

The **Vibrator** module provides APIs for vibrator services to access the vibrator driver.

**Since**: 11


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [vibrator_type.h](vibrator_type_8h.md) | Declares the APIs for starting or stopping vibration. |


### Structs

| Name| Description|
| -------- | -------- |
| [Vibrator_Attribute](_vibrator_attribute.md) | Describes the vibrator attribute. |
| [Vibrator_FileDescription](_vibrator_file_description.md) | Describes the vibration file description. |


### Types

| Name| Description|
| -------- | -------- |
| [Vibrator_ErrorCode](#vibrator_errorcode) | Defines an enum for vibrator error codes. |
| [Vibrator_Usage](#vibrator_usage) | Defines an enum for vibration scenarios.      |
| [Vibrator_Attribute](#vibrator_attribute) | Defines a struct for the vibrator attribute. |
| [Vibrator_FileDescription](#vibrator_filedescription) | Defines a struct for the vibration file description. |


### Enums

| Name| Description|
| -------- | -------- |
| [Vibrator_ErrorCode](#vibrator_errorcode) : int32_t { <br>PERMISSION_DENIED = 201, <br>PARAMETER_ERROR = 401, <br>UNSUPPORTED = 801, <br>DEVICE_OPERATION_FAILED = 14600101<br>} | Enumerates the vibrator error codes. |
| [Vibrator_Usage](#vibrator_usage) {<br>USAGE_UNKNOWN = 0, <br>USAGE_ALARM = 1, <br>USAGE_RING = 2,<br> USAGE_NOTIFICATION = 3,<br>USAGE_COMMUNICATION = 4, <br>USAGE_TOUCH = 5, <br>USAGE_MEDIA = 6, <br>USAGE_PHYSICAL_FEEDBACK = 7,<br>USAGE_SIMULATE_REALITY = 8, <br>USAGE_MAX = 9<br>} | Enumerates the vibration scenarios. |


## Type Description


### Vibrator_Attribute

```
typedef struct Vibrator_Attribute Vibrator_Attribute
```
**Description**

Defines a struct for the vibrator attribute.

**Since**: 11


### Vibrator_ErrorCode

```
typedef enum Vibrator_ErrorCode Vibrator_ErrorCode
```
**Description**

Defines an enum for vibrator error codes.

**Since**: 11


### Vibrator_FileDescription

```
typedef struct Vibrator_FileDescription Vibrator_FileDescription
```
**Description**

Defines a struct for the vibration file description.

**Since**: 11


### Vibrator_Usage

```
typedef enum Vibrator_Usage Vibrator_Usage
```
**Description**

Defines an enum for vibration scenarios.

**Since**: 11


## Enum Description


### Vibrator_ErrorCode

```
enum Vibrator_ErrorCode:int32_t
```
**Description**

Enumerates the vibrator error codes.

**Since**: 11

| Value| Description|
| -------- | -------- |
| PERMISSION_DENIED  | Permission verification failed.|
| PARAMETER_ERROR  | Parameter check failed. For example, a mandatory parameter is not passed in, or the parameter type passed in is incorrect.|
| UNSUPPORTED  | The device does not support this API. Generally, this enumerated value is used for a device that supports the corresponding system capability but only parts of APIs.|
| DEVICE_OPERATION_FAILED | Device operation failed.|


### Vibrator_Usage

```
enum Vibrator_Usage
```
**Description**

Enumerates the vibration scenarios.

**Since**: 11

| Value| Description|
| -------- | -------- |
| USAGE_UNKNOWN  | Unknown scenario.|
| USAGE_ALARM  | Vibration for alarms.|
| USAGE_RING  | Vibration for incoming calls.|
| USAGE_NOTIFICATION  | Vibration for notifications.|
| USAGE_COMMUNICATION  | Vibration for communication.|
| USAGE_TOUCH  | Touch vibration scenario.|
| USAGE_MEDIA  | Multimedia vibration scenario.|
| USAGE_PHYSICAL_FEEDBACK  | Physical feedback vibration scenario.|
| USAGE_SIMULATE_REALITY | Simulated reality vibration scenario.|
