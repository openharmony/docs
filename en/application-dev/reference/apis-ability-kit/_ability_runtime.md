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
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) {<br>    ABILITY_RUNTIME_ERROR_CODE_NO_ERROR = 0,<br>    ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED = 201,<br>    ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID = 401,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED = 801,<br>    ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY = 16000001,<br>    ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE = 16000002,<br>    ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED = 16000008,<br>    ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE = 16000009,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST = 16000011,<br>    ABILITY_RUNTIME_ERROR_CODE_CONTROLLED = 16000012,<br>    ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED = 16000013,<br>    ABILITY_RUNTIME_ERROR_CODE_CROSS_APP = 16000018,<br>    ABILITY_RUNTIME_ERROR_CODE_INTERNAL = 16000050,<br>    ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY = 16000053,<br>} | Enumerates the error codes used by the ability framework.|
| [AbilityRuntime_AreaMode](#abilityruntime_areamode) {<br>    ABILITY_RUNTIME_AREA_MODE_EL1 = 0,<br>    ABILITY_RUNTIME_AREA_MODE_EL2 = 1,<br>    ABILITY_RUNTIME_AREA_MODE_EL3 = 2,<br>    ABILITY_RUNTIME_AREA_MODE_EL4 = 3,<br>    ABILITY_RUNTIME_AREA_MODE_EL5 = 4<br>} | Enumerates the data encryption levels.    |

### Functions

| Name| Description|
| -------- | -------- |
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCacheDir](#oh_abilityruntime_applicationcontextgetcachedir)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the application-level cache directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetAreaMode](#oh_abilityruntime_applicationcontextgetareamode)([AbilityRuntime_AreaMode](#abilityruntime_areamode)* areaMode) | Obtains the application-level data encryption level.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleName](#oh_abilityruntime_applicationcontextgetbundlename)(char* buffer, int32_t bufferSize, int32_t* writeLength) | Obtains the bundle name of the application.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetTempDir](#oh_abilityruntime_applicationcontextgettempdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level temporary file directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetFilesDir](#oh_abilityruntime_applicationcontextgetfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level common file directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDatabaseDir](#oh_abilityruntime_applicationcontextgetdatabasedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level database file directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetPreferencesDir](#oh_abilityruntime_applicationcontextgetpreferencesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level preferences file directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetBundleCodeDir](#oh_abilityruntime_applicationcontextgetbundlecodedir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level installation file directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir](#oh_abilityruntime_applicationcontextgetdistributedfilesdir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level distributed file directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_ApplicationContextGetCloudFileDir](#oh_abilityruntime_applicationcontextgetcloudfiledir)(char* buffer, const int32_t bufferSize, int32_t* writeLength) | Obtains the application-level cloud file directory.|
| [AbilityRuntime_ErrorCode](#abilityruntime_errorcode) [OH_AbilityRuntime_StartSelfUIAbility](#oh_abilityruntime_startselfuiability)([AbilityBase_Want](_ability_base.md#abilitybase_want) *want) | Starts the UIAbility of the current application.|

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
| ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID | Invalid parameter.    |
| ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST  | The context does not exist.|
| ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED | Permission verification failed.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED | The device type is not supported.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY | The specified ability name does not exist.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE | The ability type is incorrect.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED | The crowdtesting application expires.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE | An ability cannot be started or stopped in Wukong mode.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CONTROLLED | The application is under control.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED | The application is under control by EDM.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_CROSS_APP | Redirection to third-party applications is not allowed in API versions later than 11.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_INTERNAL | Internal error.<br>**Since**: 15|
| ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY | The application is not on top.<br>**Since**: 15|

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

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

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

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

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

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetTempDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level temporary file directory.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level common file directory.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetDatabaseDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength);
```

**Description**

Obtains the application-level database file directory.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetPreferencesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level preferences file directory.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetBundleCodeDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level installation file directory.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level distributed file directory.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_ApplicationContextGetCloudFileDir

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level cloud file directory.

**Since**: 16

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| buffer      | Pointer to the buffer. The cache directory string is written to this area.                          |
| bufferSize  | Buffer size.                                                |
| writeLength | Pointer to the length of the string written to the buffer when **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** is returned.|

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the passed-in value of **buffer** or **writeLength** is null or the buffer size is less than the size of the string to be written.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST** if the context of the current environment does not exist. For example, the application-level context does not exist in the [child process](c-apis-ability-childprocess.md) created by the application.

### OH_AbilityRuntime_StartSelfUIAbility

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want)
```

**Description**

Starts the UIAbility of the current application.

> **NOTE**
>
> This function is valid only for 2-in-1 devices.

**Required permissions**: ohos.permission.NDK_START_SELF_UI_ABILITY

**Since**: 15

**Parameters**

| Name       | Description                                                        |
| ----------- | ------------------------------------------------------------ |
| want      | Pointer to the Want information required for starting the UIAbility.                          |

**Returns**

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR** if the operation is successful.

Returns **ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED** if permission verification failed.

Returns **ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID** if the Want information is empty, or if the bundleName or abilityName in the Want information is empty.

Returns **ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED** if the device type is not supported.

Returns **ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY** if the specified ability name does not exist.

Returns **ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE** if the ability type is incorrect.

Returns **ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED** if the crowdtesting application expires.

Returns **ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE** if the ability is started or stopped in Wukong mode.

Returns **ABILITY_RUNTIME_ERROR_CODE_CONTROLLED** if the application is under control.

Returns **ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED** if the application is under control by EDM.

Returns **ABILITY_RUNTIME_ERROR_CODE_CROSS_APP** for an attempt to redirection to third-party applications in API versions later than 11.

Returns **ABILITY_RUNTIME_ERROR_CODE_INTERNAL** if an internal error occurs.

Returns **ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY** if the application is not a top one.

**Example**

```cpp
#include <AbilityKit/ability_base/want.h>
#include <AbilityKit/ability_runtime/application_context.h>

void startSelfUIAbilityTest()
{
    AbilityBase_Element element;
    element.abilityName = const_cast<char*>("EntryAbility");
    element.bundleName = const_cast<char*>("com.exampl.myapplication");
    element.moduleName = const_cast<char*>("entry");
    AbilityBase_Want* want = OH_AbilityBase_CreateWant(element);

    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_StartSelfUIAbility(want);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
        return;
    }
    // Destroy the Want to prevent memory leakage.
    OH_AbilityBase_DestroyWant(want);
}
```
