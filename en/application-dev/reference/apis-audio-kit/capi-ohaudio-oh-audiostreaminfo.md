# OH_AudioStreamInfo

## Overview

The struct describes the audio stream information, which is used to describe the basic audio format.

**Since**: 19

**Related module**: [OHAudio](capi-ohaudio.md)

**Header file**: [native_audiostream_base.h](capi-native-audiostream-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t samplingRate | Sampling rate.|
| [OH_AudioChannelLayout](../apis-avcodec-kit/_core.md#oh_audiochannellayout-1) channelLayout | Audio channel layout.|
| [OH_AudioStream_EncodingType](capi-native-audiostream-base-h.md#oh_audiostream_encodingtype) encodingType | Encoding type.|
| [OH_AudioStream_SampleFormat](capi-native-audiostream-base-h.md#oh_audiostream_sampleformat) sampleFormat | Sampling format.|
