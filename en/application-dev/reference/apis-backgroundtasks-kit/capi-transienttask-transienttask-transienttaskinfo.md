# TransientTask_TransientTaskInfo

## Overview

A struct that describes all transient task information.

**Since**: 20

**Related module**: [TransientTask](capi-transienttask.md)

**Header file**: [transient_task_type.h](capi-transient-task-type-h.md)

## Summary

### Member Variables

| Name                                                                                                                           | Description|
|-------------------------------------------------------------------------------------------------------------------------------| -- |
| int32_t remainingQuota                                                                                                        | Remaining quota of the current day, in ms.|
| [TransientTask_DelaySuspendInfo](capi-transienttask-transienttask-delaysuspendinfo.md) transientTasks [TRANSIENT_TASK_MAX_NUM](#transient_task_max_num) | All requsted transient task information, including the task request ID and remaining time, in ms.|

## Macro Description

### TRANSIENT_TASK_MAX_NUM

```
#define TRANSIENT_TASK_MAX_NUM 3
```
**Description**

Defines the maximum number of transient tasks at the same time.

**Since**: 20
