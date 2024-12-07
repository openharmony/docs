# native_audio_manager.h


## 概述

声明音频管理相关的接口。

**库：** libohaudio.so

**引用文件**：&lt;ohaudio/native_audio_manager.h&gt;

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AudioManager](_o_h_audio.md#oh_audiomanager) [OH_AudioManager](_o_h_audio.md#oh_audiomanager) | 声明音频管理器。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_GetAudioManager](_o_h_audio.md#oh_getaudiomanager) ([OH_AudioManager](_o_h_audio.md#oh_audiomanager) \*\*audioManager) | 获取音频管理器。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_GetAudioScene](_o_h_audio.md#oh_getaudioscene) ([OH_AudioManager](_o_h_audio.md#oh_audiomanager) \*manager, [OH_AudioScene](_o_h_audio.md#oh_audioscene) \*scene) | 获取音频场景模式。  | 
