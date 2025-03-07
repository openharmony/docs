# native_audiorenderer.h


## Overview

The **native_audiorenderer.h** file declares the functions related to an audio renderer.

**Library**: libohaudio.so

**File to include**: &lt;ohaudio/native_audiorenderer.h&gt;

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 10

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_Release](_o_h_audio.md#oh_audiorenderer_release)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Releases an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_Start](_o_h_audio.md#oh_audiorenderer_start)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Starts an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_Pause](_o_h_audio.md#oh_audiorenderer_pause)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Pauses an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_Stop](_o_h_audio.md#oh_audiorenderer_stop)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Stops an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_Flush](_o_h_audio.md#oh_audiorenderer_flush)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Flushes written audio data. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetCurrentState](_o_h_audio.md#oh_audiorenderer_getcurrentstate)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_State](_o_h_audio.md#oh_audiostream_state) \*state) | Obtains the state of an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetSamplingRate](_o_h_audio.md#oh_audiorenderer_getsamplingrate)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*rate) | Obtains the sampling rate of an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetStreamId](_o_h_audio.md#oh_audiorenderer_getstreamid)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, uint32_t \*streamId) | Obtains the stream ID of an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetChannelCount](_o_h_audio.md#oh_audiorenderer_getchannelcount)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*channelCount) | Obtains the number of channels for an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetSampleFormat](_o_h_audio.md#oh_audiorenderer_getsampleformat)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_SampleFormat](_o_h_audio.md#oh_audiostream_sampleformat) \*sampleFormat) | Obtains the sampling format of an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetLatencyMode](_o_h_audio.md#oh_audiorenderer_getlatencymode)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_LatencyMode](_o_h_audio.md#oh_audiostream_latencymode) \*latencyMode) | Obtains the latency mode of an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetRendererInfo](_o_h_audio.md#oh_audiorenderer_getrendererinfo)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_Usage](_o_h_audio.md#oh_audiostream_usage) \*usage) | Obtains the usage scenario of an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetEncodingType](_o_h_audio.md#oh_audiorenderer_getencodingtype)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_EncodingType](_o_h_audio.md#oh_audiostream_encodingtype) \*encodingType) | Obtains the encoding type of an audio renderer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetFramesWritten](_o_h_audio.md#oh_audiorenderer_getframeswritten)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int64_t \*frames) | Obtains the number of frames that have been written since the stream was created. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetTimestamp](_o_h_audio.md#oh_audiorenderer_gettimestamp)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, clockid_t clockId, int64_t \*framePosition, int64_t \*timestamp) | Obtains the timestamp and position information of an output audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetFrameSizeInCallback](_o_h_audio.md#oh_audiorenderer_getframesizeincallback)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, int32_t \*frameSize) | Obtains the frame size in the callback. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetSpeed](_o_h_audio.md#oh_audiorenderer_getspeed)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, float \*speed) | Obtains the audio renderer rate. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_SetSpeed](_o_h_audio.md#oh_audiorenderer_setspeed)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, float speed) | Sets the audio renderer rate. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_SetMarkPosition](_o_h_audio.md#oh_audiorenderer_setmarkposition)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, uint32_t samplePos, [OH_AudioRenderer_OnMarkReachedCallback](_o_h_audio.md#oh_audiorenderer_onmarkreachedcallback) callback, void \*userData) | Sets the mark position for an audio renderer. When this function is called, the mark position that has been set will be overwritten. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_CancelMark](_o_h_audio.md#oh_audiorenderer_cancelmark)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer) | Cancels the mark set by [OH_AudioRenderer_SetMarkPosition](_o_h_audio.md#oh_audiorenderer_setmarkposition). | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_SetVolume](_o_h_audio.md#oh_audiorenderer_setvolume)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, float volume) | Sets the volume for an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_SetVolumeWithRamp](_o_h_audio.md#oh_audiorenderer_setvolumewithramp)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, float volume, int32_t durationMs) | Sets the volume with a ramp within the specified duration for an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetVolume](_o_h_audio.md#oh_audiorenderer_getvolume)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, float \*volume) | Obtains the volume of an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetUnderflowCount](_o_h_audio.md#oh_audiorenderer_getunderflowcount)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, uint32_t \*count) | Obtains the number of underloaded audio streams of an audio capturer. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetChannelLayout](_o_h_audio.md#oh_audiorenderer_getchannellayout)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, OH_AudioChannelLayout \*channelLayout) | Obtains the channel layout of an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetEffectMode](_o_h_audio.md#oh_audiorenderer_geteffectmode)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](_o_h_audio.md#oh_audiostream_audioeffectmode) \*effectMode) | Obtains the effect mode of an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_SetEffectMode](_o_h_audio.md#oh_audiorenderer_seteffectmode)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_AudioEffectMode](_o_h_audio.md#oh_audiostream_audioeffectmode) effectMode) | Sets the effect mode for an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetRendererPrivacy](_o_h_audio.md#oh_audiorenderer_getrendererprivacy)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioStream_PrivacyType](_o_h_audio.md#oh_audiostream_privacytype) \*privacy) | Checks whether the audio stream being played can be recorded by other applications. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_SetSilentModeAndMixWithOthers](_o_h_audio.md#oh_audiorenderer_setsilentmodeandmixwithothers)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, bool on) | Sets the silent mode in concurrent playback for an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_GetSilentModeAndMixWithOthers](_o_h_audio.md#oh_audiorenderer_getsilentmodeandmixwithothers)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, bool \*on) | Checks whether the silent mode in concurrent playback is enabled for an audio stream. | 
| [OH_AudioStream_Result](_o_h_audio.md#oh_audiostream_result) [OH_AudioRenderer_SetDefaultOutputDevice](_o_h_audio.md#oh_audiorenderer_setdefaultoutputdevice)([OH_AudioRenderer](_o_h_audio.md#oh_audiorenderer) \*renderer, [OH_AudioDevice_Type](_o_h_audio.md#oh_audiodevice_type) deviceType) | Sets the default built-in audio output device. | 
