# image_effect.h


## Overview

The **image_effect.h** file declares the APIs related to an image effector.

You can use the APIs to add, delete, and query image effect filters. You can connect multiple filters in series to implement complex effect adjustment.

The effector supports multiple input types, such as pixel map, URI, and surface. Different input types are converted into buffer objects in the effector, and effect processing is implemented through the filters.

**Library**: libimage_effect.so

**System capability**: SystemCapability.Multimedia.ImageEffect.Core

**Since**: 12

**Related module**: [ImageEffect](_image_effect.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_ImageEffect](_image_effect.md#oh_imageeffect) [OH_ImageEffect](_image_effect.md#oh_imageeffect) | Defines a struct for the image effector. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_ImageEffect](_image_effect.md#oh_imageeffect) \* [OH_ImageEffect_Create](_image_effect.md#oh_imageeffect_create) (const char \*name) | Creates an **OH_ImageEffect** instance. The instance must be released by calling [OH_ImageEffect_Release](_image_effect.md#oh_imageeffect_release) when it is no longer needed. | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_ImageEffect_AddFilter](_image_effect.md#oh_imageeffect_addfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*filterName) | Adds a filter. | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_ImageEffect_InsertFilter](_image_effect.md#oh_imageeffect_insertfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index, const char \*filterName) | Inserts a filter. | 
| int32_t [OH_ImageEffect_RemoveFilter](_image_effect.md#oh_imageeffect_removefilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*filterName) | Removes a filter. | 
| int32_t [OH_ImageEffect_GetFilterCount](_image_effect.md#oh_imageeffect_getfiltercount) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | Obtains the number of added filters. | 
| [OH_EffectFilter](_image_effect.md#oh_effectfilter) \* [OH_ImageEffect_GetFilter](_image_effect.md#oh_imageeffect_getfilter) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, uint32_t index) | Obtains the information about a filter. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Configure](_image_effect.md#oh_imageeffect_configure) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*key, const [ImageEffect_Any](_image_effect___any.md) \*value) | Configures an image effector. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputSurface](_image_effect.md#oh_imageeffect_setoutputsurface) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OHNativeWindow \*nativeWindow) | Sets an output surface. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_GetInputSurface](_image_effect.md#oh_imageeffect_getinputsurface) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OHNativeWindow \*\*nativeWindow) | Obtains an input surface. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetInputPixelmap](_image_effect.md#oh_imageeffect_setinputpixelmap) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | Sets an input pixel map. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputPixelmap](_image_effect.md#oh_imageeffect_setoutputpixelmap) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_PixelmapNative \*pixelmap) | Sets an output pixel map. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetInputNativeBuffer](_image_effect.md#oh_imageeffect_setinputnativebuffer) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | Sets an input native buffer. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputNativeBuffer](_image_effect.md#oh_imageeffect_setoutputnativebuffer) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, OH_NativeBuffer \*nativeBuffer) | Sets an output native buffer. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetInputUri](_image_effect.md#oh_imageeffect_setinputuri) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*uri) | Sets an input URI. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_SetOutputUri](_image_effect.md#oh_imageeffect_setoutputuri) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, const char \*uri) | Sets an output URI. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Start](_image_effect.md#oh_imageeffect_start) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | Starts an image effector. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Stop](_image_effect.md#oh_imageeffect_stop) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | Stops an image effector. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Release](_image_effect.md#oh_imageeffect_release) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect) | Releases an **OH_ImageEffect** instance. | 
| [ImageEffect_ErrorCode](_image_effect.md#imageeffect_errorcode) [OH_ImageEffect_Save](_image_effect.md#oh_imageeffect_save) ([OH_ImageEffect](_image_effect.md#oh_imageeffect) \*imageEffect, char \*\*info) | Serializes an image effector. | 
| [OH_ImageEffect](_image_effect.md#oh_imageeffect) \* [OH_ImageEffect_Restore](_image_effect.md#oh_imageeffect_restore) (const char \*info) | Deserializes an image effector. | 
