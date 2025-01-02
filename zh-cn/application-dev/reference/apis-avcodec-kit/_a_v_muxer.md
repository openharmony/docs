# AVMuxer


## 概述

AVMuxer模块提供用于音视频封装功能的接口。

对应的开发指南及样例可参考[媒体数据封装](../../media/avcodec/audio-video-muxer.md)。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [native_avmuxer.h](native__avmuxer_8h.md) | 声明用于音视频封装的Native API。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AVMuxer](#oh_avmuxer) [OH_AVMuxer](#oh_avmuxer) | 为封装接口定义native层对象。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AVMuxer](#oh_avmuxer) \* [OH_AVMuxer_Create](#oh_avmuxer_create) (int32_t fd, [OH_AVOutputFormat](_codec_base.md#oh_avoutputformat) format) | 通过文件描述符fd和封装格式创建OH_AVMuxer实例。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetRotation](#oh_avmuxer_setrotation) ([OH_AVMuxer](#oh_avmuxer) \*muxer, int32_t rotation) | 设置视频的旋转角度（顺时针，且旋转角度必须为0、90、180或270）。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_SetFormat](#oh_avmuxer_setformat) ([OH_AVMuxer](#oh_avmuxer) \*muxer, [OH_AVFormat](_core.md#oh_avformat) \*format) | 设置format数据到封装器。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) ([OH_AVMuxer](#oh_avmuxer) \*muxer, int32_t \*trackIndex, [OH_AVFormat](_core.md#oh_avformat) \*trackFormat) | 向封装器添加音视频轨。| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Start](#oh_avmuxer_start) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | 开始封装。| 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample) ([OH_AVMuxer](#oh_avmuxer) \*muxer, uint32_t trackIndex, [OH_AVMemory](_core.md#oh_avmemory) \*sample, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) info) | 将sample写入封装器（API11已废弃）。 | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_WriteSampleBuffer](#oh_avmuxer_writesamplebuffer) ([OH_AVMuxer](#oh_avmuxer) \*muxer, uint32_t trackIndex, const [OH_AVBuffer](_core.md#oh_avbuffer) \*sample) | 将sample写入封装器。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Stop](#oh_avmuxer_stop) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | 停止封装。  | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVMuxer_Destroy](#oh_avmuxer_destroy) ([OH_AVMuxer](#oh_avmuxer) \*muxer) | 清理内部资源，销毁OH_AVMuxer实例。  | 


## 类型定义说明


### OH_AVMuxer

```
typedef struct OH_AVMuxer OH_AVMuxer
```
**描述**
为封装接口定义native层对象。

**起始版本：** 10


## 函数说明


### OH_AVMuxer_AddTrack()

```
OH_AVErrCode OH_AVMuxer_AddTrack (OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)
```
**描述**
向封装器添加音视频轨。每调用一次本接口可以在封装器中添加一个音视频轨。该接口必须在OH_AVMuxer_Start前调用。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 
| trackIndex | 用于获取该轨的索引，该值在OH_AVMuxer_WriteSample接口中使用。 如果音视频轨添加成功，该值大于或等于0，否则小于0。  | 
| trackFormat | 指向OH_AVFormat实例的指针。  | 

**返回：**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode)。

AV_ERR_INVALID_VAL，muxer为空指针，或trackIndex无效，或trackFormat无效。 AV_ERR_OPERATE_NOT_PERMIT，不允许调用接口，它在无效状态下被调用。AV_ERR_UNSUPPORT，不支持的mime类型。 AV_ERR_NO_MEMORY，申请内存失败。AV_ERR_UNKNOWN，未知错误。


### OH_AVMuxer_Create()

```
OH_AVMuxer* OH_AVMuxer_Create (int32_t fd, OH_AVOutputFormat format)
```
**描述**
通过文件描述符fd和封装格式创建OH_AVMuxer实例。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| fd | 用读写方式打开（O_RDWR），由调用者关闭该fd。  | 
| format | 封装输出的文件格式，参考[OH_AVOutputFormat](_codec_base.md#oh_avoutputformat)。  | 

**返回：**

返回一个指向OH_AVMuxer实例的指针, 需要调用OH_AVMuxer_Destroy销毁。


### OH_AVMuxer_Destroy()

```
OH_AVErrCode OH_AVMuxer_Destroy (OH_AVMuxer *muxer)
```
**描述**
清理内部资源，销毁OH_AVMuxer实例。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 

**返回：**

执行成功返回AV_ERR_OK，需调用者置空muxer；否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode)。

