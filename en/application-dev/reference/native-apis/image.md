# Image


## Overview

Provides APIs for obtaining pixel map data and information.

\@Syscap SystemCapability.Multimedia.Image

**Since:**
8


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [image_pixel_map_napi.h](image__pixel__map__napi_8h.md) | Declares the APIs that can lock, access, and unlock pixel map data. <br>File to Include: <multimedia/image_framework/image_pixel_map_napi.h> | 


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
| [OH_GetImageInfo](#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | Obtains the **PixelMap** information and stores the information to the [OhosPixelMapInfo](_ohos_pixel_map_info.md) structure.  | 
| [OH_AccessPixels](#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | Obtains the memory address of the **PixelMap** object data and locks the memory.  | 
| [OH_UnAccessPixels](#oh_unaccesspixels) (napi_env env, napi_value value) | Unlocks the memory of the **PixelMap** object data. This function is used with [OH_AccessPixels](#oh_accesspixels) in pairs.  | 


## Enum Description


### anonymous enum

  
```
anonymous enum
```
**Description**<br>
Enumerates the error codes returned by a function.

| Name | Description | 
| -------- | -------- |
| OHOS_IMAGE_RESULT_SUCCESS  | Operation success. | 
| OHOS_IMAGE_RESULT_BAD_PARAMETER  | Invalid value. | 


### anonymous enum

  
```
anonymous enum
```
**Description**<br>
Enumerates the pixel formats.

| Name | Description | 
| -------- | -------- |
| OHOS_PIXEL_MAP_FORMAT_NONE  | Unknown format. | 
| OHOS_PIXEL_MAP_FORMAT_RGBA_8888  | 32-bit RGBA, with 8 bits each for R (red), G (green), B (blue), and A (alpha). The data is stored from the most significant bit to the least significant bit. | 
| OHOS_PIXEL_MAP_FORMAT_RGB_565  | 16-bit RGB, with 5, 6, and 5 bits for R, G, and B, respectively. The storage sequence is from the most significant bit to the least significant bit. | 


## Function Description


### OH_AccessPixels()

  
```
int32_t OH_AccessPixels (napi_env env, napi_value value, void ** addrPtr )
```
**Description**<br>
Obtains the memory address of the **PixelMap** object data and locks the memory.

After the function is executed successfully, **\*addrPtr** is the address of the memory to be accessed. After the access operation is complete, you must use [OH_UnAccessPixels](#oh_unaccesspixels) to unlock the memory. Otherwise, the resources in the memory cannot be released. After being unlocked, the memory address cannot be accessed or operated.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the NAPI environment pointer.  | 
| value | Indicates the **PixelMap** object at the application layer.  | 
| addrPtr | Indicates the double pointer to the memory address.  | 

 **See**

UnAccessPixels

**Returns**

Returns OHOS_IMAGE_RESULT_SUCCESS if the operation is successful; returns an error code otherwise.


### OH_GetImageInfo()

  
```
int32_t OH_GetImageInfo (napi_env env, napi_value value, OhosPixelMapInfo * info )
```
**Description**<br>
Obtains the **PixelMap** information and stores the information to the [OhosPixelMapInfo](_ohos_pixel_map_info.md) structure.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the NAPI environment pointer.  | 
| value | Indicates the **PixelMap** object at the application layer.  | 
| info | Indicates the pointer to the object that stores the information obtained. For details, see [OhosPixelMapInfo](_ohos_pixel_map_info.md).  | 

**Returns**

Returns **0** if the information is obtained and stored successfully; returns an error code otherwise.

 **See**

[OhosPixelMapInfo](_ohos_pixel_map_info.md)


### OH_UnAccessPixels()

  
```
int32_t OH_UnAccessPixels (napi_env env, napi_value value )
```
**Description**<br>
Unlocks the memory of the **PixelMap** object data. This function is used with [OH_AccessPixels](#oh_accesspixels) in pairs.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the NAPI environment pointer.  | 
| value | Indicates the **PixelMap** object at the application layer.  | 

**Returns**

Returns OHOS_IMAGE_RESULT_SUCCESS if the operation is successful; returns an error code otherwise.

 **See**

AccessPixels
