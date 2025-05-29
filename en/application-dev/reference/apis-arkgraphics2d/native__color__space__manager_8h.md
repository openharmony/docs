# native_color_space_manager.h


## Overview

The **native_color_space_manager.h** file declares the functions for creating and using a color space.

**File to include**: &lt;native_color_space_manager/native_color_space_manager.h&gt;

**Library**: libnative_color_space_manager.so

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Related module**: [NativeColorSpaceManager](_native_color_space_manager.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [ColorSpacePrimaries](_color_space_primaries.md) | Describes the color space primaries.| 
| struct  [WhitePointArray](_white_point_array.md) | Describes a white point array. Each white point indicates the coordinates of white in the active color space.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) | Provides the declaration of an **OH_NativeColorSpaceManager** struct.| 
| typedef enum [ColorSpaceName](_native_color_space_manager.md#colorspacename) [ColorSpaceName](_native_color_space_manager.md#colorspacename) | Defines an enum for the color space names.| 
| typedef struct [ColorSpacePrimaries](_color_space_primaries.md) [ColorSpacePrimaries](_native_color_space_manager.md#colorspaceprimaries) | Provides the declaration of a **ColorSpacePrimaries** struct.| 
| typedef struct [WhitePointArray](_white_point_array.md) [WhitePointArray](_native_color_space_manager.md#whitepointarray) | Defines a struct for a white point array. Each white point indicates the coordinates of white in the active color space.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ColorSpaceName](_native_color_space_manager.md#colorspacename) {<br>NONE = 0, ADOBE_RGB = 1, DCI_P3 = 2, DISPLAY_P3 = 3,<br>SRGB = 4, BT709 = 6, BT601_EBU = 7, BT601_SMPTE_C = 8,<br>BT2020_HLG = 9, BT2020_PQ = 10, P3_HLG = 11, P3_PQ = 12,<br>ADOBE_RGB_LIMIT = 13, DISPLAY_P3_LIMIT = 14, SRGB_LIMIT = 15, BT709_LIMIT = 16,<br>BT601_EBU_LIMIT = 17, BT601_SMPTE_C_LIMIT = 18, BT2020_HLG_LIMIT = 19, BT2020_PQ_LIMIT = 20,<br>P3_HLG_LIMIT = 21, P3_PQ_LIMIT = 22, LINEAR_P3 = 23, LINEAR_SRGB = 24,<br>LINEAR_BT709 = LINEAR_SRGB, LINEAR_BT2020 = 25, DISPLAY_SRGB = SRGB, DISPLAY_P3_SRGB = DISPLAY_P3,<br>DISPLAY_P3_HLG = P3_HLG, DISPLAY_P3_PQ = P3_PQ, CUSTOM = 5<br>} | Enumerates the color space names.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromName](_native_color_space_manager.md#oh_nativecolorspacemanager_createfromname) ([ColorSpaceName](_native_color_space_manager.md#colorspacename) colorSpaceName) | Creates an **OH_NativeColorSpaceManager** instance based on a color space name. A new **OH_NativeColorSpaceManager** instance is created each time this function is called.| 
| [OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma](_native_color_space_manager.md#oh_nativecolorspacemanager_createfromprimariesandgamma) ([ColorSpacePrimaries](_color_space_primaries.md) primaries, float gamma) | Creates an **OH_NativeColorSpaceManager** instance based on the color primaries and gamma value. A new **OH_NativeColorSpaceManager** instance is created each time this function is called.| 
| void [OH_NativeColorSpaceManager_Destroy](_native_color_space_manager.md#oh_nativecolorspacemanager_destroy) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Destroys an **OH_NativeColorSpaceManager** instance.| 
| int [OH_NativeColorSpaceManager_GetColorSpaceName](_native_color_space_manager.md#oh_nativecolorspacemanager_getcolorspacename) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Obtains the color space name.| 
| [WhitePointArray](_white_point_array.md)[OH_NativeColorSpaceManager_GetWhitePoint](_native_color_space_manager.md#oh_nativecolorspacemanager_getwhitepoint) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Obtains the white points.| 
| float [OH_NativeColorSpaceManager_GetGamma](_native_color_space_manager.md#oh_nativecolorspacemanager_getgamma) ([OH_NativeColorSpaceManager](_native_color_space_manager.md#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Obtains the gamma value.| 
