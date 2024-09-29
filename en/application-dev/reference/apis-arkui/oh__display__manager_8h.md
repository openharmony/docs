# oh_display_manager.h


## Overview

The **oh_display_manager.h** file declares the functions for basic display management. You can call the functions to obtain various information about the default display and listen for display status changes, such as rotation, folding, and unfolding.

**File to include**: &lt;window_manager/oh_display_manager.h&gt;

**Library**: libnative_display_manager.so

**System capability**: SystemCapability.WindowManager.WindowManager.Core

**Since**: 12

**Related module**: [OH_DisplayManager](_o_h___display_manager.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef void(\* [OH_NativeDisplayManager_DisplayChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_displaychangecallback)) (uint64_t displayId) | Defines a callback function used to listen for status changes of a display.| 
| typedef void(\* [OH_NativeDisplayManager_FoldDisplayModeChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_folddisplaymodechangecallback)) ([NativeDisplayManager_FoldDisplayMode](_o_h___display_manager.md#nativedisplaymanager_folddisplaymode) displayMode) | Defines a callback function used to listen for folded/unfolded state changes of a display.| 


### Callback

| Name| Description| 
| -------- | -------- |
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayId](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayid) (uint64_t \*displayId) | Obtains the ID of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayWidth](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaywidth) (int32_t \*displayWidth) | Obtains the width of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayHeight](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayheight) (int32_t \*displayHeight) | Obtains the height of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRotation](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayrotation) ([NativeDisplayManager_Rotation](_o_h___display_manager.md#nativedisplaymanager_rotation) \*displayRotation) | Obtains the clockwise rotation angle of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayOrientation](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayorientation) ([NativeDisplayManager_Orientation](_o_h___display_manager.md#nativedisplaymanager_orientation) \*displayOrientation) | Obtains the orientation of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayVirtualPixelRatio](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayvirtualpixelratio) (float \*virtualPixels) | Obtains the virtual pixel ratio of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayRefreshRate](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayrefreshrate) (uint32_t \*refreshRate) | Obtains the refresh rate of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityDpi](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensitydpi) (int32_t \*densityDpi) | Obtains the physical pixel density of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityPixels](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensitypixels) (float \*densityPixels) | Obtains the logical pixel density of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayScaledDensity](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplayscaleddensity) (float \*scaledDensity) | Obtains the scale factor of the font displayed on the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityXdpi](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensityxdpi) (float \*xDpi) | Obtains the number of physical pixels that are displayed horizontally per inch on the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetDefaultDisplayDensityYdpi](_o_h___display_manager.md#oh_nativedisplaymanager_getdefaultdisplaydensityydpi) (float \*yDpi) | Obtains the number of physical pixels that are displayed vertically per inch on the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_CreateDefaultDisplayCutoutInfo](_o_h___display_manager.md#oh_nativedisplaymanager_createdefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*\*cutoutInfo) | Obtains the cutout information of the default display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_DestroyDefaultDisplayCutoutInfo](_o_h___display_manager.md#oh_nativedisplaymanager_destroydefaultdisplaycutoutinfo) ([NativeDisplayManager_CutoutInfo](_native_display_manager___cutout_info.md) \*cutoutInfo) | Destroys the cutout information of the default display.| 
| bool [OH_NativeDisplayManager_IsFoldable](_o_h___display_manager.md#oh_nativedisplaymanager_isfoldable) () | Checks whether the device is foldable.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_GetFoldDisplayMode](_o_h___display_manager.md#oh_nativedisplaymanager_getfolddisplaymode) ([NativeDisplayManager_FoldDisplayMode](_o_h___display_manager.md#nativedisplaymanager_folddisplaymode) \*displayMode) | Obtains the display mode of the foldable device.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterDisplayChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_registerdisplaychangelistener) ([OH_NativeDisplayManager_DisplayChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_displaychangecallback) displayChangeCallback, uint32_t \*listenerIndex) | Registers a listener for status changes (such as rotation, refresh rate, DPI, and resolution changes) of the display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterDisplayChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_unregisterdisplaychangelistener) (uint32_t listenerIndex) | Cancels the listening for status changes of the display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_RegisterFoldDisplayModeChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_registerfolddisplaymodechangelistener) ([OH_NativeDisplayManager_FoldDisplayModeChangeCallback](_o_h___display_manager.md#oh_nativedisplaymanager_folddisplaymodechangecallback) displayModeChangeCallback, uint32_t \*listenerIndex) | Registers a listener for folded/unfolded state changes of the display.| 
| [NativeDisplayManager_ErrorCode](_o_h___display_manager.md#nativedisplaymanager_errorcode) [OH_NativeDisplayManager_UnregisterFoldDisplayModeChangeListener](_o_h___display_manager.md#oh_nativedisplaymanager_unregisterfolddisplaymodechangelistener) (uint32_t listenerIndex) | Cancels the listening for folded/unfolded state changes of the display.| 
