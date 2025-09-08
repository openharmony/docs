# avtranscoder_base.h
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the struct and enums used by the AVTranscoder.

**File to include**: <multimedia/player_framework/avtranscoder_base.h>

**Library**: libavtranscoder.so

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20

**Related module**: [AVTranscoder](capi-avtranscoder.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) | OH_AVTranscoder | Initializes an AVTranscoder.|
| [OH_AVTranscoder_Config](capi-avtranscoder-oh-avtranscoder-config.md) | OH_AVTranscoder_Config | Initializes an AVTranscoder_Config.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVTranscoder_State](#oh_avtranscoder_state) | OH_AVTranscoder_State | Enumerates the transcoding states.|

### Functions

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [typedef void (\*OH_AVTranscoder_OnStateChange)(OH_AVTranscoder *transcoder, OH_AVTranscoder_State state, void *userData)](#oh_avtranscoder_onstatechange) | OH_AVTranscoder_OnStateChange | Defines a callback invoked when the state of the transcoding process changes.|
| [typedef void (\*OH_AVTranscoder_OnError)(OH_AVTranscoder *transcoder, int32_t errorCode, const char *errorMsg, void *userData)](#oh_avtranscoder_onerror) | OH_AVTranscoder_OnError | Defines a callback invoked when an error occurs during the transcoding process.|
| [typedef void (\*OH_AVTranscoder_OnProgressUpdate)(OH_AVTranscoder *transcoder, int32_t progress, void *userData)](#oh_avtranscoder_onprogressupdate) | OH_AVTranscoder_OnProgressUpdate | Defines a callback invoked when the progress of the transcoding process is updated.|

## Enum Description

### OH_AVTranscoder_State

```
enum OH_AVTranscoder_State
```

**Description**

Enumerates the transcoding states.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20

| Enum Item| Description|
| -- | -- |
| AVTRANSCODER_PREPARED = 1 | The transcoding process is prepared and ready to start.|
| AVTRANSCODER_STARTED = 2 | The transcoding process has started.|
| AVTRANSCODER_PAUSED = 3 | The transcoding process is paused.|
| AVTRANSCODER_CANCELLED = 4 | The transcoding process has been canceled.|
| AVTRANSCODER_COMPLETED = 5 | The transcoding process is completed.|


## Function Description

### OH_AVTranscoder_OnStateChange()

```
typedef void (*OH_AVTranscoder_OnStateChange)(OH_AVTranscoder *transcoder, OH_AVTranscoder_State state, void *userData)
```

**Description**

Defines a callback invoked when the state of the transcoding process changes.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance.|
| [OH_AVTranscoder_State](#oh_avtranscoder_state) state | Transcoding state. For details, see [OH_AVTranscoder_State](#oh_avtranscoder_state).|
|  void *userData | Pointer to user-defined data.|

### OH_AVTranscoder_OnError()

```
typedef void (*OH_AVTranscoder_OnError)(OH_AVTranscoder *transcoder, int32_t errorCode, const char *errorMsg,void *userData)
```

**Description**

Defines a callback invoked when an error occurs during the transcoding process.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance.|
| int32_t errorCode | Error code.<br>                  **AV_ERR_NO_MEMORY**: No memory. The value is **1**.<br>                  **AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed. The value is **2**.<br>                  **AV_ERR_INVALID_VAL**: The parameter check fails. The value is **3**.<br>                  **AV_ERR_IO**: I/O error. The value is **4**.<br>                  **AV_ERR_INVALID_STATE**: The operation is not supported in the current state. The value is **8**.<br>                  **AV_ERR_UNSUPPORT**: The function is not supported. The value is **9**.|
| const char *errorMsg | Pointer to the error message.|
| void *userData | Pointer to user-defined data.|

### OH_AVTranscoder_OnProgressUpdate()

```
typedef void (*OH_AVTranscoder_OnProgressUpdate)(OH_AVTranscoder *transcoder, int32_t progress, void *userData)
```

**Description**

Defines a callback invoked when the progress of the transcoding process is updated.

**System capability**: SystemCapability.Multimedia.Media.AVTranscoder

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVTranscoder](capi-avtranscoder-oh-avtranscoder.md) *transcoder | Pointer to an OH_AVTranscoder instance.|
| int32_t progress | Transcoding progress.|
| void *userData | Pointer to user-defined data.|
