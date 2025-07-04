# oh_display_manager.h

## Overview

The **oh_display_manager.h** file declares the functions for basic display management. You can call the functions to obtain various information about the default display and listen for display status changes, such as rotation, folding, and unfolding.

**File to include**: <window_manager/oh_display_manager.h>

**Library**: libnative_display_manager.so

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Related module**: [OH_DisplayManager](capi-oh-displaymanager.md)

## Summary

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayId(uint64_t *displayId)](#oh_nativedisplaymanager_getdefaultdisplayid) | - | Obtains the ID of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayWidth(int32_t *displayWidth)](#oh_nativedisplaymanager_getdefaultdisplaywidth) | - | Obtains the width of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayHeight(int32_t *displayHeight)](#oh_nativedisplaymanager_getdefaultdisplayheight) | - | Obtains the height of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRotation(NativeDisplayManager_Rotation *displayRotation)](#oh_nativedisplaymanager_getdefaultdisplayrotation) | - | Obtains the clockwise rotation angle of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayOrientation(NativeDisplayManager_Orientation *displayOrientation)](#oh_nativedisplaymanager_getdefaultdisplayorientation) | - | Obtains the orientation of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio(float *virtualPixels)](#oh_nativedisplaymanager_getdefaultdisplayvirtualpixelratio) | - | Obtains the virtual pixel ratio of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRefreshRate(uint32_t *refreshRate)](#oh_nativedisplaymanager_getdefaultdisplayrefreshrate) | - | Obtains the refresh rate of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityDpi(int32_t *densityDpi)](#oh_nativedisplaymanager_getdefaultdisplaydensitydpi) | - | Obtains the physical pixel density of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityPixels(float *densityPixels)](#oh_nativedisplaymanager_getdefaultdisplaydensitypixels) | - | Obtains the logical pixel density of the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayScaledDensity(float *scaledDensity)](#oh_nativedisplaymanager_getdefaultdisplayscaleddensity) | - | Obtains the scale factor of fonts displayed on the default display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi(float *xDpi)](#oh_nativedisplaymanager_getdefaultdisplaydensityxdpi) | - | Obtains the number of physical pixels per inch on the default display in the X dimension.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi(float *yDpi)](#oh_nativedisplaymanager_getdefaultdisplaydensityydpi) | - | Obtains the number of physical pixels per inch on the default display in the Y dimension.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo **cutoutInfo)](#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo) | - | Obtains the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo *cutoutInfo)](#oh_nativedisplaymanager_destroydefaultdisplaycutoutinfo) | - | Destroys the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.|
| [bool OH_NativeDisplayManager_IsFoldable()](#oh_nativedisplaymanager_isfoldable) | - | Checks whether the current device is foldable.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetFoldDisplayMode(NativeDisplayManager_FoldDisplayMode *displayMode)](#oh_nativedisplaymanager_getfolddisplaymode) | - | Obtains the display mode of the foldable device.|
| [typedef void (\*OH_NativeDisplayManager_DisplayChangeCallback)(uint64_t displayId)](#oh_nativedisplaymanager_displaychangecallback) | OH_NativeDisplayManager_DisplayChangeCallback | Defines a callback function to listen for display status changes.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayChangeListener(OH_NativeDisplayManager_DisplayChangeCallback displayChangeCallback, uint32_t *listenerIndex)](#oh_nativedisplaymanager_registerdisplaychangelistener) | - | Registers a listener for display status changes (such as rotation, refresh rate, DPI, and resolution changes).|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayChangeListener(uint32_t listenerIndex)](#oh_nativedisplaymanager_unregisterdisplaychangelistener) | - | Unregisters a listener for display status changes.|
| [typedef void (\*OH_NativeDisplayManager_FoldDisplayModeChangeCallback)(NativeDisplayManager_FoldDisplayMode displayMode)](#oh_nativedisplaymanager_folddisplaymodechangecallback) | OH_NativeDisplayManager_FoldDisplayModeChangeCallback | Defines a callback function to listen for folded/unfolded state changes of the display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener(OH_NativeDisplayManager_FoldDisplayModeChangeCallback displayModeChangeCallback, uint32_t *listenerIndex)](#oh_nativedisplaymanager_registerfolddisplaymodechangelistener) | - | Registers a listener for folded/unfolded state changes of the display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener(uint32_t listenerIndex)](#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener) | - | Unregisters a listener for folded/unfolded state changes of the display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateAllDisplays(NativeDisplayManager_DisplaysInfo **allDisplays)](#oh_nativedisplaymanager_createalldisplays) | - | Obtains the object that contains the information about all displays.|
| [void OH_NativeDisplayManager_DestroyAllDisplays(NativeDisplayManager_DisplaysInfo *allDisplays)](#oh_nativedisplaymanager_destroyalldisplays) | - | Destroys the object that contains the information about all displays.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDisplayById(uint32_t displayId,NativeDisplayManager_DisplayInfo **displayInfo)](#oh_nativedisplaymanager_createdisplaybyid) | - | Obtains the object that contains the information about a display.|
| [void OH_NativeDisplayManager_DestroyDisplay(NativeDisplayManager_DisplayInfo *displayInfo)](#oh_nativedisplaymanager_destroydisplay) | - | Destroys the object that contains the information about a display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreatePrimaryDisplay(NativeDisplayManager_DisplayInfo **displayInfo)](#oh_nativedisplaymanager_createprimarydisplay) | - | Obtains the object that contains the information about the primary display. For devices other than 2-in-1 devices, the displayInfo object obtained contains information about the built-in screen. For 2-in-1 devices with an external screen, the displayInfo object obtained contains information about the current primary screen. For 2-in-1 devices without an external screen, the displayInfo object obtained contains information about the built-in screen.|
| [typedef void (\*OH_NativeDisplayManager_AvailableAreaChangeCallback)(uint64_t displayId)](#oh_nativedisplaymanager_availableareachangecallback) | OH_NativeDisplayManager_AvailableAreaChangeCallback | Defines a callback function to listen for available area changes of a display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterAvailableAreaChangeListener(OH_NativeDisplayManager_AvailableAreaChangeCallback availableAreaChangeCallback, uint32_t *listenerIndex)](#oh_nativedisplaymanager_registeravailableareachangelistener) | - | Registers a listener for available area changes of the display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterAvailableAreaChangeListener(uint32_t listenerIndex)](#oh_nativedisplaymanager_unregisteravailableareachangelistener) | - | Unregisters a listener for available area changes of the display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateAvailableArea(uint64_t displayId, NativeDisplayManager_Rect **availableArea)](#oh_nativedisplaymanager_createavailablearea) | - | Obtains the available area of a display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_DestroyAvailableArea(NativeDisplayManager_Rect *availableArea)](#oh_nativedisplaymanager_destroyavailablearea) | - | Destroys the available area of a display.|
| [typedef void (\*OH_NativeDisplayManager_DisplayAddCallback)(uint64_t displayId)](#oh_nativedisplaymanager_displayaddcallback) | OH_NativeDisplayManager_DisplayAddCallback | Defines a callback function to listen for display addition events.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayAddListener(OH_NativeDisplayManager_DisplayAddCallback displayAddCallback, uint32_t *listenerIndex)](#oh_nativedisplaymanager_registerdisplayaddlistener) | - | Registers a listener for display addition events (for example, monitor inserted).|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayAddListener(uint32_t listenerIndex)](#oh_nativedisplaymanager_unregisterdisplayaddlistener) | - | Unregisters a listener for display addition events.|
| [typedef void (\*OH_NativeDisplayManager_DisplayRemoveCallback)(uint64_t displayId)](#oh_nativedisplaymanager_displayremovecallback) | OH_NativeDisplayManager_DisplayRemoveCallback | Defines a callback function to listen for display removal events.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayRemoveListener(OH_NativeDisplayManager_DisplayRemoveCallback displayRemoveCallback, uint32_t *listenerIndex)](#oh_nativedisplaymanager_registerdisplayremovelistener) | - | Registers a listener for display removal events (for example, monitor removed).|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayRemoveListener(uint32_t listenerIndex)](#oh_nativedisplaymanager_unregisterdisplayremovelistener) | - | Unregisters a listener for display removal events.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDisplaySourceMode(uint64_t displayId, NativeDisplayManager_SourceMode *sourceMode)](#oh_nativedisplaymanager_getdisplaysourcemode) | - | Obtains the source mode of a display.|
| [NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDisplayPosition(uint64_t displayId, int32_t *x, int32_t *y)](#oh_nativedisplaymanager_getdisplayposition) | - | Obtains the position of a display.|

## Function Description

### OH_NativeDisplayManager_GetDefaultDisplayId()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayId(uint64_t *displayId)
```

**Description**

Obtains the ID of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t *displayId | Pointer to the display ID. The value is a non-negative integer.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayWidth()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayWidth(int32_t *displayWidth)
```

**Description**

Obtains the width of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t *displayWidth | Pointer to the width, in px. The value is an integer.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayHeight()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayHeight(int32_t *displayHeight)
```

**Description**

Obtains the height of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t *displayHeight | Pointer to the height, in px. The value is an integer.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayRotation()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRotation(NativeDisplayManager_Rotation *displayRotation)
```

**Description**

Obtains the clockwise rotation angle of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_Rotation](capi-oh-display-info-h.md#nativedisplaymanager_rotation) *displayRotation | Pointer to the clockwise rotation angle. For details about the available options, see [NativeDisplayManager_Rotation](capi-oh-display-info-h.md#nativedisplaymanager_rotation).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayOrientation()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayOrientation(NativeDisplayManager_Orientation *displayOrientation)
```

**Description**

Obtains the orientation of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_Orientation](capi-oh-display-info-h.md#nativedisplaymanager_orientation) *displayOrientation | Pointer to the orientation. For details about the available options, see [NativeDisplayManager_Orientation](capi-oh-display-info-h.md#nativedisplaymanager_orientation).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio(float *virtualPixels)
```

**Description**

Obtains the virtual pixel ratio of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| float *virtualPixels | Pointer to the virtual pixel ratio. The value is a floating-point number, and it is usually the same as that of **densityPixels**.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayRefreshRate()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayRefreshRate(uint32_t *refreshRate)
```

**Description**

Obtains the refresh rate of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t *refreshRate | Pointer to the refresh rate. The value is an integer, in Hz.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayDensityDpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityDpi(int32_t *densityDpi)
```

**Description**

Obtains the physical pixel density of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| int32_t *densityDpi | Pointer to the physical pixel density, that is, the number of pixels per inch. The value is an integer, in px. The actual value depends on the options provided in device settings.  |

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayDensityPixels()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityPixels(float *densityPixels)
```

**Description**

Obtains the logical pixel density of the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| float *densityPixels | Pointer to the logical pixel density, which indicates the scaling coefficient of the physical pixels and logical pixels. The value is a floating point number in the range [0.5, 4.0]. Generally, the value is **1.0** or **3.0**. The actual value depends on the density DPI provided by the device in use.  |

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayScaledDensity()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayScaledDensity(float *scaledDensity)
```

**Description**

Obtains the scale factor of fonts displayed on the default display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| float *scaledDensity | Pointer to the scale factor. The value is a floating-point number, and it is usually the same as that of **densityPixels**.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi(float *xDpi)
```

**Description**

Obtains the number of physical pixels per inch on the default display in the X dimension.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| float *xDpi | Pointer to the number of physical pixels per inch in the X dimension. The value is a floating point number.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi(float *yDpi)
```

**Description**

Obtains the number of physical pixels per inch on the default display in the Y dimension.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| float *yDpi | Pointer to the number of physical pixels per inch in the Y dimension. The value is a floating point number.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo **cutoutInfo)
```

**Description**

Obtains the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_CutoutInfo](capi-nativedisplaymanager-cutoutinfo.md) **cutoutInfo | Double pointer to the unusable area information, which is encapsulated in [NativeDisplayManager_CutoutInfo](capi-nativedisplaymanager-cutoutinfo.md).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo(NativeDisplayManager_CutoutInfo *cutoutInfo)
```

**Description**

Destroys the unusable area of the default display, including punch hole, notch, and curved area of a waterfall display.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_CutoutInfo](capi-nativedisplaymanager-cutoutinfo.md) *cutoutInfo | Pointer to the unusable area information object, which is obtained by calling [OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo](capi-oh-display-manager-h.md#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo). For details, see [NativeDisplayManager_CutoutInfo](capi-nativedisplaymanager-cutoutinfo.md).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_IsFoldable()

```
bool OH_NativeDisplayManager_IsFoldable()
```

**Description**

Checks whether the current device is foldable.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| bool | Check result. The value **true** means that the device is foldable, and **false** means the opposite.|

### OH_NativeDisplayManager_GetFoldDisplayMode()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetFoldDisplayMode(NativeDisplayManager_FoldDisplayMode *displayMode)
```

**Description**

Obtains the display mode of the foldable device.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_FoldDisplayMode](capi-oh-display-info-h.md#nativedisplaymanager_folddisplaymode) *displayMode | Pointer to the display mode. For details about the available options, see [NativeDisplayManager_FoldDisplayMode](capi-oh-display-info-h.md#nativedisplaymanager_folddisplaymode).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_DisplayChangeCallback()

```
typedef void (*OH_NativeDisplayManager_DisplayChangeCallback)(uint64_t displayId)
```

**Description**

Defines a callback function to listen for display status changes.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t displayId | ID of the display.|

### OH_NativeDisplayManager_RegisterDisplayChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayChangeListener(OH_NativeDisplayManager_DisplayChangeCallback displayChangeCallback, uint32_t *listenerIndex)
```

**Description**

Registers a listener for display status changes (such as rotation, refresh rate, DPI, and resolution changes).

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_NativeDisplayManager_DisplayChangeCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_displaychangecallback) displayChangeCallback | Callback function triggered when the display status is changed. For details, see [OH_NativeDisplayManager_DisplayChangeCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_displaychangecallback).|
| uint32_t *listenerIndex | Pointer to the index of the listener registered. It can be used as an input parameter of [OH_NativeDisplayManager_UnregisterDisplayChangeListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_unregisterdisplaychangelistener).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_UnregisterDisplayChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayChangeListener(uint32_t listenerIndex)
```

**Description**

Unregisters a listener for display status changes.

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t listenerIndex | Index of the listener returned when [OH_NativeDisplayManager_RegisterDisplayChangeListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_registerdisplaychangelistener) is called.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_FoldDisplayModeChangeCallback()

```
typedef void (*OH_NativeDisplayManager_FoldDisplayModeChangeCallback)(NativeDisplayManager_FoldDisplayMode displayMode)
```

**Description**

Defines a callback function to listen for folded/unfolded state changes of the display.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_FoldDisplayMode](capi-oh-display-info-h.md#nativedisplaymanager_folddisplaymode) displayMode | Folded or unfolded state of the display. For details about the available options, see [NativeDisplayManager_FoldDisplayMode](capi-oh-display-info-h.md#nativedisplaymanager_folddisplaymode).|

### OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener(OH_NativeDisplayManager_FoldDisplayModeChangeCallback displayModeChangeCallback, uint32_t *listenerIndex)
```

**Description**

Registers a listener for folded/unfolded state changes of the display.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_NativeDisplayManager_FoldDisplayModeChangeCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_folddisplaymodechangecallback) displayModeChangeCallback | Callback function triggered when the folded/unfolded state of the display is changed. For details, see [OH_NativeDisplayManager_FoldDisplayModeChangeCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_folddisplaymodechangecallback).|
| uint32_t *listenerIndex | Pointer to the index of the listener registered. It can be used as an input parameter of [OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener(uint32_t listenerIndex)
```

**Description**

Unregisters a listener for folded/unfolded state changes of the display.

**System capability**: SystemCapability.Window.SessionManager

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t listenerIndex | Index of the listener returned when [OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_registerfolddisplaymodechangelistener) is called.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_CreateAllDisplays()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateAllDisplays(NativeDisplayManager_DisplaysInfo **allDisplays)
```

**Description**

Obtains the object that contains the information about all displays.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_DisplaysInfo](capi-nativedisplaymanager-displaysinfo.md) **allDisplays | Double pointer to the display information, which is encapsulated in [NativeDisplayManager_DisplaysInfo](capi-nativedisplaymanager-displaysinfo.md).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_DestroyAllDisplays()

```
void OH_NativeDisplayManager_DestroyAllDisplays(NativeDisplayManager_DisplaysInfo *allDisplays)
```

**Description**

Destroys the object that contains the information about all displays.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_DisplaysInfo](capi-nativedisplaymanager-displaysinfo.md) *allDisplays | Pointer to the display information object, which is obtained by calling [OH_NativeDisplayManager_CreateAllDisplays](capi-oh-display-manager-h.md#oh_nativedisplaymanager_createalldisplays). For details, see [NativeDisplayManager_DisplaysInfo](capi-nativedisplaymanager-displaysinfo.md).|

### OH_NativeDisplayManager_CreateDisplayById()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateDisplayById(uint32_t displayId,NativeDisplayManager_DisplayInfo **displayInfo)
```

**Description**

Obtains the object that contains the information about a display.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t displayId | ID of the display. The value must be a non-negative integer.|
| [NativeDisplayManager_DisplayInfo](capi-nativedisplaymanager-displayinfo.md) **displayInfo | Double pointer to the display information, which is encapsulated in [NativeDisplayManager_DisplayInfo](capi-nativedisplaymanager-displayinfo.md).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_DestroyDisplay()

```
void OH_NativeDisplayManager_DestroyDisplay(NativeDisplayManager_DisplayInfo *displayInfo)
```

**Description**

Destroys the object that contains the information about a display.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_DisplayInfo](capi-nativedisplaymanager-displayinfo.md) *displayInfo | Pointer to the display information object, which is obtained by calling [OH_NativeDisplayManager_CreateDisplayById](capi-oh-display-manager-h.md#oh_nativedisplaymanager_createdisplaybyid) or [OH_NativeDisplayManager_CreatePrimaryDisplay](capi-oh-display-manager-h.md#oh_nativedisplaymanager_createprimarydisplay). For details, see [NativeDisplayManager_DisplayInfo](capi-nativedisplaymanager-displayinfo.md).|

### OH_NativeDisplayManager_CreatePrimaryDisplay()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreatePrimaryDisplay(NativeDisplayManager_DisplayInfo **displayInfo)
```

**Description**

Obtains the object that contains the information about the primary display. For devices other than 2-in-1 devices, the **displayInfo** object obtained contains information about the built-in screen. For 2-in-1 devices with an external screen, the displayInfo object obtained contains information about the current primary screen. For 2-in-1 devices without an external screen, the displayInfo object obtained contains information about the built-in screen.

**System capability**: SystemCapability.Window.SessionManager.Core

**Since**: 14


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_DisplayInfo](capi-nativedisplaymanager-displayinfo.md) **displayInfo | Double pointer to the display information, which is encapsulated in [NativeDisplayManager_DisplayInfo](capi-nativedisplaymanager-displayinfo.md).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_AvailableAreaChangeCallback()

```
typedef void (*OH_NativeDisplayManager_AvailableAreaChangeCallback)(uint64_t displayId)
```

**Description**

Defines a callback function to listen for available area changes of a display.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t displayId | Display ID, which is a non-negative integer.|

### OH_NativeDisplayManager_RegisterAvailableAreaChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterAvailableAreaChangeListener(OH_NativeDisplayManager_AvailableAreaChangeCallback availableAreaChangeCallback, uint32_t *listenerIndex)
```

**Description**

Registers a listener for available area changes of the display.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_NativeDisplayManager_AvailableAreaChangeCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_availableareachangecallback) availableAreaChangeCallback | Callback function triggered when the available area of the display changes.<br>For details, see [OH_NativeDisplayManager_AvailableAreaChangeCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_availableareachangecallback).|
| uint32_t *listenerIndex | Pointer to the index of the listener registered.<br>It can be used as an input parameter of [OH_NativeDisplayManager_UnregisterAvailableAreaChangeListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_unregisteravailableareachangelistener).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_UnregisterAvailableAreaChangeListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterAvailableAreaChangeListener(uint32_t listenerIndex)
```

**Description**

Unregisters a listener for available area changes of the display.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t listenerIndex | Index of the listener returned<br>when [OH_NativeDisplayManager_RegisterAvailableAreaChangeListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_registeravailableareachangelistener) is called.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_CreateAvailableArea()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_CreateAvailableArea(uint64_t displayId, NativeDisplayManager_Rect **availableArea)
```

**Description**

Obtains the available area of a display. This function can be used only on 2-in-1 devices.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t displayId | Display ID, which is a non-negative integer.|
| [NativeDisplayManager_Rect](capi-nativedisplaymanager-rect.md) **availableArea | Double pointer to the available area of the display. For details, see [NativeDisplayManager_Rect](capi-nativedisplaymanager-rect.md).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_DestroyAvailableArea()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_DestroyAvailableArea(NativeDisplayManager_Rect *availableArea)
```

**Description**

Destroys the available area of a display. This function can be used only on 2-in-1 devices.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [NativeDisplayManager_Rect](capi-nativedisplaymanager-rect.md) *availableArea | Pointer to the available area, which is obtained by calling [OH_NativeDisplayManager_CreateAvailableArea](capi-oh-display-manager-h.md#oh_nativedisplaymanager_createavailablearea).<br>For details about the available area, see [NativeDisplayManager_Rect](capi-nativedisplaymanager-rect.md).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_DisplayAddCallback()

```
typedef void (*OH_NativeDisplayManager_DisplayAddCallback)(uint64_t displayId)
```

**Description**

Defines a callback function to listen for display addition events.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t displayId | Display ID, which is a non-negative integer.|

### OH_NativeDisplayManager_RegisterDisplayAddListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayAddListener(OH_NativeDisplayManager_DisplayAddCallback displayAddCallback, uint32_t *listenerIndex)
```

**Description**

Registers a listener for display addition events (for example, monitor inserted).

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_NativeDisplayManager_DisplayAddCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_displayaddcallback) displayAddCallback | Callback function triggered when a display is added. For details, see [OH_NativeDisplayManager_DisplayAddCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_displayaddcallback).|
| uint32_t *listenerIndex | Pointer to the index of the listener registered.<br>It can be used as an input parameter of [OH_NativeDisplayManager_UnregisterDisplayAddListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_unregisterdisplayaddlistener).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_UnregisterDisplayAddListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayAddListener(uint32_t listenerIndex)
```

**Description**

Unregisters a listener for display addition events.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t listenerIndex | Index of the listener returned when [OH_NativeDisplayManager_RegisterDisplayAddListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_registerdisplayaddlistener) is called.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_DisplayRemoveCallback()

```
typedef void (*OH_NativeDisplayManager_DisplayRemoveCallback)(uint64_t displayId)
```

**Description**

Defines a callback function to listen for display removal events.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t displayId | Display ID, which is a non-negative integer.|

### OH_NativeDisplayManager_RegisterDisplayRemoveListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_RegisterDisplayRemoveListener(OH_NativeDisplayManager_DisplayRemoveCallback displayRemoveCallback, uint32_t *listenerIndex)
```

**Description**

Registers a listener for display removal events (for example, monitor removed).

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_NativeDisplayManager_DisplayRemoveCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_displayremovecallback) displayRemoveCallback | Callback function triggered when a display is removed. For details, see [OH_NativeDisplayManager_DisplayRemoveCallback](capi-oh-display-manager-h.md#oh_nativedisplaymanager_displayremovecallback).|
| uint32_t *listenerIndex | Pointer to the index of the listener registered.<br>It can be used as an input parameter of [OH_NativeDisplayManager_UnregisterDisplayRemoveListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_unregisterdisplayremovelistener).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_UnregisterDisplayRemoveListener()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_UnregisterDisplayRemoveListener(uint32_t listenerIndex)
```

**Description**

Unregisters the listener for display removal events.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint32_t listenerIndex | Index of the listener returned when [OH_NativeDisplayManager_RegisterDisplayRemoveListener](capi-oh-display-manager-h.md#oh_nativedisplaymanager_registerdisplayremovelistener) is called.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDisplaySourceMode()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDisplaySourceMode(uint64_t displayId, NativeDisplayManager_SourceMode *sourceMode)
```

**Description**

Obtains the source mode of a display.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t displayId | Display ID, which is a non-negative integer.|
| [NativeDisplayManager_SourceMode](capi-oh-display-info-h.md#nativedisplaymanager_sourcemode) *sourceMode | Pointer to the source mode. For details about the available options, see [NativeDisplayManager_SourceMode](capi-oh-display-info-h.md#nativedisplaymanager_sourcemode).|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).|

### OH_NativeDisplayManager_GetDisplayPosition()

```
NativeDisplayManager_ErrorCode OH_NativeDisplayManager_GetDisplayPosition(uint64_t displayId, int32_t *x, int32_t *y)
```

**Description**

Obtains the position of a display.

**Since**: 20


**Parameters**

| Parameter| Description|
| -- | -- |
| uint64_t displayId | Display ID, which is a non-negative integer.|
| int32_t *x | Pointer to the X coordinate of the upper left corner of the primary screen.|
| int32_t *y | Pointer to the Y coordinate of the upper left corner of the primary screen.|

**Return value**

| Type| Description|
| -- | -- |
| [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode) | Status code defined in [NativeDisplayManager_ErrorCode](capi-oh-display-info-h.md#nativedisplaymanager_errorcode).<br>Currently, only the primary screen and extended screen support position information query. Queries for other screens return **DISPLAY_MANAGER_ERROR_ILLEGAL_PARAM**.|
