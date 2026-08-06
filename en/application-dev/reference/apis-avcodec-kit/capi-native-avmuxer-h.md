# native_avmuxer.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=cd2519fe6c8e28e5233b3defca1bf4bda66b7bd0 translatedAt=2026-08-01T07:25:46.778Z pushedAt=2026-08-01T09:05:32.318Z -->

## Overview

Declares the native APIs for audio/video muxing.

**File to include:** <multimedia/player_framework/native_avmuxer.h>

**Library:** libnative_media_avmuxer.so

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Related module:** [AVMuxer](capi-avmuxer.md)

**Sample:** [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) | OH_AVMuxer | Defines the native layer object type of the muxer interface. |

### Function

| Name | Description |
| -- | -- |
| [OH_AVMuxer *OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format)](#oh_avmuxer_create) | Creates an OH_AVMuxer instance using a file descriptor (fd) and a muxer format. |
| [OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer *muxer, int32_t rotation)](#oh_avmuxer_setrotation) | Sets the video rotation angle (clockwise; the rotation angle must be 0, 90, 180, or 270). This API must be called before [OH_AVMuxer_Start](#oh_avmuxer_start). |
| [OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)](#oh_avmuxer_setformat) | Sets format data for the muxer.<br> Since API version 14, supports setting the creation time OH_MD_KEY_CREATION_TIME. If the creation time fails to be written, check whether the OH_MD_KEY_CREATION_TIME string conforms to the ISO 8601 time format and is in UTC.<br> Since API version 20, supports:<br> - Setting the descriptive text information of the file OH_MD_KEY_COMMENT. If the file description fails to be written, check whether OH_MD_KEY_COMMENT is of the string type or has a character length between 1 and 256.<br> - Setting the MP4 moov position OH_MD_KEY_ENABLE_MOOV_FRONT. When OH_MD_KEY_ENABLE_MOOV_FRONT is 0, moov is placed at the end; when it is 1, moov is placed at the front. The default is at the end. |
| [OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)](#oh_avmuxer_addtrack) | Adds an audio/video track to the muxer. Each call to this API adds one audio/video track to the muxer. This API must be called before [OH_AVMuxer_Start](#oh_avmuxer_start). |
| [OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer *muxer)](#oh_avmuxer_start) | Starts the muxer. This API must be called after [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) and before [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample). |
| [OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)](#oh_avmuxer_writesample) | Writes a sample to the muxer. This API must be called after [OH_AVMuxer_Start](#oh_avmuxer_start) and before [OH_AVMuxer_Stop](#oh_avmuxer_stop). The caller must write samples to the correct audio/video track in the chronological order specified by info. |
| [OH_AVErrCode OH_AVMuxer_WriteSampleBuffer(OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)](#oh_avmuxer_writesamplebuffer) | Writes a sample to the muxer. This API must be called after [OH_AVMuxer_Start](#oh_avmuxer_start) and before [OH_AVMuxer_Stop](#oh_avmuxer_stop). The caller must write samples to the correct audio/video track in the chronological order specified by the sample. |
| [OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer *muxer)](#oh_avmuxer_stop) | Stops the muxer. Once stopped, the muxer cannot be restarted. |
| [OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer *muxer)](#oh_avmuxer_destroy) | Cleans up internal resources and destroys the OH_AVMuxer instance. Note that repeated destruction will cause the program to crash. |

## Function Description

### OH_AVMuxer_Create()

```c
OH_AVMuxer *OH_AVMuxer_Create(int32_t fd, OH_AVOutputFormat format)
```

**Description**

Creates an OH_AVMuxer instance using a file descriptor (fd) and a muxing format.

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| int32_t fd | File descriptor opened in read/write mode (O_RDWR). The caller is responsible for closing this fd. |
| [OH_AVOutputFormat](capi-native-avcodec-base-h.md#oh_avoutputformat) format | Output file format for muxing. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) * | Pointer to the OH_AVMuxer instance. Call [OH_AVMuxer_Destroy](#oh_avmuxer_destroy) to destroy it. |

### OH_AVMuxer_SetRotation()

```c
OH_AVErrCode OH_AVMuxer_SetRotation(OH_AVMuxer *muxer, int32_t rotation)
```

**Description**

Sets the rotation angle of the video (clockwise, and the rotation angle must be 0, 90, 180, or 270). This API must be called before [OH_AVMuxer_Start](#oh_avmuxer_start).

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance. |
| int32_t rotation | Rotation angle, which must be 0, 90, 180, or 270. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | Result code.<br>         AV_ERR_OK: success.<br>         AV_ERR_INVALID_VAL: the muxer is a null pointer, or rotation is invalid.<br>         AV_ERR_OPERATE_NOT_PERMIT: the API is not allowed to be called. Check the API call sequence. |

### OH_AVMuxer_SetFormat()

```c
OH_AVErrCode OH_AVMuxer_SetFormat(OH_AVMuxer *muxer, OH_AVFormat *format)
```

**Description**

Sets format data to the muxer. This API must be called before [OH_AVMuxer_Start](#oh_avmuxer_start).<br> Since API version 14, setting the creation time OH_MD_KEY_CREATION_TIME is supported. If the creation time fails to be written, check whether the OH_MD_KEY_CREATION_TIME string conforms to the ISO 8601 standard time format and is in UTC time.<br> Since API version 20, the following are supported:

- Setting the descriptive text information of the file OH_MD_KEY_COMMENT. If the file description information fails to be written, check whether OH_MD_KEY_COMMENT is of the string type or has a character length greater than or equal to 1 and less than or equal to 256.

- Setting the position of MP4 moov OH_MD_KEY_ENABLE_MOOV_FRONT. When OH_MD_KEY_ENABLE_MOOV_FRONT is 0, moov is placed at the end; when it is 1, moov is placed at the front. The default is at the end.

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since:** 14

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance. |
| [OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance. File-level metadata set. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK: The format parameter is set correctly.<br>         AV_ERR_INVALID_VAL: The muxer is a null pointer, or the format is invalid.<br>         AV_ERR_OPERATE_NOT_PERMIT: The API is not allowed to be called. Check the API call sequence. |

### OH_AVMuxer_AddTrack()

```c
OH_AVErrCode OH_AVMuxer_AddTrack(OH_AVMuxer *muxer, int32_t *trackIndex, OH_AVFormat *trackFormat)
```

**Description**

Adds an audio/video track to the muxer. Each call to this API adds one audio/video track to the muxer. This API must be called before [OH_AVMuxer_Start](#oh_avmuxer_start).

**System capability**: SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to the OH_AVMuxer instance. |
| int32_t *trackIndex | Used to obtain the track index, which is used in the [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample) API. If the media track is added successfully, the value is greater than or equal to 0; otherwise, it is less than 0. |
| [OH_AVFormat](capi-core-oh-avformat.md) *trackFormat | Pointer to the OH_AVFormat instance. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK: operation successful.<br>         AV_ERR_INVALID_VAL: the muxer is a null pointer, or trackIndex is invalid, or trackFormat is invalid.<br>         AV_ERR_OPERATE_NOT_PERMIT: the API is not allowed to be called. Check the API call sequence.<br>         AV_ERR_UNSUPPORT: unsupported MIME type.<br>         AV_ERR_NO_MEMORY: memory allocation failed.<br>         AV_ERR_UNKNOWN: unknown error. |

### OH_AVMuxer_Start()

```c
OH_AVErrCode OH_AVMuxer_Start(OH_AVMuxer *muxer)
```

**Description**

Starts the muxer. This API must be called after [OH_AVMuxer_AddTrack](#oh_avmuxer_addtrack) and before [OH_AVMuxer_WriteSample](#oh_avmuxer_writesample).

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to the OH_AVMuxer instance. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | Result code.<br>         AV_ERR_OK: success.<br>         AV_ERR_INVALID_VAL: muxer is a null pointer.<br>         AV_ERR_OPERATE_NOT_PERMIT: calling this API is not permitted. Check the API calling sequence.<br>         AV_ERR_UNKNOWN: unknown error. |

### OH_AVMuxer_WriteSample()

```c
OH_AVErrCode OH_AVMuxer_WriteSample(OH_AVMuxer *muxer, uint32_t trackIndex, OH_AVMemory *sample, OH_AVCodecBufferAttr info)
```

**Description**

Writes a sample to the muxer. This API must be called after [OH_AVMuxer_Start](#oh_avmuxer_start) and before [OH_AVMuxer_Stop](#oh_avmuxer_stop). The caller must write samples to the correct audio/video track in the chronological order specified in info.

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Deprecated from**: 11

**Substitutes:** [OH_AVMuxer_WriteSampleBuffer](#oh_avmuxer_writesamplebuffer)

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance. |
| uint32_t trackIndex | Index of the audio/video track corresponding to the data. The value ranges from the indices of successfully added audio/video tracks. |
| [OH_AVMemory](capi-core-oh-avmemory.md) *sample | Data obtained through encoding or demuxing. |
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) info | Description information corresponding to **sample**. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK: Execution successful.<br>         AV_ERR_INVALID_VAL: The muxer is a null pointer, or trackIndex is invalid, or sample is invalid, or info is invalid.<br>         AV_ERR_OPERATE_NOT_PERMIT: The API is not allowed to be called. Check the API call sequence.<br>         AV_ERR_NO_MEMORY: Memory allocation failed.<br>         AV_ERR_UNKNOWN: Unknown error. |

### OH_AVMuxer_WriteSampleBuffer()

```c
OH_AVErrCode OH_AVMuxer_WriteSampleBuffer(OH_AVMuxer *muxer, uint32_t trackIndex, const OH_AVBuffer *sample)
```

**Description**

Writes a sample to the muxer. This API must be called after [OH_AVMuxer_Start](#oh_avmuxer_start) and before [OH_AVMuxer_Stop](#oh_avmuxer_stop). The caller needs to write samples to the correct audio/video track in chronological order based on the timestamps in the samples.

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 11

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to an OH_AVMuxer instance. |
| uint32_t trackIndex | Index of the audio/video track corresponding to the data. The value range is the indices of successfully added audio/video tracks. |
| const [OH_AVBuffer](capi-core-oh-avbuffer.md) *sample | Data and attributes obtained through encoding or demuxing. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | Result code.<br>         AV_ERR_OK: success.<br>         AV_ERR_INVALID_VAL: The muxer is a null pointer, or trackIndex is invalid, or sample is invalid.<br>         AV_ERR_OPERATE_NOT_PERMIT: The API is not allowed to be called. Check the API calling sequence.<br>         AV_ERR_NO_MEMORY: Failed to allocate memory.<br>         AV_ERR_UNKNOWN: Unknown error. |

### OH_AVMuxer_Stop()

```c
OH_AVErrCode OH_AVMuxer_Stop(OH_AVMuxer *muxer)
```

**Description**

Stops the muxer. This API must be called after [OH_AVMuxer_Start](#oh_avmuxer_start). After the muxer is stopped, it cannot be restarted.

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to the OH_AVMuxer instance. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | Result code.<br>         AV_ERR_OK: success.<br>         AV_ERR_INVALID_VAL: the muxer is a null pointer.<br>         AV_ERR_OPERATE_NOT_PERMIT: the API is not allowed to be called. Check the API calling sequence. |

### OH_AVMuxer_Destroy()

```c
OH_AVErrCode OH_AVMuxer_Destroy(OH_AVMuxer *muxer)
```

**Description**

Clears internal resources and destroys the OH_AVMuxer instance.<br>**Note:** Do not destroy the instance repeatedly, as this will cause the program to crash.

**System capability:** SystemCapability.Multimedia.Media.Muxer

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVMuxer](capi-avmuxer-oh-avmuxer.md) *muxer | Pointer to the OH_AVMuxer instance. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | AV_ERR_OK: The operation is successful.<br>        AV_ERR_INVALID_VAL: The muxer pointer is null. |