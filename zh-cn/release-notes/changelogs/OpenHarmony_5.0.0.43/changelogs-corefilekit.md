# 文件系统CoreFileKitChangelog

## cl.CoreFileKit.1 文件授权接口行为变更

**访问级别**

公开接口

**变更原因**

基于对用户个人文件资产保护，文件必须先授权后使用。文件授权接口实行强管控，提供目录授权和文件持久化授权。

**变更影响**

该变更为不兼容变更。

变更前：
应用退出后再次打开访问获取到URI的文件时获得该文件的持久化未做强制校验；3D目录（下载/文档/桌面)目录预授权未做强制校验。

变更后：
应用退出后再次打开访问获取到URI的文件时需先获得该文件的持久化，即调用文件持久化授权；3D目录授权应用需先申请才可访问对应目录下的文件。

**起始 API Level**

API Level 11

**变更发生版本**

从OpenHarmony SDK 5.0.0.43开始。

**变更的接口/组件**

接口未变更，行为变更；变更后对文件/目录授权实行强管控。授权接口见下表：

|  权限 | 变更前所属权限组  | 变更后所属权限组  | 替代权限  |
| ------------ | ------------ | ------------ | ------------ |
|ohos.fileshare.persistPermission|文件|文件|不涉及|
|ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY|文件|文件|不涉及|
|ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY|文件|文件|不涉及|
|ohos.permission.READ_WRITE_DESKTOP_DIRECTORY|文件|文件|不涉及|

**适配指导**

行为变更：
默认行为变更，需应用适配，如应用未按申请应用无法访问文件。

参考开发指南的指导进行文件[授权持久化](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/file-persistpermission-V5)，或者参考[获取并使用公共目录](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/request-dir-permission-V5)使用公共资源。