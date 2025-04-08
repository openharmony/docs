# image_source_mdk.h


## 概述

声明将ImageSource解码成像素位图的方法。

**库**：libimage_source_ndk.z.so

**引用文件**：&lt;multimedia/image_framework/image_source_mdk.h&gt;

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10

**相关模块：** [Image](image.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OhosImageRegion](_ohos_image_region.md) | 定义图像源解码的范围选项。  | 
| struct  [OhosImageSourceOps](_ohos_image_source_ops.md) | 定义图像源选项信息。   | 
| struct  [OhosImageDecodingOps](_ohos_image_decoding_ops.md) | 定义图像源解码选项。  | 
| struct  [OhosImageSourceInfo](_ohos_image_source_info.md) | 定义图像源信息。  | 
| struct  [OhosImageSource](_ohos_image_source.md) | 定义图像源输入资源，每次仅接收一种类型。  | 
| struct  [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) | 定义图像源延迟时间列表。  | 
| struct  [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md) | 定义图像源支持的格式字符串。   | 
| struct  [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) | 定义图像源支持的格式字符串列表。   | 
| struct  [OhosImageSourceProperty](_ohos_image_source_property.md) | 定义图像源属性键值字符串。   | 
| struct  [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) | 定义图像源更新数据选项。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct ImageSourceNative_ [ImageSourceNative](image.md#imagesourcenative) | 为图像源方法定义native层图像源对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| int32_t [OH_ImageSource_Create](image.md#oh_imagesource_create) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*src, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的信息[OhosImageSource](_ohos_image_source.md)和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层API**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromUri](image.md#oh_imagesource_createfromuri) (napi_env env, char \*uri, size_t size, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的标识符URI和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromFd](image.md#oh_imagesource_createfromfd) (napi_env env, int32_t fd, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的文件描述符fd和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromData](image.md#oh_imagesource_createfromdata) (napi_env env, uint8_t \*data, size_t dataSize, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的图像源缓冲区资源data和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层API**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromRawFile](image.md#oh_imagesource_createfromrawfile) (napi_env env, RawFileDescriptor rawFile, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的资源描述符 **RawFileDescriptor**和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateIncremental](image.md#oh_imagesource_createincremental) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*source, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的infomations[OhosImageSource](_ohos_image_source.md)和[OhosImageSourceOps](_ohos_image_source_ops.md)结构，获取增量类型的avaScript native层**ImageSource**对象。 | 
| int32_t [OH_ImageSource_CreateIncrementalFromData](image.md#oh_imagesource_createincrementalfromdata) (napi_env env, uint8_t \*data, size_t dataSize, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的图像源缓冲区资源data和 [OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取增量类型的JavaScript Native API ImageSource对象，图像数据应通过OH_ImageSource_UpdateData更新。  | 
| int32_t [OH_ImageSource_GetSupportedFormats](image.md#oh_imagesource_getsupportedformats) (struct [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) \*res) | 获取所有支持的解码格式元标记。  | 
| [ImageSourceNative](image.md#imagesourcenative) \* [OH_ImageSource_InitNative](image.md#oh_imagesource_initnative) (napi_env env, napi_value source) | 从输入JavaScript native层API **ImageSource** 对象中，转换成[ImageSourceNative](image.md#imagesourcenative)值。  | 
| int32_t [OH_ImageSource_CreatePixelMap](image.md#oh_imagesource_createpixelmap) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | 通过一个给定的选项[OhosImageDecodingOps](_ohos_image_decoding_ops.md)结构体，从**ImageSource**中解码JavaScript native层**PixelMap**对象。  | 
| int32_t [OH_ImageSource_CreatePixelMapList](image.md#oh_imagesource_createpixelmaplist) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | 通过一个给定的选项[OhosImageDecodingOps](_ohos_image_decoding_ops.md)结构体，从**ImageSource**中解码所有的JavaScript native层**PixelMap**对象列表。  | 
| int32_t [OH_ImageSource_GetDelayTime](image.md#oh_imagesource_getdelaytime) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) \*res) | 从一些**ImageSource**（如GIF图像源，WEBP图像源）获取延迟时间列表。 | 
| int32_t [OH_ImageSource_GetFrameCount](image.md#oh_imagesource_getframecount) (const [ImageSourceNative](image.md#imagesourcenative) \*native, uint32_t \*res) | 从**ImageSource**中获取帧计数。  | 
| int32_t [OH_ImageSource_GetImageInfo](image.md#oh_imagesource_getimageinfo) (const [ImageSourceNative](image.md#imagesourcenative) \*native, int32_t index, struct [OhosImageSourceInfo](_ohos_image_source_info.md) \*info) | 通过索引从**ImageSource**获取图像源信息。  | 
| int32_t [OH_ImageSource_GetImageProperty](image.md#oh_imagesource_getimageproperty) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | 通过关键字从**ImageSource**中获取图像源属性。  | 
| int32_t [OH_ImageSource_ModifyImageProperty](image.md#oh_imagesource_modifyimageproperty) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | 通过关键字为**ImageSource**修改图像源属性。  | 
| int32_t [OH_ImageSource_UpdateData](image.md#oh_imagesource_updatedata) (const [ImageSourceNative](image.md#imagesourcenative) \*native, struct [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) \*data) | 为了增量类型的**ImageSource**更新源数据。  | 
| int32_t [OH_ImageSource_Release](image.md#oh_imagesource_release) ([ImageSourceNative](image.md#imagesourcenative) \*native) | 释放native层图像源 **ImageSourceNative**。  | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](image.md#ohos_image_property_bits_per_sample) = "BitsPerSample" | 定义每个样本比特的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_ORIENTATION](image.md#ohos_image_property_orientation) = "Orientation" | 定义方向的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](image.md#ohos_image_property_image_length) = "ImageLength" | 定义图像长度的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](image.md#ohos_image_property_image_width) = "ImageWidth" | 定义图像宽度的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LATITUDE](image.md#ohos_image_property_gps_latitude) = "GPSLatitude" | 定义GPS纬度的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](image.md#ohos_image_property_gps_longitude) = "GPSLongitude" | 定义GPS经度的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](image.md#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | 定义GPS纬度参考的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](image.md#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | 定义GPS经度参考的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](image.md#ohos_image_property_date_time_original) = "DateTimeOriginal" | 定义初始日期时间的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](image.md#ohos_image_property_exposure_time) = "ExposureTime" | 定义曝光时间的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_SCENE_TYPE](image.md#ohos_image_property_scene_type) = "SceneType" | 定义场景类型的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](image.md#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | 定义ISO速度等级的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_F_NUMBER](image.md#ohos_image_property_f_number) = "FNumber" | 定义FNumber的图像属性关键字。   | 
| const char \* [OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](image.md#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | 定义每个像素的压缩比特的图像属性关键字。   | 
