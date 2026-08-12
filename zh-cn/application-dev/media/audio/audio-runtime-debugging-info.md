# 使用音频快照获取问题定位信息
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

从API版本26.0.0开始，支持通过音频快照（Audio Debugging Info）能力获取当前进程中音频子系统的状态信息。音频快照是对当前进程中音频各模块运行状态的瞬时记录，类似于系统在某一时刻为音频子系统拍摄的“照片”，涵盖音频流参数、通路状态、音量信息、焦点状态、错误记录等关键数据，能够帮助开发者在不影响业务逻辑的前提下，快速了解音频系统的内部运行情况。开发者可通过快照获取定位音频播放、录音、耳返、会话等场景中的异常问题所需的相关系统信息，例如无声、音量异常、焦点丢失等。

> **说明：**
>
> - 快照信息的内容和格式后续会根据开发者使用情况和反馈建议优化调整，随版本迭代可能发生变化，所以仅供人工调试参考，**不建议开发者依据快照信息开发功能逻辑**。
> - 音频快照能力同时提供C/C++ API和ArkTS API，开发者可根据开发语言选择对应接口。

**音频快照使用场景**

| 模块 | 接口类型 | 说明 | 典型使用场景 |
| :--- | :--- | :--- | :--- |
| 应用快照 | C/C++、ArkTS | 包含当前应用进程中所有播放、录音、耳返、会话的快照信息（不包含编创快照）。 | 整体问题排查、系统性异常。 |
| 音频播放（Renderer）快照 | C/C++、ArkTS | 记录播放流参数、通路信息、音量、焦点状态、错误记录等。 | 播放无声、音量异常、焦点被抢占。 |
| 音频录音（Capturer）快照 | C/C++、ArkTS | 记录录音流参数、通路信息、录音时间戳、溢出计数、错误记录等。 | 录音无数据、录音卡顿、缓冲区溢出。 |
| 音频耳返（Loopback）快照 | ArkTS | 记录耳返状态、设备信息、音效参数、上下行流状态等。 | 耳返无声、耳返时延高、音效异常。 |
| 音频会话（Session）快照 | C/C++、ArkTS | 记录会话状态、并发策略、场景类型、关联流信息等。 | 会话激活异常、并发策略不生效。 |
| 音频编创（AudioSuite）快照 | C/C++ | 记录引擎状态、管线运行状态、节点连接关系、音效参数等。 | 编创无输出、音效不生效、管线连接异常。 |

## 开发准备

以下各步骤示例为片段代码，可通过示例代码链接获取[完整示例](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/AudioSnapshot)。

### 导入模块

**C/C++开发：**

开发者使用C/C++接口获取音频快照，需要添加对应的头文件，并在CMake脚本中链接动态库。

**在CMake脚本中链接动态库：**

``` cmake
target_link_libraries(sample PUBLIC libohaudio.so)
```

**添加头文件：**

