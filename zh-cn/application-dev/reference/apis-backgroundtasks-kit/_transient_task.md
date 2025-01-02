# TransientTask

## 概述

提供短时任务C接口。

**起始版本：** 13

## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [transient_task_api.h](transient__task__api_8h.md) | 提供短时任务申请、查询、取消功能。  | 
| [transient_task_type.h](transient__task__type_8h.md) | 定义短时任务的错误码和结构体。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) | 定义短时任务返回信息结构体。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [TransientTask_ErrorCode](#transienttask_errorcode)[TransientTask_ErrorCode](#transienttask_errorcode) | 定义短时任务错误码。  | 
| typedef struct [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md)[TransientTask_DelaySuspendInfo](#transienttask_delaysuspendinfo) | 定义短时任务返回信息结构体。  | 
| typedef void(\* [TransientTask_Callback](#transienttask_callback)) (void) | 定义短时任务超时回调类型。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [TransientTask_ErrorCode](#transienttask_errorcode) {<br/>ERR_TRANSIENT_TASK_OK = 0, ERR_TRANSIENT_TASK_INVALID_PARAM = 401, ERR_TRANSIENT_TASK_PARCEL_FAILED = 9800002, ERR_TRANSIENT_TASK_TRANSACTION_FAILED = 9800003,<br/>ERR_TRANSIENT_TASK_SYS_NOT_READY = 9800004, ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED = 9900001, ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED = 9900002<br/>} | 定义短时任务错误码。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_BackgroundTaskManager_RequestSuspendDelay](#oh_backgroundtaskmanager_requestsuspenddelay) (const char \*reason, [TransientTask_Callback](#transienttask_callback) callback, [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) \*info) | 申请短时任务。  | 
| int32_t [OH_BackgroundTaskManager_GetRemainingDelayTime](#oh_backgroundtaskmanager_getremainingdelaytime) (int32_t requestId, int32_t \*delayTime) | 获取本次短时任务的剩余时间。  | 
| int32_t [OH_BackgroundTaskManager_CancelSuspendDelay](#oh_backgroundtaskmanager_cancelsuspenddelay) (int32_t requestId) | 取消短时任务。  | 


## 类型定义说明


### TransientTask_Callback

```
typedef void(* TransientTask_Callback) (void)
```
**描述**
定义短时任务超时回调类型。

**起始版本：** 13


### TransientTask_DelaySuspendInfo

```
typedef struct TransientTask_DelaySuspendInfoTransientTask_DelaySuspendInfo
```
**描述**
定义短时任务返回信息结构体。

**起始版本：** 13


### TransientTask_ErrorCode

```
typedef enum TransientTask_ErrorCodeTransientTask_ErrorCode
```
**描述**
定义短时任务错误码。

**起始版本：** 13


## 枚举类型说明


### TransientTask_ErrorCode

```
enum TransientTask_ErrorCode
```
**描述**
定义短时任务错误码。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| ERR_TRANSIENT_TASK_OK  | \@error 成功。&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_INVALID_PARAM  | \@error 入参错误，比如参数空指针。&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_PARCEL_FAILED  | \@error Parcel读写操作失败。&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_TRANSACTION_FAILED  | \@error IPC通信失败。&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_SYS_NOT_READY  | \@error 系统服务失败。&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED  | \@error 短时任务客户端信息校验失败。&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED  | \@error 短时任务服务端校验失败。&nbsp;&nbsp; | 


## 函数说明


### OH_BackgroundTaskManager_CancelSuspendDelay()

```
int32_t OH_BackgroundTaskManager_CancelSuspendDelay (int32_t requestId)
```
**描述**
取消短时任务。

**系统能力：** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestId | 短时任务的请求ID。  | 

**返回：**

返回0，表示取消成功。 返回401，表示入参错误。 返回9800002，表示Parcel读写操作失败。 返回9800003，表示IPC通信失败。 返回9800004，表示系统服务失败。 返回9900001，表示短时任务客户端信息校验失败。 返回9900002，表示短时任务服务端校验失败。 错误码的具体信息请参考[TransientTask_ErrorCode](#transienttask_errorcode)。


### OH_BackgroundTaskManager_GetRemainingDelayTime()

```
int32_t OH_BackgroundTaskManager_GetRemainingDelayTime (int32_t requestId, int32_t * delayTime )
```
**描述**
获取本次短时任务的剩余时间。

**系统能力：** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| requestId | 短时任务的请求ID。  | 
| time | 短时任务的剩余时间。  | 

**返回：**

返回0，表示查询成功。 返回401，表示入参错误。 返回9800002，表示Parcel读写操作失败。 返回9800003，表示IPC通信失败。 返回9800004，表示系统服务失败。 返回9900001，表示短时任务客户端信息校验失败。 返回9900002，表示短时任务服务端校验失败。 错误码的具体信息请参考[TransientTask_ErrorCode](#transienttask_errorcode)。


### OH_BackgroundTaskManager_RequestSuspendDelay()

```
int32_t OH_BackgroundTaskManager_RequestSuspendDelay (const char * reason, TransientTask_Callback callback, TransientTask_DelaySuspendInfo * info )
```
**描述**
申请短时任务。

**系统能力：** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| reason | 申请短时任务的原因。  | 
| callback | 短时任务即将超时的回调，一般在超时前6秒，通过此回调通知应用。  | 
| delaySuspendInfo | 返回短时任务信息。  | 

**返回：**

返回0，表示申请成功。 返回401，表示入参错误。 返回9800002，表示Parcel读写操作失败。 返回9800003，表示IPC通信失败。 返回9800004，表示系统服务失败。 返回9900001，表示短时任务客户端信息校验失败。 返回9900002，表示短时任务服务端校验失败。 错误码的具体信息请参考[TransientTask_ErrorCode](#transienttask_errorcode)。
