# Core File Kit<!--core-file-api-->

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25-->
<!--Designer: @bubble_mao; @gzhuangzhuang; @gsl_1234-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @jinqiuheng-->

- ArkTS APIs<!--core-file-arkts-->
  - [@ohos.application.BackupExtensionAbility (Backup and Restore Extension Capability)](js-apis-application-backupExtensionAbility.md)
  - [@ohos.file.cloudSync (Device-Cloud Sync)](js-apis-file-cloudsync.md)
  - [@ohos.file.cloudSyncManager (Device-Cloud Sync Management)](js-apis-file-cloudsyncmanager.md)
  - [@ohos.file.environment (Directory Environment Capability)](js-apis-file-environment.md)
  - [@ohos.file.fileuri (File URI)](js-apis-file-fileuri.md)
  - [@ohos.file.fs (File Management)](js-apis-file-fs.md)
  - [@ohos.file.hash (File Hash Processing)](js-apis-file-hash.md)
  - [@ohos.file.picker (Picker)](js-apis-file-picker.md)
  - [@ohos.file.securityLabel (Data Label)](js-apis-file-securityLabel.md)
  - [@ohos.file.statvfs (File System Space Statistics)](js-apis-file-statvfs.md)
  - [@ohos.file.storageStatistics (Application Storage Statistics)](js-apis-file-storage-statistics.md)
  - [@ohos.fileshare (File Sharing)](js-apis-fileShare.md)
  - [@ohos.file.BackupExtensionContext (Backup and Restore Extension Capability)](js-apis-file-backupextensioncontext.md)
  <!--Del-->
  - [@ohos.application.BackupExtensionAbility (Backup and Restore Extension Capability) (System API)](js-apis-application-backupExtensionAbility-sys.md)
  - [@ohos.file.backup (Backup and Restore) (System API)](js-apis-file-backup-sys.md)
  - [@ohos.file.cloudDiskManager (Cloud Disk Management) (System API)](js-apis-file-clouddiskmanager-sys.md)
  - [@ohos.file.cloudSync (Device-Cloud Sync) (System API)](js-apis-file-cloudsync-sys.md)
  - [@ohos.file.cloudSyncManager (Device-Cloud Sync Management) (System API)](js-apis-file-cloudsyncmanager-sys.md)
  - [@ohos.file.environment (Directory Environment Capability) (System API)](js-apis-file-environment-sys.md)
  - [@ohos.file.keyManager (User Key Management) (System API)](js-apis-file-keymanager-sys.md)
  - [@ohos.file.picker (Picker) (System API)](js-apis-file-picker-sys.md)
  - [@ohos.file.storageStatistics (Application Storage Statistics) (System API)](js-apis-file-storage-statistics-sys.md)
  - [@ohos.file.volumeManager (Volume Management) (System API)](js-apis-file-volumemanager-sys.md)
  - [@ohos.filemanagement.userFileManager (User Data Management) (System API)](js-apis-userFileManager-sys.md)
  - [@ohos.fileshare (File Sharing) (System API)](js-apis-fileShare-sys.md)
  <!--DelEnd-->
  - APIs No Longer Maintained<!--core-file-arkts-dep-->
    - [@ohos.document (File Operation)](js-apis-document.md)
    - [@ohos.fileio (File Management)](js-apis-fileio.md)
    - [@ohos.statfs (statfs)](js-apis-statfs.md)
    - [@system.file (File Storage)](js-apis-system-file.md)
    <!--Del-->
    - [@ohos.file.fileAccess (User File Access and Management) (System API)](js-apis-fileAccess-sys.md)
    - [@ohos.file.fileExtensionInfo (User File Access and Management Attribute Information) (System API)](js-apis-fileExtensionInfo-sys.md)
    - [@ohos.file.recent (Latest Access List) (System API)](js-apis-file-recent-sys.md)
    - [@ohos.file.trash (Trash) (System API)](js-apis-file-trash-sys.md)
    <!--DelEnd-->
- C APIs<!--core-file-c-->
  - Modules<!--core-file-module-->
    - [Environment](capi-environment.md)
    - [FileIO](capi-fileio.md)
    - [fileShare](capi-fileshare.md)
    - [fileUri](capi-fileuri.md)
    - [CloudDisk](capi-clouddisk.md)
    - [Archive](capi-archive.md)
  - Header Files<!--core-file-headerfile-->
    - [oh_environment.h](capi-oh-environment-h.md)
    - [error_code.h](capi-error-code-h.md)
    - [oh_fileio.h](capi-oh-fileio-h.md)
    - [oh_file_share.h](capi-oh-file-share-h.md)
    - [oh_file_uri.h](capi-oh-file-uri-h.md)
    - [oh_cloud_disk_manager.h](capi-oh-cloud-disk-manager-h.md)
    - [cloud_disk_error_code.h](capi-cloud-disk-error-code-h.md)
    - [oh_archive.h](capi-oh-archive-h.md)
    - [oh_archive_errcode.h](capi-oh-archive-errcode-h.md)
  - Structs<!--core-file-struct-->
    - [FileShare_PolicyErrorResult](capi-fileshare-fileshare-policyerrorresult.md)
    - [FileShare_PolicyInfo](capi-fileshare-fileshare-policyinfo.md)
    - [CloudDisk_ChangeData](capi-clouddisk-clouddisk-changedata.md)
    - [CloudDisk_ChangesResult](capi-clouddisk-clouddisk-changesresult.md)
    - [CloudDisk_DisplayNameInfo](capi-clouddisk-clouddisk-displaynameinfo.md)
    - [CloudDisk_FailedList](capi-clouddisk-clouddisk-failedlist.md)
    - [CloudDisk_FileSyncState](capi-clouddisk-clouddisk-filesyncstate.md)
    - [CloudDisk_PathInfo](capi-clouddisk-clouddisk-pathinfo.md)
    - [CloudDisk_ResultList](capi-clouddisk-clouddisk-resultlist.md)
    - [CloudDisk_SyncFolder](capi-clouddisk-clouddisk-syncfolder.md)
    - [OH_Archive_StreamInfo](capi-archive-oh-archive-streaminfo.md)
    - [OH_Archive_Stream_Config](capi-archive-oh-archive-stream-config.md)
    - [ArchiveWriteCtx](capi-archive-archivewritectx.md)
    - [ArchiveReadCtx](capi-archive-archivereadctx.md)
    - [ArchiveStreamWriteCtx](capi-archive-archivestreamwritectx.md)
    - [ArchiveStreamReadCtx](capi-archive-archivestreamreadctx.md)
- Error Codes<!--core-file-arkts-errcode-->
  - [File Management Error Codes](errorcode-filemanagement.md)
  <!--Del-->
  - [Cloud Disk Management Error Codes](errorcode-clouddiskmanager-sys.md)
  <!--DelEnd-->
  
