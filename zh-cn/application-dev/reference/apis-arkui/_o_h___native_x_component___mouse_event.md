# OH_NativeXComponent_MouseEvent


## 概述

鼠标事件。

**起始版本：** 9

**相关模块：**[Native XComponent](_o_h___native_x_component.md)


## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| float [x](_o_h___native_x_component.md#x-33) = 0.0 |  点击触点相对于当前组件左上角的x轴坐标。| 
| float [y](_o_h___native_x_component.md#y-33) = 0.0|  点击触点相对于当前组件左上角的y轴坐标。| 
| float [screenX](_o_h___native_x_component.md#screenx-33) = 0.0|  点击触点相对于XComponent所在应用屏幕左上角的x轴坐标。| 
| float [screenY](_o_h___native_x_component.md#screeny-33) = 0.0|  点击触点相对于XComponent所在应用屏幕左上角的y轴坐标。| 
| int64_t [timestamp](_o_h___native_x_component.md#timestamp) = 0|  当前鼠标事件的时间戳。触发事件时距离系统启动的时间间隔，单位纳秒。| 
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction) [action](_o_h___native_x_component.md#action) = OH_NativeXComponent_MouseEventAction::OH_NATIVEXCOMPONENT_MOUSE_NONE|  当前鼠标事件动作。| 
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton) [button](_o_h___native_x_component.md#button) = OH_NativeXComponent_MouseEventButton::OH_NATIVEXCOMPONENT_NONE_BUTTON|  鼠标事件按键。| 