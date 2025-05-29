# JSVM_HeapStatistics


## Overview

Heap statistics struct, which is used to store statistics about JavaScript heap memory usage.

**Since**: 12

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| size_t [totalHeapSize](#totalheapsize) | Total heap size, in KB. | 
| size_t [totalHeapSizeExecutable](#totalheapsizeexecutable) | Total size of the executable heap, in KB. | 
| size_t [totalPhysicalSize](#totalphysicalsize) | Total physical memory size, in KB. | 
| size_t [totalAvailableSize](#totalavailablesize) | Total available memory size, in KB. | 
| size_t [usedHeapSize](#usedheapsize) | Used heap size, in KB. | 
| size_t [heapSizeLimit](#heapsizelimit) | Heap size limit, in KB. | 
| size_t [mallocedMemory](#mallocedmemory) | Allocated memory size, in KB. | 
| size_t [externalMemory](#externalmemory) | External memory size, in KB. | 
| size_t [peakMallocedMemory](#peakmallocedmemory) | Maximum size of the memory that can be allocated, in KB. | 
| size_t [numberOfNativeContexts](#numberofnativecontexts) | Number of active native contexts. If the value keeps increasing, memory leaks may occur. | 
| size_t [numberOfDetachedContexts](#numberofdetachedcontexts) | Number of detached contexts. | 
| size_t [totalGlobalHandlesSize](#totalglobalhandlessize) | Total size of global handles, in KB. | 
| size_t [usedGlobalHandlesSize](#usedglobalhandlessize) | Size of the used global handles, in KB. | 


## Member Variable Description


### externalMemory

```
size_t JSVM_HeapStatistics::externalMemory
```
**Description**
External memory size, in KB.


### heapSizeLimit

```
size_t JSVM_HeapStatistics::heapSizeLimit
```
**Description**
Heap size limit, in KB.


### mallocedMemory

```
size_t JSVM_HeapStatistics::mallocedMemory
```
**Description**
Allocated memory size, in KB.


### numberOfDetachedContexts

```
size_t JSVM_HeapStatistics::numberOfDetachedContexts
```
**Description**
Number of detached contexts.


### numberOfNativeContexts

```
size_t JSVM_HeapStatistics::numberOfNativeContexts
```
**Description**
Number of active native contexts. If the value keeps increasing, memory leaks may occur.


### peakMallocedMemory

```
size_t JSVM_HeapStatistics::peakMallocedMemory
```
**Description**
Maximum size of the memory that can be allocated, in KB.


### totalAvailableSize

```
size_t JSVM_HeapStatistics::totalAvailableSize
```
**Description**
Total available memory size, in KB.


### totalGlobalHandlesSize

```
size_t JSVM_HeapStatistics::totalGlobalHandlesSize
```
**Description**
Total size of global handles, in KB.


### totalHeapSize

```
size_t JSVM_HeapStatistics::totalHeapSize
```
**Description**
Total heap size, in KB.


### totalHeapSizeExecutable

```
size_t JSVM_HeapStatistics::totalHeapSizeExecutable
```
**Description**
Total size of the executable heap, in KB.


### totalPhysicalSize

```
size_t JSVM_HeapStatistics::totalPhysicalSize
```
**Description**
Total physical memory size, in KB.


### usedGlobalHandlesSize

```
size_t JSVM_HeapStatistics::usedGlobalHandlesSize
```
**Description**
Size of the used global handles, in KB.


### usedHeapSize

```
size_t JSVM_HeapStatistics::usedHeapSize
```
**Description**
Used heap size, in KB.
