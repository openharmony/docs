# NativeColorSpaceManager


## Overview

The module provides the capabilities for creating a color space and obtaining its properties.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_color_space_manager.h](native__color__space__manager_8h.md) | Declares the functions for creating and using a color space.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[ColorSpacePrimaries](_color_space_primaries.md) | Describes the color space primaries.| 
| struct&nbsp;&nbsp;[WhitePointArray](_white_point_array.md) | Describes a white point array. Each white point indicates the coordinates of white in the active color space.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) | Provides the declaration of an **OH_NativeColorSpaceManager** struct.| 
| typedef enum [ColorSpaceName](#colorspacename) [ColorSpaceName](#colorspacename) | Defines an enum for the color space names.| 
| typedef struct [ColorSpacePrimaries](_color_space_primaries.md) [ColorSpacePrimaries](#colorspaceprimaries) | Provides the declaration of a **ColorSpacePrimaries** struct.| 
| typedef struct [WhitePointArray](_white_point_array.md) [WhitePointArray](#whitepointarray) | Defines a struct for a white point array. Each white point indicates the coordinates of white in the active color space.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ColorSpaceName](#colorspacename) {<br>NONE = 0, ADOBE_RGB = 1, DCI_P3 = 2, DISPLAY_P3 = 3,<br>SRGB = 4, BT709 = 6, BT601_EBU = 7, BT601_SMPTE_C = 8,<br>BT2020_HLG = 9, BT2020_PQ = 10, P3_HLG = 11, P3_PQ = 12,<br>ADOBE_RGB_LIMIT = 13, DISPLAY_P3_LIMIT = 14, SRGB_LIMIT = 15, BT709_LIMIT = 16,<br>BT601_EBU_LIMIT = 17, BT601_SMPTE_C_LIMIT = 18, BT2020_HLG_LIMIT = 19, BT2020_PQ_LIMIT = 20,<br>P3_HLG_LIMIT = 21, P3_PQ_LIMIT = 22, LINEAR_P3 = 23, LINEAR_SRGB = 24,<br>LINEAR_BT709 = LINEAR_SRGB, LINEAR_BT2020 = 25, DISPLAY_SRGB = SRGB, DISPLAY_P3_SRGB = DISPLAY_P3,<br>DISPLAY_P3_HLG = P3_HLG, DISPLAY_P3_PQ = P3_PQ, CUSTOM = 5<br>} | Enumerates the color space names.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromName](#oh_nativecolorspacemanager_createfromname) ([ColorSpaceName](#colorspacename) colorSpaceName) | Creates an **OH_NativeColorSpaceManager** instance based on a color space name. A new **OH_NativeColorSpaceManager** instance is created each time this function is called.| 
| [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \* [OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma](#oh_nativecolorspacemanager_createfromprimariesandgamma) ([ColorSpacePrimaries](_color_space_primaries.md) primaries, float gamma) | Creates an **OH_NativeColorSpaceManager** instance based on the color primaries and gamma value. A new **OH_NativeColorSpaceManager** instance is created each time this function is called.| 
| void [OH_NativeColorSpaceManager_Destroy](#oh_nativecolorspacemanager_destroy) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Destroys an **OH_NativeColorSpaceManager** instance.| 
| int [OH_NativeColorSpaceManager_GetColorSpaceName](#oh_nativecolorspacemanager_getcolorspacename) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Obtains the color space name.| 
| [WhitePointArray](_white_point_array.md)[OH_NativeColorSpaceManager_GetWhitePoint](#oh_nativecolorspacemanager_getwhitepoint) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Obtains the white points.| 
| float [OH_NativeColorSpaceManager_GetGamma](#oh_nativecolorspacemanager_getgamma) ([OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*nativeColorSpaceManager) | Obtains the gamma value.| 


## Type Description


### ColorSpaceName

```
typedef enum ColorSpaceName ColorSpaceName
```

**Description**

Defines an enum for the color space names.

**Since**: 13


### ColorSpacePrimaries

```
typedef struct ColorSpacePrimaries ColorSpacePrimaries
```

**Description**

Provides the declaration of a **ColorSpacePrimaries** struct.

**Since**: 13


### OH_NativeColorSpaceManager

```
typedef struct OH_NativeColorSpaceManager OH_NativeColorSpaceManager
```

**Description**

Provides the declaration of an **OH_NativeColorSpaceManager** struct.

**Since**: 13


### WhitePointArray

```
typedef struct WhitePointArray WhitePointArray
```

**Description**

Defines a struct for a white point array. Each white point indicates the coordinates of white in the active color space.

**Since**: 13


## Enum Description


### ColorSpaceName

```
enum ColorSpaceName
```

**Description**

Enumerates the color space names.

**Since**: 13

| Value| Description| 
| -------- | -------- |
| NONE | Unknown color space.| 
| ADOBE_RGB | Color space based on Adobe RGB.| 
| DCI_P3 | Color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999.| 
| DISPLAY_P3 | Color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999.| 
| SRGB | Standard Red Green Blue (SRGB) color space based on IEC 61966-2.1:1999.| 
| BT709 | Color space based on ITU-R BT.709.| 
| BT601_EBU | Color space based on ITU-R BT.601.| 
| BT601_SMPTE_C | Color space based on ITU-R BT.601.| 
| BT2020_HLG | Color space based on ITU-R BT.2020.| 
| BT2020_PQ | Color space based on ITU-R BT.2020.| 
| P3_HLG | Color space with the color primaries of P3_D65, the transfer characteristics of Hybrid Log-Gamma (HLG), and the color range of FULL.| 
| P3_PQ | Color space with the color primaries of P3_D65, the transfer characteristics of Perceptual Quantizer (PQ), and the color range of FULL.| 
| ADOBE_RGB_LIMIT | Color space with the color primaries of ADOBE_RGB, the transfer characteristics of ADOBE_RGB, and the color range of LIMIT.| 
| DISPLAY_P3_LIMIT | Color space with the color primaries of P3_D65, the transfer characteristics of SRGB, and the color range of LIMIT.| 
| SRGB_LIMIT | Color space with the color primaries of SRGB, the transfer characteristics of SRGB, and the color range of LIMIT.| 
| BT709_LIMIT | Color space with the color primaries of BT.709, the transfer characteristics of BT.709, and the color range of LIMIT.| 
| BT601_EBU_LIMIT | Color space with the color primaries of BT.601_P, the transfer characteristics of BT.709, and the color range of LIMIT.| 
| BT601_SMPTE_C_LIMIT | Color space with the color primaries of BT.601_N, the transfer characteristics of BT.709, and the color range of LIMIT.| 
| BT2020_HLG_LIMIT | Color space with the color primaries of BT.2020, the transfer characteristics of HLG, and the color range of LIMIT.| 
| BT2020_PQ_LIMIT | Color space with the color primaries of BT.2020, the transfer characteristics of PQ, and the color range of LIMIT.| 
| P3_HLG_LIMIT | Color space with the color primaries of P3_D65, the transfer characteristics of HLG, and the color range of LIMIT.| 
| P3_PQ_LIMIT | Color space with the color primaries of P3_D65, the transfer characteristics of PQ, and the color range of LIMIT.| 
| LINEAR_P3 | Color space with the color primaries of P3_D65 and the transfer characteristic of LINEAR.| 
| LINEAR_SRGB | Color space with the color primaries of SRGB and the transfer characteristic of LINEAR.| 
| LINEAR_BT709 | Color space with the color primaries of BT.709 and the transfer characteristic of LINEAR.| 
| LINEAR_BT2020 | Color space with the color primaries of BT.2020 and the transfer characteristic of LINEAR.| 
| DISPLAY_SRGB | Color space with the color primaries of SRGB, the transfer characteristics of SRGB, and the color range of FULL.| 
| DISPLAY_P3_SRGB | Color space with the color primaries of P3_D65, the transfer characteristics of SRGB, and the color range of FULL.| 
| DISPLAY_P3_HLG | Color space with the color primaries of P3_D65, the transfer characteristics of Hybrid Log-Gamma (HLG), and the color range of FULL.| 
| DISPLAY_P3_PQ | Color space with the color primaries of P3_D65, the transfer characteristics of Perceptual Quantizer (PQ), and the color range of FULL.| 
| CUSTOM | Custom color space.| 


## Function Description


### OH_NativeColorSpaceManager_CreateFromName()

```
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromName (ColorSpaceName colorSpaceName)
```

**Description**

Creates an **OH_NativeColorSpaceManager** instance based on a color space name. A new **OH_NativeColorSpaceManager** instance is created each time this function is called.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| colorSpaceName | Name of the color space.| 

**Returns**

Returns the pointer to an **OH_NativeColorSpaceManager** instance If the memory is insufficient, the **OH_NativeColorSpaceManager** instance fails to be created.


### OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma()

```
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma (ColorSpacePrimaries primaries, float gamma )
```

**Description**

Creates an **OH_NativeColorSpaceManager** instance based on the color primaries and gamma value. A new **OH_NativeColorSpaceManager** instance is created each time this function is called.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| primaries | Color primaries.| 
| gamma | Gamma value, which is a floating-point number used to adjust the luminance range. Generally, the gamma value is positive. A negative value results in increased brightness in low-light areas and decreased brightness in high-light areas. The value **0** indicates a linear color space.| 

**Returns**

Returns the pointer to an **OH_NativeColorSpaceManager** instance If the memory is insufficient, the **OH_NativeColorSpaceManager** instance fails to be created.


### OH_NativeColorSpaceManager_Destroy()

```
void OH_NativeColorSpaceManager_Destroy (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Destroys an **OH_NativeColorSpaceManager** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.| 


### OH_NativeColorSpaceManager_GetColorSpaceName()

```
int OH_NativeColorSpaceManager_GetColorSpaceName (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Obtains the color space name.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.| 

**Returns**

Returns the color space name, which is defined in [ColorSpaceName](#colorspacename). The return value **0** means that the function call fails.


### OH_NativeColorSpaceManager_GetGamma()

```
float OH_NativeColorSpaceManager_GetGamma (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Obtains the gamma value.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.| 

**Returns**

Returns a float value. The value **0.0** means that the function call fails.


### OH_NativeColorSpaceManager_GetWhitePoint()

```
WhitePointArray OH_NativeColorSpaceManager_GetWhitePoint (OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Obtains the white points.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Parameters**

| Name| Description| 
| -------- | -------- |
| nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.| 

**Returns**

Returns a float array of white points. The value **&lt;0.0, 0.0&gt;** means that the function call fails.
