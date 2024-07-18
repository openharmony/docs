# JSVM_HeapStatistics

## Overview

The HeapStatistics struct is used to store statistics related to the usage of JavaScript heap memory.

**Starting Version:** 12

**Related Modules:** [JSVM](_j_s_v_m.md)

## Summary

### Member Variables

| Name                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| size_t [totalHeapSize](#totalheapsize)                       | Total heap size in kb.                                       |
| size_t [totalHeapSizeExecutable](#totalheapsizeexecutable)   | Total size of executable heap in kb.                         |
| size_t [totalPhysicalSize](#totalphysicalsize)               | Total physical memory size in kb.                            |
| size_t [totalAvailableSize](#totalavailablesize)             | Total available memory size in kb.                           |
| size_t [usedHeapSize](#usedheapsize)                         | Used heap size in kb.                                        |
| size_t [heapSizeLimit](#heapsizelimit)                       | Heap size limit in kb.                                       |
| size_t [mallocedMemory](#mallocedmemory)                     | Allocated memory size in kb.                                 |
| size_t [externalMemory](#externalmemory)                     | External memory size in kb.                                  |
| size_t [peakMallocedMemory](#peakmallocedmemory)             | Peak allocatable memory size in kb.                          |
| size_t [numberOfNativeContexts](#numberofnativecontexts)     | Indicates the number of currently active native contexts; a continuously increasing value may indicate a memory leak. |
| size_t [numberOfDetachedContexts](#numberofdetachedcontexts) | Indicates the number of detached contexts.                   |
| size_t [totalGlobalHandlesSize](#totalglobalhandlessize)     | Total size of global handles in kb.                          |
| size_t [usedGlobalHandlesSize](#usedglobalhandlessize)       | Size of used global handles in kb.                           |

## Struct Member Variable Descriptions

### externalMemory

```cpp
size_t JSVM_HeapStatistics::externalMemory
```
**Description**
External memory size in kb.

### heapSizeLimit

```cpp
size_t JSVM_HeapStatistics::heapSizeLimit
```
**Description**
Heap size limit in kb.

### mallocedMemory

```cpp
size_t JSVM_HeapStatistics::mallocedMemory
```
**Description**
Allocated memory size in kb.

### numberOfDetachedContexts

```cpp
size_t JSVM_HeapStatistics::numberOfDetachedContexts
```
**Description**
Indicates the number of detached contexts.

### numberOfNativeContexts

```cpp
size_t JSVM_HeapStatistics::numberOfNativeContexts
```
**Description**
Indicates the number of currently active native contexts; a continuously increasing value may indicate a memory leak.

### peakMallocedMemory

```cpp
size_t JSVM_HeapStatistics::peakMallocedMemory
```
**Description**
Peak allocatable memory size in kb.

### totalAvailableSize

```cpp
size_t JSVM_HeapStatistics::totalAvailableSize
```
**Description**
Total available memory size in kb.

### totalGlobalHandlesSize

```cpp
size_t JSVM_HeapStatistics::totalGlobalHandlesSize
```
**Description**
Total size of global handles in kb.

### totalHeapSize

```cpp
size_t JSVM_HeapStatistics::totalHeapSize
```
**Description**
Total heap size in kb.

### totalHeapSizeExecutable

```cpp
size_t JSVM_HeapStatistics::totalHeapSizeExecutable
```
**Description**
Total size of executable heap in kb.

### totalPhysicalSize

```cpp
size_t JSVM_HeapStatistics::totalPhysicalSize
```
**Description**
Total physical memory size in kb.

### usedGlobalHandlesSize

```cpp
size_t JSVM_HeapStatistics::usedGlobalHandlesSize
```
**Description**
Size of used global handles in kb.

### usedHeapSize

```cpp
size_t JSVM_HeapStatistics::usedHeapSize
```
**Description**
Used heap size in kb.