# oh_window.h


## 概述

定义窗口管理的相关接口，主要用于设置和获取指定窗口的属性，以及设置指定窗口的状态栏样式、导航栏样式。

引用文件：&lt;window_manager/oh_window.h&gt;

**系统能力：** SystemCapability.Window.SessionManager

**库：** libnative_window_manager.so

**起始版本：** 15

**相关模块：**[WindowManager_NativeModule](_window_manager___native_module.md)


## 汇总


### 函数

| 名称 | 描述 |
| -------- | -------- |
| int32_t [OH_WindowManager_SetWindowStatusBarEnabled](_window_manager___native_module.md#oh_windowmanager_setwindowstatusbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | 设置指定窗口是否显示状态栏。 |
| int32_t [OH_WindowManager_SetWindowStatusBarColor](_window_manager___native_module.md#oh_windowmanager_setwindowstatusbarcolor) (int32_t windowId, int32_t color) | 设置指定窗口的状态栏内容颜色。 |
| int32_t [OH_WindowManager_SetWindowNavigationBarEnabled](_window_manager___native_module.md#oh_windowmanager_setwindownavigationbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | 设置指定窗口是否显示导航栏。 |
| int32_t [OH_WindowManager_GetWindowAvoidArea](_window_manager___native_module.md#oh_windowmanager_getwindowavoidarea) (int32_t windowId, [WindowManager_AvoidAreaType](_window_manager___native_module.md#windowmanager_avoidareatype) type, [WindowManager_AvoidArea](_window_manager___avoid_area.md) \*avoidArea) | 获取指定窗口的避让区域。 |
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_WindowManager_IsWindowShown](_window_manager___native_module.md#oh_windowmanager_iswindowshown) (int32_t windowId, bool \*isShow) | 判断指定窗口是否显示。 |
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_WindowManager_ShowWindow](_window_manager___native_module.md#oh_windowmanager_showwindow) (int32_t windowId) | 显示指定窗口。 |
| int32_t [OH_WindowManager_SetWindowTouchable](_window_manager___native_module.md#oh_windowmanager_setwindowtouchable) (int32_t windowId, bool isTouchable) | 设置指定窗口是否可触。 |
| int32_t [OH_WindowManager_SetWindowFocusable](_window_manager___native_module.md#oh_windowmanager_setwindowfocusable) (int32_t windowId, bool isFocusable) | 设置指定窗口是否可获焦。 |
| int32_t [OH_WindowManager_SetWindowBackgroundColor](_window_manager___native_module.md#oh_windowmanager_setwindowbackgroundcolor) (int32_t windowId, const char \*color) | 设置指定窗口背景颜色。 |
| int32_t [OH_WindowManager_SetWindowBrightness](_window_manager___native_module.md#oh_windowmanager_setwindowbrightness) (int32_t windowId, float brightness) | 设置指定窗口的屏幕亮度。 |
| int32_t [OH_WindowManager_SetWindowKeepScreenOn](_window_manager___native_module.md#oh_windowmanager_setwindowkeepscreenon) (int32_t windowId, bool isKeepScreenOn) | 设置指定窗口是否开启屏幕常亮。 |
| int32_t [OH_WindowManager_SetWindowPrivacyMode](_window_manager___native_module.md#oh_windowmanager_setwindowprivacymode) (int32_t windowId, bool isPrivacy) | 设置指定窗口是否开启隐私模式。 |
| int32_t [OH_WindowManager_GetWindowProperties](_window_manager___native_module.md#oh_windowmanager_getwindowproperties) (int32_t windowId, [WindowManager_WindowProperties](_window_manager___window_properties.md) \*windowProperties) | 获取指定窗口属性。 |
| int32_t [OH_WindowManager_Snapshot](_window_manager___native_module.md#oh_windowmanager_snapshot) (int32_t windowId, OH_PixelmapNative \*pixelMap) | 获取指定窗口截图。 |
