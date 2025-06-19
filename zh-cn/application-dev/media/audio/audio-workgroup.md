# 音频工作组管理

音频工作组是一套通过标记来帮助系统识别应用内音频关键线程的接口，系统通过应用提供的关键音频线程以及工作组运行信息可以让音频线程的运行状态更加健康。

## 使用说明

对于播放音频类的应用，开发者首先创建音频工作组，然后将工作组运行信息周期性的告知系统，在工作结束后，需要进行音频工作组的清理。

### 创建音频工作组示例

应用开发者在使用OH_AudioWorkgroup的API前，需要先用[OH_AudioManager_GetAudioResourceManager]获取OH_AudioResourceManager实例。

  ```cpp
  #include <ohaudio/native_audio_resource_manager.h>

  OH_AudioResourceManager *resMgr;
  OH_AudioManager_GetAudioResourceManager(&resMgr);
  ```

### 创建音频工作组并将关键线程加入音频工作组

应用开发者可以使用[OH_AudioResourceManager_CreateWorkgroup]创建一个新的音频工作组，然后使用[OH_AudioWorkgroup_AddCurrentThread]将关键线程加入工作组。

  ```cpp
  #include <chrono>

  int32_t tokenId;
  OH_AudioWorkgroup *grp = nullptr;

  OH_AudioResourceManager_CreateWorkgroup(resMgr, "workgroup", &grp);
  OH_AudioWorkgroup_AddCurrentThread(grp, &tokenId);
  ```

### 通知系统音频工作组的开始与结束

应用开发者可以在音频工作组开始一个周期的工作时，通知系统任务开始时间以及任务预期完成工作的时间，并在音频工作组结束当前周期内的工作时，通知系统任务已结束。

  ```cpp
  constexpr static uint64_t intervalMs = 20;
  bool threadShouldRun = true;

  while (threadShouldRun) {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto startTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();

    OH_AudioWorkgroup_Start(grp, startTimeMs, startTimeMs + intervalMs);
    
    // audio data processing work.

    OH_AudioWorkgroup_Stop(grp);
  }
  ```

### 工作组任务结束后进行清理

  ```cpp
  // remove thread from workgroup when thread is not needed.
  OH_AudioWorkgroup_RemoveThread(grp, tokenId);

  OH_AudioResourceManager_ReleaseWorkgroup(resMgr, grp);
  grp = nullptr;
  ```