# OH_NativeXComponent_HistoricalPoint
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @pengzhiwen3-->
<!--Designer: @dutie123-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

```c
typedef struct {...} OH_NativeXComponent_HistoricalPoint
```

## 概述

历史触摸点。在触摸事件处理中，系统会记录触摸轨迹中的历史触摸点信息，用于还原高速滑动等场景下的完整触摸轨迹。每个历史触摸点包含该时刻触摸点的坐标、类型、压力、时间戳等信息。该结构体用于记录触摸事件过程中的历史触摸点信息，包括触摸点的坐标、压力、时间戳、倾斜角度等属性，适用于需要分析触摸轨迹、手势识别等场景。

**起始版本：** 10

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
| [OH_NativeXComponent_TouchEventType](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_toucheventtype) type | 触摸事件的触摸类型。 |
| double size | 触摸工具与屏幕之间的接触面积。该值为归一化的接触面积，取值范围：0.0~1.0。 |
| float force | 当前触摸事件的压力。取值范围[0, 1]。取值范围：0.0~1.0，0.0表示无压力，1.0表示最大压力。 |
| int64_t timeStamp | 当前触摸事件的时间戳。触发事件时距离系统启动的时间间隔，单位纳秒。 |
| float titlX | 平面X-Y上的投影与当前触摸事件的Z轴之间的角度，单位：弧度。 |
| float titlY | 平面Y-Z上的投影与当前触摸事件的Z轴之间的角度，单位：弧度。 |
| [OH_NativeXComponent_TouchEvent_SourceTool](capi-native-interface-xcomponent-h.md#oh_nativexcomponent_touchevent_sourcetool) sourceTool | 当前触摸事件的源工具。 |


