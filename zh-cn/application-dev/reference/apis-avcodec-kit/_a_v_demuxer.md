# AVDemuxer


## 概述

AVDemuxer模块提供用于音视频解封装功能的函数。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avdemuxer.h](native__avdemuxer_8h.md) | 声明用于音视频解封装的Native API。<br>**引用文件**：<multimedia/player_framework/native_avdemuxer.h><br>**库**：libnative_media_avdemuxer.so | 

### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void(* [DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)) (DRM_MediaKeySystemInfo *mediaKeySystemInfo) | 媒体密钥系统信息回调函数指针类型。  |
| typedef void(* [Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)) (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)| 媒体密钥系统信息回调函数指针类型。  |


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OH_AVDemuxer \* [OH_AVDemuxer_CreateWithSource](#oh_avdemuxer_createwithsource) ([OH_AVSource](_a_v_source.md#oh_avsource) \*source) | 通过source实例对象创建OH_AVDemuxer实例对象。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_Destroy](#oh_avdemuxer_destroy) (OH_AVDemuxer \*demuxer) | 销毁OH_AVDemuxer实例并清理内部资源。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SelectTrackByID](#oh_avdemuxer_selecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | 选中指定轨道，解封装器将会从该轨道中读取数据。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_UnselectTrackByID](#oh_avdemuxer_unselecttrackbyid) (OH_AVDemuxer \*demuxer, uint32_t trackIndex) | 取消选择指定轨道，未选中的轨道的数据不会被解封装器读取。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_ReadSample](#oh_avdemuxer_readsample) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*info) | 从选中轨道中获取当前位置压缩帧及相关信息。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_ReadSampleBuffer](#oh_avdemuxer_readsamplebuffer) (OH_AVDemuxer \*demuxer, uint32_t trackIndex, [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | 从选中轨道中获取当前位置压缩帧及相关信息。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SeekToTime](#oh_avdemuxer_seektotime) (OH_AVDemuxer \*demuxer, int64_t millisecond, [OH_AVSeekMode](_codec_base.md#oh_avseekmode) mode) | 根据设定的跳转模式，将所有选中的轨道到指定时间附近。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SetMediaKeySystemInfoCallback](#oh_avdemuxer_setmediakeysysteminfocallback) (OH_AVDemuxer \*demuxer, DRM_MediaKeySystemInfoCallback callback) | 设置异步DRM信息回调函数。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback](#oh_avdemuxer_setdemuxermediakeysysteminfocallback) (OH_AVDemuxer \*demuxer, Demuxer_MediaKeySystemInfoCallback callback) | 设置异步DRM信息回调函数。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVDemuxer_GetMediaKeySystemInfo](#oh_avdemuxer_getmediakeysysteminfo) (OH_AVDemuxer \*demuxer, DRM_MediaKeySystemInfo \*mediaKeySystemInfo) | 获取DRM信息。  | 


## 类型定义说明

### Demuxer_MediaKeySystemInfoCallback

```
typedef void(* Demuxer_MediaKeySystemInfoCallback) (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**
媒体密钥系统信息回调函数指针类型。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12


### DRM_MediaKeySystemInfoCallback

```
typedef void(* DRM_MediaKeySystemInfoCallback) (DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```

**描述**
媒体密钥系统信息回调函数指针类型。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11


## 函数说明


### OH_AVDemuxer_CreateWithSource()

```
OH_AVDemuxer* OH_AVDemuxer_CreateWithSource (OH_AVSource *source)
```
**描述**
通过source实例对象创建OH_AVDemuxer实例对象。可以通过调用[OH_AVDemuxer_Destroy](#oh_avdemuxer_destroy)释放实例。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| source | 指向OH_AVSource实例的指针。  | 

**返回：**

返回一个指向OH_AVDemuxer实例的指针。

如果执行成功，则返回指向OH_AVDemuxer实例的指针，否则返回nullptr。
 
可能的失败原因：source无效，即空指针或非OH_AVSource实例。 


### OH_AVDemuxer_Destroy()

```
OH_AVErrCode OH_AVDemuxer_Destroy (OH_AVDemuxer *demuxer)
```
**描述**
销毁OH_AVDemuxer实例并清理内部资源。同一实例只能被销毁一次。注意，销毁的实例在被重新创建之前不能再被使用。建议实例销毁成功后将指针置为NULL。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 

**返回：**

执行成功返回AV_ERR_OK, 否则返回具体错误码请参阅[OH_AVErrCode](_core.md#oh_averrcode)。 

当输入的demuxer指针为空或非解封装器实例，返回AV_ERR_INVALID_VAL。


### OH_AVDemuxer_GetMediaKeySystemInfo()

```
OH_AVErrCode OH_AVDemuxer_GetMediaKeySystemInfo (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfo *mediaKeySystemInfo)
```
**描述**
获取DRM信息。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| mediaKeySystemInfo | 指向DRM信息的指针，请参阅[DRM_MediaKeySystemInfo](../apis-drm-kit/_d_r_m___media_key_system_info.md)。  | 

**返回：**

返回函数结果代码[OH_AVErrCode](_core.md#oh_averrcode)：

AV_ERR_OK：操作成功。

AV_ERR_INVALID_VAL：解复用器实例为nullptr或无效，或者mediaKeySystemInfo为nullptr。


### OH_AVDemuxer_ReadSample()

```
OH_AVErrCode OH_AVDemuxer_ReadSample (OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr *info)
```
**描述**
从选中轨道中获取当前位置压缩帧及相关信息。注意，读取轨道帧数据前，轨道必须被选中。调用接口后解封装器将自动前进到下一帧。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**废弃版本：** 11

**替代接口：**[OH_AVDemuxer_ReadSampleBuffer](#oh_avdemuxer_readsamplebuffer)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| trackIndex | 本次读取压缩帧的轨道的索引。  | 
| sample | 指向OH_AVMemory实例的指针，用于储存压缩帧数据。  | 
| info | 指向OH_AVCodecBufferAttr实例的指针，用于储存压缩帧的相关信息。  | 

**返回：**

执行成功返回AV_ERR_OK, 否则返回具体错误码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当输入的demuxer指针为空或非解封装器实例，或demuxer没有正确的初始化，或轨道的索引超出范围，或者不支持读取轨道，返回AV_ERR_INVALID_VAL。轨道的索引没有被选中，返回AV_ERR_OPERATE_NOT_PERMIT。sample容量不足以存储所有帧数据，返回AV_ERR_NO_MEMORY。无法从文件中读取或解析帧，返回AV_ERR_UNKNOWN。


### OH_AVDemuxer_ReadSampleBuffer()

```
OH_AVErrCode OH_AVDemuxer_ReadSampleBuffer (OH_AVDemuxer *demuxer, uint32_t trackIndex, OH_AVBuffer *sample)
```
**描述**
从选中轨道中获取当前位置压缩帧及相关信息。注意，读取轨道帧数据前，轨道必须被选中。调用接口后解封装器将自动前进到下一帧。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| trackIndex | 本次读取压缩帧的轨道的索引。  | 
| sample | 指向OH_AVBuffer实例的指针，用于储存压缩帧数据以及相关信息。  | 

**返回：**

执行成功返回AV_ERR_OK, 否则返回具体错误码请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当输入的demuxer指针为空或非解封装器实例，或demuxer没有正确的初始化，或sample为空指针， 或者轨道的索引超出范围，返回AV_ERR_INVALID_VAL。 轨道的索引没有被选中，返回AV_ERR_OPERATE_NOT_PERMIT。 sample容量不足以存储所有帧数据，返回AV_ERR_NO_MEMORY。 无法从文件中读取或解析帧，返回AV_ERR_UNKNOWN。


### OH_AVDemuxer_SeekToTime()

```
OH_AVErrCode OH_AVDemuxer_SeekToTime (OH_AVDemuxer *demuxer, int64_t millisecond, OH_AVSeekMode mode)
```
**描述**
根据设定的跳转模式，将所有选中的轨道到指定时间附近。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| millisecond | 期望跳转位置对应的时间，单位为毫秒，该时间戳是相对文件开始的位置。  | 
| mode | 跳转的模式，参考[OH_AVSeekMode](_codec_base.md#oh_avseekmode)。  | 

**返回：**

执行成功返回AV_ERR_OK, 否则返回具体错误码，请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当输入的demuxer指针为空或非解封装器实例，或demuxer没有正确的初始化，或毫秒值超出范围，返回AV_ERR_INVALID_VAL。轨道的索引没有被选中，或者资源无法seek，返回AV_ERR_OPERATE_NOT_PERMIT。seek失败，返回AV_ERR_UNKNOWN。


### OH_AVDemuxer_SelectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_SelectTrackByID (OH_AVDemuxer *demuxer, uint32_t trackIndex)
```
**描述**
选中指定轨道，解封装器将会从该轨道中读取数据。注意，通过多次调用接口并传入不同轨道的索引来选中多个轨道。 调用OH_AVDemuxer_ReadSample时只会读取被选中的轨道中数据，同一轨道被选择多次时，接口会返回AV_ERR_OK，并且只会生效一次。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| trackIndex | 需选择的轨道的索引。  | 

**返回：**

执行成功返回AV_ERR_OK, 否则返回具体错误码请参阅[OH_AVErrCode](_core.md#oh_averrcode)。 

当输入的demuxer指针为空或非解封装器实例，或demuxer没有正确的初始化，或轨道的索引超出范围， 或者不支持读取轨道，返回AV_ERR_INVALID_VAL。


### OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetDemuxerMediaKeySystemInfoCallback (OH_AVDemuxer *demuxer, Demuxer_MediaKeySystemInfoCallback callback)
```
**描述**
设置异步DRM信息回调函数。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| callback | 回调函数，详见[Demuxer_MediaKeySystemInfoCallback](#demuxer_mediakeysysteminfocallback)。  | 

**返回：**

返回函数结果代码[OH_AVErrCode](_core.md#oh_averrcode)：

AV_ERR_OK：操作成功。

AV_ERR_OPERATE_NOT_PERMIT：解复用器引擎未启动或初始化失败。

AV_ERR_INVALID_VAL：解复用器实例为nullptr或无效。


### OH_AVDemuxer_SetMediaKeySystemInfoCallback()

```
OH_AVErrCode OH_AVDemuxer_SetMediaKeySystemInfoCallback (OH_AVDemuxer *demuxer, DRM_MediaKeySystemInfoCallback callback)
```
**描述**
设置异步DRM信息回调函数。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| callback | 回调函数，详见[DRM_MediaKeySystemInfoCallback](#drm_mediakeysysteminfocallback)。  | 

**返回：**

返回函数结果代码[OH_AVErrCode](_core.md#oh_averrcode)：

AV_ERR_OK：操作成功。

AV_ERR_OPERATE_NOT_PERMIT：解复用器引擎未启动或初始化失败。

AV_ERR_INVALID_VAL：解复用器实例为nullptr或无效。


### OH_AVDemuxer_UnselectTrackByID()

```
OH_AVErrCode OH_AVDemuxer_UnselectTrackByID (OH_AVDemuxer *demuxer, uint32_t trackIndex)
```
**描述**
取消选择指定轨道，未选中的轨道的数据不会被解封装器读取。注意，通过多次调用接口并传入不同轨道的索引来取消对多个轨道的选择。 同一轨道被多次取消选择时，接口会返回AV_ERR_OK，并且只会生效一次。

**系统能力：** SystemCapability.Multimedia.Media.Spliter

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| demuxer | 指向OH_AVDemuxer实例的指针。  | 
| trackIndex | 需取消选择的轨道的索引。  | 

**返回：**

执行成功返回AV_ERR_OK, 否则返回具体错误码请参阅[OH_AVErrCode](_core.md#oh_averrcode)。

当输入的demuxer指针为空或非解封装器实例，或者没有正确的初始化，返回AV_ERR_INVALID_VAL。
