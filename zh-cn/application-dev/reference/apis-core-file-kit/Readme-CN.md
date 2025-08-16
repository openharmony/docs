# Core File Kit（文件基础服务）<!--core-file-api-->

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25-->
<!--Designer: @bubble_mao; @zhuangzhuang; @gsl_1234-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @foryourself-->

- ArkTS API<!--core-file-arkts-->
  - [@ohos.application.BackupExtensionAbility (备份恢复扩展能力)](js-apis-application-backupExtensionAbility.md)
  - [@ohos.file.cloudSync (端云同步能力)](js-apis-file-cloudsync.md)
  - [@ohos.file.environment (目录环境能力)](js-apis-file-environment.md)
  - [@ohos.file.fileuri (文件URI)](js-apis-file-fileuri.md)
  - [@ohos.file.fs (文件管理)](js-apis-file-fs.md)
  - [@ohos.file.hash (文件哈希处理)](js-apis-file-hash.md)
  - [@ohos.file.picker (选择器)](js-apis-file-picker.md)
  - [@ohos.file.securityLabel (数据标签)](js-apis-file-securityLabel.md)
  - [@ohos.file.statvfs (文件系统空间统计)](js-apis-file-statvfs.md)
  - [@ohos.file.storageStatistics (应用空间统计)](js-apis-file-storage-statistics.md)
  - [@ohos.fileshare (文件分享)](js-apis-fileShare.md)
  - [@ohos.file.BackupExtensionContext (备份恢复扩展能力)](js-apis-file-backupextensioncontext.md)
  <!--Del-->
  - [@ohos.application.BackupExtensionAbility (备份恢复扩展能力)(系统接口)](js-apis-application-backupExtensionAbility-sys.md)
  - [@ohos.file.backup (备份恢复)(系统接口)](js-apis-file-backup-sys.md)
  - [@ohos.file.cloudSync (端云同步能力)(系统接口)](js-apis-file-cloudsync-sys.md)
  - [@ohos.file.cloudSyncManager (端云同步管理)(系统接口)](js-apis-file-cloudsyncmanager-sys.md)
  - [@ohos.file.environment (目录环境能力)(系统接口)](js-apis-file-environment-sys.md)
  - [@ohos.file.fileAccess (公共文件访问与管理)(系统接口)](js-apis-fileAccess-sys.md)
  - [@ohos.file.fileExtensionInfo (公共文件访问与管理属性信息)(系统接口)](js-apis-fileExtensionInfo-sys.md)
  - [@ohos.file.keyManager (用户秘钥管理)(系统接口)](js-apis-file-keymanager-sys.md)
  - [@ohos.file.recent(最近访问列表)(系统接口)](js-apis-file-recent-sys.md)
  - [@ohos.file.picker (选择器)(系统接口)](js-apis-file-picker-sys.md)
  - [@ohos.file.storageStatistics (应用空间统计)(系统接口)](js-apis-file-storage-statistics-sys.md)
  - [@ohos.file.trash (回收站)(系统接口)](js-apis-file-trash-sys.md)
  - [@ohos.file.volumeManager (卷管理)(系统接口)](js-apis-file-volumemanager-sys.md)
  - [@ohos.filemanagement.userFileManager (用户数据管理)(系统接口)](js-apis-userFileManager-sys.md)
  - [@ohos.fileshare (文件分享)(系统接口)](js-apis-fileShare-sys.md)
  <!--DelEnd-->
  - 已停止维护的接口<!--core-file-arkts-dep-->
    - [@ohos.document (文件交互)](js-apis-document.md)
    - [@ohos.fileio (文件管理)](js-apis-fileio.md)
    - [@ohos.statfs (statfs)](js-apis-statfs.md)
    - [@system.file (文件存储)](js-apis-system-file.md)
- C API<!--core-file-c-->
  - 模块<!--core-file-module-->
    - [Environment](capi-environment.md)
    - [FileIO](capi-fileio.md)
    - [fileShare](capi-fileshare.md)
    - [fileUri](capi-fileuri.md)
  - 头文件<!--core-file-headerfile-->
    - [oh_environment.h](capi-oh-environment-h.md)
    - [error_code.h](capi-error-code-h.md)
    - [oh_fileio.h](capi-oh-fileio-h.md)
    - [oh_file_share.h](capi-oh-file-share-h.md)
    - [oh_file_uri.h](capi-oh-file-uri-h.md)
  - 结构体<!--core-file-struct-->
    - [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md)
    - [FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md)
- 错误码<!--core-file-arkts-errcode-->
  - [文件管理错误码](errorcode-filemanagement.md)
  