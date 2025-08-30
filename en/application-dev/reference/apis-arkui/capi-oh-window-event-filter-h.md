# oh_window_event_filter.h

## Overview

The file declares the APIs for a window to filter multimodal key events. When a multimodal input event passes through the window, the window can interrupt the event to prevent it from being further distributed.

**File to include**: <window_manager/oh_window_event_filter.h>

**Library**: libnative_window_manager.so

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12

**Related module**: [WindowManager](capi-windowmanager.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef bool (\*OH_NativeWindowManager_KeyEventFilter)(Input_KeyEvent* keyEvent)](#oh_nativewindowmanager_keyeventfilter) | OH_NativeWindowManager_KeyEventFilter | Defines a function for filtering multimodal key events.|
| [WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter(int32_t windowId,OH_NativeWindowManager_KeyEventFilter keyEventFilter)](#oh_nativewindowmanager_registerkeyeventfilter) | - | Registers a function for filtering multimodal key events.|
| [WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId)](#oh_nativewindowmanager_unregisterkeyeventfilter) | - | Unregisters a function for filtering multimodal key events.|
| [typedef bool (\*OH_NativeWindowManager_MouseEventFilter)(Input_MouseEvent* mouseEvent)](#oh_nativewindowmanager_mouseeventfilter) | OH_NativeWindowManager_MouseEventFilter | Defines a function for filtering multimodal mouse events.|
| [WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter(int32_t windowId,OH_NativeWindowManager_MouseEventFilter mouseEventFilter)](#oh_nativewindowmanager_registermouseeventfilter) | - | Registers a function for filtering multimodal mouse events.|
| [WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter(int32_t windowId)](#oh_nativewindowmanager_unregistermouseeventfilter) | - | Unregisters a function for filtering multimodal mouse events.|
| [typedef bool (\*OH_NativeWindowManager_TouchEventFilter)(Input_TouchEvent* touchEvent)](#oh_nativewindowmanager_toucheventfilter) | OH_NativeWindowManager_TouchEventFilter | Defines a function for filtering multimodal touch events.|
| [WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter(int32_t windowId,OH_NativeWindowManager_TouchEventFilter touchEventFilter)](#oh_nativewindowmanager_registertoucheventfilter) | - | Registers a function for filtering multimodal touch events.|
| [WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter(int32_t windowId)](#oh_nativewindowmanager_unregistertoucheventfilter) | - | Unregisters a function for filtering multimodal touch events.|

## Function Description

### OH_NativeWindowManager_KeyEventFilter()

```
typedef bool (*OH_NativeWindowManager_KeyEventFilter)(Input_KeyEvent* keyEvent)
```

**Description**

Defines a function for filtering multimodal key events.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_KeyEvent](../apis-input-kit/capi-input-input-keyevent.md)* keyEvent | Pointer to the multimodal key event. For details, see [Input_KeyEvent](../apis-input-kit/capi-input-input-keyevent.md). The event is defined in **oh_input_manager**.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Whether the event will be intercepted. **true** if intercepted, **false** otherwise.|

### OH_NativeWindowManager_RegisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter(int32_t windowId,OH_NativeWindowManager_KeyEventFilter keyEventFilter)
```

**Description**

Registers a function for filtering multimodal key events.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | ID of the window for which the function is registered.|
| [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter) keyEventFilter | Function to register.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | Status code defined in [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode).|

### OH_NativeWindowManager_UnregisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter(int32_t windowId)
```

**Description**

Unregisters a function for filtering multimodal key events.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | ID of the window for which the function is unregistered.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | Status code defined in [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode).|

### OH_NativeWindowManager_MouseEventFilter()

```
typedef bool (*OH_NativeWindowManager_MouseEventFilter)(Input_MouseEvent* mouseEvent)
```

**Description**

Defines a function for filtering multimodal mouse events.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_MouseEvent](../apis-input-kit/capi-input-input-mouseevent.md)* mouseEvent | Pointer to the multimodal mouse event. For details, see [Input_MouseEvent](../apis-input-kit/capi-input-input-mouseevent.md). The event is defined in **oh_input_manager**.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Whether the event will be intercepted. **true** if the event will be intercepted; returns **false** otherwise.|

### OH_NativeWindowManager_RegisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterMouseEventFilter(int32_t windowId,OH_NativeWindowManager_MouseEventFilter mouseEventFilter)
```

**Description**

Registers a function for filtering multimodal mouse events.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | ID of the window for which the function is registered.|
| [OH_NativeWindowManager_MouseEventFilter](#oh_nativewindowmanager_mouseeventfilter) mouseEventFilter | Function to register.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | Status code defined in [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode).|

### OH_NativeWindowManager_UnregisterMouseEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterMouseEventFilter(int32_t windowId)
```

**Description**

Unregisters a function for filtering multimodal mouse events.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | ID of the window for which the function is unregistered.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | Status code defined in [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode).|

### OH_NativeWindowManager_TouchEventFilter()

```
typedef bool (*OH_NativeWindowManager_TouchEventFilter)(Input_TouchEvent* touchEvent)
```

**Description**

Defines a function for filtering multimodal touch events.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| [Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md)* touchEvent | Pointer to the multimodal touch event. For details, see [Input_TouchEvent](../apis-input-kit/capi-input-input-touchevent.md). The event is defined in **oh_input_manager**.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Whether the event will be intercepted. **true** if the event will be intercepted; returns **false** otherwise.|

### OH_NativeWindowManager_RegisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterTouchEventFilter(int32_t windowId,OH_NativeWindowManager_TouchEventFilter touchEventFilter)
```

**Description**

Registers a function for filtering multimodal touch events.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | ID of the window for which the function is registered.|
| [OH_NativeWindowManager_TouchEventFilter](#oh_nativewindowmanager_toucheventfilter) touchEventFilter | Function to register.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | Status code defined in [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode).|

### OH_NativeWindowManager_UnregisterTouchEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterTouchEventFilter(int32_t windowId)
```

**Description**

Unregisters a function for filtering multimodal touch events.

**Since**: 15


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t windowId | ID of the window for which the function is unregistered.|

**Return value**

| Type| Description|
| -- | -- |
| [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode) | Status code defined in [WindowManager_ErrorCode](capi-oh-window-comm-h.md#windowmanager_errorcode).|
