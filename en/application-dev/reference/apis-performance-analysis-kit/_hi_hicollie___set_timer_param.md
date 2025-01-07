# HiCollie_SetTimerParam


## Overview

Used to set parameters that support SDK access.

**Valid since**: 16

**Related module**: [HiCollie](_hi_hicollie.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- | 
| const char \* [name](#name) | Pointer to the timer name.| 
| unsigned int [timeout](#timeout) | Timeout interval of the timer, in seconds. | 
| OH_HiCollie_Callback [func](#func) | Callback executed when a timeout occurs. | 
| void \* [arg](#arg) | Pointer to the parameter of the callback executed when a timeout occurs. | 
| HiCollie_Flag [flag](#flag) | Operation parameter to be executed when a timeout occurs. | 

## Member Variable Description


### name

```
const char* HiCollie_SetTimerParam::name
```
**Description**
Pointer to the name of the timer for checking the function execution duration.


### timeout

```
unsigned int HiCollie_SetTimerParam::timeout
```
**Description**
Timeout interval, in seconds. If the execution duration of a code or function exceeds the threshold, the code or function times out.


### func

```
OH_HiCollie_Callback HiCollie_SetTimerParam::func
```
**Description**
Callback executed when a timeout occurs. The value can be **nullptr**.


### arg

```
void* HiCollie_SetTimerParam::arg
```
**Description**
Callback parameter, which is of the **void*** type and is used together with the callback **func**.


### flag

```
HiCollie_Flag HiCollie_SetTimerParam::flag
```
**Description**
Behavior flag, which is an enum and determines the behavior after a timeout occurs.
