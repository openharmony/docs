# native_avsource.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @zengyawen-->

## 概述

声明用于音视频媒体数据解析的接口。

**引用文件：** <multimedia/player_framework/native_avsource.h>

**库：** libnative_media_avsource.so

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**相关模块：** [AVSource](capi-avsource.md)

**相关示例：** [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) | OH_AVSource | 为媒体资源接口定义native层对象。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVSource *OH_AVSource_CreateWithDataSource(OH_AVDataSource *dataSource)](#oh_avsource_createwithdatasource) | 为用户自定义数据源的资源对象创建OH_AVSource实例，可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。 |
| [OH_AVSource *OH_AVSource_CreateWithDataSourceExt(OH_AVDataSourceExt *dataSource, void *userData)](#oh_avsource_createwithdatasourceext) | 为用户自定义数据源的资源对象创建OH_AVSource实例，可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。<br> 回调支持通过userData传递用户自定义数据。 |
| [OH_AVSource *OH_AVSource_CreateWithURI(char *uri)](#oh_avsource_createwithuri) | 为统一资源标识符对应的资源对象创建OH_AVSource实例，可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。 |
| [OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size)](#oh_avsource_createwithfd) | 为文件描述符对应的资源对象创建OH_AVSource实例。可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。<br> 接口如果传入offset不为文件起始位置，或size不为文件大小时，可能会因数据获取不完整导致OH_AVSource创建失败、后续解封装失败等未定义错误。 |
| [OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source)](#oh_avsource_destroy) | 销毁OH_AVSource实例并清理内部资源。<br> 同一实例只能被销毁一次。销毁的实例在被重新创建之前不能再被使用。建议实例销毁成功后将指针置为NULL。 |
| [OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source)](#oh_avsource_getsourceformat) | 获取媒体资源文件的基础信息。<br> 需要注意的是，指向的OH_AVFormat实例在生命周期结束时需调用者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。 |
| [OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackIndex)](#oh_avsource_gettrackformat) | 获取轨道的基础信息。<br> 需要注意的是，指向的OH_AVFormat实例在生命周期结束时需调用者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。 |
| [OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source)](#oh_avsource_getcustommetadataformat) | 获取自定义元数据的基础信息。<br> 需要注意的是，指向的OH_AVFormat实例在生命周期结束时需开发者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。 |

## 函数说明

### OH_AVSource_CreateWithDataSource()

```
OH_AVSource *OH_AVSource_CreateWithDataSource(OH_AVDataSource *dataSource)
```

**描述**

为用户自定义数据源的资源对象创建OH_AVSource实例，可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDataSource](_codec_base.md#oh_avdatasource) *dataSource | 用户自定义数据源。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | 如果执行成功，则返回一个指向OH_AVSource实例的指针，否则返回NULL。<br> 可能的故障原因：<br> 1. dataSource为nullptr。<br> 2. dataSource->size == 0。<br> 3. 设置数据源失败。<br> 4. 内存不足。<br> 5. 解码器引擎为nullptr。<br> 6. dataSource-&gt;readAt == nullptr。 |

### OH_AVSource_CreateWithDataSourceExt()

```
OH_AVSource *OH_AVSource_CreateWithDataSourceExt(OH_AVDataSourceExt *dataSource, void *userData)
```

**描述**

为用户自定义数据源的资源对象创建OH_AVSource实例，可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。<br> 回调支持通过userData传递用户自定义数据。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDataSourceExt](_codec_base.md#oh_avdatasourcereadatext) *dataSource | 指向数据源结构体的指针，该结构体可用于获取输入数据。 |
| void *userData | 指向用户自定义数据的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | 如果执行成功，则返回一个指向OH_AVSource实例的指针，否则返回NULL。<br> 可能的故障原因：<br> 1. dataSource为nullptr。<br> 2. dataSource->size == 0。<br> 3. 设置数据源失败。<br> 4. 内存不足。<br> 5. 解码器引擎为nullptr。<br> 6. dataSource-&gt;readAt == nullptr。 |

### OH_AVSource_CreateWithURI()

```
OH_AVSource *OH_AVSource_CreateWithURI(char *uri)
```

**描述**

为统一资源标识符对应的资源对象创建OH_AVSource实例，可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| char *uri | 远程媒体资源的统一资源标识符。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | 执行成功返回一个指向OH_AVSource实例的指针, 否则返回NULL。<br> 可能的故障原因：<br> 1. 网络异常。<br> 2. 资源无效。<br> 3. 文件格式不支持。 |

### OH_AVSource_CreateWithFD()

```
OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size)
```

**描述**

为文件描述符对应的资源对象创建OH_AVSource实例。可以通过调用[OH_AVSource_Destroy](#oh_avsource_destroy)接口释放实例。<br> 接口如果传入offset不为文件起始位置，或size不为文件大小时，可能会因数据获取不完整导致OH_AVSource创建失败、后续解封装失败等未定义错误。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t fd | 数据资源的文件描述符。 |
| int64_t offset | 开始读取数据的位置。 |
| int64_t size | 文件的字节数大小。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | 执行成功返回一个指向OH_AVSource实例的指针, 否则返回NULL。<br> 可能的故障原因：<br> 1. fd无效。<br> 2. 传入offset不是文件起始位置。<br> 3. size错误。<br> 4. 资源无效。<br> 5. 文件格式不支持。 |

### OH_AVSource_Destroy()

```
OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source)
```

**描述**

销毁OH_AVSource实例并清理内部资源。<br> 同一实例只能被销毁一次。销毁的实例在被重新创建之前不能再被使用。建议实例销毁成功后将指针置为NULL。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | 指向OH_AVSource实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br>         AV_ERR_INVALID_VAL：<br>                          1. source指针无效，空指针。<br>                          2. 非OH_AVSource实例。 |

### OH_AVSource_GetSourceFormat()

```
OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source)
```

**描述**

获取媒体资源文件的基础信息。<br> 需要注意的是，指向的OH_AVFormat实例在生命周期结束时需调用者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | 指向OH_AVSource实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | 执行成功返回文件的基础信息，否则返回NULL。<br> 可能的故障原因：<br> 1. source指针无效。<br> 2. 空指针或非OH_AVSource实例。<br> 3. source没有初始化。 |

### OH_AVSource_GetTrackFormat()

```
OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackIndex)
```

**描述**

获取轨道的基础信息。<br> 需要注意的是，指向的OH_AVFormat实例在生命周期结束时需调用者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | 指向OH_AVSource实例的指针。 |
| uint32_t trackIndex | 需要获取信息的轨道的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | 执行成功返回轨道的基础信息，否则返回NULL。<br> 可能的故障原因：<br> 1. source指针无效，空指针或非OH_AVSource实例。<br> 2. 轨道的索引超出范围。<br> 3. source没有初始化。 |

### OH_AVSource_GetCustomMetadataFormat()

```
OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source)
```

**描述**

获取自定义元数据的基础信息。<br> 需要注意的是，指向的OH_AVFormat实例在生命周期结束时需开发者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 18


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | 指向OH_AVSource实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | 执行成功返回元数据的基础信息，否则返回NULL。<br> 可能的故障原因：<br> 1. source指针无效。<br> 2. 空指针或非OH_AVSource实例。<br> 3. source没有初始化。 |


