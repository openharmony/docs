# 使用AudioSession管理应用音频焦点(C/C++)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

对于涉及多个音频流并发播放的场景，系统已预设了默认的[音频焦点策略](audio-playback-concurrency.md#音频焦点策略)，该策略将对所有音频流（包括播放和录制）实施统一的焦点管理。

应用可利用音频会话管理（AudioSessionManager）提供的接口，通过AudioSession主动管理应用内音频流的焦点，自定义本应用音频流的焦点策略，调整本应用音频流释放音频焦点的时机，从而贴合应用特定的使用需求。

本文档主要介绍AudioSession相关C API的使用方法和注意事项，更多音频焦点及音频会话的信息，可参考：[音频焦点和音频会话介绍](audio-playback-concurrency.md)。

## 使用入门

应用要使用OHAudio提供的音频会话管理（AudioSessionManager）能力，需要添加对应的头文件。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

### 添加头文件

应用通过引入[native_audio_session_manager.h](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md)头文件，使用音频播放相关API。

```cpp
#include <ohaudio/native_audio_session_manager.h>
```

## 获取音频会话管理器

创建[OH_AudioSessionManager](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosessionmanager.md)实例。在使用音频会话管理功能前，需要先通过[OH_AudioManager_GetAudioSessionManager](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiomanager_getaudiosessionmanager)创建音频会话管理实例。

  ```cpp
  OH_AudioSessionManager *audioSessionManager;
  OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
  ```

## 激活音频会话

应用可以通过[OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession)接口激活当前应用的音频会话。

应用在[激活音频会话](#激活音频会话)时，需指定[音频会话策略（OH_AudioSession_Strategy）](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-strategy.md)，其中包含[音频并发模式（OH_AudioSession_ConcurrencyMode）](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosession_concurrencymode)参数，用于声明不同的音频并发策略。

  ```cpp
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
  
  OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  ```

## 查询音频会话是否已激活

应用可以通过[OH_AudioSessionManager_IsAudioSessionActivated](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_isaudiosessionactivated)接口检查当前应用的音频会话是否已激活。

  ```cpp
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  ```

## 停用音频会话

应用可以通过[OH_AudioSessionManager_DeactivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_deactivateaudiosession)接口停用当前应用的音频会话。

  ```cpp
  OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```

## 监听音频会话停用事件

在使用AudioSession功能的过程中，推荐应用监听[音频会话停用事件（OH_AudioSession_DeactivatedEvent）](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-deactivatedevent.md)。

当AudioSession被停用（非主动停用）时，应用会收到[音频会话停用事件（OH_AudioSession_DeactivatedEvent）](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-deactivatedevent.md)，其中包含[音频会话停用原因（OH_AudioSession_DeactivatedReason）](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosession_deactivatedreason)。

在收到AudioSessionDeactivatedEvent时，应用可根据自身业务需求，做相应的处理，例如释放相应资源、重新激活AudioSession等。

### 定义回调函数

  ```cpp
  int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
  {
    switch(event.reason) {
      case DEACTIVATED_LOWER_PRIORITY:
        // 应用焦点被抢占。
        return 0;
      case DEACTIVATED_TIMEOUT:
        // 超时。
        return 0;
    }
  }
  ```

### 注册音频会话停用事件回调

应用可以通过[OH_AudioSessionManager_RegisterSessionDeactivatedCallback](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_registersessiondeactivatedcallback)接口监听音频会话停用事件。

```cpp
OH_AudioSessionManager_RegisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
```

### 取消注册音频会话停用事件回调

应用可以通过[OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_unregistersessiondeactivatedcallback)接口取消监听音频会话停用事件。

```cpp
OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
```

**音频会话从创建到激活并监听的完整示例：**

参考以下示例，完成音频会话从创建到激活并监听的过程。

  ```cpp
  #include <cstdint>
  #include "ohaudio/native_audio_session_manager.h"
  
  int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
  {
    switch(event.reason) {
      case DEACTIVATED_LOWER_PRIORITY:
        // 应用焦点被抢占。
        return 0;
      case DEACTIVATED_TIMEOUT:
        // 超时。
        return 0;
    }
  }
  
  OH_AudioSessionManager *audioSessionManager;

  // 创建音频会话管理器。
  OH_AudioCommon_Result resultManager = OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
  
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};

  // 设置音频并发模式并激活音频会话。
  OH_AudioCommon_Result resultActivate = OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  
  // 查询音频会话是否已激活。
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  
  // 监听音频会话停用事件。
  OH_AudioCommon_Result resultRegister = OH_AudioSessionManager_RegisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);

  // 音频会话激活后应用在此处正常执行音频播放、暂停、停止、释放等操作即可。 
  
  // 取消监听音频会话停用事件。
  OH_AudioCommon_Result resultUnregister = OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
  
  // 停用音频会话。
  OH_AudioCommon_Result resultDeactivate = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```
## 通过设置AudioSession场景参数申请焦点
应用通过AudioSession申请焦点。首先要调用接口[OH_AudioSessionManager_SetScene](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_setscene)设置场景参数，然后调用[OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/capi-native-audio-session-manager-h.md#oh_audiosessionmanager_activateaudiosession)接口激活AudioSession。

  ```cpp

  OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);

  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};

  OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  ```

## 监听AudioSession焦点状态变化事件
通过[AudioSession焦点状态事件（OH_AudioSession_StateChangedEvent）](../../reference/apis-audio-kit/capi-ohaudio-oh-audiosession-statechangedevent.md)监听音频会话焦点状态的变化。

**AudioSession申请焦点以及监听焦点变化事件的完整示例：**

  ```cpp

OH_AudioSessionManager *audioSessionManager;

// 创建音频会话管理器。
OH_AudioCommon_Result resultManager = OH_AudioManager_GetAudioSessionManager(&audioSessionManager);

void AudioSessionStateChangedCallback(OH_AudioSession_StateChangedEvent event)
  {
    switch(event.stateChangeHint) {
      case AUDIO_SESSION_STATE_CHANGE_HINT_PAUSE:
        // 此分支表示系统已将音频流暂停（临时失去焦点），为保持状态一致，应用需切换至音频暂停状态。
        // 临时失去焦点：其他音频流释放音频焦点后，本音频流会收到resume事件，可继续播放。
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_RESUME:
        // 此分支表示系统解除对AudioSession焦点的暂停操作。
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_STOP:
        // 此分支表示系统已将音频流停止（永久失去焦点），为保持状态一致，应用需切换至音频暂停状态。
        // 永久失去焦点：后续不会再收到任何音频焦点事件，若想恢复播放，需要用户主动触发。
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_TIME_OUT_STOP:
        // 此分支表示由于长时间没有音频流播放，为防止系统资源被长时间无效占用，系统已将AudioSession停止（永久失去焦点），为保持状态一致，应用需切换至音频暂停状态。
        // 永久失去焦点：后续不会再收到任何音频焦点事件，若想恢复播放，需要用户主动触发。
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_DUCK:
        // 此分支表示系统已将音频音量降低（默认降到正常音量的20%）。
        break;
      case AUDIO_SESSION_STATE_CHANGE_HINT_UNDUCK:
        // 此分支表示系统已将音频音量恢复正常。
        break;
      default:
        break;
      }
  }

  OH_AudioCommon_Result result = OH_AudioSessionManager_RegisterStateChangeCallback(audioSessionManager, AudioSessionStateChangedCallback);

  // AUDIO_SESSION_SCENE_MEDIA 仅为示例，实际使用时请根据具体情况进行修改。
  OH_AudioSessionManager_SetScene(audioSessionManager, AUDIO_SESSION_SCENE_MEDIA);

  // CONCURRENCY_MIX_WITH_OTHERS 是示例，实际使用时请根据情况修改
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};

  result = OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);

  // 根据实际业务，可以启动多个AudioRenderer等音频播放

  result = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);

  result = OH_AudioSessionManager_UnregisterStateChangeCallback(audioSessionManager, AudioSessionStateChangedCallback);

  ```