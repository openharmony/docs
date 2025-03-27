# JSVM_ScriptOrigin


## 概述

Source code information.

**起始版本：** 12

**相关模块：**[JSVM](_j_s_v_m.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [sourceMapUrl](#sourcemapurl) | Sourcemap 路径。  | 
| const char \* [resourceName](#resourcename) | 源文件名。  | 
| size_t [resourceLineOffset](#resourcelineoffset) | 这段代码在源文件中的起始行号。  | 
| size_t [resourceColumnOffset](#resourcecolumnoffset) | 这段代码在源文件中的起始列号。  | 


## 结构体成员变量说明


### resourceColumnOffset

```
size_t JSVM_ScriptOrigin::resourceColumnOffset
```
**描述**
这段代码在源文件中的起始列号。


### resourceLineOffset

```
size_t JSVM_ScriptOrigin::resourceLineOffset
```
**描述**
这段代码在源文件中的起始行号。


### resourceName

```
const char* JSVM_ScriptOrigin::resourceName
```
**描述**
源文件名。


### sourceMapUrl

```
const char* JSVM_ScriptOrigin::sourceMapUrl
```
**描述**
Sourcemap 路径。
