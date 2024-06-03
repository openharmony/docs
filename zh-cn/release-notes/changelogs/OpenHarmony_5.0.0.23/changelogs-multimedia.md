# 媒体子系统音频接口变更说明

## c1.multimedia.1 ohos.multimedia.audio 音频内录接口废弃
**访问级别**

公开接口

**废弃原因**

音频框架的音频内录接口，收到播放框架的录屏模块统一对外开放

**废弃影响**

非兼容性变更：已有的基于API10/11开发的应用仍可以正常使用该功能，基于API12的应用使用废弃的接口，无法获取有效数据，需迁移使用MediaKit的录屏模块功能。

**废弃发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**废弃的接口**

1. AudioCapturerOptions的成员变量 playbackCaptureConfig?: AudioPlaybackCaptureConfig;
2. 接口AudioPlaybackCaptureConfig和AudioPlaybackCaptureConfig的成员 filterOptions: CaptureFilterOptions;
3. 接口CaptureFilterOptions和CaptureFilterOptions的成员 usages: Array\<StreamUsage\>;

**适配指导**

参考使用MeidaKit的[AVScreenCapture接口](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_audiocapturesourcetype-1)。


## c1.multimedia.2 native_audiostream_base.h 音频内录接口废弃
**访问级别**

公开接口

**废弃原因**

音频框架的音频内录接口，收到播放框架的录屏模块统一对外开放

**废弃影响**

非兼容性变更：已有的基于API10/11开发的应用仍可以正常使用该功能，基于API12的应用使用废弃的接口，无法获取有效数据，需迁移使用MediaKit的录屏模块功能。

**废弃发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**废弃的接口**

OH_AudioStream_SourceType的AUDIOSTREAM_SOURCE_TYPE_PLAYBACK_CAPTURE枚举值。

**适配指导**

参考使用MeidaKit的[AVScreenCapture接口](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_audiocapturesourcetype-1)。