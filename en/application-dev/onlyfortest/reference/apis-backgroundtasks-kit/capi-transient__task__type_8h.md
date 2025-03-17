# os_account.h


## Overview

The **os_account.h** file declares the error codes and structs of a transient task.

**Library**: libtransient_task.so

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Related module**: [TransientTask](capi-_transient_task.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[TransientTask_DelaySuspendInfo](capi-_transient_task___delay_suspend_info.md) | Describes the returned information about a transient task.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum TransientTask_ErrorCode TransientTask_ErrorCode | Defines an enum for the error codes available for a transient task.| 
| typedef struct TransientTask_DelaySuspendInfo TransientTask_DelaySuspendInfo | Defines a struct for the returned information about a transient task.| 
| typedef void(\* TransientTask_Callback) (void) | Defines a callback for transient task timeout.| 


### Enums

| Name| Description| 
| -------- | -------- |
| TransientTask_ErrorCode {<br>ERR_TRANSIENT_TASK_OK = 0, ERR_TRANSIENT_TASK_INVALID_PARAM = 401, ERR_TRANSIENT_TASK_PARCEL_FAILED = 9800002, ERR_TRANSIENT_TASK_TRANSACTION_FAILED = 9800003,<br>ERR_TRANSIENT_TASK_SYS_NOT_READY = 9800004, ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED = 9900001, ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED = 9900002<br>} | Enumerates the error codes available for a transient task.| 
