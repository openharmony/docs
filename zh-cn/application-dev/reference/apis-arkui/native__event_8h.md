# native_event.h


## 概述

提供ArkUI在Native侧的事件类型定义集合。

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_NativeModule](_ark_u_i___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 |
| -------- | -------- |
| struct&nbsp;&nbsp;[ArkUI_NodeTouchPoint](_ark_u_i___node_touch_point.md) | 定义Touch事件触控点信息的数据结构。  |
| struct&nbsp;&nbsp;[ArkUI_NodeHistoricalTouchPoint](_ark_u_i___node_historical_touch_point.md) | 定义历史点信息的结构类型。  |
| struct&nbsp;&nbsp;[ArkUI_NodeTouchEvent](_ark_u_i___node_touch_event.md) | 定义Touch事件的结构类型。  |


### 枚举

| 名称 | 描述 |
| -------- | -------- |
| [ArkUI_NodeToolType](_ark_u_i___native_module.md#arkui_nodetooltype) { [NODE_TOOL_TYPE_UNKNOWN](_ark_u_i___native_module.md) = -1, [NODE_TOOL_TYPE_FINGER](_ark_u_i___native_module.md) = 0, [NODE_TOOL_TYPE_STYLUS](_ark_u_i___native_module.md) = 1 } | Touch事件的工具类型定义。  |
| [ArkUI_NodeSourceType](_ark_u_i___native_module.md#arkui_nodesourcetype) { [NODE_SOURCE_TYPE_UNKNOWN](_ark_u_i___native_module.md) = -1, [NODE_SOURCE_TYPE_TOUCH_SCREEN](_ark_u_i___native_module.md) = 0, [NODE_SOURCE_TYPE_STYLUS](_ark_u_i___native_module.md) = 1, [NODE_SOURCE_TYPE_TOUCHPAD](_ark_u_i___native_module.md) = 2 } | 产生Touch事件的来源类型定义。  |
| [ArkUI_NodeTouchEventAction](_ark_u_i___native_module.md#arkui_nodetoucheventaction) { [NODE_ACTION_CANCEL](_ark_u_i___native_module.md) = 0, [NODE_ACTION_DOWN](_ark_u_i___native_module.md) = 1, [NODE_ACTION_MOVE](_ark_u_i___native_module.md) = 2, [NODE_ACTION_UP](_ark_u_i___native_module.md) = 3 } | 定义触屏事件类型的枚举值。  |
