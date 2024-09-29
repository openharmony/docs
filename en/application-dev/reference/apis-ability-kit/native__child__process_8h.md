# native_child_process.h


## Overview

The **native_child_process.h** file declares the APIs used to create a native child process and establish an IPC channel between the parent and child processes.

**Library**: libchild_process.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 12

**Related module**: [ChildProcess](c-apis-ability-childprocess.md)


## Summary

### Files

| Name                                                    | Description                                                                                                |
| ------------------------------------------------------ | -------------------------------------------------------------------------------------------------- |
| [native_child_process.h](native__child__process_8h.md) | Declares the APIs used to create a native child process and establish an IPC channel between the parent and child processes.<br>File to include: <AbilityKit/native_child_process.h><br>Library: libchild_process.so|

### Types

| Name                                                                                                                                                                            | Description               |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------- |
| typedef enum Ability_NativeChildProcess_ErrCode [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode)                        | Defines an enum for the error codes used by the native child process module.|
| typedef void(\* [OH_Ability_OnNativeChildProcessStarted](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted)) (int errCode, OHIPCRemoteProxy \*remoteProxy) | Defines a callback function for notifying the child process startup result.|


### Enums

| Name                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            | Description               |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) {<br>    NCP_NO_ERROR = 0,<br>    NCP_ERR_INVALID_PARAM = 401,<br>    NCP_ERR_NOT_SUPPORTED = 801,<br>    NCP_ERR_INTERNAL = 16000050,<br>    NCP_ERR_BUSY = 16010001,<br>    NCP_ERR_TIMEOUT = 16010002,<br>    NCP_ERR_SERVICE_ERROR = 16010003,<br>    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,<br>    NCP_ERR_ALREADY_IN_CHILD = 16010005,<br>    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,<br>    NCP_ERR_LIB_LOADING_FAILED = 16010007,<br>    NCP_ERR_CONNECTION_FAILED = 16010008<br>} | Enumerates the error codes used by the native child process module.|


### Functions

| Name                                                                                                                                                                                                                                                                    | Description                                                                                   |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](c-apis-ability-childprocess.md#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | Creates a child process, loads the specified dynamic library file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.|

> **NOTE**
>
> Currently, only 2-in-1 devices are supported, and only one native child process can be started for a process.
