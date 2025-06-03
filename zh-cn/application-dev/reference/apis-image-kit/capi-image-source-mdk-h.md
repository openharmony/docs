# image_source_mdk.h

## 概述

声明将图片源解码成像素位图的方法。

**库：** libimage_source_ndk.z.so

**起始版本：** 10

**相关模块：** [Image](capi-image.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OhosImageRegion](capi-ohosimageregion.md) | - | 定义图像源解码的范围选项。{@link OhosImageDecodingOps}, {@link OH_ImageSource_CreatePixelMap} and{@link OH_ImageSource_CreatePixelMapList}. |
| [ImageSourceNative_](capi-imagesourcenative-.md) | ImageSourceNative | 为图像源方法定义native层图像源对象。 |
| [OhosImageSourceOps](capi-ohosimagesourceops.md) | - | 定义图像源选项信息。此选项给{@link OH_ImageSource_Create}和{@link OH_ImageSource_CreateIncremental}这两个接口使用。 |
| [OhosImageDecodingOps](capi-ohosimagedecodingops.md) | - | 定义图像源解码选项。此选项给{@link OH_ImageSource_CreatePixelMap}和{@link OH_ImageSource_CreatePixelMapList}这两个接口使用。 |
| [OhosImageSourceInfo](capi-ohosimagesourceinfo.md) | - | 定义图像源信息，由{@link OH_ImageSource_GetImageInfo}获取。 |
| [OhosImageSource](capi-ohosimagesource.md) | - | 定义图像源输入资源，每次仅接收一种类型。由{@link OH_ImageSource_Create}获取。 |
| [OhosImageSourceDelayTimeList](capi-ohosimagesourcedelaytimelist.md) | - | 定义图像源延迟时间列表。由{@link OH_ImageSource_GetDelayTime}获取。 |
| [OhosImageSourceSupportedFormat](capi-ohosimagesourcesupportedformat.md) | - | 定义图像源支持的格式字符串。此选项给{@link OhosImageSourceSupportedFormatList}和{@link OH_ImageSource_GetSupportedFormats}这两个接口使用。 |
| [OhosImageSourceSupportedFormatList](capi-ohosimagesourcesupportedformatlist.md) | - | 定义图像源支持的格式字符串列表。由{@link OH_ImageSource_GetSupportedFormats}获取 |
| [OhosImageSourceProperty](capi-ohosimagesourceproperty.md) | - | 定义图像源属性键值字符串。此选项给{@link OH_ImageSource_GetImageProperty} and {@link OH_ImageSource_ModifyImageProperty}这两个接口使用。 |
| [OhosImageSourceUpdateData](capi-ohosimagesourceupdatedata.md) | - | 定义图像源更新数据选项，由{@link OH_ImageSource_UpdateData}获取。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [int32_t OH_ImageSource_CreateFromUri(napi_env env, char* uri, size_t size,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromuri) | 通过给定的标识符URI 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。 |
| [int32_t OH_ImageSource_CreateFromFd(napi_env env, int32_t fd,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromfd) | 通过给定的文件描述符 fd 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。 |
| [int32_t OH_ImageSource_CreateFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromdata) | 通过给定的图像源缓冲区资源 data 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。 |
| [int32_t OH_ImageSource_CreateFromRawFile(napi_env env, RawFileDescriptor rawFile,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createfromrawfile) | 通过给定的资源描述符 [RawFileDescriptor](../LocalizationKit/capi-rawfiledescriptor.md) 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。 |
| [int32_t OH_ImageSource_CreateIncrementalFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)](#oh_imagesource_createincrementalfromdata) | 通过给定的图像源缓冲区资源 data 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取增量类型的JavaScript Native API ImageSource对象，图像数据应通过{@link-OH_ImageSource_UpdateData}更新。 |
| [int32_t OH_ImageSource_GetSupportedFormats(struct OhosImageSourceSupportedFormatList* res)](#oh_imagesource_getsupportedformats) | 获取所有支持的解码格式元标记。 |
| [ImageSourceNative* OH_ImageSource_InitNative(napi_env env, napi_value source)](#oh_imagesource_initnative) | 从输入JavaScript native层API <b>ImageSource</b> 对象中，转换成{@link ImageSourceNative}值。 |
| [int32_t OH_ImageSource_CreatePixelMap(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)](#oh_imagesource_createpixelmap) | 通过一个给定的选项[OhosImageDecodingOps](capi-ohosimagedecodingops.md)结构体，从<b>ImageSource</b>中解码JavaScript native层API<b>PixelMap</b>对象 |
| [int32_t OH_ImageSource_CreatePixelMapList(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)](#oh_imagesource_createpixelmaplist) | 通过一个给定的选项[OhosImageDecodingOps](capi-ohosimagedecodingops.md)结构体，从<b>ImageSource</b>中解码所有的JavaScript native层API<b>PixelMap</b>对象列表 |
| [int32_t OH_ImageSource_GetDelayTime(const ImageSourceNative* native,struct OhosImageSourceDelayTimeList* res)](#oh_imagesource_getdelaytime) | 从一些<b>ImageSource</b>（如GIF图像源）获取延迟时间列表。 |
| [int32_t OH_ImageSource_GetFrameCount(const ImageSourceNative* native, uint32_t *res)](#oh_imagesource_getframecount) | 从<b>ImageSource</b>中获取帧计数。 |
| [int32_t OH_ImageSource_GetImageInfo(const ImageSourceNative* native, int32_t index,struct OhosImageSourceInfo* info)](#oh_imagesource_getimageinfo) | 通过索引从<b>ImageSource</b>获取图像源信息。 |
| [int32_t OH_ImageSource_Release(ImageSourceNative* native)](#oh_imagesource_release) | 释放native层图像源 <b>ImageSourceNative</b>。 |

### 变量

| 名称 | 描述 |
| -- | -- |
| const char * OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample" | 定义每个样本比特的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation" | 定义方向的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength" | 定义图像长度的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth" | 定义图像宽度的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude" | 定义GPS纬度的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude" | 定义GPS经度的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef" | 定义GPS纬度参考的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef" | 定义GPS经度参考的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal" | 定义初始日期时间的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime" | 定义曝光时间的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType" | 定义场景类型的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings" | 定义ISO速度等级的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber" | 定义FNumber的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |
| const char * OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel" | 定义每个像素的压缩比特的图像属性关键字。此标签给{@link OH_ImageSource_GetImageProperty}和{@link OH_ImageSource_ModifyImageProperty}这两个接口使用。<br>**起始版本：** 10 |

## 函数说明

### OH_ImageSource_CreateFromUri()

```
int32_t OH_ImageSource_CreateFromUri(napi_env env, char* uri, size_t size,struct OhosImageSourceOps* ops, napi_value *res)
```

**描述**

通过给定的标识符URI 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| char* uri | 表明图像源资源标识符，接受文件资源或者base64资源. |
| size_t size | 表明图像源资源URI的长度. |
| struct OhosImageSourceOps* ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](capi-ohosimagesourceops.md)。 |
| napi_value *res | 表明JavaScript native层API<b>ImageSource</b>对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}； |

**参考：**

[OhosImageSourceOps](capi-ohosimagesourceops.md)

### OH_ImageSource_CreateFromFd()

```
int32_t OH_ImageSource_CreateFromFd(napi_env env, int32_t fd,struct OhosImageSourceOps* ops, napi_value *res)
```

**描述**

通过给定的文件描述符 fd 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| int32_t fd | 表明图像源文件资源描述符。 |
| struct OhosImageSourceOps* ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](capi-ohosimagesourceops.md)。 |
| napi_value *res | 表明JavaScript native层API<b>ImageSource</b>对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}； |

**参考：**

[OhosImageSourceOps](capi-ohosimagesourceops.md)

### OH_ImageSource_CreateFromData()

```
int32_t OH_ImageSource_CreateFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)
```

**描述**

通过给定的图像源缓冲区资源 data 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| uint8_t* data | 表明图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区。 |
| size_t dataSize | 表明图像源缓冲区资源大小。 |
| struct OhosImageSourceOps* ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](capi-ohosimagesourceops.md)。 |
| napi_value *res | 表明JavaScript native层API<b>ImageSource</b>对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}； |

**参考：**

[OhosImageSourceOps](capi-ohosimagesourceops.md)

### OH_ImageSource_CreateFromRawFile()

```
int32_t OH_ImageSource_CreateFromRawFile(napi_env env, RawFileDescriptor rawFile,struct OhosImageSourceOps* ops, napi_value *res)
```

**描述**

通过给定的资源描述符 [RawFileDescriptor](../LocalizationKit/capi-rawfiledescriptor.md) 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取JavaScript native层API<b>ImageSource</b>对象。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| [RawFileDescriptor](../LocalizationKit/capi-rawfiledescriptor.md) rawFile | 表明图像源资源描述符。 |
| struct OhosImageSourceOps* ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](capi-ohosimagesourceops.md)。 |
| napi_value *res | 表明JavaScript native层API<b>ImageSource</b>对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}； |

**参考：**

[OhosImageSourceOps](capi-ohosimagesourceops.md)

### OH_ImageSource_CreateIncrementalFromData()

```
int32_t OH_ImageSource_CreateIncrementalFromData(napi_env env, uint8_t* data, size_t dataSize,struct OhosImageSourceOps* ops, napi_value *res)
```

**描述**

通过给定的图像源缓冲区资源 data 和 [OhosImageSourceOps](capi-ohosimagesourceops.md)结构体，获取增量类型的JavaScript Native API ImageSource对象，图像数据应通过{@link-OH_ImageSource_UpdateData}更新。

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| uint8_t* data | 表明图像源缓冲区资源，接受格式化包缓冲区或者base64缓冲区。 |
| size_t dataSize | 表明图像源缓冲区资源大小。 |
| struct OhosImageSourceOps* ops | 表明创建一个图像源的选项。查看[OhosImageSourceOps](capi-ohosimagesourceops.md)。 |
| napi_value *res | 表明JavaScript native层API<b>ImageSource</b>对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}； |

**参考：**

[OhosImageSourceOps](capi-ohosimagesourceops.md)

### OH_ImageSource_GetSupportedFormats()

```
int32_t OH_ImageSource_GetSupportedFormats(struct OhosImageSourceSupportedFormatList* res)
```

**描述**

获取所有支持的解码格式元标记。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| struct OhosImageSourceSupportedFormatList* res | 表明指向<b>OhosImageSourceSupportedFormatList</b>结构的列表指针。当<b>supportedFormatList</b>为nullptr并且<b>size</b>以res为0作为输入时，它将以res<b>size</b>返回支持的格式大小。为了获得所有的格式标记，它需要比<b>supportedFormatList</b>中的结果大小大的足够空间，还需要为{@link-OhosImageSourceSupportedFormat}项目中的每个<b>格式</b>提供足够的空间。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}；<br> 如果解码失败，返回{@link IMAGE_RESULT_DECODE_FAILED}；<br> 如果检查格式不对，返回{@IMAGE_RESULT_CHECK_FORMAT_ERROR }。 |

**参考：**

[OhosImageSourceSupportedFormatList](capi-ohosimagesourcesupportedformatlist.md), [OhosImageSourceSupportedFormat](capi-ohosimagesourcesupportedformat.md)

### OH_ImageSource_InitNative()

```
ImageSourceNative* OH_ImageSource_InitNative(napi_env env, napi_value source)
```

**描述**

从输入JavaScript native层API <b>ImageSource</b> 对象中，转换成{@link ImageSourceNative}值。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| napi_env env | 表明JNI环境的指针。 |
| napi_value source | 表明JavaScript native层API<b>ImageSource</b>对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| ImageSourceNative* | 如果操作成功返回{@link ImageSourceNative}指针；如果操作失败，返回空指针。 |

**参考：**

{@link ImageSourceNative}, [OH_ImageSource_Release](capi-image-source-mdk-h.md#oh_imagesource_release)

### OH_ImageSource_CreatePixelMap()

```
int32_t OH_ImageSource_CreatePixelMap(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)
```

**描述**

通过一个给定的选项[OhosImageDecodingOps](capi-ohosimagedecodingops.md)结构体，从<b>ImageSource</b>中解码JavaScript native层API<b>PixelMap</b>对象

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageSourceNative* native | 表明native层{@link ImageSourceNative}值的指针。 |
| struct OhosImageDecodingOps* ops | 表明为了解码图像源的选项，查看[OhosImageDecodingOps](capi-ohosimagedecodingops.md)。 |
| napi_value *res | 表明JavaScript native层API<b>PixelMap</b>对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}；<br> 如果获取图片数据异常，返回 {@link IMAGE_RESULT_GET_DATA_ABNORMAL}；<br> 如果解码失败，返回{@link IMAGE_RESULT_DECODE_FAILED}；<br> 如果图像解码头错误，返回{@link IMAGE_RESULT_DECODE_HEAD_ABNORMAL}；<br> 如果创建解码器失败，返回 {@link IMAGE_RESULT_CREATE_DECODER_FAILED}；<br> 如果创建编码器失败，返回 {@link IMAGE_RESULT_CREATE_ENCODER_FAILED}；<br> 如果检查格式不对，返回{@IMAGE_RESULT_CHECK_FORMAT_ERROR }；<br> 如果skia错误，返回 {@link IMAGE_RESULT_THIRDPART_SKIA_ERROR}；<br> 如果输入图片数据错误，返回 {@link IMAGE_RESULT_DATA_ABNORMAL}。<br> 如果共享内存错误，返回 {@link IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST}；<br> 如果共享内存数据异常，返回 {@link IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL}；<br> 如果图片解码异常，返回 {@link IMAGE_RESULT_DECODE_ABNORMAL}；<br> 如果图像错误，返回 {@link IMAGE_RESULT_MALLOC_ABNORMAL}；<br> 如果图片初始化错误，返回 {@link IMAGE_RESULT_DATA_UNSUPPORT}；<br> 如果图片输入数据错误，返回 {@link IMAGE_RESULT_INIT_ABNORMAL}；<br> 如果裁剪错误，返回 {@link IMAGE_RESULT_CROP}；<br> 如果图片格式未知，返回 {@link IMAGE_RESULT_UNKNOWN_FORMAT}；<br> 如果注册插件失败，返回 {@link IMAGE_RESULT_PLUGIN_REGISTER_FAILED}；<br> 如果创建插件失败。返回 {@link IMAGE_RESULT_PLUGIN_CREATE_FAILED}；<br> 如果增加位图失败，返回 {@link IMAGE_RESULT_ENCODE_FAILED}；<br> 如果不支持图片硬解码，返回 {@link IMAGE_RESULT_HW_DECODE_UNSUPPORT}；<br> 如果硬解码失败，返回 {@link IMAGE_RESULT_HW_DECODE_FAILED}；<br> 如果ipc失败，返回 {@link IMAGE_RESULT_ERR_IPC}；<br> 如果索引无效，返回 {@link IMAGE_RESULT_INDEX_INVALID}；<br> 如果硬解码失败，返回 {@link IMAGE_RESULT_ALPHA_TYPE_ERROR}；<br> 如果硬解码失败，返回 {@link IMAGE_RESULT_ALLOCATER_TYPE_ERROR}。 |

**参考：**

{@link ImageSourceNative}, [OhosImageDecodingOps](capi-ohosimagedecodingops.md)

### OH_ImageSource_CreatePixelMapList()

```
int32_t OH_ImageSource_CreatePixelMapList(const ImageSourceNative* native,struct OhosImageDecodingOps* ops, napi_value *res)
```

**描述**

通过一个给定的选项[OhosImageDecodingOps](capi-ohosimagedecodingops.md)结构体，从<b>ImageSource</b>中解码所有的JavaScript native层API<b>PixelMap</b>对象列表

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageSourceNative* native | 表明native层 {@link ImageSourceNative} 值的指针。 |
| struct OhosImageDecodingOps* ops | 表明为了解码图像源的选项，查看[OhosImageDecodingOps](capi-ohosimagedecodingops.md)。 |
| napi_value *res | 表明JavaScript native层API<b>PixelMap</b> 列表对象的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}；<br> 如果获取图片数据异常，返回 {@link IMAGE_RESULT_GET_DATA_ABNORMAL}；<br> 如果解码失败，返回{@link IMAGE_RESULT_DECODE_FAILED}；<br> 如果图像解码头错误，返回{@link IMAGE_RESULT_DECODE_HEAD_ABNORMAL}；<br> 如果创建解码器失败，返回 {@link IMAGE_RESULT_CREATE_DECODER_FAILED}；<br> 如果创建编码器失败，返回 {@link IMAGE_RESULT_CREATE_ENCODER_FAILED}；<br> 如果检查格式不对，返回{@IMAGE_RESULT_CHECK_FORMAT_ERROR }；<br> 如果skia错误，返回 {@link IMAGE_RESULT_THIRDPART_SKIA_ERROR}；<br> 如果输入图片数据错误，返回 {@link IMAGE_RESULT_DATA_ABNORMAL}。<br> 如果共享内存错误，返回 {@link IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST}；<br> 如果共享内存数据异常，返回 {@link IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL}；<br> 如果图片解码异常，返回 {@link IMAGE_RESULT_DECODE_ABNORMAL}；<br> 如果图像错误，返回 {@link IMAGE_RESULT_MALLOC_ABNORMAL}；<br> 如果图片初始化错误，返回 {@link IMAGE_RESULT_DATA_UNSUPPORT}；<br> 如果图片输入数据错误，返回 {@link IMAGE_RESULT_INIT_ABNORMAL}；<br> 如果裁剪错误，返回 {@link IMAGE_RESULT_CROP}；<br> 如果图片格式未知，返回 {@link IMAGE_RESULT_UNKNOWN_FORMAT}；<br> 如果注册插件失败，返回 {@link IMAGE_RESULT_PLUGIN_REGISTER_FAILED}；<br> 如果创建插件失败。返回 {@link IMAGE_RESULT_PLUGIN_CREATE_FAILED}；<br> 如果增加位图失败，返回 {@link IMAGE_RESULT_ENCODE_FAILED}；<br> 如果不支持图片硬解码，返回 {@link IMAGE_RESULT_HW_DECODE_UNSUPPORT}；<br> 如果硬解码失败，返回 {@link IMAGE_RESULT_HW_DECODE_FAILED}；<br> 如果ipc失败，返回 {@link IMAGE_RESULT_ERR_IPC}；<br> 如果索引无效，返回 {@link IMAGE_RESULT_INDEX_INVALID}；<br> 如果硬解码失败，返回 {@link IMAGE_RESULT_ALPHA_TYPE_ERROR}；<br> 如果硬解码失败，返回 {@link IMAGE_RESULT_ALLOCATER_TYPE_ERROR}；<br> 如果解码的EXIF不支持，返回 {@link IMAGE_RESULT_DECODE_EXIF_UNSUPPORT}；<br> 如果图片属性不存在，返回 {@link IMAGE_RESULT_PROPERTY_NOT_EXIST}。 |

