# transient_task_api.h

## Overview

The **transient_task_api.h** file declares the APIs for requesting, querying, and canceling transient tasks.

**File to include**: <transient_task/transient_task_api.h>

**Library**: libtransient_task.so

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Related module**: [TransientTask](capi-transienttask.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_BackgroundTaskManager_RequestSuspendDelay(const char* reason,TransientTask_Callback callback, TransientTask_DelaySuspendInfo *info)](#oh_backgroundtaskmanager_requestsuspenddelay) | Requests a transient task.|
| [int32_t OH_BackgroundTaskManager_GetRemainingDelayTime(int32_t requestId, int32_t *delayTime)](#oh_backgroundtaskmanager_getremainingdelaytime) | Obtains the remaining time of a transient task.|
| [int32_t OH_BackgroundTaskManager_CancelSuspendDelay(int32_t requestId)](#oh_backgroundtaskmanager_cancelsuspenddelay) | Cancels a transient task.|
| [int32_t OH_BackgroundTaskManager_GetTransientTaskInfo(TransientTask_TransientTaskInfo  *transientTaskInfo)](#oh_backgroundtaskmanager_gettransienttaskinfo) | Obtains all information about a transient task, including the remaining quota of the current day.|

## Function Description

### OH_BackgroundTaskManager_RequestSuspendDelay()

```
int32_t OH_BackgroundTaskManager_RequestSuspendDelay(const char* reason,TransientTask_Callback callback, TransientTask_DelaySuspendInfo *info)
```

**Description**

Requests a transient task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13


**Parameters**

| Name                                                                                         | Description|
|----------------------------------------------------------------------------------------------| -- |
| const char* reason                                                                           | Reason for requesting the transient task.|
| [TransientTask_Callback](capi-transient-task-type-h.md#transienttask_callback) callback      | Callback used to notify the application that the transient task is about to time out. Generally, the callback is invoked 6 seconds before the timeout.|
| [TransientTask_DelaySuspendInfo](capi-transienttask-transienttask-delaysuspendinfo.md) *info | Information about the transient task.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Returns 0 if the operation is successful.<br>         Returns 401 if the input parameter is incorrect.<br>         Returns 9800002 if the Parcel read/write operation fails.<br>         Returns 9800003 if the IPC fails.<br>         Returns 9800004 if the system service fails.<br>         Returns 9900001 if the client information of the transient task fails to be verified.<br>         Returns 9900002 if the server information of the transient task fails to be verified.<br>         For details about the error codes, see [TransientTask_ErrorCode](capi-transient-task-type-h.md#transienttask_errorcode).|

### OH_BackgroundTaskManager_GetRemainingDelayTime()

```
int32_t OH_BackgroundTaskManager_GetRemainingDelayTime(int32_t requestId, int32_t *delayTime)
```

**Description**

Obtains the remaining time of a transient task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| int32_t requestId | Request ID of the transient task.|
| int32_t *delayTime | Pointer to the remaining time.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Returns 0 if the operation is successful.<br>         Returns 401 if the input parameter is incorrect.<br>         Returns 9800002 if the Parcel read/write operation fails.<br>         Returns 9800003 if the IPC fails.<br>         Returns 9800004 if the system service fails.<br>         Returns 9900001 if the client information of the transient task fails to be verified.<br>         Returns 9900002 if the server information of the transient task fails to be verified.<br>         For details about the error codes, see [TransientTask_ErrorCode](capi-transient-task-type-h.md#transienttask_errorcode).|

### OH_BackgroundTaskManager_CancelSuspendDelay()

```
int32_t OH_BackgroundTaskManager_CancelSuspendDelay(int32_t requestId)
```

**Description**

Cancels a transient task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| int32_t requestId | Request ID of the transient task.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Returns 0 if the operation is successful.<br>         Returns 401 if the input parameter is incorrect.<br>         Returns 9800002 if the Parcel read/write operation fails.<br>         Returns 9800003 if the IPC fails.<br>         Returns 9800004 if the system service fails.<br>         Returns 9900001 if the client information of the transient task fails to be verified.<br>         Returns 9900002 if the server information of the transient task fails to be verified.<br>         For details about the error codes, see [TransientTask_ErrorCode](capi-transient-task-type-h.md#transienttask_errorcode).|

### OH_BackgroundTaskManager_GetTransientTaskInfo()

```
int32_t OH_BackgroundTaskManager_GetTransientTaskInfo(TransientTask_TransientTaskInfo  *transientTaskInfo)
```

**Description**

Obtains all information about a transient task, including the remaining quota of the current day.

**Since**: 20


**Parameters**

| Name                                                                                                         | Description                                                                                                     |
|--------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------|
| [TransientTask_TransientTaskInfo ](capi-transienttask-transienttask-transienttaskinfo.md) *transientTaskInfo | All information about a transient task. For details, see [TransientTask_TransientTaskInfo](capi-transienttask-transienttask-transienttaskinfo.md).|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | Returns 0 if the operation is successful.<br>         Returns 9900001 if the client information of the transient task fails to be verified.<br>         Returns 9900003 if the Parcel read/write operation fails.<br>         Returns 9900004 if the system service fails.<br>         For details about the error codes, see [TransientTask_ErrorCode](capi-transient-task-type-h.md#transienttask_errorcode).|
