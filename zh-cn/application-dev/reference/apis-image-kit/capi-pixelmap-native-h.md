# pixelmap_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @zengyawen-->

## 概述

访问Pixelmap的API。

**引用文件：** <multimedia/image_framework/image/pixelmap_native.h>

**库：** libpixelmap.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) | OH_PixelmapNative | OH_PixelmapNative结构体是native层封装的图像解码后无压缩的位图格式结构体。 |
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) | OH_NativeBuffer | NativeBuffer结构体类型，用于执行NativeBuffer相关操作。 |
| [OH_Pixelmap_HdrStaticMetadata](capi-image-nativemodule-oh-pixelmap-hdrstaticmetadata.md) | OH_Pixelmap_HdrStaticMetadata | HDR_STATIC_METADATA关键字对应的静态元数据值。 |
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) | OH_NativeColorSpaceManager | NativeColorSpaceManager结构体类型，用于执行NativeColorSpaceManager相关操作。 |
| [OH_Pixelmap_HdrDynamicMetadata](capi-image-nativemodule-oh-pixelmap-hdrdynamicmetadata.md) | OH_Pixelmap_HdrDynamicMetadata | DR_DYNAMIC_METADATA关键字对应的动态元数据值。 |
| [OH_Pixelmap_HdrGainmapMetadata](capi-image-nativemodule-oh-pixelmap-hdrgainmapmetadata.md) | OH_Pixelmap_HdrGainmapMetadata | HDR_GAINMAP_METADATA关键字对应的gainmap相关元数据值，参考ISO 21496-1。 |
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) | OH_Pixelmap_HdrMetadataValue | Pixelmap使用的HDR元数据值，和OH_Pixelmap_HdrMetadataKey关键字相对应。 |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) | OH_Pixelmap_InitializationOptions | OH_Pixelmap_InitializationOptions是native层封装的初始化参数结构体，用于设置Pixelmap的初始化参数。 |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) | OH_Pixelmap_ImageInfo | OH_Pixelmap_ImageInfo是native层封装的图像像素信息结构体，保存图像像素的宽高、行跨距、像素格式、是否是HDR。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type) | PIXELMAP_ALPHA_TYPE | Pixelmap透明度类型。 |
| [PIXEL_FORMAT](#pixel_format) | PIXEL_FORMAT | 图片像素格式。 |
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) | OH_PixelmapNative_AntiAliasingLevel | Pixelmap缩放时采用的缩放算法。 |
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) | OH_Pixelmap_HdrMetadataKey | Pixelmap使用的HDR相关元数据信息的关键字，用于[OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata)。 |
| [OH_Pixelmap_HdrMetadataType](#oh_pixelmap_hdrmetadatatype) | OH_Pixelmap_HdrMetadataType | HDR_METADATA_TYPE关键字对应的值。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [Image_ErrorCode OH_PixelmapInitializationOptions_Create(OH_Pixelmap_InitializationOptions **options)](#oh_pixelmapinitializationoptions_create) | 创建OH_Pixelmap_InitializationOptions指针。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t *width)](#oh_pixelmapinitializationoptions_getwidth) | 获取图片宽。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t width)](#oh_pixelmapinitializationoptions_setwidth) | 设置图片宽。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t *height)](#oh_pixelmapinitializationoptions_getheight) | 获取图片高。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t height)](#oh_pixelmapinitializationoptions_setheight) | 设置图片高。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *pixelFormat)](#oh_pixelmapinitializationoptions_getpixelformat) | 获取像素格式。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t pixelFormat)](#oh_pixelmapinitializationoptions_setpixelformat) | 设置像素格式。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *srcpixelFormat)](#oh_pixelmapinitializationoptions_getsrcpixelformat) | 获取源像素格式。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t srcpixelFormat)](#oh_pixelmapinitializationoptions_setsrcpixelformat) | 设置源像素格式。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t *rowStride)](#oh_pixelmapinitializationoptions_getrowstride) | 获取行跨距。<br>跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t rowStride)](#oh_pixelmapinitializationoptions_setrowstride) | 设置图像跨距。<br>跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t *alphaType)](#oh_pixelmapinitializationoptions_getalphatype) | 获取透明度类型。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t alphaType)](#oh_pixelmapinitializationoptions_setalphatype) | 设置透明度类型。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options, bool *editable)](#oh_pixelmapinitializationoptions_geteditable) | 获取可编辑标志。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options, bool editable)](#oh_pixelmapinitializationoptions_seteditable) | 设置可编辑标志。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_Release(OH_Pixelmap_InitializationOptions *options)](#oh_pixelmapinitializationoptions_release) | 释放OH_Pixelmap_InitializationOptions指针。 |
| [Image_ErrorCode OH_PixelmapImageInfo_Create(OH_Pixelmap_ImageInfo **info)](#oh_pixelmapimageinfo_create) | 创建OH_Pixelmap_ImageInfo指针。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)](#oh_pixelmapimageinfo_getwidth) | 获取图片宽。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)](#oh_pixelmapimageinfo_getheight) | 获取图片高。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *AlphaMode)](#oh_pixelmapimageinfo_getalphamode) | 获取图片alpha格式。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)](#oh_pixelmapimageinfo_getrowstride) | 获取行跨距。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)](#oh_pixelmapimageinfo_getpixelformat) | 获取像素格式。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)](#oh_pixelmapimageinfo_getalphatype) | 获取透明度类型。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)](#oh_pixelmapimageinfo_getdynamicrange) | 获取Pixelmap是否为高动态范围的信息。 |
| [Image_ErrorCode OH_PixelmapImageInfo_Release(OH_Pixelmap_ImageInfo *info)](#oh_pixelmapimageinfo_release) | 释放OH_Pixelmap_ImageInfo指针。 |
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmap) | 通过属性创建PixelMap，默认采用BGRA_8888格式处理数据，其他格式请参考[OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat)。 |
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapusingallocator) | 根据入参options创建pixelmap，pixelmap使用的内存类型可以通过allocator指定。默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理此接口返回的像素图时，需要考虑步长影响。 |
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative, napi_value *pixelmapNapi)](#oh_pixelmapnative_convertpixelmapnativetonapi) | 将nativePixelMap对象转换为PixelMapnapi对象。 |
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi, OH_PixelmapNative **pixelmapNative)](#oh_pixelmapnative_convertpixelmapnativefromnapi) | 将PixelMapnapi对象转换为nativePixelMap对象。 |
| [Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_readpixels) | 读取图像像素数据，并按照PixelMap的像素格式写入缓冲区中。 |
| [Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)](#oh_pixelmapnative_writepixels) | 读取缓冲区中的图像像素数据，并按照PixelMap的像素格式将结果写入PixelMap。 |
| [Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_getargbpixels) | 从PixelMap中读取ARGB格式的数据。 |
| [Image_ErrorCode OH_PixelmapNative_ToSdr(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_tosdr) | 将HDR的图像内容转换为SDR的图像内容。 |
| [Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)](#oh_pixelmapnative_getimageinfo) | 获取图像像素信息。 |
| [Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)](#oh_pixelmapnative_opacity) | 通过设置透明比率来让PixelMap达到对应的透明效果。 |
| [Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_scale) | 根据输入的宽高对图片进行缩放。 |
| [Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_scalewithantialiasing) | 根据指定的缩放算法和输入的宽高对图片进行缩放。 |
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_createscaledpixelmap) | 根据输入的宽高的缩放比例，创建一个新的缩放后的图片。 |
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_createscaledpixelmapwithantialiasing) | 根据指定的缩放算法和输入的宽高的缩放比例，创建一个新的缩放后的图片。 |
| [Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)](#oh_pixelmapnative_translate) | 根据输入的坐标对图片进行位置变换。 |
| [Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)](#oh_pixelmapnative_rotate) | 根据输入的角度对图片进行旋转。 |
| [Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically)](#oh_pixelmapnative_flip) | 根据输入的条件对图片进行翻转。 |
| [Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)](#oh_pixelmapnative_crop) | 根据输入的尺寸对图片进行裁剪。 |
| [Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_release) | 释放OH_PixelmapNative指针，推荐使用[OH_PixelmapNative_Destroy](#oh_pixelmapnative_destroy)。 |
| [Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_destroy) | 释放OH_PixelmapNative指针。 |
| [Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap, OH_PixelmapNative* dstpixelmap, const bool isPremul)](#oh_pixelmapnative_convertalphaformat) | 将pixelmap的像素数据做预乘和非预乘之间的转换。 |
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmap) | 利用OH_Pixelmap_InitializationOptions创建空的pixelmap对象，内存数据为0。 |
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmapusingallocator) | 根据入参options创建空的pixelmap，pixelmap使用的内存类型可以通过allocator指定。默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理此接口返回的像素图时，需要考虑步长影响。 |
| [Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)](#oh_pixelmapnative_getnativebuffer) | 从DMA内存的PixelMap中，获取NativeBuffer对象。 |
| [Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue **value)](#oh_pixelmapnative_getmetadata) | 获取元数据。 |
| [Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue *value)](#oh_pixelmapnative_setmetadata) | 设置元数据。 |
| [Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager *colorSpaceNative)](#oh_pixelmapnative_setcolorspacenative) | 设置NativeColorSpaceManager对象。 |
| [Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager **colorSpaceNative)](#oh_pixelmapnative_getcolorspacenative) | 获取NativeColorSpaceManager对象。 |
| [Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)](#oh_pixelmapnative_setmemoryname) | 设置pixelMap内存名字。 |
| [Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)](#oh_pixelmapnative_getbytecount) | 获取Pixelmap中所有像素所占用的总字节数，不包含内存填充。 |
| [Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)](#oh_pixelmapnative_getallocationbytecount) | 获取Pixelmap用于储存像素数据的内存字节数。 |
| [Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)](#oh_pixelmapnative_accesspixels) | 获取Pixelmap像素数据的内存地址，并锁定这块内存。<br>当该内存被锁定时，任何修改或释放该Pixelmap的像素数据的操作均会失败或无效。 |
| [Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_unaccesspixels) | 释放Pixelmap像素数据的内存锁。<br>该函数需要与[OH_PixelmapNative_AccessPixels](#oh_pixelmapnative_accesspixels)匹配使用。 |

## 枚举类型说明

### PIXELMAP_ALPHA_TYPE

```
enum PIXELMAP_ALPHA_TYPE
```

**描述**

Pixelmap透明度类型。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PIXELMAP_ALPHA_TYPE_UNKNOWN = 0 | 未知格式。 |
| PIXELMAP_ALPHA_TYPE_OPAQUE = 1 | 不透明的格式。 |
| PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2 | 预乘透明度格式。 |
| PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED = 3 | 非预乘透明度格式。 |

### PIXEL_FORMAT

```
enum PIXEL_FORMAT
```

**描述**

图片像素格式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| PIXEL_FORMAT_UNKNOWN = 0 | 未知格式。 |
| PIXEL_FORMAT_RGB_565 = 2 | RGB_565格式。 |
| PIXEL_FORMAT_RGBA_8888 = 3 | RGBA_8888格式。 |
| PIXEL_FORMAT_BGRA_8888 = 4 | BGRA_8888格式。 |
| PIXEL_FORMAT_RGB_888 = 5 | RGB_888格式。 |
| PIXEL_FORMAT_ALPHA_8 = 6 | ALPHA_8格式。 |
| PIXEL_FORMAT_RGBA_F16 = 7 | RGBA_F16格式。 |
| PIXEL_FORMAT_NV21 = 8 | NV21格式。 |
| PIXEL_FORMAT_NV12 = 9 | NV12格式。 |
| PIXEL_FORMAT_RGBA_1010102 = 10 | RGBA_1010102格式。 |
| PIXEL_FORMAT_YCBCR_P010 = 11 | YCBCR_P010格式。 |
| PIXEL_FORMAT_YCRCB_P010 =12 | YCRCB_P010格式。 |

### OH_PixelmapNative_AntiAliasingLevel

```
enum OH_PixelmapNative_AntiAliasingLevel
```

**描述**

Pixelmap缩放时采用的缩放算法。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_PixelmapNative_AntiAliasing_NONE = 0 | 最近邻插值算法。 |
| OH_PixelmapNative_AntiAliasing_LOW = 1 | 双线性插值算法。 |
| OH_PixelmapNative_AntiAliasing_MEDIUM = 2 | 双线性插值算法，同时开启Mipmap。缩小图片时建议使用。 |
| OH_PixelmapNative_AntiAliasing_HIGH = 3 | 三次插值算法。 |

### OH_Pixelmap_HdrMetadataKey

```
enum OH_Pixelmap_HdrMetadataKey
```

**描述**

Pixelmap使用的HDR相关元数据信息的关键字，用于[OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata)。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HDR_METADATA_TYPE = 0 | Pixelmap使用的元数据类型。 |
| HDR_STATIC_METADATA = 1 | 静态元数据。 |
| HDR_DYNAMIC_METADATA = 2 | 动态元数据。 |
| HDR_GAINMAP_METADATA = 3 | Gainmap使用的元数据。 |

### OH_Pixelmap_HdrMetadataType

```
enum OH_Pixelmap_HdrMetadataType
```

**描述**

HDR_METADATA_TYPE关键字对应的值。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HDR_METADATA_TYPE_NONE = 0 | 无元数据内容。 |
| HDR_METADATA_TYPE_BASE = 1 | 表示用于基础图的元数据。 |
| HDR_METADATA_TYPE_GAINMAP = 2 | 表示用于Gainmap图的元数据。 |
| HDR_METADATA_TYPE_ALTERNATE = 3 | 表示用于合成后HDR图的元数据。 |


## 函数说明

### OH_PixelmapInitializationOptions_Create()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Create(OH_Pixelmap_InitializationOptions **options)
```

**描述**

创建OH_Pixelmap_InitializationOptions指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) **options | 被创建的OH_Pixelmap_InitializationOptions指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth(OH_Pixelmap_InitializationOptions *options,uint32_t *width)
```

**描述**

获取图片宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t *width | 图片的宽，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth(OH_Pixelmap_InitializationOptions *options,uint32_t width)
```

**描述**

设置图片宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t width | 图片的宽，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight(OH_Pixelmap_InitializationOptions *options,uint32_t *height)
```

**描述**

获取图片高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t *height | 图片的高，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight(OH_Pixelmap_InitializationOptions *options,uint32_t height)
```

**描述**

设置图片高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t height | 图片的高，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t *pixelFormat)
```

**描述**

获取像素格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t *pixelFormat | 像素格式[PIXEL_FORMAT](#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t pixelFormat)
```

**描述**

设置像素格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t pixelFormat | 像素格式[PIXEL_FORMAT](#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t *srcpixelFormat)
```

**描述**

获取源像素格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t *srcpixelFormat | 像素格式[PIXEL_FORMAT](#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options,int32_t srcpixelFormat)
```

**描述**

设置源像素格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t srcpixelFormat | 源像素格式[PIXEL_FORMAT](#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options,int32_t *rowStride)
```

**描述**

获取行跨距。<br> 跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t *rowStride | 跨距，单位：字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNKNOWN_ERROR：options被释放。 |

### OH_PixelmapInitializationOptions_SetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options,int32_t rowStride)
```

**描述**

设置图像跨距。<br>跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t rowStride | 跨距，单位：字节。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNKNOWN_ERROR：options被释放。 |

### OH_PixelmapInitializationOptions_GetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options,int32_t *alphaType)
```

**描述**

获取透明度类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t *alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options,int32_t alphaType)
```

**描述**

设置透明度类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetEditable()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options,bool *editable)
```

**描述**

获取可编辑标志。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| bool *editable | 可编辑标志。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetEditable()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options,bool editable)
```

**描述**

设置可编辑标志。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| bool editable | 可编辑标志。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_Release()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Release(OH_Pixelmap_InitializationOptions *options)
```

**描述**

释放OH_Pixelmap_InitializationOptions指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被释放的OH_Pixelmap_InitializationOptions指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_Create()

```
Image_ErrorCode OH_PixelmapImageInfo_Create(OH_Pixelmap_ImageInfo **info)
```

**描述**

创建OH_Pixelmap_ImageInfo指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) **info | 被创建的OH_Pixelmap_ImageInfo指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetWidth()

```
Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)
```

**描述**

获取图片宽。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| uint32_t *width | 图片宽，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetHeight()

```
Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)
```

**描述**

获取图片高。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| uint32_t *height | 图片高，单位：像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetAlphaMode()

```
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *AlphaMode)
```

**描述**

获取图片alpha格式。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| int32_t *AlphaMode | 被操作的alpha格式的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetRowStride()

```
Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)
```

**描述**

获取行跨距。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| uint32_t *rowStride | 跨距，内存中每行像素所占的空间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)
```

**描述**

获取像素格式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| int32_t *pixelFormat | 像素格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetAlphaType()

```
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)
```

**描述**

获取透明度类型。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| int32_t *alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetDynamicRange()

```
Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)
```

**描述**

获取Pixelmap是否为高动态范围的信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| bool *isHdr | 是否为hdr的布尔值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_PixelmapImageInfo_Release()

```
Image_ErrorCode OH_PixelmapImageInfo_Release(OH_Pixelmap_ImageInfo *info)
```

**描述**

释放OH_Pixelmap_ImageInfo指针。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被释放的OH_Pixelmap_ImageInfo指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_CreatePixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength,OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```

