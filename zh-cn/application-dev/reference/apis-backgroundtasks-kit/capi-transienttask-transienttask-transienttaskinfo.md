# TransientTask_TransientTaskInfo

## 概述

定义所有短时任务信息结构体。

**起始版本：** 20

**相关模块：** [TransientTask](capi-transienttask.md)

**所在头文件：** [transient_task_type.h](capi-transient-task-type-h.md)

## 汇总

### 成员变量

| 名称                                                                                                                            | 描述 |
|-------------------------------------------------------------------------------------------------------------------------------| -- |
| int32_t remainingQuota                                                                                                        | 当日剩余总配额。单位：毫秒。 |
| [TransientTask_DelaySuspendInfo](capi-transienttask-transienttask-delaysuspendinfo.md) transientTasks [TRANSIENT_TASK_MAX_NUM](#transient_task_max_num) | 已申请的所有短时任务信息。包括短时任务请求ID、剩余时间（单位：毫秒）。 |

## 宏定义说明

### TRANSIENT_TASK_MAX_NUM

```
#define TRANSIENT_TASK_MAX_NUM 3
```
**描述**

同一时刻最大短时任务数量。

**起始版本：** 20
