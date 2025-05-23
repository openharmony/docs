# HiDebug_NativeMemInfo


## Overview

Defines the local memory information of an application.

**Since**: 12

**Related module**: [HiDebug](_hi_debug.md)

**Header file**: [hidebug_type.h](hidebug__type_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [pss](#pss) | Proportional set size, in KB. | 
| uint32_t [vss](#vss) | Virtual memory size, in KB. | 
| uint32_t [rss](#rss) | Resident set size, in KB. | 
| uint32_t [sharedDirty](#shareddirty) | Size of the shared dirty memory, in KB. | 
| uint32_t [privateDirty](#privatedirty) | Size of the private dirty memory, in KB. | 
| uint32_t [sharedClean](#sharedclean) | Size of the shared clean memory, in KB. | 
| uint32_t [privateClean](#privateclean) | Size of the private clean memory, in KB. | 


## Member Variable Description


### privateClean

```
uint32_t HiDebug_NativeMemInfo::privateClean
```
**Description**
Size of the private clean memory, in KB.


### privateDirty

```
uint32_t HiDebug_NativeMemInfo::privateDirty
```
**Description**
Size of the private dirty memory, in KB.


### pss

```
uint32_t HiDebug_NativeMemInfo::pss
```
**Description**
Proportional set size, in KB.


### rss

```
uint32_t HiDebug_NativeMemInfo::rss
```
**Description**
Resident set size, in KB.


### sharedClean

```
uint32_t HiDebug_NativeMemInfo::sharedClean
```
**Description**
Size of the shared clean memory, in KB.


### sharedDirty

```
uint32_t HiDebug_NativeMemInfo::sharedDirty
```
**Description**
Size of the shared dirty memory, in KB.


### vss

```
uint32_t HiDebug_NativeMemInfo::vss
```
**Description**
Virtual memory size, in KB.
