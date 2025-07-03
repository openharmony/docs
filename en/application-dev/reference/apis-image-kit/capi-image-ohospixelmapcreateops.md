# OhosPixelMapCreateOps

## Overview

The OhosPixelMapCreateOps struct describes the options used for creating a PixelMap.

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_pixel_map_mdk.h](capi-image-pixel-map-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t width | Image width, in pixels.|
| uint32_t height | Image height, in pixels.|
| int32_t pixelFormat | Image format. The options are as follows:<br>**0**: Unknown format.<br>**2**: RGB_565.<br>**3**: RGBA_8888.<br>**4**: BGRA_8888.<br>**5**: RGB_888.<br>**6**: ALPHA_8.<br>**7**: RGBA_F16.<br>**8**: NV21.<br>**9**: NV12.|
| uint32_t editable | Editing type of the image. The value **true** means that the image pixel can be edited, and **false** means the opposite.|
| uint32_t alphaType | Alpha type of the image. The options are as follows:<br>**0**: Unknown alpha type.<br>**1**: There is no alpha or the image is opaque.<br>**2**: Premultiplied alpha.<br>**3**: Unpremultiplied alpha, that is, straight alpha.|
| uint32_t scaleMode | Scale mode of the image. The options are as follows:<br>**1**: The image is scaled in such a way that it fits the dimensions of the target and centered in the target.<br>**0**: The image size is reduced to fit the dimensions of the target.|