**参考：**

{@link ImageSourceNative}, [OhosImageDecodingOps](capi-ohosimagedecodingops.md)

### OH_ImageSource_GetDelayTime()

```
int32_t OH_ImageSource_GetDelayTime(const ImageSourceNative* native,struct OhosImageSourceDelayTimeList* res)
```

**描述**

从一些<b>ImageSource</b>（如GIF图像源）获取延迟时间列表。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageSourceNative* native | 表明native层 {@link ImageSourceNative} 值的指针。 |
| struct OhosImageSourceDelayTimeList* res | 表明延迟时间列表 [OhosImageSourceDelayTimeList](capi-ohosimagesourcedelaytimelist.md) 的指针。当输入的res中<b>delayTimeList</b>是空指针并且<b>size</b>是0时，将通过res的<b>size</b>中返回延迟时间列表大小为了获取延迟时间，需要比返回的<b>delayTimeList</b>大小值大的足够空间 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}；<br> 如果获取图片数据异常，返回 {@link IMAGE_RESULT_GET_DATA_ABNORMAL}；<br> 如果解码失败，返回{@link IMAGE_RESULT_DECODE_FAILED}；<br> 如果图像解码头错误，返回{@link IMAGE_RESULT_DECODE_HEAD_ABNORMAL}；<br> 如果创建解码器失败，返回 {@link IMAGE_RESULT_CREATE_DECODER_FAILED}；<br> 如果skia错误，返回 {@link IMAGE_RESULT_THIRDPART_SKIA_ERROR}；<br> 如果输入图片数据错误，返回 {@link IMAGE_RESULT_DATA_ABNORMAL}；<br> 如果图片解码异常， {@link IMAGE_RESULT_DECODE_ABNORMAL}；<br> 如果图片初始化错误，返回 {@link IMAGE_RESULT_DATA_UNSUPPORT}；<br> 如果图片格式未知，返回 {@link IMAGE_RESULT_UNKNOWN_FORMAT}；<br> 如果注册插件失败，返回 {@link IMAGE_RESULT_PLUGIN_REGISTER_FAILED}；<br> 如果创建插件失败。返回 {@link IMAGE_RESULT_PLUGIN_CREATE_FAILED}；<br> 如果索引无效，返回 {@link IMAGE_RESULT_INDEX_INVALID}；<br> 如果解码的EXIF不支持，返回 {@link IMAGE_RESULT_DECODE_EXIF_UNSUPPORT}；<br> 如果图片属性不存在，返回 {@link IMAGE_RESULT_PROPERTY_NOT_EXIST}。 |

