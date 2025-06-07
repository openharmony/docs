# HiDebug_MemoryLimit


## Overview

Defines a struct for the memory limit of an application process.

**Since**: 12

**Related module**: [HiDebug](_hi_debug.md)

**Header file**: [hidebug_type.h](hidebug__type_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint64_t [rssLimit](#rsslimit) | Limit on the resident set size, in KB. | 
| uint64_t [vssLimit](#vsslimit) | Limit on the virtual set size, in KB. | 


## Member Variable Description


### rssLimit

```
uint64_t HiDebug_MemoryLimit::rssLimit
```
**Description**
Limit on the resident set size, in KB.


### vssLimit

```
uint64_t HiDebug_MemoryLimit::vssLimit
```
**Description**
Limit on the virtual set size, in KB.
