# native_audio_session_manager.h

## 概述

声明音频会话管理相关的接口。

包含创建音频会话管理器、激活/停用音频会话、检查音频会话是否已激活，以及监听音频会话停用事件。

**库：** libohaudio.so

**引用文件：** <ohaudio/native_audio_session_manager.h>

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**相关模块：** [OHAudio](capi-ohaudio.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioSession_Strategy](capi-oh-audiosession-strategy.md) | OH_AudioSession_Strategy | 音频会话策略。 |
| [OH_AudioSession_DeactivatedEvent](capi-oh-audiosession-deactivatedevent.md) | OH_AudioSession_DeactivatedEvent | 音频会话已停用事件。 |
| [OH_AudioSessionManager](capi-oh-audiosessionmanager.md) | OH_AudioSessionManager | 声明音频会话管理器。<br>用于管理音频会话相关功能。 |

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioSession_ConcurrencyMode](#oh_audiosession_concurrencymode) | OH_AudioSession_ConcurrencyMode | 音频并发模式。 |
| [OH_AudioSession_DeactivatedReason](#oh_audiosession_deactivatedreason) | OH_AudioSession_DeactivatedReason | 音频会话停用原因。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef int32_t (\*OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)](#oh_audiosession_deactivatedcallback) | OH_AudioSession_DeactivatedCallback | 这个函数指针将指向用于监听音频会话停用事件的回调函数。 |
| [OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager(OH_AudioSessionManager **audioSessionManager)](#oh_audiomanager_getaudiosessionmanager) | - | 获取音频会话管理器。使用音频会话管理器相关功能，首先需要获取音频会话管理器实例。 |
| [OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession(OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy)](#oh_audiosessionmanager_activateaudiosession) | - | 激活音频会话。 |
| [OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession(OH_AudioSessionManager *audioSessionManager)](#oh_audiosessionmanager_deactivateaudiosession) | - | 停用音频会话。 |
| [bool OH_AudioSessionManager_IsAudioSessionActivated(OH_AudioSessionManager *audioSessionManager)](#oh_audiosessionmanager_isaudiosessionactivated) | - | 检查音频会话是否已激活。 |
| [OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)](#oh_audiosessionmanager_registersessiondeactivatedcallback) | - | 注册音频会话停用事件回调。 |
| [OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)](#oh_audiosessionmanager_unregistersessiondeactivatedcallback) | - | 取消注册音频会话停用事件回调。 |

## 枚举类型说明

### OH_AudioSession_ConcurrencyMode

```
enum OH_AudioSession_ConcurrencyMode
```

**描述**

音频并发模式。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| CONCURRENCY_DEFAULT = 0 | 默认使用系统策略。 |
| CONCURRENCY_MIX_WITH_OTHERS = 1 | 和其它正在播放应用进行混音。 |
| CONCURRENCY_DUCK_OTHERS = 2 | 后来播放应用压低正在播放应用的音量。 |
| CONCURRENCY_PAUSE_OTHERS = 3 | 后来播放应用暂停正在播放应用。 |

### OH_AudioSession_DeactivatedReason

```
enum OH_AudioSession_DeactivatedReason
```

**描述**

音频会话停用原因。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| DEACTIVATED_LOWER_PRIORITY = 0 | 应用焦点被抢占。 |
| DEACTIVATED_TIMEOUT = 1 | 应用停流后超时。 |


## 函数说明

### OH_AudioSession_DeactivatedCallback()

```
typedef int32_t (*OH_AudioSession_DeactivatedCallback)(OH_AudioSession_DeactivatedEvent event)
```

**描述**

这个函数指针将指向用于监听音频会话停用事件的回调函数。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSession_DeactivatedEvent](capi-oh-audiosession-deactivatedevent.md) event | 指向OH_AudioSession_Deactivated_Event音频会话已停用事件。 |

### OH_AudioManager_GetAudioSessionManager()

```
OH_AudioCommon_Result OH_AudioManager_GetAudioSessionManager(OH_AudioSessionManager **audioSessionManager)
```

**描述**

获取音频会话管理器。

使用音频会话管理器相关功能，首先需要获取音频会话管理器实例。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSessionManager](capi-oh-audiosessionmanager.md) **audioSessionManager | 指向OH_AudioSessionManager音频会话管理器实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS： 函数执行成功。<br>        AUDIOCOMMON_RESULT_ERROR_SYSTEM：系统错误。 |

### OH_AudioSessionManager_ActivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_ActivateAudioSession(OH_AudioSessionManager *audioSessionManager, const OH_AudioSession_Strategy *strategy)
```

**描述**

激活音频会话。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSessionManager](capi-oh-audiosessionmanager.md) *audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例。 |
| const [OH_AudioSession_Strategy](capi-oh-audiosession-strategy.md) *strategy | 指向[OH_AudioSession_Strategy](capi-oh-audiosession-strategy.md)，用于设置音频会话策略。                                                                                                                           |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |         AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：<br>                                                        1. 参数audioSessionManager为nullptr；<br>                                                        2. 参数strategy无效。<br>         AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：非法状态。 |

### OH_AudioSessionManager_DeactivateAudioSession()

```
OH_AudioCommon_Result OH_AudioSessionManager_DeactivateAudioSession(OH_AudioSessionManager *audioSessionManager)
```

**描述**

停用音频会话。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSessionManager](capi-oh-audiosessionmanager.md) *audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |         AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数audioSessionManager为nullptr。<br>         AUDIOCOMMON_RESULT_ERROR_ILLEGAL_STATE：非法状态。 |

### OH_AudioSessionManager_IsAudioSessionActivated()

```
bool OH_AudioSessionManager_IsAudioSessionActivated(OH_AudioSessionManager *audioSessionManager)
```

**描述**

检查音频会话是否已激活。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSessionManager](capi-oh-audiosessionmanager.md) *audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| bool | 用于返回当前应用的音频会话是否已激活，true表示已激活，false表示已停用。 |

### OH_AudioSessionManager_RegisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_RegisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**描述**

注册音频会话停用事件回调。

**起始版本：** 12

**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSessionManager](capi-oh-audiosessionmanager.md) *audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例。 |
| [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback | 指向OH_AudioSessionDeactivatedCallback，用于接收音频会话已停用事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |         AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：<br>                                                        1. 参数audioSessionManager为nullptr；<br>                                                        2. 参数callback为nullptr。 |

### OH_AudioSessionManager_UnregisterSessionDeactivatedCallback()

```
OH_AudioCommon_Result OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(OH_AudioSessionManager *audioSessionManager, OH_AudioSession_DeactivatedCallback callback)
```

**描述**

取消注册音频会话停用事件回调。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioSessionManager](capi-oh-audiosessionmanager.md) *audioSessionManager | 指向[OH_AudioManager_GetAudioSessionManager](#oh_audiomanager_getaudiosessionmanager)创建的音频会话管理实例。 |
| [OH_AudioSession_DeactivatedCallback](#oh_audiosession_deactivatedcallback) callback | 指向OH_AudioSessionDeactivatedCallback，用于接收音频会话已停用事件。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) |         AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：<br>                                                        1. 参数audioSessionManager为nullptr；<br>                                                        2. 参数callback为nullptr。 |


