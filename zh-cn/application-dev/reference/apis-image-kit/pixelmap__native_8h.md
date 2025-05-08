# pixelmap_native.h


## 概述

访问Pixelmap的API。

**库：** libpixelmap.so

**引用文件**：&lt;multimedia/image_framework/image/pixelmap_native.h&gt;

**系统能力：** SystemCapability.Multimedia.Image.Core

**起始版本：** 12

**相关模块：**[Image_NativeModule](_image___native_module.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) | HDR_STATIC_METADATA关键字对应的静态元数据值。  | 
| struct  [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) | DR_DYNAMIC_METADATA关键字对应的动态元数据值。  | 
| struct  [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) | HDR_GAINMAP_METADATA关键字对应的gainmap相关元数据值，参考ISO 21496-1。  | 
| struct  [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) | Pixelmap使用的HDR元数据值，和OH_Pixelmap_HdrMetadataKey关键字相对应。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) | Pixelmap结构体类型，用于执行Pixelmap相关操作。 | 
| typedef struct [OH_NativeBuffer](_image___native_module.md#oh_nativebuffer) [OH_NativeBuffer](_image___native_module.md#oh_nativebuffer) | NativeBuffer结构体类型，用于执行NativeBuffer相关操作。 | 
| typedef struct [OH_NativeColorSpaceManager](_image___native_module.md#oh_nativecolorspacemanager) [OH_NativeColorSpaceManager](_image___native_module.md#oh_nativecolorspacemanager) | NativeColorSpaceManager结构体类型，用于执行NativeColorSpaceManager相关操作。  | 
| typedef struct [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) [OH_Pixelmap_HdrStaticMetadata](_image___native_module.md#oh_pixelmap_hdrstaticmetadata) | HDR_STATIC_METADATA关键字对应的静态元数据值。  | 
| typedef struct [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) [OH_Pixelmap_HdrDynamicMetadata](_image___native_module.md#oh_pixelmap_hdrdynamicmetadata) | DR_DYNAMIC_METADATA关键字对应的动态元数据值。  | 
| typedef struct [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) [OH_Pixelmap_HdrGainmapMetadata](_image___native_module.md#oh_pixelmap_hdrgainmapmetadata) | HDR_GAINMAP_METADATA关键字对应的gainmap相关元数据值，参考ISO 21496-1。  | 
| typedef struct [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) [OH_Pixelmap_HdrMetadataValue](_image___native_module.md#oh_pixelmap_hdrmetadatavalue) | Pixelmap使用的HDR元数据值，和OH_Pixelmap_HdrMetadataKey关键字相对应。  | 
| typedef struct [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) | 初始化参数结构体。 | 
| typedef struct [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) | 图像像素信息结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [PIXELMAP_ALPHA_TYPE](_image___native_module.md#pixelmap_alpha_type) {<br/>PIXELMAP_ALPHA_TYPE_UNKNOWN = 0,<br/>PIXELMAP_ALPHA_TYPE_OPAQUE = 1,<br/>PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2, <br/>PIXELMAP_ALPHA_TYPE_UNPREMULTIPLIED = 3 } | Pixelmap透明度类型。 | 
| [PIXEL_FORMAT](_image___native_module.md#pixel_format) {<br/>PIXEL_FORMAT_UNKNOWN = 0, PIXEL_FORMAT_ARGB_8888 = 1, <br/>PIXEL_FORMAT_RGB_565 = 2, PIXEL_FORMAT_RGBA_8888 = 3, <br/>PIXEL_FORMAT_BGRA_8888 = 4, PIXEL_FORMAT_RGB_888 = 5, <br/>PIXEL_FORMAT_ALPHA_8 = 6, PIXEL_FORMAT_RGBA_F16 = 7, <br/>PIXEL_FORMAT_NV21 = 8, PIXEL_FORMAT_NV12 = 9,  <br/>PIXEL_FORMAT_RGBA_1010102 = 10, PIXEL_FORMAT_YCBCR_P010 = 11, <br/>PIXEL_FORMAT_YCRCB_P010 = 12<br/>} | 图片像素格式。 | 
| [OH_PixelmapNative_AntiAliasingLevel](_image___native_module.md#oh_pixelmapnative_antialiasinglevel) { <br/>OH_PixelmapNative_AntiAliasing_NONE = 0, <br/>OH_PixelmapNative_AntiAliasing_LOW = 1, <br/>OH_PixelmapNative_AntiAliasing_MEDIUM = 2, <br/>OH_PixelmapNative_AntiAliasing_HIGH = 3 <br/>} | Pixelmap缩放时采用的缩放算法。  | 
| [OH_Pixelmap_HdrMetadataKey](_image___native_module.md#oh_pixelmap_hdrmetadatakey) { <br/>HDR_METADATA_TYPE = 0, <br/>HDR_STATIC_METADATA = 1, <br/>HDR_DYNAMIC_METADATA = 2, <br/>HDR_GAINMAP_METADATA = 3 <br/>} | Pixelmap使用的HDR相关元数据信息的关键字，用于[OH_PixelmapNative_SetMetadata](_image___native_module.md#oh_pixelmapnative_setmetadata)及[OH_PixelmapNative_GetMetadata](_image___native_module.md#oh_pixelmapnative_getmetadata)。  | 
| [OH_Pixelmap_HdrMetadataType](_image___native_module.md#oh_pixelmap_hdrmetadatatype) { <br/>HDR_METADATA_TYPE_NONE = 0, <br/>HDR_METADATA_TYPE_BASE = 1, <br/>HDR_METADATA_TYPE_GAINMAP = 2, <br/>HDR_METADATA_TYPE_ALTERNATE = 3 <br/>} | HDR_METADATA_TYPE关键字对应的值。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_Create](_image___native_module.md#oh_pixelmapinitializationoptions_create) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*\*options) | 创建OH_Pixelmap_InitializationOptions指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetWidth](_image___native_module.md#oh_pixelmapinitializationoptions_getwidth) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t \*width) | 获取图片宽。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetWidth](_image___native_module.md#oh_pixelmapinitializationoptions_setwidth) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t width) | 设置图片宽。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetHeight](_image___native_module.md#oh_pixelmapinitializationoptions_getheight) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t \*height) | 获取图片高。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetHeight](_image___native_module.md#oh_pixelmapinitializationoptions_setheight) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, uint32_t height) | 设置图片高。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_getpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t \*pixelFormat) | 获取像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_setpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t pixelFormat) | 设置像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetSrcPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_getsrcpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t \*srcpixelFormat) | 获取源像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetSrcPixelFormat](_image___native_module.md#oh_pixelmapinitializationoptions_setsrcpixelformat) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t srcpixelFormat) | 设置源像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetRowStride](_image___native_module.md#oh_pixelmapinitializationoptions_getrowstride) (OH_Pixelmap_InitializationOptions \*options, int32_t \*rowStride) | 获取行跨距。跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetRowStride](_image___native_module.md#oh_pixelmapinitializationoptions_setrowstride) (OH_Pixelmap_InitializationOptions \*options, int32_t rowStride) | 设置图像跨距。跨距，图像每行占用的真实内存大小，单位为字节。跨距 = width \* 单位像素字节数 + padding，padding为每行为内存对齐做的填充区域。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetAlphaType](_image___native_module.md#oh_pixelmapinitializationoptions_getalphatype) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t \*alphaType) | 获取透明度类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetAlphaType](_image___native_module.md#oh_pixelmapinitializationoptions_setalphatype) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, int32_t alphaType) | 设置透明度类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_GetEditable](_image___native_module.md#oh_pixelmapinitializationoptions_geteditable) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, bool \*editable) | 获取可编辑标志。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_SetEditable](_image___native_module.md#oh_pixelmapinitializationoptions_seteditable) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, bool editable) | 设置可编辑标志。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapInitializationOptions_Release](_image___native_module.md#oh_pixelmapinitializationoptions_release) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options) | 释放OH_Pixelmap_InitializationOptions指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_Create](_image___native_module.md#oh_pixelmapimageinfo_create) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*\*info) | 创建OH_Pixelmap_ImageInfo指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetWidth](_image___native_module.md#oh_pixelmapimageinfo_getwidth) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*width) | 获取图片宽。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetHeight](_image___native_module.md#oh_pixelmapimageinfo_getheight) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*height) | 获取图片高。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetRowStride](_image___native_module.md#oh_pixelmapimageinfo_getrowstride) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, uint32_t \*rowStride) | 获取行跨距。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetPixelFormat](_image___native_module.md#oh_pixelmapimageinfo_getpixelformat) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, int32_t \*pixelFormat) | 获取像素格式。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetAlphaType](_image___native_module.md#oh_pixelmapimageinfo_getalphatype) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, int32_t \*alphaType) | 获取透明度类型。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_GetDynamicRange](_image___native_module.md#oh_pixelmapimageinfo_getdynamicrange) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info, bool \*isHdr) | 获取Pixelmap是否为高动态范围的信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapImageInfo_Release](_image___native_module.md#oh_pixelmapimageinfo_release) ([OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*info) | 释放OH_Pixelmap_ImageInfo指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_CreatePixelmap](_image___native_module.md#oh_pixelmapnative_createpixelmap) (uint8_t \*data, size_t dataLength, [OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmap) | 通过属性创建PixelMap，默认采用BGRA_8888格式处理数据。 | 
| Image_ErrorCode [OH_PixelmapNative_ConvertPixelmapNativeToNapi](_image___native_module.md#oh_pixelmapnative_convertpixelmapnativetonapi) (napi_env env, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmapNative, napi_value \*pixelmapNapi) | 将nativePixelMap对象转换为PixelMapnapi对象。  | 
| Image_ErrorCode [OH_PixelmapNative_ConvertPixelmapNativeFromNapi](_image___native_module.md#oh_pixelmapnative_convertpixelmapnativefromnapi) (napi_env env, napi_value pixelmapNapi, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmapNative) | 将PixelMapnapi对象转换为nativePixelMap对象。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_ReadPixels](_image___native_module.md#oh_pixelmapnative_readpixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | 读取图像像素数据，结果写入ArrayBuffer里。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_WritePixels](_image___native_module.md#oh_pixelmapnative_writepixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*source, size_t bufferSize) | 读取缓冲区中的图片数据，结果写入PixelMap中。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetArgbPixels](_image___native_module.md#oh_pixelmapnative_getargbpixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | 从PixelMap中读取ARGB格式的数据。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_ToSdr](_image___native_module.md#oh_pixelmapnative_tosdr) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap) | 将HDR的图像内容转换为SDR的图像内容。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetImageInfo](_image___native_module.md#oh_pixelmapnative_getimageinfo) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_ImageInfo](_image___native_module.md#oh_pixelmap_imageinfo) \*imageInfo) | 获取图像像素信息。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Opacity](_image___native_module.md#oh_pixelmapnative_opacity) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float rate) | 通过设置透明比率来让PixelMap达到对应的透明效果。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Scale](_image___native_module.md#oh_pixelmapnative_scale) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY) | 根据输入的宽高对图片进行缩放。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_ScaleWithAntiAliasing](_image___native_module.md#oh_pixelmapnative_scalewithantialiasing) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY, [OH_PixelmapNative_AntiAliasingLevel](_image___native_module.md#oh_pixelmapnative_antialiasinglevel) level) | 根据指定的缩放算法和输入的宽高对图片进行缩放。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_CreateScaledPixelMap](_image___native_module.md#oh_pixelmapnative_createscaledpixelmap) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*srcPixelmap, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*dstPixelmap, float scaleX, float scaleY) | 根据输入的宽高的缩放比例，创建一个新的缩放后的图片。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_CreateScaledPixelMapWithAntiAliasing](_image___native_module.md#oh_pixelmapnative_createscaledpixelmapwithantialiasing) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*srcPixelmap, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*dstPixelmap, float scaleX, float scaleY, [OH_PixelmapNative_AntiAliasingLevel](_image___native_module.md#oh_pixelmapnative_antialiasinglevel) level) | 根据指定的缩放算法和输入的宽高的缩放比例，创建一个新的缩放后的图片。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Translate](_image___native_module.md#oh_pixelmapnative_translate) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float x, float y) | 根据输入的坐标对图片进行位置变换。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Rotate](_image___native_module.md#oh_pixelmapnative_rotate) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, float angle) | 根据输入的角度对图片进行旋转。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Flip](_image___native_module.md#oh_pixelmapnative_flip) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically) | 根据输入的条件对图片进行翻转。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Crop](_image___native_module.md#oh_pixelmapnative_crop) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [Image_Region](_image___region.md) \*region) | 根据输入的尺寸对图片进行裁剪。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Release](_image___native_module.md#oh_pixelmapnative_release) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap) | 释放OH_PixelmapNative指针，推荐使用 [OH_PixelmapNative_Destroy](_image___native_module.md#oh_pixelmapnative_destroy)。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_Destroy](_image___native_module.md#oh_pixelmapnative_destroy) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmap) | 释放OH_PixelmapNative指针。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_ConvertAlphaFormat](_image___native_module.md#oh_pixelmapnative_convertalphaformat) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*srcpixelmap, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*dstpixelmap, const bool isPremul) | 将pixelmap的像素数据做预乘和非预乘之间的转换。| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_CreateEmptyPixelmap](_image___native_module.md#oh_pixelmapnative_createemptypixelmap) ([OH_Pixelmap_InitializationOptions](_image___native_module.md#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*\*pixelmap) | 利用OH_Pixelmap_InitializationOptions创建空的pixelmap对象，内存数据为0。| 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetNativeBuffer](_image___native_module.md#oh_pixelmapnative_getnativebuffer) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, OH_NativeBuffer \*\*nativeBuffer) | 从DMA内存的PixelMap中，获取NativeBuffer对象。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetMetadata](_image___native_module.md#oh_pixelmapnative_getmetadata) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_HdrMetadataKey](_image___native_module.md#oh_pixelmap_hdrmetadatakey) key, [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) \*\*value) | 获取元数据。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_SetMetadata](_image___native_module.md#oh_pixelmapnative_setmetadata) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_HdrMetadataKey](_image___native_module.md#oh_pixelmap_hdrmetadatakey) key, [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) \*value) | 设置元数据。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_SetColorSpaceNative](_image___native_module.md#oh_pixelmapnative_setcolorspacenative) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [OH_NativeColorSpaceManager](_image___native_module.md#oh_nativecolorspacemanager) \*colorSpaceNative) | 设置NativeColorSpaceManager对象。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetColorSpaceNative](_image___native_module.md#oh_pixelmapnative_getcolorspacenative) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, [OH_NativeColorSpaceManager](_image___native_module.md#oh_nativecolorspacemanager) \*\*colorSpaceNative) | 获取NativeColorSpaceManager对象。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_SetMemoryName](_image___native_module.md#oh_pixelmapnative_setmemoryname) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, char \*name, size_t \*size) | 设置pixelMap内存名字。  | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetByteCount](_image___native_module.md#oh_pixelmapnative_getbytecount) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint32_t \*byteCount) | 获取Pixelmap中所有像素所占用的总字节数，不包含内存填充。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_GetAllocationByteCount](_image___native_module.md#oh_pixelmapnative_getallocationbytecount) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, uint32_t \*allocationByteCount) | 获取Pixelmap用于储存像素数据的内存字节数。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_AccessPixels](_image___native_module.md#oh_pixelmapnative_accesspixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap, void \*\*addr) | 获取Pixelmap像素数据的内存地址，并锁定这块内存。<br/>当该内存被锁定时，任何修改或释放该Pixelmap的像素数据的操作均会失败或无效。 | 
| [Image_ErrorCode](_image___native_module.md#image_errorcode) [OH_PixelmapNative_UnaccessPixels](_image___native_module.md#oh_pixelmapnative_unaccesspixels) ([OH_PixelmapNative](_image___native_module.md#oh_pixelmapnative) \*pixelmap) | 释放Pixelmap像素数据的内存锁。<br/>该函数需要与[OH_PixelmapNative_AccessPixels](_image___native_module.md#oh_pixelmapnative_accesspixels)匹配使用。 | 
