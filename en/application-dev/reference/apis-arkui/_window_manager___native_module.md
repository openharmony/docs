# WindowManager_NativeModule


## Overview

The WindowManager_NativeModule module provides the capabilities of managing application windows.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [oh_window_comm.h](oh__window__comm_8h.md) | Declares the common enums and definitions of the window manager.| 
| [oh_window_event_filter.h](oh__window__event__filter_8h.md) | Declares the APIs for a window to filter multimodal key events. When a multimodal input event passes through the window, the window can interrupt the event to prevent it from being further distributed.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [WindowManager_ErrorCode](#windowmanager_errorcode)  [WindowManager_ErrorCode](#windowmanager_errorcode) | Defines an enum for the status codes returned by the window manager interface.| 
| typedef bool(\*[OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | Defines a function for filtering a multimodal key event.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode) { OK = 0, INVAILD_WINDOW_ID = 1000, SERVICE_ERROR = 2000 } | Enumerates the status codes returned by the window manager interface.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterKeyEventFilter](#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | Registers the function for filtering a multimodal key event.| 
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterKeyEventFilter](#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | Unregisters the function for filtering a multimodal key event.| 


## Type Description


### OH_NativeWindowManager_KeyEventFilter

```
typedef bool(* OH_NativeWindowManager_KeyEventFilter) (Input_KeyEvent *keyEvent)
```

**Description**

Defines a function for filtering a multimodal key event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyEvent | Multimodal key event. For details, see **Input_KeyEvent**. The event is defined in **oh_input_manager**.| 

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
| INVAILD_WINDOW_ID | Invalid window ID.| 
| SERVICE_ERROR | Service error.| 


## Function Description


### OH_NativeWindowManager_RegisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter )
```

**Description**

Registers the function for filtering a multimodal key event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| windowId | ID of the window for which the function is registered.| 
| keyEventFilter | Function for filtering a multimodal key event.| 

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_NativeWindowManager_UnregisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter (int32_t windowId)
```

**Description**

Unregisters the function for filtering a multimodal key event.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| windowId | ID of the window for which the function is unregistered.| 

**Returns**

Returns a status code defined in [WindowManager_ErrorCode](#windowmanager_errorcode).
