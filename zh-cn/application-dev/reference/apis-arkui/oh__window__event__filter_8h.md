# oh_window_event_filter.h


## 概述

定义窗口管理按键事件过滤的接口，当多模输入的事件经过窗口时，可以通过过滤接口拦截事件不让事件往下分发。

**系统能力：** SystemCapability.Window.SessionManager

**引用文件：**&lt;window_manager/oh_window_event_filter.h&gt;

**库：** libnative_window_manager.so

**起始版本：** 12

**相关模块：**[WindowManager_NativeModule](_window_manager___native_module.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef bool(\* [OH_NativeWindowManager_KeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | 定义多模按键的过滤函数。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterKeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | 注册按键事件的过滤函数。 | 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterKeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | 取消注册窗口的按键事件过滤函数。 | 
