# HiDebug_StackFrame


## 概述

根据pc解析的栈信息。

**起始版本：** 20

**相关模块：**[HiDebug](_hi_debug.md)

**所在头文件：** [hidebug_type.h](hidebug__type_8h.md)

## 汇总


### 成员变量

| 名称                                   | 描述       | 
|--------------------------------------|----------|
| HiDebug_StackFrameType [type](#type) | 栈帧类型。    | 
| union [frame](#frame)       | 解析后的栈信息。 | 

## 结构体成员变量说明

### type

```
HiDebug_StackFrameType HiDebug_StackFrame::type
```
**描述**
栈帧类型。


### frame

```
union {
    struct HiDebug_JsStackFrame js;
    struct HiDebug_NativeStackFrame native;
} frame
```
**描述**
解析后的栈信息。