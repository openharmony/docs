# OH_NativeXComponent_TouchPoint
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} OH_NativeXComponent_TouchPoint
```

## 概述

触摸事件中触摸点的信息。该结构体由系统在触摸事件回调中填充，开发者可通过回调获取各触摸点的状态数据（包括相对于应用窗口和组件的坐标、触摸类型、接触面积、压力大小、时间戳以及按下状态等信息）。适用于需要精确获取和处理多点触控信息的场景。

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
| [OH_NativeXComponent_TouchEventType](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_toucheventtype) type | 触摸事件的类型，用于区分按压、抬起、移动等不同触摸动作，具体取值见OH_NativeXComponent_TouchEventType。 |
| double size | 指垫和屏幕之间的接触面积。取值范围为[0.0, 1.0]，值越大表示接触面积越大（归一化值）。 |
| float force | 当前触摸事件的压力，取值范围为[0, 1]，其中0表示无压力，1表示设备可识别的最大压力（具体取值范围依设备能力而定）。 |
| int64_t timeStamp | 当前触摸事件的时间戳。触发事件时距离系统启动的时间间隔，单位纳秒。 |
| bool isPressed | 当前点是否被按下，按下时为true，离开时为false。 |


