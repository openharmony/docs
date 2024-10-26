# 使用合适的音频流类型

音频流类型是用于定义音频数据的播放和录制方式的重要属性，对于播放流，其类型由[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)决定；对于录制流，其类型由[SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8)决定。音频流类型在音量控制、音频焦点管理、输入/输出设备选择等方面有决定性影响。

应用需要根据自身的业务场景和实际需求，为音频选择合适的流类型，这样可以确保其音频行为符合预期，为用户提供良好的音频体验。

## 常用的音频流类型

### 播放流类型

- **STREAM_USAGE_MUSIC**：适用于音乐场景，也可用于其他默认场景，例如[使用SoundPool](../media/using-soundpool-for-playback.md)播放简短音效等。

- **STREAM_USAGE_MOVIE**：适用于短视频、电影、电视剧等视频类场景。

- **STREAM_USAGE_AUDIOBOOK**： 适用于有声读物、听新闻、播客等场景。

- **STREAM_USAGE_GAME**：适用于游戏场景。

- **STREAM_USAGE_NAVIGATION**：适用于导航场景。

- **STREAM_USAGE_VOICE_MESSAGE**：适用于语音短消息场景。

- **STREAM_USAGE_VOICE_COMMUNICATION**：适用于VoIP语音通话场景。

- **STREAM_USAGE_ALARM**：适用于闹钟场景。

- **STREAM_USAGE_RINGTONE**：适用于VoIP来电响铃等场景。

- **STREAM_USAGE_NOTIFICATION**：适用于通知音、提示音等场景。

其他播放流类型的定义及使用场景，可参考：[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)

### 录制流类型

- **SOURCE_TYPE_MIC**：适用于普通录音场景。

- **SOURCE_TYPE_VOICE_COMMUNICATION**：适用于VoIP语音通话场景。

- **SOURCE_TYPE_VOICE_MESSAGE**：适用于录制语音短消息的场景。

其他录制流类型的定义及使用场景，可参考：[SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8)

## 流类型对音频业务的影响

### 音量控制

播放流类型[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)决定了该音频流归属于何种[音量类型（AudioVolumeType）](../../reference/apis-audio-kit/js-apis-audio.md#audiovolumetype)，不同的音量类型（如媒体、铃声、闹钟、通话等）拥有独立的音量值，互不干扰。

常见的StreamUsage与音量类型的对应关系为：

- Music、Movie、AudioBook、Game等类型会使用媒体音量。

- Ringtone、Notification等类型会使用铃声音量。

- VoiceCommunication类型会使用通话音量。

- Alarm类型会使用闹钟音量。

### 音频焦点

音频流类型在音频焦点管理中起着重要作用。不同类型的音频流（如音乐、通话、闹钟等）有不同的默认优先级和处理方式。当应用启动音频播放或者录制时，系统默认根据音频流类型申请焦点，可能打断其他音频或者降低其他音频的音量。更多音频焦点的信息，可参考：[音频焦点和音频会话介绍](./audio-playback-concurrency.md)

例如：

- 开始播放Navigation，会让正在播放的Music降低音量，后续Navigation停止时，Music会恢复音量。

- 开始播放Movie，会让正在播放的Music停止，后续Movie停止时，Music也不会收到恢复通知。

- 开始播放VoiceCommunication，会让正在播放的Music暂停，后续VoiceCommunication停止时，Music会收到恢复通知。

- Music和Game可以并发混音播放，互不影响。

- 开始录制VoiceMessage，会让正在播放的Music暂停，后续VoiceMessage录制停止时，Music会收到恢复通知。

### 输入/输出设备选择

对于不同的音频流类型，系统会默认为其选择相应的输入或输出设备。

例如：

- Music类型的默认输出设备为扬声器。

- VoiceCommunication类型的默认输入设备为麦克风，默认输出设备为听筒。

- Alarm类型的默认输出设备为扬声器‌。若先连接蓝牙耳机，再开始播放Alarm音频，则扬声器和蓝牙耳机会同时播放。

若默认的输入/输出设备不符合使用诉求，应用也可以调用相关接口主动修改。例如，应用[使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)时，可以调用[setDefaultOutputDevice](../../reference/apis-audio-kit/js-apis-audio.md#setdefaultoutputdevice12)接口，设置默认发声设备。

## 设置音频流类型

应用可以使用不同的方式实现音频播放和音频录制功能，因此设置音频流类型的方法也不尽相同。

常见的设置音频流类型的方法有：

播放流类型

- 若[使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)，则可以在调用[createAudioRenderer](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiorenderer8)接口时，传入对应的[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)。

    注：AudioRendererOptions中包含AudioRendererInfo，AudioRendererInfo中包含StreamUsage参数。

- 若[使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)，则可以在调用[OH_AudioStreamBuilder_SetRendererInfo](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setrendererinfo)接口时，传入对应的[OH_AudioStream_Usage](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_usage)。


- 若[使用AVPlayer开发音频播放功能(ArkTS)](../media/using-avplayer-for-playback.md)，则可以通过设置[属性](../../reference/apis-media-kit/js-apis-media.md#属性)audioRendererInfo中的usage来设置音频播放流类型。

    注：在设置AVPlayer的audioRendererInfo属性时，只允许在initialized状态下设置。若应用没有主动设置该属性，AVPlayer会根据媒体源是否包含视频，使用Music或Movie作为usage的默认值。

- 若[使用AVPlayer开发音频播放功能(C/C++)](../media/using-ndk-avplayer-for-playerback.md)，则可以在调用[OH_AVPlayer_SetAudioRendererInfo](../../reference/apis-media-kit/_a_v_player.md#oh_avplayer_setaudiorendererinfo)接口时，传入对应的[OH_AudioStream_Usage](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_usage)。

- 若[使用SoundPool开发音频播放功能](../media/using-soundpool-for-playback.md)，则可以在调用[createSoundPool](../../reference/apis-media-kit/js-apis-media.md#mediacreatesoundpool10)接口时，传入对应的[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)。

录制流类型

- 若[使用AudioCapturer开发音频录制功能](using-audiocapturer-for-recording.md)，则可以在调用[createAudioCapturer](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiocapturer8)接口时，传入对应的[SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8)。

    注：AudioCapturerOptions中包含AudioCapturerInfo， AudioCapturerInfo中包含SourceType参数。

- 若[使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)，则可以在调用[OH_AudioStreamBuilder_SetCapturerInfo](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostreambuilder_setcapturerinfo)接口时，传入对应的[OH_AudioStream_SourceType](../../reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_sourcetype)。

- 若[使用AVRecorder开发音频录制功能](../media/using-avrecorder-for-recording.md)，则可以在调用[prepare](../../reference/apis-media-kit/js-apis-media.md#prepare9-3)接口时，传入对应的[AudioSourceType](../../reference/apis-media-kit/js-apis-media.md#audiosourcetype9)。