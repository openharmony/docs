# 申请相机开发的权限

相机应用开发的主要流程包含开发准备、设备输入、会话管理、预览、拍照和录像等。

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
