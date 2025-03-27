# oh_axis_type.h


## 概述

输入设备的轴事件结构和枚举。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**库：** libohinput.so

**起始版本：** 12

**相关模块：**[Input](input.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef enum [InputEvent_AxisType](input.md#inputevent_axistype) [InputEvent_AxisType](input.md#inputevent_axistype) | 输入设备的轴类型。  |
| typedef enum [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) | 输入设备的轴事件类型。  | 
| typedef enum [InputEvent_AxisAction](input.md#inputevent_axisaction) [InputEvent_AxisAction](input.md#inputevent_axisaction) | 轴事件动作。  |


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [InputEvent_AxisType](input.md#inputevent_axistype) {<br/>AXIS_TYPE_UNKNOWN, AXIS_TYPE_SCROLL_VERTICAL, AXIS_TYPE_SCROLL_HORIZONTAL, <br/>AXIS_TYPE_PINCH, AXIS_TYPE_ROTATE<br/>} | 输入设备的轴类型。  | 
| [InputEvent_AxisEventType](input.md#inputevent_axiseventtype) { AXIS_EVENT_TYPE_PINCH = 1, AXIS_EVENT_TYPE_SCROLL = 2 } | 输入设备的轴事件类型。  |
| [InputEvent_AxisAction](input.md#inputevent_axisaction) { AXIS_ACTION_CANCEL = 0, AXIS_ACTION_BEGIN, AXIS_ACTION_UPDATE, AXIS_ACTION_END } | 轴事件动作。  |