**参考：**

{@link ImageSourceNative}, [OhosImageSourceDelayTimeList](capi-ohosimagesourcedelaytimelist.md)

### OH_ImageSource_GetFrameCount()

```
int32_t OH_ImageSource_GetFrameCount(const ImageSourceNative* native, uint32_t *res)
```

**描述**

从<b>ImageSource</b>中获取帧计数。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageSourceNative* native | 表明native层 {@link ImageSourceNative} 值的指针。 |
| uint32_t *res | 表明帧计数的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}；<br> 如果获取图片数据异常，返回 {@link IMAGE_RESULT_GET_DATA_ABNORMAL}；<br> 如果解码失败，返回{@link IMAGE_RESULT_DECODE_FAILED}；<br> 如果图像解码头错误，返回{@link IMAGE_RESULT_DECODE_HEAD_ABNORMAL}；<br> 如果创建解码器失败，返回 {@link IMAGE_RESULT_CREATE_DECODER_FAILED}；<br> 如果skia错误，返回 {@link IMAGE_RESULT_THIRDPART_SKIA_ERROR}；<br> 如果输入图片数据错误，返回 {@link IMAGE_RESULT_DATA_ABNORMAL}。<br> 如果图片解码异常， {@link IMAGE_RESULT_DECODE_ABNORMAL}；<br> 如果图片初始化错误，返回 {@link IMAGE_RESULT_DATA_UNSUPPORT}；<br> 如果图片格式未知，返回 {@link IMAGE_RESULT_UNKNOWN_FORMAT}；<br> 如果注册插件失败，返回 {@link IMAGE_RESULT_PLUGIN_REGISTER_FAILED}；<br> 如果创建插件失败。返回 {@link IMAGE_RESULT_PLUGIN_CREATE_FAILED}；<br> 如果索引无效，返回 {@link IMAGE_RESULT_INDEX_INVALID}；<br> 如果解码的EXIF不支持，返回 {@link IMAGE_RESULT_DECODE_EXIF_UNSUPPORT}；<br> 如果图片属性不存在，返回 {@link IMAGE_RESULT_PROPERTY_NOT_EXIST}。 |

