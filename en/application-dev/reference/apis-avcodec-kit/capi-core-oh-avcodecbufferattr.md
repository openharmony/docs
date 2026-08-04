# OH_AVCodecBufferAttr

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=50836c62c0ce369a817bdec296deca1a95a5488d translatedAt=2026-08-01T07:17:55.795Z pushedAt=2026-08-01T07:42:21.961Z -->

```c
typedef struct OH_AVCodecBufferAttr {...} OH_AVCodecBufferAttr
```

## Overview

The struct describes the description information about the buffer of an OH_AVCodec instance.

**Since**: 9

**Related module**: [Core](capi-core.md)

**Header file**: [native_avbuffer_info.h](capi-native-avbuffer-info-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int64_t pts | Display timestamp of the buffer, in microseconds.|
| int32_t size | Size of data contained in the buffer, in bytes.|
| int32_t offset | Start offset of the valid data in this buffer, in bytes.|
| uint32_t flags | Flags of the buffer. For details, see [OH_AVCodecBufferFlags](capi-native-avbuffer-info-h.md#oh_avcodecbufferflags).|