# ui_input_event.h


## 概述

提供ArkUI在Native侧的事件定义。

**库：** libace_ndk.z.so

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**起始版本：** 12

**相关模块：**[ArkUI_EventModule](_ark_u_i___event_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent)[ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) | UI输入事件定义。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) { ArkUI_UIINPUTEVENT_TYPE_UNKNOWN = 0, ArkUI_UIINPUTEVENT_TYPE_TOUCH = 1, ArkUI_UIINPUTEVENT_TYPE_AXIS = 2 } | UI输入事件类型定义。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_UIInputEvent_GetType](_ark_u_i___event_module.md#oh_arkui_uiinputevent_gettype) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取UI输入事件的类型。  | 
| int64_t [OH_ArkUI_UIInputEvent_GetEventTime](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtime) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取UI输入事件发生的时间。  | 
| double [OH_ArkUI_AxisEvent_GetVerticalAxisValue](_ark_u_i___event_module.md#oh_arkui_axisevent_getverticalaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的垂直滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetHorizontalAxisValue](_ark_u_i___event_module.md#oh_arkui_axisevent_gethorizontalaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的水平滚动轴的值。  | 
| float [OH_ArkUI_AxisEvent_GetX](_ark_u_i___event_module.md#oh_arkui_axisevent_getx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_AxisEvent_GetY](_ark_u_i___event_module.md#oh_arkui_axisevent_gety) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_AxisEvent_GetWindowX](_ark_u_i___event_module.md#oh_arkui_axisevent_getwindowx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的相对于窗口的X坐标。  | 
| float [OH_ArkUI_AxisEvent_GetWindowY](_ark_u_i___event_module.md#oh_arkui_axisevent_getwindowy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的相对于窗口的Y坐标。  | 
| float [OH_ArkUI_AxisEvent_GetDisplayX](_ark_u_i___event_module.md#oh_arkui_axisevent_getdisplayx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的相对于屏幕的X坐标。  | 
| float [OH_ArkUI_AxisEvent_GetDisplayY](_ark_u_i___event_module.md#oh_arkui_axisevent_getdisplayy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的相对于屏幕的Y坐标。  | 
