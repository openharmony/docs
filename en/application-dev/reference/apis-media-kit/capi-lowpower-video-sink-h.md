# lowpower_video_sink.h

## Overview

The file declares the native APIs provided by the LowPowerVideoSink. You can use the APIs to implement low-power video playback.

**File to include**: <multimedia/player_framework/lowpower_video_sink.h>

**Library**: liblowpower_avsink.so

**System capability**: SystemCapability.Multimedia.Media.LowPowerAVSink

**Since**: 20

**Related module**: [LowPowerVideoSink](capi-lowpowervideosink.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink* OH_LowPowerVideoSink_CreateByMime(const char* mime)](#oh_lowpowervideosink_createbymime) | Creates an OH_LowPowerVideoSink instance.|
| [OH_AVErrCode OH_LowPowerVideoSink_Configure(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)](#oh_lowpowervideosink_configure) | Configures an OH_LowPowerVideoSink instance. This function must be called before [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare).|
| [OH_AVErrCode OH_LowPowerVideoSink_SetParameter(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)](#oh_lowpowervideosink_setparameter) | Sets parameters for an OH_LowPowerVideoSink instance. The parameters can be dynamically set after [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare).|
| [OH_AVErrCode OH_LowPowerVideoSink_GetParameter(OH_LowPowerVideoSink* sink, OH_AVFormat* format)](#oh_lowpowervideosink_getparameter) | Obtains the parameters of an OH_LowPowerVideoSink instance.|
| [OH_AVErrCode OH_LowPowerVideoSink_SetVideoSurface(OH_LowPowerVideoSink* sink, const OHNativeWindow* surface)](#oh_lowpowervideosink_setvideosurface) | Sets the rendering window for an OH_LowPowerVideoSink instance. This function must be called before [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare).|
| [OH_AVErrCode OH_LowPowerVideoSink_Prepare(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_prepare) | Prepares an OH_LowPowerVideoSink instance for decoding and rendering. This function must be called after [OH_LowPowerVideoSink_SetSyncAudioSink](#oh_lowpowervideosink_setsyncaudiosink).|
| [OH_AVErrCode OH_LowPowerVideoSink_StartDecoder(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_startdecoder) | Starts an OH_LowPowerVideoSink instance for decoding. This function must be called after [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare) or if no video is playing, after [OH_LowPowerVideoSink_SetTargetStartFrame](#oh_lowpowervideosink_settargetstartframe).<br>After successful startup, the OH_LowPowerVideoSink instance starts reporting the [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) event.|
| [OH_AVErrCode OH_LowPowerVideoSink_RenderFirstFrame(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_renderfirstframe) | Renders the first frame decoded by an OH_LowPowerVideoSink instance. This function must be called after [OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder).|
| [OH_AVErrCode OH_LowPowerVideoSink_StartRenderer(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_startrenderer) | Starts an OH_LowPowerVideoSink instance for rendering. This function must be called after [OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder).|
| [OH_AVErrCode OH_LowPowerVideoSink_Pause(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_pause) | Pauses an OH_LowPowerVideoSink instance. This function must be called after [OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer) or [OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume).<br>After successful pause, the OH_LowPowerVideoSink instance stops reporting the [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) event.|
| [OH_AVErrCode OH_LowPowerVideoSink_Resume(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_resume) | Resumes an OH_LowPowerVideoSink instance. This function must be called after[OH_LowPowerVideoSink_Pause](#oh_lowpowervideosink_pause).<br>After successful resumption, the OH_LowPowerVideoSink instance resumes reporting the [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) event.|
| [OH_AVErrCode OH_LowPowerVideoSink_Flush(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_flush) | Clears all input and output data from the decoders and render buffers of an OH_LowPowerVideoSink instance.<br>You are not advised to call this function after [OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer) or [OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume).<br>Note that if the decoder has previously received data, you must input the codec data again.|
| [OH_AVErrCode OH_LowPowerVideoSink_Stop(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_stop) | Stops an OH_LowPowerVideoSink instance.|
| [OH_AVErrCode OH_LowPowerVideoSink_Reset(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_reset) | Resets an OH_LowPowerVideoSink instance.<br>To reuse the instance, you must call [OH_LowPowerVideoSink_Configure](#oh_lowpowervideosink_configure) to configure the instance again.|
| [OH_AVErrCode OH_LowPowerVideoSink_Destroy(OH_LowPowerVideoSink* sink)](#oh_lowpowervideosink_destroy) | Clears internal resources of an OH_LowPowerVideoSink instance and destroys the instance. You only need to call the function once.|
| [OH_AVErrCode OH_LowPowerVideoSink_SetSyncAudioSink(OH_LowPowerVideoSink* videoSink, OH_LowPowerAudioSink* audioSink)](#oh_lowpowervideosink_setsyncaudiosink) | Sets an OH_LowPowerAudioSink instance for audio-video synchronization in an OH_LowPowerVideoSink instance.|
| [OH_AVErrCode OH_LowPowerVideoSink_SetTargetStartFrame(OH_LowPowerVideoSink* sink,const int64_t framePts,OH_LowPowerVideoSink_OnTargetArrived onTargetArrived,const int64_t timeoutMs,void* userData)](#oh_lowpowervideosink_settargetstartframe) | Sets the target rendering frame for an OH_LowPowerVideoSink instance.|
| [OH_AVErrCode OH_LowPowerVideoSink_SetPlaybackSpeed(OH_LowPowerVideoSink* sink, const float speed)](#oh_lowpowervideosink_setplaybackspeed) | Sets the playback speed for an OH_LowPowerVideoSink instance.|
| [OH_AVErrCode OH_LowPowerVideoSink_ReturnSamples(OH_LowPowerVideoSink* sink, OH_AVSamplesBuffer* samples)](#oh_lowpowervideosink_returnsamples) | Provides a buffer to an OH_LowPowerVideoSink instance for procesing.|
| [OH_AVErrCode OH_LowPowerVideoSink_RegisterCallback(OH_LowPowerVideoSink* sink, OH_LowPowerVideoSinkCallback* callback)](#oh_lowpowervideosink_registercallback) | Registers a callback for an OH_LowPowerVideoSink instance.|
| [OH_LowPowerVideoSinkCallback* OH_LowPowerVideoSinkCallback_Create(void)](#oh_lowpowervideosinkcallback_create) | Creates an OH_LowPowerVideoSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_Destroy(OH_LowPowerVideoSinkCallback* callback)](#oh_lowpowervideosinkcallback_destroy) | Destroys an OH_LowPowerVideoSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetDataNeededListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnDataNeeded onDataNeeded, void* userData)](#oh_lowpowervideosinkcallback_setdataneededlistener) | Sets a data needed listener for an OH_LowPowerVideoSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetErrorListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnError onError, void* userData)](#oh_lowpowervideosinkcallback_seterrorlistener) | Sets an error listener for an OH_LowPowerVideoSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetRenderStartListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnRenderStarted onRenderStarted, void* userData)](#oh_lowpowervideosinkcallback_setrenderstartlistener) | Sets a render start listener for an OH_LowPowerVideoSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetStreamChangedListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnStreamChanged onStreamChanged, void* userData)](#oh_lowpowervideosinkcallback_setstreamchangedlistener) | Sets a stream change listener for an OH_LowPowerVideoSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetFirstFrameDecodedListener(OH_LowPowerVideoSinkCallback* callback,OH_LowPowerVideoSink_OnFirstFrameDecoded onFirstFrameDecoded,void* userData)](#oh_lowpowervideosinkcallback_setfirstframedecodedlistener) | Sets a first-frame ready listener for an OH_LowPowerVideoSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerVideoSinkCallback_SetEosListener(OH_LowPowerVideoSinkCallback* callback,OH_LowPowerVideoSink_OnEos onEos, void* userData)](#oh_lowpowervideosinkcallback_seteoslistener) | Sets an end-of-stream listener for an OH_LowPowerVideoSinkCallback instance.|

## Function Description

### OH_LowPowerVideoSink_CreateByMime()

```
OH_LowPowerVideoSink* OH_LowPowerVideoSink_CreateByMime(const char* mime)
```

**Description**

Creates an OH_LowPowerVideoSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char* mime | Pointer to the MIME type of the video decoder. For details about the available options, see [AVCODEC_MIME_TYPE](../apis-avcodec-kit/_codec_base.md#variables).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* | Pointer to the OH_LowPowerVideoSink instance created. If the operation fails, nullptr is returned.|

### OH_LowPowerVideoSink_Configure()

```
OH_AVErrCode OH_LowPowerVideoSink_Configure(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)
```

**Description**

Configures an OH_LowPowerVideoSink instance. This function must be called before [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| const [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | Pointer to an OH_AVFormat instance, which describes the parameters to be configured for the OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_SetParameter()

```
OH_AVErrCode OH_LowPowerVideoSink_SetParameter(OH_LowPowerVideoSink* sink, const OH_AVFormat* format)
```

**Description**

Sets parameters for an OH_LowPowerVideoSink instance. The parameters can be dynamically set after [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| const [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | Pointer to an OH_AVFormat instance, which describes the parameters to be configured for the OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_GetParameter()

```
OH_AVErrCode OH_LowPowerVideoSink_GetParameter(OH_LowPowerVideoSink* sink, OH_AVFormat* format)
```

**Description**

Obtains the parameters of an OH_LowPowerVideoSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | Pointer to an OH_AVFormat instance, which describes the parameters configured for an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_SetVideoSurface()

```
OH_AVErrCode OH_LowPowerVideoSink_SetVideoSurface(OH_LowPowerVideoSink* sink, const OHNativeWindow* surface)
```

**Description**

Sets the rendering window for an OH_LowPowerVideoSink instance. This function must be called before [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| const [OHNativeWindow](../apis-avcodec-kit/_codec_base.md#ohnativewindow)* surface | Pointer to the OHNativeWindow instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_Prepare()

```
OH_AVErrCode OH_LowPowerVideoSink_Prepare(OH_LowPowerVideoSink* sink)
```

**Description**

Prepares an OH_LowPowerVideoSink instance for decoding and rendering. This function must be called after [OH_LowPowerVideoSink_SetSyncAudioSink](#oh_lowpowervideosink_setsyncaudiosink).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_StartDecoder()

```
OH_AVErrCode OH_LowPowerVideoSink_StartDecoder(OH_LowPowerVideoSink* sink)
```

**Description**

Starts an OH_LowPowerVideoSink instance for decoding. This function must be called after [OH_LowPowerVideoSink_Prepare](#oh_lowpowervideosink_prepare) or if no video is playing, after [OH_LowPowerVideoSink_SetTargetStartFrame](#oh_lowpowervideosink_settargetstartframe).

After successful startup, the OH_LowPowerVideoSink instance starts reporting the [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_RenderFirstFrame()

```
OH_AVErrCode OH_LowPowerVideoSink_RenderFirstFrame(OH_LowPowerVideoSink* sink)
```

**Description**

Renders the first frame decoded by an OH_LowPowerVideoSink instance. This function must be called after [OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_StartRenderer()

```
OH_AVErrCode OH_LowPowerVideoSink_StartRenderer(OH_LowPowerVideoSink* sink)
```

**Description**

Starts an OH_LowPowerVideoSink instance for rendering. This function must be called after [OH_LowPowerVideoSink_StartDecoder](#oh_lowpowervideosink_startdecoder).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_Pause()

```
OH_AVErrCode OH_LowPowerVideoSink_Pause(OH_LowPowerVideoSink* sink)
```

**Description**

Pauses an OH_LowPowerVideoSink instance. This function must be called after [OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer) or [OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume).

After successful pause, the OH_LowPowerVideoSink instance stops reporting the [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_Resume()

```
OH_AVErrCode OH_LowPowerVideoSink_Resume(OH_LowPowerVideoSink* sink)
```

**Description**

Resumes an OH_LowPowerVideoSink instance. This function must be called after[OH_LowPowerVideoSink_Pause](#oh_lowpowervideosink_pause).

After successful resumption, the OH_LowPowerVideoSink instance resumes reporting the [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_Flush()

```
OH_AVErrCode OH_LowPowerVideoSink_Flush(OH_LowPowerVideoSink* sink)
```

**Description**

Clears all input and output data from the decoders and render buffers of an OH_LowPowerVideoSink instance.

You are not advised to call this function after [OH_LowPowerVideoSink_StartRenderer](#oh_lowpowervideosink_startrenderer) or [OH_LowPowerVideoSink_Resume](#oh_lowpowervideosink_resume).

Note that if the decoder has previously received data, you must input the codec data again.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_Stop()

```
OH_AVErrCode OH_LowPowerVideoSink_Stop(OH_LowPowerVideoSink* sink)
```

**Description**

Stops an OH_LowPowerVideoSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_Reset()

```
OH_AVErrCode OH_LowPowerVideoSink_Reset(OH_LowPowerVideoSink* sink)
```

**Description**

Resets an OH_LowPowerVideoSink instance.

To reuse the instance, you must call [OH_LowPowerVideoSink_Configure](#oh_lowpowervideosink_configure) to configure the instance again.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_Destroy()

```
OH_AVErrCode OH_LowPowerVideoSink_Destroy(OH_LowPowerVideoSink* sink)
```

**Description**

Clears internal resources of an OH_LowPowerVideoSink instance and destroys the instance. You only need to call the function once.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_SetSyncAudioSink()

```
OH_AVErrCode OH_LowPowerVideoSink_SetSyncAudioSink(OH_LowPowerVideoSink* videoSink, OH_LowPowerAudioSink* audioSink)
```

**Description**

Sets an OH_LowPowerAudioSink instance for audio-video synchronization in an OH_LowPowerVideoSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* videoSink | Pointer to an OH_LowPowerVideoSink instance.|
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* audioSink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_SetTargetStartFrame()

```
OH_AVErrCode OH_LowPowerVideoSink_SetTargetStartFrame(OH_LowPowerVideoSink* sink,const int64_t framePts,OH_LowPowerVideoSink_OnTargetArrived onTargetArrived,const int64_t timeoutMs,void* userData)
```

**Description**

Sets the target rendering frame for an OH_LowPowerVideoSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| const int64_t framePts | Presentation timestamp (PTS) of the target video frame to render.|
| [OH_LowPowerVideoSink_OnTargetArrived](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ontargetarrived) onTargetArrived | OH_LowPowerVideoSink_OnTargetArrived, which is invoked when the target frame is rendered.|
| const int64_t timeoutMs | Time wait for the first frame to finish rendering. If the first frame does not finish rendering within the specified time, the OH_LowPowerVideoSink_OnTargetArrived callback is directly invoked.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_SetPlaybackSpeed()

```
OH_AVErrCode OH_LowPowerVideoSink_SetPlaybackSpeed(OH_LowPowerVideoSink* sink, const float speed)
```

**Description**

Sets the playback speed for an OH_LowPowerVideoSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| const float speed | Playback speed, in the range [0.1, 4.0].|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_ReturnSamples()

```
OH_AVErrCode OH_LowPowerVideoSink_ReturnSamples(OH_LowPowerVideoSink* sink, OH_AVSamplesBuffer* samples)
```

**Description**

Provides a buffer to an OH_LowPowerVideoSink instance for procesing.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md)* samples | Pointer to the OH_AVSamplesBuffer instance to be provided. Batch input of samples is supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSink_RegisterCallback()

```
OH_AVErrCode OH_LowPowerVideoSink_RegisterCallback(OH_LowPowerVideoSink* sink, OH_LowPowerVideoSinkCallback* callback)
```

**Description**

Registers a callback for an OH_LowPowerVideoSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSink](capi-lowpowervideosink-oh-lowpowervideosink.md)* sink | Pointer to an OH_LowPowerVideoSink instance.|
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSinkCallback_Create()

```
OH_LowPowerVideoSinkCallback* OH_LowPowerVideoSinkCallback_Create(void)
```

**Description**

Creates an OH_LowPowerVideoSinkCallback instance.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* | Pointer to the OH_LowPowerVideoSinkCallback instance created. If the memory is insufficient, nullptr is returned.|

### OH_LowPowerVideoSinkCallback_Destroy()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_Destroy(OH_LowPowerVideoSinkCallback* callback)
```

**Description**

Destroys an OH_LowPowerVideoSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.|

### OH_LowPowerVideoSinkCallback_SetDataNeededListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetDataNeededListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnDataNeeded onDataNeeded, void* userData)
```

**Description**

Sets a data needed listener for an OH_LowPowerVideoSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|
| [OH_LowPowerVideoSink_OnDataNeeded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_ondataneeded) onDataNeeded | OH_LowPowerVideoSink_OnDataNeeded, which is invoked when the OH_LowPowerVideoSink instance needs more data.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSinkCallback_SetErrorListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetErrorListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnError onError, void* userData)
```

**Description**

Sets an error listener for an OH_LowPowerVideoSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|
| [OH_LowPowerVideoSink_OnError](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onerror) onError | OH_LowPowerVideoSink_OnError, which is invoked when an error occurs in the OH_LowPowerVideoSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSinkCallback_SetRenderStartListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetRenderStartListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnRenderStarted onRenderStarted, void* userData)
```

**Description**

Sets a render start listener for an OH_LowPowerVideoSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|
| [OH_LowPowerVideoSink_OnRenderStarted](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onrenderstarted) onRenderStarted | OH_LowPowerVideoSink_OnRenderStarted, which is invoked when rendering starts in the OH_LowPowerVideoSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSinkCallback_SetStreamChangedListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetStreamChangedListener(OH_LowPowerVideoSinkCallback* callback, OH_LowPowerVideoSink_OnStreamChanged onStreamChanged, void* userData)
```

**Description**

Sets a stream change listener for an OH_LowPowerVideoSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|
| [OH_LowPowerVideoSink_OnStreamChanged](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onstreamchanged) onStreamChanged | OH_LowPowerVideoSink_OnStreamChanged, which is invoked when the stream changes in the OH_LowPowerVideoSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSinkCallback_SetFirstFrameDecodedListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetFirstFrameDecodedListener(OH_LowPowerVideoSinkCallback* callback,OH_LowPowerVideoSink_OnFirstFrameDecoded onFirstFrameDecoded,void* userData)
```

**Description**

Sets a first-frame ready listener for an OH_LowPowerVideoSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|
| [OH_LowPowerVideoSink_OnFirstFrameDecoded](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_onfirstframedecoded) onFirstFrameDecoded | OH_LowPowerVideoSink_OnFirstFrameReady, which is invoked when the first frame is ready in the OH_LowPowerVideoSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerVideoSinkCallback_SetEosListener()

```
OH_AVErrCode OH_LowPowerVideoSinkCallback_SetEosListener(OH_LowPowerVideoSinkCallback* callback,OH_LowPowerVideoSink_OnEos onEos, void* userData)
```

**Description**

Sets an end-of-stream listener for an OH_LowPowerVideoSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerVideoSinkCallback](capi-lowpowervideosink-oh-lowpowervideosinkcallback.md)* callback | Pointer to an OH_LowPowerVideoSinkCallback instance.|
| [OH_LowPowerVideoSink_OnEos](capi-lowpower-video-sink-base-h.md#oh_lowpowervideosink_oneos) onEos | OH_LowPowerVideoSink_OnEos, which is invoked when playback is complete in the OH_LowPowerVideoSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|
