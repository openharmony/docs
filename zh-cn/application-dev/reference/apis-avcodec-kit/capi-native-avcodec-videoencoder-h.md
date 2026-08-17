# native_avcodec_videoencoder.h
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @rchdlee-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->

## 概述

声明用于视频编码的接口。

**引用文件：** <multimedia/player_framework/native_avcodec_videoencoder.h>

**库：** libnative_media_venc.so

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**相关模块：** [VideoEncoder](capi-videoencoder.md)

**相关示例：** [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

接口在每个版本、每种模式和状态下的支持情况说明如下表所示。

### 接口状态矩阵

下方是不同状态下是否可以调用接口的情况概览，√表示可以调用，×表示不可调用。

| 接口 | Initialized | Configured | Prepared | Flushed | Running | EndOfStream | Error | Released |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| OH_VideoEncoder_CreateByMime<sup>9+</sup> | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_CreateByName<sup>9+</sup> | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_CreatePrimaryWithPreproc | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_CreateSecondaryFromPrimary | N/A | N/A | N/A | N/A | N/A | N/A | N/A | N/A |
| OH_VideoEncoder_RegisterCallback<sup>11+</sup> | √ | √ | × | × | × | × | × | × |
| OH_VideoEncoder_RegisterParameterCallback<sup>12+</sup> | √ | × | × | × | × | × | × | × |
| OH_VideoEncoder_OnNeedInputParameter<sup>12+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_Configure<sup>9+</sup> | √ | × | × | × | × | × | × | × |
| OH_VideoEncoder_Prepare<sup>9+</sup> | × | √ | × | × | × | × | × | × |
| OH_VideoEncoder_SetParameter<sup>9+</sup> | × | × | × | √ | √ | √ | × | × |
| OH_VideoEncoder_GetSurface<sup>9+</sup> | × | √ | × | × | × | × | × | × |
| OH_VideoEncoder_GetInputDescription<sup>10+</sup> | × | √ | √ | √ | √ | √ | × | × |
| OH_VideoEncoder_PushInputBuffer<sup>11+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_PushInputParameter<sup>12+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_NotifyEndOfStream<sup>9+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_GetOutputDescription<sup>9+</sup> | √ | √ | √ | √ | √ | √ | × | × |
| OH_VideoEncoder_FreeOutputBuffer<sup>11+</sup> | × | × | × | × | √ | √ | × | × |
| OH_VideoEncoder_Start<sup>9+</sup> | × | × | √ | √ | × | × | × | × |
| OH_VideoEncoder_Stop<sup>9+</sup> | × | × | × | √ | √ | √ | × | × |
| OH_VideoEncoder_Flush<sup>9+</sup> | × | × | × | × | √ | √ | × | × |
| OH_VideoEncoder_Reset<sup>9+</sup> | √ | √ | √ | √ | √ | √ | √ | × |
| OH_VideoEncoder_Destroy<sup>9+</sup> | √ | √ | √ | √ | √ | √ | √ | × |
| OH_VideoEncoder_QueryInputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_GetInputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_QueryOutputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |
| OH_VideoEncoder_GetOutputBuffer<sup>20+</sup> | × | × | × | × | √ | × | × | × |

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_VideoEncodeBitrateMode](#oh_videoencodebitratemode) | OH_VideoEncodeBitrateMode | 视频编码器的码率控制模式。(API14废弃) |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_VideoEncoder_OnNeedInputParameter)(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)](#oh_videoencoder_onneedinputparameter) | OH_VideoEncoder_OnNeedInputParameter | 配置随帧参数，当需要设置index对应帧的编码参数时，可以通过该接口设置。该接口仅在Surface模式下生效。 |
| [OH_AVCodec *OH_VideoEncoder_CreateByMime(const char *mime)](#oh_videoencoder_createbymime) | - | 根据MIME类型创建视频编码器实例，推荐使用。 |
| [OH_AVCodec *OH_VideoEncoder_CreateByName(const char *name)](#oh_videoencoder_createbyname) | - | 根据视频编码器名称创建视频编码器实例。使用此接口的前提是知道编码器的确切名称，编码器的名称可以通过能力查询获取。 |
| [OH_AVErrCode OH_VideoEncoder_CreatePrimaryWithPreproc(const char *mime, OH_AVCodec **codec)](#oh_videoencoder_createprimarywithpreproc) | - | 创建支持前处理的主视频编码器实例，可用于配置降采样、裁剪、丢帧等前处理参数，并可从该主编码器派生副编码器实现一入二出双路编码。 |
| [OH_AVErrCode OH_VideoEncoder_CreateSecondaryFromPrimary(OH_AVCodec *primary, OH_AVCodec **codec)](#oh_videoencoder_createsecondaryfromprimary) | - | 从主编码器创建副视频编码器实例，与主编码器共享输入源，可独立配置编码参数和前处理参数。 |
| [OH_AVErrCode OH_VideoEncoder_Destroy(OH_AVCodec *codec)](#oh_videoencoder_destroy) | - | 清理编码器内部资源，销毁编码器实例。不能重复销毁。 |
| [OH_AVErrCode OH_VideoEncoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)](#oh_videoencoder_setcallback) | - | 设置OH_AVCodecAsyncCallback回调函数，让应用可以响应视频编码器生成的事件。在调用OH_VideoEncoder_Prepare接口之前，必须调用此接口。(API11废弃) |
| [OH_AVErrCode OH_VideoEncoder_RegisterCallback(OH_AVCodec *codec, OH_AVCodecCallback callback, void *userData)](#oh_videoencoder_registercallback) | - | 注册OH_AVCodecCallback回调函数，让应用可以响应视频编码器生成的事件。在调用OH_VideoEncoder_Prepare接口之前，必须调用此接口。 |
| [OH_AVErrCode OH_VideoEncoder_RegisterParameterCallback(OH_AVCodec *codec, OH_VideoEncoder_OnNeedInputParameter onInputParameter, void *userData)](#oh_videoencoder_registerparametercallback) | - | 注册OH_VideoEncoder_OnNeedInputParameter输入参数回调函数，让应用可以响应视频编码器生成的事件。在Surface编码模式下，需要设置随帧参数时，须使用该接口。<br> 如果使用该接口，必须在[OH_VideoEncoder_Configure](#oh_videoencoder_configure)之前调用该接口。 |
| [OH_AVErrCode OH_VideoEncoder_Configure(OH_AVCodec *codec, OH_AVFormat *format)](#oh_videoencoder_configure) | - | 配置视频编码器的编码参数，通常需要配置输入视频帧的描述信息，如帧的宽、高、像素格式等。必须在调用OH_VideoEncoder_Prepare接口之前，调用此接口。 |
| [OH_AVErrCode OH_VideoEncoder_Prepare(OH_AVCodec *codec)](#oh_videoencoder_prepare) | - | 准备编码器的内部资源，在OH_VideoEncoder_Configure接口后调用。 |
| [OH_AVErrCode OH_VideoEncoder_Start(OH_AVCodec *codec)](#oh_videoencoder_start) | - | 调用[OH_VideoEncoder_Prepare](#oh_videoencoder_prepare)接口成功后调用此接口启动编码器。成功启动后，编码器将开始报告注册的回调事件。 |
| [OH_AVErrCode OH_VideoEncoder_Stop(OH_AVCodec *codec)](#oh_videoencoder_stop) | - | 停止编码器，释放输入输出buffer。停止之后，可以通过调用OH_VideoEncoder_Start接口重新进入Running状态。 |
| [OH_AVErrCode OH_VideoEncoder_Flush(OH_AVCodec *codec)](#oh_videoencoder_flush) | - | 清除编码器中缓存的输入和输出数据及参数集如H.264格式的PPS/SPS。<br>调用此接口后，以前通过异步回调上报的所有缓冲区index都将失效，请确保不要访问这些index对应的缓冲区。该接口不能连续调用。 |
| [OH_AVErrCode OH_VideoEncoder_Reset(OH_AVCodec *codec)](#oh_videoencoder_reset) | - | 重置编码器，编码器回到初始化状态。如果要继续编码，需要再次调用OH_VideoEncoder_Configure接口配置编码器实例。 |
| [OH_AVFormat *OH_VideoEncoder_GetOutputDescription(OH_AVCodec *codec)](#oh_videoencoder_getoutputdescription) | - | 获取编码器输出数据的OH_AVFormat信息。<br> 需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要开发者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。 |
| [OH_AVErrCode OH_VideoEncoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format)](#oh_videoencoder_setparameter) | - | 在编码器运行时设置编码器参数。<br> 注意，此接口只有在编码器启动后才能调用。同时，不正确的参数设置可能会导致编码失败。 |
| [OH_AVErrCode OH_VideoEncoder_GetSurface(OH_AVCodec *codec, OHNativeWindow **window)](#oh_videoencoder_getsurface) | - | 从视频编码器获取输入surface，必须在调用OH_VideoEncoder_Configure接口之后OH_VideoEncoder_Prepare接口之前调用此接口。 |
| [OH_AVErrCode OH_VideoEncoder_FreeOutputData(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_freeoutputdata) | - | 将处理后的输出缓冲区返回给编码器。(API11废弃) |
| [OH_AVErrCode OH_VideoEncoder_NotifyEndOfStream(OH_AVCodec *codec)](#oh_videoencoder_notifyendofstream) | - | 通知视频编码器输入流已结束。建议使用此接口进行通知。该接口只在Surface模式下使用，Buffer模式通过OH_AVBuffer携带EOS信息，通知输入流的结束。 |
| [OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)](#oh_videoencoder_pushinputdata) | - | 将填入数据的输入缓冲区提交给视频编码器。(API11废弃) |
| [OH_AVErrCode OH_VideoEncoder_PushInputBuffer(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_pushinputbuffer) | - | Buffer模式下，将index对应的OH_AVBuffer送入编码器编码。 |
| [OH_AVErrCode OH_VideoEncoder_PushInputParameter(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_pushinputparameter) | - | Surface模式下，将index对应帧的编码参数送入编码器编码。 |
| [OH_AVErrCode OH_VideoEncoder_FreeOutputBuffer(OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_freeoutputbuffer) | - | 将处理后的index对应的OH_AVBuffer退回给编码器。开发者使用完需要及时调用此接口释放输出缓冲区，否则会阻塞编码流程。 |
| [OH_AVFormat *OH_VideoEncoder_GetInputDescription(OH_AVCodec *codec)](#oh_videoencoder_getinputdescription) | - | 编码器接收到的图像的描述信息。调用[OH_VideoEncoder_Configure](#oh_videoencoder_configure)后调用此接口。<br> 需要注意的是，返回指针所指向的OH_AVFormat实例的生命周期需要由开发者通过调用[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)接口释放。 |
| [OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec *codec, bool *isValid)](#oh_videoencoder_isvalid) | - | 在编码器实例存在的情况下，检查当前编码器服务是否有效。 |
| [OH_AVErrCode OH_VideoEncoder_QueryInputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)](#oh_videoencoder_queryinputbuffer) | - | 查询下一个可用输入缓冲区的索引。<br> 调用此接口后需要接着调用[OH_VideoEncoder_GetInputBuffer](#oh_videoencoder_getinputbuffer)接口获取缓冲区实例，并通过[OH_VideoEncoder_PushInputBuffer](#oh_videoencoder_pushinputbuffer)接口传递给编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。 |
| [OH_AVBuffer *OH_VideoEncoder_GetInputBuffer(struct OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_getinputbuffer) | - | 获取可用输入缓冲区的实例。<br> 需要注意的是，此接口仅适用于同步模式。 |
| [OH_AVErrCode OH_VideoEncoder_QueryOutputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)](#oh_videoencoder_queryoutputbuffer) | - | 查询下一个可用输出缓冲区的索引。通过[OH_VideoEncoder_GetOutputBuffer](#oh_videoencoder_getoutputbuffer)接口获取的缓冲区实例可以通过[OH_VideoEncoder_FreeOutputBuffer](#oh_videoencoder_freeoutputbuffer)接口将处理后的输出缓冲区返回到编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。 |
| [OH_AVBuffer *OH_VideoEncoder_GetOutputBuffer(struct OH_AVCodec *codec, uint32_t index)](#oh_videoencoder_getoutputbuffer) | - | 获取可用输出缓冲区的实例。<br> 需要注意的是，此接口仅适用于同步模式。 |

## 枚举类型说明

### OH_VideoEncodeBitrateMode

```c
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
| CBR = 0 | 恒定码率模式。<br>**替代接口：** [BITRATE_MODE_CBR](capi-native-avcodec-base-h.md#oh_bitratemode) |
| VBR = 1 | 可变码率模式。<br>**替代接口：** [BITRATE_MODE_VBR](capi-native-avcodec-base-h.md#oh_bitratemode) |
| CQ = 2 | 恒定QP模式。<br>**替代接口：** [BITRATE_MODE_CQ](capi-native-avcodec-base-h.md#oh_bitratemode) |


## 函数说明

### OH_VideoEncoder_OnNeedInputParameter()

```c
typedef void (*OH_VideoEncoder_OnNeedInputParameter)(OH_AVCodec *codec, uint32_t index, OH_AVFormat *parameter, void *userData)
```

**描述**

配置随帧参数，当需要设置index对应帧的编码参数时，可以通过该接口设置。只在Surface模式生效。<br> 该接口只能在Surface模式下使用，使用前需要调用OH_VideoEncoder_RegisterParameterCallback接口注册。<br> 在Buffer模式下，OH_AVBuffer可以直接携带帧的编码参数，当前可以支持的随帧参数有帧级QPMin/QPMax，指定LTR设置参考帧。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
|  uint32_t index | 对应编码帧的index。 |
|  [OH_AVFormat](capi-core-oh-avformat.md) *parameter |  编码参数。 |
|  void *userData | 开发者执行回调所依赖的数据。 |

### OH_VideoEncoder_CreateByMime()

```c
OH_AVCodec *OH_VideoEncoder_CreateByMime(const char *mime)
```

**描述**

根据MIME类型创建视频编码器实例，推荐使用。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *mime | MIME类型描述字符串，请参阅AVCODEC_MIME_TYPE类型[变量](capi-native-avcodec-base-h.md#变量)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) * | 成功则返回一个指向视频编码实例的指针。<br> 如果输入为不支持的编码器类型或内存不足时，则返回NULL。 |

### OH_VideoEncoder_CreateByName()

```c
OH_AVCodec *OH_VideoEncoder_CreateByName(const char *name)
```

**描述**

根据视频编码器名称创建视频编码器实例。使用此接口的前提是知道编码器的确切名称，编码器的名称可以通过能力查询获取。<br>详情请参见：[获取支持的编解码能力](../../media/avcodec/obtain-supported-codecs.md#创建指定名称的编解码器)。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *name | 视频编码器名称。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) * | 成功则返回一个指向视频编码实例的指针。<br> 如果输入的是不支持的编码器名称或者内存资源不足，则返回NULL。 |

### OH_VideoEncoder_CreatePrimaryWithPreproc()

```c
OH_AVErrCode OH_VideoEncoder_CreatePrimaryWithPreproc(const char *mime, OH_AVCodec **codec)
```

**描述**

创建支持前处理的主视频编码器实例。该编码器支持以下能力：
1. 前处理功能（降采样、裁剪、丢帧）。
2. 从该主编码器创建副编码器实现一入二出双路编码。

通过该接口创建的编码器仅支持Surface模式，不支持Buffer模式和同步模式。创建成功后需通过[OH_VideoEncoder_Destroy](#oh_videoencoder_destroy)销毁。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char *mime | MIME类型字符串，不可为NULL。必须是支持的类型。 |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) **codec | 双指针，用于接收创建的编码器实例，不可为NULL。创建成功后需通过[OH_VideoEncoder_Destroy](#oh_videoencoder_destroy)销毁。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>AV_ERR_INVALID_VAL：mime为NULL / codec为NULL / MIME类型不支持。<br>AV_ERR_NO_MEMORY：内存分配失败。 |

### OH_VideoEncoder_CreateSecondaryFromPrimary()

```c
OH_AVErrCode OH_VideoEncoder_CreateSecondaryFromPrimary(OH_AVCodec *primary, OH_AVCodec **codec)
```

**描述**

从主编码器创建副视频编码器实例。副编码器具有以下特性：
1. 与主编码器共享输入源。
2. 可独立配置编码参数。
3. 可使用不同的前处理参数。
4. 可独立启动/停止（不依赖主编码器的启停状态）。
5. 生命周期必须短于主编码器。
6. 一个主编码器同时只能拥有一个副编码器。

必须在主编码器创建成功之后才能创建。创建成功后需通过[OH_VideoEncoder_Destroy](#oh_videoencoder_destroy)销毁。销毁顺序建议先Destroy Secondary再Destroy Primary。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 26.0.0

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *primary | 主编码器句柄，必须由[OH_VideoEncoder_CreatePrimaryWithPreproc](#oh_videoencoder_createprimarywithpreproc)创建，不可为NULL。 |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) **codec | 双指针，用于接收创建的副编码器实例，不可为NULL。创建成功后需通过[OH_VideoEncoder_Destroy](#oh_videoencoder_destroy)销毁。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>AV_ERR_INVALID_VAL：primary为NULL / codec为NULL / primary不是有效的主编码器。<br>AV_ERR_OPERATE_NOT_PERMIT：主编码器已存在关联的副编码器。<br>AV_ERR_NO_MEMORY：内存分配失败。 |

### OH_VideoEncoder_Destroy()

```c
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
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。 |

### OH_VideoEncoder_SetCallback()

```c
OH_AVErrCode OH_VideoEncoder_SetCallback(OH_AVCodec *codec, OH_AVCodecAsyncCallback callback, void *userData)
```

**描述**

设置OH_AVCodecAsyncCallback回调函数，让应用可以响应视频编码器生成的事件。在调用OH_VideoEncoder_Prepare接口之前，必须调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_VideoEncoder_RegisterCallback](#oh_videoencoder_registercallback)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OH_AVCodecAsyncCallback](capi-codecbase-oh-avcodecasynccallback.md) callback | 所有回调函数的集合。 |
| void *userData | 开发者执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。 |

### OH_VideoEncoder_RegisterCallback()

```c
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
| [OH_AVCodecCallback](capi-codecbase-oh-avcodeccallback.md) callback | 所有回调函数的集合。 |
| void *userData | 开发者执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。 |

### OH_VideoEncoder_RegisterParameterCallback()

```c
OH_AVErrCode OH_VideoEncoder_RegisterParameterCallback(OH_AVCodec *codec, OH_VideoEncoder_OnNeedInputParameter onInputParameter, void *userData)
```

**描述**

注册OH_VideoEncoder_OnNeedInputParameter输入参数回调函数，让应用可以响应视频编码器生成的事件。在Surface编码模式下，需要设置随帧参数时，须使用该接口。<br> 如果使用该接口，必须在[OH_VideoEncoder_Configure](#oh_videoencoder_configure)之前调用该接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OH_VideoEncoder_OnNeedInputParameter](#oh_videoencoder_onneedinputparameter) onInputParameter | 输入参数回调指针。 |
| void *userData | 开发者执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：本接口必须在OH_VideoEncoder_Configure接口前调用，如果在其他状态时调用，则返回此错误码。 |

### OH_VideoEncoder_Configure()

```c
OH_AVErrCode OH_VideoEncoder_Configure(OH_AVCodec *codec, OH_AVFormat *format)
```

**描述**

配置视频编码器的编码参数，通常需要配置输入视频帧的描述信息，如帧的宽、高、像素格式等。必须在调用OH_VideoEncoder_Prepare接口之前，调用此接口。<br> 该接口对配置参数进行合法性校验，部分非法参数不会强校验，使用默认值或直接丢弃。部分非法参数会强校验，具体规则如下：<br> 以下参数的配置范围可通过[能力查询](../../media/avcodec/obtain-supported-codecs.md)获取，OH_MD_KEY_I_FRAME_INTERVAL暂不支持能力查询。<br> 设置OH_MD_KEY_VIDEO_ENCODER_ENABLE_TEMPORAL_SCALABILITY、OH_MD_KEY_VIDEO_ENCODER_LTR_FRAME_COUNT参数时，如果当前平台不支持这些功能，该接口不会报错，而是继续按照正常编码流程执行。

参数校验：

| Key     | 配置正常范围的值 | 配置超出范围的值 | 不配置该参数 |
| ------- | -------- | -------- | ------ |
| OH_MD_KEY_WIDTH  | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_INVALID_VAL |
| OH_MD_KEY_HEIGHT | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_INVALID_VAL |
| OH_MD_KEY_PIXEL_FORMAT 请参阅[OH_AVPixelFormat](capi-native-avformat-h.md#oh_avpixelformat) | AV_ERR_OK | AV_ERR_UNSUPPORT | AV_ERR_OK    |
| OH_MD_KEY_FRAME_RATE | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_OK |
| OH_MD_KEY_PROFILE 请参阅[OH_MD_KEY_PROFILE](capi-native-avcodec-base-h.md#变量)    | AV_ERR_OK | AV_ERR_INVALID_VAL | AV_ERR_OK | 
| OH_MD_KEY_I_FRAME_INTERVAL | AV_ERR_OK |  \\       | AV_ERR_OK | 

| OH_MD_KEY_<br>BITRATE | OH_MD_KEY_<br>QUALITY | OH_MD_KEY_<br>VIDEO_ENCODER_BITRATE_MODE | 返回值 | 说明     |
| :-------- | :---------| :---------- | ---- | ---------- |
| \\      | \\      | \\           |  AV_ERR_OK    | 使用编码器默认值 |
| 超出范围    | 超出范围    | 不支持的模式       | AV_ERR_INVALID_VAL   | 异常值均报错   |
| 正常值     | 正常值     | \\           | AV_ERR_INVALID_VAL   | Bitrate 与 Quality 冲突   |
| 正常值     | \\      | \\           | AV_ERR_OK     | 使能默认码控模式 |
| 正常值     | \\      | BITRATE_MODE_VBR、BITRATE_MODE_CBR      | AV_ERR_OK     |    -     |
| 正常值     | \\      | BITRATE_MODE_CQ           | AV_ERR_INVALID_VAL   | Bitrate 与 CQ 模式冲突      |
| \\      | 正常值     | \\           | AV_ERR_OK     | 使能 CQ 模式 |
| \\      | 正常值     | BITRATE_MODE_CQ           | AV_ERR_OK     |   -      |
| \\      | 正常值     | BITRATE_MODE_VBR、BITRATE_MODE_CBR      | AV_ERR_INVALID_VAL   | Quality 与 VBR、CBR 模式冲突 |
| \\      | \\      | BITRATE_MODE_VBR、BITRATE_MODE_CBR      | AV_ERR_OK     | 使用编码器默认码率|
| \\      | \\      | BITRATE_MODE_CQ           | AV_ERR_OK    | 使用默认quality  |

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OH_AVFormat](capi-core-oh-avformat.md) *format | 指向OH_AVFormat的指针，用于给出要编码的视频轨的描述。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：1. 输入的codec指针为非编码器实例，或者为空指针；2. 输入format参数不支持。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：本接口必须在OH_VideoEncoder_Prepare接口前调用，如果在其他状态时调用，则返回此错误码。<br>   AV_ERR_UNSUPPORT：不支持的像素格式。 |

### OH_VideoEncoder_Prepare()

```c
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
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_Start()

```c
OH_AVErrCode OH_VideoEncoder_Start(OH_AVCodec *codec)
```

**描述**

调用[OH_VideoEncoder_Prepare](#oh_videoencoder_prepare)接口成功后调用此接口启动编码器。成功启动后，编码器将开始报告注册的回调事件。<br> Surface模式下，在surface中有正确的输入后，每完成一帧编码会触发OnNewOutputBuffer。<br> Buffer模式下，编码器会立即触发输入回调，开发者每完成一次输入，编码器执行编码，每完成一帧编码会触发OnNewOutputBuffer。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_Stop()

```c
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
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_Flush()

```c
OH_AVErrCode OH_VideoEncoder_Flush(OH_AVCodec *codec)
```

**描述**

清除编码器中缓存的输入和输出数据及参数集如H.264格式的PPS/SPS。<br> 调用此接口后，以前通过异步回调上报的所有缓冲区index都将失效，请确保不要访问这些index对应的缓冲区。该接口不能连续调用。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_Reset()

```c
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
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。 |

### OH_VideoEncoder_GetOutputDescription()

```c
OH_AVFormat *OH_VideoEncoder_GetOutputDescription(OH_AVCodec *codec)
```

**描述**

获取编码器输出数据的OH_AVFormat信息。<br> 需要注意的是，返回值指向的OH_AVFormat实例的生命周期需要开发者通过调用接口[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)释放。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | 返回指向OH_AVFormat实例的指针。<br> 当输入的codec指针非编码实例，或者为空指针，则返回NULL。 |

### OH_VideoEncoder_SetParameter()

```c
OH_AVErrCode OH_VideoEncoder_SetParameter(OH_AVCodec *codec, OH_AVFormat *format)
```

**描述**

在编码器运行时设置编码器参数。<br> 注意，此接口只有在编码器启动后才能调用。同时，不正确的参数设置可能会导致编码失败。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OH_AVFormat](capi-core-oh-avformat.md) *format | 指向OH_AVFormat实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：1. 输入的codec指针为非编码器实例，或者为空指针；2. 输入format参数不支持。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_GetSurface()

```c
OH_AVErrCode OH_VideoEncoder_GetSurface(OH_AVCodec *codec, OHNativeWindow **window)
```

**描述**

从视频编码器获取输入surface，必须在调用OH_VideoEncoder_Configure接口之后OH_VideoEncoder_Prepare接口之前调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| [OHNativeWindow](../apis-arkgraphics2d/capi-nativewindow-nativewindow.md) **window | 指向OHNativeWindow实例的指针。应用负责管理window的生命周期，结束时调用[OH_NativeWindow_DestroyNativeWindow](../apis-arkgraphics2d/capi-external-window-h.md#oh_nativewindow_destroynativewindow)释放。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。 |

### OH_VideoEncoder_FreeOutputData()

```c
OH_AVErrCode OH_VideoEncoder_FreeOutputData(OH_AVCodec *codec, uint32_t index)
```

**描述**

将处理后的输出缓冲区返回给编码器。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 9

**废弃版本：** 11

**替代接口：** [OH_VideoEncoder_FreeOutputBuffer](#oh_videoencoder_freeoutputbuffer)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输出缓冲区对应的索引值。由[OH_AVCodecOnNewOutputData](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputdata)给出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_NotifyEndOfStream()

```c
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
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_PushInputData()

```c
OH_AVErrCode OH_VideoEncoder_PushInputData(OH_AVCodec *codec, uint32_t index, OH_AVCodecBufferAttr attr)
```

**描述**

将填入数据的输入缓冲区提交给视频编码器。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 10

**废弃版本：** 11

**替代接口：** [OH_VideoEncoder_PushInputBuffer](#oh_videoencoder_pushinputbuffer)

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输入缓冲区对应的索引值。由[OH_AVCodecOnNeedInputData](capi-native-avcodec-base-h.md#oh_avcodeconneedinputdata)给出。 |
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) attr | 缓冲区中包含数据的描述信息。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：<br>1. 输入的codec指针为非编码器实例，或者为空指针；<br>2. index非法，该错误不影响后续编码流程。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_PushInputBuffer()

```c
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
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：<br>1. 输入的codec指针为非编码器实例，或者为空指针；<br>2. index非法，该错误不影响后续编码流程。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_PushInputParameter()

```c
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
| uint32_t index | 输入参数缓冲区对应的索引值。由[OH_VideoEncoder_OnNeedInputParameter](#oh_videoencoder_onneedinputparameter)给出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：<br>1. 输入的codec指针为非编码器实例，或者为空指针；<br>2. index非法，该错误不影响后续编码流程。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_FreeOutputBuffer()

```c
OH_AVErrCode OH_VideoEncoder_FreeOutputBuffer(OH_AVCodec *codec, uint32_t index)
```

**描述**

将处理后的index对应的OH_AVBuffer退回给编码器。开发者使用完需要及时调用此接口释放输出缓冲区，否则会阻塞编码流程。<br>详情请参见：[视频编码](../../media/avcodec/video-encoding.md) “Surface模式的步骤-13或Buffer模式步骤-11”。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 11

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输出缓冲区对应的索引值。由[OH_AVCodecOnNewOutputBuffer](capi-native-avcodec-base-h.md#oh_avcodeconnewoutputbuffer)给出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码实例内部异常，如内部出现异常空指针。<br>         AV_ERR_INVALID_VAL：<br>1. 输入的codec指针为非编码器实例，或者为空指针；<br>2. index非法，该错误不影响后续编码流程。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_OPERATE_NOT_PERMIT：操作不允许。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。 |

### OH_VideoEncoder_GetInputDescription()

```c
OH_AVFormat *OH_VideoEncoder_GetInputDescription(OH_AVCodec *codec)
```

**描述**

编码器接收到的图像的描述信息。调用[OH_VideoEncoder_Configure](#oh_videoencoder_configure)后调用此接口。<br> 需要注意的是，返回指针所指向的OH_AVFormat实例的生命周期需要由开发者通过调用[OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy)接口释放。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | 返回指向OH_AVFormat实例的指针。<br> 当codec指针非编码实例，或者为空指针，则返回NULL。 |

### OH_VideoEncoder_IsValid()

```c
OH_AVErrCode OH_VideoEncoder_IsValid(OH_AVCodec *codec, bool *isValid)
```

**描述**

在编码器实例存在的情况下，检查当前编码器服务是否有效。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 10

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| bool *isValid | 输出参数，指向布尔类型的指针。只有当接口返回AV_ERR_OK时，该值表示编码器服务的有效性（true为有效，false为无效）。建议开发者将isValid初始化为false。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。 |

### OH_VideoEncoder_QueryInputBuffer()

```c
OH_AVErrCode OH_VideoEncoder_QueryInputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)
```

**描述**

查询下一个可用输入缓冲区的索引。<br> 调用此接口后需要接着调用[OH_VideoEncoder_GetInputBuffer](#oh_videoencoder_getinputbuffer)接口获取缓冲区实例，并通过[OH_VideoEncoder_PushInputBuffer](#oh_videoencoder_pushinputbuffer)接口传递给编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t *index | 输入buffer对应的索引值。 |
| int64_t timeoutUs | 超时时长，单位为微秒。负值：无限等待；0：立即退出；正值：等待指定时长后退出。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码器实例已经销毁。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。<br>         AV_ERR_OPERATE_NOT_PERMIT：禁止异步模式下使用。<br>         AV_ERR_TRY_AGAIN_LATER：查询失败，建议等待短暂间隔后重试。 |

### OH_VideoEncoder_GetInputBuffer()

```c
OH_AVBuffer *OH_VideoEncoder_GetInputBuffer(struct OH_AVCodec *codec, uint32_t index)
```

**描述**

获取可用输入缓冲区的实例。<br> 需要注意的是，此接口仅适用于同步模式。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输入buffer对应的索引值，可通过[OH_VideoEncoder_QueryInputBuffer](#oh_videoencoder_queryinputbuffer) 接口获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) * | 如果执行成功，则返回一个指向OH_AVBuffer实例的指针，否则返回NULL。 |

### OH_VideoEncoder_QueryOutputBuffer()

```c
OH_AVErrCode OH_VideoEncoder_QueryOutputBuffer(struct OH_AVCodec *codec, uint32_t *index, int64_t timeoutUs)
```

**描述**

查询下一个可用输出缓冲区的索引。通过[OH_VideoEncoder_GetOutputBuffer](#oh_videoencoder_getoutputbuffer)接口获取的缓冲区实例可以通过[OH_VideoEncoder_FreeOutputBuffer](#oh_videoencoder_freeoutputbuffer)接口将处理后的输出缓冲区返回到编码器。<br> 需要注意的是，上述操作仅在同步模式下支持。

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
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br>         AV_ERR_NO_MEMORY：输入的编码器实例已经销毁。<br>         AV_ERR_INVALID_VAL：输入的codec指针为非编码器实例，或者为空指针。<br>         AV_ERR_UNKNOWN：未知错误。<br>         AV_ERR_INVALID_STATE：当前编码器状态不支持调用本接口。<br>         AV_ERR_OPERATE_NOT_PERMIT：禁止异步模式下使用。<br>         AV_ERR_STREAM_CHANGED：流格式已变更，可以通过调用[OH_VideoEncoder_GetOutputDescription](#oh_videoencoder_getoutputdescription)接口获取新的流信息。<br>         AV_ERR_TRY_AGAIN_LATER：查询失败，建议等待短暂间隔后重试。 |

### OH_VideoEncoder_GetOutputBuffer()

```c
OH_AVBuffer *OH_VideoEncoder_GetOutputBuffer(struct OH_AVCodec *codec, uint32_t index)
```

**描述**

获取可用输出缓冲区的实例。<br> 需要注意的是，此接口仅适用于同步模式。

**系统能力：** SystemCapability.Multimedia.Media.VideoEncoder

**起始版本：** 20

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [struct OH_AVCodec](capi-codecbase-oh-avcodec.md) *codec | 指向视频编码实例的指针。 |
| uint32_t index | 输出buffer对应的索引值，可通过[OH_VideoEncoder_QueryOutputBuffer](#oh_videoencoder_queryoutputbuffer)接口获取。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) * | 如果执行成功，则返回一个指向可用输出缓冲区OH_AVBuffer实例的指针，否则返回NULL。 |


