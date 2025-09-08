# avtranscoder.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the native APIs provided by the AVTranscoder. You can use the APIs to transcode a source video file into a new video file.

**File to include**: <multimedia/player_framework/avtranscoder.h>

**Library**: libavtranscoder.so

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20

**Related module**: [AVTranscoder](capi-avtranscoder.md)

**Sample**: [AVPlayerNDKVideo](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVPlayer/AVPlayerNDK)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config *OH_AVTranscoderConfig_Create()](#oh_avtranscoderconfig_create) | Creates an instance of the transcoding configuration parameters.|
| [OH_AVErrCode OH_AVTranscoderConfig_Release(OH_AVTranscoder_Config* config)](#oh_avtranscoderconfig_release) | Releases the resources of the transcoding configuration parameters.<br>After a successful call, the instance specified by **config** is released and set to nullptr.|
| [OH_AVErrCode OH_AVTranscoderConfig_SetSrcFD(OH_AVTranscoder_Config *config, int32_t srcFd, int64_t srcOffset, int64_t length)](#oh_avtranscoderconfig_setsrcfd) | Sets the file descriptor of the source video for transcoding.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_SetDstFD(OH_AVTranscoder_Config *config, int32_t dstFd)](#oh_avtranscoderconfig_setdstfd) | Sets the file descriptor of the output video for transcoding.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoType(OH_AVTranscoder_Config *config, const char *mimeType)](#oh_avtranscoderconfig_setdstvideotype) | Sets the encoding format of the output video for transcoding.<br>Currently, only AVC and HEVC are supported. If the source video is in HEVC format, the default value is **HEVC**. Otherwise, the default value is **AVC**.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_SetDstAudioType(OH_AVTranscoder_Config *config, const char *mimeType)](#oh_avtranscoderconfig_setdstaudiotype) | Sets the encoding format of the output audio for transcoding.<br>Currently, only AAC is supported. If this parameter is not set, AAC is used by default.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_SetDstFileType(OH_AVTranscoder_Config *config, OH_AVOutputFormat mimeType)](#oh_avtranscoderconfig_setdstfiletype) | Sets the container format of the output video file for transcoding.<br>Currently, only MP4 is supported.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_SetDstAudioBitrate(OH_AVTranscoder_Config *config, int32_t bitrate)](#oh_avtranscoderconfig_setdstaudiobitrate) | Sets the bit rate of the output audio for transcoding.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoBitrate(OH_AVTranscoder_Config *config, int32_t bitrate)](#oh_avtranscoderconfig_setdstvideobitrate) | Sets the bit rate of the output video for transcoding.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoResolution(OH_AVTranscoder_Config *config, int32_t width, int32_t height)](#oh_avtranscoderconfig_setdstvideoresolution) | Sets the resolution of the output video for transcoding, in px, where **width** is the width of the output video frame and **height** is the height of the output video frame.<br>This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).|
| [OH_AVErrCode OH_AVTranscoderConfig_EnableBFrame(OH_AVTranscoder_Config *config, bool enabled)](#oh_avtranscoderconfig_enablebframe) | Enables B-frame encoding for the output video during transcoding.<br>For details about the constraints on B-frame video encoding, see [Constraints in B-Frame Video Encoding](../../media/avcodec/video-encoding-b-frame.md#constraints).<br>If the current environment does not meet these constraints, B-frames will be skipped, and encoding will proceed as if B-frame video encoding were not enabled.|
| [OH_AVTranscoder *OH_AVTranscoder_Create(void)](#oh_avtranscoder_create) | Creates an AVTranscoder instance.|
| [OH_AVErrCode OH_AVTranscoder_Prepare(OH_AVTranscoder *transcoder, OH_AVTranscoder_Config *config)](#oh_avtranscoder_prepare) | Sets the parameters for video transcoding and prepares for transcoding.<br>This function must be called before [OH_AVTranscoder_Start](#oh_avtranscoder_start). Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_PREPARED state.|
| [OH_AVErrCode OH_AVTranscoder_Start(OH_AVTranscoder *transcoder)](#oh_avtranscoder_start) | Starts transcoding.<br>This function must be called after a successful call to [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare). Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_STARTED state.|
| [OH_AVErrCode OH_AVTranscoder_Pause(OH_AVTranscoder *transcoder)](#oh_avtranscoder_pause) | Pauses transcoding.<br>This function must be called when the AVTranscoder is in the AVTRANSCODER_STARTED state. Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_PAUSED state.|
| [OH_AVErrCode OH_AVTranscoder_Resume(OH_AVTranscoder *transcoder)](#oh_avtranscoder_resume) | Resumes transcoding.<br>This function must be called when the AVTranscoder is in the AVTRANSCODER_PAUSED state. Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_STARTED state again.|
| [OH_AVErrCode OH_AVTranscoder_Cancel(OH_AVTranscoder *transcoder)](#oh_avtranscoder_cancel) | Cancels transcoding.<br>This function must be called when the AVTranscoder is in the AVTRANSCODER_STARTED or AVTRANSCODER_PAUSED state. Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_CANCELLED state.|
| [OH_AVErrCode OH_AVTranscoder_Release(OH_AVTranscoder *transcoder)](#oh_avtranscoder_release) | Releases an AVTranscoder instance.|
| [OH_AVErrCode OH_AVTranscoder_SetStateCallback(OH_AVTranscoder *transcoder, OH_AVTranscoder_OnStateChange callback, void *userData)](#oh_avtranscoder_setstatecallback) | Registers a callback for transcoding state change events.<br>This callback is invoked when the state of the transcoding process changes.<br>An application can subscribe to only one transcoding state change event. When the application initiates multiple subscriptions to this event, the last subscription is applied.<br>The callback must be registered before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare) is called.|
| [OH_AVErrCode OH_AVTranscoder_SetErrorCallback(OH_AVTranscoder *transcoder, OH_AVTranscoder_OnError callback, void *userData)](#oh_avtranscoder_seterrorcallback) | Registers a callback for transcoding error events.<br>This callback is invoked when an error occurs during the transcoding process.<br>If this event is reported, call [OH_AVTranscoder_Release](#oh_avtranscoder_release) to exit the transcoding.<br>An application can subscribe to only one transcoding error event. When the application initiates multiple subscriptions to this event, the last subscription is applied.<br>The callback must be registered before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare) is called.|
| [OH_AVErrCode OH_AVTranscoder_SetProgressUpdateCallback(OH_AVTranscoder *transcoder, OH_AVTranscoder_OnProgressUpdate callback, void *userData)](#oh_avtranscoder_setprogressupdatecallback) | Registers a callback for transcoding progress update events.<br>This callback is invoked when the progress of the transcoding process is updated.<br>An application can subscribe to only one transcoding error event. When the application initiates multiple subscriptions to this event, the last subscription is applied.<br>The callback must be registered before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare) is called.|

## Function Description

### OH_AVTranscoderConfig_Create()

```
OH_AVTranscoder_Config *OH_AVTranscoderConfig_Create()
```

**Description**

Creates an instance of the transcoding configuration parameters.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) * | Pointer to the OH_AVTranscoder_Config instance created. If the operation fails, nullptr is returned.|

### OH_AVTranscoderConfig_Release()

```
OH_AVErrCode OH_AVTranscoderConfig_Release(OH_AVTranscoder_Config* config)
```

**Description**

Releases the resources of the transcoding configuration parameters.

After a successful call, the instance specified by **config** is released and set to nullptr.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md)* config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The release operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr.|

### OH_AVTranscoderConfig_SetSrcFD()

```
OH_AVErrCode OH_AVTranscoderConfig_SetSrcFD(OH_AVTranscoder_Config *config, int32_t srcFd, int64_t srcOffset, int64_t length)
```

**Description**

Sets the file descriptor of the source video for transcoding.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| int32_t srcFd | File descriptor of the source video.|
| int64_t srcOffset | Offset of the source video in the file descriptor, in bytes.|
| int64_t length | Size of the source video, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the parameters related to the source video file are incorrect.|

### OH_AVTranscoderConfig_SetDstFD()

```
OH_AVErrCode OH_AVTranscoderConfig_SetDstFD(OH_AVTranscoder_Config *config, int32_t dstFd)
```

**Description**

Sets the file descriptor of the output video for transcoding.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| int32_t dstFd | File descriptor of the output video.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the output video file descriptor is invalid.|

### OH_AVTranscoderConfig_SetDstVideoType()

```
OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoType(OH_AVTranscoder_Config *config, const char *mimeType)
```

**Description**

Sets the encoding format of the output video for transcoding.

Currently, only AVC and HEVC are supported. If the source video is in HEVC format, the default value is **HEVC**. Otherwise, the default value is **AVC**.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| const char *mimeType | Pointer to the encoding format of the output video. For details, see [native_avcodec_base.h](../apis-avcodec-kit/native__avcodec__base_8h.md#variables).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the value of **mimeType** is not allowed.|

### OH_AVTranscoderConfig_SetDstAudioType()

```
OH_AVErrCode OH_AVTranscoderConfig_SetDstAudioType(OH_AVTranscoder_Config *config, const char *mimeType)
```

**Description**

Sets the encoding format of the output audio for transcoding.

Currently, only AAC is supported. If this parameter is not set, AAC is used by default.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| const char *mimeType | Pointer to the encoding format of the output audio. For details, see [native_avcodec_base.h](../apis-avcodec-kit/native__avcodec__base_8h.md#variables).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the value of **mimeType** is not allowed.|

### OH_AVTranscoderConfig_SetDstFileType()

```
OH_AVErrCode OH_AVTranscoderConfig_SetDstFileType(OH_AVTranscoder_Config *config, OH_AVOutputFormat mimeType)
```

**Description**

Sets the container format of the output video file for transcoding.

Currently, only MP4 is supported.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| [OH_AVOutputFormat](../apis-avcodec-kit/_codec_base.md#oh_avoutputformat-1) mimeType | Container format of the output video. For details, see [native_avcodec_base.h](../apis-avcodec-kit/native__avcodec__base_8h.md#variables).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the value of **mimeType** is invalid.|

### OH_AVTranscoderConfig_SetDstAudioBitrate()

```
OH_AVErrCode OH_AVTranscoderConfig_SetDstAudioBitrate(OH_AVTranscoder_Config *config, int32_t bitrate)
```

**Description**

Sets the bit rate of the output audio for transcoding.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| int32_t bitrate | Bit rate of the output audio, in bit/s. The value range is [1, 500000]. The default value is 48 kbit/s.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the value of **bitrate** is invalid.|

### OH_AVTranscoderConfig_SetDstVideoBitrate()

```
OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoBitrate(OH_AVTranscoder_Config *config, int32_t bitrate)
```

**Description**

Sets the bit rate of the output video for transcoding.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| int32_t bitrate | Bit rate of the output video, in bit/s. The default bit rate is set according to the resolution of the output video.<br>For the resolution range [240p, 480p], the default bit rate is 1 Mbit/s.<br>For the resolution range (480p, 720p], the default bit rate is 2 Mbit/s.<br>For the resolution range (240p, 1080p], the default bit rate is 4 Mbit/s.<br>For the resolution 1080p or above, the default bit rate is 8 Mbit/s.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the value of **bitrate** is invalid.|

### OH_AVTranscoderConfig_SetDstVideoResolution()

```
OH_AVErrCode OH_AVTranscoderConfig_SetDstVideoResolution(OH_AVTranscoder_Config *config, int32_t width, int32_t height)
```

**Description**

Sets the resolution of the output video for transcoding, in px, where **width** is the width of the output video frame and **height** is the height of the output video frame.

This function must be called before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare).

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| int32_t width | Width of the output video frame. The value range is [240, 3840]. The default value is the width of the source video frame.|
| int32_t height | Height of the output video frame. The value range is [240, 2160]. The default value is the height of the source video frame.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr, or the value of **width** or **height** is invalid.|

### OH_AVTranscoderConfig_EnableBFrame()

```
OH_AVErrCode OH_AVTranscoderConfig_EnableBFrame(OH_AVTranscoder_Config *config, bool enabled)
```

**Description**

Enables B-frame encoding for the output video during transcoding.

For details about the constraints on B-frame video encoding, see [Constraints in B-Frame Video Encoding](../../media/avcodec/video-encoding-b-frame.md#constraints).

If the current environment does not meet these constraints, B-frames will be skipped, and encoding will proceed as if B-frame video encoding were not enabled.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance, which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|
| bool enabled | Whether to enable B-frame encoding. **true** to enable, **false** otherwise.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The setting is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **config** is nullptr.|

### OH_AVTranscoder_Create()

```
OH_AVTranscoder *OH_AVTranscoder_Create(void)
```

**Description**

Creates an AVTranscoder instance.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) * | Pointer to the OH_AVTranscoder instance created. If the operation fails, nullptr is returned.|

### OH_AVTranscoder_Prepare()

```
OH_AVErrCode OH_AVTranscoder_Prepare(OH_AVTranscoder *transcoder, OH_AVTranscoder_Config *config)
```

**Description**

Sets the parameters for video transcoding and prepares for transcoding.

This function must be called before [OH_AVTranscoder_Start](#oh_avtranscoder_start). Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_PREPARED state.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) *config | Pointer to an OH_AVTranscoder_Config instance,<br>              which is created by running [OH_AVTranscoderConfig_Create](#oh_avtranscoderconfig_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The video transcoding parameters are set successfully, and the AVTranscoder enters the AVTRANSCODER_PREPARED state.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** is nullptr, or the Prepare operation fails.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The Prepare operation is not allowed in the current state, or the format is not supported.<br>**AV_ERR_IO**: An I/O access error occurs.<br>**AV_ERR_SERVICE_DIED**: The media service is stopped.|

### OH_AVTranscoder_Start()

```
OH_AVErrCode OH_AVTranscoder_Start(OH_AVTranscoder *transcoder)
```

**Description**

Starts transcoding.

This function must be called after a successful call to [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare). Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_STARTED state.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: Transcoding starts successfully, and the AVTranscoder enters the AVTRANSCODER_STARTED state.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** is nullptr, or the Start operation fails.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The Start operation is not allowed in the current state.<br>**AV_ERR_IO**: An I/O access error occurs.<br>**AV_ERR_SERVICE_DIED**: The media service is stopped.|

### OH_AVTranscoder_Pause()

```
OH_AVErrCode OH_AVTranscoder_Pause(OH_AVTranscoder *transcoder)
```

**Description**

Pauses transcoding.

This function must be called when the AVTranscoder is in the AVTRANSCODER_STARTED state. Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_PAUSED state.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: Transcoding is paused successfully, and the AVTranscoder enters the AVTRANSCODER_PAUSED state.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** is nullptr, or the Pause operation fails.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The Pause operation is not allowed in the current state.<br>**AV_ERR_IO**: An I/O access error occurs.<br>**AV_ERR_SERVICE_DIED**: The media service is stopped.|

### OH_AVTranscoder_Resume()

```
OH_AVErrCode OH_AVTranscoder_Resume(OH_AVTranscoder *transcoder)
```

**Description**

Resumes transcoding.

This function must be called when the AVTranscoder is in the AVTRANSCODER_PAUSED state. Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_STARTED state again.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: Transcoding is resumed successfully, and the AVTranscoder enters the AVTRANSCODER_STARTED state.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** is nullptr, or the Resume operation fails.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The Resume operation is not allowed in the current state.<br>**AV_ERR_IO**: An I/O access error occurs.<br>**AV_ERR_SERVICE_DIED**: The media service is stopped.|

### OH_AVTranscoder_Cancel()

```
OH_AVErrCode OH_AVTranscoder_Cancel(OH_AVTranscoder *transcoder)
```

**Description**

Cancels transcoding.

This function must be called when the AVTranscoder is in the AVTRANSCODER_STARTED or AVTRANSCODER_PAUSED state. Upon a successful call to this function, the AVTranscoder enters the AVTRANSCODER_CANCELLED state.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: Transcoding is canceled successfully, and the AVTranscoder enters the AVTRANSCODER_CANCELLED state.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** is nullptr, or the Cancel operation fails.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The Cancel operation is not allowed in the current state.<br>**AV_ERR_IO**: An I/O access error occurs.<br>**AV_ERR_SERVICE_DIED**: The media service is stopped.|

### OH_AVTranscoder_Release()

```
OH_AVErrCode OH_AVTranscoder_Release(OH_AVTranscoder *transcoder)
```

**Description**

Releases an AVTranscoder instance.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | AV_ERR_OK: The AVTranscoder instance is successfully released.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** is nullptr, or the Release operation fails.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The Release operation is not allowed in the current state.<br>**AV_ERR_IO**: An I/O access error occurs.<br>**AV_ERR_SERVICE_DIED**: The media service is stopped.|

### OH_AVTranscoder_SetStateCallback()

```
OH_AVErrCode OH_AVTranscoder_SetStateCallback(OH_AVTranscoder *transcoder, OH_AVTranscoder_OnStateChange callback, void *userData)
```

**Description**

Registers a callback for transcoding state change events.

This callback is invoked when the state of the transcoding process changes.

An application can subscribe to only one transcoding state change event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

The callback must be registered before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare) is called.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|
| [OH_AVTranscoder_OnStateChange](capi-avtranscoder-base-h.md#oh_avtranscoder_onstatechange) callback | Callback invoked when the state of the transcoding process changes. For details, see [OH_AVTranscoder_OnStateChange](capi-avtranscoder-base-h.md#oh_avtranscoder_onstatechange).|
| void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The registration is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** or **callback** is nullptr.|

### OH_AVTranscoder_SetErrorCallback()

```
OH_AVErrCode OH_AVTranscoder_SetErrorCallback(OH_AVTranscoder *transcoder, OH_AVTranscoder_OnError callback, void *userData)
```

**Description**

Registers a callback for transcoding error events.

This callback is invoked when an error occurs during the transcoding process.

If this event is reported, call [OH_AVTranscoder_Release](#oh_avtranscoder_release) to exit the transcoding.

An application can subscribe to only one transcoding error event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

The callback must be registered before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare) is called.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|
| [OH_AVTranscoder_OnError](capi-avtranscoder-base-h.md#oh_avtranscoder_onerror) callback | Callback invoked when an error occurs during the transcoding process. For details, see [OH_AVTranscoder_OnError](capi-avtranscoder-base-h.md#oh_avtranscoder_onerror).|
| void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The registration is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** or **callback** is nullptr.|

### OH_AVTranscoder_SetProgressUpdateCallback()

```
OH_AVErrCode OH_AVTranscoder_SetProgressUpdateCallback(OH_AVTranscoder *transcoder, OH_AVTranscoder_OnProgressUpdate callback, void *userData)
```

**Description**

Registers a callback for transcoding progress update events.

This callback is invoked when the progress of the transcoding process is updated.

An application can subscribe to only one transcoding error event. When the application initiates multiple subscriptions to this event, the last subscription is applied.

The callback must be registered before [OH_AVTranscoder_Prepare](#oh_avtranscoder_prepare) is called.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance, which is created by running [OH_AVTranscoder_Create](#oh_avtranscoder_create).|
| [OH_AVTranscoder_OnProgressUpdate](capi-avtranscoder-base-h.md#oh_avtranscoder_onprogressupdate) callback | Callback invoked when the progress of the transcoding process is updated. For details, see [OH_AVTranscoder_OnProgressUpdate](capi-avtranscoder-base-h.md#oh_avtranscoder_onprogressupdate).|
| void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The registration is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **transcoder** or **callback** is nullptr.|
