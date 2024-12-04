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
| [ArkUI_UIInputEvent_Type](#arkui_uiinputevent_type) { ARKUI_UIINPUTEVENT_TYPE_UNKNOWN = 0, ARKUI_UIINPUTEVENT_TYPE_TOUCH = 1, ARKUI_UIINPUTEVENT_TYPE_AXIS = 2, ARKUI_UIINPUTEVENT_TYPE_MOUSE = 3 } | UI输入事件类型定义。  | 
| {<br/>OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2, UI_TOUCH_EVENT_ACTION_CANCEL = 0,<br/>UI_TOUCH_EVENT_ACTION_DOWN = 1, UI_TOUCH_EVENT_ACTION_MOVE = 2, UI_TOUCH_EVENT_ACTION_UP = 3<br/>} | 定义输入事件的Action Code。  | 
| {<br/>UI_INPUT_EVENT_TOOL_TYPE_UNKNOWN = 0, UI_INPUT_EVENT_TOOL_TYPE_FINGER = 1, UI_INPUT_EVENT_TOOL_TYPE_PEN = 2, UI_INPUT_EVENT_TOOL_TYPE_MOUSE = 3,<br/>UI_INPUT_EVENT_TOOL_TYPE_TOUCHPAD = 4, UI_INPUT_EVENT_TOOL_TYPE_JOYSTICK = 5<br/>} | 产生输入事件的工具类型定义。  | 
| { UI_INPUT_EVENT_SOURCE_TYPE_UNKNOWN = 0, UI_INPUT_EVENTT_SOURCE_TYPE_MOUSE = 1, UI_INPUT_EVENTT_SOURCE_TYPE_TOUCH_SCREEN = 2 } | 产生输入事件的来源类型定义。  | 
| [HitTestMode](#hittestmode) { HTMDEFAULT = 0, HTMBLOCK, HTMTRANSPARENT, HTMNONE } | 定义触摸测试类型的枚举值。  | 
| { UI_MOUSE_EVENT_ACTION_UNKNOWN = 0, UI_MOUSE_EVENT_ACTION_PRESS = 1, UI_MOUSE_EVENT_ACTION_RELEASE = 2, UI_MOUSE_EVENT_ACTION_MOVE = 3 } | 定义鼠标事件的Action Code。  | 
| {<br/>UI_MOUSE_EVENT_BUTTON_NONE = 0, UI_MOUSE_EVENT_BUTTON_LEFT = 1, UI_MOUSE_EVENT_BUTTON_RIGHT = 2, UI_MOUSE_EVENT_BUTTON_MIDDLE = 3,<br/>UI_MOUSE_EVENT_BUTTON_BACK = 4, UI_MOUSE_EVENT_BUTTON_FORWARD = 5<br/>} | 定义鼠标事件的按键类型。  | 
| [ArkUI_ModifierKeyName](#arkui_modifierkeyname) { ARKUI_MODIFIER_KEY_CTRL = 1 &lt;&lt; 0, ARKUI_MODIFIER_KEY_SHIFT = 1 &lt;&lt; 1, ARKUI_MODIFIER_KEY_ALT = 1 &lt;&lt; 2, ARKUI_MODIFIER_KEY_FN = 1 &lt;&lt; 3 } | 定义modifier按键。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ArkUI_UIInputEvent_GetType](#oh_arkui_uiinputevent_gettype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件的类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetAction](#oh_arkui_uiinputevent_getaction) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件的操作类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetSourceType](#oh_arkui_uiinputevent_getsourcetype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取产生UI输入事件的来源类型。  | 
| int32_t [OH_ArkUI_UIInputEvent_GetToolType](#oh_arkui_uiinputevent_gettooltype) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取产生UI输入事件的工具类型。  | 
| int64_t [OH_ArkUI_UIInputEvent_GetEventTime](#oh_arkui_uiinputevent_geteventtime) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取UI输入事件发生的时间。  | 
| uint32_t [OH_ArkUI_PointerEvent_GetPointerCount](#oh_arkui_pointerevent_getpointercount) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点数量。  | 
| int32_t [OH_ArkUI_PointerEvent_GetPointerId](#oh_arkui_pointerevent_getpointerid) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。  | 
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
| float [OH_ArkUI_PointerEvent_GetTiltY](#oh_arkui_pointerevent_gettilty) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, uint32_t pointerIndex) | 从带有指向性的输入事件（如触摸事件）中获取相对XZ平面的角度，值的范围[-90, 90]，其中正值是向下倾斜。  | 
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
| int32_t [OH_ArkUI_PointerEvent_SetInterceptHitTestMode](#oh_arkui_pointerevent_setintercepthittestmode) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, [HitTestMode](#hittestmode) mode) | 配置HitTest模式。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseButton](#oh_arkui_mouseevent_getmousebutton) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取鼠标事件的按键类型的值。  | 
| int32_t [OH_ArkUI_MouseEvent_GetMouseAction](#oh_arkui_mouseevent_getmouseaction) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event) | 获取鼠标事件的鼠标动作类型的值。  | 
| int32_t [OH_ArkUI_PointerEvent_SetStopPropagation](#oh_arkui_pointerevent_setstoppropagation) (const [ArkUI_UIInputEvent](#arkui_uiinputevent) \*event, bool stopPropagation) | 设置是否阻止事件冒泡。  | 


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
| OH_NATIVEXCOMPONENT_RESULT_SUCCESS  | 成功结果。  | 
| OH_NATIVEXCOMPONENT_RESULT_FAILED  | 失败结果。  | 
| OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER  | 无效参数。  | 
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
| UI_INPUT_EVENTT_SOURCE_TYPE_MOUSE  | 鼠标。  | 
| UI_INPUT_EVENTT_SOURCE_TYPE_TOUCH_SCREEN  | 触摸屏。  | 


### anonymous enum

```
anonymous enum
```
**描述：**

定义鼠标事件的Action Code。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| UI_MOUSE_EVENT_ACTION_UNKNOWN  | 无效行为  | 
| UI_MOUSE_EVENT_ACTION_PRESS  | 鼠标按键按下。  | 
| UI_MOUSE_EVENT_ACTION_RELEASE  | 鼠标按键松开。  | 
| UI_MOUSE_EVENT_ACTION_MOVE  | 鼠标移动。  | 


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
| ARKUI_MODIFIER_KEY_FN  | Fn.  | 


### ArkUI_UIInputEvent_Type

```
enum ArkUI_UIInputEvent_Type
```
**描述：**

UI输入事件类型定义。

**起始版本：** 12


### HitTestMode

```
enum HitTestMode
```
**描述：**

定义触摸测试类型的枚举值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HTMDEFAULT  | 默认触摸测试效果，自身和子节点都响应触摸测试，但会阻塞兄弟节点的触摸测试。  | 
| HTMBLOCK  | 自身响应触摸测试，阻塞子节点和兄弟节点的触摸测试。  | 
| HTMTRANSPARENT  | 自身和子节点都响应触摸测试，不会阻塞兄弟节点的触摸测试。  | 
| HTMNONE  | 自身不响应触摸测试，不会阻塞子节点和兄弟节点的触摸测试。  | 


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

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取多点触控的接触点标识。

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

从带有指向性的输入事件（如触摸事件、鼠标事件、轴事件）中获取历史事件数量。

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

从带有指向性的输入事件（如触摸事件）中获取相对XZ平面的角度，值的范围[-90, 90]，其中正值是向下倾斜。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 
| pointerIndex | 表示多点触控数据列表中的序号。  | 

**返回：**

返回当前带有指向性的输入事件中相对XZ平面的角度。


### OH_ArkUI_PointerEvent_GetTouchAreaHeight()

```
float OH_ArkUI_PointerEvent_GetTouchAreaHeight (const ArkUI_UIInputEvent * event, uint32_t pointerIndex )
```
**描述：**

从带有指向性的输入事件（如触摸事件）中获取触屏区域的高度。

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

从带有指向性的输入事件（如触摸事件）中获取触屏区域的宽度。

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
| stopPropagation | 表示是否阻止事件冒泡。  | 

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


### OH_ArkUI_UIInputEvent_GetEventTime()

```
int64_t OH_ArkUI_UIInputEvent_GetEventTime (const ArkUI_UIInputEvent * event)
```
**描述：**

获取UI输入事件发生的时间。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 表示指向当前UI输入事件的指针。  | 

**返回：**

返回UI输入事件发生的时间，如果参数异常则返回0。


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
