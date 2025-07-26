# native_audiostreambuilder.h

## Overview

The file declares the functions related to an audio stream builder.

You can use the functions to create and destroy an audio stream builder, set audio stream attributes, and set callbacks.

**File to include**: <ohaudio/native_audiostreambuilder.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder** builder, OH_AudioStream_Type type)](#oh_audiostreambuilder_create) | Creates an audio stream builder, which can be an audio renderer or capturer.<br>You need to call [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy) to destroy the builder when it is no longer required.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder* builder)](#oh_audiostreambuilder_destroy) | Destroys an audio stream builder.<br>You need to call this function to destroy the builder when it is no longer required.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate(OH_AudioStreamBuilder* builder, int32_t rate)](#oh_audiostreambuilder_setsamplingrate) | Sets the sampling rate of an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount(OH_AudioStreamBuilder* builder, int32_t channelCount)](#oh_audiostreambuilder_setchannelcount) | Sets the number of channels for an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder* builder,OH_AudioStream_SampleFormat format)](#oh_audiostreambuilder_setsampleformat) | Sets the sampling format of an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder* builder,OH_AudioStream_EncodingType encodingType)](#oh_audiostreambuilder_setencodingtype) | Sets the encoding type of an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder* builder,OH_AudioStream_LatencyMode latencyMode)](#oh_audiostreambuilder_setlatencymode) | Sets the latency mode of an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout(OH_AudioStreamBuilder* builder,OH_AudioChannelLayout channelLayout)](#oh_audiostreambuilder_setchannellayout) | Sets the channel layout for an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,OH_AudioStream_Usage usage)](#oh_audiostreambuilder_setrendererinfo) | Sets the usage scenario of an audio renderer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetVolumeMode(OH_AudioStreamBuilder* builder,OH_AudioStream_VolumeMode volumeMode)](#oh_audiostreambuilder_setvolumemode) | Sets the volume mode for an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder* builder,OH_AudioStream_SourceType sourceType)](#oh_audiostreambuilder_setcapturerinfo) | Sets the usage scenario of an audio capturer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_Callbacks callbacks, void* userData)](#oh_audiostreambuilder_setrenderercallback) | Sets callbacks for an audio renderer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OutputDeviceChangeCallback callback, void* userData)](#oh_audiostreambuilder_setrendereroutputdevicechangecallback) | Sets the callback for audio renderer device change events.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererPrivacy(OH_AudioStreamBuilder* builder,OH_AudioStream_PrivacyType privacy)](#oh_audiostreambuilder_setrendererprivacy) | Sets the privacy type for the audio stream being played. The privacy type specifies whether the audio stream can be recorded by other applications.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_Callbacks callbacks, void* userData)](#oh_audiostreambuilder_setcapturercallback) | Sets callbacks for an audio capturer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_WriteDataWithMetadataCallback callback, void* userData)](#oh_audiostreambuilder_setwritedatawithmetadatacallback) | Sets the callback used to write both audio data and metadata.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder* builder,OH_AudioRenderer** audioRenderer)](#oh_audiostreambuilder_generaterenderer) | Creates an audio renderer instance.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder* builder,OH_AudioCapturer** audioCapturer)](#oh_audiostreambuilder_generatecapturer) | Creates an audio capturer instance.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder* builder,int32_t frameSize)](#oh_audiostreambuilder_setframesizeincallback) | Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptMode(OH_AudioStreamBuilder* builder,OH_AudioInterrupt_Mode mode)](#oh_audiostreambuilder_setrendererinterruptmode) | Sets the interrupt mode of the stream client.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnWriteDataCallback callback, void* userData)](#oh_audiostreambuilder_setrendererwritedatacallback) | Sets the callback used to write audio data.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnWriteDataCallbackAdvanced callback, void* userData)](#oh_audiostreambuilder_setrendererwritedatacallbackadvanced) | Sets the callback used to write audio data.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback).<br>If both the functions are used, only the last callback takes effect.<br>Unlike **OH_AudioStreamBuilder_SetRendererWriteDataCallback**, **OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced** allows an application to pass variable-length audio data and notify the system of the length of the data written.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnInterruptCallback callback, void* userData)](#oh_audiostreambuilder_setrendererinterruptcallback) | Sets the callback for interruption events of an audio renderer.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererErrorCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnErrorCallback callback, void* userData)](#oh_audiostreambuilder_setrenderererrorcallback) | Sets the callback for error events of an audio renderer.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerReadDataCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnReadDataCallback callback, void* userData)](#oh_audiostreambuilder_setcapturerreaddatacallback) | Sets the callback used to read data for an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnDeviceChangeCallback callback, void* userData)](#oh_audiostreambuilder_setcapturerdevicechangecallback) | Sets the callback for audio capturer device change events.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInterruptCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnInterruptCallback callback, void* userData)](#oh_audiostreambuilder_setcapturerinterruptcallback) | Sets the callback for interruption events of an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerErrorCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnErrorCallback callback, void* userData)](#oh_audiostreambuilder_setcapturererrorcallback) | Sets the callback for error events of an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerWillMuteWhenInterrupted(OH_AudioStreamBuilder* builder,bool muteWhenInterrupted)](#oh_audiostreambuilder_setcapturerwillmutewheninterrupted) | Sets whether to mute the audio input stream when an audio interruption occurs.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererFastStatusChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnFastStatusChange callback, void* userData)](#oh_audiostreambuilder_setrendererfaststatuschangecallback) | Sets a callback for low-latency status changes during audio playback.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerFastStatusChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnFastStatusChange callback, void* userData)](#oh_audiostreambuilder_setcapturerfaststatuschangecallback) | Sets a callback for low-latency status changes during audio recording.|

## Function Description

### OH_AudioStreamBuilder_Create()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder** builder, OH_AudioStream_Type type)
```

**Description**

Creates an audio stream builder, which can be an audio renderer or capturer.

You need to call [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy) to destroy the builder when it is no longer required.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)** builder | Double pointer to the audio stream builder created.|
| [OH_AudioStream_Type](capi-native-audiostream-base-h.md#oh_audiostream_type) type | Type of the audio stream builder, which can be AUDIOSTREAM_TYPE_RENDERER or AUDIOSTREAM_TYPE_CAPTURER.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.|

### OH_AudioStreamBuilder_Destroy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder* builder)
```

**Description**

Destroys an audio stream builder.

You need to call this function to destroy the builder when it is no longer required.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.<br>**AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal. |

### OH_AudioStreamBuilder_SetSamplingRate()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSamplingRate(OH_AudioStreamBuilder* builder, int32_t rate)
```

**Description**

Sets the sampling rate of an audio stream.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| int32_t rate | Sampling rate.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **rate** parameter is invalid. |

### OH_AudioStreamBuilder_SetChannelCount()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelCount(OH_AudioStreamBuilder* builder, int32_t channelCount)
```

**Description**

Sets the number of channels for an audio stream.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| int32_t channelCount | Number of channels.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **channelCount** parameter is invalid.|

### OH_AudioStreamBuilder_SetSampleFormat()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder* builder,OH_AudioStream_SampleFormat format)
```

**Description**

Sets the sampling format of an audio stream.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_SampleFormat](capi-native-audiostream-base-h.md#oh_audiostream_sampleformat) format | Sampling format.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetEncodingType()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder* builder,OH_AudioStream_EncodingType encodingType)
```

**Description**

Sets the encoding type of an audio stream.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_EncodingType](capi-native-audiostream-base-h.md#oh_audiostream_encodingtype) encodingType | Encoding type.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetLatencyMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder* builder,OH_AudioStream_LatencyMode latencyMode)
```

**Description**

Sets the latency mode of an audio stream.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_LatencyMode](capi-native-audiostream-base-h.md#oh_audiostream_latencymode) latencyMode | Latency mode.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetChannelLayout()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout(OH_AudioStreamBuilder* builder,OH_AudioChannelLayout channelLayout)
```

**Description**

Sets the channel layout for an audio stream.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) channelLayout | Channel layout.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,OH_AudioStream_Usage usage)
```

**Description**

Sets the usage scenario of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage scenario of the audio renderer.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **usage** parameter is invalid.|

### OH_AudioStreamBuilder_SetVolumeMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetVolumeMode(OH_AudioStreamBuilder* builder,OH_AudioStream_VolumeMode volumeMode)
```