**描述**

通过属性创建PixelMap，默认采用BGRA_8888格式处理数据，其他格式请参考[OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | BGRA_8888格式的颜色数组。 |
| size_t dataLength | 数组长度。 |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建像素的属性。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。 |

### OH_PixelmapNative_CreatePixelmapUsingAllocator()

```
Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength,OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**描述**

根据入参options创建pixelmap，pixelmap使用的内存类型可以通过allocator指定。默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理此接口返回的像素图时，需要考虑步长影响。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | BGRA_8888格式的数据。 |
| size_t dataLength | 数组长度。 |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建pixelmap的选项。 |
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | 决定pixelmap内存分配的类型。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。<br>         IMAGE_TOO_LARGE：图像过大，无法分配内存。<br>         IMAGE_DMA_OPERATION_FAILED：DMA内存操作失败。<br>         IMAGE_ALLOCATOR_MODE_UNSUPPORTED：不支持分配当前内存类型。例如，使用共享内存创建HDR图。 |

### OH_PixelmapNative_ConvertPixelmapNativeToNapi()

```
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative,napi_value *pixelmapNapi)
```

**描述**

将nativePixelMap对象转换为PixelMapnapi对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmapNative | 被操作的OH_PixelmapNative指针。 |
| napi_value *pixelmapNapi | 转换出来的PixelMapnapi对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmapNative为空。 |

### OH_PixelmapNative_ConvertPixelmapNativeFromNapi()

```
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi,OH_PixelmapNative **pixelmapNative)
```

**描述**

将PixelMapnapi对象转换为nativePixelMap对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | napi的环境指针。 |
| napi_value pixelmapNapi | 需要转换的PixelMapnapi对象。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapNative | 转换出的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmapNative是nullptr，或者pixelmapNapi不是PixelMapNapi对象。 |

### OH_PixelmapNative_ReadPixels()

```
Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**描述**

