# OH_NativeXComponent_HistoricalPoint


## 概述

历史接触点。

**起始版本：** 10

**相关模块：**[Native XComponent](_o_h___native_x_component.md)

**所在头文件：** [native_interface_xcomponent.h](native__interface__xcomponent_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [id](_o_h___native_x_component.md#id-33) = 0 |  手指的唯一标识符。| 
| float [screenX](_o_h___native_x_component.md#screenx-44) = 0.0 |  触摸点相对于XComponent所在应用窗口左上角的x坐标。| 
| float [screenY](_o_h___native_x_component.md#screeny-44) = 0.0 |  触摸点相对于XComponent所在应用窗口左上角的y坐标。| 
| float [x](_o_h___native_x_component.md#x-44) = 0.0 |  触摸点相对于XComponent组件左边缘的x坐标。| 
| float [y](_o_h___native_x_component.md#y-44) = 0.0 |  触摸点相对于XComponent组件上边缘的y坐标。| 
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype)[type](_o_h___native_x_component.md#type-33) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN | 触摸事件的触摸类型。 | 
| double [size](_o_h___native_x_component.md#size-33) = 0.0 |  指垫和屏幕之间的接触面积。| 
| float [force](_o_h___native_x_component.md#force-33) = 0.0 |  当前触摸事件的压力。| 
| int64_t [timeStamp](_o_h___native_x_component.md#timestamp-33) = 0 |  当前触摸事件的时间戳。触发事件时距离系统启动的时间间隔，单位纳秒。| 
| float [titlX](_o_h___native_x_component.md#titlx) = 0.0 | 平面X-Y上的投影与当前触摸事件的Z轴之间的角度。 |
| float [titlY](_o_h___native_x_component.md#titly) = 0.0 | 当前触摸事件在平面Y-Z和轴Z上的投影之间的角度。 |
| [OH_NativeXComponent_TouchEvent_SourceTool](_o_h___native_x_component.md#oh_nativexcomponent_touchevent_sourcetool) [sourceTool](_o_h___native_x_component.md#sourcetool) |  当前触摸事件的源工具。 | 
