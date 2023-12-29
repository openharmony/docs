# image_pixel_map_napi.h


## Overview

The **image_pixel_map_napi.h** file declares the APIs that can lock, access, and unlock a pixel map.

**Since**

8

**Related Modules**

[Image](image.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [OHOS::Media::OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) | Defines the pixel map information.| 


### Enums

| Name| Description| 
| -------- | -------- |
| { [OHOS::Media::OHOS_IMAGE_RESULT_SUCCESS](image.md#anonymous-enum-33) = 0,<br>[OHOS::Media::OHOS_IMAGE_RESULT_BAD_PARAMETER](image.md#anonymous-enum-33) = -1 } | Enumerates the error codes returned by the functions.| 
| { [OHOS::Media::OHOS_PIXEL_MAP_FORMAT_NONE](image.md#anonymous-enum-33-1) = 0,<br>[OHOS::Media::OHOS_PIXEL_MAP_FORMAT_RGBA_8888](image.md#anonymous-enum-33-1) = 3,<br>[OHOS::Media::OHOS_PIXEL_MAP_FORMAT_RGB_565](image.md#anonymous-enum-33-1) = 2 } | Enumerates the pixel map formats.| 
| { [OHOS::Media::OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE](image.md#anonymous-enum) = 0,<br>[OHOS::Media::OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP](image.md#anonymous-enum) = 1 } | Enumerates the pixel map scale modes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OHOS::Media::OH_GetImageInfo](image.md#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) \*info) | Obtains the information about a **PixelMap** object and stores the information to the [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) struct.| 
| [OHOS::Media::OH_AccessPixels](image.md#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | Obtains the memory address of a **PixelMap** object and locks the memory.| 
| [OHOS::Media::OH_UnAccessPixels](image.md#oh_unaccesspixels) (napi_env env, napi_value value) | Unlocks the memory of a **PixelMap** object. This function is used with **OH_AccessPixels** in pairs.| 
<!--no_check-->
