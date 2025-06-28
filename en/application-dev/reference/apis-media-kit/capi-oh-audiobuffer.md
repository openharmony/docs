# OH_AudioBuffer

## Overview

The OH_AudioBuffer struct describes the configuration such as the size, type, and timestamp of audio data.

**Since**: 10

**Related module**: [AVScreenCapture](capi-avscreencapture.md)

**Header file**: [native_avscreen_capture_base.h](capi-native-avscreen-capture-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| uint8_t* buf | Pointer to an audio buffer.|
| int32_t size | Size of the audio buffer.|
| int64_t timestamp | Timestamp of the audio buffer.|
| [OH_AudioCaptureSourceType](capi-native-avscreen-capture-base-h.md#oh_audiocapturesourcetype) type | Type of the audio capture source.|
