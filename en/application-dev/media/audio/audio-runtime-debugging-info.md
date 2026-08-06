# Using Audio Snapshots for Troubleshooting

<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=dbc5c483199a2ea0e3b7cfa374aa5bf041bae633 translatedAt=2026-08-06T01:47:41.010Z pushedAt=2026-08-06T07:54:52.916Z -->

Starting from API version 26.0.0, the system provides audio snapshot (Audio Debugging Info) capability, which allows apps to obtain the runtime status of the audio subsystem in the current process. Audio Debugging Info captures a point-in-time snapshot of the audio subsystem, including key information such as audio stream parameters, routing status, volume information, audio focus state, and error records. It helps you inspect the internal state of the audio subsystem without affecting app behavior. You can use the captured snapshot to obtain diagnostic information for troubleshooting issues related to audio rendering, audio capture, audio loopback, and audio sessions, such as silent playback, abnormal volume levels, and audio focus loss.

> **NOTE**
>
> - The content and format of audio snapshots may be refined in future releases based on developer feedback and usage. As a result, they are subject to change across releases. Audio snapshots are intended for manual debugging only. Do not rely on their content or format when implementing application logic.
> - Audio snapshot provides both C/C++ APIs and ArkTS APIs. Choose the appropriate API based on your development language.

**Audio Debugging Info Usage Scenarios**

| Module | API Type | Description | Typical Usage Scenario |
| :--- | :--- | :--- | :--- |
| Application Snapshot | C/C++, ArkTS | Contains snapshot information of all playback, recording, loopback, and session instances in the current app process (excluding Audio Authoring snapshots). | Overall issue troubleshooting and systemic anomalies. |
| Audio Playback (Renderer) Snapshot | C/C++, ArkTS | Records playback stream parameters, path information, volume, focus state, error records, and more. | Playback silence, volume anomaly, focus preemption. |
| Audio Recording (Capturer) Snapshot | C/C++, ArkTS | Records recording stream parameters, path information, recording timestamps, overflow count, error records, and more. | No recording data, recording stutter, buffer overflow. |
| Audio Loopback Snapshot | ArkTS | Records loopback state, device information, audio effect parameters, uplink and downlink stream states, and more. | Loopback silence, high loopback latency, audio effect anomaly. |
| Audio Session Snapshot | C/C++, ArkTS | Records session state, concurrency policy, scene type, associated stream information, and more. | Session activation anomaly, concurrency policy not taking effect. |
| Audio Authoring (AudioSuite) Snapshot | C/C++ | Records engine state, pipeline running state, node connection relationships, audio effect parameters, and more. | No output for audio creation, audio effect not taking effect, pipeline connection anomaly. |

## Getting Started

The following examples are code snippets. For the complete sample code, see [AudioSnapshot](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSnapshot).

### Importing the Module

**C/C++ Development:**

To obtain audio snapshots using C/C++ APIs, you need to include the corresponding header files and link the dynamic library in the CMake script.

**Linking the Dynamic Library in CMake:**

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

**Including Header Files:**

