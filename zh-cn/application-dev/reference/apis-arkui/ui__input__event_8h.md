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
| [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) { **ArkUI_UIINPUTEVENT_TYPE_UNKNOWN** = 0, **ArkUI_UIINPUTEVENT_TYPE_TOUCH** = 1, **ArkUI_UIINPUTEVENT_TYPE_AXIS** = 2 } | UI输入事件类型定义。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_UIInputEvent_GetType](_ark_u_i___event_module.md#oh_arkui_uiinputevent_gettype) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取UI输入事件的类型。  | 
| int64_t [OH_ArkUI_UIInputEvent_GetEventTime](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtime) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取UI输入事件发生的时间。  | 
| float [OH_ArkUI_PointerEvent_GetX](_ark_u_i___event_module.md#oh_arkui_pointerevent_getx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetY](_ark_u_i___event_module.md#oh_arkui_pointerevent_gety) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowX](_ark_u_i___event_module.md#oh_arkui_pointerevent_getwindowx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowY](_ark_u_i___event_module.md#oh_arkui_pointerevent_getwindowy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayX](_ark_u_i___event_module.md#oh_arkui_pointerevent_getdisplayx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayY](_ark_u_i___event_module.md#oh_arkui_pointerevent_getdisplayy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。  | 
| double [OH_ArkUI_AxisEvent_GetVerticalAxisValue](_ark_u_i___event_module.md#oh_arkui_axisevent_getverticalaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的垂直滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetHorizontalAxisValue](_ark_u_i___event_module.md#oh_arkui_axisevent_gethorizontalaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的水平滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetPinchAxisScaleValue](_ark_u_i___event_module.md#oh_arkui_axisevent_getpinchaxisscalevalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的捏合轴缩放的值。  | 
