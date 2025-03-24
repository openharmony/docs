# oh_window.h


## Overview

The **oh_window.h** file declares the window management APIs. You can use the APIs to set and obtain the properties of a window, and set its status bar style and navigation bar style.

**File to include**: &lt;window_manager/oh_window.h&gt;

**System capability**: SystemCapability.Window.SessionManager

**Library**: libnative_window_manager.so

**Since**: 15

**Related module**: [WindowManager_NativeModule](_window_manager___native_module.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| int32_t [OH_WindowManager_SetWindowStatusBarEnabled](_window_manager___native_module.md#oh_windowmanager_setwindowstatusbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | Sets whether to display the status bar in a window.|
| int32_t [OH_WindowManager_SetWindowStatusBarColor](_window_manager___native_module.md#oh_windowmanager_setwindowstatusbarcolor) (int32_t windowId, int32_t color) | Sets the color of the status bar in a window.|
| int32_t [OH_WindowManager_SetWindowNavigationBarEnabled](_window_manager___native_module.md#oh_windowmanager_setwindownavigationbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | Sets whether to display the navigation bar in a window.|
| int32_t [OH_WindowManager_GetWindowAvoidArea](_window_manager___native_module.md#oh_windowmanager_getwindowavoidarea) (int32_t windowId, [WindowManager_AvoidAreaType](_window_manager___native_module.md#windowmanager_avoidareatype) type, [WindowManager_AvoidArea](_window_manager___avoid_area.md) \*avoidArea) | Obtains the avoid area of a window.|
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_WindowManager_IsWindowShown](_window_manager___native_module.md#oh_windowmanager_iswindowshown) (int32_t windowId, bool \*isShow) | Checks whether a window is displayed.|
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_WindowManager_ShowWindow](_window_manager___native_module.md#oh_windowmanager_showwindow) (int32_t windowId) | Displays a window.|
| int32_t [OH_WindowManager_SetWindowTouchable](_window_manager___native_module.md#oh_windowmanager_setwindowtouchable) (int32_t windowId, bool isTouchable) | Sets whether a window is touchable.|
| int32_t [OH_WindowManager_SetWindowFocusable](_window_manager___native_module.md#oh_windowmanager_setwindowfocusable) (int32_t windowId, bool isFocusable) | Sets whether a window is focusable.|
| int32_t [OH_WindowManager_SetWindowBackgroundColor](_window_manager___native_module.md#oh_windowmanager_setwindowbackgroundcolor) (int32_t windowId, const char \*color) | Sets the background color of a window.|
| int32_t [OH_WindowManager_SetWindowBrightness](_window_manager___native_module.md#oh_windowmanager_setwindowbrightness) (int32_t windowId, float brightness) | Sets the screen brightness of a window.|
| int32_t [OH_WindowManager_SetWindowKeepScreenOn](_window_manager___native_module.md#oh_windowmanager_setwindowkeepscreenon) (int32_t windowId, bool isKeepScreenOn) | Sets whether to always keep the screen on for a window.|
| int32_t [OH_WindowManager_SetWindowPrivacyMode](_window_manager___native_module.md#oh_windowmanager_setwindowprivacymode) (int32_t windowId, bool isPrivacy) | Sets whether to enable privacy mode for a window. |
| int32_t [OH_WindowManager_GetWindowProperties](_window_manager___native_module.md#oh_windowmanager_getwindowproperties) (int32_t windowId, [WindowManager_WindowProperties](_window_manager___window_properties.md) \*windowProperties) | Obtains the properties of a window.|
| int32_t [OH_WindowManager_Snapshot](_window_manager___native_module.md#oh_windowmanager_snapshot) (int32_t windowId, OH_PixelmapNative \*pixelMap) | Obtains the snapshot of a window.|
