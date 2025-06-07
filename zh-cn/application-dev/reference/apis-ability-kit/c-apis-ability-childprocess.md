# ChildProcess


## 概述

提供子进程的管理能力，支持创建Native子进程并在父子进程间建立IPC通道，用于实现多进程应用开发。

创建的子进程不支持UI界面，也不支持Context相关的接口调用。通过此模块和[childProcessManager](js-apis-app-ability-childProcessManager.md)（非SELF_FORK模式）启动的子进程总数最大为512个。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**起始版本**：12


## 汇总


### 文件

| 名称                                                     | 描述                                                                                                     |
| ------------------------------------------------------ | ------------------------------------------------------------------------------------------------------ |
| [native_child_process.h](native__child__process_8h.md) | 支持创建Native子进程，并在父子进程间建立IPC通道。<br>引用文件：<AbilityKit/native_child_process.h><br>库：libchild_process.so<br> |

### 类型定义

| 名称                                                                                                                                               | 描述                |
| ------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------- |
| typedef enum Ability_NativeChildProcess_ErrCode [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)                        | 定义Native子进程模块错误码。 |
| typedef void(\* [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)) (int errCode, OHIPCRemoteProxy \*remoteProxy) | 定义通知子进程启动结果的回调函数。 |
| typedef struct [NativeChildProcess_Fd](#nativechildprocess_fd) | 定义子进程文件描述符记录。 |
| typedef struct [NativeChildProcess_FdList](#nativechildprocess_fdlist) | 定义子进程文件描述符记录链表。 |
| typedef struct [NativeChildProcess_Args](#nativechildprocess_args) | 定义启动子进程入参。 |
| typedef struct [NativeChildProcess_Options](#nativechildprocess_options) | 定义启动子进程的配置选项。 |
| typedef struct [Ability_ChildProcessConfigs](#ability_childprocessconfigs) | 定义启动子进程的配置信息。 |
| typedef void(\* [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit)) (int32_t pid, int32_t signal) | 定义感知Native子进程退出的回调函数。 |

### 枚举

| 名称                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               | 描述                |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) {<br>    NCP_NO_ERROR = 0,<br>    NCP_ERR_INVALID_PARAM = 401,<br>    NCP_ERR_NOT_SUPPORTED = 801,<br>    NCP_ERR_INTERNAL = 16000050,<br>    NCP_ERR_BUSY = 16010001,<br>    NCP_ERR_TIMEOUT = 16010002,<br>    NCP_ERR_SERVICE_ERROR = 16010003,<br>    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,<br>    NCP_ERR_ALREADY_IN_CHILD = 16010005,<br>    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,<br>    NCP_ERR_LIB_LOADING_FAILED = 16010007,<br>    NCP_ERR_CONNECTION_FAILED = 16010008,<br>    NCP_ERR_CALLBACK_NOT_EXIST = 16010009<br>} | 定义Native子进程模块错误码。 |


### 函数

| 名称                                                                                                                                                                                                         | 描述                                                                                    |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted) | 创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。 |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess) (const char\* entry, [NativeChildProcess_Args](#nativechildprocess_args) args, [NativeChildProcess_Options](#nativechildprocess_options) options, int32_t *pid) | 启动一个子进程，并加载指定的库文件。 |
| [Ability_ChildProcessConfigs](#ability_childprocessconfigs)* [OH_Ability_CreateChildProcessConfigs](#oh_ability_createchildprocessconfigs) () | 创建一个子进程配置信息对象。 |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_DestroyChildProcessConfigs](#oh_ability_destroychildprocessconfigs) ([Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs) | 销毁一个子进程配置信息对象，并释放其内存。 |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_ChildProcessConfigs_SetIsolationMode](#oh_ability_childprocessconfigs_setisolationmode) ([Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, [NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode) isolationMode) | 设置子进程配置信息对象的数据沙箱与网络环境的共享模式。该设置仅当调用[OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs)接口时生效。|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_ChildProcessConfigs_SetProcessName](#oh_ability_childprocessconfigs_setprocessname) ([Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, const char\* processName) | 设置子进程配置信息对象中的进程名称。 |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_CreateNativeChildProcessWithConfigs](#oh_ability_createnativechildprocesswithconfigs) (const char\* libName, [Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted) | 根据传入的子进程配置信息创建子进程，并加载参数中指定的动态链接库文件。子进程的启动结果通过回调参数异步通知调用方。该回调在独立线程中执行，需要确保线程同步，且不能执行高耗时操作避免长时间阻塞。|
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs) (const char\* entry, [NativeChildProcess_Args](#nativechildprocess_args) args, [Ability_ChildProcessConfigs](#ability_childprocessconfigs)\* configs, int32_t\* pid) | 根据传入的子进程配置信息启动一个子进程，并加载指定的库文件。 |

> **说明：**
>
> 当前仅支持2in1设备。
> 从API version 15开始，单个进程最多支持启动50个Native子进程。API version 14及之前版本，单个进程只能启动1个Native子进程。

## 类型定义说明
### OH_Ability_OnNativeChildProcessStarted

```
typedef void (*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy)
```

**描述**

通知子进程启动结果的回调函数。

**起始版本**：12

**参数：**

| 名称          | 描述                                                                                                                                                                                                                                  |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| errCode     | NCP_NO_ERROR - 创建子进程成功<br>NCP_ERR_LIB_LOADING_FAILED - 加载动态库文件失败或动态库中未实现必要的导出函数<br>NCP_ERR_CONNECTION_FAILED - 动态库中实现的OnConnect方法未返回有效的IPC Stub指针<br>详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)定义。 |
| remoteProxy | 子进程的IPC对象指针，出现异常时可能为nullptr； 使用完毕后需要调用[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)方法释放。                                                                                       |

**参见：**

[OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess)

[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)

### OH_Ability_OnNativeChildProcessExit

```
typedef void (*OH_Ability_OnNativeChildProcessExit)(int32_t pid, int32_t signal)
```

**描述**

感知Native子进程退出的回调函数。

**起始版本**：20

**参数：**

| 名称          | 描述                                                                                                                                                                                                                                  |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| pid     | 子进程的pid。 |
| signal | 子进程的异常退出信号。                                                                                       |

**参见：**

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

**描述**

子进程文件描述记录。

**起始版本**：13

**参数：**

| 名称          | 描述 |
| ----------- | ------------- |
| fdName     | 文件描述关键字。最大长度为20字符。 |
| fd | 文件描述符句柄。|
| next | 下一个文件描述记录指针。 |

### NativeChildProcess_FdList

```
typedef struct NativeChildProcess_FdList {
    struct NativeChildProcess_Fd* head;
} NativeChildProcess_FdList;
```

**描述**

子进程文件描述记录链表。文件描述符记录个数不能超过16个。

**起始版本**：13

**参数：**

| 名称          | 描述 |
| ----------- | ------------- |
| head     | 子进程文件描述记录链表中的第一个记录，详见[NativeChildProcess_FdList](#nativechildprocess_fdlist)定义。 |

### NativeChildProcess_Args

```
typedef struct NativeChildProcess_Args {
    char* entryParams;
    struct NativeChildProcess_FdList fdList;
} NativeChildProcess_Args;
```

**描述**

启动子进程的入参。

**起始版本**：13

**参数：**

| 名称          | 描述 |
| ----------- | ------------- |
| entryParams     | 入口参数，大小不能超过150KB。 |
| fdList | 子进程文件描述记录链表，详见[NativeChildProcess_FdList](#nativechildprocess_fdlist)定义。 |

### NativeChildProcess_Options

```
typedef struct NativeChildProcess_Options {
    NativeChildProcess_IsolationMode isolationMode;
    int64_t reserved;
} NativeChildProcess_Options;
```

**描述**

启动子进程的配置选项。

**起始版本**：13

**参数：**

| 名称          | 描述 |
| ----------- | ------------- |
| isolationMode     | 进程独立模式，详见[NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode)定义。 |
| reserved | 保留字段。|

### Ability_ChildProcessConfigs

**描述**

启动子进程的配置信息，包括子进程的进程名、以及数据沙箱与网络环境的共享模式。

**起始版本**：20

## 枚举类型说明

### Ability_NativeChildProcess_ErrCode

```
enum Ability_NativeChildProcess_ErrCode
```

**描述**

定义Native子进程模块错误码。

**起始版本**：12

| 枚举值                                 | 描述                                              |
| ----------------------------------- | ----------------------------------------------- |
| NCP_NO_ERROR                        | 操作成功。                                           |
| NCP_ERR_INVALID_PARAM               | 无效参数。                                           |
| NCP_ERR_NOT_SUPPORTED               | 不支持创建Native子进程。                                 |
| NCP_ERR_INTERNAL                    | 内部错误。                                           |
| NCP_ERR_BUSY                        | 在Native子进程的启动过程中不能再次创建新的子进程，可以等待当前子进程启动完成后再次尝试。从API version 15开始被废弃。 |
| NCP_ERR_TIMEOUT                     | 启动Native子进程超时。                                  |
| NCP_ERR_SERVICE_ERROR               | 服务端出错。                                          |
| NCP_ERR_MULTI_PROCESS_DISABLED      | 多进程模式已关闭，不允许启动子进程。                              |
| NCP_ERR_ALREADY_IN_CHILD            | 不允许在子进程中再次创建进程。                                 |
| NCP_ERR_MAX_CHILD_PROCESSES_REACHED | 到达最大Native子进程数量限制，不能再创建子进程。                     |
| NCP_ERR_LIB_LOADING_FAILED          | 子进程加载动态库失败，文件不存在或者未实现对应的方法并导出。                  |
| NCP_ERR_CONNECTION_FAILED           | 子进程调用动态库的OnConnect方法失败，可能返回了无效的IPC对象指针。         |
| NCP_ERR_CALLBACK_NOT_EXIST          | 子进程调用解注册Native子进程退出回调，未找到注册的回调函数。         |

### NativeChildProcess_IsolationMode

```
enum NativeChildProcess_IsolationMode
```

**描述**

定义Native子进程数据沙箱和网络环境的共享模式。

**起始版本**：13

| 枚举值                                 | 描述                                              |
| ----------------------------------- | ----------------------------------------------- |
| NCP_ISOLATION_MODE_NORMAL | 子进程与主进程共享数据沙箱和网络环境。|
| NCP_ISOLATION_MODE_ISOLATED | 子进程与主进程不共享数据沙箱和网络环境。 |

## 函数说明

### OH_Ability_CreateNativeChildProcess

```
int OH_Ability_CreateNativeChildProcess (const char *libName, OH_Ability_OnNativeChildProcessStarted onProcessStarted)
```

**描述**：

创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。

参数所指定的动态库必须实现并导出下列函数：

	1. OHIPCRemoteStub* NativeChildProcess_OnConnect()
	2. void NativeChildProcess_MainProc()

处理逻辑顺序如下列伪代码所示：

	主进程：
	1. OH_Ability_CreateNativeChildProcess(libName, onProcessStartedCallback)
	
	子进程 ：
	2. dlopen(libName)
	3. dlsym("NativeChildProcess_OnConnect")
	4. dlsym("NativeChildProcess_MainProc")
	5. ipcRemote = NativeChildProcess_OnConnect()
	6. NativeChildProcess_MainProc()
	
	主进程 ：
	7. onProcessStartedCallback(ipcRemote, errCode)
	
	子进程 ：
	8. 在NativeChildProcess_MainProc()函数返回后子进程退出。

> **说明：**
>
> 当前仅支持2in1设备。
> 从API version 15开始，单个进程最多支持启动50个Native子进程。API version 14及之前版本，单个进程只能启动1个Native子进程。

**起始版本**：12

**参数**：

| 名称                       | 描述                                                                                                              |
| ------------------------ | --------------------------------------------------------------------------------------------------------------- |
| libName                  | 子进程中加载的动态库文件名称，不能为nullptr。                                                                                      |
| onProcessStarted | 通知子进程启动结果的回调函数指针，不能为nullptr，详见[OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)。 |


**返回**：

执行成功返回NCP_NO_ERROR，失败返回错误码，详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。

### OH_Ability_StartNativeChildProcess

```
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(
    const char* entry, NativeChildProcess_Args args,
    NativeChildProcess_Options options, int32_t *pid)
```

**描述**：

启动Native子进程，加载参数中指定的动态链接库文件并调用入口函数。支持传参到子进程。子进程中不支持创建ArkTS基础运行时环境。

参数所指定的动态库必须实现参数为[NativeChildProcess_Args](#nativechildprocess_args)入口函数并导出。详见[Native子进程开发指导（C/C++）- 创建支持参数传递的子进程](../../application-models/capi_nativechildprocess_development_guideline.md#创建支持参数传递的子进程)。

> **说明：**
>
> 当前仅支持2in1、tablet设备。

**起始版本**：13

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| entry                  | 子进程中调用动态库的符号和入口函数，中间用“:”隔开（例如“libentry.so:Main”)。不能为nullptr。 |
| args | 传给子进程的参数，详见[NativeChildProcess_Args](#nativechildprocess_args)定义。 |
| options |  子进程的启动配置选项，详见[NativeChildProcess_Options](#nativechildprocess_options)定义。 |
| pid | 启动子进程号。 |


**返回**：

执行成功返回NCP_NO_ERROR，失败返回错误码，详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。

### OH_Ability_GetCurrentChildProcessArgs

```
NativeChildProcess_Args* OH_Ability_GetCurrentChildProcessArgs();
```

**描述**：

通过[OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess)启动子进程后，子进程能够在任意so和任意子线程中获取启动参数[NativeChildProcess_Args](#nativechildprocess_args)。

> **说明：**
>
> 当前仅支持2in1、tablet设备。

**起始版本**：17

**返回**：

执行成功返回指向[NativeChildProcess_Args](#nativechildprocess_args)对象的指针，失败返回nullptr。

### OH_Ability_RegisterNativeChildProcessExitCallback

```
Ability_NativeChildProcess_ErrCode OH_Ability_RegisterNativeChildProcessExitCallback(
    OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**描述**：

注册Native子进程异常退出回调函数，当通过[OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess)和[@ohos.app.ability.childProcessManager的startNativeChildProcess](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)启动的子进程异常退出时，调用入口参数的回调函数。当重复注册同一个回调函数时，子进程退出时只会执行一次回调函数。

参数必须实现[OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit)入口函数。详见[注册Native子进程退出回调](../../application-models/capi-nativechildprocess-exit-info.md)。

**起始版本**：20

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| onProcessExit                  | 子进程退出时的回调函数地址。不能为nullptr。 |

**返回**：

执行成功返回NCP_NO_ERROR，失败返回错误码，详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。

### OH_Ability_UnregisterNativeChildProcessExitCallback

```
Ability_NativeChildProcess_ErrCode OH_Ability_UnregisterNativeChildProcessExitCallback(
    OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**描述**：

解注册Native子进程异常退出回调函数。

参数必须实现[OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit)入口函数。详见[解注册Native子进程退出回调](../../application-models/capi-nativechildprocess-exit-info.md)。

**起始版本**：20

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| onProcessExit                  | 子进程退出时的回调函数地址。不能为nullptr。 |


**返回**：

执行成功返回NCP_NO_ERROR，失败返回错误码，详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。

### OH_Ability_CreateChildProcessConfigs

```
Ability_ChildProcessConfigs* OH_Ability_CreateChildProcessConfigs();
```

**描述：**

创建一个子进程配置信息对象。创建对象成功后需要通过调用[OH_Ability_DestroyChildProcessConfigs](#oh_ability_destroychildprocessconfigs)来销毁对象从而避免内存泄漏。

**起始版本**：20

**返回**：

返回一个指向[Ability_ChildProcessConfigs](#ability_childprocessconfigs)对象的指针 - 子进程配置信息对象创建成功。  
返回nullptr - 发生内部错误或者内存分配失败。

### OH_Ability_DestroyChildProcessConfigs

```
Ability_NativeChildProcess_ErrCode OH_Ability_DestroyChildProcessConfigs(Ability_ChildProcessConfigs* configs);
```

**描述**

销毁一个子进程配置信息对象，并释放其内存，在调用该接口后，要避免继续使用已销毁的configs对象。

**起始版本**：20

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| configs | 子进程的配置信息对象指针，详见[Ability_ChildProcessConfigs](#ability_childprocessconfigs)定义。在调用该接口后，对象指针将失效，避免继续使用该指针。允许传入空指针，空指针不会触发任何操作。|

**返回**：

NCP_NO_ERROR - 对象销毁成功。 

NCP_ERR_INVALID_PARAM - 传入参数为nullptr。 

错误码详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。


### OH_Ability_ChildProcessConfigs_SetIsolationMode

```
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationMode(
    Ability_ChildProcessConfigs* configs, NativeChildProcess_IsolationMode isolationMode);
```

**描述**

设置子进程配置信息对象的数据沙箱与网络环境的共享模式。该设置仅当调用[OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs)接口时生效。

**起始版本**：20

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| configs | 子进程的配置信息对象指针，详见[Ability_ChildProcessConfigs](#ability_childprocessconfigs)定义。 |
| isolationMode | 要设置的数据沙箱与网络环境的共享模式， 详见[NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode)定义。|

**返回**：

NCP_NO_ERROR - 执行成功。 

NCP_ERR_INVALID_PARAM - 传入参数configs为nullptr。 

错误码详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。

### OH_Ability_ChildProcessConfigs_SetProcessName

```
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetProcessName(Ability_ChildProcessConfigs* configs, const char* processName);
```

**描述**

设置子进程配置信息对象中的进程名称。

**起始版本**：20

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| configs | 子进程的配置信息对象指针，详见[Ability_ChildProcessConfigs](#ability_childprocessconfigs)定义。不能为空指针。 |
| processName | 设置的进程名称字符串，必须是非空字符串，并且只能由字母、数字和下划线构成，最大长度为64字符，最终的进程名是{bundleName}:{processName}。|

**返回**：

NCP_NO_ERROR - 执行成功。 

NCP_ERR_INVALID_PARAM - 传入参数configs为nullptr，或者processName包含除字母、数字、下划线以外的字符。  

错误码详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。


### OH_Ability_CreateNativeChildProcessWithConfigs

```
 Ability_NativeChildProcess_ErrCode OH_Ability_CreateNativeChildProcessWithConfigs(const char* libName,
    Ability_ChildProcessConfigs* configs, OH_Ability_OnNativeChildProcessStarted onProcessStarted);
```

**描述**

根据传入的子进程配置信息创建子进程，并加载参数中指定的动态链接库文件。子进程的启动结果通过回调参数异步通知调用方。该回调在独立线程中执行，需要确保线程同步，且不能执行高耗时操作避免长时间阻塞。

参数所指定的动态库必须实现并导出下列函数：

	1. OHIPCRemoteStub* NativeChildProcess_OnConnect()
	2. void NativeChildProcess_MainProc()

处理逻辑顺序如下列伪代码所示：

	主进程：
	1. OH_Ability_CreateNativeChildProcessWithConfigs(libName, configs, onProcessStartedCallback)
	
	子进程 ：
	2. dlopen(libName)
	3. dlsym("NativeChildProcess_OnConnect")
	4. dlsym("NativeChildProcess_MainProc")
	5. ipcRemote = NativeChildProcess_OnConnect()
	6. NativeChildProcess_MainProc()
	
	主进程 ：
	7. onProcessStartedCallback(ipcRemote, errCode)
	
	子进程 ：
	8. 在NativeChildProcess_MainProc()函数返回后子进程退出。

> **说明：**
>
> 当前仅支持2in1、tablet设备。

**起始版本**：20

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| libName                  | 子进程中加载的动态库文件名称，不能为nullptr。|
| configs | 子进程的配置信息参数，不能为nullptr，详见[Ability_ChildProcessConfigs](#ability_childprocessconfigs)定义。 |
| onProcessStarted |  通知子进程启动结果的回调函数指针，不能为nullptr，详见[OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)。 |

**返回**：

NCP_NO_ERROR - 执行成功。 

NCP_ERR_INVALID_PARAM - 传入参数无效。 

NCP_ERR_NOT_SUPPORTED - 当前设备不支持创建Native子进程。 

NCP_ERR_MULTI_PROCESS_DISABLED - 当前设备已关闭多进程模式，不允许启动子进程。 

NCP_ERR_ALREADY_IN_CHILD - 不允许在子进程中再次创建子进程。 

NCP_ERR_MAX_CHILD_PROCESSES_REACHED - 超过最大Native子进程数量限制。 

错误码详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。

### OH_Ability_StartNativeChildProcessWithConfigs

```
 Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcessWithConfigs(
    const char* entry, NativeChildProcess_Args args, Ability_ChildProcessConfigs* configs, int32_t *pid);
```

**描述**：

根据参数中子进程配置信息启动Native子进程，加载参数中指定的动态链接库文件并调用入口函数。支持传参到子进程。

参数所指定的动态库必须实现参数为[NativeChildProcess_Args](#nativechildprocess_args)的入口函数并导出，详见[Native子进程开发指导（C/C++）- 创建支持参数传递的子进程](../../application-models/capi_nativechildprocess_development_guideline.md#创建支持参数传递的子进程)。示例如下：

    1. void Main(NativeChildProcess_Args args);

处理逻辑顺序如下列伪代码所示：

	主进程：
	1. OH_Ability_StartNativeChildProcessWithConfigs(entryPoint, args, configs, &pid)
	
	子进程：
	2. dlopen(libName)
	3. dlsym("Main")
	4. Main(args)
	5. 子进程在函数Main(args)返回后退出

> **说明：**
>
> 当前仅支持2in1、tablet设备。

**起始版本**：20

**参数**：

| 名称                       | 描述 |
| ---------------------- | ---------------- |
| entry                  | 子进程中调用动态库的符号和入口函数，中间用“:”隔开（例如“libentry.so:Main”)，不能为nullptr。 |
| args | 传给子进程的参数，详见[NativeChildProcess_Args](#nativechildprocess_args)定义。 |
| configs |  子进程的配置信息参数，详见[Ability_ChildProcessConfigs](#ability_childprocessconfigs)定义。 |
| pid | 被启动的子进程号。 |

**返回**：

NCP_NO_ERROR - 执行成功。 

NCP_ERR_INVALID_PARAM - 传入参数无效。 

NCP_ERR_NOT_SUPPORTED - 当前设备不支持创建Native子进程。 

NCP_ERR_ALREADY_IN_CHILD - 不允许在子进程中再次创建子进程。 

NCP_ERR_MAX_CHILD_PROCESSES_REACHED - 超过最大Native子进程数量限制。 

错误码详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。