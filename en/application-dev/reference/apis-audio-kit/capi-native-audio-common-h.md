# native_audio_common.h
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the common basic audio data structs. It defines the types of the common return values of audio interfaces.

**File to include**: <ohaudio/native_audio_common.h>

**Library**: libohaudio.so

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](capi-ohaudio.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioCommon_Result](#oh_audiocommon_result) | OH_AudioCommon_Result | Enumerates the audio operation results.|
| [OH_AudioScene](#oh_audioscene) | OH_AudioScene | Enumerates the audio scenes.|
| [OH_AudioRingerMode](#oh_audioringermode) | OH_AudioRingerMode | Enumerates the ringer mode.|

## Enum Description

### OH_AudioCommon_Result

```
enum OH_AudioCommon_Result
```

**Description**

Enumerates the audio operation results.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| AUDIOCOMMON_RESULT_SUCCESS = 0 | Operation successful.|
| AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101 | Incorrect parameter.|
| AUDIOCOMMON_RESULT_ERROR_NO_MEMORY = 6800102 | No memory.|
| AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE = 6800103 | Invalid state.|
| AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED = 6800104 | Unsupported operation.|
| AUDIOCOMMON_RESULT_ERROR_TIMEOUT = 6800105 | Operation timeout.|
| AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT = 6800201 | Reached the maximum number of audio streams allowed.|
| AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301 | System error.|

### OH_AudioScene

```
enum OH_AudioScene
```

**Description**

Enumerates the audio scenes.

**Since**: 12

| Enum Item| Description|
| -- | -- |
| AUDIO_SCENE_DEFAULT = 0 | Default audio scene.|
| AUDIO_SCENE_RINGING = 1 | Ringing scene.|
| AUDIO_SCENE_PHONE_CALL = 2 | Phone call scene.|
| AUDIO_SCENE_VOICE_CHAT = 3 | Voice chat scene.|

### OH_AudioRingerMode

```
enum OH_AudioRingerMode
```

**Description**

Enumerates the ringer mode.

**Since**: 20

| Enum Item| Description|
| -- | -- |
| AUDIO_RINGER_MODE_SILENT = 0 | Silent mode.|
| AUDIO_RINGER_MODE_VIBRATE = 1 | Vibration mode.|
| AUDIO_RINGER_MODE_NORMAL = 2 | Normal mode.|
