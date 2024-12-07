# transient_task_api.h


## Overview

The **transient_task_api.h** file declares the APIs for requesting, querying, and canceling transient tasks.

**Library**: libtransient_task.so

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Related module**: [TransientTask](_transient_task.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_BackgroundTaskManager_RequestSuspendDelay](_transient_task.md#oh_backgroundtaskmanager_requestsuspenddelay) (const char \*reason, [TransientTask_Callback](_transient_task.md#transienttask_callback) callback, [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) \*info) | Requests a transient task.| 
| int32_t [OH_BackgroundTaskManager_GetRemainingDelayTime](_transient_task.md#oh_backgroundtaskmanager_getremainingdelaytime) (int32_t requestId, int32_t \*delayTime) | Obtains the remaining time of a transient task.| 
| int32_t [OH_BackgroundTaskManager_CancelSuspendDelay](_transient_task.md#oh_backgroundtaskmanager_cancelsuspenddelay) (int32_t requestId) | Cancels a transient task.| 
