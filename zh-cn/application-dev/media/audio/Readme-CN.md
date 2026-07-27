# Audio Kit（音频服务）
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @boxwall-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

- [Audio Kit简介](audio-kit-intro.md)
- 音频焦点和音频会话管理<!--audio-session-->
  - [音频焦点和音频会话开发概述](audio-playback-concurrency-audio-session-overview.md)
  - [音频焦点介绍](audio-playback-concurrency.md)
  - [音频会话管理(ArkTS)](audio-session-management.md)
  - [使用OHAudio开发音频会话功能(C/C++)](using-ohaudio-for-session.md)
- 音频播放<!--audio-playback-->
  - [音频播放开发概述](audio-playback-overview.md)
  - [选择合适的播放流类型](using-right-streamusage-for-playback.md)
  - [推荐使用OHAudio开发音频播放功能(C/C++)](using-ohaudio-for-playback.md)
  - [使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)
  <!--Del-->
  - [使用TonePlayer开发音频播放功能(仅对系统应用开放)](using-toneplayer-for-playback-sys.md)
  <!--DelEnd-->
  - [低时延音频播放(C/C++)](audio-fast-playback.md)
  - [低功耗音频播放](power-saving-for-playback.md)
  - [使用AudioHaptic开发音振协同播放功能(ArkTS)](using-audiohaptic-for-playback.md)
  - [使用SoundPlayer开发系统音效播放功能](using-soundplayer-for-playback.md)
  - [播放音量管理](volume-management.md)
  - [空间音频能力查询和状态订阅](public-audio-spatialization-management.md)
  <!--Del-->
  - [空间音频管理(仅对系统应用开放)](audio-spatialization-management-sys.md)
  <!--DelEnd-->
  - [音频播放流管理](audio-playback-stream-management.md)
  <!--Del-->
  - [分布式音频播放(仅对系统应用开放)](distributed-audio-playback-sys.md)
  <!--DelEnd-->
  <!--Del-->
  - [移动全景声管理（仅对系统应用开放）](audio-collaborative-management-sys.md)
  <!--DelEnd-->
- 音频录制<!--audio-recording-->
  - [音频录制开发概述](audio-recording-overview.md)
  - [选择合适的录制流类型](using-right-sourcetype-for-recording.md)
  - [推荐使用OHAudio开发音频录制功能(C/C++)](using-ohaudio-for-recording.md)
  - [使用AudioCapturer开发音频录制功能(ArkTS)](using-audiocapturer-for-recording.md)
  - [低时延音频录制(C/C++)](audio-fast-recording.md)
  - [实现后台录音](background-recording.md)
  - [管理麦克风静音状态](mic-management.md)
  - [查询和监听其他应用录制状态](audio-recording-stream-management.md)
  - [录音并发策略说明](audio-recording-concurrency.md)
  - [实现自定义耳返](audio-ear-monitor.md)
  - [实现低时延耳返](audio-ear-monitor-loopback.md)
- 音频设备路由管理<!--audio-device-->
  - [查询和监听音频输入设备](audio-input-device-management.md)
  - [查询和监听音频输出设备](audio-output-device-management.md)
  - [实现音频输入设备路由切换](audio-input-device-switcher.md)
  - [实现音频输出设备路由切换](audio-output-device-switcher.md)
  - [响应输出设备变更时合理暂停](audio-output-device-change.md)
- 音频通话<!--audio-call-->
  - [音频通话开发概述](audio-call-overview.md)
  - [开发音频通话功能](audio-call-development.md)
- 音频性能调优<!--audio-performance-optimization-->
  - [提升音频性能体验](audio-performance.md)
  - [音频工作组管理](audio-workgroup.md)
- 音频编创<!--audio-production-creation-->
  - [音频编创开发概述(C/C++)](audio-suite.md)
  - [离线编辑(C/C++)](audio-suite-manual-rendering.md)
  - [实时预览(C/C++)](audio-suite-real-time-rendering.md)
  - [音频格式转换(C/C++)](audio-suite-format-converter.md)
  - [空间渲染(C/C++)](audio-suite-space-render.md)
- MIDI设备通信<!--midi-->
  - [OH_MIDI概述(C/C++)](midi-overview.md)
  - [使用OH_MIDI进行MIDI开发(C/C++)](using-ohmidi.md)
- OpenSL ES开发指导(不再推荐)<!--not-recommended-->
  - [从OpenSL ES切换OHAudio(C/C++)](replace-opensles-by-ohaudio.md)
  - [使用OpenSL ES开发音频播放功能(C/C++)](using-opensl-es-for-playback.md)
  - [使用OpenSL ES开发音频录制功能(C/C++)](using-opensl-es-for-recording.md)
- Audio Kit常见问题<!--audio-issues-->
  - [使用音频快照获取问题定位信息](audio-runtime-debugging-info.md)
  - [录音无声定位指导](audio-recording-no-audio-troubleshooting.md)
- [Audio Kit术语](audio-glossary.md)