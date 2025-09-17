# lowpower_video_sink.h

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @Saber_e-->
<!--Designer: @yangde_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## 概述

定义LowPowerVideoSink接口。使用LowPowerVideoSink提供的Native API进行视频通路的低功耗播放。

**引用文件：** <multimedia/player_framework/lowpower_video_sink.h>

**库：** liblowpower_avsink.so

**系统能力：** SystemCapability.Multimedia.Media.LowPowerAVSink

**起始版本：** 20

**相关模块：** [LowPowerVideoSink](capi-lowpowervideosink.md)

## 汇总

### 函数

| 名称 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink* OH_LowPowerVideoSink_CreateByMime(const char* mime)](#oh_lowpowervideosink_createbymime) | 创建低功耗LowPowerVideoSink。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Configure(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)](#oh_lowpowervideosink_configure) | 配置LowPowerVideoSink，需要在[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)前完成。 |
| [OH_AVErrCode OH_LowPowerVideoSink_SetParameter(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)](#oh_lowpowervideosink_setparameter) | 为LowPowerVideoSink设置参数，支持[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)后动态设置。 |
| [OH_AVErrCode OH_LowPowerVideoSink_GetParameter(OH_LowPowerVideoSink* sink, OH_AVFormat* format)](#oh_lowpowervideosink_getparameter) | 获取LowPowerVideoSink的相关参数。 |
| [OH_AVErrCode OH_LowPowerVideoSink_SetVideoSurface(OH_LowPowerVideoSink* sink, const OHNativeWindow* surface)](#oh_lowpowervideosink_setvideosurface) | 为LowPowerVideoSink设置渲染画面窗口。 需要在[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)前完成。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Prepare(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_prepare) | 开始LowPowerVideoSink准备，需要在[OH_LowPowerVideoSink_SetSyncAudioSink](#oh_lowpowervideosink_setsyncaudiosink)之后调用。 |
| [OH_AVErrCode OH_LowPowerVideoSink_StartDecoder(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_startdecoder) | 开始LowPowerVideoSink解码，在[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)后或非播放中[OH_LowPowerVideoSink_SetTargetStartFrame](#oh_lowpowervideosink_settargetstartframe)后调用。<br> 启动成功后，LowPowerVideoSink将开始上报[OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded)事件。 |
| [OH_AVErrCode OH_LowPowerVideoSink_RenderFirstFrame(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_renderfirstframe) | 渲染LowPowerVideoSink解码出的第一帧，在[OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder)之后调用。 |
| [OH_AVErrCode OH_LowPowerVideoSink_StartRenderer(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_startrenderer) | 开始LowPowerVideoSink渲染，在[OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder)之后调用。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Pause(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_pause) | 暂停LowPowerVideoSink，在[OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer)或[OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume)后调用。<br> 暂停成功后，LowPowerVideoSink将暂停[OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded)事件的上报。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Resume(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_resume) | 恢复LowPowerVideoSink，在[OH_LowPowerVideoSink_Pause](#oh_lowpowervideosink_pause)后调用。<br> 恢复成功后，LowPowerVideoSink将恢复[OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded)事件的上报。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Flush(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_flush) | 清除LowPowerVideoSink中所有解码器和渲染缓存的输入输出数据。<br> 此接口不建议在[OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer)或[OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume)之后调用。<br> 需要注意的是，如果编解码器之前已输入数据，则需要重新输入编解码器数据。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Stop(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_stop) | 停止LowPowerVideoSink。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Reset(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_reset) | 重置LowPowerVideoSink。<br> 如果要重新使用该实例，需要调用[OH_LowPowerVideoSink_Configure](#oh_lowpowervideosink_configure)完成配置。 |
| [OH_AVErrCode OH_LowPowerVideoSink_Destroy(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_destroy) | 清理解码器内部资源，销毁LowPowerVideoSink实例。不能重复销毁。 |
| [OH_AVErrCode OH_LowPowerVideoSink_SetSyncAudioSink(OH_LowPowerVideoSink* videoSink, OH_LowPowerAudioSink* audioSink)](#oh_lowpowervideosink_setsyncaudiosink) | LowPowerVideoSink设置用于音画同步的AudioStreamer。 |
| [OH_AVErrCode OH_LowPowerVideoSink_SetTargetStartFrame(OH_LowPowerVideoSink* sink, const int64_t framePts, OH_LowPowerVideoSink_OnTargetArrived onTargetArrived, const int64_t timeoutMs,void* userData)](#oh_lowpowervideosink_settargetstartframe) | 为LowPowerVideoSink设置目标渲染帧。 |
| [OH_AVErrCode OH_LowPowerVideoSink_SetPlaybackSpeed(OH_LowPowerVideoSink* sink, const float speed)](#oh_lowpowervideosink_setplaybackspeed) | 为LowPowerVideoSink设置播放倍速。 |
| [OH_AVErrCode OH_LowPowerVideoSink_ReturnSamples(OH_LowPowerVideoSink* sink, OH_AVSamplesBuffer* samples)](#oh_lowpowervideosink_returnsamples) | 给LowPowerVideoSink输入buffer。 |
| [OH_AVErrCode OH_LowPowerVideoSink_RegisterCallback(OH_LowPowerVideoSink* sink, OH_LowPowerVideoSinkCallback* callback)](#oh_lowpowervideosink_registercallback) | 为LowPowerVideoSink注册回调。 |
| [OH_LowPowerVideoSinkCallback* OH_LowPowerVideoSinkCallback_Create(void)](#oh_lowpowervideosinkcallback_create) | 创建OH_LowPowerVideoSinkCallback。 |
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_Destroy(OH_LowPowerVideoSinkCallback* callback)](#oh_lowpowervideosinkcallback_destroy) | 销毁OH_LowPowerVideoSinkCallback对象。 |
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetDataNeededListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnDataNeeded onDataNeeded, void* userData)](#oh_lowpowervideosinkcallback_setdataneededlistener) | 为LowPowerVideoSinkCallback设置需要数据监听。 |
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetErrorListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnError onError, void* userData)](#oh_lowpowervideosinkcallback_seterrorlistener) | 为LowPowerVideoSinkCallback回调设置错误监听。 |
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetRenderStartListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnRenderStarted onRenderStarted, void* userData)](#oh_lowpowervideosinkcallback_setrenderstartlistener) | 为LowPowerVideoSinkCallback回调设置开始渲染监听。 |
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetStreamChangedListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnStreamChanged onStreamChanged, void* userData)](#oh_lowpowervideosinkcallback_setstreamchangedlistener) | 为LowPowerVideoSinkCallback回调设置流切换监听。 |
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetFirstFrameDecodedListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnFirstFrameDecoded onFirstFrameDecoded, void* userData)](#oh_lowpowervideosinkcallback_setfirstframedecodedlistener) | 为LowPowerVideoSinkCallback回调设置首帧准备完成监听。 |
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetEosListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnEos onEos, void* userData)](#oh_lowpowervideosinkcallback_seteoslistener) | 为LowPowerVideoSinkCallback回调设置播放结束监听。 |

## 函数说明

### OH_LowPowerVideoSink_CreateByMime()

```
OH_LowPowerVideoSink* OH_LowPowerVideoSink_CreateByMime(const char* mime)
```

**描述**

创建低功耗LowPowerVideoSink。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| const char* mime | 视频解码器的MIME类型，取值范围请参考[AVCODEC_MIME_TYPE](../apis-avcodec-kit/_codec_base.md#变量)。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* | 如果创建成功返回指向OH_LowPowerVideoSink实例的指针，否则返回空指针。 |

### OH_LowPowerVideoSink_Configure()

```
OH_AVErrCode OH_LowPowerVideoSink_Configure(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)
```

**描述**

配置LowPowerVideoSink，需要在[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)前完成。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| const [OH_AVFormat](../apis-avcodec-kit/capi-core-oh-avformat.md)* format | 指向OH_AVFormat的指针，用于配置LowPowerVideoSink的参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_UNSUPPORT：不支持的格式。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_SetParameter()

```
OH_AVErrCode OH_LowPowerVideoSink_SetParameter(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)
```

**描述**

为LowPowerVideoSink设置参数，支持[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)后动态设置。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| const [OH_AVFormat](../apis-avcodec-kit/capi-core-oh-avformat.md)* format | 指向OH_AVFormat的指针，用于配置LowPowerVideoSink的参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_UNSUPPORT：不支持的格式。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_GetParameter()

```
OH_AVErrCode OH_LowPowerVideoSink_GetParameter(OH_LowPowerVideoSink* sink, OH_AVFormat* format)
```

**描述**

获取LowPowerVideoSink的相关参数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| [OH_AVFormat](../apis-avcodec-kit/capi-core-oh-avformat.md)* format | 指向OH_AVFormat的指针，为LowPowerVideoSink设置的参数。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_SetVideoSurface()

```
OH_AVErrCode OH_LowPowerVideoSink_SetVideoSurface(OH_LowPowerVideoSink* sink, const OHNativeWindow* surface)
```

**描述**

为LowPowerVideoSink设置渲染画面窗口。 需要在[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)前完成。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| const [OHNativeWindow](../apis-avcodec-kit/_codec_base.md#ohnativewindow)* surface | 指向OHNativeWindow实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_Prepare()

```
OH_AVErrCode OH_LowPowerVideoSink_Prepare(OH_LowPowerVideoSink* sink)
```

**描述**

开始LowPowerVideoSink准备，需要在[OH_LowPowerVideoSink_SetSyncAudioSink](#oh_lowpowervideosink_setsyncaudiosink)之后调用。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_UNSUPPORT：不支持的格式。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_StartDecoder()

```
OH_AVErrCode OH_LowPowerVideoSink_StartDecoder(OH_LowPowerVideoSink* sink)
```

**描述**

开始LowPowerVideoSink解码，在[OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare)后或非播放中[OH_LowPowerVideoSink_SetTargetStartFrame](#oh_lowpowervideosink_settargetstartframe)后调用。<br> 启动成功后，LowPowerVideoSink将开始上报[OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded)事件。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_UNSUPPORT：不支持的格式。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_RenderFirstFrame()

```
OH_AVErrCode OH_LowPowerVideoSink_RenderFirstFrame(OH_LowPowerVideoSink* sink)
```

**描述**

渲染LowPowerVideoSink解码出的第一帧，在[OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder)之后调用。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_StartRenderer()

```
OH_AVErrCode OH_LowPowerVideoSink_StartRenderer(OH_LowPowerVideoSink* sink)
```

**描述**

开始LowPowerVideoSink渲染，在[OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder)之后调用。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_UNSUPPORT：不支持的格式。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_Pause()

```
OH_AVErrCode OH_LowPowerVideoSink_Pause(OH_LowPowerVideoSink* sink)
```

**描述**

暂停LowPowerVideoSink，在[OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer)或[OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume)后调用。<br> 暂停成功后，LowPowerVideoSink将暂停[OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded)事件的上报。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_Resume()

```
OH_AVErrCode OH_LowPowerVideoSink_Resume(OH_LowPowerVideoSink* sink)
```

**描述**

恢复LowPowerVideoSink，在[OH_LowPowerVideoSink_Pause](#oh_lowpowervideosink_pause)后调用。<br> 恢复成功后，LowPowerVideoSink将恢复[OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded)事件的上报。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_Flush()

```
OH_AVErrCode OH_LowPowerVideoSink_Flush(OH_LowPowerVideoSink* sink)
```

**描述**

清除LowPowerVideoSink中所有解码器和渲染缓存的输入输出数据。<br> 此接口不建议在[OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer)或[OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume)之后调用。<br> 需要注意的是，如果编解码器之前已输入数据，则需要重新输入编解码器数据。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_Stop()

```
OH_AVErrCode OH_LowPowerVideoSink_Stop(OH_LowPowerVideoSink* sink)
```

**描述**

停止LowPowerVideoSink。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_Reset()

```
OH_AVErrCode OH_LowPowerVideoSink_Reset(OH_LowPowerVideoSink* sink)
```

**描述**

重置LowPowerVideoSink。<br> 如果要重新使用该实例，需要调用[OH_LowPowerVideoSink_Configure](#oh_lowpowervideosink_configure)完成配置。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_Destroy()

```
OH_AVErrCode OH_LowPowerVideoSink_Destroy(OH_LowPowerVideoSink* sink)
```

**描述**

清理解码器内部资源，销毁LowPowerVideoSink实例。不能重复销毁。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_SetSyncAudioSink()

```
OH_AVErrCode OH_LowPowerVideoSink_SetSyncAudioSink(OH_LowPowerVideoSink* videoSink, OH_LowPowerAudioSink* audioSink)
```

**描述**

LowPowerVideoSink设置用于音画同步的OH_LowPowerAudioSink。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* videoSink | 指向OH_LowPowerVideoSink实例的指针。 |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* audioSink | 指向OH_LowPowerAudioSink实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_SetTargetStartFrame()

```
OH_AVErrCode OH_LowPowerVideoSink_SetTargetStartFrame(OH_LowPowerVideoSink* sink,const int64_t framePts,OH_LowPowerVideoSink_OnTargetArrived onTargetArrived,const int64_t timeoutMs,void* userData)
```

**描述**

为LowPowerVideoSink设置目标渲染帧。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| const int64_t framePts | 渲染的目标视频帧的pts。 |
| [OH_LowPowerVideoSink_OnTargetArrived](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ontargetarrived) onTargetArrived | OH_LowPowerVideoSink_OnTargetArrived方法，当目标帧渲染时触发该方法。 |
| const int64_t timeoutMs | 如果等待第一帧的时间超过timeoutMs，则直接调用onTargetArrived。 |
| void* userData | 用户数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_SetPlaybackSpeed()

```
OH_AVErrCode OH_LowPowerVideoSink_SetPlaybackSpeed(OH_LowPowerVideoSink* sink, const float speed)
```

**描述**

为LowPowerVideoSink设置播放倍速。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| const float speed | 播放速率的值。当前版本有效范围为[0.1，4.0]。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_ReturnSamples()

```
OH_AVErrCode OH_LowPowerVideoSink_ReturnSamples(OH_LowPowerVideoSink* sink, OH_AVSamplesBuffer* samples)
```

**描述**

给LowPowerVideoSink输入buffer。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md)* samples | 需要送LowPowerVideoSink消费的OH_AVSamplesBuffer，支持聚包输入。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSink_RegisterCallback()

```
OH_AVErrCode OH_LowPowerVideoSink_RegisterCallback(OH_LowPowerVideoSink* sink, OH_LowPowerVideoSinkCallback* callback)
```

**描述**

为LowPowerVideoSink注册回调。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | 指向OH_LowPowerVideoSink实例的指针。 |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_SERVICE_DIED：媒体服务端已销毁。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSinkCallback_Create()

```
OH_LowPowerVideoSinkCallback* OH_LowPowerVideoSinkCallback_Create(void)
```

**描述**

创建OH_LowPowerVideoSinkCallback。

**起始版本：** 20

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* | 返回指向OH_LowPowerVideoSinkCallback实例的指针。如果内存不足，则返回nullptr。 |

### OH_LowPowerVideoSinkCallback_Destroy()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_Destroy(OH_LowPowerVideoSinkCallback* callback)
```

**描述**

销毁OH_LowPowerVideoSinkCallback对象。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。 |

### OH_LowPowerVideoSinkCallback_SetDataNeededListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetDataNeededListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnDataNeeded onDataNeeded, void* userData)
```

**描述**

为LowPowerVideoSinkCallback设置需要数据监听。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |
| [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) onDataNeeded | OH_LowPowerVideoSink_OnDataNeeded方法，在DataNeeded事件触发时调用。 |
| void* userData | 用户执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSinkCallback_SetErrorListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetErrorListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnError onError, void* userData)
```

**描述**

为LowPowerVideoSinkCallback回调设置错误监听。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |
| [OH_LowPowerVideoSink_OnError](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onerror) onError | OH_LowPowerVideoSink_OnError方法，在Error事件触发时调用。 |
| void* userData | 用户执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSinkCallback_SetRenderStartListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetRenderStartListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnRenderStarted onRenderStarted, void* userData)
```

**描述**

为LowPowerVideoSinkCallback回调设置开始渲染监听。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |
| [OH_LowPowerVideoSink_OnRenderStarted](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onrenderstarted) onRenderStarted | OH_LowPowerVideoSink_OnRenderStarted方法，在RenderStarted事件触发时调用。 |
| void* userData | 用户执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSinkCallback_SetStreamChangedListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetStreamChangedListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnStreamChanged onStreamChanged, void* userData)
```

**描述**

为LowPowerVideoSinkCallback回调设置流切换监听。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |
| [OH_LowPowerVideoSink_OnStreamChanged](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onstreamchanged) onStreamChanged | OH_LowPowerVideoSink_OnStreamChanged方法，在StreamChanged事件触发时调用。 |
| void* userData | 用户执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSinkCallback_SetFirstFrameDecodedListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetFirstFrameDecodedListener(OH_LowPowerVideoSinkCallback* callback,OH_LowPowerVideoSink_OnFirstFrameDecoded onFirstFrameDecoded,void* userData)
```

**描述**

为LowPowerVideoSinkCallback回调设置首帧准备完成监听。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |
| [OH_LowPowerVideoSink_OnFirstFrameDecoded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onfirstframedecoded) onFirstFrameDecoded | OH_LowPowerVideoSink_OnFirstFrameReady方法，在FirstFrameReady事件触发时调用。 |
| void* userData | 用户执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |

### OH_LowPowerVideoSinkCallback_SetEosListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetEosListener(OH_LowPowerVideoSinkCallback* callback,OH_LowPowerVideoSink_OnEos onEos, void* userData)
```

**描述**

为LowPowerVideoSinkCallback回调设置播放结束监听。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | 指向OH_LowPowerVideoSinkCallback实例的指针。 |
| [OH_LowPowerVideoSink_OnEos](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_oneos) onEos | OH_LowPowerVideoSink_OnEos方法，在Eos事件触发时调用。 |
| void* userData | 用户执行回调所依赖的数据。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK：执行成功。<br> AV_ERR_INVALID_VAL：参数为nullptr或参数非法。<br> AV_ERR_OPERATE_NOT_PERMIT：操作不支持。 |


