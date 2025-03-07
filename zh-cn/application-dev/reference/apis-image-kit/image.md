# Image


## 概述

提供image接口的访问。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [使用Image完成图片解码](../../media/image/image-decoding-native.md)
- [使用Image完成图片接收器](../../media/image/image-receiver-native.md)
- [使用Image完成图像变换](../../media/image/image-transformation-native.md)
- [使用Image处理PixelMap数据](../../media/image/image-pixelmap-operation-native.md)
- [使用Image完成图片编码](../../media/image/image-encoding-native.md)

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 8


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [image_mdk.h](image__mdk_8h.md) | 声明访问图像剪辑矩形、大小、格式和组件数据的方法。 | 
| [image_mdk_common.h](image__mdk__common_8h.md) | 声明图像常用的枚举值和结构体。 |
| [image_packer_mdk.h](image__packer__mdk_8h.md) | 声明用于将图像编码到缓冲区或文件的方法。 | 
| [image_pixel_map_mdk.h](image__pixel__map__mdk_8h.md) | 声明可以锁定并访问PixelMap数据的方法，声明解锁的方法。 | 
| [image_pixel_map_napi.h](image__pixel__map__napi_8h.md) | （已废弃）声明可以锁定并访问PixelMap数据的方法，声明解锁的方法。 | 
| [image_receiver_mdk.h](image__receiver__mdk_8h.md) | 声明从native层获取图片数据的方法。 | 
| [image_source_mdk.h](image__source__mdk_8h.md) | 声明将图片源解码成像素位图的方法。 |


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) | 定义图像矩形信息。  | 
| struct  [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) | 定义图像组成信息。  | 
| struct  [OhosImageSize](_ohos_image_size.md) | 定义图像大小。  | 
| struct  [ImagePacker_Opts_](_image_packer___opts__.md) | 定义图像编码选项信息。  | 
| struct  [OhosPixelMapInfos](_ohos_pixel_map_infos.md) | 用于定义PixelMap的相关信息。  | 
| struct  [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | 用于定义创建PixelMap设置选项的相关信息。  | 
| struct  [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) | 用于定义PixelMap的相关信息。  | 
| struct  [OhosImageReceiverInfo](_ohos_image_receiver_info.md) | 定义**ImageReceiver**的相关信息。  | 
| struct  [OhosImageRegion](_ohos_image_region.md) | 定义图像源解码的范围选项。  | 
| struct  [OhosImageSourceOps](_ohos_image_source_ops.md) | 定义图像源选项信息。  | 
| struct  [OhosImageDecodingOps](_ohos_image_decoding_ops.md) | 定义图像源解码选项。  | 
| struct  [OhosImageSourceInfo](_ohos_image_source_info.md) | 定义图像源信息。  | 
| struct  [OhosImageSource](_ohos_image_source.md) | 定义图像源输入资源，每次仅接收一种类型。  | 
| struct  [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) | 定义图像源延迟时间列表。  | 
| struct  [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md) | 定义图像源支持的格式字符串。   | 
| struct  [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) | 定义图像源支持的格式字符串列表。   | 
| struct  [OhosImageSourceProperty](_ohos_image_source_property.md) | 定义图像源属性键值字符串。   | 
| struct  [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) | 定义图像源更新数据选项。  | 


### 宏定义

| 名称 | 描述 | 
| -------- | -------- |
| **IMAGE_RESULT_BASE** 62980096 | 接口返回值的基础值。  |


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct ImageNative_ [ImageNative](#imagenative) | 为图像接口定义native层图像对象。  | 
| typedef struct ImagePacker_Native_ [ImagePacker_Native](#imagepacker_native) | 为编码器方法定义native层编码器对象。  | 
| typedef struct [ImagePacker_Opts_](_image_packer___opts__.md) [ImagePacker_Opts](#imagepacker_opts) | 定义图像编码选项的别名。  | 
| typedef struct NativePixelMap_ [NativePixelMap](#nativepixelmap) | 定义native层PixelMap数据类型名称。  | 
| typedef struct [OhosPixelMapInfos](_ohos_pixel_map_infos.md) [OhosPixelMapInfos](#ohospixelmapinfos) | 用于定义PixelMap的相关信息。  | 
| typedef struct ImageReceiverNative_ [ImageReceiverNative](#imagereceivernative) | 用于定义ImageReceiverNative数据类型名称。  | 
| typedef void(\* [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)) () | 定义native层图片的回调方法。  | 
| typedef struct ImageSourceNative_ [ImageSourceNative](#imagesourcenative) | 为图像源方法定义native层图像源对象。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| { OHOS_IMAGE_FORMAT_YCBCR_422_SP = 1000,<br/>OHOS_IMAGE_FORMAT_JPEG = 2000 } | 图像格式枚举值。 | 
| { OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y = 1,<br/>OHOS_IMAGE_COMPONENT_FORMAT_YUV_U = 2,<br/>OHOS_IMAGE_COMPONENT_FORMAT_YUV_V = 3,<br/>OHOS_IMAGE_COMPONENT_FORMAT_JPEG = 4 } | 图像组成类型枚举值。 | 
| [IRNdkErrCode](#irndkerrcode) {<br/>IMAGE_RESULT_SUCCESS = 0, IMAGE_RESULT_BAD_PARAMETER = -1,<br/>IMAGE_RESULT_IMAGE_RESULT_BASE = IMAGE_RESULT_BASE,<br/>IMAGE_RESULT_ERR_IPC = IMAGE_RESULT_BASE + 1,<br/>IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST = IMAGE_RESULT_BASE + 2,<br/>IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL = IMAGE_RESULT_BASE + 3,<br/>IMAGE_RESULT_DECODE_ABNORMAL = IMAGE_RESULT_BASE + 4,<br/>IMAGE_RESULT_DATA_ABNORMAL = IMAGE_RESULT_BASE + 5,<br/>IMAGE_RESULT_MALLOC_ABNORMAL = IMAGE_RESULT_BASE + 6,<br/>IMAGE_RESULT_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 7,<br/>IMAGE_RESULT_INIT_ABNORMAL = IMAGE_RESULT_BASE + 8,<br/>IMAGE_RESULT_GET_DATA_ABNORMAL = IMAGE_RESULT_BASE + 9,<br/>IMAGE_RESULT_TOO_LARGE = IMAGE_RESULT_BASE + 10,<br/>IMAGE_RESULT_TRANSFORM = IMAGE_RESULT_BASE + 11,<br/>IMAGE_RESULT_COLOR_CONVERT = IMAGE_RESULT_BASE + 12,<br/>IMAGE_RESULT_CROP = IMAGE_RESULT_BASE + 13,<br/>IMAGE_RESULT_SOURCE_DATA = IMAGE_RESULT_BASE + 14,<br/>IMAGE_RESULT_SOURCE_DATA_INCOMPLETE = IMAGE_RESULT_BASE + 15,<br/>IMAGE_RESULT_MISMATCHED_FORMAT = IMAGE_RESULT_BASE + 16,<br/>IMAGE_RESULT_UNKNOWN_FORMAT = IMAGE_RESULT_BASE + 17,<br/>IMAGE_RESULT_SOURCE_UNRESOLVED = IMAGE_RESULT_BASE + 18,<br/>IMAGE_RESULT_INVALID_PARAMETER = IMAGE_RESULT_BASE + 19,<br/>IMAGE_RESULT_DECODE_FAILED = IMAGE_RESULT_BASE + 20,<br/>IMAGE_RESULT_PLUGIN_REGISTER_FAILED = IMAGE_RESULT_BASE + 21,<br/>IMAGE_RESULT_PLUGIN_CREATE_FAILED = IMAGE_RESULT_BASE + 22,<br/>IMAGE_RESULT_ENCODE_FAILED = IMAGE_RESULT_BASE + 23,<br/>IMAGE_RESULT_ADD_PIXEL_MAP_FAILED = IMAGE_RESULT_BASE + 24,<br/>IMAGE_RESULT_HW_DECODE_UNSUPPORT = IMAGE_RESULT_BASE + 25,<br/>IMAGE_RESULT_DECODE_HEAD_ABNORMAL = IMAGE_RESULT_BASE + 26,<br/>IMAGE_RESULT_DECODE_EXIF_UNSUPPORT = IMAGE_RESULT_BASE + 27,<br/>IMAGE_RESULT_PROPERTY_NOT_EXIST = IMAGE_RESULT_BASE + 28,<br/>IMAGE_RESULT_MEDIA_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 30,<br/>IMAGE_RESULT_MEDIA_TOO_LARGE = IMAGE_RESULT_BASE + 31,<br/>IMAGE_RESULT_MEDIA_MALLOC_FAILED = IMAGE_RESULT_BASE + 32,<br/>IMAGE_RESULT_MEDIA_END_OF_STREAM = IMAGE_RESULT_BASE + 33,<br/>IMAGE_RESULT_MEDIA_IO_ABNORMAL = IMAGE_RESULT_BASE + 34,<br/>IMAGE_RESULT_MEDIA_MALFORMED = IMAGE_RESULT_BASE + 35,<br/>IMAGE_RESULT_MEDIA_BUFFER_TOO_SMALL = IMAGE_RESULT_BASE + 36,<br/>IMAGE_RESULT_MEDIA_OUT_OF_RANGE = IMAGE_RESULT_BASE + 37,<br/>IMAGE_RESULT_MEDIA_STATUS_ABNORMAL = IMAGE_RESULT_BASE + 38,<br/>IMAGE_RESULT_MEDIA_VALUE_INVALID = IMAGE_RESULT_BASE + 39,<br/>IMAGE_RESULT_MEDIA_NULL_POINTER = IMAGE_RESULT_BASE + 40,<br/>IMAGE_RESULT_MEDIA_INVALID_OPERATION = IMAGE_RESULT_BASE + 41,<br/>IMAGE_RESULT_MEDIA_ERR_PLAYER_NOT_INIT = IMAGE_RESULT_BASE + 42,<br/>IMAGE_RESULT_MEDIA_EARLY_PREPARE = IMAGE_RESULT_BASE + 43,<br/>IMAGE_RESULT_MEDIA_SEEK_ERR = IMAGE_RESULT_BASE + 44,<br/>IMAGE_RESULT_MEDIA_PERMISSION_DENIED = IMAGE_RESULT_BASE + 45,<br/>IMAGE_RESULT_MEDIA_DEAD_OBJECT = IMAGE_RESULT_BASE + 46,<br/>IMAGE_RESULT_MEDIA_TIMED_OUT = IMAGE_RESULT_BASE + 47,<br/>IMAGE_RESULT_MEDIA_TRACK_NOT_ALL_SUPPORTED = IMAGE_RESULT_BASE + 48,<br/>IMAGE_RESULT_MEDIA_ADAPTER_INIT_FAILED = IMAGE_RESULT_BASE + 49,<br/>IMAGE_RESULT_MEDIA_WRITE_PARCEL_FAIL = IMAGE_RESULT_BASE + 50,<br/>IMAGE_RESULT_MEDIA_READ_PARCEL_FAIL = IMAGE_RESULT_BASE + 51,<br/>IMAGE_RESULT_MEDIA_NO_AVAIL_BUFFER = IMAGE_RESULT_BASE + 52,<br/>IMAGE_RESULT_MEDIA_INVALID_PARAM = IMAGE_RESULT_BASE + 53,<br/>IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 54,<br/>IMAGE_RESULT_MEDIA_CREATE_CODEC_ADAPTER_FAILED = IMAGE_RESULT_BASE + 55,<br/>IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 56,<br/>IMAGE_RESULT_MEDIA_ZCODEC_CREATE_FAILED = IMAGE_RESULT_BASE + 57,<br/>IMAGE_RESULT_MEDIA_ZCODEC_NOT_EXIST = IMAGE_RESULT_BASE + 58,<br/>IMAGE_RESULT_MEDIA_JNI_CLASS_NOT_EXIST = IMAGE_RESULT_BASE + 59,<br/>IMAGE_RESULT_MEDIA_JNI_METHOD_NOT_EXIST = IMAGE_RESULT_BASE + 60,<br/>IMAGE_RESULT_MEDIA_JNI_NEW_OBJ_FAILED = IMAGE_RESULT_BASE + 61,<br/>IMAGE_RESULT_MEDIA_JNI_COMMON_ERROR = IMAGE_RESULT_BASE + 62,<br/>IMAGE_RESULT_MEDIA_DISTRIBUTE_NOT_SUPPORT = IMAGE_RESULT_BASE + 63,<br/>IMAGE_RESULT_MEDIA_SOURCE_NOT_SET = IMAGE_RESULT_BASE + 64,<br/>IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 65,<br/>IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 66,<br/>IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT = IMAGE_RESULT_BASE + 67,<br/>IMAGE_RESULT_MEDIA_RTSP_CAPTURE_NOT_INIT = IMAGE_RESULT_BASE + 68,<br/>IMAGE_RESULT_MEDIA_RTSP_SOURCE_URL_INVALID = IMAGE_RESULT_BASE + 69,<br/>IMAGE_RESULT_MEDIA_RTSP_VIDEO_TRACK_NOT_FOUND = IMAGE_RESULT_BASE + 70,<br/>IMAGE_RESULT_MEDIA_RTSP_CAMERA_NUM_REACH_MAX = IMAGE_RESULT_BASE + 71,<br/>IMAGE_RESULT_MEDIA_SET_VOLUME = IMAGE_RESULT_BASE + 72,<br/>IMAGE_RESULT_MEDIA_NUMBER_OVERFLOW = IMAGE_RESULT_BASE + 73,<br/>IMAGE_RESULT_MEDIA_DIS_PLAYER_UNSUPPORTED = IMAGE_RESULT_BASE + 74,<br/>IMAGE_RESULT_MEDIA_DENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 75,<br/>IMAGE_RESULT_MEDIA_ENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 76,<br/>IMAGE_RESULT_MEDIA_READ_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 150,<br/>IMAGE_RESULT_MEDIA_WRITE_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 151,<br/>IMAGE_RESULT_MEDIA_PIXELMAP_NOT_ALLOW_MODIFY = IMAGE_RESULT_BASE + 152,<br/>IMAGE_RESULT_MEDIA_CONFIG_FAILED = IMAGE_RESULT_BASE + 153,<br/>IMAGE_RESULT_JNI_ENV_ABNORMAL = IMAGE_RESULT_BASE + 154,<br/>IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED = IMAGE_RESULT_BASE + 155,<br/>IMAGE_RESULT_CREATE_SURFACE_FAILED = IMAGE_RESULT_BASE + 156,<br/>IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED = IMAGE_RESULT_BASE + 157,<br/>IMAGE_RESULT_GET_SURFACE_FAILED = IMAGE_RESULT_BASE + 158,<br/>IMAGE_RESULT_SURFACE_ACQUIRE_BUFFER_FAILED = IMAGE_RESULT_BASE + 159,<br/>IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED = IMAGE_RESULT_BASE + 160,<br/>IMAGE_RESULT_REGISTER_LISTENER_FAILED = IMAGE_RESULT_BASE + 161,<br/>IMAGE_RESULT_REGISTER_BUFFER_FAILED = IMAGE_RESULT_BASE + 162,<br/>IMAGE_RESULT_FREAD_FAILED = IMAGE_RESULT_BASE + 163,<br/>IMAGE_RESULT_PEEK_FAILED = IMAGE_RESULT_BASE + 164,<br/>IMAGE_RESULT_SEEK_FAILED = IMAGE_RESULT_BASE + 165,<br/>IMAGE_RESULT_STREAM_SIZE_ERROR = IMAGE_RESULT_BASE + 166,<br/>IMAGE_RESULT_FILE_FD_ERROR = IMAGE_RESULT_BASE + 167,<br/>IMAGE_RESULT_FILE_DAMAGED = IMAGE_RESULT_BASE + 168,<br/>IMAGE_RESULT_CREATE_DECODER_FAILED = IMAGE_RESULT_BASE + 169,<br/>IMAGE_RESULT_CREATE_ENCODER_FAILED = IMAGE_RESULT_BASE + 170,<br/>IMAGE_RESULT_CHECK_FORMAT_ERROR = IMAGE_RESULT_BASE + 171,<br/>IMAGE_RESULT_THIRDPART_SKIA_ERROR = IMAGE_RESULT_BASE + 172,<br/>IMAGE_RESULT_HW_DECODE_FAILED = IMAGE_RESULT_BASE + 173,<br/>IMAGE_RESULT_ALLOCATER_TYPE_ERROR = IMAGE_RESULT_BASE + 174,<br/>IMAGE_RESULT_ALPHA_TYPE_ERROR = IMAGE_RESULT_BASE + 175,<br/>IMAGE_RESULT_INDEX_INVALID = IMAGE_RESULT_BASE + 176,<br/>IMAGE_RESULT_MEDIA_UNKNOWN = IMAGE_RESULT_BASE + 200<br/>} | 可能出现的返回值的枚举。 | 
| { OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0,<br/>OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1,<br/>OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2,<br/>OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 } | PixelMap 透明度类型的枚举。 | 
| { OHOS_PIXEL_MAP_READ_ONLY = 0,<br/>OHOS_PIXEL_MAP_EDITABLE = 1 } | PixelMap 编辑类型的枚举。 | 
| [OH_PixelMap_AntiAliasingLevel](#oh_pixelmap_antialiasinglevel) { <br/>OH_PixelMap_AntiAliasing_NONE = 0, <br/>OH_PixelMap_AntiAliasing_LOW = 1, <br/>OH_PixelMap_AntiAliasing_MEDIUM = 2, <br/>OH_PixelMap_AntiAliasing_HIGH = 3 <br/>} | Pixelmap缩放时采用的缩放算法。  | 
| { OHOS_IMAGE_RESULT_SUCCESS = 0,<br/>OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | 函数方法返回值的错误码的枚举。 | 
| { OHOS_PIXEL_MAP_FORMAT_NONE = 0,<br/>OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3,<br/>OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | pixel 格式的枚举。 | 
| { OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE = 0,<br/>OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP = 1 } | PixelMap 缩放类型的枚举。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [ImageNative](#imagenative) \* [OH_Image_InitImageNative](#oh_image_initimagenative) (napi_env env, napi_value source) | 从输入的JavaScript Native API **图像** 对象中解析 native **ImageNative** 对象。  | 
| int32_t [OH_Image_ClipRect](#oh_image_cliprect) (const [ImageNative](#imagenative) \*native, struct [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) \*rect) | 获取native **ImageNative** 对象 [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) 信息。  | 
| int32_t [OH_Image_Size](#oh_image_size) (const [ImageNative](#imagenative) \*native, struct [OhosImageSize](_ohos_image_size.md) \*size) | 获取native **ImageNative** 对象的 [OhosImageSize](_ohos_image_size.md) 信息。  | 
| int32_t [OH_Image_Format](#oh_image_format) (const [ImageNative](#imagenative) \*native, int32_t \*format) | 获取native **ImageNative** 对象的图像格式。  | 
| int32_t [OH_Image_GetComponent](#oh_image_getcomponent) (const [ImageNative](#imagenative) \*native, int32_t componentType, struct [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) \*componentNative) | 从 native **ImageNative** 对象中获取 [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md)。  | 
| int32_t [OH_Image_Release](#oh_image_release) ([ImageNative](#imagenative) \*native) | 释放 **ImageNative** native对象。   | 
| int32_t [OH_ImagePacker_Create](#oh_imagepacker_create) (napi_env env, napi_value \*res) | 获取JavaScript native层ImagePacker对象。  | 
| [ImagePacker_Native](#imagepacker_native) \* [OH_ImagePacker_InitNative](#oh_imagepacker_initnative) (napi_env env, napi_value packer) | 从输入JavaScript native层ImagePacker对象中，转换成ImagePacker_Native值。  | 
| int32_t [OH_ImagePacker_PackToData](#oh_imagepacker_packtodata) ([ImagePacker_Native](#imagepacker_native) \*native, napi_value source, [ImagePacker_Opts](#imagepacker_opts) \*opts, uint8_t \*outData, size_t \*size) | 通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层PixelMap对象或者ImageSource对象编码并输出到指定的缓存区outData中。 | 
| int32_t [OH_ImagePacker_PackToFile](#oh_imagepacker_packtofile) ([ImagePacker_Native](#imagepacker_native) \*native, napi_value source, [ImagePacker_Opts](#imagepacker_opts) \*opts, int fd) | 通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层PixelMap对象或者ImageSource对象编码并输出到指定的文件中。 | 
| int32_t [OH_ImagePacker_Release](#oh_imagepacker_release) ([ImagePacker_Native](#imagepacker_native) \*native) | 释放native层编码器对象[ImagePacker_Native](#imagepacker_native)。 | 
| int32_t [OH_PixelMap_CreatePixelMap](#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | 创建**PixelMap**对象。  | 
| int32_t [OH_PixelMap_CreatePixelMapWithStride](#oh_pixelmap_createpixelmapwithstride) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, int32_t rowStride, napi_value \*res) | 创建**PixelMap**对象。当前只支持输入流为BGRA格式的流。pixelmap内存在RGBA格式下，默认为DMA内存（图片512\*512以上）。  | 
| int32_t [OH_PixelMap_CreateAlphaPixelMap](#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | 根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的**PixelMap**对象。  | 
| [NativePixelMap](#nativepixelmap) \* [OH_PixelMap_InitNativePixelMap](#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | 初始化**NativePixelMap**对象。  | 
| int32_t [OH_PixelMap_GetBytesNumberPerRow](#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*num) | 获取**PixelMap**对象每行字节数。  | 
| int32_t [OH_PixelMap_GetIsEditable](#oh_pixelmap_getiseditable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*editable) | 获取**PixelMap**对象是否可编辑的状态。  | 
| int32_t [OH_PixelMap_IsSupportAlpha](#oh_pixelmap_issupportalpha) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*alpha) | 获取**PixelMap**对象是否支持Alpha通道。  | 
| int32_t [OH_PixelMap_SetAlphaAble](#oh_pixelmap_setalphaable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t alpha) | 设置**PixelMap**对象的Alpha通道。  | 
| int32_t [OH_PixelMap_GetDensity](#oh_pixelmap_getdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*density) | 获取**PixelMap**对象像素密度。  | 
| int32_t [OH_PixelMap_SetDensity](#oh_pixelmap_setdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t density) | 设置**PixelMap**对象像素密度。  | 
| int32_t [OH_PixelMap_SetOpacity](#oh_pixelmap_setopacity) (const [NativePixelMap](#nativepixelmap) \*native, float opacity) | 设置**PixelMap**对象的透明度。  | 
| int32_t [OH_PixelMap_Scale](#oh_pixelmap_scale) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的缩放。  | 
| int32_t [OH_PixelMap_ScaleWithAntiAliasing](#oh_pixelmap_scalewithantialiasing) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y, [OH_PixelMap_AntiAliasingLevel](#oh_pixelmap_antialiasinglevel) level) | 根据指定的缩放算法和输入的宽高对图片进行缩放。  | 
| int32_t [OH_PixelMap_Translate](#oh_pixelmap_translate) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | 设置**PixelMap**对象的偏移。  | 
| int32_t [OH_PixelMap_Rotate](#oh_pixelmap_rotate) (const [NativePixelMap](#nativepixelmap) \*native, float angle) | 设置**PixelMap**对象的旋转。  | 
| int32_t [OH_PixelMap_Flip](#oh_pixelmap_flip) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y) | 设置**PixelMap**对象的翻转。  | 
| int32_t [OH_PixelMap_Crop](#oh_pixelmap_crop) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y, int32_t width, int32_t height) | 设置**PixelMap**对象的裁剪。  | 
| int32_t [OH_PixelMap_GetImageInfo](#oh_pixelmap_getimageinfo) (const [NativePixelMap](#nativepixelmap) \*native, [OhosPixelMapInfos](_ohos_pixel_map_infos.md) \*info) | 获取**PixelMap**对象图像信息。  | 
| int32_t [OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels) (const [NativePixelMap](#nativepixelmap) \*native, void \*\*addr) | 获取native **PixelMap** 对象数据的内存地址，并锁定该内存。  | 
| int32_t [OH_PixelMap_UnAccessPixels](#oh_pixelmap_unaccesspixels) (const [NativePixelMap](#nativepixelmap) \*native) | 释放native **PixelMap**对象数据的内存锁，用于匹配方法[OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels)。  | 
| int32_t [OH_GetImageInfo](#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) \*info) | 获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md)结构中。  | 
| int32_t [OH_AccessPixels](#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | 获取**PixelMap**对象数据的内存地址，并锁定该内存。  | 
| int32_t [OH_UnAccessPixels](#oh_unaccesspixels) (napi_env env, napi_value value) | 释放**PixelMap**对象数据的内存锁, 用于匹配方法**OH_AccessPixels**。  | 
| int32_t [OH_Image_Receiver_CreateImageReceiver](#oh_image_receiver_createimagereceiver) (napi_env env, struct [OhosImageReceiverInfo](_ohos_image_receiver_info.md) info, napi_value \*res) | 创建应用层 **ImageReceiver** 对象。  | 
| [ImageReceiverNative](#imagereceivernative) \* [OH_Image_Receiver_InitImageReceiverNative](#oh_image_receiver_initimagereceivernative) (napi_env env, napi_value source) | 通过应用层**ImageReceiver**对象初始化native层[ImageReceiverNative](#imagereceivernative)对象。  | 
| int32_t [OH_Image_Receiver_GetReceivingSurfaceId](#oh_image_receiver_getreceivingsurfaceid) (const [ImageReceiverNative](#imagereceivernative) \*native, char \*id, size_t len) | 通过[ImageReceiverNative](#imagereceivernative)获取receiver的id。  | 
| int32_t [OH_Image_Receiver_ReadLatestImage](#oh_image_receiver_readlatestimage) (const [ImageReceiverNative](#imagereceivernative) \*native, napi_value \*image) | 通过[ImageReceiverNative](#imagereceivernative)获取最新的一张图片。  | 
| int32_t [OH_Image_Receiver_ReadNextImage](#oh_image_receiver_readnextimage) (const [ImageReceiverNative](#imagereceivernative) \*native, napi_value \*image) | 通过[ImageReceiverNative](#imagereceivernative)获取下一张图片。  | 
| int32_t [OH_Image_Receiver_On](#oh_image_receiver_on) (const [ImageReceiverNative](#imagereceivernative) \*native, [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback) | 注册一个[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调事件。每当接收新图片，该回调事件就会响应。  | 
| int32_t [OH_Image_Receiver_GetSize](#oh_image_receiver_getsize) (const [ImageReceiverNative](#imagereceivernative) \*native, struct [OhosImageSize](_ohos_image_size.md) \*size) | 通过[ImageReceiverNative](#imagereceivernative)获取**ImageReceiver**的大小。  | 
| int32_t [OH_Image_Receiver_GetCapacity](#oh_image_receiver_getcapacity) (const [ImageReceiverNative](#imagereceivernative) \*native, int32_t \*capacity) | 通过[ImageReceiverNative](#imagereceivernative)获取**ImageReceiver**的容量。  | 
| int32_t [OH_Image_Receiver_GetFormat](#oh_image_receiver_getformat) (const [ImageReceiverNative](#imagereceivernative) \*native, int32_t \*format) | 通过[ImageReceiverNative](#imagereceivernative)获取**ImageReceiver**的格式。  | 
| int32_t [OH_Image_Receiver_Release](#oh_image_receiver_release) ([ImageReceiverNative](#imagereceivernative) \*native) | 释放native层 [ImageReceiverNative](#imagereceivernative) 对象。 | 
| int32_t [OH_ImageSource_Create](#oh_imagesource_create) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*src, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的信息[OhosImageSource](_ohos_image_source.md)和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromUri](#oh_imagesource_createfromuri) (napi_env env, char \*uri, size_t size, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的标识符URI和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromFd](#oh_imagesource_createfromfd) (napi_env env, int32_t fd, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的文件描述符fd和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromData](#oh_imagesource_createfromdata) (napi_env env, uint8_t \*data, size_t dataSize, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的图像源缓冲区资源data和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateFromRawFile](#oh_imagesource_createfromrawfile) (napi_env env, RawFileDescriptor rawFile, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的资源描述符**RawFileDescriptor**和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateIncremental](#oh_imagesource_createincremental) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*source, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的infomations[OhosImageSource](_ohos_image_source.md)和[OhosImageSourceOps](_ohos_image_source_ops.md)结构，获取增量类型的JavaScript native层**ImageSource**对象。  | 
| int32_t [OH_ImageSource_CreateIncrementalFromData](#oh_imagesource_createincrementalfromdata) (napi_env env, uint8_t \*data, size_t dataSize, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | 通过给定的图像源缓冲区资源data和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取增量类型的JavaScript Native API ImageSource对象，图像数据应通过OH_ImageSource_UpdateData更新。  | 
| int32_t [OH_ImageSource_GetSupportedFormats](#oh_imagesource_getsupportedformats) (struct [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) \*res) | 获取所有支持的解码格式元标记。  | 
| [ImageSourceNative](#imagesourcenative) \* [OH_ImageSource_InitNative](#oh_imagesource_initnative) (napi_env env, napi_value source) | 从输入JavaScript native层**ImageSource** 对象中，转换成[ImageSourceNative](#imagesourcenative)值。  | 
| int32_t [OH_ImageSource_CreatePixelMap](#oh_imagesource_createpixelmap) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | 通过一个给定的选项[OhosImageDecodingOps](_ohos_image_decoding_ops.md)结构体，从**ImageSource**中解码JavaScript native层**PixelMap**对象  | 
| int32_t [OH_ImageSource_CreatePixelMapList](#oh_imagesource_createpixelmaplist) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | 通过一个给定的选项[OhosImageDecodingOps](_ohos_image_decoding_ops.md)结构体，从**ImageSource**中解码所有的JavaScript native层**PixelMap**对象列表  | 
| int32_t [OH_ImageSource_GetDelayTime](#oh_imagesource_getdelaytime) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) \*res) | 从一些**ImageSource**（如GIF图像源）获取延迟时间列表。  | 
| int32_t [OH_ImageSource_GetFrameCount](#oh_imagesource_getframecount) (const [ImageSourceNative](#imagesourcenative) \*native, uint32_t \*res) | 从**ImageSource**中获取帧计数。  | 
| int32_t [OH_ImageSource_GetImageInfo](#oh_imagesource_getimageinfo) (const [ImageSourceNative](#imagesourcenative) \*native, int32_t index, struct [OhosImageSourceInfo](_ohos_image_source_info.md) \*info) | 通过索引从**ImageSource**获取图像源信息。  | 
| int32_t [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | 通过关键字从**ImageSource**中获取图像源属性。  | 
| int32_t [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | 通过关键字为**ImageSource**修改图像源属性。  | 
| int32_t [OH_ImageSource_UpdateData](#oh_imagesource_updatedata) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) \*data) | 为了增量类型的**ImageSource**更新源数据。  | 
| int32_t [OH_ImageSource_Release](#oh_imagesource_release) ([ImageSourceNative](#imagesourcenative) \*native) | 释放native层图像源**ImageSourceNative**。  | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| const char \* [OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](#ohos_image_property_bits_per_sample) = "BitsPerSample" | 定义每个样本比特的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_ORIENTATION](#ohos_image_property_orientation) = "Orientation" | 定义方向的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](#ohos_image_property_image_length) = "ImageLength" | 定义图像长度的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](#ohos_image_property_image_width) = "ImageWidth" | 定义图像宽度的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LATITUDE](#ohos_image_property_gps_latitude) = "GPSLatitude" | 定义GPS纬度的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](#ohos_image_property_gps_longitude) = "GPSLongitude" | 定义GPS经度的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | 定义GPS纬度参考的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | 定义GPS经度参考的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](#ohos_image_property_date_time_original) = "DateTimeOriginal" | 定义初始日期时间的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](#ohos_image_property_exposure_time) = "ExposureTime" | 定义曝光时间的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_SCENE_TYPE](#ohos_image_property_scene_type) = "SceneType" | 定义场景类型的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | 定义ISO速度等级的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_F_NUMBER](#ohos_image_property_f_number) = "FNumber" | 定义FNumber的图像属性关键字。  | 
| const char \* [OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | 定义每个像素的压缩比特的图像属性关键字。  | 
| int32_t [OhosImageRegion::x](#x) | 起始x坐标，用pixels表示。  | 
| int32_t [OhosImageRegion::y](#y) | 起始y坐标，用pixels表示。  | 
| int32_t [OhosImageRegion::width](#width) | 宽度范围，用pixels表示。  | 
| int32_t [OhosImageRegion::height](#height) | 高度范围，用pixels表示。  | 
| int32_t [OhosImageSourceOps::density](#density-12) | 图像源像素密度。  | 
| int32_t [OhosImageSourceOps::pixelFormat](#pixelformat-13) | 图像源像素格式，通常用于描述YUV缓冲区。  | 
| struct [OhosImageSize](_ohos_image_size.md) [OhosImageSourceOps::size](#size-17) | 图像源像素宽高的大小。  | 
| int8_t [OhosImageDecodingOps::editable](#editable) | 定义输出的像素位图是否可编辑。  | 
| int32_t [OhosImageDecodingOps::pixelFormat](#pixelformat-23) | 定义输出的像素格式。  | 
| int32_t [OhosImageDecodingOps::fitDensity](#fitdensity) | 定义解码目标的像素密度。  | 
| uint32_t [OhosImageDecodingOps::index](#index) | 定义图像源解码指数。  | 
| uint32_t [OhosImageDecodingOps::sampleSize](#samplesize) | 定义解码样本大小选项。  | 
| uint32_t [OhosImageDecodingOps::rotate](#rotate) | 定义解码旋转选项。  | 
| struct [OhosImageSize](_ohos_image_size.md) [OhosImageDecodingOps::size](#size-27) | 定义解码目标像素宽高的大小。  | 
| struct [OhosImageRegion](_ohos_image_region.md) [OhosImageDecodingOps::region](#region) | 定义图像源解码的像素范围。  | 
| int32_t [OhosImageSourceInfo::pixelFormat](#pixelformat-33) | 图像源像素格式，由 [OH_ImageSource_Create](#oh_imagesource_create)设置。  | 
| int32_t [OhosImageSourceInfo::colorSpace](#colorspace) | 图像源色彩空间。  | 
| int32_t [OhosImageSourceInfo::alphaType](#alphatype) | 图像源透明度类型。  | 
| int32_t [OhosImageSourceInfo::density](#density-22) | 图像源密度，由[OH_ImageSource_Create](#oh_imagesource_create)设置。  | 
| struct [OhosImageSize](_ohos_image_size.md) [OhosImageSourceInfo::size](#size-37) | 图像源像素宽高的大小。  | 
| char \* [OhosImageSource::uri](#uri) = nullptr | 图像源资源标识符，接受文件资源或者base64资源。  | 
| size_t [OhosImageSource::uriSize](#urisize) = 0 | 图像源资源长度。  | 
| int32_t [OhosImageSource::fd](#fd) = -1 | 图像源文件资源描述符。  | 
| uint8_t \* [OhosImageSource::buffer](#buffer-12) = nullptr | 图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区。  | 
| size_t [OhosImageSource::bufferSize](#buffersize-12) = 0 | 图像源缓冲区资源大小。  | 
| int32_t \* [OhosImageSourceDelayTimeList::delayTimeList](#delaytimelist) | 图像源延迟时间列表头地址。  | 
| size_t [OhosImageSourceDelayTimeList::size](#size-47) = 0 | 图像源延迟时间列表大小。  | 
| char \* [OhosImageSourceSupportedFormat::format](#format) = nullptr | 图像源支持的格式字符串头地址。  | 
| size_t [OhosImageSourceSupportedFormat::size](#size-57) = 0 | 图像源支持的格式字符串大小。  | 
| struct [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md) \*\* [OhosImageSourceSupportedFormatList::supportedFormatList](#supportedformatlist) = nullptr | 图像源支持的格式字符串列表头地址。  | 
| size_t [OhosImageSourceSupportedFormatList::size](#size-67) = 0 | 图像源支持的格式字符串列表大小。  | 
| char \* [OhosImageSourceProperty::value](#value) = nullptr | 定义图像源属性键值字符串头地址。  | 
| size_t [OhosImageSourceProperty::size](#size-77) = 0 | 定义图像源属性键值字符串大小。  | 
| uint8_t \* [OhosImageSourceUpdateData::buffer](#buffer-22) = nullptr | 图像源更新数据缓冲区。  | 
| size_t [OhosImageSourceUpdateData::bufferSize](#buffersize-22) = 0 | 图像源更新数据缓冲区大小。  | 
| uint32_t [OhosImageSourceUpdateData::offset](#offset) = 0 | 图像源更新数据缓冲区的开端。  | 
| uint32_t [OhosImageSourceUpdateData::updateLength](#updatelength) = 0 | 图像源更新数据缓冲区的更新数据长度。  | 
| int8_t [OhosImageSourceUpdateData::isCompleted](#iscompleted) = 0 | 图像源更新数据在此节中完成。  | 


## 类型定义说明


### ImageNative

```
typedef struct ImageNative_ ImageNative
```
**描述**
为图像接口定义native层图像对象。

**起始版本：** 10


### ImagePacker_Native

```
typedef struct ImagePacker_Native_ ImagePacker_Native
```
**描述**
为编码器方法定义native层编码器对象。

**起始版本：** 11


### ImagePacker_Opts

```
typedef struct ImagePacker_Opts_ ImagePacker_Opts
```
**描述**
定义图像编码选项的别名。

**起始版本：** 11


### ImageReceiverNative

```
typedef struct ImageReceiverNative_ ImageReceiverNative
```
**描述**
用于定义ImageReceiverNative数据类型名称。

**起始版本：** 10


### ImageSourceNative

```
typedef struct ImageSourceNative_ ImageSourceNative
```
**描述**
为图像源方法定义native层图像源对象。

**系统能力：** SystemCapability.Multimedia.Image

**起始版本：** 10


### NativePixelMap

```
typedef struct NativePixelMap_ NativePixelMap
```
**描述**
定义native层PixelMap数据类型名称。

**起始版本：** 10


### OH_Image_Receiver_On_Callback

```
typedef void(* OH_Image_Receiver_On_Callback) ()
```
**描述**
定义native层图片的回调方法。

**起始版本：** 10


### OhosPixelMapInfos

```
typedef struct OhosPixelMapInfos
```
**描述**
用于定义PixelMap的相关信息。

**起始版本：** 10


## 枚举类型说明


### 图像格式

```
anonymous enum
```
**描述**
图像格式枚举值。

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_IMAGE_FORMAT_YCBCR_422_SP | YCBCR422 semi-planar 格式 | 
| OHOS_IMAGE_FORMAT_JPEG | JPEG 编码格式 | 


### PixelMap透明度类型

```
anonymous enum
```
**描述**
PixelMap透明度类型的枚举。

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN  | 未知的格式   | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE  | 不透明的格式   | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL  | 预乘的格式   | 
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL  | 预除的格式   | 


### 方法返回的错误码

```
anonymous enum
```
**描述**
函数方法返回值的错误码的枚举。

**废弃版本：** 10

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_IMAGE_RESULT_SUCCESS | 成功的结果 | 
| OHOS_IMAGE_RESULT_BAD_PARAMETER | 无效值 | 


### 图像颜色通道类型

```
anonymous enum
```
**描述**
图像颜色通道类型枚举值。

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y | 亮度信息 | 
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_U | 色度信息 | 
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_V | 色差值信息 | 
| OHOS_IMAGE_COMPONENT_FORMAT_JPEG | Jpeg 格式 | 


### PixelMap 编辑类型

```
anonymous enum
```
**描述**
PixelMap 编辑类型的枚举。

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_READ_ONLY  | 只读的格式   | 
| OHOS_PIXEL_MAP_EDITABLE  | 可编辑的格式   | 


### 像素格式

```
anonymous enum
```
**描述**
像素格式的枚举。

**废弃版本：** 10

**起始版本：** 8

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_FORMAT_NONE  | 未知的格式  | 
| OHOS_PIXEL_MAP_FORMAT_RGBA_8888  | RGBA_8888格式   | 
| OHOS_PIXEL_MAP_FORMAT_RGB_565  | RGB_565格式   | 

### PixelMap缩放类型

```
anonymous enum
```
**描述**
PixelMap缩放类型的枚举。

**起始版本：** 10

| 枚举值 | 描述 | 
| -------- | -------- |
| OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE  | 适应目标图片大小的格式   | 
| OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP  | 以中心进行缩放的格式   | 


### IRNdkErrCode

```
enum IRNdkErrCode
```
**描述**
可能被使用的接口返回值的枚举。

**起始版本：** 10


| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_RESULT_SUCCESS | 操作成功 | 
| IMAGE_RESULT_BAD_PARAMETER | 无效参数 | 
| IMAGE_RESULT_IMAGE_RESULT_BASE | 操作失败 | 
| IMAGE_RESULT_ERR_IPC | ipc 错误 | 
| IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST | 共享内存失败 | 
| IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL | 共享内存数据异常 | 
| IMAGE_RESULT_DECODE_ABNORMAL | 图像解码失败 | 
| IMAGE_RESULT_DATA_ABNORMAL | 图像输入数据异常 | 
| IMAGE_RESULT_MALLOC_ABNORMAL | 图像内存分配异常 | 
| IMAGE_RESULT_DATA_UNSUPPORT | 图像类型不支持 | 
| IMAGE_RESULT_INIT_ABNORMAL | 图像初始化失败 | 
| IMAGE_RESULT_GET_DATA_ABNORMAL | 图像获取数据错误 | 
| IMAGE_RESULT_TOO_LARGE | 图像数据过大 | 
| IMAGE_RESULT_TRANSFORM | 图像转换错误 | 
| IMAGE_RESULT_COLOR_CONVERT | 图像颜色转换错误 | 
| IMAGE_RESULT_CROP | 裁剪错误 | 
| IMAGE_RESULT_SOURCE_DATA | 图像源数据错误 | 
| IMAGE_RESULT_SOURCE_DATA_INCOMPLETE | 图像源数据不完整 | 
| IMAGE_RESULT_MISMATCHED_FORMAT | 图像格式不匹配 | 
| IMAGE_RESULT_UNKNOWN_FORMAT | 图像未知格式 | 
| IMAGE_RESULT_SOURCE_UNRESOLVED | 图像源未解析 | 
| IMAGE_RESULT_INVALID_PARAMETER | 图像无效参数 | 
| IMAGE_RESULT_DECODE_FAILED | 解码失败 | 
| IMAGE_RESULT_PLUGIN_REGISTER_FAILED | 注册插件失败 | 
| IMAGE_RESULT_PLUGIN_CREATE_FAILED | 创建插件失败 | 
| IMAGE_RESULT_ENCODE_FAILED | 图像编码失败 | 
| IMAGE_RESULT_ADD_PIXEL_MAP_FAILED | 图像添加像素位图失败 | 
| IMAGE_RESULT_HW_DECODE_UNSUPPORT | 图像硬解码不支持 | 
| IMAGE_RESULT_DECODE_HEAD_ABNORMAL | 图像头解码失败 | 
| IMAGE_RESULT_DECODE_EXIF_UNSUPPORT | 图像解码EXIF不支持 | 
| IMAGE_RESULT_PROPERTY_NOT_EXIST | 图像属性不存在 | 
| IMAGE_RESULT_MEDIA_DATA_UNSUPPORT | 媒体类型不支持 | 
| IMAGE_RESULT_MEDIA_TOO_LARGE | 媒体数据过大 | 
| IMAGE_RESULT_MEDIA_MALLOC_FAILED | 媒体分配内存失败 | 
| IMAGE_RESULT_MEDIA_END_OF_STREAM | 媒体数据流结束失败 | 
| IMAGE_RESULT_MEDIA_IO_ABNORMAL | 媒体输入输出流异常 | 
| IMAGE_RESULT_MEDIA_MALFORMED | 媒体功能异常 | 
| IMAGE_RESULT_MEDIA_BUFFER_TOO_SMALL | 媒体数据过小错误 | 
| IMAGE_RESULT_MEDIA_OUT_OF_RANGE | 媒体超出范围错误 | 
| IMAGE_RESULT_MEDIA_STATUS_ABNORMAL | 媒体状态异常错误 | 
| IMAGE_RESULT_MEDIA_VALUE_INVALID | 媒体值无效 | 
| IMAGE_RESULT_MEDIA_NULL_POINTER | 媒体操作失败 | 
| IMAGE_RESULT_MEDIA_INVALID_OPERATION | 媒体操作无效 | 
| IMAGE_RESULT_MEDIA_ERR_PLAYER_NOT_INIT | 媒体初始化异常 | 
| IMAGE_RESULT_MEDIA_EARLY_PREPARE | 媒体过早预处理 | 
| IMAGE_RESULT_MEDIA_SEEK_ERR | 媒体查找失败 | 
| IMAGE_RESULT_MEDIA_PERMISSION_DENIED | 媒体权限拒绝 | 
| IMAGE_RESULT_MEDIA_DEAD_OBJECT | 媒体对象注销 | 
| IMAGE_RESULT_MEDIA_TIMED_OUT | 媒体超时 | 
| IMAGE_RESULT_MEDIA_TRACK_NOT_ALL_SUPPORTED | 媒体能力不支持 | 
| IMAGE_RESULT_MEDIA_ADAPTER_INIT_FAILED | 媒体适配器初始化失败 | 
| IMAGE_RESULT_MEDIA_WRITE_PARCEL_FAIL | 写入parcel失败 | 
| IMAGE_RESULT_MEDIA_READ_PARCEL_FAIL | 读取parcel失败 | 
| IMAGE_RESULT_MEDIA_NO_AVAIL_BUFFER | 无效数据 | 
| IMAGE_RESULT_MEDIA_INVALID_PARAM | 媒体接口发现无效参数 | 
| IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_EXIST | 媒体代码适配器不存在 | 
| IMAGE_RESULT_MEDIA_CREATE_CODEC_ADAPTER_FAILED | 媒体创建代码适配器失败 | 
| IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_INIT | 媒体代码适配器未初始化 | 
| IMAGE_RESULT_MEDIA_ZCODEC_CREATE_FAILED | 媒体代码创建失败 | 
| IMAGE_RESULT_MEDIA_ZCODEC_NOT_EXIST | 媒体代码不存在 | 
| IMAGE_RESULT_MEDIA_JNI_CLASS_NOT_EXIST | 媒体JNI层类不存在 | 
| IMAGE_RESULT_MEDIA_JNI_METHOD_NOT_EXIST | 媒体JNI层方法不存在 | 
| IMAGE_RESULT_MEDIA_JNI_NEW_OBJ_FAILED | 媒体JNI层创建对象失败 | 
| IMAGE_RESULT_MEDIA_JNI_COMMON_ERROR | 媒体JNI层异常 | 
| IMAGE_RESULT_MEDIA_DISTRIBUTE_NOT_SUPPORT | 媒体不支持分布 | 
| IMAGE_RESULT_MEDIA_SOURCE_NOT_SET | 媒体源未设置 | 
| IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_INIT | 媒体rtsp适配器未初始化 | 
| IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_EXIST | 媒体rtsp适配器不存在 | 
| IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT | 媒体不支持rtsp surface | 
| IMAGE_RESULT_MEDIA_RTSP_CAPTURE_NOT_INIT | 媒体rtsp capture初始化失败 | 
| IMAGE_RESULT_MEDIA_RTSP_SOURCE_URL_INVALID | 媒体rtsp源路径无效 | 
| IMAGE_RESULT_MEDIA_RTSP_VIDEO_TRACK_NOT_FOUND | 媒体rtsp未发现视频能力 | 
| IMAGE_RESULT_MEDIA_RTSP_CAMERA_NUM_REACH_MAX | rtsp相机数量达到最大数量 | 
| IMAGE_RESULT_MEDIA_SET_VOLUME | 媒体设置卷失败 | 
| IMAGE_RESULT_MEDIA_NUMBER_OVERFLOW | 媒体操作次数溢出 | 
| IMAGE_RESULT_MEDIA_DIS_PLAYER_UNSUPPORTED | 媒体分布式播放器不支持 | 
| IMAGE_RESULT_MEDIA_DENCODE_ICC_FAILED | 图像解码ICC失败 | 
| IMAGE_RESULT_MEDIA_ENCODE_ICC_FAILED | 图像编码ICC失败 | 
| IMAGE_RESULT_MEDIA_READ_PIXELMAP_FAILED | 读取像素位图失败 | 
| IMAGE_RESULT_MEDIA_WRITE_PIXELMAP_FAILED | 写入像素位图失败 | 
| IMAGE_RESULT_MEDIA_PIXELMAP_NOT_ALLOW_MODIFY | 像素位图不允许修改 | 
| IMAGE_RESULT_MEDIA_CONFIG_FAILED | 配置失败 | 
| IMAGE_RESULT_JNI_ENV_ABNORMAL | JNI环境异常 | 
| IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED | surface申请内存失败 | 
| IMAGE_RESULT_CREATE_SURFACE_FAILED | 创建surface失败 | 
| IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED | 从surface获取参数失败 | 
| IMAGE_RESULT_GET_SURFACE_FAILED | 获取surface失败 | 
| IMAGE_RESULT_SURFACE_ACQUIRE_BUFFER_FAILED | 申请内存失败 | 
| IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED | 申请内存失败 | 
| IMAGE_RESULT_REGISTER_LISTENER_FAILED | 注册监听失败 | 
| IMAGE_RESULT_REGISTER_BUFFER_FAILED | 注册内存失败 | 
| IMAGE_RESULT_FREAD_FAILED | 读取文件失败 | 
| IMAGE_RESULT_PEEK_FAILED | 检测文件失败 | 
| IMAGE_RESULT_SEEK_FAILED | 查找文件失败 | 
| IMAGE_RESULT_STREAM_SIZE_ERROR | 数据流损坏 | 
| IMAGE_RESULT_FILE_FD_ERROR | 文件描述符损坏 | 
| IMAGE_RESULT_FILE_DAMAGED | 文件损坏 | 
| IMAGE_RESULT_CREATE_DECODER_FAILED | 创建解码失败 | 
| IMAGE_RESULT_CREATE_ENCODER_FAILED | 创建编码失败 | 
| IMAGE_RESULT_CHECK_FORMAT_ERROR | 检查格式失败 | 
| IMAGE_RESULT_THIRDPART_SKIA_ERROR | skia解码失败 | 
| IMAGE_RESULT_HW_DECODE_FAILED | 硬解码失败 | 
| IMAGE_RESULT_ALLOCATER_TYPE_ERROR | 内存类型校验失败 | 
| IMAGE_RESULT_ALPHA_TYPE_ERROR | 透明度类型失败 | 
| IMAGE_RESULT_INDEX_INVALID | 参数无效 | 
| IMAGE_RESULT_MEDIA_UNKNOWN | 媒体未知错误 | 


### OH_PixelMap_AntiAliasingLevel

```
enum OH_PixelMap_AntiAliasingLevel
```
**描述**
Pixelmap缩放时采用的缩放算法。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_PixelMap_AntiAliasing_NONE  | 最近邻插值算法。   | 
| OH_PixelMap_AntiAliasing_LOW  | 双线性插值算法。   | 
| OH_PixelMap_AntiAliasing_MEDIUM  | 双线性插值算法，同时开启Mipmap。缩小图片时建议使用。   | 
| OH_PixelMap_AntiAliasing_HIGH  | 三次插值算法。   | 


## 函数说明


### OH_AccessPixels()

```
int32_t OHOS::Media::OH_AccessPixels (napi_env env, napi_value value, void ** addrPtr )
```
**描述**
获取**PixelMap**对象数据的内存地址，并锁定该内存。

函数执行成功后，**\*addrPtr**就是获取的待访问的内存地址。访问操作完成后，必须要使用**OH_UnAccessPixels**来释放锁，否则的话资源无法被释放。 待解锁后，内存地址就不可以再被访问和操作。

**废弃版本：** 10

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| value | 应用层的 **PixelMap** 对象。  | 
| addrPtr | 用于指向的内存地址的指针对象。  | 

**参见：**

UnAccessPixels

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果操作失败返回IMAGE_RESULT_BAD_PARAMETER。


### OH_GetImageInfo()

```
int32_t OH_GetImageInfo (napi_env env, napi_value value, OhosPixelMapInfo * info )
```
**描述**
获取 **PixelMap** 的信息，并记录信息到[OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md)结构中。

**废弃版本：** 10

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| value | 应用层的 **PixelMap** 对象。  | 
| info | 用于保存信息的指针对象。 更多细节, 参看 [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md)。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果操作失败返回IMAGE_RESULT_BAD_PARAMETER。

**参见：**

[OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md)


### OH_Image_ClipRect()

```
int32_t OH_Image_ClipRect (const ImageNative * native, struct OhosImageRect * rect )
```
**描述**
获取native **ImageNative** 对象 [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) 信息。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表示指向 **ImageNative** native层对象的指针。  | 
| rect | 表示作为转换结果的 [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) 对象指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回IMAGE_RESULT_SUCCESS；

如果JNI环境异常返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效返回IMAGE_RESULT_INVALID_PARAMETER；

如果从surface获取参数失败返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果参数错误返回IMAGE_RESULT_BAD_PARAMETER 。

**参见：**

[ImageNative](image.md#imagenative), [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md)


### OH_Image_Format()

```
int32_t OH_Image_Format (const ImageNative * native, int32_t * format )
```
**描述**
获取native **ImageNative** 对象的图像格式。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表示 **ImageNative** native对象的指针。  | 
| format | 表示作为转换结果的图像格式对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回IMAGE_RESULT_SUCCESS；

如果JNI环境异常返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效返回IMAGE_RESULT_INVALID_PARAMETER；

如果从surface获取参数失败返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果参数错误返回IMAGE_RESULT_BAD_PARAMETER 。


**参见：**

[ImageNative](image.md#imagenative)


### OH_Image_GetComponent()

```
int32_t OH_Image_GetComponent (const ImageNative * native, int32_t componentType, struct OhosImageComponent * componentNative )
```
**描述**
从 native **ImageNative** 对象中获取 [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表示 **ImageNative** native对象的指针。  | 
| componentType | 表示所需组件的组件类型。  | 
| componentNative | 表示转换结果的 [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) 对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回IMAGE_RESULT_SUCCESS；

如果JNI环境异常返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效返回IMAGE_RESULT_INVALID_PARAMETER；

如果从surface获取参数失败返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果参数错误返回IMAGE_RESULT_BAD_PARAMETER 。

**参见：**

[ImageNative](image.md#imagenative), [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md)


### OH_Image_InitImageNative()

```
ImageNative* OH_Image_InitImageNative (napi_env env, napi_value source )
```
**描述**
从输入的JavaScript Native API **图像** 对象中解析 native **ImageNative** 对象。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表示指向 JNI 环境的指针。  | 
| source | 表示 JavaScript Native API **图像** 对象。  | 

**返回：**

如果操作成果返回 **ImageNative** 指针对象，如果操作失败返回空指针。

**参见：**

[ImageNative](image.md#imagenative), [OH_Image_Release](image.md#oh_image_release)


### OH_Image_Receiver_CreateImageReceiver()

```
int32_t OH_Image_Receiver_CreateImageReceiver (napi_env env, struct OhosImageReceiverInfo info, napi_value * res )
```
**描述**
创建应用层 **ImageReceiver** 对象。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| info | **ImageReceiver** 数据设置项。  | 
| res | 应用层的 **ImageReceiver** 对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

从surface获取参数失败则返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果创建surface失败则返回IMAGE_RESULT_CREATE_SURFACE_FAILED；

如果surface分配内存失败则返回IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED；

如果获取surface失败则返回IMAGE_RESULT_GET_SURFACE_FAILED；

如果媒体rtsp surface不支持则返回IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果媒体类型不支持失败则返回IMAGE_RESULT_MEDIA_DATA_UNSUPPORT。


**参见：**

[OhosImageReceiverInfo](_ohos_image_receiver_info.md)


### OH_Image_Receiver_GetCapacity()

```
int32_t OH_Image_Receiver_GetCapacity (const ImageReceiverNative * native, int32_t * capacity )
```
**描述**
通过[ImageReceiverNative](#imagereceivernative)获取**ImageReceiver**的容量。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 
| capacity | 作为结果的指向容量的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT。


**参见：**

[ImageReceiverNative](#imagereceivernative), [OhosImageSize](_ohos_image_size.md)


### OH_Image_Receiver_GetFormat()

```
int32_t OH_Image_Receiver_GetFormat (const ImageReceiverNative * native, int32_t * format )
```
**描述**
通过[ImageReceiverNative](#imagereceivernative)获取**ImageReceiver**的格式。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 
| format | 作为结果的指向格式的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT。


**参见：**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_GetReceivingSurfaceId()

```
int32_t OH_Image_Receiver_GetReceivingSurfaceId (const ImageReceiverNative * native, char * id, size_t len )
```
**描述**
通过[ImageReceiverNative](#imagereceivernative)获取receiver的id。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 
| id | 指向字符缓冲区的指针，用于获取字符串的id。  | 
| len | **id**所对应的字符缓冲区的大小。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

从surface获取参数失败则返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果获取surface失败则返回IMAGE_RESULT_GET_SURFACE_FAILED；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果媒体类型不支持失败则返回IMAGE_RESULT_MEDIA_DATA_UNSUPPORT。


**参见：**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_GetSize()

```
int32_t OH_Image_Receiver_GetSize (const ImageReceiverNative * native, struct OhosImageSize * size )
```
**描述**
通过[ImageReceiverNative](#imagereceivernative)获取**ImageReceiver**的大小。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 
| size | 作为结果的[OhosImageSize](_ohos_image_size.md)指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT。

**参见：**

[ImageReceiverNative](#imagereceivernative), [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)


### OH_Image_Receiver_InitImageReceiverNative()

```
ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative (napi_env env, napi_value source )
```
**描述**
通过应用层**ImageReceiver**对象初始化native层[ImageReceiverNative](#imagereceivernative)对象。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| source | napi的 **ImageReceiver** 对象。  | 

**返回：**

操作成功则返回 [ImageReceiverNative](#imagereceivernative) 指针；如果操作失败，则返回nullptr。

**参见：**

[ImageReceiverNative](#imagereceivernative), [OH_Image_Receiver_Release](#oh_image_receiver_release)


### OH_Image_Receiver_On()

```
int32_t OH_Image_Receiver_On (const ImageReceiverNative * native, OH_Image_Receiver_On_Callback callback )
```
**描述**
注册一个[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调事件。每当接收新图片，该回调事件就会响应。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 
| callback | [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)事件的回调函数。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效或从surface获取参数失败则返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取surface失败则返回IMAGE_RESULT_GET_SURFACE_FAILED；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果注册监听失败则返回IMAGE_RESULT_REGISTER_LISTENER_FAILED；

如果注册内存失败则返回IMAGE_RESULT_REGISTER_BUFFER_FAILED。


**参见：**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_ReadLatestImage()

```
int32_t OH_Image_Receiver_ReadLatestImage (const ImageReceiverNative * native, napi_value * image )
```
**描述**
通过[ImageReceiverNative](#imagereceivernative)获取最新的一张图片。

**注意**：此接口需要在[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调后调用，才能正常的接收到数据。并且使用此接口返回 **Image** 对象创建的[ImageNative](#imagenative)使用完毕后需要调用[OH_Image_Release](#oh_image_release)方法释放，释放后才可以继续接收新的数据。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 
| image | 获取到的应用层的 **Image** 指针对象。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果从surface获取参数失败返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果创建surface失败则返回IMAGE_RESULT_CREATE_SURFACE_FAILED；

如果surface分配内存失败则返回IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED；

如果获取surface失败则返回IMAGE_RESULT_GET_SURFACE_FAILED；

如果媒体rtsp surface不支持则返回IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果申请内存失败则返回IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED。


**参见：**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_ReadNextImage()

```
int32_t OH_Image_Receiver_ReadNextImage (const ImageReceiverNative * native, napi_value * image )
```
**描述**
通过[ImageReceiverNative](#imagereceivernative)获取下一张图片。

**注意**：此接口需要在[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)回调后调用，才能正常的接收到数据。并且使用此接口返回 **Image** 对象创建的[ImageNative](#imagenative)使用完毕后需要调用[OH_Image_Release](#oh_image_release)方法释放，释放后才可以继续接收新的数据。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 
| image | 读取到的应用层的 **Image** 指针对象。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果从surface获取参数失败返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果创建surface失败则返回IMAGE_RESULT_CREATE_SURFACE_FAILED；

如果surface分配内存失败则返回IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED；

如果获取surface失败则返回IMAGE_RESULT_GET_SURFACE_FAILED；

如果媒体rtsp surface不支持则返回IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT；

如果图像类型不支持失败则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果申请内存失败则返回IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED。

**参见：**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_Release()

```
int32_t OH_Image_Receiver_Release (ImageReceiverNative * native)
```
**描述**
释放native层 [ImageReceiverNative](#imagereceivernative) 对象。注意: 此方法不能释放应用层**ImageReceiver**对象。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | native层的[ImageReceiverNative](#imagereceivernative)指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER。


**参见：**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Release()

```
int32_t OH_Image_Release (ImageNative * native)
```
**描述**
释放 **ImageNative** native对象。 Note: 这个方法无法释放 JavaScript Native API **Image** 对象， 而是释放被 **OH_Image_InitImageNative** 解析的 **ImageNative** native 对象。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表示 **ImageNative** native对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回IMAGE_RESULT_SUCCESS；

如果JNI环境异常返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效返回IMAGE_RESULT_INVALID_PARAMETER；

如果参数错误返回IMAGE_RESULT_BAD_PARAMETER。

**参见：**

[ImageNative](image.md#imagenative), [OH_Image_InitImageNative](image.md#oh_image_initimagenative)


### OH_Image_Size()

```
int32_t OH_Image_Size (const ImageNative * native, struct OhosImageSize * size )
```
**描述**
获取native **ImageNative** 对象的 [OhosImageSize](_ohos_image_size.md) 信息。如果[ImageNative](image.md#imagenative) 对象所存储的是相机预览流数据，即YUV图像数据，那么获取到的[OhosImageSize](_ohos_image_size.md)中的宽高分别对应YUV图像的宽高；如果[ImageNative](image.md#imagenative) 对象所存储的是相机拍照流数据，即JPEG图像，由于已经是编码后的数据，[OhosImageSize](_ohos_image_size.md)中的宽等于JPEG数据大小，高等于1。[ImageNative](image.md#imagenative) 对象所存储的数据是预览流还是拍照流，取决于应用将receiver中的surfaceId传给相机的previewOutput还是captureOutput。相机预览与拍照最佳实践请参考[预览流二次处理(C/C++)](../../media/camera/native-camera-preview-imageReceiver.md)与[拍照(C/C++)](../../media/camera/native-camera-shooting.md)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表示 **ImageNative** native对象的指针。  | 
| size | 表示作为转换结果的 [OhosImageSize](_ohos_image_size.md) 对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回IMAGE_RESULT_SUCCESS；

如果JNI环境异常返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效返回IMAGE_RESULT_INVALID_PARAMETER；

如果从surface获取参数失败返回IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED；

如果参数错误返回IMAGE_RESULT_BAD_PARAMETER。

**参见：**

[ImageNative](image.md#imagenative), [OhosImageSize](_ohos_image_size.md)


### OH_ImagePacker_Create()

```
int32_t OH_ImagePacker_Create (napi_env env, napi_value * res )
```
**描述**
获取JavaScript native层ImagePacker对象。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| res | 表明JavaScript native层ImagePacker对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER。


### OH_ImagePacker_InitNative()

```
ImagePacker_Native* OH_ImagePacker_InitNative (napi_env env, napi_value packer )
```
**描述**
从输入JavaScript native层ImagePacker对象中，转换成ImagePacker_Native值。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| packer | 表明JavaScript native层ImagePacker对象。  | 

**返回：**

如果操作成功则返回[ImagePacker_Native](#imagepacker_native)指针，否则返回空指针。

**参见：**

[OH_ImagePacker_Release](#oh_imagepacker_release)


### OH_ImagePacker_PackToData()

```
int32_t OH_ImagePacker_PackToData (ImagePacker_Native * native, napi_value source, ImagePacker_Opts * opts, uint8_t * outData, size_t * size )
```
**描述**
通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层PixelMap对象或者ImageSource对象编码并输出到指定的缓存区outData中。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明指向native层**ImagePacker**的指针。  | 
| source | 表明待编码JavaScript native层PixelMap对象或者ImageSource对象。  | 
| opts | 表明位图编码的选项，查看[ImagePacker_Opts](#imagepacker_opts)。  | 
| outData | 输出的指定缓存区。  | 
| size | 输出的指定缓存区大小。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数无效返回IMAGE_RESULT_INVALID_PARAMETER；

如果输出缓冲区异常返回ERR_IMAGE_DATA_ABNORMAL；

如果格式不匹配返回ERR_IMAGE_MISMATCHED_FORMAT；

如果malloc内部缓冲区错误返回ERR_IMAGE_MALLOC_ABNORMAL；

如果init编解码器内部错误返回ERR_IMAGE_DECODE_ABNORMAL；

如果编码器在编码过程中出现错误返回ERR_IMAGE_ENCODE_FAILED。

**参见：**

[OH_ImagePacker_PackToFile](#oh_imagepacker_packtofile)


### OH_ImagePacker_PackToFile()

```
int32_t OH_ImagePacker_PackToFile (ImagePacker_Native * native, napi_value source, ImagePacker_Opts * opts, int fd )
```
**描述**
通过一个给定的选项ImagePacker_Opts结构体，将输入JavaScript native层PixelMap对象或者ImageSource对象编码并输出到指定的文件中。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明指向native层**ImagePacker**的指针。  | 
| source | 表明待编码JavaScript native层PixelMap对象或者ImageSource对象。  | 
| opts | 表明位图编码的选项，查看[ImagePacker_Opts](#imagepacker_opts)。  | 
| fd | 输出的指定文件描述符。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数无效返回IMAGE_RESULT_INVALID_PARAMETER；

如果输出缓冲区异常返回ERR_IMAGE_DATA_ABNORMAL；

如果格式不匹配返回ERR_IMAGE_MISMATCHED_FORMAT；

如果malloc内部缓冲区错误返回ERR_IMAGE_MALLOC_ABNORMAL；

如果init编解码器内部错误返回ERR_IMAGE_DECODE_ABNORMAL；

如果编码器在编码过程中出现错误返回ERR_IMAGE_ENCODE_FAILED。

**参见：**

[OH_ImagePacker_PackToData](#oh_imagepacker_packtodata)


### OH_ImagePacker_Release()

```
int32_t OH_ImagePacker_Release (ImagePacker_Native * native)
```
**描述**
释放native层编码器对象[ImagePacker_Native](#imagepacker_native)。 

此API不用于释放JavaScript原生API ImagePacker对象，它用于释放native层对象[ImagePacker_Native](#imagepacker_native)。

通过调用[OH_ImagePacker_InitNative](#oh_imagepacker_initnative)解析。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层[ImagePacker_Native](#imagepacker_native)值的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回IMAGE_RESULT_SUCCESS。

**参见：**

[OH_ImagePacker_InitNative](#oh_imagepacker_initnative)


### OH_ImageSource_Create()

```
int32_t OH_ImageSource_Create (napi_env env, struct OhosImageSource * src, struct OhosImageSourceOps * ops, napi_value * res )
```
**描述**
通过给定的信息[OhosImageSource](_ohos_image_source.md)和[OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。

**起始版本：** 10

**废弃版本：** 11

**替代接口：** [OH_ImageSource_CreateFromUri](#oh_imagesource_createfromuri)，[OH_ImageSource_CreateFromFd](#oh_imagesource_createfromfd)，[OH_ImageSource_CreateFromData](#oh_imagesource_createfromdata)。

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| src | 表明创建一个图像源的信息。查看[OhosImageSource](_ohos_image_source.md)获取更多细节。  | 
| ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](_ohos_image_source_ops.md)。  | 
| res | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，IMAGE_RESULT_INVALID_PARAMETER；

如果图像源数据不完整，返回IMAGE_RESULT_SOURCE_DATA_INCOMPLETE；

如果图像源数据错误，返回IMAGE_RESULT_SOURCE_DATA；

如果图像获取数据错误，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果图像数据太大，返回IMAGE_RESULT_TOO_LARGE；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果图像解码 EXIF 不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图像属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST；

如果文件损坏，返回IMAGE_RESULT_FILE_DAMAGED；

如果文件 FD 错误，返回IMAGE_RESULT_FILE_FD_ERROR；

如果数据流错误，返回IMAGE_RESULT_STREAM_SIZE_ERROR；

如果查找文件失败，返回IMAGE_RESULT_SEEK_FAILED；

如果速览文件失败，返回IMAGE_RESULT_PEEK_FAILED；

如果读取文件失败，返回IMAGE_RESULT_FREAD_FAILED。

**参见：**

[OhosImageSource](_ohos_image_source.md), [OhosImageSourceOps](_ohos_image_source_ops.md)


### OH_ImageSource_CreateFromData()

```
int32_t OH_ImageSource_CreateFromData (napi_env env, uint8_t * data, size_t dataSize, struct OhosImageSourceOps * ops, napi_value * res )
```
**描述**
通过给定的图像源缓冲区资源 data 和 [OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。data数据应该是未解码的数据，不要传入类似于RBGA，YUV的像素buffer数据，如果想通过像素buffer数据创建pixelMap，可以调用[OH_PixelMap_CreatePixelMap](./image__pixel__map__mdk_8h.md)这一类接口。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| data | 表明图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区。  | 
| dataSize | 表明图像源缓冲区资源大小。  | 
| ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](_ohos_image_source_ops.md)。  | 
| res | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER； 

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL； 

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER。

**参见：**

[OhosImageSourceOps](_ohos_image_source_ops.md)


### OH_ImageSource_CreateFromFd()

```
int32_t OH_ImageSource_CreateFromFd (napi_env env, int32_t fd, struct OhosImageSourceOps * ops, napi_value * res )
```
**描述**
通过给定的文件描述符 fd 和 [OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| fd | 表明图像源文件资源描述符。  | 
| ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](_ohos_image_source_ops.md)。  | 
| res | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER。

**参见：**

[OhosImageSourceOps](_ohos_image_source_ops.md)


### OH_ImageSource_CreateFromRawFile()

```
int32_t OH_ImageSource_CreateFromRawFile (napi_env env, RawFileDescriptor rawFile, struct OhosImageSourceOps * ops, napi_value * res )
```
**描述**
通过给定的资源描述符 **RawFileDescriptor** 和 [OhosImageSourceOps](_ohos_image_source_ops.md)结构体， 获取JavaScript native层**ImageSource**对象。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| rawFile | 表明图像源资源描述符。  | 
| ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](_ohos_image_source_ops.md)。  | 
| res | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER。

**参见：**

[OhosImageSourceOps](_ohos_image_source_ops.md)


### OH_ImageSource_CreateFromUri()

```
int32_t OH_ImageSource_CreateFromUri (napi_env env, char * uri, size_t size, struct OhosImageSourceOps * ops, napi_value * res )
```
**描述**
通过给定的标识符URI 和 [OhosImageSourceOps](_ohos_image_source_ops.md)结构体，获取JavaScript native层**ImageSource**对象。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| uri | 表明图像源资源标识符，接受文件资源或者base64资源。当前文件资源只支持绝对路径。  |
| size | 表明图像源资源URI的长度。  | 
| ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](_ohos_image_source_ops.md)。  | 
| res | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER。

**参见：**

[OhosImageSourceOps](_ohos_image_source_ops.md)


### OH_ImageSource_CreateIncremental()

```
int32_t OH_ImageSource_CreateIncremental (napi_env env, struct OhosImageSource * source, struct OhosImageSourceOps * ops, napi_value * res )
```
**描述**
通过给定的informations[OhosImageSource](_ohos_image_source.md)和[OhosImageSourceOps](_ohos_image_source_ops.md)结构， 获取增量类型的JavaScript Native API ImageSource对象，图像数据应通过**OH_ImageSource_UpdateData**更新。

**起始版本：** 10

**废弃版本：** 11

**替代接口：** [OH_ImageSource_CreateIncrementalFromData](#oh_imagesource_createincrementalfromdata)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| src | 表明创建一个图像源的信息，只接收缓冲区类型。具体查看[OhosImageSource](_ohos_image_source.md)。  | 
| ops | 表明创建一个图像源的选项。具体查看[OhosImageSourceOps](_ohos_image_source_ops.md)。  | 
| res | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，IMAGE_RESULT_INVALID_PARAMETER；

如果图像源数据不完整，返回IMAGE_RESULT_SOURCE_DATA_INCOMPLETE；

如果图像源数据错误，返回IMAGE_RESULT_SOURCE_DATA；

如果图像获取数据错误，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果图像数据太大，返回IMAGE_RESULT_TOO_LARGE；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果图像解码 EXIF 不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图像属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST；

如果文件损坏，返回IMAGE_RESULT_FILE_DAMAGED；

如果文件 FD 错误，返回IMAGE_RESULT_FILE_FD_ERROR；

如果数据流错误，返回IMAGE_RESULT_STREAM_SIZE_ERROR；

如果查找文件失败，返回IMAGE_RESULT_SEEK_FAILED；

如果速览文件失败，返回IMAGE_RESULT_PEEK_FAILED；

如果读取文件失败，返回IMAGE_RESULT_FREAD_FAILED。

**参见：**

[OhosImageSource](_ohos_image_source.md), [OhosImageSourceOps](_ohos_image_source_ops.md), [OH_ImageSource_UpdateData](#oh_imagesource_updatedata)


### OH_ImageSource_CreateIncrementalFromData()

```
int32_t OH_ImageSource_CreateIncrementalFromData (napi_env env, uint8_t * data, size_t dataSize, struct OhosImageSourceOps * ops, napi_value * res )
```
**描述**
通过给定的图像源缓冲区资源 data 和 [OhosImageSourceOps](_ohos_image_source_ops.md)结构体， 获取增量类型的JavaScript Native API ImageSource对象，图像数据应通过OH_ImageSource_UpdateData更新。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| data | 表明图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区。  | 
| dataSize | 表明图像源缓冲区资源大小。  | 
| ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](_ohos_image_source_ops.md)。  | 
| res | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER。

**参见：**

[OhosImageSourceOps](_ohos_image_source_ops.md)


### OH_ImageSource_CreatePixelMap()

```
int32_t OH_ImageSource_CreatePixelMap (const ImageSourceNative * native, struct OhosImageDecodingOps * ops, napi_value * res )
```
**描述**
通过一个给定的选项[OhosImageDecodingOps](_ohos_image_decoding_ops.md)结构体，从**ImageSource**中解码JavaScript native层**PixelMap**对象

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层[ImageSourceNative](#imagesourcenative)值的指针。  | 
| ops | 表明为了解码图像源的选项，查看[OhosImageDecodingOps](_ohos_image_decoding_ops.md)。  | 
| res | 表明JavaScript native层**PixelMap**对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果创建编码器失败，返回IMAGE_RESULT_CREATE_ENCODER_FAILED；

如果检查格式不对，返回IMAGE_RESULT_CHECK_FORMAT_ERROR；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果共享内存错误，返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST；

如果共享内存数据异常，返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL；

如果图片解码异常，返回IMAGE_RESULT_DECODE_ABNORMAL；

如果图像内存分配异常，返回IMAGE_RESULT_MALLOC_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图像初始化失败，返回IMAGE_RESULT_INIT_ABNORMAL；

如果裁剪错误，返回IMAGE_RESULT_CROP；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果图像编码失败，返回IMAGE_RESULT_ENCODE_FAILED；

如果不支持图片硬解码，返回IMAGE_RESULT_HW_DECODE_UNSUPPORT；

如果硬解码失败，返回IMAGE_RESULT_HW_DECODE_FAILED；

如果ipc失败，返回IMAGE_RESULT_ERR_IPC；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果透明度类型错误，返回IMAGE_RESULT_ALPHA_TYPE_ERROR；

如果内存分配类型错误，返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。

**参见：**

[ImageSourceNative](#imagesourcenative), [OhosImageDecodingOps](_ohos_image_decoding_ops.md)


### OH_ImageSource_CreatePixelMapList()

```
int32_t OH_ImageSource_CreatePixelMapList (const ImageSourceNative * native, struct OhosImageDecodingOps * ops, napi_value * res )
```
**描述**
通过一个给定的选项[OhosImageDecodingOps](_ohos_image_decoding_ops.md)结构体，从**ImageSource**中解码所有的JavaScript native层**PixelMap**对象列表。


**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针。  | 
| ops | 表明为了解码图像源的选项，查看[OhosImageDecodingOps](_ohos_image_decoding_ops.md)。  | 
| res | 表明JavaScript native层**PixelMap** 列表对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果创建编码器失败，返回IMAGE_RESULT_CREATE_ENCODER_FAILED；

如果检查格式不对，返回IMAGE_RESULT_CHECK_FORMAT_ERROR；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果共享内存错误，返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST；

如果共享内存数据异常，返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL；

如果图片解码异常，返回IMAGE_RESULT_DECODE_ABNORMAL；

如果图像内存分配异常，返回IMAGE_RESULT_MALLOC_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图像初始化失败，返回IMAGE_RESULT_INIT_ABNORMAL；

如果裁剪错误，返回IMAGE_RESULT_CROP；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果图像编码失败，返回IMAGE_RESULT_ENCODE_FAILED；

如果不支持图片硬解码，返回IMAGE_RESULT_HW_DECODE_UNSUPPORT；

如果硬解码失败，返回IMAGE_RESULT_HW_DECODE_FAILED；

如果ipc失败，返回IMAGE_RESULT_ERR_IPC；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果透明度类型错误，返回IMAGE_RESULT_ALPHA_TYPE_ERROR；

如果内存分配类型错误，返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR；

如果解码的EXIF不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图片属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST。

**参见：**

[ImageSourceNative](#imagesourcenative), [OhosImageDecodingOps](_ohos_image_decoding_ops.md)


### OH_ImageSource_GetDelayTime()

```
int32_t OH_ImageSource_GetDelayTime (const ImageSourceNative * native, struct OhosImageSourceDelayTimeList * res )
```
**描述**
从**ImageSource**（如GIF图像源）获取延迟时间列表。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针。  | 
| res | 表明延迟时间列表 [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) 的指针。 当输入的res中**delayTimeList**是空指针并且**size**是0时，将通过res的**size**中返回延迟时间列表大小 为了获取延迟时间，需要比返回的**delayTimeList**大小值大的足够空间  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果图片解码异常， IMAGE_RESULT_DECODE_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果解码的EXIF不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图片属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST。

**参见：**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md)


### OH_ImageSource_GetFrameCount()

```
int32_t OH_ImageSource_GetFrameCount (const ImageSourceNative * native, uint32_t * res )
```
**描述**
从**ImageSource**中获取帧计数。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针。  | 
| res | 表明帧计数的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果图片解码异常，返回IMAGE_RESULT_DECODE_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果解码的EXIF不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图片属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST。

**参见：**

[ImageSourceNative](#imagesourcenative)


### OH_ImageSource_GetImageInfo()

```
int32_t OH_ImageSource_GetImageInfo (const ImageSourceNative * native, int32_t index, struct OhosImageSourceInfo * info )
```
**描述**
通过索引从**ImageSource**获取图像源信息。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针。  | 
| index | 表明帧计数的指针。  | 
| info | 表明图像源信息[OhosImageSourceInfo](_ohos_image_source_info.md)的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果图片解码异常，返回IMAGE_RESULT_DECODE_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果解码的EXIF不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图片属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST。


**参见：**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceInfo](_ohos_image_source_info.md)


### OH_ImageSource_GetImageProperty()

```
int32_t OH_ImageSource_GetImageProperty (const ImageSourceNative * native, struct OhosImageSourceProperty * key, struct OhosImageSourceProperty * value )
```
**描述**
通过关键字从**ImageSource**中获取图像源属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针。  | 
| key | 表明属性关键字[OhosImageSourceProperty](_ohos_image_source_property.md)的指针。  | 
| value | 表明作为结果的属性值[OhosImageSourceProperty](_ohos_image_source_property.md)的指针。 当输入的value中**value**是空指针并且**size**是0时，将通过value中的**size**返回属性值的大小。 为了获取属性值，需要比**value**中的结果大小大的足够的空间。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果图片解码异常， 返回IMAGE_RESULT_DECODE_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果解码的EXIF不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图片属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST。

**参见：**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceProperty](_ohos_image_source_property.md)


### OH_ImageSource_GetSupportedFormats()

```
int32_t OH_ImageSource_GetSupportedFormats (struct OhosImageSourceSupportedFormatList * res)
```
**描述**
获取所有支持的解码格式元标记。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| res | 表明指向[OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md)结构的列表指针。 当**supportedFormatList**为nullptr并且**size**以res为0作为输入时，它将以res**size**返回支持的格式大小。<br/>为了获得所有的格式标记，它需要比**supportedFormatList**中的结果大小大的足够空间， 还需要为[OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md)项目中的每个格式提供足够的空间。 | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，IMAGE_RESULT_INVALID_PARAMETER；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果检查格式不对，返回IMAGE_RESULT_CHECK_FORMAT_ERROR。

**参见：**

[OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md), [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md)


### OH_ImageSource_InitNative()

```
ImageSourceNative* OH_ImageSource_InitNative (napi_env env, napi_value source )
```
**描述**
从输入JavaScript native层**ImageSource**对象中，转换成[ImageSourceNative](#imagesourcenative)值。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | 表明JNI环境的指针。  | 
| source | 表明JavaScript native层**ImageSource**对象的指针。  | 

**返回：**

如果操作成功返回[ImageSourceNative](#imagesourcenative)指针；如果操作失败，返回空指针。

**参见：**

[ImageSourceNative](#imagesourcenative), [OH_ImageSource_Release](#oh_imagesource_release)


### OH_ImageSource_ModifyImageProperty()

```
int32_t OH_ImageSource_ModifyImageProperty (const ImageSourceNative * native, struct OhosImageSourceProperty * key, struct OhosImageSourceProperty * value )
```
**描述**
通过关键字为**ImageSource**修改图像源属性。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针  | 
| key | 表明属性关键字[OhosImageSourceProperty](_ohos_image_source_property.md)的指针。  | 
| value | 为了修改表明属性值[OhosImageSourceProperty](_ohos_image_source_property.md)的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果图片解码异常， IMAGE_RESULT_DECODE_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果解码的EXIF不支持，返回IMAGE_RESULT_DECODE_EXIF_UNSUPPORT；

如果图片属性不存在，返回IMAGE_RESULT_PROPERTY_NOT_EXIST。

**参见：**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceProperty](_ohos_image_source_property.md)


### OH_ImageSource_Release()

```
int32_t OH_ImageSource_Release (ImageSourceNative * native)
```
**描述**
释放native层图像源 **ImageSourceNative**。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL。

**参见：**

[ImageSourceNative](#imagesourcenative), [OH_ImageSource_Create](#oh_imagesource_create), [OH_ImageSource_CreateIncremental](#oh_imagesource_createincremental)


### OH_ImageSource_UpdateData()

```
int32_t OH_ImageSource_UpdateData (const ImageSourceNative * native, struct OhosImageSourceUpdateData * data )
```
**描述**
为了增量类型的**ImageSource**更新源数据。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | 表明native层 [ImageSourceNative](#imagesourcenative) 值的指针。  | 
| data | 表明更新数据信息[OhosImageSourceUpdateData](_ohos_image_source_update_data.md)的指针。  | 

**返回：**


如果操作成功返回OHOS_IMAGE_RESULT_SUCCESS；

如果参数错误，返回IMAGE_RESULT_BAD_PARAMETER；

如果 JNI 环境异常，返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效，返回IMAGE_RESULT_INVALID_PARAMETER；

如果获取图片数据异常，返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败，返回IMAGE_RESULT_DECODE_FAILED；

如果图像解码头错误，返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL；

如果创建解码器失败，返回IMAGE_RESULT_CREATE_DECODER_FAILED；

如果创建编码器失败，返回IMAGE_RESULT_CREATE_ENCODER_FAILED；

如果检查格式不对，返回IMAGE_RESULT_CHECK_FORMAT_ERROR；

如果skia错误，返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果输入图片数据错误，返回IMAGE_RESULT_DATA_ABNORMAL；

如果共享内存错误，返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST；

如果共享内存数据异常，返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL；

如果图片解码异常，返回IMAGE_RESULT_DECODE_ABNORMAL；

如果图像内存分配异常，返回IMAGE_RESULT_MALLOC_ABNORMAL；

如果图像类型不支持，返回IMAGE_RESULT_DATA_UNSUPPORT；

如果图像初始化失败，返回IMAGE_RESULT_INIT_ABNORMAL；

如果裁剪错误，返回IMAGE_RESULT_CROP；

如果图片格式未知，返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败，返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败，返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果图像编码失败，返回IMAGE_RESULT_ENCODE_FAILED；

如果不支持图片硬解码，返回IMAGE_RESULT_HW_DECODE_UNSUPPORT；

如果硬解码失败，返回IMAGE_RESULT_HW_DECODE_FAILED；

如果ipc失败，返回IMAGE_RESULT_ERR_IPC；

如果索引无效，返回IMAGE_RESULT_INDEX_INVALID；

如果透明度类型错误，返回IMAGE_RESULT_ALPHA_TYPE_ERROR；

如果内存分配类型错误，返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。


**参见：**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceUpdateData](_ohos_image_source_update_data.md)


### OH_PixelMap_AccessPixels()

```
int32_t OH_PixelMap_AccessPixels (const NativePixelMap * native, void ** addr )
```
**描述**
获取native **PixelMap** 对象数据的内存地址，并锁定该内存。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| addr | 用于指向的内存地址的双指针对象。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED；

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR；

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST；

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL；

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL；

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果裁剪失败则返回IMAGE_RESULT_CROP；

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID；

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR；

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。



### OH_PixelMap_CreateAlphaPixelMap()

```
int32_t OH_PixelMap_CreateAlphaPixelMap (napi_env env, napi_value source, napi_value * alpha )
```
**描述**
根据Alpha通道的信息，来生成一个仅包含Alpha通道信息的**PixelMap**对象。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| source | 应用层的 **PixelMap** 对象。  | 
| alpha | alpha通道的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS;

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED;

如果图像头解码失败则返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL;

如果创建解码器失败则返回IMAGE_RESULT_CREATE_DECODER_FAILED;

如果创建编码器失败则返回IMAGE_RESULT_CREATE_ENCODER_FAILED;

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST;

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;

如果图像解码失败则返回IMAGE_RESULT_DECODE_ABNORMAL;

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;

如果图像初始化失败则返回IMAGE_RESULT_INIT_ABNORMAL;

如果裁剪失败则返回IMAGE_RESULT_CROP;

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT;

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED;

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED;

如果图像编码失败则返回IMAGE_RESULT_ENCODE_FAILED;

如果图像不支持硬件解码则返回IMAGE_RESULT_HW_DECODE_UNSUPPORT;

如果硬件解码失败则返回IMAGE_RESULT_HW_DECODE_FAILED;

如果ipc失败则返回IMAGE_RESULT_ERR_IPC;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR;

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。


### OH_PixelMap_CreatePixelMap()

```
int32_t OH_PixelMap_CreatePixelMap (napi_env env, OhosPixelMapCreateOps info, void * buf, size_t len, napi_value * res )
```
**描述**
创建**PixelMap**对象。当前只支持输入流为BGRA格式的流。该接口传入的buf不支持stride。该接口不支持DMA内存。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| info |PixelMap数据设置项。  | 
| buf | 图片的buffer数据。  | 
| len | 图片大小信息。  | 
| res | 应用层的 **PixelMap** 对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS;

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED;

如果图像头解码失败则返回IMAGE_RESULT_DECODE_HEAD_ABNORMAL;

如果创建解码器失败则返回IMAGE_RESULT_CREATE_DECODER_FAILED;

如果创建编码器失败则返回IMAGE_RESULT_CREATE_ENCODER_FAILED;

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST;

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;

如果图像解码失败则返回IMAGE_RESULT_DECODE_ABNORMAL;

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;

如果图像初始化失败则返回IMAGE_RESULT_INIT_ABNORMAL;

如果裁剪失败则返回IMAGE_RESULT_CROP;

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT;

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED;

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED;

如果图像编码失败则返回IMAGE_RESULT_ENCODE_FAILED;

如果图像不支持硬件解码则返回IMAGE_RESULT_HW_DECODE_UNSUPPORT;

如果硬件解码失败则返回IMAGE_RESULT_HW_DECODE_FAILED;

如果ipc失败则返回IMAGE_RESULT_ERR_IPC;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR;

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。



### OH_PixelMap_CreatePixelMapWithStride()

```
int32_t OH_PixelMap_CreatePixelMapWithStride (napi_env env, OhosPixelMapCreateOps info, void * buf, size_t len, int32_t rowStride, napi_value * res )
```
**描述**
创建**PixelMap**对象。当前只支持输入流为BGRA格式的流。pixelmap内存在RGBA格式下，默认为DMA内存（图片512\*512以上）。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| info | PixelMap数据设置项。  | 
| buf | 图片的buffer数据。  | 
| len | 图片buffer大小信息。  | 
| rowStride | 图片跨距信息。 跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。  | 
| res | 应用层的 PixelMap 对象的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS; 

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER; 

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL; 

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL; 

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR; 

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL; 

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL; 

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT; 

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT。



### OH_PixelMap_Crop()

```
int32_t OH_PixelMap_Crop (const NativePixelMap * native, int32_t x, int32_t y, int32_t width, int32_t height )
```
**描述**
设置**PixelMap**对象的裁剪。

> **说明：**
> 从API version 12开始，推荐使用新接口[OH_PixelmapNative_Crop](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_crop)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| x | 目标图片左上角的x坐标。  | 
| y | 目标图片左上角的y坐标。  | 
| width | 裁剪区域的宽度。  | 
| height | 裁剪区域的高度。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS;

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED;

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST;

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;

如果裁剪失败则返回IMAGE_RESULT_CROP;

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT;

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED;

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR;

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。



### OH_PixelMap_Flip()

```
int32_t OH_PixelMap_Flip (const NativePixelMap * native, int32_t x, int32_t y )
```
**描述**
设置**PixelMap**对象的翻转。

> **说明：**
> 从API version 12开始，推荐使用新接口[OH_PixelmapNative_Flip](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_flip)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| x | 根据水平方向x轴进行图片翻转。  | 
| y | 根据垂直方向y轴进行图片翻转。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS;

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED;

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST;

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;

如果裁剪失败则返回IMAGE_RESULT_CROP;

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT;

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED;

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR;

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。



### OH_PixelMap_GetBytesNumberPerRow()

```
int32_t OH_PixelMap_GetBytesNumberPerRow (const NativePixelMap * native, int32_t * num )
```
**描述**
获取**PixelMap**对象每行字节数。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| num | **PixelMap**对象的每行字节数指针。  | 

**返回:**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID。



### OH_PixelMap_GetDensity()

```
int32_t OH_PixelMap_GetDensity (const NativePixelMap * native, int32_t * density )
```
**描述**
获取**PixelMap**对象像素密度。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| density | 像素密度指针。  | 

**返回:**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID。



### OH_PixelMap_GetImageInfo()

```
int32_t OH_PixelMap_GetImageInfo (const NativePixelMap * native, OhosPixelMapInfos * info )
```
**描述**
获取**PixelMap**对象图像信息。

> 从API version 12开始，推荐使用新接口[OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_getimageinfo)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| info | 图像信息指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS;

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED;

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST;

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;

如果裁剪失败则返回IMAGE_RESULT_CROP;

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT;

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED;

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR;

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。

**参见：**

[OhosPixelMapInfos](_ohos_pixel_map_infos.md)


### OH_PixelMap_GetIsEditable()

```
int32_t OH_PixelMap_GetIsEditable (const NativePixelMap * native, int32_t * editable )
```
**描述**
获取**PixelMap**对象是否可编辑的状态。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| editable | **PixelMap** 对象是否可编辑的指针。  | 

**返回:**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID。



### OH_PixelMap_InitNativePixelMap()

```
NativePixelMap* OH_PixelMap_InitNativePixelMap (napi_env env, napi_value source )
```
**描述**
初始化**NativePixelMap**对象。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| source | 应用层的 **PixelMap** 对象。  |

**返回：**

操作成功则返回NativePixelMap的指针；如果操作失败，则返回错误码。


### OH_PixelMap_IsSupportAlpha()

```
int32_t OH_PixelMap_IsSupportAlpha (const NativePixelMap * native, int32_t * alpha )
```
**描述**
获取**PixelMap**对象是否支持Alpha通道。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| alpha | 是否支持Alpha的指针。  | 

**返回:**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID。



### OH_PixelMap_Rotate()

```
int32_t OH_PixelMap_Rotate (const NativePixelMap * native, float angle )
```
**描述**
设置**PixelMap**对象的旋转。

> **说明：**
> 从API version 12开始，推荐使用新接口[OH_PixelmapNative_Rotate](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_rotate)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| angle | 旋转角度。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS;

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED;

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST;

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;

如果裁剪失败则返回IMAGE_RESULT_CROP;

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT;

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED;

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR;

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。



### OH_PixelMap_Scale()

```
int32_t OH_PixelMap_Scale (const NativePixelMap * native, float x, float y )
```
**描述**
设置**PixelMap**对象的缩放。

> **说明：**
> 从API version 12开始，推荐使用新接口[OH_PixelmapNative_Scale](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_scale)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| x | 宽度的缩放比例。  | 
| y | 高度的缩放比例。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS;

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER;

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL;

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER;

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL;

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED;

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR;

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR;

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL;

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST;

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL;

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL;

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT;

如果图像初始化失败则返回IMAGE_RESULT_INIT_ABNORMAL;

如果裁剪失败则返回IMAGE_RESULT_CROP;

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT;

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED;

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED;

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR;

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。



### OH_PixelMap_ScaleWithAntiAliasing()

```
int32_t OH_PixelMap_ScaleWithAntiAliasing (const NativePixelMap * native, float x, float y, OH_PixelMap_AntiAliasingLevel level )
```
**描述**
根据指定的缩放算法和输入的宽高对图片进行缩放。

> **说明：**
> 从API version 12开始，推荐使用新接口[OH_PixelmapNative_ScaleWithAntiAliasing](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_scalewithantialiasing)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| x | 宽度的缩放比例。  | 
| y | 高度的缩放比例。  | 
| level | 缩放算法。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS; 

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL; 

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER; 

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL; 

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR; 

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR; 

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL; 

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL; 

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT。



### OH_PixelMap_SetAlphaAble()

```
int32_t OH_PixelMap_SetAlphaAble (const NativePixelMap * native, int32_t alpha )
```
**描述**
设置**PixelMap**对象的Alpha通道。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| alpha | Alpha通道。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID。



### OH_PixelMap_SetDensity()

```
int32_t OH_PixelMap_SetDensity (const NativePixelMap * native, int32_t density )
```
**描述**
设置**PixelMap**对象像素密度。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| density | 像素密度。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID。



### OH_PixelMap_SetOpacity()

```
int32_t OH_PixelMap_SetOpacity (const NativePixelMap * native, float opacity )
```
**描述**
设置**PixelMap**对象的透明度。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| opacity | 透明度。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID。


### OH_PixelMap_Translate()

```
int32_t OH_PixelMap_Translate (const NativePixelMap * native, float x, float y )
```
**描述**
设置**PixelMap**对象的偏移。

> **说明：**
> 从API version 12开始，推荐使用新接口[OH_PixelmapNative_Translate](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_translate)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 
| x | 水平偏移量。  | 
| y | 垂直偏移量。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED；

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR；

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST；

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL；

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL；

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果裁剪失败则返回IMAGE_RESULT_CROP；

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID;

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR；

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。



### OH_PixelMap_UnAccessPixels()

```
int32_t OH_PixelMap_UnAccessPixels (const NativePixelMap * native)
```
**描述**
释放native **PixelMap**对象数据的内存锁，用于匹配方法[OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels)。

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| native | NativePixelMap的指针。  | 

**返回：**

参考[IRNdkErrCode](#irndkerrcode-1)。

如果操作成功则返回IMAGE_RESULT_SUCCESS；

如果参数错误则返回IMAGE_RESULT_BAD_PARAMETER；

如果JNI环境异常则返回IMAGE_RESULT_JNI_ENV_ABNORMAL；

如果参数无效则返回IMAGE_RESULT_INVALID_PARAMETER；

如果图像获取数据失败则返回IMAGE_RESULT_GET_DATA_ABNORMAL；

如果解码失败则返回IMAGE_RESULT_DECODE_FAILED；

如果检查格式失败则返回IMAGE_RESULT_CHECK_FORMAT_ERROR；

如果skia能力失败则返回IMAGE_RESULT_THIRDPART_SKIA_ERROR；

如果图像输入数据失败则返回IMAGE_RESULT_DATA_ABNORMAL；

如果共享内存失败则返回IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST；

如果共享内存数据错误则返回IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL；

如果图像分配内存失败则返回IMAGE_RESULT_MALLOC_ABNORMAL；

如果属性无效或图像数据不支持则返回IMAGE_RESULT_DATA_UNSUPPORT；

如果裁剪失败则返回IMAGE_RESULT_CROP；

如果图像格式未知则返回IMAGE_RESULT_UNKNOWN_FORMAT；

如果注册插件失败则返回IMAGE_RESULT_PLUGIN_REGISTER_FAILED；

如果创建插件失败则返回IMAGE_RESULT_PLUGIN_CREATE_FAILED；

如果参数无效则返回IMAGE_RESULT_INDEX_INVALID；

如果透明度类型错误则返回IMAGE_RESULT_ALPHA_TYPE_ERROR；

如果内存分配类型错误则返回IMAGE_RESULT_ALLOCATER_TYPE_ERROR。




### OH_UnAccessPixels()

```
int32_t OH_UnAccessPixels (napi_env env, napi_value value )
```
**描述**
释放**PixelMap**对象数据的内存锁, 用于匹配方法**OH_AccessPixels**。

**废弃版本：** 10

**起始版本：** 8

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| value | 应用层的 **PixelMap** 对象。  | 

**返回：**

操作成功则返回 **OHOS_IMAGE_RESULT_SUCCESS**；如果操作失败，则返回错误码。



## 变量说明


### alphaType

```
int32_t OhosImageSourceInfo::alphaType
```
**描述**
图像源透明度类型


### buffer [1/2]

```
uint8_t* OhosImageSource::buffer = nullptr
```
**描述**
图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区

**起始版本：** 10

### buffer [2/2]

```
uint8_t* OhosImageSourceUpdateData::buffer = nullptr
```
**描述**
图像源更新数据缓冲区

**起始版本：** 10


### bufferSize [1/2]

```
size_t OhosImageSource::bufferSize = 0
```
**描述**
图像源缓冲区资源大小


### bufferSize [2/2]

```
size_t OhosImageSourceUpdateData::bufferSize = 0
```
**描述**
图像源更新数据缓冲区大小

**起始版本：** 10


### colorSpace

```
int32_t OhosImageSourceInfo::colorSpace
```
**描述**
图像源色彩空间

**起始版本：** 10


### delayTimeList

```
int32_t* OhosImageSourceDelayTimeList::delayTimeList
```
**描述**
图像源延迟时间列表头地址

**起始版本：** 10


### density [1/2]

```
int32_t OhosImageSourceOps::density
```
**描述**
图像源像素密度

**起始版本：** 10


### density [2/2]

```
int32_t OhosImageSourceInfo::density
```
**描述**
图像源密度, 由 [OH_ImageSource_Create](#oh_imagesource_create) 设置

**起始版本：** 10


### editable

```
int8_t OhosImageDecodingOps::editable
```
**描述**
定义输出的像素位图是否可编辑

**起始版本：** 10


### fd

```
int32_t OhosImageSource::fd = -1
```
**描述**
图像源文件资源描述符

**起始版本：** 10


### fitDensity

```
int32_t OhosImageDecodingOps::fitDensity
```
**描述**
定义解码目标的像素密度

**起始版本：** 10


### format

```
char* OhosImageSourceSupportedFormat::format = nullptr
```
**描述**
图像源支持的格式字符串头地址

**起始版本：** 10


### height

```
int32_t OhosImageRegion::height
```
**描述**
高度范围，用pixels表示

**起始版本：** 10

### index

```
uint32_t OhosImageDecodingOps::index
```
**描述**
定义图像源解码指数

**起始版本：** 10


### isCompleted

```
int8_t OhosImageSourceUpdateData::isCompleted = 0
```
**描述**
图像源更新数据在此节中完成

**起始版本：** 10


### offset

```
uint32_t OhosImageSourceUpdateData::offset = 0
```
**描述**
图像源更新数据缓冲区的开端

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE

```
const char* OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample"
```
**描述**
定义每个样本比特的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL

```
const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel"
```
**描述**
定义每个像素的压缩比特的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL

```
const char* OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal"
```
**描述**
定义初始日期时间的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_EXPOSURE_TIME

```
const char* OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime"
```
**描述**
定义曝光时间的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。
**起始版本：** 10


### OHOS_IMAGE_PROPERTY_F_NUMBER

```
const char* OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber"
```
**描述**
定义FNumber的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE

```
const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude"
```
**描述**
定义GPS纬度的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF

```
const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef"
```
**描述**
定义GPS纬度参考的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE

```
const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude"
```
**描述**
定义GPS经度的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF

```
const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef"
```
**描述**
定义GPS经度参考的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。


**起始版本：** 10


### OHOS_IMAGE_PROPERTY_IMAGE_LENGTH

```
const char* OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength"
```
**描述**
定义图像长度的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_IMAGE_WIDTH

```
const char* OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth"
```
**描述**
定义图像宽度的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。


**起始版本：** 10


### OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS

```
const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings"
```
**描述**
定义ISO速度等级的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_ORIENTATION

```
const char* OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation"
```
**描述**
定义方向的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### OHOS_IMAGE_PROPERTY_SCENE_TYPE

```
const char* OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType"
```
**描述**
定义场景类型的图像属性关键字。 此标签给[OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty)和[OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty)这两个接口使用。

**起始版本：** 10


### pixelFormat [1/3]

```
int32_t OhosImageSourceOps::pixelFormat
```
**描述**
图像源像素格式，通常用于描述YUV缓冲区

**起始版本：** 10


### pixelFormat [2/3]

```
int32_t OhosImageDecodingOps::pixelFormat
```
**描述**
定义输出的像素格式

**起始版本：** 10


### pixelFormat [3/3]

```
int32_t OhosImageSourceInfo::pixelFormat
```
**描述**
图像源像素格式, 由 [OH_ImageSource_Create](#oh_imagesource_create) 设置

**起始版本：** 10


### region

```
struct OhosImageRegion OhosImageDecodingOps::region
```
**描述**
定义图像源解码的像素范围

**起始版本：** 10


### rotate

```
uint32_t OhosImageDecodingOps::rotate
```
**描述**
定义解码旋转选项

**起始版本：** 10


### sampleSize

```
uint32_t OhosImageDecodingOps::sampleSize
```
**描述**
定义解码样本大小选项

**起始版本：** 10


### size [1/7]

```
struct OhosImageSize OhosImageSourceOps::size
```
**描述**
图像源像素宽高的大小

**起始版本：** 10


### size [2/7]

```
struct OhosImageSize OhosImageDecodingOps::size
```
**描述**
定义解码目标像素宽高的大小

**起始版本：** 10


### size [3/7]

```
struct OhosImageSize OhosImageSourceInfo::size
```
**描述**
图像源像素宽高的大小

**起始版本：** 10


### size [4/7]

```
size_t OhosImageSourceDelayTimeList::size = 0
```
**描述**
图像源延迟时间列表大小

**起始版本：** 10


### size [5/7]

```
size_t OhosImageSourceSupportedFormat::size = 0
```
**描述**
图像源支持的格式字符串大小

**起始版本：** 10


### size [6/7]

```
size_t OhosImageSourceSupportedFormatList::size = 0
```
**描述**
图像源支持的格式字符串列表大小

**起始版本：** 10


### size [7/7]

```
size_t OhosImageSourceProperty::size = 0
```
**描述**
定义图像源属性键值字符串大小

**起始版本：** 10


### supportedFormatList

```
struct OhosImageSourceSupportedFormat** OhosImageSourceSupportedFormatList::supportedFormatList = nullptr
```
**描述**
图像源支持的格式字符串列表头地址

**起始版本：** 10


### updateLength

```
uint32_t OhosImageSourceUpdateData::updateLength = 0
```
**描述**
图像源更新数据缓冲区的更新数据长度

**起始版本：** 10


### uri

```
char* OhosImageSource::uri = nullptr
```
**描述**
图像源资源标识符，接受文件资源或者base64资源

**起始版本：** 10


### uriSize

```
size_t OhosImageSource::uriSize = 0
```
**描述**
图像源资源长度

**起始版本：** 10


### value

```
char* OhosImageSourceProperty::value = nullptr
```
**描述**
定义图像源属性键值字符串头地址

**起始版本：** 10


### width

```
int32_t OhosImageRegion::width
```
**描述**
宽度范围，用pixels表示

**起始版本：** 10


### x

```
int32_t OhosImageRegion::x
```
**描述**
起始x坐标，用pixels表示

**起始版本：** 10


### y

```
int32_t OhosImageRegion::y
```
**描述**
起始y坐标，用pixels表示

**起始版本：** 10


