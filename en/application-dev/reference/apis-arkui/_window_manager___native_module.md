# WindowManager_NativeModule


## Overview

Provides the capabilities of managing application windows.

**Since**: 12


## Summary


### File

| Name | **Description** | 
| -------- | -------- |
| [oh_window_comm.h](oh__window__comm_8h.md) | Declares the common enums and definitions of the window manager. | 
| [oh_window_event_filter.h](oh__window__event__filter_8h.md) | Declares the APIs for a window to filter multimodal key events. When a multimodal input event passes through the window, the window can interrupt the event and prevent it from being further distributed. | 


### Types

| Name | Description | 
| -------- | -------- |
| typedef enum [WindowManager_ErrorCode](#windowmanager_errorcode)  [WindowManager_ErrorCode](#windowmanager_errorcode) | Enumerates the status codes returned by the window manager interface. | 
| typedef bool(\*[OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter)) (Input_KeyEvent \*keyEvent) | Defines a function for filtering a multimodal key event. | 


### Enums

| Name | **Description** | 
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode) { OK = 0, INVAILD_WINDOW_ID = 1000, SERVICE_ERROR = 2000 } | Enumerates the status codes returned by the window manager interface. | 


### Callback

| Name | Description | 
| -------- | -------- |
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_RegisterKeyEventFilter](#oh_nativewindowmanager_registerkeyeventfilter) (int32_t windowId, [OH_NativeWindowManager_KeyEventFilter](#oh_nativewindowmanager_keyeventfilter) keyEventFilter) | Registers the function for filtering a multimodal key event. | 
| [WindowManager_ErrorCode](#windowmanager_errorcode)  [OH_NativeWindowManager_UnregisterKeyEventFilter](#oh_nativewindowmanager_unregisterkeyeventfilter) (int32_t windowId) | Unregisters the function for filtering a multimodal key event. | 


## Type Description


### OH_NativeWindowManager_KeyEventFilter

```
typedef bool(* OH_NativeWindowManager_KeyEventFilter) (Input_KeyEvent *keyEvent)
```

**Description**

Defines a function for filtering a multimodal key event.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| keyEvent | Multi-mode key event. For details, see Input_KeyEvent. The event is defined in oh_input_manager. | 

**Returns**

Returns **true** if the event will be intercepted; returns **false** otherwise.


### WindowManager_ErrorCode

```
typedef enum WindowManager_ErrorCode WindowManager_ErrorCode
```

**Description**

Enumerates the status codes returned by the window manager interface.

**Since**: 12


## Enum Description


### WindowManager_ErrorCode

```
enum WindowManager_ErrorCode
```

**Description**

Enumerates the status codes returned by the window manager interface.

**Since**: 12

| Enum | Description | 
| -------- | -------- |
| OK | Success. | 
| INVAILD_WINDOW_ID | /** Invalid window ID. | 
| SERVICE_ERROR | A system error occurs. | 


## Function Description


### OH_NativeWindowManager_RegisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_RegisterKeyEventFilter (int32_t windowId, OH_NativeWindowManager_KeyEventFilter keyEventFilter )
```

**Description**

Registers the function for filtering a multimodal key event.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| windowId | ID of the window whose key events need to be filtered. | 
| keyEventFilter | Filters multi-mode keys. | 

**Returns**

Common status code of the window management API. For details, see [WindowManager_ErrorCode](#windowmanager_errorcode).


### OH_NativeWindowManager_UnregisterKeyEventFilter()

```
WindowManager_ErrorCode OH_NativeWindowManager_UnregisterKeyEventFilter (int32_t windowId)
```

**Description**

Unregisters the function for filtering a multimodal key event.

**Since**: 12

**Parameters**

| Name | Description | 
| -------- | -------- |
| windowId | ID of the window whose key event filtering needs to be canceled. | 

**Returns**

Common status code of the window management API. For details, see [WindowManager_ErrorCode](#windowmanager_errorcode).
