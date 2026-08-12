# native_audiostreambuilder.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the functions related to an audio stream builder.<br>You can use the functions to create and destroy an audio stream builder, set audio stream attributes, and set callbacks.

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
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetSampleFormat(OH_AudioStreamBuilder* builder, OH_AudioStream_SampleFormat format)](#oh_audiostreambuilder_setsampleformat) | Sets the sampling format of an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetEncodingType(OH_AudioStreamBuilder* builder, OH_AudioStream_EncodingType encodingType)](#oh_audiostreambuilder_setencodingtype) | Sets the encoding type of an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetLatencyMode(OH_AudioStreamBuilder* builder, OH_AudioStream_LatencyMode latencyMode)](#oh_audiostreambuilder_setlatencymode) | Sets the latency mode of an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout(OH_AudioStreamBuilder* builder, OH_AudioChannelLayout channelLayout)](#oh_audiostreambuilder_setchannellayout) | Sets the channel layout for an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder, OH_AudioStream_Usage usage)](#oh_audiostreambuilder_setrendererinfo) | Sets the usage scenario of an audio renderer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetVolumeMode(OH_AudioStreamBuilder* builder, OH_AudioStream_VolumeMode volumeMode)](#oh_audiostreambuilder_setvolumemode) | Sets the volume mode for an audio stream.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder* builder, OH_AudioStream_SourceType sourceType)](#oh_audiostreambuilder_setcapturerinfo) | Sets the usage scenario of an audio capturer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder* builder, OH_AudioRenderer_Callbacks callbacks, void* userData)](#oh_audiostreambuilder_setrenderercallback) | Sets callbacks for an audio renderer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback(OH_AudioStreamBuilder* builder, OH_AudioRenderer_OutputDeviceChangeCallback callback, void* userData)](#oh_audiostreambuilder_setrendereroutputdevicechangecallback) | Sets the callback for audio renderer device change events.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererPrivacy(OH_AudioStreamBuilder* builder, OH_AudioStream_PrivacyType privacy)](#oh_audiostreambuilder_setrendererprivacy) | Sets the privacy type for the audio stream being played. The privacy type specifies whether the audio stream can be recorded by other applications.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_Callbacks callbacks, void* userData)](#oh_audiostreambuilder_setcapturercallback) | Sets callbacks for an audio capturer.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback(OH_AudioStreamBuilder* builder, OH_AudioRenderer_WriteDataWithMetadataCallback callback, void* userData)](#oh_audiostreambuilder_setwritedatawithmetadatacallback) | Sets the callback used to write both audio data and metadata.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_GenerateRenderer(OH_AudioStreamBuilder* builder, OH_AudioRenderer** audioRenderer)](#oh_audiostreambuilder_generaterenderer) | Creates an audio renderer instance.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_GenerateCapturer(OH_AudioStreamBuilder* builder, OH_AudioCapturer** audioCapturer)](#oh_audiostreambuilder_generatecapturer) | Creates an audio capturer instance.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder* builder, int32_t frameSize)](#oh_audiostreambuilder_setframesizeincallback) | Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptMode(OH_AudioStreamBuilder* builder, OH_AudioInterrupt_Mode mode)](#oh_audiostreambuilder_setrendererinterruptmode) | Sets the interrupt mode of the stream client.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallback(OH_AudioStreamBuilder* builder, OH_AudioRenderer_OnWriteDataCallback callback, void* userData)](#oh_audiostreambuilder_setrendererwritedatacallback) | Sets the callback used to write audio data.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced(OH_AudioStreamBuilder* builder, OH_AudioRenderer_OnWriteDataCallbackAdvanced callback, void* userData)](#oh_audiostreambuilder_setrendererwritedatacallbackadvanced) | Sets the callback used to write audio data.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback).<br>If both the functions are used, only the last callback takes effect.<br>Unlike **OH_AudioStreamBuilder_SetRendererWriteDataCallback**, **OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced** allows an application to pass variable-length audio data and notify the system of the length of the data written.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptCallback(OH_AudioStreamBuilder* builder, OH_AudioRenderer_OnInterruptCallback callback, void* userData)](#oh_audiostreambuilder_setrendererinterruptcallback) | Sets the callback for interruption events of an audio renderer.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererErrorCallback(OH_AudioStreamBuilder* builder, OH_AudioRenderer_OnErrorCallback callback, void* userData)](#oh_audiostreambuilder_setrenderererrorcallback) | Sets the callback for error events of an audio renderer.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerReadDataCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_OnReadDataCallback callback, void* userData)](#oh_audiostreambuilder_setcapturerreaddatacallback) | Sets the callback used to read data for an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_OnDeviceChangeCallback callback, void* userData)](#oh_audiostreambuilder_setcapturerdevicechangecallback) | Sets the callback for audio capturer device change events.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInterruptCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_OnInterruptCallback callback, void* userData)](#oh_audiostreambuilder_setcapturerinterruptcallback) | Sets the callback for interruption events of an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerErrorCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_OnErrorCallback callback, void* userData)](#oh_audiostreambuilder_setcapturererrorcallback) | Sets the callback for error events of an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerWillMuteWhenInterrupted(OH_AudioStreamBuilder* builder, bool muteWhenInterrupted)](#oh_audiostreambuilder_setcapturerwillmutewheninterrupted) | Sets whether to mute the audio input stream when an audio interruption occurs.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererFastStatusChangeCallback(OH_AudioStreamBuilder* builder, OH_AudioRenderer_OnFastStatusChange callback, void* userData)](#oh_audiostreambuilder_setrendererfaststatuschangecallback) | Sets a callback for low-latency status changes during audio playback.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerFastStatusChangeCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_OnFastStatusChange callback, void* userData)](#oh_audiostreambuilder_setcapturerfaststatuschangecallback) | Sets a callback for low-latency status changes during audio recording.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerLoopbackEffectEnabled(OH_AudioStreamBuilder* builder, bool enabled)](#oh_audiostreambuilder_setcapturerloopbackeffectenabled) | Sets whether the audio recording stream captures audio data with reverb effects. When audio loopback is set to hardware mode and reverb is enabled, the low-latency capturer can acquire recorded data with reverb effects.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetPlaybackCaptureMode(OH_AudioStreamBuilder* builder, uint32_t mode)](#oh_audiostreambuilder_setplaybackcapturemode) | Sets the audio modes for internal audio recording (capturing sound from the applications on the device). The modes determine the types of audio streams to be recorded. This function applies only to [AudioStream_Type_Capturer](./capi-native-audiostream-base-h.md#oh_audiostream_type). This API is not currently supported for external use.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetSensitiveRecordPermitCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_SensitiveRecordPermitCallback callback, void* userData)](#oh_audiostreambuilder_setsensitiverecordpermitcallback) | Sets the callback function for when the risk warning prompt finishes playing in the cellular call downlink recording scenario. This function needs to be set only when [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype).AUDIOSTREAM_SOURCE_TYPE_VOICE_DOWNLINK is used for recording. This callback must be set successfully. Otherwise, the audio capturer cannot be created. After the audio capturer is created, the risk warning prompt will be automatically added to the voice data sent to the call recipient. Your app should start the audio capturer after receiving the callback result. Otherwise, [OH_AudioCapturer_Start](capi-native-audiocapturer-h.md#oh_audiocapturer_start) will return an error. Ensure that the audio capturer is created after the cellular call starts. Otherwise, [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer) will return an error.|
| [OH_AudioStream_Result OH_AudioStreamBuilder_SetCellularRecordSecurityParams(OH_AudioStreamBuilder* builder, const char* cellularRecordPhoneNum, const char* cellularRecordToken)](#oh_audiostreambuilder_setcellularrecordsecurityparams) | Sets the phone number and security token for cellular call downlink recording. This function needs to be set only when [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype).AUDIOSTREAM_SOURCE_TYPE_VOICE_DOWNLINK is used for recording. The phone number and security token are used to verify whether the cellular call downlink capturer matches the corresponding cellular call. They must be set successfully. Otherwise, the capturer cannot be created.|

## Function Description

### OH_AudioStreamBuilder_Create()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_Create(OH_AudioStreamBuilder** builder, OH_AudioStream_Type type)
```

**Description**

Creates an audio stream builder, which can be an audio renderer or capturer.<br>You need to call [OH_AudioStreamBuilder_Destroy](#oh_audiostreambuilder_destroy) to destroy the builder when it is no longer required.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)** builder | Pointer to the created builder instance.|
| [OH_AudioStream_Type](capi-native-audiostream-base-h.md#oh_audiostream_type) type | Type of the audio stream builder, which can be AUDIOSTREAM_TYPE_RENDERER or AUDIOSTREAM_TYPE_CAPTURER.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.|

### OH_AudioStreamBuilder_Destroy()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_Destroy(OH_AudioStreamBuilder* builder)
```

**Description**

Destroys an audio stream builder.<br>You need to call this function to destroy the builder when it is no longer required.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.<br>        **AUDIOSTREAM_ERROR_ILLEGAL_STATE**: The execution status is abnormal.|

### OH_AudioStreamBuilder_SetSamplingRate()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **rate** parameter is invalid.|

### OH_AudioStreamBuilder_SetChannelCount()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **channelCount** parameter is invalid.|

### OH_AudioStreamBuilder_SetSampleFormat()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetEncodingType()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetLatencyMode()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetChannelLayout()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetChannelLayout(OH_AudioStreamBuilder* builder,OH_AudioChannelLayout channelLayout)
```

**Description**

Sets the channel layout for an audio stream.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioChannelLayout](../apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout) channelLayout | Channel layout.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererInfo()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInfo(OH_AudioStreamBuilder* builder,OH_AudioStream_Usage usage)
```

**Description**

Sets the usage scenario of an audio renderer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_Usage](capi-native-audiostream-base-h.md#oh_audiostream_usage) usage | Usage scenario of the output audio stream.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **usage** parameter is invalid.|

### OH_AudioStreamBuilder_SetVolumeMode()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetVolumeMode(OH_AudioStreamBuilder* builder,OH_AudioStream_VolumeMode volumeMode)
```

**Description**

Sets the volume mode for an audio stream.

**Since**: 19

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_VolumeMode](capi-native-audiostream-base-h.md#oh_audiostream_volumemode) volumeMode | Volume mode of the audio stream.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **volumeMode** parameter is invalid.|

### OH_AudioStreamBuilder_SetCapturerInfo()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInfo(OH_AudioStreamBuilder* builder,OH_AudioStream_SourceType sourceType)
```

**Description**

Sets the usage scenario of an audio capturer.

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype) sourceType | Usage scenario of the input audio stream.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **sourceType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_Callbacks callbacks, void* userData)
```

**Description**

Sets callbacks for an audio renderer.

**Since**: 10

**Deprecated from**: 20

**Substitute**

Use the following APIs for substitute:<br>[OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback), [OH_AudioStreamBuilder_SetRendererInterruptCallback](#oh_audiostreambuilder_setrendererinterruptcallback), [OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback](#oh_audiostreambuilder_setrendereroutputdevicechangecallback), and [OH_AudioStreamBuilder_SetRendererErrorCallback](#oh_audiostreambuilder_setrenderererrorcallback)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_Callbacks](capi-ohaudio-oh-audiorenderer-callbacks-struct.md) callbacks | Callbacks that will be used to process events related to audio output streams.|
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererOutputDeviceChangeCallback()

```c
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
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererPrivacy()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetCapturerCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_Callbacks callbacks, void* userData)
```

**Description**

Sets callbacks for an audio capturer.

**Since**: 10

**Deprecated from**: 20

**Substitute**

Use the following APIs for substitute:<br>[OH_AudioStreamBuilder_SetCapturerReadDataCallback](#oh_audiostreambuilder_setcapturerreaddatacallback), [OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback](#oh_audiostreambuilder_setcapturerdevicechangecallback), [OH_AudioStreamBuilder_SetCapturerInterruptCallback](#oh_audiostreambuilder_setcapturerinterruptcallback), and [OH_AudioStreamBuilder_SetCapturerErrorCallback](#oh_audiostreambuilder_setcapturererrorcallback)


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioCapturer_Callbacks](capi-ohaudio-oh-audiocapturer-callbacks-struct.md) callbacks | Callbacks that will be used to process events related to audio input streams.|
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetWriteDataWithMetadataCallback()

```c
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
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_GenerateRenderer()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.<br>                                                3. The OHAudioRenderer instance fails to be created.|

