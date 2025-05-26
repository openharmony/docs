# avimage_generator.h

## 概述

定义AVImageGenerator接口。使用其Native API从视频资源中获取指定时间点视频帧。

**库：** libavimage_generator.so

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18

**相关模块：** [AVImageGenerator](capi-avimagegenerator.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md) | OH_AVImageGenerator | 定义OH_AVImageGenerator类型，用于生成指定时间点视频帧。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVImageGenerator* OH_AVImageGenerator_Create(void)](#oh_avimagegenerator_create) | 创建OH_AVImageGenerator实例，用于生成指定时间点视频帧。 |
| [OH_AVErrCode OH_AVImageGenerator_SetFDSource(OH_AVImageGenerator* generator,int32_t fd, int64_t offset, int64_t size)](#oh_avimagegenerator_setfdsource) | 通过媒体文件描述设置数据源。 |
| [OH_AVErrCode OH_AVImageGenerator_FetchFrameByTime(OH_AVImageGenerator* generator,int64_t timeUs, OH_AVImageGenerator_QueryOptions options, OH_PixelmapNative** pixelMap)](#oh_avimagegenerator_fetchframebytime) | 从视频资源中获取指定时间点视频帧。此函数必须在｛@link SetFDSource｝之后调用。 |
| [OH_AVErrCode OH_AVImageGenerator_Release(OH_AVImageGenerator* generator)](#oh_avimagegenerator_release) | 释放用于OH_AVImageGenerator的资源以及销毁OH_AVImageGenerator实例。 |

## 函数说明

### OH_AVImageGenerator_Create()

```
OH_AVImageGenerator* OH_AVImageGenerator_Create(void)
```

**描述**

创建OH_AVImageGenerator实例，用于生成指定时间点视频帧。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVImageGenerator* | 创建成功时返回指向OH_AVImageGenerator实例的指针，否则返回空指针。<br>         可能的失败原因：HstEngineFactory未能创建AVMetadataHelperEngine。 |

### OH_AVImageGenerator_SetFDSource()

```
OH_AVErrCode OH_AVImageGenerator_SetFDSource(OH_AVImageGenerator* generator,int32_t fd, int64_t offset, int64_t size)
```

**描述**

通过媒体文件描述设置数据源。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md)* generator | 指向OH_AVImageGenerator实例的指针。 |
| int32_t fd | 媒体源的文件描述符。 |
| int64_t offset | 媒体源在文件描述符中的偏移量。 |
| int64_t size | 媒体源的大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功。<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的generator为空指针或参数无效。<br>         [AV_ERR_OPERATE_NOT_PERMIT](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 操作被禁止。<br>         [AV_ERR_NO_MEMORY](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 内部内存分配失败。 |

### OH_AVImageGenerator_FetchFrameByTime()

```
OH_AVErrCode OH_AVImageGenerator_FetchFrameByTime(OH_AVImageGenerator* generator,int64_t timeUs, OH_AVImageGenerator_QueryOptions options, OH_PixelmapNative** pixelMap)
```

**描述**

从视频资源中获取指定时间点视频帧。此函数必须在｛@link SetFDSource｝之后调用。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md)* generator | 指向OH_AVImageGenerator实例的指针。 |
| int64_t timeUs | 需要获取的视频帧在视频中的时间点，单位为微秒（μs）。 |
| [OH_AVImageGenerator_QueryOptions](capi-avimage-generator-base-h.md#oh_avimagegenerator_queryoptions) options | 关于给定时间Us和视频帧之间关系的时间选项，请参阅 [OH_AVImageGenerator_QueryOptions](capi-avimage-generator-base-h.md#oh_avimagegenerator_queryoptions) 。 |
| OH_PixelmapNative** pixelMap | 获取的视频帧对象。详细信息请参阅 [OH_PixelmapNative](../ImageKit/capi-pixelmap-native-h.md#oh_pixelmapnative_antialiasinglevel) 。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功。<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的generator为空指针或参数无效。<br>         [AV_ERR_OPERATE_NOT_PERMIT](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 操作被禁止。<br>         [AV_ERR_UNSUPPORTED_FORMAT](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 格式不支持。<br>         [AV_ERR_NO_MEMORY](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 内部内存分配失败。 |

### OH_AVImageGenerator_Release()

```
OH_AVErrCode OH_AVImageGenerator_Release(OH_AVImageGenerator* generator)
```

**描述**

释放用于OH_AVImageGenerator的资源以及销毁OH_AVImageGenerator实例。

**系统能力：** SystemCapability.Multimedia.Media.AVImageGenerator

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md)* generator | 指向OH_AVImageGenerator实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) | 函数结果代码：<br>         [AV_ERR_OK](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 执行成功。<br>         [AV_ERR_INVALID_VAL](../AVCodecKit/capi-native-averrors-h.md#oh_averrcode) 输入的generator为空指针或参数无效。 |


