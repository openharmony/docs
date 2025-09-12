# 音频工作组管理
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

音频工作组是一套通过标记来帮助系统识别应用内音频关键线程的接口，系统通过应用提供的关键音频线程以及工作组运行信息可以让音频线程的运行状态更加健康。

## 使用说明

对于播放音频类应用，开发者需要先创建音频工作组，再将工作组运行信息的周期性告知系统。当工作结束后，需要对音频工作组进行清理。

### 创建音频工作组示例

开发者在使用OH_AudioWorkgroup的API前，需要先用[OH_AudioManager_GetAudioResourceManager](../../reference/apis-audio-kit/capi-native-audio-resource-manager-h.md#oh_audiomanager_getaudioresourcemanager)获取OH_AudioResourceManager实例。

  ```cpp
  #include <ohaudio/native_audio_resource_manager.h>

  OH_AudioResourceManager *resMgr;
  OH_AudioManager_GetAudioResourceManager(&resMgr);
  ```

### 创建音频工作组并将关键线程加入音频工作组

开发者先使用[OH_AudioResourceManager_CreateWorkgroup](../../reference/apis-audio-kit/capi-native-audio-resource-manager-h.md#oh_audioresourcemanager_createworkgroup)创建一个新的音频工作组，再使用[OH_AudioWorkgroup_AddCurrentThread](../../reference/apis-audio-kit/capi-native-audio-resource-manager-h.md#oh_audioworkgroup_addcurrentthread)将关键线程加入音频工作组。

  ```cpp
  #include <chrono>

  int32_t tokenId;
  OH_AudioWorkgroup *grp = nullptr;

  OH_AudioResourceManager_CreateWorkgroup(resMgr, "workgroup", &grp);
  OH_AudioWorkgroup_AddCurrentThread(grp, &tokenId);
  ```

### 通知系统音频工作组的开始与结束

在当音频工作组开始进行一个周期的工作时，开发者可以通知系统任务开始时间和任务预期完成的时间，并在音频工作组结束当前周期内的工作时，通知系统任务已结束。

  ```cpp
  constexpr static uint64_t intervalMs = 20;
  bool threadShouldRun = true;

  while (threadShouldRun) {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto startTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();

    OH_AudioWorkgroup_Start(grp, startTimeMs, startTimeMs + intervalMs);
    
    // 应用音频数据处理。

    OH_AudioWorkgroup_Stop(grp);
  }
  ```

### 工作组任务结束后进行清理

  ```cpp
  // 当线程已经不需要接入分组时，将其从工作组中移除。
  OH_AudioWorkgroup_RemoveThread(grp, tokenId);

  OH_AudioResourceManager_ReleaseWorkgroup(resMgr, grp);
  grp = nullptr;
  ```