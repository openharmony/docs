# Application Data Backup and Restore Overview

Application data, such as the configuration and service data, is generated when an application is used. To prevent user data against loss due to operations such as application updates and hopping, the application data needs to be backed up and restored.

Before development, you need to understand the [ExtensionAbility](../application-models/extensionability-overview.md) component.

Derived from ExtensionAbility in the stage model, BackupExtensionAbility provides the capabilities of backing up and restoring application data. It is an extended component without the UI. It runs when a backup or restore task starts and exits when the task is complete.

Application data backup and restore can be implemented in either of the following ways:

- [Accessing backup and restore](app-file-backup-extension.md): All applications can access the data backup and restore framework. The application that has accessed the framework can customize the backup and restore behavior, including whether to enable backup and restore and specifying the data to be backed up, in a profile.

  The application itself cannot trigger data backup and restore.
<!--RP1-->
- [Triggering backup and restore (for system applications only)](app-file-backup.md): Only system applications can trigger data backup and restore. After data backup or restore is triggered, the backup and restore framework backs up or restores data based on the profiles of the applications that have accessed the framework.<!--RP1End-->
