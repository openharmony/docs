# oh_window_event_filter.h


## Overview

The **oh_window_event_filter.h** file declares the APIs for a window to filter multimodal key events. When a multimodal input event passes through the window, the window can interrupt the event to prevent it from being further distributed.

**System capability**: SystemCapability.Window.SessionManager

**File to include**: &lt;window_manager/oh_window_event_filter.h&gt;

**Library**: libnative_window_manager.so

**Since**: 12

**Related module**: [WindowManager_NativeModule](_window_manager___native_module.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef bool(\* [OH_NativeWindowManager_KeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | Defines a function for filtering multimodal key events.| 
| typedef bool(\* [OH_NativeWindowManager_MouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_mouseeventfilter)) (Input_MouseEvent \*mouseEvent) | Defines a function for filtering multimodal mouse events.| 
| typedef bool(\* [OH_NativeWindowManager_TouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_toucheventfilter)) (Input_TouchEvent \*touchEvent) | Defines a function for filtering multimodal touch events.| 

### Callback

| Name| Description| 
| -------- | -------- |
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterKeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | Registers the function for filtering multimodal key events.| 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterKeyEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | Unregisters the function for filtering multimodal key events.| 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_RegisterMouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_registermouseeventfilter) (int32_t windowId, [OH_NativeWindowManager_MouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_mouseeventfilter) mouseEventFilter) | Registers the function for filtering multimodal mouse events.| 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_UnregisterMouseEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_unregistermouseeventfilter) (int32_t windowId) | Unregisters the function for filtering multimodal mouse events.| 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_RegisterTouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_registertoucheventfilter) (int32_t windowId, [OH_NativeWindowManager_TouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_toucheventfilter) touchEventFilter) | Registers the function for filtering multimodal touch events.| 
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) [OH_NativeWindowManager_UnregisterTouchEventFilter](_window_manager___native_module.md#oh_nativewindowmanager_unregistertoucheventfilter) (int32_t windowId) | Unregisters the function for filtering multimodal touch events.| 
