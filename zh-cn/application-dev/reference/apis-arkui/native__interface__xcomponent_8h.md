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
| struct&nbsp;&nbsp;[OH_NativeXComponent_HistoricalPoint](_o_h___native_x_component___historical_point.md) | 历史接触点。 |
| struct&nbsp;&nbsp;[OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) | 鼠标事件。  | 
| struct&nbsp;&nbsp;[OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md) | 注册surface生命周期和触摸事件回调。  | 
| struct&nbsp;&nbsp;[OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md) | 注册鼠标事件回调。  | 
| struct&nbsp;&nbsp;[OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) | 定义期望帧率范围。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)[OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) | 提供封装的OH_NativeXComponent实例。  | 
| typedef struct [OH_NativeXComponent_Callback](_o_h___native_x_component___callback.md)[OH_NativeXComponent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_callback) | 注册surface生命周期和触摸事件回调。  | 
| typedef struct [OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component___mouse_event___callback.md)[OH_NativeXComponent_MouseEvent_Callback](_o_h___native_x_component.md#oh_nativexcomponent_mouseevent_callback) | 注册鼠标事件的回调。  | 
| typedef struct [OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)[OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent) | 提供封装的OH_NativeXComponent_KeyEvent实例。 | 
| [OH_NativeXComponent_ExtraMouseEventInfo](_o_h___native_x_component.md#oh_nativexcomponent_extramouseeventinfo) | 提供封装的扩展的鼠标事件信息实例。|
| [OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback) | 定义surface生命周期回调函数。|
| [OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder) | 提供封装的OH_ArkUI_SurfaceHolder实例。|
| [OHNativeWindow](_o_h___native_x_component.md#ohnativewindow) | 提供封装的NativeWindow实例。|


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { OH_NATIVEXCOMPONENT_RESULT_SUCCESS = 0, OH_NATIVEXCOMPONENT_RESULT_FAILED = -1, OH_NATIVEXCOMPONENT_RESULT_BAD_PARAMETER = -2 } | 枚举API访问状态。  |
| [OH_NativeXComponent_TouchEventType](_o_h___native_x_component.md#oh_nativexcomponent_toucheventtype) {<br/>OH_NATIVEXCOMPONENT_DOWN = 0, OH_NATIVEXCOMPONENT_UP, OH_NATIVEXCOMPONENT_MOVE, OH_NATIVEXCOMPONENT_CANCEL,<br/>OH_NATIVEXCOMPONENT_UNKNOWN<br/>} | 触摸事件类型。  |
| [OH_NativeXComponent_TouchPointToolType](_o_h___native_x_component.md#oh_nativexcomponent_touchpointtooltype) {<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_UNKNOWN = 0, OH_NATIVEXCOMPONENT_TOOL_TYPE_FINGER, OH_NATIVEXCOMPONENT_TOOL_TYPE_PEN, OH_NATIVEXCOMPONENT_TOOL_TYPE_RUBBER,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_BRUSH, OH_NATIVEXCOMPONENT_TOOL_TYPE_PENCIL, OH_NATIVEXCOMPONENT_TOOL_TYPE_AIRBRUSH, OH_NATIVEXCOMPONENT_TOOL_TYPE_MOUSE,<br/>OH_NATIVEXCOMPONENT_TOOL_TYPE_LENS<br/>} | 触摸点工具类型。  |
| [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype) {<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_UNKNOWN = 0, OH_NATIVEXCOMPONENT_SOURCE_TYPE_MOUSE, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHSCREEN, OH_NATIVEXCOMPONENT_SOURCE_TYPE_TOUCHPAD,<br/>OH_NATIVEXCOMPONENT_SOURCE_TYPE_JOYSTICK, OH_NATIVEXCOMPONENT_SOURCE_TYPE_KEYBOARD<br/>} | 触摸事件源类型。  |
| [OH_NativeXComponent_TouchEvent_SourceTool](_o_h___native_x_component.md#oh_nativexcomponent_touchevent_sourcetool) {<br/>OH_NATIVEXCOMPONENT_SOURCETOOL_UNKNOWN = 0, OH_NATIVEXCOMPONENT_SOURCETOOL_FINGER, OH_NATIVEXCOMPONENT_SOURCETOOL_PEN, OH_NATIVEXCOMPONENT_SOURCETOOL_RUBBER,<br/>OH_NATIVEXCOMPONENT_SOURCETOOL_BRUSH, OH_NATIVEXCOMPONENT_SOURCETOOL_PENCIL, OH_NATIVEXCOMPONENT_SOURCETOOL_AIRBRUSH, OH_NATIVEXCOMPONENT_SOURCETOOL_MOUSE,<br/>OH_NATIVEXCOMPONENT_SOURCETOOL_LENS, OH_NATIVEXCOMPONENT_SOURCETOOL_TOUCHPAD<br/>} | 表示触摸事件的源工具类型。 |
| [OH_NativeXComponent_MouseEventAction](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventaction) { OH_NATIVEXCOMPONENT_MOUSE_NONE = 0, OH_NATIVEXCOMPONENT_MOUSE_PRESS, OH_NATIVEXCOMPONENT_MOUSE_RELEASE, OH_NATIVEXCOMPONENT_MOUSE_MOVE } | 鼠标事件动作。 |
| [OH_NativeXComponent_MouseEventButton](_o_h___native_x_component.md#oh_nativexcomponent_mouseeventbutton) {<br/>OH_NATIVEXCOMPONENT_NONE_BUTTON = 0, OH_NATIVEXCOMPONENT_LEFT_BUTTON = 0x01, OH_NATIVEXCOMPONENT_RIGHT_BUTTON = 0x02, OH_NATIVEXCOMPONENT_MIDDLE_BUTTON = 0x04,<br/>OH_NATIVEXCOMPONENT_BACK_BUTTON = 0x08, OH_NATIVEXCOMPONENT_FORWARD_BUTTON = 0x10<br/>} | 鼠标事件按键。  |
|[ArkUI_XComponent_ImageAnalyzerState](_o_h___native_x_component.md#arkui_xcomponent_imageanalyzerstate)&nbsp;{&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_FINISHED&nbsp;=&nbsp;0,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_DISABLED&nbsp;=&nbsp;110000,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_UNSUPPORTED&nbsp;=&nbsp;110001,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_ONGOING&nbsp;=&nbsp;110002,&nbsp;ARKUI_XCOMPONENT_AI_ANALYSIS_STOPPED&nbsp;=&nbsp;110003}|XComponent图像AI分析状态码。|


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
| int32_t [OH_NativeXComponent_GetHistoricalPoints](_o_h___native_x_component.md#oh_nativexcomponent_gethistoricalpoints) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, int32_t \*size, [OH_NativeXComponent_HistoricalPoint](_o_h___native_x_component___historical_point.md) \*\*historicalPoints) | 获取ArkUI XComponent的历史接触点。  | 
| int32_t [OH_NativeXComponent_GetMouseEvent](_o_h___native_x_component.md#oh_nativexcomponent_getmouseevent) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, const void \*window, [OH_NativeXComponent_MouseEvent](_o_h___native_x_component___mouse_event.md) \*mouseEvent) | 获取ArkUI XComponent调度的鼠标事件。  | 
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
| int32_t [OH_NativeXComponent_RegisterOnTouchInterceptCallback](_o_h___native_x_component.md#oh_nativexcomponent_registerontouchinterceptcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [HitTestMode](_ark_u_i___event_module.md#hittestmode)(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, [ArkUI_UIInputEvent](_ark_u_i___event_module.md#arkui_uiinputevent) \*event)) | 为此OH_NativeXComponent实例注册自定义事件拦截回调，并使能在做触摸测试时回调此函数。  |
| int32_t [OH_NativeXComponent_SetNeedSoftKeyboard](_o_h___native_x_component.md#oh_nativexcomponent_setneedsoftkeyboard) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, bool needSoftKeyboard) | 为此OH_NativeXComponent实例设置是否需要软键盘。  | 
| int32_t [OH_NativeXComponent_RegisterSurfaceShowCallback](_o_h___native_x_component.md#oh_nativexcomponent_registersurfaceshowcallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册surface显示回调，该回调在应用从后台返回前台时触发。  | 
| int32_t [OH_NativeXComponent_RegisterSurfaceHideCallback](_o_h___native_x_component.md#oh_nativexcomponent_registersurfacehidecallback) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册surface隐藏回调，该回调在应用从前台来到后台时触发。  | 
| int32_t [OH_NativeXComponent_GetTouchEventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_gettoucheventsourcetype) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, int32_t pointId, [OH_NativeXComponent_EventSourceType](_o_h___native_x_component.md#oh_nativexcomponent_eventsourcetype) \*sourceType) | 获取ArkUI XComponent触发触摸事件的输入设备类型。  |
| [OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \* [OH_NativeXComponent_GetNativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent_getnativexcomponent) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 基于Native接口创建的组件实例获取OH_NativeXComponent类型的指针。  | 
| int32_t [OH_NativeXComponent_RegisterKeyEventCallbackWithResult](_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallbackwithresult) ([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, bool(\*callback)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent) \*component, void \*window)) | 为此OH_NativeXComponent实例注册有返回值的按键事件回调。  | 
|int32_t [OH_ArkUI_XComponent_StartImageAnalyzer](_o_h___native_x_component.md#oh_arkui_xcomponent_startimageanalyzer) ([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, void \*userData,void (\*callback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [ArkUI_XComponent_ImageAnalyzerState](_o_h___native_x_component.md#arkui_xcomponent_imageanalyzerstate) statusCode, void \*userData))|为此XComponent组件实例开始图像AI分析。|
|int32_t [OH_ArkUI_XComponent_StopImageAnalyzer](_o_h___native_x_component.md#oh_arkui_xcomponent_stopimageanalyzer)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|为此XComponent组件实例停止图像AI分析。|
|[OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* [OH_ArkUI_SurfaceCallback_Create](_o_h___native_x_component.md#oh_arkui_surfacecallback_create)()|创建OH_ArkUI_SurfaceCallback对象。|
|void [OH_ArkUI_SurfaceCallback_Dispose](_o_h___native_x_component.md#oh_arkui_surfacecallback_dispose)([OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback)|销毁OH_ArkUI_SurfaceCallback对象。|
|[OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* [OH_ArkUI_SurfaceHolder_Create](_o_h___native_x_component.md#oh_arkui_surfaceholder_create)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|创建XComponent组件的OH_ArkUI_SurfaceHolder对象。|
|void [OH_ArkUI_SurfaceHolder_Dispose](_o_h___native_x_component.md#oh_arkui_surfaceholder_dispose)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder)|销毁OH_ArkUI_SurfaceHolder对象。|
|int32_t [OH_NativeXComponent_GetExtraMouseEventInfo](_o_h___native_x_component.md#oh_nativexcomponent_getextramouseeventinfo)([OH_NativeXComponent](_o_h___native_x_component.md#oh_nativexcomponent)* component, [OH_NativeXComponent_ExtraMouseEventInfo](_o_h___native_x_component.md#oh_nativexcomponent_getextramouseeventinfo)** extraMouseEventInfo)| 从此OH_NativeXComponent实例中获取扩展的鼠标事件信息。|
|int32_t [OH_NativeXComponent_GetMouseEventModifierKeyStates](_o_h___native_x_component.md#oh_nativexcomponent_getmouseeventmodifierkeystates)([OH_NativeXComponent_ExtraMouseEventInfo](_o_h___native_x_component.md#oh_nativexcomponent_getextramouseeventinfo)* ExtraMouseEventInfo, uint64_t* keys)|从OH_NativeXComponent_ExtraMouseEventInfo实例中获取功能键按压状态信息。|
|int32_t [OH_NativeXComponent_GetKeyEventModifierKeyStates](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventmodifierkeystates)([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)* keyEvent, uint64_t* keys)|从按键事件中获取功能键按压状态。|
|int32_t [OH_NativeXComponent_GetKeyEventNumLockState](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventnumlockstate)([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)* keyEvent, bool* isNumLockOn) | 从按键事件中获取NumLock（小键盘锁定）键的状态。|
|int32_t [OH_NativeXComponent_GetKeyEventCapsLockState](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventcapslockstate)([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)* keyEvent, bool* isCapsLockOn)| 从按键事件中获取CapsLock（大写锁定）键的状态。|
|int32_t [OH_NativeXComponent_GetKeyEventScrollLockState](_o_h___native_x_component.md#oh_nativexcomponent_getkeyeventscrolllockstate)([OH_NativeXComponent_KeyEvent](_o_h___native_x_component.md#oh_nativexcomponent_keyevent)* keyEvent, bool* isScrollLockOn) | 从按键事件中获取ScrollLock（滚动锁定）键的状态。|
|int32_t [OH_ArkUI_XComponent_SetExpectedFrameRateRange](_o_h___native_x_component.md#oh_arkui_xcomponent_setexpectedframeraterange)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, [OH_NativeXComponent_ExpectedRateRange](_o_h___native_x_component___expected_rate_range.md) range)|为此XComponent组件实例设置期望帧率。|
|int32_t [OH_ArkUI_XComponent_RegisterOnFrameCallback](_o_h___native_x_component.md#oh_arkui_xcomponent_registeronframecallback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node,void (*callback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, uint64_t timestamp, uint64_t targetTimestamp))|为此XComponent组件实例注册帧回调函数。|
|int32_t [OH_ArkUI_XComponent_UnregisterOnFrameCallback](_o_h___native_x_component.md#oh_arkui_xcomponent_unregisteronframecallback)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|为此XComponent组件实例取消注册帧回调函数。|
|int32_t [OH_ArkUI_XComponent_SetNeedSoftKeyboard](_o_h___native_x_component.md#oh_arkui_xcomponent_setneedsoftkeyboard)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool needSoftKeyboard) | 为此XComponent组件实例设置是否需要软键盘。|
|[ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)* [OH_ArkUI_AccessibilityProvider_Create](_o_h___native_x_component.md#oh_arkui_accessibilityprovider_create)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node) | 基于此XComponent组件实例创建ArkUI_AccessibilityProvider实例。|
|void [OH_ArkUI_AccessibilityProvider_Dispose](_o_h___native_x_component.md#oh_arkui_accessibilityprovider_dispose)([ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)* provider)|销毁由NDK接口[OH_ArkUI_AccessibilityProvider_Create](_o_h___native_x_component.md#oh_arkui_accessibilityprovider_create)创建的[ArkUI_AccessibilityProvider](arkui_native_interface_accessibility.md#arkui_accessibilityprovider)实例。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceShowEvent](_o_h___native_x_component.md#oh_arkui_surfacecallback_setsurfaceshowevent)([OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback,void (\*onSurfaceShow)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder))|为此OH_ArkUI_SurfaceCallback实例设置Surface显示回调。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceHideEvent](_o_h___native_x_component.md#oh_arkui_surfacecallback_setsurfacehideevent)([OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback,void (\*onSurfaceHide)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder))|为此OH_ArkUI_SurfaceCallback实例设置Surface隐藏回调。|
|int32_t [OH_ArkUI_SurfaceHolder_SetUserData](_o_h___native_x_component.md#oh_arkui_surfaceholder_setuserdata)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder,void* userData)|向OH_ArkUI_SurfaceHolder实例存储自定义数据。|
|void* [OH_ArkUI_SurfaceHolder_GetUserData](_o_h___native_x_component.md#oh_arkui_surfaceholder_getuserdata)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder)|获取OH_ArkUI_SurfaceHolder实例存储的自定义数据。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceCreatedEvent](_o_h___native_x_component.md#oh_arkui_surfacecallback_setsurfacecreatedevent)([OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback,void (\*onSurfaceCreated)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)\* surfaceHolder))|设置surface生命周期回调中的创建回调事件。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceChangedEvent](_o_h___native_x_component.md#oh_arkui_surfacecallback_setsurfacechangedevent)([OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback,void (\*onSurfaceChanged)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)\* surfaceHolder,uint64_t width,uint64_t height))|设置surface生命周期回调中的大小改变回调事件。|
|void [OH_ArkUI_SurfaceCallback_SetSurfaceDestroyedEvent](_o_h___native_x_component.md#oh_arkui_surfacecallback_setsurfacedestroyedevent)([OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback,void (\*onSurfaceDestroyed)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)\* surfaceHolder))|设置surface生命周期回调中的销毁回调事件。|
|int32_t [OH_ArkUI_SurfaceHolder_AddSurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfaceholder_addsurfacecallback)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder,[OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback)|添加surface生命周期回调到OH_ArkUI_SurfaceHolder实例。|
|int32_t [OH_ArkUI_SurfaceHolder_RemoveSurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfaceholder_removesurfacecallback)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder,[OH_ArkUI_SurfaceCallback](_o_h___native_x_component.md#oh_arkui_surfacecallback)* callback)|删除OH_ArkUI_SurfaceHolder实例的先前添加的surface生命周期回调。|
|[OHNativeWindow](_o_h___native_x_component.md#ohnativewindow)* [OH_ArkUI_XComponent_GetNativeWindow](_o_h___native_x_component.md#oh_arkui_xcomponent_getnativewindow)([OH_ArkUI_SurfaceHolder](_o_h___native_x_component.md#oh_arkui_surfaceholder)* surfaceHolder)|获取OH_ArkUI_SurfaceHolder实例关联的nativeWindow。|
|int32_t [OH_ArkUI_XComponent_SetAutoInitialize](_o_h___native_x_component.md#oh_arkui_xcomponent_setautoinitialize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node,bool autoInitialize)|设置XComponent组件是否需要自动初始化的标志位。|
|int32_t [OH_ArkUI_XComponent_Initialize](_o_h___native_x_component.md#oh_arkui_xcomponent_initialize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|初始化XComponent组件持有的surface。|
|int32_t [OH_ArkUI_XComponent_Finalize](_o_h___native_x_component.md#oh_arkui_xcomponent_finalize)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node)|销毁XComponent组件持有的surface。|
|int32_t [OH_ArkUI_XComponent_IsInitialized](_o_h___native_x_component.md#oh_arkui_xcomponent_isinitialized)([ArkUI_NodeHandle](_ark_u_i___native_module.md#arkui_nodehandle) node, bool* isInitialized)|获取XComponent组件是否已经初始化的标志位。|


### 变量

| 名称 | 描述 | 
| -------- | -------- |
|  const uint32_t **OH_XCOMPONENT_ID_LEN_MAX** = 128 |  ArkUI XComponent的id的最大长度。| 
|  const uint32_t **OH_MAX_TOUCH_POINTS_NUMBER** = 10 |  触摸事件中的可识别的触摸点个数最大值。| 
