# 音频会话管理(C/C++)

**对于多个音频流并发的场景，系统预设了默认的[音频焦点策略](./audio-playback-concurrency.md#音频焦点策略)，会对所有音频流（包含播放和录制）进行统一的焦点管理。**

**应用可以使用音频会话管理（AudioSessionManager）的相关接口，通过AudioSession主动管理本应用音频流的焦点，定制本应用音频流的焦点策略，修改本应用音频流释放音频焦点的时机，以满足应用特定的使用场景。**

本文主要介绍AudioSession相关C/C++接口的使用方法和注意事项，更多音频焦点及音频会话的信息，可参考：[音频焦点和音频会话介绍](./audio-playback-concurrency.md)

## 使用入门

应用要使用OHAudio提供的音频会话管理（AudioSessionManager）能力，需要添加对应的头文件。

### 在 CMake 脚本中链接动态库

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

### 添加头文件

应用通过引入[native_audio_session_manager.h](../../reference/apis-audio-kit/native__audio__session__manager_8h.md)头文件，使用音频播放相关API。

```cpp
#include <ohaudio/native_audio_session_manager.h>
```

## 获取音频会话管理器

创建[OH_AudioSessionManager](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager)实例。在使用音频会话管理功能前，需要先通过[OH_AudioManager_GetAudioSessionManager](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiomanager_getaudiosessionmanager)创建音频会话管理实例。

  ```cpp
  OH_AudioSessionManager *audioSessionManager;
  OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
  ```

## 激活音频会话

应用可以通过[OH_AudioSessionManager_ActivateAudioSession](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager_activateaudiosession)接口激活当前应用的音频会话。

  ```cpp
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
  
  OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  ```

## 停用音频会话

应用可以通过[OH_AudioSessionManager_DeactivateAudioSession](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager_deactivateaudiosession)接口停用当前应用的音频会话。

  ```cpp
  OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```

## 音频会话策略

应用在[激活音频会话](#激活音频会话)时，需指定[音频会话策略（OH_AudioSession_Strategy）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_strategy)，其中包含[音频并发模式（OH_AudioSession_ConcurrencyMode）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_concurrencymode)参数，用于声明不同的音频并发策略。

系统预设了以下4种音频并发模式：

- 默认模式（CONCURRENCY_DEFAULT）：即系统默认的[音频焦点策略](./audio-playback-concurrency.md#音频焦点策略)。

- 并发模式（CONCURRENCY_MIX_WITH_OTHERS）：和其它音频流并发。

- 降低音量模式（CONCURRENCY_DUCK_OTHERS）：和其他音频流并发，并且降低其他音频流的音量。

- 暂停模式（CONCURRENCY_PAUSE_OTHERS）：暂停其他音频流，待释放焦点后通知其他音频流恢复。

注意：AudioSession使用以上各模式时，系统会最大程度满足其焦点策略，但并不一定能在所有场景都能满足。

例如：使用CONCURRENCY_PAUSE_OTHERS模式时，Movie流申请音频焦点，如果Music流正在播放，则Music流会被暂停。但是如果VoiceCommunication流正在播放，则VoiceCommunication流不会被暂停。

## 查询音频会话是否已激活。

应用可以通过[OH_AudioSessionManager_IsAudioSessionActivated](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager_isaudiosessionactivated)接口检查当前应用的音频会话是否已激活。

  ```cpp
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  ```

## 注册音频会话停用事件回调&取消注册音频会话停用事件回调

在使用AudioSession功能的过程中，推荐应用监听[音频会话停用事件（OH_AudioSession_DeactivatedEvent）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_deactivatedevent)。

当AudioSession被停用（非主动停用）时，应用会收到[音频会话停用事件（OH_AudioSession_DeactivatedEvent）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_deactivatedevent)。，其中包含[音频会话停用原因（OH_AudioSession_DeactivatedReason）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_deactivatedreason)。

系统预设了以下2种音频会话停用原因：

- 应用焦点被抢占（DEACTIVATED_LOWER_PRIORITY）：该应用所有的音频流全部被其他音频流打断，丢失焦点，AudioSession被同时停用。

- 超时（DEACTIVATED_TIMEOUT）：若AudioSession处于激活状态，但该应用没有音频流在运行状态，则AudioSession会在1分钟之后被超时停用。

  注意：当AudioSession因超时而停用时，被其压低音量（Duck）的音频会触发恢复音量（Unduck）操作，被其暂停（Pause）的音频流会触发停止（Stop）操作。

在收到AudioSessionDeactivatedEvent时，应用可根据自身业务需求，做相应的处理，例如释放相应资源、重新激活AudioSession等。

### 定义回调函数

  ```cpp
  int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
  {
    switch(event.reason) {
      case DEACTIVATED_LOWER_PRIORITY:
        // 应用焦点被抢占
        return 0;
      case DEACTIVATED_TIMEOUT:
        // 超时
        return 0;
    }
  }
  ```

### 注册音频会话停用事件回调
应用可以通过[OH_AudioSessionManager_RegisterSessionDeactivatedCallback](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager_registersessiondeactivatedcallback)接口监听音频会话停用事件。

  ```cpp
  OH_AudioSessionManager_RegisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
  ```

### 取消注册音频会话停用事件回调

应用可以通过[OH_AudioSessionManager_UnregisterSessionDeactivatedCallback](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager_unregistersessiondeactivatedcallback)接口取消监听音频会话停用事件。

  ```cpp
  OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
  ```

## 完整示例

参考以下示例，完成音频会话从创建到激活并监听的过程。

  ```cpp
  #include <cstdint>
  #include "ohaudio/native_audio_session_manager.h"
  
  int32_t MyAudioSessionDeactivatedCallback(OH_AudioSession_DeactivatedEvent event)
  {
    switch(event.reason) {
      case DEACTIVATED_LOWER_PRIORITY:
        // 应用焦点被抢占
        return 0;
      case DEACTIVATED_TIMEOUT:
        // 超时
        return 0;
    }
  }
  
  OH_AudioSessionManager *audioSessionManager;

  // 创建音频会话管理器
  OH_AudioCommon_Result resultManager = OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
  
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};

  // 设置音频并发模式并激活音频会话
  OH_AudioCommon_Result resultActivate = OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  
  // 查询音频会话是否已激活。
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  
  // 监听音频会话停用事件
  OH_AudioCommon_Result resultRegister = OH_AudioSessionManager_RegisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);

  // 音频会话激活后应用在此处正常执行音频播放、暂停、停止、释放等操作即可。 
  
  // 取消监听音频会话停用事件
  OH_AudioCommon_Result resultUnregister = OH_AudioSessionManager_UnregisterSessionDeactivatedCallback(audioSessionManager, MyAudioSessionDeactivatedCallback);
  
  // 停用音频会话
  OH_AudioCommon_Result resultDeactivate = OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```