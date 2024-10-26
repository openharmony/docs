# transient_task_type.h


## Overview

The **transient_task_type.h** file declares the error codes and structs of a transient task.

**Library**: libtransient_task.so

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Related module**: [TransientTask](_transient_task.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) | Describes the returned information about a transient task.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [TransientTask_ErrorCode](_transient_task.md#transienttask_errorcode)[TransientTask_ErrorCode](_transient_task.md#transienttask_errorcode) | Defines an enum for the error codes available for a transient task.| 
| typedef struct [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md)[TransientTask_DelaySuspendInfo](_transient_task.md#transienttask_delaysuspendinfo) | Defines a struct for the returned information about a transient task.| 
| typedef void(\* [TransientTask_Callback](_transient_task.md#transienttask_callback)) (void) | Defines a callback for transient task timeout.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [TransientTask_ErrorCode](_transient_task.md#transienttask_errorcode) {<br>[ERR_TRANSIENT_TASK_OK](_transient_task.md) = 0, [ERR_TRANSIENT_TASK_INVALID_PARAM](_transient_task.md) = 401, [ERR_TRANSIENT_TASK_PARCEL_FAILED](_transient_task.md) = 9800002, [ERR_TRANSIENT_TASK_TRANSACTION_FAILED](_transient_task.md) = 9800003,<br>[ERR_TRANSIENT_TASK_SYS_NOT_READY](_transient_task.md) = 9800004, [ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED](_transient_task.md) = 9900001, [ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED](_transient_task.md) = 9900002<br>} | Enumerates the error codes available for a transient task.| 
