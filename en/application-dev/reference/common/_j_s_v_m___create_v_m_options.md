# JSVM_CreateVMOptions


## Overview

Options for creating a JavaScript VM.

**Since**: 11

**Related module**: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| size_t [maxOldGenerationSize](#maxoldgenerationsize) | Maximum size of the old-generation memory. | 
| size_t [maxYoungGenerationSize](#maxyounggenerationsize) | Maximum size of the young-generation memory. | 
| size_t [initialOldGenerationSize](#initialoldgenerationsize) | Initial size of the old-generation memory. | 
| size_t [initialYoungGenerationSize](#initialyounggenerationsize) | Initial size of the young-generation memory. | 
| const char \* [snapshotBlobData](#snapshotblobdata) | Startup snapshot data. | 
| size_t [snapshotBlobSize](#snapshotblobsize) | Size of the startup snapshot data. | 
| bool [isForSnapshotting](#isforsnapshotting) | Whether the VM is used for snapshotting. | 


## Member Variable Description


### initialOldGenerationSize

```
size_t JSVM_CreateVMOptions::initialOldGenerationSize
```
**Description**
Initial size of the old-generation memory.


### initialYoungGenerationSize

```
size_t JSVM_CreateVMOptions::initialYoungGenerationSize
```
**Description**
Initial size of the young-generation memory.


### isForSnapshotting

```
bool JSVM_CreateVMOptions::isForSnapshotting
```
**Description**
Whether the VM is used for snapshotting.


### maxOldGenerationSize

```
size_t JSVM_CreateVMOptions::maxOldGenerationSize
```
**Description**
Maximum size of the old-generation memory.


### maxYoungGenerationSize

```
size_t JSVM_CreateVMOptions::maxYoungGenerationSize
```
**Description**
Maximum size of the young-generation memory.


### snapshotBlobData

```
const char* JSVM_CreateVMOptions::snapshotBlobData
```
**Description**
Startup snapshot data.


### snapshotBlobSize

```
size_t JSVM_CreateVMOptions::snapshotBlobSize
```
**Description**
Size of the startup snapshot data.
