# JSVM_CreateVMOptions


## 概述

创建JavaScript虚拟机的选项。

**起始版本：** 11

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| size_t [maxOldGenerationSize](#maxoldgenerationsize) | 老年代内存大小上限。  | 
| size_t [maxYoungGenerationSize](#maxyounggenerationsize) | 年轻代内存大小上限。  | 
| size_t [initialOldGenerationSize](#initialoldgenerationsize) | 老年代内存大小初始值。  | 
| size_t [initialYoungGenerationSize](#initialyounggenerationsize) | 年轻代内存大小初始值。  | 
| const char \* [snapshotBlobData](#snapshotblobdata) | 启动快照数据。  | 
| size_t [snapshotBlobSize](#snapshotblobsize) | 启动快照数据的大小。  | 
| bool [isForSnapshotting](#isforsnapshotting) | 虚拟机是否用于创建快照。  | 


## 结构体成员变量说明


### initialOldGenerationSize

```
size_t JSVM_CreateVMOptions::initialOldGenerationSize
```
**描述**
老年代内存大小初始值。


### initialYoungGenerationSize

```
size_t JSVM_CreateVMOptions::initialYoungGenerationSize
```
**描述**
年轻代内存大小初始值。


### isForSnapshotting

```
bool JSVM_CreateVMOptions::isForSnapshotting
```
**描述**
虚拟机是否用于创建快照。


### maxOldGenerationSize

```
size_t JSVM_CreateVMOptions::maxOldGenerationSize
```
**描述**
老年代内存大小上限。


### maxYoungGenerationSize

```
size_t JSVM_CreateVMOptions::maxYoungGenerationSize
```
**描述**
年轻代内存大小上限。


### snapshotBlobData

```
const char* JSVM_CreateVMOptions::snapshotBlobData
```
**描述**
启动快照数据。


### snapshotBlobSize

```
size_t JSVM_CreateVMOptions::snapshotBlobSize
```
**描述**
启动快照数据的大小。
