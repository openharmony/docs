# OH_Pixelmap_InitializationOptions

## Overview

The OH_Pixelmap_InitializationOptions struct describes the initialization options encapsulated at the native layer. The struct is used to set the initialization parameters for a PixelMap.

To create an OH_Pixelmap_InitializationOptions object, call [OH_PixelmapInitializationOptions_Create](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_create).

To release an OH_Pixelmap_InitializationOptions object, call [OH_PixelmapInitializationOptions_Release](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_release).

The table below describes the content and operation mode of the OH_Pixelmap_InitializationOptions struct.

| Field type.| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width.| [OH_PixelmapInitializationOptions_GetWidth](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getwidth) |Obtains the image width.|
| uint32_t | width | Image width.| [OH_PixelmapInitializationOptions_SetWidth](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setwidth) |Sets the image width.|
| uint32_t | height | Image height.| [OH_PixelmapInitializationOptions_GetHeight](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getheight) |Obtains the image height.|
| uint32_t | height | Image height.| [OH_PixelmapInitializationOptions_SetHeight](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setheight) |Sets the image height.|
| int32_t | pixelFormat | Pixel format.| [OH_PixelmapInitializationOptions_GetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getpixelformat) |Obtains the pixel format.|
| int32_t | pixelFormat | Pixel format.| [OH_PixelmapInitializationOptions_SetPixelFormat](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setpixelformat) |Sets the pixel format.|
| int32_t | alphaType | Alpha type.| [OH_PixelmapInitializationOptions_GetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getalphatype) |Obtains the alpha type.|
| int32_t | alphaType | Alpha type.| [OH_PixelmapInitializationOptions_SetAlphaType](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_setalphatype) |Sets the alpha type.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [pixelmap_native.h](capi-pixelmap-native-h.md)
