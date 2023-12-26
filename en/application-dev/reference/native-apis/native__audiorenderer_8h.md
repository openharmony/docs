# native_audiorenderer.h


## Overview

The **native_audiorenderer.h** file declares the functions related to an audio renderer.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioRenderer_Release](_o_h_audio.md#oh_audiorenderer_release) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Releases an audio renderer.| 
| [OH_AudioRenderer_Start](_o_h_audio.md#oh_audiorenderer_start) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Starts an audio renderer.| 
| [OH_AudioRenderer_Pause](_o_h_audio.md#oh_audiorenderer_pause) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Pauses an audio renderer.| 
| [OH_AudioRenderer_Stop](_o_h_audio.md#oh_audiorenderer_stop) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Stops an audio renderer.| 
| [OH_AudioRenderer_Flush](_o_h_audio.md#oh_audiorenderer_flush) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Flushes written audio data.| 
| [OH_AudioRenderer_GetCurrentState](_o_h_audio.md#oh_audiorenderer_getcurrentstate) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) \*state) | Obtains the state of an audio renderer.| 
| [OH_AudioRenderer_GetSamplingRate](_o_h_audio.md#oh_audiorenderer_getsamplingrate) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*rate) | Obtains the sampling rate of an audio renderer.| 
| [OH_AudioRenderer_GetStreamId](_o_h_audio.md#oh_audiorenderer_getstreamid) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, uint32_t \*streamId) | Obtains the stream ID of an audio renderer.| 
| [OH_AudioRenderer_GetChannelCount](_o_h_audio.md#oh_audiorenderer_getchannelcount) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*channelCount) | Obtains the number of channels for an audio renderer.| 
| [OH_AudioRenderer_GetSampleFormat](_o_h_audio.md#oh_audiorenderer_getsampleformat) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio renderer.| 
| [OH_AudioRenderer_GetLatencyMode](_o_h_audio.md#oh_audiorenderer_getlatencymode) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) \*latencyMode) | Obtains the latency mode of an audio renderer.| 
| [OH_AudioRenderer_GetRendererInfo](_o_h_audio.md#oh_audiorenderer_getrendererinfo) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) \*usage) | Obtains the usage scenario of an audio renderer.| 
| [OH_AudioRenderer_GetEncodingType](_o_h_audio.md#oh_audiorenderer_getencodingtype) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio renderer.| 
| [OH_AudioRenderer_GetFramesWritten](_o_h_audio.md#oh_audiorenderer_getframeswritten) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int64_t \*frames) | Obtains the number of frames that have been written since the stream was created.| 
| [OH_AudioRenderer_GetTimestamp](_o_h_audio.md#oh_audiorenderer_gettimestamp) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | Obtains the timestamp and position information of an output audio stream.| 
| [OH_AudioRenderer_GetFrameSizeInCallback](_o_h_audio.md#oh_audiorenderer_getframesizeincallback) ([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*frameSize) | Obtains the frame size in the callback.| 
