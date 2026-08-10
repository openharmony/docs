# 选择合适的录制流类型
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

录制流类型由[SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8)定义，用于向系统标识录制流的使用场景。系统会将其用于[音频焦点策略](audio-playback-concurrency.md#音频焦点策略)和[音频通路配置](audio-performance.md#了解系统音频通路)，部分类型还对应特定的录音处理场景。

选择SourceType时，应先确定录制数据的实际用途，再选择与业务场景匹配的类型。仅当业务属于普通录音且没有语音识别、通话、语音消息、录像、直播或获取未处理音频等明确需求时，才选择SOURCE_TYPE_MIC。不建议所有录制场景都使用该类型，因为不同录制流类型对应不同的系统优化处理策略，如果类型选择不当，会导致相应的优化策略不生效，影响录音效果和用户体验。例如，在VoIP通话场景下错误使用SOURCE_TYPE_MIC，会使降噪、环境音抑制等优化策略不生效，导致通话质量不佳。实际使用的输入设备、音频通路和可用处理能力还取决于设备能力及系统配置。

## 常用的录制流类型及其适用场景

| 音频流使用类型（SourceType） | 适用场景 | 主要效果与选择说明 |
| ---------- | ---------- | ---------- |
| SOURCE_TYPE_MIC | 普通录音，如录音机。 | 系统按普通录音场景配置默认输入通路和录音处理。存在更明确的业务类型时，优先选择对应类型。 |
| SOURCE_TYPE_VOICE_RECOGNITION<sup>9+</sup> | 语音识别。 | 对应语音识别处理场景，系统可根据设备配置匹配语音识别输入通路。 |
| SOURCE_TYPE_PLAYBACK_CAPTURE | 录制其他应用送到系统中播放的原始音频数据。 | 从API版本12开始废弃，Audio Kit不再提供内录接口。内录场景请使用[AVScreenCapture](../../reference/apis-media-kit/capi-avscreencapture.md)。 |
| SOURCE_TYPE_VOICE_COMMUNICATION | VoIP语音或视频通话。 | 增强人声录制并抑制环境音等非人声。根据[SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8)定义，单独启动录制会开启3A算法。 |
| SOURCE_TYPE_VOICE_MESSAGE<sup>12+</sup> | 录制语音短消息。 | 标识语音消息录制场景。根据系统默认的[音频焦点策略](audio-playback-concurrency.md#音频焦点策略)，开始录制时会暂停正在播放的音乐，并在录制结束后通知音乐应用恢复播放。 |
| SOURCE_TYPE_CAMCORDER<sup>13+</sup> | 相机录像。 | 向系统标识录像用途，系统可根据设备配置匹配录像输入通路。 |
| SOURCE_TYPE_UNPROCESSED<sup>14+</sup> | 获取麦克风采集的原始音频。 | 根据[SourceType](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8)定义，系统不对采集数据进行算法处理。 |
| SOURCE_TYPE_LIVE<sup>20+</sup> | 直播。 | 在支持的设备上，系统会提供[回声消除功能](using-audiocapturer-for-recording.md#回声消除功能)。使用前可调用[isAcousticEchoCancelerSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isacousticechocancelersupported20)查询当前设备是否支持该能力。 |

## 录制流类型对音频业务的影响

系统会根据录制流类型配置相应的音频焦点、输入通路和优化处理策略，因此SourceType会影响录音效果。例如，在VoIP通话场景下使用SOURCE_TYPE_MIC而不是SOURCE_TYPE_VOICE_COMMUNICATION，可能会使降噪、环境音抑制等优化策略不生效，造成通话体验不佳。

### 音频焦点调整

系统会根据录制流类型和音频流启动顺序进行音频焦点决策。例如，开始录制语音短消息（VoiceMessage）时，会暂停正在播放的音乐（Music）；录制结束后，播放音乐的应用将收到恢复播放通知。更多信息请参考[音频焦点策略](audio-playback-concurrency.md#音频焦点策略)。

### 输入设备选择

系统会根据录制流类型选择相应的输入设备。例如，SOURCE_TYPE_MIC默认使用内置麦克风录音，SOURCE_TYPE_VOICE_COMMUNICATION的输入设备会跟随当前输出设备。若默认输入设备不符合使用诉求，请参考[实现音频输入设备路由切换](audio-input-device-switcher.md)。

## 设置录制流类型

应用可采用多种方式实现音频录制，各方式设置录制流类型的方法如下：

- [使用AudioCapturer开发音频录制功能(ArkTS)](using-audiocapturer-for-recording.md)：调用[createAudioCapturer](../../reference/apis-audio-kit/arkts-apis-audio-f.md#audiocreateaudiocapturer8)时，通过AudioCapturerOptions中的AudioCapturerInfo.source指定SourceType。
- [推荐使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)：调用[OH_AudioStreamBuilder_SetCapturerInfo](../../reference/apis-audio-kit/capi-native-audiostreambuilder-h.md#oh_audiostreambuilder_setcapturerinfo)时，传入[OH_AudioStream_SourceType](../../reference/apis-audio-kit/capi-native-audiostream-base-h.md#oh_audiostream_sourcetype)。
- [使用AVRecorder录制音频(ArkTS)](../media/using-avrecorder-for-recording.md)：调用[AVRecorder.prepare](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#prepare9-1)时，通过AVRecorderConfig.audioSourceType指定[AudioSourceType](../../reference/apis-media-kit/arkts-apis-media-e.md#audiosourcetype9)。

## 使用不同录制通路

音频通路是音频数据在系统内部的传输和处理路径。系统通过SourceType获取录制场景信息，并结合采样率、声道数、编码格式等参数选择合适的音频通路。常见录制通路如下：

| 音频通路类型 | 特征 | 适用场景 |
| ---------- | ---------- | ---------- |
| 低时延录制通路 | 通过缩短缓冲和最小化音效算法降低时延。 | K歌场景。 |
| 普通录制通路 | 通用通路，按当前设备默认音频格式输入。 | 录音机、相机录制、语音消息等。 |

应用可以调用[isFastRecordingSupported](../../reference/apis-audio-kit/arkts-apis-audio-AudioStreamManager.md#isfastrecordingsupported)，在创建音频流之前查询设备是否支持低时延录制。

> **说明：**
>
> - 音频通路的支持情况取决于设备的硬件能力和系统配置，不同设备有所不同。
> - 查询接口返回的结果仅表示在指定参数下系统是否支持对应的音频通路，实际使用的通路还需结合系统当前的运行状态和资源配置情况确定。
