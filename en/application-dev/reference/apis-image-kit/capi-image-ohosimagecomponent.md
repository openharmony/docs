# OhosImageComponent
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @liyang_bryan-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The struct describes the information about an image component.

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_mdk.h](capi-image-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t* byteBuffer | Pointer to the buffer that stores the pixel data.|
| size_t size | Size of the pixel data in the memory.|
| int32_t componentType | Type of the pixel data.<br>**1**: OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y, luminance information<br>**2**: OHOS_IMAGE_COMPONENT_FORMAT_YUV_U, chrominance component.<br>**3**: OHOS_IMAGE_COMPONENT_FORMAT_YUV_V, chrominance component.<br>**4**: OHOS_IMAGE_COMPONENT_FORMAT_JPEG, JPEG format.|
| int32_t rowStride | Row stride of the pixel data. Camera preview stream data must be read based on the stride. For details, see [Secondary Processing of Preview Streams (C/C++)](../../media/camera/native-camera-preview-imageReceiver.md).|
| int32_t pixelStride | Pixel stride of the pixel data.|
