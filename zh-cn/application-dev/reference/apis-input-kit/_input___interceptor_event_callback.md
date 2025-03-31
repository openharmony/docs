# Input_InterceptorEventCallback


## 概述

拦截回调事件结构体，拦截鼠标事件、触摸事件和轴事件。

**起始版本：** 12

**相关模块：**[Input](input.md)

**所在头文件：**[oh_input_manager.h](oh__input__manager_8h.md)

## 汇总


### 成员变量

| 名称 | 描述 | 
| -------- | -------- |
| [Input_MouseEventCallback](input.md#input_mouseeventcallback) [mouseCallback](#mousecallback) | 鼠标事件的回调函数。  | 
| [Input_TouchEventCallback](input.md#input_toucheventcallback) [touchCallback](#touchcallback) | 触摸事件的回调函数。  | 
| [Input_AxisEventCallback](input.md#input_axiseventcallback) [axisCallback](#axiscallback) | 轴事件的回调函数。  | 


## 结构体成员变量说明


### axisCallback

```
Input_AxisEventCallback Input_InterceptorEventCallback::axisCallback
```
**描述**

轴事件的回调函数。

**起始版本：** 12


### mouseCallback

```
Input_MouseEventCallback Input_InterceptorEventCallback::mouseCallback
```
**描述**

鼠标事件的回调函数。

**起始版本：** 12


### touchCallback

```
Input_TouchEventCallback Input_InterceptorEventCallback::touchCallback
```
**描述**

触摸事件的回调函数。

**起始版本：** 12
