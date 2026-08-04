# OH_NativeXComponent_TouchEvent
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} OH_NativeXComponent_TouchEvent
```

## 概述

触摸事件。当用户在XComponent组件上进行触摸操作时，通过该结构体可获取触摸点的坐标、触摸类型、接触面积、压力、时间戳等信息，适用于需要在Native层处理XComponent触摸交互的场景。

**起始版本：** 8

**相关模块：** [OH_NativeXComponent Native XComponent](capi-oh-nativexcomponent-native-xcomponent.md)

**所在头文件：** [native_interface_xcomponent.h](capi-native-interface-xcomponent-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| -- | -- |
| int32_t id | 手指的唯一标识符。 |
| float screenX | 触摸点相对于XComponent所在应用窗口左上角的x坐标，单位：px。 |
| float screenY | 触摸点相对于XComponent所在应用窗口左上角的y坐标，单位：px。 |
| float x | 触摸点相对于XComponent组件左边缘的x坐标，单位：px。 |
| float y | 触摸点相对于XComponent组件上边缘的y坐标，单位：px。 |
| [OH_NativeXComponent_TouchEventType](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_toucheventtype) type | 触摸事件的类型。 |
| double size | 触摸区域的归一化大小，表示指垫与屏幕接触面积的相对比例，取值范围为0.0~1.0，值越大表示接触面积越大。 |
| float force | 当前触摸事件的压力，归一化值，取值范围为0.0~1.0，0表示无压力，1表示设备可识别的最大压力。 |
| int64_t deviceId | 产生当前触摸事件的设备的ID。 |
| int64_t timeStamp | 当前触摸事件的时间戳。触发事件时距离系统启动的时间间隔，单位纳秒。 |
| [OH_NativeXComponent_TouchPoint](capi-oh-nativexcomponent-native-xcomponent-oh-nativexcomponent-touchpoint.md) touchPoints[OH_NATIVE_XCOMPONENT_MAX_TOUCH_POINTS_NUMBER] | 当前触摸点的数组，数组中有效元素的个数为numPoints。OH_NATIVE_XCOMPONENT_MAX_TOUCH_POINTS_NUMBER的介绍请参考[宏定义](capi-native-interface-xcomponent-h.md#宏定义)。|
| uint32_t numPoints | 当前触摸点的数量，取值范围为[1, OH_NATIVE_XCOMPONENT_MAX_TOUCH_POINTS_NUMBER]。值为1时为单指触摸，大于1时为多指触摸。 |
