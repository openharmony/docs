# oh_window.h

## Overview

The **oh_window.h** file declares the window management APIs. You can use the APIs to set and obtain the properties of a window, and set its status bar style and navigation bar style.

**File to include**: <window_manager/oh_window.h>

**Library**: libnative_window_manager.so

**System capability**: SystemCapability.Window.SessionManager

**Since**: 15

**Related module**: [WindowManager](capi-windowmanager.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)](#oh_windowmanager_setwindowstatusbarenabled) | Sets whether to display the status bar in a window.|
| [int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color)](#oh_windowmanager_setwindowstatusbarcolor) | Sets the color of the status bar in a window.|
| [int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)](#oh_windowmanager_setwindownavigationbarenabled) | Sets whether to display the navigation bar in a window.|
| [int32_t OH_WindowManager_GetWindowAvoidArea(int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea* avoidArea)](#oh_windowmanager_getwindowavoidarea) | Obtains the avoid area of a window.|
| [WindowManager_ErrorCode OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow)](#oh_windowmanager_iswindowshown) | Checks whether a window is displayed.|
| [WindowManager_ErrorCode OH_WindowManager_ShowWindow(int32_t windowId)](#oh_windowmanager_showwindow) | Shows a window.|
| [int32_t OH_WindowManager_SetWindowTouchable(int32_t windowId, bool isTouchable)](#oh_windowmanager_setwindowtouchable) | Sets whether a window is touchable.|
| [int32_t OH_WindowManager_SetWindowFocusable(int32_t windowId, bool isFocusable)](#oh_windowmanager_setwindowfocusable) | Sets whether a window is focusable.|
| [int32_t OH_WindowManager_SetWindowBackgroundColor(int32_t windowId, const char* color)](#oh_windowmanager_setwindowbackgroundcolor) | Sets the background color of a window.|
| [int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness)](#oh_windowmanager_setwindowbrightness) | Sets the screen brightness of a window.|
| [int32_t OH_WindowManager_SetWindowKeepScreenOn(int32_t windowId, bool isKeepScreenOn)](#oh_windowmanager_setwindowkeepscreenon) | Sets whether to always keep the screen on for a window.|
| [int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy)](#oh_windowmanager_setwindowprivacymode) | Sets whether to enable privacy mode for a window.|
| [int32_t OH_WindowManager_GetWindowProperties(int32_t windowId, WindowManager_WindowProperties* windowProperties)](#oh_windowmanager_getwindowproperties) | Obtains the properties of a window.|
| [int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap)](#oh_windowmanager_snapshot) | Obtains the snapshot of a window.|
| [int32_t OH_WindowManager_GetAllWindowLayoutInfoList(int64_t displayId,WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize)](#oh_windowmanager_getallwindowlayoutinfolist) | Obtains the layout information array of all windows visible on a display. The layout information is arranged based on the current window stacking order, and the topmost window in the hierarchy is at index 0 of the array.|
| [void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList)](#oh_windowmanager_releaseallwindowlayoutinfolist) | Releases the memory occupied by a window layout information array.|
| [int32_t OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent)](#oh_windowmanager_injecttouchevent) | Injects multimodal touch events to a window. The injection does not trigger window focus or layer changes and is directly sent to ArkUI.|

## Function Description

### OH_WindowManager_SetWindowStatusBarEnabled()

```
int32_t OH_WindowManager_SetWindowStatusBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
```

**Description**

Sets whether to display the status bar in a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| bool enabled | Whether to display the status bar. The value **true** means to display the status bar, and **false** means the opposite.|
| bool enableAnimation | Whether to enable the show/hide animation of the status bar. The value **true** means to enable the show/hide animation of the status bar, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The feature is not supported by the device.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_SetWindowStatusBarColor()

```
int32_t OH_WindowManager_SetWindowStatusBarColor(int32_t windowId, int32_t color)
```

**Description**

Sets the color of the status bar in a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| int32_t color | Color to set, in ARGB format.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The feature is not supported by the device.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_SetWindowNavigationBarEnabled()

```
int32_t OH_WindowManager_SetWindowNavigationBarEnabled(int32_t windowId, bool enabled, bool enableAnimation)
```

**Description**

Sets whether to display the navigation bar in a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| bool enabled | Whether to display the navigation bar. The value **true** means to display the navigation bar, and **false** means the opposite.|
| bool enableAnimation | Whether to enable the show/hide animation of the navigation bar. The value **true** means to enable the show/hide animation of the navigation bar, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The feature is not supported by the device.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_GetWindowAvoidArea()

```
int32_t OH_WindowManager_GetWindowAvoidArea(int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea* avoidArea)
```

**Description**

Obtains the avoid area of a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| [WindowManager_AvoidAreaType](capi-oh-window-comm-h.md#windowmanager_avoidareatype) type | Type of the avoid area.|
| [WindowManager_AvoidArea](capi-windowmanager-avoidarea.md)* avoidArea | Pointer to the avoid area.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called, and the pointer to the avoid area is returned.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_IsWindowShown()

```
WindowManager_ErrorCode OH_WindowManager_IsWindowShown(int32_t windowId, bool* isShow)
```

**Description**

Checks whether a window is displayed.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| bool* isShow | Pointer to the check result. The value **true** means that the window is displayed, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.|

### OH_WindowManager_ShowWindow()

```
WindowManager_ErrorCode OH_WindowManager_ShowWindow(int32_t windowId)
```

**Description**

Shows a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_SetWindowTouchable()

```
int32_t OH_WindowManager_SetWindowTouchable(int32_t windowId, bool isTouchable)
```

**Description**

Sets whether a window is touchable.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| bool isTouchable | Whether the window is touchable. The value **true** means that the window is touchable, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_SetWindowFocusable()

```
int32_t OH_WindowManager_SetWindowFocusable(int32_t windowId, bool isFocusable)
```

**Description**

Sets whether a window is focusable.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| bool isFocusable | Whether the window is focusable. The value **true** means that the window is focusable, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_SetWindowBackgroundColor()

```
int32_t OH_WindowManager_SetWindowBackgroundColor(int32_t windowId, const char* color)
```

**Description**

Sets the background color of a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| const char* color | Pointer to the background color. The value is a string in hexadecimal RGB or ARGB color format.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.|

### OH_WindowManager_SetWindowBrightness()

```
int32_t OH_WindowManager_SetWindowBrightness(int32_t windowId, float brightness)
```

**Description**

Sets the screen brightness of a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| float brightness | Screen brightness. The value is a floating point number in the range [0.0, 1.0] or is set to **-1.0**, where **1.0** indicates the brightest, and **-1.0** is the default brightness.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_SetWindowKeepScreenOn()

```
int32_t OH_WindowManager_SetWindowKeepScreenOn(int32_t windowId, bool isKeepScreenOn)
```

**Description**

Sets whether to always keep the screen on for a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| bool isKeepScreenOn | Whether to always keep the screen on. The value **true** means to always keep the screen on, and the value **false** indicates the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_SetWindowPrivacyMode()

```
int32_t OH_WindowManager_SetWindowPrivacyMode(int32_t windowId, bool isPrivacy)
```

**Description**

Sets whether to enable privacy mode for a window.

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| bool isPrivacy | Whether to enable privacy mode. The value **true** means to enable privacy mode, and **false** means the opposite.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PERMISSION**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_NO_PERMISSION**: The permission verification fails.|

### OH_WindowManager_GetWindowProperties()

```
int32_t OH_WindowManager_GetWindowProperties(int32_t windowId, WindowManager_WindowProperties* windowProperties)
```

**Description**

Obtains the properties of a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| [WindowManager_WindowProperties](capi-windowmanager-windowproperties.md)* windowProperties | Pointer to the properties.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called, and the pointer to the window properties is returned.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_Snapshot()

```
int32_t OH_WindowManager_Snapshot(int32_t windowId, OH_PixelmapNative* pixelMap)
```

**Description**

Obtains the snapshot of a window.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.<br>If the window ID is invalid or the window has been destroyed, you cannot obtain the window snapshot. To successfully obtain a snapshot, a valid window ID is required.<br>You can obtain a valid window ID by calling the ArkTS API **getWindowProperties** on the window object.|
| [OH_PixelmapNative](capi-struct.md)* pixelMap | Pointer to the snapshot.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called, and the pointer to the pixelMap is returned.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.|

### OH_WindowManager_GetAllWindowLayoutInfoList()

```
int32_t OH_WindowManager_GetAllWindowLayoutInfoList(int64_t displayId,WindowManager_Rect** windowLayoutInfoList, size_t* windowLayoutInfoSize)
```

**Description**

Obtains the layout information array of all windows visible on a display. The layout information is arranged based on the current window stacking order, and the topmost window in the hierarchy is at index 0 of the array.

**Since**: 17


**Parameters**

| Parameter| Description|
| -- | -- |
| int64_t displayId | ID of the display. You can obtain a valid display ID by calling the ArkTS API **getWindowProperties** on the window object.|
| [WindowManager_Rect](capi-windowmanager-rect.md)** windowLayoutInfoList | Double pointer to the layout information array of all windows visible.|
| size_t* windowLayoutInfoSize | Pointer to the length of the layout information array.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called, and the double pointer to the array and the pointer to the array length are returned.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: The feature is not supported by the device.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|

### OH_WindowManager_ReleaseAllWindowLayoutInfoList()

```
void OH_WindowManager_ReleaseAllWindowLayoutInfoList(WindowManager_Rect* windowLayoutInfoList)
```

**Description**

Releases the memory occupied by a window layout information array.

**Since**: 17


**Parameters**

| Parameter| Description|
| -- | -- |
| [WindowManager_Rect](capi-windowmanager-rect.md)* windowLayoutInfoList | Pointer to the layout information array of all windows visible on the display. You can obtain the array pointer by calling [OH_WindowManager_GetAllWindowLayoutInfoList](capi-oh-window-h.md#oh_windowmanager_getallwindowlayoutinfolist).|

### OH_WindowManager_InjectTouchEvent()

```
int32_t OH_WindowManager_InjectTouchEvent(int32_t windowId, Input_TouchEvent* touchEvent)
```

**Description**

Injects multimodal touch events to a window. The injection does not trigger window focus or layer changes and is directly sent to ArkUI.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | Window ID. The default value is **0**. The value is an integer.|
| [Input_TouchEvent](../apis-input-kit/capi-oh-input-manager-h.md#input_touchevent)* touchEvent | Pointer to the multimodal touch event. For details, see [Input_TouchEvent](../apis-input-kit/capi-oh-input-manager-h.md#input_touchevent). The event is defined in **oh_input_manager.h**.|

**Return value**

| Type| Description|
| -- | -- |
| int32_t | One of the following result codes:<br> **OK**: The function is successfully called.<br> **WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: A parameter is incorrect.<br> **WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: The window status is abnormal.<br> **WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: The window manager service is abnormal.|
