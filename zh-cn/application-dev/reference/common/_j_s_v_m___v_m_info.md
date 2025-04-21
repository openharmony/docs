# JSVM_VMInfo


## 概述

JavaScript虚拟机信息。

**起始版本：** 11

**相关模块：** [JSVM](_j_s_v_m.md)

**所在头文件：** [jsvm_types.h](jsvm__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [apiVersion](#apiversion) | 此虚拟机支持的最高API版本。  | 
| const char \* [engine](#engine) | 实现虚拟机的引擎名称。  | 
| const char \* [version](#version) | 虚拟机的版本。  | 
| uint32_t [cachedDataVersionTag](#cacheddataversiontag) | 缓存数据版本标签。  | 


## 结构体成员变量说明


### apiVersion

```
uint32_t JSVM_VMInfo::apiVersion
```
**描述**
此虚拟机支持的最高API版本。


### cachedDataVersionTag

```
uint32_t JSVM_VMInfo::cachedDataVersionTag
```
**描述**
缓存数据版本标签。


### engine

```
const char* JSVM_VMInfo::engine
```
**描述**
实现虚拟机的引擎名称。


### version

```
const char* JSVM_VMInfo::version
```
**描述**
虚拟机的版本。
