# mutex.h


## 概述

声明mutex提供的C接口。

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| FFRT_C_API int [ffrt_mutex_init](_f_f_r_t.md#ffrt_mutex_init) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex, const [ffrt_mutexattr_t](ffrt__mutexattr__t.md)\* attr) | 初始化mutex。  | 
| FFRT_C_API int [ffrt_mutex_lock](_f_f_r_t.md#ffrt_mutex_lock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 获取mutex。  | 
| FFRT_C_API int [ffrt_mutex_unlock](_f_f_r_t.md#ffrt_mutex_unlock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 释放mutex。  | 
| FFRT_C_API int [ffrt_mutex_trylock](_f_f_r_t.md#ffrt_mutex_trylock) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 尝试获取mutex。  | 
| FFRT_C_API int [ffrt_mutex_destroy](_f_f_r_t.md#ffrt_mutex_destroy) ([ffrt_mutex_t](ffrt__mutex__t.md)\* mutex) | 销毁mutex。  | 
