# HiDebug_ThreadCpuUsage


## Overview

Defines a struct for the CPU usage of all threads of an application.

**Since**: 12

**Related module**: [HiDebug](_hi_debug.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [threadId](#threadid) | Thread ID. | 
| double [cpuUsage](#cpuusage) | Thread CPU usage, in percentage. | 
| struct HiDebug_ThreadCpuUsage \* [next](#next) | Pointer to the CPU usage of the next thread. | 


## Member Variable Description


### cpuUsage

```
double HiDebug_ThreadCpuUsage::cpuUsage
```
**Description**
Thread CPU usage, in percentage.


### next

```
struct HiDebug_ThreadCpuUsage* HiDebug_ThreadCpuUsage::next
```
**Description**
Pointer to the CPU usage of the next thread.


### threadId

```
uint32_t HiDebug_ThreadCpuUsage::threadId
```
**Description**
Thread ID.
