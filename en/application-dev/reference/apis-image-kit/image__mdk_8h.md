# image_mdk.h


## Overview

Declares the APIs used to access the image rectangle, size, format, and component data.

**Library**: libimage_ndk.z.so

**File to include**: &lt;multimedia/image_framework/image_mdk.h&gt;

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) | Defines the information about an image rectangle. | 
| struct  [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) | Defines the information about an image component. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct ImageNative_ [ImageNative](image.md#imagenative) | Defines an image object at the native layer. | 


### Enums

| Name| Description| 
| -------- | -------- |
| { [OHOS_IMAGE_FORMAT_YCBCR_422_SP](image.md#anonymous-enum-13) = 1000,<br>[OHOS_IMAGE_FORMAT_JPEG](image.md#anonymous-enum-13) = 2000, } | Enumerates the image formats.| 
| { [OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y](image.md#anonymous-enum-13-1) = 1,<br>[OHOS_IMAGE_COMPONENT_FORMAT_YUV_U](image.md#anonymous-enum-13-1) = 2,<br>[OHOS_IMAGE_COMPONENT_FORMAT_YUV_V](image.md#anonymous-enum-13-1) = 3,<br>[OHOS_IMAGE_COMPONENT_FORMAT_JPEG](image.md#anonymous-enum-13-1) = 4, } | Enumerates the image components.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [ImageNative](image.md#imagenative) \* [OH_Image_InitImageNative](image.md#oh_image_initimagenative) (napi_env env, napi_value source) | Converts an **Image** object at the JavaScript native layer into an **ImageNative** object. | 
| int32_t [OH_Image_ClipRect](image.md#oh_image_cliprect) (const [ImageNative](image.md#imagenative) \*native, struct [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) \*rect) | Obtains [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) of an **ImageNative** object. | 
| int32_t [OH_Image_Size](image.md#oh_image_size) (const [ImageNative](image.md#imagenative) \*native, struct [OhosImageSize](_ohos_image_size.md) \*size) | Obtains [OhosImageSize](_ohos_image_size.md) of an **ImageNative** object. | 
| int32_t [OH_Image_Format](image.md#oh_image_format) (const [ImageNative](image.md#imagenative) \*native, int32_t \*format) | Obtains the image format of an **ImageNative** object. | 
| int32_t [OH_Image_GetComponent](image.md#oh_image_getcomponent) (const [ImageNative](image.md#imagenative) \*native, int32_t componentType, struct [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) \*componentNative) | Obtains [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) of an **ImageNative** object. | 
| int32_t [OH_Image_Release](image.md#oh_image_release) ([ImageNative](image.md#imagenative) \*native) | Releases an **ImageNative** object. | 
