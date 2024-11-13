# native_audio_common.h


## 概述

声明音频公共基础数据结构。

定义音频接口的公共返回值的类型。

**库：** libohaudio.so

**引用文件**：&lt;ohaudio/native_audio_common.h&gt;

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) {<br/>AUDIOCOMMON_RESULT_SUCCESS = 0,<br/>AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM = 6800101,<br/>AUDIOCOMMON_RESULT_ERROR_NO_MEMORY = 6800102,<br/>AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE = 6800103,<br/>AUDIOCOMMON_RESULT_ERROR_UNSUPPORTED = 6800104,<br/>AUDIOCOMMON_RESULT_ERROR_TIMEOUT = 6800105,<br/>AUDIOCOMMON_RESULT_ERROR_STREAM_LIMIT = 6800201,<br/>AUDIOCOMMON_RESULT_ERROR_SYSTEM = 6800301<br/>} | 音频错误码。 | 
| [OH_AudioScene](_o_h_audio.md#oh_audioscene) { <br/>AUDIO_SCENE_DEFAULT = 0, <br/>AUDIO_SCENE_RINGING = 1, <br/>AUDIO_SCENE_PHONE_CALL = 2, <br/>AUDIO_SCENE_VOICE_CHAT = 3 <br/>} | 定义音频场景。  | 
