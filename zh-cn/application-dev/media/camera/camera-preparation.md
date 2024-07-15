# 开发准备

相机应用开发的主要流程包含开发准备、设备输入、会话管理、预览、拍照和录像等。

在开发相机应用时，需要先申请相机相关权限，确保应用拥有访问相机硬件及其他功能的权限，需要的权限如下表。在申请权限前，请保证符合[权限使用的基本原则](../../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。


| 权限名 | 说明 | 授权方式 | 
| -------- | -------- | -------- |
| ohos.permission.CAMERA | 允许应用使用相机拍摄照片和录制视频。 | user_grant | 
| ohos.permission.MICROPHONE | 允许应用使用麦克风（可选）。<br/>如需同时录制音频，需要申请该权限。 | user_grant | 
| ohos.permission.WRITE_MEDIA | 允许应用读写用户外部存储中的媒体文件信息（可选）。 | user_grant | 
| ohos.permission.READ_MEDIA | 允许应用读取用户外部存储中的媒体文件信息（可选）。 | user_grant | 
| ohos.permission.MEDIA_LOCATION | 允许应用访问用户媒体文件中的地理位置信息（可选）。 | user_grant | 


以上权限的授权方式均为user_grant（用户授权），即开发者在module.json5文件中配置对应的权限后，需要使用接口[abilityAccessCtrl.requestPermissionsFromUser](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)去校验当前用户是否已授权。如果是，应用可以直接访问/操作目标对象；否则需要弹框向用户申请授权。


具体申请方式及校验方式，请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。


> **说明：**
> 即使用户曾被授予过权限，应用在调用此权限保护的接口前，也应该先检查是否有权限。不能把之前授予的状态持久化，因为用户在动态授予后可能通过“设置”取消应用权限。

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
| 录像流二次处理 | - | [录像流二次处理(C/C++)](native-camera-recording-imageReceiver.md) |
| 元数据 | [元数据(ArkTS)](camera-metadata.md) | [元数据(C/C++)](native-camera-metadata.md) |