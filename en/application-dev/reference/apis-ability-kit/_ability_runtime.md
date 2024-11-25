# AbilityRuntime


## Overview

The AbilityRuntime module provides capabilities related to the ability framework.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [ability_runtime_common.h](ability__runtime__common_8h.md) | Declares the error codes of the ability framework.<br>**File to include**: <AbilityKit/ability_runtime/ability_runtime_common.h><br>**Library**: libability_runtime.so|
| [application_context.h](application__context_8h.md) | Declares the context capability at the application level.<br>**File to include**: <AbilityKit/ability_runtime/application_context.h><br>**Library**: libability_runtime.so|
| [context_constant.h](context__constant_8h.md) | Declares context-related enums.<br>**File to include**: <AbilityKit/ability_runtime/context_constant.h><br>**Library**: libability_runtime.so|

### Enums

| Name                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br>} | Enumerates the error codes used by the ability framework.|
| [AbilityRuntime_AreaMode](#abilityruntime_areamode) {<br>    ABILITY_RUNTIME_AREA_MODE_EL1 = 0,<br>    ABILITY_RUNTIME_AREA_MODE_EL2 = 1,<br>    ABILITY_RUNTIME_AREA_MODE_EL3 = 2,<br>    ABILITY_RUNTIME_AREA_MODE_EL4 = 3,<br>    ABILITY_RUNTIME_AREA_MODE_EL5 = 4<br>} | Enumerates the data encryption levels.    |

### Functions

| Name| Description|
| -------- | -------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCacheDir](#oh_abilityruntime_applicationcontextgetcachedir)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the application-level cache directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetAreaMode](#oh_abilityruntime_applicationcontextgetareamode)([AbilityRuntime_AreaMode](#abilityruntime_areamode)* areaMode) | Obtains the application-level data encryption level.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleName](#oh_abilityruntime_applicationcontextgetbundlename)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the bundle name of the application.|

## Enum Description

### AbilityRuntime_ErrorCode

```
enum AbilityRuntime_ErrorCode
```

**Description**

Enumerates the error codes used by the ability framework.

**Since**: 13

| Value                                       | Description          |
| --------------------------------------------- | -------------- |
| ABILITY_RUNTIME_ERROR_CODE_NO_ERROR           | Operation successful.    |
| ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID ARAM | Invalid parameter.    |
| ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  | The context does not exist.|

### AbilityRuntime_AreaMode

```
enum AbilityRuntime_AreaMode
```

**Description**

Enumerates the data encryption levels.

**Since**: 13

| Value                       | Description                                                        |
| ----------------------------- | ------------------------------------------------------------ |
| ABILITY_RUNTIME_AREA_MODE_EL1 | For private files, such as alarms and wallpapers, the application can place them in a directory with the device-level encryption (EL1) to ensure that they can be accessed before the user enters the password.|
| ABILITY_RUNTIME_AREA_MODE_EL2 | For sensitive files, such as personal privacy data, the application can place them in a directory with the user-level encryption (EL2).|
| ABILITY_RUNTIME_AREA_MODE_EL3 | For step recording, file download, or music playback that needs to read, write, and create files when the screen is locked, the application can place these files in EL3.|
| ABILITY_RUNTIME_AREA_MODE_EL4 | For files that are related to user security information and do not need to be read, written, or created when the screen is locked, the application can place them in EL4.|
| ABILITY_RUNTIME_AREA_MODE_EL5 | By default, sensitive user privacy files cannot be read or written on the lock screen. If such files need to be read or written on the lock screen, you can call [Access](js-apis-screenLockFileManager.md#screenlockfilemanageracquireaccess) to apply for reading or writing files before the screen is locked or create new files that can be read and written after the screen is locked. It is more appropriate to place these files in EL5.|

## Function Description


### OH_AbilityRuntime_ApplicationContextGetCacheDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)
```
**Description**

Obtains the application-level cache directory.

**Since**: 13

**Parameters**

| Name| Description|
| -------- | -------- |
| buffer | Pointer to the buffer. The cache directory string is written to this area.|
| bufferSize | Buffer size.|
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process] (c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetAreaMode

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)
```

**Description**

Obtains the application-level data encryption level.

**Since**: 13

**Parameters**

| Name    | Description                    |
| -------- | ------------------------ |
| areaMode | Pointer to the data encryption level.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if **areaMode** is a null pointer.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process] (c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetBundleName

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the bundle name of the application.

**Since**: 13

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The bundle name string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process] (c-apis-ability-childprocess.md) created by the application.
