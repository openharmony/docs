# native_audio_session_manager.h


## 概述

声明音频会话管理相关的接口。

包含创建音频会话管理器、激活/停用音频会话、检查音频会话是否已激活，以及监听音频会话停用事件。

**库：** libohaudio.so

**引用文件**：&lt;ohaudio/native_audio_session_manager.h&gt;

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**相关模块：**[OHAudio](_o_h_audio.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) | 音频会话策略。  | 
| struct  [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) | 音频会话已停用事件。  | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) [OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) | 声明音频会话管理器。  | 
| typedef struct [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) [OH_AudioSession_Strategy](_o_h_audio.md#oh_audiosession_strategy) | 音频会话策略。  | 
| typedef struct [OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) [OH_AudioSession_DeactivatedEvent](_o_h_audio.md#oh_audiosession_deactivatedevent) | 音频会话已停用事件。  | 
| typedef int32_t (\*[OH_AudioSession_DeactivatedCallback](_o_h_audio.md#oh_audiosession_deactivatedcallback))([OH_AudioSession_DeactivatedEvent](_o_h___audio_session___deactivated_event.md) event) | 这个函数指针将指向用于监听音频会话停用事件的回调函数。  | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioSession_ConcurrencyMode](_o_h_audio.md#oh_audiosession_concurrencymode) { <br/>CONCURRENCY_DEFAULT = 0, <br/>CONCURRENCY_MIX_WITH_OTHERS = 1, <br/>CONCURRENCY_DUCK_OTHERS = 2, <br/>CONCURRENCY_PAUSE_OTHERS = 3 <br/>} | 音频并发模式。  | 
| [OH_AudioSession_DeactivatedReason](_o_h_audio.md#oh_audiosession_deactivatedreason) { <br/>DEACTIVATED_LOWER_PRIORITY = 0, <br/>DEACTIVATED_TIMEOUT = 1 <br/>} | 音频会话停用原因。  | 

### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioManager_GetAudioSessionManager](_o_h_audio.md#oh_audiomanager_getaudiosessionmanager)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*\*audioSessionManager) | 获取音频会话管理器。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_ActivateAudioSession](_o_h_audio.md#oh_audiosessionmanager_activateaudiosession)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager, const [OH_AudioSession_Strategy](_o_h___audio_session___strategy.md) \*strategy) | 激活音频会话。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_DeactivateAudioSession](_o_h_audio.md#oh_audiosessionmanager_deactivateaudiosession)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager) | 停用音频会话。  | 
| bool [OH_AudioSessionManager_IsAudioSessionActivated](_o_h_audio.md#oh_audiosessionmanager_isaudiosessionactivated)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager) | 检查音频会话是否已激活。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_RegisterSessionDeactivatedCallback](_o_h_audio.md#oh_audiosessionmanager_registersessiondeactivatedcallback)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](_o_h_audio.md#oh_audiosession_deactivatedcallback) callback) | 注册音频会话停用事件回调。  | 
| [OH_AudioCommon_Result](_o_h_audio.md#oh_audiocommon_result) [OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](_o_h_audio.md#oh_audiosessionmanager_unregistersessiondeactivatedcallback)([OH_AudioSessionManager](_o_h_audio.md#oh_audiosessionmanager) \*audioSessionManager, [OH_AudioSession_DeactivatedCallback](_o_h_audio.md#oh_audiosession_deactivatedcallback) callback) | 取消注册音频会话停用事件回调。  | 
