# ImageEffect


## Overview

The ImageEffect module provides the APIs for editing an image.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [image_effect.h](image__effect_8h.md) | Declares the APIs related to an image effector.| 
| [image_effect_errors.h](image__effect__errors_8h.md) | Declares the error codes used by an image effector.| 
| [image_effect_filter.h](image__effect__filter_8h.md) | Declare the APIs related to an image effect filter.| 


### Structs

| Name| Description| 
| -------- | -------- |
| union  [ImageEffect_DataValue](union_image_effect___data_value.md) | Describes the data values.| 
| struct  [ImageEffect_Any](_image_effect___any.md) | Describes the image effect parameters.| 
| struct  [ImageEffect_FilterNames](_image_effect___filter_names.md) | Describes the filter name information.| 
| struct  [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) | Describes the callback functions of a custom image effect filter.| 
| struct  [ImageEffect_Region](_image_effect___region.md) | Describes the image region.| 
| struct  [ImageEffect_Size](_image_effect___size.md) | Describes the image size.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [OH_EFFECT_BRIGHTNESS_FILTER](#oh_effect_brightness_filter)   "Brightness" | Brightness filter. The corresponding parameter is **OH_EFFECT_FILTER_INTENSITY_KEY** and the parameter type is **EFFECT_DATA_TYPE_FLOAT**.| 
| [OH_EFFECT_CONTRAST_FILTER](#oh_effect_contrast_filter)   "Contrast" | Contrast filter. The corresponding parameter is **OH_EFFECT_FILTER_INTENSITY_KEY** and the parameter type is **EFFECT_DATA_TYPE_FLOAT**.| 
| [OH_EFFECT_CROP_FILTER](#oh_effect_crop_filter)   "Crop" | Crop filter. The corresponding parameter is **OH_EFFECT_FILTER_REGION_KEY**, the parameter type is **EFFECT_DATA_TYPE_PTR**, and the parameter value is [ImageEffect_Region](_image_effect___region.md).| 
| [OH_EFFECT_FILTER_INTENSITY_KEY](#oh_effect_filter_intensity_key)   "FilterIntensity" | Intensity filter.| 
| [OH_EFFECT_FILTER_REGION_KEY](#oh_effect_filter_region_key)   "FilterRegion" | Image region filter.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImageEffect](#oh_imageeffect) [OH_ImageEffect](#oh_imageeffect) | Defines a struct for the image effector.| 
| typedef enum [ImageEffect_ErrorCode](#imageeffect_errorcode-1) [ImageEffect_ErrorCode](#imageeffect_errorcode) | Defines an enum for the error codes used by the image effector.| 
| typedef struct [OH_EffectFilter](#oh_effectfilter) [OH_EffectFilter](#oh_effectfilter) | Defines a struct for the image effect filter.| 
| typedef enum [ImageEffect_DataType](#imageeffect_datatype) [ImageEffect_DataType](#imageeffect_datatype) | Defines an enum for the data types.| 
| typedef union [ImageEffect_DataValue](union_image_effect___data_value.md) [ImageEffect_DataValue](#imageeffect_datavalue) | Defines a union for the data values.| 
| typedef struct [ImageEffect_Any](_image_effect___any.md) [ImageEffect_Any](#imageeffect_any) | Defines a struct for the image effect parameters.| 
| typedef enum [ImageEffect_Format](#imageeffect_format-1) [ImageEffect_Format](#imageeffect_format) | Defines an enum for the pixel formats.| 
| typedef enum [ImageEffect_BufferType](#imageeffect_buffertype-1) [ImageEffect_BufferType](#imageeffect_buffertype) | Defines an enum for the buffer types.| 
| typedef struct [OH_EffectFilterInfo](#oh_effectfilterinfo) [OH_EffectFilterInfo](#oh_effectfilterinfo) | Defines a struct for the image effect filter information.| 
| typedef struct [ImageEffect_FilterNames](_image_effect___filter_names.md) [ImageEffect_FilterNames](#imageeffect_filternames) | Defines a struct for the filter name information.| 
| typedef struct [OH_EffectBufferInfo](#oh_effectbufferinfo) [OH_EffectBufferInfo](#oh_effectbufferinfo) | Defines a struct for the image buffer information.| 
| typedef bool(\* [OH_EffectFilterDelegate_SetValue](#oh_effectfilterdelegate_setvalue)) ([OH_EffectFilter](#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | Defines a pointer to the callback function for setting parameters of a custom filter. It is used to verify parameters and parameter values.| 
| typedef void(\* [OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata)) ([OH_EffectFilter](#oh_effectfilter) \*filter, [OH_EffectBufferInfo](#oh_effectbufferinfo) \*info) | Defines a pointer to the callback function used by a custom filter to push image data to the next-level filter.| 
| typedef bool(\* [OH_EffectFilterDelegate_Render](#oh_effectfilterdelegate_render)) ([OH_EffectFilter](#oh_effectfilter) \*filter, [OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, [OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata) pushData) | Defines a pointer to the callback function for rendering an image using a custom filter.| 
| typedef bool(\* [OH_EffectFilterDelegate_Save](#oh_effectfilterdelegate_save)) ([OH_EffectFilter](#oh_effectfilter) \*filter, char \*\*info) | Defines a pointer to the callback function for serializing a custom filter. Filters are serialized in JSON format.| 
| typedef [OH_EffectFilter](#oh_effectfilter) \*(\* [OH_EffectFilterDelegate_Restore](#oh_effectfilterdelegate_restore)) (const char \*info) | Defines a pointer to the callback function for deserializing a custom filter.| 
| typedef struct [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) [ImageEffect_FilterDelegate](#imageeffect_filterdelegate) | Defines a struct for the callback functions of a custom image effect filter.| 
| typedef struct [ImageEffect_Region](_image_effect___region.md) [ImageEffect_Region](#imageeffect_region) | Defines a struct for the image region.| 
| typedef struct [ImageEffect_Size](_image_effect___size.md) [ImageEffect_Size](#imageeffect_size) | Defines a struct for the image size.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ImageEffect_ErrorCode](#imageeffect_errorcode-1) {<br>EFFECT_SUCCESS = 0, EFFECT_ERROR_PERMISSION_DENIED = 201,<br>EFFECT_ERROR_PARAM_INVALID = 401, EFFECT_BUFFER_SIZE_NOT_MATCH = 29000001,<br>EFFECT_COLOR_SPACE_NOT_MATCH = 29000002, EFFECT_INPUT_OUTPUT_NOT_MATCH = 29000101,<br>EFFECT_EFFECT_NUMBER_LIMITED = 29000102, EFFECT_INPUT_OUTPUT_NOT_SUPPORTED = 29000103,<br>EFFECT_ALLOCATE_MEMORY_FAILED = 29000104, EFFECT_PARAM_ERROR = 29000121,<br>EFFECT_KEY_ERROR = 29000122, EFFECT_UNKNOWN = 29000199<br>} | Enumerates the error codes used by the image effector.| 
| [ImageEffect_DataType](#imageeffect_datatype-1) {<br>EFFECT_DATA_TYPE_UNKNOWN = 0, EFFECT_DATA_TYPE_INT32 = 1,<br>EFFECT_DATA_TYPE_FLOAT = 2, EFFECT_DATA_TYPE_DOUBLE = 3,<br>EFFECT_DATA_TYPE_CHAR = 4, EFFECT_DATA_TYPE_LONG = 5,<br>EFFECT_DATA_TYPE_BOOL = 6, EFFECT_DATA_TYPE_PTR = 7<br>} | Enumerates the data types.| 
| [ImageEffect_Format](#imageeffect_format-1) {<br>EFFECT_PIXEL_FORMAT_UNKNOWN = 0, EFFECT_PIXEL_FORMAT_RGBA8888 = 1,<br>EFFECT_PIXEL_FORMAT_NV21 = 2, EFFECT_PIXEL_FORMAT_NV12 = 3,<br>EFFECT_PIXEL_FORMAT_RGBA1010102 = 4, EFFECT_PIXEL_FORMAT_YCBCR_P010 = 5,<br>EFFECT_PIXEL_FORMAT_YCRCB_P010 = 6<br>} | Enumerates the pixel formats.| 
| [ImageEffect_BufferType](#imageeffect_buffertype-1) { EFFECT_BUFFER_TYPE_UNKNOWN = 0,<br>EFFECT_BUFFER_TYPE_PIXEL = 1, EFFECT_BUFFER_TYPE_TEXTURE = 2 } | Enumerates the buffer types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_ImageEffect](#oh_imageeffect) \* [OH_ImageEffect_Create](#oh_imageeffect_create) (const char \*name) | Creates an **OH_ImageEffect** instance. The instance must be released by calling [OH_ImageEffect_Release](#oh_imageeffect_release) when it is no longer needed.| 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_ImageEffect_AddFilter](#oh_imageeffect_addfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*filterName) | Adds a filter.| 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_ImageEffect_InsertFilter](#oh_imageeffect_insertfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | Inserts a filter.| 
| int32_t [OH_ImageEffect_RemoveFilter](#oh_imageeffect_removefilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*filterName) | Removes a filter.| 
| int32_t [OH_ImageEffect_GetFilterCount](#oh_imageeffect_getfiltercount) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | Obtains the number of added filters.| 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_ImageEffect_GetFilter](#oh_imageeffect_getfilter) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, uint32_t index) | Obtains the information about a filter.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Configure](#oh_imageeffect_configure) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | Configures an image effector.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputSurface](#oh_imageeffect_setoutputsurface) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OHNativeWindow \*nativeWindow) | Sets an output surface.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_GetInputSurface](#oh_imageeffect_getinputsurface) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OHNativeWindow \*\*nativeWindow) | Obtains an input surface.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetInputPixelmap](#oh_imageeffect_setinputpixelmap) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | Sets an input pixel map.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputPixelmap](#oh_imageeffect_setoutputpixelmap) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | Sets an output pixel map.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetInputNativeBuffer](#oh_imageeffect_setinputnativebuffer) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | Sets an input native buffer.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputNativeBuffer](#oh_imageeffect_setoutputnativebuffer) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | Sets an output native buffer.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetInputUri](#oh_imageeffect_setinputuri) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*uri) | Sets an input URI.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_SetOutputUri](#oh_imageeffect_setoutputuri) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, const char \*uri) | Sets an output URI.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Start](#oh_imageeffect_start) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | Starts an image effector.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Stop](#oh_imageeffect_stop) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | Stops an image effector.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Release](#oh_imageeffect_release) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect) | Releases an **OH_ImageEffect** instance.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_ImageEffect_Save](#oh_imageeffect_save) ([OH_ImageEffect](#oh_imageeffect) \*imageEffect, char \*\*info) | Serializes an image effector.| 
| [OH_ImageEffect](#oh_imageeffect) \* [OH_ImageEffect_Restore](#oh_imageeffect_restore) (const char \*info) | Deserializes an image effector.| 
| [OH_EffectFilterInfo](#oh_effectfilterinfo) \* [OH_EffectFilterInfo_Create](#oh_effectfilterinfo_create) () | Creates an **OH_EffectFilterInfo** instance. The instance must be released by calling [OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release) when it is no longer needed.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_SetFilterName](#oh_effectfilterinfo_setfiltername) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, const char \*name) | Sets a filter name.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_GetFilterName](#oh_effectfilterinfo_getfiltername) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, char \*\*name) | Obtains a filter name.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedBufferTypes](#oh_effectfilterinfo_setsupportedbuffertypes) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_BufferType](#imageeffect_buffertype) \*bufferTypeArray) | Sets the buffer types supported by a filter.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedBufferTypes](#oh_effectfilterinfo_getsupportedbuffertypes) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_BufferType](#imageeffect_buffertype) \*\*bufferTypeArray) | Obtains the buffer types supported by a filter.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedFormats](#oh_effectfilterinfo_setsupportedformats) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_Format](#imageeffect_format) \*formatArray) | Sets the pixel formats supported by a filter.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedFormats](#oh_effectfilterinfo_getsupportedformats) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_Format](#imageeffect_format) \*\*formatArray) | Obtains the pixel formats supported by a filter.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release) ([OH_EffectFilterInfo](#oh_effectfilterinfo) \*info) | Destroys an **OH_EffectFilterInfo** instance.| 
| [OH_EffectBufferInfo](#oh_effectbufferinfo) \* [OH_EffectBufferInfo_Create](#oh_effectbufferinfo_create) () | Creates an **OH_EffectBufferInfo** instance. The instance must be released by calling [OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release) when it is no longer needed.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetAddr](#oh_effectbufferinfo_setaddr) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, void \*addr) | Sets the address of an effect buffer.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetAddr](#oh_effectbufferinfo_getaddr) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, void \*\*addr) | Obtains the address of an effect buffer.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetWidth](#oh_effectbufferinfo_setwidth) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t width) | Sets the image width.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetWidth](#oh_effectbufferinfo_getwidth) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t \*width) | Obtains the image width.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetHeight](#oh_effectbufferinfo_setheight) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t height) | Sets the image height.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetHeight](#oh_effectbufferinfo_getheight) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t \*height) | Obtains the image height.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetRowSize](#oh_effectbufferinfo_setrowsize) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t rowSize) | Sets the number of bytes per row for an image.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetRowSize](#oh_effectbufferinfo_getrowsize) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, int32_t \*rowSize) | Obtains the number of bytes per row of an image.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_SetEffectFormat](#oh_effectbufferinfo_seteffectformat) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, [ImageEffect_Format](#imageeffect_format) format) | Sets the pixel format for an image.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_GetEffectFormat](#oh_effectbufferinfo_geteffectformat) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info, [ImageEffect_Format](#imageeffect_format) \*format) | Obtains the pixel format of an image.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release) ([OH_EffectBufferInfo](#oh_effectbufferinfo) \*info) | Destroys an **OH_EffectBufferInfo** instance.| 
| [OH_EffectFilter](#oh_effectfilter) \* [OH_EffectFilter_Create](#oh_effectfilter_create) (const char \*name) | Creates an **OH_EffectFilter** instance. The instance must be released by calling [OH_EffectFilter_Release](#oh_effectfilter_release) when it is no longer needed.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_SetValue](#oh_effectfilter_setvalue) ([OH_EffectFilter](#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | Sets a filter parameter.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_GetValue](#oh_effectfilter_getvalue) ([OH_EffectFilter](#oh_effectfilter) \*filter, const char \*key, [ImageEffect_Any](_image_effect___any.md) \*value) | Obtains a filter parameter.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_Register](#oh_effectfilter_register) (const [OH_EffectFilterInfo](#oh_effectfilterinfo) \*info, const [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) \*delegate) | Registers a custom filter.| 
| [ImageEffect_FilterNames](_image_effect___filter_names.md) \* [OH_EffectFilter_LookupFilters](#oh_effectfilter_lookupfilters) (const char \*key) | Obtains filters that meet given conditions.| 
| void [OH_EffectFilter_ReleaseFilterNames](#oh_effectfilter_releasefilternames) () | Releases filter name memory resources.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_LookupFilterInfo](#oh_effectfilter_lookupfilterinfo) (const char \*name, [OH_EffectFilterInfo](#oh_effectfilterinfo) \*info) | Obtains the filter information.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_Render](#oh_effectfilter_render) ([OH_EffectFilter](#oh_effectfilter) \*filter, OH_PixelmapNative \*inputPixelmap, OH_PixelmapNative \*outputPixelmap) | Starts image rendering.| 
| [ImageEffect_ErrorCode](#imageeffect_errorcode) [OH_EffectFilter_Release](#oh_effectfilter_release) ([OH_EffectFilter](#oh_effectfilter) \*filter) | Destroys an **OH_EffectFilter** instance.| 


## Macro Description


### OH_EFFECT_BRIGHTNESS_FILTER

```
#define OH_EFFECT_BRIGHTNESS_FILTER   "Brightness"
```

**Description**

Brightness filter. The corresponding parameter is **OH_EFFECT_FILTER_INTENSITY_KEY** and the parameter type is **EFFECT_DATA_TYPE_FLOAT**.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EFFECT_CONTRAST_FILTER

```
#define OH_EFFECT_CONTRAST_FILTER   "Contrast"
```

**Description**

Contrast filter. The corresponding parameter is **OH_EFFECT_FILTER_INTENSITY_KEY** and the parameter type is **EFFECT_DATA_TYPE_FLOAT**.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EFFECT_CROP_FILTER

```
#define OH_EFFECT_CROP_FILTER   "Crop"
```

**Description**

Crop filter. The corresponding parameter is **OH_EFFECT_FILTER_REGION_KEY**, the parameter type is **EFFECT_DATA_TYPE_PTR**, and the parameter value is [ImageEffect_Region](_image_effect___region.md).

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EFFECT_FILTER_INTENSITY_KEY

```
#define OH_EFFECT_FILTER_INTENSITY_KEY   "FilterIntensity"
```

**Description**

Intensity filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EFFECT_FILTER_REGION_KEY

```
#define OH_EFFECT_FILTER_REGION_KEY   "FilterRegion"
```

**Description**

Image region filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


## Type Description


### ImageEffect_Any

```
typedef struct ImageEffect_Any ImageEffect_Any
```

**Description**

Describes the image effect parameters.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_BufferType

```
typedef enum ImageEffect_BufferType ImageEffect_BufferType
```

**Description**

Defines an enum for the buffer types.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_DataType

```
typedef enum ImageEffect_DataType ImageEffect_DataType
```

**Description**

Defines an enum for the data types.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_DataValue

```
typedef union ImageEffect_DataValue ImageEffect_DataValue
```

**Description**

Defines a union for the data values.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_ErrorCode

```
typedef enum ImageEffect_ErrorCode ImageEffect_ErrorCode
```

**Description**

Defines an enum for the error codes used by the image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_FilterDelegate

```
typedef struct ImageEffect_FilterDelegate ImageEffect_FilterDelegate
```

**Description**

Describes the callback functions of a custom image effect filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_FilterNames

```
typedef struct ImageEffect_FilterNames ImageEffect_FilterNames
```

**Description**

Describes the filter name information.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_Format

```
typedef enum ImageEffect_Format ImageEffect_Format
```

**Description**

Defines an enum for the pixel formats.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_Region

```
typedef struct ImageEffect_Region ImageEffect_Region
```

**Description**

Describes the image region.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### ImageEffect_Size

```
typedef struct ImageEffect_Size ImageEffect_Size
```

**Description**

Describes the image size.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EffectBufferInfo

```
typedef struct OH_EffectBufferInfo OH_EffectBufferInfo
```

**Description**

Defines a struct for the image buffer information.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EffectFilter

```
typedef struct OH_EffectFilter OH_EffectFilter
```

**Description**

Defines a struct for the image effect filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EffectFilterDelegate_PushData

```
typedef void(* OH_EffectFilterDelegate_PushData) (OH_EffectFilter *filter, OH_EffectBufferInfo *info)
```

**Description**

Defines a pointer to the callback function used by a custom filter to push image data to the next-level filter. The function pointer must be actively called in the callback of [OH_EffectFilterDelegate_Render](#oh_effectfilterdelegate_render).

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| info | Pointer to the buffer information, which is [OH_EffectBufferInfo](#oh_effectbufferinfo).| 


### OH_EffectFilterDelegate_Render

```
typedef bool(* OH_EffectFilterDelegate_Render) (OH_EffectFilter *filter, OH_EffectBufferInfo *info, OH_EffectFilterDelegate_PushData pushData)
```

**Description**

Defines a pointer to the callback function for rendering an image using a custom filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| info | Pointer to the buffer information, which is [OH_EffectBufferInfo](#oh_effectbufferinfo).| 
| pushData | Callback function [OH_EffectFilterDelegate_PushData](#oh_effectfilterdelegate_pushdata) used by the custom filter to push image data to the next-level filter.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.


### OH_EffectFilterDelegate_Restore

```
typedef OH_EffectFilter*(* OH_EffectFilterDelegate_Restore) (const char *info)
```

**Description**

Defines a pointer to the callback function for deserializing a custom filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to a serialized JSON string.| 

**Returns**

Returns an **OH_EffectFilter** instance if the operation is successful; returns a null pointer otherwise.


### OH_EffectFilterDelegate_Save

```
typedef bool(* OH_EffectFilterDelegate_Save) (OH_EffectFilter *filter, char **info)
```

**Description**

Defines a pointer to the callback function for serializing a custom filter. Filters are serialized in JSON format.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| info | Double pointer to a char array holding a serialized JSON string.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.


### OH_EffectFilterDelegate_SetValue

```
typedef bool(* OH_EffectFilterDelegate_SetValue) (OH_EffectFilter *filter, const char *key, const ImageEffect_Any *value)
```

**Description**

Defines a pointer to the callback function for setting parameters of a custom filter. It is used to verify parameters and parameter values.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| key | Pointer to the key of a filter parameter.| 
| value | Pointer to the value of the filter parameter.| 

**Returns**

Returns **true** if the parameter is valid; returns **false** otherwise.


### OH_EffectFilterInfo

```
typedef struct OH_EffectFilterInfo OH_EffectFilterInfo
```

**Description**

Defines a struct for the image effect filter information.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_ImageEffect

```
typedef struct OH_ImageEffect OH_ImageEffect
```

**Description**

Defines a struct for the image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


## Enum Description


### ImageEffect_BufferType

```
enum ImageEffect_BufferType
```

**Description**

Enumerates the buffer types.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| EFFECT_BUFFER_TYPE_UNKNOWN | Undefined type.| 
| EFFECT_BUFFER_TYPE_PIXEL | Pixel image type.| 
| EFFECT_BUFFER_TYPE_TEXTURE | Texture type.| 


### ImageEffect_DataType

```
enum ImageEffect_DataType
```

**Description**

Enumerates the data types.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| EFFECT_DATA_TYPE_UNKNOWN | Undefined type.| 
| EFFECT_DATA_TYPE_INT32 | Integer.| 
| EFFECT_DATA_TYPE_FLOAT | Single-precision floating point.| 
| EFFECT_DATA_TYPE_DOUBLE | Double-precision floating point.| 
| EFFECT_DATA_TYPE_CHAR | Byte.| 
| EFFECT_DATA_TYPE_LONG | Long integer.| 
| EFFECT_DATA_TYPE_BOOL | Boolean.| 
| EFFECT_DATA_TYPE_PTR | Pointer.| 


### ImageEffect_ErrorCode

```
enum ImageEffect_ErrorCode
```

**Description**

Enumerates the error codes used by the image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| EFFECT_SUCCESS | The operation is successful.| 
| EFFECT_ERROR_PERMISSION_DENIED | Permission verification fails.| 
| EFFECT_ERROR_PARAM_INVALID | Parameter check fails.| 
| EFFECT_BUFFER_SIZE_NOT_MATCH | The output buffer size does not match.| 
| EFFECT_COLOR_SPACE_NOT_MATCH | The input and output color spaces do not match.| 
| EFFECT_INPUT_OUTPUT_NOT_MATCH | The input and output configurations do not match. For example, the input is a surface, but the output is a pixel map.| 
| EFFECT_EFFECT_NUMBER_LIMITED | The maximum number is reached.| 
| EFFECT_INPUT_OUTPUT_NOT_SUPPORTED | The input or output configuration is not supported.| 
| EFFECT_ALLOCATE_MEMORY_FAILED | Requesting for the buffer fails.| 
| EFFECT_PARAM_ERROR | Invalid parameter value. For example, the filter parameter value is invalid.| 
| EFFECT_KEY_ERROR | Invalid parameter. For example, the filter parameter is invalid.| 
| EFFECT_UNKNOWN | Undefined error.| 


### ImageEffect_Format

```
enum ImageEffect_Format
```

**Description**

Enumerates the pixel formats.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

| Value| Description| 
| -------- | -------- |
| EFFECT_PIXEL_FORMAT_UNKNOWN | Undefined format.| 
| EFFECT_PIXEL_FORMAT_RGBA8888 | RGBA8888.| 
| EFFECT_PIXEL_FORMAT_NV21 | NV21.| 
| EFFECT_PIXEL_FORMAT_NV12 | NV12.| 
| EFFECT_PIXEL_FORMAT_RGBA1010102 | 10-bit RGBA.| 
| EFFECT_PIXEL_FORMAT_YCBCR_P010 | 10-bit YCBCR420.| 
| EFFECT_PIXEL_FORMAT_YCRCB_P010 | 10-bit YCRCB420.| 


## Function Description


### OH_EffectBufferInfo_Create()

```
OH_EffectBufferInfo* OH_EffectBufferInfo_Create ()
```

**Description**

Creates an **OH_EffectBufferInfo** instance. The instance must be released by calling [OH_EffectBufferInfo_Release](#oh_effectbufferinfo_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Returns**

Returns the pointer to the **OH_EffectBufferInfo** instance created if the operation is successful; returns a null pointer otherwise.


### OH_EffectBufferInfo_GetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetAddr (OH_EffectBufferInfo * info, void ** addr )
```

**Description**

Obtains the address of an effect buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| addr | Double pointer to the virtual address of the image buffer.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_GetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetEffectFormat (OH_EffectBufferInfo * info, ImageEffect_Format * format )
```

**Description**

Obtains the pixel format of an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| format | Pointer to the pixel format, which is [ImageEffect_Format](#imageeffect_format).| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_GetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetHeight (OH_EffectBufferInfo * info, int32_t * height )
```

**Description**

Obtains the image height.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| height | Pointer to the image height, in px.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_GetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetRowSize (OH_EffectBufferInfo * info, int32_t * rowSize )
```

**Description**

Obtains the number of bytes per row of an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| rowSize | Pointer to the number of bytes per row, in bytes.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_GetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_GetWidth (OH_EffectBufferInfo * info, int32_t * width )
```

**Description**

Obtains the image width.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| width | Pointer to the image width, in px.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_Release()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_Release (OH_EffectBufferInfo * info)
```

**Description**

Destroys an **OH_EffectBufferInfo** instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_SetAddr()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetAddr (OH_EffectBufferInfo * info, void * addr )
```

**Description**

Sets the address of an effect buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| addr | Pointer to the virtual address of the image buffer.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_SetEffectFormat()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetEffectFormat (OH_EffectBufferInfo * info, ImageEffect_Format format )
```

**Description**

Sets the pixel format for an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| format | Pixel format, which is [ImageEffect_Format](#imageeffect_format).| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_SetHeight()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetHeight (OH_EffectBufferInfo * info, int32_t height )
```

**Description**

Sets the image height.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| height | Image height, in px.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_SetRowSize()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetRowSize (OH_EffectBufferInfo * info, int32_t rowSize )
```

**Description**

Sets the number of bytes per row for an image.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| rowSize | Number of bytes per row, in bytes.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectBufferInfo_SetWidth()

```
ImageEffect_ErrorCode OH_EffectBufferInfo_SetWidth (OH_EffectBufferInfo * info, int32_t width )
```

**Description**

Sets the image width.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the image information.| 
| width | Image width, in px.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilter_Create()

```
OH_EffectFilter* OH_EffectFilter_Create (const char * name)
```

**Description**

Creates an **OH_EffectFilter** instance. The instance must be released by calling [OH_EffectFilter_Release](#oh_effectfilter_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Pointer to the filter name, for example, **OH_EFFECT_BRIGHTNESS_FILTER**.| 

**Returns**

Returns the pointer to the **OH_EffectFilter** instance created if the operation is successful; returns a null pointer otherwise.


### OH_EffectFilter_GetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_GetValue (OH_EffectFilter * filter, const char * key, ImageEffect_Any * value )
```

**Description**

Obtains a filter parameter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| key | Pointer to the key of the filter parameter, for example, **OH_EFFECT_FILTER_INTENSITY_KEY**.| 
| value | Pointer to the value of the filter parameter.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer; returns **EFFECT_KEY_ERROR** if the key of the filter parameter is invalid.


### OH_EffectFilter_LookupFilterInfo()

```
ImageEffect_ErrorCode OH_EffectFilter_LookupFilterInfo (const char * name, OH_EffectFilterInfo * info )
```

**Description**

Obtains the filter information.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Pointer to the filter name.| 
| info | Pointer to the filter information, which is [OH_EffectFilterInfo](#oh_effectfilterinfo).| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer or an invalid value.


### OH_EffectFilter_LookupFilters()

```
ImageEffect_FilterNames* OH_EffectFilter_LookupFilters (const char * key)
```

**Description**

Obtains filters that meet given conditions.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| key | Pointer to the conditions. You can use the keyword **Default** to obtain all filters.| 

**Returns**

Returns a list of filter names, which is [ImageEffect_FilterNames](_image_effect___filter_names.md).


### OH_EffectFilter_Register()

```
ImageEffect_ErrorCode OH_EffectFilter_Register (const OH_EffectFilterInfo * info, const ImageEffect_FilterDelegate * delegate )
```

**Description**

Registers a custom filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information, which is [OH_EffectFilterInfo](#oh_effectfilterinfo).| 
| delegate | Pointer to the callback function [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) of the filter.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilter_Release()

```
ImageEffect_ErrorCode OH_EffectFilter_Release (OH_EffectFilter * filter)
```

**Description**

Destroys an **OH_EffectFilter** instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilter_ReleaseFilterNames()

```
void OH_EffectFilter_ReleaseFilterNames ()
```

**Description**

Releases filter name memory resources.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12


### OH_EffectFilter_Render()

```
ImageEffect_ErrorCode OH_EffectFilter_Render (OH_EffectFilter * filter, OH_PixelmapNative * inputPixelmap, OH_PixelmapNative * outputPixelmap )
```

**Description**

Starts image rendering.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| inputPixelmap | Pointer to the input image.| 
| outputPixelmap | Pointer to the output image.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilter_SetValue()

```
ImageEffect_ErrorCode OH_EffectFilter_SetValue (OH_EffectFilter * filter, const char * key, const ImageEffect_Any * value )
```

**Description**

Sets a filter parameter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| filter | Pointer to the filter.| 
| key | Pointer to the key of the filter parameter, for example, **OH_EFFECT_FILTER_INTENSITY_KEY**.| 
| value | Pointer to the value of the filter parameter.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer; returns **EFFECT_KEY_ERROR** if the key of the filter parameter is invalid; returns **EFFECT_PARAM_ERROR** if the value of the filter parameter is invalid.


### OH_EffectFilterInfo_Create()

```
OH_EffectFilterInfo* OH_EffectFilterInfo_Create ()
```

**Description**

Creates an **OH_EffectFilterInfo** instance. The instance must be released by calling [OH_EffectFilterInfo_Release](#oh_effectfilterinfo_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Returns**

Returns the pointer to the **OH_EffectFilterInfo** instance created if the operation is successful; returns a null pointer otherwise.


### OH_EffectFilterInfo_GetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetFilterName (OH_EffectFilterInfo * info, char ** name )
```

**Description**

Obtains a filter name.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information.| 
| name | Double pointer to the char array holding the filter name.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilterInfo_GetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedBufferTypes (OH_EffectFilterInfo * info, uint32_t * size, ImageEffect_BufferType ** bufferTypeArray )
```

**Description**

Obtains the buffer types supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information.| 
| size | Pointer to the number of buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).| 
| bufferTypeArray | Double pointer to the array holding the buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilterInfo_GetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_GetSupportedFormats (OH_EffectFilterInfo * info, uint32_t * size, ImageEffect_Format ** formatArray )
```

**Description**

Obtains the pixel formats supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information.| 
| size | Pointer to the number of pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).| 
| formatArray | Double pointer to the array holding the pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilterInfo_Release()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_Release (OH_EffectFilterInfo * info)
```

**Description**

Destroys an **OH_EffectFilterInfo** instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilterInfo_SetFilterName()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetFilterName (OH_EffectFilterInfo * info, const char * name )
```

**Description**

Sets a filter name.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information.| 
| name | Pointer to the filter name, for example, **OH_EFFECT_BRIGHTNESS_FILTER**.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilterInfo_SetSupportedBufferTypes()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedBufferTypes (OH_EffectFilterInfo * info, uint32_t size, ImageEffect_BufferType * bufferTypeArray )
```

**Description**

Sets the buffer types supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information.| 
| size | Number of buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).| 
| bufferTypeArray | Pointer to the array holding the buffer types supported, each of which is [ImageEffect_BufferType](#imageeffect_buffertype).| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_EffectFilterInfo_SetSupportedFormats()

```
ImageEffect_ErrorCode OH_EffectFilterInfo_SetSupportedFormats (OH_EffectFilterInfo * info, uint32_t size, ImageEffect_Format * formatArray )
```

**Description**

Sets the pixel formats supported by a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to the filter information.| 
| size | Number of pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).| 
| formatArray | Pointer to the array holding the pixel formats supported, each of which is [ImageEffect_Format](#imageeffect_format).| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_AddFilter()

```
OH_EffectFilter* OH_ImageEffect_AddFilter (OH_ImageEffect * imageEffect, const char * filterName )
```

**Description**

Adds a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| filterName | Pointer to the filter name.| 

**Returns**

Returns the pointer to the **OH_EffectFilter** instance created if the operation is successful; returns a null pointer if the effector is invalid.


### OH_ImageEffect_Configure()

```
ImageEffect_ErrorCode OH_ImageEffect_Configure (OH_ImageEffect * imageEffect, const char * key, const ImageEffect_Any * value )
```

**Description**

Configures an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| key | Pointer to the key of a configuration parameter.| 
| value | Pointer to the value of a configuration parameter.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer. returns **EFFECT_KEY_ERROR** if the key of the configuration parameter is invalid; returns **EFFECT_PARAM_ERROR** if the value of the configuration parameter is invalid.


### OH_ImageEffect_Create()

```
OH_ImageEffect* OH_ImageEffect_Create (const char * name)
```

**Description**

Creates an **OH_ImageEffect** instance. The instance must be released by calling [OH_ImageEffect_Release](#oh_imageeffect_release) when it is no longer needed.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| name | Pointer to the image effector name, which is used to identify the effector. The value can be customized but cannot be empty.| 

**Returns**

Returns the pointer to the **OH_ImageEffect** instance created if the operation is successful; returns a null pointer otherwise.


### OH_ImageEffect_GetFilter()

```
OH_EffectFilter* OH_ImageEffect_GetFilter (OH_ImageEffect * imageEffect, uint32_t index )
```

**Description**

Obtains the information about a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| index | Index of the filter.| 

**Returns**

Returns the pointer to the **OH_EffectFilter** instance created if the operation is successful; returns a null pointer if an input parameter is invalid.


### OH_ImageEffect_GetFilterCount()

```
int32_t OH_ImageEffect_GetFilterCount (OH_ImageEffect * imageEffect)
```

**Description**

Obtains the number of added filters.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 

**Returns**

Returns the number of filters.


### OH_ImageEffect_GetInputSurface()

```
ImageEffect_ErrorCode OH_ImageEffect_GetInputSurface (OH_ImageEffect * imageEffect, OHNativeWindow ** nativeWindow )
```

**Description**

Obtains an input surface.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| nativeWindow | Double pointer to the **OHNativeWindow** instance.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_InsertFilter()

```
OH_EffectFilter* OH_ImageEffect_InsertFilter (OH_ImageEffect * imageEffect, uint32_t index, const char * filterName )
```

**Description**

Inserts a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| index | Index of the filter.| 
| filterName | Pointer to the filter name.| 

**Returns**

Returns the pointer to the **OH_EffectFilter** instance created if the operation is successful; returns a null pointer if an input parameter is invalid.


### OH_ImageEffect_Release()

```
ImageEffect_ErrorCode OH_ImageEffect_Release (OH_ImageEffect * imageEffect)
```

**Description**

Releases an **OH_ImageEffect** instance.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_RemoveFilter()

```
int32_t OH_ImageEffect_RemoveFilter (OH_ImageEffect * imageEffect, const char * filterName )
```

**Description**

Removes a filter.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| filterName | Pointer to the filter name.| 

**Returns**

Returns the number of filters.


### OH_ImageEffect_Restore()

```
OH_ImageEffect* OH_ImageEffect_Restore (const char * info)
```

**Description**

Deserializes an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to a serialized JSON string.| 

**Returns**

Returns an **OH_ImageEffect** instance if the deserialization is successful; returns a null pointer otherwise.


### OH_ImageEffect_Save()

```
ImageEffect_ErrorCode OH_ImageEffect_Save (OH_ImageEffect * imageEffect, char ** info )
```

**Description**

Serializes an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| info | Double pointer to a char array holding a serialized JSON string.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_SetInputNativeBuffer()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputNativeBuffer (OH_ImageEffect * imageEffect, OH_NativeBuffer * nativeBuffer )
```

**Description**

Sets an input native buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| nativeBuffer | Pointer to the **OH_NativeBuffer** instance.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_SetInputPixelmap()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputPixelmap (OH_ImageEffect * imageEffect, OH_PixelmapNative * pixelmap )
```

**Description**

Sets an input pixel map.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| pixelmap | Pointer to the **OH_PixelmapNative** instance.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_SetInputUri()

```
ImageEffect_ErrorCode OH_ImageEffect_SetInputUri (OH_ImageEffect * imageEffect, const char * uri )
```

**Description**

Sets an input URI.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| uri | Pointer to the URI.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_SetOutputNativeBuffer()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputNativeBuffer (OH_ImageEffect * imageEffect, OH_NativeBuffer * nativeBuffer )
```

**Description**

Sets an output native buffer.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| nativeBuffer | Pointer to the **OH_NativeBuffer** instance.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_SetOutputPixelmap()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputPixelmap (OH_ImageEffect * imageEffect, OH_PixelmapNative * pixelmap )
```

**Description**

Sets an output pixel map.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| pixelmap | Pointer to the **OH_PixelmapNative** instance.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_SetOutputSurface()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputSurface (OH_ImageEffect * imageEffect, OHNativeWindow * nativeWindow )
```

**Description**

Sets an output surface.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| nativeWindow | Pointer to the **OHNativeWindow** instance.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_SetOutputUri()

```
ImageEffect_ErrorCode OH_ImageEffect_SetOutputUri (OH_ImageEffect * imageEffect, const char * uri )
```

**Description**

Sets an output URI.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 
| uri | Pointer to the URI.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.


### OH_ImageEffect_Start()

```
ImageEffect_ErrorCode OH_ImageEffect_Start (OH_ImageEffect * imageEffect)
```

**Description**

Starts an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer; returns **EFFECT_INPUT_OUTPUT_NOT_SUPPORTED** if the data types of the input and output images to be processed are different; returns **EFFECT_COLOR_SPACE_NOT_MATCH** if the color spaces of the input and output images are different; returns **EFFECT_ALLOCATE_MEMORY_FAILED** if the buffer fails to be allocated.


### OH_ImageEffect_Stop()

```
ImageEffect_ErrorCode OH_ImageEffect_Stop (OH_ImageEffect * imageEffect)
```

**Description**

Stops an image effector.

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imageEffect | Pointer to the image effector.| 

**Returns**

Returns **EFFECT_SUCCESS** if the operation is successful; returns **EFFECT_ERROR_PARAM_INVALID** if the input parameter is a null pointer.
