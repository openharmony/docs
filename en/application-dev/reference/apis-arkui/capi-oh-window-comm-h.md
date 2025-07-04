# oh_window_comm.h

## Overview

The **oh_window_comm.h** file declares the common enums and definitions of the window manager.

**File to include**: <window_manager/oh_window_comm.h>

**Library**: libnative_window_manager.so

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12

**Related module**: [WindowManager](capi-windowmanager.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [WindowManager_Rect](capi-windowmanager-rect.md) | WindowManager_Rect | Describes the window rectangle, including the window position, width, and height.|
| [struct](capi-struct.md) | OH_PixelmapNative | Describes the native pixel image information.|
| [WindowManager_WindowProperties](capi-windowmanager-windowproperties.md) | WindowManager_WindowProperties | Describes the window properties.|
| [WindowManager_AvoidArea](capi-windowmanager-avoidarea.md) | WindowManager_AvoidArea | Describes the avoid area.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [WindowManager_ErrorCode](#windowmanager_errorcode) | WindowManager_ErrorCode | Enumerates the status codes returned by the window manager interface.|
| [WindowManager_AvoidAreaType](#windowmanager_avoidareatype) | WindowManager_AvoidAreaType | Enumerates the avoid area types.|
| [WindowManager_WindowType](#windowmanager_windowtype) | WindowManager_WindowType | Enumerates the window types.|

## Enum Description

### WindowManager_ErrorCode

```
enum WindowManager_ErrorCode
```

**Description**

Enumerates the status codes returned by the window manager interface.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| OK = 0 | Operation successful.|
| WINDOW_MANAGER_ERRORCODE_NO_PERMISSION = 201 | No permission.<br>**Since**: 15|
| WINDOW_MANAGER_ERRORCODE_INVALID_PARAM = 401 | Invalid parameter.<br>**Since**: 15|
| WINDOW_MANAGER_ERRORCODE_DEVICE_NOT_SUPPORTED = 801 | Not supported by the device.<br>**Since**: 15|
| INVAILD_WINDOW_ID = 1000 | Invalid window ID.|
| SERVICE_ERROR = 2000 | Service error.|
| WINDOW_MANAGER_ERRORCODE_STATE_ABNORMAL = 1300002 | Abnormal window status.<br>**Since**: 15|
| WINDOW_MANAGER_ERRORCODE_SYSTEM_ABNORMAL = 1300003 | Abnormal window manager service.<br>**Since**: 15|
| WINDOW_MANAGER_ERRORCODE_PIP_DESTROY_FAILED = 1300011 | Failed to destroy the PiP window.<br>**Since**: 20|
| WINDOW_MANAGER_ERRORCODE_PIP_STATE_ABNORMAL = 1300012 | Abnormal PiP status.<br>**Since**: 20|
| WINDOW_MANAGER_ERRORCODE_PIP_CREATE_FAILED = 1300013 | Failed to create the PiP window.<br>**Since**: 20|
| WINDOW_MANAGER_ERRORCODE_PIP_INTERNAL_ERROR = 1300014 | An internal error occurs in PiP. Possible causes:<br>1. The window on which the PiP feature depends is abnormal. For example, the window is empty. 2. The PiP controller is abnormal.<br>**Since**: 20|
| WINDOW_MANAGER_ERRORCODE_PIP_REPEATED_OPERATION = 1300015 | Repeated PiP operation.<br>**Since**: 20|
| WINDOW_MANAGER_ERRORCODE_INCORRECT_PARAM = 1300016 | Incorrect parameter. Possible causes:<br>1. The parameter value range is invalid. 2. The number of parameters is invalid. 3. The parameter type is invalid.<br>**Since**: 20|

### WindowManager_AvoidAreaType

```
enum WindowManager_AvoidAreaType
```

**Description**

Enumerates the avoid area types.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM = 0 | System avoid area.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_CUTOUT = 1 | Cutout area.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_SYSTEM_GESTURE = 2 | System gesture area.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_KEYBOARD = 3 | Keyboard area.|
| WINDOW_MANAGER_AVOID_AREA_TYPE_NAVIGATION_INDICATOR = 4 | Navigation bar area.|

### WindowManager_WindowType

```
enum WindowManager_WindowType
```

**Description**

Enumerates the window types.

**Since**: 15

| Enum Item| Description|
| -- | -- |
| WINDOW_MANAGER_WINDOW_TYPE_APP = 0 | Child window.|
| WINDOW_MANAGER_WINDOW_TYPE_MAIN = 1 | Main window.|
| WINDOW_MANAGER_WINDOW_TYPE_FLOAT = 8 | Floating window.|
| WINDOW_MANAGER_WINDOW_TYPE_DIALOG = 16 | Modal window.|
