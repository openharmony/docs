# ChildProcess


## 概述

提供子进程的管理能力，支持创建Native子进程并在父子进程间建立IPC通道，用于实现多进程应用开发。

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 12


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


### 枚举

| 名称                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               | 描述                |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------- |
| [Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode) {<br>    NCP_NO_ERROR = 0,<br>    NCP_ERR_INVALID_PARAM = 401,<br>    NCP_ERR_NOT_SUPPORTED = 801,<br>    NCP_ERR_INTERNAL = 16000050,<br>    NCP_ERR_BUSY = 16010001,<br>    NCP_ERR_TIMEOUT = 16010002,<br>    NCP_ERR_SERVICE_ERROR = 16010003,<br>    NCP_ERR_MULTI_PROCESS_DISABLED = 16010004,<br>    NCP_ERR_ALREADY_IN_CHILD = 16010005,<br>    NCP_ERR_MAX_CHILD_PROCESSES_REACHED = 16010006,<br>    NCP_ERR_LIB_LOADING_FAILED = 16010007,<br>    NCP_ERR_CONNECTION_FAILED = 16010008<br>} | 定义Native子进程模块错误码。 |


### 函数

| 名称                                                                                                                                                                                                         | 描述                                                                                    |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| int [OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) onProcessStarted) | 创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知，需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。 |

> **说明：**
>
> 当前仅支持2in1设备，且单个进程只能启动一个Native子进程。

## 类型定义说明
### OH_Ability_OnNativeChildProcessStarted

```
typedef void (*OH_Ability_OnNativeChildProcessStarted)(int errCode, OHIPCRemoteProxy *remoteProxy)
```

**描述**

通知子进程启动结果的回调函数。

**起始版本：** 12

**参数:**

| 名称          | 描述                                                                                                                                                                                                                                  |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| errCode     | NCP_NO_ERROR - 创建子进程成功<br>NCP_ERR_LIB_LOADING_FAILED - 加载动态库文件失败或动态库中未实现必要的导出函数<br>NCP_ERR_CONNECTION_FAILED - 动态库中实现的OnConnect方法未返回有效的IPC Stub指针<br>详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)定义。 |
| remoteProxy | 子进程的IPC对象指针，出现异常时可能为nullptr； 使用完毕后需要调用[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)方法释放。                                                                                       |

**参见：**

[OH_Ability_CreateNativeChildProcess](#oh_ability_createnativechildprocess)

[OH_IPCRemoteProxy_Destroy](../apis-ipc-kit/_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy)



## 枚举类型说明

### Ability_NativeChildProcess_ErrCode

```
enum Ability_NativeChildProcess_ErrCode
```

**描述**

定义Native子进程模块错误码。

**起始版本：** 12

| 枚举值                                 | 描述                                              |
| ----------------------------------- | ----------------------------------------------- |
| NCP_NO_ERROR                        | 操作成功。                                           |
| NCP_ERR_INVALID_PARAM               | 无效参数。                                           |
| NCP_ERR_NOT_SUPPORTED               | 不支持创建Native子进程。                                 |
| NCP_ERR_INTERNAL                    | 内部错误。                                           |
| NCP_ERR_BUSY                        | 在Native子进程的启动过程中不能再次创建新的子进程，可以等待当前子进程启动完成后再次尝试。 |
| NCP_ERR_TIMEOUT                     | 启动Native子进程超时。                                  |
| NCP_ERR_SERVICE_ERROR               | 服务端出错。                                          |
| NCP_ERR_MULTI_PROCESS_DISABLED      | 多进程模式已关闭，不允许启动子进程。                              |
| NCP_ERR_ALREADY_IN_CHILD            | 不允许在子进程中再次创建进程。                                 |
| NCP_ERR_MAX_CHILD_PROCESSES_REACHED | 到达最大Native子进程数量限制，不能再创建子进程。                     |
| NCP_ERR_LIB_LOADING_FAILED          | 子进程加载动态库失败，文件不存在或者未实现对应的方法并导出。                  |
| NCP_ERR_CONNECTION_FAILED           | 子进程调用动态库的OnConnect方法失败，可能返回了无效的IPC对象指针。         |


## 函数说明

### OH_Ability_CreateNativeChildProcess

```
int OH_Ability_CreateNativeChildProcess (const char *libName, OH_Ability_OnNativeChildProcessStarted onProcessStarted )
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
> 当前仅支持2in1设备，且单个进程只能启动一个Native子进程。

**起始版本：** 12

**参数**：

| 名称                       | 描述                                                                                                              |
| ------------------------ | --------------------------------------------------------------------------------------------------------------- |
| libName                  | 子进程中加载的动态库文件名称，不能为nullptr。                                                                                      |
| onProcessStartedCallback | 通知子进程启动结果的回调函数指针，不能为nullptr，详见[OH_Ability_OnNativeChildProcessStarted](#oh_ability_onnativechildprocessstarted) |


**返回**：

执行成功返回NCP_NO_ERROR，失败返回错误码，详见[Ability_NativeChildProcess_ErrCode](#ability_nativechildprocess_errcode)。

