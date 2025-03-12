# ffrt_function_header_t


## 概述

任务执行体。

**起始版本：** 10

**相关模块：**[FFRT](_f_f_r_t.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [ffrt_function_t](_f_f_r_t.md#ffrt_function_t) [exec](#exec) | 任务执行函数  | 
| [ffrt_function_t](_f_f_r_t.md#ffrt_function_t) [destroy](#destroy) | 任务销毁函数  | 
| uint64_t [reserve](#reserve) [2] | 保留位需要设置为0  | 


## 结构体成员变量说明


### destroy

```
ffrt_function_t ffrt_function_header_t::destroy
```
**描述**
任务销毁函数


### exec

```
ffrt_function_t ffrt_function_header_t::exec
```
**描述**
任务执行函数


### reserve

```
uint64_t ffrt_function_header_t::reserve[2]
```
**描述**
保留位需要设置为0
