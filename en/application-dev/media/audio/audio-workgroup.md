# Audio Workgroup Management

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=1ff9e9cd1ebb6561090ad32be99073f8301559bf translatedAt=2026-08-06T10:45:53.123Z pushedAt=2026-08-06T10:56:30.077Z -->

The audio workgroup is a set of APIs that help the system identify critical audio threads within an app through tagging. By providing critical audio threads and workgroup runtime information, the system can improve the stability of audio thread execution.

The following examples are code snippets. For the [complete sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioRendererSampleC), click the link at the bottom right of the example.

## How to Use

For audio playback apps, you need to first create an audio workgroup, and then periodically notify the system of the workgroup runtime information. When the work is complete, clean up the audio workgroup.

### Obtaining an AudioResourceManager Instance

Before calling any API of OH_AudioWorkgroup, you must use [OH_AudioManager_GetAudioResourceManager](../../reference/apis-audio-kit/capi-native-audio-resource-manager-h.md#oh_audiomanager_getaudioresourcemanager) to obtain an OH_AudioResourceManager instance.

<!-- @[GetAudioResourceManager](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

``` C++
#include <ohaudio/native_audio_resource_manager.h>
// ...
OH_AudioResourceManager *resMgr;
// ...
    OH_AudioManager_GetAudioResourceManager(&resMgr);
```

### Creating an Audio Workgroup and Adding Key Threads

Call [OH_AudioResourceManager_CreateWorkgroup](../../reference/apis-audio-kit/capi-native-audio-resource-manager-h.md#oh_audioresourcemanager_createworkgroup) to create an audio workgroup, and then call [OH_AudioWorkgroup_AddCurrentThread](../../reference/apis-audio-kit/capi-native-audio-resource-manager-h.md#oh_audioworkgroup_addcurrentthread) to add key threads to the workgroup.

<!-- @[CreateWorkgroup](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

``` C++
#include <chrono>
// ...
int32_t g_tokenId;
OH_AudioWorkgroup *grp = nullptr;
// ...
    OH_AudioResourceManager_CreateWorkgroup(resMgr, "workgroup", &grp);
    OH_AudioWorkgroup_AddCurrentThread(grp, &g_tokenId);
```

### Notifying the System of Workgroup Start and End

When an audio workgroup begins a cycle of work, you can notify the system of the task's start time and expected end time. When the workgroup finishes its work for the current cycle, notify the system that the task has ended.

<!-- @[OH_AudioWorkgroup_Start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

``` C++
constexpr static uint64_t intervalMs = 20;
bool threadShouldRun = true;

while (threadShouldRun) {
    auto now = std::chrono::system_clock::now().time_since_epoch();
    auto startTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
    OH_AudioWorkgroup_Start(grp, startTimeMs, startTimeMs + intervalMs);
    // This is sample logic. In actual development, control the thread running cycle based on business requirements.
    threadShouldRun = false;
    // Process audio data.
    OH_AudioWorkgroup_Stop(grp);
}
```

### Cleanup After Workgroup Task Completion

<!-- @[OH_AudioWorkgroup_RemoveThread](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioRendererSampleC/entry/src/main/cpp/renderer.cpp) -->

``` C++
// Remove the thread from the workgroup when it no longer needs to participate in workgroup tasks.
OH_AudioWorkgroup_RemoveThread(grp, g_tokenId);

OH_AudioResourceManager_ReleaseWorkgroup(resMgr, grp);
grp = nullptr;
```