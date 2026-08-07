# Input_InterceptorEventCallback

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @zhang_yixin13-->

```c
typedef struct Input_InterceptorEventCallback {...} Input_InterceptorEventCallback
```

## 概述

拦截回调事件结构体，用于定义输入事件拦截所需的回调函数类型，支持拦截鼠标事件、触屏输入事件、按键事件和轴事件。

**起始版本：** 12

**相关模块：** [input](capi-input.md)

**所在头文件：** [oh_input_manager.h](capi-oh-input-manager-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| [Input_MouseEventCallback](capi-oh-input-manager-h.md#input_mouseeventcallback) mouseCallback | 鼠标事件的回调函数。 |
| [Input_TouchEventCallback](capi-oh-input-manager-h.md#input_toucheventcallback) touchCallback | 触屏输入事件的回调函数。 |
| [Input_AxisEventCallback](capi-oh-input-manager-h.md#input_axiseventcallback) axisCallback | 轴事件的回调函数。 |
