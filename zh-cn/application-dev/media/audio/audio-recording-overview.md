# 音频录制开发概述
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @weixin_41398971-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

## 如何选择音频录制开发方式

系统提供了多样化的API，来帮助开发者完成音频录制的开发，不同的API适用于不同录音输出格式、音频使用场景或不同开发语言。因此，选择合适的音频录制API，有助于降低开发工作量，实现更佳的音频录制效果。

- [AudioCapturer](using-audiocapturer-for-recording.md)：用于音频输入的ArkTS/JS API，仅支持PCM格式，需要应用持续读取音频数据进行工作。应用可以在音频采集后添加数据处理，要求开发者具备音频处理的基础知识，适用于更专业、更多样化的媒体录制应用开发。

- [OHAudio](using-ohaudio-for-recording.md)：用于音频输入的Native API，此API在设计上实现归一，同时支持普通音频通路和低时延通路。仅支持PCM格式，适用于依赖Native层实现音频输入功能的场景。

如果开发者需要采集设备内部播放音频，可参考[实现录制系统音频](implement-system-audio-recording.md)。

除上述方式外，也可以通过Media Kit中的AVRecorder实现音频录制。

- [AVRecorder](../media/using-avrecorder-for-recording.md)：用于音频录制的ArkTS/JS API，集成了音频采集、音频编码和媒体封装的功能。开发者可以直接调用设备硬件如麦克风录音，并生成m4a音频文件。

## 开发音频录制应用须知

- 应用可以调用麦克风录制音频，但该行为属于隐私敏感行为，在调用麦克风前，需要先[向用户申请授权](../../security/AccessToken/request-user-authorization.md)：ohos.permission.MICROPHONE。
  
  如何管理麦克风静音状态，请参考[管理麦克风静音状态](mic-management.md)。

- 如果需要持续录制或后台录制，请申请长时任务避免进入挂起（Suspend）状态。具体参考[长时任务(ArkTS)](../../task-management/continuous-task.md)。
- 录制需要在前台启动，启动后可以退后台。在后台启动录制将会失败。
- 应用录制音频时需要使用合适的录制流类型，请参考[选择合适的录制流类型](using-right-sourcetype-for-recording.md)。
- 如果需要判断麦克风是否被占用，请参考[判断麦克风是否被占用](audio-recording-stream-management.md#判断麦克风是否被占用)。
- 如果开发者需要实现屏幕录制功能，可参考[使用AVScreenCaptureRecorder录屏写文件(ArkTS)](../media/using-avscreencapture-ArkTs.md)和[使用AVScreenCapture录屏写文件(C/C++)](../media/using-avscreencapture-for-file.md)。