读取图像像素数据，并按照PixelMap的像素格式写入缓冲区中。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| uint8_t *destination | 缓冲区，获取的图像像素数据写入到该内存区域内。 |
| size_t *bufferSize | 缓冲区大小。RGBA格式的缓冲区大小等于width \* height \* 4，NV21与NV12格式的缓冲区大小等于width \* height+((width+1)/2) \* ((height+1)/2) \* 2。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_PixelmapNative_WritePixels()

```
Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)
```

**描述**

读取缓冲区中的图像像素数据，并按照PixelMap的像素格式将结果写入PixelMap。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| uint8_t *source | 图像像素数据。 |
| size_t bufferSize | 图像像素数据长度。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。<br>         IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_PixelmapNative_GetArgbPixels()

```
Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**描述**

从PixelMap中读取ARGB格式的数据。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| uint8_t *destination | 缓冲区，获取的图像像素数据写入到该内存区域内。 |
| size_t *bufferSize | 缓冲区大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_CONVERSION：PixelMap格式不支持读取ARGB数据。<br>         IMAGE_ALLOC_FAILED：内存申请失败。<br>         IMAGE_COPY_FAILED：内存数据拷贝、读取、操作失败。 |

### OH_PixelmapNative_ToSdr()

```
Image_ErrorCode OH_PixelmapNative_ToSdr(OH_PixelmapNative *pixelmap)
```

**描述**

将HDR的图像内容转换为SDR的图像内容。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。 |

### OH_PixelmapNative_GetImageInfo()

```
Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)
```

**描述**

获取图像像素信息。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *imageInfo | 图像像素信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Opacity()

```
Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)
```

**描述**

通过设置透明比率来让PixelMap达到对应的透明效果。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float rate | 透明比率的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Scale()

```
Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)
```

**描述**

根据输入的宽高对图片进行缩放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float scaleX | 宽度的缩放比例。 |
| float scaleY | 高度的缩放比例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ScaleWithAntiAliasing()

```
Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY,OH_PixelmapNative_AntiAliasingLevel level)
```

**描述**

根据指定的缩放算法和输入的宽高对图片进行缩放。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float scaleX | 宽度的缩放比例。 |
| float scaleY | 高度的缩放比例。 |
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | 缩放算法。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_TOO_LARGE：图片过大。<br>         IMAGE_ALLOC_FAILED：内存申请失败。<br>         IMAGE_UNKNOWN_ERROR：pixelmap已经被释放。 |

### OH_PixelmapNative_CreateScaledPixelMap()

```
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap,float scaleX, float scaleY)
```

**描述**

根据输入的宽高的缩放比例，创建一个新的缩放后的图片。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 被操作的OH_PixelmapNative指针，源pixelmap对象指针。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | 被操作的OH_PixelmapNative指针，目标pixelmap对象指针。 |
| float scaleX | 宽度的缩放比例。 |
| float scaleY | 高度的缩放比例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing()

```
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap,OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**描述**

