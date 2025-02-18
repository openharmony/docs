# OH_DisplayManager


## Overview

The OH_DisplayManager module provides the display management capability.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

## Summary

### Files

| Name| Description| 
| -------- | -------- |
| [oh_display_capture.h](oh__display__capture_8h.md) | Declares the capability to take screenshots.| 
| [oh_display_info.h](oh__display__info_8h.md) | Declares the common enums and definitions of the display.| 
| [oh_display_manager.h](oh__display__manager_8h.md) | Declares the functions for basic display management. You can call the functions to obtain various information about the default display and listen for display status changes, such as rotation, folding, and unfolding.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [NativeDisplayManager_Rect](_native_display_manager___rect.md) | Describes a rectangle.| 
| struct  [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) | Describes the curved area on a waterfall display.| 
| struct  [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) | Describes the unusable area of a display, including punch hole, notch, and curved area of a waterfall display.| 
| struct  [NativeDisplayManager_DisplayHdrFormat](_native_display_manager___display_hdr_format.md) | Describes all the HDR formats supported by a display.| 
| struct  [NativeDisplayManager_DisplayColorSpace](_native_display_manager___display_color_space.md) | Describes all the color spaces supported by a display.| 
| struct  [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) | Encapsulates the information about a display.| 
| struct  [NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) | Encapsulates the information about displays of a device with multiple screens.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation) [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation) | Defines an enum for the clockwise rotation angles of a display.| 
| typedef enum [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation) [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation) | Defines an enum for the orientations of a display.| 
| typedef enum [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) | Defines an enum for the status codes returned by the display manager interface.| 
| typedef enum [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) | Defines an enum for the display modes of a foldable device.| 
| typedef struct [NativeDisplayManager_Rect](_native_display_manager___rect.md) [NativeDisplayManager_Rect](#nativedisplaymanager_rect) | Defines a struct for a rectangle.| 
| typedef struct [NativeDisplayManager_WaterfallDisplayAreaRects](ive_display_manager___waterfall_display_area_rects.md) [NativeDisplayManager_WaterfallDisplayAreaRects](#nativedisplaymanager_waterfalldisplayarearects) | Defines a struct for the curved area on a waterfall display.| 
| typedef struct [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) [NativeDisplayManager_CutoutInfo](#nativedisplaymanager_cutoutinfo) | Defines a struct for the unusable area of a display, including punch hole, notch, and curved area of a waterfall display.| 
| typedef enum [NativeDisplayManager_DisplayState](#nativedisplaymanager_displaystate) [NativeDisplayManager_DisplayState](#nativedisplaymanager_displaystate) | Defines an enum for the states of a display.| 
| typedef struct [NativeDisplayManager_DisplayHdrFormat](_native_display_manager___display_hdr_format.md) [NativeDisplayManager_DisplayHdrFormat](#nativedisplaymanager_displayhdrformat) | Defines a struct for all the HDR formats supported by a display.| 
| typedef struct [NativeDisplayManager_DisplayColorSpace](_native_display_manager___display_color_space.md) [NativeDisplayManager_DisplayColorSpace](#nativedisplaymanager_displaycolorspace) | Defines a struct for all the color spaces supported by a display.| 
| typedef struct [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) [NativeDisplayManager_DisplayInfo](#nativedisplaymanager_displayinfo) | Defines a struct that encapsulates the information about a display.| 
| typedef struct [NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) [NativeDisplayManager_DisplaysInfo](#nativedisplaymanager_displaysinfo) | Defines a struct that encapsulates the information about displays of a device with multiple screens.| 
| typedef void(\* [OH_NativeDisplayManager_DisplayChangeCallback](#oh_nativedisplaymanager_displaychangecallback)) (uint64_t displayId) | Defines a callback function to listen for status changes of a display.| 
| typedef void(\* [OH_NativeDisplayManager_FoldDisplayModeChangeCallback](#oh_nativedisplaymanager_folddisplaymodechangecallback)) ([NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) displayMode) | Defines a callback function to listen for folded/unfolded state changes of a display.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation-1) { DISPLAY_MANAGER_ROTATION_0 = 0, DISPLAY_MANAGER_ROTATION_90 = 1, DISPLAY_MANAGER_ROTATION_180 = 2, DISPLAY_MANAGER_ROTATION_270 = 3 } | Enumerates the clockwise rotation angles of a display.| 
| [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation-1) {<br>DISPLAY_MANAGER_PORTRAIT = 0, DISPLAY_MANAGER_LANDSCAPE = 1, DISPLAY_MANAGER_PORTRAIT_INVERTED = 2, DISPLAY_MANAGER_LANDSCAPE_INVERTED = 3,<br>DISPLAY_MANAGER_UNKNOWN<br>} | Enumerates the orientations of a display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode-1) {<br>DISPLAY_MANAGER_OK = 0, DISPLAY_MANAGER_ERROR_NO_PERMISSION = 201, DISPLAY_MANAGER_ERROR_NOT_SYSTEM_APP = 202, DISPLAY_MANAGER_ERROR_INVALID_PARAM = 401,<br>DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED = 801, DISPLAY_MANAGER_ERROR_INVALID_SCREEN = 1400001, DISPLAY_MANAGER_ERROR_INVALID_CALL = 1400002, DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL = 1400003<br>} | Enumerates the status codes returned by the display manager interface.| 
| [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode-1) {<br>DISPLAY_MANAGER_FOLD_DISPLAY_MODE_UNKNOWN = 0, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_FULL = 1, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_MAIN = 2, DISPLAY_MANAGER_FOLD_DISPLAY_MODE_SUB = 3,<br>DISPLAY_MANAGER_FOLD_DISPLAY_MODE_COORDINATION = 4<br>} | Enumerates the display modes of a foldable device.| 
| [NativeDisplayManager_DisplayState](#nativedisplaymanager_displaystate-1) {<br>DISPLAY_MANAGER_DISPLAY_STATE_UNKNOWN = 0, DISPLAY_MANAGER_DISPLAY_STATE_OFF = 1, DISPLAY_MANAGER_DISPLAY_STATE_ON = 2, DISPLAY_MANAGER_DISPLAY_STATE_DOZE = 3,<br>DISPLAY_MANAGER_DISPLAY_STATE_DOZE_SUSPEND = 4, DISPLAY_MANAGER_DISPLAY_STATE_VR = 5, DISPLAY_MANAGER_DISPLAY_STATE_ON_SUSPEND = 6<br>} | Enumerates the states of a display.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CaptureScreenPixelmap](#oh_nativedisplaymanager_capturescreenpixelmap) (uint32_t displayId, OH_PixelmapNative \*\*pixelMap) | Takes a screenshot of the entire screen. This function can be used only on tablets and 2-in-1 devices. It can be used to capture a full-screen screenshot on the specified display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayId](#oh_nativedisplaymanager_getdefaultdisplayid) (uint64_t \*displayId) | Obtains the ID of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayWidth](#oh_nativedisplaymanager_getdefaultdisplaywidth) (int32_t \*displayWidth) | Obtains the width of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayHeight](#oh_nativedisplaymanager_getdefaultdisplayheight) (int32_t \*displayHeight) | Obtains the height of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRotation](#oh_nativedisplaymanager_getdefaultdisplayrotation) ([NativeDisplayManager_Rotation](#nativedisplaymanager_rotation) \*displayRotation) | Obtains the clockwise rotation angle of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayOrientation](#oh_nativedisplaymanager_getdefaultdisplayorientation) ([NativeDisplayManager_Orientation](#nativedisplaymanager_orientation) \*displayOrientation) | Obtains the orientation of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio](#oh_nativedisplaymanager_getdefaultdisplayvirtualpixelratio) (float \*virtualPixels) | Obtains the virtual pixel ratio of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRefreshRate](#oh_nativedisplaymanager_getdefaultdisplayrefreshrate) (uint32_t \*refreshRate) | Obtains the refresh rate of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityDpi](#oh_nativedisplaymanager_getdefaultdisplaydensitydpi) (int32_t \*densityDpi) | Obtains the physical pixel density of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityPixels](#oh_nativedisplaymanager_getdefaultdisplaydensitypixels) (float \*densityPixels) | Obtains the logical pixel density of the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayScaledDensity](#oh_nativedisplaymanager_getdefaultdisplayscaleddensity) (float \*scaledDensity) | Obtains the scale factor of fonts displayed on the default display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi](#oh_nativedisplaymanager_getdefaultdisplaydensityxdpi) (float \*xDpi) | Obtains the number of physical pixels per inch on the default display in the X dimension.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi](#oh_nativedisplaymanager_getdefaultdisplaydensityydpi) (float \*yDpi) | Obtains the number of physical pixels per inch on the default display in the Y dimension.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo](#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*\*cutoutInfo) | Obtains the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo](#oh_nativedisplaymanager_destroydefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*cutoutInfo) | Destroys the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.| 
| bool [OH_NativeDisplayManager_IsFoldable](#oh_nativedisplaymanager_isfoldable) () | Checks whether the current device is foldable.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetFoldDisplayMode](#oh_nativedisplaymanager_getfolddisplaymode) ([NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode) \*displayMode) | Obtains the display mode of the foldable device.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterDisplayChangeListener](#oh_nativedisplaymanager_registerdisplaychangelistener) ([OH_NativeDisplayManager_DisplayChangeCallback](#oh_nativedisplaymanager_displaychangecallback) displayChangeCallback, uint32_t \*listenerIndex) | Registers a listener for status changes (such as rotation, refresh rate, DPI, and resolution changes) of the display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterDisplayChangeListener](#oh_nativedisplaymanager_unregisterdisplaychangelistener) (uint32_t listenerIndex) | Cancels the listening for status changes of the display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_registerfolddisplaymodechangelistener) ([OH_NativeDisplayManager_FoldDisplayModeChangeCallback](#oh_nativedisplaymanager_folddisplaymodechangecallback) displayModeChangeCallback, uint32_t \*listenerIndex) | Registers a listener for folded/unfolded state changes of the display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener) (uint32_t listenerIndex) | Cancels the listening for folded/unfolded state changes of the display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateAllDisplays](#oh_nativedisplaymanager_createalldisplays) ([NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) \*\*allDisplays) | Obtains the object that contains the information about all displays.| 
| void [OH_NativeDisplayManager_DestroyAllDisplays](#oh_nativedisplaymanager_destroyalldisplays) ([NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md) \*allDisplays) | Destroys the object that contains the information about all displays.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateDisplayById](#oh_nativedisplaymanager_createdisplaybyid) (uint32_t displayId, [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) \*\*displayInfo) | Obtains the object that contains the information about a display.| 
| void [OH_NativeDisplayManager_DestroyDisplay](#oh_nativedisplaymanager_destroydisplay) ([NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) \*displayInfo) | Destroys the object that contains the information about a display.| 
| [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreatePrimaryDisplay](#oh_nativedisplaymanager_createprimarydisplay) ([NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md) \*\*displayInfo) | Obtains the object that contains the information about the primary display. For devices other than 2-in-1 devices, the displayInfo object obtained contains information about the built-in screen. For 2-in-1 devices with an external screen, the displayInfo object obtained contains information about the current primary screen. For 2-in-1 devices without an external screen, the displayInfo object obtained contains information about the built-in screen.| 


## Type Description

### NativeDisplayManager_DisplayColorSpace

```
typedef struct NativeDisplayManager_DisplayColorSpace NativeDisplayManager_DisplayColorSpace
```

**Description**

Defines a struct for all the color spaces supported by a display.

**Since**: 14


### NativeDisplayManager_DisplayHdrFormat

```
typedef struct NativeDisplayManager_DisplayHdrFormat NativeDisplayManager_DisplayHdrFormat
```

**Description**

Defines a struct for all the HDR formats supported by a display.

**Since**: 14


### NativeDisplayManager_DisplayInfo

```
typedef struct NativeDisplayManager_DisplayInfo NativeDisplayManager_DisplayInfo
```

**Description**

Defines a struct that encapsulates the information about a display.

**Since**: 14


### NativeDisplayManager_DisplaysInfo

```
typedef struct NativeDisplayManager_DisplaysInfo NativeDisplayManager_DisplaysInfo
```

**Description**

Defines a struct that encapsulates the information about displays of a device with multiple screens.

**Since**: 14


### NativeDisplayManager_DisplayState

```
typedef enum NativeDisplayManager_DisplayState NativeDisplayManager_DisplayState
```

**Description**

Defines an enum for the states of a display.

**Since**: 14

### NativeDisplayManager_CutoutInfo

```
typedef struct NativeDisplayManager_CutoutInfo NativeDisplayManager_CutoutInfo
```

**Description**

Defines a struct for the unusable area of a display, including punch hole, notch, and curved area of a waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


### NativeDisplayManager_ErrorCode

```
typedef enum NativeDisplayManager_ErrorCode NativeDisplayManager_ErrorCode
```

**Description**

Defines an enum for the status codes returned by the display manager interface.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


### NativeDisplayManager_FoldDisplayMode

```
typedef enum NativeDisplayManager_FoldDisplayMode NativeDisplayManager_FoldDisplayMode
```

**Description**

Defines an enum for the display modes of a foldable device.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


### NativeDisplayManager_Orientation

```
typedef enum NativeDisplayManager_Orientation NativeDisplayManager_Orientation
```

**Description**

Defines an enum for the orientations of a display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


### NativeDisplayManager_Rect

```
typedef struct NativeDisplayManager_Rect NativeDisplayManager_Rect
```

**Description**

Defines a struct for a rectangle.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


### NativeDisplayManager_Rotation

```
typedef enum NativeDisplayManager_Rotation NativeDisplayManager_Rotation
```

**Description**

Defines an enum for the clockwise rotation angles of a display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


### NativeDisplayManager_WaterfallDisplayAreaRects

```
typedef struct NativeDisplayManager_WaterfallDisplayAreaRects NativeDisplayManager_WaterfallDisplayAreaRects
```

**Description**

Defines a struct for the curved area on a waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


### OH_NativeDisplayManager_DisplayChangeCallback

```
typedef void(* OH_NativeDisplayManager_DisplayChangeCallback) (uint64_t displayId)
```

**Description**

Defines a callback function to listen for status changes of a display.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayId | ID of the display.| 


### OH_NativeDisplayManager_FoldDisplayModeChangeCallback

```
typedef void(* OH_NativeDisplayManager_FoldDisplayModeChangeCallback) (NativeDisplayManager_FoldDisplayMode displayMode)
```

**Description**

Defines a callback function to listen for folded/unfolded state changes of a display.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayMode | Folded or unfolded state of the display. For details about the available options, see [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode).| 


## Enum Description

### NativeDisplayManager_DisplayState

```
enum NativeDisplayManager_DisplayState
```

**Description**

Enumerates the states of a display.

**Since**: 14

| Value| Description| 
| -------- | -------- |
| DISPLAY_MANAGER_DISPLAY_STATE_UNKNOWN | Unknown.| 
| DISPLAY_MANAGER_DISPLAY_STATE_OFF | The display is shut down.| 
| DISPLAY_MANAGER_DISPLAY_STATE_ON | The display is powered on.| 
| DISPLAY_MANAGER_DISPLAY_STATE_DOZE | The display is in sleep mode.| 
| DISPLAY_MANAGER_DISPLAY_STATE_DOZE_SUSPEND | The display is in sleep mode, and the CPU is suspended.| 
| DISPLAY_MANAGER_DISPLAY_STATE_VR | The display is in VR mode.| 
| DISPLAY_MANAGER_DISPLAY_STATE_ON_SUSPEND | The display is powered on, and the CPU is suspended.| 

### NativeDisplayManager_ErrorCode

```
enum NativeDisplayManager_ErrorCode
```

**Description**

Enumerates the status codes returned by the display manager interface.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DISPLAY_MANAGER_OK | The operation is successful.| 
| DISPLAY_MANAGER_ERROR_NO_PERMISSION | Permission verification failed. The application does not have the permission to use the API.| 
| DISPLAY_MANAGER_ERROR_NOT_SYSTEM_APP | Permission verification failed. A non-system application attempts to call a system API.| 
| DISPLAY_MANAGER_ERROR_INVALID_PARAM | Parameter check fails.| 
| DISPLAY_MANAGER_ERROR_DEVICE_NOT_SUPPORTED | The device does not support the API.| 
| DISPLAY_MANAGER_ERROR_INVALID_SCREEN | The display is invalid.| 
| DISPLAY_MANAGER_ERROR_INVALID_CALL | The current operation object does not have the operation permission.| 
| DISPLAY_MANAGER_ERROR_SYSTEM_ABNORMAL | The system service is abnormal.| 


### NativeDisplayManager_FoldDisplayMode

```
enum NativeDisplayManager_FoldDisplayMode
```

**Description**

Enumerates the display modes of a foldable device.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_UNKNOWN | The display mode of the device is unknown.| 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_FULL | The device is displayed in full screen.| 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_MAIN | The main screen of the device is displayed.| 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_SUB | The subscreen of the device is displayed.| 
| DISPLAY_MANAGER_FOLD_DISPLAY_MODE_COORDINATION | Both screens of the device are displayed in collaborative mode.| 


### NativeDisplayManager_Orientation

```
enum NativeDisplayManager_Orientation
```

**Description**

Enumerates the orientations of a display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DISPLAY_MANAGER_PORTRAIT | The display is in portrait mode.| 
| DISPLAY_MANAGER_LANDSCAPE | The display is in landscape mode.| 
| DISPLAY_MANAGER_PORTRAIT_INVERTED | The display is in reverse portrait mode.| 
| DISPLAY_MANAGER_LANDSCAPE_INVERTED | The display is in reverse landscape mode.| 
| DISPLAY_MANAGER_UNKNOWN | The screen orientation is unknown.| 


### NativeDisplayManager_Rotation

```
enum NativeDisplayManager_Rotation
```

**Description**

Enumerates the clockwise rotation angles of a display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| DISPLAY_MANAGER_ROTATION_0 | The display is rotated clockwise by 0 degrees.| 
| DISPLAY_MANAGER_ROTATION_90 | The display is rotated clockwise by 90 degrees.| 
| DISPLAY_MANAGER_ROTATION_180 | The display is rotated clockwise by 180 degrees.| 
| DISPLAY_MANAGER_ROTATION_270 | The display is rotated clockwise by 270 degrees.| 


## Function Description


### OH_NativeDisplayManager_CaptureScreenPixelmap()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CaptureScreenPixelmap (uint32_t displayId, OH_PixelmapNative **pixelMap )
```

**Description**

Takes a screenshot of the entire screen. This function can be used only on tablets and 2-in-1 devices. It can be used to capture a full-screen screenshot on the specified display.

**Required permissions**

ohos.permission.CUSTOM_SCREEN_CAPTURE

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayId | ID of the display. The value must be a non-negative integer.| 
| pixelMap | Double pointer to an **OH_PixelmapNative** object, which is the screenshot taken.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_CreateAllDisplays()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateAllDisplays (NativeDisplayManager_DisplaysInfo **allDisplays)
```

**Description**

Obtains the object that contains the information about all displays.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| allDisplays | Double pointer to the display information, which is encapsulated in [NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_CreateDisplayById()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDisplayById (uint32_t displayId, NativeDisplayManager_DisplayInfo **displayInfo )
```

**Description**

Obtains the object that contains the information about a display.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayId | ID of the display. The value must be a non-negative integer.| 
| displayInfo | Double pointer to the display information, which is encapsulated in [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_CreatePrimaryDisplay()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreatePrimaryDisplay (NativeDisplayManager_DisplayInfo **displayInfo)
```

**Description**

Obtains the object that contains the information about the primary display. For devices other than 2-in-1 devices, the displayInfo object obtained contains information about the built-in screen. For 2-in-1 devices with an external screen, the displayInfo object obtained contains information about the current primary screen. For 2-in-1 devices without an external screen, the displayInfo object obtained contains information about the built-in screen.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayInfo | Double pointer to the display information, which is encapsulated in [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_DestroyAllDisplays()

```
void OH_NativeDisplayManager_DestroyAllDisplays (NativeDisplayManager_DisplaysInfo *allDisplays)
```

**Description**

Destroys the object that contains the information about all displays.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| allDisplays | Pointer to the display information object, which is obtained by calling [OH_NativeDisplayManager_CreateAllDisplays](#oh_nativedisplaymanager_createalldisplays). For details, see [NativeDisplayManager_DisplaysInfo](_native_display_manager___displays_info.md).| 


### OH_NativeDisplayManager_DestroyDisplay()

```
void OH_NativeDisplayManager_DestroyDisplay (NativeDisplayManager_DisplayInfo *displayInfo)
```

**Description**

Destroys the object that contains the information about a display.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayInfo | Pointer to the display information object, which is obtained by calling [OH_NativeDisplayManager_CreateDisplayById](#oh_nativedisplaymanager_createdisplaybyid) or [OH_NativeDisplayManager_CreatePrimaryDisplay](#oh_nativedisplaymanager_createprimarydisplay). For details, see [NativeDisplayManager_DisplayInfo](_native_display_manager___display_info.md).| 

### OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo (NativeDisplayManager_CutoutInfo **cutoutInfo)
```

**Description**

Obtains the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cutoutInfo | Double pointer to the unusable area information, which is encapsulated in [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo (NativeDisplayManager_CutoutInfo *cutoutInfo)
```

**Description**

Destroys the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| cutoutInfo | Pointer to the unusable area information object, which is obtained by calling [OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo](#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo). For details, see [NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayDensityDpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityDpi (int32_t *densityDpi)
```

**Description**

Obtains the physical pixel density of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| densityDpi | Pointer to the physical pixel density, that is, the number of pixels per inch. The value is an integer, in px. The actual value depends on the options provided in device settings.  | 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayDensityPixels()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityPixels (float *densityPixels)
```

**Description**

Obtains the logical pixel density of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| densityPixels | Pointer to the logical pixel density, which indicates the scaling coefficient of the physical pixels and logical pixels. The value is a floating point number in the range [0.5, 4.0]. Generally, the value is **1.0** or **3.0**. The actual value depends on the density DPI provided by the device in use.  | 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi (float *xDpi)
```

**Description**

Obtains the number of physical pixels per inch on the default display in the X dimension.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| xDpi | Pointer to the number of physical pixels per inch in the X dimension. The value is a floating point number.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi (float *yDpi)
```

**Description**

Obtains the number of physical pixels per inch on the default display in the Y dimension.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| yDpi | Pointer to the number of physical pixels per inch in the Y dimension. The value is a floating point number.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayHeight()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayHeight (int32_t *displayHeight)
```

**Description**

Obtains the height of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayHeight | Pointer to the height, in px. The value is an integer.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayId()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayId (uint64_t *displayId)
```

**Description**

Obtains the ID of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayId | Pointer to the display ID. The value is a non-negative integer.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayOrientation()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayOrientation (NativeDisplayManager_Orientation *displayOrientation)
```

**Description**

Obtains the orientation of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayOrientation | Pointer to the orientation. For details about the available options, see [NativeDisplayManager_Orientation](#nativedisplaymanager_orientation).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayRefreshRate()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRefreshRate (uint32_t *refreshRate)
```

**Description**

Obtains the refresh rate of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| refreshRate | Pointer to the refresh rate. The value is an integer, in Hz.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayRotation()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRotation (NativeDisplayManager_Rotation *displayRotation)
```

**Description**

Obtains the clockwise rotation angle of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayRotation | Pointer to the clockwise rotation angle. For details about the available options, see [NativeDisplayManager_Rotation](#nativedisplaymanager_rotation).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayScaledDensity()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayScaledDensity (float *scaledDensity)
```

**Description**

Obtains the scale factor of fonts displayed on the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| scaledDensity | Pointer to the scale factor. The value is a floating-point number, and it is usually the same as that of **densityPixels**.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio (float *virtualPixels)
```

**Description**

Obtains the virtual pixel ratio of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| virtualPixels | Pointer to the virtual pixel ratio. The value is a floating-point number, and it is usually the same as that of **densityPixels**.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetDefaultDisplayWidth()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayWidth (int32_t *displayWidth)
```

**Description**

Obtains the width of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayWidth | Pointer to the width, in px. The value is an integer.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_GetFoldDisplayMode()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetFoldDisplayMode (NativeDisplayManager_FoldDisplayMode *displayMode)
```

**Description**

Obtains the display mode of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayMode | Pointer to the display mode. For details about the available options, see [NativeDisplayManager_FoldDisplayMode](#nativedisplaymanager_folddisplaymode).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_IsFoldable()

```
bool OH_NativeDisplayManager_IsFoldable ()
```

**Description**

Checks whether the current device is foldable.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Returns**

Returns the check result. The value **true** means that the device is foldable, and **false** means the opposite.


### OH_NativeDisplayManager_RegisterDisplayChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayChangeListener (OH_NativeDisplayManager_DisplayChangeCallback displayChangeCallback, uint32_t *listenerIndex )
```

**Description**

Registers a listener for status changes (such as rotation, refresh rate, DPI, and resolution changes) of the display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayChangeCallback | Callback function triggered when the display status is changed. For details, see [OH_NativeDisplayManager_DisplayChangeCallback](#oh_nativedisplaymanager_displaychangecallback).| 
| listenerIndex | Pointer to the index of the listener registered. It can be used as an input parameter of [OH_NativeDisplayManager_UnregisterDisplayChangeListener](#oh_nativedisplaymanager_unregisterdisplaychangelistener).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener (OH_NativeDisplayManager_FoldDisplayModeChangeCallback displayModeChangeCallback, uint32_t *listenerIndex )
```

**Description**

Registers a listener for folded/unfolded state changes of the display.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| displayModeChangeCallback | Callback function triggered when the folded/unfolded state of the display is changed. For details, see [OH_NativeDisplayManager_FoldDisplayModeChangeCallback](#oh_nativedisplaymanager_folddisplaymodechangecallback).| 
| listenerIndex | Pointer to the index of the listener registered. It can be used as an input parameter of [OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener).| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_UnregisterDisplayChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayChangeListener (uint32_t listenerIndex)
```

**Description**

Cancels the listening for status changes of the display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| listenerIndex | Index of the listener returned when [OH_NativeDisplayManager_RegisterDisplayChangeListener](#oh_nativedisplaymanager_registerdisplaychangelistener) is called.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).


### OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener (uint32_t listenerIndex)
```

**Description**

Cancels the listening for folded/unfolded state changes of the display.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| listenerIndex | Index of the listener returned when [OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener](#oh_nativedisplaymanager_registerfolddisplaymodechangelistener) is called.| 

**Returns**

Returns a status code defined in [NativeDisplayManager_ErrorCode](#nativedisplaymanager_errorcode).
