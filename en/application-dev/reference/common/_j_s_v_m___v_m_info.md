# JSVM_VMInfo


## Overview

JavaScript VM information.

**Since**: 11

Related module: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint32_t [apiVersion](#apiversion) | Specifies the latest API version supported by the VM. | 
| const char \* [engine](#engine) | Name of the engine that implements the VM. | 
| const char \* [version](#version) | Version of the VM. | 
| uint32_t [cachedDataVersionTag](#cacheddataversiontag) | Cache data version tag. | 


## Member Variable Description


### apiVersion

```
uint32_t JSVM_VMInfo::apiVersion
```
**Description**
Specifies the latest API version supported by the VM.


### cachedDataVersionTag

```
uint32_t JSVM_VMInfo::cachedDataVersionTag
```
**Description**
Cache data version tag.


### engine

```
const char* JSVM_VMInfo::engine
```
**Description**
Name of the engine that implements the VM.


### version

```
const char* JSVM_VMInfo::version
```
**Description**
Version of the VM.
