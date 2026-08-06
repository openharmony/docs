# Application Data Backup and Restore Overview

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--Designer: @chenxi0605-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=23fd3050bf417376fb6020b82cd43307338e4432 translatedAt=2026-08-01T07:23:13.887Z pushedAt=2026-08-01T08:18:50.372Z -->

Application data, such as the configuration and service data, is generated when an application is used. To prevent user data from being lost due to operations such as app updates and migration, the app needs to integrate data backup and restoration.

Before development, you need to understand the [ExtensionAbility](../application-models/extensionability-overview.md) component.

Derived from ExtensionAbility in the stage model, BackupExtensionAbility provides the capabilities of backing up and restoring application data. It is an extended component without the UI. It runs when a backup or restore task starts and exits when the task is complete.

Application data backup and restore can be implemented in either of the following ways:

- [Accessing backup and restore](app-file-backup-extension.md): All applications can access the data backup and restore framework. The application that has accessed the framework can customize the backup and restore behavior, including whether to enable backup and restore and specifying the data to be backed up, in a profile.

An app itself cannot trigger data backup and restore; it can only configure backup and restore. <!--RP2--> <!--RP2End-->

<!--RP1-->

- [Triggering backup and restore (for system applications only)](app-file-backup-sys.md): Only system applications can trigger data backup and restore. After data backup or restore is triggered, the backup and restore framework backs up or restores data based on the profiles of the applications that have accessed the framework.<!--RP1End-->