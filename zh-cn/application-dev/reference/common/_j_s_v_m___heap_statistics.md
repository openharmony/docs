# JSVM_HeapStatistics


## 概述

Heapstatisics结构体，用于保存有关JavaScript堆内存使用情况的统计信息。

**起始版本：** 12

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [totalHeapSize](#totalheapsize) | 总堆大小，单位kb。  | 
| size_t [totalHeapSizeExecutable](#totalheapsizeexecutable) | 可执行堆的总大小，单位kb。  | 
| size_t [totalPhysicalSize](#totalphysicalsize) | 总的物理内存大小，单位kb。  | 
| size_t [totalAvailableSize](#totalavailablesize) | 总的可用内存大小，单位kb。  | 
| size_t [usedHeapSize](#usedheapsize) | 已使用的堆大小，单位kb。  | 
| size_t [heapSizeLimit](#heapsizelimit) | 堆大小限制，单位kb。  | 
| size_t [mallocedMemory](#mallocedmemory) | 已分配内存的大小，单位kb。  | 
| size_t [externalMemory](#externalmemory) | 外部内存大小，单位kb。  | 
| size_t [peakMallocedMemory](#peakmallocedmemory) | 最大可分配内存的大小，单位kb。  | 
| size_t [numberOfNativeContexts](#numberofnativecontexts) | 表示当前活跃的native上下文的数量，该数值一直增加可能指示存在内存泄漏。  | 
| size_t [numberOfDetachedContexts](#numberofdetachedcontexts) | 表示已经脱离的上下文数量。  | 
| size_t [totalGlobalHandlesSize](#totalglobalhandlessize) | 全局Handle的总大小，单位kb。  | 
| size_t [usedGlobalHandlesSize](#usedglobalhandlessize) | 已经使用的全局Handle的大小，单位kb。  | 


## 结构体成员变量说明


### externalMemory

```
size_t JSVM_HeapStatistics::externalMemory
```
**描述**
外部内存大小，单位kb。


### heapSizeLimit

```
size_t JSVM_HeapStatistics::heapSizeLimit
```
**描述**
堆大小限制，单位kb。


### mallocedMemory

```
size_t JSVM_HeapStatistics::mallocedMemory
```
**描述**
已分配内存的大小，单位kb。


### numberOfDetachedContexts

```
size_t JSVM_HeapStatistics::numberOfDetachedContexts
```
**描述**
表示已经脱离的上下文数量。


### numberOfNativeContexts

```
size_t JSVM_HeapStatistics::numberOfNativeContexts
```
**描述**
表示当前活跃的native上下文的数量，该数值一直增加可能指示存在内存泄漏。


### peakMallocedMemory

```
size_t JSVM_HeapStatistics::peakMallocedMemory
```
**描述**
最大可分配内存的大小，单位kb。


### totalAvailableSize

```
size_t JSVM_HeapStatistics::totalAvailableSize
```
**描述**
总的可用内存大小，单位kb。


### totalGlobalHandlesSize

```
size_t JSVM_HeapStatistics::totalGlobalHandlesSize
```
**描述**
全局Handle的总大小，单位kb。


### totalHeapSize

```
size_t JSVM_HeapStatistics::totalHeapSize
```
**描述**
总堆大小，单位kb。


### totalHeapSizeExecutable

```
size_t JSVM_HeapStatistics::totalHeapSizeExecutable
```
**描述**
可执行堆的总大小，单位kb。


### totalPhysicalSize

```
size_t JSVM_HeapStatistics::totalPhysicalSize
```
**描述**
总的物理内存大小，单位kb。


### usedGlobalHandlesSize

```
size_t JSVM_HeapStatistics::usedGlobalHandlesSize
```
**描述**
已经使用的全局Handle的大小，单位kb。


### usedHeapSize

```
size_t JSVM_HeapStatistics::usedHeapSize
```
**描述**
已使用的堆大小，单位kb。
