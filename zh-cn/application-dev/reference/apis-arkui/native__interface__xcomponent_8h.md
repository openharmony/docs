# native_interface_xcomponent.h


## 概述

声明用于访问Native XComponent的API。

**起始版本:**

8

**相关模块:**

[Native XComponent](_o_h___native_x_component.md)


## 汇总


### 结构体

| 名称                                                         | 描述                                |
| ------------------------------------------------------------ | ----------------------------------- |
| [OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) | 触摸事件中触摸点的信息。            |
| [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | 触摸事件。                          |
| [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | 鼠标事件。                          |
| [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | 注册surface生命周期和触摸事件回调。 |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | 注册鼠标事件的回调。                |
| [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) | 定义期望帧率范围。                  |


### 类型定义

| 名称                                       | 描述                                   |
| ---------------------------------------- | ------------------------------------ |
| [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) | 提供封装的OH_NativeXComponent实例。          |
| [OH_NativeXComponent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_callback) | 注册surface生命周期和触摸事件回调。                |
| [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_mouseevent_callback) | 注册鼠标事件的回调。                           |
| [OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) | 提供封装的OH_NativeXComponent_KeyEvent实例。 |


### 枚举

| 枚举名称                                     | 描述         |
| ---------------------------------------- | ---------- |
| {&nbsp;OH_NATIVEXCOMPONENT_RESULT_SUCCESS&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_RESULT_FAILED&nbsp;=&nbsp;-1,&nbsp;OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER&nbsp;=&nbsp;-2&nbsp;} | 枚举API访问状态。 |
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_DOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_UP,&nbsp;OH_NATIVEXCOMPONENT_MOVE,&nbsp;OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN<br/>} | 触摸事件类型。    |
| [OH_NativeXComponent_TouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_touchpointtooltype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH,&nbsp;OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS<br/>} | 触摸点工具类型。   |
| [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype)&nbsp;{<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK,&nbsp;OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<br/>} | 触摸事件源类型。   |
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction)&nbsp;{&nbsp;OH_NATIVEXCOMPONENT_MOUSE_NONE&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_PRESS,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_RELEASE,&nbsp;OH_NATIVEXCOMPONENT_MOUSE_MOVE&nbsp;} | 鼠标事件动作。    |
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton)&nbsp;{<br/>OH_NATIVEXCOMPONENT_NONE_BUTTON&nbsp;=&nbsp;0,&nbsp;OH_NATIVEXCOMPONENT_LEFT_BUTTON&nbsp;=&nbsp;0x01,&nbsp;OH_NATIVEXCOMPONENT_RIGHT_BUTTON&nbsp;=&nbsp;0x02,&nbsp;OH_NATIVEXCOMPONENT_MIDDLE_BUTTON&nbsp;=&nbsp;0x04,<br/>OH_NATIVEXCOMPONENT_BACK_BUTTON&nbsp;=&nbsp;0x08,&nbsp;OH_NATIVEXCOMPONENT_FORWARD_BUTTON&nbsp;=&nbsp;0x10<br/>} | 鼠标事件按键。    |


### 函数

