# HiDebug_JsStackFrame


## 概述

js栈帧内容的定义。

**起始版本：** 20

**相关模块：**[HiDebug](_hi_debug.md)

**所在头文件：** [hidebug_type.h](hidebug__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| uint64_t [relativePc](#relativepc) | 相对pc地址。当前pc相对于其所在的映射区域（如可执行文件或共享库）起始地址的偏移量。  | 
| int32_t [line](#line) | 代码所在的行号。当前栈帧对应的代码位于文件的具体行位置。  | 
| int32_t [column](#column) | 代码所在的列号。当前栈帧对应的代码在指定行的具体列位置。  | 
| const char \* [mapName](#mapname) | 映射名称。当前栈帧所属的映射区域的名称。  | 
| const char \* [functionName](#functionname) | 函数名称。当前栈帧对应的函数的名称。  | 
| const char \* [url](#url) | URL地址。当前栈帧对应代码的文件的URL，无论是本地文件路径还是远程服务器上的文件地址，通过该URL能找到对应的代码文件。  | 
| const char \* [packageName](#packagename) | 包名。当前栈帧对应的代码所属包的名称。  | 


## 结构体成员变量说明


### column

```
int32_t HiDebug_JsStackFrame::column
```
**描述**
代码所在的列号。当前栈帧对应的代码在指定行的具体列位置。


### functionName

```
const char* HiDebug_JsStackFrame::functionName
```
**描述**
函数名称。当前栈帧对应的函数的名称。


### line

```
int32_t HiDebug_JsStackFrame::line
```
**描述**
代码所在的行号。当前栈帧对应的代码位于文件的具体行位置。


### mapName

```
const char* HiDebug_JsStackFrame::mapName
```
**描述**
映射名称。当前栈帧所属的映射区域的名称。


### packageName

```
const char* HiDebug_JsStackFrame::packageName
```
**描述**
包名。当前栈帧对应的代码所属包的名称。


### relativePc

```
uint64_t HiDebug_JsStackFrame::relativePc
```
**描述**
相对pc地址。当前pc相对于其所在的映射区域（如可执行文件或共享库）起始地址的偏移量。


### url

```
const char* HiDebug_JsStackFrame::url
```
**描述**
URL地址。当前栈帧对应代码的文件的URL，无论是本地文件路径还是远程服务器上的文件地址，通过该URL能找到对应的代码文件。
