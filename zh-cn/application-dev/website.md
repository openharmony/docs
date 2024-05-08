# 应用开发文档

- 开发
  - Audio Kit（音频服务）
    - [Audio Kit简介](only for test/media/audio/audio-kit-intro.md)
    - 音频播放
      - [音频播放开发概述](only for test/media/audio/audio-playback-overview.md)
      - [使用AudioRenderer开发音频播放功能](only for test/media/audio/using-audiorenderer-for-playback.md)
      <!--Del-->
      - [使用TonePlayer开发音频播放功能(仅对系统应用开放)](only for test/media/audio/using-toneplayer-for-playback.md)
      <!--DelEnd-->
      - [使用OHAudio开发音频播放功能(C/C++)](only for test/media/audio/using-ohaudio-for-playback.md)
      - [使用AudioHaptic开发音振协同播放功能](only for test/media/audio/using-audiohaptic-for-playback.md)
      - [多音频播放的并发策略](only for test/media/audio/audio-playback-concurrency.md)
      - [播放音量管理](only for test/media/audio/volume-management.md)
      - [音效管理](only for test/media/audio/audio-effect-management.md)
      - [音频播放流管理](only for test/media/audio/audio-playback-stream-management.md)
      - [音频输出设备管理](only for test/media/audio/audio-output-device-management.md)
      <!--Del-->
      - [分布式音频播放(仅对系统应用开放)](only for test/media/audio/distributed-audio-playback.md)
      <!--DelEnd-->
    - 音频录制
      - [音频录制开发概述](only for test/media/audio/audio-recording-overview.md)
      - [使用AudioCapturer开发音频录制功能](only for test/media/audio/using-audiocapturer-for-recording.md)
      - [使用OHAudio开发音频录制功能(C/C++)](only for test/media/audio/using-ohaudio-for-recording.md)
      - [管理麦克风](only for test/media/audio/mic-management.md)
      - [音频录制流管理](only for test/media/audio/audio-recording-stream-management.md)
      - [音频输入设备管理](only for test/media/audio/audio-input-device-management.md)
    - 音频通话
      - [音频通话开发概述](only for test/media/audio/audio-call-overview.md)
      - [开发音频通话功能](only for test/media/audio/audio-call-development.md)
    - 不再推荐使用
      - [从OpenSL ES切换OHAudio(C/C++)](only for test/media/audio/replace-opensles-by-ohaudio.md)
      - [使用OpenSL ES开发音频播放功能(C/C++)](only for test/media/audio/using-opensl-es-for-playback.md)
      - [使用OpenSL ES开发音频录制功能(C/C++)](only for test/media/audio/using-opensl-es-for-recording.md)
  - [Media Kit（媒体服务）](only for test/media/media/Readme-CN.md)
    - [Media Kit简介](only for test/media/media/media-kit-intro.md)
    - 音频播放和录制
      - [使用AVPlayer开发音频播放功能(ArkTS)](only for test/media/media/using-avplayer-for-playback.md)
      - [使用AVPlayer开发音频播放功能(C/C++)](only for test/media/media/using-ndk-avplayer-for-playerback.md)
      - [使用SoundPool开发音频播放功能](only for test/media/media/using-soundpool-for-playback.md)
      - [使用AVRecorder开发音频录制功能](only for test/media/media/using-avrecorder-for-recording.md)
      - [获取音视频元数据](only for test/media/media/avmetadataextractor.md)
    - 视频播放和录制
      - [视频播放](only for test/media/media/video-playback.md)
      - [视频录制](only for test/media/media/video-recording.md)
      <!--Del-->
      - [屏幕录制(仅对系统应用开放)(C/C++)](only for test/media/media/avscreen-capture.md)
      <!--DelEnd-->
      - [获取视频缩略图](only for test/media/media/avimagegenerator.md)
