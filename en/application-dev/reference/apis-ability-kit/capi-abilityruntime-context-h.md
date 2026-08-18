# context.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yangzhongkai-->
<!--Designer: @yangzhongkai-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=650803b1fa576dbf2144b7c991efd4398d52b615 translatedAt=2026-08-13T13:15:09.840Z pushedAt=2026-08-17T10:49:52.373Z -->

## Overview

Provides the context data structure [AbilityRuntime_Context](capi-abilityruntime-abilityruntime-context.md) and related APIs for obtaining information such as the app file path, data encryption level, and process name of the current context.

**Reference file:** <AbilityKit/ability_runtime/context.h>

**Library:** libability_runtime.so

**System capability:** SystemCapability.Ability.AbilityRuntime.Core

**Since**: 24

**Related module:** [AbilityRuntime](capi-abilityruntime.md)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [AbilityRuntime_Context](capi-abilityruntime-abilityruntime-context.md) | - | Defines the AbilityRuntime_Context struct type. |
| [AbilityRuntime_Context*](capi-abilityruntime-abilityruntime-context8h.md) | AbilityRuntime_ContextHandle | Defines a pointer to the AbilityRuntime_Context object. |

### Functions

| Name | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetCacheDir(AbilityRuntime_ContextHandle context, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getcachedir) | Obtains the cache directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetTempDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_gettempdir) | Obtains the temporary file directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetFilesDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getfilesdir) | Obtains the files directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetDatabaseDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getdatabasedir) | Obtains the database file directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetPreferencesDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getpreferencesdir) | Obtains the preferences file directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetBundleCodeDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getbundlecodedir) | Obtains the bundle code directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetDistributedFilesDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getdistributedfilesdir) | Obtains the distributed files directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetResourceDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getresourcedir) | Obtains the resource directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetCloudFileDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getcloudfiledir) | Obtains the cloud file directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetAreaMode(AbilityRuntime_ContextHandle context, AbilityRuntime_AreaMode* areaMode)](#oh_abilityruntime_context_getareamode) | Obtains the data encryption level of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_SetAreaMode(AbilityRuntime_ContextHandle context, AbilityRuntime_AreaMode areaMode)](#oh_abilityruntime_context_setareamode) | Sets the data encryption level of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetLogFileDir(AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getlogfiledir) | Obtains the log file directory of the context. |
| [AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetProcessName(AbilityRuntime_ContextHandle context, char* buffer, int32_t bufferSize, int32_t* writeLength)](#oh_abilityruntime_context_getprocessname) | Obtains the process name of the context. |

## Function Description

### OH_AbilityRuntime_Context_GetCacheDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetCacheDir(
    AbilityRuntime_ContextHandle context, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the cache directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the cache directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the cache directory of the context. |
| int32_t bufferSize | Buffer Size, Unit: Byte. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer, Unit: Byte. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return Execution Result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation Successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetCacheDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t cacheDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetCacheDir(context, buffer, 1024, &cacheDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business.
}
```

### OH_AbilityRuntime_Context_GetTempDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetTempDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the temporary file directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the temp file directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the temp file directory of the context. |
| const int32_t bufferSize | Buffer size. Unit: Byte. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer. Unit: Byte. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetTempDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t tempDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetTempDir(context, buffer, 1024, &tempDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business.
}
```

### OH_AbilityRuntime_Context_GetFilesDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetFilesDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the general file directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the general file directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the general file directory of the context. |
| const int32_t bufferSize | Buffer size. Unit: Byte. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer. Unit: Byte. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetFilesDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t filesDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetFilesDir(context, buffer, 1024, &filesDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business logic.
}
```

### OH_AbilityRuntime_Context_GetDatabaseDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetDatabaseDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Gets the database file directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the database file directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the database file directory of the context. |
| const int32_t bufferSize | Buffer size. Unit: Byte. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer. Unit: Byte. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetDatabaseDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t databaseDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetDatabaseDir(context, buffer, 1024, &databaseDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business logic.
}
```

### OH_AbilityRuntime_Context_GetPreferencesDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetPreferencesDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the preferences file directory of the context.

**Since**: 24

**Parameters**

| Parameter Item | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the preferences file directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the preferences file directory of the context. |
| const int32_t bufferSize | Buffer size, in bytes. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer, in bytes. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return Execution Result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation Successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetPreferencesDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t preferencesDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetPreferencesDir(context, buffer, 1024, &preferencesDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business.
}
```

### OH_AbilityRuntime_Context_GetBundleCodeDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetBundleCodeDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Gets the installation file directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the installation file directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the installation file directory of the context. |
| const int32_t bufferSize | Buffer size, in bytes. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer, in bytes. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetBundleCodeDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t bundleCodeDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetBundleCodeDir(context, buffer, 1024, &bundleCodeDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Handle normal business logic.
}
```

### OH_AbilityRuntime_Context_GetDistributedFilesDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetDistributedFilesDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the distributed file directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the distributed files directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the distributed files directory of the context. |
| const int32_t bufferSize | Buffer size, in bytes. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer, in bytes. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return Execution Result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation Successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - Parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - Context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetDistributedFilesDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t distributedFilesDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetDistributedFilesDir(context, buffer, 1024, &distributedFilesDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business.
}
```

### OH_AbilityRuntime_Context_GetResourceDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetResourceDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Gets the resource directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the resource directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the resource directory of the context. |
| const int32_t bufferSize | Buffer size. Unit: Byte. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer. Unit: Byte. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetResourceDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t resourceDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetResourceDir(context, buffer, 1024, &resourceDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business logic.
}
```

### OH_AbilityRuntime_Context_GetCloudFileDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetCloudFileDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the cloud file directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the cloud file directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the cloud file directory of the context. |
| const int32_t bufferSize | Buffer size. Unit: Byte. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer. Unit: Byte. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetCloudFileDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t cloudFileDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetCloudFileDir(context, buffer, 1024, &cloudFileDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business logic.
}
```

### OH_AbilityRuntime_Context_GetAreaMode()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetAreaMode(
    AbilityRuntime_ContextHandle context, AbilityRuntime_AreaMode* areaMode)
```

**Description**

Gets the data encryption level of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the data encryption level is to be obtained. |
| [AbilityRuntime_AreaMode](capi-context-constant-h.md#abilityruntime_areamode)* areaMode | Pointer to the data encryption level received. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Result code.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter areaMode is null.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetAreaMode(AbilityRuntime_ContextHandle context)
{
    AbilityRuntime_AreaMode areaMode;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetAreaMode(context, &areaMode);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Handle normal business.
}
```

### OH_AbilityRuntime_Context_SetAreaMode()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_SetAreaMode(
    AbilityRuntime_ContextHandle context, AbilityRuntime_AreaMode areaMode)
```

**Description**

Sets the data encryption level of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the data encryption level is to be set. |
| [AbilityRuntime_AreaMode](capi-context-constant-h.md#abilityruntime_areamode) areaMode | Data encryption level. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter context is null.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testSetAreaMode(AbilityRuntime_ContextHandle context)
{
    AbilityRuntime_AreaMode areaMode = ABILITY_RUNTIME_AREA_MODE_EL1;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_SetAreaMode(context, areaMode);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business logic.
}
```

### OH_AbilityRuntime_Context_GetLogFileDir()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetLogFileDir(
    AbilityRuntime_ContextHandle context, char* buffer, const int32_t bufferSize, int32_t* writeLength)
```

**Description**

Obtains the log file directory of the context.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the log file directory is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the log file directory of the context. |
| const int32_t bufferSize | Buffer size, in bytes. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer, in bytes. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return Execution Result.<br>Returns ABILITY_RUNTIME_ERROR_CODE_NO_ERROR if the operation is successful.<br>Returns ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID if buffer or writeLength is null, context is null, or the buffer size is smaller than the size to be written.<br>Returns ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST if the context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Obtain a context object.
void testGetLogFileDir(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t logFileDirSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetLogFileDir(context, buffer, 1024, &logFileDirSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other business processing.
    }
    // Process normal business.
}
```

### OH_AbilityRuntime_Context_GetProcessName()

```c
AbilityRuntime_ErrorCode OH_AbilityRuntime_Context_GetProcessName(
    AbilityRuntime_ContextHandle context, char* buffer, int32_t bufferSize, int32_t* writeLength)
```

**Description**

Gets the process name where the context is located.

**Since**: 24

**Parameters**

| Name | Description |
| -- | -- |
| [AbilityRuntime_ContextHandle](capi-abilityruntime-abilityruntime-context8h.md) context | Context for which the process name is to be obtained. |
| char* buffer | Pointer to the buffer used to receive the process name. |
| int32_t bufferSize | Buffer size. Unit: Byte. |
| int32_t* writeLength | When [ABILITY_RUNTIME_ERROR_CODE_NO_ERROR](capi-ability-runtime-common-h.md#abilityruntime_errorcode) is returned, indicates the length of the string actually written to the buffer. Unit: Byte. |

**Returns**

| Type | Description |
| -- | -- |
| [AbilityRuntime_ErrorCode](capi-ability-runtime-common-h.md#abilityruntime_errorcode) | Return execution result.<br>ABILITY_RUNTIME_ERROR_CODE_NO_ERROR - Operation successful.<br>ABILITY_RUNTIME_ERROR_CODE_PARAM_INVALID - The input parameter buffer or writeLength is null, or context is null, or the buffer size is smaller than the size to be written.<br>ABILITY_RUNTIME_ERROR_CODE_CONTEXT_NOT_EXIST - The context does not exist. |

**Example:**

```c
#include <AbilityKit/ability_runtime/context.h>

// Receive a context object.
void testGetProcessName(AbilityRuntime_ContextHandle context)
{
    char buffer[1024] = {0};
    int32_t processNameSize = 0;
    AbilityRuntime_ErrorCode errorCode = ABILITY_RUNTIME_ERROR_CODE_NO_ERROR;
    errorCode = OH_AbilityRuntime_Context_GetProcessName(context, buffer, 1024, &processNameSize);
    if (errorCode != ABILITY_RUNTIME_ERROR_CODE_NO_ERROR) {
        // Record the error log and perform other service processing.
    }
    // Process normal business logic.
}
```