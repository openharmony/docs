# OhosPixelMapCreateOps

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=c3fc7552ecc67e4184d5fea40476f98a1ca548f2 translatedAt=2026-08-03T04:04:54.408Z pushedAt=2026-08-04T03:06:18.120Z -->

```c
struct OhosPixelMapCreateOps {...}
```

## Overview

This struct defines the options for creating a PixelMap, including the image width and height, pixel format, whether it is editable, alpha type, and scale type. It is used to specify initialization properties for creating a PixelMap at the native layer.

**Since**: 10

**Related module**: [Image](capi-image.md)

**Header file**: [image_pixel_map_mdk.h](capi-image-pixel-map-mdk-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint32_t width | Image width, in pixels. The value must be greater than 0. If **0** is passed, the PixelMap fails to be created. |
| uint32_t height | Image height, in pixels. The value must be greater than 0. If **0** is passed, the PixelMap fails to be created. |
| int32_t pixelFormat | Pixel format of the image. Value range:<br>**0**: unknown format.<br>**2**: RGB_565.<br>**3**: RGBA_8888.<br>**4**: BGRA_8888.<br>**5**: RGB_888.<br>**6**: ALPHA_8.<br>**7**: RGBA_F16.<br>**8**: NV21.<br>**9**: NV12. |
| uint32_t editable | Whether the image is editable. The value **1** means the image pixels are editable, and **0** means not editable. |
| uint32_t alphaType | Alpha type of the image. Value range:<br>**0**: Unknown alpha type.<br>**1**: No alpha channel or the image is opaque.<br>**2**: Premultiplied alpha.<br>**3**: Non-premultiplied alpha. |
| uint32_t scaleMode | Scale mode of the image. The options are as follows:<br>**1**: scales the image to fill the target image area and crops the portion outside the area with center alignment.<br>**0**: scales the image proportionally to fit the target image size (maintaining the aspect ratio). |