**Description**

Sets the volume mode for an audio stream.

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_VolumeMode](capi-native-audiostream-base-h.md#oh_audiostream_volumemode) volumeMode | Volume mode of the audio stream.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **volumeMode** parameter is invalid.|

### OH_AudioStreamBuilder_SetCapturerInfo()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder* builder,OH_AudioStream_SourceType sourceType)
```

**Description**

Sets the usage scenario of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) sourceType | Usage scenario of the audio capturer.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **sourceType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_Callbacks callbacks, void* userData)
```

**Description**

Sets callbacks for an audio renderer.

**Since**: 10

**Deprecated from**: 20

**Substitute**

Use the following APIs for substitute:

[OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback), [OH_AudioStreamBuilder_SetRendererInterruptCallback](#oh_audiostreambuilder_setrendererinterruptcallback), [OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback](#oh_audiostreambuilder_setrendereroutputdevicechangecallback), and [OH_AudioStreamBuilder_SetRendererErrorCallback](#oh_audiostreambuilder_setrenderererrorcallback)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_Callbacks](capi-ohaudio-oh-audiorenderer-callbacks-struct.md) callbacks | Callbacks that will be used to process events related to audio output streams.|
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OutputDeviceChangeCallback callback, void* userData)
```

**Description**

Sets the callback for audio renderer device change events.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OutputDeviceChangeCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_outputdevicechangecallback) callback | Callback that will be used to process events related to audio renderer device changes.|
| void* userData | Pointer to the application data passed through the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererPrivacy()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererPrivacy(OH_AudioStreamBuilder* builder,OH_AudioStream_PrivacyType privacy)
```

**Description**

Sets the privacy type for the audio stream being played. The privacy type specifies whether the audio stream can be recorded by other applications.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_PrivacyType](capi-native-audiostream-base-h.md#oh_audiostream_privacytype) privacy | Privacy type, which specifies whether the audio stream can be recorded by other applications.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetCapturerCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_Callbacks callbacks, void* userData)
```

**Description**

Sets callbacks for an audio capturer.

**Since**: 10

**Deprecated from**: 20

**Substitute**

Use the following APIs for substitute:

[OH_AudioStreamBuilder_SetCapturerReadDataCallback](#oh_audiostreambuilder_setcapturerreaddatacallback), [OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback](#oh_audiostreambuilder_setcapturerdevicechangecallback), [OH_AudioStreamBuilder_SetCapturerInterruptCallback](#oh_audiostreambuilder_setcapturerinterruptcallback), and [OH_AudioStreamBuilder_SetCapturerErrorCallback](#oh_audiostreambuilder_setcapturererrorcallback)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer_Callbacks](capi-ohaudio-oh-audiocapturer-callbacks-struct.md) callbacks | Callbacks that will be used to process events related to audio input streams.|
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_WriteDataWithMetadataCallback callback, void* userData)
```

**Description**

Sets the callback used to write both audio data and metadata.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_WriteDataWithMetadataCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_writedatawithmetadatacallback) callback | Callback used to write both audio data and metadata.|
| void* userData | Pointer to the application data passed through the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_GenerateRenderer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder* builder,OH_AudioRenderer** audioRenderer)
```

**Description**

Creates an audio renderer instance.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer](capi-ohaudio-oh-audiorendererstruct.md)** audioRenderer | Double pointer to the audio renderer instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.<br>3. The OHAudioRenderer instance fails to be created.|

### OH_AudioStreamBuilder_GenerateCapturer()

```
OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder* builder,OH_AudioCapturer** audioCapturer)
```

**Description**

Creates an audio capturer instance.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer](capi-ohaudio-oh-audiocapturerstruct.md)** audioCapturer | Double pointer to the audio capturer instance created.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.<br>3. The OHAudioCapturer instance fails to be created.|

### OH_AudioStreamBuilder_SetFrameSizeInCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder* builder,int32_t frameSize)
```

