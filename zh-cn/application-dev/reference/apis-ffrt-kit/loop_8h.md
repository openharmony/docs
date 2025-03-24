# loop.h


## 概述

声明循环的C接口。

**引用文件：**&lt;ffrt/condition_variable.h&gt;

**库：** libffrt.z.so

**系统能力：** SystemCapability.Resourceschedule.Ffrt.Core

**起始版本：** 12

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void \* [ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) | loop句柄。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API [ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) [ffrt_loop_create](_f_f_r_t.md#ffrt_loop_create) ([ffrt_queue_t](_f_f_r_t.md#ffrt_queue_t) queue) | 创建loop对象。  | 
| FFRT_C_API int [ffrt_loop_destroy](_f_f_r_t.md#ffrt_loop_destroy) ([ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) loop) | 销毁loop对象。  | 
| FFRT_C_API int [ffrt_loop_run](_f_f_r_t.md#ffrt_loop_run) ([ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) loop) | 开启loop循环。  | 
| FFRT_C_API void [ffrt_loop_stop](_f_f_r_t.md#ffrt_loop_stop) ([ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) loop) | 停止loop循环。  | 
| FFRT_C_API int [ffrt_loop_epoll_ctl](_f_f_r_t.md#ffrt_loop_epoll_ctl) ([ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) loop, int op, int fd, uint32_t events, void \*data, [ffrt_poller_cb](_f_f_r_t.md#ffrt_poller_cb) cb) | 管理loop上的监听事件。  | 
| FFRT_C_API [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) [ffrt_loop_timer_start](_f_f_r_t.md#ffrt_loop_timer_start) ([ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) loop, uint64_t timeout, void \*data, [ffrt_timer_cb](_f_f_r_t.md#ffrt_timer_cb) cb, bool repeat) | 在ffrt loop上启动定时器。  | 
| FFRT_C_API int [ffrt_loop_timer_stop](_f_f_r_t.md#ffrt_loop_timer_stop) ([ffrt_loop_t](_f_f_r_t.md#ffrt_loop_t) loop, [ffrt_timer_t](_f_f_r_t.md#ffrt_timer_t) handle) | 停止ffrt loop定时器。  | 