AV_ERR_INVALID_VAL，muxer为空指针。


### OH_AVMuxer_SetRotation()

```
OH_AVErrCode OH_AVMuxer_SetRotation (OH_AVMuxer *muxer, int32_t rotation)
```
**描述**
设置视频的旋转角度（顺时针，且旋转角度必须为0、90、180或270）。该接口必须在OH_AVMuxer_Start前调用。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 
| rotation | 角度，必须为0、90、180 或 270。  | 

**返回：**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode)。

AV_ERR_INVALID_VAL，muxer为空指针，或rotation无效。AV_ERR_OPERATE_NOT_PERMIT，不允许调用接口，它在无效状态下被调用。


### OH_AVMuxer_SetFormat()

```
OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)
```
**描述**
设置format数据到封装器。当前只支持设置创建时间OH_MD_KEY_CREATION_TIME。若创建时间未写入成功，请排查OH_MD_KEY_CREATION_TIME字符串设置是否符合ISO 8601标准的时间格式且为UTC时间。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 14

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 
| format | 指向OH_AVFormat实例的指针。文件级元数据集。  | 

**返回：**

AV_ERR_OK，设置format参数正确。

AV_ERR_INVALID_VAL，muxer为空指针，或format无效。AV_ERR_OPERATE_NOT_PERMIT，不允许调用接口，它在无效状态下被调用。


### OH_AVMuxer_Start()

```
OH_AVErrCode OH_AVMuxer_Start (OH_AVMuxer *muxer)
```
**描述**
开始封装。该接口必须在OH_AVMuxer_AddTrack后，OH_AVMuxer_WriteSample前调用。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 

**返回：**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode)。

AV_ERR_INVALID_VAL，muxer为空指针。AV_ERR_OPERATE_NOT_PERMIT，不允许调用接口，它在无效状态下被调用。AV_ERR_UNKNOWN，未知错误。


### OH_AVMuxer_Stop()

```
OH_AVErrCode OH_AVMuxer_Stop (OH_AVMuxer *muxer)
```
**描述**
停止封装。封装器停止后不支持重新开始。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 

**返回：**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode)。

AV_ERR_INVALID_VAL，muxer为空指针。AV_ERR_OPERATE_NOT_PERMIT，不允许调用接口，它在无效状态下被调用。


### OH_AVMuxer_WriteSample()

```
OH_AVErrCode OH_AVMuxer_WriteSample (OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)
```
**描述**
将sample写入封装器。该接口必须在OH_AVMuxer_Start后，OH_AVMuxer_Stop前调用。调用者需要按info中的时间顺序将sample写入正确的音视频轨。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**废弃版本：** 11

**替代接口：**[OH_AVMuxer_WriteSampleBuffer](#oh_avmuxer_writesamplebuffer)

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 
| trackIndex | 数据对应的音视频轨的索引。  | 
| sample | 编码或解封装得到的数据。  | 
| info | sample对应的描述信息，参考**OH_AVCodecBufferAttr**。  | 

**返回：**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode)。

AV_ERR_INVALID_VAL，muxer为空指针，或trackIndex无效，或sample无效，或info无效。AV_ERR_OPERATE_NOT_PERMIT，不允许调用接口，它在无效状态下被调用。AV_ERR_NO_MEMORY，申请内存失败。AV_ERR_UNKNOWN，未知错误。


### OH_AVMuxer_WriteSampleBuffer()

```
OH_AVErrCode OH_AVMuxer_WriteSampleBuffer (OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)
```
**描述**
将sample写入封装器。该接口必须在OH_AVMuxer_Start后，OH_AVMuxer_Stop前调用。 调用者需要按sample中的时间顺序将sample写入正确的音视频轨。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| muxer | 指向OH_AVMuxer实例的指针。  | 
| trackIndex | 数据对应的音视频轨的索引。  | 
| sample | 编码或解封装得到的数据。包含数据与数据属性  | 

**返回：**

执行成功返回AV_ERR_OK，否则返回具体错误码，参考[OH_AVErrCode](_core.md#oh_averrcode)。

AV_ERR_INVALID_VAL，muxer为空指针，或trackIndex无效，或sample无效。 AV_ERR_OPERATE_NOT_PERMIT，不允许调用接口，它在无效状态下被调用。 AV_ERR_NO_MEMORY，申请内存失败。AV_ERR_UNKNOWN，未知错误。
