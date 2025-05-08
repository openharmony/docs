# sleep.h


## 概述

声明sleep和yield的C接口。

**引用文件：**&lt;ffrt/sleep.h&gt;

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API int [ffrt_usleep](_f_f_r_t.md#ffrt_usleep) (uint64_t usec) | 睡眠调用线程固定的时间。  | 
| FFRT_C_API void [ffrt_yield](_f_f_r_t.md#ffrt_yield) (void) | 当前任务主动放权，让其他任务有机会调度执行。  | 
