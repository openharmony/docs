# native_audio_manager.h

## 概述

声明音频管理相关的接口。

**引用文件：** <ohaudio/native_audio_manager.h>

**库：** libohaudio.so

**系统能力：** SystemCapability.Multimedia.Audio.Core

**起始版本：** 12

**相关模块：** [OHAudio](capi-ohaudio.md)

## 汇总

### 结构体

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [OH_AudioManager](capi-ohaudio-oh-audiomanager.md) | OH_AudioManager | 声明音频管理器。用于管理音频管理相关功能。 |

### 函数

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [typedef void (\*OH_AudioManager_OnAudioSceneChangeCallback)(void *userData,OH_AudioScene scene)](#oh_audiomanager_onaudioscenechangecallback) | OH_AudioManager_OnAudioSceneChangeCallback | 音频场景变化回调函数的原型定义，用于传递给[OH_AudioManager_RegisterAudioSceneChangeCallback](capi-native-audio-manager-h.md#oh_audiomanager_registeraudioscenechangecallback)。 |
| [OH_AudioCommon_Result OH_GetAudioManager(OH_AudioManager **audioManager)](#oh_getaudiomanager) | - | 获取音频管理器。<br> 使用音频管理器相关功能，首先需要获取音频管理器实例。 |
| [OH_AudioCommon_Result OH_GetAudioScene(OH_AudioManager* manager, OH_AudioScene *scene)](#oh_getaudioscene) | - | 获取音频场景模式。 |
| [OH_AudioCommon_Result OH_AudioManager_RegisterAudioSceneChangeCallback(OH_AudioManager *manager,OH_AudioManager_OnAudioSceneChangeCallback callback, void *userData)](#oh_audiomanager_registeraudioscenechangecallback) | - | 注册音频场景切换回调函数。 |
| [OH_AudioCommon_Result OH_AudioManager_UnregisterAudioSceneChangeCallback(OH_AudioManager *manager,OH_AudioManager_OnAudioSceneChangeCallback callback)](#oh_audiomanager_unregisteraudioscenechangecallback) | - | 取消注册音频场景切换回调函数。 |

## 函数说明

### OH_AudioManager_OnAudioSceneChangeCallback()

```
typedef void (*OH_AudioManager_OnAudioSceneChangeCallback) (void *userData, OH_AudioScene scene)
```

**描述**

音频场景变化回调函数的原型定义，用于传递给[OH_AudioManager_RegisterAudioSceneChangeCallback](capi-native-audio-manager-h.md#oh_audiomanager_registeraudioscenechangecallback)。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| void *userData | 用户自定义数据指针。 |
| [OH_AudioScene](capi-native-audio-common-h.md#oh_audioscene) scene | 切换后的音频场景。 |

### OH_GetAudioManager()

```
OH_AudioCommon_Result OH_GetAudioManager(OH_AudioManager **audioManager)
```

**描述**

获取音频管理器。<br> 使用音频管理器相关功能，首先需要获取音频管理器实例。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioManager](capi-ohaudio-oh-audiomanager.md) **audioManager | 指向[OH_AudioManager](capi-ohaudio-oh-audiomanager.md)用于接收创建的音频管理器实例。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：参数audioManager为nullptr。 |

### OH_GetAudioScene()

```
OH_AudioCommon_Result OH_GetAudioScene(OH_AudioManager* manager, OH_AudioScene *scene)
```

**描述**

获取音频场景模式。

**起始版本：** 12


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioManager](capi-ohaudio-oh-audiomanager.md)* manager | 指向[OH_GetAudioManager](capi-native-audio-manager-h.md#oh_getaudiomanager)创建的音频管理器实例：[OH_AudioManager](capi-ohaudio-oh-audiomanager.md)。 |
| [OH_AudioScene](capi-native-audio-common-h.md#oh_audioscene) *scene | 指向[OH_AudioScene](capi-native-audio-common-h.md#oh_audioscene)用于接收返回的音频场景模式。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：<br>                                                        1.参数audioManager为nullptr;<br>                                                        2.参数scene为nullptr。 |

### OH_AudioManager_RegisterAudioSceneChangeCallback()

```
OH_AudioCommon_Result OH_AudioManager_RegisterAudioSceneChangeCallback(OH_AudioManager *manager,OH_AudioManager_OnAudioSceneChangeCallback callback, void *userData)
```

**描述**

注册音频场景切换回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioManager](capi-ohaudio-oh-audiomanager.md) *manager | 指向[OH_AudioManager](capi-ohaudio-oh-audiomanager.md)用于接收创建的音频管理器实例。 |
| [OH_AudioManager_OnAudioSceneChangeCallback](capi-native-audio-manager-h.md#oh_audiomanager_onaudioscenechangecallback) callback | 当音频场景切换时，将调用此回调函数[OH_AudioManager_OnAudioSceneChangeCallback](capi-native-audio-manager-h.md#oh_audiomanager_onaudioscenechangecallback)。 |
| void *userData | 用户自定义数据指针。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：<br>                                                    1.参数manager为nullptr；<br>                                                    2.参数callback为nullptr。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：系统错误。 |

### OH_AudioManager_UnregisterAudioSceneChangeCallback()

```
OH_AudioCommon_Result OH_AudioManager_UnregisterAudioSceneChangeCallback(OH_AudioManager *manager,OH_AudioManager_OnAudioSceneChangeCallback callback)
```

**描述**

取消注册音频场景切换回调函数。

**起始版本：** 20


**参数：**

| 参数项 | 描述 |
| -- | -- |
| [OH_AudioManager](capi-ohaudio-oh-audiomanager.md) *manager | 指向[OH_AudioManager](capi-ohaudio-oh-audiomanager.md)用于接收创建的音频管理器实例。 |
| [OH_AudioManager_OnAudioSceneChangeCallback](capi-native-audio-manager-h.md#oh_audiomanager_onaudioscenechangecallback) callback | 指向[OH_AudioManager_OnAudioSceneChangeCallback](capi-native-audio-manager-h.md#oh_audiomanager_onaudioscenechangecallback)传入的回调函数，用于取消注册。 |

**返回：**

| 类型 | 说明 |
| -- | -- |
| [OH_AudioCommon_Result](capi-native-audio-common-h.md#oh_audiocommon_result) | AUDIOCOMMON_RESULT_SUCCESS：函数执行成功。<br>         AUDIOCOMMON_RESULT_ERROR_INVALID_PARAM：<br>                                                    1.参数manager为nullptr；<br>                                                    2.参数callback为nullptr。<br>         AUDIOCOMMON_RESULT_ERROR_SYSTEM：系统错误。 |


