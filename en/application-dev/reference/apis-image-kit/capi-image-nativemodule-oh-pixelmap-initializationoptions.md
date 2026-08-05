# OH_Pixelmap_InitializationOptions

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=c3fc7552ecc67e4184d5fea40476f98a1ca548f2 translatedAt=2026-08-03T04:03:42.040Z pushedAt=2026-08-04T06:41:25.292Z -->

```c
struct OH_Pixelmap_InitializationOptions
```

## Overview

OH_Pixelmap_InitializationOptions is an initialization options struct encapsulated at the native layer. It specifies properties such as image width, height, pixel format, and alpha type for PixelMap creation. It is suitable for scenarios where a PixelMap needs to be created at the native layer with customized initialization properties.

Use the [OH_PixelmapInitializationOptions_Create](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_create) function to create an OH_Pixelmap_InitializationOptions object. After use, call the [OH_PixelmapInitializationOptions_Release](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_release) function to release resources. The two functions must be used in pairs; otherwise, memory leaks may occur.

The table below describes the content and operation mode of the OH_Pixelmap_InitializationOptions struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width, in pixels. The value must be greater than 0, and the maximum value is limited by the system memory. | [OH_PixelmapInitializationOptions_GetWidth](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getwidth) | Obtains the image width. |
| uint32_t | width | Image width, in pixels. The value must be greater than 0, and the maximum value is limited by the system memory. | [OH_PixelmapInitializationOptions_SetWidth](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setwidth) | Sets the image width. |
| uint32_t | height | Image height, in pixels. The value must be greater than 0, and the maximum value is limited by the system memory. | [OH_PixelmapInitializationOptions_GetHeight](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getheight) | Obtains the image height. |
| uint32_t | height | Image height, in pixels. The value must be greater than 0, and the maximum value is limited by the system memory. | [OH_PixelmapInitializationOptions_SetHeight](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setheight) | Sets the image height. |
| int32_t | pixelFormat | Pixel format. For valid values, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format). Select an appropriate pixel format based on whether the image requires a alpha channel and the memory usage requirements. For the applicable scenarios of each enum value, see the PIXEL_FORMAT Enumeration Description. | [OH_PixelmapInitializationOptions_GetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getpixelformat) | Obtains the pixel format. |
| int32_t | pixelFormat | Pixel format. For valid values, see [PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format). Select an appropriate pixel format based on whether the image requires a alpha channel and the memory usage requirements. For the applicable scenarios of each enum value, see the PIXEL_FORMAT Enumeration Description. | [OH_PixelmapInitializationOptions_SetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setpixelformat) | Sets the pixel format. |
| int32_t | alphaType | Alpha type. For valid values, see [PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type). Select an appropriate type based on whether the image requires premultiplied alpha processing. For the applicable scenarios of each enum value, see the PIXELMAP_ALPHA_TYPE Enumeration Description. | [OH_PixelmapInitializationOptions_GetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getalphatype) | Obtains the alpha type. |
| int32_t | alphaType | Alpha type. For valid values, see [PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type). Select an appropriate type based on whether the image requires premultiplied alpha processing. For the applicable scenarios of each enum value, see the PIXELMAP_ALPHA_TYPE Enumeration Description. | [OH_PixelmapInitializationOptions_SetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setalphatype) | Sets the alpha type. |

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)