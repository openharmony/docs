# Accessing Backup and Restore

You can use BackupExtensionAbility to enable an application to access the backup and restore framework.

BackupExtensionAbility is a class derived from [ExtensionAbility](../application-models/extensionability-overview.md) in the [stage model](../application-models/stage-model-development-overview.md). The application that has accessed the backup and restore framework can customize the backup and restore behavior, including whether to enable backup and restore and specifying the data to be backed up, in a profile. 

## Available APIs

| Module            | Class  | Interface| Description    |
| -------------------- | ---------- | ---- | ----------------------- |
| application | BundleVersion | code: number   | Application version number. |
| application | BundleVersion | name: string   | Application version name. |
| application | BackupExtensionAbility | onBackup(): void   | Callback provided by BackupExtensionAbility and implemented by the developer for data backup. |
| application | BackupExtensionAbility | onRestore(bundleVersion: BundleVersion): void   | Callback provided by BackupExtensionAbility and implemented by the developer for data restore. |
| application | BackupExtensionAbility | context: ExtensionContext   | BackupExtensionAbility context, which inherits from **Context**. |

For details about how to use the APIs of BackupExtensionAbility, see [BackupExtensionAbility](../reference/apis/js-apis-application-backupExtensionAbility.md#backupextensionability).

## Constraints

- The path of the file or directory to be backed up or restored cannot exceed 4095 bytes. Otherwise, undefined behavior may occur.
- If a directory needs to be backed up, the application process must have the permission to read the directory and all its subdirectories (**r** in DAC). Otherwise, the backup fails.
- If a file needs to be backed up, the application process must have the permission to retrieve all the ancestor directories of the file (**x** in DAC). Otherwise, the backup fails.

## How to Develop

1. Add **extensionAbilities** to the application's **module.json5** file.

   In **module.json5**, add the **extensionAbilities** field, set **type** to **backup**, and add a record with **name** set to **ohos.extension.backup** under **[metadata](../reference/apis/js-apis-bundleManager-metadata.md)**.

   Example:

   ```json
   {
       "extensionAbilities": [
           {
               "description": "$string:ServiceExtAbility",
               "icon": "$media:icon",
               "name": "BackupExtensionAbility",
               "type": "backup",
               "visible": true,
               "metadata": [
                   {
                       "name": "ohos.extension.backup",
                       "resource": "$profile:backup_config"
                   }
               ],
               // In the BackupExtension.ts file, inherit from BackupExtensionAbility and override the onBackup and onRestore methods.
               // If there is no special requirement, you do not have to override onBackup and onRestore. In this case, the backup and restore service backs up and restores data based on the unified backup and restore rules.
               "srcEntrance": "./ets/BackupExtension/BackupExtension.ts", 
           }      
       ]
   }
   ```

2. Add a metadata profile.

   The metadata profile defines the files to be transferred during the backup and restore process. The profile is located in the **resources/profile** directory of the project, and the file name must be the same as the value of **metadata.resource** in the **module.json5** file.

   Example:

   ```json
   {
       "allowToBackupRestore": true,
       "includes": [
           "/data/storage/el2/base/files/users/*/*.json"
       ],
       "excludes": [
           "/data/storage/el2/base/files/users/*/hidden.json"
       ],
       "fullBackupOnly": true,
       "restoreDeps": ""
   }
   ```

### Description of the Metadata Profile

| Field            | Type  | Mandatory| Description    |
| -------------------- | ---------- | ---- | ----------------------- |
| allowToBackupRestore | Boolean    | Yes  | Whether to enable backup and restore. The default value is **false**. |
| includes             | String array| No  | Files and directories to be backed up in the application sandbox directory.<br>The value is an array of pattern strings, which can contain shell-style wildcards such as *, ?, and [.<br>The pattern string that does not start with a slash (/) indicates a relative path.<br>If **includes** is not specified, the backup and restore framework uses the **includes** default (as listed in the code snippet below).|
| excludes             | String array| No  | Items in **includes** that do not need to be backed up. The value is in the same format as **includes**.<br>If **excludes** is not configured, the backup and restore framework uses an empty array by default. |
| fullBackupOnly       | Boolean    | No  | Whether to use the default restore directory of the application. If the value is **true**, data is decompressed under **/data/storage/el2/backup/restore/** during the data restore process.<br>If the value is **false** or is not specified, data is decompressed under **/**. |
| restoreDeps          | String    | No  | Names of the applications, on which the application restore depends. Use commas (,) to separate multiple applications.|

**includes** default:

```json
{
    "includes": [
    "data/storage/el1/database/",
    "data/storage/el1/base/files/",
    "data/storage/el1/base/preferences/",
    "data/storage/el1/base/haps/*/database/",
    "data/storage/el1/base/haps/*/files/",
    "data/storage/el1/base/haps/*/preferences/",
    "data/storage/el2/database/",
    "data/storage/el2/base/files/",
    "data/storage/el2/base/preferences/",
    "data/storage/el2/base/haps/*/database/",
    "data/storage/el2/base/haps/*/files/",
    "data/storage/el2/base/haps/*/preferences/",
    "data/storage/el2/distributedfiles/",
    ]
}
```