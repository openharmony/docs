# 音频播放开发概述

## 如何选择音频播放开发方式

系统提供了多样化的API，来帮助开发者完成音频播放的开发，不同的API适用于不同音频数据格式、音频资源来源、音频使用场景，甚至是不同开发语言。因此，选择合适的音频播放API，有助于降低开发工作量，实现更佳的音频播放效果。

- [AudioRenderer](using-audiorenderer-for-playback.md)：用于音频输出的ArkTS/JS API，仅支持PCM格式，需要应用持续写入音频数据进行工作。应用可以在输入前添加数据预处理，如设定音频文件的采样率、位宽等，要求开发者具备音频处理的基础知识，适用于更专业、更多样化的媒体播放应用开发。

- [AudioHaptic](using-audiohaptic-for-playback.md)：用于音振协同播放的ArkTS/JS API，适用于需要在播放音频时同步发起振动的场景，如来电铃声随振、键盘按键反馈、消息通知反馈等。

- [OpenSL ES](using-opensl-es-for-playback.md)：一套跨平台标准化的音频Native API，同样提供音频输出能力，仅支持PCM格式，适用于从其他嵌入式平台移植，或依赖在Native层实现音频输出功能的播放应用使用。

- [OHAudio](using-ohaudio-for-playback.md)：用于音频输出的Native API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。仅支持PCM格式，适用于依赖Native层实现音频输出功能的场景。<!--Del-->

- [TonePlayer](using-toneplayer-for-playback.md)：拨号和回铃音播放ArkTS/JS API，只能在固定的类型范围内选择播放内容，无需输入媒体资源或音频数据，适用于拨号盘按键和通话回铃音的特定场景。该功能当前仅对系统应用开放。<!--DelEnd-->

除上述方式外，也可以通过Media Kit实现音频播放。

- [AVPlayer](../media/using-avplayer-for-playback.md)：用于音频播放的ArkTS/JS API，集成了流媒体和本地资源解析、媒体资源解封装、音频解码和音频输出功能。可用于直接播放mp3、m4a等格式的音频文件，不支持直接播放PCM格式文件。

- [SoundPool](../media/using-soundpool-for-playback.md)：低时延的短音播放ArkTS/JS API，适用于播放急促简短的音效，如相机快门音效、按键音效、游戏射击音效等。

## 开发音频播放应用须知

应用如果要实现后台播放或熄屏播放，需要同时满足：

1. 使用媒体会话功能注册到系统内统一管理，否则在应用进入后台时，播放将被强制停止。具体参考[AVSession Kit开发指导](../avsession/avsession-overview.md)。

2. 申请长时任务避免进入挂起（Suspend）状态。具体参考[长时任务开发指导](../../task-management/continuous-task.md)。

当应用进入后台，播放被中断，如果被媒体会话管控，将打印日志“pause id”；如果没有该日志，则说明被长时任务管控。
