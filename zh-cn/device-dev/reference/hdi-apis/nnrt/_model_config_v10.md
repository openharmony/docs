# ModelConfig


## 概述

定义编译模型需要的参数配置。

**起始版本：** 3.2

**相关模块：**[NNRt](_n_n_rt_v10.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| boolean [enableFloat16](#enablefloat16) | float32浮点模型是否以float16浮点运行  | 
| enum [PerformanceMode](_n_n_rt_v10.md#performancemode)[mode](#mode) | 计算任务的性能模式，性能模式定义请查看[PerformanceMode](_n_n_rt_v10.md#performancemode) | 
| enum [Priority](_n_n_rt_v10.md#priority)[priority](#priority) | 计算任务的优先级，优先级详情请看[Priority](_n_n_rt_v10.md#priority) | 


## 类成员变量说明


### enableFloat16

```
boolean ModelConfig::enableFloat16
```
**描述**

float32浮点模型是否以float16浮点运行


### mode

```
enum PerformanceMode ModelConfig::mode
```
**描述**

计算任务的性能模式，性能模式定义请查看[PerformanceMode](_n_n_rt_v10.md#performancemode)


### priority

```
enum Priority ModelConfig::priority
```
**描述**

计算任务的优先级，优先级详情请看[Priority](_n_n_rt_v10.md#priority)
