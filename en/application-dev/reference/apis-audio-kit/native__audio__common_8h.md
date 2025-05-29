# native_audio_common.h


## Overview

The **native_audio_common.h** file declares the common basic audio data structs.

It defines the types of the common return values of audio interfaces.

**Library**: libohaudio.so

**File to include**: &lt;ohaudio/native_audio_common.h&gt;

**System capability**: SystemCapability.Multimedia.Audio.Core

**Since**: 12

**Related module**: [OHAudio](_o_h_audio.md)


## Summary


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) {<br>AUDIOCOMMON_RESULT_SUCCESS = 0,<br>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101,<br>AUDIOCOMMON_RESULT_ERROR_NO_MEMORY = 6800102,<br>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE = 6800103,<br>AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED = 6800104,<br>AUDIOCOMMON_RESULT_ERROR_TIMEOUT = 6800105,<br>AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT = 6800201,<br>AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301<br>} | Enumerates the audio operation results.| 
| [OH_AudioScene](_o_h_audio.md#oh_audioscene) { <br>AUDIO_SCENE_DEFAULT = 0, <br>AUDIO_SCENE_RINGING = 1, <br>AUDIO_SCENE_PHONE_CALL = 2, <br>AUDIO_SCENE_VOICE_CHAT = 3 <br>} | Enumerates the audio scenes. | 
