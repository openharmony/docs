# image_source_mdk.h


## Overview

The **image_source_mdk.h** file declares the APIs used to decode an image source into a PixelMap.

**Library**: libimage_source_ndk.z.so

**File to include**: &lt;multimedia/image_framework/image_source_mdk.h&gt;

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](image.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OhosImageRegion](_ohos_image_region.md) | Defines the region of an image source to decode. | 
| struct  [OhosImageSourceOps](_ohos_image_source_ops.md) | Defines the image source options.  | 
| struct  [OhosImageDecodingOps](_ohos_image_decoding_ops.md) | Defines the options for decoding an image source. | 
| struct  [OhosImageSourceInfo](_ohos_image_source_info.md) | Defines the information about an image source. | 
| struct  [OhosImageSource](_ohos_image_source.md) | Defines the input resource of an image source. Only one type of resource is accepted at a time. | 
| struct  [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) | Defines the delay time list of an image source. | 
| struct  [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md) | Defines the format string supported by an image source.  | 
| struct  [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) | Defines the format string list supported by an image source.  | 
| struct  [OhosImageSourceProperty](_ohos_image_source_property.md) | Defines the property string (in key-value format) of an image source.  | 
| struct  [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) | Defines the update data of an image source. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct ImageSourceNative_ [ImageSourceNative](image.md#imagesourcenative) | Defines an image source object at the native layer. | 


### Functions

| Name| Description| 
| -------- | -------- |
| int32_t [OH_ImageSource_Create](image.md#oh_imagesource_create) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*src, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object at the JavaScript native layer based on the specified [OhosImageSource](_ohos_image_source.md) and [OhosImageSourceOps](_ohos_image_source_ops.md) structs. | 
| int32_t [OH_ImageSource_CreateFromUri](image.md#oh_imagesource_createfromuri) (napi_env env, char \*uri, size_t size, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object at the JavaScript native layer based on the specified URI and [OhosImageSourceOps](_ohos_image_source_ops.md) struct. | 
| int32_t [OH_ImageSource_CreateFromFd](image.md#oh_imagesource_createfromfd) (napi_env env, int32_t fd, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object at the JavaScript native layer based on the specified file descriptor and [OhosImageSourceOps](_ohos_image_source_ops.md) struct. | 
| int32_t [OH_ImageSource_CreateFromData](image.md#oh_imagesource_createfromdata) (napi_env env, uint8_t \*data, size_t dataSize, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object at the JavaScript native layer based on the specified image source buffer (defined by **data**) and [OhosImageSourceOps](_ohos_image_source_ops.md) struct. | 
| int32_t [OH_ImageSource_CreateFromRawFile](image.md#oh_imagesource_createfromrawfile) (napi_env env, RawFileDescriptor rawFile, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object at the JavaScript native layer based on the specified raw file descriptor and [OhosImageSourceOps](_ohos_image_source_ops.md) struct. | 
| int32_t [OH_ImageSource_CreateIncremental](image.md#oh_imagesource_createincremental) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*source, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object of the incremental type at the JavaScript native layer based on the specified [OhosImageSource](_ohos_image_source.md) and [OhosImageSourceOps](_ohos_image_source_ops.md) structs.| 
| int32_t [OH_ImageSource_CreateIncrementalFromData](image.md#oh_imagesource_createincrementalfromdata) (napi_env env, uint8_t \*data, size_t dataSize, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object of the incremental type at the JavaScript native layer based on the specified image source buffer (defined by **data**) and [OhosImageSourceOps](_ohos_image_source_ops.md) struct. The image data is updated through **OH_ImageSource_UpdateData**.  | 
| int32_t [OH_ImageSource_GetSupportedFormats](image.md#oh_imagesource_getsupportedformats) (struct [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) \*res) | Obtains all supported decoding formats. | 
| [ImageSourceNative](image.md#imagesourcenative) \* [OH_ImageSource_InitNative](image.md#oh_imagesource_initnative) (napi_env env, napi_value source) | Converts an **ImageSource** object at the JavaScript native layer into an [ImageSourceNative](image.md#imagesourcenative) object. | 
| int32_t [OH_ImageSource_CreatePixelMap](image.md#oh_imagesource_createpixelmap) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | Decodes an **ImageSourceNative** object to obtain a **PixelMap** object at the JavaScript native layer based on the specified [OhosImageDecodingOps](_ohos_image_decoding_ops.md) struct. | 
| int32_t [OH_ImageSource_CreatePixelMapList](image.md#oh_imagesource_createpixelmaplist) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | Decodes an **ImageSourceNative** object to obtain all **PixelMap** objects at the JavaScript native layer based on the specified [OhosImageDecodingOps](_ohos_image_decoding_ops.md) struct. | 
| int32_t [OH_ImageSource_GetDelayTime](image.md#oh_imagesource_getdelaytime) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) \*res) | Obtains the delay time list from an **ImageSource** object (such as GIF or WEBP image source).| 
| int32_t [OH_ImageSource_GetFrameCount](image.md#oh_imagesource_getframecount) (const [ImageSourceNative](image.md#imagesourcenative) \*native, uint32_t \*res) | Obtains the number of frames from an **ImageSourceNative** object. | 
| int32_t [OH_ImageSource_GetImageInfo](image.md#oh_imagesource_getimageinfo) (const [ImageSourceNative](image.md#imagesourcenative) \*native, int32_t index, struct [OhosImageSourceInfo](_ohos_image_source_info.md) \*info) | Obtains image source information from an **ImageSourceNative** object by index. | 
| int32_t [OH_ImageSource_GetImageProperty](image.md#oh_imagesource_getimageproperty) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | Obtains the value of an image property from an **ImageSourceNative** object. | 
| int32_t [OH_ImageSource_ModifyImageProperty](image.md#oh_imagesource_modifyimageproperty) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | Modifies the value of an image property of an **ImageSourceNative** object. | 
| int32_t [OH_ImageSource_UpdateData](image.md#oh_imagesource_updatedata) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) \*data) | Updates the data of an **ImageSourceNative** object. | 
| int32_t [OH_ImageSource_Release](image.md#oh_imagesource_release) ([ImageSourceNative](image.md#imagesourcenative) \*native) | Releases an **ImageSourceNative** object. | 


### Variables

| Name| Description| 
| -------- | -------- |
| const char \* [OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](image.md#ohos_image_property_bits_per_sample) = "BitsPerSample" | Defines a pointer to bits per sample, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_ORIENTATION](image.md#ohos_image_property_orientation) = "Orientation" | Defines a pointer to the orientation, one of the image properties. | 
| const char \* [OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](image.md#ohos_image_property_image_length) = "ImageLength" | Defines a pointer to the image length, one of the image properties. | 
| const char \* [OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](image.md#ohos_image_property_image_width) = "ImageWidth" | Defines a pointer to the image width, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LATITUDE](image.md#ohos_image_property_gps_latitude) = "GPSLatitude" | Defines a pointer to the GPS latitude, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](image.md#ohos_image_property_gps_longitude) = "GPSLongitude" | Defines a pointer to the GPS longitude, one of the image properties. | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](image.md#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | Defines a pointer to the GPS latitude reference information, one of the image properties. | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](image.md#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | Defines a pointer to the GPS longitude reference information, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](image.md#ohos_image_property_date_time_original) = "DateTimeOriginal" | Defines a pointer to the created date and time, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](image.md#ohos_image_property_exposure_time) = "ExposureTime" | Defines a pointer to the exposure time, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_SCENE_TYPE](image.md#ohos_image_property_scene_type) = "SceneType" | Defines a pointer to the scene type, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](image.md#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | Defines a pointer to the ISO speed ratings, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_F_NUMBER](image.md#ohos_image_property_f_number) = "FNumber" | Defines a pointer to the f-number of the image, one of the image properties.  | 
| const char \* [OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](image.md#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | Defines a pointer to the compressed bits per pixel, one of the image properties.  | 
