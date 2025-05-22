# Core File Kit（文件基础服务）<!--core-file-kit-->

- [Core File Kit简介](core-file-kit-intro.md)
- 应用文件<!--app-file-->
  - [应用文件概述](app-file-overview.md)
  - [应用沙箱目录](app-sandbox-directory.md)
  - 应用文件访问与管理<!--app-file-access-management-->
    - [应用文件访问(ArkTS)](app-file-access.md)
    - [应用文件访问(C/C++)](native-fileio-guidelines.md)
    - [应用及文件系统空间统计](app-fs-space-statistics.md)
  <!--Del-->
  - [向应用沙箱推送文件](send-file-to-app-sandbox.md)
  <!--DelEnd-->
  - [应用文件分享](share-app-file.md)
  - 应用数据备份恢复<!--app-file-backup-restore-->
    - [应用数据备份恢复概述](app-file-backup-overview.md)
    - [应用接入数据备份恢复](app-file-backup-extension.md)
    <!--Del-->
    - [应用触发数据备份/恢复（仅对系统应用开放）](app-file-backup.md)
    <!--DelEnd-->
- 用户文件<!--user-files-->
  - [用户文件概述](user-file-overview.md)
  - [用户文件uri介绍](user-file-uri-intro.md)
  - [FileUri开发指导(C/C++)](native-fileuri-guidelines.md)
  - [获取用户目录环境(C/C++)](native-environment-guidelines.md)
  - 选择与保存用户文件<!--select-save-user-file-->
    - [选择用户文件](select-user-file.md)
    - [保存用户文件](save-user-file.md)
    - [授权持久化](file-persistPermission.md)
    - [授权持久化(C/C++)](native-fileshare-guidelines.md)
  - [获取并使用公共目录](request-dir-permission.md)
  <!--Del-->
  - [开发用户文件管理器（仅对系统应用开放）](dev-user-file-manager.md)
  - [管理外置存储设备（仅对系统应用开放）](manage-external-storage.md)
  <!--DelEnd-->
- 分布式文件系统<!--distributed-fs-->
  - [分布式文件系统概述](distributed-fs-overview.md)
  - [设置分布式文件数据等级](set-security-label.md)
  - [跨设备文件访问](file-access-across-devices.md)
  - [跨设备文件拷贝](file-copy-across-devices.md)