根据指定的缩放算法和输入的宽高的缩放比例，创建一个新的缩放后的图片。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 被操作的OH_PixelmapNative指针，源pixelmap对象指针。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | 被操作的OH_PixelmapNative指针，目标pixelmap对象指针。 |
| float scaleX | 宽度的缩放比例。 |
| float scaleY | 高度的缩放比例。 |
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | 缩放算法。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_TOO_LARGE：图片过大。<br>         IMAGE_ALLOC_FAILED：内存申请失败。 |

### OH_PixelmapNative_Translate()

```
Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)
```

**描述**

根据输入的坐标对图片进行位置变换。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float x | 区域横坐标。 |
| float y | 区域纵坐标。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Rotate()

```
Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)
```

**描述**

根据输入的角度对图片进行旋转。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float angle | 图片旋转的角度，单位为deg。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Flip()

```
Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically)
```

**描述**

根据输入的条件对图片进行翻转。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| bool shouldFilpHorizontally | 是否水平翻转图像。 |
| bool shouldFilpVertically | 是否垂直翻转图像。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Crop()

```
Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)
```

**描述**

根据输入的尺寸对图片进行裁剪。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *region | 裁剪的尺寸。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Release()

```
Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)
```

**描述**

释放OH_PixelmapNative指针，推荐使用[OH_PixelmapNative_Destroy](#oh_pixelmapnative_destroy)。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被释放的OH_PixelmapNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Destroy()

```
Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)
```

**描述**

释放OH_PixelmapNative指针。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被释放的OH_PixelmapNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ConvertAlphaFormat()

```
Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap,OH_PixelmapNative* dstpixelmap, const bool isPremul)
```

**描述**

将pixelmap的像素数据做预乘和非预乘之间的转换。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* srcpixelmap | 被操作的OH_PixelmapNative指针，源pixelmap对象指针。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* dstpixelmap | 被操作的OH_PixelmapNative指针，目标pixelmap对象指针。 |
| const bool isPremul | 转换方式，true为非预乘转预乘，false为预乘转非预乘。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_CreateEmptyPixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options,OH_PixelmapNative **pixelmap)
```

**描述**

利用OH_Pixelmap_InitializationOptions创建空的pixelmap对象，内存数据为0。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建像素的属性。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator()

```
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**描述**

