# native_child_process.h


## Overview

The **native_child_process.h** file declares the APIs used to create a native child process and establish an IPC channel between the main process and child process. A maximum of 512 child processes can be started through this module and [childProcessManager](js-apis-app-ability-childProcessManager.md) (non-SELF_FORK mode).

**Library**: libchild_process.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 12

**Related module**: [ChildProcess](c-apis-ability-childprocess.md)


## Summary

### Files

| Name                                                    | Description                                                                                                |
| ------------------------------------------------------ | -------------------------------------------------------------------------------------------------- |
| [native_child_process.h](native__child__process_8h.md) | Declares the APIs used to create a native child process and establish an IPC channel between the main process and child process.<br>File to include: <AbilityKit/native_child_process.h><br>Library: libchild_process.so|

### Types

| Name                                                                                                                                                                            | Description               |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------- |
| typedef enum Ability_NativeChildProcess_ErrCode [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode)                        | Defines an enum for the error codes used by the native child process module.|
| typedef void(\* [OH_Ability_OnNativeChildProcessStarted](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted)) (int errCode, OHIPCRemoteProxy \*remoteProxy) | Defines a callback function for notifying the child process startup result.|
| typedef void(\* [OH_Ability_OnNativeChildProcessExit](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit)) (int32_t pid, int32_t signal) | Defines the callback function for detecting abnormal exit of a native child process.|
| typedef struct [NativeChildProcess_Fd](c-apis-ability-childprocess.md#nativechildprocess_fd) | Defines a struct for the file descriptor of a child process.|
| typedef struct [NativeChildProcess_FdList](c-apis-ability-childprocess.md#nativechildprocess_fdlist) | Defines a struct for the linked list of file descriptors of a child process.|
| typedef struct [NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args) | Defines a struct for the arguments used for starting a child process.|
| typedef struct [NativeChildProcess_Options](c-apis-ability-childprocess.md#nativechildprocess_options) | Defines a struct for the startup configuration options of a child process.|


### Enums

| Name                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | Description               |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) {<br>    NCP_NO_ERROR = 0,<br>    NCP_ERR_INVALID_PARAM = 401,<br>    NCP_ERR_NOT_SUPPORTED = 801,<br>    NCP_ERR_INTERNAL = 16000050,<br>    NCP_ERR_BUSY = 16010001,<br>    NCP_ERR_TIMEOUT = 16010002,<br>    NCP_ERR_SERVICE_ERROR = 16010003,<br>    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,<br>    NCP_ERR_ALREADY_IN_CHILD = 16010005,<br>    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,<br>    NCP_ERR_LIB_LOADING_FAILED = 16010007,<br>    NCP_ERR_CONNECTION_FAILED = 16010008<br>NCP_ERR_CALLBACK_NOT_EXIST = 16010009<br>} | Enumerates the error codes used by the native child process module.|
| [NativeChildProcess_IsolationMode](c-apis-ability-childprocess.md#nativechildprocess_isolationmode) {<br>    NCP_ISOLATION_MODE_NORMAL = 0,<br>    NCP_ISOLATION_MODE_ISOLATED = 1,<br>} | Enumerates the isolation modes of a child process.|


### Functions

| Name                                                                                                                                                                                                                                                                    | Description                                                                                   |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](c-apis-ability-childprocess.md#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | Creates a child process, loads the specified dynamic library file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.<br><b>NOTE</b><br>Currently, this function is valid only for 2-in-1 devices. Since API version 15, a single process supports a maximum of 50 native child processes. In API version 14 and earlier versions, a single process supports only one native child process.|
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcess](c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)(const char\* entry, [NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args) args, [NativeChildProcess_Options](c-apis-ability-childprocess.md#nativechildprocess_options) options, int32_t *pid) | Starts a child process, loads the specified dynamic library file, and calls the entry function. Arguments can be passed to the child process.<br><b>NOTE</b><br>Currently, this function is valid only for 2-in-1 devices and tablets.|
| [NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args)* [OH_Ability_GetCurrentChildProcessArgs](c-apis-ability-childprocess.md#oh_ability_getcurrentchildprocessargs)() | Used by a child process, after being started by calling [OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess), to obtain the startup parameter [NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args) from any .so file or child thread.<br><b>NOTE</b><br>Currently, this function is valid only for 2-in-1 devices and tablets.|
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_RegisterNativeChildProcessExitCallback](c-apis-ability-childprocess.md#oh_ability_registernativechildprocessexitcallback)([OH_Ability_OnNativeChildProcessExit](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit) onProcessExit) | Registers a callback function for detecting abnormal exit of a native child process. It is used to obtain the information about the child process that exits abnormally.|
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_UnregisterNativeChildProcessExitCallback](c-apis-ability-childprocess.md#oh_ability_unregisternativechildprocessexitcallback)([OH_Ability_OnNativeChildProcessExit](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit) onProcessExit) | Unregisters the callback function used for detecting abnormal exit of a native child process.|
