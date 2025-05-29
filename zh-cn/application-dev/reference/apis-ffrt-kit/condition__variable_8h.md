# condition_variable.h


## 概述

声明条件变量的C接口。

**引用文件：**&lt;ffrt/condition_variable.h&gt;

**库：** libffrt.z.so 

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API int [ffrt_cond_init](_f_f_r_t.md#ffrt_cond_init) ([ffrt_cond_t](ffrt__cond__t.md) \*cond, const [ffrt_condattr_t](ffrt__condattr__t.md) \*attr) | 初始化条件变量。  | 
| FFRT_C_API int [ffrt_cond_signal](_f_f_r_t.md#ffrt_cond_signal) ([ffrt_cond_t](ffrt__cond__t.md) \*cond) | 唤醒阻塞在条件变量上的一个任务。  | 
| FFRT_C_API int [ffrt_cond_broadcast](_f_f_r_t.md#ffrt_cond_broadcast) ([ffrt_cond_t](ffrt__cond__t.md) \*cond) | 唤醒阻塞在条件变量上的所有任务。  | 
| FFRT_C_API int [ffrt_cond_wait](_f_f_r_t.md#ffrt_cond_wait) ([ffrt_cond_t](ffrt__cond__t.md) \*cond, [ffrt_mutex_t](ffrt__mutex__t.md) \*mutex) | 条件变量等待函数，条件变量不满足时阻塞当前任务。  | 
| FFRT_C_API int [ffrt_cond_timedwait](_f_f_r_t.md#ffrt_cond_timedwait) ([ffrt_cond_t](ffrt__cond__t.md) \*cond, [ffrt_mutex_t](ffrt__mutex__t.md) \*mutex, const struct timespec \*time_point) | 条件变量超时等待函数，条件变量不满足时阻塞当前任务，超时等待返回。  | 
| FFRT_C_API int [ffrt_cond_destroy](_f_f_r_t.md#ffrt_cond_destroy) ([ffrt_cond_t](ffrt__cond__t.md) \*cond) | 销毁条件变量。  | 
