# OH_AVRecorder_Config

## Overview

The struct describes the AVRecorder configuration.

**Since**: 18

**Related module**: [AVRecorder](capi-avrecorder.md)

**Header file**: [avrecorder_base.h](capi-avrecorder-base-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| [OH_AVRecorder_AudioSourceType](capi-avrecorder-base-h.md#oh_avrecorder_audiosourcetype) audioSourceType | Type of the audio source to record.|
| [OH_AVRecorder_VideoSourceType](capi-avrecorder-base-h.md#oh_avrecorder_videosourcetype) videoSourceType | Type of the video source to record.|
| [OH_AVRecorder_Profile](capi-avrecorder-oh-avrecorder-profile.md) profile | Audio and video encoding configuration.|
| char* url | Pointer to the URL of the recording output file, in the format of fd://xx.|
| [OH_AVRecorder_FileGenerationMode](capi-avrecorder-base-h.md#oh_avrecorder_filegenerationmode) fileGenerationMode | Mode for generating the recording output file.|
| [OH_AVRecorder_Metadata](capi-avrecorder-oh-avrecorder-metadata.md) metadata | Metadata of the recorded media.|
| int32_t maxDuration | Maximum recording duration.|
