# HiCollie_SetTimerParam


## 概述

用于设置支持对外SDK接入能力的相关参数。

**起始版本：** 16

**相关模块：**[HiCollie](_hi_hicollie.md)


## 汇总 


### 成员变量

| 名称 | 描述 | 
| -------- | -------- | 
| const char \* [name](#name) | timer名称。 | 
| unsigned int [timeout](#timeout) | timer超时时间阈值，单位秒。  | 
| OH_HiCollie_Callback [func](#func) | 超时发生时执行的回调函数。  | 
| void \* [arg](#arg) | 超时发生时执行的回调函数传参。  | 
| HiCollie_Flag [flag](#flag) | 超时发生时需要执行的操作参数。  | 

## 结构体成员变量说明


### name

```
const char* HiCollie_SetTimerParam::name
```
**描述**
函数执行时长检测定时器任务名称，非空字符指针。


### timeout

```
unsigned int HiCollie_SetTimerParam::timeout
```
**描述**
大于0，单位s，超时时间阈值，当代码或函数执行时长超过此阈值即为超时。


### func

```
OH_HiCollie_Callback HiCollie_SetTimerParam::func
```
**描述**
回调函数，超时发生时执行此函数，可为nullptr。


### arg

```
void* HiCollie_SetTimerParam::arg
```
**描述**
回调函数参数，void*类型，与回调函数func匹配使用。


### flag

```
HiCollie_Flag HiCollie_SetTimerParam::flag
```
**描述**
行为信号，枚举值，决定超时发生后的行为。