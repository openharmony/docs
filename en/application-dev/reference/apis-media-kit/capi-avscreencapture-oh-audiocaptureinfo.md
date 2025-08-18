# OH_AudioCaptureInfo

## Overview

The struct describes the audio capture information.

When both **audioSampleRate** and **audioChannels** are **0**, the audio-related parameters are ignored and the audio data is not recorded.

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

**Header file**: [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t audioSampleRate | Audio sampling rate. For details about the supported rates, see [AudioSamplingRate](../apis-audio-kit/arkts-apis-audio-e.md#audiosamplingrate8) of Audio Kit.|
| int32_t audioChannels | Number of audio channels.|
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) audioSource | Audio source.|
