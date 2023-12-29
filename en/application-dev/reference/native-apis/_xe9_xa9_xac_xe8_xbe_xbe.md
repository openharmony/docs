# Vibrator


## Overview

The **Vibrator** module provides APIs for vibrator services to access the vibrator driver.

**Since**: 11


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [vibrator_type.h](vibrator__type_8h.md) | Declares the APIs for starting or stopping vibration. |


### Structs

| Name| Description|
| -------- | -------- |
| [Vibrator_Attribute](_vibrator___attribute.md) | struct<br>Defines the vibrator attribute. |
| [Vibrator_FileDescription](_vibrator___file_description.md) | struct<br>Defines the vibration file description. |


### Types

| Name| Description|
| -------- | -------- |
| [Vibrator_ErrorCode](#vibrator_errorcode) | typedef enum [Vibrator_ErrorCode](#vibrator_errorcode)<br>Defines an enum that enumerates the vibrator error codes. |
| [Vibrator_Usage](#vibrator_usage) | typedef enum [Vibrator_Usage](#vibrator_usage)<br>Defines an enum that enumerates the vibration scenarios. |
| [Vibrator_Attribute](#vibrator_attribute) | typedef struct [Vibrator_Attribute](_vibrator___attribute.md)<br>Defines the vibrator attribute. |
| [Vibrator_FileDescription](#vibrator_filedescription) | typedef struct [Vibrator_FileDescription](_vibrator___file_description.md)<br>Defines the vibration file description. |


### Enums

| Name| Description|
| -------- | -------- |
| [Vibrator_ErrorCode](#vibrator_errorcode) : int32_t { PERMISSION_DENIED = 201, PARAMETER_ERROR = 401, UNSUPPORTED = 801, **DEVICE_OPERATION_FAILED** = 14600101 } | Enumerates the vibrator error codes. |
| [Vibrator_Usage](#vibrator_usage) {<br>USAGE_UNKNOWN = 0, USAGE_ALARM = 1, USAGE_RING = 2, USAGE_NOTIFICATION = 3,<br>USAGE_COMMUNICATION = 4, USAGE_TOUCH = 5, USAGE_MEDIA = 6, USAGE_PHYSICAL_FEEDBACK = 7,<br>**USAGE_SIMULATE_REALITY** = 8, **USAGE_MAX** = 9<br>} | Enumerates the vibration scenarios. |


## Type Description


### Vibrator_Attribute

```
typedef struct Vibrator_Attribute Vibrator_Attribute
```
**Description**

Defines the vibrator attribute.

**Since**: 11


### Vibrator_ErrorCode

```
typedef enum Vibrator_ErrorCode Vibrator_ErrorCode
```
**Description**

Defines an enum that enumerates the vibrator error codes.

**Since**: 11


### Vibrator_FileDescription

```
typedef struct Vibrator_FileDescription Vibrator_FileDescription
```
**Description**

Defines the vibration file description.

**Since**: 11


### Vibrator_Usage

```
typedef enum Vibrator_Usage Vibrator_Usage
```
**Description**

Defines an enum that enumerates the vibration scenarios.

**Since**: 11


## Enum Description


### Vibrator_ErrorCode

```
enum Vibrator_ErrorCode : int32_t
```
**Description**

Enumerates the vibrator error codes.

**Since**: 11

| Value| Description|
| -------- | -------- |
| PERMISSION_DENIED  | Permission verification failed. |
| PARAMETER_ERROR  | Parameter check failed. For example, a mandatory parameter is not passed in, or the parameter type passed in is incorrect. |
| UNSUPPORTED  | The device does not support this API. Generally, this enumerated value is used for a device that supports the corresponding system capability but only parts of APIs. |


### Vibrator_Usage

```
enum Vibrator_Usage
```
**Description**

Enumerates the vibration scenarios.

**Since**: 11

| Value| Description|
| -------- | -------- |
| USAGE_UNKNOWN  | Unknown scenario. |
| USAGE_ALARM  | Vibration for alarms. |
| USAGE_RING  | Vibration for incoming calls. |
| USAGE_NOTIFICATION  | Vibration for notifications. |
| USAGE_COMMUNICATION  | Vibration for communication. |
| USAGE_TOUCH  | Touch vibration scenario. |
| USAGE_MEDIA  | Multimedia vibration scenario. |
| USAGE_PHYSICAL_FEEDBACK  | Physical feedback vibration scenario. |
