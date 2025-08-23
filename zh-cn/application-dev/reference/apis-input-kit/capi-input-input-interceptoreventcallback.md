# Input_InterceptorEventCallback

<!--Kit: Input Kit-->
<!--Subsystem: MultimodalInput-->
<!--Owner: @zhaoxueyuan-->
<!--Designer: @hanruofei-->
<!--Tester: @Lyuxin-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

拦截回调事件结构体，拦截鼠标事件、触屏事件和轴事件。

**起始版本：** 12

**相关模块：** [input](capi-input.md)

**所在头文件：** [oh_input_manager.h](capi-oh-input-manager-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| Input_MouseEventCallback mouseCallback | 鼠标事件的回调函数。<br>**起始版本：** 12。 |
| Input_TouchEventCallback touchCallback | 触屏事件的回调函数。<br>**起始版本：** 12。 |
| Input_AxisEventCallback axisCallback | 轴事件的回调函数。<br>**起始版本：** 12。 |


### 成员函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*Input_KeyEventCallback)(const Input_KeyEvent* keyEvent)](#input_keyeventcallback) | Input_KeyEventCallback() | 按键事件的回调函数，keyEvent的生命周期为回调函数内。<br>**起始版本：** 12。 |
| [typedef void (\*Input_MouseEventCallback)(const Input_MouseEvent* mouseEvent)](#input_mouseeventcallback) | Input_MouseEventCallback() | 鼠标事件的回调函数，mouseEvent的生命周期为回调函数内。<br>**起始版本：** 12。 |
| [typedef void (\*Input_TouchEventCallback)(const Input_TouchEvent* touchEvent)](#input_toucheventcallback) | Input_TouchEventCallback() | 触屏事件的回调函数，touchEvent的生命周期为回调函数内。<br>**起始版本：** 12。 |
| [typedef void (\*Input_AxisEventCallback)(const Input_AxisEvent* axisEvent)](#input_axiseventcallback) | Input_AxisEventCallback() | 轴事件的回调函数，axisEvent的生命周期为回调函数内。<br>**起始版本：** 12。 |
| [typedef void (\*Input_DeviceAddedCallback)(int32_t deviceId)](#input_deviceaddedcallback) | Input_DeviceAddedCallback() | 回调函数，用于回调输入设备的热插事件。<br>**起始版本：** 13。 |
| [typedef void (\*Input_DeviceRemovedCallback)(int32_t deviceId)](#input_deviceremovedcallback) | Input_DeviceRemovedCallback() | 回调函数，用于回调输入设备的热拔事件。<br>**起始版本：** 13。 |

## 成员函数说明

### Input_KeyEventCallback()

```
typedef void (*Input_KeyEventCallback)(const Input_KeyEvent* keyEvent)
```

**描述**

按键事件的回调函数，keyEvent的生命周期为回调函数内。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象。 |

### Input_MouseEventCallback()

```
typedef void (*Input_MouseEventCallback)(const Input_MouseEvent* mouseEvent)
```

**描述**

鼠标事件的回调函数，mouseEvent的生命周期为回调函数内。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象。 |

### Input_TouchEventCallback()

```
typedef void (*Input_TouchEventCallback)(const Input_TouchEvent* touchEvent)
```

**描述**

触屏事件的回调函数，touchEvent的生命周期为回调函数内。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象。 |

### Input_AxisEventCallback()

```
typedef void (*Input_AxisEventCallback)(const Input_AxisEvent* axisEvent)
```

**描述**

轴事件的回调函数，axisEvent的生命周期为回调函数内。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象。 |

### Input_DeviceAddedCallback()

```
typedef void (*Input_DeviceAddedCallback)(int32_t deviceId)
```

**描述**

回调函数，用于回调输入设备的热插事件。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备的ID。 |

### Input_DeviceRemovedCallback()

```
typedef void (*Input_DeviceRemovedCallback)(int32_t deviceId)
```

**描述**

回调函数，用于回调输入设备的热拔事件。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备的ID。 |


