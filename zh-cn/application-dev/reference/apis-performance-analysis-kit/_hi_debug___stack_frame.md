# HiDebug_StackFrame


## 概述

栈帧内容的定义。

**起始版本：** 20

**相关模块：**[HiDebug](_hi_debug.md)

**所在头文件：** [hidebug_type.h](hidebug__type_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [HiDebug_StackFrameType](_hi_debug.md#hidebug_stackframetype) [type](#type) | 当前栈的类型。  | 
| union { |  | 
| &nbsp;&nbsp;&nbsp;struct [HiDebug_JsStackFrame](_hi_debug___js_stack_frame.md) [js](#js) |  | 
| &nbsp;&nbsp;&nbsp;struct [HiDebug_NativeStackFrame](_hi_debug___native_stack_frame.md) [native](#native) |  | 
| } [frame](#frame) | 栈帧内容。  | 


## 结构体成员变量说明


### frame

```
union { ... } HiDebug_StackFrame::frame
```
**描述**
栈帧内容。


### js

```
struct HiDebug_JsStackFrame HiDebug_StackFrame::js
```
**描述**
由[HiDebug_JsStackFrame](_hi_debug___js_stack_frame.md)定义的js栈帧内容。


### native

```
struct HiDebug_NativeStackFrame HiDebug_StackFrame::native
```
**描述**
由[HiDebug_NativeStackFrame](_hi_debug___native_stack_frame.md)定义的native栈帧内容。


### type

```
HiDebug_StackFrameType HiDebug_StackFrame::type
```
**描述**
当前栈的类型。
