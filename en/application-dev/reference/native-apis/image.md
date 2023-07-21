# Image


Provides APIs for obtaining pixel map data and information.

To use the APIs in this file, **libpixelmap_ndk.z.so** is required.

@Syscap SystemCapability.Multimedia.Image

**Since**


8


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [image_pixel_map_napi.h](image__pixel__map__napi_8h.md) | Declares the APIs that can lock, access, and unlock a pixel map.<br>File to include: <multimedia/image_framework/image_pixel_map_napi.h> |


### Structs

| Name| Description|
| -------- | -------- |
| [OhosPixelMapInfo](_ohos_pixel_map_info.md) | Defines the pixel map information.|


### Types

| Name| Description|
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | Enumerates the error codes returned by the functions.|
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | Enumerates the pixel formats.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_GetImageInfo](#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | Obtains the **PixelMap** information and stores the information to the [OhosPixelMapInfo](_ohos_pixel_map_info.md) struct.|
| [OH_AccessPixels](#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | Obtains the memory address of a **PixelMap** object and locks the memory.|
| [OH_UnAccessPixels](#oh_unaccesspixels) (napi_env env, napi_value value) | Unlocks the memory of a **PixelMap** object. This function is used with [OH_AccessPixels](#oh_accesspixels) in pairs.|


## Type Description


### anonymous enum


```
anonymous enum
```
**Description**

Enumerates the error codes returned by the functions.

| Value| Description|
| -------- | -------- |
| OHOS_IMAGE_RESULT_SUCCESS| Operation success.|
| OHOS_IMAGE_RESULT_BAD_PARAMETER| Invalid value.|

**Since**

8

### anonymous enum


```
anonymous enum
```
**Description**

Enumerates the pixel formats.

| Value| Description|
| -------- | -------- |
| OHOS_PIXEL_MAP_FORMAT_NONE| Unknown format.|
| OHOS_PIXEL_MAP_FORMAT_RGBA_8888| 32-bit RGBA, with 8 bits each for R (red), G (green), B (blue), and A (alpha). The data is stored from the most significant bit to the least significant bit.|
| OHOS_PIXEL_MAP_FORMAT_RGB_565| 16-bit RGB, with 5, 6, and 5 bits for R, G, and B, respectively. The storage sequence is from the most significant bit to the least significant bit.|

**Since**

8

## anonymous enum


### OH_AccessPixels()


```
int32_t OH_AccessPixels (napi_env env, napi_value value, void ** addrPtr )
```
**Description**

Obtains the memory address of a **PixelMap** object and locks the memory.

After the function is executed successfully, **\*addrPtr** is the address of the memory to be accessed. After the access operation is complete, you must use [OH_UnAccessPixels](#oh_unaccesspixels) to unlock the memory. Otherwise, the resources in the memory cannot be released. After the memory is unlocked, its address cannot be accessed or operated.

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Indicates the NAPI environment pointer.|
| value | Indicates the **PixelMap** object at the application layer.|
| addrPtr | Indicates the double pointer to the memory address.|

**See**

UnAccessPixels

**Returns**

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**
8


### OH_GetImageInfo()


```
struct OhosPixelMapCreateOps OH_GetImageInfo (napi_env env, napi_value value, OhosPixelMapInfo * info )
```
**Description**

Obtains the **PixelMap** information and stores the information to the [OhosPixelMapInfo](_ohos_pixel_map_info.md) struct.

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Indicates the NAPI environment pointer.|
| value | Indicates the **PixelMap** object at the application layer.|
| info | Indicates the pointer to the object that stores the information obtained. For details, see [OhosPixelMapInfo](_ohos_pixel_map_info.md).|

**Returns**

Returns **0** if the information is obtained and stored successfully; returns an error code otherwise.

**See**

[OhosPixelMapInfo](_ohos_pixel_map_info.md)

**Since**

8

### OH_UnAccessPixels()


```
int32_t OH_UnAccessPixels (napi_env env, napi_value value )
```
**Description**

Unlocks the memory of a **PixelMap** object. This function is used with [OH_AccessPixels](#oh_accesspixels) in pairs.

**Parameters**

| Name| Description|
| -------- | -------- |
| env | Indicates the NAPI environment pointer.|
| value | Indicates the **PixelMap** object at the application layer.|

**Returns**

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful; returns an error code otherwise.

**See**

AccessPixels

**Since**

8

