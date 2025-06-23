# ui_input_event.h


## 概述

提供ArkUI在Native侧的事件定义。

**库：** libace_ndk.z.so

**引用文件：** <arkui/ui_input_event.h>

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
| [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) { **ARKUI_UIINPUTEVENT_TYPE_UNKNOWN** = 0, **ARKUI_UIINPUTEVENT_TYPE_TOUCH** = 1, **ARKUI_UIINPUTEVENT_TYPE_AXIS** = 2, **ARKUI_UIINPUTEVENT_TYPE_MOUSE** = 3, **ARKUI_UIINPUTEVENT_TYPE_KEY** = 4 } | UI输入事件类型定义。  | 
| {<br/>[UI_TOUCH_EVENT_ACTION_CANCEL](_ark_u_i___event_module.md) = 0,<br/>[UI_TOUCH_EVENT_ACTION_DOWN](_ark_u_i___event_module.md) = 1, [UI_TOUCH_EVENT_ACTION_MOVE](_ark_u_i___event_module.md) = 2, [UI_TOUCH_EVENT_ACTION_UP](_ark_u_i___event_module.md) = 3<br/>} | 定义输入事件的Action Code。  | 
| {<br/>[UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN](_ark_u_i___event_module.md) = 0, [UI_INPUT_EVENT_TOOL_TYPE_FINGER](_ark_u_i___event_module.md) = 1, [UI_INPUT_EVENT_TOOL_TYPE_PEN](_ark_u_i___event_module.md) = 2, [UI_INPUT_EVENT_TOOL_TYPE_MOUSE](_ark_u_i___event_module.md) = 3,<br/>[UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD](_ark_u_i___event_module.md) = 4, [UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK](_ark_u_i___event_module.md) = 5<br/>} | 产生输入事件的工具类型定义。  | 
| { [UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN](_ark_u_i___event_module.md) = 0, [UI_INPUT_EVENT_SOURCE_TYPE_MOUSE](_ark_u_i___event_module.md) = 1, [UI_INPUT_EVENTT_SOURCE_TYPE_TOUCH_SCREEN](_ark_u_i___event_module.md) = 2 } | 产生输入事件的来源类型定义。  | 
| [HitTestMode](_ark_u_i___event_module.md#hittestmode) { [HTM_DEFAULT](_ark_u_i___event_module.md) = 0, [HTM_BLOCK](_ark_u_i___event_module.md), [HTM_TRANSPARENT](_ark_u_i___event_module.md), [HTM_NONE](_ark_u_i___event_module.md) } | 定义触摸测试类型的枚举值。  | 
| { [UI_MOUSE_EVENT_ACTION_UNKNOWN](_ark_u_i___event_module.md) = 0, [UI_MOUSE_EVENT_ACTION_PRESS](_ark_u_i___event_module.md) = 1, [UI_MOUSE_EVENT_ACTION_RELEASE](_ark_u_i___event_module.md) = 2, [UI_MOUSE_EVENT_ACTION_MOVE](_ark_u_i___event_module.md) = 3, [UI_MOUSE_EVENT_ACTION_CANCEL](_ark_u_i___event_module.md) = 13, } | 定义鼠标事件的Action Code。  | 
| {<br/>[UI_MOUSE_EVENT_BUTTON_NONE](_ark_u_i___event_module.md) = 0, [UI_MOUSE_EVENT_BUTTON_LEFT](_ark_u_i___event_module.md) = 1, [UI_MOUSE_EVENT_BUTTON_RIGHT](_ark_u_i___event_module.md) = 2, [UI_MOUSE_EVENT_BUTTON_MIDDLE](_ark_u_i___event_module.md) = 3,<br/>[UI_MOUSE_EVENT_BUTTON_BACK](_ark_u_i___event_module.md) = 4, [UI_MOUSE_EVENT_BUTTON_FORWARD](_ark_u_i___event_module.md) = 5<br/>} | 定义鼠标事件的按键类型。  | 
| [ArkUI_ModifierKeyName](_ark_u_i___event_module.md#arkui_modifierkeyname) { [ARKUI_MODIFIER_KEY_CTRL](_ark_u_i___event_module.md) = 1 &lt;&lt; 0, [ARKUI_MODIFIER_KEY_SHIFT](_ark_u_i___event_module.md) = 1 &lt;&lt; 1, [ARKUI_MODIFIER_KEY_ALT](_ark_u_i___event_module.md) = 1 &lt;&lt; 2, [ARKUI_MODIFIER_KEY_FN](_ark_u_i___event_module.md) = 1 &lt;&lt; 3 } | 定义modifier按键。  | 
| {<br/>[UI_FOCUS_AXIS_EVENT_ABS_X](_ark_u_i___event_module.md) = 0, [UI_FOCUS_AXIS_EVENT_ABS_Y](_ark_u_i___event_module.md) = 1, [UI_FOCUS_AXIS_EVENT_ABS_Z](_ark_u_i___event_module.md) = 2, [UI_FOCUS_AXIS_EVENT_ABS_RZ](_ark_u_i___event_module.md) = 3,<br/>[UI_FOCUS_AXIS_EVENT_ABS_GAS](_ark_u_i___event_module.md) = 4, [UI_FOCUS_AXIS_EVENT_ABS_BRAKE](_ark_u_i___event_module.md) = 5, [UI_FOCUS_AXIS_EVENT_ABS_HAT0X](_ark_u_i___event_module.md) = 6, [UI_FOCUS_AXIS_EVENT_ABS_HAT0Y](_ark_u_i___event_module.md) = 7<br/>} | 定义焦点轴事件的轴类型。  | 
| [ArkUI_InteractionHand](_ark_u_i___event_module.md#interactionhand){<br/>[ARKUI_EVENT_HAND_NONE](_ark_u_i___event_module.md#interactionhand) = 0, [ARKUI_EVENT_HAND_LEFT](_ark_u_i___event_module.md#interactionhand) = 1, [ARKUI_EVENT_HAND_RIGHT](_ark_u_i___event_module.md#interactionhand) = 2} | 定义事件是由左手点击触发还是右手点击触发。  | 
| {<br/>[UI_AXIS_EVENT_ACTION_NONE](_ark_u_i___event_module.md) = 0, [UI_AXIS_EVENT_ACTION_BEGIN](_ark_u_i___event_module.md) = 1, [UI_AXIS_EVENT_ACTION_UPDATE](_ark_u_i___event_module.md) = 2, [UI_AXIS_EVENT_ACTION_END](_ark_u_i___event_module.md) = 3, [UI_AXIS_EVENT_ACTION_CANCEL](_ark_u_i___event_module.md) = 4<br/>} | 定义轴事件的Action Code。  | 


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
| int32_t [OH_ArkUI_PointerEvent_GetChangedPointerId](_ark_u_i___event_module.md#oh_arkui_pointerevent_getchangedpointerid) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint32_t \*pointerIndex) | 获取当前触摸事件触发的id。  | 
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
| int32_t [OH_ArkUI_PointerEvent_GetRollAngle](_ark_u_i___event_module.md#oh_arkui_pointerevent_getrollangle) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, double \*rollAngle) | 从带有指向性的输入事件（如触摸事件）中获取手写笔与设备平面的夹角。  | 
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
| int32_t [OH_ArkUI_AxisEvent_GetAxisAction](_ark_u_i___event_module.md#oh_arkui_axisevent_getaxisaction)(const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前轴事件的操作类型的值。  | 
| int32_t [OH_ArkUI_AxisEvent_SetPropagation](_ark_u_i___event_module.md#oh_arkui_axisevent_setpropagation)(const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool propagation) | 设置是否激活轴事件冒泡。|
| int32_t [OH_ArkUI_AxisEvent_GetScrollStep](_ark_u_i___event_module.md#oh_arkui_axisevent_getscrollstep)(const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取鼠标滚轮轴滚动步长配置。|
| int32_t [OH_ArkUI_PointerEvent_SetInterceptHitTestMode](_ark_u_i___event_module.md#oh_arkui_pointerevent_setintercepthittestmode) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [HitTestMode](_ark_u_i___event_module.md#hittestmode) mode) | 配置HitTest模式。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseButton](_ark_u_i___event_module.md#oh_arkui_mouseevent_getmousebutton) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取鼠标事件的按键类型的值。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseAction](_ark_u_i___event_module.md#oh_arkui_mouseevent_getmouseaction) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取鼠标事件的鼠标动作类型的值。  | 
| int32_t [OH_ArkUI_PointerEvent_SetStopPropagation](_ark_u_i___event_module.md#oh_arkui_pointerevent_setstoppropagation) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool stopPropagation) | 设置是否阻止事件冒泡。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetDeviceId](_ark_u_i___event_module.md#oh_arkui_uiinputevent_getdeviceid) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取当前按键的输入设备ID。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetPressedKeys](_ark_u_i___event_module.md#oh_arkui_uiinputevent_getpressedkeys) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t \*pressedKeyCodes, int32_t \*length) | 获取所有按下的按键，当前只支持按键事件。  | 
| double [OH_ArkUI_FocusAxisEvent_GetAxisValue](_ark_u_i___event_module.md#oh_arkui_focusaxisevent_getaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t \*axis) | 获取焦点轴事件的轴值。  | 
| int32_t [OH_ArkUI_FocusAxisEvent_SetStopPropagation](_ark_u_i___event_module.md#oh_arkui_focusaxisevent_setstoppropagation) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool \*stopPropagation) | 设置是否阻止焦点轴事件冒泡。  | 
| int32_t [OH_ArkUI_PointerEvent_GetInteractionHand](_ark_u_i___event_module.md#oh_arkui_pointerevent_getinteractionhand) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [ArkUI_InteractionHand](_ark_u_i___event_module.md#interactionhand) \*hand) | 获取当前触摸事件是左手点击触发还是右手点击触发。  | 
| int32_t [OH_ArkUI_PointerEvent_GetInteractionHandByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getinteractionhandbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t pointerIndex, [ArkUI_InteractionHand](_ark_u_i___event_module.md#interactionhand) \*hand) | 获取当前触摸事件是左手点击触发还是右手点击触发。  | 
| int32_t [OH_ArkUI_PointerEvent_CreateClonedEvent](_ark_u_i___event_module.md#oh_arkui_pointerevent_createclonedevent) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*clonedevent) | 基于原始事件指针创建克隆事件指针。  | 
| int32_t [OH_ArkUI_PointerEvent_DestroyClonedEvent](_ark_u_i___event_module.md#oh_arkui_pointerevent_destroyclonedevent) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 销毁克隆事件指针。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventLocalPosition](_ark_u_i___event_module.md#oh_arkui_pointerevent_setclonedeventlocalposition) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, float x, float y) | 设置指向性事件相对于当前组件左上角的X坐标和Y坐标。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_setclonedeventlocalpositionbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, float x, float y, int32_t pointerIndex) | 设置指向性事件特有接触点相对于当前组件左上角的X坐标和Y坐标。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventActionType](_ark_u_i___event_module.md#oh_arkui_pointerevent_setclonedeventactiontype) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t actionType) | 设置当前带有指向性的克隆输入事件的事件类型。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId](_ark_u_i___event_module.md#oh_arkui_pointerevent_setclonedeventchangedfingerid) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t fingerId) | 设置当前带有指向性的克隆输入事件的触摸点ID。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_setclonedeventfingeridbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t fingerId, int32_t pointerIndexe) | 设置带有指向性的克隆输入事件特定接触点的触摸点ID。  | 
| int32_t [OH_ArkUI_PointerEvent_PostClonedEvent](_ark_u_i___event_module.md#oh_arkui_pointerevent_postclonedevent) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) \*node, const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 转发克隆事件到特定节点。  | 
| int64_t [OH_ArkUI_PointerEvent_GetPressedTimeByIndex](_ark_u_i___event_module.md#oh_arkui_pointerevent_getpressedtimebyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t pointerIndex) | 获取特定触摸点的按压时间。  | 
| float [OH_ArkUI_MouseEvent_GetRawDeltaX](_ark_u_i___event_module.md#oh_arkui_mouseevent_getrawdeltax) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取X轴相对于前一个上报的鼠标事件的鼠标指针位置的偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的X坐标的差。  | 
| float [OH_ArkUI_MouseEvent_GetRawDeltaY](_ark_u_i___event_module.md#oh_arkui_mouseevent_getrawdeltay) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取相对于前一个上报的鼠标事件的鼠标指针位置的Y轴偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的Y坐标的差。  | 
| int32_t [OH_ArkUI_MouseEvent_GetPressedButtons](_ark_u_i___event_module.md#oh_arkui_mouseevent_getpressedbuttons) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t* pressedButtons, int32_t* length) | 从鼠标事件中获取按下的按钮。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetTargetDisplayId](_ark_u_i___event_module.md#oh_arkui_uiinputevent_gettargetdisplayid) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取发生UI输入事件的屏幕ID。  | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetWidth](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetwidth) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取事件命中的组件的宽度。  | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetHeight](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetheight) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取事件命中的组件的高度。  | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetPositionX](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetpositionx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取事件命中的组件的X坐标。  | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetPositionY](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetpositiony) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取事件命中的组件的Y坐标。  | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetglobalpositionx) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取事件命中的组件的全局X坐标。  | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY](_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetglobalpositiony) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取事件命中的组件的全局Y坐标。  | 
| bool [OH_ArkUI_HoverEvent_IsHovered](_ark_u_i___event_module.md#oh_arkui_hoverevent_ishovered) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event) | 获取鼠标是否悬浮在当前组件上。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetModifierKeyStates](_ark_u_i___event_module.md#oh_arkui_uiinputevent_getmodifierkeystates) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, uint64_t keys) | 获取UI输入事件的功能键按压状态。  | 
| ArkUI_ErrorCode [OH_ArkUI_UIInputEvent_GetLatestStatus](_ark_u_i___event_module.md#oh_arkui_uiinputevent_getlateststatus)() | 调用该方法获取最近一次UIInput相关方法的执行情况。通常情况下不需要使用该方法，仅在返回值结果不确定是否异常时使用。<br>**起始版本：** 20 |
