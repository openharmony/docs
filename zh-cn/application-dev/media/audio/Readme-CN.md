# Audio Kit（音频服务）

- [Audio Kit简介](audio-kit-intro.md)
- [使用合适的音频类型](using-right-streamusage-and-sourcetype.md)
- [音频焦点和音频会话介绍](audio-playback-concurrency.md)
- 音频焦点管理<!--audio-session-->
  - [使用AudioSession管理应用音频焦点(ArkTS)](audio-session-management.md)
  - [使用AudioSession管理应用音频焦点(C/C++)](using-ohaudio-for-session.md)
- 音频播放<!--audio-playback-->
  - [音频播放开发概述](audio-playback-overview.md)
  - [使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)
  - [响应音频流输出设备变更](audio-output-device-change.md)
  <!--Del-->
  - [使用TonePlayer开发音频播放功能(仅对系统应用开放)](using-toneplayer-for-playback.md)
  <!--DelEnd-->
  - [使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)
  - [使用AudioHaptic开发音振协同播放功能](using-audiohaptic-for-playback.md)
  - [播放音量管理](volume-management.md)
  - [音频时延管理](audio-latency.md)
  - [音效管理](audio-effect-management.md)
  - [空间音频管理](public-audio-spatialization-management.md)
  <!--Del-->
  - [空间音频管理(仅对系统应用开放)](audio-spatialization-management.md)
  <!--DelEnd-->
  - [音频播放流管理](audio-playback-stream-management.md)
  - [管理全局音频输出设备](audio-output-device-management.md)
  <!--Del-->
  - [分布式音频播放(仅对系统应用开放)](distributed-audio-playback.md)
  <!--DelEnd-->
- 音频录制<!--audio-recording-->
  - [音频录制开发概述](audio-recording-overview.md)
  - [使用AudioCapturer开发音频录制功能](using-audiocapturer-for-recording.md)
  - [使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)
  - [管理麦克风](mic-management.md)
  - [音频录制流管理](audio-recording-stream-management.md)
  - [管理全局音频输入设备](audio-input-device-management.md)
  - [共享音频输入](audio-recording-concurrency.md)
  - [实现音频耳返](audio-ear-monitor.md)
- 音频通话<!--audio-call-->
  - [音频通话开发概述](audio-call-overview.md)
  - [开发音频通话功能](audio-call-development.md)
- 不再推荐使用<!--not-recommended-->
  - [从OpenSL ES切换OHAudio(C/C++)](replace-opensles-by-ohaudio.md)
  - [使用OpenSL ES开发音频播放功能(C/C++)](using-opensl-es-for-playback.md)
  - [使用OpenSL ES开发音频录制功能(C/C++)](using-opensl-es-for-recording.md)