# HiTraceId

## 概述

HiTraceId定义。

**起始版本：** 12

**相关模块：** [Hitrace](capi-hitrace.md)

**所在头文件：** [trace.h](capi-trace-h.md)

## 汇总

### 成员变量

如果字节顺序为__LITTLE_ENDIAN时，结构体顺序如下表所示：

| 字段 | 字段bit数 | 描述 | 
| -------- | -------- | -------- |
| uint64_t [valid](_hitrace.md#valid) | 1 | HiTraceId是否有效 | 
| uint64_t [ver](_hitrace.md#ver) | 3 | HiTraceId的版本号 | 
| uint64_t [chainId](_hitrace.md#chainid) | 60 | HiTraceId的链Id | 
| uint64_t [flags](_hitrace.md#flags) | 12 | HiTraceId的标志位 | 
| uint64_t [spanId](_hitrace.md#spanid) | 26 | HiTraceId的当前跨度号 | 
| uint64_t [parentSpanId](_hitrace.md#parentspanid) | 26 | HiTraceId的父跨度号 | 

如果字节顺序为__BIG_ENDIAN时，结构体顺序如下表所示：

| 字段 | 字段bit数 | 描述 | 
| -------- | -------- | -------- |
| uint64_t [chainId](_hitrace.md#chainid) | 60 | HiTraceId的链Id | 
| uint64_t [ver](_hitrace.md#ver) | 3 | HiTraceId的版本号 | 
| uint64_t [valid](_hitrace.md#valid) | 1 | HiTraceId是否有效 | 
| uint64_t [parentSpanId](_hitrace.md#parentspanid) | 26 | HiTraceId的父跨度号 | 
| uint64_t [spanId](_hitrace.md#spanid) | 26 | HiTraceId的当前跨度号 | 
| uint64_t [flags](_hitrace.md#flags) | 12 | HiTraceId的标志位 | 



