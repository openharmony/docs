# inputmethod_cursor_info_capi.h


## 概述

提供光标信息对象的创建、销毁与读写方法。

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：**[InputMethod](_input_method.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) | 光标信息。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \* [OH_CursorInfo_Create](_input_method.md#oh_cursorinfo_create) (double left, double top, double width, double height) | 创建一个新的[InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo)实例。 | 
| void [OH_CursorInfo_Destroy](_input_method.md#oh_cursorinfo_destroy) ([InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo) | 销毁一个[InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo)实例。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_CursorInfo_SetRect](_input_method.md#oh_cursorinfo_setrect) ([InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo, double left, double top, double width, double height) | 设置光标信息内容。 | 
| [InputMethod_ErrorCode](_input_method.md#inputmethod_errorcode) [OH_CursorInfo_GetRect](_input_method.md#oh_cursorinfo_getrect) ([InputMethod_CursorInfo](_input_method.md#inputmethod_cursorinfo) \*cursorInfo, double \*left, double \*top, double \*width, double \*height) | 获取光标信息内容。 | 
