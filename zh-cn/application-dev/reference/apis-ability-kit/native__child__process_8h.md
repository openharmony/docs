# native_child_process.h


## 概述

支持创建Native子进程，并在父子进程间建立IPC通道。

**库：** libchild_process.so

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**起始版本：** 12

**相关模块：**[ChildProcess](_child_process.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [Ability_NativeChildProcess_ErrCode](_child_process.md#ability_nativechildprocess_errcode)[Ability_NativeChildProcess_ErrCode](_child_process.md#ability_nativechildprocess_errcode) | 定义Native子进程模块错误码。  | 
| typedef void(\* [OH_Ability_OnNativeChildProcessStarted](_child_process.md#oh_ability_onnativechildprocessstarted)) (int errCode, OHIPCRemoteProxy \*remoteProxy) | 定义通知子进程启动结果的回调函数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Ability_NativeChildProcess_ErrCode](_child_process.md#ability_nativechildprocess_errcode) {<br/>[NCP_NO_ERROR](_child_process.md) = 0, [NCP_ERR_INVALID_PARAM](_child_process.md) = 401, [NCP_ERR_NOT_SUPPORTED](_child_process.md) = 801, [NCP_ERR_INTERNAL](_child_process.md) = 16000050,<br/>[NCP_ERR_BUSY](_child_process.md) = 16010001, [NCP_ERR_TIMEOUT](_child_process.md) = 16010002, [NCP_ERR_SERVICE_ERROR](_child_process.md) = 16010003, [NCP_ERR_MULTI_PROCESS_DISABLED](_child_process.md) = 16010004,<br/>[NCP_ERR_ALREADY_IN_CHILD](_child_process.md) = 16010005, [NCP_ERR_MAX_CHILD_PROCESSES_REACHED](_child_process.md) = 16010006, [NCP_ERR_LIB_LOADING_FAILED](_child_process.md) = 16010007, [NCP_ERR_CONNECTION_FAILED](_child_process.md) = 16010008<br/>} | 定义Native子进程模块错误码。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [OH_Ability_CreateNativeChildProcess](_child_process.md#oh_ability_createnativechildprocess) (const char \*libName, [OH_Ability_OnNativeChildProcessStarted](_child_process.md#oh_ability_onnativechildprocessstarted) onProcessStarted) | 创建子进程并加载参数中指定的动态链接库文件，进程启动结果通过回调参数异步通知， 需注意回调通知为独立线程，回调函数实现需要注意线程同步，且不能执行高耗时操作避免长时间阻塞。  | 
