# native_averrors.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @xushubo; @chennotfound-->
<!--Designer: @dongyu_dy-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the error codes used by the media framework.

**File to include**: <multimedia/player_framework/native_averrors.h>

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](capi-core.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVErrCode](#oh_averrcode) | OH_AVErrCode | Enumerates the error codes used by the media framework.|

## Enum Description

### OH_AVErrCode

```
enum OH_AVErrCode
```

**Description**

Enumerates the error codes used by the media framework.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

| Value| Description|
| -- | -- |
| AV_ERR_OK = 0 | Operation successful.|
| AV_ERR_NO_MEMORY = 1 | No memory.|
| AV_ERR_OPERATE_NOT_PERMIT = 2 | Operation not allowed.|
| AV_ERR_INVALID_VAL = 3 | Invalid value.|
| AV_ERR_IO = 4 | I/O error.|
| AV_ERR_TIMEOUT = 5 | Timeout.|
| AV_ERR_UNKNOWN = 6 | Unknown error.|
| AV_ERR_SERVICE_DIED = 7 | Unavailable service.|
| AV_ERR_INVALID_STATE = 8 | Unsupported operation in this state.|
| AV_ERR_UNSUPPORT = 9 | Unsupported API.|
| AV_ERR_INPUT_DATA_ERROR = 10 |  Incorrect input data.<br>**Since**: 12|
| AV_ERR_UNSUPPORTED_FORMAT = 11 |  Unsupported format.<br>**Since**: 18|
| AV_ERR_EXTEND_START = 100 | Initial value for extended error codes.|
| AV_ERR_DRM_BASE = 200 | DRM start error code.<br>**Since**: 12|
| AV_ERR_DRM_DECRYPT_FAILED = 201 | DRM decryption fails.<br>**Since**: 12|
| AV_ERR_VIDEO_BASE = 300 | Video start error code.<br>**Since**: 12|
| AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION = 301 | Color Space Conversion (CSC) is not supported.<br>**Since**: 12|
| AV_ERR_IO_CANNOT_FIND_HOST = 5411001 |  The host is not found. The possible cause is that the server address is incorrect.<br>**Since**: 14|
| AV_ERR_IO_CONNECTION_TIMEOUT = 5411002 |  Network connection times out.<br>**Since**: 14|
| AV_ERR_IO_NETWORK_ABNORMAL = 5411003 |  The connection fails due to a network error.<br>**Since**: 14|
| AV_ERR_IO_NETWORK_UNAVAILABLE = 5411004 |  The connection fails due to network unavailability.<br>**Since**: 14|
| AV_ERR_IO_NO_PERMISSION = 5411005 |  No network access permission.<br>**Since**: 14|
| AV_ERR_IO_NETWORK_ACCESS_DENIED = 5411006 |  The client request parameter is incorrect or exceeds the processing capability.<br>**Since**: 14|
| AV_ERR_IO_RESOURCE_NOT_FOUND = 5411007 |  No network resource is available.<br>**Since**: 14|
| AV_ERR_IO_SSL_CLIENT_CERT_NEEDED = 5411008 |  Server authentication fails because the client certificate is not carried, is invalid, or has expired.<br>**Since**: 14|
| AV_ERR_IO_SSL_CONNECT_FAIL = 5411009 |  Client authentication fails because the server certificate is not carried, is invalid, or has expired.<br>**Since**: 14|
| AV_ERR_IO_SSL_SERVER_CERT_UNTRUSTED = 5411010 |  The SSL server certificate is untrusted.<br>**Since**: 14|
| AV_ERR_IO_UNSUPPORTED_REQUEST = 5411011 |  The network protocol does not support the request.<br>**Since**: 14|
| AV_ERR_STREAM_CHANGED = 5410005 | The stream format changes in synchronous mode. You can call [OH_VideoEncoder_GetOutputDescription](_video_encoder.md#oh_videoencoder_getoutputdescription) (video encoding), [OH_VideoDecoder_GetOutputDescription](_video_decoder.md#oh_videodecoder_getoutputdescription) (video decoding), or [OH_AudioCodec_GetOutputDescription](capi-native-avcodec-audiocodec-h.md#oh_audiocodec_getoutputdescription) (audio encoding and decoding) to obtain the new stream configuration.<br>**Since**: 20|
| AV_ERR_TRY_AGAIN_LATER = 5410006 |  The temporary buffer query fails in synchronous mode. You are advised to wait for a short period of time and try again.<br>**Since**: 20|
