# OH_NativeXComponent_TouchPoint


## 概述

触摸事件中触摸点的信息。

**起始版本：** 8

**相关模块：**[Native XComponent](_o_h___native_x_component.md)

**所在头文件：** [native_interface_xcomponent.h](native__interface__xcomponent_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [id](_o_h___native_x_component.md#id-13) = 0 |  手指的唯一标识符。| 
| float [screenX](_o_h___native_x_component.md#screenx-14) = 0.0 |   触摸点相对于XComponent所在应用窗口左上角的x坐标。| 
| float [screenY](_o_h___native_x_component.md#screeny-14) = 0.0 |  触摸点相对于XComponent所在应用窗口左上角的y坐标。| 
| float [x](_o_h___native_x_component.md#x-14) = 0.0 |  触摸点相对于XComponent组件左边缘的x坐标。| 
| float [y](_o_h___native_x_component.md#y-14) = 0.0 |  触摸点相对于XComponent组件上边缘的y坐标。| 
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype)[type](_o_h___native_x_component.md#type-13) = OH_NativeXComponent_TouchEventType::OH_NATIVEXCOMPONENT_UNKNOWN |  触摸事件的触摸类型。| 
| double [size](_o_h___native_x_component.md#size-13) = 0.0 |  指垫和屏幕之间的接触面积。| 
| float [force](_o_h___native_x_component.md#force-13) = 0.0 |  当前触摸事件的压力。| 
| long long [timeStamp](_o_h___native_x_component.md#timestamp-13) = 0 | 当前触摸事件的时间戳。触发事件时距离系统启动的时间间隔，单位纳秒。| 
| bool [isPressed](_o_h___native_x_component.md#ispressed) = false |  触摸点是否被按下。true：触摸点被按下；false：触摸点未被按下。|
