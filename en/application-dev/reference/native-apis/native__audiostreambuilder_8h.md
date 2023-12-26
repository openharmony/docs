# native_audiostreambuilder.h


## Overview

The **native_audiostreambuilder.h** file declares the functions related to the audio stream builder.

You can use the functions to create and destroy an audio stream builder, set audio stream attributes, and set callbacks.

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioStreamBuilder_Create](_o_h_audio.md#oh_audiostreambuilder_create) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*\*builder, [OH_AudioStream_Type](_o_h_audio.md#oh_audiostream_type) type) | Creates an audio stream builder, which can be an audio renderer or capturer.| 
| [OH_AudioStreamBuilder_Destroy](_o_h_audio.md#oh_audiostreambuilder_destroy) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder) | Destroys an audio stream builder.| 
| [OH_AudioStreamBuilder_SetSamplingRate](_o_h_audio.md#oh_audiostreambuilder_setsamplingrate) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, int32_t rate) | Sets the sampling rate of an audio stream.| 
| [OH_AudioStreamBuilder_SetChannelCount](_o_h_audio.md#oh_audiostreambuilder_setchannelcount) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, int32_t channelCount) | Sets the number of channels for an audio stream.| 
| [OH_AudioStreamBuilder_SetSampleFormat](_o_h_audio.md#oh_audiostreambuilder_setsampleformat) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) format) | Sets the sampling format of an audio stream.| 
| [OH_AudioStreamBuilder_SetEncodingType](_o_h_audio.md#oh_audiostreambuilder_setencodingtype) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) encodingType) | Sets the encoding type of an audio stream.| 
| [OH_AudioStreamBuilder_SetLatencyMode](_o_h_audio.md#oh_audiostreambuilder_setlatencymode) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) latencyMode) | Sets the latency mode of an audio stream.| 
| [OH_AudioStreamBuilder_SetRendererInfo](_o_h_audio.md#oh_audiostreambuilder_setrendererinfo) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) usage) | Sets the usage scenario of an audio renderer.| 
| [OH_AudioStreamBuilder_SetCapturerInfo](_o_h_audio.md#oh_audiostreambuilder_setcapturerinfo) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioStream_SourceType](_o_h_audio.md#oh_audiostream_sourcetype) sourceType) | Sets the usage scenario of an audio capturer.| 
| [OH_AudioStreamBuilder_SetRendererCallback](_o_h_audio.md#oh_audiostreambuilder_setrenderercallback) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioRenderer_Callbacks](_o_h_audio.md#oh_audiorenderer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio renderer.| 
| [OH_AudioStreamBuilder_SetCapturerCallback](_o_h_audio.md#oh_audiostreambuilder_setcapturercallback) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioCapturer_Callbacks](_o_h_audio.md#oh_audiocapturer_callbacks) callbacks, void \*userData) | Sets callbacks for an audio capturer.| 
| [OH_AudioStreamBuilder_GenerateRenderer](_o_h_audio.md#oh_audiostreambuilder_generaterenderer) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*\*audioRenderer) | Creates an audio renderer instance.| 
| [OH_AudioStreamBuilder_GenerateCapturer](_o_h_audio.md#oh_audiostreambuilder_generatecapturer) ([OH_AudioStreamBuilder](_o_h_audio.md#oh_audiostreambuilder) \*builder, [OH_AudioCapturer](_o_h_audio.md#oh_audiocapturer) \*\*audioCapturer) | Creates an audio capturer instance.| 
