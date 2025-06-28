# ArkUI_EventModule


## 概述

在Native端提供ArkUI的UI输入事件能力。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ui_input_event.h](ui__input__event_8h.md) | 提供ArkUI在Native侧的事件定义。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [ArkUI_UIInputEvent](#arkui_uiinputevent) [ArkUI_UIInputEvent](#arkui_uiinputevent) | UI输入事件定义。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) { ARKUI_UIINPUTEVENT_TYPE_UNKNOWN = 0, ARKUI_UIINPUTEVENT_TYPE_TOUCH = 1, ARKUI_UIINPUTEVENT_TYPE_AXIS = 2, ARKUI_UIINPUTEVENT_TYPE_MOUSE = 3, ARKUI_UIINPUTEVENT_TYPE_KEY = 4<sup>20+</sup> } | UI输入事件类型定义。  | 
| {<br/>UI_TOUCH_EVENT_ACTION_CANCEL = 0,<br/>UI_TOUCH_EVENT_ACTION_DOWN = 1, UI_TOUCH_EVENT_ACTION_MOVE = 2, UI_TOUCH_EVENT_ACTION_UP = 3<br/>} | 定义输入事件的Action Code。  | 
| {<br/>UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN = 0, UI_INPUT_EVENT_TOOL_TYPE_FINGER = 1, UI_INPUT_EVENT_TOOL_TYPE_PEN = 2, UI_INPUT_EVENT_TOOL_TYPE_MOUSE = 3,<br/>UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD = 4, UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK = 5<br/>} | 产生输入事件的工具类型定义。  | 
| { UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN = 0, UI_INPUT_EVENT_SOURCE_TYPE_MOUSE = 1, UI_INPUT_EVENT_SOURCE_TYPE_TOUCH_SCREEN = 2 } | 产生输入事件的来源类型定义。  | 
| [HitTestMode](#hittestmode) { HTM_DEFAULT = 0, HTM_BLOCK, HTM_TRANSPARENT, HTM_NONE } | 定义触摸测试类型的枚举值。  | 
| { UI_MOUSE_EVENT_ACTION_UNKNOWN = 0, UI_MOUSE_EVENT_ACTION_PRESS = 1, UI_MOUSE_EVENT_ACTION_RELEASE = 2, UI_MOUSE_EVENT_ACTION_MOVE = 3, UI_MOUSE_EVENT_ACTION_CANCEL = 13 } | 定义鼠标事件的Action Code。  | 
| {<br/>UI_MOUSE_EVENT_BUTTON_NONE = 0, UI_MOUSE_EVENT_BUTTON_LEFT = 1, UI_MOUSE_EVENT_BUTTON_RIGHT = 2, UI_MOUSE_EVENT_BUTTON_MIDDLE = 3,<br/>UI_MOUSE_EVENT_BUTTON_BACK = 4, UI_MOUSE_EVENT_BUTTON_FORWARD = 5<br/>} | 定义鼠标事件的按键类型。  | 
| [ArkUI_ModifierKeyName](#arkui_modifierkeyname) { ARKUI_MODIFIER_KEY_CTRL = 1 &lt;&lt; 0, ARKUI_MODIFIER_KEY_SHIFT = 1 &lt;&lt; 1, ARKUI_MODIFIER_KEY_ALT = 1 &lt;&lt; 2, ARKUI_MODIFIER_KEY_FN = 1 &lt;&lt; 3 } | 定义modifier按键。  | 
| {<br/>UI_FOCUS_AXIS_EVENT_ABS_X = 0, UI_FOCUS_AXIS_EVENT_ABS_Y = 1, UI_FOCUS_AXIS_EVENT_ABS_Z = 2, UI_FOCUS_AXIS_EVENT_ABS_RZ = 3,<br/>UI_FOCUS_AXIS_EVENT_ABS_GAS = 4, UI_FOCUS_AXIS_EVENT_ABS_BRAKE = 5, UI_FOCUS_AXIS_EVENT_ABS_HAT0X = 6, UI_FOCUS_AXIS_EVENT_ABS_HAT0Y = 7<br/>} | 定义焦点轴事件的轴类型。  | 
| {<br/>ARKUI_EVENT_HAND_NONE = 0, ARKUI_EVENT_HAND_LEFT = 1, ARKUI_EVENT_HAND_RIGHT = 2<br/>} | 定义事件是由左手点击触发还是右手点击触发。  | 
| {<br/>UI_AXIS_EVENT_ACTION_NONE = 0, UI_AXIS_EVENT_ACTION_BEGIN = 1, UI_AXIS_EVENT_ACTION_UPDATE = 2, UI_AXIS_EVENT_ACTION_END = 3, UI_AXIS_EVENT_ACTION_CANCEL = 4<br/>} | 定义轴事件的操作类型。  | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_UIInputEvent_GetType](#oh_arkui_uiinputevent_gettype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件的类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetAction](#oh_arkui_uiinputevent_getaction) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件的操作类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetSourceType](#oh_arkui_uiinputevent_getsourcetype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取产生UI输入事件的来源类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetToolType](#oh_arkui_uiinputevent_gettooltype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取产生UI输入事件的工具类型。  | 
| int64_t [OH_ArkUI_UIInputEvent_GetEventTime](#oh_arkui_uiinputevent_geteventtime) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件发生的时间。单位为ns。  | 
| uint32_t [OH_ArkUI_PointerEvent_GetPointerCount](#oh_arkui_pointerevent_getpointercount) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。  | 
| int32_t [OH_ArkUI_PointerEvent_GetPointerId](#oh_arkui_pointerevent_getpointerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。  | 
| int32_t [OH_ArkUI_PointerEvent_GetChangedPointerId](#oh_arkui_pointerevent_getchangedpointerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t \*pointerIndex) | 获取当前触摸事件触发的id。  | 
| float [OH_ArkUI_PointerEvent_GetX](#oh_arkui_pointerevent_getx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetXByIndex](#oh_arkui_pointerevent_getxbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetY](#oh_arkui_pointerevent_gety) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetYByIndex](#oh_arkui_pointerevent_getybyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowX](#oh_arkui_pointerevent_getwindowx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowXByIndex](#oh_arkui_pointerevent_getwindowxbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowY](#oh_arkui_pointerevent_getwindowy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetWindowYByIndex](#oh_arkui_pointerevent_getwindowybyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayX](#oh_arkui_pointerevent_getdisplayx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayXByIndex](#oh_arkui_pointerevent_getdisplayxbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayY](#oh_arkui_pointerevent_getdisplayy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetDisplayYByIndex](#oh_arkui_pointerevent_getdisplayybyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetPressure](#oh_arkui_pointerevent_getpressure) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取触屏压力。  | 
| float [OH_ArkUI_PointerEvent_GetTiltX](#oh_arkui_pointerevent_gettiltx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。  | 
| float [OH_ArkUI_PointerEvent_GetTiltY](#oh_arkui_pointerevent_gettilty) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从指向性输入事件（如触摸事件）中获取相对XZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。<br/>仅适用于支持倾角上报的触控笔操作产生的触控事件。  | 
| int32_t [OH_ArkUI_PointerEvent_GetRollAngle](#oh_arkui_pointerevent_getrollangle) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, double \*rollAngle) | 获取触控笔绕Z轴旋转的角度。<br/>**起始版本：** 17  | 
| float [OH_ArkUI_PointerEvent_GetTouchAreaWidth](#oh_arkui_pointerevent_gettouchareawidth) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取触屏区域的宽度。  | 
| float [OH_ArkUI_PointerEvent_GetTouchAreaHeight](#oh_arkui_pointerevent_gettouchareaheight) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取触屏区域的高度。  | 
| uint32_t [OH_ArkUI_PointerEvent_GetHistorySize](#oh_arkui_pointerevent_gethistorysize) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件数量。  | 
| int64_t [OH_ArkUI_PointerEvent_GetHistoryEventTime](#oh_arkui_pointerevent_gethistoryeventtime) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件发生的时间。  | 
| uint32_t [OH_ArkUI_PointerEvent_GetHistoryPointerCount](#oh_arkui_pointerevent_gethistorypointercount) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中多点触控的接触点数量。  | 
| int32_t [OH_ArkUI_PointerEvent_GetHistoryPointerId](#oh_arkui_pointerevent_gethistorypointerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryX](#oh_arkui_pointerevent_gethistoryx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryY](#oh_arkui_pointerevent_gethistoryy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryWindowX](#oh_arkui_pointerevent_gethistorywindowx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryWindowY](#oh_arkui_pointerevent_gethistorywindowy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryDisplayX](#oh_arkui_pointerevent_gethistorydisplayx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的X坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryDisplayY](#oh_arkui_pointerevent_gethistorydisplayy) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的Y坐标。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryPressure](#oh_arkui_pointerevent_gethistorypressure) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏压力。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTiltX](#oh_arkui_pointerevent_gethistorytiltx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTiltY](#oh_arkui_pointerevent_gethistorytilty) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对XZ平面的角度，值的范围[-90, 90]，其中正值是向下倾斜。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth](#oh_arkui_pointerevent_gethistorytouchareawidth) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的宽度。  | 
| float [OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight](#oh_arkui_pointerevent_gethistorytouchareaheight) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex, uint32_t historyIndex) | 从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的高度。  | 
| double [OH_ArkUI_AxisEvent_GetVerticalAxisValue](#oh_arkui_axisevent_getverticalaxisvalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前轴事件的垂直滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetHorizontalAxisValue](#oh_arkui_axisevent_gethorizontalaxisvalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前轴事件的水平滚动轴的值。  | 
| double [OH_ArkUI_AxisEvent_GetPinchAxisScaleValue](#oh_arkui_axisevent_getpinchaxisscalevalue) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前轴事件的捏合轴缩放的值。  | 
| int32_t [OH_ArkUI_AxisEvent_GetAxisAction](#oh_arkui_axisevent_getaxisaction)(const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前轴事件的操作类型的值。  | 
| int32_t [OH_ArkUI_PointerEvent_SetInterceptHitTestMode](#oh_arkui_pointerevent_setintercepthittestmode) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, [HitTestMode](#hittestmode) mode) | 配置HitTest模式。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseButton](#oh_arkui_mouseevent_getmousebutton) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取鼠标事件的按键类型的值。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseAction](#oh_arkui_mouseevent_getmouseaction) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取鼠标事件的鼠标动作类型的值。  | 
| int32_t [OH_ArkUI_PointerEvent_SetStopPropagation](#oh_arkui_pointerevent_setstoppropagation) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, bool stopPropagation) | 设置是否阻止事件冒泡。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetDeviceId](#oh_arkui_uiinputevent_getdeviceid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取当前按键的输入设备ID。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetPressedKeys](#oh_arkui_uiinputevent_getpressedkeys) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t \*pressedKeyCodes, int32_t \*length) | 获取所有按下的按键，当前只支持按键事件。  | 
| double [OH_ArkUI_FocusAxisEvent_GetAxisValue](#oh_arkui_focusaxisevent_getaxisvalue) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t \*axis) | 获取焦点轴事件的轴值。  | 
| int32_t [OH_ArkUI_FocusAxisEvent_SetStopPropagation](#oh_arkui_focusaxisevent_setstoppropagation) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, bool stopPropagation) | 设置是否阻止焦点轴事件冒泡。<br/>**起始版本：** 15  | 
| int32_t [OH_ArkUI_PointerEvent_GetInteractionHand](#oh_arkui_pointerevent_getinteractionhand) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [ArkUI_InteractionHand](_ark_u_i___event_module.md#interactionhand) \*hand) | 获取当前触摸事件是左手点击触发还是右手点击触发。  | 
| int32_t [OH_ArkUI_PointerEvent_GetInteractionHandByIndex](#oh_arkui_pointerevent_getinteractionhandbyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t pointerIndex, [ArkUI_InteractionHand](_ark_u_i___event_module.md#interactionhand) \*hand) | 获取当前触摸事件是左手点击触发还是右手点击触发。  | 
| float [OH_ArkUI_UIInputEvent_GetEventTargetWidth](#oh_arkui_uiinputevent_geteventtargetwidth) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | 获取事件命中的组件的宽度。  |
| float [OH_ArkUI_UIInputEvent_GetEventTargetHeight](#oh_arkui_uiinputevent_geteventtargetheight) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | 获取事件命中的组件的高度。  |
| float [OH_ArkUI_UIInputEvent_GetEventTargetPositionX](#oh_arkui_uiinputevent_geteventtargetpositionx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | 获取事件命中的组件的X坐标。  |
| float [OH_ArkUI_UIInputEvent_GetEventTargetPositionY](#oh_arkui_uiinputevent_geteventtargetpositiony) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | 获取事件命中的组件的Y坐标。  |
| float [OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX](#oh_arkui_uiinputevent_geteventtargetglobalpositionx) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | 获取事件命中的组件的全局X坐标。  |
| float [OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY](#oh_arkui_uiinputevent_geteventtargetglobalpositiony) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | 获取事件命中的组件的全局Y坐标。  |
| int32_t [OH_ArkUI_UIInputEvent_GetModifierKeyStates](#oh_arkui_uiinputevent_getmodifierkeystates) (const [ArkUI_UIInputEvent](#arkui_uiinputevent), uint64_t \*keys) | 获取UI输入事件的修饰键状态。该接口会通过keys传出当前事件发生时所有修饰键的状态。<br/>**起始版本：** 17  | 
| bool [OH_ArkUI_HoverEvent_IsHovered](#oh_arkui_hoverevent_ishovered) (const [ArkUI_UIInputEvent](#arkui_uiinputevent)) | 获取鼠标是否悬浮在当前组件上。  |    
| int32_t [OH_ArkUI_PointerEvent_CreateClonedEvent](#oh_arkui_pointerevent_createclonedevent) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, [ArkUI_UIInputEvent](#arkui_uiinputevent) \*\*clonedevent) | 基于原始事件指针创建克隆事件指针。仅对触摸事件有效。<br/>**起始版本：** 15  | 
| int32_t [OH_ArkUI_PointerEvent_DestroyClonedEvent](#oh_arkui_pointerevent_destroyclonedevent) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 销毁克隆事件指针。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventLocalPosition](#oh_arkui_pointerevent_setclonedeventlocalposition) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, float x, float y) | 设置指向性事件相对于当前组件左上角的X坐标和Y坐标。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex](#oh_arkui_pointerevent_setclonedeventlocalpositionbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, float x, float y, int32_t pointerIndex) | 设置指向性事件特有接触点相对于当前组件左上角的X坐标和Y坐标。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventActionType](#oh_arkui_pointerevent_setclonedeventactiontype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t actionType) | 设置当前带有指向性的克隆输入事件的事件类型。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId](#oh_arkui_pointerevent_setclonedeventchangedfingerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t fingerId) | 设置当前带有指向性的克隆输入事件的触摸点ID。  | 
| int32_t [OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex](#oh_arkui_pointerevent_setclonedeventfingeridbyindex) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t fingerId, int32_t pointerIndex) | 设置带有指向性的克隆输入事件特定接触点的触摸点ID。  | 
| int32_t [OH_ArkUI_PointerEvent_PostClonedEvent](#oh_arkui_pointerevent_postclonedevent) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) \*node, const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 转发克隆事件到特定节点。  | 
| int64_t [OH_ArkUI_PointerEvent_GetPressedTimeByIndex](#oh_arkui_pointerevent_getpressedtimebyindex) (const [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, int32_t pointerIndex) | 获取特定触摸点的按压时间。  | 
| float [OH_ArkUI_MouseEvent_GetRawDeltaX](#oh_arkui_mouseevent_getrawdeltax) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取X轴相对于前一个上报的鼠标事件的鼠标指针位置的偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的X坐标的差。  | 
| float [OH_ArkUI_MouseEvent_GetRawDeltaY](#oh_arkui_mouseevent_getrawdeltay) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取相对于前一个上报的鼠标事件的鼠标指针位置的Y轴偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的Y坐标的差。  | 
| int32_t [OH_ArkUI_MouseEvent_GetPressedButtons](#oh_arkui_mouseevent_getpressedbuttons) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, int32_t* pressedButtons, int32_t* length) | 从鼠标事件中获取按下的按钮。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetTargetDisplayId](#oh_arkui_uiinputevent_gettargetdisplayid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取发生UI输入事件的屏幕ID。 | 
| int32_t [OH_ArkUI_AxisEvent_SetPropagation](#oh_arkui_axisevent_setpropagation)(const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, bool propagation) | 设置是否激活轴事件冒泡。|
| int32_t [OH_ArkUI_AxisEvent_GetScrollStep](#oh_arkui_axisevent_getscrollstep)(const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取滚动轴事件的滚动步长系数，适用于鼠标滚轮产生的轴事件。这个值可以告诉你用户所配置的滚动放大系数。<br/>**起始版本：** 17|
| ArkUI_ErrorCode [OH_ArkUI_UIInputEvent_GetLatestStatus](#oh_arkui_uiinputevent_getlateststatus)() | 调用该方法获取最近一次UIInput相关方法的执行情况。通常情况下不需要使用该方法，仅在返回值结果不确定是否异常时使用。<br>**起始版本：** 20 |


## 类型定义说明


### ArkUI_UIInputEvent

```
typedef struct ArkUI_UIInputEvent ArkUI_UIInputEvent
```
**描述：**

UI输入事件定义。

**起始版本：** 12


## 枚举类型说明


### anonymous enum

```
anonymous enum
```
**描述：**

定义输入事件的Action Code。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_TOUCH_EVENT_ACTION_CANCEL  | 触摸取消。  | 
| UI_TOUCH_EVENT_ACTION_DOWN  | 触摸按下。  | 
| UI_TOUCH_EVENT_ACTION_MOVE  | 触摸移动。  | 
| UI_TOUCH_EVENT_ACTION_UP  | 触摸抬起。  | 


### anonymous enum

```
anonymous enum
```
**描述：**

产生输入事件的工具类型定义。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN  | 不支持的工具类型。  | 
| UI_INPUT_EVENT_TOOL_TYPE_FINGER  | 手指。  | 
| UI_INPUT_EVENT_TOOL_TYPE_PEN  | 笔。  | 
| UI_INPUT_EVENT_TOOL_TYPE_MOUSE  | 鼠标。  | 
| UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD  | 触控板。  | 
| UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK  | 操纵杆。  | 


### anonymous enum

```
anonymous enum
```
**描述：**

产生输入事件的来源类型定义。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN  | 不支持的来源类型。  | 
| UI_INPUT_EVENT_SOURCE_TYPE_MOUSE  | 鼠标。  | 
| UI_INPUT_EVENT_SOURCE_TYPE_TOUCH_SCREEN  | 触摸屏。  | 


### anonymous enum

```
anonymous enum
```
**描述：**

定义鼠标事件的Action Code。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_MOUSE_EVENT_ACTION_UNKNOWN  | 无效行为。  | 
| UI_MOUSE_EVENT_ACTION_PRESS  | 鼠标按键按下。  | 
| UI_MOUSE_EVENT_ACTION_RELEASE  | 鼠标按键松开。  | 
| UI_MOUSE_EVENT_ACTION_MOVE  | 鼠标移动。  | 
| UI_MOUSE_EVENT_ACTION_CANCEL  | 鼠标按键被取消。<br/>**起始版本：** 18  | 


### anonymous enum

```
anonymous enum
```
**描述：**

定义鼠标事件的按键类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_MOUSE_EVENT_BUTTON_NONE  | 无按键。  | 
| UI_MOUSE_EVENT_BUTTON_LEFT  | 鼠标左键。  | 
| UI_MOUSE_EVENT_BUTTON_RIGHT  | 鼠标右键。  | 
| UI_MOUSE_EVENT_BUTTON_MIDDLE  | 鼠标中键。  | 
| UI_MOUSE_EVENT_BUTTON_BACK  | 鼠标左侧后退键。  | 
| UI_MOUSE_EVENT_BUTTON_FORWARD  | 鼠标左侧前进键。  | 


### ArkUI_ModifierKeyName

```
enum ArkUI_ModifierKeyName
```
**描述：**

定义modifier按键。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_MODIFIER_KEY_CTRL  | Ctrl.  | 
| ARKUI_MODIFIER_KEY_SHIFT  | Shift.  | 
| ARKUI_MODIFIER_KEY_ALT  | Alt.  | 
| ARKUI_MODIFIER_KEY_FN  | Fn（仅调试使用，通常不上报Fn状态）.  | 


### ArkUI_UIInputEvent_Type

```
enum ArkUI_UIInputEvent_Type
```
**描述：**

UI输入事件类型定义。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_UIINPUTEVENT_TYPE_UNKNOWN  | 未定义。 | 
| ARKUI_UIINPUTEVENT_TYPE_TOUCH  | 触摸事件。  | 
| ARKUI_UIINPUTEVENT_TYPE_AXIS  | 轴事件。  | 
| ARKUI_UIINPUTEVENT_TYPE_MOUSE  | 鼠标事件。  | 
| ARKUI_UIINPUTEVENT_TYPE_KEY  | 按键事件。  | 

### HitTestMode

```
enum HitTestMode
```
**描述：**

定义触摸测试类型的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HTM_DEFAULT  | 默认触摸测试效果，自身和子节点都响应触摸测试，但会阻塞兄弟节点的触摸测试。  | 
| HTM_BLOCK  | 自身响应触摸测试，阻塞子节点和兄弟节点的触摸测试。  | 
| HTM_TRANSPARENT  | 自身和子节点都响应触摸测试，不会阻塞兄弟节点的触摸测试。  | 
| HTM_NONE  | 自身不响应触摸测试，不会阻塞子节点和兄弟节点的触摸测试。  | 


### anonymous enum

```
anonymous enum
```
**描述：**

定义焦点轴事件的轴类型。

**起始版本：** 15

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_FOCUS_AXIS_EVENT_ABS_X  | 游戏手柄X轴。  | 
| UI_FOCUS_AXIS_EVENT_ABS_Y  | 游戏手柄Y轴。 | 
| UI_FOCUS_AXIS_EVENT_ABS_Z  | 游戏手柄Z轴。  | 
| UI_FOCUS_AXIS_EVENT_ABS_RZ  | 游戏手柄RZ轴。  | 
| UI_FOCUS_AXIS_EVENT_ABS_GAS  | 游戏手柄GAS轴。 | 
| UI_FOCUS_AXIS_EVENT_ABS_BRAKE  | 游戏手柄BRAKE轴。   | 
| UI_FOCUS_AXIS_EVENT_ABS_HAT0X  | 游戏手柄HAT0X轴。   | 
| UI_FOCUS_AXIS_EVENT_ABS_HAT0Y  | 游戏手柄HAT0Y轴。 | 

### InteractionHand

```
enum ArkUI_InteractionHand
```
**描述：**

定义事件是由左手点击触发还是右手点击触发。

**起始版本：** 15

| 枚举值 | 描述 | 
| -------- | -------- |
| ARKUI_EVENT_HAND_NONE  | 未知。  | 
| ARKUI_EVENT_HAND_LEFT  | 左手。  | 
| ARKUI_EVENT_HAND_RIGHT  | 右手。  | 

```
anonymous enum
```
**描述：**

定义轴事件的操作类型。

**起始版本：** 15

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_AXIS_EVENT_ACTION_NONE  | 轴事件异常。 | 
| UI_AXIS_EVENT_ACTION_BEGIN  | 轴事件开始。 | 
| UI_AXIS_EVENT_ACTION_UPDATE  | 轴事件更新。 | 
| UI_AXIS_EVENT_ACTION_END  | 轴事件结束。  | 
| UI_AXIS_EVENT_ACTION_CANCEL  | 轴事件取消。 | 


## 函数说明


### OH_ArkUI_AxisEvent_GetHorizontalAxisValue()

```
double OH_ArkUI_AxisEvent_GetHorizontalAxisValue (const ArkUI_UIInputEvent * event)
```
**描述：**

获取当前轴事件的水平滚动轴的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前轴事件的水平滚动轴的值，如果参数异常则返回0.0。


### OH_ArkUI_AxisEvent_GetPinchAxisScaleValue()

```
double OH_ArkUI_AxisEvent_GetPinchAxisScaleValue (const ArkUI_UIInputEvent * event)
```
**描述：**

获取当前轴事件的捏合轴缩放的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前轴事件的捏合轴缩放的值，如果参数异常则返回0.0。


### OH_ArkUI_AxisEvent_GetVerticalAxisValue()

```
double OH_ArkUI_AxisEvent_GetVerticalAxisValue (const ArkUI_UIInputEvent * event)
```
**描述：**

获取当前轴事件的垂直滚动轴的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前轴事件的垂直滚动轴的值，如果参数异常则返回0.0。

### OH_ArkUI_AxisEvent_GetAxisAction()

```
int32_t OH_ArkUI_AxisEvent_GetAxisAction(const ArkUI_UIInputEvent* event)
```

**描述：**

获取当前轴事件的操作类型的值。

**起始版本：** 15

**参数:**

| 名称  | 描述 |
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前轴事件的操作类型的值。


### OH_ArkUI_MouseEvent_GetMouseAction()

```
int32_t OH_ArkUI_MouseEvent_GetMouseAction (const ArkUI_UIInputEvent * event)
```
**描述：**

获取鼠标事件的鼠标动作类型的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回鼠标动作类型，1表示按键按下，2表示按键松开，3表示鼠标移动。


### OH_ArkUI_MouseEvent_GetMouseButton()

```
int32_t OH_ArkUI_MouseEvent_GetMouseButton (const ArkUI_UIInputEvent * event)
```
**描述：**

获取鼠标事件的按键类型的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回鼠标按键类型，1为左键，2为右键，3为中键，4为后退键，5为前进键。


### OH_ArkUI_PointerEvent_GetDisplayX()

```
float OH_ArkUI_PointerEvent_GetDisplayX (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetDisplayXByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayXByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetDisplayY()

```
float OH_ArkUI_PointerEvent_GetDisplayY (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前屏幕左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetDisplayYByIndex()

```
float OH_ArkUI_PointerEvent_GetDisplayYByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前屏幕左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetHistoryDisplayX()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetHistoryDisplayY()

```
float OH_ArkUI_PointerEvent_GetHistoryDisplayY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前屏幕左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前屏幕左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetHistoryEventTime()

```
int64_t OH_ArkUI_PointerEvent_GetHistoryEventTime (const ArkUI_UIInputEvent * event, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件发生的时间。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回UI输入事件发生的时间，如果参数异常则返回0。


### OH_ArkUI_PointerEvent_GetHistoryPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetHistoryPointerCount (const ArkUI_UIInputEvent * event, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中多点触控的接触点数量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

特定历史事件中多点触控的接触点数量。


### OH_ArkUI_PointerEvent_GetHistoryPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetHistoryPointerId (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从指向性输入事件（如触摸事件）的历史点中获取多点触控的接触点标识。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回特定历史事件中的特定接触点标识。


### OH_ArkUI_PointerEvent_GetHistoryPressure()

```
float OH_ArkUI_PointerEvent_GetHistoryPressure (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏压力。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件产生的触屏压力，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetHistorySize()

```
uint32_t OH_ArkUI_PointerEvent_GetHistorySize (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件数量。历史事件为此次事件与上一次事件之间发生的原始事件，仅适用于move事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前历史事件数量。


### OH_ArkUI_PointerEvent_GetHistoryTiltX()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件中相对YZ平面的角度。


### OH_ArkUI_PointerEvent_GetHistoryTiltY()

```
float OH_ArkUI_PointerEvent_GetHistoryTiltY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的相对XZ平面的角度，值的范围[-90, 90]，其中正值是向下倾斜。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件中相对XZ平面的角度。

### OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaHeight (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的高度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件中触屏区域的高度。


### OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetHistoryTouchAreaWidth (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取特定历史事件中的触屏区域的宽度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件中触屏区域的宽度。


### OH_ArkUI_PointerEvent_GetHistoryWindowX()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetHistoryWindowY()

```
float OH_ArkUI_PointerEvent_GetHistoryWindowY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前应用窗口左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetHistoryX()

```
float OH_ArkUI_PointerEvent_GetHistoryX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetHistoryY()

```
float OH_ArkUI_PointerEvent_GetHistoryY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex, uint32_t historyIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定历史事件中特定接触点相对于当前组件左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表的序号。  | 
| historyIndex | 表示历史事件数据列表的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetPointerCount()

```
uint32_t OH_ArkUI_PointerEvent_GetPointerCount (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件的接触点数量。


### OH_ArkUI_PointerEvent_GetPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetPointerId (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回特定接触点标识。


### OH_ArkUI_PointerEvent_GetChangedPointerId()

```
int32_t OH_ArkUI_PointerEvent_GetChangedPointerId (const ArkUI_UIInputEvent * event, uint32_t * pointerIndex )
```
**描述：**

获取当前触摸事件触发的id。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### OH_ArkUI_PointerEvent_GetPressure()

```
float OH_ArkUI_PointerEvent_GetPressure (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取触屏压力。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件产生的触屏压力，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetTiltX()

```
float OH_ArkUI_PointerEvent_GetTiltX (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取相对YZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件中相对YZ平面的角度。


### OH_ArkUI_PointerEvent_GetTiltY()

```
float OH_ArkUI_PointerEvent_GetTiltY (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从指向性输入事件（如触摸事件）中获取相对XZ平面的角度，取值的范围[-90, 90]，其中正值是向右倾斜。仅适用于支持倾角上报的触控笔操作产生的触控事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件中相对XZ平面的角度。

### OH_ArkUI_PointerEvent_GetRollAngle()

```
int32_t OH_ArkUI_PointerEvent_GetRollAngle (const ArkUI_UIInputEvent * event, double * rollAngle )
```
**描述：**

获取触控笔绕Z轴旋转的角度。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| rollAngle | 触控笔绕Z轴旋转的角度。默认值为0。参数异常不会更改此值。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。

### OH_ArkUI_PointerEvent_GetTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetTouchAreaHeight (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取触屏区域的高度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件中触屏区域的高度。


### OH_ArkUI_PointerEvent_GetTouchAreaWidth()

```
float OH_ArkUI_PointerEvent_GetTouchAreaWidth (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取触屏区域的宽度。仅适用于手指操作产生的触控事件，这通常是一个圆形区域的半径。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件中触屏区域的宽度。


### OH_ArkUI_PointerEvent_GetWindowX()

```
float OH_ArkUI_PointerEvent_GetWindowX (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetWindowXByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowXByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetWindowY()

```
float OH_ArkUI_PointerEvent_GetWindowY (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前应用窗口左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetWindowYByIndex()

```
float OH_ArkUI_PointerEvent_GetWindowYByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前应用窗口左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前应用窗口左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetX()

```
float OH_ArkUI_PointerEvent_GetX (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetXByIndex()

```
float OH_ArkUI_PointerEvent_GetXByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的X坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的X坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetY()

```
float OH_ArkUI_PointerEvent_GetY (const ArkUI_UIInputEvent * event)
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取相对于当前组件左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_GetYByIndex()

```
float OH_ArkUI_PointerEvent_GetYByIndex (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取特定接触点相对于当前组件左上角的Y坐标。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件相对于当前组件左上角的Y坐标，如果参数异常则返回0.0f。


### OH_ArkUI_PointerEvent_SetInterceptHitTestMode()

```
int32_t OH_ArkUI_PointerEvent_SetInterceptHitTestMode (const ArkUI_UIInputEvent * event, HitTestMode mode )
```
**描述：**

配置HitTest模式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| mode | 指定HitTest模式，参数类型[HitTestMode](#hittestmode)。  | 

**返回：**

返回执行的状态代码。


### OH_ArkUI_PointerEvent_SetStopPropagation()

```
int32_t OH_ArkUI_PointerEvent_SetStopPropagation (const ArkUI_UIInputEvent * event, bool stopPropagation )
```
**描述：**

设置是否阻止事件冒泡。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| stopPropagation | 表示是否阻止事件冒泡。true表示阻止事件冒泡，false表示不阻止事件冒泡。  | 

**返回：**

返回执行的状态代码。返回0表示设置成功，如果返回401，表示返回失败，可能的原因是参数异常，例如event是一个空指针。


### OH_ArkUI_UIInputEvent_GetAction()

```
int32_t OH_ArkUI_UIInputEvent_GetAction (const ArkUI_UIInputEvent * event)
```
**描述：**

获取UI输入事件的操作类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前UI输入事件的操作类型，如果参数异常则返回0。


### OH_ArkUI_UIInputEvent_GetDeviceId()

```
int32_t OH_ArkUI_UIInputEvent_GetDeviceId (const ArkUI_UIInputEvent * event)
```
**描述：**

获取当前按键的输入设备ID。

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 

**返回：**

当前按键的输入设备ID。


### OH_ArkUI_UIInputEvent_GetEventTime()

```
int64_t OH_ArkUI_UIInputEvent_GetEventTime (const ArkUI_UIInputEvent * event)
```
**描述：**

获取UI输入事件发生的时间。单位：ns。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回UI输入事件发生的时间，如果参数异常则返回0。


### OH_ArkUI_UIInputEvent_GetPressedKeys()

```
int32_t OH_ArkUI_UIInputEvent_GetPressedKeys (const ArkUI_UIInputEvent * event, int32_t * pressedKeyCodes, int32_t * length )
```
**描述：**

获取所有按下的按键，当前只支持按键事件。

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。| 
| pressedKeyCodes | 输出参数，表示所有按下键的数组，指向的内存空间需要调用者申请。| 
| length | 作为输入参数表示传入的pressedKeyCodes数组长度，作为输出参数表示实际按下按键的个数。| 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_BUFFER_SIZE_NOT_ENOUGH](_ark_u_i___native_module.md) 内存分配不足。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### OH_ArkUI_UIInputEvent_GetSourceType()

```
int32_t OH_ArkUI_UIInputEvent_GetSourceType (const ArkUI_UIInputEvent * event)
```
**描述：**

获取产生UI输入事件的来源类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回产生当前UI输入事件的来源类型。


### OH_ArkUI_UIInputEvent_GetToolType()

```
int32_t OH_ArkUI_UIInputEvent_GetToolType (const ArkUI_UIInputEvent * event)
```
**描述：**

获取产生UI输入事件的工具类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回产生当前UI输入事件的工具类型。


### OH_ArkUI_UIInputEvent_GetType()

```
int32_t OH_ArkUI_UIInputEvent_GetType (const ArkUI_UIInputEvent * event)
```
**描述：**

获取UI输入事件的类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回当前UI输入事件的类型，如果参数异常则返回0。


### OH_ArkUI_FocusAxisEvent_GetAxisValue()

```
double OH_ArkUI_FocusAxisEvent_GetAxisValue (const ArkUI_UIInputEvent * event， int32_t axis)
```
**描述：**

获取焦点轴事件的轴值。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| [axis](#anonymous-enum-5) | 焦点轴事件的轴类型。  | 

**返回：**

返回焦点轴事件的轴值，表示手柄上摇杆推动或按键按下的程度，如果参数异常则返回0.0。


### OH_ArkUI_FocusAxisEvent_SetStopPropagation()

```
int32_t OH_ArkUI_FocusAxisEvent_SetStopPropagation (const ArkUI_UIInputEvent * event， bool stopPropagation)
```
**描述：**

设置是否阻止焦点轴事件冒泡。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| stopPropagation | 是否阻止事件冒泡。true表示阻止事件冒泡，false表示不阻止事件冒泡。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### OH_ArkUI_PointerEvent_GetPressedTimeByIndex()

```
int64_t OH_ArkUI_PointerEvent_GetPressedTimeByIndex (const ArkUI_UIInputEvent* event, uint32_t pointerIndex)
```
**描述：**

获取特定触摸点的按压时间。仅对触摸事件有效。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 指示多点触控数据列表中目标触控点的索引。  | 

**返回：**

返回特定触摸点的按下时间；如果发生任何参数错误，则返回0。


### OH_ArkUI_MouseEvent_GetRawDeltaX()

```
float OH_ArkUI_MouseEvent_GetRawDeltaX (const ArkUI_UIInputEvent* event)
```
**描述：**

获取X轴相对于前一个上报的鼠标事件的鼠标指针位置的偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的X坐标的差。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回相对于前一个上报的鼠标事件的鼠标指针位置的X轴偏移量；如果发生任何参数错误，则返回0.0f。


### OH_ArkUI_MouseEvent_GetRawDeltaY()

```
float OH_ArkUI_MouseEvent_GetRawDeltaY (const ArkUI_UIInputEvent* event)
```
**描述：**

获取Y轴相对于前一个上报的鼠标事件的鼠标指针位置的偏移量。当鼠标指针位于屏幕边缘时，该值可能小于两次上报的Y坐标的差。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回相对于前一个上报的鼠标事件的鼠标指针位置的Y轴偏移量；如果发生任何参数错误，则返回0.0f。


### OH_ArkUI_MouseEvent_GetPressedButtons()

```
int32_t OH_ArkUI_MouseEvent_GetPressedButtons (const ArkUI_UIInputEvent* event, int32_t* pressedButtons, int32_t* length)
```
**描述：**

从鼠标事件中获取按下的按钮。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pressedButtons | 指示按下按钮的列表。需要先创建一个int数组，用来储存按下的按钮。 |
| length | 作为输入参数表示传入的pressedButtons数组长度，作为输出参数表示实际按下按键的个数。 |

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_BUFFER_SIZE_ERROR](_ark_u_i___native_module.md) 给定的缓冲区不够。


### OH_ArkUI_UIInputEvent_GetTargetDisplayId()

```
int32_t OH_ArkUI_UIInputEvent_GetTargetDisplayId (const ArkUI_UIInputEvent* event)
```
**描述：**

获取发生UI输入事件的屏幕ID。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回屏幕ID；如果发生任何参数错误，则返回0。


### OH_ArkUI_PointerEvent_GetInteractionHand()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHand (const ArkUI_UIInputEvent * event, ArkUI_InteractionHand * hand)
```
**描述：**

获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| hand | 返回当前事件识别的交互手。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### OH_ArkUI_PointerEvent_GetInteractionHandByIndex()

```
int32_t OH_ArkUI_PointerEvent_GetInteractionHandByIndex (const ArkUI_UIInputEvent * event, int32_t pointerIndex, ArkUI_InteractionHand * hand)
```
**描述：**

获取当前触摸事件是左手点击触发还是右手点击触发。仅在部分触控产品上有效。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 
| hand | 返回指定手指的交互手。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### OH_ArkUI_UIInputEvent_GetEventTargetWidth()

```
float OH_ArkUI_UIInputEvent_GetEventTargetWidth(const ArkUI_UIInputEvent* event)
```
**描述：**

获取事件命中的组件的宽度。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 

**返回：**

返回事件命中的组件的宽度；如果发生任何参数错误，则返回 0.0f。


### OH_ArkUI_UIInputEvent_GetEventTargetHeight()

```
float OH_ArkUI_UIInputEvent_GetEventTargetHeight(const ArkUI_UIInputEvent* event)
```
**描述：**

获取事件命中的组件的高度。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 

**返回：**

返回事件命中的组件的高度；如果发生任何参数错误，则返回 0.0f。


### OH_ArkUI_UIInputEvent_GetEventTargetPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionX(const ArkUI_UIInputEvent* event)
```
**描述：**

获取事件命中的组件的X坐标。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 

**返回：**

返回事件命中的组件的X坐标；如果发生任何参数错误，则返回 0.0f。


### OH_ArkUI_UIInputEvent_GetEventTargetPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetPositionY(const ArkUI_UIInputEvent* event)
```
**描述：**

获取事件命中的组件的Y坐标。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 

**返回：**

返回事件命中的组件的Y坐标；如果发生任何参数错误，则返回 0.0f。


### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionX(const ArkUI_UIInputEvent* event)
```
**描述：**

获取事件命中的组件的全局X坐标。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 

**返回：**

返回事件命中的组件的全局X坐标；如果发生任何参数错误，则返回 0.0f。


### OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY()

```
float OH_ArkUI_UIInputEvent_GetEventTargetGlobalPositionY(const ArkUI_UIInputEvent* event)
```
**描述：**

获取事件命中的组件的全局Y坐标。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 

**返回：**

返回事件命中的组件的全局Y坐标；如果发生任何参数错误，则返回 0.0f。


### OH_ArkUI_UIInputEvent_GetModifierKeyStates()

```
int32_t OH_ArkUI_UIInputEvent_GetModifierKeyStates(const ArkUI_UIInputEvent* event, uint64_t* keys)
```
**描述：**

获取UI输入事件的修饰键状态。该接口会通过keys传出当前事件发生时所有修饰键的状态。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 
| keys | 表示当前处于按下状态的modifier key组合。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### OH_ArkUI_HoverEvent_IsHovered()

```
bool OH_ArkUI_HoverEvent_IsHovered(const ArkUI_UIInputEvent* event)
```
**描述：**

获取鼠标是否悬浮在当前组件上。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向ArkUI_UIInputEvent对象的指针。  | 

**返回：**

如果鼠标悬浮在当前组件上则返回true。如果鼠标没有悬浮在当前组件上，返回false。


### OH_ArkUI_PointerEvent_CreateClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_CreateClonedEvent(const ArkUI_UIInputEvent* event, ArkUI_UIInputEvent** clonedEvent)
```
**描述：**

基于原始事件指针创建克隆事件指针。仅对触摸事件有效。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 
| clonedEvent | ArkUI_UIInputEvent克隆事件指针。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。

### OH_ArkUI_PointerEvent_DestroyClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_DestroyClonedEvent(const ArkUI_UIInputEvent* event)
```
**描述：**

销毁克隆事件指针。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
[ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) 输入的事件指针不是克隆事件。

### OH_ArkUI_PointerEvent_SetClonedEventLocalPosition()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPosition(const ArkUI_UIInputEvent * event, float x, float y)
```
**描述：**

设置指向性事件相对于当前组件左上角的X坐标和Y坐标。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 
| x | 当前带有指向性的输入事件相对于当前组件左上角的X坐标。  | 
| y | 当前带有指向性的输入事件相对于当前组件左上角的Y坐标。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
[ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) 输入的事件指针不是克隆事件。

### OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventLocalPositionByIndex(const ArkUI_UIInputEvent * event, 
float x, float y, int32_t pointerIndex)
```
**描述：**

设置指向性事件特有接触点相对于当前组件左上角的X坐标和Y坐标。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 
| x | 当前带有指向性的输入事件相对于当前组件左上角的X坐标。  | 
| y | 当前带有指向性的输入事件相对于当前组件左上角的Y坐标。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
[ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) 输入的事件指针不是克隆事件。

### OH_ArkUI_PointerEvent_SetClonedEventActionType()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventActionType(const ArkUI_UIInputEvent * event, int32_t actionType)
```
**描述：**

设置当前带有指向性的克隆输入事件的事件类型。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 
| actionType | ArkUI_UIInputEvent克隆事件类型。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
[ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) 输入的事件指针不是克隆事件。

### OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventChangedFingerId(const ArkUI_UIInputEvent * event, int32_t fingerId)
```
**描述：**

设置当前带有指向性的克隆输入事件的触摸点ID。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 
| fingerId | 触发当前事件指针的触摸点ID。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
[ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) 输入的事件指针不是克隆事件。

### OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex()

```
int32_t OH_ArkUI_PointerEvent_SetClonedEventFingerIdByIndex(const ArkUI_UIInputEvent * event, 
int32_t fingerId, int32_t pointerIndex)
```
**描述：**

设置带有指向性的克隆输入事件特定接触点的触摸点ID。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 
| fingerId | 触发当前事件指针的触摸点ID。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
[ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) 输入的事件指针不是克隆事件。

### OH_ArkUI_PointerEvent_PostClonedEvent()

```
int32_t OH_ArkUI_PointerEvent_PostClonedEvent(ArkUI_NodeHandle node, const ArkUI_UIInputEvent * event)
```
**描述：**

转发克隆事件到特定节点。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | ArkUI_UIInputEvent事件指针。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。
[ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。
[ARKUI_ERROR_CODE_NON_CLONED_POINTER_EVENT](_ark_u_i___native_module.md) 输入的事件指针不是克隆事件。
[ARKUI_ERROR_CODE_POST_CLONED_COMPONENT_STATUS_ABNORMAL](_ark_u_i___native_module.md) 组件状态异常。
[ARKUI_ERROR_CODE_POST_CLONED_NO_COMPONENT_HIT_TO_RESPOND_TO_THE_EVENT](_ark_u_i___native_module.md) 未命中可响应事件的组件。


### OH_ArkUI_AxisEvent_SetPropagation()

```
int32_t OH_ArkUI_AxisEvent_SetPropagation (const ArkUI_UIInputEvent * event, bool propagation)
```
**描述：**

设置是否激活轴事件冒泡。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。 | 
| propagation | 表示是否激活事件冒泡。true表示激活事件冒泡，false表示不激活事件冒泡。  | 

**返回：**

[ARKUI_ERROR_CODE_NO_ERROR](_ark_u_i___native_module.md) 成功。 [ARKUI_ERROR_CODE_PARAM_INVALID](_ark_u_i___native_module.md) 函数参数异常。


### OH_ArkUI_AxisEvent_GetScrollStep()

```
int32_t OH_ArkUI_AxisEvent_GetScrollStep (const ArkUI_UIInputEvent * event)
```
**描述：**

获取滚动轴事件的滚动步长系数，适用于鼠标滚轮产生的轴事件。这个值可以告诉你用户所配置的滚动放大系数。

**起始版本：** 17

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 指向 ArkUI_UIInputEvent事件指针。 | 

**返回：**

返回鼠标滚轮轴滚动步长配置。

### OH_ArkUI_UIInputEvent_GetLatestStatus()
```
ArkUI_ErrorCode OH_ArkUI_UIInputEvent_GetLatestStatus()
```
**描述：**

调用该方法获取最近一次UIInput相关方法的执行情况。通常情况下不需要使用该方法，仅在返回值结果不确定是否异常时使用。
以下是一个使用示例（对于返回的float类型，0.0并不代表错误，因此可以进一步使用OH_ArkUI_UIInputEvent_GetLatestStatus方法来确认是否发生异常）。
```
float x = OH_ArkUI_PointerEvent_GetX(event);
if (ARKUI_ERROR_CODE_NO_ERROR != OH_Arkui_UIInputEvent_GetlatestStatus()) {
    // error
    return;
}
```
系统将在每次执行UIInput相关函数时主动清空上一次函数调用的状态，以确保每次通过该接口获取的均为最近一次的状态。

**起始版本：** 20

**返回：**

返回最近一次调用UIInput方法产生的结果代码。