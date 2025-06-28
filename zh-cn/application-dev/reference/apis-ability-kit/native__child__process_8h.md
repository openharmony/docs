# native_child_process.h


## 概述

支持创建Native子进程，并在父子进程间建立IPC通道。通过此模块和[childProcessManager](js-apis-app-ability-childProcessManager.md)（非SELF_FORK模式）可以启动的子进程总数最大为512个。

**库**：libchild_process.so

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**起始版本**：12

**相关模块**：[ChildProcess](c-apis-ability-childprocess.md)


## 汇总

### 文件

| 名称                                                     | 描述                                                                                                 |
| ------------------------------------------------------ | -------------------------------------------------------------------------------------------------- |
| [native_child_process.h](native__child__process_8h.md) | 支持创建Native子进程，并在父子进程间建立IPC通道。<br>引用文件：<AbilityKit/native_child_process.h><br>库：libchild_process.so |

### 类型定义

| 名称                                                                                                                                                                             | 描述                |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ----------------- |
| typedef enum Ability_NativeChildProcess_ErrCode [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode)                        | 定义Native子进程模块错误码。 |
| typedef void(\* [OH_Ability_OnNativeChildProcessStarted](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted)) (int errCode, OHIPCRemoteProxy \*remoteProxy) | 定义通知子进程启动结果的回调函数。 |
| typedef void(\* [OH_Ability_OnNativeChildProcessExit](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit)) (int32_t pid, int32_t signal) | 定义感知子进程异常退出的回调函数。 |
| typedef struct [NativeChildProcess_Fd](c-apis-ability-childprocess.md#nativechildprocess_fd) | 定义子进程文件描述符记录。 |
| typedef struct [NativeChildProcess_FdList](c-apis-ability-childprocess.md#nativechildprocess_fdlist) | 定义子进程文件描述符记录链表。 |
| typedef struct [NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args) | 定义启动子进程入参。 |
| typedef struct [NativeChildProcess_Options](c-apis-ability-childprocess.md#nativechildprocess_options) | 定义子进程选项。 |


### 枚举

| 名称                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             | 描述                |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) {<br>    NCP_NO_ERROR = 0,<br>    NCP_ERR_INVALID_PARAM = 401,<br>    NCP_ERR_NOT_SUPPORTED = 801,<br>    NCP_ERR_INTERNAL = 16000050,<br>    NCP_ERR_BUSY = 16010001,<br>    NCP_ERR_TIMEOUT = 16010002,<br>    NCP_ERR_SERVICE_ERROR = 16010003,<br>    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,<br>    NCP_ERR_ALREADY_IN_CHILD = 16010005,<br>    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,<br>    NCP_ERR_LIB_LOADING_FAILED = 16010007,<br>    NCP_ERR_CONNECTION_FAILED = 16010008<br>NCP_ERR_CALLBACK_NOT_EXIST = 16010009<br>} | 定义Native子进程模块错误码。 |
| [NativeChildProcess_IsolationMode](c-apis-ability-childprocess.md#nativechildprocess_isolationmode) {<br>    NCP_ISOLATION_MODE_NORMAL = 0,<br>    NCP_ISOLATION_MODE_ISOLATED = 1,<br>} | 定义子进程独立模式。 |


### 函数

| 名称                                                                                                                                                                                                                                                                     | 描述                                                                                    |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](c-apis-ability-childprocess.md#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | 创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。 <br/><b>说明：</b>当前仅支持2in1设备。从API version 15开始，单个进程最多支持启动50个Native子进程。API version 14及之前版本，单个进程只能启动1个Native子进程。|
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_StartNativeChildProcess](c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)(const char\* entry, [NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args) args, [NativeChildProcess_Options](c-apis-ability-childprocess.md#nativechildprocess_options) options, int32_t *pid) | 启动子进程，加载参数中指定的动态链接库文件并调用入口函数。支持传参到子进程。<br/><b>说明：</b>当前仅支持2in1、tablet设备。|
| [NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args)* [OH_Ability_GetCurrentChildProcessArgs](c-apis-ability-childprocess.md#oh_ability_getcurrentchildprocessargs)() | 通过[OH_Ability_StartNativeChildProcess](c-apis-ability-childprocess.md#oh_ability_startnativechildprocess)启动子进程后，子进程能够在任意so和任意子线程中获取启动参数[NativeChildProcess_Args](c-apis-ability-childprocess.md#nativechildprocess_args)。<br/><b>说明：</b>当前仅支持2in1、tablet设备。|
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_RegisterNativeChildProcessExitCallback](c-apis-ability-childprocess.md#oh_ability_registernativechildprocessexitcallback)([OH_Ability_OnNativeChildProcessExit](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit) onProcessExit) | 注册子进程异常退出回调函数，当子进程异常退出时，能够获取子进程的相关信息。|
| [Ability_NativeChildProcess_ErrCode](c-apis-ability-childprocess.md#ability_nativechildprocess_errcode) [OH_Ability_UnregisterNativeChildProcessExitCallback](c-apis-ability-childprocess.md#oh_ability_unregisternativechildprocessexitcallback)([OH_Ability_OnNativeChildProcessExit](c-apis-ability-childprocess.md#oh_ability_onnativechildprocessexit) onProcessExit) | 解注册子进程异常退出回调函数。|