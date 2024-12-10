# 开发准备

媒体应用开发的主要流程包含开发准备、音视频播放、音视频录制、元数据信息提取、录屏等。

在开发媒体应用时，需要先申请相关权限，确保应用拥有访问媒体文件及其他功能的权限，例如若希望访问在线媒体资源，则需要申请 ohos.permission.INTERNET 权限。在申请权限前，请保证符合[权限使用的基本原则](../../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。

媒体相关权限的授权方式大多均为user_grant（用户授权），即开发者在module.json5文件中配置对应的权限后，需要使用接口[abilityAccessCtrl.requestPermissionsFromUser](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)去校验当前用户是否已授权。如果是，应用可以直接访问/操作目标对象；否则需要弹框向用户申请授权。


具体申请方式及校验方式，请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

## 开发指导

当前媒体提供了ArkTS和C++两种开发语言的开发指导，如下表所示。

| 开发流程     | ArkTS开发指导                                     | C++开发指导                             |
| ------------ | ------------------------------------------------- | --------------------------------------- |
| 音频播放     | [使用AVPlayer接口播放音频(ArkTS)](using-avplayer-for-playback.md) | [使用AVPlayer接口播放音频(C/C++)](using-ndk-avplayer-for-playerback.md) |
| 视频播放     | [使用AVPlayer接口播放视频(ArkTS)](video-playback.md)              | - |
| 流媒体     |  [使用AVPlayer播放流媒体(ArkTS)](streaming-media-playback-development-guide.md)              | - |
| 添加字幕     | [使用AVPlayer接口添加视频外挂字幕(ArkTS)](video-subtitle.md) | -                                    |
| 音频池       | [使用SoundPool接口播放短音频(ArkTS)](using-soundpool-for-playback.md)           | -                                     |
| 音频录制     | [使用AVRecorder接口录制音频(ArkTS)](using-avrecorder-for-recording.md) | -                                     |
| 视频录制     | [使用AVRecorder接口录制视频(ArkTS)](video-recording.md) | -                                     |
| 录屏写文件   | [使用AVScreenCaptureRecorder接口录屏写文件(ArkTS)](using-avscreencapture-ArkTs.md) | [使用AVScreenCapture接口录屏写文件(C/C++)](using-avscreencapture-for-file.md) |
| 元数据       | [使用AVMetadataExtractor提取音视频元数据信息(ArkTS)](avmetadataextractor.md) | -                                     |
| 图像提取     | [使用AVImageGenerator提取视频指定时间图像(ArkTS)](avimagegenerator.md) | -                                     |
| 视频转码     | [使用AVTranscoder接口转码(ArkTS)](using-avtranscoder-for-transcodering.md) | -                                     |
| 录屏取码流   | -                                               | [使用AVScreenCapture接口录屏取码流(C/C++)](using-avscreencapture-for-buffer.md) |


