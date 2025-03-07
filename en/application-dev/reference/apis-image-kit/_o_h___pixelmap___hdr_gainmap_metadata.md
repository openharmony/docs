# OH_Pixelmap_HdrGainmapMetadata


## Overview

The OH_Pixelmap_HdrGainmapMetadata struct describes the gain map metadata values available for the key **HDR_GAINMAP_METADATA**. For details, see ISO 21496-1.

**Since**: 12

**Related module**: [Image_NativeModule](_image___native_module.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| uint16_t [writerVersion](#writerversion) | Version used by the metadata editor. | 
| uint16_t [miniVersion](#miniversion) | Minimum version that needs to be understood for metadata parsing. | 
| uint8_t [gainmapChannelNum](#gainmapchannelnum) | Number of color channels of the gain map. When the value is 3, the metadata values of the RGB channels are different. When the value is 1, the metadata values of the RGB channels are the same. | 
| bool [useBaseColorFlag](#usebasecolorflag) | Whether to use the color space of the base graphic. For details, see ISO 21496-1. | 
| float [baseHeadroom](#baseheadroom) | Headroom of the base graphic, which means the additional brightness that can be added to the base graphic. For details, see ISO 21496-1. | 
| float [alternateHeadroom](#alternateheadroom) | Headroom of the alternate graphic. For details, see ISO 21496-1. | 
| float [gainmapMax](#gainmapmax)[3] | Maximum value of the gain map. For details, see ISO 21496-1. | 
| float [gainmapMin](#gainmapmin)[3] | Minimum value of the gain map. For details, see ISO 21496-1. | 
| float [gamma](#gamma)[3] | Gamma. For details, see ISO 21496-1. | 
| float [baselineOffset](#baselineoffset)[3] | Offset of the base graphic. For details, see ISO 21496-1. | 
| float [alternateOffset](#alternateoffset)[3] | Offset of the alternative graphic that can be extracted. For details, see ISO 21496-1. | 


## Member Variable Description


### alternateHeadroom

```
float OH_Pixelmap_HdrGainmapMetadata::alternateHeadroom
```

**Description**

Headroom of the alternate graphic. For details, see ISO 21496-1.


### alternateOffset

```
float OH_Pixelmap_HdrGainmapMetadata::alternateOffset[3]
```

**Description**

Offset of the alternative graphic that can be extracted. For details, see ISO 21496-1.


### baseHeadroom

```
float OH_Pixelmap_HdrGainmapMetadata::baseHeadroom
```

**Description**

Headroom of the base graphic, which means the additional brightness that can be added to the base graphic. For details, see ISO 21496-1.


### baselineOffset

```
float OH_Pixelmap_HdrGainmapMetadata::baselineOffset[3]
```

**Description**

Offset of the base graphic. For details, see ISO 21496-1.


### gainmapChannelNum

```
uint8_t OH_Pixelmap_HdrGainmapMetadata::gainmapChannelNum
```

**Description**

Number of color channels of the gain map. When the value is 3, the metadata values of the RGB channels are different. When the value is 1, the metadata values of the RGB channels are the same.


### gainmapMax

```
float OH_Pixelmap_HdrGainmapMetadata::gainmapMax[3]
```

**Description**

Maximum value of the gain map. For details, see ISO 21496-1.


### gainmapMin

```
float OH_Pixelmap_HdrGainmapMetadata::gainmapMin[3]
```

**Description**

Minimum value of the gain map. For details, see ISO 21496-1.


### gamma

```
float OH_Pixelmap_HdrGainmapMetadata::gamma[3]
```

**Description**

Gamma. For details, see ISO 21496-1.


### miniVersion

```
uint16_t OH_Pixelmap_HdrGainmapMetadata::miniVersion
```

**Description**

Minimum version that needs to be understood for metadata parsing.


### useBaseColorFlag

```
bool OH_Pixelmap_HdrGainmapMetadata::useBaseColorFlag
```

**Description**

Whether to use the color space of the base graphic. For details, see ISO 21496-1.


### writerVersion

```
uint16_t OH_Pixelmap_HdrGainmapMetadata::writerVersion
```

**Description**

Version used by the metadata editor.
