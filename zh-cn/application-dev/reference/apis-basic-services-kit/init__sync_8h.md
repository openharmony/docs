# init_sync.h


## 概述

声明用于向Init进程通知事件的api。

\@kit BasicServicesKit

**系统能力：** SystemCapability.Startup.SystemInfo

**起始版本：** 10

**相关模块：**[InitSync](_init_sync.md)


## 汇总


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
| int [NotifyInit](_init_sync.md#notifyinit) (unsigned long event) | 通知事件到Init进程。 所有进程都可以调用，通常由被监听进程调用。 | 
