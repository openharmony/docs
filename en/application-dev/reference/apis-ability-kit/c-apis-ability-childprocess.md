# ChildProcess


## Overview

The module provides APIs to manage child processes. You can call the APIs to create a native child process and establish an IPC channel between the parent and child processes to implement multi-process application development.

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
| typedef struct [NativeChildProcess_Fd](#nativechildprocess_fd) | Defines a struct for the file descriptor of a child process.|
| typedef struct [NativeChildProcess_FdList](#nativechildprocess_fdlist) | Defines a struct for the linked list of file descriptors of a child process.|
| typedef struct [NativeChildProcess_Args](#nativechildprocess_args) | Defines a struct for the arguments used for starting a child process.|
| typedef struct [NativeChildProcess_Options](#nativechildprocess_options) | Defines a struct for the child process options.|
| typedef struct [Ability_ChildProcessConfigs](#ability_childprocessconfigs) | Defines the configuration for starting a child process.|
| typedef void(\* [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit)) (int32_t pid, int32_t signal) | Defines the callback function for detecting abnormal exit of a native child process.|

### Enums

| Name                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              | Description               |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) {<br>    NCP_NO_ERROR = 0,<br>    NCP_ERR_INVALID_PARAM = 401,<br>    NCP_ERR_NOT_SUPPORTED = 801,<br>    NCP_ERR_INTERNAL = 16000050,<br>    NCP_ERR_BUSY = 16010001,<br>    NCP_ERR_TIMEOUT = 16010002,<br>    NCP_ERR_SERVICE_ERROR = 16010003,<br>    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,<br>    NCP_ERR_ALREADY_IN_CHILD = 16010005,<br>    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,<br>    NCP_ERR_LIB_LOADING_FAILED = 16010007,<br>    NCP_ERR_CONNECTION_FAILED = 16010008,<br>    NCP_ERR_CALLBACK_NOT_EXIST = 16010009<br>} | Enumerates the error codes used by the native child process module.|


### Functions

| Name                                                                                                                                                                                                        | Description                                                                                   |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted) | Creates a child process, loads the specified Dynamic Link Library (DLL) file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess) (const char\* entry, [NativeChildProcess_Args](#nativechildprocess_args) args, [NativeChildProcess_Options](#nativechildprocess_options) options, int32_t *pid) | Starts a child process and loads the specified library file.|
| [Ability_ChildProcessConfigs](#ability_childprocessconfigs)* [OH_Ability_CreateChildProcessConfigs](#oh_ability_createchildprocessconfigs) () | Creates a child process configuration object.|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_DestroyChildProcessConfigs](#oh_ability_destroychildprocessconfigs) ([Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs) | Destroys a child process configuration object and releases the memory.|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_ChildProcessConfigs_SetIsolationMode](#oh_ability_childprocessconfigs_setisolationmode) ([Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, [NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode) isolationMode) | Sets the sharing mode of the data sandbox and network environment for a child process configuration object. This setting takes effect only when [OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs) is called.|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_ChildProcessConfigs_SetProcessName](#oh_ability_childprocessconfigs_setprocessname) ([Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, const char\* processName) | Sets the process name in a child process configuration object.|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_CreateNativeChildProcessWithConfigs](#oh_ability_createnativechildprocesswithconfigs) (const char\* libName, [Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted) | Creates a child process based on a child process configuration object and loads the specified DLL file. The startup result is asynchronously communicated to the caller via a callback. The callback runs in a separate thread. You must ensure thread synchronization and avoid time-consuming operations to prevent delays.|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs) (const char\* entry, [NativeChildProcess_Args](#nativechildprocess_args) args, [Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, int32_t\* pid) | Starts a child process based on a child process configuration object and loads the specified library file.|

> **NOTE**
>
> This function is valid only for 2-in-1 devices.
> Since API version 15, a single process supports a maximum of 50 native child processes. In API version 14 and earlier versions, a single process supports only one native child process.

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
| errCode     | NCP_NO_ERROR - The child process is created successfully.<br>NCP_ERR_LIB_LOADING_FAILED - Loading the DLL file fails or the necessary export function is not implemented in the DLL.<br>NCP_ERR_CONNECTION_FAILED - The OnConnect method implemented in the DLL does not return a valid IPC stub pointer.<br>For details about the error codes, see [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode).|
| remoteProxy | Pointer to the IPC object of the child process. If an exception occurs, the value may be nullptr. The pointer must be released by calling [OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy) when it is no longer needed.                                                                                      |

**See**

[OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess)

[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)

### OH_Ability_OnNativeChildProcessExit

```
typedef void (*OH_Ability_OnNativeChildProcessExit)(int32_t pid, int32_t signal)
```

**Description**

Defines the callback function for detecting abnormal exit of a native child process.

**Since**: 20

**Parameters**

| Name         | Description                                                                                                                                                                                                                                 |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| pid     | PID of the child process.|
| signal | Signal for abnormal exit of the child process.                                                                                      |

**See**

[OH_Ability_RegisterNativeChildProcessExitCallback](#oh_ability_registernativechildprocessexitcallback)

[OH_Ability_UnregisterNativeChildProcessExitCallback](#oh_ability_unregisternativechildprocessexitcallback)

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

### Ability_ChildProcessConfigs

**Description**

Describes the configuration information about a child process, including the child process name and the sharing mode of the data sandbox and network environment.

**Since**: 20

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
| NCP_ERR_BUSY                        | A new child process cannot be created during the startup of another native child process. You can try again after the child process is started. This function is deprecated since API version 15.|
| NCP_ERR_TIMEOUT                     | Starting the native child process times out.                                 |
| NCP_ERR_SERVICE_ERROR               | Server error.                                         |
| NCP_ERR_MULTI_PROCESS_DISABLED      | The multi-process mode is disabled. A child process cannot be started.                             |
| NCP_ERR_ALREADY_IN_CHILD            | A process cannot be created in a child process.                                |
| NCP_ERR_MAX_CHILD_PROCESSES_REACHED | The number of native child processes reaches the maximum.                    |
| NCP_ERR_LIB_LOADING_FAILED          | The child process fails to load the DLL because the file does not exist or the corresponding method is not implemented or exported.                 |
| NCP_ERR_CONNECTION_FAILED           | The child process fails to call the OnConnect method of the DLL. An invalid IPC object pointer may be returned.        |
| NCP_ERR_CALLBACK_NOT_EXIST          | The child process calls the **OH_Ability_UnregisterNativeChildProcessExitCallback** function to unregister a callback function, but the callback function is not found.        |

### NativeChildProcess_IsolationMode

```
enum NativeChildProcess_IsolationMode
```

**Description**

Enumerates the sharing modes available for the data sandbox and network environment of a native child process.

**Since**: 13

| Value                                | Description                                             |
| ----------------------------------- | ----------------------------------------------- |
| NCP_ISOLATION_MODE_NORMAL | The child process shares the same data sandbox and network environment as the main process.|
| NCP_ISOLATION_MODE_ISOLATED | The child process has its own separate data sandbox and network environment, isolated from the main process.|

## Function Description

### OH_Ability_CreateNativeChildProcess

```
int OH_Ability_CreateNativeChildProcess (const char *libName, OH_Ability_OnNativeChildProcessStarted onProcessStarted)
```

**Description**

Creates a child process, loads the specified DLL file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.

The DLL specified must implement and export the following functions:

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
> This function is valid only for 2-in-1 devices.
>
> Since API version 15, a single process supports a maximum of 50 native child processes. In API version 14 and earlier versions, a single process supports only one native child process.

**Since**: 12

**Parameters**

| Name                      | Description                                                                                                             |
| ------------------------ | --------------------------------------------------------------------------------------------------------------- |
| libName                  | Pointer to the name of the DLL file loaded in the child process. The value cannot be nullptr.                                                                                     |
| onProcessStarted | Pointer to the callback function for notifying the child process startup result. The value cannot be nullptr. For details, see [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted).|


**Returns**

**NCP_NO_ERROR**. If the operation fails, an error code defined in [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) is returned.

### OH_Ability_StartNativeChildProcess

```
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(
    const char* entry, NativeChildProcess_Args args,
    NativeChildProcess_Options options, int32_t *pid)
```

**Description**

Starts a native child process, loads the specified DLL file, and calls the entry function. Arguments can be passed to the child process. The ArkTS basic runtime environment cannot be created in the child process.

The specified DLL must implement and export the entry parameters of [NativeChildProcess_Args](#nativechildprocess_args). For details, see [Native Child Process Development (C/C++) - Creating a Child Process That Supports Pass-by-Parameter](../../application-models/capi_nativechildprocess_development_guideline.md#creating-a-child-process-that-supports-pass-by-parameter).

> **NOTE**
>
> This function is valid only for 2-in-1 devices and tablets.

**Since**: 13

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| entry                  | The symbol and entry function of the DLL called in the child process are separated by a colon (:), for example, **libentry.so:Main**. The value cannot be nullptr.|
| args | Arguments passed to the child process. For details, see [NativeChildProcess_Args](#nativechildprocess_args).|
| options |  Startup configuration options of the child process. For details, see [NativeChildProcess_Options](#nativechildprocess_options).|
| pid | ID of the child process to start.|


**Returns**

**NCP_NO_ERROR**. If the operation fails, an error code defined in [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) is returned.

### OH_Ability_GetCurrentChildProcessArgs

```
NativeChildProcess_Args* OH_Ability_GetCurrentChildProcessArgs();
```

**Description**

Used by a child process, after being started by calling [OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess), to obtain the startup parameter [NativeChildProcess_Args](#nativechildprocess_args) from any .so file or child thread.

> **NOTE**
>
> This function is valid only for 2-in-1 devices and tablets.

**Since**: 17

**Returns**

Pointer to a [NativeChildProcess_Args](#nativechildprocess_args) object. If the operation fails, nullptr is returned.

### OH_Ability_RegisterNativeChildProcessExitCallback

```
Ability_NativeChildProcess_ErrCode OH_Ability_RegisterNativeChildProcessExitCallback(
    OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**Description**

Registers a callback function for detecting abnormal exit of a native child process. When a child process started by calling [OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess) or [startNativeChildProcess in @ohos.app.ability.childProcessManager](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13) exits abnormally, the callback function is invoked. If the same callback function is registered multiple times, the callback function is executed only once when the child process exits.

The parameter must implement the entry function [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit). For details, see [Registering the Native Child Process Exit Callback Function](../../application-models/capi-nativechildprocess-exit-info.md).

**Since**: 20

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| onProcessExit                  | Address of the callback function to be called when the child process exits. The value cannot be nullptr.|

**Returns**

**NCP_NO_ERROR**. If the operation fails, an error code defined in [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) is returned.

### OH_Ability_UnregisterNativeChildProcessExitCallback

```
Ability_NativeChildProcess_ErrCode OH_Ability_UnregisterNativeChildProcessExitCallback(
    OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**Description**

Unregisters the callback function used for detecting abnormal exit of a native child process.

The parameter must implement the entry function [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit). For details, see [Registering the Native Child Process Exit Callback Function](../../application-models/capi-nativechildprocess-exit-info.md).

**Since**: 20

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| onProcessExit                  | Address of the callback function to be called when the child process exits. The value cannot be nullptr.|


**Returns**

**NCP_NO_ERROR**. If the operation fails, an error code defined in [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) is returned.

### OH_Ability_CreateChildProcessConfigs

```
Ability_ChildProcessConfigs* OH_Ability_CreateChildProcessConfigs();
```

**Description**

Creates a child process configuration object. When this object is no longer needed, call [OH_Ability_DestroyChildProcessConfigs](#oh_ability_destroychildprocessconfigs) to destroy the object to prevent memory leakage.

**Since**: 20

**Returns**

Pointer to the [Ability_ChildProcessConfigs](#ability_childprocessconfigs) object: The operation is successful. 
nullptr: An internal error occurs or memory allocation fails.

### OH_Ability_DestroyChildProcessConfigs

```
Ability_NativeChildProcess_ErrCode OH_Ability_DestroyChildProcessConfigs(Ability_ChildProcessConfigs* configs);
```

**Description**

Destroys a child process configuration object and releases its memory. After this function is called, do not use the destroyed object.

**Since**: 20

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| configs | Pointer to a child process configuration object. For details, see [Ability_ChildProcessConfigs](#ability_childprocessconfigs). After this function is called, the object pointer becomes invalid. Do not use the pointer. nullptr is allowed, which does not trigger any operation.|

**Returns**

**NCP_NO_ERROR**: The operation is successful.

**NCP_ERR_INVALID_PARAM**: An input parameter is nullptr.

For details about the error codes, see [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode).


### OH_Ability_ChildProcessConfigs_SetIsolationMode

```
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationMode(
    Ability_ChildProcessConfigs* configs, NativeChildProcess_IsolationMode isolationMode);
```

**Description**

Sets the sharing mode of the data sandbox and network environment for a child process configuration object. This setting takes effect only when [OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs) is called.

**Since**: 20

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| configs | Pointer to a child process configuration object. For details, see [Ability_ChildProcessConfigs](#ability_childprocessconfigs).|
| isolationMode | Sharing mode of the data sandbox and network environment. For details, see [NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode).|

**Returns**

**NCP_NO_ERROR**: The operation is successful.

**NCP_ERR_INVALID_PARAM**: The parameter **configs** is nullptr.

For details about the error codes, see [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode).

### OH_Ability_ChildProcessConfigs_SetProcessName

```
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetProcessName(Ability_ChildProcessConfigs* configs, const char* processName);
```

**Description**

Sets the process name in a child process configuration object.

**Since**: 20

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| configs | Pointer to a child process configuration object. For details, see [Ability_ChildProcessConfigs](#ability_childprocessconfigs). The pointer cannot be null.|
| processName | Pointer to the process name, which must be a non-empty string containing a maximum of 64 characters. The string can contain only letters, digits, and underscores (_). The final process name is in the format of {bundleName}:{processName}.|

**Returns**

**NCP_NO_ERROR**: The operation is successful.

**NCP_ERR_INVALID_PARAM**: The input parameter **configs** is nullptr, or **processName** contains characters other than letters, digits, and underscores (_). 

For details about the error codes, see [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode).


### OH_Ability_CreateNativeChildProcessWithConfigs

```
 Ability_NativeChildProcess_ErrCode OH_Ability_CreateNativeChildProcessWithConfigs(const char* libName,
    Ability_ChildProcessConfigs* configs, OH_Ability_OnNativeChildProcessStarted onProcessStarted);
```

**Description**

Creates a child process based on a child process configuration object and loads the specified DLL file. The startup result is asynchronously communicated to the caller via a callback. The callback runs in a separate thread. You must ensure thread synchronization and avoid time-consuming operations to prevent delays.

The DLL specified must implement and export the following functions:

	1. OHIPCRemoteStub* NativeChildProcess_OnConnect()
	2. void NativeChildProcess_MainProc()

The processing logic sequence is shown in the following pseudocode:

	Parent process:
	1. OH_Ability_CreateNativeChildProcessWithConfigs(libName, configs, onProcessStartedCallback)
	
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
> This function is valid only for 2-in-1 devices and tablets.

**Since**: 20

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| libName                  | Pointer to the name of the DLL file loaded in the child process. The value cannot be nullptr.|
| configs | Pointer to the child process configuration object. The value cannot be nullptr. For details, see [Ability_ChildProcessConfigs](#ability_childprocessconfigs).|
| onProcessStarted |  Pointer to the callback function for notifying the child process startup result. The value cannot be nullptr. For details, see [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted).|

**Returns**

**NCP_NO_ERROR**: The operation is successful.

**NCP_ERR_INVALID_PARAM**: An input parameter is invalid.

**NCP_ERR_NOT_SUPPORTED**: The device does not support the creation of native child processes.

**NCP_ERR_MULTI_PROCESS_DISABLED**: Multi-process mode is disabled on the device, and the child process cannot be started.

**NCP_ERR_ALREADY_IN_CHILD**: A process cannot be created in a child process.

**NCP_ERR_MAX_CHILD_PROCESSES_REACHED**: The maximum number of native child processes has been reached.

For details about the error codes, see [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode).

### OH_Ability_StartNativeChildProcessWithConfigs

```
 Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcessWithConfigs(
    const char* entry, NativeChildProcess_Args args, Ability_ChildProcessConfigs* configs, int32_t *pid);
```

**Description**

Starts a native child process based on the child process configuration object, loads the specified DLL file, and calls the entry function. Arguments can be passed to the child process.

The specified DLL file must implement the entry function with the parameter [NativeChildProcess_Args](#nativechildprocess_args) and export the entry function. For details, see [Creating a Child Process That Supports Pass-by-Parameter](../../application-models/capi_nativechildprocess_development_guideline.md#creating-a-child-process-that-supports-pass-by-parameter). The following is an example:

    1. void Main(NativeChildProcess_Args args);

The processing logic sequence is shown in the following pseudocode:

	Parent process:
	1. OH_Ability_StartNativeChildProcessWithConfigs(entryPoint, args, configs, &pid)
	
	Child process:
	2. dlopen(libName)
	3. dlsym("Main")
	4. Main(args)
	5. The child process exits after the Main(args) function returns.

> **NOTE**
>
> This function is valid only for 2-in-1 devices and tablets.

**Since**: 20

**Parameters**

| Name                      | Description|
| ---------------------- | ---------------- |
| entry                  | Pointer to the symbol and entry function of the DDL called in the child process, separated by a colon (:), for example, **libentry.so:Main**. The value cannot be nullptr.|
| args | Arguments passed to the child process. For details, see [NativeChildProcess_Args](#nativechildprocess_args).|
| configs |  Pointer to a child process configuration object. For details, see [Ability_ChildProcessConfigs](#ability_childprocessconfigs).|
| pid | Pointer to the ID of the child process to start.|

**Returns**

**NCP_NO_ERROR**: The operation is successful.

**NCP_ERR_INVALID_PARAM**: An input parameter is invalid.

**NCP_ERR_NOT_SUPPORTED**: The device does not support the creation of native child processes.

**NCP_ERR_ALREADY_IN_CHILD**: A process cannot be created in a child process.

**NCP_ERR_MAX_CHILD_PROCESSES_REACHED**: The maximum number of native child processes has been reached.

For details about the error codes, see [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode).
