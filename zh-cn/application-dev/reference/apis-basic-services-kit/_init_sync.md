# InitSync


## 概述

提供用于向Init进程通知事件的api。

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [init_sync.h](init__sync_8h.md) | 声明用于向Init进程通知事件的api。 | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| **EVENT1**&nbsp;&nbsp;&nbsp;0xf | 定义事件EVENT1。 | 
| **EVENT1_WAITTIME**&nbsp;&nbsp;&nbsp;10000 | 10000表示EVENT1事件的等待时间为10s。 | 
| **EVENT2**&nbsp;&nbsp;&nbsp;0xf0 | 定义事件EVENT2。 | 
| **EVENT2_WAITTIME**&nbsp;&nbsp;&nbsp;0 | 定义EVENT2_WAITTIME 0表示没有使用QS_STAGE2。 | 
| **EVENT3**&nbsp;&nbsp;&nbsp;0xf00 | 定义事件EVENT3。 | 
| **EVENT3_WAITTIME**&nbsp;&nbsp;&nbsp;0 | 定义EVENT3_WAITTIME 0表示没有使用QS_STAGE3。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int [NotifyInit](#notifyinit) (unsigned long event) | 通知事件到Init进程。 所有进程都可以调用，通常由被监听进程调用。 | 


## 函数说明


### NotifyInit()

```
int NotifyInit (unsigned long event)
```

**描述**

通知事件到Init进程。 所有进程都可以调用，通常由被监听进程调用。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 需要在监听器（init进程）和通知器之间达成一致。 | 

**返回：**

失败时返回-1。
