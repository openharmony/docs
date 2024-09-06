# OH_Pixelmap_HdrStaticMetadata


## Overview

The OH_Pixelmap_HdrStaticMetadata struct describes the static metadata values available for the key **HDR_STATIC_METADATA**.

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| float [displayPrimariesX](#displayprimariesx)[3] | X coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. | 
| float [displayPrimariesY](#displayprimariesy)[3] | Y coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0]. | 
| float [whitePointX](#whitepointx) | X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0]. | 
| float [whitePointY](#whitepointy) | X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0]. | 
| float [maxLuminance](#maxluminance) | Maximum luminance of the main monitor. The unit is 1, and the maximum value is 65535. | 
| float [minLuminance](#minluminance) | Minimum luminance of the main monitor. The unit is 0.0001, and the maximum value is 6.55535. | 
| float [maxContentLightLevel](#maxcontentlightlevel) | Maximum luminance of the displayed content. The unit is 1, and the maximum value is 65535. | 
| float [maxFrameAverageLightLevel](#maxframeaveragelightlevel) | Maximum average luminance of the displayed content. The unit is 1, and the maximum value is 65535. | 


## Member Variable Description


### displayPrimariesX

```
float OH_Pixelmap_HdrStaticMetadata::displayPrimariesX[3]
```

**Description**

X coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0].


### displayPrimariesY

```
float OH_Pixelmap_HdrStaticMetadata::displayPrimariesY[3]
```

**Description**

Y coordinate of the three primary colors of the display device after normalization. The array length is 3. The unit is 0.00002. The value range is [0.0, 1.0].


### maxContentLightLevel

```
float OH_Pixelmap_HdrStaticMetadata::maxContentLightLevel
```

**Description**

Maximum luminance of the displayed content. The unit is 1, and the maximum value is 65535.


### maxFrameAverageLightLevel

```
float OH_Pixelmap_HdrStaticMetadata::maxFrameAverageLightLevel
```

**Description**

Maximum average luminance of the displayed content. The unit is 1, and the maximum value is 65535.


### maxLuminance

```
float OH_Pixelmap_HdrStaticMetadata::maxLuminance
```

**Description**

Maximum luminance of the main monitor. The unit is 1, and the maximum value is 65535.


### minLuminance

```
float OH_Pixelmap_HdrStaticMetadata::minLuminance
```

**Description**

Minimum luminance of the main monitor. The unit is 0.0001, and the maximum value is 6.55535.


### whitePointX

```
float OH_Pixelmap_HdrStaticMetadata::whitePointX
```

**Description**

X coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].


### whitePointY

```
float OH_Pixelmap_HdrStaticMetadata::whitePointY
```

**Description**

Y coordinate of the white point after normalization. The unit is 0.00002. The value range is [0.0, 1.0].
