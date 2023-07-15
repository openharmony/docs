# 音频录制开发概述

## 如何选择音频录制开发方式

在OpenHarmony系统中，多种API都提供了音频录制开发的支持，不同的API适用于不同录音输出格式、音频使用场景或不同开发语言。因此，选择合适的音频录制API，有助于降低开发工作量，实现更佳的音频录制效果。

- [AVRecorder](using-avrecorder-for-recording.md)：功能较完善的音频、视频录制ArkTS/JS API，集成了音频输入录制、音频编码和媒体封装的功能。开发者可以直接调用设备硬件如麦克风录音，并生成m4a音频文件。

- [AudioCapturer](using-audiocapturer-for-recording.md)：用于音频输入的的ArkTS/JS API，仅支持PCM格式，需要应用持续读取音频数据进行工作。应用可以在音频输出后添加数据处理，要求开发者具备音频处理的基础知识，适用于更专业、更多样化的媒体录制应用开发。

- [OpenSL ES](using-opensl-es-for-recording.md)：一套跨平台标准化的音频Native API，目前阶段唯一的音频类Native API，同样提供音频输入原子能力，仅支持PCM格式，适用于从其他嵌入式平台移植，或依赖在Native层实现音频输入功能的录音应用使用。

## 开发音频录制应用须知

应用可以调用麦克风录制音频，但该行为属于隐私敏感行为，在调用麦克风前，需要先向用户申请权限“ohos.permission.MICROPHONE”。

权限申请的流程请参考[访问控制授权申请指导](../security/accesstoken-guidelines.md)。如何使用和管理麦克风请参考[管理麦克风](mic-management.md)。
