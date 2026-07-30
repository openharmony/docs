# 音频焦点和音频会话开发概述
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->
 
在应用播放或录制声音时，会遇到与其他应用或本应用内的其他音频流发生焦点冲突。本章节概括了该场景的处理方式，帮助开发者了解如何使用系统的音频焦点冲突管理能力来解决各类音频打断问题。

当前系统音频推荐使用两种能力来管理音频冲突：音频焦点和音频会话。

音频焦点是系统预置策略，可以管理相对简单的场景，选择正确的音频流类型后，由系统进行管理，不需要应用参与。

当音频焦点无法满足应用需要时，使用音频会话来定制应用的音频冲突管理策略，需要应用接入音频会话。

下表列出音频焦点和音频会话的主要区别：

| 对比项 | 音频焦点 | 音频会话 |
|---|---|---|
| 管理粒度 | 单个音频流级别。 | 一组音频流整体管理。 |
| 冲突解决策略 | 固定的优先级规则。 | 可配置的并发模式（MIX/DUCK/PAUSE等）。 |
| 控制灵活性 | 系统主导，应用被动响应。 | 应用可主动配置策略。 |
| 状态回调 | 中断事件回调。 | 状态变化回调、设备变化回调、会话失效回调。 |
| 适用场景 | 单播放、录制场景。 | 复杂并发场景、需要精细化控制。 |

## 音频焦点使用场景概述
音频焦点是系统主导，按照系统预置焦点策略处理简单的音频并发。典型场景如下。

### 场景1：VoIP通话与系统来电处理

用户正在进行[VoIP通话](./audio-call-overview.md)，此时有系统来电，需要正确处理通话状态切换。

解决方案：系统来电对应音频焦点最高优先级，独占音频焦点，VoIP收到`INTERRUPT_HINT_PAUSE`后，执行暂停通话逻辑。来电结束后VoIP应用收到`INTERRUPT_HINT_RESUME`，可以恢复通话。

焦点特点：来电是系统级强制独占，使用固定优先级，强制打断所有音频，VoIP应用被动响应中断，无法自主控制。

### 场景2：后台播放应用被前台应用打断

后台音乐播放器正在播放，前台应用（如短视频）开始播放音频。