<!-- @[header_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
#include <ohaudio/native_audio_debugging_manager.h>
#include <fcntl.h>
#include <unistd.h>
// File permission constant.
constexpr mode_t FILE_PERMISSION = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 0644
```

**ArkTS Development:**

When using ArkTS APIs to obtain audio snapshots, you need to import the audio module.

<!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { fileIo as fileio } from '@kit.CoreFileKit';
```

### Obtaining the Audio Debugging Manager

Before using the debugging APIs, obtain an audio debugging manager instance first. This instance is a singleton and can be reused.

For API details, see [getDebuggingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getdebuggingmanager).

**C/C++ API:**

<!-- @[get_debug_manager_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// Obtain the audio debugging manager.
OH_AudioDebuggingManager *debugManager = nullptr;
OH_AudioCommon_Result result = OH_AudioManager_GetAudioDebuggingManager(&debugManager);
if (result != AUDIOCOMMON_RESULT_SUCCESS || debugManager == nullptr) {
    // Failed to obtain. Handle the error.
    return;
}
```

**ArkTS API:**

<!-- @[get_debug_manager_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Obtain the audio debugging manager.
const audioManager = audio.getAudioManager();
const debugManager: audio.AudioDebuggingManager = audioManager.getDebuggingManager();
```

## App Snapshot

The app snapshot contains all information about renderer, capturer, loopback, and session snapshots within the current app process. It is a summary of snapshots from different scenarios. The app snapshot does not include AudioSuite snapshots. It is suitable for scenarios where you need to obtain the overall audio running status at once.

The following table lists the information in app snapshots.

| Information Category | Included Fields | Description |
| :--- | :--- | :--- |
| Playback snapshot list | renderers | All playback snapshot information in the current app process. For details, see [Audio Renderer Snapshot](#audio-renderer-snapshot). |
| Recording snapshot list | capturers | All recording snapshot information in the current app process. For details, see [Audio Capturer Snapshot](#audio-capturer-snapshot). |
| Ear return snapshot list | loopbacks | All ear return snapshot information in the current app process. For details, see [Audio Loopback Snapshot](#audio-loopback-snapshot). |
| Session snapshot list | sessions | All session snapshot information in the current app process. For details, see [Audio Session Snapshot](#audio-session-snapshot). |

> **NOTE**
>
> For detailed field information of each snapshot, see the output examples in the corresponding sections below.

For API details, see [printAppInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printappinfo).

**C/C++ API:**

<!-- @[print_app_snapshot_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// Print the app snapshot to a file.
int32_t fd = open("/data/storage/el2/base/cache/audio_snapshot.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSION);
if (fd >= 0) {
    OH_AudioDebuggingManager_PrintAppInfo(debugManager, fd);
    close(fd);
}

// You can also output the snapshot information to hilog logs (output to hilog when fd &lt; 0).
OH_AudioDebuggingManager_PrintAppInfo(debugManager, -1);
```

**ArkTS API:**

<!-- @[print_app_snapshot_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Print the application snapshot to a file.
const path = this.context.filesDir + '/audio_snapshot.txt';
// READ_WRITE indicates read/write mode, CREATE indicates creating the file if it does not exist, and TRUNC indicates clearing the original content when opening.
const file = fileio.openSync(path,
  fileio.OpenMode.READ_WRITE | fileio.OpenMode.CREATE | fileio.OpenMode.TRUNC);
debugManager.printAppInfo(file.fd);
fileio.closeSync(file);

// You can also output the snapshot information to the hilog log (output to hilog when fd &lt; 0).
debugManager.printAppInfo(-1);
```

**Example:**

```text
audioApp {
  renderers: [                          // List of playback snapshot information.
    { ... },                            // Playback snapshot information. For details, see "Audio Playback Snapshot".
    { ... }
  ],
  capturers: [                          // List of recording snapshot information.
    { ... },                            // Recording snapshot information. For details, see "Recording Snapshot".
    { ... }
  ],
  loopbacks: [                          // List of ear return snapshot information.
    { ... }                             // Ear return snapshot information. For details, see "Audio Ear Return Snapshot".
  ],
  sessions: [                           // List of session snapshot information.
    { ... }                             // Session snapshot information. For details, see "Audio Session Snapshot".
  ]
}
```

## Audio Renderer Snapshot

The audio renderer snapshot records playback stream parameters, path information, volume, device information, focus state, error records, and more. It is suitable for troubleshooting issues such as no sound during playback, abnormal volume, and focus preemption.

The following table lists the information in audio renderer snapshots.

| Information Category | Included Fields | Description |
| :--- | :--- | :--- |
| Stream Information | streamId, samplingRate, channels, format, encoding, streamUsage, rendererFlags | Basic audio stream parameters. |
| Path Information | pipeId, pipeRole, pipeName, routeFlag, adapterName, pipeFormat, pipeRate, etc. | Underlying audio path status. |
| Device Information | mainDeviceType | Current output device type. |
| Volume Information | volumeType, streamVolume, systemVolume, volume | Volume information at each level. |
| Audio Effect Information | speed, pitch, effectMode | Audio effect parameters. |
| Focus Information | focusState, focusHistory | Current focus state and focus change history. |
| Fault Code | errorInfos | Fault code records. The system retains a maximum of 10 most recent fault code entries. |

> **NOTE**
>
> See the output example below for detailed field information.

For API details, see [printRendererInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printrendererinfo).

**C/C++ API:**

<!-- @[print_renderer_snapshot_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// Print the snapshot of the specified playback instance.
int32_t fd = open("/data/storage/el2/base/cache/renderer_snapshot.txt",
    O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSION);
if (fd >= 0) {
    OH_AudioDebuggingManager_PrintRendererInfo(debugManager, renderer, fd);
    close(fd);
}
```

**ArkTS API:**

<!-- @[print_renderer_snapshot_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Print the snapshot of the specified playback instance.
const path = this.context.filesDir + '/renderer_snapshot.txt';
const file = fileio.openSync(path,
  fileio.OpenMode.READ_WRITE | fileio.OpenMode.CREATE | fileio.OpenMode.TRUNC);
debugManager.printRendererInfo(renderer, file.fd);
fileio.closeSync(file);
```

**Example:**

```text
audioRenderer {
  streamInfo: {                         // Stream information.
    streamId: 100001,                   // Stream ID.
    samplingRate: 48000,               // Sample rate.
    channels: 2,                        // Channel count.
    format: SAMPLE_S16LE,              // Sample format.
    encoding: ENCODING_PCM,            // Encoding format.
    streamUsage: STREAM_USAGE_MUSIC,   // Playback stream usage.
    rendererFlags: AUDIO_FLAG_NORMAL   // Playback stream flag.
  },
  pipeInfo: {                           // Path information.
    pipeId: 5,                          // Path ID.
    pipeRole: PIPE_ROLE_OUTPUT,        // Pipe role.
    pipeName: primary,                  // Pipe name.
    routeFlag: OUTPUT_FLAG_NORMAL,     // Routing flag.
    adapterName: primary,              // Adapter name.
    pipeFormat: S16LE,                 // Pipe format.
    pipeRate: 48000,                   // Path sample rate.
    pipeChannels: 2,                   // Path channel count.
    pipeChannelLayout: CH_LAYOUT_STEREO, // Path channel layout.
    pipeDeviceType: DEVICE_TYPE_SPEAKER // Path device type.
  },
  deviceInfo: {                         // Device information.
    mainDeviceType: DEVICE_TYPE_SPEAKER // Main device type.
  },
  volumeInfo: {                         // Volume information.
    volumeType: MEDIA_STREAM,          // Volume type.
    streamVolume: 1.000000,            // Stream volume.
    systemVolume: 1.000000,            // System volume.
    volume: 1.000000                   // Actual volume.
  },
  effectInfo: {                         // Audio effect information.
    speed: 1.000000,                    // Speed.
    pitch: 1.000000,                    // Pitch.
    effectMode: EFFECT_DEFAULT          // Audio effect mode.
  },
  focusInfo: {                          // Focus information.
    focusState: ACTIVE,                // Current focus state.
    focusHistory: [                    // Historical focus behavior.
      { streamId: 100001, pid: xx, uid: xx, streamType: STREAM_MUSIC,
        sourceType: SOURCE_TYPE_INVALID, hintType: INTERRUPT_HINT_NONE,
        timestamp: xx },
    ]
  },
  errorInfos: []                        // Fault code information list.
}
```

## Audio Capturer Snapshot

The audio capturer snapshot records audio capture stream parameters, path information, capture timestamps, device information, overflow count, error records, and more. It is suitable for troubleshooting issues such as no capture data or capture stuttering.

The following table lists the information in audio capturer snapshots.

| Category | Field | Description |
| :--- | :--- | :--- |
| Stream Information | streamId, samplingRate, channels, format, encoding, sourceType, capturerFlag | Basic audio stream parameters. |
| Recording Information | timestamp, bufferSize, overflowCount, muteWhenInterrupted, inputDeviceType | Recording running status. |
| Path Information | pipeRole, samplingRate, channels, format, encoding, channelLayout | Underlying path status. |
| Focus Information | focusState, focusHistory | Current focus state and focus change history. |
| Fault Code | errorInfos | Fault code records. The system retains a maximum of 10 latest fault code entries. |

> **NOTE**
>
> See the output example below for detailed field information.

For API reference, see [printCapturerInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printcapturerinfo).

**C/C++ API:**

<!-- @[print_capturer_snapshot_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// Print the snapshot of the specified recording instance.
int32_t fd = open("/data/storage/el2/base/cache/capturer_snapshot.txt",
    O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSION);
if (fd >= 0) {
    OH_AudioDebuggingManager_PrintCapturerInfo(debugManager, capturer, fd);
    close(fd);
}
```

**ArkTS API:**

<!-- @[print_capturer_snapshot_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// Print the snapshot of the specified recording instance.
const path = this.context.filesDir + '/capturer_snapshot.txt';
const file = fileio.openSync(path,
  fileio.OpenMode.READ_WRITE | fileio.OpenMode.CREATE | fileio.OpenMode.TRUNC);
debugManager.printCapturerInfo(capturer, file.fd);
fileio.closeSync(file);
```

**Example:**

```text
audioCapturer {
  streamInfo: {                         // Stream information.
    streamId: 100002,                   // Stream ID.
    samplingRate: 16000,               // Sample rate.
    channels: 1,                        // Channel count.
    format: SAMPLE_S16LE,              // Sample format.
    encoding: ENCODING_PCM,            // Encoding format.
    channelLayout: CH_LAYOUT_MONO,     // Channel layout.
    sourceType: SOURCE_TYPE_MIC,       // Recording stream type.
    capturerFlag: AUDIO_FLAG_NORMAL    // Recording flag.
  },
  captureInfo: {                        // Recording information.
    timestamp(frame: xx, sec: xx, nsec: xx), // Timestamp.
    bufferSize: 6400,                  // Buffer size.
    overflowCount: 0,                  // Overflow count.
    muteWhenInterrupted: false,        // Mute state when interrupted by focus.
    inputDeviceType: 15                // Input device type.
  },
  pipeInfo: {                           // Path Information.
    pipeRole: PIPE_ROLE_INPUT,         // Path role.
    samplingRate: 16000,               // Path sample rate.
    channels: 1,                        // Path channel count.
    format: SAMPLE_S16LE,              // Path format.
    encoding: ENCODING_PCM,            // Path encoding.
    channelLayout: CH_LAYOUT_MONO      // Path channel layout.
  },
  focusInfo: {                          // Focus information.
    focusState: ACTIVE,                // Current focus state.
    focusHistory: []                   // Historical focus behavior.
  },
  errorInfos: []                        // Fault code information list.
}
```

## Audio Loopback Snapshot

The audio loopback snapshot records the working mode, current state, active devices, audio effect parameters (reverb/equalizer presets, volume), and uplink/downlink stream status of the loopback, helping troubleshoot issues such as no sound during loopback, high loopback latency, and abnormal audio effects.

The following table lists the information in audio loopback snapshots.

| Category | Field | Description |
| :--- | :--- | :--- |
| App Information | appUid, appName | App information of the loopback. |
| Status Information | mode, currentState | Loopback working mode and current state. |
| Device Information | activeOutputDevice, activeInputDevice | Currently active output and input devices. |
| Audio Effect Information | reverbPreset, equalizerPreset, volume | Reverb preset, equalizer preset, and volume. |
| Stream Status Information | uplinkStreamState, downlinkStreamState | Uplink capture stream and downlink playback stream states. |

> **NOTE**
>
> For detailed field information, see the output example below.
> Before calling this method, you need to create an AudioLoopback instance. For details about how to create and use loopback, see [Low-Latency Audio Monitoring](audio-ear-monitor-loopback.md). When the loopback is in the available state (`AVAILABLE_IDLE` or `AVAILABLE_RUNNING`), the complete snapshot information can be queried.

For API details, refer to [printLoopbackInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printloopbackinfo).

**ArkTS API:**

<!-- @[print_loopback_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopbackDebugInfo.ets) -->

``` TypeScript
// audioLoopback is the created AudioLoopback instance.
// Obtain the debug manager.
let debugManager = audio.getAudioManager().getDebuggingManager();

// Output to hilog log.
debugManager.printLoopbackInfo(audioLoopback, -1);

// Output to a file.
let filePath = getContext().filesDir + '/audio_loopback_debug.txt';
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
debugManager.printLoopbackInfo(audioLoopback, file.fd);
fs.closeSync(file);
```

**Example:**

```text
audioLoopback {
  appInfo: {                            // Application information.
    appUid: 10001,                      // Application UID.
    appName: com.example.karaoke        // Application name.
  },
  statusInfo: {                         // Status information.
    mode: LOOPBACK_HARDWARE,           // Ear return mode.
    currentState: LOOPBACK_STATE_RUNNING // Current state.
  },
  deviceInfo: {                         // Device information.
    activeOutputDevice: DEVICE_TYPE_WIRED_HEADPHONES, // Active output device.
    activeInputDevice: DEVICE_TYPE_WIRED_HEADPHONES   // Active input device.
  },
  effectInfo: {                         // Audio effect information.
    reverbPreset: REVERB_PRESET_THEATER, // Reverb preset.
    equalizerPreset: EQUALIZER_PRESET_FULL, // Equalizer preset.
    volume: 50                          // Volume.
  },
  streamInfo: {                         // Stream status information.
    uplinkStreamState: CAPTURER_RUNNING,   // Uplink stream status.
    downlinkStreamState: RENDERER_RUNNING  // Downlink stream state.
  }
}
```

## Audio Session Snapshot

The audio session snapshot records the session state, concurrency policy, scenario type, device information, associated stream information, and more. It is suitable for troubleshooting issues such as session activation exceptions and concurrency policy failures.

The following table lists the information in audio session snapshots.

| Category | Field | Description |
| :--- | :--- | :--- |
| Strategy Information | concurrencyMode | Session concurrency policy. |
| Scene Information | audioSessionScene, defaultDeviceType | Session scene and default device. |
| Status Information | state, fakeFocusState | Session state. |
| Process Information | pid, uid | Owning process information. |
| Associated Stream Information | streamInfos (streamId, focusState, streamType) | List of audio streams associated with the session. |

> **NOTE**
>
> For detailed field information, see the output example below.
> Before calling this method, you need to create and activate an audio session. For details about how to create and use an audio session, see [Using OHAudio for Audio Session (C/C++)](using-ohaudio-for-session.md) or [Using AudioSession to Manage Audio Focus (ArkTS)](audio-session-management.md).

For API details, see [printSessionInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printsessioninfo).

**C/C++ API:**

<!-- @[print_session_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
#include "ohaudio/native_audio_debugging_manager.h"
// ...
OH_AudioSessionManager *audioSessionManager;
// ...
    // Create the audio session manager.
    OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
    // Set the audio concurrency mode.
    OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
    // Activate the audio session.
    OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
    
    // Create the audio debugging manager.
    OH_AudioDebuggingManager *audioDebuggingManager;
    OH_AudioManager_GetAudioDebuggingManager(&audioDebuggingManager);
    
    // Output to the hilog log.
    OH_AudioDebuggingManager_PrintSessionInfo(audioDebuggingManager, audioSessionManager, -1);
    
    // fd: file descriptor. Obtain it based on the actual situation.
    // Output to a file.
    OH_AudioDebuggingManager_PrintSessionInfo(audioDebuggingManager, audioSessionManager, fd);

```

**ArkTS API:**

<!-- @[print_session_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...
import { fileIo as fs } from '@kit.CoreFileKit';
// ...
  // Set the audio concurrency mode.
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };
  // Activate the audio session.
  await audioSessionManager.activateAudioSession(strategy);

  // Create the audio debugging manager.
  let audioDebuggingManager: audio.AudioDebuggingManager = audioManager.getDebuggingManager();

  // Output to the hilog log.
  audioDebuggingManager.printSessionInfo(audioSessionManager, -1);

  // fd is a file descriptor. Obtain it based on the actual situation during use.
  let filePath = context.filesDir + '/audio_session_info.txt';
  let fd = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.WRITE_ONLY | fs.OpenMode.TRUNC).fd;
  // Output to file.
  audioDebuggingManager.printSessionInfo(audioSessionManager, fd);
  fs.closeSync(fd);
```

**Example:**

```text
audioSession {
  strategy: DEFAULT,                    // Session policy.
  audioSessionScene: MEDIA,            // Session scenario.
  defaultDeviceType: DEVICE_TYPE_SPEAKER, // Default device type.
  state: SESSION_ACTIVE,               // Session state.
  fakeFocusState: ACTIVE,              // Fake focus state.
  pid: xx,                              // Process ID.
  uid: xx,                              // User ID.
  streams: [                            // Associated stream list.
    {
      streamId: 100001,                 // Stream ID.
      streamType: STREAM_MUSIC         // Stream type.
    },
  ]
}
```

## AudioSuite Snapshot

An AudioSuite snapshot provides the runtime status of the AudioSuite engine, pipelines, and nodes, helping you troubleshoot issues in the AudioSuite processing pipeline. For an introduction to the basic AudioSuite concepts, such as engines, pipelines, and nodes, see [Audio Creation Overview (C/C++)](audio-suite.md).

The following table lists the information in AudioSuite snapshots.

| Category | Field | Description |
| :--- | :--- | :--- |
| Engine Information | engineState, pipelineCount | Engine running state and pipeline count. |
| Pipeline Information | pipelineId, pipelineState, nodeCount | Pipeline ID, running state, and node count. |
| Node Information | nodeId, nodeType, connectState, format | Node ID, type, connection state, and audio format. |
| Audio Effect Information | effectType, effectParams | Audio effect type and parameters used by the node. |

> **NOTE**
>
> See the output example below for detailed field information.

For API reference, see [OH_AudioSuite_PrintInfo](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuite_printinfo).

<!-- @[audioSuite_PrintInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/print_info_to_file.cpp) -->

``` C++
// engine is the created OH_AudioSuiteEngine instance. Ensure that the engine parameter is valid; otherwise, the output is empty.
// When pipeline is nullptr, all pipelines are output. When a specific pipeline instance is passed, only that pipeline is output.
OH_AudioSuiteEngine *engine = audioSuiteEngine;
if (!engine) {
    OH_AudioSuiteEngine_Create(&g_printInfoEngine);
    engine = g_printInfoEngine;
}
// Print the authoring snapshot to a file.
const char *filePath =
    "/storage/Users/currentUser/Download/com.example.audiosuitesample/printfile/audio_snapshot.txt";
int fd = open(filePath, O_WRONLY | O_CREAT | O_APPEND, FILE_PERMISSION);
if (fd < 0) {
    // File opening failed. Fall back to log output.
    // fd &lt; 0 indicates output to the log.
    OH_AudioSuite_PrintInfo(engine, nullptr, -1);
    napi_get_boolean(env, true, &result);
    return result;
}
// Output all pipeline information to a file.
// nullptr indicates outputting all pipelines under the engine, and fd is the file descriptor.
OH_AudioSuite_Result ret = OH_AudioSuite_PrintInfo(engine, nullptr, fd);
close(fd);
```

**Example:**

```text
========================================
Audio Suite Engine Debug Info
Timestamp: xxxx-xx-xx xx:xx:xx.xxx      // Timestamp.
========================================

Total Pipelines: 1                       // Total number of pipelines.

Pipeline [ID: 1]                         // Unique identifier of the pipeline.
  Work Mode: EDIT_MODE                  // Work mode: Manual (offline editing) or Real-time (real-time rendering).
  State: RUNNING                         // Current state: Stopped or Running.
  Nodes: 3                               // Number of nodes.
  Connections: 2                         // Number of connections.

  Node [ID: 103, Type: NODE_TYPE_EQUALIZER] // Unique identifier and type of the node.
    Volume: 1                            // Volume.
    Bypass: false                        // Bypass.
    Gains: band0:1, band1:1, ...        // Gain parameters.

  Node [ID: 102, Type: NODE_TYPE_OUTPUT]    // Unique node identifier and type.
    Format: sampleRate=24000, channels=2, format=PCM24 // Audio format.
    Volume: 1                            // Volume.

  Node [ID: 101, Type: NODE_TYPE_INPUT]     // Unique node identifier and type.
    Format: sampleRate=44100, channels=2, format=FLOAT32 // Audio format.
    Volume: 1                            // Volume.
    Finished: true                       // Whether finished.

  Connections:                           // Forward connections: upstream node -> downstream node.
    103 -> 102
    101 -> 103

  Reverse Connections:                   // Reverse connections: downstream node <- upstream node.eam node.
    102 -> 103
    103 -> 101

========================================
```

## Notes

- When calling a print API, if `fd` is less than 0 or not writable, the snapshot information will be output to the running log (hilog) and can be viewed using the log tool.

- It is recommended that you obtain snapshot information when an audio exception occurs (such as no sound, abnormal volume, or focus loss) for fault locating.

- Each print API is a synchronous call. It is recommended that you avoid calling them in audio data callbacks to prevent affecting audio processing performance.

- The snapshot file is saved in the app sandbox directory and can be exported to the local device for viewing using the hdc tool:

  ``` bash
  hdc file recv /data/app/el2/100/base/<bundleName>/haps/entry/cache/audio_snapshot.txt ./
  ```

- The complete snapshot information can be queried only when audio loopback is in an available state (`AVAILABLE_IDLE` or `AVAILABLE_RUNNING`).

- Before calling the session snapshot API, an audio session must be created and activated; otherwise, complete snapshot information cannot be obtained.

- When the `pipeline` parameter is NULL, information about all pipelines under the engine is output.

- The specific parameters for node attribute configuration vary by node type. For details, see the description of each node in [OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md).