**参考：**

{@link ImageSourceNative}

### OH_ImageSource_GetImageInfo()

```
int32_t OH_ImageSource_GetImageInfo(const ImageSourceNative* native, int32_t index,struct OhosImageSourceInfo* info)
```

**描述**

通过索引从<b>ImageSource</b>获取图像源信息。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const ImageSourceNative* native | 表明native层 {@link ImageSourceNative} 值的指针。 |
| int32_t index | 表明帧计数的指针。 |
| struct OhosImageSourceInfo* info | 表明图像源信息[OhosImageSourceInfo](capi-ohosimagesourceinfo.md)的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | 如果操作成功返回{@link OHOS_IMAGE_RESULT_SUCCESS}；<br> 如果参数错误，返回{@link IMAGE_RESULT_BAD_PARAMETER}；<br> 如果 JNI 环境异常，返回{@link IMAGE_RESULT_JNI_ENV_ABNORMAL}；<br> 如果参数无效，{@link IMAGE_RESULT_INVALID_PARAMETER}；<br> 如果获取图片数据异常，返回 {@link IMAGE_RESULT_GET_DATA_ABNORMAL}；<br> 如果解码失败，返回{@link IMAGE_RESULT_DECODE_FAILED}；<br> 如果图像解码头错误，返回{@link IMAGE_RESULT_DECODE_HEAD_ABNORMAL}；<br> 如果创建解码器失败，返回 {@link IMAGE_RESULT_CREATE_DECODER_FAILED}；<br> 如果skia错误，返回 {@link IMAGE_RESULT_THIRDPART_SKIA_ERROR}；<br> 如果输入图片数据错误，返回 {@link IMAGE_RESULT_DATA_ABNORMAL}。<br> 如果图片解码异常， {@link IMAGE_RESULT_DECODE_ABNORMAL}；<br> 如果图片初始化错误，返回 {@link IMAGE_RESULT_DATA_UNSUPPORT}；<br> 如果图片格式未知，返回 {@link IMAGE_RESULT_UNKNOWN_FORMAT}；<br> 如果注册插件失败，返回 {@link IMAGE_RESULT_PLUGIN_REGISTER_FAILED}；<br> 如果创建插件失败。返回 {@link IMAGE_RESULT_PLUGIN_CREATE_FAILED}；<br> 如果索引无效，返回 {@link IMAGE_RESULT_INDEX_INVALID}；<br> 如果解码的EXIF不支持，返回 {@link IMAGE_RESULT_DECODE_EXIF_UNSUPPORT}；<br> 如果图片属性不存在，返回 {@link IMAGE_RESULT_PROPERTY_NOT_EXIST}。 |

**参考：**

{@link ImageSourceNative}, [OhosImageSourceInfo](capi-ohosimagesourceinfo.md)

### OH_ImageSource_Release()

```
int32_t OH_ImageSource_Release(ImageSourceNative* native)
```

**描述**

释放native层图像源 <b>ImageSourceNative</b>。

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [ImageSourceNative](capi-imagesourcenative-.md)* native | 表明native层 {@link ImageSourceNative} 值的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| int32_t | {@link OHOS_IMAGE_RESULT_SUCCESS}如果操作成功；<br> {@link IMAGE_RESULT_BAD_PARAMETER}如果参数错误；<br> {@link IMAGE_RESULT_JNI_ENV_ABNORMAL}如果 JNI 环境异常；<br> {@link IMAGE_RESULT_INVALID_PARAMETER}如果参数无效；<br> {@link IMAGE_RESULT_GET_DATA_ABNORMAL}如果获取图片数据异常；<br> {@link IMAGE_RESULT_DATA_ABNORMAL}如果输入图片数据错误。 |

**参考：**

{@link ImageSourceNative}, {@link OH_ImageSource_Create}, {@link OH_ImageSource_CreateIncremental}