解决方案：后台应用请求音频焦点（通过会话机制或焦点机制），后台播放器收到中断回调，根据[`InterruptHint`](../../reference/apis-audio-kit/arkts-apis-audio-e.md#interrupthint)判断执行`INTERRUPT_HINT_PAUSE`或`INTERRUPT_HINT_DUCK`。当前台应用释放焦点后，后台播放器收到`INTERRUPT_HINT_RESUME`，继续播放。

焦点特点：后台应用被动接收中断事件，根据`InterruptHint`响应（暂停/停止/压低音量），应用无法主动声明策略，适用于传统应用或简单播放场景。

### 场景3：音乐播放与系统来电处理

用户听音乐时接到来电，希望通话结束后音乐自动恢复播放。

解决方案：音乐播放器收到来电的`INTERRUPT_HINT_PAUSE`提示后暂停播放，来电结束时收到`INTERRUPT_HINT_RESUME`提示，自动恢复播放。

焦点特点：利用音频焦点的自动恢复机制，`INTERRUPT_TYPE_END`事件携带RESUME提示，应用被动响应恢复播放，适合应用保持播放状态。

## 音频会话使用场景概述

如果系统默认策略不满足场景需求，建议使用音频渲染、录制和会话相关接口进行处理，典型场景如下。

### 场景1：音乐被后启动应用打断后，无法恢复

先打开应用A播放音乐，然后打开应用B，应用B有音频播放。默认焦点策略是STOP，应用A被应用B打断后，当B停止播放时，A不能恢复播放；要使A重新播放，系统当前有如下方案供选择：

<!--Table: 6%; 30%; 30%; 17%; 17% -->
| - | 应用A | 应用B | 打断效果 | 备注 |
|--|-------|-------|---------|------|
| 默认场景 | 播放媒体类音频（音乐） | 播放媒体类音频（短视频） | 默认焦点策略是停止，B播放后A被打断，不恢复 | 需要应用A继续播放，参考如下方案 |
| 方案一 | 使用音频渲染接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用MUTE_WHEN_INTERRUPTED | 无需适配 | B抢占焦点后，A会继续静音播放，B完成播放后A恢复 | 复播后会跳过之前静音的内容，对进度条敏感的场景不建议使用 |
| 方案二 | 使用音频渲染接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用PAUSE_WHEN_INTERRUPTED | 无需适配 | 应用B音频打断应用A时使用暂停策略，B播放完成后，A收到RESUME消息后继续播放 | 进度条敏感应用推荐使用该方案 |
| 方案三 | 无需适配 | 使用音频会话，在启动时使用CONCURRENCY_PAUSE_OTHERS，打断时使用PAUSE策略。当应用B释放焦点时，会给A发送RESUME事件 | B播放完成后，会发送RESUME，A继续播放 | - |
| 方案四 | 应用A提供开关，音频会话并发策略使用`CONCURRENCY_MIX_WITH_OTHERS` | 无需适配 | 应用A提供设置开关，用户手动开启生效，B播放后与A同时播放 | 开关参考系统音乐设置 |
| 方案五 | 无需适配 | 应用B提供开关，音频会话并发策略使用`CONCURRENCY_MIX_WITH_OTHERS` | 应用B提供设置开关，用户手动开启生效，B播放后与A同时播放 | 开关参考系统音乐设置 |
| 方案六 | 使用音频会话接口[setAudioSessionBehavior](../../reference/apis-audio-kit/arkts-apis-audio-AudioSessionManager.md#setaudiosessionbehavior24)，AudioSessionBehaviorFlags使用MUTE_WHEN_INTERRUPTED | 应用B提供开关，音频会话并发策略使用`CONCURRENCY_MIX_WITH_OTHERS` | 应用提供设置开关，用户手动开启生效，B播放后与A同时播放 | 开关参考系统音乐设置 |
| 方案七 | 无需适配 | 音频会话并发策略使用`CONCURRENCY_DUCK_OTHERS` | A音量压低，B停止后A音量自动恢复 | 音量自动恢复，无需额外适配 |

### 场景2：录音被通话应用打断后，无法恢复

<!--Table: 6%; 30%; 30%; 17%; 17% -->
| - | 应用A | 应用B | 打断效果 | 备注 |
|--|-------|-------|---------|------|
| 默认场景 | 启动音频录制 | 蜂窝通话、视频通话 | 通话和VoIP通话出于安全考虑，禁止录音 | - |
| 方案一 | 使用[setWillMuteWhenInterrupted](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setwillmutewheninterrupted20)接口，设置录制静音打断 | 无需配置 | 应用B音频播放或录制时，应用A可以持续录制，录制为静音流 | - |
| 方案二 | 使用音频录制接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用MUTE_WHEN_INTERRUPTED | 无需配置 | 应用B打断A录制时，应用A录制静音数据，应用B动作完成后恢复有声数据 | 与方案一效果相当，推荐方案二 |
| 方案三 | 使用音频录制接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用PAUSE_WHEN_INTERRUPTED | 无需配置 | 应用B打断A录制时，应用A录制暂停，应用B动作完成后，应用A收到RESUME事件恢复录制 | - |

### 场景3：通话过程中开启录制失败

<!--Table: 6%; 30%; 30%; 17%; 17% -->
| - | 应用A | 应用B | 打断效果 | 备注 |
|--|-------|-------|---------|------|
| 默认场景 | 启动通话 | 开启录制 | 录制失败 | - |
| 方案一 | 无需配置 | 使用[setWillMuteWhenInterrupted](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setwillmutewheninterrupted20)接口 | 录制可以启动，录制数据为静音流 | - |
| 方案二 | 无需配置 | 使用音频录制接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用MUTE_WHEN_INTERRUPTED | 录制可以启动，录制数据为静音流 | 与方案一效果相当，推荐方案二 |
| 方案三 | 无需配置 | 使用音频录制接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioCapturer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用PAUSE_WHEN_INTERRUPTED | 录制被暂停，应用A通话结束后，应用B收到RESUME事件恢复录制 | - |

### 场景4：音乐播放过程中开启录制，打断音乐播放

应用A正在播放音乐，应用B开始录音（语音识别、录音机等），音乐被暂停，录音结束后音乐可恢复播放。

| - | 应用A | 应用B | 打断效果 | 备注 |
|--|-------|-------|---------|------|
| 默认场景 | 启动音乐播放 | 开启录制 | 录音抢占焦点，音乐暂停；录音结束后音乐收到RESUME提示可恢复 | RESUME事件需应用主动调用play()恢复 |
| 方案一 | 使用音频录制接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用MUTE_WHEN_INTERRUPTED | 无需适配 | 录音期间音乐静音继续播放，录音结束后音乐恢复有声 | 复播会跳过静音期内容，对进度条敏感场景不建议使用 |
| 方案二 | 无需适配 | 音频会话并发策略使用`CONCURRENCY_DUCK_OTHERS` | 录音正常采集，音乐音量降低；录音结束后音量自动恢复 | 音量自动恢复，无需额外适配 |
| 方案三 | 无需适配 | 音频会话并发策略使用`CONCURRENCY_MIX_WITH_OTHERS` | 录音与音乐同时运行，互不影响 | - |

### 场景5：提示音（TTS）打断音乐，无法恢复

应用A正在播放音乐，应用B播放提示音。提示音使用通知音类型（STREAM_USAGE_NOTIFICATION）时不会打断音乐；但使用TTS播报时，TTS属于媒体类音频流，与音乐之间的默认焦点策略为STOP，音乐被打断后不恢复。

| - | 应用A | 应用B | 打断效果 | 备注 |
|--|-------|-------|---------|------|
| 默认场景 | 启动音乐播放 | 播放提示音（TTS，媒体类流） | TTS抢占焦点，音乐停止且不恢复 | TTS与音乐同为媒体类流，默认策略为STOP |
| 方案一 | 启动音乐播放 | 使用STREAM_USAGE_NOTIFICATION流类型播放提示音 | NOTIFICATION正常播放，音乐降低音量；提示音结束后音乐音量自动恢复 | - |
| 方案二 | 使用音频录制接口[setIndependentAudioSessionStrategy](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setindependentaudiosessionstrategy24)，AudioSessionBehaviorFlags使用MUTE_WHEN_INTERRUPTED | 无需适配 | B抢占焦点后，A会继续静音播放，B完成提示播报后A恢复 | 复播会跳过静音期内容，对进度条敏感场景不建议使用 |
| 方案三 | 无需适配 | 音频会话并发策略使用`CONCURRENCY_MIX_WITH_OTHERS` | TTS与音乐同时播放，互不影响 | - |

## 同应用内不同音频流之间的焦点管理

系统预设了两种焦点模式：

| 焦点模式 | 说明 | 同应用内焦点策略 |
|---------|------|-------------------|
| SHARE_MODE（默认，推荐） | 与同应用内其他SHARE_MODE流不触发焦点策略，应用自行管控；<br>与同应用内INDEPENDENT_MODE流触发焦点策略。 | 不触发焦点策略，应用自行决定各流的播放、暂停、停止等操作，系统不发送DUCK/PAUSE/STOP/RESUME事件。 |
| INDEPENDENT_MODE | 与同应用内所有流（无论SHARE_MODE或INDEPENDENT_MODE）均触发焦点策略。 | 触发焦点策略，按跨应用焦点策略管理 |

推荐使用共享焦点模式（SHARE_MODE），由应用自行管控各流的播放与恢复。

焦点模式详细介绍及实践可参考[同应用内焦点管理](./audio-playback-concurrency.md#同应用内焦点管理)

### 场景1：同应用内音乐和视频冲突

| - | 流A | 流B | 适配方案 | 打断效果 |
|--|-------|-------|-------------|---------|
| 默认场景 | 播放音乐（MUSIC） | 播放视频（MOVIE） | 默认为SHARE_MODE模式，不触发焦点策略 | 音乐A与视频B并发播放 |
| 方案一（推荐） | 播放音乐（MUSIC） | 播放视频（MOVIE） | SHARE_MODE模式，应用自行管控。如：<br> ①A流启动 -> B 流要开始 → 应用主动暂停 A 流 → B 流播放 <br> ②B 流要结束 → 应用主动恢复 A 流 → A 流继续播放 | 音乐A被视频B打断，视频B暂停，音乐A恢复 |
| 方案二 | 播放音乐（MUSIC） | 播放视频（MOVIE） | INDEPENDENT模式，与其他流触发焦点策略 | 音乐A被视频B打断，视频B暂停，音乐A不恢复 |