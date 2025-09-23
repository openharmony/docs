# lowpower_audio_sink.h

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @Saber_e-->
<!--Designer: @yangde_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the native APIs provided by the OH_LowPowerAudioSink instance. You can use the APIs to implement low-power audio playback.

**File to include**: <multimedia/player_framework/lowpower_audio_sink.h>

**Library**: liblowpower_avsink.so

**System capability**: SystemCapability.Multimedia.Media.LowPowerAVSink

**Since**: 20

**Related module**: [LowPowerAudioSink](capi-lowpoweraudiosink.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink* OH_LowPowerAudioSink_CreateByMime(const char* mime)](#oh_lowpoweraudiosink_createbymime) | Creates an OH_LowPowerAudioSink instance.|
| [OH_AVErrCode OH_LowPowerAudioSink_Configure(OH_LowPowerAudioSink* sink, const OH_AVFormat* format)](#oh_lowpoweraudiosink_configure) | Configures an OH_LowPowerAudioSink instance. This function must be called before [OH_LowPowerAudioSink_Prepare](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_prepare).|
| [OH_AVErrCode OH_LowPowerAudioSink_SetParameter(OH_LowPowerAudioSink* sink, const OH_AVFormat* format)](#oh_lowpoweraudiosink_setparameter) | Sets parameters for an OH_LowPowerAudioSink instance. The parameters can be dynamically set after [OH_LowPowerAudioSink_Prepare](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_prepare).|
| [OH_AVErrCode OH_LowPowerAudioSink_GetParameter(OH_LowPowerAudioSink* sink, OH_AVFormat* format)](#oh_lowpoweraudiosink_getparameter) | Obtains the parameters of an OH_LowPowerAudioSink instance.|
| [OH_AVErrCode OH_LowPowerAudioSink_Prepare(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_prepare) | Prepares an OH_LowPowerAudioSink instance for decoding and rendering. This function must be called after [OH_LowPowerAudioSink_Configure](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_configure).<br>Before calling this function, you must call [OH_LowPowerVideoSink_SetSyncAudioSink](capi-lowpower-video-sink-h.md#oh_lowpowervideosink_setsyncaudiosink) of the LowPowerVideoSink.|
| [OH_AVErrCode OH_LowPowerAudioSink_Start(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_start) | Starts an OH_LowPowerAudioSink instance. This function must be called after a successful call to [OH_LowPowerAudioSink_Prepare](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_prepare).<br>After successful startup, the OH_LowPowerAudioSink instance starts reporting the [OH_LowPowerAudioSink_OnDataNeeded](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondataneeded) event.|
| [OH_AVErrCode OH_LowPowerAudioSink_Pause(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_pause) | Pauses an OH_LowPowerAudioSink instance. This function must be called after [OH_LowPowerAudioSink_Start](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_start) or [OH_LowPowerAudioSink_Resume](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_resume).<br>After successful pause, the OH_LowPowerAudioSink instance stops reporting the [OH_LowPowerAudioSink_OnDataNeeded](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondataneeded) event.|
| [OH_AVErrCode OH_LowPowerAudioSink_Resume(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_resume) | Resumes an OH_LowPowerAudioSink instance. This function must be called after [OH_LowPowerAudioSink_Pause](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_pause).<br>After successful resumption, the OH_LowPowerAudioSink instance resumes reporting the [OH_LowPowerAudioSink_OnDataNeeded](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondataneeded) event.|
| [OH_AVErrCode OH_LowPowerAudioSink_Flush(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_flush) | Clears all input and output data from the decoders and render buffers of an OH_LowPowerAudioSink instance.<br>You are not advised to call this function after [OH_LowPowerAudioSink_Start](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_start) or [OH_LowPowerAudioSink_Resume](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_resume).<br>Note that if the decoder has previously received data, you must input the codec data again.|
| [OH_AVErrCode OH_LowPowerAudioSink_Stop(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_stop) | Stops an OH_LowPowerAudioSink instance.|
| [OH_AVErrCode OH_LowPowerAudioSink_Reset(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_reset) | Resets an OH_LowPowerAudioSink instance.<br>To reuse the instance, you must call [OH_LowPowerAudioSink_Configure](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_configure) to configure the instance again.|
| [OH_AVErrCode OH_LowPowerAudioSink_Destroy(OH_LowPowerAudioSink* sink)](#oh_lowpoweraudiosink_destroy) | Clears internal resources of an OH_LowPowerAudioSink instance and destroys the instance. You only need to call the function once.|
| [OH_AVErrCode OH_LowPowerAudioSink_SetVolume(OH_LowPowerAudioSink* sink, const float volume)](#oh_lowpoweraudiosink_setvolume) | Sets the rendering volume for an OH_LowPowerAudioSink instance.|
| [OH_AVErrCode OH_LowPowerAudioSink_SetPlaybackSpeed(OH_LowPowerAudioSink* sink, const float speed)](#oh_lowpoweraudiosink_setplaybackspeed) | Sets the audio rendering speed for an OH_LowPowerAudioSink instance.|
| [OH_AVErrCode OH_LowPowerAudioSink_ReturnSamples(OH_LowPowerAudioSink* sink, OH_AVSamplesBuffer* samples)](#oh_lowpoweraudiosink_returnsamples) | Provides a buffer to an OH_LowPowerAudioSink instance for procesing.|
| [OH_AVErrCode OH_LowPowerAudioSink_RegisterCallback(OH_LowPowerAudioSink* sink, OH_LowPowerAudioSinkCallback* callback)](#oh_lowpoweraudiosink_registercallback) | Registers a callback for an OH_LowPowerAudioSink instance.|
| [OH_LowPowerAudioSinkCallback* OH_LowPowerAudioSinkCallback_Create(void)](#oh_lowpoweraudiosinkcallback_create) | Creates an OH_LowPowerAudioSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerAudioSinkCallback_Destroy(OH_LowPowerAudioSinkCallback* callback)](#oh_lowpoweraudiosinkcallback_destroy) | Destroys an OH_LowPowerAudioSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerAudioSinkCallback_SetPositionUpdateListener(OH_LowPowerAudioSinkCallback* callback, OH_LowPowerAudioSink_OnPositionUpdated onPositionUpdated, void* userData)](#oh_lowpoweraudiosinkcallback_setpositionupdatelistener) | Sets a progress update listener for an OH_LowPowerAudioSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerAudioSinkCallback_SetDataNeededListener(OH_LowPowerAudioSinkCallback* callback, OH_LowPowerAudioSink_OnDataNeeded onDataNeeded, void* userData)](#oh_lowpoweraudiosinkcallback_setdataneededlistener) | Sets a data needed listener for an OH_LowPowerAudioSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerAudioSinkCallback_SetErrorListener(OH_LowPowerAudioSinkCallback* callback, OH_LowPowerAudioSink_OnError onError, void* userData)](#oh_lowpoweraudiosinkcallback_seterrorlistener) | Sets an error listener for an OH_LowPowerAudioSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerAudioSinkCallback_SetInterruptListener(OH_LowPowerAudioSinkCallback* callback, OH_LowPowerAudioSink_OnInterrupted onInterrupted, void* userData)](#oh_lowpoweraudiosinkcallback_setinterruptlistener) | Sets an audio focus interruption listener for an OH_LowPowerAudioSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerAudioSinkCallback_SetDeviceChangeListener(OH_LowPowerAudioSinkCallback* callback, OH_LowPowerAudioSink_OnDeviceChanged onDeviceChanged, void* userData)](#oh_lowpoweraudiosinkcallback_setdevicechangelistener) | Sets an audio device change listener for an OH_LowPowerAudioSinkCallback instance.|
| [OH_AVErrCode OH_LowPowerAudioSinkCallback_SetEosListener(OH_LowPowerAudioSinkCallback *callback, OH_LowPowerAudioSink_OnEos onEos, void* userData)](#oh_lowpoweraudiosinkcallback_seteoslistener) | Sets an end-of-stream listener for an OH_LowPowerAudioSinkCallback instance.|

## Function Description

### OH_LowPowerAudioSink_CreateByMime()

```
OH_LowPowerAudioSink* OH_LowPowerAudioSink_CreateByMime(const char* mime)
```

**Description**

Creates an OH_LowPowerAudioSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| const char* mime | Pointer to the MIME type of the audio decoder. For details about the available options, see [AVCODEC_MIME_TYPE](../apis-avcodec-kit/_codec_base.md#variables).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* | Pointer to the OH_LowPowerAudioSink instance created. If the operation fails, nullptr is returned.|

### OH_LowPowerAudioSink_Configure()

```
OH_AVErrCode OH_LowPowerAudioSink_Configure(OH_LowPowerAudioSink* sink, const OH_AVFormat* format)
```

**Description**

Configures an OH_LowPowerAudioSink instance. This function must be called before [OH_LowPowerAudioSink_Prepare](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_prepare).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| const [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | Pointer to an OH_AVFormat instance, which describes the parameters to be configured for the OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_SetParameter()

```
OH_AVErrCode OH_LowPowerAudioSink_SetParameter(OH_LowPowerAudioSink* sink, const OH_AVFormat* format)
```

**Description**

Sets parameters for an OH_LowPowerAudioSink instance. The parameters can be dynamically set after [OH_LowPowerAudioSink_Prepare](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_prepare).

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| const [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | Pointer to an OH_AVFormat instance, which describes the parameters configured for an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_GetParameter()

```
OH_AVErrCode OH_LowPowerAudioSink_GetParameter(OH_LowPowerAudioSink* sink, OH_AVFormat* format)
```

**Description**

Obtains the parameters of an OH_LowPowerAudioSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* format | Pointer to an OH_AVFormat instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Prepare()

```
OH_AVErrCode OH_LowPowerAudioSink_Prepare(OH_LowPowerAudioSink* sink)
```

**Description**

Prepares an OH_LowPowerAudioSink instance for decoding and rendering. This function must be called after [OH_LowPowerAudioSink_Configure](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_configure).

Before calling this function, you must call [OH_LowPowerVideoSink_SetSyncAudioSink](capi-lowpower-video-sink-h.md#oh_lowpowervideosink_setsyncaudiosink) of the LowPowerVideoSink.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Start()

```
OH_AVErrCode OH_LowPowerAudioSink_Start(OH_LowPowerAudioSink* sink)
```

**Description**

Starts an OH_LowPowerAudioSink instance. This function must be called after a successful call to [OH_LowPowerAudioSink_Prepare](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_prepare).

After successful startup, the OH_LowPowerAudioSink instance starts reporting the [OH_LowPowerAudioSink_OnDataNeeded](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondataneeded) event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_UNSUPPORT**: The format is not supported.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Pause()

```
OH_AVErrCode OH_LowPowerAudioSink_Pause(OH_LowPowerAudioSink* sink)
```

**Description**

Pauses an OH_LowPowerAudioSink instance. This function must be called after [OH_LowPowerAudioSink_Start](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_start) or [OH_LowPowerAudioSink_Resume](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_resume).

After successful pause, the OH_LowPowerAudioSink instance stops reporting the [OH_LowPowerAudioSink_OnDataNeeded](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondataneeded) event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Resume()

```
OH_AVErrCode OH_LowPowerAudioSink_Resume(OH_LowPowerAudioSink* sink)
```

**Description**

Resumes an OH_LowPowerAudioSink instance. This function must be called after [OH_LowPowerAudioSink_Pause](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_pause).

After successful resumption, the OH_LowPowerAudioSink instance resumes reporting the [OH_LowPowerAudioSink_OnDataNeeded](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondataneeded) event.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Flush()

```
OH_AVErrCode OH_LowPowerAudioSink_Flush(OH_LowPowerAudioSink* sink)
```

**Description**

Clears all input and output data from the decoders and render buffers of an OH_LowPowerAudioSink instance.

You are not advised to call this function after [OH_LowPowerAudioSink_Start](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_start) or [OH_LowPowerAudioSink_Resume](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_resume).

Note that if the decoder has previously received data, you must input the codec data again.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Stop()

```
OH_AVErrCode OH_LowPowerAudioSink_Stop(OH_LowPowerAudioSink* sink)
```

**Description**

Stops an OH_LowPowerAudioSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Reset()

```
OH_AVErrCode OH_LowPowerAudioSink_Reset(OH_LowPowerAudioSink* sink)
```

**Description**

Resets an OH_LowPowerAudioSink instance.

To reuse the instance, you must call [OH_LowPowerAudioSink_Configure](capi-lowpower-audio-sink-h.md#oh_lowpoweraudiosink_configure) to configure the instance again.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_Destroy()

```
OH_AVErrCode OH_LowPowerAudioSink_Destroy(OH_LowPowerAudioSink* sink)
```

**Description**

Clears internal resources of an OH_LowPowerAudioSink instance and destroys the instance. You only need to call the function once.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_SetVolume()

```
OH_AVErrCode OH_LowPowerAudioSink_SetVolume(OH_LowPowerAudioSink* sink, const float volume)
```

**Description**

Sets the rendering volume for an OH_LowPowerAudioSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| const float volume | Rendering volume, in the range of [0.0, 1.0].|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_SetPlaybackSpeed()

```
OH_AVErrCode OH_LowPowerAudioSink_SetPlaybackSpeed(OH_LowPowerAudioSink* sink, const float speed)
```

**Description**

Sets the audio rendering speed for an OH_LowPowerAudioSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| const float speed | Audio rendering speed, in the range [0.25, 4.0].|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_ReturnSamples()

```
OH_AVErrCode OH_LowPowerAudioSink_ReturnSamples(OH_LowPowerAudioSink* sink, OH_AVSamplesBuffer* samples)
```

**Description**

Provides a buffer to an OH_LowPowerAudioSink instance for procesing.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| [OH_AVSamplesBuffer](capi-avsinkbase-oh-avsamplesbuffer.md)* samples | Pointer to the OH_AVSamplesBuffer instance to be provided. Batch input of samples is supported.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSink_RegisterCallback()

```
OH_AVErrCode OH_LowPowerAudioSink_RegisterCallback(OH_LowPowerAudioSink* sink, OH_LowPowerAudioSinkCallback* callback)
```

**Description**

Registers a callback for an OH_LowPowerAudioSink instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSink](capi-lowpoweraudiosink-oh-lowpoweraudiosink.md)* sink | Pointer to an OH_LowPowerAudioSink instance.|
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_SERVICE_DIED**: The media server is destroyed.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSinkCallback_Create()

```
OH_LowPowerAudioSinkCallback* OH_LowPowerAudioSinkCallback_Create(void)
```

**Description**

Creates an OH_LowPowerAudioSinkCallback instance.

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* | Pointer to the OH_LowPowerAudioSinkCallback instance created. If the memory is insufficient, nullptr is returned.|

### OH_LowPowerAudioSinkCallback_Destroy()

```
OH_AVErrCode OH_LowPowerAudioSinkCallback_Destroy(OH_LowPowerAudioSinkCallback* callback)
```

**Description**

Destroys an OH_LowPowerAudioSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.|

### OH_LowPowerAudioSinkCallback_SetPositionUpdateListener()

```
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetPositionUpdateListener(OH_LowPowerAudioSinkCallback* callback,OH_LowPowerAudioSink_OnPositionUpdated onPositionUpdated,void* userData)
```

**Description**

Sets a progress update listener for an OH_LowPowerAudioSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|
| [OH_LowPowerAudioSink_OnPositionUpdated](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_onpositionupdated) onPositionUpdated | OH_LowPowerAudioSink_OnPositionUpdated, which is invoked when the playback position is updated in the OH_LowPowerAudioSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSinkCallback_SetDataNeededListener()

```
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetDataNeededListener(OH_LowPowerAudioSinkCallback* callback,OH_LowPowerAudioSink_OnDataNeeded onDataNeeded,void* userData)
```

**Description**

Sets a data needed listener for an OH_LowPowerAudioSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|
| [OH_LowPowerAudioSink_OnDataNeeded](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondataneeded) onDataNeeded | OH_LowPowerAudioSink_OnDataNeeded, which is invoked when the OH_LowPowerAudioSink instance needs more data.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSinkCallback_SetErrorListener()

```
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetErrorListener(OH_LowPowerAudioSinkCallback* callback,OH_LowPowerAudioSink_OnError onError,void* userData)
```

**Description**

Sets an error listener for an OH_LowPowerAudioSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|
| [OH_LowPowerAudioSink_OnError](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_onerror) onError | OH_LowPowerAudioSink_OnError, which is invoked when an error occurs in the OH_LowPowerAudioSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSinkCallback_SetInterruptListener()

```
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetInterruptListener(OH_LowPowerAudioSinkCallback* callback,OH_LowPowerAudioSink_OnInterrupted onInterrupted,void* userData)
```

**Description**

Sets an audio focus interruption listener for an OH_LowPowerAudioSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|
| [OH_LowPowerAudioSink_OnInterrupted](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_oninterrupted) onInterrupted | OH_LowPowerAudioSink_OnInterrupted, which is invoked when the audio focus is interrupted in the OH_LowPowerAudioSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSinkCallback_SetDeviceChangeListener()

```
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetDeviceChangeListener(OH_LowPowerAudioSinkCallback* callback,OH_LowPowerAudioSink_OnDeviceChanged onDeviceChanged,void* userData)
```

**Description**

Sets an audio device change listener for an OH_LowPowerAudioSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md)* callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|
| [OH_LowPowerAudioSink_OnDeviceChanged](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_ondevicechanged) onDeviceChanged | OH_LowPowerAudioSink_OnDeviceChanged, which is invoked when the audio device changes in the OH_LowPowerAudioSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|

### OH_LowPowerAudioSinkCallback_SetEosListener()

```
OH_AVErrCode OH_LowPowerAudioSinkCallback_SetEosListener(OH_LowPowerAudioSinkCallback *callback,OH_LowPowerAudioSink_OnEos onEos,void* userData)
```

**Description**

Sets an end-of-stream listener for an OH_LowPowerAudioSinkCallback instance.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_LowPowerAudioSinkCallback](capi-lowpoweraudiosink-oh-lowpoweraudiosinkcallback.md) *callback | Pointer to an OH_LowPowerAudioSinkCallback instance.|
| [OH_LowPowerAudioSink_OnEos](capi-lowpower-audio-sink-base-h.md#oh_lowpoweraudiosink_oneos) onEos | OH_LowPowerAudioSink_OnEos, which is invoked when playback is complete in the OH_LowPowerAudioSink instance.|
| void* userData | Pointer to the data on which the caller depends when executing the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: An input parameter is nullptr or invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not supported.|
