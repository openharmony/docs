# TransientTask

## Overview

The TransientTask module provides C APIs for transient tasks.

**Since**: 13

## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [transient_task_api.h](transient__task__api_8h.md) | Declares the APIs for requesting, querying, and canceling transient tasks. | 
| [transient_task_type.h](transient__task__type_8h.md) | Declares the error codes and structs of a transient task. | 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) | Defines a struct for the returned information about a transient task. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [TransientTask_ErrorCode](#transienttask_errorcode) [TransientTask_ErrorCode](#transienttask_errorcode) | Defines an enum for the error codes available for a transient task. | 
| typedef struct [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md)| Defines a struct for the returned information about a transient task. | 
| typedef void(\* [TransientTask_Callback](#transienttask_callback)) (void) | Defines a callback for transient task timeout. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [TransientTask_ErrorCode](#transienttask_errorcode) {<br>ERR_TRANSIENT_TASK_OK = 0, ERR_TRANSIENT_TASK_INVALID_PARAM = 401, ERR_TRANSIENT_TASK_PARCEL_FAILED = 9800002, ERR_TRANSIENT_TASK_TRANSACTION_FAILED = 9800003,<br>ERR_TRANSIENT_TASK_SYS_NOT_READY = 9800004, ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED = 9900001, ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED = 9900002<br>} | Enumerates the error codes available for a transient task. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_BackgroundTaskManager_RequestSuspendDelay](#oh_backgroundtaskmanager_requestsuspenddelay) (const char \*reason, [TransientTask_Callback](#transienttask_callback) callback, [TransientTask_DelaySuspendInfo](_transient_task___delay_suspend_info.md) \*info) | Requests a transient task. | 
| int32_t [OH_BackgroundTaskManager_GetRemainingDelayTime](#oh_backgroundtaskmanager_getremainingdelaytime) (int32_t requestId, int32_t \*delayTime) | Obtains the remaining time of a transient task. | 
| int32_t [OH_BackgroundTaskManager_CancelSuspendDelay](#oh_backgroundtaskmanager_cancelsuspenddelay) (int32_t requestId) | Cancels a transient task. | 


## Type Description


### TransientTask_Callback

```
typedef void(* TransientTask_Callback) (void)
```
**Description**
Defines a callback for transient task timeout.

**Since**: 13


### TransientTask_DelaySuspendInfo

```
typedef struct TransientTask_DelaySuspendInfo TransientTask_DelaySuspendInfo
```
**Description**
Defines a struct for the returned information about a transient task.

**Since**: 13


### TransientTask_ErrorCode

```
typedef enum TransientTask_ErrorCode TransientTask_ErrorCode
```
**Description**
Defines an enum for the error codes available for a transient task.

**Since**: 13


## Enum Description


### TransientTask_ErrorCode

```
enum TransientTask_ErrorCode
```
**Description**

Enumerates the error codes available for a transient task.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| ERR_TRANSIENT_TASK_OK  | \@error The operation is successful.&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_INVALID_PARAM  | \@error Parameter check fails. Possible causes: 1. Mandatory parameters are not passed. 2. The parameter type is incorrect.&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_PARCEL_FAILED  | \@error Parcel read/write operation failed. &nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_TRANSACTION_FAILED  | \@error IPC failed.&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_SYS_NOT_READY  | \@error The system service fails.&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED  | \@error Failed to verify the client information of the transient task.&nbsp;&nbsp; | 
| ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED  | \@error Failed to verify the server information of the transient task.&nbsp;&nbsp; | 


## Function Description


### OH_BackgroundTaskManager_CancelSuspendDelay()

```
int32_t OH_BackgroundTaskManager_CancelSuspendDelay (int32_t requestId)
```
**Description**
Cancels a transient task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestId | Request ID of the transient task. | 

**Returns**

Returns 0 if the operation is successful.

Returns 401 if the input parameter is incorrect.

Returns 9800002 if the Parcel read/write operation fails.

Returns 9800003 if the IPC fails.

Returns 9800004 if the system service fails.

Returns 9900001 if the client information of the transient task fails to be verified.

Returns 9900002 if the server information of the transient task fails to be verified.

For details about error codes, see [TransientTask_ErrorCode](#transienttask_errorcode).


### OH_BackgroundTaskManager_GetRemainingDelayTime()

```
int32_t OH_BackgroundTaskManager_GetRemainingDelayTime (int32_t requestId, int32_t * delayTime )
```
**Description**
Obtains the remaining time of a transient task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| requestId | Request ID of the transient task. | 
| time | Pointer to the remaining time. | 

**Returns**

Returns 0 if the operation is successful.

Returns 401 if the input parameter is incorrect.

Returns 9800002 if the Parcel read/write operation fails.

Returns 9800003 if the IPC fails.

Returns 9800004 if the system service fails.

Returns 9900001 if the client information of the transient task fails to be verified.

Returns 9900002 if the server information of the transient task fails to be verified.

For details about error codes, see [TransientTask_ErrorCode](#transienttask_errorcode).


### OH_BackgroundTaskManager_RequestSuspendDelay()

```
int32_t OH_BackgroundTaskManager_RequestSuspendDelay (const char * reason, TransientTask_Callback callback, TransientTask_DelaySuspendInfo * info )
```
**Description**
Requests a transient task.

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| reason | Pointer to the reason for requesting the transient task. | 
| callback | Callback used to notify the application that the transient task is about to time out. Generally, the callback is invoked 6 seconds before the timeout. | 
| delaySuspendInfo | Pointer to the information about the transient task. | 

**Returns**

Returns 0 if the operation is successful.

Returns 401 if the input parameter is incorrect.

Returns 9800002 if the Parcel read/write operation fails.

Returns 9800003 if the IPC fails.

Returns 9800004 if the system service fails.

Returns 9900001 if the client information of the transient task fails to be verified.

Returns 9900002 if the server information of the transient task fails to be verified.

For details about error codes, see [TransientTask_ErrorCode](#transienttask_errorcode).