# 开发准备

相机应用开发的主要流程包含开发准备、设备输入、会话管理、预览、拍照和录像等。

## 申请权限

在开发相机应用时，需要先申请相机相关权限，确保应用拥有访问相机硬件及其他功能的权限，需要的权限如下表。在申请权限前，请保证符合[权限使用的基本原则](../../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。

- 使用相机拍摄前，需要申请**ohos.permission.CAMERA**相机权限。
- 当需要使用麦克风同时录制音频时，需要申请**ohos.permission.MICROPHONE**麦克风权限。
- 当需要拍摄的图片/视频显示地理位置信息时，需要申请**ohos.permission.MEDIA_LOCATION**，来访问用户媒体文件中的地理位置信息。

以上权限均需要通过弹窗向用户申请授权，具体申请方式及校验方式，请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

- 当需要读取图片或视频文件时，请优先使用媒体库[Picker选择媒体资源](../medialibrary/photoAccessHelper-photoviewpicker.md)。
- 当需要保存图片或视频文件时，请优先使用[安全控件保存媒体资源](../medialibrary/photoAccessHelper-savebutton.md)。
  
> **说明：** 
> 
> 仅应用需要克隆、备份或同步用户公共目录的图片、视频类文件时，可申请ohos.permission.READ_IMAGEVIDEO、ohos.permission.WRITE_IMAGEVIDEO权限来读写音频文件，申请方式请参考<!--RP1-->[申请受控权限](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->。

## 开发指导

当前相机提供了ArkTS和C++两种开发语言的开发指导，如下表所示。

| 开发流程 | ArkTS开发指导 | C++开发指导 |
| ------- | ------------- | --------- |
| 设备输入 | [设备输入(ArkTS)](camera-device-input.md) | [设备输入(C/C++)](native-camera-device-input.md) |
| 会话管理 | [会话管理(ArkTS)](camera-session-management.md) | [会话管理(C/C++)](native-camera-session-management.md) |
| 预览  | [预览(ArkTS)](camera-preview.md) | [预览(C/C++)](native-camera-preview.md) |
| 预览流二次处理 | -  | [预览流二次处理(C/C++)](native-camera-preview-imageReceiver.md) |
| 拍照 | [拍照(ArkTS)](camera-shooting.md) | [拍照(C/C++)](native-camera-shooting.md) |
| 分段式拍照 | [分段式拍照(ArkTS)](camera-deferred-capture.md) | -  |
| 动态照片 | [动态照片(ArkTS)](camera-moving-photo.md) | - |
| 录像 | [录像(ArkTS)](camera-recording.md) | [录像(C/C++)](native-camera-recording.md) |
| 元数据 | [元数据(ArkTS)](camera-metadata.md) | [元数据(C/C++)](native-camera-metadata.md) |