# image_pixel_map_napi.h


## Overview

Declares the APIs that can lock, access, and unlock pixel map data.

**Since:**
8

**Related Modules:**

[Image](image.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| [OhosPixelMapInfo](_ohos_pixel_map_info.md) | Defines the pixel map information.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | Enumerates the error codes returned by a function.  | 
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | Enumerates the pixel formats.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_GetImageInfo](image.md#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | Obtains the **PixelMap** information and stores the information to the [OhosPixelMapInfo](_ohos_pixel_map_info.md) structure.  | 
| [OH_AccessPixels](image.md#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | Obtains the memory address of the **PixelMap** object data and locks the memory.  | 
| [OH_UnAccessPixels](image.md#oh_unaccesspixels) (napi_env env, napi_value value) | Unlocks the memory of the **PixelMap** object data. This function is used with [OH_AccessPixels](image.md#oh_accesspixels) in pairs.  | 

