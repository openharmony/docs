# 音频会话管理(C/C++)

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

应用在[激活音频会话](#激活音频会话)时，需指定[音频会话策略（OH_AudioSession_Strategy）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_strategy)，其中包含[音频并发模式（OH_AudioSession_ConcurrencyMode）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_concurrencymode)参数，用于声明不同的音频并发策略。

  ```cpp
  OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
  
  OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
  ```

## 查询音频会话是否已激活

应用可以通过[OH_AudioSessionManager_IsAudioSessionActivated](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager_isaudiosessionactivated)接口检查当前应用的音频会话是否已激活。

  ```cpp
  bool isActivated = OH_AudioSessionManager_IsAudioSessionActivated(audioSessionManager);
  ```

## 停用音频会话

应用可以通过[OH_AudioSessionManager_DeactivateAudioSession](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosessionmanager_deactivateaudiosession)接口停用当前应用的音频会话。

  ```cpp
  OH_AudioSessionManager_DeactivateAudioSession(audioSessionManager);
  ```

## 监听音频会话停用事件

在使用AudioSession功能的过程中，推荐应用监听[音频会话停用事件（OH_AudioSession_DeactivatedEvent）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_deactivatedevent)。

当AudioSession被停用（非主动停用）时，应用会收到[音频会话停用事件（OH_AudioSession_DeactivatedEvent）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_deactivatedevent)。，其中包含[音频会话停用原因（OH_AudioSession_DeactivatedReason）](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiosession_deactivatedreason)。

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
