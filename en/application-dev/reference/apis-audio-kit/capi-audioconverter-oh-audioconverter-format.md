# OH_AudioConverter_Format

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xxngwang-->
<!--Designer: @jay-liusong-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=0d69160d2baf7eb9ac7eca6b0e1cc7f7793cd894 translatedAt=2026-08-10T06:24:45.489Z pushedAt=2026-08-10T06:47:13.807Z -->

```c
typedef struct OH_AudioConverter_Format {...} OH_AudioConverter_Format
```

## Overview

This struct defines the audio converter format data structure, which is used to describe the basic audio format.

**Since**: 26.0.0

**Related module**: [OHAudioSuite](capi-ohaudiosuite.md)

**Header file**: [native_audio_converter.h](capi-native-audio-converter-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_Audio_EncodingType](capi-native-audio-suite-base-h.md#oh_audio_encodingtype) encodingType | Audio encoding format type.<br>**Since**: 26.0.0|
| [OH_Audio_SampleRate](capi-native-audio-suite-base-h.md#oh_audio_samplerate) samplingRate | Audio sampling rate.<br>**Since**: 26.0.0|
| [OH_AudioChannelLayout](../../reference/apis-avcodec-kit/capi-native-audio-channel-layout-h.md#oh_audiochannellayout) channelLayout | Audio channel layout.<br>**Since:** 26.0.0 |
| [OH_Audio_SampleFormat](capi-native-audio-suite-base-h.md#oh_audio_sampleformat) sampleFormat | Audio sample format.<br>**Since**: 26.0.0|