# oh_window_event_filter.h


## 概述

定义窗口管理按键事件过滤的接口，当多模输入的事件经过窗口时，可以通过过滤接口拦截事件不让事件往下分发。

**系统能力：** SystemCapability.Window.SessionManager

**引用文件：**&lt;window_manager/oh_window_event_filter.h&gt;

**库：** libnative_window_manager.so

**起始版本：** 12

**相关模块：**[WindowManager](_window_manager___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef bool(\* [OH_NativeWindowManager_KeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | 定义多模按键的过滤函数。 | 
| typedef bool(\* [OH_NativeWindowManager_MouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_mouseeventfilter)) (Input_MouseEvent \*mouseEvent) | 定义多模鼠标事件的过滤函数。 | 
| typedef bool(\* [OH_NativeWindowManager_TouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_toucheventfilter)) (Input_TouchEvent \*touchEvent) | 定义多模触摸事件的过滤函数。 | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterKeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | 注册按键事件的过滤函数。 | 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterKeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | 取消注册窗口的按键事件过滤函数。 | 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_RegisterMouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_registermouseeventfilter) (int32_t windowId, [OH_NativeWindowManager_MouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_mouseeventfilter) mouseEventFilter) | 注册鼠标事件的过滤函数。 | 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_UnregisterMouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_unregistermouseeventfilter) (int32_t windowId) | 取消注册窗口的鼠标事件过滤函数。 | 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_RegisterTouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_registertoucheventfilter) (int32_t windowId, [OH_NativeWindowManager_TouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_toucheventfilter) touchEventFilter) | 注册触摸事件的过滤函数。 | 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_UnregisterTouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_unregistertoucheventfilter) (int32_t windowId) | 取消注册窗口的触摸事件过滤函数。 | 