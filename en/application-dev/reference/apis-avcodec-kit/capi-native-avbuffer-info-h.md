# native_avbuffer_info.h

## Overview

The file declares the attribute definition of the media struct AVBuffer.

**File to include**: <multimedia/player_framework/native_avbuffer_info.h>

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](capi-core.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) | OH_AVCodecBufferAttr | Describes the description information about the buffer of an OH_AVCodec instance.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) | OH_AVCodecBufferFlags | Enumerates the flags for the buffer of an OH_AVCodec instance.|

## Enum Description

### OH_AVCodecBufferFlags

```
enum OH_AVCodecBufferFlags
```

**Description**

Enumerates the flags for the buffer of an OH_AVCodec instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

| Value| Description|
| -- | -- |
| AVCODEC_BUFFER_FLAGS_NONE = 0 | Common frame.|
| AVCODEC_BUFFER_FLAGS_EOS = 1 << 0 | The buffer is an end-of-stream frame.|
| AVCODEC_BUFFER_FLAGS_SYNC_FRAME = 1 << 1 | The buffer contains key frames.|
| AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME = 1 << 2 | The data in the buffer is only part of the frame.|
| AVCODEC_BUFFER_FLAGS_CODEC_DATA = 1 << 3 | The buffer contains codec-specific data.|
| AVCODEC_BUFFER_FLAGS_DISCARD = 1 << 4 | The decoding process depends on the buffer, and the decoded data can be discarded.<br>**Since**: 12|
| AVCODEC_BUFFER_FLAGS_DISPOSABLE = 1 << 5 | The buffer can be disposed directly.<br>**Since**: 12|
