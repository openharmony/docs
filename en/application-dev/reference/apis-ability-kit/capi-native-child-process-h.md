# native_child_process.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## Overview

Declares the APIs used to create a native child process and establish an IPC channel between the parent and child processes.

A maximum of 512 child processes can be started through this module and [childProcessManager](js-apis-app-ability-childProcessManager.md) (non-SELF_FORK mode).

**File to include**: <AbilityKit/native_child_process.h>

**Library**: libchild_process.so

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 12

**Related module**: [ChildProcess](capi-childprocess.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NativeChildProcess_Fd](capi-nativechildprocess-fd.md) | NativeChildProcess_Fd | Describes the information about the file descriptor passed to the child process.|
| [NativeChildProcess_FdList](capi-nativechildprocess-fdlist.md) | NativeChildProcess_FdList | Describes the list of file descriptors passed to the child process. A maximum of 16 file descriptors are supported.|
| [NativeChildProcess_Options](capi-nativechildprocess-options.md) | NativeChildProcess_Options | Describes the options used by the child process.|
| [NativeChildProcess_Args](capi-nativechildprocess-args.md) | NativeChildProcess_Args | Describes the parameters passed to the child process.|
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md) | Ability_ChildProcessConfigs | Describes the configuration information about a child process, including the child process name and the sharing mode of the data sandbox and network environment.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | Ability_NativeChildProcess_ErrCode | Defines an enum for the error codes used by the native child process module.|
| [NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode) | NativeChildProcess_IsolationMode | Enumerates the sharing modes available for the data sandbox and network environment of a native child process.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [Ability_ChildProcessConfigs* OH_Ability_CreateChildProcessConfigs()](#oh_ability_createchildprocessconfigs) | - | Creates a child process configuration object. When this object is no longer needed, call [OH_Ability_DestroyChildProcessConfigs](capi-native-child-process-h.md#oh_ability_destroychildprocessconfigs) to destroy the object to prevent memory leakage.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_DestroyChildProcessConfigs(Ability_ChildProcessConfigs* configs)](#oh_ability_destroychildprocessconfigs) | - | Destroys a child process configuration object and releases its memory. After this function is called, do not use the destroyed object.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationMode(Ability_ChildProcessConfigs* configs, NativeChildProcess_IsolationMode isolationMode)](#oh_ability_childprocessconfigs_setisolationmode) | - | Sets the sharing mode of the data sandbox and network environment for a child process configuration object. For details, see [NativeChildProcess_IsolationMode](capi-native-child-process-h.md#nativechildprocess_isolationmode). This setting takes effect only when [OH_Ability_StartNativeChildProcessWithConfigs](capi-native-child-process-h.md#oh_ability_startnativechildprocesswithconfigs) is called.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetProcessName(Ability_ChildProcessConfigs* configs,const char* processName)](#oh_ability_childprocessconfigs_setprocessname) | - | Sets the process name in a child process configuration object.|
| [typedef void (\*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy)](#oh_ability_onnativechildprocessstarted) | OH_Ability_OnNativeChildProcessStarted | Creates a child process based on a child process configuration object and loads the specified DLL file. The startup result is asynchronously communicated to the caller via a callback. The callback runs in a separate thread. You must ensure thread synchronization and avoid time-consuming operations to prevent delays.|
| [int OH_Ability_CreateNativeChildProcess(const char* libName,OH_Ability_OnNativeChildProcessStarted onProcessStarted)](#oh_ability_createnativechildprocess) | - | Creates a child process, loads the specified Dynamic Link Library (DLL) file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking. The DLL specified must implement and export the following functions:<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_CreateNativeChildProcess(libName, onProcessStartedCallback)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>Parent process:<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>Child process:<br>8. The child process exits after the NativeChildProcess_MainProc() function is returned.<br>Note: Starting from API version 14, 2-in-1 devices and tablets are supported. In API version 13 and earlier versions, only 2-in-1 devices are supported. Starting from API version 15, a single process supports a maximum of 50 native child processes. In API version 14 and earlier versions, a single process supports only one native child process.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_CreateNativeChildProcessWithConfigs(const char* libName,Ability_ChildProcessConfigs* configs, OH_Ability_OnNativeChildProcessStarted onProcessStarted)](#oh_ability_createnativechildprocesswithconfigs) | - | Creates a child process based on a child process configuration object and loads the specified DLL file. The startup result is asynchronously communicated to the caller via a callback. The callback runs in a separate thread. You must ensure thread synchronization and avoid time-consuming operations to prevent delays. The DLL specified must implement and export the following functions:<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_CreateNativeChildProcessWithConfigs(libName, configs, onProcessStartedCallback)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>Parent process:<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>Child process:<br>8. <br>The child process exits after the NativeChildProcess_MainProc() function is returned. <br>Note: Currently, only 2-in-1 devices and tablets are supported.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(const char* entry, NativeChildProcess_Args args,NativeChildProcess_Options options, int32_t *pid)](#oh_ability_startnativechildprocess) | - | Starts a child process and loads the specified Dynamic Link Library (DLL) file. The specified DLL must implement and export a function that accepts **NativeChildProcess_Args** as its parameter (you can customize the function name). The following is an example:<br>1. void Main(NativeChildProcess_Args args);<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_StartNativeChildProcess(entryPoint, args, options)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. The child process exits after the Main(args) function returns.<br>Note: Currently, only 2-in-1 devices and tablets are supported.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcessWithConfigs(const char* entry, NativeChildProcess_Args args, Ability_ChildProcessConfigs* configs, int32_t *pid)](#oh_ability_startnativechildprocesswithconfigs) | - | Starts a native child process based on the child process configuration object, loads the specified DLL file, and calls the entry function. Arguments can be passed to the child process. The specified DLL must implement and export a function that accepts **NativeChildProcess_Args** as its parameter (you can customize the function name). The following is an example:<br>1. void Main(NativeChildProcess_Args args);<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_StartNativeChildProcessWithConfigs(entryPoint, args, configs, &pid)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. The child process exits after the Main(args) function returns.<br>Note: Currently, only 2-in-1 devices and tablets are supported.|
| [NativeChildProcess_Args* OH_Ability_GetCurrentChildProcessArgs()](#oh_ability_getcurrentchildprocessargs) | - | Obtains the startup parameters of the child process.<br>Note: Currently, only 2-in-1 devices and tablets are supported.|
| [typedef void (\*OH_Ability_OnNativeChildProcessExit)(int32_t pid, int32_t signal)](#oh_ability_onnativechildprocessexit) | OH_Ability_OnNativeChildProcessExit | Obtains the exit information of the child process.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_RegisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)](#oh_ability_registernativechildprocessexitcallback) | - | Registers a callback to listen for child process exit. If the same callback function is registered repeatedly, only one of them is kept.|
| [Ability_NativeChildProcess_ErrCode OH_Ability_UnregisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)](#oh_ability_unregisternativechildprocessexitcallback) | - | Unregisters the callback used to listen for child process exit.|

## Enum Description

### Ability_NativeChildProcess_ErrCode

```
enum Ability_NativeChildProcess_ErrCode
```

**Description**

Defines an enum for the error codes used by the native child process module.

**Since**: 12

| Value| Description|
| -- | -- |
| NCP_NO_ERROR = 0 | Operation successful.|
| NCP_ERR_INVALID_PARAM = 401 | Invalid parameter.|
| NCP_ERR_NOT_SUPPORTED = 801 | Creating a native child process is not supported.|
| NCP_ERR_INTERNAL = 16000050 | Internal error.|
| NCP_ERR_BUSY = 16010001 | A new child process cannot be created during the startup of another native child process. You can try again after the child process is started. This function is deprecated since API version 15.|
| NCP_ERR_TIMEOUT = 16010002 | Starting the native child process times out.|
| NCP_ERR_SERVICE_ERROR = 16010003 | Server error.|
| NCP_ERR_MULTI_PROCESS_DISABLED = 16010004 | The multi-process mode is disabled. A child process cannot be started.|
| NCP_ERR_ALREADY_IN_CHILD = 16010005 | A process cannot be created in a child process.|
| NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006 | The number of native child processes reaches the maximum.|
| NCP_ERR_LIB_LOADING_FAILED = 16010007 | The child process fails to load the DLL because the file does not exist or the corresponding method is not implemented or exported.|
| NCP_ERR_CONNECTION_FAILED = 16010008 | The child process fails to call the OnConnect method of the DLL. An invalid IPC object pointer may be returned.|
| NCP_ERR_CALLBACK_NOT_EXIST = 16010009 | The parent process calls the **OH_Ability_UnregisterNativeChildProcessExitCallback** function to unregister a callback function, but the callback function is not found.|

### NativeChildProcess_IsolationMode

```
enum NativeChildProcess_IsolationMode
```

**Description**

Enumerates the sharing modes available for the data sandbox and network environment of a native child process.

**Since**: 13

| Value| Description|
| -- | -- |
| NCP_ISOLATION_MODE_NORMAL = 0 | In normal mode, the parent and child processes share the same sandbox or network environment.|
| NCP_ISOLATION_MODE_ISOLATED = 1 | In isolated mode, the parent and child processes each have their own separate sandbox and network environment.|


## Function Description

### OH_Ability_CreateChildProcessConfigs()

```
Ability_ChildProcessConfigs* OH_Ability_CreateChildProcessConfigs()
```

**Description**

Creates a child process configuration object. When this object is no longer needed, call [OH_Ability_DestroyChildProcessConfigs](capi-native-child-process-h.md#oh_ability_destroychildprocessconfigs) to destroy the object to prevent memory leakage.

**Since**: 20

**Returns**

| Type                              | Description|
|----------------------------------| -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* | Pointer to the [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md) object: The call is successful.<br>         nullptr: An internal error occurs or memory allocation fails.|

### OH_Ability_DestroyChildProcessConfigs()

```
Ability_NativeChildProcess_ErrCode OH_Ability_DestroyChildProcessConfigs(Ability_ChildProcessConfigs* configs)
```

**Description**

Destroys a child process configuration object and releases its memory. After this function is called, do not use the destroyed object.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | Pointer to a child process configuration object. After this function is called, the object pointer becomes invalid. Do not use the pointer. nullptr is allowed, which does not trigger any operation.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_NO_ERR_INVALID_PARAM**: An input parameter is nullptr.|

### OH_Ability_ChildProcessConfigs_SetIsolationMode()

```
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationMode(Ability_ChildProcessConfigs* configs, NativeChildProcess_IsolationMode isolationMode)
```

**Description**

Sets the sharing mode of the data sandbox and network environment for a child process configuration object. For details, see [NativeChildProcess_IsolationMode](capi-native-child-process-h.md#nativechildprocess_isolationmode). This setting takes effect only when [OH_Ability_StartNativeChildProcessWithConfigs](capi-native-child-process-h.md#oh_ability_startnativechildprocesswithconfigs) is called.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | Pointer to a child process configuration object. The value cannot be nullptr.|
| [NativeChildProcess_IsolationMode](capi-native-child-process-h.md#nativechildprocess_isolationmode) isolationMode | Sharing mode of the data sandbox and network environment. For details, see **NativeChildProcess_IsolationMode**.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_NO_ERR_INVALID_PARAM**: The input parameter **configs** is nullptr.|

### OH_Ability_ChildProcessConfigs_SetProcessName()

```
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetProcessName(Ability_ChildProcessConfigs* configs,const char* processName)
```

**Description**

Sets the process name in a child process configuration object.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | Pointer to a child process configuration object. The pointer cannot be null.|
| const char* processName | Pointer to the process name, which must be a non-empty string accepting only letters, digits, and underscores (_). The string contains a maximum of 64 characters. The final process name is in the format of {bundleName}:{processName}.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_NO_ERR_INVALID_PARAM**: The input parameter **configs** is nullptr, or **processName** contains characters other than letters, digits, and underscores (_).|

### OH_Ability_OnNativeChildProcessStarted()

```
typedef void (*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy)
```

**Description**

Defines a callback function for notifying the child process startup result.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| int errCode | Error code returned by the callback function.<br>[NCP_NO_ERROR](capi-native-child-process-h.md#ability_nativechildprocess_errcode): The child process is created successfully.<br>[NCP_ERR_LIB_LOADING_FAILED](capi-native-child-process-h.md#ability_nativechildprocess_errcode): Loading the DLL file fails or the necessary export function is not implemented in the DLL.<br>[NCP_ERR_CONNECTION_FAILED](capi-native-child-process-h.md#ability_nativechildprocess_errcode): The **OnConnect** method implemented in the DLL does not return a valid IPC stub pointer.<br>For details, see [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode).|
| [OHIPCRemoteProxy *remoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md) | Pointer to the IPC object of the child process. If an exception occurs, the value may be nullptr. The pointer must be released by calling [OH_IPCRemoteProxy_Destory](../apis-ipc-kit/capi-ipc-cremote-object-h.md#oh_ipcremoteproxy_destroy) when it is no longer needed.|

**Reference**

[OH_IPCRemoteProxy_Destory](../apis-ipc-kit/capi-ipc-cremote-object-h.md#oh_ipcremoteproxy_destroy)

### OH_Ability_CreateNativeChildProcess()

```
int OH_Ability_CreateNativeChildProcess(const char* libName,OH_Ability_OnNativeChildProcessStarted onProcessStarted)
```

**Description**

Creates a child process, loads the specified Dynamic Link Library (DLL) file, and returns the startup result asynchronously through a callback parameter. The callback notification is an independent thread. When implementing the callback function, pay attention to thread synchronization and do not perform time-consuming operations to avoid long-time blocking.

The DLL specified must implement and export the following functions:<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_CreateNativeChildProcess(libName, onProcessStartedCallback)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>Parent process:<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>Child process:<br>8. The child process exits after the NativeChildProcess_MainProc() function is returned.

> **NOTE**
>
> Starting from API version 14, 2-in-1 devices and tablets are supported. In API version 13 and earlier versions, only 2-in-1 devices are supported.
>
> Starting from API version 15, a single process supports a maximum of 50 native child processes. In API version 14 and earlier versions, a single process supports only one native child process.

**Since**: 12

**Parameters**

| Name| Description|
| -- | -- |
| const char* libName | Pointer to the name of the DLL file loaded in the child process. The value cannot be nullptr.|
| [OH_Ability_OnNativeChildProcessStarted](capi-native-child-process-h.md#oh_ability_onnativechildprocessstarted) onProcessStarted | Pointer to the callback function for notifying the child process startup result. The value cannot be nullptr. For details, see [OH_Ability_OnNativeChildProcessStarted](capi-native-child-process-h.md#oh_ability_onnativechildprocessstarted).|

**Returns**

| Type| Description|
| -- | -- |
| int | [NCP_NO_ERROR](capi-native-child-process-h.md#ability_nativechildprocess_errcode): The call is successful, but the actual startup result is notified by the callback function.<br>[NCP_ERR_INVALID_PARAM](capi-native-child-process-h.md#ability_nativechildprocess_errcode): The dynamic library name or callback function pointer is invalid.<br>[NCP_ERR_NOT_SUPPORTED](capi-native-child-process-h.md#ability_nativechildprocess_errcode): The device does not support the creation of native child processes.<br>[NCP_ERR_MULTI_PROCESS_DISABLED](capi-native-child-process-h.md#ability_nativechildprocess_errcode): Multi-process mode is disabled on the device.<br>[NCP_ERR_ALREADY_IN_CHILD](capi-native-child-process-h.md#ability_nativechildprocess_errcode): A process cannot be created in a child process.<br>[NCP_ERR_MAX_CHILD_PROCESSES_REACHED](capi-native-child-process-h.md#ability_nativechildprocess_errcode): The number of native child processes reaches the maximum.<br>For details, see [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode).|

**Reference**

[OH_Ability_OnNativeChildProcessStarted](capi-native-child-process-h.md#oh_ability_onnativechildprocessstarted)

### OH_Ability_CreateNativeChildProcessWithConfigs()

```
Ability_NativeChildProcess_ErrCode OH_Ability_CreateNativeChildProcessWithConfigs(const char* libName,Ability_ChildProcessConfigs* configs, OH_Ability_OnNativeChildProcessStarted onProcessStarted)
```

**Description**

Creates a child process based on a child process configuration object and loads the specified DLL file. The startup result is asynchronously communicated to the caller via a callback. The callback runs in a separate thread. You must ensure thread synchronization and avoid time-consuming operations to prevent delays.

The DLL specified must implement and export the following functions:<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_CreateNativeChildProcessWithConfigs(libName, configs, onProcessStartedCallback)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>Parent process:<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>Child process:<br>8. The child process exits after the NativeChildProcess_MainProc() function is returned.

> **NOTE**
>
> Currently, only 2-in-1 devices and tablets are supported.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const char* libName | Pointer to the name of the DLL file loaded in the child process. The value cannot be nullptr.|
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | Pointer to a child process configuration object. The value cannot be nullptr.|
| [OH_Ability_OnNativeChildProcessStarted](capi-native-child-process-h.md#oh_ability_onnativechildprocessstarted) onProcessStarted | Pointer to the callback function for notifying the child process startup result. The value cannot be nullptr. For details, see **OH_Ability_OnNativeChildProcessStarted**.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_ERR_INVALID_PARAM**: An input parameter is invalid.<br>**NCP_ERR_NOT_SUPPORTED**: The device does not support the creation of native child processes.<br>**NCP_ERR_MULTI_PROCESS_DISABLED**: Multi-process mode is disabled on the device, and the child process cannot be started.<br>**NCP_ERR_ALREADY_IN_CHILD**: A process cannot be created in a child process.<br>**NCP_ERR_MAX_CHILD_PROCESSES_REACHED**: The maximum number of native child processes has been reached.<br>For details about the error codes, see **Ability_NativeChildProcess_ErrCode**.|

**Reference**

[OH_Ability_OnNativeChildProcessStarted](capi-native-child-process-h.md#oh_ability_onnativechildprocessstarted)

### OH_Ability_StartNativeChildProcess()

```
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(const char* entry, NativeChildProcess_Args args,NativeChildProcess_Options options, int32_t *pid)
```

**Description**

Starts a native child process, loads the specified DLL file, and calls the entry function. The specified DLL must implement and export a function that accepts [NativeChildProcess_Args](capi-nativechildprocess-args.md) as its parameter (you can customize the function name). Arguments can be passed to the child process. The ArkTS basic runtime environment cannot be created in the child process.

The following is an example:<br>void Main(NativeChildProcess_Args args);<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_StartNativeChildProcess(entryPoint, args, options)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. The child process exits after the Main(args) function returns.

> **NOTE**
>
> Starting from API version 14, 2-in-1 devices and tablets are supported. In API version 13 and earlier versions, only 2-in-1 devices are supported.

**Since**: 13

**Parameters**

| Name| Description|
| -- | -- |
| const char* entry | Pointer to the DDL and entry function to be loaded by the child process, for example, **libEntry.so:Main**. The value cannot be nullptr.|
| [NativeChildProcess_Args](capi-nativechildprocess-args.md) args | Parameters passed to the child process.|
| [NativeChildProcess_Options](capi-nativechildprocess-options.md) options | Child process options.|
| int32_t *pid | Pointer to the ID of the child process.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_ERR_INVALID_PARAM**: The dynamic library name or callback function pointer is invalid.<br>**NCP_ERR_NOT_SUPPORTED**: The device does not support the creation of native child processes.<br> **NCP_ERR_ALREADY_IN_CHILD**: Multi-process mode is disabled on the device.<br>**NCP_ERR_MAX_CHILD_PROCESSES_REACHED**: The maximum number of native child processes has been reached.<br>For details about the error codes, see **Ability_NativeChildProcess_ErrCode**.|

**Reference**

[OH_Ability_OnNativeChildProcessStarted](capi-native-child-process-h.md#oh_ability_onnativechildprocessstarted)

### OH_Ability_StartNativeChildProcessWithConfigs()

```
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcessWithConfigs(const char* entry, NativeChildProcess_Args args, Ability_ChildProcessConfigs* configs, int32_t *pid)
```

**Description**

Starts a native child process based on the child process configuration object, loads the specified DLL file, and calls the entry function. Arguments can be passed to the child process. The specified DLL must implement and export a function that accepts [NativeChildProcess_Args](capi-nativechildprocess-args.md) as its parameter (you can customize the function name).

The following is an example:<br>void Main(NativeChildProcess_Args args);<br>The processing logic sequence is shown in the following pseudocode:<br>Parent process:<br>1. OH_Ability_StartNativeChildProcessWithConfigs(entryPoint, args, configs, &pid)<br>Child process:<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. The child process exits after the Main(args) function returns.

> **NOTE**
>
> Currently, only 2-in-1 devices and tablets are supported.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| const char* entry | Pointer to the symbol and entry function of the DDL called in the child process, separated by a colon (:), for example, **libentry.so:Main**. The value cannot be nullptr.|
| [NativeChildProcess_Args](capi-nativechildprocess-args.md) args | Parameters passed to the child process.|
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | Pointer to a child process configuration object.|
| int32_t *pid | Pointer to the ID of the child process.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_ERR_INVALID_PARAM**: An input parameter is invalid.<br>**NCP_ERR_NOT_SUPPORTED**: The device does not support the creation of native child processes.<br>**NCP_ERR_ALREADY_IN_CHILD**: A process cannot be created in a child process.<br>**NCP_ERR_MAX_CHILD_PROCESSES_REACHED**: The maximum number of native child processes has been reached.<br>For details about the error codes, see **Ability_NativeChildProcess_ErrCode**.|

### OH_Ability_GetCurrentChildProcessArgs()

```
NativeChildProcess_Args* OH_Ability_GetCurrentChildProcessArgs()
```

**Description**

Used by a child process, after being started by calling [OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess), to obtain the startup parameter [NativeChildProcess_Args](capi-nativechildprocess-args.md) from any .so file or child thread.

> **NOTE**
>
> Currently, only 2-in-1 devices and tablets are supported.

**Since**: 17

**Returns**

| Type                          | Description|
|------------------------------| -- |
| [NativeChildProcess_Args](capi-nativechildprocess-args.md)* | Pointer to the startup parameters of the child process.|

### OH_Ability_OnNativeChildProcessExit()

```
typedef void (*OH_Ability_OnNativeChildProcessExit)(int32_t pid, int32_t signal)
```

**Description**

Defines a callback to listen for child process exit.

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| int32_t pid | Pointer to the ID of the child process.|
| int32_t signal | Signal for child process exit.|

**See**

[OH_Ability_RegisterNativeChildProcessExitCallback](#oh_ability_registernativechildprocessexitcallback)

[OH_Ability_UnregisterNativeChildProcessExitCallback](#oh_ability_unregisternativechildprocessexitcallback)

### OH_Ability_RegisterNativeChildProcessExitCallback()

```
Ability_NativeChildProcess_ErrCode OH_Ability_RegisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**Description**

Registers a callback to listen for child process exit. When a child process started by calling [OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess) or [startNativeChildProcess in @ohos.app.ability.childProcessManager](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13) exits abnormally, the callback function is invoked. If the same callback function is registered multiple times, the callback function is executed only once when the child process exits.

The parameter must implement the entry function [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit). For details, see [Registering the Native Child Process Exit Callback Function](../../application-models/capi-nativechildprocess-exit-info.md).

**Since**: 20

**Parameters**

| Name| Description|
| -- | -- |
| [OH_Ability_OnNativeChildProcessExit](capi-native-child-process-h.md#oh_ability_onnativechildprocessexit) onProcessExit | Entry point of the callback function to be called when the child process exits. The value cannot be nullptr.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_ERR_INVALID_PARAM**: An input parameter is invalid.<br>**NCP_ERR_INTERNAL**: An internal error occurs.<br>For details, see **Ability_NativeChildProcess_ErrCode**.|

### OH_Ability_UnregisterNativeChildProcessExitCallback()

```
Ability_NativeChildProcess_ErrCode OH_Ability_UnregisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**Description**

Unregisters the callback used to listen for child process exit.

The parameter must implement the entry function [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit). For details, see [Registering the Native Child Process Exit Callback Function](../../application-models/capi-nativechildprocess-exit-info.md).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_Ability_OnNativeChildProcessExit](capi-native-child-process-h.md#oh_ability_onnativechildprocessexit) onProcessExit | Entry point of the callback function to be called when the child process exits. The value cannot be nullptr.|

**Returns**

| Type| Description|
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](capi-native-child-process-h.md#ability_nativechildprocess_errcode) | **NCP_NO_ERROR**: The call is successful.<br>**NCP_ERR_INVALID_PARAM**: An input parameter is invalid.<br>**NCP_ERR_INTERNAL**: An internal error occurs.<br>**NCP_ERR_CALLBACK_NOT_EXIST**: The callback function is not found.<br>For details, see **Ability_NativeChildProcess_ErrCode**.|
