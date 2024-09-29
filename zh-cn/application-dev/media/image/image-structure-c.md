# 介绍Image_NativeModule结构体信息

本章节对Image_NativeModule模块开放给开发者使用的结构体进行解释说明。其余结构体说明可直接查阅[API参考](../../reference/apis-image-kit/_image___native_module.md#结构体)。

## OH_ImageNative结构体

OH_ImageNative是native层封装的图像对象结构体。OH_ImageNative结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| Image_Size| imageSize | 图像大小 |[OH_ImageNative_GetImageSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getimagesize) | 获取 OH_ImageNative 对象的 Image_Size 信息。|
| uint32_t | types |组件类型 |[OH_ImageNative_GetComponentTypes](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getcomponenttypes) | 获取 OH_ImageNative 对象的组件列表信息。 |
| OH_NativeBuffer | nativeBuffer | 组件缓冲区|[OH_ImageNative_GetByteBuffer](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getbytebuffer) | 获取 OH_ImageNative 对象中某个组件类型所对应的缓冲区。|
| size_t | bufferSize | 缓冲区的大小 | [OH_ImageNative_GetBufferSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getbuffersize) | 获取 OH_ImageNative 对象中某个组件类型所对应的缓冲区的大小。|
| int32_t | rowStride | 像素行宽 | [OH_ImageNative_GetRowStride](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getrowstride) | 获取 OH_ImageNative 对象中某个组件类型所对应的像素行宽。 |
| int32_t | pixelStride | 像素大小 | [OH_ImageNative_GetPixelStride](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getpixelstride) | 获取 OH_ImageNative 对象中某个组件类型所对应的像素大小。 |

释放OH_ImageNative对象使用[OH_ImageNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_release)函数。

## OH_ImagePackerNative结构体

OH_ImagePackerNative是native层封装的图像打包结构体，OH_ImagePackerNative结构体内容不可直接操作，采用函数调用方式操作具体字段，结构体内容和操作方式如下：

| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| OH_ImageSourceNative | imageSource | 图片源 | [OH_ImagePackerNative_PackToDataFromImageSource](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtodatafromimagesource) | 将ImageSource编码为指定格式的数据。 |
|OH_PixelmapNative | pixelmap | native层的pixelmap | [OH_ImagePackerNative_PackToDataFromPixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtodatafrompixelmap) | 将Pixelmap编码为指定格式的数据。|
|int32_t | imagesourceFd | imagesource关联的文件描述符 | [OH_ImagePackerNative_PackToFileFromImageSource](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtofilefromimagesource) | 将一个ImageSource编码到文件中。|
|int32_t | pixelmapFd | pixelmap关联的文件描述符| [OH_ImagePackerNative_PackToFileFromPixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtofilefrompixelmap) | 将一个Pixelmap编码到文件中。|

创建OH_ImagePackerNative对象使用[OH_ImagePackerNative_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_create)函数。

释放OH_ImagePackerNative对象使用[OH_ImagePackerNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_release)函数。

## OH_PackingOptions结构体

OH_PackingOptions是native层封装的图像编码选项结构体，OH_PackingOptions结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

创建PackingOptions结构体的对象使用[OH_PackingOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_create)函数。

释放OH_PackingOptions对象使用[OH_PackingOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_release)函数。

OH_PackingOptions结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| Image_MimeType | mimeType | MIME类型 | [OH_PackingOptions_GetMimeType](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_getmimetype) | 获取MIME类型。|
| Image_MimeType | mimeType | MIME类型 | [OH_PackingOptions_SetMimeType](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_setmimetype) | 设置MIME类型。|
| uint32_t | quality | 编码质量 | [OH_PackingOptions_GetQuality](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_getquality) | 获取编码质量。|
| uint32_t | quality | 编码质量 | [OH_PackingOptions_SetQuality](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_setquality) | 设置编码质量。|
| int32_t | desiredDynamicRange | 图片动态范围 | [OH_PackingOptions_GetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_getdesireddynamicrange) | 获取编码时期望的图片动态范围。|
| int32_t | desiredDynamicRange | 图片动态范围 | [OH_PackingOptions_SetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_setdesireddynamicrange) | 设置编码时期望的图片动态范围。|

## OH_ImageReceiverNative结构体

OH_ImageReceiverNative是native层封装的图片接收器结构体，OH_ImageReceiverNative结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

创建OH_ImageReceiverNative对象使用[OH_ImageReceiverNative_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_create)函数。

释放OH_ImageReceiverNative对象使用[OH_ImageReceiverNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_release)函数。

OH_ImageReceiverNative结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint64_t | surfaceId | 接收器的surfaceId | [OH_ImageReceiverNative_GetReceivingSurfaceId](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_getreceivingsurfaceid) |通过OH_ImageReceiverNative获取receiver的id。|
| OH_ImageNative | image | native层的image | [OH_ImageReceiverNative_ReadLatestImage](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_readlatestimage) | 通过OH_ImageReceiverNative获取最新的一张图片。|
| OH_ImageNative | image | native层的image | [OH_ImageReceiverNative_ReadNextImage](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_readnextimage) |通过OH_ImageReceiverNative获取下一张图片。|
| OH_ImageReceiver_OnCallback | callback| 图片接收器回调函数 | [OH_ImageReceiverNative_On](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_on) |注册一个OH_ImageReceiver_OnCallback回调事件。|
| OH_ImageReceiver_OnCallback | callback| 图片接收器回调函数 | [OH_ImageReceiverNative_Off](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_off) |关闭OH_ImageReceiver_OnCallback回调事件。|
| Image_Size | size | ImageReceiver的大小 | [OH_ImageReceiverNative_GetSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_getsize) |通过OH_ImageReceiverNative获取ImageReceiver的大小。|
|int32_t | capacity| 图片接收器容量 | [OH_ImageReceiverNative_GetCapacity](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_getcapacity) |通过OH_ImageReceiverNative获取ImageReceiver的容量。|

## OH_ImageReceiverOptions结构体

OH_ImageReceiverOptions是native层封装的图片接收器选项设置器结构体，用于创建OH_ImageReceiverNative时传入设置参数。
OH_ImageReceiverOptions结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

创建OH_ImageReceiverOptions对象使用[OH_ImageReceiverOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_create)函数。

释放OH_ImageReceiverOptions对象使用[OH_ImageReceiverOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_release)函数。

OH_ImageReceiverOptions结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| Image_Size | size | 图像大小 | [OH_ImageReceiverOptions_GetSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_getsize)	|获取 OH_ImageReceiverOptions 对象的 Image_Size 信息。|
| Image_Size | size | 图像大小 | [OH_ImageReceiverOptions_SetSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_setsize)	|设置 OH_ImageReceiverOptions 对象的 Image_Size 信息。|
| int32_t | capacity | 图片缓存容量 | [OH_ImageReceiverOptions_GetCapacity](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_getcapacity)	|获取 OH_ImageReceiverOptions 对象的图片缓存容量的信息。|
| int32_t | capacity | 图片缓存容量 | [OH_ImageReceiverOptions_SetCapacity](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_setcapacity)	|设置 OH_ImageReceiverOptions 对象的图片缓存容量的信息。|

## OH_ImageSourceNative结构体

OH_ImageSourceNative是native层封装的图片源结构体，用于创建图片数据。OH_ImageSourceNative结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

有多种方式创建OH_ImageSourceNative，具体如下：
| 函数 | 描述 |
| -------- | -------- |
| [OH_ImageSourceNative_CreateFromUri](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromuri)	|通过uri创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreateFromFd](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromfd)	|通过fd创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreateFromData](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromdata)	|通过缓冲区数据创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreateFromRawFile](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromrawfile)	|通过图像资源文件的RawFileDescriptor创建OH_ImageSourceNative对象。|
| [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmap)	|通过图片解码参数创建OH_PixelmapNative对象。|
| [OH_ImageSourceNative_CreatePixelmapList](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmaplist)	|通过图片解码参数创建OH_PixelmapNative数组。|

