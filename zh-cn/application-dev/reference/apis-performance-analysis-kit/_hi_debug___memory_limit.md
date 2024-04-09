# HiDebug_MemoryLimit


## 概述

应用程序进程内存限制结构类型定义。

**起始版本：** 12

**相关模块：**[HiDebug](_hi_debug.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint64_t [rssLimit](#rsslimit) | 应用程序进程驻留集的限制，以KB为单位。  | 
| uint64_t [vssLimit](#vsslimit) | 应用程序进程的虚拟内存限制，以KB为单位。  | 


## 结构体成员变量说明


### rssLimit

```
uint64_t HiDebug_MemoryLimit::rssLimit
```
**描述**
应用程序进程驻留集的限制，以KB为单位。


### vssLimit

```
uint64_t HiDebug_MemoryLimit::vssLimit
```
**描述**
应用程序进程的虚拟内存限制，以KB为单位。
