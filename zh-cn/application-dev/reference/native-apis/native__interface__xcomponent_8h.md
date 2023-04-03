# native_interface_xcomponent.h


## 概述

声明用于访问Native XComponent的API。

**起始版本：**

8

**相关模块：**

[Native XComponent](_o_h___native_x_component.md)


## 汇总


### 结构体

| 结构体名称 | 描述 |
| -------- | -------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | 触摸事件中触摸点的信息。 |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | 触摸事件。 |
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | 鼠标事件。 |
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | 注册鼠标事件的回调。 |


### 类型定义

| 类型定义名称 | 描述 |
| -------- | -------- |
| [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) | 提供封装的OH_NativeXComponent实例。 |
| [OH_NativeXComponent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_callback) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_mouseevent_callback) | 注册鼠标事件的回调。 |


### 枚举

| 枚举名称 | 描述 |
| -------- | -------- |
| { OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, <br/>OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, <br/>OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2} | [枚举](_o_h___native_x_component.md#anonymous-enum)API访问状态。 |
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype) {  <br/>OH_NATIVEXCOMPONENT_DOWN = 0, <br/>OH_NATIVEXCOMPONENT_UP, <br/>OH_NATIVEXCOMPONENT_MOVE, <br/>OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN } | 触摸事件类型。 |
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction) { <br/>OH_NATIVEXCOMPONENT_MOUSE_NONE = 0, <br/>OH_NATIVEXCOMPONENT_MOUSE_PRESS, <br/>OH_NATIVEXCOMPONENT_MOUSE_RELEASE, <br/>OH_NATIVEXCOMPONENT_MOUSE_MOVE } | 鼠标事件动作。 |
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton) {  <br/>OH_NATIVEXCOMPONENT_NONE_BUTTON = 0, <br/>OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01, <br/>OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02, <br/>OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04,   <br/>OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08, <br/>OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10 } | 鼠标事件按键。 |


### 函数

| 函数名称 | 描述 |
| -------- | -------- |
| [OH_NativeXComponent_GetXComponentId](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentid) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, char \*id, uint64_t \*size) | 获取ArkUI XComponent的id。 |
| [OH_NativeXComponent_GetXComponentSize](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentsize) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, uint64_t \*width, uint64_t \*height) | 获取ArkUI XComponent持有的surface的大小。 |
| [OH_NativeXComponent_GetXComponentOffset](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentoffset) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, double \*x, double \*y) | 获取ArkUI XComponent组件相对屏幕左上顶点的偏移量。 |
| [OH_NativeXComponent_GetTouchEvent](_o_h___native_x_component.md#oh_nativexcomponent_gettouchevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) \*touchEvent) | 获取ArkUI XComponent调度的触摸事件。 |
| [OH_NativeXComponent_GetMouseEvent](_o_h___native_x_component.md#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | 获取ArkUI XComponent调度的鼠标事件 |
| [OH_NativeXComponent_RegisterCallback](_o_h___native_x_component.md#oh_nativexcomponent_registercallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) \*callback) | 为此OH_NativeXComponent实例注册回调。 |
| [OH_NativeXComponent_RegisterMouseEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registermouseeventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) \*callback) | 为此OH_NativeXComponent实例注册鼠标事件回调。 |


### 变量

| 变量名称 | 描述 |
| -------- | -------- |
| **OH_XCOMPONENT_ID_LEN_MAX** = 128 | ArkUI XComponent的id的最大长度。 |
| **OH_MAX_TOUCH_POINTS_NUMBER** = 10 | 触摸事件中的可识别的触摸点个数最大值。 |
