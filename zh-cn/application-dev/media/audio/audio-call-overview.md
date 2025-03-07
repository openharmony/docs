# 音频通话开发概述

常用的音频通话模式包括VoIP通话和蜂窝通话。

- VoIP通话：
  VoIP（Voice over Internet Protocol）通话是指基于互联网协议（IP）进行通讯的一种语音通话技术。VoIP通话会将通话信息打包成数据包，通过网络进行传输，因此VoIP通话对网络要求较高，通话质量与网络连接速度紧密相关。

- 蜂窝通话（仅对系统应用开放）：
  蜂窝通话是指传统的电话功能，由运营商提供服务，目前仅对系统应用开放，未向第三方应用提供开发接口。

在开发音频通话相关功能时，开发者可以根据实际情况，检查当前的[音频场景模式](#音频场景模式)和[铃声模式](#铃声模式)，以使用相应的音频处理策略。

## 音频场景模式

应用使用音频通话相关功能时，系统会切换至与通话相关的音频场景模式（[AudioScene](../../reference/apis-audio-kit/js-apis-audio.md#audioscene8)），当前预置了多种音频场景，包括响铃、通话、语音聊天等，在不同的场景下，系统会采用不同的策略来处理音频。
<!--Del-->
如在蜂窝通话场景中会更注重人声的清晰度。系统会使用3A算法对音频数据进行预处理，抑制通话回声，消除背景噪音，调整音量范围，从而达到清晰人声的效果。3A算法，指声学回声消除（Acoustic Echo Cancellation, AEC）、背景噪声抑制（Active Noise Control, ANC）、自动增益控制（Automatic Gain Control, AGC）三种音频处理算法。<!--DelEnd-->

当前预置的音频场景：

- AUDIO_SCENE_DEFAULT：默认音频场景，音频通话之外的场景均可使用。<!--Del-->

- AUDIO_SCENE_RINGING：响铃音频场景，来电响铃时使用，仅对系统应用开放。

- AUDIO_SCENE_PHONE_CALL：蜂窝通话音频场景，蜂窝通话时使用，仅对系统应用开放。<!--DelEnd-->

- AUDIO_SCENE_VOICE_CHAT：语音聊天音频场景，VoIP通话时使用。

应用可通过[AudioManager](../../reference/apis-audio-kit/js-apis-audio.md#audiomanager)的getAudioScene来获取当前的音频场景模式。当应用开始或结束使用音频通话相关功能时，可通过此方法检查系统是否已切换为合适的音频场景模式。

## 铃声模式

在用户进入到音频通话时，应用可以使用铃声或振动来提示用户。系统通过调整铃声模式（[AudioRingMode](../../reference/apis-audio-kit/js-apis-audio.md#audioringmode)），实现便捷地管理铃声音量，并调整设备的振动模式。

当前预置的三种铃声模式：

- RINGER_MODE_SILENT：静音模式，此模式下铃声音量为零（即静音）。

- RINGER_MODE_VIBRATE：振动模式，此模式下铃声音量为零，设备振动开启（即响铃时静音，触发振动）。

- RINGER_MODE_NORMAL：响铃模式，此模式下铃声音量正常。

应用可以调用[AudioVolumeGroupManager](../../reference/apis-audio-kit/js-apis-audio.md#audiovolumegroupmanager9)中的getRingerMode获取当前的铃声模式，以便采取合适的提示策略。

如果应用希望及时获取铃声模式的变化情况，可以通过AudioVolumeGroupManager中的on('ringerModeChange')监听铃声模式变化事件，使应用在铃声模式发生变化时及时收到通知，方便应用做出相应的调整。

## 通话场景音频设备切换

在通话场景下，系统会根据默认优先级选择合适的音频设备。应用可以根据需要，切换音频设备。

切换方式可参考[AVSession Kit使用通话设备切换组件](../avsession/using-switch-call-devices.md)。
