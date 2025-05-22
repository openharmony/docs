# image_effect_filter.h


## Overview

The **image_effect_filter.h** file declares the APIs related to an image effect filter.

With these APIs, you can quickly implement basic effect processing or connect multiple filters in series in an image effector to implement complex effect processing. The system provides basic effect processing filters such as brightness and crop filters.

**Library**: libimage_effect.so

**File to include**: &lt;multimedia/image_effect/image_effect_filter.h&gt;

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](_image_effect.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| union  [ImageEffect_DataValue](union_image_effect___data_value.md) | Describes the data values.| 
| struct  [ImageEffect_Any](_image_effect___any.md) | Describes the image effect parameters.| 
| struct  [ImageEffect_FilterNames](_image_effect___filter_names.md) | Describes the filter name information.| 
| struct  [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) | Describes the callback functions of a custom filter.| 
| struct  [ImageEffect_Region](_image_effect___region.md) | Describes the image region.| 
| struct  [ImageEffect_Size](_image_effect___size.md) | Describes the image size.| 


### Macros

| Name| Description| 
| -------- | -------- |
| [OH_EFFECT_BRIGHTNESS_FILTER](_image_effect.md#oh_effect_brightness_filter)   "Brightness" | Brightness filter. The corresponding parameter is **OH_EFFECT_FILTER_INTENSITY_KEY** and the parameter type is [EFFECT_DATA_TYPE_FLOAT](_image_effect.md).| 
| [OH_EFFECT_CONTRAST_FILTER](_image_effect.md#oh_effect_contrast_filter)   "Contrast" | Contrast filter. The corresponding parameter is **OH_EFFECT_FILTER_INTENSITY_KEY** and the parameter type is [EFFECT_DATA_TYPE_FLOAT](_image_effect.md).| 
| [OH_EFFECT_CROP_FILTER](_image_effect.md#oh_effect_crop_filter)   "Crop" | Crop filter. The corresponding parameter is **OH_EFFECT_FILTER_REGION_KEY**, the parameter type is [EFFECT_DATA_TYPE_PTR](_image_effect.md), and the parameter value is [ImageEffect_Region](_image_effect___region.md).| 
| [OH_EFFECT_FILTER_INTENSITY_KEY](_image_effect.md#oh_effect_filter_intensity_key)   "FilterIntensity" | Intensity filter.| 
| [OH_EFFECT_FILTER_REGION_KEY](_image_effect.md#oh_effect_filter_region_key)   "FilterRegion" | Image region filter.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_EffectFilter](_image_effect.md#oh_effectfilter) [OH_EffectFilter](_image_effect.md#oh_effectfilter) | Defines a struct for the image effect filter.| 
| typedef enum [ImageEffect_DataType](_image_effect.md#imageeffect_datatype-1) [ImageEffect_DataType](_image_effect.md#imageeffect_datatype) | Defines an enum for the data types.| 
| typedef union [ImageEffect_DataValue](union_image_effect___data_value.md) [ImageEffect_DataValue](_image_effect.md#imageeffect_datavalue) | Defines a union for the data values.| 
| typedef struct [ImageEffect_Any](_image_effect___any.md) [ImageEffect_Any](_image_effect.md#imageeffect_any) | Defines a struct for the image effect parameters.| 
| typedef enum [ImageEffect_Format](_image_effect.md#imageeffect_format) [ImageEffect_Format](_image_effect.md#imageeffect_format) | Defines an enum for the pixel formats.| 
| typedef enum [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype-1) [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype) | Defines an enum for the buffer types.| 
| typedef struct [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) | Defines a struct for the filter information.| 
| typedef struct [ImageEffect_FilterNames](_image_effect___filter_names.md) [ImageEffect_FilterNames](_image_effect.md#imageeffect_filternames) | Defines a struct for the filter name information.| 
| typedef struct [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) | Defines a struct for the buffer information.| 
| typedef bool(\* [OH_EffectFilterDelegate_SetValue](_image_effect.md#oh_effectfilterdelegate_setvalue)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | Defines a pointer to the callback function for setting parameters of a custom filter. It is used to verify parameters and parameter values.| 
| typedef void(\* [OH_EffectFilterDelegate_PushData](_image_effect.md#oh_effectfilterdelegate_pushdata)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info) | Defines a pointer to the callback function used by a custom filter to push image data to the next-level filter.| 
| typedef bool(\* [OH_EffectFilterDelegate_Render](_image_effect.md#oh_effectfilterdelegate_render)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, [OH_EffectFilterDelegate_PushData](_image_effect.md#oh_effectfilterdelegate_pushdata) pushData) | Defines a pointer to the callback function for rendering an image using a custom filter.| 
| typedef bool(\* [OH_EffectFilterDelegate_Save](_image_effect.md#oh_effectfilterdelegate_save)) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, char \*\*info) | Defines a pointer to the callback function for serializing a custom filter. Filters are serialized in JSON format.| 
| typedef [OH_EffectFilter](_image_effect.md#oh_effectfilter) \*(\* [OH_EffectFilterDelegate_Restore](_image_effect.md#oh_effectfilterdelegate_restore)) (const char \*info) | Defines a pointer to the callback function for deserializing a custom filter.| 
| typedef struct [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) [ImageEffect_FilterDelegate](_image_effect.md#imageeffect_filterdelegate) | Describes the callback functions of a custom filter.| 
| typedef struct [ImageEffect_Region](_image_effect___region.md) [ImageEffect_Region](_image_effect.md#imageeffect_region) | Defines a struct for the image region.| 
| typedef struct [ImageEffect_Size](_image_effect___size.md) [ImageEffect_Size](_image_effect.md#imageeffect_size) | Defines a struct for the image size.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [ImageEffect_DataType](_image_effect.md#imageeffect_datatype-1) {<br>EFFECT_DATA_TYPE_UNKNOWN = 0, EFFECT_DATA_TYPE_INT32 = 1,<br>EFFECT_DATA_TYPE_FLOAT = 2, EFFECT_DATA_TYPE_DOUBLE = 3,<br>EFFECT_DATA_TYPE_CHAR = 4, EFFECT_DATA_TYPE_LONG = 5,<br>EFFECT_DATA_TYPE_BOOL = 6, EFFECT_DATA_TYPE_PTR = 7<br>} | Enumerates the data types.| 
| [ImageEffect_Format](_image_effect.md#imageeffect_format-1) {<br>EFFECT_PIXEL_FORMAT_UNKNOWN = 0, EFFECT_PIXEL_FORMAT_RGBA8888 = 1,<br>EFFECT_PIXEL_FORMAT_NV21 = 2, EFFECT_PIXEL_FORMAT_NV12 = 3,<br>EFFECT_PIXEL_FORMAT_RGBA1010102 = 4, EFFECT_PIXEL_FORMAT_YCBCR_P010 = 5,<br>EFFECT_PIXEL_FORMAT_YCRCB_P010 = 6<br>} | Enumerates the pixel formats.| 
| [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype-1) { EFFECT_BUFFER_TYPE_UNKNOWN = 0,<br>EFFECT_BUFFER_TYPE_PIXEL = 1, EFFECT_BUFFER_TYPE_TEXTURE = 2 } | Enumerates the buffer types.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \* [OH_EffectFilterInfo_Create](_image_effect.md#oh_effectfilterinfo_create) () | Creates an **OH_EffectFilterInfo** instance. The instance must be released by calling [OH_EffectFilterInfo_Release](_image_effect.md#oh_effectfilterinfo_release) when it is no longer needed.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_SetFilterName](_image_effect.md#oh_effectfilterinfo_setfiltername) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, const char \*name) | Sets a filter name.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_GetFilterName](_image_effect.md#oh_effectfilterinfo_getfiltername) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, char \*\*name) | Obtains a filter name.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedBufferTypes](_image_effect.md#oh_effectfilterinfo_setsupportedbuffertypes) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype) \*bufferTypeArray) | Sets the buffer types supported by a filter.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedBufferTypes](_image_effect.md#oh_effectfilterinfo_getsupportedbuffertypes) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_BufferType](_image_effect.md#imageeffect_buffertype) \*\*bufferTypeArray) | Obtains the buffer types supported by a filter.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_SetSupportedFormats](_image_effect.md#oh_effectfilterinfo_setsupportedformats) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t size, [ImageEffect_Format](_image_effect.md#imageeffect_format) \*formatArray) | Sets the pixel formats supported by a filter.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_GetSupportedFormats](_image_effect.md#oh_effectfilterinfo_getsupportedformats) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, uint32_t \*size, [ImageEffect_Format](_image_effect.md#imageeffect_format) \*\*formatArray) | Obtains the pixel formats supported by a filter.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilterInfo_Release](_image_effect.md#oh_effectfilterinfo_release) ([OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info) | Destroys an **OH_EffectFilterInfo** instance.| 
| [OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \* [OH_EffectBufferInfo_Create](_image_effect.md#oh_effectbufferinfo_create) () | Creates an **OH_EffectBufferInfo** instance. The instance must be released by calling [OH_EffectBufferInfo_Release](_image_effect.md#oh_effectbufferinfo_release) when it is no longer needed.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetAddr](_image_effect.md#oh_effectbufferinfo_setaddr) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, void \*addr) | Sets the address of an effect buffer.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetAddr](_image_effect.md#oh_effectbufferinfo_getaddr) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, void \*\*addr) | Obtains the address of an effect buffer.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetWidth](_image_effect.md#oh_effectbufferinfo_setwidth) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t width) | Sets the image width.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetWidth](_image_effect.md#oh_effectbufferinfo_getwidth) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t \*width) | Obtains the image width.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetHeight](_image_effect.md#oh_effectbufferinfo_setheight) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t height) | Sets the image height.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetHeight](_image_effect.md#oh_effectbufferinfo_getheight) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t \*height) | Obtains the image height.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetRowSize](_image_effect.md#oh_effectbufferinfo_setrowsize) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t rowSize) | Sets the number of bytes per row for an image.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetRowSize](_image_effect.md#oh_effectbufferinfo_getrowsize) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, int32_t \*rowSize) | Obtains the number of bytes per row of an image.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_SetEffectFormat](_image_effect.md#oh_effectbufferinfo_seteffectformat) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, [ImageEffect_Format](_image_effect.md#imageeffect_format) format) | Sets the pixel format for an image.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_GetEffectFormat](_image_effect.md#oh_effectbufferinfo_geteffectformat) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info, [ImageEffect_Format](_image_effect.md#imageeffect_format) \*format) | Obtains the pixel format of an image.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectBufferInfo_Release](_image_effect.md#oh_effectbufferinfo_release) ([OH_EffectBufferInfo](_image_effect.md#oh_effectbufferinfo) \*info) | Destroys an **OH_EffectBufferInfo** instance.| 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_EffectFilter_Create](_image_effect.md#oh_effectfilter_create) (const char \*name) | Creates an **OH_EffectFilter** instance. The instance must be released by calling [OH_EffectFilter_Release](_image_effect.md#oh_effectfilter_release) when it is no longer needed.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_SetValue](_image_effect.md#oh_effectfilter_setvalue) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | Sets a filter parameter.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_GetValue](_image_effect.md#oh_effectfilter_getvalue) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, const char \*key, [ImageEffect_Any](_image_effect___any.md) \*value) | Obtains a filter parameter.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_Register](_image_effect.md#oh_effectfilter_register) (const [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info, const [ImageEffect_FilterDelegate](_image_effect___filter_delegate.md) \*delegate) | Registers a custom filter.| 
| [ImageEffect_FilterNames](_image_effect___filter_names.md) \* [OH_EffectFilter_LookupFilters](_image_effect.md#oh_effectfilter_lookupfilters) (const char \*key) | Obtains filters that meet given conditions.| 
| void [OH_EffectFilter_ReleaseFilterNames](_image_effect.md#oh_effectfilter_releasefilternames) () | Releases filter name memory resources.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_LookupFilterInfo](_image_effect.md#oh_effectfilter_lookupfilterinfo) (const char \*name, [OH_EffectFilterInfo](_image_effect.md#oh_effectfilterinfo) \*info) | Obtains the filter information.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_Render](_image_effect.md#oh_effectfilter_render) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter, OH_PixelmapNative \*inputPixelmap, OH_PixelmapNative \*outputPixelmap) | Starts image rendering.| 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_EffectFilter_Release](_image_effect.md#oh_effectfilter_release) ([OH_EffectFilter](_image_effect.md#oh_effectfilter) \*filter) | Destroys an **OH_EffectFilter** instance.| 
