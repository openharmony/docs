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
| [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | Defines the options used for creating a pixel map.  | 


### Types

| Name | Description | 
| -------- | -------- |
| [NativePixelMap](#nativepixelmap) | Defines the data type name of the native pixel map. |


### Enums

| Name | Description | 
| -------- | -------- |
| { OHOS_IMAGE_RESULT_SUCCESS = 0, OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | Enumerates the error codes returned by a function.  | 
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0, OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3, OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | Enumerates the pixel formats.  | 
| { OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0, OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1, OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2, OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 } | Enumerates the pixel map alpha types. | 
| { OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE = 0, OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP = 1 } | Enumerates the pixel map scale modes. | 
| { OHOS_PIXEL_MAP_READ_ONLY = 0, OHOS_PIXEL_MAP_EDITABLE = 1 } | Enumerates the pixel map editing types.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_GetImageInfo](#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_ohos_pixel_map_info.md) \*info) | Obtains the **PixelMap** information and stores the information to the [OhosPixelMapInfo](_ohos_pixel_map_info.md) structure.  | 
| [OH_AccessPixels](#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | Obtains the memory address of the **PixelMap** object data and locks the memory.  | 
| [OH_UnAccessPixels](#oh_unaccesspixels) (napi_env env, napi_value value) | Unlocks the memory of the **PixelMap** object data. This function is used with [OH_AccessPixels](#oh_accesspixels) in pairs.  | 
| [OH_PixelMap_CreatePixelMap](#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | Creates a **PixelMap** object.  | 
| [OH_PixelMap_CreateAlphaPixelMap](#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | Creates a **PixelMap** object that contains only alpha channel information.  | 
| [OH_PixelMap_InitNativePixelMap](#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | Initializes a **PixelMap** object.  | 
| [OH_PixelMap_GetBytesNumberPerRow](#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*num) | Obtains the number of bytes per row of a **PixelMap** object.  | 
| [OH_PixelMap_GetIsEditable](#oh_pixelmap_getiseditable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*[editable](image__pixel__map__napi_8h.md#editable)) | Checks whether a **PixelMap** object is editable.  | 
| [OH_PixelMap_IsSupportAlpha](#oh_pixelmap_issupportalpha) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*alpha) | Checks whether a **PixelMap** object supports alpha channels.  | 
| [OH_PixelMap_SetAlphaAble](#oh_pixelmap_setalphaable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t alpha) | Sets an alpha channel for a **PixelMap** object.  | 
| [OH_PixelMap_GetDensity](#oh_pixelmap_getdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*density) | Obtains the pixel density of a **PixelMap** object.  | 
| [OH_PixelMap_SetDensity](#oh_pixelmap_setdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t density) | Sets the pixel density for a **PixelMap** object.  | 
| [OH_PixelMap_SetOpacity](#oh_pixelmap_setopacity) (const [NativePixelMap](#nativepixelmap) \*native, float opacity) | Sets the opacity for a **PixelMap** object.  | 
| [OH_PixelMap_Scale](#oh_pixelmap_scale) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | Scales a **PixelMap** object.  | 
| [OH_PixelMap_Translate](#oh_pixelmap_translate) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | Translates a **PixelMap** object.  | 
| [OH_PixelMap_Rotate](#oh_pixelmap_rotate) (const [NativePixelMap](#nativepixelmap) \*native, float angle) | Rotates a **PixelMap** object.  | 
| [OH_PixelMap_Flip](#oh_pixelmap_flip) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y) | Flips a **PixelMap** object.  | 
| [OH_PixelMap_Crop](#oh_pixelmap_crop) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y, int32_t [width](image__pixel__map__napi_8h.md#width), int32_t [height](image__pixel__map__napi_8h.md#height)) | Crops a **PixelMap** object.  | 

## Type Description


### NativePixelMap

  
```
typedef struct NativePixelMapNativePixelMap
```
**Description:**<br/>
Defines the data type name of the native pixel map.

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

### anonymous enum

  
```
anonymous enum
```
**Description:**<br/>
Enumerates the pixel map alpha types.

| Name | Description | 
| -------- | -------- |
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN  | Unknown format. | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE  | Opaque format. | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL  | Premultiplied format. | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL  | Unpremultiplied format. | 


### anonymous enum

  
```
anonymous enum
```
**Description:**<br/>
Enumerates the pixel map scale modes.

| Name | Description | 
| -------- | -------- |
| OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE  | Adaptation to the target image size. | 
| OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP  | Cropping the center portion of an image to the target size. | 


### anonymous enum

  
```
anonymous enum
```
**Description:**<br/>
Enumerates the pixel map editing types.

| Name | Description | 
| -------- | -------- |
| OHOS_PIXEL_MAP_READ_ONLY  | Read-only. | 
| OHOS_PIXEL_MAP_EDITABLE  | Editable. | 


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

### OH_PixelMap_CreateAlphaPixelMap()

  
```
int32_t OH_PixelMap_CreateAlphaPixelMap (napi_env env, napi_value source, napi_value * alpha )
```
**Description:**<br/>
Creates a **PixelMap** object that contains only alpha channel information.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the NAPI environment pointer.  | 
| source | Indicates the options for setting the **PixelMap** object.  | 
| alpha | Indicates the pointer to the alpha channel.  | 

**Returns**

Returns a **PixelMap** object if the operation is successful; returns an error code otherwise.

 **See**

CreateAlphaPixelMap


### OH_PixelMap_CreatePixelMap()

  
```
int32_t OH_PixelMap_CreatePixelMap (napi_env env, OhosPixelMapCreateOps info, void * buf, size_t len, napi_value * res )
```
**Description:**<br/>
Creates a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the NAPI environment pointer.  | 
| info | Indicates the options for setting the **PixelMap** object.  | 
| buf | Indicates the pointer to the buffer of the image.  | 
| len | Indicates the image size.  | 
| res | Indicates the pointer to the **PixelMap** object at the application layer.  | 

**Returns**

Returns a **PixelMap** object if the operation is successful; returns an error code otherwise.

 **See**

CreatePixelMap


### OH_PixelMap_Crop()

  
```
int32_t OH_PixelMap_Crop (const NativePixelMap * native, int32_t x, int32_t y, int32_t width, int32_t height )
```
**Description:**<br/>
Crops a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| x | Indicates the x-coordinate of the upper left corner of the target image.  | 
| y | Indicates the y-coordinate of the upper left corner of the target image.  | 
| width | Indicates the width of the cropped region.  | 
| height | Indicates the height of the cropped region.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

Crop


### OH_PixelMap_Flip()

  
```
int32_t OH_PixelMap_Flip (const NativePixelMap * native, int32_t x, int32_t y )
```
**Description:**<br/>
Flips a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| x | Specifies whether to flip around the x axis.  | 
| y | Specifies whether to flip around the y axis.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

Flip


### OH_PixelMap_GetBytesNumberPerRow()

  
```
int32_t OH_PixelMap_GetBytesNumberPerRow (const NativePixelMap * native, int32_t * num )
```
**Description:**<br/>
Obtains the number of bytes per row of a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| num | Indicates the pointer to the number of bytes per row of the **PixelMap** object.  | 

**Returns**

Returns the number of bytes per row of the **PixelMap** object if the operation is successful; returns an error code otherwise.

 **See**

GetBytesNumberPerRow


### OH_PixelMap_GetDensity()

  
```
int32_t OH_PixelMap_GetDensity (const NativePixelMap * native, int32_t * density )
```
**Description:**<br/>
Obtains the pixel density of a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| density | Indicates the pointer to the pixel density.  | 

**Returns**

Returns the pixel density if the operation is successful; returns an error code otherwise.

 **See**

GetDensity


### OH_PixelMap_GetImageInfo()

  
```
int32_t OH_PixelMap_GetImageInfo (const NativePixelMap * native, OhosPixelMapInfo * info )
```
**Description:**<br/>
Obtains the image information of a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| info | Indicates the pointer to the image information.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

[OhosPixelMapInfo](_ohos_pixel_map_info.md)


### OH_PixelMap_GetIsEditable()

  
```
int32_t OH_PixelMap_GetIsEditable (const NativePixelMap * native, int32_t * editable )
```
**Description:**<br/>
Checks whether a **PixelMap** object is editable.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| editable | Indicates the pointer to the editing type of the **PixelMap** object.  | 

**Returns**

Returns an enumerated value that indicates the editing type of the **PixelMap** object if the operation is successful; returns an error code otherwise.

 **See**

GetIsEditable


### OH_PixelMap_InitNativePixelMap()

  
```
NativePixelMap* OH_PixelMap_InitNativePixelMap (napi_env env, napi_value source )
```
**Description:**<br/>
Initializes a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the NAPI environment pointer.  | 
| source | Indicates the options for setting the **PixelMap** object.  | 

**Returns**

Returns a pointer to the **NativePixelMap** object if the operation is successful; returns an error code otherwise.

 **See**

InitNativePixelMap


### OH_PixelMap_IsSupportAlpha()

  
```
int32_t OH_PixelMap_IsSupportAlpha (const NativePixelMap * native, int32_t * alpha )
```
**Description:**<br/>
Checks whether a **PixelMap** object supports alpha channels.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| alpha | Indicates the pointer to the support for alpha channels.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

IsSupportAlpha


### OH_PixelMap_Rotate()

  
```
int32_t OH_PixelMap_Rotate (const NativePixelMap * native, float angle )
```
**Description:**<br/>
Rotates a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| angle | Indicates the angle to rotate.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

Rotate


### OH_PixelMap_Scale()

  
```
int32_t OH_PixelMap_Scale (const NativePixelMap * native, float x, float y )
```
**Description:**<br/>
Scales a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| x | Indicates the scaling ratio of the width.  | 
| y | Indicates the scaling ratio of the height.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

Scale


### OH_PixelMap_SetAlphaAble()

  
```
int32_t OH_PixelMap_SetAlphaAble (const NativePixelMap * native, int32_t alpha )
```
**Description:**<br/>
Sets an alpha channel for a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| alpha | Indicates the alpha channel to set.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

SetAlphaAble


### OH_PixelMap_SetDensity()

  
```
int32_t OH_PixelMap_SetDensity (const NativePixelMap * native, int32_t density )
```
**Description:**<br/>
Sets the pixel density for a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| density | Indicates the pixel density to set.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

GetDensity


### OH_PixelMap_SetOpacity()

  
```
int32_t OH_PixelMap_SetOpacity (const NativePixelMap * native, float opacity )
```
**Description:**<br/>
Sets the opacity for a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| opacity | Indicates the opacity to set.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

SetOpacity


### OH_PixelMap_Translate()

  
```
int32_t OH_PixelMap_Translate (const NativePixelMap * native, float x, float y )
```
**Description:**<br/>
Translates a **PixelMap** object.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| x | Indicates the horizontal distance to translate.  | 
| y | Indicates the vertical distance to translate.  | 

**Returns**

Returns **0** if the operation is successful; returns an error code otherwise.

 **See**

Translate


### OH_PixelMap_UnAccessPixels()

  
```
int32_t OH_PixelMap_UnAccessPixels (const NativePixelMap * native)
```
**Description:**<br/>
Unlocks the memory of the **NativePixelMap** object data. This function is used with [OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels) in pairs.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 

**Returns**

Returns OHOS_IMAGE_RESULT_SUCCESS if the operation is successful; returns an error code otherwise.

 **See**

AccessPixels


### OH_PixelMap_AccessPixels()

  
```
int32_t OH_PixelMap_AccessPixels(const NativePixelMap* native, void** addr)
```
**Description:**<br/>
Obtains the memory address of a **NativePixelMap** object and locks the memory.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| native | Indicates the pointer to a **NativePixelMap** object.  | 
| addr | Indicates the double pointer to the memory address.  |

**Returns**

Returns OHOS_IMAGE_RESULT_SUCCESS if the operation is successful; returns an error code otherwise.

 **See**

UnAccessPixels


### OH_UnAccessPixels()

  
```
int32_t OH_UnAccessPixels (napi_env env, napi_value value )
```
**Description:**<br/>
Unlocks the memory of a **PixelMap** object. This function is used with [OH_AccessPixels](#oh_accesspixels) in pairs.

 **Parameters**

| Name | Description | 
| -------- | -------- |
| env | Indicates the NAPI environment pointer.  | 
| value | Indicates the **PixelMap** object at the application layer.  | 

**Returns**

Returns OHOS_IMAGE_RESULT_SUCCESS if the operation is successful; returns an error code otherwise.

 **See**

AccessPixels
