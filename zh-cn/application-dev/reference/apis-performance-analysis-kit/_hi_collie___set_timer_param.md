# HiCollie_SetTimerParam


## 概述

定义OH_HiCollie_SetTimer函数的输入参数。

**起始版本：** 18

**相关模块：**[HiCollie](_hi_collie.md)

**所在头文件：** [hicollie.h](hicollie_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [name](#name) | timer任务名称，非空字符串。 | 
| unsigned int [timeout](#timeout) | 任务超时时间阈值，单位s。  | 
| [OH_HiCollie_Callback](_hi_collie.md#oh_hicollie_callback) [func](#func) | 超时发生时执行的回调函数 (无回调可传nullptr)。  | 
| void \* [arg](#arg) | 回调函数的参数，无类型指针。  | 
| [HiCollie_Flag](_hi_collie.md#hicollie_flag) [flag](#flag) | 超时发生时执行的动作，参考[HiCollie_Flag](_hi_collie.md#hicollie_flag)。  | 


## 结构体成员变量说明


### arg

```
void* HiCollie_SetTimerParam::arg
```
**描述**
回调函数的参数。


### flag

```
HiCollie_Flag HiCollie_SetTimerParam::flag
```
**描述**
超时发生时执行的动作，参考[HiCollie_Flag](_hi_collie.md#hicollie_flag)。


### func

```
OH_HiCollie_Callback HiCollie_SetTimerParam::func
```
**描述**
超时发生时执行的回调函数。


### name

```
const char* HiCollie_SetTimerParam::name
```
**描述**
timer任务名称。


### timeout

```
unsigned int HiCollie_SetTimerParam::timeout
```
**描述**
任务超时时间阈值，单位s。
