# oh_input_manager.h

## 概述

提供事件注入和关键状态查询等功能。

**库：** libohinput.so

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**相关模块：** [input](capi-input.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Input_InterceptorEventCallback](capi-input-input-interceptoreventcallback.md) | Input_InterceptorEventCallback | 拦截回调事件结构体，拦截鼠标事件、触屏事件和轴事件。 |
| [Input_DeviceListener](capi-input-input-devicelistener.md) | Input_DeviceListener | 定义一个结构体用于监听设备热插拔。 |
| [Input_KeyState](capi-input-input-keystate.md) | Input_KeyState | 定义按键信息，用于标识按键行为。例如，“Ctrl”按键信息包含键值和键类型。 |
| [Input_KeyEvent](capi-input-input-keyevent.md) | Input_KeyEvent | 要注入的按键事件。 |
| [Input_MouseEvent](capi-input-input-mouseevent.md) | Input_MouseEvent | 要注入的鼠标事件。 |
| [Input_TouchEvent](capi-input-input-touchevent.md) | Input_TouchEvent | 要注入的触屏事件。 |
| [Input_AxisEvent](capi-input-input-axisevent.md) | Input_AxisEvent | 轴事件。 |
| [Input_Hotkey](capi-input-input-hotkey.md) | Input_Hotkey | 定义快捷键结构体。 |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) | Input_DeviceInfo | 输入设备信息。 |
| [Input_InterceptorOptions](capi-input-input-interceptoroptions.md) | Input_InterceptorOptions | 事件拦截选项。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [Input_KeyStateAction](#input_keystateaction) | Input_KeyStateAction | 按键状态的枚举值。 |
| [Input_KeyEventAction](#input_keyeventaction) | Input_KeyEventAction | 按键事件类型的枚举值。 |
| [Input_MouseEventAction](#input_mouseeventaction) | Input_MouseEventAction | 鼠标动作的枚举值。 |
| [InputEvent_MouseAxis](#inputevent_mouseaxis) | InputEvent_MouseAxis | 鼠标轴事件类型。 |
| [Input_MouseEventButton](#input_mouseeventbutton) | Input_MouseEventButton | 鼠标按键的枚举值。 |
| [Input_TouchEventAction](#input_toucheventaction) | Input_TouchEventAction | 触屏动作的枚举值。 |
| [Input_InjectionStatus](#input_injectionstatus) | Input_InjectionStatus | 注入权限状态枚举值。 |
| [InputEvent_SourceType](#inputevent_sourcetype) | InputEvent_SourceType | 输入事件源类型。 |
| [Input_KeyboardType](#input_keyboardtype) | Input_KeyboardType | 输入设备的键盘类型。 |
| [Input_Result](#input_result) | Input_Result | 错误码枚举值。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*Input_HotkeyCallback)(Input_Hotkey* hotkey)](#input_hotkeycallback) | Input_HotkeyCallback | 回调函数，用于回调快捷键事件。 |
| [typedef void (\*Input_KeyEventCallback)(const Input_KeyEvent* keyEvent)](#input_keyeventcallback) | Input_KeyEventCallback | 按键事件的回调函数，keyEvent的生命周期为回调函数内。 |
| [typedef void (\*Input_MouseEventCallback)(const Input_MouseEvent* mouseEvent)](#input_mouseeventcallback) | Input_MouseEventCallback | 鼠标事件的回调函数，mouseEvent的生命周期为回调函数内。 |
| [typedef void (\*Input_TouchEventCallback)(const Input_TouchEvent* touchEvent)](#input_toucheventcallback) | Input_TouchEventCallback | 触屏事件的回调函数，touchEvent的生命周期为回调函数内。 |
| [typedef void (\*Input_AxisEventCallback)(const Input_AxisEvent* axisEvent)](#input_axiseventcallback) | Input_AxisEventCallback | 轴事件的回调函数，axisEvent的生命周期为回调函数内。 |
| [typedef void (\*Input_DeviceAddedCallback)(int32_t deviceId)](#input_deviceaddedcallback) | Input_DeviceAddedCallback | 回调函数，用于回调输入设备的热插事件。 |
| [typedef void (\*Input_DeviceRemovedCallback)(int32_t deviceId)](#input_deviceremovedcallback) | Input_DeviceRemovedCallback | 回调函数，用于回调输入设备的热拔事件。 |
| [typedef void (\*Input_InjectAuthorizeCallback)(Input_InjectionStatus authorizedStatus)](#input_injectauthorizecallback) | Input_InjectAuthorizeCallback | 回调函数，用于获取注入权限状态。 |
| [Input_Result OH_Input_GetKeyState(struct Input_KeyState* keyState)](#oh_input_getkeystate) | - | 查询按键状态的枚举对象。 |
| [struct Input_KeyState* OH_Input_CreateKeyState()](#oh_input_createkeystate) | - | 创建按键状态的枚举对象。 |
| [void OH_Input_DestroyKeyState(struct Input_KeyState** keyState)](#oh_input_destroykeystate) | - | 销毁按键状态的枚举对象。 |
| [void OH_Input_SetKeyCode(struct Input_KeyState* keyState, int32_t keyCode)](#oh_input_setkeycode) | - | 设置按键状态对象的键值。 |
| [int32_t OH_Input_GetKeyCode(const struct Input_KeyState* keyState)](#oh_input_getkeycode) | - | 获取按键状态对象的键值。 |
| [void OH_Input_SetKeyPressed(struct Input_KeyState* keyState, int32_t keyAction)](#oh_input_setkeypressed) | - | 设置按键状态对象的按键是否按下。 |
| [int32_t OH_Input_GetKeyPressed(const struct Input_KeyState* keyState)](#oh_input_getkeypressed) | - | 获取按键状态对象的按键是否按下。 |
| [void OH_Input_SetKeySwitch(struct Input_KeyState* keyState, int32_t keySwitch)](#oh_input_setkeyswitch) | - | 设置按键状态对象的按键开关。 |
| [int32_t OH_Input_GetKeySwitch(const struct Input_KeyState* keyState)](#oh_input_getkeyswitch) | - | 获取按键状态对象的按键开关。 |
| [int32_t OH_Input_InjectKeyEvent(const struct Input_KeyEvent* keyEvent)](#oh_input_injectkeyevent) | - | 注入按键事件。 |
| [struct Input_KeyEvent* OH_Input_CreateKeyEvent()](#oh_input_createkeyevent) | - | 创建按键事件对象。 |
| [void OH_Input_DestroyKeyEvent(struct Input_KeyEvent** keyEvent)](#oh_input_destroykeyevent) | - | 销毁按键事件对象。 |
| [void OH_Input_SetKeyEventAction(struct Input_KeyEvent* keyEvent, int32_t action)](#oh_input_setkeyeventaction) | - | 设置按键事件类型。 |
| [int32_t OH_Input_GetKeyEventAction(const struct Input_KeyEvent* keyEvent)](#oh_input_getkeyeventaction) | - | 获取按键事件类型。 |
| [void OH_Input_SetKeyEventKeyCode(struct Input_KeyEvent* keyEvent, int32_t keyCode)](#oh_input_setkeyeventkeycode) | - | 设置按键事件的键值。 |
| [int32_t OH_Input_GetKeyEventKeyCode(const struct Input_KeyEvent* keyEvent)](#oh_input_getkeyeventkeycode) | - | 获取按键事件的键值。 |
| [void OH_Input_SetKeyEventActionTime(struct Input_KeyEvent* keyEvent, int64_t actionTime)](#oh_input_setkeyeventactiontime) | - | 设置按键事件发生的时间。 |
| [int64_t OH_Input_GetKeyEventActionTime(const struct Input_KeyEvent* keyEvent)](#oh_input_getkeyeventactiontime) | - | 获取按键事件发生的时间。 |
| [void OH_Input_SetKeyEventWindowId(struct Input_KeyEvent* keyEvent, int32_t windowId)](#oh_input_setkeyeventwindowid) | - | 设置按键事件的窗口Id。 |
| [int32_t OH_Input_GetKeyEventWindowId(const struct Input_KeyEvent* keyEvent)](#oh_input_getkeyeventwindowid) | - | 获取按键事件的窗口Id。 |
| [void OH_Input_SetKeyEventDisplayId(struct Input_KeyEvent* keyEvent, int32_t displayId)](#oh_input_setkeyeventdisplayid) | - | 设置按键事件的屏幕Id。 |
| [int32_t OH_Input_GetKeyEventDisplayId(const struct Input_KeyEvent* keyEvent)](#oh_input_getkeyeventdisplayid) | - | 获取按键事件的屏幕Id。 |
| [struct Input_MouseEvent* OH_Input_CreateMouseEvent()](#oh_input_createmouseevent) | - | 创建鼠标事件对象。 |
| [void OH_Input_DestroyMouseEvent(struct Input_MouseEvent** mouseEvent)](#oh_input_destroymouseevent) | - | 销毁鼠标事件对象。 |
| [void OH_Input_SetMouseEventAction(struct Input_MouseEvent* mouseEvent, int32_t action)](#oh_input_setmouseeventaction) | - | 设置鼠标事件的动作。 |
| [int32_t OH_Input_GetMouseEventAction(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventaction) | - | 获取鼠标事件的动作。 |
| [void OH_Input_SetMouseEventDisplayX(struct Input_MouseEvent* mouseEvent, int32_t displayX)](#oh_input_setmouseeventdisplayx) | - | 设置鼠标事件的屏幕X坐标。 |
| [int32_t OH_Input_GetMouseEventDisplayX(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventdisplayx) | - | 获取鼠标事件的屏幕X坐标。 |
| [void OH_Input_SetMouseEventDisplayY(struct Input_MouseEvent* mouseEvent, int32_t displayY)](#oh_input_setmouseeventdisplayy) | - | 设置鼠标事件的屏幕Y坐标。 |
| [int32_t OH_Input_GetMouseEventDisplayY(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventdisplayy) | - | 获取鼠标事件的屏幕Y坐标。 |
| [void OH_Input_SetMouseEventButton(struct Input_MouseEvent* mouseEvent, int32_t button)](#oh_input_setmouseeventbutton) | - | 设置鼠标事件的按键。 |
| [int32_t OH_Input_GetMouseEventButton(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventbutton) | - | 获取鼠标事件的按键。 |
| [void OH_Input_SetMouseEventAxisType(struct Input_MouseEvent* mouseEvent, int32_t axisType)](#oh_input_setmouseeventaxistype) | - | 设置鼠标轴事件的类型。 |
| [int32_t OH_Input_GetMouseEventAxisType(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventaxistype) | - | 获取鼠标轴事件的类型。 |
| [void OH_Input_SetMouseEventAxisValue(struct Input_MouseEvent* mouseEvent, float axisValue)](#oh_input_setmouseeventaxisvalue) | - | 设置鼠标轴事件的值。 |
| [float OH_Input_GetMouseEventAxisValue(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventaxisvalue) | - | 获取鼠标轴事件的值。 |
| [void OH_Input_SetMouseEventActionTime(struct Input_MouseEvent* mouseEvent, int64_t actionTime)](#oh_input_setmouseeventactiontime) | - | 设置鼠标事件发生的时间。 |
| [int64_t OH_Input_GetMouseEventActionTime(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventactiontime) | - | 获取鼠标事件发生的时间。 |
| [void OH_Input_SetMouseEventWindowId(struct Input_MouseEvent* mouseEvent, int32_t windowId)](#oh_input_setmouseeventwindowid) | - | 设置鼠标事件的窗口Id。 |
| [int32_t OH_Input_GetMouseEventWindowId(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventwindowid) | - | 获取鼠标事件的窗口Id。 |
| [void OH_Input_SetMouseEventDisplayId(struct Input_MouseEvent* mouseEvent, int32_t displayId)](#oh_input_setmouseeventdisplayid) | - | 设置鼠标事件的屏幕Id。 |
| [struct Input_TouchEvent* OH_Input_CreateTouchEvent()](#oh_input_createtouchevent) | - | 创建触屏事件对象。 |
| [void OH_Input_DestroyTouchEvent(struct Input_TouchEvent** touchEvent)](#oh_input_destroytouchevent) | - | 销毁触屏事件对象。 |
| [void OH_Input_SetTouchEventAction(struct Input_TouchEvent* touchEvent, int32_t action)](#oh_input_settoucheventaction) | - | 设置触屏事件的动作。 |
| [int32_t OH_Input_GetTouchEventAction(const struct Input_TouchEvent* touchEvent)](#oh_input_gettoucheventaction) | - | 获取触屏事件的动作。 |
| [void OH_Input_SetTouchEventFingerId(struct Input_TouchEvent* touchEvent, int32_t id)](#oh_input_settoucheventfingerid) | - | 设置触屏事件的手指ID。 |
| [int32_t OH_Input_GetTouchEventFingerId(const struct Input_TouchEvent* touchEvent)](#oh_input_gettoucheventfingerid) | - | 获取触屏事件的手指ID。 |
| [void OH_Input_SetTouchEventDisplayX(struct Input_TouchEvent* touchEvent, int32_t displayX)](#oh_input_settoucheventdisplayx) | - | 设置触屏事件的屏幕X坐标。 |
| [int32_t OH_Input_GetTouchEventDisplayX(const struct Input_TouchEvent* touchEvent)](#oh_input_gettoucheventdisplayx) | - | 获取触屏事件的屏幕X坐标。 |
| [void OH_Input_SetTouchEventDisplayY(struct Input_TouchEvent* touchEvent, int32_t displayY)](#oh_input_settoucheventdisplayy) | - | 设置触屏事件的屏幕Y坐标。 |
| [int32_t OH_Input_GetTouchEventDisplayY(const struct Input_TouchEvent* touchEvent)](#oh_input_gettoucheventdisplayy) | - | 获取触屏事件的屏幕Y坐标。 |
| [void OH_Input_SetTouchEventActionTime(struct Input_TouchEvent* touchEvent, int64_t actionTime)](#oh_input_settoucheventactiontime) | - | 设置触屏事件发生的时间。 |
| [int64_t OH_Input_GetTouchEventActionTime(const struct Input_TouchEvent* touchEvent)](#oh_input_gettoucheventactiontime) | - | 获取触屏事件发生的时间。 |
| [void OH_Input_SetTouchEventWindowId(struct Input_TouchEvent* touchEvent, int32_t windowId)](#oh_input_settoucheventwindowid) | - | 设置触屏事件的窗口Id。 |
| [int32_t OH_Input_GetTouchEventWindowId(const struct Input_TouchEvent* touchEvent)](#oh_input_gettoucheventwindowid) | - | 获取触屏事件的窗口Id。 |
| [void OH_Input_SetTouchEventDisplayId(struct Input_TouchEvent* touchEvent, int32_t displayId)](#oh_input_settoucheventdisplayid) | - | 设置触屏事件的屏幕Id。 |
| [int32_t OH_Input_GetTouchEventDisplayId(const struct Input_TouchEvent* touchEvent)](#oh_input_gettoucheventdisplayid) | - | 获取触屏事件的屏幕Id。 |
| [void OH_Input_CancelInjection()](#oh_input_cancelinjection) | - | 取消事件注入并撤销授权。 |
| [Input_Result OH_Input_RequestInjection(Input_InjectAuthorizeCallback callback)](#oh_input_requestinjection) | - | 当前应用申请注入权限，包括申请注入按键事件[OH_Input_InjectKeyEvent](capi-oh-input-manager-h.md#oh_input_injectkeyevent)、注入触屏事件[OH_Input_InjectTouchEvent](capi-oh-input-manager-h.md#oh_input_injecttouchevent)、注入鼠标事件[OH_Input_InjectMouseEvent](capi-oh-input-manager-h.md#oh_input_injectmouseevent)等注入操作的权限。该接口仅在PC/2in1设备上生效。 |
| [Input_Result OH_Input_QueryAuthorizedStatus(Input_InjectionStatus* status)](#oh_input_queryauthorizedstatus) | - | 查询当前应用注入的权限状态。 |
| [Input_AxisEvent* OH_Input_CreateAxisEvent(void)](#oh_input_createaxisevent) | - | 创建轴事件对象实例。 |
| [Input_Result OH_Input_DestroyAxisEvent(Input_AxisEvent** axisEvent)](#oh_input_destroyaxisevent) | - | 销毁轴事件对象实例。 |
| [Input_Result OH_Input_SetAxisEventAction(Input_AxisEvent* axisEvent, InputEvent_AxisAction action)](#oh_input_setaxiseventaction) | - | 设置轴事件的动作。 |
| [Input_Result OH_Input_GetAxisEventAction(const Input_AxisEvent* axisEvent, InputEvent_AxisAction *action)](#oh_input_getaxiseventaction) | - | 获取轴事件的动作。 |
| [Input_Result OH_Input_SetAxisEventDisplayX(Input_AxisEvent* axisEvent, float displayX)](#oh_input_setaxiseventdisplayx) | - | 设置轴事件的X坐标。 |
| [Input_Result OH_Input_GetAxisEventDisplayX(const Input_AxisEvent* axisEvent, float* displayX)](#oh_input_getaxiseventdisplayx) | - | 获取轴事件的X坐标。 |
| [Input_Result OH_Input_SetAxisEventDisplayY(Input_AxisEvent* axisEvent, float displayY)](#oh_input_setaxiseventdisplayy) | - | 设置轴事件的Y坐标。 |
| [Input_Result OH_Input_GetAxisEventDisplayY(const Input_AxisEvent* axisEvent, float* displayY)](#oh_input_getaxiseventdisplayy) | - | 获取轴事件的Y坐标。 |
| [Input_Result OH_Input_SetAxisEventAxisValue(Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double axisValue)](#oh_input_setaxiseventaxisvalue) | - | 设置轴事件指定轴类型的轴值。 |
| [Input_Result OH_Input_GetAxisEventAxisValue(const Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double* axisValue)](#oh_input_getaxiseventaxisvalue) | - | 获取轴事件指定轴类型的轴值。 |
| [Input_Result OH_Input_SetAxisEventActionTime(Input_AxisEvent* axisEvent, int64_t actionTime)](#oh_input_setaxiseventactiontime) | - | 设置轴事件发生的时间。 |
| [Input_Result OH_Input_GetAxisEventActionTime(const Input_AxisEvent* axisEvent, int64_t* actionTime)](#oh_input_getaxiseventactiontime) | - | 获取轴事件发生的时间。 |
| [Input_Result OH_Input_SetAxisEventType(Input_AxisEvent* axisEvent, InputEvent_AxisEventType axisEventType)](#oh_input_setaxiseventtype) | - | 设置轴事件类型。 |
| [Input_Result OH_Input_GetAxisEventType(const Input_AxisEvent* axisEvent, InputEvent_AxisEventType* axisEventType)](#oh_input_getaxiseventtype) | - | 获取轴事件类型。 |
| [Input_Result OH_Input_SetAxisEventSourceType(Input_AxisEvent* axisEvent, InputEvent_SourceType sourceType)](#oh_input_setaxiseventsourcetype) | - | 设置轴事件源类型。 |
| [Input_Result OH_Input_GetAxisEventSourceType(const Input_AxisEvent* axisEvent, InputEvent_SourceType* sourceType)](#oh_input_getaxiseventsourcetype) | - | 获取轴事件源类型。 |
| [Input_Result OH_Input_SetAxisEventWindowId(Input_AxisEvent* axisEvent, int32_t windowId)](#oh_input_setaxiseventwindowid) | - | 设置轴事件的窗口Id。 |
| [Input_Result OH_Input_GetAxisEventWindowId(const Input_AxisEvent* axisEvent, int32_t* windowId)](#oh_input_getaxiseventwindowid) | - | 获取轴事件的窗口Id。 |
| [Input_Result OH_Input_SetAxisEventDisplayId(Input_AxisEvent* axisEvent, int32_t displayId)](#oh_input_setaxiseventdisplayid) | - | 设置轴事件的屏幕Id。 |
| [Input_Result OH_Input_GetAxisEventDisplayId(const Input_AxisEvent* axisEvent, int32_t* displayId)](#oh_input_getaxiseventdisplayid) | - | 获取轴事件的屏幕Id。 |
| [Input_Result OH_Input_AddKeyEventMonitor(Input_KeyEventCallback callback)](#oh_input_addkeyeventmonitor) | - | 添加按键事件监听。 |
| [Input_Result OH_Input_AddMouseEventMonitor(Input_MouseEventCallback callback)](#oh_input_addmouseeventmonitor) | - | 添加鼠标事件监听,包含鼠标点击，移动，不包含滚轮事件，滚轮事件归属于轴事件。 |
| [Input_Result OH_Input_AddTouchEventMonitor(Input_TouchEventCallback callback)](#oh_input_addtoucheventmonitor) | - | 添加触屏事件监听。 |
| [Input_Result OH_Input_AddAxisEventMonitorForAll(Input_AxisEventCallback callback)](#oh_input_addaxiseventmonitorforall) | - | 添加所有类型轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。 |
| [Input_Result OH_Input_AddAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)](#oh_input_addaxiseventmonitor) | - | 添加指定类型的轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。 |
| [Input_Result OH_Input_RemoveKeyEventMonitor(Input_KeyEventCallback callback)](#oh_input_removekeyeventmonitor) | - | 移除按键事件监听。 |
| [Input_Result OH_Input_RemoveMouseEventMonitor(Input_MouseEventCallback callback)](#oh_input_removemouseeventmonitor) | - | 移除鼠标事件监听。 |
| [Input_Result OH_Input_RemoveTouchEventMonitor(Input_TouchEventCallback callback)](#oh_input_removetoucheventmonitor) | - | 移除触屏事件监听。 |
| [Input_Result OH_Input_RemoveAxisEventMonitorForAll(Input_AxisEventCallback callback)](#oh_input_removeaxiseventmonitorforall) | - | 移除所有类型轴事件监听。 |
| [Input_Result OH_Input_RemoveAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)](#oh_input_removeaxiseventmonitor) | - | 移除指定类型轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。 |
| [Input_Result OH_Input_AddKeyEventInterceptor(Input_KeyEventCallback callback, Input_InterceptorOptions *option)](#oh_input_addkeyeventinterceptor) | - | 添加按键事件的拦截，重复添加只有第一次生效。仅在应用获焦时拦截按键事件。 |
| [Input_Result OH_Input_AddInputEventInterceptor(Input_InterceptorEventCallback *callback,Input_InterceptorOptions *option)](#oh_input_addinputeventinterceptor) | - | 添加输入事件拦截，包括鼠标、触屏和轴事件，重复添加只有第一次生效。仅命中应用窗口时拦截输入事件。 |
| [Input_Result OH_Input_RemoveKeyEventInterceptor(void)](#oh_input_removekeyeventinterceptor) | - | 移除按键事件拦截。 |
| [Input_Result OH_Input_RemoveInputEventInterceptor(void)](#oh_input_removeinputeventinterceptor) | - | 移除输入事件拦截，包括鼠标、触屏和轴事件。 |
| [Input_Result OH_Input_GetIntervalSinceLastInput(int64_t *timeInterval)](#oh_input_getintervalsincelastinput) | - | 获取距离上次系统输入事件的时间间隔。 |
| [Input_Hotkey *OH_Input_CreateHotkey(void)](#oh_input_createhotkey) | - | 创建快捷键对象的实例。 |
| [void OH_Input_DestroyHotkey(Input_Hotkey **hotkey)](#oh_input_destroyhotkey) | - | 销毁快捷键对象的实例。 |
| [void OH_Input_SetPreKeys(Input_Hotkey *hotkey, int32_t *preKeys, int32_t size)](#oh_input_setprekeys) | - | 设置修饰键。 |
| [Input_Result OH_Input_GetPreKeys(const Input_Hotkey *hotkey, int32_t **preKeys, int32_t *preKeyCount)](#oh_input_getprekeys) | - | 获取修饰键。 |
| [void OH_Input_SetFinalKey(Input_Hotkey* hotkey, int32_t finalKey)](#oh_input_setfinalkey) | - | 设置被修饰键。 |
| [Input_Result OH_Input_GetFinalKey(const Input_Hotkey* hotkey, int32_t *finalKeyCode)](#oh_input_getfinalkey) | - | 获取被修饰键。 |
| [Input_Hotkey **OH_Input_CreateAllSystemHotkeys(int32_t count)](#oh_input_createallsystemhotkeys) | - | 创建[Input_Hotkey](capi-input-input-hotkey.md)类型实例的数组。 |
| [void OH_Input_DestroyAllSystemHotkeys(Input_Hotkey **hotkeys, int32_t count)](#oh_input_destroyallsystemhotkeys) | - | 销毁[Input_Hotkey](capi-input-input-hotkey.md)实例数组并回收内存。 |
| [Input_Result OH_Input_GetAllSystemHotkeys(Input_Hotkey **hotkey, int32_t *count)](#oh_input_getallsystemhotkeys) | - | 获取设置的所有快捷键。 |
| [void OH_Input_SetRepeat(Input_Hotkey* hotkey, bool isRepeat)](#oh_input_setrepeat) | - | 设置是否上报重复key事件。 |
| [Input_Result OH_Input_GetRepeat(const Input_Hotkey* hotkey, bool *isRepeat)](#oh_input_getrepeat) | - | 获取是否上报重复key事件。 |
| [Input_Result OH_Input_AddHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)](#oh_input_addhotkeymonitor) | - | 订阅快捷键事件。此接口在智能穿戴、轻量级智能穿戴设备不生效。 |
| [Input_Result OH_Input_RemoveHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)](#oh_input_removehotkeymonitor) | - | 取消订阅快捷键。 |
| [Input_Result OH_Input_RegisterDeviceListener(Input_DeviceListener* listener)](#oh_input_registerdevicelistener) | - | 注册设备热插拔的监听器。 |
| [Input_Result OH_Input_UnregisterDeviceListener(Input_DeviceListener* listener)](#oh_input_unregisterdevicelistener) | - | 取消注册设备热插拔的监听。 |
| [Input_Result OH_Input_UnregisterDeviceListeners()](#oh_input_unregisterdevicelisteners) | - | 取消注册所有的设备热插拔的监听。 |
| [Input_Result OH_Input_GetDeviceIds(int32_t *deviceIds, int32_t inSize, int32_t *outSize)](#oh_input_getdeviceids) | - | 获取所有输入设备的ID列表。 |
| [Input_Result OH_Input_GetDevice(int32_t deviceId, Input_DeviceInfo **deviceInfo)](#oh_input_getdevice) | - | 获取输入设备信息。 |
| [Input_DeviceInfo* OH_Input_CreateDeviceInfo(void)](#oh_input_createdeviceinfo) | - | 创建输入设备信息的对象。 |
| [void OH_Input_DestroyDeviceInfo(Input_DeviceInfo **deviceInfo)](#oh_input_destroydeviceinfo) | - | 销毁输入设备信息的对象。 |
| [Input_Result OH_Input_GetKeyboardType(int32_t deviceId, int32_t *keyboardType)](#oh_input_getkeyboardtype) | - | 获取输入设备的键盘类型。 |
| [Input_Result OH_Input_GetDeviceId(Input_DeviceInfo *deviceInfo, int32_t *id)](#oh_input_getdeviceid) | - | 获取输入设备的id。 |
| [Input_Result OH_Input_GetDeviceName(Input_DeviceInfo *deviceInfo, char **name)](#oh_input_getdevicename) | - | 获取输入设备的名称。 |
| [Input_Result OH_Input_GetCapabilities(Input_DeviceInfo *deviceInfo, int32_t *capabilities)](#oh_input_getcapabilities) | - | 获取有关输入设备能力信息，比如设备是触摸屏、触控板、键盘等。 |
| [Input_Result OH_Input_GetDeviceVersion(Input_DeviceInfo *deviceInfo, int32_t *version)](#oh_input_getdeviceversion) | - | 获取输入设备的版本信息。 |
| [Input_Result OH_Input_GetDeviceProduct(Input_DeviceInfo *deviceInfo, int32_t *product)](#oh_input_getdeviceproduct) | - | 获取输入设备的产品信息。 |
| [Input_Result OH_Input_GetDeviceVendor(Input_DeviceInfo *deviceInfo, int32_t *vendor)](#oh_input_getdevicevendor) | - | 获取输入设备的厂商信息。 |
| [Input_Result OH_Input_GetDeviceAddress(Input_DeviceInfo *deviceInfo, char **address)](#oh_input_getdeviceaddress) | - | 获取输入设备的物理地址。 |
| [Input_Result OH_Input_GetFunctionKeyState(int32_t keyCode, int32_t *state)](#oh_input_getfunctionkeystate) | - | 获取功能键状态。 |
| [int32_t OH_Input_InjectTouchEvent(const struct Input_TouchEvent* touchEvent)](#oh_input_injecttouchevent) | - | 注入触屏事件。 |
| [int32_t OH_Input_InjectMouseEvent(const struct Input_MouseEvent* mouseEvent)](#oh_input_injectmouseevent) | - | 注入鼠标事件。 |
| [int32_t OH_Input_GetMouseEventDisplayId(const struct Input_MouseEvent* mouseEvent)](#oh_input_getmouseeventdisplayid) | - | 获取鼠标事件的屏幕Id。 |

## 枚举类型说明

### Input_KeyStateAction

```
enum Input_KeyStateAction
```

**描述**

按键状态的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| KEY_DEFAULT = -1 | 默认状态。 |
| KEY_PRESSED = 0 | 按键按下。 |
| KEY_RELEASED = 1 | 按键抬起。 |
| KEY_SWITCH_ON = 2 | 按键开关使能。 |
| KEY_SWITCH_OFF = 3 | 按键开关去使能。 |

### Input_KeyEventAction

```
enum Input_KeyEventAction
```

**描述**

按键事件类型的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| KEY_ACTION_CANCEL = 0 | 按键动作取消。 |
| KEY_ACTION_DOWN = 1 | 按键按下。 |
| KEY_ACTION_UP = 2 | 按键抬起。 |

### Input_MouseEventAction

```
enum Input_MouseEventAction
```

**描述**

鼠标动作的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MOUSE_ACTION_CANCEL = 0 | 取消鼠标动作。 |
| MOUSE_ACTION_MOVE = 1 | 移动鼠标。 |
| MOUSE_ACTION_BUTTON_DOWN = 2 | 按下鼠标。 |
| MOUSE_ACTION_BUTTON_UP = 3 | 抬起鼠标按键。 |
| MOUSE_ACTION_AXIS_BEGIN = 4 | 鼠标轴事件开始。 |
| MOUSE_ACTION_AXIS_UPDATE = 5 | 更新鼠标轴事件。 |
| MOUSE_ACTION_AXIS_END = 6 | 鼠标轴事件结束。 |

### InputEvent_MouseAxis

```
enum InputEvent_MouseAxis
```

**描述**

鼠标轴事件类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MOUSE_AXIS_SCROLL_VERTICAL = 0 | 垂直滚动轴。 |
| MOUSE_AXIS_SCROLL_HORIZONTAL = 1 | 水平滚动轴。 |

### Input_MouseEventButton

```
enum Input_MouseEventButton
```

**描述**

鼠标按键的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| MOUSE_BUTTON_NONE = -1 | 无效按键。 |
| MOUSE_BUTTON_LEFT = 0 | 鼠标左键。 |
| MOUSE_BUTTON_MIDDLE = 1 | 鼠标中间键。 |
| MOUSE_BUTTON_RIGHT = 2 | 鼠标右键。 |
| MOUSE_BUTTON_FORWARD = 3 | 鼠标前进键。 |
| MOUSE_BUTTON_BACK = 4 | 鼠标返回键。 |

### Input_TouchEventAction

```
enum Input_TouchEventAction
```

**描述**

触屏动作的枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| TOUCH_ACTION_CANCEL = 0 | 触屏取消。 |
| TOUCH_ACTION_DOWN = 1 | 触屏按下。 |
| TOUCH_ACTION_MOVE = 2 | 触屏移动。 |
| TOUCH_ACTION_UP = 3 | 触屏抬起。 |

### Input_InjectionStatus

```
enum Input_InjectionStatus
```

**描述**

注入权限状态枚举值。

**起始版本：** 20

| 枚举项 | 描述 |
| -- | -- |
| UNAUTHORIZED = 0 | 未授权。 |
| AUTHORIZING = 1 | 授权中。 |
| AUTHORIZED = 2 | 已授权。 |

### InputEvent_SourceType

```
enum InputEvent_SourceType
```

**描述**

输入事件源类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| SOURCE_TYPE_MOUSE = 1 | 表示输入源生成鼠标光标移动、按钮按下和释放以及滚轮滚动的事件。 |
| SOURCE_TYPE_TOUCHSCREEN = 2 | 表示输入源产生触摸屏多点触屏事件。 |
| SOURCE_TYPE_TOUCHPAD = 3 | 表示输入源产生触摸板多点触屏事件。 |

### Input_KeyboardType

```
enum Input_KeyboardType
```

**描述**

输入设备的键盘类型。

**起始版本：** 13

| 枚举项 | 描述 |
| -- | -- |
| KEYBOARD_TYPE_NONE = 0 | 表示无按键设备。 |
| KEYBOARD_TYPE_UNKNOWN = 1 | 表示未知按键设备。 |
| KEYBOARD_TYPE_ALPHABETIC = 2 | 表示全键盘设备。 |
| KEYBOARD_TYPE_DIGITAL = 3 | 表示数字键盘设备。 |
| KEYBOARD_TYPE_STYLUS = 4 | 表示手写笔设备。 |
| KEYBOARD_TYPE_REMOTE_CONTROL = 5 | 表示遥控器设备。 |

### Input_Result

```
enum Input_Result
```

**描述**

错误码枚举值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| INPUT_SUCCESS = 0 | 操作成功。 |
| INPUT_PERMISSION_DENIED = 201 | 权限验证失败。 |
| INPUT_NOT_SYSTEM_APPLICATION = 202 | 非系统应用。 |
| INPUT_PARAMETER_ERROR = 401 | 参数检查失败。 |
| INPUT_DEVICE_NOT_SUPPORTED = 801 | 表示功能不受支持。<br>**起始版本：** 14。|
| INPUT_SERVICE_EXCEPTION = 3800001 | 服务异常。 |
| INPUT_REPEAT_INTERCEPTOR = 4200001 | 应用创建拦截后，再次执行创建拦截的操作。 |
| INPUT_OCCUPIED_BY_SYSTEM = 4200002 | 已经被系统应用占用。<br>**起始版本：** 14。 |
| INPUT_OCCUPIED_BY_OTHER = 4200003 | 已经被其他应用占用。<br>**起始版本：** 14。 |
| INPUT_KEYBOARD_DEVICE_NOT_EXIST = 3900002 |  未连接键盘设备。<br>**起始版本：** 15。 |
| INPUT_INJECTION_AUTHORIZING = 3900005 |  正在授权中。<br>**起始版本：** 20。 |
| INPUT_INJECTION_OPERATION_FREQUENT = 3900006 |  重复请求。<br>**起始版本：** 20。 |
| INPUT_INJECTION_AUTHORIZED = 3900007 |  当前应用已经授权。<br>**起始版本：** 20。 |
| INPUT_INJECTION_AUTHORIZED_OTHERS = 3900008 |  其它应用已经授权。<br>**起始版本：** 20。 |


## 函数说明

### Input_HotkeyCallback()

```
typedef void (*Input_HotkeyCallback)(Input_Hotkey* hotkey)
```

**描述**

回调函数，用于回调快捷键事件。

**起始版本：** 14

### Input_KeyEventCallback()

```
typedef void (*Input_KeyEventCallback)(const Input_KeyEvent* keyEvent)
```

**描述**

按键事件的回调函数，keyEvent的生命周期为回调函数内。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |

### Input_MouseEventCallback()

```
typedef void (*Input_MouseEventCallback)(const Input_MouseEvent* mouseEvent)
```

**描述**

鼠标事件的回调函数，mouseEvent的生命周期为回调函数内。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

### Input_TouchEventCallback()

```
typedef void (*Input_TouchEventCallback)(const Input_TouchEvent* touchEvent)
```

**描述**

触屏事件的回调函数，touchEvent的生命周期为回调函数内。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

### Input_AxisEventCallback()

```
typedef void (*Input_AxisEventCallback)(const Input_AxisEvent* axisEvent)
```

**描述**

轴事件的回调函数，axisEvent的生命周期为回调函数内。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |

### Input_DeviceAddedCallback()

```
typedef void (*Input_DeviceAddedCallback)(int32_t deviceId)
```

**描述**

回调函数，用于回调输入设备的热插事件。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备的ID。 |

### Input_DeviceRemovedCallback()

```
typedef void (*Input_DeviceRemovedCallback)(int32_t deviceId)
```

**描述**

回调函数，用于回调输入设备的热拔事件。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备的ID。 |

### Input_InjectAuthorizeCallback()

```
typedef void (*Input_InjectAuthorizeCallback)(Input_InjectionStatus authorizedStatus)
```

**描述**

回调函数，用于获取注入权限状态。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_InjectionStatus](capi-oh-input-manager-h.md#input_injectionstatus) authorizedStatus | 注入权限状态。 |

### OH_Input_GetKeyState()

```
Input_Result OH_Input_GetKeyState(struct Input_KeyState* keyState)
```

**描述**

查询按键状态的枚举对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyState](capi-input-input-keystate.md)* keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](#input_keystateaction)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 如果操作成功，@return返回[INPUT_SUCCESS](#input_result)； <br> 否则返回[Input_Result](#input_result)中定义的其他错误代码。 |

### OH_Input_CreateKeyState()

```
struct Input_KeyState* OH_Input_CreateKeyState()
```

**描述**

创建按键状态的枚举对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| struct | 如果操作成功，@return返回一个[Input_KeyState](capi-input-input-keystate.md)指针对象；否则返回空指针。 |

### OH_Input_DestroyKeyState()

```
void OH_Input_DestroyKeyState(struct Input_KeyState** keyState)
```

**描述**

销毁按键状态的枚举对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyState](capi-input-input-keystate.md)** keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](#input_keystateaction)。 |

### OH_Input_SetKeyCode()

```
void OH_Input_SetKeyCode(struct Input_KeyState* keyState, int32_t keyCode)
```

**描述**

设置按键状态对象的键值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyState](capi-input-input-keystate.md)* keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](#input_keystateaction)。 |
| int32_t keyCode | 按键键值。 |

### OH_Input_GetKeyCode()

```
int32_t OH_Input_GetKeyCode(const struct Input_KeyState* keyState)
```

**描述**

获取按键状态对象的键值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyState](capi-input-input-keystate.md)* keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](capi-oh-input-manager-h.md#input_keystateaction)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回按键状态对象的键值。 |

### OH_Input_SetKeyPressed()

```
void OH_Input_SetKeyPressed(struct Input_KeyState* keyState, int32_t keyAction)
```

**描述**

设置按键状态对象的按键是否按下。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyState](capi-input-input-keystate.md)* keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](#input_keystateaction)。 |
| int32_t keyAction | 按键是否按下，具体请参考[Input_KeyEventAction](#input_keyeventaction)。 |

### OH_Input_GetKeyPressed()

```
int32_t OH_Input_GetKeyPressed(const struct Input_KeyState* keyState)
```

**描述**

获取按键状态对象的按键是否按下。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyState](capi-input-input-keystate.md)* keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](capi-oh-input-manager-h.md#input_keystateaction)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回按键状态对象的按键按下状态。 |

### OH_Input_SetKeySwitch()

```
void OH_Input_SetKeySwitch(struct Input_KeyState* keyState, int32_t keySwitch)
```

**描述**

设置按键状态对象的按键开关。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyState](capi-input-input-keystate.md)* keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](#input_keystateaction)。 |
| int32_t keySwitch | 按键开关。 |

### OH_Input_GetKeySwitch()

```
int32_t OH_Input_GetKeySwitch(const struct Input_KeyState* keyState)
```

**描述**

获取按键状态对象的按键开关。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyState](capi-input-input-keystate.md)* keyState | 按键状态的枚举对象，具体请参考[Input_KeyStateAction](capi-oh-input-manager-h.md#input_keystateaction)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回按键状态对象的按键开关。 |

### OH_Input_InjectKeyEvent()

```
int32_t OH_Input_InjectKeyEvent(const struct Input_KeyEvent* keyEvent)
```

**描述**

注入按键事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | OH_Input_InjectKeyEvent 函数错误码。<br>         若注入成功，返回[INPUT_SUCCESS](capi-oh-input-manager-h.md#input_result)；<br>         若缺少权限，返回[INPUT_PERMISSION_DENIED](capi-oh-input-manager-h.md#input_result)；<br>         若参数错误，返回[INPUT_PARAMETER_ERROR](capi-oh-input-manager-h.md#input_result)。 |

### OH_Input_CreateKeyEvent()

```
struct Input_KeyEvent* OH_Input_CreateKeyEvent()
```

**描述**

创建按键事件对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| struct | 如果操作成功返回一个[Input_KeyEvent](capi-input-input-keyevent.md)指针对象，否则返回空指针。 |

### OH_Input_DestroyKeyEvent()

```
void OH_Input_DestroyKeyEvent(struct Input_KeyEvent** keyEvent)
```

**描述**

销毁按键事件对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyEvent](capi-input-input-keyevent.md)** keyEvent | 按键事件对象。 |

### OH_Input_SetKeyEventAction()

```
void OH_Input_SetKeyEventAction(struct Input_KeyEvent* keyEvent, int32_t action)
```

**描述**

设置按键事件类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |
| int32_t action | 按键事件类型。相关取值可参考[Input_KeyEventAction](#input_keyeventaction)。 |

### OH_Input_GetKeyEventAction()

```
int32_t OH_Input_GetKeyEventAction(const struct Input_KeyEvent* keyEvent)
```

**描述**

获取按键事件类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 返回按键事件类型。相关取值可参考[Input_KeyEventAction](#input_keyeventaction)。 |

### OH_Input_SetKeyEventKeyCode()

```
void OH_Input_SetKeyEventKeyCode(struct Input_KeyEvent* keyEvent, int32_t keyCode)
```

**描述**

设置按键事件的键值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |
| int32_t keyCode | 按键的键值。 |

### OH_Input_GetKeyEventKeyCode()

```
int32_t OH_Input_GetKeyEventKeyCode(const struct Input_KeyEvent* keyEvent)
```

**描述**

获取按键事件的键值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | Key code. |

### OH_Input_SetKeyEventActionTime()

```
void OH_Input_SetKeyEventActionTime(struct Input_KeyEvent* keyEvent, int64_t actionTime)
```

**描述**

设置按键事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |
| int64_t actionTime | 按键事件发生的时间，表示从1970.1.1 00:00:00 GMT逝去的微秒数。 |

### OH_Input_GetKeyEventActionTime()

```
int64_t OH_Input_GetKeyEventActionTime(const struct Input_KeyEvent* keyEvent)
```

**描述**

获取按键事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回按键事件发生的时间。 |

### OH_Input_SetKeyEventWindowId()

```
void OH_Input_SetKeyEventWindowId(struct Input_KeyEvent* keyEvent, int32_t windowId)
```

**描述**

设置按键事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |
| int32_t windowId | 按键事件对应的窗口Id。 |

### OH_Input_GetKeyEventWindowId()

```
int32_t OH_Input_GetKeyEventWindowId(const struct Input_KeyEvent* keyEvent)
```

**描述**

获取按键事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 按键事件的窗口Id。 |

### OH_Input_GetKeyEventDisplayId()

```
int32_t OH_Input_GetKeyEventDisplayId(const struct Input_KeyEvent* keyEvent)
```

**描述**

获取按键事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 按键事件的屏幕Id。 |

### OH_Input_SetKeyEventDisplayId()

```
void OH_Input_SetKeyEventDisplayId(struct Input_KeyEvent* keyEvent, int32_t displayId)
```

**描述**

设置按键事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_KeyEvent](capi-input-input-keyevent.md)* keyEvent | 按键事件对象，通过[OH_Input_CreateKeyEvent](#oh_input_createkeyevent)接口可以创建按键事件对象。<br>使用完需使用[OH_Input_DestroyKeyEvent](#oh_input_destroykeyevent)接口销毁按键事件对象。 |
| int32_t displayId | 按键事件对应的屏幕Id。 |

### OH_Input_CreateMouseEvent()

```
struct Input_MouseEvent* OH_Input_CreateMouseEvent()
```

**描述**

创建鼠标事件对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| struct | 如果操作成功返回一个[Input_MouseEvent](capi-input-input-mouseevent.md)指针对象，否则返回空指针。 |

### OH_Input_DestroyMouseEvent()

```
void OH_Input_DestroyMouseEvent(struct Input_MouseEvent** mouseEvent)
```

**描述**

销毁鼠标事件对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)** mouseEvent | 鼠标事件对象。 |

### OH_Input_SetMouseEventAction()

```
void OH_Input_SetMouseEventAction(struct Input_MouseEvent* mouseEvent, int32_t action)
```

**描述**

设置鼠标事件的动作。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int32_t action | 鼠标的动作。相关取值可参考[Input_MouseEventAction](#input_mouseeventaction)。 |

### OH_Input_GetMouseEventAction()

```
int32_t OH_Input_GetMouseEventAction(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标事件的动作。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 鼠标的动作。 |

### OH_Input_SetMouseEventDisplayX()

```
void OH_Input_SetMouseEventDisplayX(struct Input_MouseEvent* mouseEvent, int32_t displayX)
```

**描述**

设置鼠标事件的屏幕X坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int32_t displayX | 屏幕X坐标。 |

### OH_Input_GetMouseEventDisplayX()

```
int32_t OH_Input_GetMouseEventDisplayX(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标事件的屏幕X坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 屏幕X坐标。 |

### OH_Input_SetMouseEventDisplayY()

```
void OH_Input_SetMouseEventDisplayY(struct Input_MouseEvent* mouseEvent, int32_t displayY)
```

**描述**

设置鼠标事件的屏幕Y坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int32_t displayY | 屏幕Y坐标。 |

### OH_Input_GetMouseEventDisplayY()

```
int32_t OH_Input_GetMouseEventDisplayY(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标事件的屏幕Y坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 屏幕Y坐标。 |

### OH_Input_SetMouseEventButton()

```
void OH_Input_SetMouseEventButton(struct Input_MouseEvent* mouseEvent, int32_t button)
```

**描述**

设置鼠标事件的按键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int32_t button | 鼠标按键。相关取值可参考[Input_MouseEventButton](#input_mouseeventbutton)。 |

### OH_Input_GetMouseEventButton()

```
int32_t OH_Input_GetMouseEventButton(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标事件的按键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 鼠标按键。相关取值可参考[Input_MouseEventButton](#input_mouseeventbutton)。 |

### OH_Input_SetMouseEventAxisType()

```
void OH_Input_SetMouseEventAxisType(struct Input_MouseEvent* mouseEvent, int32_t axisType)
```

**描述**

设置鼠标轴事件的类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int32_t axisType | 轴类型，比如垂直轴、水平轴。相关取值可参考[InputEvent_MouseAxis](#inputevent_mouseaxis)。 |

### OH_Input_GetMouseEventAxisType()

```
int32_t OH_Input_GetMouseEventAxisType(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标轴事件的类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 轴类型。相关取值可参考[InputEvent_MouseAxis](#inputevent_mouseaxis)。 |

### OH_Input_SetMouseEventAxisValue()

```
void OH_Input_SetMouseEventAxisValue(struct Input_MouseEvent* mouseEvent, float axisValue)
```

**描述**

设置鼠标轴事件的值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| float axisValue | 轴事件的值，正数向前滚动（例如，1.0表示向前滚动一个单位），负数向后滚动（例如，-1.0表示向后滚动一个单位）,零表示没有滚动。 |

### OH_Input_GetMouseEventAxisValue()

```
float OH_Input_GetMouseEventAxisValue(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标轴事件的值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| float | 轴事件的值。 |

### OH_Input_SetMouseEventActionTime()

```
void OH_Input_SetMouseEventActionTime(struct Input_MouseEvent* mouseEvent, int64_t actionTime)
```

**描述**

设置鼠标事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int64_t actionTime | 鼠标事件发生的时间，表示从1970.1.1 00:00:00 GMT逝去的微秒数。 |

### OH_Input_GetMouseEventActionTime()

```
int64_t OH_Input_GetMouseEventActionTime(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回鼠标事件发生的时间。 |

### OH_Input_SetMouseEventWindowId()

```
void OH_Input_SetMouseEventWindowId(struct Input_MouseEvent* mouseEvent, int32_t windowId)
```

**描述**

设置鼠标事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int32_t windowId | 鼠标事件的窗口Id。 |

### OH_Input_GetMouseEventWindowId()

```
int32_t OH_Input_GetMouseEventWindowId(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 鼠标事件的窗口Id。 |

### OH_Input_SetMouseEventDisplayId()

```
void OH_Input_SetMouseEventDisplayId(struct Input_MouseEvent* mouseEvent, int32_t displayId)
```

**描述**

设置鼠标事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 |
| int32_t displayId | 鼠标事件的屏幕Id。 |

### OH_Input_CreateTouchEvent()

```
struct Input_TouchEvent* OH_Input_CreateTouchEvent()
```

**描述**

创建触屏事件对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| struct | 如果操作成功返回一个[Input_TouchEvent](capi-input-input-touchevent.md)指针对象，否则返回空指针。 |

### OH_Input_DestroyTouchEvent()

```
void OH_Input_DestroyTouchEvent(struct Input_TouchEvent** touchEvent)
```

**描述**

销毁触屏事件对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_TouchEvent](capi-input-input-touchevent.md)** touchEvent | 触屏事件对象。 |

### OH_Input_SetTouchEventAction()

```
void OH_Input_SetTouchEventAction(struct Input_TouchEvent* touchEvent, int32_t action)
```

**描述**

设置触屏事件的动作。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |
| int32_t action | 触屏的动作。相关取值可参考[Input_TouchEventAction](#input_toucheventaction)。 |

### OH_Input_GetTouchEventAction()

```
int32_t OH_Input_GetTouchEventAction(const struct Input_TouchEvent* touchEvent)
```

**描述**

获取触屏事件的动作。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 触屏的动作。相关取值可参考[Input_TouchEventAction](#input_toucheventaction)。 |

### OH_Input_SetTouchEventFingerId()

```
void OH_Input_SetTouchEventFingerId(struct Input_TouchEvent* touchEvent, int32_t id)
```

**描述**

设置触屏事件的手指ID。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |
| int32_t id | 触屏的手指ID。第一个手指碰到屏幕，id就是0，第二个手指碰到屏幕，id就是1，依次累加。 |

### OH_Input_GetTouchEventFingerId()

```
int32_t OH_Input_GetTouchEventFingerId(const struct Input_TouchEvent* touchEvent)
```

**描述**

获取触屏事件的手指ID。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 触屏的手指ID。第一个手指碰到屏幕，id就是0，第二个手指碰到屏幕，id就是1，依次累加。 |

### OH_Input_SetTouchEventDisplayX()

```
void OH_Input_SetTouchEventDisplayX(struct Input_TouchEvent* touchEvent, int32_t displayX)
```

**描述**

设置触屏事件的屏幕X坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |
| int32_t displayX | 触屏的屏幕X坐标。 |

### OH_Input_GetTouchEventDisplayX()

```
int32_t OH_Input_GetTouchEventDisplayX(const struct Input_TouchEvent* touchEvent)
```

**描述**

获取触屏事件的屏幕X坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 触屏的屏幕X坐标。 |

### OH_Input_SetTouchEventDisplayY()

```
void OH_Input_SetTouchEventDisplayY(struct Input_TouchEvent* touchEvent, int32_t displayY)
```

**描述**

设置触屏事件的屏幕Y坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |
| int32_t displayY | 触屏的屏幕Y坐标。 |

### OH_Input_GetTouchEventDisplayY()

```
int32_t OH_Input_GetTouchEventDisplayY(const struct Input_TouchEvent* touchEvent)
```

**描述**

获取触屏事件的屏幕Y坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 触屏的屏幕Y坐标。 |

### OH_Input_SetTouchEventActionTime()

```
void OH_Input_SetTouchEventActionTime(struct Input_TouchEvent* touchEvent, int64_t actionTime)
```

**描述**

设置触屏事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |
| int64_t actionTime | 触屏事件发生的时间，表示从1970.1.1 00:00:00 GMT逝去的微秒数。 |

### OH_Input_GetTouchEventActionTime()

```
int64_t OH_Input_GetTouchEventActionTime(const struct Input_TouchEvent* touchEvent)
```

**描述**

获取触屏事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int64_t | 返回触屏事件发生的时间。 |

### OH_Input_SetTouchEventWindowId()

```
void OH_Input_SetTouchEventWindowId(struct Input_TouchEvent* touchEvent, int32_t windowId)
```

**描述**

设置触屏事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |
| int32_t windowId | 触屏事件的窗口Id。 |

### OH_Input_GetTouchEventWindowId()

```
int32_t OH_Input_GetTouchEventWindowId(const struct Input_TouchEvent* touchEvent)
```

**描述**

获取触屏事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 触屏事件的窗口Id。 |

### OH_Input_SetTouchEventDisplayId()

```
void OH_Input_SetTouchEventDisplayId(struct Input_TouchEvent* touchEvent, int32_t displayId)
```

**描述**

设置触屏事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |
| int32_t displayId | 触屏事件的屏幕Id。 |

### OH_Input_GetTouchEventDisplayId()

```
int32_t OH_Input_GetTouchEventDisplayId(const struct Input_TouchEvent* touchEvent)
```

**描述**

获取触屏事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 触屏事件的屏幕Id。 |

### OH_Input_CancelInjection()

```
void OH_Input_CancelInjection()
```

**描述**

取消事件注入并撤销授权。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

### OH_Input_RequestInjection()

```
Input_Result OH_Input_RequestInjection(Input_InjectAuthorizeCallback callback)
```

**描述**

当前应用申请注入权限，包括申请注入按键事件[OH_Input_InjectKeyEvent](capi-oh-input-manager-h.md#oh_input_injectkeyevent)、注入触屏事件[OH_Input_InjectTouchEvent](capi-oh-input-manager-h.md#oh_input_injecttouchevent)、注入鼠标事件[OH_Input_InjectMouseEvent](capi-oh-input-manager-h.md#oh_input_injectmouseevent)等注入操作的权限。该接口仅在PC/2in1设备上生效。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_InjectAuthorizeCallback](capi-oh-input-manager-h.md#input_injectauthorizecallback) callback | 授权状态回调，具体请参考[Input_InjectAuthorizeCallback](capi-oh-input-manager-h.md#input_injectauthorizecallback)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](capi-oh-input-manager-h.md#input_result) | 返回结果码，参见[Input_Result](capi-oh-input-manager-h.md#input_result)。<br>      INPUT_SUCCESS = 0 申请授权成功，等待用户授权结果并回调授权状态。<br>      INPUT_PARAMETER_ERROR = 401  参数错误，参数callback为空。<br>      INPUT_DEVICE_NOT_SUPPORTED = 801  设备不支持。<br>      INPUT_SERVICE_EXCEPTION = 3800001  服务器错误。<br>      INPUT_INJECTION_AUTHORIZING =  3900005 正在授权中。<br>      INPUT_INJECTION_OPERATION_FREQUENT = 3900006 重复请求（当前应用连续申请授权弹窗成功，间隔时间不超过3秒）。<br>      INPUT_INJECTION_AUTHORIZED = 3900007 当前应用已经授权。<br>      INPUT_INJECTION_AUTHORIZED_OTHERS = 3900008   其它应用已经授权。 |

### OH_Input_QueryAuthorizedStatus()

```
Input_Result OH_Input_QueryAuthorizedStatus(Input_InjectionStatus* status)
```

**描述**

查询当前应用注入的权限状态。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_InjectionStatus](capi-oh-input-manager-h.md#input_injectionstatus)* status | 当前应用注入权限状态。参见[Input_InjectionStatus](capi-oh-input-manager-h.md#input_injectionstatus)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](capi-oh-input-manager-h.md#input_result) | 返回结果码，参见[Input_Result](capi-oh-input-manager-h.md#input_result)。<br>      INPUT_SUCCESS = 0 查询成功。<br>      INPUT_PARAMETER_ERROR = 401  参数错误，参数status为空。<br>      INPUT_SERVICE_EXCEPTION = 3800001  服务器错误。 |

### OH_Input_CreateAxisEvent()

```
Input_AxisEvent* OH_Input_CreateAxisEvent(void)
```

**描述**

创建轴事件对象实例。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| Input_AxisEvent* | 成功返回[Input_AxisEvent](capi-input-input-axisevent.md)对象实例，失败则返回null。 |

### OH_Input_DestroyAxisEvent()

```
Input_Result OH_Input_DestroyAxisEvent(Input_AxisEvent** axisEvent)
```

**描述**

销毁轴事件对象实例。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)** axisEvent | 轴事件对象实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若销毁成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL或者axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventAction()

```
Input_Result OH_Input_SetAxisEventAction(Input_AxisEvent* axisEvent, InputEvent_AxisAction action)
```

**描述**

设置轴事件的动作。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axisaction) action | 轴事件动作，具体请参考[InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axisaction)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件的动作成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventAction()

```
Input_Result OH_Input_GetAxisEventAction(const Input_AxisEvent* axisEvent, InputEvent_AxisAction *action)
```

**描述**

获取轴事件的动作。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axisaction) *action | action 出参，返回轴事件动作，具体请参考在[InputEvent_AxisAction](capi-oh-axis-type-h.md#inputevent_axisaction)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件的动作成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者action为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventDisplayX()

```
Input_Result OH_Input_SetAxisEventDisplayX(Input_AxisEvent* axisEvent, float displayX)
```

**描述**

设置轴事件的X坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| float displayX | 轴事件X坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件的X坐标成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventDisplayX()

```
Input_Result OH_Input_GetAxisEventDisplayX(const Input_AxisEvent* axisEvent, float* displayX)
```

**描述**

获取轴事件的X坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| float* displayX | 出参，返回轴事件X坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件的X坐标成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者displayX为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventDisplayY()

```
Input_Result OH_Input_SetAxisEventDisplayY(Input_AxisEvent* axisEvent, float displayY)
```

**描述**

设置轴事件的Y坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| float displayY | 轴事件Y坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件的Y坐标成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventDisplayY()

```
Input_Result OH_Input_GetAxisEventDisplayY(const Input_AxisEvent* axisEvent, float* displayY)
```

**描述**

获取轴事件的Y坐标。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| float* displayY | 出参，返回轴事件Y坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件的Y坐标成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者displayY为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventAxisValue()

```
Input_Result OH_Input_SetAxisEventAxisValue(Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double axisValue)
```

**描述**

设置轴事件指定轴类型的轴值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype) axisType | 轴类型，具体请参考[InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype)。 |
| double axisValue | 轴事件的值，正数向前滚动（例如，1.0表示向前滚动一个单位），负数向后滚动（例如，-1.0表示向后滚动一个单位）,零表示没有滚动。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件指定轴类型的轴值成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventAxisValue()

```
Input_Result OH_Input_GetAxisEventAxisValue(const Input_AxisEvent* axisEvent,InputEvent_AxisType axisType, double* axisValue)
```

**描述**

获取轴事件指定轴类型的轴值。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype) axisType | 轴类型，具体请参考[InputEvent_AxisType](capi-oh-axis-type-h.md#inputevent_axistype)。 |
| double* axisValue | 出参，返回轴事件的值，正数向前滚动（例如，1.0表示向前滚动一个单位），负数向后滚动（例如，-1.0表示向后滚动一个单位）,零表示没有滚动。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件指定轴类型的轴值成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者axisValue为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventActionTime()

```
Input_Result OH_Input_SetAxisEventActionTime(Input_AxisEvent* axisEvent, int64_t actionTime)
```

**描述**

设置轴事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| int64_t actionTime | 轴事件发生的时间，表示从1970.1.1 00:00:00 GMT逝去的微秒数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件发生的时间成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventActionTime()

```
Input_Result OH_Input_GetAxisEventActionTime(const Input_AxisEvent* axisEvent, int64_t* actionTime)
```

**描述**

获取轴事件发生的时间。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| int64_t* actionTime | 出参，返回轴事件发生的时间，表示从1970.1.1 00:00:00 GMT逝去的微秒数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件发生的时间成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者actionTime为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventType()

```
Input_Result OH_Input_SetAxisEventType(Input_AxisEvent* axisEvent, InputEvent_AxisEventType axisEventType)
```

**描述**

设置轴事件类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype) axisEventType | 轴事件类型，具体请参考[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件类型成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventType()

```
Input_Result OH_Input_GetAxisEventType(const Input_AxisEvent* axisEvent, InputEvent_AxisEventType* axisEventType)
```

**描述**

获取轴事件类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)* axisEventType | 出参，返回轴事件类型，具体请参考[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件类型成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者axisEventType为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventSourceType()

```
Input_Result OH_Input_SetAxisEventSourceType(Input_AxisEvent* axisEvent, InputEvent_SourceType sourceType)
```

**描述**

设置轴事件源类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_SourceType](#inputevent_sourcetype) sourceType | 轴事件源类型,具体请参考[InputEvent_SourceType](#inputevent_sourcetype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件源类型成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventSourceType()

```
Input_Result OH_Input_GetAxisEventSourceType(const Input_AxisEvent* axisEvent, InputEvent_SourceType* sourceType)
```

**描述**

获取轴事件源类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| [InputEvent_SourceType](#inputevent_sourcetype)* sourceType | 出参，返回轴事件源类型，具体请参考[InputEvent_SourceType](#inputevent_sourcetype)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件源类型成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者sourceType为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventWindowId()

```
Input_Result OH_Input_SetAxisEventWindowId(Input_AxisEvent* axisEvent, int32_t windowId)
```

**描述**

设置轴事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| int32_t windowId | 轴事件窗口Id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件的窗口Id成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventWindowId()

```
Input_Result OH_Input_GetAxisEventWindowId(const Input_AxisEvent* axisEvent, int32_t* windowId)
```

**描述**

获取轴事件的窗口Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| int32_t* windowId | 出参，返回轴事件窗口Id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件的窗口Id成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者windowId为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetAxisEventDisplayId()

```
Input_Result OH_Input_SetAxisEventDisplayId(Input_AxisEvent* axisEvent, int32_t displayId)
```

**描述**

设置轴事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| int32_t displayId | 轴事件屏幕Id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若设置轴事件的屏幕Id成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_GetAxisEventDisplayId()

```
Input_Result OH_Input_GetAxisEventDisplayId(const Input_AxisEvent* axisEvent, int32_t* displayId)
```

**描述**

获取轴事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_AxisEvent](capi-input-input-axisevent.md)* axisEvent | 轴事件对象，通过[OH_Input_CreateAxisEvent](#oh_input_createaxisevent)接口可以创建轴事件对象。<br>使用完需使用[OH_Input_DestroyAxisEvent](#oh_input_destroyaxisevent)接口销毁轴事件对象。 |
| int32_t* displayId | 出参，返回轴事件屏幕Id。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若获取轴事件的屏幕Id成功，则返回[INPUT_SUCCESS](#input_result)；若axisEvent或者displayId为NULL，则返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_AddKeyEventMonitor()

```
Input_Result OH_Input_AddKeyEventMonitor(Input_KeyEventCallback callback)
```

**描述**

添加按键事件监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_KeyEventCallback](#input_keyeventcallback) callback | 回调函数，用于接收按键事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若添加按键事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_AddMouseEventMonitor()

```
Input_Result OH_Input_AddMouseEventMonitor(Input_MouseEventCallback callback)
```

**描述**

添加鼠标事件监听,包含鼠标点击，移动，不包含滚轮事件，滚轮事件归属于轴事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_MouseEventCallback](#input_mouseeventcallback) callback | 回调函数，用于接收鼠标事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若添加鼠标事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_AddTouchEventMonitor()

```
Input_Result OH_Input_AddTouchEventMonitor(Input_TouchEventCallback callback)
```

**描述**

添加触屏事件监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_TouchEventCallback](#input_toucheventcallback) callback | 回调函数，用于接收触屏事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若添加触屏事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_AddAxisEventMonitorForAll()

```
Input_Result OH_Input_AddAxisEventMonitorForAll(Input_AxisEventCallback callback)
```

**描述**

添加所有类型轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEventCallback](#input_axiseventcallback) callback | 回调函数，用于接收轴事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若添加轴事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_AddAxisEventMonitor()

```
Input_Result OH_Input_AddAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)
```

**描述**

添加指定类型的轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype) axisEventType | 要监听的轴事件类型，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。 |
| [Input_AxisEventCallback](#input_axiseventcallback) callback | 回调函数，用于接收指定类型的轴事件 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若添加轴事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_RemoveKeyEventMonitor()

```
Input_Result OH_Input_RemoveKeyEventMonitor(Input_KeyEventCallback callback)
```

**描述**

移除按键事件监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_KeyEventCallback](#input_keyeventcallback) callback | 指定要被移除的用于按键事件监听的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若移除按键事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空或者没有被添加监听，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_RemoveMouseEventMonitor()

```
Input_Result OH_Input_RemoveMouseEventMonitor(Input_MouseEventCallback callback)
```

**描述**

移除鼠标事件监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_MouseEventCallback](#input_mouseeventcallback) callback | 指定要被移除的用于鼠标事件监听的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若移除鼠标事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空或者没有被添加监听，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_RemoveTouchEventMonitor()

```
Input_Result OH_Input_RemoveTouchEventMonitor(Input_TouchEventCallback callback)
```

**描述**

移除触屏事件监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_TouchEventCallback](#input_toucheventcallback) callback | 指定要被移除的用于触屏事件监听的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若移除触屏事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空或者没有被添加监听，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_RemoveAxisEventMonitorForAll()

```
Input_Result OH_Input_RemoveAxisEventMonitorForAll(Input_AxisEventCallback callback)
```

**描述**

移除所有类型轴事件监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_AxisEventCallback](#input_axiseventcallback) callback | 指定要被移除的用于所有类型轴事件监听的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若移除轴事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空或者没有被添加监听，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_RemoveAxisEventMonitor()

```
Input_Result OH_Input_RemoveAxisEventMonitor(InputEvent_AxisEventType axisEventType, Input_AxisEventCallback callback)
```

**描述**

移除指定类型轴事件监听，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INPUT_MONITORING

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype) axisEventType | 指定要移除监听的轴事件类型，轴事件类型定义在[InputEvent_AxisEventType](capi-oh-axis-type-h.md#inputevent_axiseventtype)中。 |
| [Input_AxisEventCallback](#input_axiseventcallback) callback | 指定要被移除的用于指定类型轴事件监听的回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若移除轴事件监听成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空或者没有被添加监听，则返回[INPUT_PARAMETER_ERROR](#input_result)；若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_AddKeyEventInterceptor()

```
Input_Result OH_Input_AddKeyEventInterceptor(Input_KeyEventCallback callback, Input_InterceptorOptions *option)
```

**描述**

添加按键事件的拦截，重复添加只有第一次生效。仅在应用获焦时拦截按键事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INTERCEPT_INPUT_EVENT

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_KeyEventCallback](#input_keyeventcallback) callback | 回调函数，用于接收按键事件。 |
| [Input_InterceptorOptions](capi-input-input-interceptoroptions.md) *option | option 输入事件拦截的可选项，传null则使用默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若添加按键事件的拦截成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空，则返回[INPUT_PARAMETER_ERROR](#input_result)；若重复添加拦截器，则返回[INPUT_REPEAT_INTERCEPTOR](#input_result)；<br>         若服务异常；则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_AddInputEventInterceptor()

```
Input_Result OH_Input_AddInputEventInterceptor(Input_InterceptorEventCallback *callback,Input_InterceptorOptions *option)
```

**描述**

添加输入事件拦截，包括鼠标、触屏和轴事件，重复添加只有第一次生效。仅命中应用窗口时拦截输入事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INTERCEPT_INPUT_EVENT

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_InterceptorEventCallback](capi-input-input-interceptoreventcallback.md) *callback | callback 用于回调输入事件的结构体指针，请参考定义[Input_InterceptorEventCallback](capi-input-input-interceptoreventcallback.md)。 |
| [Input_InterceptorOptions](capi-input-input-interceptoroptions.md) *option | option 输入事件拦截的可选项，传null则使用默认值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若添加输入事件的拦截成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若callback为空，则返回[INPUT_PARAMETER_ERROR](#input_result)；若重复添加拦截器，则返回[INPUT_REPEAT_INTERCEPTOR](#input_result)；<br>         若服务异常；则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_RemoveKeyEventInterceptor()

```
Input_Result OH_Input_RemoveKeyEventInterceptor(void)
```

**描述**

移除按键事件拦截。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INTERCEPT_INPUT_EVENT

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若移除按键事件拦截成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_RemoveInputEventInterceptor()

```
Input_Result OH_Input_RemoveInputEventInterceptor(void)
```

**描述**

移除输入事件拦截，包括鼠标、触屏和轴事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**需要权限：** ohos.permission.INTERCEPT_INPUT_EVENT

**起始版本：** 12

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | 若移除输入事件拦截成功，则返回[INPUT_SUCCESS](#input_result)；若权限校验失败，则返回[INPUT_PERMISSION_DENIED](#input_result)；<br>         若服务异常，则返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_GetIntervalSinceLastInput()

```
Input_Result OH_Input_GetIntervalSinceLastInput(int64_t *timeInterval)
```

**描述**

获取距离上次系统输入事件的时间间隔。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int64_t *timeInterval | timeInterval 时间间隔，单位为微秒。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_GetIntervalSinceLastInput 函数错误码。<br>         若获取时间间隔成功，则返回[INPUT_SUCCESS](#input_result)；若获取失败，返回[INPUT_SERVICE_EXCEPTION](#input_result)。 |

### OH_Input_CreateHotkey()

```
Input_Hotkey *OH_Input_CreateHotkey(void)
```

**描述**

创建快捷键对象的实例。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md) | 如果操作成功,则返回一个[Input_Hotkey](capi-input-input-hotkey.md)指针对象。否则, 返回一个空指针， 可能的原因是内存分配失败。 |

### OH_Input_DestroyHotkey()

```
void OH_Input_DestroyHotkey(Input_Hotkey **hotkey)
```

**描述**

销毁快捷键对象的实例。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md) **hotkey | hotkey 快捷键对象的实例。 |

### OH_Input_SetPreKeys()

```
void OH_Input_SetPreKeys(Input_Hotkey *hotkey, int32_t *preKeys, int32_t size)
```

**描述**

设置修饰键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md) *hotkey | hotkey 快捷键对象的实例。 |
| int32_t *preKeys | preKeys 修饰键列表。 |
| int32_t size | 修饰键个数， 取值范围1~2个。 |

### OH_Input_GetPreKeys()

```
Input_Result OH_Input_GetPreKeys(const Input_Hotkey *hotkey, int32_t **preKeys, int32_t *preKeyCount)
```

**描述**

获取修饰键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_Hotkey](capi-input-input-hotkey.md) *hotkey | hotkey 快捷键对象的实例。 |
| int32_t **preKeys | preKeys 返回修饰键列表。 |
| int32_t *preKeyCount | preKeyCount 返回修饰键个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_GetpressedKeys 函数错误码。<br>         若获取成功，返回[INPUT_SUCCESS](#input_result)；若获取失败，返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetFinalKey()

```
void OH_Input_SetFinalKey(Input_Hotkey* hotkey, int32_t finalKey)
```

**描述**

设置被修饰键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md)* hotkey | 快捷键对象的实例。 |
| int32_t finalKey | 被修饰键值，被修饰键值只能是1个。 |

### OH_Input_GetFinalKey()

```
Input_Result OH_Input_GetFinalKey(const Input_Hotkey* hotkey, int32_t *finalKeyCode)
```

**描述**

获取被修饰键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_Hotkey](capi-input-input-hotkey.md)* hotkey | 快捷键对象的实例。 |
| int32_t *finalKeyCode | finalKeyCode 返回被修饰键键值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_GetfinalKey 函数错误码。<br>         若获取成功，返回[INPUT_SUCCESS](#input_result)；<br>         若获取失败，返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_CreateAllSystemHotkeys()

```
Input_Hotkey **OH_Input_CreateAllSystemHotkeys(int32_t count)
```

**描述**

创建[Input_Hotkey](capi-input-input-hotkey.md)类型实例的数组。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t count | 创建[Input_Hotkey](capi-input-input-hotkey.md)实例的数量。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md) | OH_Input_CreateAllSystemHotkey 函数错误码。<br>         [INPUT_SUCCESS](#input_result) 创建实例数组的双指针成功。 |

### OH_Input_DestroyAllSystemHotkeys()

```
void OH_Input_DestroyAllSystemHotkeys(Input_Hotkey **hotkeys, int32_t count)
```

**描述**

销毁[Input_Hotkey](capi-input-input-hotkey.md)实例数组并回收内存。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md) **hotkeys | hotkeys 指向[Input_Hotkey](capi-input-input-hotkey.md)实例数组的双指针。 |
| int32_t count | 销毁[Input_Hotkey](capi-input-input-hotkey.md)实例的数量。 |

### OH_Input_GetAllSystemHotkeys()

```
Input_Result OH_Input_GetAllSystemHotkeys(Input_Hotkey **hotkey, int32_t *count)
```

**描述**

获取设置的所有快捷键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md) **hotkey | hotkey 返回[Input_Hotkey](capi-input-input-hotkey.md) 类型实例数组。首次调用可传入NULL，可获取数组长度。 |
| int32_t *count | count 返回支持快捷键的个数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_GetAllSystemHotkeys 函数错误码。<br>         若获取成功，返回[INPUT_SUCCESS](#input_result)；<br>         若获取失败，返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_SetRepeat()

```
void OH_Input_SetRepeat(Input_Hotkey* hotkey, bool isRepeat)
```

**描述**

设置是否上报重复key事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_Hotkey](capi-input-input-hotkey.md)* hotkey | 快捷键对象的实例。 |
| bool isRepeat | 是否上报重复key事件。true表示上报，false表示不上报。 |

### OH_Input_GetRepeat()

```
Input_Result OH_Input_GetRepeat(const Input_Hotkey* hotkey, bool *isRepeat)
```

**描述**

获取是否上报重复key事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_Hotkey](capi-input-input-hotkey.md)* hotkey | 快捷键对象的实例。 |
| bool *isRepeat | isRepeat 返回Key事件是否重复。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_GetIsRepeat 函数错误码。<br>         若获取成功，返回[INPUT_SUCCESS](#input_result)；<br>         若获取失败，返回[INPUT_PARAMETER_ERROR](#input_result)。 |

### OH_Input_AddHotkeyMonitor()

```
Input_Result OH_Input_AddHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)
```

**描述**

订阅快捷键事件。此接口在智能穿戴、轻量级智能穿戴设备不生效。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_Hotkey](capi-input-input-hotkey.md)* hotkey | 指定要订阅的快捷键对象。 |
| [Input_HotkeyCallback](#input_hotkeycallback) callback | 回调函数，用于回调快捷键事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_AddHotkeyMonitor 函数错误码。<br>         [INPUT_SUCCESS](#input_result) 表示订阅组合按键成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 参数检查失败。<br>         [INPUT_OCCUPIED_BY_SYSTEM](#input_result) 该快捷键已被系统占用，可以通过接口[OH_Input_GetAllSystemHotkeys](#oh_input_getallsystemhotkeys)查询所有的系统快捷键。<br>         [INPUT_OCCUPIED_BY_OTHER](#input_result) 已被抢占订阅。<br>         [INPUT_DEVICE_NOT_SUPPORTED](#input_result) 表示功能不受支持。 |

### OH_Input_RemoveHotkeyMonitor()

```
Input_Result OH_Input_RemoveHotkeyMonitor(const Input_Hotkey* hotkey, Input_HotkeyCallback callback)
```

**描述**

取消订阅快捷键。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const [Input_Hotkey](capi-input-input-hotkey.md)* hotkey | 指定要取消订阅的快捷键对象。 |
| [Input_HotkeyCallback](#input_hotkeycallback) callback | 回调函数，用于回调快捷键事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_RemoveHotkeyMonitor 函数错误码。<br>         [INPUT_SUCCESS](#input_result) 取消订阅组合按键成功， [INPUT_PARAMETER_ERROR](#input_result) 参数检查失败。 |

### OH_Input_RegisterDeviceListener()

```
Input_Result OH_Input_RegisterDeviceListener(Input_DeviceListener* listener)
```

**描述**

注册设备热插拔的监听器。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceListener](capi-input-input-devicelistener.md)* listener | 指向设备热插拔监听器[Input_DeviceListener](capi-input-input-devicelistener.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_RegisterDeviceListener 的返回值。<br>         [INPUT_SUCCESS](#input_result) 表示注册成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示listener 为NULL。 |

### OH_Input_UnregisterDeviceListener()

```
Input_Result OH_Input_UnregisterDeviceListener(Input_DeviceListener* listener)
```

**描述**

取消注册设备热插拔的监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceListener](capi-input-input-devicelistener.md)* listener | 指向设备热插拔监听器[Input_DeviceListener](capi-input-input-devicelistener.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_UnregisterDeviceListener 的返回值。<br>         [INPUT_SUCCESS](#input_result) 表示取消注册成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示listener 为 NULL 或者 listener 未被注册。<br>         [INPUT_SERVICE_EXCEPTION](#input_result) 表示由于服务异常调用失败。 |

### OH_Input_UnregisterDeviceListeners()

```
Input_Result OH_Input_UnregisterDeviceListeners()
```

**描述**

取消注册所有的设备热插拔的监听。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_UnregisterDeviceListener 的返回值。<br>         [INPUT_SUCCESS](#input_result) 表示调用成功。<br>         [INPUT_SERVICE_EXCEPTION](#input_result) 表示由于服务异常调用失败。 |

### OH_Input_GetDeviceIds()

```
Input_Result OH_Input_GetDeviceIds(int32_t *deviceIds, int32_t inSize, int32_t *outSize)
```

**描述**

获取所有输入设备的ID列表。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t *deviceIds | deviceIds 保存输入设备ID的列表。 |
| int32_t inSize | 保存输入设备ID列表的大小。 |
| int32_t *outSize | outSize 输出输入设备ID列表的长度，值小于等于inSize长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceIds或outSize为空指针或inSize小于0。 |

### OH_Input_GetDevice()

```
Input_Result OH_Input_GetDevice(int32_t deviceId, Input_DeviceInfo **deviceInfo)
```

**描述**

获取输入设备信息。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备ID。 |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) **deviceInfo | deviceInfo 指向输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo为空指针或deviceId无效。<br> 可以通过 [OH_Input_GetDeviceIds](#oh_input_getdeviceids) 表示接口查询系统支持的设备ID。 |

### OH_Input_CreateDeviceInfo()

```
Input_DeviceInfo* OH_Input_CreateDeviceInfo(void)
```

**描述**

创建输入设备信息的对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13

**返回：**

| 类型 | 说明 |
| -- | -- |
| Input_DeviceInfo* | 如果操作成功，返回设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)实例的指针。否则返回空指针，可能的原因是分配内存失败。 |

### OH_Input_DestroyDeviceInfo()

```
void OH_Input_DestroyDeviceInfo(Input_DeviceInfo **deviceInfo)
```

**描述**

销毁输入设备信息的对象。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) **deviceInfo | deviceInfo 设备信息的对象。 |

### OH_Input_GetKeyboardType()

```
Input_Result OH_Input_GetKeyboardType(int32_t deviceId, int32_t *keyboardType)
```

**描述**

获取输入设备的键盘类型。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t deviceId | 设备ID。 |
| int32_t *keyboardType | keyboardType 指向输入设备的键盘指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示设备ID为无效值或者keyboardType是空指针。 |

### OH_Input_GetDeviceId()

```
Input_Result OH_Input_GetDeviceId(Input_DeviceInfo *deviceInfo, int32_t *id)
```

**描述**

获取输入设备的id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) *deviceInfo | deviceInfo 输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)。 |
| int32_t *id | id 指向输入设备ID的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo或者id是空指针。 |

### OH_Input_GetDeviceName()

```
Input_Result OH_Input_GetDeviceName(Input_DeviceInfo *deviceInfo, char **name)
```

**描述**

获取输入设备的名称。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) *deviceInfo | deviceInfo 输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)。 |
| char **name | name 指向输入设备名称的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo或者name是空指针。 |

### OH_Input_GetCapabilities()

```
Input_Result OH_Input_GetCapabilities(Input_DeviceInfo *deviceInfo, int32_t *capabilities)
```

**描述**

获取有关输入设备能力信息，比如设备是触摸屏、触控板、键盘等。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) *deviceInfo | deviceInfo 输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)。 |
| int32_t *capabilities | capabilities 指向输入设备能力信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo或者capabilities是空指针。 |

### OH_Input_GetDeviceVersion()

```
Input_Result OH_Input_GetDeviceVersion(Input_DeviceInfo *deviceInfo, int32_t *version)
```

**描述**

获取输入设备的版本信息。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) *deviceInfo | deviceInfo 输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)。 |
| int32_t *version | version 指向输入设备版本信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo或者version是空指针。 |

### OH_Input_GetDeviceProduct()

```
Input_Result OH_Input_GetDeviceProduct(Input_DeviceInfo *deviceInfo, int32_t *product)
```

**描述**

获取输入设备的产品信息。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) *deviceInfo | deviceInfo 输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)。 |
| int32_t *product | product 指向输入设备产品信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo或者product是空指针。 |

### OH_Input_GetDeviceVendor()

```
Input_Result OH_Input_GetDeviceVendor(Input_DeviceInfo *deviceInfo, int32_t *vendor)
```

**描述**

获取输入设备的厂商信息。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) *deviceInfo | deviceInfo 输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)。 |
| int32_t *vendor | vendor 指向输入设备厂商信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo或者vendor是空指针。 |

### OH_Input_GetDeviceAddress()

```
Input_Result OH_Input_GetDeviceAddress(Input_DeviceInfo *deviceInfo, char **address)
```

**描述**

获取输入设备的物理地址。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [Input_DeviceInfo](capi-input-input-deviceinfo.md) *deviceInfo | deviceInfo 输入设备信息[Input_DeviceInfo](capi-input-input-deviceinfo.md)。 |
| char **address | address 指向输入设备物理地址的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | [INPUT_SUCCESS](#input_result) 表示操作成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示deviceInfo或者address是空指针。 |

### OH_Input_GetFunctionKeyState()

```
Input_Result OH_Input_GetFunctionKeyState(int32_t keyCode, int32_t *state)
```

**描述**

获取功能键状态。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t keyCode | 功能键值。支持的功能键包含CapsLock键。 |
| int32_t *state | state 功能键状态。0表示功能键关闭，1表示功能键打开。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Input_Result](#input_result) | OH_Input_GetFunctionKeyState的执行结果。<br>         [INPUT_SUCCESS](#input_result) 表示获取状态成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示参数错误。<br>         {@link INPUT_DEVICE_NOT_EXIST } 表示键盘设备不存在。 |

### OH_Input_InjectTouchEvent()

```
int32_t OH_Input_InjectTouchEvent(const struct Input_TouchEvent* touchEvent)
```

**描述**

注入触屏事件。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_TouchEvent](capi-input-input-touchevent.md)* touchEvent | 触屏事件对象，通过[OH_Input_CreateTouchEvent](#oh_input_createtouchevent)接口可以创建触屏事件对象。<br>使用完需使用[OH_Input_DestroyTouchEvent](#oh_input_destroytouchevent)接口销毁触屏事件对象。 | 

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | OH_Input_InjectTouchEvent的执行结果。<br>         [INPUT_SUCCESS](#input_result) 表示注入成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示参数错误。<br>         [INPUT_PERMISSION_DENIED](#input_result) 表示缺少权限。 |

### OH_Input_InjectMouseEvent()

```
int32_t OH_Input_InjectMouseEvent(const struct Input_MouseEvent* mouseEvent)
```

**描述**

注入鼠标事件。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent |  鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 | 

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | OH_Input_InjectTouchEvent的执行结果。<br>         [INPUT_SUCCESS](#input_result) 表示注入成功。<br>         [INPUT_PARAMETER_ERROR](#input_result) 表示参数错误。<br>         [INPUT_PERMISSION_DENIED](#input_result) 表示缺少权限。 |

### OH_Input_GetMouseEventDisplayId()

```
int32_t OH_Input_GetMouseEventDisplayId(const struct Input_MouseEvent* mouseEvent)
```

**描述**

获取鼠标事件的屏幕Id。

**系统能力：** SystemCapability.MultimodalInput.Input.Core

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const struct [Input_MouseEvent](capi-input-input-mouseevent.md)* mouseEvent | 鼠标事件对象，通过[OH_Input_CreateMouseEvent](#oh_input_createmouseevent)接口可以创建鼠标事件对象。<br>使用完需使用[OH_Input_DestroyMouseEvent](#oh_input_destroymouseevent)接口销毁鼠标事件对象。 | 

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 若获取鼠标事件的屏幕Id成功，则返回鼠标事件的屏幕Id；若mouseEvent为NULL，则返回-1。 |
