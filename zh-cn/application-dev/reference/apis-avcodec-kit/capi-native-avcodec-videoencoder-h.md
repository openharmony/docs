# native_avcodec_videoencoder.h

## 概述

声明用于视频编码的接口。

**引用文件：** <multimedia/player_framework/native_avcodec_videoencoder.h>

**库：** libnative_media_venc.so

**系统能力：** SystemCapability.Multimedia.VideoEncoder

**起始版本：** 9

**相关模块：** [VideoEncoder](capi-videoencoder.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_VideoEncodeBitrateMode](#oh_videoencodebitratemode) | OH_VideoEncodeBitrateMode | 视频编码器的码率控制模式。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_VideoEncoder_OnNeedInputParameter)(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter,void *userData)](#oh_videoencoder_onneedinputparameter) | OH_VideoEncoder_OnNeedInputParameter | 配置随帧参数，当需要设置index对应帧的编码参数时，可以通过该接口设置。只在Surface模式生效。 |
| [OH_AVCodec *OH_VideoEncoder_CreateByMime(const char *mime)](#oh_videoencoder_createbymime) | - | 根据MIME类型创建视频编码器实例，推荐使用。 |
| [OH_AVCodec *OH_VideoEncoder_CreateByName(const char *name)](#oh_videoencoder_createbyname) | - | 根据视频编码器名称创建视频编码器实例。使用此接口的前提是知道编码器的确切名称，编码器的名称可以通过能力查询获取。 |
| [OH_AVErrCode OH_VideoEncoder_Destroy(OH_AVCodec *codec)](#oh_videoencoder_destroy) | - | 清理编码器内部资源，销毁编码器实例。不能重复销毁。 |
| [OH_AVErrCode OH_VideoEncoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)](#oh_videoencoder_setcallback) | - | 设置OH_AVCodecCallback回调函数，让应用可以响应视频编码器生成的事件。在调用OH_VideoEncoder_Prepare接口之前，必须调用此接口。 |
| [OH_AVErrCode OH_VideoEncoder_RegisterCallback(OH_AVCodec *codec, OH_AVCodecCallback callback, void *userData)](#oh_videoencoder_registercallback) | - | 注册OH_AVCodecCallback回调函数，让应用可以响应视频编码器生成的事件。在调用OH_VideoEncoder_Prepare接口之前，必须调用此接口。 |
| [OH_AVErrCode OH_VideoEncoder_RegisterParameterCallback(OH_AVCodec *codec,OH_VideoEncoder_OnNeedInputParameter onInputParameter,void *userData)](#oh_videoencoder_registerparametercallback) | - | 注册OH_AVCodecCallback输入参数回调函数，让应用可以响应视频编码器生成的事件。编码Surface模式，需要设置随帧参数时，须使用该接口。如果使用该接口，必须在[OH_VideoEncoder_Configure](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_configure)之前调用该接口。 |
| [OH_AVErrCode OH_VideoEncoder_Configure(OH_AVCodec *codec, OH_AVFormat *format)](#oh_videoencoder_configure) | - | 配置视频编码器的编码参数，通常需要配置要编码的视频轨的描述信息，如宽、高、像素格式等。必须在调用OH_VideoEncoder_Prepare接口之前，调用此接口。 |
| [OH_AVErrCode OH_VideoEncoder_Prepare(OH_AVCodec *codec)](#oh_videoencoder_prepare) | - | 准备编码器的内部资源，在OH_VideoEncoder_Configure接口后调用。 |
| [OH_AVErrCode OH_VideoEncoder_Start(OH_AVCodec *codec)](#oh_videoencoder_start) | - | 调用[OH_VideoEncoder_Prepare](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_prepare)接口成功后调用此接口启动编码器。成功启动后，编码器将开始报告注册的回调事件。 |
| [OH_AVErrCode OH_VideoEncoder_Stop(OH_AVCodec *codec)](#oh_videoencoder_stop) | - | 停止编码器，释放输入输出buffer。停止之后，可以通过调用OH_VideoEncoder_Start接口重新进入Running状态。 |
| [OH_AVErrCode OH_VideoEncoder_Flush(OH_AVCodec *codec)](#oh_videoencoder_flush) | - | 清除编码器中缓存的输入和输出数据及参数集如H264格式的PPS/SPS。调用此接口后，以前通过异步回调上报的所有缓冲区index都将失效，请确保不要访问这些index对应的缓冲区。该接口不能连续调用。 |
| [OH_AVErrCode OH_VideoEncoder_Reset(OH_AVCodec *codec)](#oh_videoencoder_reset) | - | 重置编码器，编码器回到初始化状态。如果要继续编码，需要再次调用OH_VideoEncoder_Configure接口配置编码器实例。 |
| [OH_AVFormat *OH_VideoEncoder_GetOutputDescription(OH_AVCodec *codec)](#oh_videoencoder_getoutputdescription) | - | 获取编码器输出数据的OH_AVFormat信息。请参阅{@link OH_AVFormat}。需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要调用者通过调用接口OH_AVFormat_Destroy()释放。 |
| [OH_AVErrCode OH_VideoEncoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format)](#oh_videoencoder_setparameter) | - | 在编码器运行时设置编码器参数。注意，此接口只有在编码器启动后才能调用。 同时，不正确的参数设置可能会导致编码失败。 |
| [OH_AVErrCode OH_VideoEncoder_GetSurface(OH_AVCodec *codec, OHNativeWindow **window)](#oh_videoencoder_getsurface) | - | 从视频编码器获取输入surface，必须在调用OH_VideoEncoder_Prepare接口之前调用此接口。 |
| [OH_AVErrCode OH_VideoEncoder_FreeOutputData(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_freeoutputdata) | - | 将处理后的输出缓冲区返回给编码器。 |
| [OH_AVErrCode OH_VideoEncoder_NotifyEndOfStream(OH_AVCodec *codec)](#oh_videoencoder_notifyendofstream) | - | 通知视频编码器输入流已结束。建议使用此接口进行通知。该接口只在Surface模式下使用，Buffer模式通过OH_AVBuffer携带EOS信息，通知输入流的结束。 |
| [OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)](#oh_videoencoder_pushinputdata) | - | 将填入数据的输入缓冲区提交给视频编码器。 |
| [OH_AVErrCode OH_VideoEncoder_PushInputBuffer(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_pushinputbuffer) | - | Buffer模式下，将index对应的OH_AVBuffer送入编码器编码。 |
| [OH_AVErrCode OH_VideoEncoder_PushInputParameter(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_pushinputparameter) | - | Surface模式下，将index对应帧的编码参数送入编码器编码。 |
| [OH_AVErrCode OH_VideoEncoder_FreeOutputBuffer(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_freeoutputbuffer) | - | 将处理后的index对应的OH_AVBuffer返回给编码器。调用者使用完需要及时调用此接口释放输出缓存区，否则会阻塞编码流程。 |
| [OH_AVFormat *OH_VideoEncoder_GetInputDescription(OH_AVCodec *codec)](#oh_videoencoder_getinputdescription) | - | 编码器接收到的图像的描述信息，调用{@OH_VideoEncoder_Configure}后调用此接口，请参阅{@link OH_AVFormat}获取详细信息。需要注意的是，返回指针所指向的OH_AVFormat实例的生命周期需要由调用者通过调用OH_AVFormat_Destroy接口释放，请参阅{@link OH_AVFormat_Destory}。 |
| [OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec *codec, bool *isValid)](#oh_videoencoder_isvalid) | - | 检查当前编码实例是否有效。 |
| [OH_AVErrCode OH_VideoEncoder_QueryInputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)](#oh_videoencoder_queryinputbuffer) | - | 查询下一个可用输入缓冲区的索引。调用此接口后需要接着调用[OH_VideoEncoder_GetInputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputbuffer)接口获取缓冲区实例，并通过[OH_VideoEncoder_PushInputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputbuffer)接口传递给编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。 |
| [OH_AVBuffer *OH_VideoEncoder_GetInputBuffer(struct OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_getinputbuffer) | - | 获取可用输入缓冲区的实例。需要注意的是，此接口仅适用于同步模式。 |
| [OH_AVErrCode OH_VideoEncoder_QueryOutputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)](#oh_videoencoder_queryoutputbuffer) | - | 查询下一个可用输出缓冲区的索引。通过[OH_VideoEncoder_GetOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputbuffer)接口获取的缓冲区实例可以通过[OH_VideoEncoder_FreeOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_freeoutputbuffer)接口将处理后的输出缓冲区返回到编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。 |
| [OH_AVBuffer *OH_VideoEncoder_GetOutputBuffer(struct OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_getoutputbuffer) | - | 获取可用输出缓冲区的实例。需要注意的是，此接口仅适用于同步模式。 |

## 枚举类型说明

### OH_VideoEncodeBitrateMode

```
enum OH_VideoEncodeBitrateMode
```

**描述**

视频编码器的码率控制模式。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**废弃版本：** 14

**替代接口：** [OH_BitrateMode](capi-native-avcodec-base-h.md#oh_bitratemode)

| 枚举项 | 描述 |
| -- | -- |
| CBR = 0 |  |
| VBR = 1 |  |
| CQ = 2 |  |


## 函数说明

### OH_VideoEncoder_OnNeedInputParameter()

```
typedef void (*OH_VideoEncoder_OnNeedInputParameter)(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter,void *userData)
```

**描述**

配置随帧参数，当需要设置index对应帧的编码参数时，可以通过该接口设置。只在Surface模式生效。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
|  uint32_t index | 对应编码帧的index。 |
|  OH_AVFormat *parameter |  编码参数。 |
| void *userData | 调用者执行回调所依赖的数据。 |

### OH_VideoEncoder_CreateByMime()

```
OH_AVCodec *OH_VideoEncoder_CreateByMime(const char *mime)
```

**描述**

根据MIME类型创建视频编码器实例，推荐使用。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *mime | MIME类型描述字符串，请参阅{@link AVCODEC_MIME_TYPE}。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVCodec * | 成功则返回一个指向视频编码实例的指针。<br> 如果输入为不支持的编码器类型或内存不足时，则返回NULL。 |

### OH_VideoEncoder_CreateByName()

```
OH_AVCodec *OH_VideoEncoder_CreateByName(const char *name)
```

**描述**

根据视频编码器名称创建视频编码器实例。使用此接口的前提是知道编码器的确切名称，编码器的名称可以通过能力查询获取。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *name | 视频编码器名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVCodec * | 成功则返回一个指向视频编码实例的指针。<br> 如果输入是不支持编码器名称或者内存资源不足，则返回NULL。 |

### OH_VideoEncoder_Destroy()

```
OH_AVErrCode OH_VideoEncoder_Destroy(OH_AVCodec *codec)
```

**描述**

清理编码器内部资源，销毁编码器实例。不能重复销毁。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。 |

### OH_VideoEncoder_SetCallback()

```
OH_AVErrCode OH_VideoEncoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)
```

**描述**

设置OH_AVCodecCallback回调函数，让应用可以响应视频编码器生成的事件。在调用OH_VideoEncoder_Prepare接口之前，必须调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_VideoEncoder_RegisterCallback](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_registercallback)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OH_AVCodecAsyncCallback](capi-codecbase-oh-avcodecasynccallback.md) callback | 所有回调函数的集合，请参阅[OH_AVCodecAsyncCallback](capi-codecbase-oh-avcodecasynccallback.md)。 |
| void *userData | 调用者执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：本接口必须在OH_VideoEncoder_Prepare接口前调用，如果在其他状态时调用，则返回此错误码。 |

### OH_VideoEncoder_RegisterCallback()

```
OH_AVErrCode OH_VideoEncoder_RegisterCallback(OH_AVCodec *codec, OH_AVCodecCallback callback, void *userData)
```

**描述**

注册OH_AVCodecCallback回调函数，让应用可以响应视频编码器生成的事件。在调用OH_VideoEncoder_Prepare接口之前，必须调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OH_AVCodecCallback](capi-codecbase-oh-avcodeccallback.md) callback | 所有回调函数的集合，请参阅[OH_AVCodecCallback](capi-codecbase-oh-avcodeccallback.md)。 |
| void *userData | 调用者执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：本接口必须在OH_VideoEncoder_Prepare接口前调用，如果在其他状态时调用，则返回此错误码。 |

### OH_VideoEncoder_RegisterParameterCallback()

```
OH_AVErrCode OH_VideoEncoder_RegisterParameterCallback(OH_AVCodec *codec,OH_VideoEncoder_OnNeedInputParameter onInputParameter,void *userData)
```

**描述**

注册OH_AVCodecCallback输入参数回调函数，让应用可以响应视频编码器生成的事件。编码Surface模式，需要设置随帧参数时，须使用该接口。如果使用该接口，必须在[OH_VideoEncoder_Configure](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_configure)之前调用该接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OH_VideoEncoder_OnNeedInputParameter](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_onneedinputparameter) onInputParameter | 输入参数回调指针, 请参阅[OH_VideoEncoder_OnNeedInputParameter](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_onneedinputparameter)。 |
| void *userData | 调用者执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：本接口必须在OH_VideoEncoder_Prepare接口前调用，如果在其他状态时调用，则返回此错误码。 |

### OH_VideoEncoder_Configure()

```
OH_AVErrCode OH_VideoEncoder_Configure(OH_AVCodec *codec, OH_AVFormat *format)
```

**描述**

配置视频编码器的编码参数，通常需要配置要编码的视频轨的描述信息，如宽、高、像素格式等。必须在调用OH_VideoEncoder_Prepare接口之前，调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| OH_AVFormat *format | 指向OH_AVFormat的指针，用于给出要编码的视频轨的描述。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：1. 输入的codec指针为非编码器实例，或者为空指针；2. 输入format参数不支持。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：本接口必须在OH_VideoEncoder_Prepare接口前调用，如果在其他状态时调用，则返回此错误码。 |

### OH_VideoEncoder_Prepare()

```
OH_AVErrCode OH_VideoEncoder_Prepare(OH_AVCodec *codec)
```

**描述**

准备编码器的内部资源，在OH_VideoEncoder_Configure接口后调用。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。 |

### OH_VideoEncoder_Start()

```
OH_AVErrCode OH_VideoEncoder_Start(OH_AVCodec *codec)
```

**描述**

调用[OH_VideoEncoder_Prepare](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_prepare)接口成功后调用此接口启动编码器。成功启动后，编码器将开始报告注册的回调事件。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_Stop()

```
OH_AVErrCode OH_VideoEncoder_Stop(OH_AVCodec *codec)
```

**描述**

停止编码器，释放输入输出buffer。停止之后，可以通过调用OH_VideoEncoder_Start接口重新进入Running状态。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_Flush()

```
OH_AVErrCode OH_VideoEncoder_Flush(OH_AVCodec *codec)
```

**描述**

清除编码器中缓存的输入和输出数据及参数集如H264格式的PPS/SPS。调用此接口后，以前通过异步回调上报的所有缓冲区index都将失效，请确保不要访问这些index对应的缓冲区。该接口不能连续调用。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_Reset()

```
OH_AVErrCode OH_VideoEncoder_Reset(OH_AVCodec *codec)
```

**描述**

重置编码器，编码器回到初始化状态。如果要继续编码，需要再次调用OH_VideoEncoder_Configure接口配置编码器实例。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。 |

### OH_VideoEncoder_GetOutputDescription()

```
OH_AVFormat *OH_VideoEncoder_GetOutputDescription(OH_AVCodec *codec)
```

**描述**

获取编码器输出数据的OH_AVFormat信息。请参阅{@link OH_AVFormat}。需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要调用者通过调用接口OH_AVFormat_Destroy()释放。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVFormat * | 返回指向OH_AVFormat实例的指针。<br> 当输入的codec指针非编码实例，或者为空指针，则返回NULL。 |

### OH_VideoEncoder_SetParameter()

```
OH_AVErrCode OH_VideoEncoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format)
```

**描述**

在编码器运行时设置编码器参数。注意，此接口只有在编码器启动后才能调用。 同时，不正确的参数设置可能会导致编码失败。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| OH_AVFormat *format | 指向OH_AVFormat实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：1. 输入的codec指针为非编码器实例，或者为空指针；2. 输入format参数不支持。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_GetSurface()

```
OH_AVErrCode OH_VideoEncoder_GetSurface(OH_AVCodec *codec, OHNativeWindow **window)
```

**描述**

从视频编码器获取输入surface，必须在调用OH_VideoEncoder_Prepare接口之前调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OHNativeWindow](capi-codecbase-nativewindow.md) **window | 指向OHNativeWindow实例的指针, 请参阅[OHNativeWindow](capi-codecbase-nativewindow.md)。应用负责管理window的生命周期，结束时调用{@link OH_NativeWindow_DestroyNativeWindow}释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。 |

### OH_VideoEncoder_FreeOutputData()

```
OH_AVErrCode OH_VideoEncoder_FreeOutputData(OH_AVCodec *codec, uint32_t index)
```

**描述**

将处理后的输出缓冲区返回给编码器。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_VideoEncoder_FreeOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_freeoutputbuffer)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输出缓冲区对应的索引值。由[OH_AVCodecOnNewOutputData](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputdata)给出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_NotifyEndOfStream()

```
OH_AVErrCode OH_VideoEncoder_NotifyEndOfStream(OH_AVCodec *codec)
```

**描述**

通知视频编码器输入流已结束。建议使用此接口进行通知。该接口只在Surface模式下使用，Buffer模式通过OH_AVBuffer携带EOS信息，通知输入流的结束。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_PushInputData()

```
OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)
```

**描述**

将填入数据的输入缓冲区提交给视频编码器。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 10

**废弃版本：** 11

**替代接口：** [OH_VideoEncoder_PushInputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputbuffer)


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输入缓冲区对应的索引值。 |
| OH_AVCodecBufferAttr attr | 缓冲区中包含数据的描述信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_PushInputBuffer()

```
OH_AVErrCode OH_VideoEncoder_PushInputBuffer(OH_AVCodec *codec, uint32_t index)
```

**描述**

Buffer模式下，将index对应的OH_AVBuffer送入编码器编码。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输入缓冲区对应的索引值。由[OH_AVCodecOnNeedInputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconneedinputbuffer)给出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：1. 输入的codec指针为非编码器实例，或者为空指针；2. 输入format参数不支持。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_PushInputParameter()

```
OH_AVErrCode OH_VideoEncoder_PushInputParameter(OH_AVCodec *codec, uint32_t index)
```

**描述**

Surface模式下，将index对应帧的编码参数送入编码器编码。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输入参数缓冲区对应的索引值。由[OH_AVCodecOnNeedInputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconneedinputbuffer)给出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_FreeOutputBuffer()

```
OH_AVErrCode OH_VideoEncoder_FreeOutputBuffer(OH_AVCodec *codec, uint32_t index)
```

**描述**

将处理后的index对应的OH_AVBuffer返回给编码器。调用者使用完需要及时调用此接口释放输出缓存区，否则会阻塞编码流程。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 11


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输出缓冲区对应的索引值。由[OH_AVCodecOnNeedInputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconneedinputbuffer)给出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：<br>         1. 输入的 codec 指针为非编码器实例，或者为空指针；<br>         2. 输入format参数不支持；<br>         3. index非法或者连续给同一个index，该错误不影响后续编码流程。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：内部执行错误。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。 |

### OH_VideoEncoder_GetInputDescription()

```
OH_AVFormat *OH_VideoEncoder_GetInputDescription(OH_AVCodec *codec)
```

**描述**

编码器接收到的图像的描述信息，调用{@OH_VideoEncoder_Configure}后调用此接口，请参阅{@link OH_AVFormat}获取详细信息。需要注意的是，返回指针所指向的OH_AVFormat实例的生命周期需要由调用者通过调用OH_AVFormat_Destroy接口释放，请参阅{@link OH_AVFormat_Destory}。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVFormat * | 返回指向OH_AVFormat实例的指针。<br> 当codec指针非编码实例，或者为空指针，则返回NULL。 |

### OH_VideoEncoder_IsValid()

```
OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec *codec, bool *isValid)
```

**描述**

检查当前编码实例是否有效。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 10


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| bool *isValid | 输出参数，指向布尔类型的指针。指向布尔实例的指针，如果编码器实例有效，则为true，如果编码器实例无效，则为false。建议调用者将isValid初始化为false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果 {@link OH_AVErrCode}：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。 |

### OH_VideoEncoder_QueryInputBuffer()

```
OH_AVErrCode OH_VideoEncoder_QueryInputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)
```

**描述**

查询下一个可用输入缓冲区的索引。调用此接口后需要接着调用[OH_VideoEncoder_GetInputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getinputbuffer)接口获取缓冲区实例，并通过[OH_VideoEncoder_PushInputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_pushinputbuffer)接口传递给编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t *index | 输入buffer对应的索引值。 |
| int64_t timeoutUs | 超时时长，单位为微秒。负值：无限等待；0：立即退出；正值：等待指定时长后退出。AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码器实例已经销毁。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_SERVICE_DIED：编解码服务已终止。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。<br>         AV_ERR_OPERATE_NOT_PERMIT：禁止异步模式下使用。<br>         AV_ERR_TRY_AGAIN_LATER：查询失败，建议等待短暂间隔后重试。 |

### OH_VideoEncoder_GetInputBuffer()

```
OH_AVBuffer *OH_VideoEncoder_GetInputBuffer(struct OH_AVCodec *codec, uint32_t index)
```

**描述**

获取可用输入缓冲区的实例。需要注意的是，此接口仅适用于同步模式。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输入buffer对应的索引值，可通过[OH_VideoEncoder_GetOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputbuffer) 接口获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVBuffer * | 如果执行成功，则返回一个指向OH_AVBuffer实例的指针，否则返回NULL。 |

### OH_VideoEncoder_QueryOutputBuffer()

```
OH_AVErrCode OH_VideoEncoder_QueryOutputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)
```

**描述**

查询下一个可用输出缓冲区的索引。通过[OH_VideoEncoder_GetOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputbuffer)接口获取的缓冲区实例可以通过[OH_VideoEncoder_FreeOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_freeoutputbuffer)接口将处理后的输出缓冲区返回到编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t *index | 输出buffer对应的索引值。 |
| int64_t timeoutUs | 超时时长，单位为微秒。负值：无限等待；0：立即退出；正值：等待指定时长后退出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVErrCode | 返回接口结果：<br>         AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码器实例已经销毁。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_SERVICE_DIED：编解码服务已终止。<br>         AV_ERR_INVALID_STATE：编码器状态不支持调用本接口时调用。<br>         AV_ERR_OPERATE_NOT_PERMIT：禁止异步模式下使用。<br>         AV_ERR_STREAM_CHANGED：流格式已变更，可以通过调用[OH_VideoEncoder_GetOutputDescription](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_getoutputdescription)接口获取新的流信息。<br>         AV_ERR_TRY_AGAIN_LATER：查询失败，建议等待短暂间隔后重试。 |

### OH_VideoEncoder_GetOutputBuffer()

```
OH_AVBuffer *OH_VideoEncoder_GetOutputBuffer(struct OH_AVCodec *codec, uint32_t index)
```

**描述**

获取可用输出缓冲区的实例。需要注意的是，此接口仅适用于同步模式。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输出buffer对应的索引值，可通过[OH_VideoEncoder_QueryOutputBuffer](capi-native-avcodec-videoencoder-h.md#oh_videoencoder_queryoutputbuffer)接口获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| OH_AVBuffer * | 如果执行成功，则返回一个指向OH_AVBuffer实例的指针，否则返回NULL。 |


