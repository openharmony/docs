# Application Data Backup and Restoration Overview

Application data, such as the configuration and service data, is generated when an application is used. To ensure that user data will not be lost due to operations, such as application updates and hopping, applications need to access data backup and restoration.

Before development, you need to understand the ExtensionAbility component. For details, see [ExtensionAbility Component Overview](../application-models/extensionability-overview.md).

BackupExtensionAbility is a class derived from ExtensionAbility in the stage model. It provides the capabilities of backing up and restoring application data. It is an extended component without the UI. It runs when a backup or restoration task starts and exits when the task is complete.

The implementation includes the following:

- [Backup and restoration of application access data](app-file-backup-extension.md): All applications can access data backup and restoration. After accessed, the application can modify the configuration file to customize the behavior of the backup and restoration framework, including whether to allow backup and restoration and specifying the data to be backed up.

  Applications can perform backup and restoration configurations, but not trigger data backup and restoration.

- [Backup and restoration of application-triggered data](app-file-backup.md): Only system applications can trigger data backup and restoration. After data backup or restoration is triggered, the backup and restoration framework checks whether each application has accessed data backup and restoration. If yes, the backup and restore framework backs up or restores data based on the application's configuration file.