<!-- @[header_file](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
#include <ohaudio/native_audio_debugging_manager.h>
#include <fcntl.h>
#include <unistd.h>
// 文件权限常量。
constexpr mode_t FILE_PERMISSION = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; // 0644
```

**ArkTS开发：**

开发者使用ArkTS接口获取音频快照时，需导入音频模块。

<!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { fileIo as fileio } from '@kit.CoreFileKit';
```

### 获取音频调试管理器

在使用调试接口前，需先获取音频调试管理器实例。该实例为单例，获取后可重复使用。

接口说明请参考[getDebuggingManager](../../reference/apis-audio-kit/arkts-apis-audio-AudioManager.md#getdebuggingmanager)。

**C/C++接口：**

<!-- @[get_debug_manager_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// 获取音频调试管理器。
OH_AudioDebuggingManager *debugManager = nullptr;
OH_AudioCommon_Result result = OH_AudioManager_GetAudioDebuggingManager(&debugManager);
if (result != AUDIOCOMMON_RESULT_SUCCESS || debugManager == nullptr) {
    // 获取失败，处理错误。
    return;
}
```

**ArkTS接口：**

<!-- @[get_debug_manager_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// 获取音频调试管理器。
const audioManager = audio.getAudioManager();
const debugManager: audio.AudioDebuggingManager = audioManager.getDebuggingManager();
```

## 应用快照

应用快照包含当前应用进程中所有播放快照、录音快照、耳返快照和会话快照信息，是不同场景快照的汇总。应用快照不包含编创快照。适用于需要一次性获取整体音频运行状态的场景。

应用快照包含如下信息：

| 信息分类 | 包含字段 | 说明 |
| :--- | :--- | :--- |
| 播放快照列表 | renderers | 当前应用进程中所有播放快照信息，具体请参考[音频播放快照](#音频播放快照)。 |
| 录音快照列表 | capturers | 当前应用进程中所有录音快照信息，具体请参考[录音快照](#录音快照)。 |
| 耳返快照列表 | loopbacks | 当前应用进程中所有耳返快照信息，具体请参考[音频耳返快照](#音频耳返快照)。 |
| 会话快照列表 | sessions | 当前应用进程中所有会话快照信息，具体请参考[音频会话快照](#音频会话快照)。 |

> **说明：**
>
> 各快照详细字段信息见下方对应章节的输出示例。

接口说明请参考[printAppInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printappinfo)。

**C/C++接口：**

<!-- @[print_app_snapshot_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// 打印应用快照到文件。
int32_t fd = open("/data/storage/el2/base/cache/audio_snapshot.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSION);
if (fd >= 0) {
    OH_AudioDebuggingManager_PrintAppInfo(debugManager, fd);
    close(fd);
}

// 也可将快照信息输出到hilog日志（fd < 0时输出到hilog）。
OH_AudioDebuggingManager_PrintAppInfo(debugManager, -1);
```

**ArkTS接口：**

<!-- @[print_app_snapshot_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// 打印应用快照到文件。
const path = this.context.filesDir + '/audio_snapshot.txt';
// READ_WRITE表示可读写，CREATE表示文件不存在时创建，TRUNC表示打开时清空原有内容。
const file = fileio.openSync(path,
  fileio.OpenMode.READ_WRITE | fileio.OpenMode.CREATE | fileio.OpenMode.TRUNC);
debugManager.printAppInfo(file.fd);
fileio.closeSync(file);

// 也可将快照信息输出到hilog日志（fd < 0时输出到hilog）。
debugManager.printAppInfo(-1);
```

**输出示例：**

```text
audioApp {
  renderers: [                          // 播放快照信息列表。
    { ... },                            // 播放快照信息，详见"音频播放快照"。
    { ... }
  ],
  capturers: [                          // 录音快照信息列表。
    { ... },                            // 录音快照信息，详见"录音快照"。
    { ... }
  ],
  loopbacks: [                          // 耳返快照信息列表。
    { ... }                             // 耳返快照信息，详见"音频耳返快照"。
  ],
  sessions: [                           // 会话快照信息列表。
    { ... }                             // 会话快照信息，详见"音频会话快照"。
  ]
}
```

## 音频播放快照

音频播放快照记录播放流参数、通路信息、音量、设备信息、焦点状态、错误记录等，适用于排查播放无声、音量异常、焦点被抢占等问题。

音频播放快照包含如下信息：

| 信息分类 | 包含字段 | 说明 |
| :--- | :--- | :--- |
| 流信息 | streamId、samplingRate、channels、format、encoding、streamUsage、rendererFlags | 音频流基本参数。 |
| 通路信息 | pipeId、pipeRole、pipeName、routeFlag、adapterName、pipeFormat、pipeRate等 | 底层音频通路状态。 |
| 设备信息 | mainDeviceType | 当前输出设备类型。 |
| 音量信息 | volumeType、streamVolume、systemVolume、volume | 各级音量信息。 |
| 音效信息 | speed、pitch、effectMode | 音效参数。 |
| 焦点信息 | focusState、focusHistory | 当前焦点状态及焦点变化历史。 |
| 故障编码 | errorInfos | 故障编码记录，系统内最多保留10条最新故障编码信息。 |

> **说明：**
>
> 详细字段信息见下方输出示例。

接口说明请参考[printRendererInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printrendererinfo)。

**C/C++接口：**

<!-- @[print_renderer_snapshot_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// 打印指定播放实例的快照。
int32_t fd = open("/data/storage/el2/base/cache/renderer_snapshot.txt",
    O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSION);
if (fd >= 0) {
    OH_AudioDebuggingManager_PrintRendererInfo(debugManager, renderer, fd);
    close(fd);
}
```

**ArkTS接口：**

<!-- @[print_renderer_snapshot_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// 打印指定播放实例的快照。
const path = this.context.filesDir + '/renderer_snapshot.txt';
const file = fileio.openSync(path,
  fileio.OpenMode.READ_WRITE | fileio.OpenMode.CREATE | fileio.OpenMode.TRUNC);
debugManager.printRendererInfo(renderer, file.fd);
fileio.closeSync(file);
```

**输出示例：**

```text
audioRenderer {
  streamInfo: {                         // 流信息。
    streamId: 100001,                   // 流ID。
    samplingRate: 48000,               // 采样率。
    channels: 2,                        // 声道数。
    format: SAMPLE_S16LE,              // 采样格式。
    encoding: ENCODING_PCM,            // 编码格式。
    streamUsage: STREAM_USAGE_MUSIC,   // 播放流用途。
    rendererFlags: AUDIO_FLAG_NORMAL   // 播放流标记。
  },
  pipeInfo: {                           // 通路信息。
    pipeId: 5,                          // 通路ID。
    pipeRole: PIPE_ROLE_OUTPUT,        // 通路角色。
    pipeName: primary,                  // 通路名称。
    routeFlag: OUTPUT_FLAG_NORMAL,     // 路由标志。
    adapterName: primary,              // 适配器名称。
    pipeFormat: S16LE,                 // 通路格式。
    pipeRate: 48000,                   // 通路采样率。
    pipeChannels: 2,                   // 通路声道数。
    pipeChannelLayout: CH_LAYOUT_STEREO, // 通路声道布局。
    pipeDeviceType: DEVICE_TYPE_SPEAKER // 通路设备类型。
  },
  deviceInfo: {                         // 设备信息。
    mainDeviceType: DEVICE_TYPE_SPEAKER // 主设备类型。
  },
  volumeInfo: {                         // 音量信息。
    volumeType: MEDIA_STREAM,          // 音量类型。
    streamVolume: 1.000000,            // 流音量。
    systemVolume: 1.000000,            // 系统音量。
    volume: 1.000000                   // 实际音量。
  },
  effectInfo: {                         // 音效信息。
    speed: 1.000000,                    // 速度。
    pitch: 1.000000,                    // 音调。
    effectMode: EFFECT_DEFAULT          // 音效模式。
  },
  focusInfo: {                          // 焦点信息。
    focusState: ACTIVE,                // 当前焦点状态。
    focusHistory: [                    // 历史焦点行为。
      { streamId: 100001, pid: xx, uid: xx, streamType: STREAM_MUSIC,
        sourceType: SOURCE_TYPE_INVALID, hintType: INTERRUPT_HINT_NONE,
        timestamp: xx },
    ]
  },
  errorInfos: []                        // 故障编码信息列表。
}
```

## 录音快照

录音快照记录录音流参数、通路信息、录音时间戳、设备信息、溢出计数、错误记录等，适用于排查录音无数据、录音卡顿等问题。

录音快照包含如下信息：

| 信息分类 | 包含字段 | 说明 |
| :--- | :--- | :--- |
| 流信息 | streamId、samplingRate、channels、format、encoding、sourceType、capturerFlag | 音频流基本参数。 |
| 录音信息 | timestamp、bufferSize、overflowCount、muteWhenInterrupted、inputDeviceType | 录音运行状态。 |
| 通路信息 | pipeRole、samplingRate、channels、format、encoding、channelLayout | 底层通路状态。 |
| 焦点信息 | focusState、focusHistory | 当前焦点状态及焦点变化历史。 |
| 故障编码 | errorInfos | 故障编码记录，系统内最多保留10条最新故障编码信息。 |

> **说明：**
>
> 详细字段信息见下方输出示例。

接口说明请参考[printCapturerInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printcapturerinfo)。

**C/C++接口：**

<!-- @[print_capturer_snapshot_c](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/cpp/audio.cpp) -->

``` C++
// 打印指定录音实例的快照。
int32_t fd = open("/data/storage/el2/base/cache/capturer_snapshot.txt",
    O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSION);
if (fd >= 0) {
    OH_AudioDebuggingManager_PrintCapturerInfo(debugManager, capturer, fd);
    close(fd);
}
```

**ArkTS接口：**

<!-- @[print_capturer_snapshot_ts](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSnapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
// 打印指定录音实例的快照。
const path = this.context.filesDir + '/capturer_snapshot.txt';
const file = fileio.openSync(path,
  fileio.OpenMode.READ_WRITE | fileio.OpenMode.CREATE | fileio.OpenMode.TRUNC);
debugManager.printCapturerInfo(capturer, file.fd);
fileio.closeSync(file);
```

**输出示例：**

```text
audioCapturer {
  streamInfo: {                         // 流信息。
    streamId: 100002,                   // 流ID。
    samplingRate: 16000,               // 采样率。
    channels: 1,                        // 声道数。
    format: SAMPLE_S16LE,              // 采样格式。
    encoding: ENCODING_PCM,            // 编码格式。
    channelLayout: CH_LAYOUT_MONO,     // 声道布局。
    sourceType: SOURCE_TYPE_MIC,       // 录音流类型。
    capturerFlag: AUDIO_FLAG_NORMAL    // 录音标志。
  },
  captureInfo: {                        // 录音信息。
    timestamp(frame: xx, sec: xx, nsec: xx), // 时间戳。
    bufferSize: 6400,                  // 缓冲区大小。
    overflowCount: 0,                  // 溢出次数。
    muteWhenInterrupted: false,        // 焦点打断静音状态。
    inputDeviceType: 15                // 输入设备类型。
  },
  pipeInfo: {                           // 通路信息。
    pipeRole: PIPE_ROLE_INPUT,         // 通路角色。
    samplingRate: 16000,               // 通路采样率。
    channels: 1,                        // 通路声道数。
    format: SAMPLE_S16LE,              // 通路格式。
    encoding: ENCODING_PCM,            // 通路编码。
    channelLayout: CH_LAYOUT_MONO      // 通路声道布局。
  },
  focusInfo: {                          // 焦点信息。
    focusState: ACTIVE,                // 当前焦点状态。
    focusHistory: []                   // 历史焦点行为。
  },
  errorInfos: []                        // 故障编码信息列表。
}
```

## 音频耳返快照

音频耳返快照记录耳返的工作模式、当前状态、活跃设备、音效参数（混响/均衡器预设、音量）以及上下行流状态等，适用于排查耳返无声、耳返时延高、音效异常等问题。

音频耳返快照包含如下信息：

| 信息分类 | 包含字段 | 说明 |
| :--- | :--- | :--- |
| 应用信息 | appUid、appName | 耳返所属应用信息。 |
| 状态信息 | mode、currentState | 耳返工作模式和当前状态。 |
| 设备信息 | activeOutputDevice、activeInputDevice | 当前活跃的输出和输入设备。 |
| 音效信息 | reverbPreset、equalizerPreset、volume | 混响预设、均衡器预设和音量。 |
| 流状态信息 | uplinkStreamState、downlinkStreamState | 上行采集流和下行播放流状态。 |

> **说明：**
>
> 详细字段信息见下方输出示例。
> 调用该方法前，需要先创建AudioLoopback实例。耳返的创建及使用方式可参考[实现低时延耳返](audio-ear-monitor-loopback.md)。耳返处于可用状态（AVAILABLE_IDLE或AVAILABLE_RUNNING）时，可查询到完整的快照信息。

接口说明请参考[printLoopbackInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printloopbackinfo)。

**ArkTS接口：**

<!-- @[print_loopback_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioCaptureSampleJS/entry/src/main/ets/pages/AudioLoopbackDebugInfo.ets) -->

``` TypeScript
// audioLoopback为已创建的AudioLoopback实例。
// 获取调试管理器。
let debugManager = audio.getAudioManager().getDebuggingManager();

// 输出到hilog日志。
debugManager.printLoopbackInfo(audioLoopback, -1);

// 输出到文件。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;                                                              
let filePath = context.filesDir + '/audio_loopback_debug.txt';
let file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
debugManager.printLoopbackInfo(audioLoopback, file.fd);
fs.closeSync(file);
```

**输出示例：**

```text
audioLoopback {
  appInfo: {                            // 应用信息。
    appUid: 10001,                      // 应用UID。
    appName: com.example.karaoke        // 应用名称。
  },
  statusInfo: {                         // 状态信息。
    mode: LOOPBACK_HARDWARE,           // 耳返模式。
    currentState: LOOPBACK_STATE_RUNNING // 当前状态。
  },
  deviceInfo: {                         // 设备信息。
    activeOutputDevice: DEVICE_TYPE_WIRED_HEADPHONES, // 活跃输出设备。
    activeInputDevice: DEVICE_TYPE_WIRED_HEADPHONES   // 活跃输入设备。
  },
  effectInfo: {                         // 音效信息。
    reverbPreset: REVERB_PRESET_THEATER, // 混响预设。
    equalizerPreset: EQUALIZER_PRESET_FULL, // 均衡器预设。
    volume: 50                          // 音量。
  },
  streamInfo: {                         // 流状态信息。
    uplinkStreamState: CAPTURER_RUNNING,   // 上行流状态。
    downlinkStreamState: RENDERER_RUNNING  // 下行流状态。
  }
}
```

## 音频会话快照

音频会话快照记录会话状态、并发策略、场景类型、设备信息、关联流信息等，适用于排查会话激活异常、并发策略不生效等问题。

音频会话快照包含如下信息：

| 信息分类 | 包含字段 | 说明 |
| :--- | :--- | :--- |
| 策略信息 | concurrencyMode | 会话并发策略。 |
| 场景信息 | audioSessionScene、defaultDeviceType | 会话场景和默认设备。 |
| 状态信息 | state、fakeFocusState | 会话状态。 |
| 进程信息 | pid、uid | 所属进程信息。 |
| 关联流信息 | streamInfos（streamId、focusState、streamType） | 会话关联的音频流列表。 |

> **说明：**
>
> 详细字段信息见下方输出示例。
> 调用该方法前，需要先创建并激活音频会话。音频会话的创建及使用方式可参考[使用OHAudio开发音频会话功能(C/C++)](using-ohaudio-for-session.md)或[音频会话管理(ArkTS)](audio-session-management.md)。

接口说明请参考[printSessionInfo](../../reference/apis-audio-kit/arkts-apis-audio-AudioDebuggingManager.md#printsessioninfo)。

**C/C++接口：**

<!-- @[print_session_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleC/entry/src/main/cpp/audiosession.cpp) -->

``` C++
#include "ohaudio/native_audio_debugging_manager.h"
// ...
OH_AudioSessionManager *audioSessionManager;
// ...
    // 创建音频会话管理器。
    OH_AudioManager_GetAudioSessionManager(&audioSessionManager);
    // 设置音频并发模式。
    OH_AudioSession_Strategy strategy = {CONCURRENCY_MIX_WITH_OTHERS};
    // 激活音频会话。
    OH_AudioSessionManager_ActivateAudioSession(audioSessionManager, &strategy);
    
    // 创建音频调试管理器。
    OH_AudioDebuggingManager *audioDebuggingManager;
    OH_AudioManager_GetAudioDebuggingManager(&audioDebuggingManager);
    
    // 输出到hilog日志。
    OH_AudioDebuggingManager_PrintSessionInfo(audioDebuggingManager, audioSessionManager, -1);
    
    // fd 文件描述符，实际使用时请根据具体情况获取
    // 输出到文件
    OH_AudioDebuggingManager_PrintSessionInfo(audioDebuggingManager, audioSessionManager, fd);

```

**ArkTS接口：**

<!-- @[print_session_info](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSessionSampleJS/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
// ...
import { fileIo as fs } from '@kit.CoreFileKit';
// ...
  // 设置音频并发模式。
  let strategy: audio.AudioSessionStrategy = {
    concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
  };
  // 激活音频会话。
  await audioSessionManager.activateAudioSession(strategy);

  // 创建音频调试管理器。
  let audioDebuggingManager: audio.AudioDebuggingManager = audioManager.getDebuggingManager();

  // 输出到hilog日志。
  audioDebuggingManager.printSessionInfo(audioSessionManager, -1);

  // fd 文件描述符，实际使用时请根据具体情况获取
  let filePath = context.filesDir + '/audio_session_info.txt';
  let fd = fs.openSync(filePath, fs.OpenMode.CREATE | fs.OpenMode.WRITE_ONLY | fs.OpenMode.TRUNC).fd;
  // 输出到文件。
  audioDebuggingManager.printSessionInfo(audioSessionManager, fd);
  fs.closeSync(fd);
```

**输出示例：**

```text
audioSession {
  strategy: DEFAULT,                    // 会话策略。
  audioSessionScene: MEDIA,            // 会话场景。
  defaultDeviceType: DEVICE_TYPE_SPEAKER, // 默认设备类型。
  state: SESSION_ACTIVE,               // 会话状态。
  fakeFocusState: ACTIVE,              // 假焦点状态。
  pid: xx,                              // 进程ID。
  uid: xx,                              // 用户ID。
  streams: [                            // 关联流列表。
    {
      streamId: 100001,                 // 流ID。
      streamType: STREAM_MUSIC         // 流类型。
    },
  ]
}
```

## 音频编创快照

音频编创（AudioSuite）快照信息用于获取音频编创引擎、管线和节点的状态信息，帮助开发者排查音频编创处理链路中的问题。音频编创的基本概念（引擎、管线、节点）请参考[音频编创开发概述(C/C++)](audio-suite.md)。

音频编创快照包含如下信息：

| 信息分类 | 包含字段 | 说明 |
| :--- | :--- | :--- |
| 引擎信息 | engineState、pipelineCount | 引擎运行状态和管线数量。 |
| 管线信息 | pipelineId、pipelineState、nodeCount | 管线标识、运行状态和节点数量。 |
| 节点信息 | nodeId、nodeType、connectState、format | 节点标识、类型、连接状态和音频格式。 |
| 音效信息 | effectType、effectParams | 节点所使用的音效类型和参数。 |

> **说明：**
>
> 详细字段信息见下方输出示例。

接口说明请参考[OH_AudioSuite_PrintInfo](../../reference/apis-audio-kit/capi-native-audio-suite-engine-h.md#oh_audiosuite_printinfo)。

<!-- @[audioSuite_PrintInfo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/AudioSuiteSample/entry/src/main/cpp/print_info_to_file.cpp) -->

``` C++
// engine为已创建的OH_AudioSuiteEngine实例，必须确保engine参数有效，否则输出内容为空。
// pipeline为nullptr时输出所有管线，传入具体管线实例则仅输出该管线。
OH_AudioSuiteEngine *engine = audioSuiteEngine;
if (!engine) {
    OH_AudioSuiteEngine_Create(&g_printInfoEngine);
    engine = g_printInfoEngine;
}
// 打印编创快照到文件。
const char *filePath =
    "/storage/Users/currentUser/Download/com.example.audiosuitesample/printfile/audio_snapshot.txt";
int fd = open(filePath, O_WRONLY | O_CREAT | O_APPEND, FILE_PERMISSION);
if (fd < 0) {
    // 文件打开失败，回退到日志输出。
    // fd < 0表示输出到日志。
    OH_AudioSuite_PrintInfo(engine, nullptr, -1);
    napi_get_boolean(env, true, &result);
    return result;
}
// 输出所有管线信息到文件。
// nullptr表示输出engine下所有pipeline，fd为文件描述符。
OH_AudioSuite_Result ret = OH_AudioSuite_PrintInfo(engine, nullptr, fd);
close(fd);
```

**输出示例：**

```text
========================================
Audio Suite Engine Debug Info
Timestamp: xxxx-xx-xx xx:xx:xx.xxx      // 时间戳。
========================================

Total Pipelines: 1                       // 管线总数。

Pipeline [ID: 1]                         // 管线唯一标识符。
  Work Mode: EDIT_MODE                  // 工作模式：Manual（离线编辑）或Real-time（实时渲染）。
  State: RUNNING                         // 当前状态：Stopped或Running。
  Nodes: 3                               // 节点数。
  Connections: 2                         // 连接数。

  Node [ID: 103, Type: NODE_TYPE_EQUALIZER] // 节点唯一标识符和类型。
    Volume: 1                            // 音量。
    Bypass: false                        // 旁路。
    Gains: band0:1, band1:1, ...        // 增益参数。

  Node [ID: 102, Type: NODE_TYPE_OUTPUT]    // 节点唯一标识符和类型。
    Format: sampleRate=24000, channels=2, format=PCM24 // 音频格式。
    Volume: 1                            // 音量。

  Node [ID: 101, Type: NODE_TYPE_INPUT]     // 节点唯一标识符和类型。
    Format: sampleRate=44100, channels=2, format=FLOAT32 // 音频格式。
    Volume: 1                            // 音量。
    Finished: true                       // 是否完成。

  Connections:                           // 正向连接关系：上游节点 -> 下游节点。
    103 -> 102
    101 -> 103

  Reverse Connections:                   // 反向连接关系：下游节点 <- 上游节点。
    102 -> 103
    103 -> 101

========================================
```

## 注意事项

- 调用打印接口时，如果`fd`小于0或不可写，快照信息将输出到运行日志（hilog）中，可通过日志工具查看。
- 建议在出现音频异常时（如无声、音量异常、焦点丢失等）获取快照信息，用于问题定位。
- 各打印接口为同步调用，建议避免在音频数据回调中调用，以免影响音频处理性能。
- 快照文件保存在应用沙箱目录下，可通过hdc工具导出到本地查看：
  ``` bash
  hdc file recv /data/app/el2/100/base/<bundleName>/haps/entry/cache/audio_snapshot.txt ./
  ```
- 耳返须处于可用状态（AVAILABLE_IDLE或AVAILABLE_RUNNING）时，才能查询到完整的快照信息。
- 调用会话快照接口前，需要先创建并激活音频会话，否则无法获取到完整的快照信息。
- 当`pipeline`参数为NULL时，输出引擎下所有管线的信息。
- 节点属性配置的具体参数因节点类型而异，详见[OHAudioSuite](../../reference/apis-audio-kit/capi-ohaudiosuite.md)中各节点的说明。
