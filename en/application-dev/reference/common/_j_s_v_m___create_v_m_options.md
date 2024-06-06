# JSVM_CreateVMOptions


## Overview

Options for creating a JavaScript virtual machine.

**Since**: 11

Related module: [JSVM](_j_s_v_m.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| size_t [maxOldGenerationSize](#maxoldgenerationsize) | Upper limit of the old-generation memory size. | 
| size_t [maxYoungGenerationSize](#maxyounggenerationsize) | Upper limit of the memory size of the young generation. | 
| size_t [initialOldGenerationSize](#initialoldgenerationsize) | Initial size of the old-generation memory. | 
| size_t [initialYoungGenerationSize](#initialyounggenerationsize) | Initial size of the young-generation memory. | 
| const char \* [snapshotBlobData](#snapshotblobdata) | Starts snapshot data. | 
| size_t [snapshotBlobSize](#snapshotblobsize) | Size of the snapshot data to be started. | 
| bool [isForSnapshotting](#isforsnapshotting) | Specifies whether the VM is used to create a snapshot. | 


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
Specifies whether the VM is used to create a snapshot.


### maxOldGenerationSize

```
size_t JSVM_CreateVMOptions::maxOldGenerationSize
```
**Description**
Upper limit of the old-generation memory size.


### maxYoungGenerationSize

```
size_t JSVM_CreateVMOptions::maxYoungGenerationSize
```
**Description**
Upper limit of the memory size of the young generation.


### snapshotBlobData

```
const char* JSVM_CreateVMOptions::snapshotBlobData
```
**Description**
Starts snapshot data.


### snapshotBlobSize

```
size_t JSVM_CreateVMOptions::snapshotBlobSize
```
**Description**
Size of the snapshot data to be started.
