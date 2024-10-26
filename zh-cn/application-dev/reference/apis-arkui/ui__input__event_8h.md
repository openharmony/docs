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
| typedef struct [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) | UI输入事件定义。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) { **ARKUI_UIINPUTEVENT_TYPE_UNKNOWN** = 0, **ARKUI_UIINPUTEVENT_TYPE_TOUCH** = 1, **ARKUI_UIINPUTEVENT_TYPE_AXIS** = 2, **ARKUI_UIINPUTEVENT_TYPE_MOUSE** = 3 } | UI输入事件类型定义。  | 
| {<br/>[OH_NATIVEXCOMPONENT_RESULT_SUCCESS](_ark_u_i___event_module.md) = 0, [OH_NATIVEXCOMPONENT_RESULT_FAILED](_ark_u_i___event_module.md) = -1, [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](_ark_u_i___event_module.md) = -2, [UI_TOUCH_EVENT_ACTION_CANCEL](_ark_u_i___event_module.md) = 0,<br/>[UI_TOUCH_EVENT_ACTION_DOWN](_ark_u_i___event_module.md) = 1, [UI_TOUCH_EVENT_ACTION_MOVE](_ark_u_i___event_module.md) = 2, [UI_TOUCH_EVENT_ACTION_UP](_ark_u_i___event_module.md) = 3<br/>} | 定义输入事件的Action Code。  | 
| {<br/>[UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN](_ark_u_i___event_module.md) = 0, [UI_INPUT_EVENT_TOOL_TYPE_FINGER](_ark_u_i___event_module.md) = 1, [UI_INPUT_EVENT_TOOL_TYPE_PEN](_ark_u_i___event_module.md) = 2, [UI_INPUT_EVENT_TOOL_TYPE_MOUSE](_ark_u_i___event_module.md) = 3,<br/>[UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD](_ark_u_i___event_module.md) = 4, [UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK](_ark_u_i___event_module.md) = 5<br/>} | 产生输入事件的工具类型定义。  | 
| { [UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN](_ark_u_i___event_module.md) = 0, [UI_INPUT_EVENTT_SOURCE_TYPE_MOUSE](_ark_u_i___event_module.md) = 1, [UI_INPUT_EVENTT_SOURCE_TYPE_TOUCH_SCREEN](_ark_u_i___event_module.md) = 2 } | 产生输入事件的来源类型定义。  | 
| [HitTestMode](_ark_u_i___event_module.md#hittestmode) { [HTMDEFAULT](_ark_u_i___event_module.md) = 0, [HTMBLOCK](_ark_u_i___event_module.md), [HTMTRANSPARENT](_ark_u_i___event_module.md), [HTMNONE](_ark_u_i___event_module.md) } | 定义触摸测试类型的枚举值。  | 
| { [UI_MOUSE_EVENT_ACTION_UNKNOWN](_ark_u_i___event_module.md) = 0, [UI_MOUSE_EVENT_ACTION_PRESS](_ark_u_i___event_module.md) = 1, [UI_MOUSE_EVENT_ACTION_RELEASE](_ark_u_i___event_module.md) = 2, [UI_MOUSE_EVENT_ACTION_MOVE](_ark_u_i___event_module.md) = 3 } | 定义鼠标事件的Action Code。  | 
| {<br/>[UI_MOUSE_EVENT_BUTTON_NONE](_ark_u_i___event_module.md) = 0, [UI_MOUSE_EVENT_BUTTON_LEFT](_ark_u_i___event_module.md) = 1, [UI_MOUSE_EVENT_BUTTON_RIGHT](_ark_u_i___event_module.md) = 2, [UI_MOUSE_EVENT_BUTTON_MIDDLE](_ark_u_i___event_module.md) = 3,<br/>[UI_MOUSE_EVENT_BUTTON_BACK](_ark_u_i___event_module.md) = 4, [UI_MOUSE_EVENT_BUTTON_FORWARD](_ark_u_i___event_module.md) = 5<br/>} | 定义鼠标事件的按键类型。  | 
| [ArkUI_ModifierKeyName](_ark_u_i___event_module.md#arkui_modifierkeyname) { [ARKUI_MODIFIER_KEY_CTRL](_ark_u_i___event_module.md) = 1 &lt;&lt; 0, [ARKUI_MODIFIER_KEY_SHIFT](_ark_u_i___event_module.md) = 1 &lt;&lt; 1, [ARKUI_MODIFIER_KEY_ALT](_ark_u_i___event_module.md) = 1 &lt;&lt; 2, [ARKUI_MODIFIER_KEY_FN](_ark_u_i___event_module.md) = 1 &lt;&lt; 3 } | 定义modifier按键。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_UIInputEvent_GetType](_ark_u_i___event_module.md#oh_arkui_uiinputevent_gettype) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取UI输入事件的类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetAction](_ark_u_i___event_module.md#oh_arkui_uiinputevent_getaction) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取UI输入事件的操作类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetSourceType](_ark_u_i___event_module.md#oh_arkui_uiinputevent_getsourcetype) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取产生UI输入事件的来源类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetToolType](_ark_u_i___event_module.md#oh_arkui_uiinputevent_gettooltype) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取产生UI输入事件的工具类型。  | 
| int64_t [OH_ArkUI_UIInputEvent_GetEventTime](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtime) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取UI输入事件发生的时间。  | 
| uint32_t [OH_ArkUI_PointerEvent_GetPointerCount](_ark_u_i___event_module.md#oh_arkui_pointerevent_getpointercount) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。  | 
| int32_t [OH_ArkUI_PointerEvent_GetPointerId](_ark_u_i___event_module.md#oh_arkui_pointerevent_getpointerid) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。  | 
| float [OH_ArkUI_PointerEvent_GetX](_ark_u_i___event_module.md#oh_arkui_pointerevent_getx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetXByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getxbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetY](_ark_u_i___event_module.md#oh_arkui_pointerevent_gety) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetYByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getybyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowX](_ark_u_i___event_module.md#oh_arkui_pointerevent_getwindowx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowXByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getwindowxbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowY](_ark_u_i___event_module.md#oh_arkui_pointerevent_getwindowy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowYByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getwindowybyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayX](_ark_u_i___event_module.md#oh_arkui_pointerevent_getdisplayx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayXByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getdisplayxbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayY](_ark_u_i___event_module.md#oh_arkui_pointerevent_getdisplayy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayYByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getdisplayybyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetPressure](_ark_u_i___event_module.md#oh_arkui_pointerevent_getpressure) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取触屏压力。  | 
| float [OH_ArkUI_PointerEvent_GetTiltX](_ark_u_i___event_module.md#oh_arkui_pointerevent_gettiltx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。  | 
| float [OH_ArkUI_PointerEvent_GetTiltY](_ark_u_i___event_module.md#oh_arkui_pointerevent_gettilty) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取相对XZ平面的角度，值的范围[-90, 90]，其中正值是向下倾斜。  | 
| float [OH_ArkUI_PointerEvent_GetTouchAreaWidth](_ark_u_i___event_module.md#oh_arkui_pointerevent_gettouchareawidth) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取触屏区域的宽度。  | 
| float [OH_ArkUI_PointerEvent_GetTouchAreaHeight](_ark_u_i___event_module.md#oh_arkui_pointerevent_gettouchareaheight) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取触屏区域的高度。  | 
| uint32_t [OH_ArkUI_PointerEvent_GetHistorySize](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorysize) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件数量。  | 
| int64_t [OH_ArkUI_PointerEvent_GetHistoryEventTime](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistoryeventtime) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件发生的时间。  | 
| uint32_t [OH_ArkUI_PointerEvent_GetHistoryPointerCount](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorypointercount) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中多点触控的接触点数量。  | 
| int32_t [OH_ArkUI_PointerEvent_GetHistoryPointerId](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorypointerid) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryX](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistoryx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryY](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistoryy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryWindowX](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorywindowx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryWindowY](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorywindowy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryDisplayX](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorydisplayx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryDisplayY](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorydisplayy) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryPressure](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorypressure) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏压力。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTiltX](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorytiltx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTiltY](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorytilty) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对XZ平面的角度，值的范围[-90, 90]，其中正值是向下倾斜。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorytouchareawidth) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的宽度。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight](_ark_u_i___event_module.md#oh_arkui_pointerevent_gethistorytouchareaheight) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的高度。  | 
| double [OH_ArkUI_AxisEvent_GetVerticalAxisValue](_ark_u_i___event_module.md#oh_arkui_axisevent_getverticalaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的垂直滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetHorizontalAxisValue](_ark_u_i___event_module.md#oh_arkui_axisevent_gethorizontalaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的水平滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetPinchAxisScaleValue](_ark_u_i___event_module.md#oh_arkui_axisevent_getpinchaxisscalevalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的捏合轴缩放的值。  | 
| int32_t [OH_ArkUI_PointerEvent_SetInterceptHitTestMode](_ark_u_i___event_module.md#oh_arkui_pointerevent_setintercepthittestmode) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [HitTestMode](_ark_u_i___event_module.md#hittestmode) mode) | 配置HitTest模式。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseButton](_ark_u_i___event_module.md#oh_arkui_mouseevent_getmousebutton) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取鼠标事件的按键类型的值。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseAction](_ark_u_i___event_module.md#oh_arkui_mouseevent_getmouseaction) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取鼠标事件的鼠标动作类型的值。  | 
| int32_t [OH_ArkUI_PointerEvent_SetStopPropagation](_ark_u_i___event_module.md#oh_arkui_pointerevent_setstoppropagation) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool stopPropagation) | 设置是否阻止事件冒泡。  | 
