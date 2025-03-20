# oh_window_comm.h


## Overview

The **oh_window_comm.h** file declares the common enums and definitions of the window manager.

**System capability**: SystemCapability.Window.SessionManager

**File to include**: &lt;window_manager/oh_window_comm.h&gt;

**Library**: libnative_window_manager.so

**Since**: 12

**Related module**: [WindowManager_NativeModule](_window_manager___native_module.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| struct  [WindowManager_Rect](_window_manager___rect.md) | Defines a struct for the window rectangle, including the window position, width, and height.|
| struct  [WindowManager_WindowProperties](_window_manager___window_properties.md) | Defines a struct for the window properties.|
| struct  [WindowManager_AvoidArea](_window_manager___avoid_area.md) | Defines a struct for the avoid area.|


### Types

| Name| Description|
| -------- | -------- |
| typedef enum [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode)  [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) | Defines an enum for the status codes returned by the window manager interface.|


### Enums

| Name| Description|
| -------- | -------- |
| [WindowManager_ErrorCode](_window_manager___native_module.md#windowmanager_errorcode) {<br>OK = 0, WINDOW_MANAGER_ERRORCODE_NO_PERMISSION = 201, WINDOW_MANAGER_ERRORCODE_INVALID_PARAM = 401, WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED = 801,<br>INVAILD_WINDOW_ID = 1000, SERVICE_ERROR = 2000, WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL = 1300002, WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL = 1300003<br>} | Enumerates the status codes returned by the window manager interface.|
| [WindowManager_AvoidAreaType](_window_manager___native_module.md#windowmanager_avoidareatype) {<br>WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM = 0, WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT = 1, WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE = 2, WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD = 3,<br>WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR = 4<br>} | Enumerates the avoid area types.|
| [WindowManager_WindowType](_window_manager___native_module.md#windowmanager_windowtype) { WINDOW_MANAGER_WINDOW_TYPE_APP = 0, WINDOW_MANAGER_WINDOW_TYPE_MAIN = 1, WINDOW_MANAGER_WINDOW_TYPE_FLOAT = 8, WINDOW_MANAGER_WINDOW_TYPE_DIALOG = 16 } | Enumerates the window types.|
