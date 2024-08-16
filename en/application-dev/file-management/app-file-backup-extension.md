# Accessing Backup and Restore

You can use BackupExtensionAbility to enable an application to access the backup and restore framework.

BackupExtensionAbility is a class derived from [ExtensionAbility](../application-models/extensionability-overview.md) in the [stage model](../application-models/stage-model-development-overview.md). The application that has accessed the backup and restore framework can customize the backup and restore behavior, including whether to enable backup and restore and specifying the data to be backed up, in a profile. 

## Available APIs

| Module       | Class                  | Interface                                         | Description                                                         |
| ----------- | ---------------------- | --------------------------------------------- | ----------------------------------------------------------------- |
| application | BundleVersion          | code: number                                  | Application version number.                                                     |
| application | BundleVersion          | name: string                                  | Application version name.                                                   |
| application | BackupExtensionAbility | onBackup(): void                              | Callback provided by BackupExtensionAbility to be invoked before the data backup is triggered.|
| application | BackupExtensionAbility | onRestore(bundleVersion: BundleVersion): void | Callback provided by BackupExtensionAbility to be invoked after the data restore is triggered.|
| application | BackupExtensionAbility | context: ExtensionContext                     | BackupExtensionAbility context, which inherits from **Context**.              |

For details about how to use the APIs, see [BackupExtensionAbility](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md#backupextensionability).

## Constraints

- The path of the file or directory to be backed up or restored cannot exceed 4095 bytes. Otherwise, undefined behavior may occur.
- If a directory needs to be backed up, the application process must have the permission to read the directory and all its subdirectories (**r** in DAC). Otherwise, the backup fails.
- If a file needs to be backed up, the application process must have the permission to retrieve all the ancestor directories of the file (**x** in DAC). Otherwise, the backup fails.

## How to Develop

1. Add **extensionAbilities** to the application's **module.json5** file.

   In **module.json5**, add the **extensionAbilities** field, set **type** to **backup**, and add a record with **name** set to **ohos.extension.backup** under **["metadata"](../reference/apis-ability-kit/js-apis-bundleManager-metadata.md)**.

   Example:

   ```json
   {
       "extensionAbilities": [
           {
               "description": "$string:ServiceExtAbility",
               "icon": "$media:icon",
               "name": "BackupExtensionAbility",
               "type": "backup",
               "exported": false,
               "metadata": [
                   {
                       "name": "ohos.extension.backup",
                       "resource": "$profile:backup_config"
                   }
               ],
               // In the BackupExtension.ets file, inherit from BackupExtensionAbility and override the onBackup and onRestore methods.
               // If there is no special requirement, you do not have to override onBackup and onRestore. In this case, the backup and restore service backs up or restores data based on the unified backup and restore rules.
               "srcEntry": "./ets/BackupExtension/BackupExtension.ets", 
           }      
       ]
   }
   ```

2. Add a metadata profile.

   The metadata profile defines the files to be transferred during the backup and restore process. The profile is located in the **resources/profile** directory of the project, and the file name must be the same as the value of **metadata.resource** in the **module.json5** file.

   Metadata profile example:

   ```json
   {
       "allowToBackupRestore": true,
       "includes": [
           "/data/storage/el2/base/files/users/"
       ],
       "excludes": [
           "/data/storage/el2/base/files/users/hidden/"
       ],
       "fullBackupOnly": false,
       "restoreDeps": "",
   }
   ```

3. Customize **BackupExtensionAbility** that is inherited by the class in the **BackupExtension.ets** file and override **onBackup** or **onRestore** to back up preprocessed application data or process the data to be restored.

   Empty implementation can be used if there is no special requirement. In this case, the backup and restore service backs up or restores data based on the unified backup and restore rules.

   The following example shows an empty implementation of the **BackupExtension.ets** file.

    ```ts
    import BackupExtensionAbility, {BundleVersion} from '@ohos.application.BackupExtensionAbility';
    import {hilog} from '@kit.PerformanceAnalysisKit';
    
    const TAG = `FileBackupExtensionAbility`;
    export default class BackupExtension extends  BackupExtensionAbility {
      async onBackup ()   {
        hilog.info(0x0000, TAG, `onBackup ok`);
      }

      async onRestore (bundleVersion : BundleVersion) {
        hilog.info(0x0000, TAG, `onRestore ok ${JSON.stringify(bundleVersion)}`);
        hilog.info(0x0000, TAG, `onRestore end`);
      }
    }
    ```

### Description of the Metadata Profile

| Field            | Type  | Mandatory| Description                                                                                                                                                                                           |
| -------------------- | ---------- | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| allowToBackupRestore | Boolean    | Yes  | Whether to enable backup and restore. The default value is **false**.                                                                                                                                                                |
| includes             | String array| No  | Files and directories to be backed up in the application sandbox directory.<br>The pattern string that does not start with a slash (/) indicates a relative path.<br>If **includes** is not specified, the backup and restore framework uses the **includes** default (as listed in the code snippet below).|
| excludes             | String array| No  | Items in **includes** that do not need to be backed up. The value is in the same format as **includes**.<br>If **excludes** is not configured, the backup and restore framework uses an empty array by default.                                             |
| fullBackupOnly       | Boolean    | No  | Whether to use the default restore directory of the application. The default value is **false**. If this parameter is set to **true**, a temporary directory obtained by using [backupDir](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md) is used to cache the data. This directory can be used as a temporary directory for data backup and restore only.<br>If it is **false** or not specified, the restored data is decompressed in **/**.  |
| restoreDeps          | String    | No  | Dependencies for the application to restore. Use commas (,) to separate multiple dependencies. The default value is "".                                                                                                          |

> **NOTE**
> 
> When setting **fullBackupOnly**, note the following:
> - If **fullBackupOnly** is set to **false**, the restored files will overwrite the file with the same name in the directory.
> - If **fullBackupOnly** is set to **true**, the restored data is decompressed in the **/data/storage/el2/backup/restore/** directory. You can access the data via **OnRestore** to restore it.
>
> You can determine the data restore mode to use based on service requirements. If **fullBackupOnly** is set to **true**, you need to implement the data restore logic in **OnRestore**.
>

**includes** default:

```json
{
    "includes": [
    "data/storage/el1/database/",
    "data/storage/el1/base/files/",
    "data/storage/el1/base/preferences/",
    "data/storage/el1/base/haps/<module-name>/files/",
    "data/storage/el1/base/haps/<module-name>/preferences/",
    "data/storage/el2/database/",
    "data/storage/el2/base/files/",
    "data/storage/el2/base/preferences/",
    "data/storage/el2/base/haps/<module-name>/files/",
    "data/storage/el2/base/haps/<module-name>/preferences/",
    "data/storage/el2/distributedfiles/"
    ]
}
```
<!--no_check-->