根据入参options创建空的pixelmap，pixelmap使用的内存类型可以通过allocator指定。默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理此接口返回的像素图时，需要考虑步长影响。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建pixelmap的选项。 |
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | 决定pixelmap内存分配的类型。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。<br>         IMAGE_TOO_LARGE：图像过大，无法分配内存。<br>         IMAGE_DMA_OPERATION_FAILED：DMA内存操作失败。<br>         IMAGE_ALLOCATOR_MODE_UNSUPPORTED：不支持分配当前内存类型。例如，使用共享内存创建HDR图。 |

### OH_PixelmapNative_GetNativeBuffer()

```
Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)
```

**描述**

从DMA内存的PixelMap中，获取NativeBuffer对象。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 要获取NativeBuffer的源PixelMap。 |
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) **nativeBuffer | 被创建的NativeBuffer对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DMA_NOT_EXIST：不是DMA内存。<br>         IMAGE_DMA_OPERATION_FAILED：DMA内存操作失败。 |

### OH_PixelmapNative_GetMetadata()

```
Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key,OH_Pixelmap_HdrMetadataValue **value)
```

**描述**

获取元数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key | 元数据的关键字。 |
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) **value | 元数据的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DMA_NOT_EXIST：不存在DMA内存。<br>         IMAGE_COPY_FAILED：如果内存拷贝失败。 |

