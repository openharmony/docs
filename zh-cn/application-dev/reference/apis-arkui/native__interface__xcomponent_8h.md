# native_interface_xcomponent.h


## 概述

声明用于访问Native XComponent的API。

**库：** libace_ndk.z.so

**引用文件：** <ace/xcomponent/native_interface_xcomponent.h>

**起始版本：** 8

**相关模块：**[Native XComponent](_o_h___native_x_component.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_NativeXComponent_TouchPoint](_o_h___native_x_component___touch_point.md) |  触摸事件中触摸点的信息。| 
| struct&nbsp;&nbsp;[OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) | 触摸事件。  | 
| struct&nbsp;&nbsp;[OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | 鼠标事件。  | 
| struct&nbsp;&nbsp;[OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | 注册surface生命周期和触摸事件回调。  | 
| struct&nbsp;&nbsp;[OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | 注册鼠标事件的回调。  | 
| struct&nbsp;&nbsp;[OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) | 定义期望帧率范围。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)[OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) | 提供封装的OH_NativeXComponent实例。  | 
| typedef struct [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md)[OH_NativeXComponent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_callback) | 注册surface生命周期和触摸事件回调。  | 
| typedef struct [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md)[OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_mouseevent_callback) | 注册鼠标事件的回调。  | 
| typedef struct [OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)[OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) | 提供封装的OH_NativeXComponent_KeyEvent实例  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { [OH_NATIVEXCOMPONENT_RESULT_SUCCESS](_o_h___native_x_component.md) = 0, [OH_NATIVEXCOMPONENT_RESULT_FAILED](_o_h___native_x_component.md) = -1, [OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER](_o_h___native_x_component.md) = -2 } | 枚举API访问状态。  | 
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype) {<br/>[OH_NATIVEXCOMPONENT_DOWN](_o_h___native_x_component.md) = 0, [OH_NATIVEXCOMPONENT_UP](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_MOVE](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_CANCEL](_o_h___native_x_component.md),<br/>[OH_NATIVEXCOMPONENT_UNKNOWN](_o_h___native_x_component.md)<br/>} | 触摸事件类型。  | 
| [OH_NativeXComponent_TouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_touchpointtooltype) {<br/>[OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN](_o_h___native_x_component.md) = 0, [OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER](_o_h___native_x_component.md),<br/>[OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE](_o_h___native_x_component.md),<br/>[OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS](_o_h___native_x_component.md)<br/>} | 触摸点工具类型  | 
| [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype) {<br/>[OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN](_o_h___native_x_component.md) = 0, [OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD](_o_h___native_x_component.md),<br/>[OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD](_o_h___native_x_component.md)<br/>} | 触摸事件源类型.  | 
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction) { [OH_NATIVEXCOMPONENT_MOUSE_NONE](_o_h___native_x_component.md) = 0, [OH_NATIVEXCOMPONENT_MOUSE_PRESS](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_MOUSE_RELEASE](_o_h___native_x_component.md), [OH_NATIVEXCOMPONENT_MOUSE_MOVE](_o_h___native_x_component.md) } | 鼠标事件动作.  | 
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton) {<br/>[OH_NATIVEXCOMPONENT_NONE_BUTTON](_o_h___native_x_component.md) = 0, [OH_NATIVEXCOMPONENT_LEFT_BUTTON](_o_h___native_x_component.md) = 0x01, [OH_NATIVEXCOMPONENT_RIGHT_BUTTON](_o_h___native_x_component.md) = 0x02, [OH_NATIVEXCOMPONENT_MIDDLE_BUTTON](_o_h___native_x_component.md) = 0x04,<br/>[OH_NATIVEXCOMPONENT_BACK_BUTTON](_o_h___native_x_component.md) = 0x08, [OH_NATIVEXCOMPONENT_FORWARD_BUTTON](_o_h___native_x_component.md) = 0x10<br/>} | 鼠标事件按键。  | 
|[ArkUI_XComponent_ImageAnalyzerState](_o_h___native_x_component.md#arkui_xcomponent_imageanalyzerstate)&nbsp;{&nbsp;[ARKUI_XCOMPONENT_AI_ANALYSIS_FINISHED](_o_h___native_x_component.md)&nbsp;=&nbsp;0,&nbsp;[ARKUI_XCOMPONENT_AI_ANALYSIS_DISABLED](_o_h___native_x_component.md)&nbsp;=&nbsp;110000,&nbsp;[ARKUI_XCOMPONENT_AI_ANALYSIS_UNSUPPORTED](_o_h___native_x_component.md)&nbsp;=&nbsp;110001,&nbsp;[ARKUI_XCOMPONENT_AI_ANALYSIS_ONGOING](_o_h___native_x_component.md)&nbsp;=&nbsp;110002,&nbsp;[ARKUI_XCOMPONENT_AI_ANALYSIS_STOPPED](_o_h___native_x_component.md)&nbsp;=&nbsp;110003}|XComponent图像AI分析状态码。|


### 函数

| 名称 | 描述 |
| -------- | -------- |
| int32_t [OH_NativeXComponent_GetXComponentId](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentid) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, char \*id, uint64_t \*size) | 获取ArkUI XComponent的id。  | 
| int32_t [OH_NativeXComponent_GetXComponentSize](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentsize) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, uint64_t \*width, uint64_t \*height) | 获取ArkUI XComponent持有的surface的大小。  | 
| int32_t [OH_NativeXComponent_GetXComponentOffset](_o_h___native_x_component.md#oh_nativexcomponent_getxcomponentoffset) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, double \*x, double \*y) | 获取ArkUI XComponent组件相对屏幕左上顶点的偏移量。  | 
| int32_t [OH_NativeXComponent_GetTouchEvent](_o_h___native_x_component.md#oh_nativexcomponent_gettouchevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_TouchEvent](_o_h___native_x_component___touch_event.md) \*touchEvent) | 获取ArkUI XComponent调度的触摸事件。  | 
| int32_t [OH_NativeXComponent_GetTouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtooltype) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint32_t pointIndex, [OH_NativeXComponent_TouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_touchpointtooltype) \*toolType) | 获取ArkUI XComponent触摸点工具类型。  | 
| int32_t [OH_NativeXComponent_GetTouchPointTiltX](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtiltx) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltX) | 获取ArkUI XComponent触摸点倾斜与X轴角度。  | 
| int32_t [OH_NativeXComponent_GetTouchPointTiltY](_o_h___native_x_component.md#oh_nativexcomponent_gettouchpointtilty) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint32_t pointIndex, float \*tiltY) | 获取ArkUI XComponent触摸点倾斜与Y轴角度。  | 
| int32_t [OH_NativeXComponent_GetMouseEvent](_o_h___native_x_component.md#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | 获取ArkUI XComponent调度的鼠标事件  | 
| int32_t [OH_NativeXComponent_RegisterCallback](_o_h___native_x_component.md#oh_nativexcomponent_registercallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) \*callback) | 为此OH_NativeXComponent实例注册回调。  | 
| int32_t [OH_NativeXComponent_RegisterMouseEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registermouseeventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) \*callback) | 为此OH_NativeXComponent实例注册鼠标事件回调。  | 
| int32_t [OH_NativeXComponent_RegisterFocusEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerfocuseventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册获焦事件回调。  | 
| int32_t [OH_NativeXComponent_RegisterKeyEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册按键事件回调。  | 
| int32_t [OH_NativeXComponent_RegisterKeyEventCallbackWithResult](_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallbackwithresult) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, bool(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册有返回值的按键事件回调。  | 
| int32_t [OH_NativeXComponent_RegisterBlurEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerblureventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册失焦事件回调。  | 
| int32_t [OH_NativeXComponent_GetKeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_getkeyevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*\*keyEvent) | 获取ArkUI XComponent调度的按键事件。  | 
| int32_t [OH_NativeXComponent_GetKeyEventAction](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventaction) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_KeyAction](_o_h___native_x_component.md#oh_nativexcomponent_keyaction) \*action) | 获取传入按键事件的动作。  | 
| int32_t [OH_NativeXComponent_GetKeyEventCode](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventcode) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_KeyCode](_o_h___native_x_component.md#oh_nativexcomponent_keycode) \*code) | 获取传入按键事件的按键码。  | 
| int32_t [OH_NativeXComponent_GetKeyEventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventsourcetype) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype) \*sourceType) | 获取传入按键事件的事件源类型。  | 
| int32_t [OH_NativeXComponent_GetKeyEventDeviceId](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventdeviceid) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, int64_t \*deviceId) | 获取传入按键事件的设备id。  | 
| int32_t [OH_NativeXComponent_GetKeyEventTimeStamp](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventtimestamp) ([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) \*keyEvent, int64_t \*timeStamp) | 获取传入按键事件的时间戳。  | 
| int32_t [OH_NativeXComponent_SetExpectedFrameRateRange](_o_h___native_x_component.md#oh_nativexcomponent_setexpectedframeraterange) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) \*range) | 设置期望帧率范围。  | 
| int32_t [OH_NativeXComponent_RegisterOnFrameCallback](_o_h___native_x_component.md#oh_nativexcomponent_registeronframecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, uint64_t timestamp, uint64_t targetTimestamp)) | 为此OH_NativeXComponent实例注册显示更新回调，并使能每帧回调此函数。  | 
| int32_t [OH_NativeXComponent_UnregisterOnFrameCallback](_o_h___native_x_component.md#oh_nativexcomponent_unregisteronframecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component) | 为此OH_NativeXComponent实例取消注册回调函数，并关闭每帧回调此函数。  | 
| int32_t [OH_NativeXComponent_AttachNativeRootNode](_o_h___native_x_component.md#oh_nativexcomponent_attachnativerootnode) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) root) | 将通过ArkUI的native接口创建出来的UI组件挂载到当前XComponent上。  | 
| int32_t [OH_NativeXComponent_DetachNativeRootNode](_o_h___native_x_component.md#oh_nativexcomponent_detachnativerootnode) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) root) | 将ArkUI的native组件从当前XComponent上卸载.  | 
| int32_t [OH_NativeXComponent_RegisterUIInputEventCallback](_o_h___native_x_component.md#oh_nativexcomponent_registeruiinputeventcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event, [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) type), [ArkUI_UIInputEvent_Type](_ark_u_i___event_module.md#arkui_uiinputevent_type) type) | 为此OH_NativeXComponent实例注册UI输入事件回调，并使能收到UI输入事件时回调此函数。  | 
| int32_t [OH_NativeXComponent_RegisterOnTouchInterceptCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerontouchinterceptcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [HitTestMode](_ark_u_i___native_module.md#hittestmode)(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event)) | 为此OH_NativeXComponent实例注册自定义事件拦截回调，并使能在做触摸测试时回调此函数。  | 
| int32_t [OH_NativeXComponent_SetNeedSoftKeyboard](_o_h___native_x_component.md#oh_nativexcomponent_setneedsoftkeyboard) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, bool needSoftKeyboard) | 为此OH_NativeXComponent实例设置是否需要软键盘。  | 
| int32_t [OH_NativeXComponent_RegisterSurfaceShowCallback](_o_h___native_x_component.md#oh_nativexcomponent_registersurfaceshowcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册surface显示回调，该回调在应用从后台返回前台时触发。  | 
| int32_t [OH_NativeXComponent_RegisterSurfaceHideCallback](_o_h___native_x_component.md#oh_nativexcomponent_registersurfacehidecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册surface隐藏回调，该回调在应用从前台来到后台时触发。  | 
| int32_t [OH_NativeXComponent_GetTouchEventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_gettoucheventsourcetype) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, int32_t pointId, [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype) \*sourceType) | 获取ArkUI XComponent触发触摸事件的输入设备类型。  |
| [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \* [OH_NativeXComponent_GetNativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent_getnativexcomponent) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 基于Native接口创建的组件实例获取OH_NativeXComponent类型的指针。  | 
| int32_t [OH_NativeXComponent_RegisterKeyEventCallbackWithResult](_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallbackwithresult) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, bool(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册有返回值的按键事件回调。  | 
|int32_t [OH_ArkUI_XComponent_StartImageAnalyzer](_o_h___native_x_component.md#oh_arkui_xcomponent_startimageanalyzer) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData,void (\*callback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_XComponent_ImageAnalyzerState](_o_h___native_x_component.md#arkui_xcomponent_imageanalyzerstate) statusCode, void \*userData))|为此XComponent实例开始图像AI分析。|
|int32_t [OH_ArkUI_XComponent_StopImageAnalyzer](_o_h___native_x_component.md#oh_arkui_xcomponent_stopimageanalyzer)([ArkUI_NodeHandle]() node)|为此XComponent实例停止图像AI分析。|

### 变量

| 名称 | 描述 | 
| -------- | -------- |
|  const uint32_t **OH_XCOMPONENT_ID_LEN_MAX** = 128 |  ArkUI XComponent的id的最大长度。| 
|  const uint32_t **OH_MAX_TOUCH_POINTS_NUMBER** = 10 |  触摸事件中的可识别的触摸点个数最大值。| 
