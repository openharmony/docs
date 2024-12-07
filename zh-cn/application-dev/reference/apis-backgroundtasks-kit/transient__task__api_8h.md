# transient_task_api.h


## 概述

提供短时任务申请、查询、取消功能。

**库：** libtransient_task.so

**系统能力：** SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**起始版本：** 13

**相关模块：**[TransientTask](_transient_task.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_BackgroundTaskManager_RequestSuspendDelay](_transient_task.md#oh_backgroundtaskmanager_requestsuspenddelay) (const char \*reason, [TransientTask_Callback](_transient_task.md#transienttask_callback) callback, [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) \*info) | 申请短时任务。 | 
| int32_t [OH_BackgroundTaskManager_GetRemainingDelayTime](_transient_task.md#oh_backgroundtaskmanager_getremainingdelaytime) (int32_t requestId, int32_t \*delayTime) | 获取本次短时任务的剩余时间。 | 
| int32_t [OH_BackgroundTaskManager_CancelSuspendDelay](_transient_task.md#oh_backgroundtaskmanager_cancelsuspenddelay) (int32_t requestId) | 取消短时任务。 | 