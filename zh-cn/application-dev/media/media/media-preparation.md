# 开发准备

媒体应用开发的主要流程包含开发准备、音视频播放、音视频录制、元数据信息提取、录屏等。

在开发媒体应用时，需要先申请媒体相关权限，确保应用拥有访问媒体文件及其他功能的权限，需要的权限如下表。在申请权限前，请保证符合[权限使用的基本原则](../../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。


| 权限名 | 说明 | 授权方式 | 
| -------- | -------- | -------- |
| ohos.permission.MICROPHONE | 允许应用使用麦克风（可选）。<br/>如需同时录制音频，需要申请该权限。 | user_grant | 
| ohos.permission.WRITE_MEDIA | 允许应用读写用户外部存储中的媒体文件信息（可选）。 | user_grant | 
| ohos.permission.READ_MEDIA | 允许应用读取用户外部存储中的媒体文件信息（可选）。 | user_grant | 
| ohos.permission.INTERNET| 允许应用访问网络（可选）。<br/>如需访问在线媒体资源，需要申请该权限。  | user_grant | 


以上权限的授权方式均为user_grant（用户授权），即开发者在module.json5文件中配置对应的权限后，需要使用接口[abilityAccessCtrl.requestPermissionsFromUser](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)去校验当前用户是否已授权。如果是，应用可以直接访问/操作目标对象；否则需要弹框向用户申请授权。


具体申请方式及校验方式，请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

## 开发指导

当前媒体提供了ArkTS和C++两种开发语言的开发指导，如下表所示。

| 开发流程     | ArkTS开发指导                                     | C++开发指导                             |
| ------------ | ------------------------------------------------- | --------------------------------------- |
| 音频播放     | [使用AVPlayer接口播放音频(ArkTS)](using-avplayer-for-playback.md) | [使用AVPlayer接口播放音频(C/C++)](using-avplayer-for-playback.md) |
| 视频播放     | [使用AVPlayer接口播放视频(ArkTS)](-)              | [使用AVPlayer接口播放视频(C/C++)](video-playerback.md) |
| 音频录制     | [使用AVRecorder接口录制音频(ArkTS)](using-avrecorder-for-recording.md) | `-`                                     |
| 视频录制     | [使用AVRecorder接口录制视频(ArkTS)](video-recording.md) | `-`                                     |
| 元数据       | [使用AVMetadataExtractor提取音视频元数据信息(ArkTS)](-) | `-`                                     |
| 图像提取     | [使用AVImageGenerator提取视频指定时间图像(ArkTS)](-) | `-`                                     |
| 录屏取码流   | `-`                                               | [使用AVScreenCapture接口录屏取码流(C/C++)](using-avscreencapture-for-buffer.md) |
| 录屏写文件   | [使用AVScreenCaptureRecorder接口录屏写文件(ArkTS)](using-avscreencapture-ArkTs.md) | [使用AVScreenCapture接口录屏写文件(C/C++)](using-avscreencapture-for-file.md) |
| 音频池       | [使用SoundPool接口播放短音频(ArkTS)](-)           | `-`                                     |
| 视频转码     | [使用AVTranscoder接口转码(ArkTS)](using-avtranscoder-for-transcodering.md) | `-`                                     |

