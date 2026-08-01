# Core File Kit<!--core-file-kit-->

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wangke25-->
<!--Designer: @bubble_mao; @gzhuangzhuang; @gsl_1234-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=4f18c57bcbc4988278ed782932d83b5e0aeec8ed translatedAt=2026-08-01T07:27:07.074Z pushedAt=2026-08-01T10:33:17.290Z -->

- [About This Kit](core-file-kit-intro.md)

- Application Files<!--app-file-->

  - [Application File Overview](app-file-overview.md)

  - [Application Sandbox](app-sandbox-directory.md)

  - Application File Access and Management<!--app-file-access-management-->

    - [Accessing Application Files (ArkTS)](app-file-access.md)

    - [Accessing Application Files (C/C++)](native-fileio-guidelines.md)

    - [Obtaining Application and File System Space Statistics](app-fs-space-statistics.md)

  <!--Del-->

  - [Pushing Files to an Application Sandbox Directory (for System Applications Only)](send-file-to-app-sandbox-sys.md)

  <!--DelEnd-->

  - [Sharing an Application File](share-app-file.md)

  - [Configuring the Application Shared Directory](share-app-file-configuration.md)

  - Application Data Backup and Restore<!--app-file-backup-restore-->

    - [Application Data Backup and Restore Overview](app-file-backup-overview.md)

    - [Accessing Backup and Restore](app-file-backup-extension.md)<!--RP2--><!--RP2End-->

    <!--Del-->

    - [Triggering Backup and Restore (for System Applications Only)](app-file-backup-sys.md)

    <!--DelEnd-->

- User Files<!--user-files-->

  - [User File Overview](user-file-overview.md)

  - [User File URI](user-file-uri-intro.md)

  - [FileUri Development (C/C++)](native-fileuri-guidelines.md)

  - [Obtaining the User Directory Environment (C/C++)](native-environment-guidelines.md)

  - Selecting and Saving User Files<!--select-save-user-file-->

    - [Selecting User Files](select-user-file.md)

    - [Saving User Files](save-user-file.md)

    - [Persisting Temporary Permissions (ArkTS)](file-persistPermission.md)

    - [Persisting Temporary Permissions (C/C++)](native-fileshare-guidelines.md)

  - [Obtaining and Accessing a User Directory](request-dir-permission.md)

  <!--Del-->

  - [Developing a File Manager Application (for System Applications Only)](dev-user-file-manager-sys.md)

  - [Managing External Storage Devices (for System Applications Only)](manage-external-storage-sys.md)

  <!--DelEnd-->

- Distributed File System<!--distributed-fs-->

  - [Distributed File System Overview](distributed-fs-overview.md)

  - [Setting the Security Level of a Distributed File](set-security-label.md)

  - [Sharing and Accessing Files Across Devices](file-access-across-devices.md)

  - [Copying Files Across Devices](file-copy-across-devices.md)<!--RP1--><!--RP1End-->

- File Compression and Decompression<!--compression-->

  - [Compression and Decompression Overview](archive-overview.md)

  - [Archive File Compression and Decompression (C/C++)](archive-file-compression-guidelines.md)

  - [Streaming Compression and Decompression (C/C++)](archive-stream-compression-guidelines.md)

  - [Buffer Compression and Decompression (C/C++)](archive-buffer-compression-guidelines.md)

  <!--RP3--><!--RP3End-->