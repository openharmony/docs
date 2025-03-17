# jsvm.h


## Overview

The **transient_task_api.h** file declares the APIs for requesting, querying, and canceling transient tasks.

**Library**: libtransient_task.so

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Related module**: [TransientTask](capi-_transient_task.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t OH_BackgroundTaskManager_RequestSuspendDelay (const char \*reason, TransientTask_Callback callback, TransientTask_DelaySuspendInfo \*info) | Requests a transient task.| 
| int32_t OH_BackgroundTaskManager_GetRemainingDelayTime (int32_t requestId, int32_t \*delayTime) | Obtains the remaining time of a transient task.| 
| int32_t OH_BackgroundTaskManager_CancelSuspendDelay (int32_t requestId) | Cancels a transient task.| 
