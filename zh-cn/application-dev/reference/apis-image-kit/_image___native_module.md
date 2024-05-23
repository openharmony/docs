# Image_NativeModule


## 概述

提供图片处理的相关能力，包括图片编解码、从Native层获取图片数据等。

使用该模块的接口，无需通过JS接口导入，可直接使用NDK完成功能开发。

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [image_common.h](image__common_8h.md) | 声明图像接口使用的公共枚举和结构体。 | 
| [image_native.h](image__native_8h.md) | 声明图像的剪辑矩形、大小和组件数据的接口函数。 | 
| [image_packer_native.h](image__packer__native_8h.md) | 图片编码API。 | 
| [image_receiver_native.h](image__receiver__native_8h.md) | 声明从Native层获取图片数据的方法。 | 
| [image_source_native.h](image__source__native_8h.md) | 图片解码API。 | 
| [pixelmap_native.h](pixelmap__native_8h.md) | 访问Pixelmap的API。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Image_Size](_image___size.md) | 图像大小结构体。 | 
| struct  [Image_Region](_image___region.md) | 待解码的图像源区域结构体。 | 
| struct  [Image_String](_image___string.md) | 字符串结构。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Image_Size](_image___size.md) [Image_Size](#image_size) | 声明图像大小结构。 | 
| typedef struct [Image_Region](_image___region.md) [Image_Region](#image_region) | 声明要解码的图像源区域结构体类型名称。 | 
| typedef struct [Image_String](_image___string.md) [Image_String](#image_string) | 声明字符串结构的名称。 | 
| typedef struct [Image_String](_image___string.md) [Image_MimeType](#image_mimetype) | 声明一个图片格式类型的名称。 | 
| typedef struct [OH_ImageNative](#oh_imagenative) [OH_ImageNative](#oh_imagenative) | 为图像接口定义native层图像对象的别名。 | 
| typedef struct [OH_ImagePackerNative](#oh_imagepackernative) [OH_ImagePackerNative](#oh_imagepackernative) | ImagePacker结构体类型，用于执行ImagePacker相关操作。 | 
| typedef struct [OH_PackingOptions](#oh_packingoptions) [OH_PackingOptions](#oh_packingoptions) | 图像编码选项。 | 
| typedef struct [OH_ImageReceiverNative](#oh_imagereceivernative) [OH_ImageReceiverNative](#oh_imagereceivernative) | 用于定义OH_ImageReceiverNative数据类型名称。 | 
| typedef struct [OH_ImageReceiverOptions](#oh_imagereceiveroptions) [OH_ImageReceiverOptions](#oh_imagereceiveroptions) | 用于定义OH_ImageReceiverOptions数据类型名称。 | 
| typedef void(\*[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | 定义native层图片的回调方法。 | 
| typedef struct [OH_ImageSourceNative](#oh_imagesourcenative) [OH_ImageSourceNative](#oh_imagesourcenative) | ImageSource结构体类型，用于执行ImageSource相关操作。 | 
| typedef struct [OH_ImageSource_Info](#oh_imagesource_info) [OH_ImageSource_Info](#oh_imagesource_info) | 图片源信息结构体 [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create). | 
| typedef struct [OH_DecodingOptions](#oh_decodingoptions) [OH_DecodingOptions](#oh_decodingoptions) | 编码选项参数结构体,被用于[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)。 | 
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | Pixelmap结构体类型，用于执行Pixelmap相关操作。 | 
| typedef struct [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) | 初始化参数结构体。 | 
| typedef struct [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) | 图像像素信息结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](#image_errorcode) {<br/>IMAGE_SUCCESS = 0,<br/>IMAGE_BAD_PARAMETER = 401,<br/>IMAGE_UNSUPPORTED_MIME_TYPE = 7600101,<br/>IMAGE_UNKNOWN_MIME_TYPE = 7600102,<br/>IMAGE_TOO_LARGE = 7600103,<br/>IMAGE_UNSUPPORTED_OPERATION = 7600201,<br/>IMAGE_UNSUPPORTED_METADATA = 7600202,<br/>IMAGE_UNSUPPORTED_CONVERSION = 7600203,<br/>IMAGE_INVALID_REGION = 7600204,<br/>IMAGE_ALLOC_FAILED = 7600301,<br/>IMAGE_COPY_FAILED = 7600302,<br/>IMAGE_UNKNOWN_ERROR = 7600901,<br/>IMAGE_BAD_SOURCE = 7700101,<br/>IMAGE_DECODE_FAILED = 7700301,<br/>IMAGE_ENCODE_FAILED = 7800301<br/>} | 错误码。 | 
| [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range) {<br/>IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0,<br/>IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1 } | 编码指定动态范围。 | 
| [IMAGE_DYNAMIC_RANGE](#image_dynamic_range) {<br/>IMAGE_DYNAMIC_RANGE_AUTO = 0,<br/>IMAGE_DYNAMIC_RANGE_SDR = 1,<br/>IMAGE_DYNAMIC_RANGE_HDR = 2 } | 解码指定期望动态范围。 | 
| [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type) {<br/>PIXELMAP_ALPHA_TYPE_UNKNOWN = 0,<br/>PIXELMAP_ALPHA_TYPE_OPAQUE = 1,<br/>PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2 } | Pixelmap透明度类型。 | 
| [PIXEL_FORMAT](#pixel_format) {<br/>PIXEL_FORMAT_UNKNOWN = 0, PIXEL_FORMAT_RGB_565 = 2,<br/>PIXEL_FORMAT_RGBA_8888 = 3, PIXEL_FORMAT_BGRA_8888 = 4,<br/>PIXEL_FORMAT_RGB_888 = 5, PIXEL_FORMAT_ALPHA_8 = 6,<br/>PIXEL_FORMAT_RGBA_F16 = 7, PIXEL_FORMAT_NV21 = 8,<br/>PIXEL_FORMAT_NV12 = 9<br/>} | 图片像素格式。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetImageSize](#oh_imagenative_getimagesize) ([OH_ImageNative](#oh_imagenative) \*image, [Image_Size](_image___size.md) \*size) | 获取Native [OH_ImageNative](#oh_imagenative) 对象的 [Image_Size](_image___size.md) 信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetComponentTypes](#oh_imagenative_getcomponenttypes) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t \*\*types, size_t \*typeSize) | 获取Native [OH_ImageNative](#oh_imagenative) 对象的组件列表信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetByteBuffer](#oh_imagenative_getbytebuffer) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, OH_NativeBuffer \*\*nativeBuffer) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的缓冲区。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetBufferSize](#oh_imagenative_getbuffersize) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, size_t \*size) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的缓冲区的大小。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetRowStride](#oh_imagenative_getrowstride) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, int32_t \*rowStride) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的像素行宽。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetPixelStride](#oh_imagenative_getpixelstride) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, int32_t \*pixelStride) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的像素大小。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_Release](#oh_imagenative_release) ([OH_ImageNative](#oh_imagenative) \*image) | 释放Native [OH_ImageNative](#oh_imagenative) 对象。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_Create](#oh_packingoptions_create) ([OH_PackingOptions](#oh_packingoptions) \*\*options) | 创建PackingOptions结构体的指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetMimeType](#oh_packingoptions_getmimetype) ([OH_PackingOptions](#oh_packingoptions) \*options, [Image_MimeType](#image_mimetype) \*format) | 获取MIME类型。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetMimeType](#oh_packingoptions_setmimetype) ([OH_PackingOptions](#oh_packingoptions) \*options, [Image_MimeType](#image_mimetype) \*format) | 设置MIME类型。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetQuality](#oh_packingoptions_getquality) ([OH_PackingOptions](#oh_packingoptions) \*options, uint32_t \*quality) | 获取编码质量。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetQuality](#oh_packingoptions_setquality) ([OH_PackingOptions](#oh_packingoptions) \*options, uint32_t quality) | 设置编码质量。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetDesiredDynamicRange](#oh_packingoptions_getdesireddynamicrange) ([OH_PackingOptions](#oh_packingoptions) \*options, int32_t \*desiredDynamicRange) | 获取编码时期望的图片动态范围。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetDesiredDynamicRange](#oh_packingoptions_setdesireddynamicrange) ([OH_PackingOptions](#oh_packingoptions) \*options, int32_t desiredDynamicRange) | 设置编码时期望的图片动态范围。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_Release](#oh_packingoptions_release) ([OH_PackingOptions](#oh_packingoptions) \*options) | 释放OH_PackingOptions指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_Create](#oh_imagepackernative_create) ([OH_ImagePackerNative](#oh_imagepackernative) \*\*imagePacker) | 创建OH_ImagePackerNative指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromImageSource](#oh_imagepackernative_packtodatafromimagesource) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_ImageSourceNative](#oh_imagesourcenative) \*imageSource, uint8_t \*outData, size_t \*size) | 将ImageSource编码为指定格式的数据。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmap](#oh_imagepackernative_packtodatafrompixelmap) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*outData, size_t \*size) | 将Pixelmap编码为指定格式的数据。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromImageSource](#oh_imagepackernative_packtofilefromimagesource) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_ImageSourceNative](#oh_imagesourcenative) \*imageSource, int32_t fd) | 将一个ImageSource编码到文件中。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmap](#oh_imagepackernative_packtofilefrompixelmap) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, int32_t fd) | 将一个Pixelmap编码到文件中。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_Release](#oh_imagepackernative_release) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker) | 释放OH_ImagePackerNative指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_Create](#oh_imagereceiveroptions_create) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*\*options) | 创建应用层 OH_ImageReceiverOptions 对象。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_GetSize](#oh_imagereceiveroptions_getsize) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) \*size) | 获取 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_SetSize](#oh_imagereceiveroptions_setsize) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) size) | 设置 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_GetCapacity](#oh_imagereceiveroptions_getcapacity) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, int32_t \*capacity) | 获取 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的图片缓存容量的信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_SetCapacity](#oh_imagereceiveroptions_setcapacity) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, int32_t capacity) | 设置 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的图片缓存容量的信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_Release](#oh_imagereceiveroptions_release) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options) | 释放 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Create](#oh_imagereceivernative_create) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [OH_ImageReceiverNative](#oh_imagereceivernative) \*\*receiver) | 创建应用层 OH_ImageReceiverNative 对象。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetReceivingSurfaceId](#oh_imagereceivernative_getreceivingsurfaceid) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, uint64_t \*surfaceId) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取receiver的id。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_ReadLatestImage](#oh_imagereceivernative_readlatestimage) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageNative](#oh_imagenative) \*\*image) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取最新的一张图片。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_ReadNextImage](#oh_imagereceivernative_readnextimage) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageNative](#oh_imagenative) \*\*image) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取下一张图片。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_On](#oh_imagereceivernative_on) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback) | 注册一个[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调事件。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Off](#oh_imagereceivernative_off) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | 关闭[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调事件。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetSize](#oh_imagereceivernative_getsize) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [Image_Size](_image___size.md) \*size) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取ImageReceiver的大小。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetCapacity](#oh_imagereceivernative_getcapacity) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, int32_t \*capacity) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取ImageReceiver的容量。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Release](#oh_imagereceivernative_release) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | 释放native [OH_ImageReceiverNative](#oh_imagereceivernative) 对象。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create) ([OH_ImageSource_Info](#oh_imagesource_info) \*\*info) | 创建OH_ImageSource_Info指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetWidth](#oh_imagesourceinfo_getwidth) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, uint32_t \*width) | 获取图片的宽。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetHeight](#oh_imagesourceinfo_getheight) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, uint32_t \*height) | 获取图片的高。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetDynamicRange](#oh_imagesourceinfo_getdynamicrange) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, bool \*isHdr) | 获取图片是否为高动态范围的信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_Release](#oh_imagesourceinfo_release) ([OH_ImageSource_Info](#oh_imagesource_info) \*info) | 释放OH_ImageSource_Info指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_Create](#oh_decodingoptions_create) ([OH_DecodingOptions](#oh_decodingoptions) \*\*options) | 创建OH_DecodingOptions指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetPixelFormat](#oh_decodingoptions_getpixelformat) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t \*pixelFormat) | 获取pixel格式。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetPixelFormat](#oh_decodingoptions_setpixelformat) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t pixelFormat) | 设置pixel格式。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetIndex](#oh_decodingoptions_getindex) ([OH_DecodingOptions](#oh_decodingoptions) \*options, uint32_t \*index) | 获取解码图片序号。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetIndex](#oh_decodingoptions_setindex) ([OH_DecodingOptions](#oh_decodingoptions) \*options, uint32_t index) | 设置解码图片序号。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetRotate](#oh_decodingoptions_getrotate) ([OH_DecodingOptions](#oh_decodingoptions) \*options, float \*rotate) | 获取旋转角度。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetRotate](#oh_decodingoptions_setrotate) ([OH_DecodingOptions](#oh_decodingoptions) \*options, float rotate) | 设置旋转角度。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredSize](#oh_decodingoptions_getdesiredsize) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | 获取期望输出大小。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredSize](#oh_decodingoptions_setdesiredsize) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | 设置期望输出大小。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredRegion](#oh_decodingoptions_getdesiredregion) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | 设置解码区域。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredRegion](#oh_decodingoptions_setdesiredregion) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | 设置解码区域。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredDynamicRange](#oh_decodingoptions_getdesireddynamicrange) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t \*desiredDynamicRange) | 获取解码时设置的期望动态范围。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredDynamicRange](#oh_decodingoptions_setdesireddynamicrange) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t desiredDynamicRange) | 设置解码时的期望动态范围。 | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_Release](#oh_decodingoptions_release) ([OH_DecodingOptions](#oh_decodingoptions) \*options) | 释放OH_DecodingOptions指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromUri](#oh_imagesourcenative_createfromuri) (char \*uri, size_t uriSize, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过uri创建OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromFd](#oh_imagesourcenative_createfromfd) (int32_t fd, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过fd创建OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromData](#oh_imagesourcenative_createfromdata) (uint8_t \*data, size_t dataSize, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过缓冲区数据创建OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromRawFile](#oh_imagesourcenative_createfromrawfile) (RawFileDescriptor \*rawFile, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [OH_DecodingOptions](#oh_decodingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | 通过图片解码参数创建OH_PixelmapNative指针 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePixelmapList](#oh_imagesourcenative_createpixelmaplist) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [OH_DecodingOptions](#oh_decodingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*resVecPixMap[], size_t size) | 通过图片解码参数创建OH_PixelmapNative数组 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetDelayTimeList](#oh_imagesourcenative_getdelaytimelist) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, int32_t \*delayTimeList, size_t size) | 获取图像延迟时间数组 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetImageInfo](#oh_imagesourcenative_getimageinfo) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, int32_t index, [OH_ImageSource_Info](#oh_imagesource_info) \*info) | 获取指定序号的图片信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 获取图片指定属性键的值。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_ModifyImageProperty](#oh_imagesourcenative_modifyimageproperty) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 通过指定的键修改图片属性的值。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, uint32_t \*frameCount) | 获取图像帧数。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_Release](#oh_imagesourcenative_release) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source) | 释放OH_ImageSourceNative指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_Create](#oh_pixelmapinitializationoptions_create) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*\*options) | 创建OH_Pixelmap_InitializationOptions指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetWidth](#oh_pixelmapinitializationoptions_getwidth) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t \*width) | 获取图片宽。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetWidth](#oh_pixelmapinitializationoptions_setwidth) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t width) | 设置图片宽。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetHeight](#oh_pixelmapinitializationoptions_getheight) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t \*height) | 获取图片高。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetHeight](#oh_pixelmapinitializationoptions_setheight) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t height) | 设置图片高。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetPixelFormat](#oh_pixelmapinitializationoptions_getpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*pixelFormat) | 获取像素格式。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetPixelFormat](#oh_pixelmapinitializationoptions_setpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t pixelFormat) | 设置像素格式。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetAlphaType](#oh_pixelmapinitializationoptions_getalphatype) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*alphaType) | 获取透明度类型。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetAlphaType](#oh_pixelmapinitializationoptions_setalphatype) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t alphaType) | 设置透明度类型。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_Release](#oh_pixelmapinitializationoptions_release) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options) | 释放OH_Pixelmap_InitializationOptions指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_Create](#oh_pixelmapimageinfo_create) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*\*info) | 创建OH_Pixelmap_ImageInfo指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetWidth](#oh_pixelmapimageinfo_getwidth) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*width) | 获取图片宽。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetHeight](#oh_pixelmapimageinfo_getheight) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*height) | 获取图片高。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetRowStride](#oh_pixelmapimageinfo_getrowstride) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*rowStride) | 获取行跨距。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetPixelFormat](#oh_pixelmapimageinfo_getpixelformat) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, int32_t \*pixelFormat) | 获取像素格式。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetAlphaType](#oh_pixelmapimageinfo_getalphatype) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, int32_t \*alphaType) | 获取透明度类型。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetDynamicRange](#oh_pixelmapimageinfo_getdynamicrange) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, bool \*isHdr) | 获取Pixelmap是否为高动态范围的信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_Release](#oh_pixelmapimageinfo_release) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info) | 释放OH_Pixelmap_ImageInfo指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_CreatePixelmap](#oh_pixelmapnative_createpixelmap) (uint8_t \*data, size_t dataLength, [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | 通过属性创建PixelMap，默认采用BGRA_8888格式处理数据。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ReadPixels](#oh_pixelmapnative_readpixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | 读取图像像素数据，结果写入ArrayBuffer里。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_WritePixels](#oh_pixelmapnative_writepixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*source, size_t bufferSize) | 读取缓冲区中的图片数据，结果写入PixelMap中。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetImageInfo](#oh_pixelmapnative_getimageinfo) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*imageInfo) | 获取图像像素信息。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Opacity](#oh_pixelmapnative_opacity) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float rate) | 通过设置透明比率来让PixelMap达到对应的透明效果。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Scale](#oh_pixelmapnative_scale) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY) | 根据输入的宽高对图片进行缩放。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Translate](#oh_pixelmapnative_translate) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float x, float y) | 根据输入的坐标对图片进行位置变换。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Rotate](#oh_pixelmapnative_rotate) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float angle) | 根据输入的角度对图片进行旋转。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Flip](#oh_pixelmapnative_flip) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically) | 根据输入的条件对图片进行翻转。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Crop](#oh_pixelmapnative_crop) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [Image_Region](_image___region.md) \*region) | 根据输入的尺寸对图片进行裁剪 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Release](#oh_pixelmapnative_release) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap) | 释放OH_PixelmapNative指针。 | 


## 类型定义说明


### Image_MimeType

```
typedef struct Image_String Image_MimeType
```

**描述**

声明一个图片格式类型的名称。

**起始版本：** 12


### Image_Region

```
typedef struct Image_Region Image_Region
```

**描述**

声明要解码的图像源区域结构体类型名称。

**起始版本：** 12


### Image_Size

```
typedef struct Image_Size Image_Size
```

**描述**

声明图像大小结构。

**起始版本：** 12


### Image_String

```
typedef struct Image_String Image_String
```

**描述**

声明字符串结构的名称。

**起始版本：** 12


### OH_DecodingOptions

```
typedef struct OH_DecodingOptions OH_DecodingOptions
```

**描述**

编码选项参数结构体,被用于[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)。

**起始版本：** 12


### OH_ImageNative

```
typedef struct OH_ImageNative OH_ImageNative
```

**描述**

为图像接口定义native层图像对象的别名。

**起始版本：** 12


### OH_ImagePackerNative

```
typedef struct OH_ImagePackerNative OH_ImagePackerNative
```

**描述**

ImagePacker结构体类型，用于执行ImagePacker相关操作。

**起始版本：** 12


### OH_ImageReceiver_OnCallback

```
typedef void(*OH_ImageReceiver_OnCallback) (OH_ImageReceiverNative *receiver)
```

**描述**

定义native层图片的回调方法。

**起始版本：** 12


### OH_ImageReceiverNative

```
typedef struct OH_ImageReceiverNative OH_ImageReceiverNative
```

**描述**

用于定义OH_ImageReceiverNative数据类型名称。

**起始版本：** 12


### OH_ImageReceiverOptions

```
typedef struct OH_ImageReceiverOptions OH_ImageReceiverOptions
```

**描述**

用于定义OH_ImageReceiverOptions数据类型名称。

**起始版本：** 12


### OH_ImageSource_Info

```
typedef struct OH_ImageSource_Info OH_ImageSource_Info
```

**描述**

图片源信息结构体 [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create).

**起始版本：** 12


### OH_ImageSourceNative

```
typedef struct OH_ImageSourceNative OH_ImageSourceNative
```

**描述**

ImageSource结构体类型，用于执行ImageSource相关操作。

**起始版本：** 12


### OH_PackingOptions

```
typedef struct OH_PackingOptions OH_PackingOptions
```

**描述**

图像编码选项。

**起始版本：** 12


### OH_Pixelmap_ImageInfo

```
typedef struct OH_Pixelmap_ImageInfo OH_Pixelmap_ImageInfo
```

**描述**

图像像素信息结构体。

**起始版本：** 12


### OH_Pixelmap_InitializationOptions

```
typedef struct OH_Pixelmap_InitializationOptions OH_Pixelmap_InitializationOptions
```

**描述**

初始化参数结构体。

**起始版本：** 12


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```

**描述**

Pixelmap结构体类型，用于执行Pixelmap相关操作。

**起始版本：** 12


## 枚举类型说明


### IMAGE_DYNAMIC_RANGE

```
enum IMAGE_DYNAMIC_RANGE
```

**描述**

解码指定期望动态范围。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_DYNAMIC_RANGE_AUTO | 根据图片自适应处理。 | 
| IMAGE_DYNAMIC_RANGE_SDR | 标准动态范围。 | 
| IMAGE_DYNAMIC_RANGE_HDR | 高动态范围。 | 


### Image_ErrorCode

```
enum Image_ErrorCode
```

**描述**

错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_SUCCESS | 操作成功。 | 
| IMAGE_BAD_PARAMETER | 无效参数。 | 
| IMAGE_UNSUPPORTED_MIME_TYPE | 不支持的MIME类型。 | 
| IMAGE_UNKNOWN_MIME_TYPE | 未知的MIME类型。 | 
| IMAGE_TOO_LARGE | 过大的数据或图片。 | 
| IMAGE_UNSUPPORTED_OPERATION | 不支持的操作。 | 
| IMAGE_UNSUPPORTED_METADATA | 不支持的 metadata。 | 
| IMAGE_UNSUPPORTED_CONVERSION | 不支持的转换。 | 
| IMAGE_INVALID_REGION | 无效区域。 | 
| IMAGE_ALLOC_FAILED | 申请内存失败。 | 
| IMAGE_COPY_FAILED | 内存拷贝失败。 | 
| IMAGE_UNKNOWN_ERROR | 未知错误。 | 
| IMAGE_BAD_SOURCE | 解码数据源异常。 | 
| IMAGE_DECODE_FAILED | 解码失败。 | 
| IMAGE_ENCODE_FAILED | 编码失败。 | 


### IMAGE_PACKER_DYNAMIC_RANGE

```
enum IMAGE_PACKER_DYNAMIC_RANGE
```

**描述**

编码指定动态范围。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_PACKER_DYNAMIC_RANGE_AUTO | 编码动态范围根据图像信息自适应。 | 
| IMAGE_PACKER_DYNAMIC_RANGE_SDR | 编码图片为标准动态范围。 | 


### PIXEL_FORMAT

```
enum PIXEL_FORMAT
```

**描述**

图片像素格式。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PIXEL_FORMAT_UNKNOWN | 未知格式 | 
| PIXEL_FORMAT_RGB_565 | RGB_565格式 | 
| PIXEL_FORMAT_RGBA_8888 | RGBA_8888格式 | 
| PIXEL_FORMAT_BGRA_8888 | BGRA_8888格式 | 
| PIXEL_FORMAT_RGB_888 | RGB_888格式 | 
| PIXEL_FORMAT_ALPHA_8 | ALPHA_8格式 | 
| PIXEL_FORMAT_RGBA_F16 | RGBA_F16格式 | 
| PIXEL_FORMAT_NV21 | NV21格式 | 
| PIXEL_FORMAT_NV12 | NV12格式 | 


### PIXELMAP_ALPHA_TYPE

```
enum PIXELMAP_ALPHA_TYPE
```

**描述**

Pixelmap透明度类型。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| PIXELMAP_ALPHA_TYPE_UNKNOWN | 未知格式 | 
| PIXELMAP_ALPHA_TYPE_OPAQUE | 不透明的格式 | 
| PIXELMAP_ALPHA_TYPE_PREMULTIPLIED | 预乘透明度格式 | 


## 函数说明


### OH_DecodingOptions_Create()

```
Image_ErrorCode OH_DecodingOptions_Create (OH_DecodingOptions ** options)
```

**描述**

创建OH_DecodingOptions指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange (OH_DecodingOptions * options, int32_t * desiredDynamicRange )
```

**描述**

获取解码时设置的期望动态范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 
| desiredDynamicRange | 期望的动态范围值 [IMAGE_DYNAMIC_RANGE](#image_dynamic_range)。 | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion (OH_DecodingOptions * options, Image_Region * desiredRegion )
```

**描述**

设置解码区域。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 
| desiredRegion | 解码区域。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredSize (OH_DecodingOptions * options, Image_Size * desiredSize )
```

**描述**

获取期望输出大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 
| desiredSize | 期望输出大小。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetIndex()

```
Image_ErrorCode OH_DecodingOptions_GetIndex (OH_DecodingOptions * options, uint32_t * index )
```

**描述**

获取解码图片序号。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 
| index | 解码图片序号。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_GetPixelFormat (OH_DecodingOptions * options, int32_t * pixelFormat )
```

**描述**

获取pixel格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 
| pixelFormat | pixel格式[PIXEL_FORMAT](#pixel_format)。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetRotate()

```
Image_ErrorCode OH_DecodingOptions_GetRotate (OH_DecodingOptions * options, float * rotate )
```

**描述**

获取旋转角度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 
| rotate | 旋转角度，单位为deg。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_Release()

```
Image_ErrorCode OH_DecodingOptions_Release (OH_DecodingOptions * options)
```

**描述**

释放OH_DecodingOptions指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange (OH_DecodingOptions * options, int32_t desiredDynamicRange )
```

**描述**

设置解码时的期望动态范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptions指针。 | 
| desiredDynamicRange | 期望的动态范围值 [IMAGE_DYNAMIC_RANGE](#image_dynamic_range)。 | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。