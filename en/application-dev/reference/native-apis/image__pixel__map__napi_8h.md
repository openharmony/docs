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
| [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) |Defines the options used for creating a pixel map.  | 

### Types

| Name | Description | 
| -------- | -------- |
| [NativePixelMap](image.md#nativepixelmap) | Defines the data type name of the native pixel map.  | 

### Enums

| Name | Description | 
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | Enumerates the error codes returned by a function.  | 
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | Enumerates the pixel formats.  | 
| { OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0, OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1, OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2, OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 } | Enumerates the pixel map alpha types.  | 
| { OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE = 0, OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP = 1 } | Enumerates the pixel map scale modes.  | 
| { OHOS_PIXEL_MAP_READ_ONLY = 0, OHOS_PIXEL_MAP_EDITABLE = 1 } | Enumerates the pixel map editing types.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_GetImageInfo](image.md#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | Obtains the **PixelMap** information and stores the information to the [OhosPixelMapInfo](_ohos_pixel_map_info.md) structure.  | 
| [OH_AccessPixels](image.md#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | Obtains the memory address of the **PixelMap** object data and locks the memory.  | 
| [OH_UnAccessPixels](image.md#oh_unaccesspixels) (napi_env env, napi_value value) | Unlocks the memory of the **PixelMap** object data. This function is used with [OH_AccessPixels](image.md#oh_accesspixels) in pairs.  | 


### Variables

| Name | Description | 
| -------- | -------- |
| [width](#width) | Image width, in pixels.  | 
| [height](#height) | Image height, in pixels.  | 
| [pixelFormat](#pixelformat) | Image format.  | 
| [editable](#editable) | Editing type of the image.  | 
| [alphaType](#alphatype) | Alpha type of the image.  | 
| [scaleMode](#scalemode) | Scale mode of the image.  | 


## Variable Description


### alphaType

  
```
uint32_t alphaType
```
**Description:**
Alpha type of the image.


### editable

  
```
uint32_t editable
```
**Description:**
Editing type of the image.


### height

  
```
uint32_t height
```
**Description:**
Image height, in pixels.


### pixelFormat

  
```
int32_t pixelFormat
```
**Description:**
Image format.


### scaleMode

  
```
uint32_t scaleMode
```
**Description:**
Scale mode of the image.


### width

  
```
uint32_t width
```
**Description:**
Image width, in pixels.
