# TransientTask_TransientTaskInfo


## 概述

定义所有短时任务返回信息结构体。

**起始版本：** 20

**相关模块：**[TransientTask](_transient_task.md)


## 汇总


### 成员变量

| 名称                                                                                             | 描述             | 
|------------------------------------------------------------------------------------------------|----------------|
| int32_t [remainingQuota](#remainingquota)                                                      | 当日剩余总配额。单位：毫秒。 | 
| TransientTask_DelaySuspendInfo [transientTaskInfo[]](#transienttaskinfo) | 已申请的所有短时任务信息。包括短时任务请求ID、剩余时间（单位：毫秒）。   | 


## 结构体成员变量说明


### remainingQuota

```
int32_t TransientTask_TransientTaskInfo::remainingQuota
```
**描述**

当日剩余总配额。单位：毫秒。


### transientTaskInfo[]

```
TransientTask_DelaySuspendInfo TransientTask_TransientTaskInfo::transientTaskInfo[]
```
**描述**

已申请的所有短时任务信息。包括短时任务请求ID、剩余时间（单位：毫秒）。