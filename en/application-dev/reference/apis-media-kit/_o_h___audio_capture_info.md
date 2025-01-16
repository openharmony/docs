# OH_AudioCaptureInfo


## Overview

The OH_AudioCaptureInfo struct describes the audio capture information.

When both **audioSampleRate** and **audioChannels** are **0**, the audio-related parameters are ignored and the audio data is not recorded.

**System capability**: SystemCapability.Multimedia.Media.AVScreenCapture

**Since**: 10

**Related module**: [AVScreenCapture](_a_v_screen_capture.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [audioSampleRate](#audiosamplerate) | Audio sampling rate. | 
| int32_t [audioChannels](#audiochannels) | Number of audio channels. | 
| [OH_AudioCaptureSourceType](_a_v_screen_capture.md#oh_audiocapturesourcetype) [audioSource](#audiosource) | Audio source. | 


## Member Variable Description


### audioChannels

```
int32_t OH_AudioCaptureInfo::audioChannels
```
**Description**
Number of audio channels.


### audioSampleRate

```
int32_t OH_AudioCaptureInfo::audioSampleRate
```
**Description**
Audio sampling rate. For details about the supported rates, see [AudioSamplingRate](../apis-audio-kit/js-apis-audio.md#audiosamplingrate8) of Audio Kit.


### audioSource

```
OH_AudioCaptureSourceType OH_AudioCaptureInfo::audioSource
```
**Description**
Audio source.
