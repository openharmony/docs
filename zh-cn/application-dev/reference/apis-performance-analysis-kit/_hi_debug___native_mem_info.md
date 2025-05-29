# HiDebug_NativeMemInfo


## 概述

应用程序进程本机内存信息结构类型定义。

**起始版本：** 12

**相关模块：**[HiDebug](_hi_debug.md)

**所在头文件：** [hidebug_type.h](hidebug__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint32_t [pss](#pss) | 进程比例集大小内存，以KB为单位。  | 
| uint32_t [vss](#vss) | 虚拟内存大小，以KB为单位。  | 
| uint32_t [rss](#rss) | 常驻集大小，以KB为单位。  | 
| uint32_t [sharedDirty](#shareddirty) | 共享脏内存的大小，以KB为单位。  | 
| uint32_t [privateDirty](#privatedirty) | 专用脏内存的大小，以KB为单位。  | 
| uint32_t [sharedClean](#sharedclean) | 共享干净内存的大小，以KB为单位。  | 
| uint32_t [privateClean](#privateclean) | 专用干净内存的大小，以KB为单位。  | 


## 结构体成员变量说明


### privateClean

```
uint32_t HiDebug_NativeMemInfo::privateClean
```
**描述**
专用干净内存的大小，以KB为单位。


### privateDirty

```
uint32_t HiDebug_NativeMemInfo::privateDirty
```
**描述**
专用脏内存的大小，以KB为单位。


### pss

```
uint32_t HiDebug_NativeMemInfo::pss
```
**描述**
进程比例集大小内存，以KB为单位。


### rss

```
uint32_t HiDebug_NativeMemInfo::rss
```
**描述**
常驻集大小，以KB为单位。


### sharedClean

```
uint32_t HiDebug_NativeMemInfo::sharedClean
```
**描述**
共享干净内存的大小，以KB为单位。


### sharedDirty

```
uint32_t HiDebug_NativeMemInfo::sharedDirty
```
**描述**
共享脏内存的大小，以KB为单位。


### vss

```
uint32_t HiDebug_NativeMemInfo::vss
```
**描述**
虚拟内存大小，以KB为单位。
