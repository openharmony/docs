# 程序访问控制子系统ChangeLog

## cl.accessToken.1 "媒体和文件"权限组拆分
原"媒体和文件"权限组内包含以下权限：
- ohos.permission.MEDIA_LOCATION
- ohos.permission.READ_MEDIA
- ohos.permission.WRITE_MEDIA

对这三个权限所属的权限组进行调整：
- ohos.permission.MEDIA_LOCATION 划分到 "图片和视频" 权限组
- ohos.permission.READ_MEDIA 和 ohos.permission.WRITE_MEDIA 划分到 "文件" 权限组。


**变更影响**

权限弹窗是以权限组为单位进行展示的。

- 在变更前，如果开发者同时申请以上三个权限，应用仅会弹一次申请"媒体和文件"权限的弹窗；
- 在变更后，如果开发者同时申请以上三个权限，应用会分别弹一次申请"图片和视频"权限的弹窗和申请"文件"权限的弹窗；

**关键的接口/组件变更**

修改前的权限组归属：

| 权限   | 所属权限组                         |
| -------- | ---------------------------- |
| ohos.permission.MEDIA_LOCATION | 媒体和文件 |
| ohos.permission.READ_MEDIA | 媒体和文件 |
| ohos.permission.WRITE_MEDIA | 媒体和文件 |

修改后的权限组归属：

| 权限   | 所属权限组                         |
| -------- | ---------------------------- |
| ohos.permission.MEDIA_LOCATION | 图片和视频 |
| ohos.permission.READ_MEDIA | 文件 |
| ohos.permission.WRITE_MEDIA | 文件 |


**适配指导**

应用开发者无需适配。

## cl.accessToken.2 “电话”/“信息”/“通话记录”权限组的权限申请方式调整
 “电话”/“信息”/“通话记录”权限组的共包含以下权限：
- ohos.permission.ANSWER_CALL
- ohos.permission.MANAGE_VOICEMAIL
- ohos.permission.READ_CELL_MESSAGES
- ohos.permission.READ_MESSAGES
- ohos.permission.RECEIVE_MMS
- ohos.permission.RECEIVE_SMS
- ohos.permission.RECEIVE_WAP_MESSAGES
- ohos.permission.SEND_MESSAGES
- ohos.permission.READ_CALL_LOG
- ohos.permission.WRITE_CALL_LOG
- ohos.permission.MEDIA_LOCATION

当前调整这些权限的申请方式：这些权限仅能通过预授权方式进行授权。


**变更影响**

当前申请这些权限的系统应用无法通过权限弹窗进行权限请求，仅能通过预授权方式获取权限。

**关键的接口/组件变更**

不涉及。

**适配指导**

申请上述权限时，需要调整权限请求方式，申请权限预授权。