释放OH_ImageSourceNative对象使用[OH_ImageSourceNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_release)函数。

OH_ImageSourceNative结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| int32_t | delayTimeList | 图像延迟时间数组 | [OH_ImageSourceNative_GetDelayTimeList](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getdelaytimelist)	|获取图像延迟时间数组 |
| OH_ImageSource_Info | info | 图片源信息 | [OH_ImageSourceNative_GetImageInfo](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getimageinfo)	|获取指定序号的图片信息。|
| Image_String | value | 配置项 | [OH_ImageSourceNative_GetImageProperty](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getimageproperty)	|获取图片指定属性键的值。|
| Image_String | value | 配置项 | [OH_ImageSourceNative_ModifyImageProperty](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_modifyimageproperty)	|通过指定的键修改图片属性的值。|
| uint32_t | frameCount | 图像帧数 | [OH_ImageSourceNative_GetFrameCount](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getframecount)	|获取图像帧数。|

## OH_ImageSource_Info结构体

OH_ImageSource_Info是native层封装的图片源信息结构体，OH_ImageSource_Info结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

创建OH_ImageSource_Info对象使用[OH_ImageSourceInfo_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_create)函数。

释放OH_ImageSource_Info对象使用[OH_ImageSourceInfo_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_release)函数。

OH_ImageSource_Info结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | 图片宽度 | [OH_ImageSourceInfo_GetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_getwidth)	|获取图片的宽。|
| uint32_t | height | 图片高度 | [OH_ImageSourceInfo_GetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_getheight)	|获取图片的高。|
| bool | isHdr | 是否为高动态范围的信息 | [OH_ImageSourceInfo_GetDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_getdynamicrange)	|获取图片是否为高动态范围的信息。|

