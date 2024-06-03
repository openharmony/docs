# 应用权限组列表

## 使用须知

- 在申请目标权限前，建议开发者先阅读[应用权限管控概述-权限组和子权限](app-permission-mgmt-overview.md#权限组和子权限)，了解相关概念，再合理申请对应的权限组。

- 当应用请求权限时，同一个权限组的权限将会在一个弹窗内一起请求用户授权，用户同意授权后，权限组内权限将被统一授权。地理位置、通讯录、通话记录、电话、信息、日历权限组除外。
  
  以位置信息和相机权限组举例说明：

  - 当应用只申请了权限ohos.permission.APPROXIMATELY_LOCATION（属于位置信息权限组）时，应用用户将收到一个请求位置信息的弹窗，包含单个权限的申请。
  - 当应用同时申请权限ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION（均属于位置信息权限组）时，应用用户将收到一个请求位置信息的弹窗，包含两个权限的申请。
  - 当应用同时申请权限ohos.permission.APPROXIMATELY_LOCATION（属于位置信息权限组）和ohos.permission.CAMERA（属于相机权限组）时，应用用户将收到请求位置信息、请求使用相机的两个弹窗。

- 当前系统支持的权限组如下所示，各子权限的含义请查阅[应用权限列表](permissions-for-all.md)。

## 位置信息

- ohos.permission.LOCATION_IN_BACKGROUND

- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

## 相机

- ohos.permission.CAMERA

## 麦克风

- ohos.permission.MICROPHONE

<!--Del-->
## 通讯录

- ohos.permission.READ_CONTACTS

- ohos.permission.WRITE_CONTACTS
<!--DelEnd-->

## 日历

- ohos.permission.READ_CALENDAR

- ohos.permission.WRITE_CALENDAR
<!--Del-->
- ohos.permission.READ_WHOLE_CALENDAR

- ohos.permission.WRITE_WHOLE_CALENDAR
<!--DelEnd-->

## 健身运动

- ohos.permission.ACTIVITY_MOTION

## 身体传感器

- ohos.permission.READ_HEALTH_DATA

## 图片和视频

- ohos.permission.WRITE_IMAGEVIDEO

- ohos.permission.READ_IMAGEVIDEO

- ohos.permission.MEDIA_LOCATION

## 音乐和音频

- ohos.permission.WRITE_AUDIO

- ohos.permission.READ_AUDIO

## 文件
<!--Del-->
- ohos.permission.READ_DOCUMENT

- ohos.permission.WRITE_DOCUMENT
<!--DelEnd-->
- ohos.permission.READ_MEDIA

- ohos.permission.WRITE_MEDIA

## 广告跟踪

- ohos.permission.APP_TRACKING_CONSENT

<!--Del-->
## 读取已安装应用列表

- ohos.permission.GET_INSTALLED_BUNDLE_LIST
<!--DelEnd-->

## 多设备协同

- ohos.permission.DISTRIBUTED_DATASYNC

## 蓝牙

- ohos.permission.ACCESS_BLUETOOTH

<!--Del-->
## 电话

- ohos.permission.ANSWER_CALL

- ohos.permission.MANAGE_VOICEMAIL

## 通话记录

- ohos.permission.READ_CALL_LOG

- ohos.permission.WRITE_CALL_LOG

## 信息

- ohos.permission.READ_CELL_MESSAGES

- ohos.permission.READ_MESSAGES

- ohos.permission.RECEIVE_MMS

- ohos.permission.RECEIVE_SMS

- ohos.permission.RECEIVE_WAP_MESSAGES

- ohos.permission.SEND_MESSAGES
<!--DelEnd-->

## 剪切板

- ohos.permission.READ_PASTEBOARD

<!--Del-->
## 文件夹

- ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY

- ohos.permission.READ_WRITE_DESKTOP_DIRECTORY

- ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY
<!--DelEnd-->

## 星闪

- ohos.permission.ACCESS_NEARLINK
