# transient_task_type.h


## 概述

定义短时任务的错误码和结构体。

**库：** libtransient_task.so

**系统能力：** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**起始版本：** 13

**相关模块：**[TransientTask](_transient_task.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) | 定义短时任务返回信息结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [TransientTask_ErrorCode](_transient_task.md#transienttask_errorcode) [TransientTask_ErrorCode](_transient_task.md#transienttask_errorcode) | 定义短时任务错误码。 | 
| typedef struct [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) [TransientTask_DelaySuspendInfo](_transient_task.md#transienttask_delaysuspendinfo) | 定义短时任务返回信息结构体。 | 
| typedef void(\* [TransientTask_Callback](_transient_task.md#transienttask_callback)) (void) | 定义短时任务超时回调类型。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [TransientTask_ErrorCode](_transient_task.md#transienttask_errorcode) {<br/>[ERR_TRANSIENT_TASK_OK](_transient_task.md) = 0, [ERR_TRANSIENT_TASK_INVALID_PARAM](_transient_task.md) = 401, [ERR_TRANSIENT_TASK_PARCEL_FAILED](_transient_task.md) = 9800002, [ERR_TRANSIENT_TASK_TRANSACTION_FAILED](_transient_task.md) = 9800003,<br/>[ERR_TRANSIENT_TASK_SYS_NOT_READY](_transient_task.md) = 9800004, [ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED](_transient_task.md) = 9900001, [ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED](_transient_task.md) = 9900002<br/>} | 定义短时任务错误码。 | 
