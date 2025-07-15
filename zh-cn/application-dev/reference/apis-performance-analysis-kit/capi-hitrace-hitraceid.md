# HiTraceId

## 概述

HiTraceId定义。

**起始版本：** 12

**相关模块：** [Hitrace](capi-hitrace.md)

**所在头文件：** [trace.h](capi-trace-h.md)

## 汇总

### 成员变量

| 名称                          | 描述              |
|-----------------------------|-----------------|
| uint64_t valid : 1          | HiTraceId是否有效。  |
| uint64_t ver : 3            | HiTraceId的版本号。  |
| uint64_t chainId : 60       | HiTraceId的链Id。  |
| uint64_t flags : 12         | HiTraceId的标志位。  |
| uint64_t spanId : 26        | HiTraceId的当前跨度号。 |
| uint64_t parentSpanId : 26  | HiTraceId的父跨度号。 |
| uint64_t chainId : 60       | HiTraceId的链Id。  |
| uint64_t ver : 3            | HiTraceId的版本号。  |
| uint64_t valid : 1          | HiTraceId是否有效。  |
| uint64_t parentSpanId : 26  | HiTraceId的父跨度号。 |
| uint64_t spanId : 26        | HiTraceId的当前跨度号。 |
| uint64_t flags : 12;     | HiTraceId的标志位。  |   


