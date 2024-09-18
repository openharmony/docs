# image_pixel_map_mdk.h


## Overview

The **image_pixel_map_mdk.h** file declares the APIs used to lock, access, and unlock a pixel map.

**Library**: libpixelmap_ndk.z.so

**File to include**: &lt;multimedia/image_framework/image_pixel_map_mdk.h&gt;

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OhosPixelMapInfos](_ohos_pixel_map_infos.md) | Defines the information about a pixel map. | 
| struct  [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | Defines the options used for creating a pixel map. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct NativePixelMap_ [NativePixelMap](image.md#nativepixelmap) | Defines the data type name of the pixel map at the native layer. | 
| typedef struct [OhosPixelMapInfos](_ohos_pixel_map_infos.md) [OhosPixelMapInfos](image.md#ohospixelmapinfos) | Defines the information about a pixel map. | 


### Enums

| Name| Description| 
| -------- | -------- |
| { [OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN](image.md#anonymous-enum-23) = 0,<br>[OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE](image.md#anonymous-enum-23) = 1,<br>[OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL](image.md#anonymous-enum-23) = 2,<br>[OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL](image.md#anonymous-enum-23) = 3 } | Enumerates the pixel map alpha types.| 
| { [OHOS_PIXEL_MAP_READ_ONLY](image.md#anonymous-enum-23-1) = 0,<br>[OHOS_PIXEL_MAP_EDITABLE](image.md#anonymous-enum-23-1) = 1 } | Enumerates the pixel map editing types.| 
| [OH_PixelMap_AntiAliasingLevel](image.md#oh_pixelmap_antialiasinglevel) { <br>OH_PixelMap_AntiAliasing_NONE = 0, <br>OH_PixelMap_AntiAliasing_LOW = 1, <br>OH_PixelMap_AntiAliasing_MEDIUM = 2, <br>OH_PixelMap_AntiAliasing_HIGH = 3 <br>} | Enumerates the antialiasing levels used for scaling pixel maps. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_PixelMap_CreatePixelMap](image.md#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | Creates a **PixelMap** object. | 
| int32_t [OH_PixelMap_CreatePixelMapWithStride](image.md#oh_pixelmap_createpixelmapwithstride) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, int32_t rowStride, napi_value \*res) | Creates a **PixelMap** object. Currently, only BGRA input streams are supported. For a pixel map in RGBA format (with the size greater than 512\*512), DMA memory is used by default. | 
| int32_t [OH_PixelMap_CreateAlphaPixelMap](image.md#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | Creates a **PixelMap** object that contains only alpha channel information. | 
| [NativePixelMap](image.md#nativepixelmap) \* [OH_PixelMap_InitNativePixelMap](image.md#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | Initializes a **PixelMap** object. | 
| int32_t [OH_PixelMap_GetBytesNumberPerRow](image.md#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*num) | Obtains the number of bytes per row of a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_GetIsEditable](image.md#oh_pixelmap_getiseditable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*editable) | Checks whether a **NativePixelMap** object is editable. | 
| int32_t [OH_PixelMap_IsSupportAlpha](image.md#oh_pixelmap_issupportalpha) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*alpha) | Checks whether a **NativePixelMap** object supports alpha channels. | 
| int32_t [OH_PixelMap_SetAlphaAble](image.md#oh_pixelmap_setalphaable) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t alpha) | Sets an alpha channel for a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_GetDensity](image.md#oh_pixelmap_getdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t \*density) | Obtains the pixel density of a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_SetDensity](image.md#oh_pixelmap_setdensity) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t density) | Sets the pixel density for a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_SetOpacity](image.md#oh_pixelmap_setopacity) (const [NativePixelMap](image.md#nativepixelmap) \*native, float opacity) | Sets the opacity for a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_Scale](image.md#oh_pixelmap_scale) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | Scales a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_ScaleWithAntiAliasing](image.md#oh_pixelmap_scalewithantialiasing) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y, [OH_PixelMap_AntiAliasingLevel](image.md#oh_pixelmap_antialiasinglevel) level) | Scales an image based on the specified antialiasing level, width, and height. | 
| int32_t [OH_PixelMap_Translate](image.md#oh_pixelmap_translate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float x, float y) | Translates a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_Rotate](image.md#oh_pixelmap_rotate) (const [NativePixelMap](image.md#nativepixelmap) \*native, float angle) | Rotates a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_Flip](image.md#oh_pixelmap_flip) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y) | Flips a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_Crop](image.md#oh_pixelmap_crop) (const [NativePixelMap](image.md#nativepixelmap) \*native, int32_t x, int32_t y, int32_t width, int32_t height) | Crops a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_GetImageInfo](image.md#oh_pixelmap_getimageinfo) (const [NativePixelMap](image.md#nativepixelmap) \*native, [OhosPixelMapInfos](_ohos_pixel_map_infos.md) \*info) | Obtains the image information of a **NativePixelMap** object. | 
| int32_t [OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native, void \*\*addr) | Obtains the memory address of a **NativePixelMap** object and locks the memory. | 
| int32_t [OH_PixelMap_UnAccessPixels](image.md#oh_pixelmap_unaccesspixels) (const [NativePixelMap](image.md#nativepixelmap) \*native) | Unlocks the memory of a **NativePixelMap** object. This function is used with [OH_PixelMap_AccessPixels](image.md#oh_pixelmap_accesspixels) in pairs. | 
