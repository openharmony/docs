# ChildProcess


## Overview

The ChildProcess module provides APIs to manage child processes. You can call the APIs to create a native child process and establish an IPC channel between the parent and child processes to implement multi-process application development.

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
| remoteProxy | Pointer to the IPC object of the child process. If an exception occurs, the value may be nullptr. The pointer must be released by calling [OH_IPCRemoteProxy_Destory](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy) when it is no longer needed.                                                                                      |

**See**

[OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess)

[OH_IPCRemoteProxy_Destory](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)



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
