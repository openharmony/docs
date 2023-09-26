# Application Data Backup and Restoration Overview

Application data, such as the configuration and service data, is generated when an application is used. To prevent user data against loss due to operations such as application updates and hopping, the application data needs to be backed up and restored.

Before development, you need to understand the [ExtensionAbility](../application-models/extensionability-overview.md) component.

Derived from ExtensionAbility in the stage model, BackupExtensionAbility provides the capabilities of backing up and restoring application data. It is an extended component without the UI. It runs when a backup or restoration task starts and exits when the task is complete.

The implementation includes the following:

- [Backup and restoration accessed by applications](app-file-backup-extension.md): All applications can access the data backup and restoration framework. You can customize the backup and restoration framework behavior for the application, including whether to allow backup and restoration and specifying the data to be backed up, by modifying the application configuration file.

  The application itself cannot trigger data backup and restoration.

- [Backup and restoration triggered by system applications](app-file-backup.md): Only system applications can trigger data backup and restoration. After data backup or restoration is triggered, the backup and restoration framework locates the applications that have accessed the data backup and restoration framework and backs up or restores data based on the application's configuration file.
