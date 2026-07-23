# native_child_process.h

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @jsjzju-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

## 概述

支持创建Native子进程，并在父子进程间建立IPC通道，适用于需要将耗时任务、高风险操作或独立业务逻辑隔离到独立进程执行的多种场景。该模块提供了进程隔离、IPC通信、灵活配置等核心能力，可以有效提升应用的稳定性和安全性，避免主进程阻塞或崩溃。通过子进程机制，开发者可以实现多进程架构，将计算密集型任务、媒体处理、网络请求等业务独立运行，提升应用的响应速度和用户体验。

通过此模块和[childProcessManager](js-apis-app-ability-childProcessManager.md)（非SELF_FORK模式）可以启动的子进程总数最大为512个。

**引用文件：** <AbilityKit/native_child_process.h>

**库：** libchild_process.so

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 12

**相关模块：** [ChildProcess](capi-childprocess.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [NativeChildProcess_Fd](capi-nativechildprocess-fd.md) | NativeChildProcess_Fd | 传递给子进程的文件描述符信息。 |
| [NativeChildProcess_FdList](capi-nativechildprocess-fdlist.md) | NativeChildProcess_FdList | 传递给子进程的文件描述符信息列表。文件描述符记录个数不能超过16个。 |
| [NativeChildProcess_Options](capi-nativechildprocess-options.md) | NativeChildProcess_Options | 子进程所使用的选项。 |
| [NativeChildProcess_Args](capi-nativechildprocess-args.md) | NativeChildProcess_Args | 传递给子进程的参数。 |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md) | Ability_ChildProcessConfigs | 启动子进程的配置信息，包括子进程的进程名、以及数据沙箱与网络环境的共享模式。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | Ability_NativeChildProcess_ErrCode | 定义Native子进程模块错误码。 |
| [NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode) | NativeChildProcess_IsolationMode | 定义Native子进程数据沙箱与网络环境的共享模式。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Ability_ChildProcessConfigs* OH_Ability_CreateChildProcessConfigs()](#oh_ability_createchildprocessconfigs) | - | 创建一个子进程配置信息对象。创建对象成功后需要通过调用[OH_Ability_DestroyChildProcessConfigs](#oh_ability_destroychildprocessconfigs)来销毁对象从而避免内存泄漏。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_DestroyChildProcessConfigs(Ability_ChildProcessConfigs* configs)](#oh_ability_destroychildprocessconfigs) | - | 销毁一个子进程配置信息对象，并释放其内存，在调用该接口后，要避免继续使用已销毁的configs对象。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationMode(Ability_ChildProcessConfigs* configs, NativeChildProcess_IsolationMode isolationMode)](#oh_ability_childprocessconfigs_setisolationmode) | - | 设置子进程配置信息对象的数据沙箱与网络环境的共享模式，详见[NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode)。该设置仅当调用[OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs)、[OH_Ability_CreateNativeChildProcessWithConfigs](#oh_ability_createnativechildprocesswithconfigs)接口时生效。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetProcessName(Ability_ChildProcessConfigs* configs,const char* processName)](#oh_ability_childprocessconfigs_setprocessname) | - | 设置子进程配置信息对象中的进程名称。 |
| [typedef void (\*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy)](#oh_ability_onnativechildprocessstarted) | OH_Ability_OnNativeChildProcessStarted | 通知子进程启动结果的回调函数。 |
| [int OH_Ability_CreateNativeChildProcess(const char* libName,OH_Ability_OnNativeChildProcessStarted onProcessStarted)](#oh_ability_createnativechildprocess) | - | 创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。参数所指定的动态库必须实现并导出下列函数：<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_CreateNativeChildProcess(libName, onProcessStartedCallback)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>主进程：<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>子进程：<br>8. 在NativeChildProcess_MainProc()函数返回后子进程退出。<br>**设备行为差异：** 对于API version 13及之前版本，该接口在PC/2in1中可正常使用，在其他设备中返回[NCP_ERR_NOT_SUPPORTED](#ability_nativechildprocess_errcode)错误码。对于API version 14及之后版本，该接口在PC/2in1、Tablet设备可正常使用，在其他设备中返回[NCP_ERR_NOT_SUPPORTED](#ability_nativechildprocess_errcode)错误码。<br>**说明：** 对于API version 14及之前版本，单个进程只能启动1个Native子进程。从API version 15开始，单个进程最多支持启动50个Native子进程。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_CreateNativeChildProcessWithConfigs(const char* libName,Ability_ChildProcessConfigs* configs, OH_Ability_OnNativeChildProcessStarted onProcessStarted)](#oh_ability_createnativechildprocesswithconfigs) | - | 根据传入的子进程配置信息创建子进程，并加载参数中指定的动态链接库文件。子进程的启动结果通过回调异步通知调用方。该回调在独立线程中执行，需要确保线程同步，且不能执行高耗时操作避免长时间阻塞。参数所指定的动态库必须实现并导出下列函数：<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_CreateNativeChildProcessWithConfigs(libName, configs, onProcessStartedCallback)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>主进程：<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>子进程：<br>8. <br>在NativeChildProcess_MainProc()函数返回后子进程退出。<br>**设备行为差异：** 该接口在PC/2in1、Tablet设备中可正常调用，在其他设备中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(const char* entry, NativeChildProcess_Args args,NativeChildProcess_Options options, int32_t *pid)](#oh_ability_startnativechildprocess) | - | 启动一个Native子进程，并加载指定的动态链接库文件。指定的动态库必须实现一个以NativeChildProcess_Args为参数的函数（函数名称可自定义），并导出该函数。示例如下：<br>1. void Main(NativeChildProcess_Args args);<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_StartNativeChildProcess(entryPoint, args, options)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. 子进程将在Main(args)函数返回后退出。<br>**设备行为差异：** 对于API 13及之前版本，该接口在PC/2in1设备中可正常使用，在其他设备类型中返回[NCP_ERR_NOT_SUPPORTED](#ability_nativechildprocess_errcode)错误码。对于API 14及之后版本，该接口在PC/2in1、Tablet中可正常使用，在其他设备类型中返回[NCP_ERR_NOT_SUPPORTED](#ability_nativechildprocess_errcode)错误码。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcessWithConfigs(const char* entry, NativeChildProcess_Args args, Ability_ChildProcessConfigs* configs, int32_t *pid)](#oh_ability_startnativechildprocesswithconfigs) | - | 根据参数中子进程配置信息启动Native子进程，加载参数中指定的动态链接库文件并调用入口函数。支持传参到子进程。指定的动态库必须实现一个以NativeChildProcess_Args为参数的函数（函数名称可自定义），并导出该函数。示例如下：<br>1. void Main(NativeChildProcess_Args args);<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_StartNativeChildProcessWithConfigs(entryPoint, args, configs, &pid)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. 子进程将在Main(args)函数返回后退出。<br>**设备行为差异：** 该接口在PC/2in1、Tablet设备中可正常调用，在其他设备中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。 |
| [NativeChildProcess_Args* OH_Ability_GetCurrentChildProcessArgs()](#oh_ability_getcurrentchildprocessargs) | - | 子进程获取自身的启动参数。 |
| [typedef void (\*OH_Ability_OnNativeChildProcessExit)(int32_t pid, int32_t signal)](#oh_ability_onnativechildprocessexit) | OH_Ability_OnNativeChildProcessExit | 获取子进程退出信息。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_RegisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)](#oh_ability_registernativechildprocessexitcallback) | - | 注册子进程退出回调。只有[OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess)、[OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs)和[childProcessManager.startNativeChildProcess](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)启动的子进程退出时才会触发所注册的回调函数。重复注册同一个回调函数只会保留一个。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_UnregisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)](#oh_ability_unregisternativechildprocessexitcallback) | - | 解注册子进程退出回调。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationUid(Ability_ChildProcessConfigs* configs, bool isolationUid)](#oh_ability_childprocessconfigs_setisolationuid) | - | 设置子进程配置信息对象的uid是否隔离。该设置仅在NativeChildProcess_IsolationMode为NCP_ISOLATION_MODE_ISOLATED时生效。 |
| [Ability_NativeChildProcess_ErrCode OH_Ability_KillChildProcess(int32_t pid)](#oh_ability_killchildprocess) | - | 终止当前进程创建的子进程。 |
| [OH_Ability_IsNativeChildProcessSupported()](#oh_ability_isnativechildprocesssupported) | - | 查询是否允许调用者在此设备上创建Native子进程。 |

## 枚举类型说明

### Ability_NativeChildProcess_ErrCode

```c
enum Ability_NativeChildProcess_ErrCode
```

**描述**

定义Native子进程模块错误码。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| NCP_NO_ERROR = 0 | 操作成功。 |
| NCP_ERR_INVALID_PARAM = 401 | 无效参数。 请检查传入参数的类型、取值范围和是否是nullptr。|
| NCP_ERR_NOT_SUPPORTED = 801 | 当前设备类型不支持创建Native子进程，请使用其他类型的设备尝试。|
| NCP_ERR_INTERNAL = 16000050 | 内部错误。请重启应用或设备再尝试。 |
| NCP_ERR_BUSY = 16010001 | 在Native子进程的启动过程中不能再次创建新的子进程，可以等待当前子进程启动完成后再次尝试。从API version 15开始被废弃。 |
| NCP_ERR_TIMEOUT = 16010002 | 启动Native子进程超时。可能是系统资源不足或动态库加载耗时过长，请检查系统资源状态，优化动态库加载逻辑。|
| NCP_ERR_SERVICE_ERROR = 16010003 | 服务端出错。请尝试重新执行操作，如问题持续存在请重启应用或设备再尝试。|
| NCP_ERR_MULTI_PROCESS_DISABLED = 16010004 | 多进程模式已关闭，不允许启动子进程。请更换其他类型的设备再尝试。|
| NCP_ERR_ALREADY_IN_CHILD = 16010005 | 不允许在子进程中再次创建进程。请在主进程中创建子进程，避免在子进程中嵌套创建。|
| NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006 | 到达最大Native子进程数量限制，不能再创建子进程。请先终止不需要的子进程后再创建新的子进程。 |
| NCP_ERR_LIB_LOADING_FAILED = 16010007 | 子进程加载动态库失败，文件不存在或者未实现对应的方法并导出。请检查动态库文件路径和名称是否正确，确保动态库实现并导出了对应的方法。|
| NCP_ERR_CONNECTION_FAILED = 16010008 | 子进程调用动态库的OnConnect方法失败，可能返回了无效的IPC对象指针。请检查NativeChildProcess_OnConnect函数的实现，确保返回有效的IPC对象指针。 |
| NCP_ERR_CALLBACK_NOT_EXIST = 16010009 | 父进程调用解注册Native子进程退出回调，未找到注册的回调函数。<br>**起始版本：** 20 |
| NCP_ERR_INVALID_PID = 16010010 | 该进程pid不存在，或并非当前进程的子进程pid，或属于[childProcessManager.startChildProcess](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)接口在SELF_FORK模式下启动的子进程。 <br>**起始版本：** 22|

### NativeChildProcess_IsolationMode

```c
enum NativeChildProcess_IsolationMode
```

**描述**

定义Native子进程数据沙箱与网络环境的共享模式。数据沙箱是进程的文件系统隔离环境，控制进程对文件和数据的访问权限；网络环境是进程的网络访问配置，控制进程的网络连接和通信能力。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| NCP_ISOLATION_MODE_NORMAL = 0 | 普通隔离模式下，父进程与子进程共享同一沙箱环境或网络环境。 |
| NCP_ISOLATION_MODE_ISOLATED = 1 | 在隔离模式下，父进程与子进程不共享同一沙箱环境或网络环境。 |


## 函数说明

### OH_Ability_CreateChildProcessConfigs()

```c
Ability_ChildProcessConfigs* OH_Ability_CreateChildProcessConfigs()
```

**描述**

创建一个子进程配置信息对象。创建对象成功后需要通过调用[OH_Ability_DestroyChildProcessConfigs](#oh_ability_destroychildprocessconfigs)来销毁对象从而避免内存泄漏。

**起始版本：** 20

**返回：**

| 类型                               | 说明 |
|----------------------------------| -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* | 返回一个指向[Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)对象的指针 - 子进程配置信息对象创建成功。<br>         返回nullptr - 发生内部错误或者内存分配失败。 |

### OH_Ability_DestroyChildProcessConfigs()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_DestroyChildProcessConfigs(Ability_ChildProcessConfigs* configs)
```

**描述**

销毁一个子进程配置信息对象，并释放其内存，在调用该接口后，要避免继续使用该指针。

**起始版本：** 20


**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -- | -- | -- | -- |
| configs | [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* | 是 | 需要销毁的子进程配置信息对象指针。在调用该接口后，对象指针将失效，避免继续使用该指针。传入空指针时返回[NCP_ERR_INVALID_PARAM](#ability_nativechildprocess_errcode)错误码。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 操作成功。<br>NCP_ERR_INVALID_PARAM - 传入参数为nullptr。 |

### OH_Ability_ChildProcessConfigs_SetIsolationMode()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationMode(Ability_ChildProcessConfigs* configs, NativeChildProcess_IsolationMode isolationMode)
```

**描述**

设置子进程配置信息对象的数据沙箱与网络环境的共享模式，详见[NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode)。该设置仅当调用[OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs)、[OH_Ability_CreateNativeChildProcessWithConfigs](#oh_ability_createnativechildprocesswithconfigs)接口时生效。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | 子进程的配置信息对象指针。不能为nullptr。 |
| [NativeChildProcess_IsolationMode](#nativechildprocess_isolationmode) isolationMode | 要设置的数据沙箱与网络环境的共享模式。NCP_ISOLATION_MODE_NORMAL适用于父子进程需要共享数据沙箱或网络环境的场景（如需要访问父进程文件、共享网络连接等），NCP_ISOLATION_MODE_ISOLATED适用于需要增强安全隔离的场景（如处理不受信任的数据、运行不受信任的代码等）。如果不设置默认为NCP_ISOLATION_MODE_NORMAL。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 执行成功。<br>NCP_ERR_INVALID_PARAM - 传入参数configs为nullptr。 |

### OH_Ability_ChildProcessConfigs_SetIsolationUid()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetIsolationUid(Ability_ChildProcessConfigs* configs, bool isolationUid)
```

**描述**

设置子进程配置信息对象的uid是否隔离。例如用于浏览器的安全加固场景，设置主进程与子进程的uid隔离。

该设置仅在NativeChildProcess_IsolationMode为NCP_ISOLATION_MODE_ISOLATED时生效。不调用该接口设置isolationUid时，则默认为false，即子进程与主进程拥有相同uid。

**起始版本：** 21


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | 子进程的配置信息对象指针。不能为nullptr。 |
| bool isolationUid | 控制子进程是否使用独立的uid。true表示子进程拥有独立的uid（适用于需要增强安全隔离的场景，如浏览器安全加固、处理不受信任数据等），false表示子进程与主进程拥有相同uid（适用于父子进程需要共享资源的场景）。不调用该接口设置时默认为false。该设置仅在NativeChildProcess_IsolationMode为NCP_ISOLATION_MODE_ISOLATED时生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 执行成功。<br>NCP_ERR_INVALID_PARAM - 传入参数configs为nullptr。 |

### OH_Ability_ChildProcessConfigs_SetProcessName()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_ChildProcessConfigs_SetProcessName(Ability_ChildProcessConfigs* configs,const char* processName)
```

**描述**

设置子进程配置信息对象中的进程名称。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | 子进程的配置信息对象指针。不能为nullptr。 |
| const char* processName | 设置的子进程名字符串必须是非空字符串，并且只能由字母、数字和下划线构成。最大长度为64字符。最终的进程名是{bundleName}:{processName}。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 执行成功。<br>NCP_ERR_INVALID_PARAM - 传入参数configs为nullptr，或者processName包含除字母、数字、下划线以外的字符。 |

### OH_Ability_OnNativeChildProcessStarted()

```c
typedef void (*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy)
```

**描述**

定义通知子进程启动结果的回调函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int errCode | 回调函数返回的错误码，可用的值如下：<br>[NCP_NO_ERROR](#ability_nativechildprocess_errcode) - 创建子进程成功。<br>[NCP_ERR_LIB_LOADING_FAILED](#ability_nativechildprocess_errcode) - 加载动态库文件失败或动态库中未实现必要的导出函数。<br>[NCP_ERR_CONNECTION_FAILED](#ability_nativechildprocess_errcode) - 动态库中实现的OnConnect方法未返回有效的IPC Stub指针。<br>详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)定义。 |
| [OHIPCRemoteProxy](../apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md) *remoteProxy | 子进程的IPC对象指针，出现异常时可能为nullptr：使用完毕后需要调用[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/capi-ipc-cremote-object-h.md#oh_ipcremoteproxy_destroy)方法释放。 |

**参考：**

[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/capi-ipc-cremote-object-h.md#oh_ipcremoteproxy_destroy)

### OH_Ability_CreateNativeChildProcess()

```c
int OH_Ability_CreateNativeChildProcess(const char* libName,OH_Ability_OnNativeChildProcessStarted onProcessStarted)
```

**描述**

创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。

参数所指定的动态库必须实现并导出下列函数：<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_CreateNativeChildProcess(libName, onProcessStartedCallback)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>主进程：<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>子进程：<br>8. 在NativeChildProcess_MainProc()函数返回后子进程退出。

**设备行为差异：** 对于API version 13及之前版本，该接口在PC/2in1中可正常使用，在Tablet设备中返回[NCP_ERR_NOT_SUPPORTED](#ability_nativechildprocess_errcode)错误码，在其他设备中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。对于API version 14及之后版本，该接口在PC/2in1、Tablet设备可正常使用，在其他设备中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。

> **说明：**
>
> API version 14及之前版本，单个进程只能启动1个Native子进程。从API version 15开始，单个进程最多支持启动50个Native子进程。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* libName | 子进程中加载的动态库文件名称，不能为nullptr。 |
| [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted | 通知子进程启动结果的回调函数指针，不能为nullptr。详见[OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int | [NCP_NO_ERROR](#ability_nativechildprocess_errcode) - 调用成功，但子进程的实际启动结果由回调函数通知。<br>[NCP_ERR_INVALID_PARAM](#ability_nativechildprocess_errcode) - 无效的动态库名称或者回调函数指针。<br>[NCP_ERR_NOT_SUPPORTED](#ability_nativechildprocess_errcode) - 当前设备不支持创建Native子进程。<br>[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode) - 当前设备已关闭多进程模式。<br>[NCP_ERR_ALREADY_IN_CHILD](#ability_nativechildprocess_errcode) - 不允许在子进程中再次创建子进程。<br>[NCP_ERR_MAX_CHILD_PROCESSES_REACHED](#ability_nativechildprocess_errcode) - 到达最大Native子进程数限制。<br>详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)定义。 |

**参考：**

[OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)

### OH_Ability_CreateNativeChildProcessWithConfigs()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_CreateNativeChildProcessWithConfigs(const char* libName,Ability_ChildProcessConfigs* configs, OH_Ability_OnNativeChildProcessStarted onProcessStarted)
```

**描述**

根据传入的子进程配置信息创建子进程，并加载参数中指定的动态链接库文件。子进程的启动结果通过回调异步通知调用方。该回调在独立线程中执行，需要确保线程同步，且不能执行高耗时操作避免长时间阻塞。

参数所指定的动态库必须实现并导出下列函数：<br>1. OHIPCRemoteStub* NativeChildProcess_OnConnect()<br>2. void NativeChildProcess_MainProc()<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_CreateNativeChildProcessWithConfigs(libName, configs, onProcessStartedCallback)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("NativeChildProcess_OnConnect")<br>4. dlsym("NativeChildProcess_MainProc")<br>5. ipcRemote = NativeChildProcess_OnConnect()<br>6. NativeChildProcess_MainProc()<br>主进程：<br>7. onProcessStartedCallback(ipcRemote, errCode)<br>子进程：<br>8. 在NativeChildProcess_MainProc()函数返回后子进程退出。

**设备行为差异：** 该接口在PC/2in1、Tablet设备中可正常调用，在其他设备中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* libName | 子进程中加载的动态库文件名称，不能为nullptr。 |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | 子进程的配置信息参数，不能为nullptr。 |
| [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted | 通知子进程启动结果的回调函数指针，不能为nullptr，详见OH_Ability_OnNativeChildProcessStarted。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 执行成功。<br>NCP_ERR_INVALID_PARAM - 传入参数无效。<br>NCP_ERR_NOT_SUPPORTED - 当前设备不支持创建Native子进程。<br>NCP_ERR_MULTI_PROCESS_DISABLED - 当前设备已关闭多进程模式，不允许启动子进程。<br>NCP_ERR_ALREADY_IN_CHILD - 不允许在子进程中再次创建子进程。<br>NCP_ERR_MAX_CHILD_PROCESSES_REACHED - 超过最大Native子进程数限制。<br>详见Ability_NativeChildProcess_ErrCode定义。 |

**参考：**

[OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)

### OH_Ability_StartNativeChildProcess()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcess(const char* entry, NativeChildProcess_Args args,NativeChildProcess_Options options, int32_t *pid)
```

**描述**

启动Native子进程，加载参数中指定的动态链接库文件并调用入口函数。指定的动态库必须实现一个以[NativeChildProcess_Args](capi-nativechildprocess-args.md)为参数的函数（函数名称可自定义），并导出该函数。支持传参到子进程。子进程中不支持创建ArkTS基础运行时环境。

示例如下：<br>void Main(NativeChildProcess_Args args);<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_StartNativeChildProcess(entryPoint, args, options)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. 子进程将在Main(args)函数返回后退出。

**设备行为差异：** 在API version 13及之前，该接口在PC/2in1设备中可正常使用，在其他设备类型中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。从API version 14开始，该接口在PC/2in1、Tablet中可正常使用，在其他设备类型中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* entry | 子进程中加载的动态库及入口函数，例如"libEntry.so:Main"，不能为nullptr。 |
| [NativeChildProcess_Args](capi-nativechildprocess-args.md) args | 传递给子进程的参数。 |
| [NativeChildProcess_Options](capi-nativechildprocess-options.md) options | 子进程选项。 |
| int32_t *pid | 启动的子进程id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 调用成功。<br>NCP_ERR_INVALID_PARAM - 无效的动态库名称或者回调函数指针。<br>NCP_ERR_NOT_SUPPORTED - 当前设备不支持创建Native子进程。<br> NCP_ERR_ALREADY_IN_CHILD - 不允许在子进程中再次创建子进程。<br>NCP_ERR_MAX_CHILD_PROCESSES_REACHED - 到达最大Native子进程数限制。<br>详见Ability_NativeChildProcess_ErrCode定义。 |

**参考：**

[OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted)

### OH_Ability_StartNativeChildProcessWithConfigs()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_StartNativeChildProcessWithConfigs(const char* entry, NativeChildProcess_Args args, Ability_ChildProcessConfigs* configs, int32_t *pid)
```

**描述**

根据参数中的子进程配置信息启动Native子进程，加载指定的动态链接库文件并调用入口函数。支持传参到子进程。指定的动态库必须实现一个以[NativeChildProcess_Args](capi-nativechildprocess-args.md)为参数的函数（函数名称可自定义），并导出该函数。

示例如下：<br>void Main(NativeChildProcess_Args args);<br>处理逻辑顺序如下列伪代码所示：<br>主进程：<br>1. OH_Ability_StartNativeChildProcessWithConfigs(entryPoint, args, configs, &pid)<br>子进程：<br>2. dlopen(libName)<br>3. dlsym("Main")<br>4. Main(args)<br>5. 子进程将在Main(args)函数返回后退出。

**设备行为差异：** 该接口在PC/2in1、Tablet中可正常调用，在其他设备类型中返回[NCP_ERR_MULTI_PROCESS_DISABLED](#ability_nativechildprocess_errcode)错误码。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* entry | 子进程中调用动态库的符号和入口函数，中间用“:”隔开（例如“libentry.so:Main”），不能为nullptr。 |
| [NativeChildProcess_Args](capi-nativechildprocess-args.md) args | 传给子进程的参数。 |
| [Ability_ChildProcessConfigs](capi-ability-childprocessconfigs.md)* configs | 子进程的配置信息参数。 |
| int32_t *pid | 被启动的子进程号。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 执行成功。<br>NCP_ERR_INVALID_PARAM - 传入参数无效。<br>NCP_ERR_NOT_SUPPORTED - 当前设备不支持创建Native子进程。<br>NCP_ERR_ALREADY_IN_CHILD - 不允许在子进程中再次创建子进程。<br>NCP_ERR_MAX_CHILD_PROCESSES_REACHED - 超过最大Native子进程数限制。<br>详见Ability_NativeChildProcess_ErrCode定义。 |

### OH_Ability_GetCurrentChildProcessArgs()

```c
NativeChildProcess_Args* OH_Ability_GetCurrentChildProcessArgs()
```

**描述**

通过[OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess)或[OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs)启动子进程后，子进程能够在任意so和任意子线程中获取启动参数[NativeChildProcess_Args](capi-nativechildprocess-args.md)。参数在子进程启动时传递并存储在进程全局上下文中，生命周期贯穿子进程整个运行期间，可在子进程任意位置随时获取。

**起始版本：** 17

**返回：**

| 类型                           | 说明 |
|------------------------------| -- |
| [NativeChildProcess_Args](capi-nativechildprocess-args.md)* | 返回指向当前子进程启动参数的指针。 |

### OH_Ability_OnNativeChildProcessExit()

```c
typedef void (*OH_Ability_OnNativeChildProcessExit)(int32_t pid, int32_t signal)
```

**描述**

用于获取Native子进程退出信息的回调函数。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t pid | 启动的子进程id。 |
| int32_t signal | 子进程退出信号值，表示子进程的退出原因。常见的信号值包括：1（SIGHUP挂起）、2（SIGINT中断）、9（SIGKILL强制终止）、15（SIGTERM终止）等。 |

**参见：**

[OH_Ability_RegisterNativeChildProcessExitCallback](#oh_ability_registernativechildprocessexitcallback)

[OH_Ability_UnregisterNativeChildProcessExitCallback](#oh_ability_unregisternativechildprocessexitcallback)

### OH_Ability_RegisterNativeChildProcessExitCallback()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_RegisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**描述**

注册Native子进程退出回调函数。只有[OH_Ability_StartNativeChildProcess](#oh_ability_startnativechildprocess)、[OH_Ability_StartNativeChildProcessWithConfigs](#oh_ability_startnativechildprocesswithconfigs)和[childProcessManager.startNativeChildProcess](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartnativechildprocess13)启动的子进程退出时才会触发所注册的回调函数。回调函数在独立线程中执行，触发时机为子进程退出后，signal参数表示子进程退出信号类型。当重复注册同一个回调函数时，子进程退出时只会执行一次回调函数。回调函数实现需要注意线程同步，且不能执行高耗时操作。

参数必须实现[OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit)入口函数。详见[注册Native子进程退出回调](../../application-models/capi-nativechildprocess-exit-info.md)。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit) onProcessExit | 子进程退出的回调函数入口，不能为nullptr。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 调用成功。<br>NCP_ERR_INVALID_PARAM - 传入参数onProcessExit为nullptr或无效。<br>NCP_ERR_INTERNAL - 内部错误。<br>详见Ability_NativeChildProcess_ErrCode。 |

### OH_Ability_UnregisterNativeChildProcessExitCallback()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_UnregisterNativeChildProcessExitCallback(OH_Ability_OnNativeChildProcessExit onProcessExit)
```

**描述**

解注册子进程退出回调。

参数必须实现[OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit)入口函数。详见[解注册Native子进程退出回调](../../application-models/capi-nativechildprocess-exit-info.md)。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Ability_OnNativeChildProcessExit](#oh_ability_onnativechildprocessexit) onProcessExit | 子进程退出的回调函数入口，不能为nullptr。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 调用成功。<br>NCP_ERR_INVALID_PARAM - 参数不合法，传入参数onProcessExit为nullptr或无效。<br>NCP_ERR_INTERNAL - 内部错误。<br>NCP_ERR_CALLBACK_NOT_EXIST - 未找到回调函数。<br>详见Ability_NativeChildProcess_ErrCode。 |

### OH_Ability_KillChildProcess()

```c
Ability_NativeChildProcess_ErrCode OH_Ability_KillChildProcess(int32_t pid)
```

**描述**

终止当前进程创建的子进程。该接口通过发送终止信号强制结束子进程，子进程立即停止执行并退出。终止后子进程资源被系统回收，如已注册退出回调则会被触发。

> **说明：**
>
> 调用该接口无法终止[childProcessManager.startChildProcess](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)接口在SELF_FORK模式下启动的子进程。

**起始版本：** 22


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t pid | 要终止的子进程pid。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) | NCP_NO_ERROR - 调用成功。<br> NCP_ERR_SERVICE_ERROR - 服务端出错。<br>NCP_ERR_INVALID_PID - 所传入的子进程pid不合法。传入的进程pid不存在，或并非当前进程所创建的子进程pid，或属于[childProcessManager.startChildProcess](js-apis-app-ability-childProcessManager.md#childprocessmanagerstartchildprocess)接口在SELF_FORK模式下启动的子进程。<br>详见Ability_NativeChildProcess_ErrCode。 |

### OH_Ability_IsNativeChildProcessSupported()

```c
bool OH_Ability_IsNativeChildProcessSupported()
```

**描述**

查询是否允许调用者在此设备上创建[Native子进程](../../application-models/ability-terminology.md#native子进程)。

**起始版本：** 26.0.0

**返回：**

| 类型 | 说明 |
| -- | -- |
| boolean | 是否允许调用者创建Native子进程。<br>true：允许创建Native子进程。<br>false：不允许创建Native子进程。<br>默认值：false。 |