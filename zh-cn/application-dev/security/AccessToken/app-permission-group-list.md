# 应用权限组列表

## 使用须知

- 在申请目标权限前，建议开发者先阅读[应用权限管控概述-权限组和子权限](app-permission-mgmt-overview.md#权限组和子权限)，了解相关概念，再合理申请对应的权限组。

- 当应用请求权限时，同一个权限组的权限将会在一个弹窗内一起请求用户授权，用户同意授权后，权限组内权限将被统一授权。地理位置、通讯录、通话记录、电话、信息、日历权限组除外。
  
  以位置信息和相机权限组举例说明：

  - 当应用只申请了权限ohos.permission.APPROXIMATELY_LOCATION（属于位置信息权限组）时，应用用户将收到一个请求位置信息的弹窗，包含单个权限的申请。
  - 当应用同时申请权限ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION（均属于位置信息权限组）时，应用用户将收到一个请求位置信息的弹窗，包含两个权限的申请。
  - 当应用同时申请权限ohos.permission.APPROXIMATELY_LOCATION（属于位置信息权限组）和ohos.permission.CAMERA（属于相机权限组）时，应用用户将收到请求位置信息、请求使用相机的两个弹窗。

- 当前系统支持的权限组如下所示，各子权限的含义请查阅[应用权限列表](permissions-for-all-user.md)。

## 位置<!--Del-->信息<!--DelEnd-->

- [ohos.permission.LOCATION_IN_BACKGROUND](permissions-for-all-user.md#ohospermissionlocation_in_background)

- [ohos.permission.LOCATION](permissions-for-all-user.md#ohospermissionlocation)

- [ohos.permission.APPROXIMATELY_LOCATION](permissions-for-all-user.md#ohospermissionapproximately_location)

## 相机

- [ohos.permission.CAMERA](permissions-for-all-user.md#ohospermissioncamera)

## 麦克风

- [ohos.permission.MICROPHONE](permissions-for-all-user.md#ohospermissionmicrophone)

## 通讯录

- [ohos.permission.READ_CONTACTS](restricted-permissions.md#ohospermissionread_contacts)

- [ohos.permission.WRITE_CONTACTS](restricted-permissions.md#ohospermissionwrite_contacts)

## 日历

- [ohos.permission.READ_CALENDAR](permissions-for-all-user.md#ohospermissionread_calendar)
 
- [ohos.permission.WRITE_CALENDAR](permissions-for-all-user.md#ohospermissionwrite_calendar)
 
<!--Del-->
- [ohos.permission.READ_WHOLE_CALENDAR](permissions-for-system-apps-user.md#ohospermissionread_whole_calendar)

- [ohos.permission.WRITE_WHOLE_CALENDAR](permissions-for-system-apps-user.md#ohospermissionwrite_whole_calendar)
<!--DelEnd-->

<!--RP1-->
## 健身运动

- [ohos.permission.ACTIVITY_MOTION](permissions-for-all-user.md#ohospermissionactivity_motion)

## 身体传感器

- [ohos.permission.READ_HEALTH_DATA](permissions-for-all-user.md#ohospermissionread_health_data)
<!--RP1End-->

## 图片和视频

- [ohos.permission.WRITE_IMAGEVIDEO](restricted-permissions.md#ohospermissionwrite_imagevideo)

- [ohos.permission.READ_IMAGEVIDEO](restricted-permissions.md#ohospermissionread_imagevideo)

- [ohos.permission.MEDIA_LOCATION](permissions-for-all-user.md#ohospermissionmedia_location)

- [ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO](restricted-permissions.md#ohospermissionshort_term_write_imagevideo)

## 音乐和音频

- [ohos.permission.WRITE_AUDIO](restricted-permissions.md#ohospermissionwrite_audio)

- [ohos.permission.READ_AUDIO](restricted-permissions.md#ohospermissionread_audio)

<!--RP2-->
## 广告跟踪

- [ohos.permission.APP_TRACKING_CONSENT](permissions-for-all-user.md#ohospermissionapp_tracking_consent)
<!--RP2End-->

<!--Del-->
## 读取已安装应用列表

- [ohos.permission.GET_INSTALLED_BUNDLE_LIST](permissions-for-system-apps-user.md#ohospermissionget_installed_bundle_list)
<!--DelEnd-->

<!--RP3-->
## 多设备协同

- [ohos.permission.DISTRIBUTED_DATASYNC](permissions-for-all-user.md#ohospermissiondistributed_datasync)

## 蓝牙

- [ohos.permission.ACCESS_BLUETOOTH](permissions-for-all-user.md#ohospermissionaccess_bluetooth)

## 星闪

- [ohos.permission.ACCESS_NEARLINK](permissions-for-all-user.md#ohospermissionaccess_nearlink)
<!--RP3End-->

<!--Del-->
## 电话

- [ohos.permission.ANSWER_CALL](permissions-for-system-apps-user.md#ohospermissionanswer_call)

- [ohos.permission.MANAGE_VOICEMAIL](permissions-for-system-apps-user.md#ohospermissionmanage_voicemail)

## 通话记录

- [ohos.permission.READ_CALL_LOG](permissions-for-system-apps-user.md#ohospermissionread_call_log)

- [ohos.permission.WRITE_CALL_LOG](permissions-for-system-apps-user.md#ohospermissionwrite_call_log)

## 信息

- [ohos.permission.READ_CELL_MESSAGES](permissions-for-system-apps-user.md#ohospermissionread_cell_messages)

- [ohos.permission.READ_MESSAGES](permissions-for-system-apps-user.md#ohospermissionread_messages)

- [ohos.permission.RECEIVE_MMS](permissions-for-system-apps-user.md#ohospermissionreceive_mms)

- [ohos.permission.RECEIVE_SMS](permissions-for-system-apps-user.md#ohospermissionreceive_sms)

- [ohos.permission.RECEIVE_WAP_MESSAGES](permissions-for-system-apps-user.md#ohospermissionreceive_wap_messages)

- [ohos.permission.SEND_MESSAGES](permissions-for-system-apps-user.md#ohospermissionsend_messages)
<!--DelEnd-->

## 剪切板

- [ohos.permission.READ_PASTEBOARD](restricted-permissions.md#ohospermissionread_pasteboard)

## 截屏

- [ohos.permission.CUSTOM_SCREEN_CAPTURE](permissions-for-all-user.md#ohospermissioncustom_screen_capture)

## 文件夹

> **说明：**
> 仅2in1设备可申请。

- [ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY](permissions-for-all-user.md#ohospermissionread_write_download_directory)

- [ohos.permission.READ_WRITE_DESKTOP_DIRECTORY](restricted-permissions.md#ohospermissionread_write_desktop_directory)
- [ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY](permissions-for-all-user.md#ohospermissionread_write_documents_directory)

## 文件<sup>(deprecated)</sup>

> **说明：**
> 从API 12开始，该权限组及其子权限废弃。

<!--Del-->
- ohos.permission.READ_DOCUMENT

- ohos.permission.WRITE_DOCUMENT
<!--DelEnd-->
- ohos.permission.READ_MEDIA

- ohos.permission.WRITE_MEDIA

**废弃替代方案：**

- 读写媒体库图片或视频：

  - 推荐方案（无需申请权限）：使用[Picker](../../media/medialibrary/photoAccessHelper-photoviewpicker.md)读取媒体库的图片与视频；使用[保存控件](../../media/medialibrary/photoAccessHelper-savebutton.md#安全控件保存)保存媒体库的图片与视频。
  - 受限使用方案：申请受限权限[ohos.permission.READ_IMAGEVIDEO](restricted-permissions.md#ohospermissionread_imagevideo)或[ohos.permission.WRITE_IMAGEVIDEO](restricted-permissions.md#ohospermissionwrite_imagevideo)读取媒体库的图片与视频。

- 读取媒体库音频文件：

  申请受限权限[ohos.permission.READ_AUDIO](restricted-permissions.md#ohospermissionread_audio)或[ohos.permission.WRITE_AUDIO](restricted-permissions.md#ohospermissionwrite_audio)读写媒体库的音频文件。

- 读取文件管理器中的文件：

  无需申请权限，通过文件Picker读写文件管理器中的文件。参考：[选择用户文件](../../file-management/select-user-file.md#选择文档类文件)、[保存用户文件](../../file-management/save-user-file.md#保存文档类文件)。

