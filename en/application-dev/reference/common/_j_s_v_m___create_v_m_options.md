# JSVM_CreateVMOptions

## Overview

Options for creating a JavaScript Virtual Machine.

**Starting Version:** 11

**Related Modules:** [JSVM](_j_s_v_m.md)

## Summary

### Member Variables

| Name                                                         | Description                                                 |
| ------------------------------------------------------------ | ----------------------------------------------------------- |
| size_t [maxOldGenerationSize](#maxoldgenerationsize)         | The maximum size of the old generation memory.              |
| size_t [maxYoungGenerationSize](#maxyounggenerationsize)     | The maximum size of the young generation memory.            |
| size_t [initialOldGenerationSize](#initialoldgenerationsize) | The initial size of the old generation memory.              |
| size_t [initialYoungGenerationSize](#initialyounggenerationsize) | The initial size of the young generation memory.            |
| const char \* [snapshotBlobData](#snapshotblobdata)          | Startup snapshot data.                                      |
| size_t [snapshotBlobSize](#snapshotblobsize)                 | The size of the startup snapshot data.                      |
| bool [isForSnapshotting](#isforsnapshotting)                 | Whether the virtual machine is used for creating snapshots. |

## Struct Member Variable Descriptions

### initialOldGenerationSize

```cpp
size_t JSVM_CreateVMOptions::initialOldGenerationSize
```
**Description**
The initial size of the old generation memory.

### initialYoungGenerationSize

```cpp
size_t JSVM_CreateVMOptions::initialYoungGenerationSize
```
**Description**
The initial size of the young generation memory.

### isForSnapshotting

```cpp
bool JSVM_CreateVMOptions::isForSnapshotting
```
**Description**
Whether the virtual machine is used for creating snapshots.

### maxOldGenerationSize

```cpp
size_t JSVM_CreateVMOptions::maxOldGenerationSize
```
**Description**
The maximum size of the old generation memory.

### maxYoungGenerationSize

```cpp
size_t JSVM_CreateVMOptions::maxYoungGenerationSize
```
**Description**
The maximum size of the young generation memory.

### snapshotBlobData

```cpp
const char* JSVM_CreateVMOptions::snapshotBlobData
```
**Description**
Startup snapshot data.

### snapshotBlobSize

```cpp
size_t JSVM_CreateVMOptions::snapshotBlobSize
```
**Description**
The size of the startup snapshot data.