## OH_DecodingOptions结构体

OH_DecodingOptions是native层封装的编码选项参数结构体，用于设置编码选项参数，在创建Pixelmap时作为入参传入，详细信息见 [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmap)。

OH_DecodingOptions结构体不可直接操作，而是采用函数调用方式创建、释放结构体以及操作具体字段。

创建OH_DecodingOptions对象使用[OH_DecodingOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_create)函数。

释放OH_DecodingOptions对象使用[OH_DecodingOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_release)函数。

OH_DecodingOptions结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| int32_t | pixelFormat | 像素格式 | [OH_DecodingOptions_GetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getpixelformat)	|获取pixel格式。|
| int32_t | pixelFormat | 像素格式 | [OH_DecodingOptions_SetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setpixelformat)	| 设置像素格式。|
| uint32_t | index | 解码图片序号 | [OH_DecodingOptions_GetIndex](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getindex)	| 获取解码图片序号。|
| uint32_t | index | 解码图片序号 | [OH_DecodingOptions_SetIndex](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setindex)	| 设置解码图片序号。|
| float | rotate | 旋转角度 | [OH_DecodingOptions_GetRotate](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getrotate)	| 获取旋转角度。|
| float | rotate | 旋转角度 | [OH_DecodingOptions_SetRotate](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setrotate)	| 设置旋转角度。|
| Image_Size | desiredSize | 期望输出大小 | [OH_DecodingOptions_GetDesiredSize](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getdesiredsize)	| 获取期望输出大小。|
| Image_Size | desiredSize | 期望输出大小 | [OH_DecodingOptions_SetDesiredSize](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setdesiredsize)	| 设置期望输出大小。|
| Image_Region | desiredRegion | 解码区域 | [OH_DecodingOptions_GetDesiredRegion](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getdesiredregion) | 获取解码区域。|
| Image_Region | desiredRegion | 解码区域 | [OH_DecodingOptions_SetDesiredRegion](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setdesiredregion) | 设置解码区域。|
| int32_t | desiredDynamicRange | 期望动态范围 | [OH_DecodingOptions_GetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getdesireddynamicrange)	|获取解码时设置的期望动态范围。|
| int32_t | desiredDynamicRange | 期望动态范围 | [OH_DecodingOptions_SetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setdesireddynamicrange)|设置解码时的期望动态范围。|

## OH_PixelmapNative结构体

OH_PixelmapNative结构体是native层封装的图像解码后无压缩的位图格式结构体。

函数创建OH_PixelmapNative使用[OH_PixelmapNative_CreatePixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_createpixelmap)函数，默认采用BGRA_8888格式处理数据。

释放OH_PixelmapNative对象使用[OH_PixelmapNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_release)函数。

