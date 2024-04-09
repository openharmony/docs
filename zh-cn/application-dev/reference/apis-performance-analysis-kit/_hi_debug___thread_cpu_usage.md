# HiDebug_ThreadCpuUsage


## 概述

应用程序所有线程的CPU使用率结构体定义。

**起始版本：** 12

**相关模块：**[HiDebug](_hi_debug.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [threadId](#threadid) | 线程ID。  | 
| double [cpuUsage](#cpuusage) | 线程CPU使用率百分比。  | 
| struct HiDebug_ThreadCpuUsage \* [next](#next) | 下一个线程的使用率信息。  | 


## 结构体成员变量说明


### cpuUsage

```
double HiDebug_ThreadCpuUsage::cpuUsage
```
**描述**
线程CPU使用率百分比。


### next

```
struct HiDebug_ThreadCpuUsage* HiDebug_ThreadCpuUsage::next
```
**描述**
下一个线程的使用率信息。


### threadId

```
uint32_t HiDebug_ThreadCpuUsage::threadId
```
**描述**
线程ID。