- API参考
  - Audio Kit API参考
    - ArkTS API
      - [@ohos.multimedia.audio (音频管理)](only for test/reference/apis-audio-kit/js-apis-audio.md)
      - [@ohos.multimedia.audioHaptic (音振协同)](only for test/reference/apis-audio-kit/js-apis-audioHaptic.md)
      <!--Del-->
      - [@ohos.multimedia.audio (音频管理)(系统接口)](only for test/reference/apis-audio-kit/js-apis-audio-sys.md)
      - [@ohos.multimedia.systemSoundManager (系统声音管理)(系统接口)](only for test/reference/apis-audio-kit/js-apis-systemSoundManager-sys.md)
      - multimedia
        - [ringtonePlayer (铃声播放器)(系统接口)](only for test/reference/apis-audio-kit/js-apis-inner-multimedia-ringtonePlayer-sys.md)
        - [systemTonePlayer (系统提示音播放器)(系统接口)](only for test/reference/apis-audio-kit/js-apis-inner-multimedia-systemTonePlayer-sys.md)
      <!--DelEnd-->
    - C API
      - 模块
        - [OHAudio](only for test/reference/apis-audio-kit/_o_h_audio.md)
      - 头文件
        - [native_audiocapturer.h](only for test/reference/apis-audio-kit/native__audiocapturer_8h.md)
        - [native_audiorenderer.h](only for test/reference/apis-audio-kit/native__audiorenderer_8h.md)
        - [native_audiostream_base.h](only for test/reference/apis-audio-kit/native__audiostream__base_8h.md)
        - [native_audiostreambuilder.h](only for test/reference/apis-audio-kit/native__audiostreambuilder_8h.md)
      - 结构体
        - [OH_AudioCapturer_Callbacks_Struct](only for test/reference/apis-audio-kit/_o_h___audio_capturer___callbacks___struct.md)
        - [OH_AudioRenderer_Callbacks_Struct](only for test/reference/apis-audio-kit/_o_h___audio_renderer___callbacks___struct.md)
    - 错误码
      - [Audio错误码](only for test/reference/apis-audio-kit/errorcode-audio.md)
  - Media Kit API参考
    - ArkTS API
      - [@ohos.multimedia.media (媒体服务)](only for test/reference/apis-media-kit/js-apis-media.md)
      <!--Del-->
      - [@ohos.multimedia.media (媒体服务)(系统接口)](only for test/reference/apis-media-kit/js-apis-media-sys.md)
      <!--DelEnd-->
      - multimedia
        - [SoundPool (音频池)](only for test/reference/apis-media-kit/js-apis-inner-multimedia-soundPool.md)
      <!--Del-->
        - [SoundPool (音频池)(系统接口)](only for test/reference/apis-media-kit/js-apis-inner-multimedia-soundPool-sys.md)
      <!--DelEnd-->
    - C API
      - 模块
        - [AVPlayer](only for test/reference/apis-media-kit/_a_v_player.md)
        - [AVScreenCapture](only for test/reference/apis-media-kit/_a_v_screen_capture.md)
      - 头文件
        - [native_avscreen_capture.h](only for test/reference/apis-media-kit/native__avscreen__capture_8h.md)
        - [native_avscreen_capture_base.h](only for test/reference/apis-media-kit/native__avscreen__capture__base_8h.md)
        - [native_avscreen_capture_errors.h](only for test/reference/apis-media-kit/native__avscreen__capture__errors_8h.md)
        - [avplayer.h](only for test/reference/apis-media-kit/avplayer_8h.md)
        - [avplayer_base.h](only for test/reference/apis-media-kit/avplayer__base_8h.md)
      - 结构体
        - [AVPlayerCallback](only for test/reference/apis-media-kit/_a_v_player_callback.md)
        - [OH_AudioBuffer](only for test/reference/apis-media-kit/_o_h___audio_buffer.md)
        - [OH_AudioCaptureInfo](only for test/reference/apis-media-kit/_o_h___audio_capture_info.md)
        - [OH_AudioEncInfo](only for test/reference/apis-media-kit/_o_h___audio_enc_info.md)
        - [OH_AudioInfo](only for test/reference/apis-media-kit/_o_h___audio_info.md)
        - [OH_AVScreenCaptureCallback](only for test/reference/apis-media-kit/_o_h___a_v_screen_capture_callback.md)
        - [OH_AVScreenCaptureConfig](only for test/reference/apis-media-kit/_o_h___a_v_screen_capture_config.md)
        - [OH_RecorderInfo](only for test/reference/apis-media-kit/_o_h___recorder_info.md)
        - [OH_Rect](only for test/reference/apis-media-kit/_o_h___rect.md)
        - [OH_VideoCaptureInfo](only for test/reference/apis-media-kit/_o_h___video_capture_info.md)
        - [OH_VideoEncInfo](only for test/reference/apis-media-kit/_o_h___video_enc_info.md)
        - [OH_VideoInfo](only for test/reference/apis-media-kit/_o_h___video_info.md)
    - 错误码
      - [Media错误码](only for test/reference/apis-media-kit/errorcode-media.md)
