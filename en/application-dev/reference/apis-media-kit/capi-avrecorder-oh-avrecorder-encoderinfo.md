# OH_AVRecorder_EncoderInfo

## Overview

The struct describes the encoder information.

**Since**: 18

**Related module**: [AVRecorder](capi-avrecorder.md)

**Header file**: [avrecorder_base.h](capi-avrecorder-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_AVRecorder_CodecMimeType](capi-avrecorder-base-h.md#oh_avrecorder_codecmimetype) mimeType | MIME type of the encoder.|
| char* type | Pointer to the encoder type. The value **audio** means an audio encoder, and **video** means a video encoder.|
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) bitRate | Bit rate range of the encoder, with the minimum and maximum bit rates specified.|
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) frameRate | Video frame rate range, with the minimum and maximum frame rates specified. This parameter is available only for video encoders.|
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) width | Video frame width range, with the minimum and maximum widths specified. This parameter is available only for video encoders.|
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) height | Video frame height range, with the minimum and maximum heights specified. This parameter is available only for video encoders.|
| [OH_AVRecorder_Range](capi-avrecorder-oh-avrecorder-range.md) channels | Number of audio channels for the audio capturer, with the minimum and maximum numbers of audio channels specified. This parameter is available only for audio encoders.|
| int32_t* sampleRate | Pointer to the list of audio sampling rates, including all available audio sampling rates. This parameter is available only for audio encoders.|
| int32_t sampleRateLen | Length of the audio sampling rate list.|
