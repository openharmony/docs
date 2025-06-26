# VideoProcessing_ColorSpaceInfo


## Overview

The VideoProcessing_ColorSpaceInfo struct describes the color space information of video processing.

**See also**: [OH_VideoProcessing_IsColorSpaceConversionSupported](_video_processing.md#oh_videoprocessing_iscolorspaceconversionsupported)

**Since**: 12

**Related module**: [VideoProcessing](_video_processing.md)

**Header file**: [video_processing_types.h](video__processing__types_8h.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| int32_t [metadataType](#metadatatype) | Video metadata type. For details, see [OH_NativeBuffer_MetadataType](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_metadatatype).|
| int32_t [colorSpace](#colorspace) | Video color space type. For details, see [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace). |
| int32_t [pixelFormat](#pixelformat) | Video pixel format. For details, see [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format-1).|


## Member Variable Description


### colorSpace

```
int32_t VideoProcessing_ColorSpaceInfo::colorSpace
```

**Description**

Video color space type. For details, see [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace).


### metadataType

```
int32_t VideoProcessing_ColorSpaceInfo::metadataType
```

**Description**

Video metadata type. For details, see [OH_NativeBuffer_MetadataType](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_metadatatype).


### pixelFormat

```
int32_t VideoProcessing_ColorSpaceInfo::pixelFormat
```

**Description**

Video pixel format. For details, see [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format-1).

 <!--no_check--> 