# HiCollie_SetTimerParam


## Overview

Defines the input parameters of the **OH_HiCollie_SetTimer** function.

**Since**: 18

**Related module**: [HiCollie](_hi_collie.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| const char \* [name](#name) | Timer task name. | 
| unsigned int [timeout](#timeout) | Task timeout threshold, in seconds. | 
| [OH_HiCollie_Callback](_hi_collie.md#oh_hicollie_callback) [func](#func) | Callback executed when a timeout occurs. | 
| void \* [arg](#arg) | Parameters of the callback. | 
| [HiCollie_Flag](_hi_collie.md#hicollie_flag) [flag](#flag) | Execution to be performed when a timeout occurs. For details, see [HiCollie_Flag](_hi_collie.md#hicollie_flag). | 


## Member Variable Description


### arg

```
void* HiCollie_SetTimerParam::arg
```
**Description**
Parameters of the callback.


### flag

```
HiCollie_Flag HiCollie_SetTimerParam::flag
```
**Description**
Execution to be performed when a timeout occurs. For details, see [HiCollie_Flag](_hi_collie.md#hicollie_flag).


### func

```
OH_HiCollie_Callback HiCollie_SetTimerParam::func
```
**Description**
Callback executed when a timeout occurs.


### name

```
const char* HiCollie_SetTimerParam::name
```
**Description**
Timer task name.


### timeout

```
unsigned int HiCollie_SetTimerParam::timeout
```
**Description**
Task timeout threshold, in seconds.
