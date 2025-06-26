# OH_AVRecorder_Profile

## Overview

The OH_AVRecorder_Profile struct describes the parameters used for audio and video recording.

You can choose to record only audio or only video by setting the parameters.

1. When **audioBitrate** or **audioChannels** is set to **0**, audio recording is disabled.
2. When **videoFrameWidth** or **videoFrameHeight** is set to **0**, video recording is disabled.

For details about the value range of each parameter, see [AVRecorderProfile](js-apis-media.md#avrecorderprofile9).

**Since**: 18

**Related module**: [AVRecorder](capi-avrecorder.md)

**Header file**: [avrecorder_base.h](capi-avrecorder-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int32_t audioBitrate | Audio bit rate.|
| int32_t audioChannels | Number of channels.|
| [OH_AVRecorder_CodecMimeType](capi-avrecorder-base-h.md#oh_avrecorder_codecmimetype) audioCodec | Audio encoding format.|
| int32_t audioSampleRate | Audio sampling rate.|
| [OH_AVRecorder_ContainerFormatType](capi-avrecorder-base-h.md#oh_avrecorder_containerformattype) fileFormat | Output file format.|
| int32_t videoBitrate | Video bit rate.|
| [OH_AVRecorder_CodecMimeType](capi-avrecorder-base-h.md#oh_avrecorder_codecmimetype) videoCodec | Video encoding format.|
| int32_t videoFrameWidth | Video width.|
| int32_t videoFrameHeight | Video height.|
| int32_t videoFrameRate | Video frame rate.|
| bool isHdr | Whether to record HDR videos.|
| bool enableTemporalScale | Whether to enable temporal scaling encoding mode.|
