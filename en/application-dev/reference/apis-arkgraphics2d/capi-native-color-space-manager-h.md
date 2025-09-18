# native_color_space_manager.h

## Overview

The **native_color_space_manager.h** file declares the functions for creating and using a color space.

**File to import**: <native_color_space_manager/native_color_space_manager.h>

**Library**: libnative_color_space_manager.so

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13

**Related module**: [NativeColorSpaceManager](capi-nativecolorspacemanager.md)

## Total

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ColorSpacePrimaries](capi-nativecolorspacemanager-colorspaceprimaries.md) | ColorSpacePrimaries | Describes the color space primaries.|
| [WhitePointArray](capi-nativecolorspacemanager-whitepointarray.md) | - | Describes a white point array. Each white point indicates the coordinates of white in the active color space.|
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) | OH_NativeColorSpaceManager | Provides the declaration of an **OH_NativeColorSpaceManager** struct.|

### Enumerated value

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [ColorSpaceName](#colorspacename) | ColorSpaceName | Defines an enum for the color space names.|

### Functions

| Name| Description|
| -- | -- |
| [OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromName(ColorSpaceName colorSpaceName)](#oh_nativecolorspacemanager_createfromname) | Creates an **OH_NativeColorSpaceManager** instance based on a color space name.<br>A new **OH_NativeColorSpaceManager** instance is created each time this function is called.|
| [OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma(ColorSpacePrimaries primaries, float gamma)](#oh_nativecolorspacemanager_createfromprimariesandgamma) | Creates an **OH_NativeColorSpaceManager** instance based on the color primaries and gamma value.<br>A new **OH_NativeColorSpaceManager** instance is created each time this function is called.|
| [void OH_NativeColorSpaceManager_Destroy(OH_NativeColorSpaceManager* nativeColorSpaceManager)](#oh_nativecolorspacemanager_destroy) | Destroys an **OH_NativeColorSpaceManager** instance.|
| [int OH_NativeColorSpaceManager_GetColorSpaceName(OH_NativeColorSpaceManager* nativeColorSpaceManager)](#oh_nativecolorspacemanager_getcolorspacename) | Obtains the color space name.|
| [WhitePointArray OH_NativeColorSpaceManager_GetWhitePoint(OH_NativeColorSpaceManager* nativeColorSpaceManager)](#oh_nativecolorspacemanager_getwhitepoint) | Obtains the white points.|
| [float OH_NativeColorSpaceManager_GetGamma(OH_NativeColorSpaceManager* nativeColorSpaceManager)](#oh_nativecolorspacemanager_getgamma) | Obtains the gamma value.|

## Enum Description

### ColorSpaceName

```
enum ColorSpaceName
```

**Description**

Defines an enum for the color space names.

**Since**: 13

| Value| Description|
| -- | -- |
| NONE = 0 | Unknown color space.|
| ADOBE_RGB = 1 | Adobe RGB color space.|
| DCI_P3 = 2 | Color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999.|
| DISPLAY_P3 = 3 | Color space based on SMPTE RP 431-2-2007 and IEC 61966-2.1:1999.|
| SRGB = 4 | Standard RGB (SRGB) color space based on IEC 61966-2.1:1999.|
| BT709 = 6 | Color space based on ITU-R BT.709.|
| BT601_EBU = 7 | Color space based on ITU-R BT.601.|
| BT601_SMPTE_C = 8 | Color space based on ITU-R BT.601.|
| BT2020_HLG = 9 | Color space based on ITU-R BT.2020.|
| BT2020_PQ = 10 | Color space based on ITU-R BT.2020.|
| P3_HLG = 11 | Color space with the color primaries of P3_D65, the transfer characteristics of Hybrid Log-Gamma (HLG), and the color range of FULL.|
| P3_PQ = 12 | Color space with the color primaries of P3_D65, the transfer characteristics of Perceptual Quantizer (PQ), and the color range of FULL.|
| ADOBE_RGB_LIMIT = 13 | Color space with the color primaries of ADOBE_RGB, the transfer characteristics of ADOBE_RGB, and the color range of LIMIT.|
| DISPLAY_P3_LIMIT = 14 | Color space with the color primaries of P3_D65, the transfer characteristics of SRGB, and the color range of LIMIT.|
| SRGB_LIMIT = 15 | Color space with the color primaries of SRGB, the transfer characteristics of SRGB, and the color range of LIMIT.|
| BT709_LIMIT = 16 | Color space with the color primaries of BT.709, the transfer characteristics of BT.709, and the color range of LIMIT.|
| BT601_EBU_LIMIT = 17 | Color space with the color primaries of BT.601_P, the transfer characteristics of BT.709, and the color range of LIMIT.|
| BT601_SMPTE_C_LIMIT = 18 | Color space with the color primaries of BT.601_N, the transfer characteristics of BT.709, and the color range of LIMIT.|
| BT2020_HLG_LIMIT = 19 | Color space with the color primaries of BT.2020, the transfer characteristics of HLG, and the color range of LIMIT.|
| BT2020_PQ_LIMIT = 20 | Color space with the color primaries of BT.2020, the transfer characteristics of PQ, and the color range of LIMIT.|
| P3_HLG_LIMIT = 21 | Color space with the color primaries of P3_D65, the transfer characteristics of HLG, and the color range of LIMIT.|
| P3_PQ_LIMIT = 22 | Color space with the color primaries of P3_D65, the transfer characteristics of PQ, and the color range of LIMIT.|
| LINEAR_P3 = 23 | Color space with the color primaries of P3_D65 and the transfer characteristic of LINEAR.|
| LINEAR_SRGB = 24 | Color space with the color primaries of SRGB and the transfer characteristic of LINEAR.|
| LINEAR_BT709 = LINEAR_SRGB | Color space with the color primaries of BT.709 and the transfer characteristic of LINEAR.|
| LINEAR_BT2020 = 25 | Color space with the color primaries of BT.2020 and the transfer characteristic of LINEAR.|
| DISPLAY_SRGB = SRGB | Color space with the color primaries of SRGB, the transfer characteristics of SRGB, and the color range of FULL.|
| DISPLAY_P3_SRGB = DISPLAY_P3 | Color space with the color primaries of P3_D65, the transfer characteristics of SRGB, and the color range of FULL.|
| DISPLAY_P3_HLG = P3_HLG | Color space with the color primaries of P3_D65, the transfer characteristics of Hybrid Log-Gamma (HLG), and the color range of FULL.|
| DISPLAY_P3_PQ = P3_PQ | Color space with the color primaries of P3_D65, the transfer characteristics of Perceptual Quantizer (PQ), and the color range of FULL.|
| CUSTOM = 5 | Custom color space.|


## Function Description

### OH_NativeColorSpaceManager_CreateFromName()

```
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromName(ColorSpaceName colorSpaceName)
```

**Description**

Creates an **OH_NativeColorSpaceManager** instance based on a color space name.<br>A new **OH_NativeColorSpaceManager** instance is created each time this function is called.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ColorSpaceName](#colorspacename) colorSpaceName | Name of the color space of the [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) to be created.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* | Pointer to the [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) instance. If the memory is insufficient, the OH_NativeColorSpaceManager instance fails to be created.|

### OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma()

```
OH_NativeColorSpaceManager* OH_NativeColorSpaceManager_CreateFromPrimariesAndGamma(ColorSpacePrimaries primaries, float gamma)
```

**Description**

Creates an **OH_NativeColorSpaceManager** instance based on the color primaries and gamma value.<br>A new **OH_NativeColorSpaceManager** instance is created each time this function is called.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [ColorSpacePrimaries](capi-nativecolorspacemanager-colorspaceprimaries.md) primaries | Primary color of the [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) to be created.|
| float gamma | Gamma value of the [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md), which is a floating point number used to correct the luminance range.<br>Generally, the gamma value is positive. A negative value results in increased brightness in low-light areas and decreased brightness in high-light areas. The value **0** indicates a linear color space.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* | Pointer to the [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md) instance.<br> If the memory is insufficient, the OH_NativeColorSpaceManager instance fails to be created.|

### OH_NativeColorSpaceManager_Destroy()

```
void OH_NativeColorSpaceManager_Destroy(OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Destroys an **OH_NativeColorSpaceManager** instance.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.|

### OH_NativeColorSpaceManager_GetColorSpaceName()

```
int OH_NativeColorSpaceManager_GetColorSpaceName(OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Obtains the color space name.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.|

**Return value**

| Type| Description|
| -- | -- |
| int | Value of the color space enumeration [ColorSpaceName](capi-native-color-space-manager-h.md#colorspacename). If the return value is 0, the API operation fails.|

### OH_NativeColorSpaceManager_GetWhitePoint()

```
WhitePointArray OH_NativeColorSpaceManager_GetWhitePoint(OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Obtains the white points.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.|

**Return value**

| Type| Description|
| -- | -- |
| [WhitePointArray](capi-nativecolorspacemanager-whitepointarray.md) | An array of floats. If the return value is <0.0, 0.0>, the API operation fails. If the return value is not <0.0, 0.0>, the API operation is successful.|

### OH_NativeColorSpaceManager_GetGamma()

```
float OH_NativeColorSpaceManager_GetGamma(OH_NativeColorSpaceManager* nativeColorSpaceManager)
```

**Description**

Obtains the gamma value.

**System capability**: SystemCapability.Graphic.Graphic2D.ColorManager.Core

**Since**: 13


**Parameters**

| Name| Description|
| -- | -- |
| [OH_NativeColorSpaceManager](capi-nativecolorspacemanager-oh-nativecolorspacemanager.md)* nativeColorSpaceManager | Pointer to an **OH_NativeColorSpaceManager** instance.|

**Return value**

| Type| Description|
| -- | -- |
| float | The return value is of the float type. If the return value is 0.0, the API operation fails. If the return value is not 0.0, the API operation is successful.|
