# HiDebug_SystemMemInfo


## 概述

系统内存信息结构类型定义。

**起始版本：** 12

**相关模块：**[HiDebug](_hi_debug.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [totalMem](#totalmem) | 系统总的内存，以KB为单位。  | 
| uint32_t [freeMem](#freemem) | 系统空闲的内存，以KB为单位。  | 
| uint32_t [availableMem](#availablemem) | 系统可用的内存，以KB为单位。  | 


## 结构体成员变量说明


### availableMem

```
uint32_t HiDebug_SystemMemInfo::availableMem
```
**描述**
系统可用的内存，以KB为单位。


### freeMem

```
uint32_t HiDebug_SystemMemInfo::freeMem
```
**描述**
系统空闲的内存，以KB为单位。


### totalMem

```
uint32_t HiDebug_SystemMemInfo::totalMem
```
**描述**
系统总的内存，以KB为单位。