**Description**

Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity.

In the case of low-latency playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 5 ms, 10 ms, 15 ms, or 20 ms.

In the case of common playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 20 ms to 100 ms.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| int32_t frameSize | Frame size.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererInterruptMode()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptMode(OH_AudioStreamBuilder* builder,OH_AudioInterrupt_Mode mode)
```

**Description**

Sets the interrupt mode of the stream client.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioInterrupt_Mode](capi-native-audiostream-base-h.md#oh_audiointerrupt_mode) mode | Audio interruption mode.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **mode** parameter is invalid.<br>3. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererWriteDataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnWriteDataCallback callback, void* userData)
```

**Description**

Sets the callback used to write audio data.

This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OnWriteDataCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback) callback | Callback to be used to write audio data.|
| void* userData | Pointer to the application data passed through the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>1. The **builder** parameter is nullptr.<br>2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnWriteDataCallbackAdvanced callback, void* userData)
```

**Description**

Sets the callback used to write audio data.

This function is similar to [OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback).

If both the functions are used, only the last callback takes effect.

Unlike **OH_AudioStreamBuilder_SetRendererWriteDataCallback**, **OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced** allows an application to pass variable-length audio data and notify the system of the length of the data written.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OnWriteDataCallbackAdvanced](capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallbackadvanced) callback | Callback to be used to write audio data.|
| void* userData | Pointer to the application data passed through the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: An input parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererInterruptCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnInterruptCallback callback, void* userData)
```