| 名称                                       | 描述                                     |
| ---------------------------------------- | -------------------------------------- |
| [OH_NativeXComponent_GetXComponentId](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentid)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;char&nbsp;\*id,&nbsp;uint64_t&nbsp;\*size) | 获取ArkUI&nbsp;XComponent的id。            |
| [OH_NativeXComponent_GetXComponentSize](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentsize)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;uint64_t&nbsp;\*width,&nbsp;uint64_t&nbsp;\*height) | 获取ArkUI&nbsp;XComponent持有的surface的大小。  |
| [OH_NativeXComponent_GetXComponentOffset](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentoffset)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;double&nbsp;\*x,&nbsp;double&nbsp;\*y) | 获取ArkUI&nbsp;XComponent组件相对屏幕左上顶点的偏移量。 |
| [OH_NativeXComponent_GetTouchEvent](_o_h___native_x_component.md#oh_nativexcomponent_gettouchevent)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;[OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md)&nbsp;\*touchEvent) | 获取ArkUI&nbsp;XComponent调度的触摸事件。        |
| [OH_NativeXComponent_GetTouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtooltype)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;[OH_NativeXComponent_TouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_touchpointtooltype)&nbsp;\*toolType) | 获取ArkUI&nbsp;XComponent触摸点工具类型。        |
| [OH_NativeXComponent_GetTouchPointTiltX](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtiltx)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;float&nbsp;\*tiltX) | 获取ArkUI&nbsp;XComponent触摸点倾斜与X轴角度。     |
| [OH_NativeXComponent_GetTouchPointTiltY](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtilty)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;uint32_t&nbsp;pointIndex,&nbsp;float&nbsp;\*tiltY) | 获取ArkUI&nbsp;XComponent触摸点倾斜与Y轴角度。     |
| [OH_NativeXComponent_GetMouseEvent](_o_h___native_x_component.md#oh_nativexcomponent_getmouseevent)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;const&nbsp;void&nbsp;\*window,&nbsp;[OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md)&nbsp;\*mouseEvent) | 获取ArkUI&nbsp;XComponent调度的鼠标事件。        |
| [OH_NativeXComponent_RegisterCallback](_o_h___native_x_component.md#oh_nativexcomponent_registercallback)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md)&nbsp;\*callback) | 为此OH_NativeXComponent实例注册回调。           |
| [OH_NativeXComponent_RegisterMouseEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registermouseeventcallback)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md)&nbsp;\*callback) | 为此OH_NativeXComponent实例注册鼠标事件回调。       |
| [OH_NativeXComponent_RegisterFocusEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerfocuseventcallback)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册获焦事件回调。       |
| [OH_NativeXComponent_RegisterKeyEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallback)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册按键事件回调。       |
| [OH_NativeXComponent_RegisterBlurEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerblureventcallback)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;void&nbsp;\*window)) | 为此OH_NativeXComponent实例注册失焦事件回调。       |
| [OH_NativeXComponent_GetKeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_getkeyevent)&nbsp;([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)&nbsp;\*component,&nbsp;[OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)&nbsp;\*\*keyEvent) | 获取ArkUI&nbsp;XComponent调度的按键事件。        |
| [OH_NativeXComponent_GetKeyEventAction](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventaction)&nbsp;([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_KeyAction](_o_h___native_x_component.md#oh_nativexcomponent_keyaction)&nbsp;\*action) | 获取传入按键事件的动作。                           |
| [OH_NativeXComponent_GetKeyEventCode](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventcode)&nbsp;([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_KeyCode](_o_h___native_x_component.md#oh_nativexcomponent_keycode)&nbsp;\*code) | 获取传入按键事件的按键码。                          |
| [OH_NativeXComponent_GetKeyEventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventsourcetype)&nbsp;([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;[OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype)&nbsp;\*sourceType) | 获取传入按键事件的事件源类型。                        |
| [OH_NativeXComponent_GetKeyEventDeviceId](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventdeviceid)&nbsp;([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;int64_t&nbsp;\*deviceId) | 获取传入按键事件的设备id。                         |
| [OH_NativeXComponent_GetKeyEventTimeStamp](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventtimestamp)&nbsp;([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)&nbsp;\*keyEvent,&nbsp;int64_t&nbsp;\*timeStamp) | 获取传入按键事件的时间戳。                          |
| [OH_NativeXComponent_SetExpectedFrameRateRange](_o_h___native_x_component.md#oh_nativexcomponent_setexpectedframeraterange) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) \*range) | 设置期望帧率范围。  |
| [OH_NativeXComponent_RegisterOnFrameCallback](_o_h___native_x_component.md#oh_nativexcomponent_registeronframecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint64_t timestamp, uint64_t targetTimestamp)) | 为此OH_NativeXComponent实例注册显示更新回调，并使能每帧回调此函数。  |
| [OH_NativeXComponent_UnregisterOnFrameCallback](_o_h___native_x_component.md#oh_nativexcomponent_unregisteronframecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component) | 为此OH_NativeXComponent实例取消注册回调函数，并关闭每帧回调此函数。  |

### 变量

| 名称                                       | 描述                        |
| ---------------------------------------- | ------------------------- |
| **OH_XCOMPONENT_ID_LEN_MAX**&nbsp;=&nbsp;128 | ArkUI XComponent的id的最大长度。 |
| **OH_MAX_TOUCH_POINTS_NUMBER**&nbsp;=&nbsp;10 | 触摸事件中的可识别的触摸点个数最大值。       |
