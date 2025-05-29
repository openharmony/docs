# timer.h


## 概述

声明定时器的C接口。

**引用文件：**&lt;ffrt/timer.h&gt;

**库：** libffrt.z.so 

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 12

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) [ffrt_timer_start](_f_f_r_t.md#ffrt_timer_start) ([ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) qos, uint64_t timeout, void \*data, [ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb) cb, bool repeat) | 启动计时器。  | 
| FFRT_C_API int [ffrt_timer_stop](_f_f_r_t.md#ffrt_timer_stop) ([ffrt_qos_t](_f_f_r_t.md#ffrt_qos_t) qos, [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) handle) | 关闭计时器。  | 
