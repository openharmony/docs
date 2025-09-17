# native_avdemuxer.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @zengyawen-->

## 概述

声明用于音视频媒体数据解析的接口。

**引用文件：** <multimedia/player_framework/native_avdemuxer.h>

**库：** libnative_media_avdemuxer.so

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**相关模块：** [AVDemuxer](capi-avdemuxer.md)

**相关示例：**[AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) | OH_AVDemuxer | 为OH_AVDemuxer接口定义native层对象。 |
| [DRM_MediaKeySystemInfo](capi-avdemuxer-drm-mediakeysysteminfo.md) | DRM_MediaKeySystemInfo | 为DRM_MediaKeySystemInf接口定义native层对象。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo* mediaKeySystemInfo)](#drm_mediakeysysteminfocallback) | DRM_MediaKeySystemInfoCallback | DRM_MediaKeySystemInfo回调函数指针类型，不返回解封装器实例，适用于单个解封装器实例场景。<br> 需要使用[OH_AVDemuxer_SetMediaKeySystemInfoCallback](#oh_avdemuxer_setmediakeysysteminfocallback)接口将其设置为回调。 |
| [typedef void (\*Demuxer_MediaKeySystemInfoCallback)(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#demuxer_mediakeysysteminfocallback) | Demuxer_MediaKeySystemInfoCallback | DRM_MediaKeySystemInfo回调函数指针类型，返回解封装器实例，适用于多个解封装器实例场景。<br> 需要使用[OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback)接口将其设置为回调，推荐使用。 |
| [OH_AVDemuxer *OH_AVDemuxer_CreateWithSource(OH_AVSource *source)](#oh_avdemuxer_createwithsource) | - | 通过source实例创建OH_AVDemuxer实例。<br> source的创建、销毁及使用，详情请参考[OH_AVSource](capi-avsource.md)。 |
| [OH_AVErrCode OH_AVDemuxer_Destroy(OH_AVDemuxer *demuxer)](#oh_avdemuxer_destroy) | - | 销毁OH_AVDemuxer实例并清理内部资源。同一实例只能被销毁一次。<br> 注意，销毁的实例在被重新创建之前不能再被使用。建议实例销毁成功后将指针置为NULL。 |
| [OH_AVErrCode OH_AVDemuxer_SelectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)](#oh_avdemuxer_selecttrackbyid) | - | 指定读取sample的轨道，解封装器将会从该轨道中读取数据，未指定的轨道不会读取。<br> 注意，通过多次调用接口并传入不同轨道的索引来选中多个轨道。<br> 调用[OH_AVDemuxer_ReadSample](#oh_avdemuxer_readsample)时只会读取被选中的轨道中数据，同一轨道被选择多次时，接口会返回AV_ERR_OK，并且只会生效一次。 |
| [OH_AVErrCode OH_AVDemuxer_UnselectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)](#oh_avdemuxer_unselecttrackbyid) | - | 移除读取sample的轨道，未选中的轨道的数据不会被解封装器读取。<br> 注意，通过多次调用接口并传入不同轨道的索引来取消对多个轨道的选择。<br> 同一轨道被多次取消选择时，接口会返回AV_ERR_OK，并且只会生效一次。 |
| [OH_AVErrCode OH_AVDemuxer_ReadSample(OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr *info)](#oh_avdemuxer_readsample) | - | 获取指定轨道的sample及相关信息。<br> 注意，读取轨道sample前，轨道必须被选中。调用接口后解封装器将自动前进到下一帧。 |
| [OH_AVErrCode OH_AVDemuxer_ReadSampleBuffer(OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVBuffer *sample)](#oh_avdemuxer_readsamplebuffer) | - | 获取指定轨道的sample及相关信息。<br> 注意，读取轨道sample前，轨道必须被选中。调用接口后解封装器将自动前进到下一帧。 |
| [OH_AVErrCode OH_AVDemuxer_SeekToTime(OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode)](#oh_avdemuxer_seektotime) | - | 根据设定的跳转模式，将所有选中的轨道到指定时间附近。 |
| [OH_AVErrCode OH_AVDemuxer_SetMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfoCallback callback)](#oh_avdemuxer_setmediakeysysteminfocallback) | - | 设置DRM信息回调函数。 |
| [OH_AVErrCode OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer, Demuxer_MediaKeySystemInfoCallback callback)](#oh_avdemuxer_setdemuxermediakeysysteminfocallback) | - | 设置DRM信息回调函数。 |
| [OH_AVErrCode OH_AVDemuxer_GetMediaKeySystemInfo(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)](#oh_avdemuxer_getmediakeysysteminfo) | - | 获取DRM信息。在[Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)或[DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)接口成功回调以后，调用此接口才能获取到DRM信息。 |

## 函数说明

### DRM_MediaKeySystemInfoCallback()

```
typedef void (*DRM_MediaKeySystemInfoCallback)(DRM_MediaKeySystemInfo* mediaKeySystemInfo)
```

**描述**

DRM_MediaKeySystemInfo回调函数指针类型，不返回解封装器实例，适用于单个解封装器实例场景。<br> 需要使用[OH_AVDemuxer_SetMediaKeySystemInfoCallback](#oh_avdemuxer_setmediakeysysteminfocallback)接口将其设置为回调。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11

**废弃版本：** 14

**替代接口：** [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)

### Demuxer_MediaKeySystemInfoCallback()

```
typedef void (*Demuxer_MediaKeySystemInfoCallback)(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**

DRM_MediaKeySystemInfo回调函数指针类型，返回解封装器实例，适用于多个解封装器实例场景。<br> 需要使用[OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback)接口将其设置为回调，推荐使用。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

### OH_AVDemuxer_CreateWithSource()

```
OH_AVDemuxer *OH_AVDemuxer_CreateWithSource(OH_AVSource *source)
```

**描述**

通过source实例创建OH_AVDemuxer实例。<br> source的创建、销毁及使用，详情请参考[OH_AVSource](capi-avsource.md)。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | 指向OH_AVSource实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) * | 返回一个指向OH_AVDemuxer实例的指针。<br> 如果执行成功，则返回指向OH_AVDemuxer实例的指针，否则返回NULL。<br> 可能的失败原因：<br> 1. source无效，即空指针或非OH_AVSource实例。<br> 2. 非OH_AVSource实例。 |

### OH_AVDemuxer_Destroy()

```
OH_AVErrCode OH_AVDemuxer_Destroy(OH_AVDemuxer *demuxer)
```

**描述**

销毁OH_AVDemuxer实例并清理内部资源。同一实例只能被销毁一次。<br> 注意，销毁的实例在被重新创建之前不能再被使用。建议实例销毁成功后将指针置为NULL。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：当输入的demuxer指针为空或非解封装器实例。 |

### OH_AVDemuxer_SelectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_SelectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**描述**

指定读取sample的轨道，解封装器将会从该轨道中读取数据，未指定的轨道不会读取。<br> 注意，通过多次调用接口并传入不同轨道的索引来选中多个轨道。<br> 调用[OH_AVDemuxer_ReadSample](#oh_avdemuxer_readsample)时只会读取被选中的轨道中数据，同一轨道被选择多次时，接口会返回AV_ERR_OK，并且只会生效一次。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| uint32_t trackIndex | 需选择的轨道的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：<br>                           1. 输入的demuxer指针为空或为非解封装器实例。<br>                           2. 轨道的索引超出范围。<br>                           3. 不支持读取轨道。<br>         AV_ERR_OPERATE_NOT_PERMIT：demuxer没有正确的初始化。 |

### OH_AVDemuxer_UnselectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_UnselectTrackByID(OH_AVDemuxer *demuxer, uint32_t trackIndex)
```

**描述**

移除读取sample的轨道，未选中的轨道的数据不会被解封装器读取。<br> 注意，通过多次调用接口并传入不同轨道的索引来取消对多个轨道的选择。<br> 同一轨道被多次取消选择时，接口会返回AV_ERR_OK，并且只会生效一次。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| uint32_t trackIndex | 需取消选择的轨道的索引。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入的demuxer指针为空或为非解封装器实例。<br>         AV_ERR_OPERATE_NOT_PERMIT：demuxer没有正确的初始化。 |

### OH_AVDemuxer_ReadSample()

```
OH_AVErrCode OH_AVDemuxer_ReadSample(OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr *info)
```

**描述**

获取指定轨道的sample及相关信息。<br> 注意，读取轨道sample前，轨道必须被选中。调用接口后解封装器将自动前进到下一帧。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**废弃版本：** 11

**替代接口：** [OH_AVDemuxer_ReadSampleBuffer](#oh_avdemuxer_readsamplebuffer)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| uint32_t trackIndex | 本次读取压缩帧的轨道的索引。 |
| [OH_AVMemory](capi-core-oh-avmemory.md) *sample | 指向OH_AVMemory实例的指针，用于储存压缩帧数据。 |
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) *info | 指向OH_AVCodecBufferAttr实例的指针，用于储存压缩帧的相关信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：<br>                           1. 输入的demuxer指针为空或为非解封装器实例。<br>                           2. 轨道的索引超出范围。<br>                           3. 不支持读取轨道。<br>                           4. 输入sample为空。<br>                           5. 输入info为空。<br>         AV_ERR_OPERATE_NOT_PERMIT：<br>                           1. 轨道的索引没有被选中。<br>                           2. demuxer没有正确的初始化。<br>         AV_ERR_NO_MEMORY：sample容量不足以存储所有帧数据。<br>         AV_ERR_UNKNOWN：无法从文件中读取或解析帧。 |

### OH_AVDemuxer_ReadSampleBuffer()

```
OH_AVErrCode OH_AVDemuxer_ReadSampleBuffer(OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVBuffer *sample)
```

**描述**

获取指定轨道的sample及相关信息。<br>注意，读取轨道sample前，轨道必须被选中，可使用[OH_AVDemuxer_SelectTrackByID](#oh_avdemuxer_selecttrackbyid)。调用接口后解封装器将自动前进到下一帧。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| uint32_t trackIndex | 本次读取压缩帧的轨道的索引。. |
| OH_AVBuffer *sample | 指向OH_AVBuffer实例的指针，用于储存压缩帧数据以及相关信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：<br>                           1. 输入的demuxer指针为空或为非解封装器实例。<br>                           2. sample为空指针。<br>                           3. 轨道的索引超出范围。<br>                           4. 输入sample为空。<br>         AV_ERR_OPERATE_NOT_PERMIT：<br>                           1. 轨道的索引没有被选中。<br>                           2. demuxer没有正确的初始化。<br>         AV_ERR_NO_MEMORY：sample容量不足以存储所有帧数据。<br>         AV_ERR_UNKNOWN：无法从文件中读取或解析帧。 |

### OH_AVDemuxer_SeekToTime()

```
OH_AVErrCode OH_AVDemuxer_SeekToTime(OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode)
```

**描述**

根据设定的跳转模式，将所有选中的轨道到指定时间附近。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| int64_t millisecond | 期望跳转位置对应的时间，单位为毫秒，该时间戳是相对文件开始的位置。 |
| [OH_AVSeekMode](_codec_base.md#oh_avseekmode) mode | 跳转的模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：<br>                           1. 输入的demuxer指针为空或为非解封装器实例。<br>                           2. 毫秒值超出范围。<br>         AV_ERR_OPERATE_NOT_PERMIT：<br>                           1. 轨道的索引没有被选中。<br>                           2. demuxer没有正确的初始化。<br>                           3. 资源无法seek。<br>         AV_ERR_UNKNOWN：<br>                           1. seek失败。<br>                           2. OH_AVSeekMode选择SEEK_MODE_NEXT_SYNC，并且时间点后无I帧，可能会跳转失败。 |

### OH_AVDemuxer_SetMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfoCallback callback)
```

**描述**

设置DRM信息回调函数。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11

**废弃版本：** 14

**替代接口：** [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback) callback | 回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br>         AV_ERR_OPERATE_NOT_PERMIT：demuxer没有正确的初始化。<br>         AV_ERR_INVALID_VAL：输入的demuxer指针为空或为非解封装器实例。 |

### OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback(OH_AVDemuxer *demuxer, Demuxer_MediaKeySystemInfoCallback callback)
```

**描述**

设置DRM信息回调函数。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback) callback | 回调函数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br>         AV_ERR_OPERATE_NOT_PERMIT：demuxer没有正确的初始化。<br>         AV_ERR_INVALID_VAL：输入的demuxer指针为空或为非解封装器实例。 |

### OH_AVDemuxer_GetMediaKeySystemInfo()

```
OH_AVErrCode OH_AVDemuxer_GetMediaKeySystemInfo(OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**

获取DRM信息。在[Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)或[DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)接口成功回调以后，调用此接口才能获取到DRM信息。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVDemuxer](capi-avdemuxer-oh-avdemuxer.md) *demuxer | 指向OH_AVDemuxer实例的指针。 |
| [DRM_MediaKeySystemInfo](capi-avdemuxer-drm-mediakeysysteminfo.md) *mediaKeySystemInfo | 指向DRM信息的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：操作成功。<br>         AV_ERR_INVALID_VAL：<br>                           1. 输入的demuxer指针为空或为非解封装器实例。<br>                           2. mediaKeySystemInfo为nullptr。 |


