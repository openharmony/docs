# application_context.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## Overview

The file declares the APIs related to the application-level context.

**File to include**: <AbilityKit/ability_runtime/application_context.h>

**Library**: libability_runtime.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 13

**Related module**: [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetcachedir) | Obtains the application-level cache directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)](#oh_abilityruntime_applicationcontextgetareamode) | Obtains the application-level file data encryption level of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetbundlename) | Obtains the bundle name of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgettempdir) | Obtains the application-level temporary file directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetfilesdir) | Obtains the application-level common file directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetdatabasedir) | Obtains the application-level database file directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetpreferencesdir) | Obtains the application-level preferences file directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetbundlecodedir) | Obtains the application-level installation file directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetdistributedfilesdir) | Obtains the application-level distributed file directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetcloudfiledir) | Obtains the application-level cloud file directory of the application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetResourceDir(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_applicationcontextgetresourcedir) | Obtains the application-level resource directory of the application.    |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbility(AbilityBase_Want *want)](#oh_abilityruntime_startselfuiability) | Starts the UIAbility of the current application.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(AbilityBase_Want *want,AbilityRuntime_StartOptions *options)](#oh_abilityruntime_startselfuiabilitywithstartoptions) | Starts the UIAbility of the current application using **StartOptions**.|
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetVersionCode(int64_t* versionCode)](#oh_abilityruntime_applicationcontextgetversioncode) | Obtains the application version code.|

## Function Description

### OH_AbilityRuntime_ApplicationContextGetCacheDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCacheDir(char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level cache directory of the application.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the application-level cache directory of the application.|
| int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetAreaMode()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetAreaMode(AbilityRuntime_AreaMode* areaMode)
```

**Description**

Obtains the application-level file data encryption level of the application.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityRuntime_AreaMode](capi-context-constant-h.md#abilityruntime_areamode)* areaMode | Pointer to the encryption level of the received data.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetBundleName()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleName(char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the bundle name of the application.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetTempDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetTempDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level temporary file directory of the application.

**Since**: 16

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| const int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetFilesDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level common file directory of the application.

**Since**: 16

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| const int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetDatabaseDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDatabaseDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level database file directory of the application.

**Since**: 16

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| const int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetPreferencesDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetPreferencesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level preferences file directory of the application.

**Since**: 16

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| const int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetBundleCodeDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetBundleCodeDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level installation file directory of the application.

**Since**: 16

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| const int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetDistributedFilesDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level distributed file directory of the application.

**Since**: 16

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| const int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetCloudFileDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetCloudFileDir(char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level cloud file directory of the application.

**Since**: 16

**Parameters**

| Name| Description|
| -- | -- |
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| const int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_ApplicationContextGetResourceDir()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetResourceDir(const char* moduleName, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the application-level resource directory of the application.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| char* moduleName | Pointer to the module name.|
| char* buffer | Pointer to the buffer, which is used to receive the bundle name.|
| int32_t bufferSize | Buffer size, in bytes.|
| int32_t* writeLength | Pointer to the length of the string written to the buffer when [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: The passed-in value of **buffer** or **writeLength** is null, or the buffer size is less than the size of the string to be written.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.|

### OH_AbilityRuntime_StartSelfUIAbility()

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

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md) *want | Pointer to the Want information required for starting the UIAbility.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The API call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED**: Permission verification for the caller fails.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: Parameter verification for the caller fails.<br>**ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED**: The device type is not supported.<br>**ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY**: The specified ability name does not exist.<br>**ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE**: The ability type is incorrect.<br>**ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED**: The crowdtesting application expires.<br>**ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE**: The ability is started or stopped in Wukong mode.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTROLLED**: The application is under control.<br>**ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED**: The application is under control by EDM.<br>**ABILITY_RUNTIME_ERROR_CODE_CROSS_APP**: Redirecting to third-party applications is not allowed in API versions later than 11.<br>**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error occurs.<br>**ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY**: The application is not a top one.<br>**ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED** (available since API version 17): The number of instances has reached the upper limit.<br>**ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED** (available since API version 17): Setting **APP_INSTANCE_KEY** is not supported.<br>For details, see **AbilityRuntime_ErrorCode**.|

**Example**

```cpp
#include <AbilityKit/ability_base/want.h>
#include <AbilityKit/ability_runtime/application_context.h>

void startSelfUIAbilityTest()
{
    AbilityBase_Element element;
    element.abilityName = const_cast<char*>("EntryAbility");
    element.bundleName = const_cast<char*>("com.example.myapplication");
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

### OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(AbilityBase_Want *want,AbilityRuntime_StartOptions *options)
```

**Description**

Starts the UIAbility of the current application using **StartOptions**.

> **NOTE**
>
> This function is valid only for 2-in-1 devices.

**Required permissions**: ohos.permission.NDK_START_SELF_UI_ABILITY

**Since**: 17

**Parameters**

| Name| Description|
| -- | -- |
| [AbilityBase_Want](capi-abilitybase-want.md) *want | Pointer to the Want information required for starting the UIAbility.|
| [AbilityRuntime_StartOptions](capi-abilityruntime-startoptions.md) *options | Pointer to **StartOptions** required for starting the UIAbility. If the value of [startVisibility](capi-context-constant-h.md#abilityruntime_startvisibility) is not null, ensure that the current application has been added to the status bar. Otherwise, the [ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED](capi-ability-runtime-common-h.md#abilityruntime_errorcode) error code is returned.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | **ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The API call is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PERMISSION_DENIED**: Permission verification for the caller fails.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: Parameter verification for the caller fails.<br>**ABILITY_RUNTIME_ERROR_CODE_NOT_SUPPORTED**: The device type is not supported.<br>**ABILITY_RUNTIME_ERROR_CODE_NO_SUCH_ABILITY**: The specified ability name does not exist.<br>**ABILITY_RUNTIME_ERROR_CODE_INCORRECT_ABILITY_TYPE**: The ability type is incorrect.<br>**ABILITY_RUNTIME_ERROR_CODE_CROWDTEST_EXPIRED**: The crowdtesting application expires.<br>**ABILITY_RUNTIME_ERROR_CODE_WUKONG_MODE**: The ability is started or stopped in Wukong mode.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTROLLED**: The application is under control.<br>**ABILITY_RUNTIME_ERROR_CODE_EDM_CONTROLLED**: The application is under control by EDM.<br>**ABILITY_RUNTIME_ERROR_CODE_CROSS_APP**: Redirecting to third-party applications is not allowed in API versions later than 11.<br>**ABILITY_RUNTIME_ERROR_CODE_INTERNAL**: An internal error occurs.<br>**ABILITY_RUNTIME_ERROR_CODE_NOT_TOP_ABILITY**: The application is not a top one.<br>**ABILITY_RUNTIME_ERROR_VISIBILITY_SETTING_DISABLED**: Setting the window visibility during startup is not allowed.<br>**ABILITY_RUNTIME_ERROR_CODE_MULTI_APP_NOT_SUPPORTED**: The application does not support clone or multi-instance mode.<br>**ABILITY_RUNTIME_ERROR_CODE_INVALID_APP_INSTANCE_KEY**: The multi-instance key is invalid.<br> **ABILITY_RUNTIME_ERROR_CODE_UPPER_LIMIT_REACHED**: The number of instances has reached the upper limit.<br>**ABILITY_RUNTIME_ERROR_MULTI_INSTANCE_NOT_SUPPORTED**: The application does not support multi-instance mode.<br>**ABILITY_RUNTIME_ERROR_CODE_APP_INSTANCE_KEY_NOT_SUPPORTED**: Setting **APP_INSTANCE_KEY** is not supported.<br>For details, see **AbilityRuntime_ErrorCode**.|

**Example**

```cpp
#include <AbilityKit/ability_base/want.h>
#include <AbilityKit/ability_runtime/application_context.h>

void demo()
{
    AbilityBase_Element element;
    element.abilityName = const_cast<char*>("EntryAbility");
    element.bundleName = const_cast<char*>("com.example.myapplication");
    element.moduleName = const_cast<char*>("entry");
    AbilityBase_Want* want = OH_AbilityBase_CreateWant(element);
    if (want == nullptr) {
        // Record error logs and other service processing.
        return;
    }

    AbilityRuntime_StartOptions* options = OH_AbilityRuntime_CreateStartOptions();
    if (options == nullptr) {
        // Record error logs and other service processing.

        // Destroy the Want to prevent memory leakage.
        OH_AbilityBase_DestroyWant(want);
        return;
    }
    AbilityRuntime_ErrorCode err = OH_AbilityRuntime_StartSelfUIAbilityWithStartOptions(want, options);
    if (err != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record error logs and other service processing.
    }
    // Destroy the Want to prevent memory leakage.
    OH_AbilityBase_DestroyWant(want);

    // Destroy options to prevent memory leakage.
    OH_AbilityRuntime_DestroyStartOptions(&options);
}
```

### OH_AbilityRuntime_ApplicationContextGetVersionCode()

```
AbilityRuntime_ErrorCode OH_AbilityRuntime_ApplicationContextGetVersionCode(int64_t* versionCode)
```

**Description**

Obtains the application version code.

**Since**: 21

**Parameters**

| Name| Description|
| -- | -- |
| int64_t* [versionCode](js-apis-bundleManager-bundleInfo.md#bundleinfo) | Pointer to the bundle's version code, which corresponds to the **versionCode** field in **bundleInfo**.|

**Returns**

| Type| Description|
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | One of the following execution results:<br>**ABILITY_RUNTIME_ERROR_CODE_NO_ERROR**: The operation is successful.<br>**ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID**: **versionCode** is null.<br>**ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST**: The application context does not exist. For example, the application-level context does not exist in the [child process](capi-childprocess.md) created by the application.<br>**ABILITY_RUNTIME_ERROR_CODE_GET_APPLICATION_INFO_FAILED**: Failed to obtain the application information.|
