# Image_NativeModule


## 概述

提供图片处理的相关能力，包括图片编解码、从Native层获取图片数据等。

使用该模块的接口，无需通过JS接口导入，可直接使用NDK完成功能开发。

开发者可根据实际的开发需求，参考对应的开发指南及样例：

- [使用Image_NativeModule完成图片解码](../../media/image/image-source-c.md)
- [使用Image_NativeModule完成多图对象解码](../../media/image/image-source-picture-c.md)
- [使用Image_NativeModule完成图片接收器](../../media/image/image-receiver-c.md)
- [使用Image_NativeModule完成位图操作](../../media/image/pixelmap-c.md)
- [使用Image_NativeModule处理图像信息](../../media/image/image-info-c.md)
- [使用Image_NativeModule完成图片编码](../../media/image/image-packer-c.md)
- [使用Image_NativeModule完成多图对象编码](../../media/image/image-packer-picture-c.md)

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [image_common.h](image__common_8h.md) | 声明图像接口使用的公共枚举和结构体。  | 
| [image_native.h](image__native_8h.md) | 声明图像的剪辑矩形、大小和组件数据的接口函数。  | 
| [image_packer_native.h](image__packer__native_8h.md) | 图片编码API。  | 
| [image_receiver_native.h](image__receiver__native_8h.md) | 声明从Native层获取图片数据的方法。  | 
| [image_source_native.h](image__source__native_8h.md) | 图片解码API。  | 
| [picture_native.h](picture__native_8h.md) | 提供获取picture数据和信息的API。  | 
| [pixelmap_native.h](pixelmap__native_8h.md) | 访问Pixelmap的API。  | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [Image_Size](_image___size.md) | 图像大小结构体。  | 
| struct  [Image_Region](_image___region.md) | 待解码的图像源区域结构体。  | 
| struct  [Image_String](_image___string.md) | 字符串结构。  | 
| struct  [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) | HDR_STATIC_METADATA关键字对应的静态元数据值。  | 
| struct  [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) | DR_DYNAMIC_METADATA关键字对应的动态元数据值。  | 
| struct  [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) | HDR_GAINMAP_METADATA关键字对应的gainmap相关元数据值，参考ISO 21496-1。  | 
| struct  [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) | Pixelmap使用的HDR元数据值，和OH_Pixelmap_HdrMetadataKey关键字相对应。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [Image_Size](_image___size.md) [Image_Size](#image_size) | 声明图像大小结构。  | 
| typedef struct [Image_Region](_image___region.md) [Image_Region](#image_region) | 声明要解码的图像源区域结构体类型名称。  | 
| typedef struct [OH_PictureMetadata](#oh_picturemetadata) [OH_PictureMetadata](#oh_picturemetadata) | 声明用于Picture的元数据。  | 
| typedef struct [Image_String](_image___string.md) [Image_String](#image_string) | 声明字符串结构的名称。  | 
| typedef struct [Image_String](_image___string.md) [Image_MimeType](#image_mimetype) | 声明一个图片格式类型的名称。  | 
| typedef struct [OH_ImageNative](#oh_imagenative) [OH_ImageNative](#oh_imagenative) | 为图像接口定义native层图像对象的别名。  | 
| typedef struct [OH_ImagePackerNative](#oh_imagepackernative) [OH_ImagePackerNative](#oh_imagepackernative) | ImagePacker结构体类型，用于执行ImagePacker相关操作。  | 
| typedef struct [OH_PackingOptions](#oh_packingoptions) [OH_PackingOptions](#oh_packingoptions) | 图像编码选项。  | 
| typedef struct [OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) [OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) | 图像序列编码选项。  | 
| typedef struct [OH_ImageReceiverNative](#oh_imagereceivernative) [OH_ImageReceiverNative](#oh_imagereceivernative) | 用于定义OH_ImageReceiverNative数据类型名称。  | 
| typedef struct [OH_ImageReceiverOptions](#oh_imagereceiveroptions) [OH_ImageReceiverOptions](#oh_imagereceiveroptions) | 用于定义OH_ImageReceiverOptions数据类型名称。  | 
| typedef void(\* [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | 定义native层图片的回调方法。  | 
| typedef struct [OH_ImageSourceNative](#oh_imagesourcenative) [OH_ImageSourceNative](#oh_imagesourcenative) | ImageSource结构体类型，用于执行ImageSource相关操作。  | 
| typedef struct [OH_ImageSource_Info](#oh_imagesource_info) [OH_ImageSource_Info](#oh_imagesource_info) | 图片源信息结构体 [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create)。 | 
| typedef struct [OH_DecodingOptions](#oh_decodingoptions) [OH_DecodingOptions](#oh_decodingoptions) | 解码选项参数结构体,被用于[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)。  | 
| typedef struct [OH_PictureNative](#oh_picturenative) [OH_PictureNative](#oh_picturenative) | Picture结构体类型，用于执行picture相关操作。  | 
| typedef struct [OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) [OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) | AuxiliaryPicture结构体类型，用于执行AuxiliaryPicture相关操作。  | 
| typedef struct [OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) [OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) | AuxiliaryPictureInfo结构体类型，用于执行AuxiliaryPictureInfo相关操作。  | 
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | Pixelmap结构体类型，用于执行Pixelmap相关操作。 | 
| typedef struct [OH_NativeBuffer](#oh_nativebuffer) [OH_NativeBuffer](#oh_nativebuffer) | NativeBuffer结构体类型，用于执行NativeBuffer相关操作。 | 
| typedef struct [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) | NativeColorSpaceManager结构体类型，用于执行NativeColorSpaceManager相关操作。  | 
| typedef struct [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) [OH_Pixelmap_HdrStaticMetadata](#oh_pixelmap_hdrstaticmetadata) | HDR_STATIC_METADATA关键字对应的静态元数据值。  | 
| typedef struct [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) [OH_Pixelmap_HdrDynamicMetadata](#oh_pixelmap_hdrdynamicmetadata) | DR_DYNAMIC_METADATA关键字对应的动态元数据值。  | 
| typedef struct [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) [OH_Pixelmap_HdrGainmapMetadata](#oh_pixelmap_hdrgainmapmetadata) | HDR_GAINMAP_METADATA关键字对应的gainmap相关元数据值，参考ISO 21496-1。  | 
| typedef struct [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) [OH_Pixelmap_HdrMetadataValue](#oh_pixelmap_hdrmetadatavalue) | Pixelmap使用的HDR元数据值，和OH_Pixelmap_HdrMetadataKey关键字相对应。  | 
| typedef struct [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) | 初始化参数结构体。 | 
| typedef struct [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) | 图像像素信息结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](#image_errorcode) {<br/>IMAGE_SUCCESS = 0, IMAGE_BAD_PARAMETER = 401, IMAGE_UNSUPPORTED_MIME_TYPE = 7600101, IMAGE_UNKNOWN_MIME_TYPE = 7600102,<br/>IMAGE_TOO_LARGE = 7600103, IMAGE_DMA_NOT_EXIST = 7600173, IMAGE_DMA_OPERATION_FAILED = 7600174, IMAGE_UNSUPPORTED_OPERATION = 7600201,<br/>IMAGE_UNSUPPORTED_METADATA = 7600202, IMAGE_UNSUPPORTED_CONVERSION = 7600203, IMAGE_INVALID_REGION = 7600204, IMAGE_UNSUPPORTED_MEMORY_FORMAT = 7600205,<br/>IMAGE_ALLOC_FAILED = 7600301, IMAGE_COPY_FAILED = 7600302, IMAGE_LOCK_UNLOCK_FAILED = 7600303, IMAGE_UNKNOWN_ERROR = 7600901,<br/>IMAGE_BAD_SOURCE = 7700101,<br/>IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE = 7700102,<br/>IMAGE_SOURCE_TOO_LARGE = 7700103,<br/>IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE = 7700201,<br/>IMAGE_SOURCE_UNSUPPORTED_OPTIONS = 7700203, <br/>IMAGE_DECODE_FAILED = 7700301,<br/>IMAGE_SOURCE_ALLOC_FAILED = 7700302,<br/>IMAGE_ENCODE_FAILED = 7800301<br/>} | 错误码。 | 
| [Image_MetadataType](#image_metadatatype) { EXIF_METADATA = 1, FRAGMENT_METADATA = 2 } | 定义元数据类型。  | 
| [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range) {<br/>IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0,<br/>IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1 } | 编码指定动态范围。 | 
| [IMAGE_DYNAMIC_RANGE](#image_dynamic_range) {<br/>IMAGE_DYNAMIC_RANGE_AUTO = 0,<br/>IMAGE_DYNAMIC_RANGE_SDR = 1,<br/>IMAGE_DYNAMIC_RANGE_HDR = 2 } | 解码指定期望动态范围。 | 
| [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) {<br/>IMAGE_ALLOCATOR_TYPE_AUTO = 0,<br/>IMAGE_ALLOCATOR_TYPE_DMA = 1,<br/>IMAGE_ALLOCATOR_TYPE_SHARE_MEMORY = 2 } | 用于分配 PixelMap 内存的分配器类型。 | 
| [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) {<br/>AUXILIARY_PICTURE_TYPE_GAINMAP = 1, AUXILIARY_PICTURE_TYPE_DEPTH_MAP = 2, AUXILIARY_PICTURE_TYPE_UNREFOCUS_MAP = 3, AUXILIARY_PICTURE_TYPE_LINEAR_MAP = 4,<br/>AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP = 5<br/>} | 辅助图类型。  | 
| [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type) {<br/>PIXELMAP_ALPHA_TYPE_UNKNOWN = 0,<br/>PIXELMAP_ALPHA_TYPE_OPAQUE = 1,<br/>PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2, <br/>PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED = 3 } | Pixelmap透明度类型。 | 
| [PIXEL_FORMAT](#pixel_format) {<br/>PIXEL_FORMAT_UNKNOWN = 0, PIXEL_FORMAT_RGB_565 = 2,<br/>PIXEL_FORMAT_RGBA_8888 = 3, PIXEL_FORMAT_BGRA_8888 = 4,<br/>PIXEL_FORMAT_RGB_888 = 5, PIXEL_FORMAT_ALPHA_8 = 6,<br/>PIXEL_FORMAT_RGBA_F16 = 7, PIXEL_FORMAT_NV21 = 8,<br/>PIXEL_FORMAT_NV12 = 9, <br/>PIXEL_FORMAT_RGBA_1010102 = 10, <br/>PIXEL_FORMAT_YCBCR_P010 = 11, <br/>PIXEL_FORMAT_YCRCB_P010 = 12<br/>} | 图片像素格式。 | 
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) { <br/>OH_PixelmapNative_AntiAliasing_NONE = 0, <br/>OH_PixelmapNative_AntiAliasing_LOW = 1, <br/>OH_PixelmapNative_AntiAliasing_MEDIUM = 2, <br/>OH_PixelmapNative_AntiAliasing_HIGH = 3 <br/>} | Pixelmap缩放时采用的缩放算法。  | 
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) { <br/>HDR_METADATA_TYPE = 0, <br/>HDR_STATIC_METADATA = 1, <br/>HDR_DYNAMIC_METADATA = 2, <br/>HDR_GAINMAP_METADATA = 3 } | Pixelmap使用的HDR相关元数据信息的关键字，用于[OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata)。  | 
| [OH_Pixelmap_HdrMetadataType](#oh_pixelmap_hdrmetadatatype) { <br/>HDR_METADATA_TYPE_NONE = 0, <br/>HDR_METADATA_TYPE_BASE = 1, <br/>HDR_METADATA_TYPE_GAINMAP = 2, <br/>HDR_METADATA_TYPE_ALTERNATE = 3 } | HDR_METADATA_TYPE关键字对应的值。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](#image_errorcode) [OH_PictureMetadata_Create](#oh_picturemetadata_create) ([Image_MetadataType](#image_metadatatype) metadataType, [OH_PictureMetadata](#oh_picturemetadata) \*\*metadata) | 创建OH_PictureMetadata指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureMetadata_GetProperty](#oh_picturemetadata_getproperty) ([OH_PictureMetadata](#oh_picturemetadata) \*metadata, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 根据key获取Metadata的单条属性。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureMetadata_SetProperty](#oh_picturemetadata_setproperty) ([OH_PictureMetadata](#oh_picturemetadata) \*metadata, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 根据key修改Metadata的单条属性。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureMetadata_Release](#oh_picturemetadata_release) ([OH_PictureMetadata](#oh_picturemetadata) \*metadata) | 释放OH_PictureMetadata指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureMetadata_Clone](#oh_picturemetadata_clone) ([OH_PictureMetadata](#oh_picturemetadata) \*oldMetadata, [OH_PictureMetadata](#oh_picturemetadata) \*\*newMetadata) | 拷贝元数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetImageSize](#oh_imagenative_getimagesize) ([OH_ImageNative](#oh_imagenative) \*image, [Image_Size](_image___size.md) \*size) | 获取Native [OH_ImageNative](#oh_imagenative) 对象的 [Image_Size](_image___size.md) 信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetComponentTypes](#oh_imagenative_getcomponenttypes) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t \*\*types, size_t \*typeSize) | 获取Native [OH_ImageNative](#oh_imagenative) 对象的组件列表信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetByteBuffer](#oh_imagenative_getbytebuffer) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, OH_NativeBuffer \*\*nativeBuffer) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的缓冲区。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetBufferSize](#oh_imagenative_getbuffersize) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, size_t \*size) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的缓冲区的大小。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetRowStride](#oh_imagenative_getrowstride) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, int32_t \*rowStride) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的像素行宽。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetPixelStride](#oh_imagenative_getpixelstride) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, int32_t \*pixelStride) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的像素大小。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetTimestamp](#oh_imagenative_gettimestamp) ([OH_ImageNative](#oh_imagenative) \*image, int64_t \*timestamp) | 获取Native [OH_ImageNative](#oh_imagenative) 对象中的时间戳信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_Release](#oh_imagenative_release) ([OH_ImageNative](#oh_imagenative) \*image) | 释放native [OH_ImageNative](#oh_imagenative) 对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_Create](#oh_packingoptions_create) ([OH_PackingOptions](#oh_packingoptions) \*\*options) | 创建PackingOptions结构体的指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetMimeType](#oh_packingoptions_getmimetype) ([OH_PackingOptions](#oh_packingoptions) \*options, [Image_MimeType](#image_mimetype) \*format) | 获取MIME类型。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetMimeType](#oh_packingoptions_setmimetype) ([OH_PackingOptions](#oh_packingoptions) \*options, [Image_MimeType](#image_mimetype) \*format) | 设置MIME类型。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetQuality](#oh_packingoptions_getquality) ([OH_PackingOptions](#oh_packingoptions) \*options, uint32_t \*quality) | 获取编码质量。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetQuality](#oh_packingoptions_setquality) ([OH_PackingOptions](#oh_packingoptions) \*options, uint32_t quality) | 设置编码质量。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetDesiredDynamicRange](#oh_packingoptions_getdesireddynamicrange) ([OH_PackingOptions](#oh_packingoptions) \*options, int32_t \*desiredDynamicRange) | 获取编码时期望的图片动态范围。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetDesiredDynamicRange](#oh_packingoptions_setdesireddynamicrange) ([OH_PackingOptions](#oh_packingoptions) \*options, int32_t desiredDynamicRange) | 设置编码时期望的图片动态范围。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_Release](#oh_packingoptions_release) ([OH_PackingOptions](#oh_packingoptions) \*options) | 释放OH_PackingOptions指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_Create](#oh_packingoptionsforsequence_create) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*\*options) | 创建OH_PackingOptionsForSequence结构体的指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_SetFrameCount](#oh_packingoptionsforsequence_setframecount) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, uint32_t frameCount) | 设置编码时指定的帧数。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_GetFrameCount](#oh_packingoptionsforsequence_getframecount) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, uint32_t \*frameCount) | 获取编码时指定的帧数。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_SetDelayTimeList](#oh_packingoptionsforsequence_setdelaytimelist) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, int32_t \*delayTimeList, size_t delayTimeListLength) | 设定编码时图片的延迟时间数组。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_GetDelayTimeList](#oh_packingoptionsforsequence_getdelaytimelist) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, int32_t \*delayTimeList, size_t delayTimeListLength) | 获取编码时图片的延迟时间数组。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_SetDisposalTypes](#oh_packingoptionsforsequence_setdisposaltypes) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, uint32_t \*disposalTypes, size_t disposalTypesLength) | 设定编码时图片的过渡帧模式数组。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_GetDisposalTypes](#oh_packingoptionsforsequence_getdisposaltypes) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, uint32_t \*disposalTypes, size_t disposalTypesLength) | 获取编码时图片的过渡帧模式数组。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_SetLoopCount](#oh_packingoptionsforsequence_setloopcount) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, uint32_t loopCount) | 设定编码时图片循环播放次数。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_GetLoopCount](#oh_packingoptionsforsequence_getloopcount) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, uint32_t \*loopCount) | 获取编码时图片循环播放次数。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptionsForSequence_Release](#oh_packingoptionsforsequence_release) ([OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options) | 释放OH_PackingOptionsForSequence指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_Create](#oh_imagepackernative_create) ([OH_ImagePackerNative](#oh_imagepackernative) \*\*imagePacker) | 创建OH_ImagePackerNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromImageSource](#oh_imagepackernative_packtodatafromimagesource) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_ImageSourceNative](#oh_imagesourcenative) \*imageSource, uint8_t \*outData, size_t \*size) | 将ImageSource编码为指定格式的数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmap](#oh_imagepackernative_packtodatafrompixelmap) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*outData, size_t \*size) | 将Pixelmap编码为指定格式的数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromPicture](#oh_imagepackernative_packtodatafrompicture) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PictureNative](#oh_picturenative) \*picture, uint8_t \*outData, size_t \*size) | 将Picture编码为指定格式的数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmapSequence](#oh_imagepackernative_packtodatafrompixelmapsequence) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, [OH_ImagePackerNative](#oh_imagepackernative) \*\*pixelmapSequence, size_t sequenceLength, uint8_t \*outData, size_t \*outDataSize) | 将Pixelmap序列编码为数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromImageSource](#oh_imagepackernative_packtofilefromimagesource) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_ImageSourceNative](#oh_imagesourcenative) \*imageSource, int32_t fd) | 将一个ImageSource编码到文件中。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmap](#oh_imagepackernative_packtofilefrompixelmap) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, int32_t fd) | 将一个Pixelmap编码到文件中。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromPicture](#oh_imagepackernative_packtofilefrompicture) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PictureNative](#oh_picturenative) \*picture, int32_t fd) | 将一个Picture编码到文件中。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmapSequence](#oh_imagepackernative_packtofilefrompixelmapsequence) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptionsForSequence](#oh_packingoptionsforsequence) \*options, [OH_ImagePackerNative](#oh_imagepackernative) \*\*pixelmapSequence, size_t sequenceLength, int32_t fd) | 将一个Pixelmap序列编码到文件中。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_Release](#oh_imagepackernative_release) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker) | 释放OH_ImagePackerNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_Create](#oh_imagereceiveroptions_create) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*\*options) | 创建应用层 OH_ImageReceiverOptions 对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_GetSize](#oh_imagereceiveroptions_getsize) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) \*size) | 获取 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_SetSize](#oh_imagereceiveroptions_setsize) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) size) | 设置 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_GetCapacity](#oh_imagereceiveroptions_getcapacity) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, int32_t \*capacity) | 获取 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的图片缓存容量的信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_SetCapacity](#oh_imagereceiveroptions_setcapacity) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, int32_t capacity) | 设置 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的图片缓存容量的信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_Release](#oh_imagereceiveroptions_release) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options) | 释放 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Create](#oh_imagereceivernative_create) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [OH_ImageReceiverNative](#oh_imagereceivernative) \*\*receiver) | 创建应用层 OH_ImageReceiverNative 对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetReceivingSurfaceId](#oh_imagereceivernative_getreceivingsurfaceid) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, uint64_t \*surfaceId) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取receiver的id。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_ReadLatestImage](#oh_imagereceivernative_readlatestimage) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageNative](#oh_imagenative) \*\*image) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取最新的一张图片。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_ReadNextImage](#oh_imagereceivernative_readnextimage) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageNative](#oh_imagenative) \*\*image) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取下一张图片。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_On](#oh_imagereceivernative_on) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback) | 注册一个[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调事件。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Off](#oh_imagereceivernative_off) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | 关闭[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调事件。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetSize](#oh_imagereceivernative_getsize) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [Image_Size](_image___size.md) \*size) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取ImageReceiver的大小。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetCapacity](#oh_imagereceivernative_getcapacity) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, int32_t \*capacity) | 通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取ImageReceiver的容量。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Release](#oh_imagereceivernative_release) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | 释放native [OH_ImageReceiverNative](#oh_imagereceivernative) 对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create) ([OH_ImageSource_Info](#oh_imagesource_info) \*\*info) | 创建OH_ImageSource_Info指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetWidth](#oh_imagesourceinfo_getwidth) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, uint32_t \*width) | 获取图片的宽。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetHeight](#oh_imagesourceinfo_getheight) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, uint32_t \*height) | 获取图片的高。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetDynamicRange](#oh_imagesourceinfo_getdynamicrange) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, bool \*isHdr) | 获取图片是否为高动态范围的信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_Release](#oh_imagesourceinfo_release) ([OH_ImageSource_Info](#oh_imagesource_info) \*info) | 释放OH_ImageSource_Info指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_Create](#oh_decodingoptions_create) ([OH_DecodingOptions](#oh_decodingoptions) \*\*options) | 创建OH_DecodingOptions指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetPixelFormat](#oh_decodingoptions_getpixelformat) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t \*pixelFormat) | 获取pixel格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetPixelFormat](#oh_decodingoptions_setpixelformat) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t pixelFormat) | 设置pixel格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetIndex](#oh_decodingoptions_getindex) ([OH_DecodingOptions](#oh_decodingoptions) \*options, uint32_t \*index) | 获取解码图片序号。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetIndex](#oh_decodingoptions_setindex) ([OH_DecodingOptions](#oh_decodingoptions) \*options, uint32_t index) | 设置解码图片序号。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetRotate](#oh_decodingoptions_getrotate) ([OH_DecodingOptions](#oh_decodingoptions) \*options, float \*rotate) | 获取旋转角度。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetRotate](#oh_decodingoptions_setrotate) ([OH_DecodingOptions](#oh_decodingoptions) \*options, float rotate) | 设置旋转角度。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredSize](#oh_decodingoptions_getdesiredsize) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | 获取期望输出大小。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredSize](#oh_decodingoptions_setdesiredsize) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | 设置期望输出大小。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredRegion](#oh_decodingoptions_getdesiredregion) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | 获取解码区域。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredRegion](#oh_decodingoptions_setdesiredregion) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | 设置解码区域。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredDynamicRange](#oh_decodingoptions_getdesireddynamicrange) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t \*desiredDynamicRange) | 获取解码时设置的期望动态范围。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredDynamicRange](#oh_decodingoptions_setdesireddynamicrange) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t desiredDynamicRange) | 设置解码时的期望动态范围。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_Release](#oh_decodingoptions_release) ([OH_DecodingOptions](#oh_decodingoptions) \*options) | 释放OH_DecodingOptions指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromUri](#oh_imagesourcenative_createfromuri) (char \*uri, size_t uriSize, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过uri创建OH_ImageSourceNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromFd](#oh_imagesourcenative_createfromfd) (int32_t fd, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过fd创建OH_ImageSourceNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromData](#oh_imagesourcenative_createfromdata) (uint8_t \*data, size_t dataSize, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过缓冲区数据创建OH_ImageSourceNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromRawFile](#oh_imagesourcenative_createfromrawfile) (RawFileDescriptor \*rawFile, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | 通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [OH_DecodingOptions](#oh_decodingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | 通过图片解码参数创建OH_PixelmapNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePixelmapUsingAllocator](#oh_imagesourcenative_createpixelmapusingallocator) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [OH_DecodingOptions](#oh_decodingoptions) \*options, [IMAGE_ALLOCATOR_TYPE](#image_allocator_type) allocator, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | 根据解码参数创建一个PixelMap，PixelMap使用的内存类型可以通过allocatorType来指定。<br/>默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。 在处理通过此接口返回的PixelMap时，请始终考虑步幅（stride）的影响。 | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePixelmapList](#oh_imagesourcenative_createpixelmaplist) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [OH_DecodingOptions](#oh_decodingoptions) \*options, OH_PixelmapNative \*resVecPixMap[], size_t size) | 通过图片解码参数创建OH_PixelmapNative数组。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePicture](#oh_imagesourcenative_createpicture) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, OH_DecodingOptionsForPicture \*options, [OH_PictureNative](#oh_picturenative) \*\*picture) | 通过图片解码创建OH_PictureNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetDelayTimeList](#oh_imagesourcenative_getdelaytimelist) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, int32_t \*delayTimeList, size_t size) | 获取图像延迟时间数组。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetImageInfo](#oh_imagesourcenative_getimageinfo) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, int32_t index, [OH_ImageSource_Info](#oh_imagesource_info) \*info) | 获取指定序号的图片信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 获取图片指定属性键的值。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_ModifyImageProperty](#oh_imagesourcenative_modifyimageproperty) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | 通过指定的键修改图片属性的值。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, uint32_t \*frameCount) | 获取图像帧数。  | 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_Release](#oh_imagesourcenative_release) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source) | 释放OH_ImageSourceNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptionsForPicture_Create](#oh_decodingoptionsforpicture_create) (OH_DecodingOptionsForPicture \*\*options) | 创建OH_DecodingOptionsForPicture指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures](#oh_decodingoptionsforpicture_getdesiredauxiliarypictures) (OH_DecodingOptionsForPicture \*options, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) \*\*desiredAuxiliaryPictures, size_t \*length) | 获取解码时设置的期望辅助图（期望解码出的picture包含的辅助图）。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures](#oh_decodingoptionsforpicture_setdesiredauxiliarypictures) (OH_DecodingOptionsForPicture \*options, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) \*desiredAuxiliaryPictures, size_t length) | 设置解码选项中的期望辅助图。  | 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptionsForPicture_Release](#oh_decodingoptionsforpicture_release) (OH_DecodingOptionsForPicture \*options) | 释放OH_DecodingOptionsForPicture指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_CreatePicture](#oh_picturenative_createpicture) (OH_PixelmapNative \*mainPixelmap, [OH_PictureNative](#oh_picturenative) \*\*picture) | 创建OH_PictureNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_GetMainPixelmap](#oh_picturenative_getmainpixelmap) ([OH_PictureNative](#oh_picturenative) \*picture, OH_PixelmapNative \*\*mainPixelmap) | 获取主图的OH_PixelmapNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_GetHdrComposedPixelmap](#oh_picturenative_gethdrcomposedpixelmap) ([OH_PictureNative](#oh_picturenative) \*picture, OH_PixelmapNative \*\*hdrPixelmap) | 获取hdr图的OH_PixelmapNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_GetGainmapPixelmap](#oh_picturenative_getgainmappixelmap) ([OH_PictureNative](#oh_picturenative) \*picture, OH_PixelmapNative \*\*gainmapPixelmap) | 获取增益图的OH_PixelmapNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_SetAuxiliaryPicture](#oh_picturenative_setauxiliarypicture) ([OH_PictureNative](#oh_picturenative) \*picture, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture) | 设置辅助图。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_GetAuxiliaryPicture](#oh_picturenative_getauxiliarypicture) ([OH_PictureNative](#oh_picturenative) \*picture, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*\*auxiliaryPicture) | 根据类型获取辅助图。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_GetMetadata](#oh_picturenative_getmetadata) ([OH_PictureNative](#oh_picturenative) \*picture, [Image_MetadataType](#image_metadatatype) metadataType, [OH_PictureMetadata](#oh_picturemetadata) \*\*metadata) | 获取主图的元数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_SetMetadata](#oh_picturenative_setmetadata) ([OH_PictureNative](#oh_picturenative) \*picture, [Image_MetadataType](#image_metadatatype) metadataType, [OH_PictureMetadata](#oh_picturemetadata) \*metadata) | 设置主图的元数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PictureNative_Release](#oh_picturenative_release) ([OH_PictureNative](#oh_picturenative) \*picture) | 释放OH_PictureNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_Create](#oh_auxiliarypicturenative_create) (uint8_t \*data, size_t dataLength, [Image_Size](_image___size.md) \*size, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type, [OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*\*auxiliaryPicture) | 创建OH_AuxiliaryPictureNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_WritePixels](#oh_auxiliarypicturenative_writepixels) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture, uint8_t \*source, size_t bufferSize) | 读取缓冲区的图像像素数据，并将结果写入为辅助图中。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_ReadPixels](#oh_auxiliarypicturenative_readpixels) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture, uint8_t \*destination, size_t \*bufferSize) | 读取辅助图的像素数据，结果写入缓冲区。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_GetType](#oh_auxiliarypicturenative_gettype) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) \*type) | 获取辅助图类型。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_GetInfo](#oh_auxiliarypicturenative_getinfo) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture, [OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*\*info) | 获取辅助图信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_SetInfo](#oh_auxiliarypicturenative_setinfo) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture, [OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info) | 设置辅助图信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_GetMetadata](#oh_auxiliarypicturenative_getmetadata) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_MetadataType](#image_metadatatype) metadataType, [OH_PictureMetadata](#oh_picturemetadata) \*\*metadata) | 获取辅助图的元数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_SetMetadata](#oh_auxiliarypicturenative_setmetadata) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*auxiliaryPicture, [Image_MetadataType](#image_metadatatype) metadataType, [OH_PictureMetadata](#oh_picturemetadata) \*metadata) | 设置辅助图的元数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureNative_Release](#oh_auxiliarypicturenative_release) ([OH_AuxiliaryPictureNative](#oh_auxiliarypicturenative) \*picture) | 释放OH_AuxiliaryPictureNative指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_Create](#oh_auxiliarypictureinfo_create) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*\*info) | 创建一个OH_AuxiliaryPictureInfo对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_GetType](#oh_auxiliarypictureinfo_gettype) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) \*type) | 获取辅助图的图片信息的辅助图类型。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_SetType](#oh_auxiliarypictureinfo_settype) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, [Image_AuxiliaryPictureType](#image_auxiliarypicturetype) type) | 设置辅助图的图片信息的辅助图类型。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_GetSize](#oh_auxiliarypictureinfo_getsize) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, [Image_Size](_image___size.md) \*size) | 获取辅助图的图片尺寸。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_SetSize](#oh_auxiliarypictureinfo_setsize) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, [Image_Size](_image___size.md) \*size) | 设置辅助图的图片尺寸。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_GetRowStride](#oh_auxiliarypictureinfo_getrowstride) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, uint32_t \*rowStride) | 获取辅助图的图片信息的行跨距。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_SetRowStride](#oh_auxiliarypictureinfo_setrowstride) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, uint32_t rowStride) | 设置辅助图的图片信息的行跨距。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_GetPixelFormat](#oh_auxiliarypictureinfo_getpixelformat) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, PIXEL_FORMAT \*pixelFormat) | 获取辅助图的图片信息的像素格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_SetPixelFormat](#oh_auxiliarypictureinfo_setpixelformat) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info, PIXEL_FORMAT pixelFormat) | 设置辅助图的图片信息的像素格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_AuxiliaryPictureInfo_Release](#oh_auxiliarypictureinfo_release) ([OH_AuxiliaryPictureInfo](#oh_auxiliarypictureinfo) \*info) | 释放OH_AuxiliaryPictureInfo指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_Create](#oh_pixelmapinitializationoptions_create) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*\*options) | 创建OH_Pixelmap_InitializationOptions指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetWidth](#oh_pixelmapinitializationoptions_getwidth) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t \*width) | 获取图片宽。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetWidth](#oh_pixelmapinitializationoptions_setwidth) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t width) | 设置图片宽。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetHeight](#oh_pixelmapinitializationoptions_getheight) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t \*height) | 获取图片高。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetHeight](#oh_pixelmapinitializationoptions_setheight) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t height) | 设置图片高。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetPixelFormat](#oh_pixelmapinitializationoptions_getpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*pixelFormat) | 获取像素格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetPixelFormat](#oh_pixelmapinitializationoptions_setpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t pixelFormat) | 设置像素格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetSrcPixelFormat](#oh_pixelmapinitializationoptions_getsrcpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*srcpixelFormat) | 获取源像素格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t srcpixelFormat) | 设置源像素格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*rowStride) | 获取行跨距。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetRowStride](#oh_pixelmapinitializationoptions_setrowstride) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t rowStride) | 设置图像跨距。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetAlphaType](#oh_pixelmapinitializationoptions_getalphatype) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*alphaType) | 获取透明度类型。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetAlphaType](#oh_pixelmapinitializationoptions_setalphatype) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t alphaType) | 设置透明度类型。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetEditable](#oh_pixelmapinitializationoptions_geteditable) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, bool \*editable) | 获取可编辑标志。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetEditable](#oh_pixelmapinitializationoptions_seteditable) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, bool editable) | 设置可编辑标志。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_Release](#oh_pixelmapinitializationoptions_release) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options) | 释放OH_Pixelmap_InitializationOptions指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_Create](#oh_pixelmapimageinfo_create) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*\*info) | 创建OH_Pixelmap_ImageInfo指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetWidth](#oh_pixelmapimageinfo_getwidth) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*width) | 获取图片宽。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetHeight](#oh_pixelmapimageinfo_getheight) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*height) | 获取图片高。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetRowStride](#oh_pixelmapimageinfo_getrowstride) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*rowStride) | 获取行跨距。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetPixelFormat](#oh_pixelmapimageinfo_getpixelformat) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, int32_t \*pixelFormat) | 获取像素格式。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetAlphaType](#oh_pixelmapimageinfo_getalphatype) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, int32_t \*alphaType) | 获取透明度类型。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetDynamicRange](#oh_pixelmapimageinfo_getdynamicrange) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, bool \*isHdr) | 获取Pixelmap是否为高动态范围的信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_Release](#oh_pixelmapimageinfo_release) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info) | 释放OH_Pixelmap_ImageInfo指针。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_CreatePixelmap](#oh_pixelmapnative_createpixelmap) (uint8_t \*data, size_t dataLength, [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | 通过属性创建PixelMap，默认采用BGRA_8888格式处理数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ConvertPixelmapNativeToNapi](#oh_pixelmapnative_convertpixelmapnativetonapi) (napi_env env, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmapNative, napi_value \*pixelmapNapi) | 将nativePixelMap对象转换为PixelMapnapi对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ConvertPixelmapNativeFromNapi](#oh_pixelmapnative_convertpixelmapnativefromnapi) (napi_env env, napi_value pixelmapNapi, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmapNative) | 将PixelMapnapi对象转换为nativePixelMap对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ReadPixels](#oh_pixelmapnative_readpixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | 读取图像像素数据，结果写入ArrayBuffer里。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_WritePixels](#oh_pixelmapnative_writepixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*source, size_t bufferSize) | 读取缓冲区中的图片数据，结果写入PixelMap中.  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetArgbPixels](#oh_pixelmapnative_getargbpixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | 从PixelMap中读取ARGB格式的数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ToSdr](#oh_pixelmapnative_tosdr) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap) | 将HDR的图像内容转换为SDR的图像内容。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetImageInfo](#oh_pixelmapnative_getimageinfo) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*imageInfo) | 获取图像像素信息。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Opacity](#oh_pixelmapnative_opacity) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float rate) | 通过设置透明比率来让PixelMap达到对应的透明效果。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Scale](#oh_pixelmapnative_scale) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY) | 根据输入的宽高对图片进行缩放。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ScaleWithAntiAliasing](#oh_pixelmapnative_scalewithantialiasing) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY, [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level) | 根据指定的缩放算法和输入的宽高对图片进行缩放。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_CreateScaledPixelMap](#oh_pixelmapnative_createscaledpixelmap) ([OH_PixelmapNative](#oh_pixelmapnative) \*srcPixelmap, [OH_PixelmapNative](#oh_pixelmapnative) \*\*dstPixelmap, float scaleX, float scaleY) | 根据输入的宽高的缩放比例，创建一个新的缩放后的图片。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing](#oh_pixelmapnative_createscaledpixelmapwithantialiasing) ([OH_PixelmapNative](#oh_pixelmapnative) \*srcPixelmap, [OH_PixelmapNative](#oh_pixelmapnative) \*\*dstPixelmap, float scaleX, float scaleY, [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level) | 根据指定的缩放算法和输入的宽高的缩放比例，创建一个新的缩放后的图片。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Translate](#oh_pixelmapnative_translate) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float x, float y) | 根据输入的坐标对图片进行位置变换。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Rotate](#oh_pixelmapnative_rotate) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float angle) | 根据输入的角度对图片进行旋转。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Flip](#oh_pixelmapnative_flip) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically) | 根据输入的条件对图片进行翻转。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Crop](#oh_pixelmapnative_crop) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [Image_Region](_image___region.md) \*region) | 根据输入的尺寸对图片进行裁剪  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Release](#oh_pixelmapnative_release) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap) | 释放OH_PixelmapNative指针，推荐使用 [OH_PixelmapNative_Destroy](#oh_pixelmapnative_destroy)。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Destroy](#oh_pixelmapnative_destroy) (OH_PixelmapNative \*\*pixelmap) | 释放OH_PixelmapNative指针。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ConvertAlphaFormat](#oh_pixelmapnative_convertalphaformat) ([OH_PixelmapNative](#oh_pixelmapnative) \*srcpixelmap, [OH_PixelmapNative](#oh_pixelmapnative) \*dstpixelmap, const bool isPremul) | 将pixlemap的像素数据做预乘和非预乘之间的转换。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_CreateEmptyPixelmap](#oh_pixelmapnative_createemptypixelmap) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | 利用OH_Pixelmap_InitializationOptions创建空的pixelmap对象，内存数据为0。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetNativeBuffer](#oh_pixelmapnative_getnativebuffer) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, OH_NativeBuffer \*\*nativeBuffer) | 从DMA内存的PixelMap中，获取NativeBuffer对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key, [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) \*\*value) | 获取元数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key, [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) \*value) | 设置元数据。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_SetColorSpaceNative](#oh_pixelmapnative_setcolorspacenative) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*colorSpaceNative) | 设置NativeColorSpaceManager对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetColorSpaceNative](#oh_pixelmapnative_getcolorspacenative) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_NativeColorSpaceManager](#oh_nativecolorspacemanager) \*\*colorSpaceNative) | 获取NativeColorSpaceManager对象。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_SetMemoryName](#oh_pixelmapnative_setmemoryname) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, char \*name, size_t \*size) | 设置pixelMap内存名字。  | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint32_t \*byteCount) | 获取Pixelmap中所有像素所占用的总字节数，不包含内存填充。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetAllocationByteCount](#oh_pixelmapnative_getallocationbytecount) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint32_t \*allocationByteCount) | 获取Pixelmap用于储存像素数据的内存字节数。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_AccessPixels](#oh_pixelmapnative_accesspixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, void \*\*addr) | 获取Pixelmap像素数据的内存地址，并锁定这块内存。<br/>当该内存被锁定时，任何修改或释放该Pixelmap的像素数据的操作均会失败或无效。 | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_UnaccessPixels](#oh_pixelmapnative_unaccesspixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap) | 释放Pixelmap像素数据的内存锁。<br/>该函数需要与[OH_PixelmapNative_AccessPixels](#oh_pixelmapnative_accesspixels)匹配使用。 | 


### 变量

| 名称 | 描述 | 
| -------- | -------- |
| static const char \*[MIME_TYPE_BMP](#mime_type_bmp) = "image/bmp" | bmp图片格式。 | 
| static const char \*[MIME_TYPE_JPEG](#mime_type_jpeg) = "image/jpeg" | jpeg图片格式。 | 
| static const char \*[MIME_TYPE_HEIC](#mime_type_heic) = "image/heic" | heic图片格式。 | 
| static const char \*[MIME_TYPE_PNG](#mime_type_png) = "image/png" | png图片格式。 | 
| static const char \*[MIME_TYPE_WEBP](#mime_type_webp) = "image/webp" | webp图片格式。 | 
| static const char \*[MIME_TYPE_GIF](#mime_type_gif) = "image/gif" | gif图片格式。 | 
| static const char \*[MIME_TYPE_ICON](#mime_type_icon) = "image/x-icon" | ico图片格式。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](#ohos_image_property_bits_per_sample) = "BitsPerSample" | 每个像素比特数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_ORIENTATION](#ohos_image_property_orientation) = "Orientation" | 图片方向。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](#ohos_image_property_image_length) = "ImageLength" | 图片长度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](#ohos_image_property_image_width) = "ImageWidth" | 图片宽度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE](#ohos_image_property_gps_latitude) = "GPSLatitude" | 图片纬度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](#ohos_image_property_gps_longitude) = "GPSLongitude" | 图片经度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | 纬度引用，例如N或S。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | 经度引用，例如W或E。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](#ohos_image_property_date_time_original) = "DateTimeOriginal" | 拍摄时间，例如2022:09:06 15:48:00。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](#ohos_image_property_exposure_time) = "ExposureTime" | 曝光时间，例如1/33 sec。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_TYPE](#ohos_image_property_scene_type) = "SceneType" | 拍摄场景模式，例如人像、风光、运动、夜景等。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | ISO感光度，例如400。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_F_NUMBER](#ohos_image_property_f_number) = "FNumber" | 光圈值，例如f/1.8。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | 用于压缩图像的压缩模式，单位为每像素位数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSION](#ohos_image_property_compression) = "Compression" | 图像压缩方案。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION](#ohos_image_property_photometric_interpretation) = "PhotometricInterpretation" | 像素构成，例如RGB或YCbCr。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_OFFSETS](#ohos_image_property_strip_offsets) = "StripOffsets" | 每个strip的字节偏移量。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL](#ohos_image_property_samples_per_pixel) = "SamplesPerPixel" | 每个像素的分量数。由于该标准适用于 RGB 和 YCbCr 图像，因此该标签的值设置为 3。 在JPEG压缩数据中，使用JPEG标记代替该标签。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP](#ohos_image_property_rows_per_strip) = "RowsPerStrip" | 每个strip的图像数据行数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS](#ohos_image_property_strip_byte_counts) = "StripByteCounts" | 每个图像数据带的总字节数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_X_RESOLUTION](#ohos_image_property_x_resolution) = "XResolution" | 图像宽度方向的分辨率。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_Y_RESOLUTION](#ohos_image_property_y_resolution) = "YResolution" | 图像高度方向的分辨率。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION](#ohos_image_property_planar_configuration) = "PlanarConfiguration" | 表示像素组件的记录格式，chunky格式或是planar格式。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT](#ohos_image_property_resolution_unit) = "ResolutionUnit" | 用于测量XResolution和YResolution的单位。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION](#ohos_image_property_transfer_function) = "TransferFunction" | 图像的传递函数，通常用于颜色校正。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOFTWARE](#ohos_image_property_software) = "Software" | 用于生成图像的软件的名称和版本。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_ARTIST](#ohos_image_property_artist) = "Artist" | 创建图像的用户名称。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_WHITE_POINT](#ohos_image_property_white_point) = "WhitePoint" | 图像的白点色度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES](#ohos_image_property_primary_chromaticities) = "PrimaryChromaticities" | 图像的主要颜色的色度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS](#ohos_image_property_ycbcr_coefficients) = "YCbCrCoefficients" | 从RGB到YCbCr图像数据的转换矩阵系数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING](#ohos_image_property_ycbcr_sub_sampling) = "YCbCrSubSampling" | 色度分量与亮度分量的采样比率。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING](#ohos_image_property_ycbcr_positioning) = "YCbCrPositioning" | 色度分量相对于亮度分量的位置。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE](#ohos_image_property_reference_black_white) = "ReferenceBlackWhite" | 参考黑点值和参考白点值。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_COPYRIGHT](#ohos_image_property_copyright) = "Copyright" | 图像的版权信息。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT](#ohos_image_property_jpeg_interchange_format) = "JPEGInterchangeFormat" | JPEG压缩缩略图数据开始字节（SOI）的偏移。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH](#ohos_image_property_jpeg_interchange_format_length) = "JPEGInterchangeFormatLength" | JPEG压缩缩略图数据的字节数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM](#ohos_image_property_exposure_program) = "ExposureProgram" | 拍照时相机用来设置曝光的程序的类别。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY](#ohos_image_property_spectral_sensitivity) = "SpectralSensitivity" | 表示所用相机的每个通道的光谱灵敏度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_OECF](#ohos_image_property_oecf) = "OECF" | 表示ISO 14524中规定的光电转换函数（OECF）。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXIF_VERSION](#ohos_image_property_exif_version) = "ExifVersion" | 支持的Exif标准版本。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED](#ohos_image_property_date_time_digitized) = "DateTimeDigitized" | 图像作为数字数据存储的日期和时间，格式为YYYY:MM:DD HH:MM:SS。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION](#ohos_image_property_components_configuration) = "ComponentsConfiguration" | 压缩数据的特定信息。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE](#ohos_image_property_shutter_speed_value) = "ShutterSpeedValue" | 快门速度，以APEX（摄影曝光的加法系统）值表示。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE](#ohos_image_property_brightness_value) = "BrightnessValue" | 图像的亮度值，以APEX单位表示。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE](#ohos_image_property_max_aperture_value) = "MaxApertureValue" | 最小F数镜头。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE](#ohos_image_property_subject_distance) = "SubjectDistance" | 测量单位为米的主体距离。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_AREA](#ohos_image_property_subject_area) = "SubjectArea" | 该标签指示整个场景中主要主体的位置和区域。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_MAKER_NOTE](#ohos_image_property_maker_note) = "MakerNote" | Exif/DCF制造商使用的标签，用于记录任何所需信息。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME](#ohos_image_property_subsec_time) = "SubsecTime" | 用于为DateTime标签记录秒的分数的标签。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL](#ohos_image_property_subsec_time_original) = "SubsecTimeOriginal" | 用于为DateTimeOriginal标签记录秒的分数的标签。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED](#ohos_image_property_subsec_time_digitized) = "SubsecTimeDigitized" | 用于为DateTimeDigitized标签记录秒的分数的标签。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION](#ohos_image_property_flashpix_version) = "FlashpixVersion" | 该标签表示FPXR文件支持的Flashpix格式版本，增强了设备兼容性。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_COLOR_SPACE](#ohos_image_property_color_space) = "ColorSpace" | 色彩空间信息标签，通常记录为色彩空间指定符。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE](#ohos_image_property_related_sound_file) = "RelatedSoundFile" | 与图像数据相关的音频文件的名称。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASH_ENERGY](#ohos_image_property_flash_energy) = "FlashEnergy" | 图像捕获时的闪光能量，以BCPS表示。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE](#ohos_image_property_spatial_frequency_response) = "SpatialFrequencyResponse" | 相机或输入设备的空间频率表。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION](#ohos_image_property_focal_plane_x_resolution) = "FocalPlaneXResolution" | 图像宽度中每FocalPlaneResolutionUnit的像素。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION](#ohos_image_property_focal_plane_y_resolution) = "FocalPlaneYResolution" | 图像高度中每FocalPlaneResolutionUnit的像素。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT](#ohos_image_property_focal_plane_resolution_unit) = "FocalPlaneResolutionUnit" | 测量FocalPlaneXResolution和FocalPlaneYResolution的单位。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION](#ohos_image_property_subject_location) = "SubjectLocation" | 主要对象相对于左边缘的位置。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX](#ohos_image_property_exposure_index) = "ExposureIndex" | 捕获时选定的曝光指数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SENSING_METHOD](#ohos_image_property_sensing_method) = "SensingMethod" | 相机上的图像传感器类型。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FILE_SOURCE](#ohos_image_property_file_source) = "FileSource" | 表明图像来源。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_CFA_PATTERN](#ohos_image_property_cfa_pattern) = "CFAPattern" | 图像传感器的色彩滤光片（CFA）几何图案。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED](#ohos_image_property_custom_rendered) = "CustomRendered" | 指示图像数据上的特殊处理。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_MODE](#ohos_image_property_exposure_mode) = "ExposureMode" | 拍摄时设置的曝光模式。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO](#ohos_image_property_digital_zoom_ratio) = "DigitalZoomRatio" | 捕获时的数字变焦比率。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE](#ohos_image_property_scene_capture_type) = "SceneCaptureType" | 捕获的场景类型。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GAIN_CONTROL](#ohos_image_property_gain_control) = "GainControl" | 整体图像增益调整的程度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_CONTRAST](#ohos_image_property_contrast) = "Contrast" | 相机应用的对比度处理方向。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SATURATION](#ohos_image_property_saturation) = "Saturation" | 相机应用的饱和度处理方向。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SHARPNESS](#ohos_image_property_sharpness) = "Sharpness" | 相机应用的锐度处理方向。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION](#ohos_image_property_device_setting_description) = "DeviceSettingDescription" | 特定相机模型的拍照条件信息。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE](#ohos_image_property_subject_distance_range) = "SubjectDistanceRange" | 表示主体到相机的距离范围。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID](#ohos_image_property_image_unique_id) = "ImageUniqueID" | 为每张图片唯一分配的标识符。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_VERSION_ID](#ohos_image_property_gps_version_id) = "GPSVersionID" | GPSInfoIFD的版本。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF](#ohos_image_property_gps_altitude_ref) = "GPSAltitudeRef" | 用于GPS高度的参照高度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE](#ohos_image_property_gps_altitude) = "GPSAltitude" | 基于GPSAltitudeRef的高度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SATELLITES](#ohos_image_property_gps_satellites) = "GPSSatellites" | 用于测量的GPS卫星。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_STATUS](#ohos_image_property_gps_status) = "GPSStatus" | 录制图像时GPS接收器的状态。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE](#ohos_image_property_gps_measure_mode) = "GPSMeasureMode" | GPS测量模式。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DOP](#ohos_image_property_gps_dop) = "GPSDOP" | GPS DOP（数据精度等级）。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED_REF](#ohos_image_property_gps_speed_ref) = "GPSSpeedRef" | 用来表示GPS接收器移动速度的单位。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED](#ohos_image_property_gps_speed) = "GPSSpeed" | GPS接收器的移动速度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK_REF](#ohos_image_property_gps_track_ref) = "GPSTrackRef" | GPS接收机移动方向的参照。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK](#ohos_image_property_gps_track) = "GPSTrack" | GPS接收机的移动方向。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF](#ohos_image_property_gps_img_direction_ref) = "GPSImgDirectionRef" | 图像方向的参照。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION](#ohos_image_property_gps_img_direction) = "GPSImgDirection" | 拍摄时图像的方向。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM](#ohos_image_property_gps_map_datum) = "GPSMapDatum" | GPS接收器使用的大地测量数据。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF](#ohos_image_property_gps_dest_latitude_ref) = "GPSDestLatitudeRef" | 目的地点的纬度参照。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE](#ohos_image_property_gps_dest_latitude) = "GPSDestLatitude" | 目的地点的纬度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF](#ohos_image_property_gps_dest_longitude_ref) = "GPSDestLongitudeRef" | 目的地点的经度参照。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD](#ohos_image_property_gps_processing_method) = "GPSProcessingMethod" | 记录定位方法名的字符字符串。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION](#ohos_image_property_gps_area_information) = "GPSAreaInformation" | 记录GPS区域名的字符字符串。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL](#ohos_image_property_gps_differential) = "GPSDifferential" | 此字段表示GPS数据是否应用了差分校正，对于精确的位置准确性至关重要。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER](#ohos_image_property_body_serial_number) = "BodySerialNumber" | 相机机身的序列号。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME](#ohos_image_property_camera_owner_name) = "CameraOwnerName" | 相机所有者的姓名。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE](#ohos_image_property_composite_image) = "CompositeImage" | 表示图像是否为合成图像。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_DNG_VERSION](#ohos_image_property_dng_version) = "DNGVersion" | DNG版本标签编码了符合DNG规范的四级版本号。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE](#ohos_image_property_gps_dest_longitude) = "GPSDestLongitude" | 目的地点的经度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF](#ohos_image_property_gps_dest_bearing_ref) = "GPSDestBearingRef" | 指向目的地点的方位参照。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING](#ohos_image_property_gps_dest_bearing) = "GPSDestBearing" | 目的地方位。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF](#ohos_image_property_gps_dest_distance_ref) = "GPSDestDistanceRef" | 目标点距离的测量单位。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE](#ohos_image_property_gps_dest_distance) = "GPSDestDistance" | 到目的地点的距离。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE](#ohos_image_property_default_crop_size) = "DefaultCropSize" | DefaultCropSize指定了原始坐标中的最终图像大小，考虑了额外的边缘像素。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GAMMA](#ohos_image_property_gamma) = "Gamma" | 表示系数伽马的值。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY](#ohos_image_property_iso_speed_latitudeyyy) = "ISOSpeedLatitudeyyy" | 该标签指示摄像机或输入设备的ISO速度纬度yyy值，该值在ISO 12232中定义。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ](#ohos_image_property_iso_speed_latitudezzz) = "ISOSpeedLatitudezzz" | 该标签指示摄像机或输入设备的ISO速度纬度zzz值，该值在ISO 12232中定义。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MAKE](#ohos_image_property_lens_make) = "LensMake" | 镜头的制造商。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MODEL](#ohos_image_property_lens_model) = "LensModel" | 镜头的型号名称。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER](#ohos_image_property_lens_serial_number) = "LensSerialNumber" | 镜头的序列号。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION](#ohos_image_property_lens_specification) = "LensSpecification" | 使用的镜头规格。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE](#ohos_image_property_new_subfile_type) = "NewSubfileType" | 在Exif中，"NewSubfileType"字段用于标识子文件的数据类型，如全分辨率图像、缩略图或多帧图像的一部分。 其值是位掩码，0代表全分辨率图像，1代表缩略图，2代表多帧图像的一部分。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME](#ohos_image_property_offset_time) = "OffsetTime" | 在Exif中，OffsetTime字段表示与UTC（协调世界时）的时间偏移，格式为±HH:MM，用于确定照片拍摄的本地时间。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED](#ohos_image_property_offset_time_digitized) = "OffsetTimeDigitized" | 此标签记录图像数字化时的UTC偏移量，有助于准确调整时间戳。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL](#ohos_image_property_offset_time_original) = "OffsetTimeOriginal" | 此标签记录原始图像创建时的UTC偏移量，对于时间敏感的应用至关重要。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE](#ohos_image_property_source_exposure_times_of_composite_image) = "SourceExposureTimesOfCompositeImage" | 合成图像的源图像曝光时间。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE](#ohos_image_property_source_image_number_of_composite_image) = "SourceImageNumberOfCompositeImage" | 用于合成图像的源图像数量。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBFILE_TYPE](#ohos_image_property_subfile_type) = "SubfileType" | 此标签指示此子文件中的数据类型。标签已弃用，请使用NewSubfileType替代。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR](#ohos_image_property_gps_h_positioning_error) = "GPSHPositioningError" | 此标签指示水平定位误差，单位为米。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY](#ohos_image_property_photographic_sensitivity) = "PhotographicSensitivity" | 此标签指示拍摄图像时相机或输入设备的灵敏度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_BURST_NUMBER](#ohos_image_property_burst_number) = "HwMnoteBurstNumber" | 连拍次数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_CONF](#ohos_image_property_face_conf) = "HwMnoteFaceConf" | 人脸置信度。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER](#ohos_image_property_face_leye_center) = "HwMnoteFaceLeyeCenter" | 左眼中心。被用于 [OH_ImageSource_GetImageProperty](#oh_imagesourcenative_getimageproperty) 和 [OH_ImageSource_ModifyImageProperty](#oh_imagesourcenative_modifyimageproperty)。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER](#ohos_image_property_face_mouth_center) = "HwMnoteFaceMouthCenter" | 嘴中心。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_POINTER](#ohos_image_property_face_pointer) = "HwMnoteFacePointer" | 脸部指针。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_RECT](#ohos_image_property_face_rect) = "HwMnoteFaceRect" | 脸部矩形。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER](#ohos_image_property_face_reye_center) = "HwMnoteFaceReyeCenter" | 右眼中心。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE](#ohos_image_property_face_smile_score) = "HwMnoteFaceSmileScore" | FaceCount张人脸的笑脸分数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_VERSION](#ohos_image_property_face_version) = "HwMnoteFaceVersion" | 人脸算法版本信息。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRONT_CAMERA](#ohos_image_property_front_camera) = "HwMnoteFrontCamera" | 是否是前置相机自拍。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_POINTER](#ohos_image_property_scene_pointer) = "HwMnoteScenePointer" | 场景指针。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_VERSION](#ohos_image_property_scene_version) = "HwMnoteSceneVersion" | 场景算法版本信息。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT](#ohos_image_property_gif_loop_count) = "GIFLoopCount" | GIF图片循环次数。 | 
| static const char \*[OHOS_IMAGE_PROPERTY_X_IN_ORIGINAL](#ohos_image_property_x_in_original) = "XInOriginal" | 水印裁剪图左上角在原始图中的X坐标。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_Y_IN_ORIGINAL](#ohos_image_property_y_in_original) = "YInOriginal" | 水印裁剪图左上角在原始图中的Y坐标。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRAGMENT_WIDTH](#ohos_image_property_fragment_width) = "FragmentImageWidth"| 水印裁剪图的宽。  | 
| static const char \*[OHOS_IMAGE_PROPERTY_FRAGMENT_HEIGHT](#ohos_image_property_fragment_height) = "FragmentImageHeight" | 水印裁剪图的高。  | 


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


### OH_AuxiliaryPictureInfo

```
typedef struct OH_AuxiliaryPictureInfo OH_AuxiliaryPictureInfo
```
**描述**
AuxiliaryPictureInfo结构体类型，用于执行AuxiliaryPictureInfo相关操作。

**起始版本：** 13


### OH_AuxiliaryPictureNative

```
typedef struct OH_AuxiliaryPictureNative OH_AuxiliaryPictureNative
```
**描述**
AuxiliaryPicture结构体类型，用于执行AuxiliaryPicture相关操作。

**起始版本：** 13


### OH_DecodingOptions

```
typedef struct OH_DecodingOptions OH_DecodingOptions
```
**描述**
解码选项参数结构体,被用于选项参数结构体,被用于[OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap)。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_DecodingOptions结构体介绍](../../media/image/image-structure-c.md#oh_decodingoptions结构体)。

**起始版本：** 12


### OH_ImageNative

```
typedef struct OH_ImageNative OH_ImageNative
```
**描述**
为图像接口定义native层图像对象的别名。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_ImageNative结构体介绍](../../media/image/image-structure-c.md#oh_imagenative结构体)。

**起始版本：** 12


### OH_ImagePackerNative

```
typedef struct OH_ImagePackerNative OH_ImagePackerNative
```
**描述**
ImagePacker结构体类型，用于执行ImagePacker相关操作。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_ImagePackerNative结构体介绍](../../media/image/image-structure-c.md#oh_imagepackernative结构体)。

**起始版本：** 12


### OH_ImageReceiver_OnCallback

```
typedef void(* OH_ImageReceiver_OnCallback) (OH_ImageReceiverNative *receiver)
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

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_ImageReceiverNative结构体介绍](../../media/image/image-structure-c.md#oh_imagereceivernative结构体)。

**起始版本：** 12


### OH_ImageReceiverOptions

```
typedef struct OH_ImageReceiverOptionsOH_ImageReceiverOptions
```
**描述**
用于定义OH_ImageReceiverOptions数据类型名称。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_ImageReceiverOptions结构体介绍](../../media/image/image-structure-c.md#oh_imagereceiveroptions结构体)。

**起始版本：** 12


### OH_ImageSource_Info

```
typedef struct OH_ImageSource_Info OH_ImageSource_Info
```
**描述**
图片源信息结构体 [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create)。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_ImageSource_Info结构体介绍](../../media/image/image-structure-c.md#oh_imagesource_info结构体)。

**起始版本：** 12


### OH_ImageSourceNative

```
typedef struct OH_ImageSourceNative OH_ImageSourceNative
```
**描述**
ImageSource结构体类型，用于执行ImageSource相关操作。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_ImageSourceNative结构体介绍](../../media/image/image-structure-c.md#oh_imagesourcenative结构体)。

**起始版本：** 12


### OH_NativeColorSpaceManager

```
typedef struct OH_NativeColorSpaceManager OH_NativeColorSpaceManager
```
**描述**
NativeColorSpaceManager结构体类型，用于执行NativeColorSpaceManager相关操作。

**起始版本：** 13


### OH_PackingOptions

```
typedef struct OH_PackingOptions OH_PackingOptions
```
**描述**
图像编码选项。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_PackingOptions结构体介绍](../../media/image/image-structure-c.md#oh_packingoptions结构体)。

**起始版本：** 12


### OH_PackingOptionsForSequence

```
typedef struct OH_PackingOptionsForSequence OH_PackingOptionsForSequence
```
**描述**
图像序列编码选项。

**起始版本：** 13


### OH_PictureMetadata

```
typedef struct OH_PictureMetadata OH_PictureMetadata
```
**描述**
声明用于Picture的元数据。

**起始版本：** 13


### OH_PictureNative

```
typedef struct OH_PictureNativeOH_PictureNative
```
**描述**
Picture结构体类型，用于执行picture相关操作。

**起始版本：** 13


### OH_Pixelmap_HdrDynamicMetadata

```
typedef struct OH_Pixelmap_HdrDynamicMetadata OH_Pixelmap_HdrDynamicMetadata
```
**描述**
DR_DYNAMIC_METADATA关键字对应的动态元数据值。

**起始版本：** 12


### OH_Pixelmap_HdrGainmapMetadata

```
typedef struct OH_Pixelmap_HdrGainmapMetadata OH_Pixelmap_HdrGainmapMetadata
```
**描述**
HDR_GAINMAP_METADATA关键字对应的gainmap相关元数据值，参考ISO 21496-1。

**起始版本：** 12


### OH_Pixelmap_HdrMetadataValue

```
typedef struct OH_Pixelmap_HdrMetadataValue OH_Pixelmap_HdrMetadataValue
```
**描述**
Pixelmap使用的HDR元数据值，和OH_Pixelmap_HdrMetadataKey关键字相对应。

用于[OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata)，有相应[OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey)关键字作为入参时，设置或获取到本结构体中相对应的元数据类型的值。

**起始版本：** 12


### OH_Pixelmap_HdrStaticMetadata

```
typedef struct OH_Pixelmap_HdrStaticMetadata OH_Pixelmap_HdrStaticMetadata
```
**描述**
HDR_STATIC_METADATA关键字对应的静态元数据值。

**起始版本：** 12


### OH_Pixelmap_ImageInfo

```
typedef struct OH_Pixelmap_ImageInfo OH_Pixelmap_ImageInfo
```
**描述**
图像像素信息结构体。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_Pixelmap_ImageInfo结构体介绍](../../media/image/image-structure-c.md#oh_pixelmap_imageinfo结构体)。

**起始版本：** 12


### OH_Pixelmap_InitializationOptions

```
typedef struct OH_Pixelmap_InitializationOptions OH_Pixelmap_InitializationOptions
```
**描述**
初始化参数结构体。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_Pixelmap_InitializationOptions结构体介绍](../../media/image/image-structure-c.md#oh_pixelmap_initializationoptions结构体)。

**起始版本：** 12


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```
**描述**
Pixelmap结构体类型，用于执行Pixelmap相关操作。

此结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式请参考[OH_PixelmapNative结构体介绍](../../media/image/image-structure-c.md#oh_pixelmapnative结构体)。

**起始版本：** 12


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```
**描述**
NativeBuffer结构体类型，用于执行NativeBuffer相关操作。


**起始版本：** 12


## 枚举类型说明


### IMAGE_ALLOCATOR_TYPE

```
enum IMAGE_ALLOCATOR_TYPE
```

**描述**

用于分配 PixelMap 内存的分配器类型。

**起始版本：** 15

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_ALLOCATOR_TYPE_AUTO | 由系统决定使用DMA内存或共享内存来创建 PixelMap。 | 
| IMAGE_ALLOCATOR_TYPE_DMA | 使用 DMA 内存来创建 PixelMap。 | 
| IMAGE_ALLOCATOR_TYPE_SHARE_MEMORY | 使用共享内存来创建 PixelMap。 | 


### Image_AuxiliaryPictureType

```
enum Image_AuxiliaryPictureType
```
**描述**
辅助图类型。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| AUXILIARY_PICTURE_TYPE_GAINMAP  | 增益图，代表了一种增强SDR图像以产生具有可变显示调整能力的HDR图像的机制。它是一组描述如何应用gainmap元数据的组合。   | 
| AUXILIARY_PICTURE_TYPE_DEPTH_MAP  | 深度图，储存图像的深度数据，通过捕捉每个像素与摄像机之间的距离，提供场景的三维结构信息，通常用于3D重建和场景理解。   | 
| AUXILIARY_PICTURE_TYPE_UNREFOCUS_MAP  | 人像未对焦的原图，提供了一种在人像拍摄中突出背景模糊效果的方式，能够帮助用户在后期处理中选择焦点区域，增加创作自由度。   | 
| AUXILIARY_PICTURE_TYPE_LINEAR_MAP  | 线性图，用于提供额外的数据视角或补充信息，通常用于视觉效果的增强，它可以包含场景中光照、颜色或其他视觉元素的线性表示。   | 
| AUXILIARY_PICTURE_TYPE_FRAGMENT_MAP  | 水印裁剪图，表示在原图中被水印覆盖的区域，该图像用于修复或移除水印影响，恢复图像的完整性和可视性。   | 


### IMAGE_DYNAMIC_RANGE

```
enum IMAGE_DYNAMIC_RANGE
```
**描述**
解码指定期望动态范围。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_DYNAMIC_RANGE_AUTO  | 根据图片自适应处理。   | 
| IMAGE_DYNAMIC_RANGE_SDR  | 标准动态范围。   | 
| IMAGE_DYNAMIC_RANGE_HDR  | 高动态范围。   | 


### Image_ErrorCode

```
enum Image_ErrorCode
```
**描述**
错误码。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_SUCCESS  | 操作成功。 | 
| IMAGE_BAD_PARAMETER  | 无效参数。 | 
| IMAGE_UNSUPPORTED_MIME_TYPE  | 不支持的MIME类型。 | 
| IMAGE_UNKNOWN_MIME_TYPE  | 未知的MIME类型。 | 
| IMAGE_TOO_LARGE  | 过大的数据或图片。 | 
| IMAGE_DMA_NOT_EXIST  | 内存不是DMA内存。 | 
| IMAGE_DMA_OPERATION_FAILED  | DMA内存操作失败。 | 
| IMAGE_UNSUPPORTED_OPERATION  | 不支持的操作。 | 
| IMAGE_UNSUPPORTED_METADATA  | 不支持的 metadata。 | 
| IMAGE_UNSUPPORTED_CONVERSION  | 不支持的转换。 | 
| IMAGE_INVALID_REGION  | 无效区域。 | 
| IMAGE_UNSUPPORTED_MEMORY_FORMAT  | 不支持的内存格式。<br/>**起始版本：** 13 | 
| IMAGE_ALLOC_FAILED  | 申请内存失败。 | 
| IMAGE_COPY_FAILED  | 内存拷贝失败。 | 
| IMAGE_LOCK_UNLOCK_FAILED | 内存加锁或解锁失败。<br/>**起始版本：** 15 | 
| IMAGE_UNKNOWN_ERROR  | 未知错误。 | 
| IMAGE_BAD_SOURCE | 解码数据源异常。 | 
| IMAGE_SOURCE_UNSUPPORTED_MIME_TYPE | 不支持的 MIME 类型。<br/>**起始版本：** 15 | 
| IMAGE_SOURCE_TOO_LARGE | 图像过大。<br/>**起始版本：** 15 | 
| IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE | 不支持的分配器类型。例如，DMA支持HDR元数据，可以使用共享内存解码HDR图像。<br/>**起始版本：** 15 | 
| IMAGE_SOURCE_UNSUPPORTED_OPTIONS | 不支持的选项。例如，无法将图像转换为所需的像素格式。<br/>**起始版本：** 15 | 
| IMAGE_DECODE_FAILED | 解码失败。 | 
| IMAGE_SOURCE_ALLOC_FAILED | 内存申请失败。<br/>**起始版本：** 15 | 
| IMAGE_ENCODE_FAILED | 编码失败。 | 


### Image_MetadataType

```
enum Image_MetadataType
```
**描述**
定义元数据类型。

**起始版本：** 13

| 枚举值 | 描述 | 
| -------- | -------- |
| EXIF_METADATA  | EXIF元数据。   | 
| FRAGMENT_METADATA  | 水印裁剪图元数据。   | 


### IMAGE_PACKER_DYNAMIC_RANGE

```
enum IMAGE_PACKER_DYNAMIC_RANGE
```
**描述**
编码指定动态范围。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| IMAGE_PACKER_DYNAMIC_RANGE_AUTO  | 编码动态范围根据图像信息自适应。   | 
| IMAGE_PACKER_DYNAMIC_RANGE_SDR  | 编码图片为标准动态范围。   | 


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
| PIXEL_FORMAT_RGBA_1010102 | RGBA_1010102 格式 | 
| PIXEL_FORMAT_YCBCR_P010 | YCBCR_P010 格式 | 
| PIXEL_FORMAT_YCRCB_P010 | YCRCB_P010 格式 | 


### OH_Pixelmap_HdrMetadataKey

```
enum OH_Pixelmap_HdrMetadataKey
```
**描述**
Pixelmap使用的HDR相关元数据信息的关键字，用于[OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata)。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HDR_METADATA_TYPE  | Pixelmap使用的元数据类型。   | 
| HDR_STATIC_METADATA  | 静态元数据。   | 
| HDR_DYNAMIC_METADATA  | 动态元数据。   | 
| HDR_GAINMAP_METADATA  | Gainmap使用的元数据。   | 


### OH_Pixelmap_HdrMetadataType

```
enum OH_Pixelmap_HdrMetadataType
```
**描述**
HDR_METADATA_TYPE关键字对应的值。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| HDR_METADATA_TYPE_NONE  | 无元数据内容。   | 
| HDR_METADATA_TYPE_BASE  | 表示用于基础图的元数据。   | 
| HDR_METADATA_TYPE_GAINMAP  | 表示用于Gainmap图的元数据。   | 
| HDR_METADATA_TYPE_ALTERNATE  | 表示用于合成后HDR图的元数据。   | 


### OH_PixelmapNative_AntiAliasingLevel

```
enum OH_PixelmapNative_AntiAliasingLevel
```
**描述**
Pixelmap缩放时采用的缩放算法。

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_PixelmapNative_AntiAliasing_NONE  | 最近邻插值算法。   | 
| OH_PixelmapNative_AntiAliasing_LOW  | 双线性插值算法。   | 
| OH_PixelmapNative_AntiAliasing_MEDIUM  | 双线性插值算法，同时开启Mipmap。缩小图片时建议使用。   | 
| OH_PixelmapNative_AntiAliasing_HIGH  | 三次插值算法。   | 


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
| PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED | 非预乘透明度格式 |


## 函数说明


### OH_AuxiliaryPictureInfo_Create()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_Create(OH_AuxiliaryPictureInfo **info)
```
**描述**
创建一个OH_AuxiliaryPictureInfo对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_GetPixelFormat()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT *pixelFormat)
```
**描述**
获取辅助图的图片信息的像素格式。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| pixelFormat | 获取的像素格式。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_GetRowStride()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t *rowStride)
```
**描述**
获取辅助图的图片信息的行跨距。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| rowStride | 跨距，内存中每行像素所占的空间。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_GetSize()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```
**描述**
获取辅助图的图片尺寸。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| size | 获取的图片尺寸。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_GetType()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_GetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType *type)
```
**描述**
获取辅助图的图片信息的辅助图类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| type | 获取的辅助图类型。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_Release()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_Release(OH_AuxiliaryPictureInfo *info)
```
**描述**
释放OH_AuxiliaryPictureInfo指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_SetPixelFormat()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetPixelFormat(OH_AuxiliaryPictureInfo *info, PIXEL_FORMAT pixelFormat)
```
**描述**
设置辅助图的图片信息的像素格式。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| pixelFormat | 将要设置的像素格式。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_SetRowStride()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetRowStride(OH_AuxiliaryPictureInfo *info, uint32_t rowStride)
```
**描述**
设置辅助图的图片信息的行跨距。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| rowStride | 跨距，内存中每行像素所占的空间。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_SetSize()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetSize(OH_AuxiliaryPictureInfo *info, Image_Size *size)
```
**描述**
设置辅助图的图片尺寸。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| size | 将要设置的图片尺寸。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureInfo_SetType()

```
Image_ErrorCode OH_AuxiliaryPictureInfo_SetType(OH_AuxiliaryPictureInfo *info, Image_AuxiliaryPictureType type)
```
**描述**
设置辅助图的图片信息的辅助图类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 将操作的OH_AuxiliaryPictureInfo指针。  | 
| type | 将要设置的辅助图类型。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_Create()

```
Image_ErrorCode OH_AuxiliaryPictureNative_Create(uint8_t *data, size_t dataLength, Image_Size *size, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)
```
**描述**
创建OH_AuxiliaryPictureNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 图像数据。  | 
| dataLength | 图像数据长度。  | 
| size | 辅助图尺寸。  | 
| type | 辅助图类型。  | 
| auxiliaryPicture | 被创建的OH_AuxiliaryPictureNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_GetInfo()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_AuxiliaryPictureInfo **info)
```
**描述**
获取辅助图信息。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。  | 
| info | 辅助图信息。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_GetMetadata()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_MetadataType metadataType, OH_PictureMetadata **metadata)
```
**描述**
获取辅助图的元数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| auxiliaryPicture | 将操作的OH_AuxiliaryPictureNative指针。  | 
| metadataType | 元数据类型。  | 
| metadata | 获取的元数据。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果是不支持的元数据类型，或者元数据类型与辅助图片类型不匹配返回 IMAGE_UNSUPPORTED_METADATA， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_GetType()

```
Image_ErrorCode OH_AuxiliaryPictureNative_GetType(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_AuxiliaryPictureType *type)
```
**描述**
获取辅助图类型。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。  | 
| type | 辅助图类型。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_ReadPixels()

```
Image_ErrorCode OH_AuxiliaryPictureNative_ReadPixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *destination, size_t *bufferSize)
```
**描述**
读取辅助图的像素数据，结果写入缓冲区。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。  | 
| destination | 缓冲区，获取的辅助图像素数据写入到该内存区域内。  | 
| bufferSize | 缓冲区大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果内存分配失败返回 IMAGE_ALLOC_FAILED，如果内存拷贝失败返回 IMAGE_COPY_FAILED， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_Release()

```
Image_ErrorCode OH_AuxiliaryPictureNative_Release(OH_AuxiliaryPictureNative *picture)
```
**描述**
释放OH_AuxiliaryPictureNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 将操作的OH_AuxiliaryPictureNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_SetInfo()

```
Image_ErrorCode OH_AuxiliaryPictureNative_SetInfo(OH_AuxiliaryPictureNative *auxiliaryPicture, OH_AuxiliaryPictureInfo *info)
```
**描述**
设置辅助图信息。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| auxiliaryPicture | 将操作的OH_AuxiliaryPictureNative指针。  | 
| info | 将要设置的辅助图信息。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_SetMetadata()

```
Image_ErrorCode OH_AuxiliaryPictureNative_SetMetadata(OH_AuxiliaryPictureNative *auxiliaryPicture, Image_MetadataType metadataType, OH_PictureMetadata *metadata)
```
**描述**
设置辅助图的元数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| auxiliaryPicture | 将操作的OH_AuxiliaryPictureNative指针。  | 
| metadataType | 元数据类型。  | 
| metadata | 将要设置的元数据。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果是不支持的元数据类型，或者元数据类型与辅助图片类型不匹配返回 IMAGE_UNSUPPORTED_METADATA， 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_AuxiliaryPictureNative_WritePixels()

```
Image_ErrorCode OH_AuxiliaryPictureNative_WritePixels(OH_AuxiliaryPictureNative *auxiliaryPicture, uint8_t *source, size_t bufferSize)
```
**描述**
读取缓冲区的图像像素数据，并将结果写入为辅助图中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| auxiliaryPicture | 被操作的OH_AuxiliaryPictureNative指针。  | 
| source | 将被写入的图像像素数据。  | 
| bufferSize | 图像像素数据长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果内存分配失败返回 IMAGE_ALLOC_FAILED，如果内存拷贝失败返回 IMAGE_COPY_FAILED， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_Create()

```
Image_ErrorCode OH_DecodingOptions_Create(OH_DecodingOptions **options)
```
**描述**
创建OH_DecodingOptions指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange(OH_DecodingOptions *options, int32_t *desiredDynamicRange)
```
**描述**
获取解码时设置的期望动态范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| desiredDynamicRange | 期望的动态范围值 [IMAGE_DYNAMIC_RANGE](#image_dynamic_range)。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)
```
**描述**
获取解码区域。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| desiredRegion | 解码区域。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)
```
**描述**
获取期望输出大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| desiredSize | 期望输出大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetIndex()

```
Image_ErrorCode OH_DecodingOptions_GetIndex(OH_DecodingOptions *options, uint32_t *index)
```
**描述**
获取解码图片序号。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| index | 解码图片序号。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_GetPixelFormat(OH_DecodingOptions *options, int32_t *pixelFormat)
```
**描述**
获取pixel格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| pixelFormat | pixel格式[PIXEL_FORMAT](#pixel_format)。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_GetRotate()

```
Image_ErrorCode OH_DecodingOptions_GetRotate(OH_DecodingOptions *options, float *rotate)
```
**描述**
获取旋转角度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| rotate | 旋转角度，单位为deg。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_Release()

```
Image_ErrorCode OH_DecodingOptions_Release(OH_DecodingOptions *options)
```
**描述**
释放OH_DecodingOptions指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange(OH_DecodingOptions *options, int32_t desiredDynamicRange)
```
**描述**
设置解码时的期望动态范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| desiredDynamicRange | 期望的动态范围值 [IMAGE_DYNAMIC_RANGE](#image_dynamic_range)。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_SetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredRegion(OH_DecodingOptions *options, Image_Region *desiredRegion)
```
**描述**
设置解码区域。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| desiredRegion | 解码区域。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_SetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredSize(OH_DecodingOptions *options, Image_Size *desiredSize)
```
**描述**
设置期望输出大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| desiredSize | 期望输出大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_SetIndex()

```
Image_ErrorCode OH_DecodingOptions_SetIndex(OH_DecodingOptions *options, uint32_t index)
```
**描述**
设置解码图片序号。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| index | 解码图片序号。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_SetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_SetPixelFormat(OH_DecodingOptions *options, int32_t pixelFormat)
```
**描述**
设置pixel格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| pixelFormat | pixel格式[PIXEL_FORMAT](#pixel_format)。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptions_SetRotate()

```
Image_ErrorCode OH_DecodingOptions_SetRotate(OH_DecodingOptions *options, float rotate)
```
**描述**
设置旋转角度。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的[OH_DecodingOptions](#oh_decodingoptions)指针。  | 
| rotate | 旋转角度，单位为deg。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptionsForPicture_Create()

```
Image_ErrorCode OH_DecodingOptionsForPicture_Create(OH_DecodingOptionsForPicture **options)
```
**描述**
创建OH_DecodingOptionsForPicture指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptionsForPicture指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures()

```
Image_ErrorCode OH_DecodingOptionsForPicture_GetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType **desiredAuxiliaryPictures, size_t *length)
```
**描述**
获取解码时设置的期望辅助图（期望解码出的picture包含的辅助图）。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptionsForPicture指针。  | 
| desiredAuxiliaryPictures | 解码选项中的期望辅助图。  | 
| length | 期望辅助图长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptionsForPicture_Release()

```
Image_ErrorCode OH_DecodingOptionsForPicture_Release(OH_DecodingOptionsForPicture *options)
```
**描述**
释放OH_DecodingOptionsForPicture指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 要释放的OH_DecodingOptionsForPicture指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures()

```
Image_ErrorCode OH_DecodingOptionsForPicture_SetDesiredAuxiliaryPictures(OH_DecodingOptionsForPicture *options, Image_AuxiliaryPictureType *desiredAuxiliaryPictures, size_t length)
```
**描述**
设置解码选项中的期望辅助图。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_DecodingOptionsForPicture指针  | 
| desiredAuxiliaryPictures | 将要设置的期望辅助图。  | 
| length | 期望辅助图长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_GetBufferSize()

```
Image_ErrorCode OH_ImageNative_GetBufferSize(OH_ImageNative *image, uint32_t componentType, size_t *size)
```
**描述**
获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的缓冲区的大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 
| componentType | 表示组件的类型。  | 
| size | 表示作为获取结果的缓冲区大小的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_GetByteBuffer()

```
Image_ErrorCode OH_ImageNative_GetByteBuffer(OH_ImageNative *image, uint32_t componentType, OH_NativeBuffer **nativeBuffer)
```
**描述**
获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的缓冲区。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 
| componentType | 表示组件的类型。  | 
| nativeBuffer | 表示作为获取结果的 **OH_NativeBuffer** 缓冲区对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_GetComponentTypes()

```
Image_ErrorCode OH_ImageNative_GetComponentTypes(OH_ImageNative *image, uint32_t **types, size_t *typeSize)
```
**描述**
获取Native [OH_ImageNative](#oh_imagenative) 对象的组件列表信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 
| types | 表示作为获取结果的组件列表对象的指针。  | 
| typeSize | 表示作为获取结果的组件列表中，元素个数的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_GetImageSize()

```
Image_ErrorCode OH_ImageNative_GetImageSize(OH_ImageNative *image, Image_Size *size)
```
**描述**
获取Native [OH_ImageNative](#oh_imagenative) 对象的 [Image_Size](_image___size.md) 信息。如果[OH_ImageNative](#oh_imagenative) 对象所存储的是相机预览流数据，即YUV图像数据，那么获取到的[Image_Size](_image___size.md)中的宽高分别对应YUV图像的宽高；如果[OH_ImageNative](#oh_imagenative) 对象所存储的是相机拍照流数据，即JPEG图像，由于已经是编码后的数据，[Image_Size](_image___size.md)中的宽等于JPEG数据大小，高等于1。[OH_ImageNative](#oh_imagenative) 对象所存储的数据是预览流还是拍照流，取决于应用将receiver中的surfaceId传给相机的previewOutput还是captureOutput。相机预览与拍照最佳实践请参考[预览流二次处理(C/C++)](../../media/camera/native-camera-preview-imageReceiver.md)与[拍照(C/C++)](../../media/camera/native-camera-shooting.md)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 
| size | 表示作为获取结果的 [Image_Size](_image___size.md) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_GetPixelStride()

```
Image_ErrorCode OH_ImageNative_GetPixelStride(OH_ImageNative *image, uint32_t componentType, int32_t *pixelStride)
```
**描述**
获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的像素大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 
| componentType | 表示组件的类型。  | 
| pixelStride | 表示作为获取结果的像素大小的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_GetRowStride()

```
Image_ErrorCode OH_ImageNative_GetRowStride(OH_ImageNative *image, uint32_t componentType, int32_t *rowStride)
```
**描述**
获取Native [OH_ImageNative](#oh_imagenative) 对象中某个组件类型所对应的像素行宽。读取相机预览流数据时，需要考虑按stride进行读取，具体用法见[C/C++预览流二次处理示例](../../media/camera/native-camera-preview-imageReceiver.md)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 
| componentType | 表示组件的类型。  | 
| rowStride | 表示作为获取结果的像素行宽的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_GetTimestamp()

```
Image_ErrorCode OH_ImageNative_GetTimestamp(OH_ImageNative *image, int64_t *timestamp)
```
**描述**
获取Native [OH_ImageNative](#oh_imagenative) 对象中的时间戳信息。时间戳以纳秒为单位，通常是单调递增的。时间戳的具体含义和基准取决于图像的生产者，在相机预览/拍照场景，生产者就是相机。来自不同生产者的图像的时间戳可能有不同的含义和基准，因此可能无法进行比较。
如果要获取某张照片的生成时间，可以通过[OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty)接口读取相关的EXIF信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 
| timestamp | 表示作为获取结果的时间戳信息的指针。  |

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageNative_Release()

```
Image_ErrorCode OH_ImageNative_Release(OH_ImageNative *image)
```
**描述**
释放Native [OH_ImageNative](#oh_imagenative) 对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| image | 表示 [OH_ImageNative](#oh_imagenative) native对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_Create()

```
Image_ErrorCode OH_ImagePackerNative_Create(OH_ImagePackerNative **imagePacker)
```
**描述**
创建OH_ImagePackerNative指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_ImagePackerNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToDataFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_ImageSourceNative *imageSource, uint8_t *outData, size_t *size)
```
**描述**
将ImageSource编码为指定格式的数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 打包选项参数 [OH_PackingOptions](#oh_packingoptions)。  | 
| imageSource | 用于编码的image source指针。  | 
| outData | 用于存储打包图像输出数据的缓冲区。  | 
| size | 用于存储打包图像输出数据的缓冲区大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码失败返回 IMAGE_DECODE_FAILED，如果申请内存失败返回 IMAGE_ALLOC_FAILED， 如果数据或图片过大返回 IMAGE_TOO_LARGE，如果未知错误返回 IMAGE_UNKNOWN_ERROR， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToDataFromPicture()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPicture(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PictureNative *picture, uint8_t *outData, size_t *size)
```
**描述**
将Picture编码为指定格式的数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 打包选项参数 [OH_PackingOptions](#oh_packingoptions)。  | 
| picture | 用于编码的Picture指针。  | 
| outData | 用于存储打包图像输出数据的缓冲区。  | 
| size | 用于存储打包图像输出数据的缓冲区大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码失败返回 IMAGE_DECODE_FAILED，具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToDataFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PixelmapNative *pixelmap, uint8_t *outData, size_t *size)
```
**描述**
将Pixelmap编码为指定格式的数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 打包选项参数 [OH_PackingOptions](#oh_packingoptions)。  | 
| pixelmap | 用于编码的Pixelmap指针。  | 
| outData | 用于存储打包图像输出数据的缓冲区。  | 
| size | 用于存储打包图像输出数据的缓冲区大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码失败返回 IMAGE_DECODE_FAILED，如果申请内存失败返回 IMAGE_ALLOC_FAILED， 如果数据或图片过大返回 IMAGE_TOO_LARGE，如果未知错误返回 IMAGE_UNKNOWN_ERROR， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToDataFromPixelmapSequence()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmapSequence(OH_ImagePackerNative *imagePacker, OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, uint8_t *outData, size_t *outDataSize)
```
**描述**
将Pixelmap序列编码为数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 编码选项参数 [OH_PackingOptionsForSequence](#oh_packingoptionsforsequence)。  | 
| pixelmapSequence | 用于编码的Pixelmap序列指针。  | 
| sequenceLength | 用于编码的Pixelmap序列长度。  | 
| outData | 用于存储编码后图像输出数据的缓冲区。  | 
| outDataSize | 用于存储编码后图像输出数据的缓冲区大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，如果解码失败返回 IMAGE_DECODE_FAILED， 具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToFileFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_ImageSourceNative *imageSource, int32_t fd)
```
**描述**
将一个ImageSource编码到文件中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 打包选项参数 [OH_PackingOptions](#oh_packingoptions)。  | 
| imageSource | 用于编码的image source指针。  | 
| fd | 可写的文件描述符。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码失败返回 IMAGE_DECODE_FAILED，如果未知错误返回 IMAGE_UNKNOWN_ERROR， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToFileFromPicture()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPicture(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PictureNative *picture, int32_t fd)
```
**描述**
将一个Picture编码到文件中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 打包选项参数 [OH_PackingOptions](#oh_packingoptions)。  | 
| picture | 用于编码的picture指针。  | 
| fd | 可写的文件描述符。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码失败返回 IMAGE_DECODE_FAILED，如果未知错误返回 IMAGE_UNKNOWN_ERROR， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToFileFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap(OH_ImagePackerNative *imagePacker, OH_PackingOptions *options, OH_PixelmapNative *pixelmap, int32_t fd)
```
**描述**
将一个Pixelmap编码到文件中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 打包选项参数 [OH_PackingOptions](#oh_packingoptions)。  | 
| pixelmap | 用于编码的pixelmap指针。  | 
| fd | 可写的文件描述符。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码失败返回 IMAGE_DECODE_FAILED，如果未知错误返回 IMAGE_UNKNOWN_ERROR， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_PackToFileFromPixelmapSequence()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmapSequence(OH_ImagePackerNative *imagePacker, OH_PackingOptionsForSequence *options, OH_PixelmapNative **pixelmapSequence, size_t sequenceLength, int32_t fd)
```
**描述**
将一个Pixelmap序列编码到文件中。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 
| options | 编码选项参数 [OH_PackingOptionsForSequence](#oh_packingoptionsforsequence)。  | 
| pixelmapSequence | 用于编码的Pixelmap序列指针。  | 
| sequenceLength | 用于编码的Pixelmap序列长度。  | 
| fd | 可写的文件描述符。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，如果解码失败返回 IMAGE_DECODE_FAILED， 具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_ImagePackerNative_Release()

```
Image_ErrorCode OH_ImagePackerNative_Release(OH_ImagePackerNative *imagePacker)
```
**描述**
释放OH_ImagePackerNative指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| imagePacker | 被操作的OH_ImagePackerNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageReceiverNative_Create()

```
Image_ErrorCode OH_ImageReceiverNative_Create(OH_ImageReceiverOptions* options, OH_ImageReceiverNative** receiver)
```
**描述**
创建应用层 OH_ImageReceiverNative 对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的指针。  | 
| receiver | 表示作为获取结果的 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 如果申请内存失败返回 IMAGE_ALLOC_FAILED； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageReceiverNative_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverNative_GetCapacity(OH_ImageReceiverNative* receiver, int32_t* capacity)
```
**描述**
通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取ImageReceiver的容量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 
| capacity | 表示作为获取结果的图片缓存容量对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative)


### OH_ImageReceiverNative_GetReceivingSurfaceId()

```
Image_ErrorCode OH_ImageReceiverNative_GetReceivingSurfaceId(OH_ImageReceiverNative* receiver, uint64_t* surfaceId)
```
**描述**
通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取receiver的id。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 
| surfaceId | 表示作为获取结果的id对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative)


### OH_ImageReceiverNative_GetSize()

```
Image_ErrorCode OH_ImageReceiverNative_GetSize(OH_ImageReceiverNative* receiver, Image_Size* size)
```
**描述**
通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取ImageReceiver的大小。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 
| size | 表示作为获取结果的 [Image_Size](_image___size.md) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative), [Image_Size](_image___size.md)


### OH_ImageReceiverNative_Off()

```
Image_ErrorCode OH_ImageReceiverNative_Off(OH_ImageReceiverNative* receiver)
```
**描述**
关闭[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调事件。

关闭被 [OH_ImageReceiverNative_On](#oh_imagereceivernative_on) 开启的回调事件。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageReceiverNative_On](#oh_imagereceivernative_on)


### OH_ImageReceiverNative_On()

```
Image_ErrorCode OH_ImageReceiverNative_On(OH_ImageReceiverNative* receiver, OH_ImageReceiver_OnCallback callback)
```
**描述**
注册一个[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调事件。

每当接收到新的图片，该回调事件就会响应。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 
| callback | 表示 [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) 事件的回调函数。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)


### OH_ImageReceiverNative_ReadLatestImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadLatestImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)
```
**描述**
通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取最新的一张图片。

**注意**：此接口需要在[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调后调用，才能正常的接收到数据。并且此接口返回的[OH_ImageNative](#oh_imagenative)使用完毕后需要调用[OH_ImageNative_Release](#oh_imagenative_release)方法释放，释放后才可以继续接收新的数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 
| image | 获取到的应用层的 OH_ImageNative 指针对象。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR； 如果申请内存失败返回 IMAGE_ALLOC_FAILED； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageNative](#oh_imagenative)


### OH_ImageReceiverNative_ReadNextImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadNextImage(OH_ImageReceiverNative* receiver, OH_ImageNative** image)
```
**描述**
通过[OH_ImageReceiverNative](#oh_imagereceivernative)获取下一张图片。

**注意**：此接口需要在[OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)回调后调用，才能正常的接收到数据。并且此接口返回的[OH_ImageNative](#oh_imagenative)使用完毕后需要调用[OH_ImageNative_Release](#oh_imagenative_release)方法释放，释放后才可以继续接收新的数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 
| image | 获取到的应用层的 OH_ImageNative 指针对象。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 如果未知原因错误返回 IMAGE_UNKNOWN_ERROR； 如果申请内存失败返回 IMAGE_ALLOC_FAILED； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageNative](#oh_imagenative)


### OH_ImageReceiverNative_Release()

```
Image_ErrorCode OH_ImageReceiverNative_Release(OH_ImageReceiverNative* receiver)
```
**描述**
释放Native [OH_ImageReceiverNative](#oh_imagereceivernative) 对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| receiver | 表示 [OH_ImageReceiverNative](#oh_imagereceivernative) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverNative](#oh_imagereceivernative)


### OH_ImageReceiverOptions_Create()

```
Image_ErrorCode OH_ImageReceiverOptions_Create(OH_ImageReceiverOptions **options)
```
**描述**
创建应用层 OH_ImageReceiverOptions 对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示作为获取结果的 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 如果申请内存失败返回 IMAGE_ALLOC_FAILED； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageReceiverOptions_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_GetCapacity(OH_ImageReceiverOptions* options, int32_t* capacity)
```
**描述**
获取 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的图片缓存容量的信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的指针。  | 
| capacity | 表示作为获取结果的图片缓存容量对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageReceiverOptions_GetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_GetSize(OH_ImageReceiverOptions* options, Image_Size* size)
```
**描述**
获取 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的指针。  | 
| size | 表示作为获取结果的 [Image_Size](_image___size.md) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageReceiverOptions_Release()

```
Image_ErrorCode OH_ImageReceiverOptions_Release(OH_ImageReceiverOptions* options)
```
**描述**
释放 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。

**参见：**

[OH_ImageReceiverOptions](#oh_imagereceiveroptions)


### OH_ImageReceiverOptions_SetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_SetCapacity(OH_ImageReceiverOptions* options, int32_t capacity)
```
**描述**
设置 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的图片缓存容量的信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的指针。  | 
| capacity | 表示图片缓存容量对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageReceiverOptions_SetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_SetSize(OH_ImageReceiverOptions* options, Image_Size size)
```
**描述**
设置 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的 [Image_Size](_image___size.md) 信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 表示 [OH_ImageReceiverOptions](#oh_imagereceiveroptions) 对象的指针。  | 
| size | 表示 [Image_Size](_image___size.md) 对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS； 如果参数错误返回 IMAGE_BAD_PARAMETER； 具体释义参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceInfo_Create()

```
Image_ErrorCode OH_ImageSourceInfo_Create(OH_ImageSource_Info **info)
```
**描述**
创建OH_ImageSource_Info指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_ImageSource_Info指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceInfo_GetDynamicRange()

```
Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange(OH_ImageSource_Info *info, bool *isHdr)
```
**描述**
获取图片是否为高动态范围的信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_ImageSource_Info指针。  | 
| isHdr | 是否为hdr的布尔值。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceInfo_GetHeight()

```
Image_ErrorCode OH_ImageSourceInfo_GetHeight(OH_ImageSource_Info *info, uint32_t *height)
```
**描述**
获取图片的高。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_ImageSource_Info指针。  | 
| height | 图片的高，单位：像素高  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceInfo_GetWidth()

```
Image_ErrorCode OH_ImageSourceInfo_GetWidth(OH_ImageSource_Info *info, uint32_t *width)
```
**描述**
获取图片的宽。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_ImageSource_Info指针。  | 
| width | 图片的宽，单位：像素。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceInfo_Release()

```
Image_ErrorCode OH_ImageSourceInfo_Release(OH_ImageSource_Info *info)
```
**描述**
释放OH_ImageSource_Info指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_ImageSource_Info指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreateFromData()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromData(uint8_t *data, size_t dataSize, OH_ImageSourceNative **res)
```
**描述**
通过缓冲区数据创建OH_ImageSourceNative指针。

data数据应该是未解码的数据，不要传入类似于RBGA，YUV的像素buffer数据，如果想通过像素buffer数据创建pixelMap，可以调用[OH_PixelmapNative_CreatePixelmap](./pixelmap__native_8h.md)这一类接口。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | 图像缓冲区数据。  | 
| dataSize | 图像缓冲区数据长度。  | 
| res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码数据源异常返回 IMAGE_BAD_SOURCE， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreateFromFd()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromFd(int32_t fd, OH_ImageSourceNative **res)
```
**描述**
通过fd创建OH_ImageSourceNative指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fd | 文件描述符fd。  | 
| res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreateFromRawFile()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile(RawFileDescriptor *rawFile, OH_ImageSourceNative **res)
```
**描述**
通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative指针

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| rawFile | 指示raw文件的文件描述符。  | 
| res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreateFromUri()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromUri(char *uri, size_t uriSize, OH_ImageSourceNative **res)
```
**描述**
通过uri创建OH_ImageSourceNative指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| uri | 指向图像源URI的指针。只接受文件URI或Base64 URI。当前文件资源只支持绝对路径。  |
| uriSize | URI长度。  | 
| res | 指向c++本地层创建的OH_ImageSourceNative对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果解码数据源异常返回 IMAGE_BAD_SOURCE， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreatePicture()

```
Image_ErrorCode OH_ImageSourceNative_CreatePicture(OH_ImageSourceNative *source, OH_DecodingOptionsForPicture *options, OH_PictureNative **picture)
```
**描述**
通过图片解码创建OH_PictureNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| options | 解码参数。  | 
| picture | 指向c++本地层创建的OH_PictureNative对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 解码失败返回 IMAGE_DECODE_FAILED， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreatePixelmap()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmap(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative **pixelmap)
```
**描述**
通过图片解码参数创建OH_PixelmapNative指针

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| options | 解码参数。  | 
| resPixMap | 指向c++本地层创建的OH_PixelmapNative对象的指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreatePixelmapList()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList(OH_ImageSourceNative *source, OH_DecodingOptions *options, OH_PixelmapNative *resVecPixMap[], size_t size)
```
**描述**
通过图片解码参数创建OH_PixelmapNative数组

> **注意：**
> 此接口会一次性解码全部帧，当帧数过多或单帧图像过大时，会占用较大内存，造成系统内存紧张，此种情况推荐使用Image组件显示动图，Image组件采用逐帧解码，占用内存比此接口少。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| options | 解码参数。  | 
| resVecPixMap | 指向c++本地层创建的OH_PixelmapNative对象的指针数组。  | 
| size | 数组长度。 用户可以使用[OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount)获取。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果不支持的操作返回 IMAGE_UNSUPPORTED_OPERATION， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_CreatePixelmapUsingAllocator()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapUsingAllocator (OH_ImageSourceNative *source, OH_DecodingOptions *options, IMAGE_ALLOCATOR_TYPE allocator, OH_PixelmapNative **pixelmap )
```

**描述**

根据解码参数创建一个PixelMap，PixelMap使用的内存类型可以通过allocatorType来指定。

默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。 在处理通过此接口返回的PixelMap时，请始终考虑步幅（stride）的影响。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。 | 
| options | 解码参数。 详情请参见 **OH_DecodingOptions**。 | 
| allocator | 指示返回的PixelMap将使用哪种内存类型。 | 
| pixelmap | 指向c++本地层创建的OH_PixelmapNative对象的指针。 | 

**返回：**

错误码。

如果操作成功返回 IMAGE_SUCCESS。

如果参数错误返回 IMAGE_BAD_PARAMETER。

如果数据源异常返回 IMAGE_BAD_SOURCE。

如果是不支持的MIME类型返回 IMAGE_SOURCE_UNSUPPORTED_MIMETYPE。

如果图像过大返回 IMAGE_SOURCE_TOO_LARGE。

如果是不支持的分配器类型返回 IMAGE_SOURCE_UNSUPPORTED_ALLOCATOR_TYPE。 例如，使用共享内存解码HDR图像，因为只有DMA支持HDR元数据。

如果是不支持的选项返回 IMAGE_SOURCE_UNSUPPORTED_OPTIONS。 例如，无法将图像转换为所需的像素格式。

如果解码失败返回 IMAGE_DECODE_FAILED。

如果内存分配失败返回 IMAGE_SOURCE_ALLOC_FAILED。

具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_GetDelayTimeList()

```
Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList(OH_ImageSourceNative *source, int32_t *delayTimeList, size_t size)
```
**描述**
获取图像延迟时间数组

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| delayTimeList | 指向获得的延迟时间列表的指针。它不能是空指针。  | 
| size | delayTimeList的大小。用户可以从[OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount)获得大小。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_GetFrameCount()

```
Image_ErrorCode OH_ImageSourceNative_GetFrameCount(OH_ImageSourceNative *source, uint32_t *frameCount)
```
**描述**
获取图像帧数。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| frameCount | 图像帧数。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_GetImageInfo()

```
Image_ErrorCode OH_ImageSourceNative_GetImageInfo(OH_ImageSourceNative *source, int32_t index, OH_ImageSource_Info *info)
```
**描述**
获取指定序号的图片信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| index | 图片序号。对GIF图片可传入[0,N-1],N表示GIF的帧数。对只有一帧数据的图片格式，可传入0。  | 
| info | 指向获取的图像源信息的OH_ImageSource_Info指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_GetImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_GetImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```
**描述**
获取图片指定属性键的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| key | 指示指向属性的指针，详情请参见[Image_String](_image___string.md)，key的取值范围参考OHOS_IMAGE_PROPERTY_XXX定义。 使用ImageSource后释放，参见[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)。  | 
| value | 指向获取的值的指针。用户可以传入一个空指针和零大小， 我们将分配内存，但用户必须在使用后释放内存。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_ModifyImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty(OH_ImageSourceNative *source, Image_String *key, Image_String *value)
```
**描述**
通过指定的键修改图片属性的值。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 被操作的OH_ImageSourceNative指针。  | 
| key | 指向属性键的指针，详情请参见[Image_String](_image___string.md)，key是一个exif常数。 使用ImageSource后释放，参见[OH_ImageSourceNative_Release](#oh_imagesourcenative_release)。  | 
| value | 需要修改的属性值。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_ImageSourceNative_Release()

```
Image_ErrorCode OH_ImageSourceNative_Release(OH_ImageSourceNative *source)
```
**描述**
释放OH_ImageSourceNative指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 要释放的OH_ImageSourceNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_Create()

```
Image_ErrorCode OH_PackingOptions_Create(OH_PackingOptions **options)
```
**描述**
创建PackingOptions结构体的指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的PackingOptions指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange(OH_PackingOptions *options, int32_t* desiredDynamicRange)
```
**描述**
获取编码时期望的图片动态范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_PackingOptions指针。  | 
| desiredDynamicRange | 期望的动态范围 [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range)。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_GetMimeType()

```
Image_ErrorCode OH_PackingOptions_GetMimeType (OH_PackingOptions * options, Image_MimeType * format )
```
**描述**
获取MIME类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_PackingOptions指针。  | 
| format | 图像格式。可传入一个空指针和零大小，系统将分配内存，但必须在使用后释放内存。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_GetQuality()

```
Image_ErrorCode OH_PackingOptions_GetQuality(OH_PackingOptions *options, uint32_t *quality)
```
**描述**
获取编码质量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_PackingOptions指针。  | 
| quality | 编码质量。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_Release()

```
Image_ErrorCode OH_PackingOptions_Release(OH_PackingOptions *options)
```
**描述**
释放OH_PackingOptions指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_PackingOptions指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange(OH_PackingOptions *options, int32_t desiredDynamicRange)
```
**描述**
设置编码时期望的图片动态范围。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_PackingOptions指针。  | 
| desiredDynamicRange | 期望的动态范围 [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range)。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_SetMimeType()

```
Image_ErrorCode OH_PackingOptions_SetMimeType(OH_PackingOptions *options, Image_MimeType *format)
```
**描述**
设置MIME类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_PackingOptions指针。  | 
| format | 图像格式。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PackingOptions_SetQuality()

```
Image_ErrorCode OH_PackingOptions_SetQuality(OH_PackingOptions *options, uint32_t quality)
```
**描述**
设置编码质量。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_PackingOptions指针。  | 
| quality | 编码质量。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_Create()

```
Image_ErrorCode OH_PackingOptionsForSequence_Create(OH_PackingOptionsForSequence **options)
```
**描述**
创建OH_PackingOptionsForSequence结构体的指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_GetDelayTimeList()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetDelayTimeList(OH_PackingOptionsForSequence *options, int32_t *delayTimeList, size_t delayTimeListLength)
```
**描述**
获取编码时图片的延迟时间数组。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| delayTimeList | 图片延迟时间数组的指针。  | 
| delayTimeListLength | 图片延迟时间数组的长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_GetDisposalTypes()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetDisposalTypes(OH_PackingOptionsForSequence *options, uint32_t *disposalTypes, size_t disposalTypesLength)
```
**描述**
获取编码时图片的过渡帧模式数组。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| disposalTypes | 图片过渡帧模式数组的指针。  | 
| disposalTypesLength | 图片过渡帧模式数组的长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_GetFrameCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetFrameCount(OH_PackingOptionsForSequence *options, uint32_t *frameCount)
```
**描述**
获取编码时指定的帧数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| frameCount | 图片的帧数。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_GetLoopCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_GetLoopCount(OH_PackingOptionsForSequence *options, uint32_t *loopCount)
```
**描述**
获取编码时图片循环播放次数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| loopCount | 图片循环播放次数。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_Release()

```
Image_ErrorCode OH_PackingOptionsForSequence_Release(OH_PackingOptionsForSequence *options)
```
**描述**
释放OH_PackingOptionsForSequence指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_SetDelayTimeList()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetDelayTimeList(OH_PackingOptionsForSequence *options, int32_t *delayTimeList, size_t delayTimeListLength)
```
**描述**
设定编码时图片的延迟时间数组。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| delayTimeList | 图片延迟时间数组的指针。  | 
| delayTimeListLength | 图片延迟时间数组的长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_SetDisposalTypes()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetDisposalTypes(OH_PackingOptionsForSequence *options, uint32_t *disposalTypes, size_t disposalTypesLength)
```
**描述**
设定编码时图片的过渡帧模式数组。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| disposalTypes | 图片过渡帧模式数组的指针。  | 
| disposalTypesLength | 图片过渡帧模式数组的长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_SetFrameCount()

```
mage_ErrorCode OH_PackingOptionsForSequence_SetFrameCount(OH_PackingOptionsForSequence *options, uint32_t frameCount)
```
**描述**
设置编码时指定的帧数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| frameCount | 图片的帧数。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PackingOptionsForSequence_SetLoopCount()

```
Image_ErrorCode OH_PackingOptionsForSequence_SetLoopCount(OH_PackingOptionsForSequence *options, uint32_t loopCount)
```
**描述**
设定编码时图片循环播放次数。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 用于操作的OH_PackingOptionsForSequence指针。  | 
| loopCount | 图片循环播放次数。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PictureMetadata_Clone()

```
Image_ErrorCode OH_PictureMetadata_Clone(OH_PictureMetadata *oldMetadata, OH_PictureMetadata **newMetadata)
```
**描述**
拷贝元数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| oldMetadata | 被操作的OH_PictureMetadata指针。  | 
| newMetadata | 拷贝得到的OH_PictureMetadata指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果内存分配失败返回 IMAGE_ALLOC_FAILED，如果内存拷贝失败返回 IMAGE_COPY_FAILED， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureMetadata_Create()

```
Image_ErrorCode OH_PictureMetadata_Create(Image_MetadataType metadataType, OH_PictureMetadata **metadata)
```
**描述**
创建OH_PictureMetadata指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadataType | 元数据的类型。  | 
| metadata | 被操作的OH_PictureMetadata指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureMetadata_GetProperty()

```
Image_ErrorCode OH_PictureMetadata_GetProperty(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)
```
**描述**
根据key获取Metadata的单条属性。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadata | 被操作的OH_PictureMetadata指针。  | 
| key | 属性的键。  | 
| value | 属性的值。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果是不支持的元数据类型或元数据类型与辅助图类型不匹配返回 IMAGE_UNSUPPORTED_METADATA， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureMetadata_Release()

```
Image_ErrorCode OH_PictureMetadata_Release(OH_PictureMetadata *metadata)
```
**描述**
释放OH_PictureMetadata指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadata | 被操作的OH_PictureMetadata指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureMetadata_SetProperty()

```
Image_ErrorCode OH_PictureMetadata_SetProperty(OH_PictureMetadata *metadata, Image_String *key, Image_String *value)
```
**描述**
根据key修改Metadata的单条属性。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| metadata | 被操作的OH_PictureMetadata指针。  | 
| key | 属性的键。  | 
| value | 属性的值。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果是不支持的元数据类型或元数据类型与辅助图类型不匹配返回 IMAGE_UNSUPPORTED_METADATA， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_CreatePicture()

```
Image_ErrorCode OH_PictureNative_CreatePicture(OH_PixelmapNative *mainPixelmap, OH_PictureNative **picture)
```
**描述**
创建OH_PictureNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| mainPixelmap | 主图的OH_PixelmapNative指针。  | 
| picture | 被创建的OH_PictureNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_GetAuxiliaryPicture()

```
Image_ErrorCode OH_PictureNative_GetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative **auxiliaryPicture)
```
**描述**
根据类型获取辅助图。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 
| type | 辅助图类型。  | 
| auxiliaryPicture | 获取的OH_AuxiliaryPictureNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_GetGainmapPixelmap()

```
Image_ErrorCode OH_PictureNative_GetGainmapPixelmap(OH_PictureNative *picture, OH_PixelmapNative **gainmapPixelmap)
```
**描述**
获取增益图的OH_PixelmapNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 
| gainmapPixelmap | 获取的增益图OH_PixelmapNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_GetHdrComposedPixelmap()

```
Image_ErrorCode OH_PictureNative_GetHdrComposedPixelmap(OH_PictureNative *picture, OH_PixelmapNative **hdrPixelmap)
```
**描述**
获取hdr图的OH_PixelmapNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 
| hdrPixelmap | 获取的hdr图OH_PixelmapNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果是不支持的操作，例如picture对象中不包含增益图返回 IMAGE_UNSUPPORTED_OPERATION， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_GetMainPixelmap()

```
Image_ErrorCode OH_PictureNative_GetMainPixelmap(OH_PictureNative *picture, OH_PixelmapNative **mainPixelmap)
```
**描述**
获取主图的OH_PixelmapNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 
| mainPixelmap | 获取的OH_PixelmapNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_GetMetadata()

```
Image_ErrorCode OH_PictureNative_GetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType, OH_PictureMetadata **metadata)
```
**描述**
获取主图的元数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 
| metadataType | 元数据类型。  | 
| metadata | 主图的元数据。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果是不支持的元数据类型返回 IMAGE_UNSUPPORTED_METADATA， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_Release()

```
Image_ErrorCode OH_PictureNative_Release(OH_PictureNative *picture)
```
**描述**
释放OH_PictureNative指针。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_SetAuxiliaryPicture()

```
Image_ErrorCode OH_PictureNative_SetAuxiliaryPicture(OH_PictureNative *picture, Image_AuxiliaryPictureType type, OH_AuxiliaryPictureNative *auxiliaryPicture)
```
**描述**
设置辅助图。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 
| type | 辅助图的类型。  | 
| auxiliaryPicture | 设置的OH_AuxiliaryPictureNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PictureNative_SetMetadata()

```
Image_ErrorCode OH_PictureNative_SetMetadata(OH_PictureNative *picture, Image_MetadataType metadataType, OH_PictureMetadata *metadata)
```
**描述**
设置主图的元数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| picture | 被操作的OH_PictureNative指针。  | 
| metadataType | 元数据类型。  | 
| metadata | 将设置的元数据。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果是不支持的元数据类型返回 IMAGE_UNSUPPORTED_METADATA， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_Create()

```
Image_ErrorCode OH_PixelmapImageInfo_Create(OH_Pixelmap_ImageInfo **info)
```
**描述**
创建OH_Pixelmap_ImageInfo指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被创建的OH_Pixelmap_ImageInfo指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_GetAlphaType()

```
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)
```
**描述**
获取透明度类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_Pixelmap_ImageInfo指针。  | 
| alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type)。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_GetDynamicRange()

```
Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)
```
**描述**
获取Pixelmap是否为高动态范围的信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_Pixelmap_ImageInfo指针。  | 
| isHdr | 是否为hdr的布尔值。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，参数校验错误返回IMAGE_BAD_PARAMETER。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_GetHeight()

```
Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)
```
**描述**
获取图片高。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_Pixelmap_ImageInfo指针。  | 
| height | 图片高，单位：像素。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)
```
**描述**
获取像素格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_Pixelmap_ImageInfo指针。  | 
| pixelFormat | 像素格式。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_GetRowStride()

```
Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)
```
**描述**
获取行跨距。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_Pixelmap_ImageInfo指针。  | 
| rowStride | 跨距，内存中每行像素所占的空间。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_GetWidth()

```
Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)
```
**描述**
获取图片宽。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被操作的OH_Pixelmap_ImageInfo指针。  | 
| width | 图片宽，单位：像素。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapImageInfo_Release()

```
Image_ErrorCode OH_PixelmapImageInfo_Release(OH_Pixelmap_ImageInfo *info)
```
**描述**
释放OH_Pixelmap_ImageInfo指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| info | 被释放的OH_Pixelmap_ImageInfo指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_Create()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Create(OH_Pixelmap_InitializationOptions **options)
```
**描述**
创建OH_Pixelmap_InitializationOptions指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被创建的OH_Pixelmap_InitializationOptions指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_GetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t *alphaType)
```
**描述**
获取透明度类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type)。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_GetEditable()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options, bool *editable)
```

**描述**

获取可编辑标志。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。 | 
| editable | 可编辑标志。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_GetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t *height)
```
**描述**
获取图片高。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| height | 图片的高，单位：像素。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *pixelFormat)
```
**描述**
获取像素格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| pixelFormat | 像素格式[PIXEL_FORMAT](#pixel_format)。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_GetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t *rowStride)
```
**描述**
获取行跨距。

跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| rowStride | 跨距，单位：字节。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果options被释放返回 IMAGE_UNKNOWN_ERROR； 具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_GetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *srcpixelFormat)
```
**描述**
获取源像素格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| srcpixelFormat | 源像素格式[PIXEL_FORMAT](#pixel_format)。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_GetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t *width)
```
**描述**
获取图片宽。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| width | 图片的宽，单位：像素。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_Release()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Release(OH_Pixelmap_InitializationOptions *options)
```
**描述**
释放OH_Pixelmap_InitializationOptions指针。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被释放的OH_Pixelmap_InitializationOptions指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_SetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t alphaType)
```
**描述**
设置透明度类型。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type)。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_SetEditable()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options, bool editable)
```

**描述**

设置可编辑标志。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。 | 
| editable | 可编辑标志。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_SetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t height)
```
**描述**
设置图片高。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| height | 图片的高，单位：像素。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_SetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t pixelFormat)
```
**描述**
设置像素格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| pixelFormat | 像素格式[PIXEL_FORMAT](#pixel_format)。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_SetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t rowStride)
```
**描述**
设置图像跨距。

跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| rowStride | 跨距，单位：字节。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果options被释放返回 IMAGE_UNKNOWN_ERROR； 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_SetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t srcpixelFormat)
```
**描述**
设置源像素格式。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| srcpixelFormat | 源像素格式[PIXEL_FORMAT](#pixel_format)。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapInitializationOptions_SetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t width)
```
**描述**
设置图片宽。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 被操作的OH_Pixelmap_InitializationOptions指针。  | 
| width | 图片的宽，单位：像素。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_AccessPixels()

```
Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)
```

**描述**

获取Pixelmap像素数据的内存地址，并锁定这块内存。

当该内存被锁定时，任何修改或释放该Pixelmap的像素数据的操作均会失败或无效。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的Pixelmap指针。 | 
| addr | Pixelmap内存地址的双指针。 | 

**返回：**

如果操作成功则返回IMAGE_SUCCESS， 如果pixelmap或addr参数无效则返回IMAGE_BAD_PARAMETER， 如果内存锁定失败则返回IMAGE_LOCK_UNLOCK_FAILED。 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_ConvertAlphaFormat()

```
Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap, OH_PixelmapNative* dstpixelmap, const bool isPremul)
```
**描述**
将pixlemap的像素数据做预乘和非预乘之间的转换。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| srcpixelmap | 被操作的OH_PixelmapNative指针, 源pixelmap对象指针。  | 
| dstpixelmap | 被操作的OH_PixelmapNative指针, 目标pixelmap对象指针。目标指针和源指针不能是同一个。  | 
| isPremul | 转换方式，true为非预乘转预乘，false为预乘转非预乘。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_ConvertPixelmapNativeFromNapi()

```
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi, OH_PixelmapNative **pixelmapNative)
```
**描述**
将PixelMapnapi对象转换为nativePixelMap对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| pixelmapNapi | 需要转换的PixelMapnapi对象。  | 
| pixelmapNative | 转换出的OH_PixelmapNative对象指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS， 如果pixelmapNative是nullptr，或者pixelmapNapi不是PixelMapNapi对象返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_ConvertPixelmapNativeToNapi()

```
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative, napi_value *pixelmapNapi)
```
**描述**
将nativePixelMap对象转换为PixelMapnapi对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| env | napi的环境指针。  | 
| pixelmapNative | 被操作的OH_PixelmapNative指针。  | 
| pixelmapNapi | 转换出来的PixelMapnapi对象指针。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果pixelmapNative为空返回IMAGE_BAD_PARAMETER，具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_CreateEmptyPixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```
**描述**
利用OH_Pixelmap_InitializationOptions创建空的pixelmap对象，内存数据为0。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| options | 创建像素的属性。  | 
| pixelmap | 被创建的OH_PixelmapNative对象指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_CreatePixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```
**描述**
通过属性创建PixelMap，默认采用BGRA_8888格式处理数据，其他格式请参考[OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| data | BGRA_8888格式的颜色数组。  | 
| dataLength | 数组长度。  | 
| options | 创建像素的属性。  | 
| pixelmap | 被创建的OH_PixelmapNative对象指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果不支持的操作返回 IMAGE_UNSUPPORTED_OPERATION， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_CreateScaledPixelMap()

```
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY)
```

**描述**

根据输入的宽高的缩放比例，创建一个新的缩放后的图片。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| srcpixelmap | 被操作的OH_PixelmapNative指针，源pixelmap对象指针。 | 
| dstpixelmap | 被操作的OH_PixelmapNative指针，目标pixelmap对象指针。 | 
| scaleX | 宽度的缩放比例。 | 
| scaleY | 高度的缩放比例。 | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果参数错误返回IMAGE_BAD_PARAMETER，具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing()

```
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**描述**

根据指定的缩放算法和输入的宽高的缩放比例，创建一个新的缩放后的图片。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| srcpixelmap | 被操作的OH_PixelmapNative指针，源pixelmap对象指针。 | 
| dstpixelmap | 被操作的OH_PixelmapNative指针，目标pixelmap对象指针。 | 
| scaleX | 宽度的缩放比例。 | 
| scaleY | 高度的缩放比例。 | 
| level | 缩放算法。 | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果参数错误返回IMAGE_BAD_PARAMETER，如果图片过大返回IMAGE_TOO_LARGE，如果内存申请失败返回IMAGE_ALLOC_FAILED，具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Crop()

```
Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)
```
**描述**
根据输入的尺寸对图片进行裁剪

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| region | 裁剪的尺寸。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Destroy()

```
Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)
```

**描述**

释放OH_PixelmapNative指针。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被释放的OH_PixelmapNative指针。 | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Flip()

```
Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically)
```
**描述**
根据输入的条件对图片进行翻转。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| shouldFilpHorizontally | 是否水平翻转图像。  | 
| shouldFilpVertically | 是否垂直翻转图像。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_GetAllocationByteCount()

```
Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)
```

**描述**

获取Pixelmap用于储存像素数据的内存字节数。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的Pixelmap指针。 | 
| allocationByteCount | 获取的内存字节数。 | 

**返回：**

如果操作成功则返回IMAGE_SUCCESS， 如果pixelmap或allocationByteCount参数无效则返回IMAGE_BAD_PARAMETER。 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_GetArgbPixels()

```
Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```
**描述**
从PixelMap中读取ARGB格式的数据。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| destination | 缓冲区，获取的图像像素数据写入到该内存区域内。  | 
| bufferSize | 缓冲区大小。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果参数错误返回IMAGE_BAD_PARAMETER，如果PixelMap格式不支持读取ARGB数据，返回IMAGE_UNSUPPORTED_CONVERSION，如果内存申请失败，返回IMAGE_ALLOC_FAILED, 如果内存数据拷贝、读取、操作失败，返回IMAGE_COPY_FAILED。具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_GetByteCount()

```
Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)
```

**描述**

获取Pixelmap中所有像素所占用的总字节数，不包含内存填充。

**起始版本：** 18

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的Pixelmap指针。 | 
| byteCount | 获取的总字节数。 | 

**返回：**

如果操作成功则返回IMAGE_SUCCESS， 如果pixelmap或byteCount参数无效则返回IMAGE_BAD_PARAMETER。 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_GetColorSpaceNative()

```
Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager **colorSpaceNative)
```
**描述**
获取NativeColorSpaceManager对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 获取到NativeColorSpaceManager的源PixelMap。  | 
| colorSpaceNative | 获取到的NativeColorSpaceManager对象。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果参数错误返回IMAGE_BAD_PARAMETER。具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_GetImageInfo()

```
Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)
```
**描述**
获取图像像素信息。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| imageInfo | 图像像素信息。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_GetMetadata()

```
Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue **value)
```
**描述**
获取元数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| key | 元数据的关键字，参见[OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey)。  | 
| value | 元数据的值，参见[OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md)。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果不存在DMA内存返回 IMAGE_DMA_NOT_EXIST，如果内存拷贝失败返回 IMAGE_COPY_FAILED。具体请参考[Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_GetNativeBuffer()

```
Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)
```
**描述**
从DMA内存的PixelMap中，获取NativeBuffer对象。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 要获取NativeBuffer的源PixelMap。  | 
| nativeBuffer | 被创建的NativeBuffer对象指针。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER，如果不是DMA内存返回IMAGE_DMA_NOT_EXIST，如果DMA内存操作失败返回IMAGE_DMA_OPERATION_FAILED。具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Opacity()

```
Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)
```
**描述**
通过设置透明比率来让PixelMap达到对应的透明效果

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| rate | 透明比率的值。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_ReadPixels()

```
Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```
**描述**
读取图像像素数据，并按照PixelMap的像素格式写入缓冲区中。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| destination | 缓冲区，获取的图像像素数据写入到该内存区域内。  | 
| bufferSize | 缓冲区大小。RGBA格式的缓冲区大小等于width * height * 4，NV21与NV12格式的缓冲区大小等于width * height+((width+1)/2) * ((height+1)/2) * 2。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果未知错误返回 IMAGE_UNKNOWN_ERROR， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Release()

```
Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)
```
**描述**
释放OH_PixelmapNative指针，推荐使用 [OH_PixelmapNative_Destroy](#oh_pixelmapnative_destroy)。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被释放的OH_PixelmapNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Rotate()

```
Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)
```
**描述**
根据输入的角度对图片进行旋转。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| angle | 图片旋转的角度，单位为deg。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Scale()

```
Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)
```
**描述**
根据输入的宽高对图片进行缩放。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| scaleX | 宽度的缩放比例。  | 
| scaleY | 高度的缩放比例。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_ScaleWithAntiAliasing()

```
Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```
**描述**
根据指定的缩放算法和输入的宽高对图片进行缩放。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| scaleX | 宽度的缩放比例。  | 
| scaleY | 高度的缩放比例。  | 
| level | 缩放算法。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果图片过大返回 IMAGE_TOO_LARGE，如果内存申请失败返回 IMAGE_ALLOC_FAILED， 如果pixelmap已经被释放返回 IMAGE_UNKNOWN_ERROR，具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_SetColorSpaceNative()

```
Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager *colorSpaceNative)
```
**描述**
设置NativeColorSpaceManager对象。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 要设置NativeColorSpaceManager的目标PixelMap。  | 
| colorSpaceNative | 要设置的NativeColorSpaceManager对象。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果参数错误返回IMAGE_BAD_PARAMETER。具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_SetMemoryName()

```
Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)
```
**描述**
设置pixelMap内存名字。

**起始版本：** 13

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| name | 需要被设置的PixelMap内存名称。  | 
| size | 需要被设置的PixelMap内存名称的字节大小。  | 

**返回：**

如果操作成功返回的是IMAGE_SUCCESS，如果名字长度超出31位或者小于1位会返回IMAGE_BAD_PARAMETER。 如果既不是DMA内存也不是ASHMEM内存返回IMAGE_UNSUPPORTED_MEMORY_FORMAT。具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_SetMetadata()

```
Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue *value)
```
**描述**
设置元数据。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| key | 元数据的关键字，参见[OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey)。  | 
| value | 元数据的值，参见[OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md)。  | 

**返回：**

如果操作成功返回IMAGE_SUCCESS，如果参数错误返回IMAGE_BAD_PARAMETER，如果不存在DMA内存返回IMAGE_DMA_NOT_EXIST，如果内存拷贝失败返回IMAGE_COPY_FAILED。具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_ToSdr()

```
Image_ErrorCode OH_PixelmapNative_ToSdr(OH_PixelmapNative *pixelmap)
```
**描述**
将HDR的图像内容转换为SDR的图像内容。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果不支持的操作返回 IMAGE_UNSUPPORTED_OPERATION， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_Translate()

```
Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)
```
**描述**
根据输入的坐标对图片进行位置变换。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| x | 区域横坐标。  | 
| y | 区域纵坐标。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_UnaccessPixels()

```
Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)
```

**描述**

释放Pixelmap像素数据的内存锁。

该函数需要与[OH_PixelmapNative_AccessPixels](#oh_pixelmapnative_accesspixels)匹配使用。

**起始版本：** 15

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的Pixelmap指针。 | 

**返回：**

如果操作成功则返回IMAGE_SUCCESS， 如果pixelmap参数无效则返回IMAGE_BAD_PARAMETER， 如果内存解锁失败则返回IMAGE_LOCK_UNLOCK_FAILED。 具体请参考 [Image_ErrorCode](#image_errorcode)。


### OH_PixelmapNative_WritePixels()

```
Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)
```
**描述**
读取缓冲区中的图像像素数据，并按照PixelMap的像素格式将结果写入PixelMap。

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| pixelmap | 被操作的OH_PixelmapNative指针。  | 
| source | 图像像素数据。  | 
| bufferSize | 图像像素数据长度。  | 

**返回：**

如果操作成功返回 IMAGE_SUCCESS，如果参数错误返回 IMAGE_BAD_PARAMETER， 如果不支持的操作返回 IMAGE_UNSUPPORTED_OPERATION，如果未知错误返回 IMAGE_UNKNOWN_ERROR， 具体请参考 [Image_ErrorCode](#image_errorcode)。

## 变量说明


### MIME_TYPE_BMP

```
static const char* MIME_TYPE_BMP = "image/bmp"
```

**描述**

bmp图片格式。

**起始版本：** 12


### MIME_TYPE_GIF

```
static const char* MIME_TYPE_GIF = "image/gif"
```

**描述**

gif图片格式。

**起始版本：** 12


### MIME_TYPE_HEIC

```
static const char* MIME_TYPE_HEIC = "image/heic"
```

**描述**

heic图片格式。

**起始版本：** 12


### MIME_TYPE_ICON

```
static const char* MIME_TYPE_ICON = "image/x-icon"
```

**描述**

ico图片格式。

**起始版本：** 12


### MIME_TYPE_JPEG

```
static const char* MIME_TYPE_JPEG = "image/jpeg"
```

**描述**

jpeg图片格式。

**起始版本：** 12


### MIME_TYPE_PNG

```
static const char* MIME_TYPE_PNG = "image/png"
```

**描述**

png图片格式。

**起始版本：** 12


### MIME_TYPE_WEBP

```
static const char* MIME_TYPE_WEBP = "image/webp"
```

**描述**

webp图片格式。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_ARTIST

```
static const char* OHOS_IMAGE_PROPERTY_ARTIST = "Artist"
```

**描述**

创建图像的用户名称。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE

```
static const char* OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample"
```

**描述**

每个像素比特数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER = "BodySerialNumber"
```

**描述**

相机机身的序列号。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE

```
static const char* OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE = "BrightnessValue"
```

**描述**

图像的亮度值，以APEX单位表示。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_BURST_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_BURST_NUMBER = "HwMnoteBurstNumber"
```

**描述**

连拍次数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME

```
static const char* OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME = "CameraOwnerName"
```

**描述**

相机所有者的姓名。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_CFA_PATTERN

```
static const char* OHOS_IMAGE_PROPERTY_CFA_PATTERN = "CFAPattern"
```

**描述**

图像传感器的色彩滤光片（CFA）几何图案。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_COLOR_SPACE

```
static const char* OHOS_IMAGE_PROPERTY_COLOR_SPACE = "ColorSpace"
```

**描述**

色彩空间信息标签，通常记录为色彩空间指定符。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION

```
static const char* OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION = "ComponentsConfiguration"
```

**描述**

压缩数据的特定信息。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE

```
static const char* OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE = "CompositeImage"
```

**描述**

表示图像是否为合成图像。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL

```
static const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel"
```

**描述**

用于压缩图像的压缩模式，单位为每像素位数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_COMPRESSION

```
static const char* OHOS_IMAGE_PROPERTY_COMPRESSION = "Compression"
```

**描述**

图像压缩方案。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_CONTRAST

```
static const char* OHOS_IMAGE_PROPERTY_CONTRAST = "Contrast"
```

**描述**

相机应用的对比度处理方向。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_COPYRIGHT

```
static const char* OHOS_IMAGE_PROPERTY_COPYRIGHT = "Copyright"
```

**描述**

图像的版权信息。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED

```
static const char* OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED = "CustomRendered"
```

**描述**

指示图像数据上的特殊处理。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED

```
static const char* OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED = "DateTimeDigitized"
```

**描述**

图像作为数字数据存储的日期和时间，格式为YYYY:MM:DD HH:MM:SS。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL

```
static const char* OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal"
```

**描述**

拍摄时间，例如2022:09:06 15:48:00。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE

```
static const char* OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE = "DefaultCropSize"
```

**描述**

DefaultCropSize指定了原始坐标中的最终图像大小，考虑了额外的边缘像素。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION

```
static const char* OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION = "DeviceSettingDescription"
```

**描述**

特定相机模型的拍照条件信息。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO

```
static const char* OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO = "DigitalZoomRatio"
```

**描述**

捕获时的数字变焦比率。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_DNG_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_DNG_VERSION = "DNGVersion"
```

**描述**

DNG版本标签编码了符合DNG规范的四级版本号。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_EXIF_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_EXIF_VERSION = "ExifVersion"
```

**描述**

支持的Exif标准版本。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX = "ExposureIndex"
```

**描述**

捕获时选定的曝光指数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_MODE

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_MODE = "ExposureMode"
```

**描述**

拍摄时设置的曝光模式。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM = "ExposureProgram"
```

**描述**

拍照时相机用来设置曝光的程序的类别。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_TIME

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime"
```

**描述**

曝光时间，例如1/33 sec。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_F_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber"
```

**描述**

光圈值，例如f/1.8。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_CONF

```
static const char* OHOS_IMAGE_PROPERTY_FACE_CONF = "HwMnoteFaceConf"
```

**描述**

人脸置信度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER = "HwMnoteFaceLeyeCenter"
```

**描述**

左眼中心。被用于 **OH_ImageSource_GetImageProperty** 和 **OH_ImageSource_ModifyImageProperty**。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER = "HwMnoteFaceMouthCenter"
```

**描述**

嘴中心。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_POINTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_POINTER = "HwMnoteFacePointer"
```

**描述**

脸部指针。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_RECT

```
static const char* OHOS_IMAGE_PROPERTY_FACE_RECT = "HwMnoteFaceRect"
```

**描述**

脸部矩形。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER = "HwMnoteFaceReyeCenter"
```

**描述**

右眼中心。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE

```
static const char* OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE = "HwMnoteFaceSmileScore"
```

**描述**

FaceCount张人脸的笑脸分数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FACE_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_FACE_VERSION = "HwMnoteFaceVersion"
```

**描述**

人脸算法版本信息。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FILE_SOURCE

```
static const char* OHOS_IMAGE_PROPERTY_FILE_SOURCE = "FileSource"
```

**描述**

表明图像来源。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FLASH_ENERGY

```
static const char* OHOS_IMAGE_PROPERTY_FLASH_ENERGY = "FlashEnergy"
```

**描述**

图像捕获时的闪光能量，以BCPS表示。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION = "FlashpixVersion"
```

**描述**

该标签表示FPXR文件支持的Flashpix格式版本，增强了设备兼容性。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT

```
static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT = "FocalPlaneResolutionUnit"
```

**描述**

测量FocalPlaneXResolution和FocalPlaneYResolution的单位。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION = "FocalPlaneXResolution"
```

**描述**

图像宽度中每FocalPlaneResolutionUnit的像素。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION = "FocalPlaneYResolution"
```

**描述**

图像高度中每FocalPlaneResolutionUnit的像素。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_FRAGMENT_HEIGHT

```
static const char *OHOS_IMAGE_PROPERTY_FRAGMENT_HEIGHT = "FragmentImageHeight"
```

**描述**

水印裁剪图的高。

**起始版本：** 13


### OHOS_IMAGE_PROPERTY_FRAGMENT_WIDTH

```
static const char *OHOS_IMAGE_PROPERTY_FRAGMENT_WIDTH = "FragmentImageWidth"
```

**描述**

水印裁剪图的宽。

**起始版本：** 13


### OHOS_IMAGE_PROPERTY_FRONT_CAMERA

```
static const char* OHOS_IMAGE_PROPERTY_FRONT_CAMERA = "HwMnoteFrontCamera"
```

**描述**

是否是前置相机自拍。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GAIN_CONTROL

```
static const char* OHOS_IMAGE_PROPERTY_GAIN_CONTROL = "GainControl"
```

**描述**

整体图像增益调整的程度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GAMMA

```
static const char* OHOS_IMAGE_PROPERTY_GAMMA = "Gamma"
```

**描述**

表示系数伽马的值。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT

```
static const char* OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT = "GIFLoopCount"
```

**描述**

GIF图片循环次数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_ALTITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE = "GPSAltitude"
```

**描述**

基于GPSAltitudeRef的高度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF = "GPSAltitudeRef"
```

**描述**

用于GPS高度的参照高度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION

```
static const char* OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION = "GPSAreaInformation"
```

**描述**

记录GPS区域名的字符字符串。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING = "GPSDestBearing"
```

**描述**

目的地方位。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF = "GPSDestBearingRef"
```

**描述**

指向目的地点的方位参照。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE = "GPSDestDistance"
```

**描述**

到目的地点的距离。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF = "GPSDestDistanceRef"
```

**描述**

目标点距离的测量单位。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE = "GPSDestLatitude"
```

**描述**

目的地点的纬度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF = "GPSDestLatitudeRef"
```

**描述**

目的地点的纬度参照。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE = "GPSDestLongitude"
```

**描述**

目的地点的经度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF = "GPSDestLongitudeRef"
```

**描述**

目的地点的经度参照。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL = "GPSDifferential"
```

**描述**

此字段表示GPS数据是否应用了差分校正，对于精确的位置准确性至关重要。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_DOP

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DOP = "GPSDOP"
```

**描述**

GPS DOP（数据精度等级）。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR

```
static const char* OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR = "GPSHPositioningError"
```

**描述**

此标签指示水平定位误差，单位为米。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION

```
static const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION = "GPSImgDirection"
```

**描述**

拍摄时图像的方向。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF = "GPSImgDirectionRef"
```

**描述**

图像方向的参照。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude"
```

**描述**

图片纬度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef"
```

**描述**

纬度引用，例如N或S。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude"
```

**描述**

图片经度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef"
```

**描述**

经度引用，例如W或E。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM

```
static const char* OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM = "GPSMapDatum"
```

**描述**

GPS接收器使用的大地测量数据。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE = "GPSMeasureMode"
```

**描述**

GPS测量模式。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD

```
static const char* OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD = "GPSProcessingMethod"
```

**描述**

记录定位方法名的字符字符串。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_SATELLITES

```
static const char* OHOS_IMAGE_PROPERTY_GPS_SATELLITES = "GPSSatellites"
```

**描述**

用于测量的GPS卫星。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_SPEED

```
static const char* OHOS_IMAGE_PROPERTY_GPS_SPEED = "GPSSpeed"
```

**描述**

GPS接收器的移动速度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_SPEED_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_SPEED_REF = "GPSSpeedRef"
```

**描述**

用来表示GPS接收器移动速度的单位。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_STATUS

```
static const char* OHOS_IMAGE_PROPERTY_GPS_STATUS = "GPSStatus"
```

**描述**

录制图像时GPS接收器的状态。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_TRACK

```
static const char* OHOS_IMAGE_PROPERTY_GPS_TRACK = "GPSTrack"
```

**描述**

GPS接收机的移动方向。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_TRACK_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_TRACK_REF = "GPSTrackRef"
```

**描述**

GPS接收机移动方向的参照。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_GPS_VERSION_ID

```
static const char* OHOS_IMAGE_PROPERTY_GPS_VERSION_ID = "GPSVersionID"
```

**描述**

GPSInfoIFD的版本。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_IMAGE_LENGTH

```
static const char* OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength"
```

**描述**

图片长度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID

```
static const char* OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID = "ImageUniqueID"
```

**描述**

为每张图片唯一分配的标识符。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_IMAGE_WIDTH

```
static const char* OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth"
```

**描述**

图片宽度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY

```
static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY = "ISOSpeedLatitudeyyy"
```

**描述**

该标签指示摄像机或输入设备的ISO速度纬度yyy值，该值在ISO 12232中定义。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ

```
static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ = "ISOSpeedLatitudezzz"
```

**描述**

该标签指示摄像机或输入设备的ISO速度纬度zzz值，该值在ISO 12232中定义。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS

```
static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings"
```

**描述**

ISO感光度，例如400。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT

```
static const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT = "JPEGInterchangeFormat"
```

**描述**

JPEG压缩缩略图数据开始字节（SOI）的偏移。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH

```
static const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH = "JPEGInterchangeFormatLength"
```

**描述**

JPEG压缩缩略图数据的字节数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_LENS_MAKE

```
static const char* OHOS_IMAGE_PROPERTY_LENS_MAKE = "LensMake"
```

**描述**

镜头的制造商。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_LENS_MODEL

```
static const char* OHOS_IMAGE_PROPERTY_LENS_MODEL = "LensModel"
```

**描述**

镜头的型号名称。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER = "LensSerialNumber"
```

**描述**

镜头的序列号。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION

```
static const char* OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION = "LensSpecification"
```

**描述**

使用的镜头规格。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_MAKER_NOTE

```
static const char* OHOS_IMAGE_PROPERTY_MAKER_NOTE = "MakerNote"
```

**描述**

Exif/DCF制造商使用的标签，用于记录任何所需信息。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE

```
static const char* OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE = "MaxApertureValue"
```

**描述**

最小F数镜头。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE = "NewSubfileType"
```

**描述**

在Exif中，"NewSubfileType"字段用于标识子文件的数据类型，如全分辨率图像、缩略图或多帧图像的一部分。 其值是位掩码，0代表全分辨率图像，1代表缩略图，2代表多帧图像的一部分。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_OECF

```
static const char* OHOS_IMAGE_PROPERTY_OECF = "OECF"
```

**描述**

表示ISO 14524中规定的光电转换函数（OECF）。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_OFFSET_TIME

```
static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME = "OffsetTime"
```

**描述**

在Exif中，OffsetTime字段表示与UTC（协调世界时）的时间偏移，格式为±HH:MM，用于确定照片拍摄的本地时间。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED

```
static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED = "OffsetTimeDigitized"
```

**描述**

此标签记录图像数字化时的UTC偏移量，有助于准确调整时间戳。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL

```
static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL = "OffsetTimeOriginal"
```

**描述**

此标签记录原始图像创建时的UTC偏移量，对于时间敏感的应用至关重要。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_ORIENTATION

```
static const char* OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation"
```

**描述**

图片方向。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY

```
static const char* OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY = "PhotographicSensitivity"
```

**描述**

此标签指示拍摄图像时相机或输入设备的灵敏度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION

```
static const char* OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION = "PhotometricInterpretation"
```

**描述**

像素构成，例如RGB或YCbCr。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION

```
const char* OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION = "PlanarConfiguration"
```

**描述**

表示像素组件的记录格式，chunky格式或是planar格式。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES

```
static const char* OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES = "PrimaryChromaticities"
```

**描述**

图像的主要颜色的色度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE

```
static const char* OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE = "ReferenceBlackWhite"
```

**描述**

参考黑点值和参考白点值。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE

```
static const char* OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE = "RelatedSoundFile"
```

**描述**

与图像数据相关的音频文件的名称。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT

```
static const char* OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT = "ResolutionUnit"
```

**描述**

用于测量XResolution和YResolution的单位。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP

```
static const char* OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP = "RowsPerStrip"
```

**描述**

每个strip的图像数据行数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL

```
static const char* OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL = "SamplesPerPixel"
```

**描述**

每个像素的分量数。由于该标准适用于 RGB 和 YCbCr 图像，因此该标签的值设置为 3。 在JPEG压缩数据中，使用JPEG标记代替该标签。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SATURATION

```
static const char* OHOS_IMAGE_PROPERTY_SATURATION = "Saturation"
```

**描述**

相机应用的饱和度处理方向。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE = "SceneCaptureType"
```

**描述**

捕获的场景类型。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SCENE_POINTER

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_POINTER = "HwMnoteScenePointer"
```

**描述**

场景指针。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SCENE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType"
```

**描述**

拍摄场景模式，例如人像、风光、运动、夜景等。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SCENE_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_VERSION = "HwMnoteSceneVersion"
```

**描述**

场景算法版本信息。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SENSING_METHOD

```
static const char* OHOS_IMAGE_PROPERTY_SENSING_METHOD = "SensingMethod"
```

**描述**

相机上的图像传感器类型。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SHARPNESS

```
static const char* OHOS_IMAGE_PROPERTY_SHARPNESS = "Sharpness"
```

**描述**

相机应用的锐度处理方向。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE

```
static const char* OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE = "ShutterSpeedValue"
```

**描述**

快门速度，以APEX（摄影曝光的加法系统）值表示。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SOFTWARE

```
static const char* OHOS_IMAGE_PROPERTY_SOFTWARE = "Software"
```

**描述**

用于生成图像的软件的名称和版本。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE

```
static const char* OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE = "SourceExposureTimesOfCompositeImage"
```

**描述**

合成图像的源图像曝光时间。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE

```
static const char* OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE = "SourceImageNumberOfCompositeImage"
```

**描述**

用于合成图像的源图像数量。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE

```
static const char* OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE = "SpatialFrequencyResponse"
```

**描述**

相机或输入设备的空间频率表。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY

```
static const char* OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY = "SpectralSensitivity"
```

**描述**

表示所用相机的每个通道的光谱灵敏度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS

```
static const char* OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS = "StripByteCounts"
```

**描述**

每个图像数据带的总字节数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_STRIP_OFFSETS

```
static const char* OHOS_IMAGE_PROPERTY_STRIP_OFFSETS = "StripOffsets"
```

**描述**

每个strip的字节偏移量。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBFILE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_SUBFILE_TYPE = "SubfileType"
```

**描述**

此标签指示此子文件中的数据类型。标签已弃用，请使用NewSubfileType替代。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBJECT_AREA

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_AREA = "SubjectArea"
```

**描述**

该标签指示整个场景中主要主体的位置和区域。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE = "SubjectDistance"
```

**描述**

测量单位为米的主体距离。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE = "SubjectDistanceRange"
```

**描述**

表示主体到相机的距离范围。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION = "SubjectLocation"
```

**描述**

主要对象相对于左边缘的位置。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBSEC_TIME

```
static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME = "SubsecTime"
```

**描述**

用于为DateTime标签记录秒的分数的标签。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED

```
static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED = "SubsecTimeDigitized"
```

**描述**

用于为DateTimeDigitized标签记录秒的分数的标签。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL

```
static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL = "SubsecTimeOriginal"
```

**描述**

用于为DateTimeOriginal标签记录秒的分数的标签。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION

```
static const char* OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION = "TransferFunction"
```

**描述**

图像的传递函数，通常用于颜色校正。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_WHITE_POINT

```
static const char* OHOS_IMAGE_PROPERTY_WHITE_POINT = "WhitePoint"
```

**描述**

图像的白点色度。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_X_IN_ORIGINAL

```
static const char *OHOS_IMAGE_PROPERTY_X_IN_ORIGINAL = "XInOriginal"
```

**描述**

水印裁剪图左上角在原始图中的X坐标。

**起始版本：** 13


### OHOS_IMAGE_PROPERTY_X_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_X_RESOLUTION = "XResolution"
```

**描述**

图像宽度方向的分辨率。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_Y_IN_ORIGINAL

```
static const char *OHOS_IMAGE_PROPERTY_Y_IN_ORIGINAL = "YInOriginal"
```

**描述**

水印裁剪图左上角在原始图中的Y坐标。

**起始版本：** 13


### OHOS_IMAGE_PROPERTY_Y_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_Y_RESOLUTION = "YResolution"
```

**描述**

图像高度方向的分辨率。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS

```
static const char* OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS = "YCbCrCoefficients"
```

**描述**

从RGB到YCbCr图像数据的转换矩阵系数。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING

```
static const char* OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING = "YCbCrPositioning"
```

**描述**

色度分量相对于亮度分量的位置。

**起始版本：** 12


### OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING

```
static const char* OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING = "YCbCrSubSampling"
```

**描述**

色度分量与亮度分量的采样比率。

**起始版本：** 12


