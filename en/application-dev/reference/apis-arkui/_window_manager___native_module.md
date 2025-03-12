# WindowManager_NativeModule


## Overview

The WindowManager_NativeModule module provides the capabilities of managing application windows.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [oh_window.h](oh__window_8h.md) | Declares the window management APIs. You can use the APIs to set and obtain the properties of a window, and set its status bar style and navigation bar style.|
| [oh_window_comm.h](oh__window__comm_8h.md) | Declares the common enums and definitions of the window manager.|
| [oh_window_event_filter.h](oh__window__event__filter_8h.md) | Declares the APIs for a window to filter multimodal key events. When a multimodal input event passes through the window, the window can interrupt the event to prevent it from being further distributed.|


### Structs

| Name| Description|
| -------- | -------- |
| struct  [WindowManager_Rect](_window_manager___rect.md) | Defines a struct for the window rectangle, including the window position, width, and height.|
| struct  [WindowManager_WindowProperties](_window_manager___window_properties.md) | Defines a struct for the window properties.|
| struct  [WindowManager_AvoidArea](_window_manager___avoid_area.md) | Defines a struct for the avoid area.|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [WindowManager_ErrorCode](#windowmanager_errorcode)  [WindowManager_ErrorCode](#windowmanager_errorcode) | Defines an enum for the status codes returned by the window manager interface.|
| typedef bool(\* [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | Defines a function for filtering multimodal key events.|
| typedef bool(\* [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter)) (Input_MouseEvent \*mouseEvent) | Defines a function for filtering multimodal mouse events.|
| typedef bool(\* [OH_NativeWindowManager_TouchEventFilter](#oh_nativewindowmanager_toucheventfilter)) (Input_TouchEvent \*touchEvent) | Defines a function for filtering multimodal touch events.|


### Enums

| Name| Description|
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode-1) {<br>OK = 0, WINDOW_MANAGER_ERRORCODE_NO_PERMISSION = 201, WINDOW_MANAGER_ERRORCODE_INVALID_PARAM = 401, WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED = 801,<br>INVAILD_WINDOW_ID = 1000, SERVICE_ERROR = 2000, WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL = 1300002, WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL = 1300003<br>} | Enumerates the status codes returned by the window manager interface.|
| [WindowManager_AvoidAreaType](#windowmanager_avoidareatype) {<br>WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM = 0, WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT = 1, WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE = 2, WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD = 3,<br>WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR = 4<br>} | Enumerates the avoid area types.|
| [WindowManager_WindowType](#windowmanager_windowtype) { WINDOW_MANAGER_WINDOW_TYPE_APP = 0, WINDOW_MANAGER_WINDOW_TYPE_MAIN = 1, WINDOW_MANAGER_WINDOW_TYPE_FLOAT = 8, WINDOW_MANAGER_WINDOW_TYPE_DIALOG = 16 } | Enumerates the window types.|


### Functions

| Name| Description|
| -------- | -------- |
| int32_t [OH_WindowManager_SetWindowStatusBarEnabled](#oh_windowmanager_setwindowstatusbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | Sets whether to display the status bar in a window.|
| int32_t [OH_WindowManager_SetWindowStatusBarColor](#oh_windowmanager_setwindowstatusbarcolor) (int32_t windowId, int32_t color) | Sets the color of the status bar in a window.|
| int32_t [OH_WindowManager_SetWindowNavigationBarEnabled](#oh_windowmanager_setwindownavigationbarenabled) (int32_t windowId, bool enabled, bool enableAnimation) | Sets whether to display the navigation bar in a window.|
| int32_t [OH_WindowManager_GetWindowAvoidArea](#oh_windowmanager_getwindowavoidarea) (int32_t windowId, [WindowManager_AvoidAreaType](#windowmanager_avoidareatype) type, [WindowManager_AvoidArea](_window_manager___avoid_area.md) \*avoidArea) | Obtains the avoid area of a window.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_WindowManager_IsWindowShown](#oh_windowmanager_iswindowshown) (int32_t windowId, bool \*isShow) | Checks whether a window is displayed.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_WindowManager_ShowWindow](#oh_windowmanager_showwindow) (int32_t windowId) | Displays a window.|
| int32_t [OH_WindowManager_SetWindowTouchable](#oh_windowmanager_setwindowtouchable) (int32_t windowId, bool isTouchable) | Sets whether a window is touchable.|
| int32_t [OH_WindowManager_SetWindowFocusable](#oh_windowmanager_setwindowfocusable) (int32_t windowId, bool isFocusable) | Sets whether a window is focusable.|
| int32_t [OH_WindowManager_SetWindowBackgroundColor](#oh_windowmanager_setwindowbackgroundcolor) (int32_t windowId, const char \*color) | Sets the background color of a window.|
| int32_t [OH_WindowManager_SetWindowBrightness](#oh_windowmanager_setwindowbrightness) (int32_t windowId, float brightness) | Sets the screen brightness of a window.|
| int32_t [OH_WindowManager_SetWindowKeepScreenOn](#oh_windowmanager_setwindowkeepscreenon) (int32_t windowId, bool isKeepScreenOn) | Sets whether to always keep the screen on for a window.|
| int32_t [OH_WindowManager_SetWindowPrivacyMode](#oh_windowmanager_setwindowprivacymode) (int32_t windowId, bool isPrivacy) | Sets whether to enable privacy mode for a window.|
| int32_t [OH_WindowManager_GetWindowProperties](#oh_windowmanager_getwindowproperties) (int32_t windowId, [WindowManager_WindowProperties](_window_manager___window_properties.md) \*windowProperties) | Obtains the properties of a window.|
| int32_t [OH_WindowManager_Snapshot](#oh_windowmanager_snapshot) (int32_t windowId, OH_PixelmapNative \*pixelMap) | Obtains the snapshot of a window.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_RegisterKeyEventFilter](#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | Registers the function for filtering multimodal key events.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_UnregisterKeyEventFilter](#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | Unregisters the function for filtering multimodal key events.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_RegisterMouseEventFilter](#oh_nativewindowmanager_registermouseeventfilter) (int32_t windowId, [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter) mouseEventFilter) | Registers the function for filtering multimodal mouse events.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_UnregisterMouseEventFilter](#oh_nativewindowmanager_unregistermouseeventfilter) (int32_t windowId) | Unregisters the function for filtering multimodal mouse events.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_RegisterTouchEventFilter](#oh_nativewindowmanager_registertoucheventfilter) (int32_t windowId, [OH_NativeWindowManager_TouchEventFilter](#oh_nativewindowmanager_toucheventfilter) touchEventFilter) | Registers the function for filtering multimodal touch events.|
| [WindowManager_ErrorCode](#windowmanager_errorcode-1)  [OH_NativeWindowManager_UnregisterTouchEventFilter](#oh_nativewindowmanager_unregistertoucheventfilter) (int32_t windowId) | Unregisters the function for filtering multimodal touch events.|


## Type Description


### OH_NativeWindowManager_KeyEventFilter

```
typedef bool(* OH_NativeWindowManager_KeyEventFilter) (Input_KeyEvent *keyEvent)
```

**Description**

Defines a function for filtering multimodal key events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| keyEvent | Pointer to the multimodal key event. For details, see **Input_KeyEvent**. The event is defined in **oh_input_manager**.|

**Returns**

Returns **true** if the event will be intercepted; returns **false** otherwise.


### OH_NativeWindowManager_MouseEventFilter

```
typedef bool(* OH_NativeWindowManager_MouseEventFilter) (Input_MouseEvent *mouseEvent)
```

**Description**

Defines a function for filtering multimodal mouse events.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| mouseEvent | Pointer to the multimodal mouse event. For details, see **Input_MouseEvent**. The event is defined in **oh_input_manager**.|

**Returns**

Returns **true** if the event will be intercepted; returns **false** otherwise.


### OH_NativeWindowManager_TouchEventFilter

```
typedef bool(* OH_NativeWindowManager_TouchEventFilter) (Input_TouchEvent *touchEvent)
```

**Description**

Defines a function for filtering multimodal touch events.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| touchEvent | Pointer to the multimodal touch event. For details, see **Input_TouchEvent**. The event is defined in **oh_input_manager**.|

**Returns**

Returns **true** if the event will be intercepted; returns **false** otherwise.


### WindowManager_ErrorCode

```
typedef enum WindowManager_ErrorCode WindowManager_ErrorCode
```

**Description**

Defines an enum for the status codes returned by the window manager interface.

**Since**: 12


## Enum Description


### WindowManager_AvoidAreaType

```
enum WindowManager_AvoidAreaType
```

**Description**

Enumerates the avoid area types.

**Since**: 15

| Value| Description|
| -------- | -------- |
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM | System avoid area.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT | Cutout.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE | System gesture area.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD | Keyboard area.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR | Navigation bar area.|


### WindowManager_ErrorCode

```
enum WindowManager_ErrorCode
```

**Description**

Enumerates the status codes returned by the window manager interface.

**Since**: 12

| Value| Description|
| -------- | -------- |
| OK | Operation successful.|
| WINDOW_MANAGER_ERRORCODE_NO_PERMISSION<sup>15+</sup> | No permission.|
| WINDOW_MANAGER_ERRORCODE_INVALID_PARAM<sup>15+</sup> | Invalid parameter.|
| WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED<sup>15+</sup> | Not supported by the device.|
| INVAILD_WINDOW_ID | Invalid window ID.|
| SERVICE_ERROR | Service error.|
| WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL<sup>15+</sup> | Abnormal window status.|
| WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL<sup>15+</sup> | Abnormal window manager service.|


### WindowManager_WindowType

```
enum WindowManager_WindowType
```

**Description**

Enumerates the window types.

**Since**: 15

| Value| Description|
| -------- | -------- |
| WINDOW_MANAGER_WINDOW_TYPE_APP | Child window.|
| WINDOW_MANAGER_WINDOW_TYPE_MAIN | Main window.|
| WINDOW_MANAGER_WINDOW_TYPE_FLOAT | Floating window.|
| WINDOW_MANAGER_WINDOW_TYPE_DIALOG | Modal window.|


## Function Description


### OH_NativeWindowManager_RegisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter )
```

**Description**

Registers the function for filtering multimodal key events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | ID of the window for which the function is registered.|
| keyEventFilter | Function to register.|

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_NativeWindowManager_RegisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter (int32_t windowId, OH_NativeWindowManager_MouseEventFilter mouseEventFilter )
```

**Description**

Registers the function for filtering multimodal mouse events.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | ID of the window for which the function is registered.|
| mouseEventFilter | Function to register.|

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_NativeWindowManager_RegisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter (int32_t windowId, OH_NativeWindowManager_TouchEventFilter touchEventFilter )
```

**Description**

Registers the function for filtering multimodal touch events.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | ID of the window for which the function is registered.|
| touchEventFilter | Function to register.|

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_NativeWindowManager_UnregisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter (int32_t windowId)
```

**Description**

Unregisters the function for filtering multimodal key events.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | ID of the window for which the function is unregistered.|

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_NativeWindowManager_UnregisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter (int32_t windowId)
```

**Description**

Unregisters the function for filtering multimodal mouse events.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | ID of the window for which the function is unregistered.|

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_NativeWindowManager_UnregisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter (int32_t windowId)
```

**Description**

Unregisters the function for filtering multimodal touch events.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | ID of the window for which the function is unregistered.|

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_WindowManager_GetWindowAvoidArea()

```
int32_t OH_WindowManager_GetWindowAvoidArea (int32_t windowId, WindowManager_AvoidAreaType type, WindowManager_AvoidArea * avoidArea )
```

**Description**

Obtains the avoid area of a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| type | Type of the avoid area.|
| avoidArea | Pointer to the avoid area.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called, and the pointer to the avoid area is returned.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_GetWindowProperties()

```
int32_t OH_WindowManager_GetWindowProperties (int32_t windowId, WindowManager_WindowProperties * windowProperties )
```

**Description**

Obtains the properties of a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| windowProperties | Pointer to the properties.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called, and the pointer to the window properties is returned.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_IsWindowShown()

```
WindowManager_ErrorCode OH_WindowManager_IsWindowShown (int32_t windowId, bool * isShow )
```

**Description**

Checks whether a window is displayed.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| isShow | Pointer to the check result. The value **true** means that the window is displayed, and **false** means the opposite.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.


### OH_WindowManager_SetWindowBackgroundColor()

```
int32_t OH_WindowManager_SetWindowBackgroundColor (int32_t windowId, const char * color )
```

**Description**

Sets the background color of a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| color | Pointer to the background color. The value is a string in hexadecimal RGB or ARGB color format.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.


### OH_WindowManager_SetWindowBrightness()

```
int32_t OH_WindowManager_SetWindowBrightness (int32_t windowId, float brightness )
```

**Description**

Sets the screen brightness of a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| brightness | Screen brightness. The value is a floating point number in the range [0.0, 1.0] or set to **-1.0**, where **1.0** indicates the brightest, and **-1.0** is the default brightness.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_SetWindowFocusable()

```
int32_t OH_WindowManager_SetWindowFocusable (int32_t windowId, bool isFocusable )
```

**Description**

Sets whether a window is focusable.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| isFocusable | Whether the window is focusable. The value **true** means that the window is focusable, and **false** means the opposite.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_SetWindowKeepScreenOn()

```
int32_t OH_WindowManager_SetWindowKeepScreenOn (int32_t windowId, bool isKeepScreenOn )
```

**Description**

Sets whether to always keep the screen on for a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| isKeepScreenOn | Whether to always keep the screen on. The value **true** means to always keep the screen on, and the value **false** indicates the opposite.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_SetWindowNavigationBarEnabled()

```
int32_t OH_WindowManager_SetWindowNavigationBarEnabled (int32_t windowId, bool enabled, bool enableAnimation )
```

**Description**

Sets whether to display the navigation bar in a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| enabled | Whether to display the navigation bar. The value **true** means to display the navigation bar, and **false** means the opposite.|
| enableAnimation | Whether to enable the show/hide animation of the navigation bar. The value **true** means to enable the show/hide animation of the navigation bar, and **false** means the opposite.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: This code is returned if the feature is not supported by the device.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_SetWindowPrivacyMode()

```
int32_t OH_WindowManager_SetWindowPrivacyMode (int32_t windowId, bool isPrivacy )
```

**Description**

Sets whether to enable privacy mode for a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| isPrivacy | Whether to enable privacy mode. The value **true** means to enable privacy mode, and **false** means the opposite.|

**Required permissions**: ohos.permission.PRIVACY_WINDOW

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.

**WINDOW_MANAGER_ERRORCODE_NO_PERMISSION**: This code is returned if the permission verification fails.


### OH_WindowManager_SetWindowStatusBarColor()

```
int32_t OH_WindowManager_SetWindowStatusBarColor (int32_t windowId, int32_t color )
```

**Description**

Sets the color of the status bar in a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| color | Color to set, in the ARGB format.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: This code is returned if the feature is not supported by the device.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_SetWindowStatusBarEnabled()

```
int32_t OH_WindowManager_SetWindowStatusBarEnabled (int32_t windowId, bool enabled, bool enableAnimation )
```

**Description**

Sets whether to display the status bar in a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| enabled | Whether to display the status bar. The value **true** means to display the status bar, and **false** means the opposite.|
| enableAnimation | Whether to enable the show/hide animation of the status bar. The value **true** means to enable the show/hide animation of the status bar, and **false** means the opposite.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED**: This code is returned if the feature is not supported by the device.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_SetWindowTouchable()

```
int32_t OH_WindowManager_SetWindowTouchable (int32_t windowId, bool isTouchable )
```

**Description**

Sets whether a window is touchable.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|
| isTouchable | Whether the window is touchable. The value **true** means that the window is touchable, and **false** means the opposite.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_ShowWindow()

```
WindowManager_ErrorCode OH_WindowManager_ShowWindow (int32_t windowId)
```

**Description**

Displays a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.

**WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL**: This code is returned if the window manager service is abnormal.


### OH_WindowManager_Snapshot()

```
int32_t OH_WindowManager_Snapshot (int32_t windowId, OH_PixelmapNative * pixelMap )
```

**Description**

Obtains the snapshot of a window.

**Since**: 15

**Parameters**

| Name| Description|
| -------- | -------- |
| windowId | Window ID. The default value is **0**. The value is an integer. If the window ID is invalid or the window has been destroyed, you cannot obtain the window screenshot. To successfully obtain a screenshot, a valid window ID is required. You can obtain a valid window ID by calling the ArkTS API **getWindowProperties** on the window object.|
| pixelMap | Pointer to the snapshot.|

**Returns**

Returns one of the following result codes:

**OK**: This code is returned if the function is successfully called, and the pointer to the pixelMap is returned.

**WINDOW_MANAGER_ERRORCODE_INVALID_PARAM**: This code is returned if a parameter is incorrect.

**WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL**: This code is returned if the window status is abnormal.
