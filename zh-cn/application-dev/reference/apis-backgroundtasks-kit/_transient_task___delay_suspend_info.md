# TransientTask_DelaySuspendInfo


## 概述

定义短时任务返回信息结构体。

**起始版本：** 13

**相关模块：**[TransientTask](_transient_task.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [requestId](#requestid) | 短时任务请求ID  | 
| int32_t [actualDelayTime](#actualdelaytime) | 剩余时间（单位：毫秒）  | 


## 结构体成员变量说明


### actualDelayTime

```
int32_t TransientTask_DelaySuspendInfo::actualDelayTime
```
**描述**
剩余时间（单位：毫秒）


### requestId

```
int32_t TransientTask_DelaySuspendInfo::requestId
```
**描述**
短时任务请求ID