### OH_AudioStreamBuilder_GenerateCapturer()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.<br>                                                3. The OHAudioCapturer instance fails to be created.|

### OH_AudioStreamBuilder_SetFrameSizeInCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetFrameSizeInCallback(OH_AudioStreamBuilder* builder,int32_t frameSize)
```

**Description**

Sets the frame size for each callback during playback. The frame size must be at least equal to the size of the data processed by the audio hardware at a time and less than half of the internal buffer capacity.<br>In the case of low-latency playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 5 ms, 10 ms, 15 ms, or 20 ms.<br>In the case of common playback, **frameSize** can be set to the frame length corresponding to the audio that lasts for 20 ms to 100 ms. For example, if the sampling rate is 48000 Hz, the frame length of 20 ms audio data is calculated as follows: frameSize = 48000 x 0.02, that is, 960 sampling points. When **frameSize** is **960**, the corresponding data callback length is 960 × channel count × sample bit width (in bytes). For example, for a 2-channel 16-bit format, the length is 960 × 2 × 2 = 3840.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| int32_t frameSize | Frame size.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererInterruptMode()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **mode** parameter is invalid.<br>                                                3. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererWriteDataCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnWriteDataCallback callback, void* userData)
```

**Description**

Sets the callback used to write audio data.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OnWriteDataCallback](capi-native-audiostream-base-h.md#oh_audiorenderer_onwritedatacallback) callback | Callback to be used to write audio data.|
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**:<br>                                                1. The **builder** parameter is nullptr.<br>                                                2. The **StreamType** parameter is invalid.|

### OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnWriteDataCallbackAdvanced callback, void* userData)
```

**Description**

Sets the callback used to write audio data.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererWriteDataCallback](#oh_audiostreambuilder_setrendererwritedatacallback).<br>If both the functions are used, only the last callback takes effect.<br>Unlike **OH_AudioStreamBuilder_SetRendererWriteDataCallback**, **OH_AudioStreamBuilder_SetRendererWriteDataCallbackAdvanced** allows an application to pass variable-length audio data and notify the system of the length of the data written.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| [OH_AudioRenderer_OnWriteDataCallbackAdvanced](capi-native-audiorenderer-h.md#oh_audiorenderer_onwritedatacallbackadvanced) callback | Callback to be used to write audio data.|
| void* userData | Pointer to the application data passed through the callbacks.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: An input parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererInterruptCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererInterruptCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnInterruptCallback callback, void* userData)
```

**Description**

Sets the callback for interruption events of an audio renderer.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.

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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererErrorCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetRendererErrorCallback(OH_AudioStreamBuilder* builder,OH_AudioRenderer_OnErrorCallback callback, void* userData)
```

**Description**

Sets the callback for error events of an audio renderer.<br>This function is similar to [OH_AudioStreamBuilder_SetRendererCallback](#oh_audiostreambuilder_setrenderercallback). If both the functions are used, only the last callback takes effect.

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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerReadDataCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerReadDataCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnReadDataCallback callback, void* userData)
```

**Description**

Sets the callback used to read data for an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerDeviceChangeCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnDeviceChangeCallback callback, void* userData)
```

**Description**

Sets the callback for audio capturer device change events.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerInterruptCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerInterruptCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnInterruptCallback callback, void* userData)
```

