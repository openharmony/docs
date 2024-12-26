# ChildProcess


## Overview

The ChildProcess module provides APIs to manage child processes. You can call the APIs to create a native child process and establish an IPC channel between the parent and child processes to implement multi-process application development.

The created child process does not support the UI or the calling of context-related APIs. A maximum of 512 child processes can be started through this module and [childProcessManager](js-apis-app-ability-childProcessManager.md) (non-SELF_FORK mode).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 12


## Summary


### Files

| Name                                                    | Description                                                                                                    |
| ------------------------------------------------------ | ------------------------------------------------------------------------------------------------------ |
| [native_child_process.h](native__child__process_8h.md) | Declares the APIs used to create a native child process and establish an IPC channel between the parent and child processes.<br>File to include: <AbilityKit/native_child_process.h><br>Library: libchild_process.so<br>|

### Types

| Name                                                                                                                                              | Description               |
| ------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------- |
| typedef enum Ability_NativeChildProcess_ErrCode [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)                        | Defines an enum for the error codes used by the native child process module.|
| typedef void(\* [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)) (int errCode, OHIPCRemoteProxy \*remoteProxy) | Defines a callback function for notifying the child process startup result.|
| typedef struct [NativeChildProcess_Fd](#nativechildprocess_fdlist) | Defines a struct for the file descriptor of a child process.|
| typedef struct [NativeChildProcess_FdList](#nativechildprocess_fdlist) | Defines a struct for the linked list of file descriptors of a child process.|
| typedef struct [NativeChildProcess_Args](#nativechildprocess_args) | Defines a struct for the arguments used for starting a child process.|


### Enums

| Name                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              | Description               |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) {<br>    NCP_NO_ERROR = 0,<br>    NCP_ERR_INVALID_PARAM = 401,<br>    NCP_ERR_NOT_SUPPORTED = 801,<br>    NCP_ERR_INTERNAL = 16000050,<br>    NCP_ERR_BUSY = 16010001,<br>    NCP_ERR_TIMEOUT = 16010002,<br>    NCP_ERR_SERVICE_ERROR = 16010003,<br>    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,<br>    NCP_ERR_ALREADY_IN_CHILD = 16010005,<br>    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,<br>    NCP_ERR_LIB_LOADING_FAILED = 16010007,<br>    NCP_ERR_CONNECTION_FAILED = 16010008<br>} | Enumerates the error codes used by the native child process module.|


### Functions

| Name                                                                                                                                                                                                        | Description                                                                                   |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted) | Creates a child process, loads the specified dynamic library file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.|

> **NOTE**
>
> Currently, only 2-in-1 devices are supported, and only one native child process can be started for a process.

## Type Description
### OH_Ability_OnNativeChildProcessStarted

```
typedef void (*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy)
```

**Description**

Defines a callback function for notifying the child process startup result.

**Since**: 12

**Parameters**

| Name         | Description                                                                                                                                                                                                                                 |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| errCode     | NCP_NO_ERROR - The child process is created successfully.<br>NCP_ERR_LIB_LOADING_FAILED - Loading the dynamic library file fails or the necessary export function is not implemented in the dynamic library.<br>NCP_ERR_CONNECTION_FAILED - The OnConnect method implemented in the dynamic library does not return a valid IPC stub pointer.<br>For details, see [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode).|
| remoteProxy | Pointer to the IPC object of the child process. If an exception occurs, the value may be nullptr. The pointer must be released by calling [OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy) when it is no longer needed.                                                                                      |

**See**

[OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess)

[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)

### NativeChildProcess_Fd

```
typedef struct NativeChildProcess_Fd {
    char* fdName;
    int32_t fd;
    struct NativeChildProcess_Fd* next;
} NativeChildProcess_Fd;
```

**Description**

Defines a struct for the file descriptor of a child process.

**Since**: 13

**Parameters**

| Name         | Description|
| ----------- | ------------- |
| fdName     | Pointer to the keyword of the file descriptor. A maximum of 20 characters are allowed.|
| fd | File descriptor handle.|
| next | Pointer to the next file descriptor.|

### NativeChildProcess_FdList

```
typedef struct NativeChildProcess_FdList {
    struct NativeChildProcess_Fd* head;
} NativeChildProcess_FdList;
```

**Description**

Defines a struct for the linked list of file descriptors of a child process. A maximum of 16 file descriptors are supported.

**Since**: 13

**Parameters**

| Name         | Description|
| ----------- | ------------- |
| head     | First file descriptor record in the linked list. For details, see [NativeChildProcess_FdList](#nativechildprocess_fdlist).|

### NativeChildProcess_Args

```
typedef struct NativeChildProcess_Args {
    char* entryParams;
    struct NativeChildProcess_FdList fdList;
} NativeChildProcess_Args;
```

**Description**

Defines a struct for the arguments used for starting a child process.

**Since**: 13

**Parameters**

| Name         | Description|
| ----------- | ------------- |
| entryParams     | Pointer to the entry parameters. The size cannot exceed 150 KB.|
| fdList | Linked list of File descriptors. For details, see [NativeChildProcess_FdList](#nativechildprocess_fdlist).|

### NativeChildProcess_Options

```
typedef struct NativeChildProcess_Options {
    NativeChildProcess_IsolationMode isolationMode;
    int64_t reserved;
} NativeChildProcess_Options;
```

**Description**

Defines a struct for the child process options.

**Since**: 13

**Parameters**

| Name         | Description|
| ----------- | ------------- |
| isolationMode     | Process isolation mode. For details, see [NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode).|
| reserved | Reserved field.|

## Enum Description

### Ability_NativeChildProcess_ErrCode

```
enum Ability_NativeChildProcess_ErrCode
```

**Description**

Enumerates the error codes used by the native child process module.

**Since**: 12

| Value                                | Description                                             |
| ----------------------------------- | ----------------------------------------------- |
| NCP_NO_ERROR                        | Operation successful.                                          |
| NCP_ERR_INVALID_PARAM               | Invalid parameter.                                          |
| NCP_ERR_NOT_SUPPORTED               | Creating a native child process is not supported.                                |
| NCP_ERR_INTERNAL                    | Internal error.                                          |
| NCP_ERR_BUSY                        | A new child process cannot be created during the startup of another native child process. You can try again after the child process is started.|
| NCP_ERR_TIMEOUT                     | Starting the native child process times out.                                 |
| NCP_ERR_SERVICE_ERROR               | Server error.                                         |
| NCP_ERR_MULTI_PROCESS_DISABLED      | The multi-process mode is disabled. A child process cannot be started.                             |
| NCP_ERR_ALREADY_IN_CHILD            | A process cannot be created in a child process.                                |
| NCP_ERR_MAX_CHILD_PROCESSES_REACHED | The number of native child processes reaches the maximum.                    |
| NCP_ERR_LIB_LOADING_FAILED          | The child process fails to load the dynamic library because the file does not exist or the corresponding method is not implemented or exported.                 |
| NCP_ERR_CONNECTION_FAILED           | The child process fails to call the OnConnect method of the dynamic library. An invalid IPC object pointer may be returned.        |

### NativeChildProcess_IsolationMode

```
enum NativeChildProcess_IsolationMode
```

**Description**

Enumerates the isolation modes of a child process.

**Since**: 13

| Value                                | Description                                             |
| ----------------------------------- | ----------------------------------------------- |
| NCP_ISOLATION_MODE_NORMAL | Normal mode. The child process shares the data sandbox and network environment with the main process.|
| NCP_ISOLATION_MODE_ISOLATED | Isolated mode. The child process does not share the data sandbox and network environment with the main process.|

## Function Description

### OH_Ability_CreateNativeChildProcess

```
int OH_Ability_CreateNativeChildProcess (const char *libName, OH_Ability_OnNativeChildProcessStarted onProcessStarted )
```

**Description**

Creates a child process, loads the specified dynamic library file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.

The dynamic library specified must implement and export the following functions:

	1. OHIPCRemoteStub* NativeChildProcess_OnConnect()
	2. void NativeChildProcess_MainProc()

The processing logic sequence is shown in the following pseudocode:

	Parent process:
	1. OH_Ability_CreateNativeChildProcess(libName, onProcessStartedCallback)
	
	Child process:
	2. dlopen(libName)
	3. dlsym("NativeChildProcess_OnConnect")
	4. dlsym("NativeChildProcess_MainProc")
	5. ipcRemote = NativeChildProcess_OnConnect()
	6. NativeChildProcess_MainProc()
	
	Parent process:
	7. onProcessStartedCallback(ipcRemote, errCode)
	
	Child process:
	8. The child process exits after the NativeChildProcess_MainProc() function is returned.

> **NOTE**
>
> Currently, only 2-in-1 devices are supported, and only one native child process can be started for a process.

**Since**: 12

**Parameters**

| Name                      | Description                                                                                                             |
| ------------------------ | --------------------------------------------------------------------------------------------------------------- |
| libName                  | Pointer to the name of the dynamic library file loaded in the child process. The value cannot be nullptr.                                                                                     |
| onProcessStartedCallback | Pointer to the callback function for notifying the child process startup result. The value cannot be nullptr. For details, see [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted).|


**Returns**

Returns **NCP_NO_ERROR** if the operation is successful; returns an error code defined in [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) otherwise.

### OH_Ability_StartNativeChildProcess

```
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(
    const char* entry, NativeChildProcess_Args args,
    NativeChildProcess_Options options, int32_t *pid)
```

**Description**

Starts a native child process, loads the specified dynamic library file, and calls the entry function. Arguments can be passed to the child process. The ArkTS basic runtime environment cannot be created in the child process.

The specified dynamic library must implement and export the entry parameters of [NativeChildProcess_Args](#nativechildprocess_args). For details, see [Native Child Process Development (C/C++) - Creating a Child Process That Supports Pass-by-Parameter](../../application-models/capi_nativechildprocess_development_guideline.md#creating-a-child-process-that-supports-pass-by-parameter).

> **NOTE**
>
> This function is valid only for 2-in-1 devices and tablets.

**Since**: 13

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| entry                  | The symbol and entry function of the dynamic library called in the child process are separated by a colon (:), for example, **libentry.so:Main**. The value cannot be a null pointer.|
| args | Arguments passed to the child process. For details, see [NativeChildProcess_Args](#nativechildprocess_args).|
| options |  Startup configuration options of the child process. For details, see [NativeChildProcess_Options](#nativechildprocess_options).|
| pid | ID of the child process to start.|


**Returns**

Returns **NCP_NO_ERROR** if the operation is successful; returns an error code defined in [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) otherwise.
