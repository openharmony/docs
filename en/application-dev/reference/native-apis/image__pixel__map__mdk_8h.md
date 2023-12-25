# image_pixel_map_mdk.h


## Overview

The **image_pixel_map_mdk.h** file declares the APIs that can lock, access, and unlock a pixel map. Need link **libpixelmapndk.z.so**

**Since**

10

**Related Modules**

[Image](image.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [OhosPixelMapInfos](_ohos_pixel_map_infos.md) | Defines the pixel map information.| 
| [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | Defines the options for creating a pixel map.| 


### Types

| Name| Description| 
| -------- | -------- |
| [NativePixelMap](image.md#nativepixelmap) | Defines the data type name of the pixel map at the native layer.| 
| [OhosPixelMapInfos](image.md#ohospixelmapinfos) | Defines the pixel map information.| 


### Enums

| Name| Description| 
| -------- | -------- |
| { [OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN](image.md#anonymous-enum-23) = 0,<br>[OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE](image.md#anonymous-enum-23) = 1,<br>[OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL](image.md#anonymous-enum-23) = 2,<br>[OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL](image.md#anonymous-enum-23) = 3 } | Enumerates the pixel map alpha types.| 
| { [OHOS_PIXEL_MAP_READ_ONLY](image.md#anonymous-enum-23-1) = 0,<br>[OHOS_PIXEL_MAP_EDITABLE](image.md#anonymous-enum-23-1) = 1 } | Enumerates the pixel map editing types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_PixelMap_CreatePixelMap](image.md#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | Creates a **PixelMap** object.| 
| [OH_PixelMap_CreateAlphaPixelMap](image.md#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | Creates a **PixelMap** object that contains only alpha channel information.| 
| [OH_PixelMap_InitNativePixelMap](image.md#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | Initializes a **PixelMap** object.| 
| [OH_PixelMap_GetBytesNumberPerRow](image.md#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*num) | Obtains the number of bytes per row of a **NativePixelMap** object.| 
| [OH_PixelMap_GetIsEditable](image.md#oh_pixelmap_getiseditable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*editable) | Checks whether a **NativePixelMap** object is editable.| 
| [OH_PixelMap_IsSupportAlpha](image.md#oh_pixelmap_issupportalpha) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*alpha) | Checks whether a **NativePixelMap** object supports alpha channels.| 
| [OH_PixelMap_SetAlphaAble](image.md#oh_pixelmap_setalphaable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t alpha) | Sets an alpha channel for a **NativePixelMap** object.| 
| [OH_PixelMap_GetDensity](image.md#oh_pixelmap_getdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*density) | Obtains the pixel density of a **NativePixelMap** object.| 
| [OH_PixelMap_SetDensity](image.md#oh_pixelmap_setdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t density) | Sets the pixel density for a **NativePixelMap** object.| 
| [OH_PixelMap_SetOpacity](image.md#oh_pixelmap_setopacity) (const [NativePixelMap](image.md#nativepixelmap) \*native, float opacity) | Sets the opacity for a **NativePixelMap** object.| 
| [OH_PixelMap_Scale](image.md#oh_pixelmap_scale) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | Scales a **NativePixelMap** object.| 
| [OH_PixelMap_Translate](image.md#oh_pixelmap_translate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | Translates a **NativePixelMap** object.| 
| [OH_PixelMap_Rotate](image.md#oh_pixelmap_rotate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float angle) | Rotates a **NativePixelMap** object.| 
| [OH_PixelMap_Flip](image.md#oh_pixelmap_flip) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y) | Flips a **NativePixelMap** object.| 
| [OH_PixelMap_Crop](image.md#oh_pixelmap_crop) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y, int32_t width, int32_t height) | Crops a **NativePixelMap** object.| 
| [OH_PixelMap_GetImageInfo](image.md#oh_pixelmap_getimageinfo) (const [NativePixelMap](image.md#nativepixelmap) \*native, [OhosPixelMapInfos](_ohos_pixel_map_infos.md) \*info) | Obtains the image information of a **NativePixelMap** object.| 
| [OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native, void \*\*addr) | Obtains the memory address of a **NativePixelMap** object and locks the memory.| 
| [OH_PixelMap_UnAccessPixels](image.md#oh_pixelmap_unaccesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native) | Unlocks the memory of a **NativePixelMap** object. This function is used with [OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels) in pairs.| 
<!--no_check-->