**Description**

Sets the callback for interruption events of an audio renderer.

This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OnInterruptCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_oninterruptcallback) callback | Callback used to receive interruption events.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererErrorCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererErrorCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnErrorCallback callback, void* userData)
```

**Description**

Sets the callback for error events of an audio renderer.

This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OnErrorCallback](capi-native-audiorenderer-h.md#oh_audiorenderer_onerrorcallback) callback | Callback used to receive error events.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerReadDataCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerReadDataCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnReadDataCallback callback, void* userData)
```

**Description**

Sets the callback used to read data for an audio capturer.

This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer_OnReadDataCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onreaddatacallback) callback | Callback used to receive data read events.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnDeviceChangeCallback callback, void* userData)
```

**Description**

Sets the callback for audio capturer device change events.

This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer_OnDeviceChangeCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_ondevicechangecallback) callback | Callback used to receive device change events.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerInterruptCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInterruptCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnInterruptCallback callback, void* userData)
```

**Description**

Sets the callback for interruption events of an audio capturer.

This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer_OnInterruptCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_oninterruptcallback) callback | Callback used to receive interruption events.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerErrorCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerErrorCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnErrorCallback callback, void* userData)
```

**Description**

Sets the callback for error events of an audio capturer.

This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer_OnErrorCallback](capi-native-audiocapturer-h.md#oh_audiocapturer_onerrorcallback) callback | Callback used to receive error events.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerWillMuteWhenInterrupted()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerWillMuteWhenInterrupted(OH_AudioStreamBuilder* builder,bool muteWhenInterrupted)
```

**Description**

Sets whether to mute the audio input stream when an audio interruption occurs.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| bool muteWhenInterrupted | Whether to mute the audio stream when an audio interruption occurs. The value **true** means to mute the stream.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererFastStatusChangeCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererFastStatusChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnFastStatusChange callback, void* userData)
```

**Description**

Sets a callback for low-latency status changes during audio playback.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OnFastStatusChange](capi-native-audiorenderer-h.md#oh_audiorenderer_onfaststatuschange) callback | Callback invoked for low-latency status changes during audio playback.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerFastStatusChangeCallback()

```
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerFastStatusChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnFastStatusChange callback, void* userData)
```

**Description**

Sets a callback for low-latency status changes during audio recording.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer_OnFastStatusChange](capi-native-audiocapturer-h.md#oh_audiocapturer_onfaststatuschange) callback | Callback invoked for low-latency status changes during audio recording.|
| void* userData | Pointer to the application data struct that will be passed to the callback.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>**AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|
