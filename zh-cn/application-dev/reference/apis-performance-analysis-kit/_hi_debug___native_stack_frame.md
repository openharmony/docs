# HiDebug_NativeStackFrame


## 概述

native栈帧内容的定义。

**起始版本：** 20

**相关模块：**[HiDebug](_hi_debug.md)

**所在头文件：** [hidebug_type.h](hidebug__type_8h.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint64_t [relativePc](#relativepc) | 相对pc地址。当前pc相对于其所在的映射区域（如可执行文件或共享库）起始地址的偏移量。  | 
| uint64_t [funcOffset](#funcoffset) | 函数偏移量。当前栈帧对应的函数在其所在的映射区域（如可执行文件或共享库）内的偏移量。  | 
| const char \* [mapName](#mapname) | 映射名称。当前栈帧所属的映射区域的名称。  | 
| const char \* [functionName](#functionname) | 函数名称。当前栈帧对应的函数的名称。  | 
| const char \* [buildId](#buildid) | 构建标识符。当前映射区域（如可执行文件或共享库）相关的唯一标识符。在调试和符号解析时，buildId可确保使用的符号文件与实际运行的二进制文件版本一致。  | 
| const char \* [reserved](#reserved) | 保留字段。为了后续扩展预留的字段。  | 


## 结构体成员变量说明


### buildId

```
const char* HiDebug_NativeStackFrame::buildId
```
**描述**
构建标识符。当前映射区域（如可执行文件或共享库）相关的唯一标识符。在调试和符号解析时，buildId可确保使用的符号文件与实际运行的二进制文件版本一致。


### funcOffset

```
uint64_t HiDebug_NativeStackFrame::funcOffset
```
**描述**
函数偏移量。当前栈帧对应的函数在其所在的映射区域（如可执行文件或共享库）内的偏移量。


### functionName

```
const char* HiDebug_NativeStackFrame::functionName
```
**描述**
函数名称。当前栈帧对应的函数的名称。


### mapName

```
const char* HiDebug_NativeStackFrame::mapName
```
**描述**
映射名称。当前栈帧所属的映射区域的名称。


### relativePc

```
uint64_t HiDebug_NativeStackFrame::relativePc
```
**描述**
相对pc地址。当前pc相对于其所在的映射区域（如可执行文件或共享库）起始地址的偏移量。


### reserved

```
const char* HiDebug_NativeStackFrame::reserved
```
**描述**
保留字段。为了后续扩展预留的字段。