**Description**

Sets the callback for interruption events of an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerErrorCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerErrorCallback(OH_AudioStreamBuilder* builder,OH_AudioCapturer_OnErrorCallback callback, void* userData)
```

**Description**

Sets the callback for error events of an audio capturer.<br>This function is similar to [OH_AudioStreamBuilder_SetCapturerCallback](#oh_audiostreambuilder_setcapturercallback). If both the functions are used, only the last callback takes effect.

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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerWillMuteWhenInterrupted()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerWillMuteWhenInterrupted(OH_AudioStreamBuilder* builder,bool muteWhenInterrupted)
```

**Description**

Sets whether to mute the audio input stream when an audio interruption occurs.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to an audio stream builder instance, which is created by calling [OH_AudioStreamBuilder_Create](#oh_audiostreambuilder_create).|
| bool muteWhenInterrupted | Whether to mute the audio stream when an audio interruption occurs. **true** to mute, **false** otherwise (default interruption mode used).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetRendererFastStatusChangeCallback()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerFastStatusChangeCallback()

```c
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
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>        **AUDIOSTREAM_ERROR_INVALID_PARAM**: A parameter is invalid. For example, the **builder** parameter is nullptr.|

### OH_AudioStreamBuilder_SetCapturerLoopbackEffectEnabled()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCapturerLoopbackEffectEnabled(OH_AudioStreamBuilder* builder, bool enabled)
```

**Description**

Sets whether the audio recording stream captures audio data with reverb effects. When audio loopback is set to hardware mode and reverb is enabled, the low-latency capturer can acquire recorded data with reverb effects.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to a builder instance created by [OH_AudioStreamBuilder_Create](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_create).|
| bool enabled | Whether the app captures audio data with reverb effects. The value **true** indicates yes, and the value **false** indicates no.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: Invalid parameters. For example, **builder** is nullptr.|

### OH_AudioStreamBuilder_SetPlaybackCaptureMode()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetPlaybackCaptureMode(OH_AudioStreamBuilder* builder, uint32_t mode)
```

**Description**

Sets the audio modes for internal audio recording (capturing sound from the applications on the device). The modes determine the types of audio streams to be recorded. This function applies only to [AudioStream_Type_Capturer](./capi-native-audiostream-base-h.md#oh_audiostream_type). This API is not currently supported for external use.

**Since**: 23

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to a builder instance created by [OH_AudioStreamBuilder_Create](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_create).|
| uint32_t mode | Internal audio recording modes to be set. The value can be a combination of multiple values in [OH_AudioStream_PlaybackCaptureMode](capi-native-audiostream-base-h.md#oh_audiostream_playbackcapturemode).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | **AUDIOSTREAM_SUCCESS**: The function is executed successfully.<br>         **AUDIOSTREAM_ERROR_INVALID_PARAM**: Invalid parameters. For example, **builder** is a null pointer or the value of **mode** is invalid.|

### OH_AudioStreamBuilder_SetSensitiveRecordPermitCallback()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetSensitiveRecordPermitCallback(OH_AudioStreamBuilder* builder, OH_AudioCapturer_SensitiveRecordPermitCallback callback, void* userData)
```

**Description**

Sets the callback function for when the risk warning prompt finishes playing in the cellular call downlink recording scenario. This function needs to be set only when [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype).AUDIOSTREAM_SOURCE_TYPE_VOICE_DOWNLINK is used for recording. This callback must be set successfully. Otherwise, the audio capturer cannot be created. After the audio capturer is created, the risk warning prompt will be automatically added to the voice data sent to the call recipient. Your app should start the audio capturer after receiving the callback result. Otherwise, [OH_AudioCapturer_Start](capi-native-audiocapturer-h.md#oh_audiocapturer_start) will return an error. Ensure that the audio capturer is created after the cellular call starts. Otherwise, [OH_AudioStreamBuilder_GenerateCapturer](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_generatecapturer) will return an error.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to a builder instance created by [OH_AudioStreamBuilder_Create](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_create).|
| OH_AudioCapturer_SensitiveRecordPermitCallback callback | Callback function used to receive the notification when the risk warning prompt finishes playing. It must not be a null pointer.|
| void* userData | Pointer to user data, which will be passed to the app in the callback. If no data needs to be passed, you can pass a null pointer. If it is not a null pointer, the caller should verify that the data is still valid when the callback is received.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | <ul><br>         <li>**AUDIOSTREAM_SUCCESS**: The function is executed successfully.</li><br>         <li>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder** or **callback** parameter is a null pointer.</li><br>         </ul> |

### OH_AudioStreamBuilder_SetCellularRecordSecurityParams()

```c
OH_AudioStream_Result OH_AudioStreamBuilder_SetCellularRecordSecurityParams(OH_AudioStreamBuilder* builder, const char* cellularRecordPhoneNum, const char* cellularRecordToken)
```

**Description**

Sets the phone number and security token for cellular call downlink recording. This function needs to be set only when [OH_AudioStream_SourceType](capi-native-audiostream-base-h.md#oh_audiostream_sourcetype).AUDIOSTREAM_SOURCE_TYPE_VOICE_DOWNLINK is used for recording. The phone number and security token are used to verify whether the cellular call downlink capturer matches the corresponding cellular call. They must be set successfully. Otherwise, the capturer cannot be created.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioStreamBuilder](capi-ohaudio-oh-audiostreambuilderstruct.md)* builder | Pointer to a builder instance created by [OH_AudioStreamBuilder_Create](capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_create).|
| const char* cellularRecordPhoneNum | Phone number of the target cellular call, which is used in **makeCallWithToken()**. This parameter cannot be a null pointer.|
| const char* cellularRecordToken | Security token of the target cellular call, which can be obtained via **makeCallWithToken()** of the call management module. This parameter cannot be a null pointer.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AudioStream_Result](capi-native-audiostream-base-h.md#oh_audiostream_result) | <ul><br>         <li>**AUDIOSTREAM_SUCCESS**: The function is executed successfully.</li><br>         <li>**AUDIOSTREAM_ERROR_INVALID_PARAM**: The **builder**, **cellularRecordPhoneNum**, or **cellularRecordToken** parameter is a null pointer.</li><br>         </ul> |
