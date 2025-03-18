# TransientTask_DelaySuspendInfo


## Overview

The TransientTask_DelaySuspendInfo struct describes the returned information about a transient task.

**Since**: 13

**Related module**: [TransientTask](capi-_transient_task.md)

**Header file**: [os_account.h](capi-transient__task__type_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| int32_t [requestId](#requestid) | Request ID of a transient task. |
| int32_t [actualDelayTime](#actualdelaytime) | Remaining time, in ms. |


## Member Variable Description


### actualDelayTime

```
int32_t TransientTask_DelaySuspendInfo::actualDelayTime
```
**Description**

Remaining time, in ms.


### requestId

```
int32_t TransientTask_DelaySuspendInfo::requestId
```
**Description**

Request ID of a transient task.