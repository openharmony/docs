# JSVM_InitOptions


## 概述

初始化选项，用于初始化JavaScript虚拟机。

**起始版本：** 11

**相关模块：** [JSVM](_j_s_v_m.md)

**所在头文件：** [jsvm_types.h](jsvm__types_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const intptr_t \* [externalReferences](#externalreferences) | 可选。嵌入器中可选的、以nullptr结尾的原始地址数组， 虚拟机可以在序列化期间与之匹配，并可用于反序列化。 此数组及其内容必须在虚拟机实例的整个生命周期内保持有效。  | 
| int \* [argc](#argc) | 虚拟机的标志。如果removeFlags为true，则已识别的标志将从 （argc, argv）中移除。请注意，这些标志当前仅限于V8虚拟机。 它们主要用于开发。不要将它们用于生产环境，因为如果虚拟机与 开发环境不同，它们可能不会生效。  | 
| char \*\* [argv](#argv) | 传入的参数列表。  | 
| bool [removeFlags](#removeflags) | 删除标志。  | 


## 结构体成员变量说明


### argc

```
int* JSVM_InitOptions::argc
```
**描述**
虚拟机的标志。如果removeFlags为true，则已识别的标志将从 （argc, argv）中移除。请注意，这些标志当前仅限于V8虚拟机。 它们主要用于开发。不要将它们用于生产环境，因为如果虚拟机与 开发环境不同，它们可能不会生效。


### argv

```
char** JSVM_InitOptions::argv
```
**描述**
传入的参数列表。


### externalReferences

```
const intptr_t* JSVM_InitOptions::externalReferences
```
**描述**
可选。嵌入器中可选的、以nullptr结尾的原始地址数组， 虚拟机可以在序列化期间与之匹配，并可用于反序列化。 此数组及其内容必须在虚拟机实例的整个生命周期内保持有效。


### removeFlags

```
bool JSVM_InitOptions::removeFlags
```
**描述**
删除标志。
