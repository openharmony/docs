# pixelmap_native.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yaozhupeng-->
<!--Designer: @yaozhupeng-->
<!--Tester: @zhaoxiaoguang2-->
<!--Adviser: @w_Machine_cc-->

## 概述

访问Pixelmap的API。提供对Pixelmap（像素图）的访问能力，支持通过像素数据、Surface、NativeBuffer等多种方式创建像素图、克隆像素图、读写像素数据，以及进行缩放、旋转、翻转、平移、裁剪等图像变换操作，同时支持HDR元数据管理、色彩空间设置、透明度类型转换、Native与Napi对象互转和内存直接访问等功能，适用于需要在Native层对解码后的图像位图进行像素级处理与变换的场景。

**引用文件：** <multimedia/image_framework/image/pixelmap_native.h>

**库：** libpixelmap.so

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：** [Image_NativeModule](capi-image-nativemodule.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_Pixelmap_HdrStaticMetadata](capi-image-nativemodule-oh-pixelmap-hdrstaticmetadata.md) | OH_Pixelmap_HdrStaticMetadata | [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey)中HDR_STATIC_METADATA关键字对应的元数据值类型，用于存储HDR静态元数据。 |
| [OH_Pixelmap_HdrDynamicMetadata](capi-image-nativemodule-oh-pixelmap-hdrdynamicmetadata.md) | OH_Pixelmap_HdrDynamicMetadata | [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey)中HDR_DYNAMIC_METADATA关键字对应的元数据值类型，用于存储HDR动态元数据，格式遵循相关HDR动态元数据标准。 |
| [OH_Pixelmap_HdrGainmapMetadata](capi-image-nativemodule-oh-pixelmap-hdrgainmapmetadata.md) | OH_Pixelmap_HdrGainmapMetadata | [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey)中HDR_GAINMAP_METADATA关键字对应的元数据值类型，用于存储HDR增益图元数据，参考ISO 21496-1。 |
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) | OH_Pixelmap_HdrMetadataValue | Pixelmap使用的HDR元数据值，和[OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey)关键字相对应。当传入相应的[OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey)关键字作为入参时，可通过本结构体设置或获取对应类型的元数据值，用于[OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata)。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) | - | OH_PixelmapNative结构体是Native层封装的图像解码后无压缩的位图格式结构体。<br> 创建OH_PixelmapNative使用[OH_PixelmapNative_CreatePixelmap](#oh_pixelmapnative_createpixelmap)函数，默认采用BGRA_8888格式处理数据。<br> 释放OH_PixelmapNative对象使用[OH_PixelmapNative_Release](#oh_pixelmapnative_release)函数。 |
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) | - | NativeBuffer结构体类型，用于执行NativeBuffer相关操作。 |
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) | OH_NativeColorSpaceManager | NativeColorSpaceManager结构体类型，用于执行NativeColorSpaceManager相关操作。 |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) | - | OH_Pixelmap_InitializationOptions是Native层封装的初始化参数结构体，用于设置Pixelmap的初始化参数。<br> 创建OH_Pixelmap_InitializationOptions对象使用[OH_PixelmapInitializationOptions_Create](#oh_pixelmapinitializationoptions_create)函数。<br> 释放OH_Pixelmap_InitializationOptions对象使用[OH_PixelmapInitializationOptions_Release](#oh_pixelmapinitializationoptions_release)函数。 |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) | - | 图像像素信息结构体。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type) | PIXELMAP_ALPHA_TYPE | Pixelmap透明度类型。 |
| [PIXEL_FORMAT](#pixel_format) | PIXEL_FORMAT | 图像的像素格式，包含像素数据的颜色通道排列和位深信息。 |
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) | OH_PixelmapNative_AntiAliasingLevel | Pixelmap缩放时采用的缩放算法。 |
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) | OH_Pixelmap_HdrMetadataKey | Pixelmap使用的HDR相关元数据信息的关键字，用于[OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata)。 |
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
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *srcpixelFormat)](#oh_pixelmapinitializationoptions_getsrcpixelformat) | 获取源像素格式（创建Pixelmap时输入数据的像素格式）。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t srcpixelFormat)](#oh_pixelmapinitializationoptions_setsrcpixelformat) | 设置源像素格式（创建Pixelmap时输入数据的像素格式）。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t *rowStride)](#oh_pixelmapinitializationoptions_getrowstride) | 获取行跨距。<br> 跨距，图像每行像素占用的真实内存大小。单位：字节（Byte）。跨距 = 图像宽度 \* 每像素字节数 + 填充（padding），填充是每行像素的末尾为内存对齐所增加的空白区域。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t rowStride)](#oh_pixelmapinitializationoptions_setrowstride) | 设置行跨距。<br> 跨距，图像每行像素占用的真实内存大小。单位：字节（Byte）。跨距 = 图像宽度 \* 每像素字节数 + 填充（padding），填充是每行像素的末尾为内存对齐所增加的空白区域。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t *alphaType)](#oh_pixelmapinitializationoptions_getalphatype) | 获取透明度类型。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t alphaType)](#oh_pixelmapinitializationoptions_setalphatype) | 设置透明度类型。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options, bool *editable)](#oh_pixelmapinitializationoptions_geteditable) | 获取可编辑标志。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options, bool editable)](#oh_pixelmapinitializationoptions_seteditable) | 设置可编辑标志。 |
| [Image_ErrorCode OH_PixelmapInitializationOptions_Release(OH_Pixelmap_InitializationOptions *options)](#oh_pixelmapinitializationoptions_release) | 释放OH_Pixelmap_InitializationOptions指针。 |
| [Image_ErrorCode OH_PixelmapImageInfo_Create(OH_Pixelmap_ImageInfo **info)](#oh_pixelmapimageinfo_create) | 创建OH_Pixelmap_ImageInfo指针。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)](#oh_pixelmapimageinfo_getwidth) | 获取图片宽。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)](#oh_pixelmapimageinfo_getheight) | 获取图片高。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *alphaMode)](#oh_pixelmapimageinfo_getalphamode) | 获取图片透明通道类型。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)](#oh_pixelmapimageinfo_getrowstride) | 获取行跨距。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)](#oh_pixelmapimageinfo_getpixelformat) | 获取像素格式。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)](#oh_pixelmapimageinfo_getalphatype) | 获取OH_PixelmapImageInfo默认的透明度类型。若要获取图片当前透明度类型，请使用[OH_PixelmapImageInfo_GetAlphaMode](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getalphamode)。 |
| [Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)](#oh_pixelmapimageinfo_getdynamicrange) | 获取Pixelmap是否为高动态范围的信息。 |
| [Image_ErrorCode OH_PixelmapImageInfo_Release(OH_Pixelmap_ImageInfo *info)](#oh_pixelmapimageinfo_release) | 释放OH_Pixelmap_ImageInfo指针。 |
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmap) | 通过像素数据和图像属性创建Pixelmap。<br>此接口不支持创建以下像素格式的Pixelmap：PIXEL_FORMAT_RGBA_1010102、PIXEL_FORMAT_YCBCR_P010和PIXEL_FORMAT_YCRCB_P010。 |
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapusingallocator) | 通过像素数据和图像属性创建Pixelmap，可以通过allocator指定内存类型。<br>默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。<br>在处理此接口返回的像素图时，需要考虑行跨距的影响。行跨距即图像每行占用的真实内存大小，可能因内存对齐而大于图像宽度乘以单位像素字节数，请参考[OH_PixelmapInitializationOptions_GetRowStride](capi-pixelmap-native-h.md#oh_pixelmapinitializationoptions_getrowstride)获取详细说明。 |
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative, napi_value *pixelmapNapi)](#oh_pixelmapnative_convertpixelmapnativetonapi) | 将OH_PixelmapNative对象转换为PixelmapNapi对象。 |
| [Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi, OH_PixelmapNative **pixelmapNative)](#oh_pixelmapnative_convertpixelmapnativefromnapi) | 将PixelmapNapi对象转换为OH_PixelmapNative对象。 |
| [Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_readpixels) | 读取图像像素数据，并按照Pixelmap的像素格式存入缓冲区中。 |
| [Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)](#oh_pixelmapnative_writepixels) | 将缓冲区中的图像像素数据按照Pixelmap的像素格式写入Pixelmap。 |
| [Image_ErrorCode OH_PixelmapNative_ReadPixelsFromArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)](#oh_pixelmapnative_readpixelsfromarea) | 从Pixelmap的指定区域中读取像素数据并存入缓冲区。如果Pixelmap的像素格式为YUV类型，则会按照Pixelmap的像素格式存入缓冲区，否则会按照BGRA_8888格式存入缓冲区。 |
| [Image_ErrorCode OH_PixelmapNative_WritePixelsToArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)](#oh_pixelmapnative_writepixelstoarea) | 将缓冲区中的像素数据写入Pixelmap的指定区域。如果Pixelmap的像素格式为YUV类型，则数据源的格式需与Pixelmap相同，否则数据源需要为BGRA_8888格式。 |
| [Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)](#oh_pixelmapnative_getargbpixels) | 从Pixelmap中读取ARGB格式的数据。 |
| [Image_ErrorCode OH_PixelmapNative_ToSdr(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_tosdr) | 将HDR的图像内容转换为SDR的图像内容。 |
| [Image_ErrorCode OH_PixelmapNative_GetImageInfo(OH_PixelmapNative *pixelmap, OH_Pixelmap_ImageInfo *imageInfo)](#oh_pixelmapnative_getimageinfo) | 获取图像像素信息。 |
| [Image_ErrorCode OH_PixelmapNative_SetOpacity(OH_PixelmapNative *pixelmap, float value)](#oh_pixelmapnative_setopacity) | 设置Pixelmap的不透明度。指定的不透明度值将被应用于所有像素。 |
| [Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)](#oh_pixelmapnative_opacity) | 设置Pixelmap的不透明度。指定的不透明度值将被应用于所有像素。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_SetOpacity](capi-pixelmap-native-h.md#oh_pixelmapnative_setopacity)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_ApplyScale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_applyscale) | 根据指定的宽高缩放倍数对Pixelmap进行水平或垂直方向的缩放。 |
| [Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_scale) | 根据输入的缩放比例对Pixelmap进行缩放。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyScale](capi-pixelmap-native-h.md#oh_pixelmapnative_applyscale)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_ApplyScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_applyscalewithantialiasing) | 根据指定的宽高缩放倍数和缩放算法对Pixelmap进行水平或垂直方向的缩放。 |
| [Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_scalewithantialiasing) | 根据指定的缩放算法和输入的缩放比例对图片进行缩放。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyScaleWithAntiAliasing](capi-pixelmap-native-h.md#oh_pixelmapnative_applyscalewithantialiasing)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY)](#oh_pixelmapnative_createscaledpixelmap) | 根据输入的宽高的缩放比例，创建一个新的缩放后的图像，生成的新Pixelmap不可编辑。该接口不会拷贝原图像的HDR元数据和EXIF信息。 |
| [Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)](#oh_pixelmapnative_createscaledpixelmapwithantialiasing) | 根据指定的缩放算法和输入的宽高的缩放比例，创建一个新的缩放后的图像，生成的新Pixelmap不可编辑。该接口不会拷贝原图像的HDR元数据和EXIF信息。 |
| [Image_ErrorCode OH_PixelmapNative_CreateAlphaPixelmap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)](#oh_pixelmapnative_createalphapixelmap) | 从源Pixelmap创建一个仅包含Alpha通道的ALPHA_8格式的Pixelmap，生成的新Pixelmap不可编辑。<br>若源Pixelmap的格式是ALPHA_F16，则新生成的Pixelmap将维持ALPHA_F16格式。 |
| [Image_ErrorCode OH_PixelmapNative_Clone(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)](#oh_pixelmapnative_clone) | 对源Pixelmap进行拷贝，生成一个新的Pixelmap。该接口不会拷贝原图像的EXIF信息。 |
| [Image_ErrorCode OH_PixelmapNative_CreateCroppedAndScaledPixelMap(OH_PixelmapNative *srcPixelmap, Image_Region *region, Image_Scale *scale, OH_PixelmapNative_AntiAliasingLevel level, OH_PixelmapNative **dstPixelmap)](#oh_pixelmapnative_createcroppedandscaledpixelmap) | 基于源Pixelmap创建一个裁剪并缩放的新Pixelmap。该接口不会拷贝原图像的EXIF信息。 |
| [Image_ErrorCode OH_PixelmapNative_ApplyTranslate(OH_PixelmapNative *pixelmap, float x, float y)](#oh_pixelmapnative_applytranslate) | 根据指定的横向和纵向距离对Pixelmap进行水平或垂直方向的平移。<br>平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。 |
| [Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)](#oh_pixelmapnative_translate) | 根据输入的平移距离对图片进行位置变换。<br>平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyTranslate](capi-pixelmap-native-h.md#oh_pixelmapnative_applytranslate)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_ApplyRotate(OH_PixelmapNative *pixelmap, float angle)](#oh_pixelmapnative_applyrotate) | 根据指定的角度对Pixelmap进行旋转。YUV格式仅支持90°倍数的旋转角。 |
| [Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)](#oh_pixelmapnative_rotate) | 根据输入的角度对图片进行旋转，YUV格式仅支持90°倍数的旋转角。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyRotate](capi-pixelmap-native-h.md#oh_pixelmapnative_applyrotate)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_ApplyFlip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)](#oh_pixelmapnative_applyflip) | 根据指定的水平或垂直翻转条件对Pixelmap进行翻转。 |
| [Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)](#oh_pixelmapnative_flip) | 根据输入的条件对图片进行翻转。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyFlip](capi-pixelmap-native-h.md#oh_pixelmapnative_applyflip)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_ApplyCrop(OH_PixelmapNative *pixelmap, Image_Region *region)](#oh_pixelmapnative_applycrop) | 根据指定的区域信息对Pixelmap进行裁剪。 |
| [Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)](#oh_pixelmapnative_crop) | 根据输入的区域信息对图片进行裁剪。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyCrop](capi-pixelmap-native-h.md#oh_pixelmapnative_applycrop)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_release) | 释放OH_PixelmapNative指针（当内存被[OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels)锁定时无法释放）。<br>推荐使用[OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy)。 |
| [Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_destroy) | 释放OH_PixelmapNative指针，不受[OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels)锁定内存的影响。 |
| [Image_ErrorCode OH_PixelmapNative_ConvertAlphaType(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative *dstPixelmap, const bool toPremul)](#oh_pixelmapnative_convertalphatype) | 将Pixelmap像素数据的透明度类型在预乘模式（[PIXELMAP_ALPHA_TYPE_PREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)）和非预乘模式（[PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)）之间转换。该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。<br>     像素格式的列表请参考[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |
| [Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap, OH_PixelmapNative* dstpixelmap, const bool isPremul)](#oh_pixelmapnative_convertalphaformat) | 将Pixelmap像素数据的透明度类型在预乘模式和非预乘模式之间转换。该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ConvertAlphaType](capi-pixelmap-native-h.md#oh_pixelmapnative_convertalphatype)代替，以获得更完善的异常报错信息。 |
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmap) | 利用OH_Pixelmap_InitializationOptions创建空的Pixelmap对象，内存数据为0。 |
| [Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createemptypixelmapusingallocator) | 根据入参options创建空的Pixelmap，Pixelmap使用的内存类型可以通过allocator指定。默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理此接口返回的像素图时，需要考虑行跨距的影响。行跨距即图像每行占用的真实内存大小，可能因内存对齐而大于图像宽度乘以单位像素字节数，请参考[OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride)获取详细说明。 |
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurface(const char *surfaceId, size_t length, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapfromsurface) | 通过Surface的ID创建一个Pixelmap。如果Surface携带旋转或翻转的变换信息且需要校正方向，请使用[OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation](#oh_pixelmapnative_createpixelmapfromsurfacewithtransformation)。 |
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation(const char *surfaceId, size_t length, bool transformEnabled, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapfromsurfacewithtransformation) | 通过Surface的ID创建一个预览流画面的Pixelmap对象。该Surface可能携带旋转或翻转的变换信息。 |
| [Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromNativeBuffer(OH_NativeBuffer *nativeBuffer, OH_PixelmapNative **pixelmap)](#oh_pixelmapnative_createpixelmapfromnativebuffer) | 通过NativeBuffer创建一个Pixelmap。如果NativeBuffer的用途未配置CPU访问权限（详情请参考[OH_NativeBuffer_Usage](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_usage)），则不支持创建。<br> 支持创建的像素格式为RGBA_8888、NV21、NV12、YCBCR_P010、YCRCB_P010。 |
| [Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)](#oh_pixelmapnative_getnativebuffer) | 从DMA内存的Pixelmap中，获取NativeBuffer对象。 |
| [Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue **value)](#oh_pixelmapnative_getmetadata) | 获取Pixelmap的HDR元数据。 |
| [Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue *value)](#oh_pixelmapnative_setmetadata) | 设置Pixelmap的HDR元数据。 |
| [Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager *colorSpaceNative)](#oh_pixelmapnative_setcolorspacenative) | 设置Pixelmap的NativeColorSpaceManager对象，用于管理Pixelmap的色彩空间信息。 |
| [Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager **colorSpaceNative)](#oh_pixelmapnative_getcolorspacenative) | 获取Pixelmap的NativeColorSpaceManager对象，用于查询Pixelmap当前配置的色彩空间信息。 |
| [Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)](#oh_pixelmapnative_setmemoryname) | 设置Pixelmap内存名称，便于在内存调试或问题定位时识别该内存。 |
| [Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)](#oh_pixelmapnative_getbytecount) | 获取Pixelmap中所有像素所占用的总字节数，不包含内存对齐填充字节。 |
| [Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)](#oh_pixelmapnative_getallocationbytecount) | 获取Pixelmap实际分配的用于存储像素数据的内存字节数，包含内存对齐填充字节。与[OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount)（不包含内存填充）不同，本接口返回的是系统为Pixelmap分配的真实内存大小。 |
| [Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)](#oh_pixelmapnative_accesspixels) | 获取Pixelmap像素数据的内存地址，并锁定这块内存。<br> 当该内存被锁定时，任何修改或释放该Pixelmap的像素数据的操作均会失败或无效。<br> 使用完毕后，必须调用[OH_PixelmapNative_UnaccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_unaccesspixels)释放内存锁，两者需配对使用。 |
| [Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)](#oh_pixelmapnative_unaccesspixels) | 释放Pixelmap像素数据的内存锁。<br> 该函数需要与[OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels)匹配使用。 |
| [Image_ErrorCode OH_PixelmapNative_GetUniqueId(OH_PixelmapNative *pixelmap, uint32_t *uniqueId)](#oh_pixelmapnative_getuniqueid) | 获取Pixelmap的唯一ID。 |
| [Image_ErrorCode OH_PixelmapNative_IsReleased(OH_PixelmapNative *pixelmap, bool *released)](#oh_pixelmapnative_isreleased) | 检测Pixelmap是否已被释放。如果已被释放，则任何访问该对象内部数据的方法调用将会失效。 |

## 枚举类型说明

### PIXELMAP_ALPHA_TYPE

```c
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

```c
enum PIXEL_FORMAT
```

**描述**

图像的像素格式，包含像素数据的颜色通道排列和位深信息。

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
| PIXEL_FORMAT_YCRCB_P010 = 12 | YCRCB_P010格式。 |
| PIXEL_FORMAT_ALPHA_U8 = 15 | ALPHA_U8格式。<br>**起始版本：** 26.0.0 |
| PIXEL_FORMAT_ALPHA_F16 = 16 | ALPHA_F16格式。<br>**起始版本：** 26.0.0 |

### OH_PixelmapNative_AntiAliasingLevel

```c
enum OH_PixelmapNative_AntiAliasingLevel
```

**描述**

Pixelmap缩放时采用的缩放算法。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| OH_PixelmapNative_AntiAliasing_NONE = 0 | 最近邻插值算法。<br>速度最快，放大时会有明显的马赛克/锯齿感，适合对性能要求高、对画质要求低的快速缩放场景。 |
| OH_PixelmapNative_AntiAliasing_LOW = 1 | 双线性插值算法。<br>适合一般缩放场景。 |
| OH_PixelmapNative_AntiAliasing_MEDIUM = 2 | 双线性插值算法，同时开启Mipmap。<br>适合缩小图片的场景，能极好地消除大幅缩小时的混叠与纹理闪烁。 |
| OH_PixelmapNative_AntiAliasing_HIGH = 3 | 三次卷积插值算法。<br>适合对画质要求较高的放大场景。 |

### OH_Pixelmap_HdrMetadataKey

```c
enum OH_Pixelmap_HdrMetadataKey
```

**描述**

Pixelmap使用的HDR相关元数据信息的关键字，用于[OH_PixelmapNative_SetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](capi-pixelmap-native-h.md#oh_pixelmapnative_getmetadata)。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| HDR_METADATA_TYPE = 0 | Pixelmap使用的元数据类型。 |
| HDR_STATIC_METADATA = 1 | 静态元数据。 |
| HDR_DYNAMIC_METADATA = 2 | 动态元数据。 |
| HDR_GAINMAP_METADATA = 3 | 增益图使用的元数据。 |

### OH_Pixelmap_HdrMetadataType

```c
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

```c
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

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t *width)
```

**描述**

获取图片宽。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t *width | 图片的宽，单位：像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetWidth()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth(OH_Pixelmap_InitializationOptions *options, uint32_t width)
```

**描述**

设置图片宽。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t width | 图片的宽，单位：像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetHeight()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t *height)
```

**描述**

获取图片高。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t *height | 图片的高，单位：像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetHeight()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight(OH_Pixelmap_InitializationOptions *options, uint32_t height)
```

**描述**

设置图片高。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| uint32_t height | 图片的高，单位：像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetPixelFormat()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *pixelFormat)
```

**描述**

获取像素格式。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t *pixelFormat | 像素格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetPixelFormat()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t pixelFormat)
```

**描述**

设置像素格式。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t pixelFormat | 像素格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetSrcPixelFormat()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t *srcpixelFormat)
```

**描述**

获取源像素格式（创建Pixelmap时输入数据的像素格式）。

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

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat(OH_Pixelmap_InitializationOptions *options, int32_t srcpixelFormat)
```

**描述**

设置源像素格式（创建Pixelmap时输入数据的像素格式）。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t srcpixelFormat | 源像素格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetRowStride()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t *rowStride)
```

**描述**

获取行跨距。<br> 跨距，图像每行像素占用的真实内存大小。单位：字节（Byte）。跨距 = 图像宽度 \* 每像素字节数 + 填充（padding），填充是每行像素的末尾为内存对齐所增加的空白区域。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t *rowStride | 跨距，单位：字节（Byte）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNKNOWN_ERROR：options被释放。 |

### OH_PixelmapInitializationOptions_SetRowStride()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride(OH_Pixelmap_InitializationOptions *options, int32_t rowStride)
```

**描述**

设置行跨距。<br> 跨距，图像每行像素占用的真实内存大小。单位：字节（Byte）。跨距 = 图像宽度 \* 每像素字节数 + 填充（padding），填充是每行像素的末尾为内存对齐所增加的空白区域。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t rowStride | 跨距，单位：字节（Byte）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNKNOWN_ERROR：options被释放。 |

### OH_PixelmapInitializationOptions_GetAlphaType()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t *alphaType)
```

**描述**

获取透明度类型。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t *alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetAlphaType()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType(OH_Pixelmap_InitializationOptions *options, int32_t alphaType)
```

**描述**

设置透明度类型。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| int32_t alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_GetEditable()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_GetEditable(OH_Pixelmap_InitializationOptions *options, bool *editable)
```

**描述**

获取可编辑标志。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| bool *editable | 可编辑标志。true表示可编辑，false表示不可编辑。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_SetEditable()

```c
Image_ErrorCode OH_PixelmapInitializationOptions_SetEditable(OH_Pixelmap_InitializationOptions *options, bool editable)
```

**描述**

设置可编辑标志。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 被操作的OH_Pixelmap_InitializationOptions指针。 |
| bool editable | 可编辑标志。true表示可编辑，false表示不可编辑。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapInitializationOptions_Release()

```c
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

```c
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

```c
Image_ErrorCode OH_PixelmapImageInfo_GetWidth(OH_Pixelmap_ImageInfo *info, uint32_t *width)
```

**描述**

获取图片宽。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| uint32_t *width | 图片宽，单位：像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetHeight()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetHeight(OH_Pixelmap_ImageInfo *info, uint32_t *height)
```

**描述**

获取图片高。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| uint32_t *height | 图片高，单位：像素（px）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetAlphaMode()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaMode(OH_Pixelmap_ImageInfo *info, int32_t *alphaMode)
```

**描述**

获取图片透明通道类型。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| int32_t *alphaMode | 获取的透明通道类型。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetRowStride()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetRowStride(OH_Pixelmap_ImageInfo *info, uint32_t *rowStride)
```

**描述**

获取行跨距。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| uint32_t *rowStride | 跨距，内存中每行像素所占的空间。单位：字节（Byte）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetPixelFormat()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat(OH_Pixelmap_ImageInfo *info, int32_t *pixelFormat)
```

**描述**

获取像素格式。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| int32_t *pixelFormat | 像素格式[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetAlphaType()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType(OH_Pixelmap_ImageInfo *info, int32_t *alphaType)
```

**描述**

获取OH_PixelmapImageInfo默认的透明度类型。若要获取图片当前透明度类型，请使用[OH_PixelmapImageInfo_GetAlphaMode](capi-pixelmap-native-h.md#oh_pixelmapimageinfo_getalphamode)。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| int32_t *alphaType | 透明度类型[PIXELMAP_ALPHA_TYPE](capi-pixelmap-native-h.md#pixelmap_alpha_type)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapImageInfo_GetDynamicRange()

```c
Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange(OH_Pixelmap_ImageInfo *info, bool *isHdr)
```

**描述**

获取Pixelmap是否为高动态范围的信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_ImageInfo](capi-image-nativemodule-oh-pixelmap-imageinfo.md) *info | 被操作的OH_Pixelmap_ImageInfo指针。 |
| bool *isHdr | 表示是否为高动态范围（HDR）的信息。true表示是高动态范围的信息，false表示不是高动态范围的信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数校验错误。 |

### OH_PixelmapImageInfo_Release()

```c
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

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmap(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```

**描述**

通过像素数据和图像属性创建Pixelmap。<br>此接口不支持创建以下像素格式的Pixelmap：PIXEL_FORMAT_RGBA_1010102、PIXEL_FORMAT_YCBCR_P010和PIXEL_FORMAT_YCRCB_P010。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | 像素数据的数组。<br>传入的像素数据默认按BGRA_8888格式解析，如果需要设置为其他格式，请参考[OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat)。<br>如果像素数据中含有用于内存对齐的行末填充字节，则必须使用[OH_PixelmapInitializationOptions_SetRowStride](#oh_pixelmapinitializationoptions_setrowstride)设置行跨距。 |
| size_t dataLength | 像素数组的长度。单位：字节（Byte）。 |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建图像的初始化属性。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。 |

### OH_PixelmapNative_CreatePixelmapUsingAllocator()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapUsingAllocator(uint8_t *data, size_t dataLength, OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**描述**

通过像素数据和图像属性创建Pixelmap，可以通过allocator指定内存类型。<br>默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。<br>在处理此接口返回的像素图时，需要考虑行跨距的影响。行跨距即图像每行占用的真实内存大小，可能因内存对齐而大于图像宽度乘以单位像素字节数，请参考[OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride)获取详细说明。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| uint8_t *data | 像素数据的数组。<br>传入的像素数据默认按BGRA_8888格式解析，如果需要设置为其他格式，请参考[OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat)。<br>如果像素数据中含有用于内存对齐的行末填充字节，则必须使用[OH_PixelmapInitializationOptions_SetRowStride](#oh_pixelmapinitializationoptions_setrowstride)设置行跨距。 |
| size_t dataLength | 像素数组的长度。单位：字节（Byte）。 |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建图像的初始化属性。 |
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | 决定Pixelmap内存分配的类型。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。<br>         IMAGE_TOO_LARGE：图像过大，无法分配内存。<br>         IMAGE_DMA_OPERATION_FAILED：DMA内存操作失败。<br>         IMAGE_ALLOCATOR_MODE_UNSUPPORTED：不支持分配当前内存类型。例如，使用共享内存创建HDR图。 |

### OH_PixelmapNative_ConvertPixelmapNativeToNapi()

```c
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeToNapi(napi_env env, OH_PixelmapNative *pixelmapNative, napi_value *pixelmapNapi)
```

**描述**

将OH_PixelmapNative对象转换为PixelmapNapi对象。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Napi的环境指针。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmapNative | 被操作的OH_PixelmapNative指针。 |
| napi_value *pixelmapNapi | 转换出来的PixelmapNapi对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmapNative为空。 |

### OH_PixelmapNative_ConvertPixelmapNativeFromNapi()

```c
Image_ErrorCode OH_PixelmapNative_ConvertPixelmapNativeFromNapi(napi_env env, napi_value pixelmapNapi, OH_PixelmapNative **pixelmapNative)
```

**描述**

将PixelmapNapi对象转换为OH_PixelmapNative对象。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | Napi的环境指针。 |
| napi_value pixelmapNapi | 需要转换的PixelmapNapi对象。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmapNative | 转换出的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmapNative是nullptr，或者pixelmapNapi不是PixelmapNapi对象。 |

### OH_PixelmapNative_ReadPixels()

```c
Image_ErrorCode OH_PixelmapNative_ReadPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**描述**

读取图像像素数据，并按照Pixelmap的像素格式存入缓冲区中。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| uint8_t *destination | 目标缓冲区，获取的像素数据会被拷贝至该缓冲区。缓冲区内像素的格式与PixelMap相同，不包含内存对齐填充字节。 |
| size_t *bufferSize | 缓冲区大小。单位：字节（Byte）。可通过[OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount)接口获取。RGBA格式的缓冲区大小等于width \* height \* 4，NV21与NV12格式的缓冲区大小等于width \* height + ((width+1)/2) \* ((height+1)/2) \* 2。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_PixelmapNative_WritePixels()

```c
Image_ErrorCode OH_PixelmapNative_WritePixels(OH_PixelmapNative *pixelmap, uint8_t *source, size_t bufferSize)
```

**描述**

将缓冲区中的图像像素数据按照Pixelmap的像素格式写入Pixelmap。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| uint8_t *source | 源数据缓冲区，该缓冲区内的图像像素数据会被写入Pixelmap。缓冲区内的像素数据必须是整个Pixelmap的像素数据，且像素格式需与Pixelmap相同，不包含内存对齐填充字节。 |
| size_t bufferSize | 缓冲区大小。单位：字节（Byte）。可通过[OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount)接口获取。RGBA格式的缓冲区大小等于width \* height \* 4，NV21与NV12格式的缓冲区大小等于width \* height + ((width+1)/2) \* ((height+1)/2) \* 2。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。<br>         IMAGE_UNKNOWN_ERROR：未知错误。 |

### OH_PixelmapNative_ReadPixelsFromArea()

```c
Image_ErrorCode OH_PixelmapNative_ReadPixelsFromArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)
```

**描述**

从Pixelmap的指定区域中读取像素数据并存入缓冲区。如果Pixelmap的像素格式为YUV类型，则会按照Pixelmap的像素格式存入缓冲区，否则会按照BGRA_8888格式存入缓冲区。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被读取的Pixelmap。 |
| [Image_PositionArea](capi-image-nativemodule-image-positionarea.md) *area | 读取数据的Pixelmap指定区域，该区域的像素数据会被读取并拷贝至area->pixels。如果PixelMap的像素格式为YUV类型，则获取的像素数据格式与Pixelmap相同，否则会被转换为BGRA_8888格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：pixelmap或area有误。<br>         IMAGE_UNKNOWN_ERROR：未知的内部错误，例如：不支持的像素格式。 |

### OH_PixelmapNative_WritePixelsToArea()

```c
Image_ErrorCode OH_PixelmapNative_WritePixelsToArea(OH_PixelmapNative *pixelmap, Image_PositionArea *area)
```

**描述**

将缓冲区中的像素数据写入Pixelmap的指定区域。如果Pixelmap的像素格式为YUV类型，则数据源的格式需与Pixelmap相同，否则数据源需要为BGRA_8888格式。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被写入的Pixelmap。 |
| [Image_PositionArea](capi-image-nativemodule-image-positionarea.md) *area | 写入数据的Pixelmap指定区域，area->pixels中的像素数据会被写入Pixelmap的该区域。如果PixelMap的像素格式为YUV类型，则area->pixels中的像素数据格式需与PixelMap相同，否则需要为BGRA_8888格式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：pixelmap或area有误。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap不可编辑。<br>         IMAGE_UNKNOWN_ERROR：未知的内部错误，例如：不支持的像素格式。 |

### OH_PixelmapNative_GetArgbPixels()

```c
Image_ErrorCode OH_PixelmapNative_GetArgbPixels(OH_PixelmapNative *pixelmap, uint8_t *destination, size_t *bufferSize)
```

**描述**

从Pixelmap中读取ARGB格式的数据。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| uint8_t *destination | 缓冲区，获取的图像像素数据写入到该内存区域内。缓冲区大小应不小于width * height * 4字节。 |
| size_t *bufferSize | 缓冲区大小。单位：字节（Byte）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_CONVERSION：Pixelmap格式不支持读取ARGB数据。<br>         IMAGE_ALLOC_FAILED：内存申请失败。<br>         IMAGE_COPY_FAILED：内存数据拷贝、读取、操作失败。 |

### OH_PixelmapNative_ToSdr()

```c
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

```c
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

### OH_PixelmapNative_SetOpacity()

```c
Image_ErrorCode OH_PixelmapNative_SetOpacity(OH_PixelmapNative *pixelmap, float value)
```

**描述**

设置Pixelmap的不透明度。指定的不透明度值将被应用于所有像素。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative的指针。 |
| float value | 指定的不透明度值。取值范围是(0.0, 1.0]，1.0表示完全不透明，数值越接近0.0则透明度越高。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：1. 不透明度值超出范围。2. 入参为空。<br>         IMAGE_UNSUPPORTED_DATA_FORMAT：不支持的数据格式。可能的原因：透明度类型不支持。 |

### OH_PixelmapNative_Opacity()

```c
Image_ErrorCode OH_PixelmapNative_Opacity(OH_PixelmapNative *pixelmap, float rate)
```

**描述**

设置Pixelmap的不透明度。指定的不透明度值将被应用于所有像素。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_SetOpacity](#oh_pixelmapnative_setopacity)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float rate | 不透明度的值。取值范围是(0.0, 1.0]，1.0表示完全不透明，数值越接近0.0则透明度越高。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ApplyScale()

```c
Image_ErrorCode OH_PixelmapNative_ApplyScale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)
```

**描述**

根据指定的宽高缩放倍数对Pixelmap进行水平或垂直方向的缩放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被缩放的OH_PixelmapNative的指针。 |
| float scaleX | 宽度的缩放倍数。取值不能为0。 |
| float scaleY | 高度的缩放倍数。取值不能为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：入参为空。<br>         IMAGE_ALLOC_FAILED：申请内存失败。可能的原因：1. 生成的Pixelmap尺寸过大。2. 系统内存不足。 |

### OH_PixelmapNative_Scale()

```c
Image_ErrorCode OH_PixelmapNative_Scale(OH_PixelmapNative *pixelmap, float scaleX, float scaleY)
```

**描述**

根据输入的缩放比例对Pixelmap进行缩放。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyScale](capi-pixelmap-native-h.md#oh_pixelmapnative_applyscale)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float scaleX | 宽度的缩放比例。取值不能为0。 |
| float scaleY | 高度的缩放比例。取值不能为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ApplyScaleWithAntiAliasing()

```c
Image_ErrorCode OH_PixelmapNative_ApplyScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**描述**

根据指定的宽高缩放倍数和缩放算法对Pixelmap进行水平或垂直方向的缩放。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被缩放的OH_PixelmapNative的指针。 |
| float scaleX | 宽度的缩放倍数。取值不能为0。 |
| float scaleY | 高度的缩放倍数。取值不能为0。 |
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | 采用的缩放算法。该参数对于ASTC格式的Pixelmap不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：入参为空。<br>         IMAGE_ALLOC_FAILED：申请内存失败。可能的原因：1. 生成的Pixelmap尺寸过大。2. 系统内存不足。 |

### OH_PixelmapNative_ScaleWithAntiAliasing()

```c
Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing(OH_PixelmapNative *pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**描述**

根据指定的缩放算法和输入的缩放比例对图片进行缩放。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyScaleWithAntiAliasing](#oh_pixelmapnative_applyscalewithantialiasing)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float scaleX | 宽度的缩放比例。取值不能为0。 |
| float scaleY | 高度的缩放比例。取值不能为0。 |
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | 缩放算法。该参数对于ASTC格式的Pixelmap不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_TOO_LARGE：图片过大。<br>         IMAGE_ALLOC_FAILED：内存申请失败。<br>         IMAGE_UNKNOWN_ERROR：pixelmap已经被释放。 |

### OH_PixelmapNative_CreateScaledPixelMap()

```c
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY)
```

**描述**

根据输入的宽高的缩放比例，创建一个新的缩放后的图像，生成的新Pixelmap不可编辑。该接口不会拷贝原图像的HDR元数据和EXIF信息。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 被操作的OH_PixelmapNative指针，源Pixelmap对象指针。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | 被操作的OH_PixelmapNative指针，目标Pixelmap对象指针。 |
| float scaleX | 宽度的缩放比例。取值不能为0。 |
| float scaleY | 高度的缩放比例。取值不能为0。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing()

```c
Image_ErrorCode OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level)
```

**描述**

根据指定的缩放算法和输入的宽高的缩放比例，创建一个新的缩放后的图像，生成的新Pixelmap不可编辑。该接口不会拷贝原图像的HDR元数据和EXIF信息。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 被操作的OH_PixelmapNative指针，源Pixelmap对象指针。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | 被操作的OH_PixelmapNative指针，目标Pixelmap对象指针。 |
| float scaleX | 宽度的缩放比例。取值不能为0。 |
| float scaleY | 高度的缩放比例。取值不能为0。 |
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level | 缩放算法。该参数对于ASTC格式的Pixelmap不生效。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_TOO_LARGE：图片过大。<br>         IMAGE_ALLOC_FAILED：内存申请失败。 |

### OH_PixelmapNative_CreateAlphaPixelmap()

```c
Image_ErrorCode OH_PixelmapNative_CreateAlphaPixelmap(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)
```

**描述**

从源Pixelmap创建一个仅包含Alpha通道的ALPHA_8格式的Pixelmap，生成的新Pixelmap不可编辑。<br>     若源Pixelmap的格式是ALPHA_F16，则新生成的Pixelmap将维持ALPHA_F16格式。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 提供Alpha通道数据的源Pixelmap。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | 被创建的目标Pixelmap。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：srcPixelmap或dstPixelmap有误。 |

### OH_PixelmapNative_Clone()

```c
Image_ErrorCode OH_PixelmapNative_Clone(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative **dstPixelmap)
```

**描述**

对源Pixelmap进行拷贝，生成一个新的Pixelmap。该接口不会拷贝原图像的EXIF信息。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 被拷贝的源Pixelmap。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | 生成的目标Pixelmap。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：srcPixelmap或dstPixelmap有误。<br>         IMAGE_UNSUPPORTED_DATA_FORMAT：像素格式不支持。<br>         IMAGE_TOO_LARGE：源Pixelmap的尺寸过大。<br>         IMAGE_INIT_FAILED：目标Pixelmap初始化失败。<br>         IMAGE_ALLOC_FAILED：内存申请或数据复制失败。 |

### OH_PixelmapNative_CreateCroppedAndScaledPixelMap()

```c
Image_ErrorCode OH_PixelmapNative_CreateCroppedAndScaledPixelMap(OH_PixelmapNative *srcPixelmap, Image_Region *region, Image_Scale *scale, OH_PixelmapNative_AntiAliasingLevel level, OH_PixelmapNative **dstPixelmap)
```

**描述**

基于源Pixelmap创建一个裁剪并缩放的新Pixelmap。该接口不会拷贝原图像的EXIF信息。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 源Pixelmap。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *region | 裁剪区域。 |
| [Image_Scale](capi-image-nativemodule-image-scale.md) *scale | 宽和高的缩放倍数。不能为0。 |
| [OH_PixelmapNative_AntiAliasingLevel](capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel) level | 要使用的缩放插值算法。该参数对于ASTC格式的Pixelmap不生效。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **dstPixelmap | 被创建的目标Pixelmap。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：srcPixelmap、region、scale或dstPixelmap有误。<br>         IMAGE_UNSUPPORTED_DATA_FORMAT：像素格式不支持。<br>         IMAGE_TOO_LARGE：源Pixelmap的尺寸过大。<br>         IMAGE_INIT_FAILED：目标Pixelmap初始化失败。<br>         IMAGE_ALLOC_FAILED：内存申请或数据复制失败。 |

### OH_PixelmapNative_ApplyTranslate()

```c
Image_ErrorCode OH_PixelmapNative_ApplyTranslate(OH_PixelmapNative *pixelmap, float x, float y)
```

**描述**

根据指定的横向和纵向距离对Pixelmap进行水平或垂直方向的平移。<br>平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被平移的OH_PixelmapNative的指针。 |
| float x | 横向平移的距离。方向为正数向右，负数向左。取值范围是(-图像宽度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像左侧起的x列像素。 |
| float y | 纵向平移的距离。方向为正数向下，负数向上。取值范围是(-图像高度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像上方起的y行像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：入参为空。<br>         IMAGE_ALLOC_FAILED：申请内存失败。可能的原因：1. 生成的Pixelmap尺寸过大。2. 系统内存不足。 |

### OH_PixelmapNative_Translate()

```c
Image_ErrorCode OH_PixelmapNative_Translate(OH_PixelmapNative *pixelmap, float x, float y)
```

**描述**

根据输入的平移距离对图片进行位置变换。<br>平移后的图像尺寸将变为：宽度 = 原宽度 + x，高度 = 原高度 + y。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyTranslate](capi-pixelmap-native-h.md#oh_pixelmapnative_applytranslate)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float x | 横向平移的距离。方向为正数向右，负数向左。取值范围是(-图像宽度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像左侧起的x列像素。 |
| float y | 纵向平移的距离。方向为正数向下，负数向上。取值范围是(-图像高度, +∞)。单位：像素（px）。<br>取值为负数时，平移的效果等同于裁剪掉自图像上方起的y行像素。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ApplyRotate()

```c
Image_ErrorCode OH_PixelmapNative_ApplyRotate(OH_PixelmapNative *pixelmap, float angle)
```

**描述**

根据指定的角度对Pixelmap进行旋转。YUV格式仅支持90°倍数的旋转角。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被旋转的OH_PixelmapNative的指针。 |
| float angle | 旋转的角度。单位：角度（°）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：入参为空。<br>         IMAGE_ALLOC_FAILED：申请内存失败。可能的原因：1. 生成的Pixelmap尺寸过大。2. 系统内存不足。 |

### OH_PixelmapNative_Rotate()

```c
Image_ErrorCode OH_PixelmapNative_Rotate(OH_PixelmapNative *pixelmap, float angle)
```

**描述**

根据输入的角度对图片进行旋转，YUV格式仅支持90°倍数的旋转角。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyRotate](#oh_pixelmapnative_applyrotate)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| float angle | 图片旋转的角度。单位：角度（°）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ApplyFlip()

```c
Image_ErrorCode OH_PixelmapNative_ApplyFlip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)
```

**描述**

根据指定的水平或垂直翻转条件对Pixelmap进行翻转。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被翻转的OH_PixelmapNative的指针。 |
| bool shouldFlipHorizontally | 是否进行水平翻转。true表示进行水平翻转，false表示不进行水平翻转。 |
| bool shouldFlipVertically | 是否进行垂直翻转。true表示进行垂直翻转，false表示不进行垂直翻转。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：入参为空。<br>         IMAGE_ALLOC_FAILED：申请内存失败。可能的原因：系统内存不足。 |

### OH_PixelmapNative_Flip()

```c
Image_ErrorCode OH_PixelmapNative_Flip(OH_PixelmapNative *pixelmap, bool shouldFlipHorizontally, bool shouldFlipVertically)
```

**描述**

根据输入的条件对图片进行翻转。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyFlip](capi-pixelmap-native-h.md#oh_pixelmapnative_applyflip)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| bool shouldFlipHorizontally | 是否水平翻转图像。true表示进行水平翻转，false表示不进行水平翻转。 |
| bool shouldFlipVertically | 是否垂直翻转图像。true表示进行垂直翻转，false表示不进行垂直翻转。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ApplyCrop()

```c
Image_ErrorCode OH_PixelmapNative_ApplyCrop(OH_PixelmapNative *pixelmap, Image_Region *region)
```

**描述**

根据指定的区域信息对Pixelmap进行裁剪。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被裁剪的OH_PixelmapNative的指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *region | 裁剪区域的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_REGION：指定的区域无效或超出范围。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：任意入参为空。<br>         IMAGE_ALLOC_FAILED：申请内存失败。可能的原因：1. 处理像素数据失败。2. 系统内存不足。 |

### OH_PixelmapNative_Crop()

```c
Image_ErrorCode OH_PixelmapNative_Crop(OH_PixelmapNative *pixelmap, Image_Region *region)
```

**描述**

根据输入的区域信息对图片进行裁剪。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ApplyCrop](capi-pixelmap-native-h.md#oh_pixelmapnative_applycrop)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| [Image_Region](capi-image-nativemodule-image-region.md) *region | 裁剪的区域，包含起始坐标和宽高。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_Release()

```c
Image_ErrorCode OH_PixelmapNative_Release(OH_PixelmapNative *pixelmap)
```

**描述**

释放OH_PixelmapNative指针（当内存被[OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels)锁定时无法释放）。<br>推荐使用[OH_PixelmapNative_Destroy](capi-pixelmap-native-h.md#oh_pixelmapnative_destroy)。

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

```c
Image_ErrorCode OH_PixelmapNative_Destroy(OH_PixelmapNative **pixelmap)
```

**描述**

释放OH_PixelmapNative指针，不受[OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels)锁定内存的影响。

**起始版本：** 18

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被释放的OH_PixelmapNative指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_ConvertAlphaType()

```c
Image_ErrorCode OH_PixelmapNative_ConvertAlphaType(OH_PixelmapNative *srcPixelmap, OH_PixelmapNative *dstPixelmap, const bool toPremul)
```

**描述**

将Pixelmap像素数据的透明度类型在预乘模式（[PIXELMAP_ALPHA_TYPE_PREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)）和非预乘模式（[PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED](capi-pixelmap-native-h.md#pixelmap_alpha_type)）之间转换。该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。<br>     像素格式的列表请参考[PIXEL_FORMAT](capi-pixelmap-native-h.md#pixel_format)。

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *srcPixelmap | 源Pixelmap的指针，包含待转换的像素数据，其透明度格式必须是预乘或非预乘。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *dstPixelmap | 一个空白的目标Pixelmap的指针，其属性（宽度、高度、像素格式等）必须与源Pixelmap相同，但其透明度类型必须与源Pixelmap相反（例如，如果源Pixelmap为预乘，则目标Pixelmap必须为非预乘）且必须可编辑。转换后的像素数据将写入此Pixelmap。 |
| const bool toPremul | 指定转换方向。true表示从非预乘转换为预乘，false表示从预乘转换为非预乘。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取图像数据失败。可能的原因：内部数据损坏。详情请检查日志。<br>         IMAGE_PIXELMAP_RELEASED：任一Pixelmap已被释放。<br>         IMAGE_UNSUPPORTED_OPERATION：Pixelmap被锁定，不支持该操作。<br>         IMAGE_INVALID_PARAMETER：无效参数。可能的原因：1. 任一Pixelmap不符合要求。2. 任意入参为空。<br>         IMAGE_UNSUPPORTED_DATA_FORMAT：任一Pixelmap的像素格式不被支持。 |

### OH_PixelmapNative_ConvertAlphaFormat()

```c
Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat(OH_PixelmapNative* srcpixelmap, OH_PixelmapNative* dstpixelmap, const bool isPremul)
```

**描述**

将Pixelmap像素数据的透明度类型在预乘模式和非预乘模式之间转换。该转换仅支持除RGBA_F16和ASTC_4x4之外其他包含Alpha通道的像素格式。<br>     从API版本26.0.0开始，建议使用[OH_PixelmapNative_ConvertAlphaType](capi-pixelmap-native-h.md#oh_pixelmapnative_convertalphatype)代替，以获得更完善的异常报错信息。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* srcpixelmap | 源Pixelmap的指针，包含待转换的像素数据，其透明度格式必须是预乘或非预乘。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)* dstpixelmap | 一个空白的目标Pixelmap的指针，其属性（宽度、高度、像素格式等）必须与源Pixelmap相同，但其透明度类型必须与源Pixelmap相反（例如，如果源Pixelmap为预乘，则目标Pixelmap必须为非预乘）且必须可编辑。转换后的像素数据将写入此Pixelmap。 |
| const bool isPremul | 转换方向，true为非预乘转预乘，false为预乘转非预乘。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_CreateEmptyPixelmap()

```c
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap(OH_Pixelmap_InitializationOptions *options, OH_PixelmapNative **pixelmap)
```

**描述**

利用OH_Pixelmap_InitializationOptions创建空的Pixelmap对象，内存数据为0。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建图像的初始化属性。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator()

```c
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmapUsingAllocator(OH_Pixelmap_InitializationOptions *options, IMAGE_ALLOCATOR_MODE allocator, OH_PixelmapNative **pixelmap)
```

**描述**

根据入参options创建空的Pixelmap，Pixelmap使用的内存类型可以通过allocator指定。默认情况下，系统会根据图像类型、图像大小、平台能力等选择内存类型。在处理此接口返回的像素图时，需要考虑行跨距的影响。行跨距即图像每行占用的真实内存大小，可能因内存对齐而大于图像宽度乘以单位像素字节数，请参考[OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride)获取详细说明。

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_Pixelmap_InitializationOptions](capi-image-nativemodule-oh-pixelmap-initializationoptions.md) *options | 创建图像的初始化属性。 |
| [IMAGE_ALLOCATOR_MODE](capi-image-common-h.md#image_allocator_mode) allocator | 决定pixelmap内存分配的类型。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的OH_PixelmapNative对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_UNSUPPORTED_OPERATION：操作不支持。<br>         IMAGE_TOO_LARGE：图像过大，无法分配内存。<br>         IMAGE_DMA_OPERATION_FAILED：DMA内存操作失败。<br>         IMAGE_ALLOCATOR_MODE_UNSUPPORTED：不支持分配当前内存类型。例如，使用共享内存创建HDR图。 |

### OH_PixelmapNative_CreatePixelmapFromSurface()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurface(const char *surfaceId, size_t length, OH_PixelmapNative **pixelmap)
```

**描述**

通过Surface的ID创建一个Pixelmap。如果Surface携带旋转或翻转的变换信息且需要校正方向，请使用[OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation](#oh_pixelmapnative_createpixelmapfromsurfacewithtransformation)。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *surfaceId | Surface ID字符串。 |
| size_t length | Surface ID字符串的长度。单位：字节（Byte）。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的Pixelmap。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：surfaceId或pixelmap有误。<br>         IMAGE_CREATE_PIXELMAP_FAILED：Pixelmap创建失败。 |

### OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromSurfaceWithTransformation(const char *surfaceId, size_t length, bool transformEnabled, OH_PixelmapNative **pixelmap)
```

**描述**

通过Surface的ID创建一个预览流画面的Pixelmap对象。该Surface可能携带旋转或翻转的变换信息。

**起始版本：** 23

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *surfaceId | 对应Surface的ID字符串。 |
| size_t length | 对应Surface的ID字符串长度。单位：字节（Byte）。 |
| bool transformEnabled | 是否对携带变换信息的Surface预先进行逆变换来消除Pixelmap的旋转或翻转效果，即是否进行方向校正。如果Surface未携带变换信息，则本参数不生效。<br>true表示进行逆变换，变换的角度与Surface携带的角度一致且方向相反，输出的Pixelmap无旋转或翻转效果。<br>false表示不进行逆变换，输出的Pixelmap会根据Surface中的变换信息而带有旋转或翻转效果。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的Pixelmap。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_INVALID_PARAMETER：参数无效，例如：surfaceId或pixelmap有误。<br>         IMAGE_UNSUPPORTED_OPERATION：不支持的操作，例如：跨平台时调用。<br>         IMAGE_GET_IMAGE_DATA_FAILED：获取Surface的数据失败。<br>         IMAGE_CREATE_PIXELMAP_FAILED：Pixelmap创建失败。 |

**参考：**

[OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md)


### OH_PixelmapNative_CreatePixelmapFromNativeBuffer()

```c
Image_ErrorCode OH_PixelmapNative_CreatePixelmapFromNativeBuffer(OH_NativeBuffer *nativeBuffer, OH_PixelmapNative **pixelmap)
```

**描述**

通过NativeBuffer创建一个Pixelmap。如果NativeBuffer的用途未配置CPU访问权限（详情请参考[OH_NativeBuffer_Usage](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_usage)），则不支持创建。<br> 支持创建的像素格式为RGBA_8888、NV21、NV12、YCBCR_P010、YCRCB_P010。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) *nativeBuffer | 含有Pixelmap数据的NativeBuffer对象。NativeBuffer的用途必须配置CPU访问权限（详情请参考[OH_NativeBuffer_Usage](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_usage)），且像素格式必须为RGBA_8888、NV21、NV12、YCBCR_P010或YCRCB_P010。 |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) **pixelmap | 被创建的Pixelmap。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：nativeBuffer或pixelmap有误，像素格式不支持，或未配置CPU访问权限。<br>         IMAGE_CREATE_PIXELMAP_FAILED：Pixelmap创建失败。 |

### OH_PixelmapNative_GetNativeBuffer()

```c
Image_ErrorCode OH_PixelmapNative_GetNativeBuffer(OH_PixelmapNative *pixelmap, OH_NativeBuffer **nativeBuffer)
```

**描述**

从DMA内存的Pixelmap中，获取NativeBuffer对象。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 要获取NativeBuffer的源Pixelmap，内存类型必须是DMA。 |
| [OH_NativeBuffer](capi-image-nativemodule-image-nativemodule-oh-nativebuffer.md) **nativeBuffer | 被创建的NativeBuffer对象指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DMA_NOT_EXIST：不是DMA内存。<br>         IMAGE_DMA_OPERATION_FAILED：DMA内存操作失败。 |

### OH_PixelmapNative_GetMetadata()

```c
Image_ErrorCode OH_PixelmapNative_GetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue **value)
```

**描述**

获取Pixelmap的HDR元数据。通过传入[OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey)关键字指定需要获取的元数据类型，并通过[OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md)返回对应的元数据值。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针，Pixelmap的内存类型必须是DMA。 |
| [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey) key | 元数据的关键字。 |
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) **value | 元数据的值。<br>如果获取的是动态元数据（HDR_DYNAMIC_METADATA）且接口调用成功，使用完成后必须调用free(value->dynamicMetadata.data)释放内存。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DMA_NOT_EXIST：不存在DMA内存。<br>         IMAGE_COPY_FAILED：如果内存拷贝失败。 |

### OH_PixelmapNative_SetMetadata()

```c
Image_ErrorCode OH_PixelmapNative_SetMetadata(OH_PixelmapNative *pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue *value)
```

**描述**

设置Pixelmap的HDR元数据。通过传入[OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey)关键字指定需要设置的元数据类型，并通过[OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md)传入对应的元数据值。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针，Pixelmap的内存类型必须是DMA。 |
| [OH_Pixelmap_HdrMetadataKey](capi-pixelmap-native-h.md#oh_pixelmap_hdrmetadatakey) key | 元数据的关键字。 |
| [OH_Pixelmap_HdrMetadataValue](capi-image-nativemodule-oh-pixelmap-hdrmetadatavalue.md) *value | 元数据的值。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。<br>         IMAGE_DMA_NOT_EXIST：不存在DMA内存。<br>         IMAGE_COPY_FAILED：如果内存拷贝失败。 |

### OH_PixelmapNative_SetColorSpaceNative()

```c
Image_ErrorCode OH_PixelmapNative_SetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager *colorSpaceNative)
```

**描述**

设置Pixelmap的NativeColorSpaceManager对象，用于管理Pixelmap的色彩空间信息。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 要设置NativeColorSpaceManager的目标Pixelmap。 |
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) *colorSpaceNative | 要设置的NativeColorSpaceManager对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_GetColorSpaceNative()

```c
Image_ErrorCode OH_PixelmapNative_GetColorSpaceNative(OH_PixelmapNative *pixelmap, OH_NativeColorSpaceManager **colorSpaceNative)
```

**描述**

获取Pixelmap的NativeColorSpaceManager对象，用于查询Pixelmap当前配置的色彩空间信息。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 获取到NativeColorSpaceManager的源Pixelmap。 |
| [OH_NativeColorSpaceManager](capi-image-nativemodule-oh-nativecolorspacemanager.md) **colorSpaceNative | 获取到的NativeColorSpaceManager对象。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：参数错误。 |

### OH_PixelmapNative_SetMemoryName()

```c
Image_ErrorCode OH_PixelmapNative_SetMemoryName(OH_PixelmapNative *pixelmap, char *name, size_t *size)
```

**描述**

设置Pixelmap的内存标识符，便于在内存调试或问题定位时识别该内存。<br>仅支持DMA和SHARE_MEMORY内存类型的PixelMap设置内存标识符，且SHARE_MEMORY内存的标识符设置仅在鸿蒙内核中支持。

**起始版本：** 13

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的OH_PixelmapNative指针。 |
| char *name | 需要设置的内存标识符。DMA内存标识符的字符串长度取值范围为[1, 255]字节，SHARE_MEMORY内存标识符的字符串长度长度取值范围为[1, 244]字节。 |
| size_t *size | 需要设置的内存标识符的字符串长度。单位：字节（Byte）。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：名字长度超过取值范围。DMA内存名字取值范围为[1, 255]，SHARE_MEMORY内存名字取值范围为[1, 244]。单位：字节（Byte）。<br>         IMAGE_UNSUPPORTED_MEMORY_FORMAT：既不是DMA内存也不是SHARE_MEMORY内存。 |

### OH_PixelmapNative_GetByteCount()

```c
Image_ErrorCode OH_PixelmapNative_GetByteCount(OH_PixelmapNative *pixelmap, uint32_t *byteCount)
```

**描述**

获取Pixelmap中所有像素所占用的总字节数，不包含内存对齐填充字节。

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

```c
Image_ErrorCode OH_PixelmapNative_GetAllocationByteCount(OH_PixelmapNative *pixelmap, uint32_t *allocationByteCount)
```

**描述**

获取Pixelmap实际分配的用于存储像素数据的内存字节数，包含内存对齐填充字节。与[OH_PixelmapNative_GetByteCount](#oh_pixelmapnative_getbytecount)（不包含内存填充）不同，本接口返回的是系统为Pixelmap分配的真实内存大小。

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

```c
Image_ErrorCode OH_PixelmapNative_AccessPixels(OH_PixelmapNative *pixelmap, void **addr)
```

**描述**

获取Pixelmap像素数据的内存地址，并锁定这块内存。<br> 当该内存被锁定时，任何修改或释放该Pixelmap的像素数据的操作均会失败或无效。<br> 使用完毕后，必须调用[OH_PixelmapNative_UnaccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_unaccesspixels)释放内存锁，两者需配对使用。

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

```c
Image_ErrorCode OH_PixelmapNative_UnaccessPixels(OH_PixelmapNative *pixelmap)
```

**描述**

释放Pixelmap像素数据的内存锁。<br> 该函数需要与[OH_PixelmapNative_AccessPixels](capi-pixelmap-native-h.md#oh_pixelmapnative_accesspixels)匹配使用。

**起始版本：** 15

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被操作的Pixelmap指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：执行成功。<br>         IMAGE_BAD_PARAMETER：pixelmap参数无效。<br>         IMAGE_LOCK_UNLOCK_FAILED：内存解锁失败。 |

### OH_PixelmapNative_GetUniqueId()

```c
Image_ErrorCode OH_PixelmapNative_GetUniqueId(OH_PixelmapNative *pixelmap, uint32_t *uniqueId)
```

**描述**

获取Pixelmap的唯一ID。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 获取唯一ID的Pixelmap。 |
| uint32_t *uniqueId | 获取的唯一ID。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：pixelmap或uniqueId有误。 |

### OH_PixelmapNative_IsReleased()

```c
Image_ErrorCode OH_PixelmapNative_IsReleased(OH_PixelmapNative *pixelmap, bool *released)
```

**描述**

检测Pixelmap是否已被释放。如果已被释放，则任何访问该对象内部数据的方法调用将会失效。

**起始版本：** 22

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_PixelmapNative](capi-image-nativemodule-oh-pixelmapnative.md) *pixelmap | 被检测的Pixelmap。 |
| bool *released | 获取的Pixelmap的释放状态。true表示已被释放，false表示未被释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [Image_ErrorCode](capi-image-common-h.md#image_errorcode) | IMAGE_SUCCESS：操作成功。<br>         IMAGE_BAD_PARAMETER：参数无效，例如：pixelmap或released有误。 |


