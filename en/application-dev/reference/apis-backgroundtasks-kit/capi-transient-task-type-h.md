# transient_task_type.h

## Overview

The **transient_task_type.h** file declares the error codes and structs of a transient task.

**File to include**: <transient_task/transient_task_type.h>

**Library**: libtransient_task.so

**System capability**: SystemCapability.ResourceSchedule.BackgroundTaskManager.TransientTask

**Since**: 13

**Related module**: [TransientTask](capi-transienttask.md)

## Summary

### Structs

| Name                                                                                      | typedef Keyword| Description|
|------------------------------------------------------------------------------------------| -- | -- |
| [TransientTask_DelaySuspendInfo](capi-transienttask-transienttask-delaysuspendinfo.md)   | TransientTask_DelaySuspendInfo | A struct that describes the returned information about a transient task.|
| [TransientTask_TransientTaskInfo](capi-transienttask-transienttask-transienttaskinfo.md) | TransientTask_TransientTaskInfo | A struct that describes all transient task information.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [TransientTask_ErrorCode](#transienttask_errorcode) | TransientTask_ErrorCode | Enumerates the error codes available for a transient task.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*TransientTask_Callback)(void)](#transienttask_callback) | TransientTask_Callback | Defines a callback for transient task timeout.|

## Enum Description

### TransientTask_ErrorCode

```
enum TransientTask_ErrorCode
```

**Description**

Enumerates the error codes available for a transient task.

**Since**: 13

| Enum| Description|
| -- | -- |
| ERR_TRANSIENT_TASK_OK = 0 | Operation successful.|
| ERR_TRANSIENT_TASK_INVALID_PARAM = 401 | Parameter check failed. Possible causes: 1. Mandatory parameters are not passed. 2. Incorrect parameter types.|
| ERR_TRANSIENT_TASK_PARCEL_FAILED = 9800002 | Parcel read/write operation failed.|
| ERR_TRANSIENT_TASK_TRANSACTION_FAILED = 9800003 | IPC failed.|
| ERR_TRANSIENT_TASK_SYS_NOT_READY = 9800004 | System service failed.|
| ERR_TRANSIENT_TASK_CLIENT_INFO_VERIFICATION_FAILED = 9900001 | Failed to verify the client information of the transient task.|
| ERR_TRANSIENT_TASK_SERVICE_VERIFICATION_FAILED = 9900002 | Failed to verify the server information of the transient task.|
| ERR_TRANSIENT_TASK_PARCELABLE_FAILED = 9900003 | Parcel read/write operation failed for the transient task. Possible causes: 1. The parameter is invalid. 2. Memory allocation fails.|
| ERR_TRANSIENT_TASK_SERVICE_NOT_READY = 9900004 | System service failed for the transient task.|


## Function Description

### TransientTask_Callback()

```
typedef void (*TransientTask_Callback)(void)
```

**Description**

Defines a callback for transient task timeout.

**Since**: 13
