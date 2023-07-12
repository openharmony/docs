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