OH_PixelmapNative结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint8_t | data | 图像像素数据 | [OH_PixelmapNative_ReadPixels](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_readpixels)	| 读取图像像素数据，结果写入ArrayBuffer里。|
| uint8_t | data | 图像像素数据 | [OH_PixelmapNative_WritePixels](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_writepixels)	| 读取缓冲区中的图片数据，结果写入PixelMap中。|
| OH_Pixelmap_ImageInfo | imageInfo | 图像像素信息 | [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_getimageinfo)	| 获取图像像素信息。|
| float | alphaRate | 透明度 | [OH_PixelmapNative_Opacity](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_opacity)	| 通过设置透明比率来让PixelMap达到对应的透明效果。|
|float, float, | scaleX, scaleY | scaleX沿X轴缩放比例，scaleY沿Y轴缩放比例 |[OH_PixelmapNative_Scale](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_scale)	| 根据输入的宽高对图片进行缩放。|
| float, float| x, y | x平移量，y平移量 | [OH_PixelmapNative_Translate](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_translate)	| 根据输入的坐标对图片进行位置变换。|
| float | angle | 旋转角度 |[OH_PixelmapNative_Rotate](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_rotate) | 根据输入的角度对图片进行旋转。|
| bool, bool | shouldFilpHorizontally, shouldFilpVertically | 是否水平翻转，是否垂直翻转 | [OH_PixelmapNative_Flip](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_flip)	| 根据输入的条件对图片进行翻转。|
| Image_Region | region | 裁剪区间 | [OH_PixelmapNative_Crop](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_crop)	| 根据输入的尺寸对图片进行裁剪。|

## OH_Pixelmap_InitializationOptions结构体

OH_Pixelmap_InitializationOptions是native层封装的初始化参数结构体，用于设置Pixelmap的初始化参数。

创建OH_Pixelmap_InitializationOptions对象使用[OH_PixelmapInitializationOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_create)函数。

释放OH_Pixelmap_InitializationOptions对象使用[OH_PixelmapInitializationOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_release)函数。

OH_Pixelmap_InitializationOptions结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | 图片宽 | [OH_PixelmapInitializationOptions_GetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getwidth)	|获取图片宽。|
| uint32_t | width | 图片宽 | [OH_PixelmapInitializationOptions_SetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setwidth)	|设置图片宽。|
| uint32_t | height | 图片高 | [OH_PixelmapInitializationOptions_GetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getheight)	|获取图片高。|
| uint32_t | height | 图片高 | [OH_PixelmapInitializationOptions_SetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setheight)	|设置图片高。|
| int32_t | pixelFormat | 像素格式 | [OH_PixelmapInitializationOptions_GetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getpixelformat)	|获取像素格式。|
| int32_t | pixelFormat | 像素格式 | [OH_PixelmapInitializationOptions_SetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setpixelformat)	|设置像素格式。|
| int32_t | alphaType | 透明度类型 | [OH_PixelmapInitializationOptions_GetAlphaType](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getalphatype)	|获取透明度类型。|
| int32_t | alphaType | 透明度类型 | [OH_PixelmapInitializationOptions_SetAlphaType](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setalphatype)	|设置透明度类型。|

## OH_Pixelmap_ImageInfo结构体

OH_Pixelmap_ImageInfo是native层封装的图像像素信息结构体，保存图像像素的宽高、行跨距、像素格式、是否是HDR。

创建OH_Pixelmap_ImageInfo对象使用[OH_PixelmapImageInfo_Create](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_create)函数。

释放OH_Pixelmap_ImageInfo对象使用[OH_PixelmapImageInfo_Release](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_release)函数。

OH_Pixelmap_ImageInfo结构体内容和操作方式如下：
| 字段类型| 字段名称 | 字段描述 |操作函数 | 函数描述 |
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | 图片宽 | [OH_PixelmapImageInfo_GetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getwidth)	| 获取图片宽。|
| uint32_t | height | 图片高 | [OH_PixelmapImageInfo_GetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getheight)	| 获取图片高。|
| uint32_t | rowStride | 行跨距 | [OH_PixelmapImageInfo_GetRowStride](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getrowstride)	| 获取行跨距。|
| int32_t | pixelFormat| 像素格式 | [OH_PixelmapImageInfo_GetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getpixelformat)	|获取像素格式。|
| int32_t | alphaType | 透明度类型 | [OH_PixelmapImageInfo_GetAlphaType](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getalphatype)	|获取透明度类型。|
| bool | isHdr | 是否为高动态范围的信息 | [OH_PixelmapImageInfo_GetDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getdynamicrange)	|获取Pixelmap是否为高动态范围的信息。|