### OH_PixelmapNative_SetMetadata()

```
Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key,OH_Pixelmap_HdrMetadataValue *value)
```

**描述**

设置元数据。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key | 元数据的关键字。 |
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) *value | 元数据的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DMA_NOT_EXIST：不存在DMA内存。<br>         IMAGE_COPY_FAILED：如果内存拷贝失败。 |

### OH_PixelmapNative_SetColorSpaceNative()

```
Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap,OH_NativeColorSpaceManager *colorSpaceNative)
```

**描述**

设置NativeColorSpaceManager对象。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 要设置NativeColorSpaceManager的目标PixelMap。 |
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) *colorSpaceNative | 要设置的NativeColorSpaceManager对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_GetColorSpaceNative()

```
Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap,OH_NativeColorSpaceManager **colorSpaceNative)
```

**描述**

获取NativeColorSpaceManager对象。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 获取到NativeColorSpaceManager的源PixelMap。 |
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) **colorSpaceNative | 获取到的NativeColorSpaceManager对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_SetMemoryName()

```
Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)
```

**描述**

设置pixelMap内存名字。

**起始版本：** 13


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| char *name | 需要被设置的PixelMap内存名称。 |
| size_t *size | 需要被设置的PixelMap内存名称的字节大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：名字长度超过取值范围。DMA内存名字取值范围为[1, 255]，ASHMEM内存名字取值范围为[1, 244]，单位字节。<br>         IMAGE_UNSUPPORTED_MEMORY_FORMAT：既不是DMA内存也不是ASHMEM内存。 |

