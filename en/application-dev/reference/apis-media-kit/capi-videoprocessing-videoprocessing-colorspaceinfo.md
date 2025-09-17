# VideoProcessing_ColorSpaceInfo
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the color space information of video processing.

**Reference**: [OH_VideoProcessing_IsColorSpaceConversionSupported](capi-video-processing-h.md#oh_videoprocessing_iscolorspaceconversionsupported)

**Since**: 12

**Related module**: [VideoProcessing](capi-videoprocessing.md)

**Header file**: [video_processing_types.h](capi-video-processing-types-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t metadataType | Video metadata type. For details, see [OH_NativeBuffer_MetadataType](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_metadatatype).|
| int32_t colorSpace | Video color space type. For details, see [OH_NativeBuffer_ColorSpace](../apis-arkgraphics2d/capi-buffer-common-h.md#oh_nativebuffer_colorspace).|
| int32_t pixelFormat | Video pixel format. For details, see [OH_NativeBuffer_Format](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_format).|

<!--no_check-->