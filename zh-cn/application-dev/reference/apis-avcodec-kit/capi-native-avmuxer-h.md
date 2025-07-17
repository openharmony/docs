# native_avmuxer.h

## 概述

声明用于音视频封装的Native API。

**引用文件：** <multimedia/player_framework/native_avmuxer.h>

**库：** libnative_media_avmuxer.so

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**相关模块：** [AVMuxer](capi-avmuxer.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) | OH_AVMuxer | 为封装接口定义native层对象。 |

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_AVMuxer *OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format)](#oh_avmuxer_create) | 通过文件描述符fd和封装格式创建OH_AVMuxer实例。 |
| [OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer *muxer, int32_t rotation)](#oh_avmuxer_setrotation) | 设置视频的旋转角度（顺时针）。Note: 这个接口必须在OH_AVMuxer_Start前调用。 |
| [OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)](#oh_avmuxer_setformat) | 设置format数据到封装器。Note: 当前只支持设置创建时间OH_MD_KEY_CREATION_TIME。若创建时间未写入成功，请排查OH_MD_KEY_CREATION_TIME字符串设置是否符合ISO 8601标准的时间格式且为UTC时间。 |
| [OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)](#oh_avmuxer_addtrack) | 向封装器添加媒体轨。Note: 该接口必须在OH_AVMuxer_Start前调用。 |
| [OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer *muxer)](#oh_avmuxer_start) | 开始封装。Note: 该接口必须在OH_AVMuxer_AddTrack后，OH_AVMuxer_WriteSample前调用。 |
| [OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)](#oh_avmuxer_writesample) | 将数据写入封装器。 Note: 该接口必须在OH_AVMuxer_Start后，OH_AVMuxer_Stop前调用。调用者需要保证数据写入正确的轨道，并按时间顺序排列。 |
| [OH_AVErrCode OH_AVMuxer_WriteSampleBuffer(OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)](#oh_avmuxer_writesamplebuffer) | 将数据写入封装器。 Note: 该接口必须在OH_AVMuxer_Start后，OH_AVMuxer_Stop前调用。调用者需要保证数据写入正确的轨道，并按时间顺序排列。 |
| [OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer *muxer)](#oh_avmuxer_stop) | 停止封装。Note: 封装器一旦停止，不能重新开始。 |
| [OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer *muxer)](#oh_avmuxer_destroy) | 清理内部资源，销毁OH_AVMuxer实例。 |

## 函数说明

### OH_AVMuxer_Create()

```
OH_AVMuxer *OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format)
```

**描述**

通过文件描述符fd和封装格式创建OH_AVMuxer实例。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| int32_t fd | 用读写方式打开（O_RDWR），由调用者关闭该fd。 |
| [OH_AVOutputFormat](capi-native-avcodec-base-h.md#oh_avoutputformat) format | 封装输出的文件格式，参考[OH_AVOutputFormat](capi-native-avcodec-base-h.md#oh_avoutputformat)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVMuxer * | 返回一个指向OH_AVMuxer实例的指针, 需要调用OH_AVMuxer_Destroy销毁。 |

### OH_AVMuxer_SetRotation()

```
OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer *muxer, int32_t rotation)
```

**描述**

设置视频的旋转角度（顺时针）。Note: 这个接口必须在OH_AVMuxer_Start前调用。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |
| int32_t rotation | 角度，必须为0、90、180 或 270。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 执行成功返回AV_ERR_OK，否则返回具体错误码，参考{@link OH_AVErrCode}。<br>         AV_ERR_INVALID_VAL：muxer为空指针，或rotation无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：不允许调用接口，它在无效状态下被调用。 |

### OH_AVMuxer_SetFormat()

```
OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)
```

**描述**

设置format数据到封装器。Note: 当前只支持设置创建时间OH_MD_KEY_CREATION_TIME。若创建时间未写入成功，请排查OH_MD_KEY_CREATION_TIME字符串设置是否符合ISO 8601标准的时间格式且为UTC时间。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 14


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |
| 指向OH_AVFormat实例的指针。文件级元数据集。 |  |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | AV_ERR_OK：设置format参数正确。<br>         AV_ERR_INVALID_VAL：muxer为空指针，或format无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：不允许调用接口，它在无效状态下被调用。 |

### OH_AVMuxer_AddTrack()

```
OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)
```

**描述**

向封装器添加媒体轨。Note: 该接口必须在OH_AVMuxer_Start前调用。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |
| int32_t *trackIndex | 用于获取该轨的索引，该值在OH_AVMuxer_WriteSample接口中使用。如果媒体轨添加成功，该值大于或等于0，否则小于0。 |
| OH_AVFormat *trackFormat | 指向OH_AVFormat实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 执行成功返回AV_ERR_OK，否则返回具体错误码，参考{@link OH_AVErrCode}。<br>         AV_ERR_INVALID_VAL：muxer为空指针，或trackIndex无效，或trackFormat无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：不允许调用接口，它在无效状态下被调用。<br>         AV_ERR_UNSUPPORT：不支持的mime类型。<br>         AV_ERR_NO_MEMORY：申请内存失败。<br>         AV_ERR_UNKNOWN：未知错误。 |

### OH_AVMuxer_Start()

```
OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer *muxer)
```

**描述**

开始封装。Note: 该接口必须在OH_AVMuxer_AddTrack后，OH_AVMuxer_WriteSample前调用。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 执行成功返回AV_ERR_OK，否则返回具体错误码，参考{@link OH_AVErrCode}。<br>         AV_ERR_INVALID_VAL：muxer为空指针。<br>         AV_ERR_OPERATE_NOT_PERMIT：不允许调用接口，它在无效状态下被调用。<br>         AV_ERR_UNKNOWN：未知错误。 |

### OH_AVMuxer_WriteSample()

```
OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)
```

**描述**

将数据写入封装器。 Note: 该接口必须在OH_AVMuxer_Start后，OH_AVMuxer_Stop前调用。调用者需要保证数据写入正确的轨道，并按时间顺序排列。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10

**废弃版本：** 11

**替代接口：** [OH_AVMuxer_WriteSampleBuffer](capi-native-avmuxer-h.md#oh_avmuxer_writesamplebuffer)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |
| uint32_t trackIndex | 数据对应的媒体轨的索引。 |
| OH_AVMemory *sample | 写入的数据，编码或解封装得到的数据。 |
| OH_AVCodecBufferAttr info | 写入数据的信息，参考{@link OH_AVCodecBufferAttr}。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 执行成功返回AV_ERR_OK，否则返回具体错误码，参考{@link OH_AVErrCode}。<br>         AV_ERR_INVALID_VAL：muxer为空指针，或trackIndex无效，或sample无效，或info无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：不允许调用接口，它在无效状态下被调用。<br>         AV_ERR_NO_MEMORY：申请内存失败。<br>         AV_ERR_UNKNOWN：未知错误。 |

### OH_AVMuxer_WriteSampleBuffer()

```
OH_AVErrCode OH_AVMuxer_WriteSampleBuffer(OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)
```

**描述**

将数据写入封装器。 Note: 该接口必须在OH_AVMuxer_Start后，OH_AVMuxer_Stop前调用。调用者需要保证数据写入正确的轨道，并按时间顺序排列。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |
| uint32_t trackIndex | 数据对应的媒体轨的索引。 |
| const OH_AVBuffer *sample | 写入的数据，编码或解封装得到的数据。包含数据与数据属性 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 执行成功返回AV_ERR_OK，否则返回具体错误码，参考{@link OH_AVErrCode}。<br>         AV_ERR_INVALID_VAL：muxer为空指针，或trackIndex无效，或sample无效。<br>         AV_ERR_OPERATE_NOT_PERMIT：不允许调用接口，它在无效状态下被调用。<br>         AV_ERR_NO_MEMORY：申请内存失败。<br>         AV_ERR_UNKNOWN：未知错误。 |

### OH_AVMuxer_Stop()

```
OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer *muxer)
```

**描述**

停止封装。Note: 封装器一旦停止，不能重新开始。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 执行成功返回AV_ERR_OK，否则返回具体错误码，参考{@link OH_AVErrCode}。<br>         AV_ERR_INVALID_VAL：muxer为空指针。<br>         AV_ERR_OPERATE_NOT_PERMIT：不允许调用接口，它在无效状态下被调用。 |

### OH_AVMuxer_Destroy()

```
OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer *muxer)
```

**描述**

清理内部资源，销毁OH_AVMuxer实例。

**系统能力：** SystemCapability.Multimedia.Media.Muxer

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | 指向OH_AVMuxer实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 执行成功返回AV_ERR_OK，需调用者置空muxer；否则返回具体错误码，参考{@link OH_AVErrCode}。<br>         AV_ERR_INVALID_VAL：muxer为空指针。 |