### OH_PixelmapNative_GetByteCount()

```
Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)
```

**描述**

获取Pixelmap中所有像素所占用的总字节数，不包含内存填充。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的Pixelmap指针。 |
| uint32_t *byteCount | 获取的总字节数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmap或byteCount参数无效。 |

### OH_PixelmapNative_GetAllocationByteCount()

```
Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)
```

**描述**

获取Pixelmap用于储存像素数据的内存字节数。

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的Pixelmap指针。 |
| uint32_t *allocationByteCount | 获取的内存字节数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmap或allocationByteCount参数无效。 |

### OH_PixelmapNative_AccessPixels()

```
Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)
```

**描述**

获取Pixelmap像素数据的内存地址，并锁定这块内存。<br>当该内存被锁定时，任何修改或释放该Pixelmap的像素数据的操作均会失败或无效。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的Pixelmap指针。 |
| void **addr | Pixelmap内存地址的双指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmap或addr参数无效。<br>         IMAGE_LOCK_UNLOCK_FAILED：内存锁定失败。 |

### OH_PixelmapNative_UnaccessPixels()

```
Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)
```

**描述**

释放Pixelmap像素数据的内存锁。<br>该函数需要与[OH_PixelmapNative_AccessPixels](#oh_pixelmapnative_accesspixels)匹配使用。

**起始版本：** 15


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的Pixelmap指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmap参数无效。<br>         IMAGE_LOCK_UNLOCK_FAILED：内存解锁失败。 |


