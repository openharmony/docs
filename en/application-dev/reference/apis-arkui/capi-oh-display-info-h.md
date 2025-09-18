# oh_display_info.h
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk; @logn-->
<!--Designer: @hejunfei1991-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## Overview

The file declares the common enums and definitions of the display.

**File to include**: <window_manager/oh_display_info.h>

**Library**: libnative_display_manager.so

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Related module**: [OH_DisplayManager](capi-oh-displaymanager.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NativeDisplayManager_Rect](capi-nativedisplaymanager-rect.md) | NativeDisplayManager_Rect | Describes a rectangle.|
| [NativeDisplayManager_WaterfallDisplayAreaRects](capi-nativedisplaymanager-waterfalldisplayarearects.md) | NativeDisplayManager_WaterfallDisplayAreaRects | Describes the curved area on a waterfall display.|
| [NativeDisplayManager_CutoutInfo](capi-nativedisplaymanager-cutoutinfo.md) | NativeDisplayManager_CutoutInfo | Describes the unusable area of a display, including punch hole, notch, and curved area of a waterfall display.|
| [NativeDisplayManager_DisplayHdrFormat](capi-nativedisplaymanager-displayhdrformat.md) | NativeDisplayManager_DisplayHdrFormat | Describes all the HDR formats supported by a display.|
| [NativeDisplayManager_DisplayColorSpace](capi-nativedisplaymanager-displaycolorspace.md) | NativeDisplayManager_DisplayColorSpace | Describes all the color spaces supported by a display.|
| [NativeDisplayManager_DisplayInfo](capi-nativedisplaymanager-displayinfo.md) | NativeDisplayManager_DisplayInfo | Describes the information about a display.|
| [NativeDisplayManager_DisplaysInfo](capi-nativedisplaymanager-displaysinfo.md) | NativeDisplayManager_DisplaysInfo | Describes the information about displays of a device with multiple screens.|

### Macros

| Name | Description  |
|--------------|-----------|
| [OH_DISPLAY_NAME_LENGTH](#oh_display_name_length)  32 | Maximum length of a display name.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation) | NativeDisplayManager_Rotation | Enumerates the clockwise rotation angles of a display.|
| [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation) | NativeDisplayManager_Orientation | Enumerates the orientations of a display.|
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) | NativeDisplayManager_ErrorCode | Enumerates the status codes returned by the display manager interface.|
| [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) | NativeDisplayManager_FoldDisplayMode | Enumerates the display modes of a foldable device.|
| [NativeDisplayManager_DisplayState](#nativedisplaymanager_displaystate) | NativeDisplayManager_DisplayState | Enumerates the states of a display.|
| [NativeDisplayManager_SourceMode](#nativedisplaymanager_sourcemode) | NativeDisplayManager_SourceMode | Enumerates the source modes of a device.|

## Macro Description

### OH_DISPLAY_NAME_LENGTH

```
#define OH_DISPLAY_NAME_LENGTH 32
```

**Description**

Maximum length of a display name.

**Since**: 14

## Enum Description

### NativeDisplayManager_Rotation

```
enum NativeDisplayManager_Rotation
```

**Description**

Enumerates the clockwise rotation angles of a display.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DISPLAY_MANAGER_ROTATION_0 = 0 | The display is rotated clockwise by 0 degrees.|
| DISPLAY_MANAGER_ROTATION_90 = 1 | The display is rotated clockwise by 90 degrees.|
| DISPLAY_MANAGER_ROTATION_180 = 2 | The display is rotated clockwise by 180 degrees.|
| DISPLAY_MANAGER_ROTATION_270 = 3 | The display is rotated clockwise by 270 degrees.|

### NativeDisplayManager_Orientation

```
enum NativeDisplayManager_Orientation
```

**Description**

Enumerates the orientations of a display.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DISPLAY_MANAGER_PORTRAIT = 0 | The display is in portrait mode.|
| DISPLAY_MANAGER_LANDSCAPE = 1 | The display is in landscape mode.|
| DISPLAY_MANAGER_PORTRAIT_INVERTED = 2 | The display is in reverse portrait mode.|
| DISPLAY_MANAGER_LANDSCAPE_INVERTED = 3 | The display is in reverse landscape mode.|
| DISPLAY_MANAGER_UNKNOWN | The screen orientation is unknown.|

### NativeDisplayManager_ErrorCode

```
enum NativeDisplayManager_ErrorCode
```

**Description**

Enumerates the status codes returned by the display manager interface.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DISPLAY_MANAGER_OK = 0 | Success.|
| DISPLAY_MANAGER_ERROR_NO_PERMISSION = 201 | Permission verification fails. The application does not have the permission to use the API.|
| DISPLAY_MANAGER_ERROR_NOT_SYSTEM_APP = 202 | Permission verification fails. A non-system application attempts to call a system API.|
| DISPLAY_MANAGER_ERROR_INVALID_PARAM = 401 | Parameter check fails.|
| DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED = 801 | The device does not support the API.|
| DISPLAY_MANAGER_ERROR_INVALID_SCREEN = 1400001 | The display is invalid.|
| DISPLAY_MANAGER_ERROR_INVALID_CALL = 1400002 | The current operation object does not have the operation permission.|
| DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL = 1400003 | The system service is abnormal.|
| DISPLAY_MANAGER_ERROR_ILLEGAL_PARAM = 1400004 |  Invalid parameter.<br>**Since**: 20|

### NativeDisplayManager_FoldDisplayMode

```
enum NativeDisplayManager_FoldDisplayMode
```

**Description**

Enumerates the display modes of a foldable device.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_UNKNOWN = 0 | The display mode of the device is unknown.|
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_FULL = 1 | The device is displayed in full screen.|
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_MAIN = 2 | The main screen of the device is displayed.|
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_SUB = 3 | The subscreen of the device is displayed.|
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_COORDINATION = 4 | Both screens of the device are displayed in collaborative mode.|

### NativeDisplayManager_DisplayState

```
enum NativeDisplayManager_DisplayState
```

**Description**

Enumerates the states of a display.

**Since**: 14

| Enum Item| Description|
| -- | -- |
| DISPLAY_MANAGER_DISPLAY_STATE_UNKNOWN = 0 | Unknown.|
| DISPLAY_MANAGER_DISPLAY_STATE_OFF = 1 | The display is shut down.|
| DISPLAY_MANAGER_DISPLAY_STATE_ON = 2 | The display is powered on.|
| DISPLAY_MANAGER_DISPLAY_STATE_DOZE = 3 | The display is in sleep mode.|
| DISPLAY_MANAGER_DISPLAY_STATE_DOZE_SUSPEND = 4 | The display is in sleep mode, and the CPU is suspended.|
| DISPLAY_MANAGER_DISPLAY_STATE_VR = 5 | The display is in VR mode.|
| DISPLAY_MANAGER_DISPLAY_STATE_ON_SUSPEND = 6 | The display is powered on, and the CPU is suspended.|

### NativeDisplayManager_SourceMode

```
enum NativeDisplayManager_SourceMode
```

**Description**

Enumerates the source modes of a device.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| DISPLAY_SOURCE_MODE_NONE = 0 | The device is currently not in use.|
| DISPLAY_SOURCE_MODE_MAIN = 1 | The primary screen of the device is currently in use.|
| DISPLAY_SOURCE_MODE_MIRROR = 2 | The device is currently in mirror display mode.|
| DISPLAY_SOURCE_MODE_EXTEND = 3 | The device is currently in extended display mode.|
| DISPLAY_SOURCE_MODE_ALONE = 4 | The device is currently in independent display mode.|
