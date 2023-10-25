# Backup and Restoration Accessed by Applications

You can use BackupExtensionAbility to enable an application to access the backup and restoration framework.

BackupExtensionAbility is a class derived from the [ExtensionAbility](../application-models/extensionability-overview.md) based on the [stage model](../application-models/stage-model-development-overview.md). You can modify the configuration file to customize the backup and restoration framework behavior, including whether to allow backup and restoration and specifying the files to be backed up.

## Constraints

- The paths of all files and directories to be backed up cannot exceed 4095 bytes. Otherwise, undefined behavior may occur.
- If a directory needs to be backed up, the application process must have the permission to read the directory and all its subdirectories (**r** in DAC). Otherwise, the backup fails.
- If a file needs to be backed up, the application process must have the permission to retrieve the grandparent directory of the file (**x** in DAC). Otherwise, the backup fails.

## How to Develop

1. Add **extensionAbilities** to the application's **module.json5** file.

   Add the **extensionAbilities** field, set **type** to **backup**, and add a record with **name** of **ohos.extension.backup** to **[metadata](../reference/apis/js-apis-bundleManager-metadata.md)**.

   BackupExtensionAbility configuration example:

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
               "srcEntrance": "",
           }      
       ]
   }
   ```

2. Add a metadata resource profile.

   The metadata resource profile defines the files to be transferred during the backup and restoration process. The file is located in the **resource/profile** directory of the project, and the file name must be the same as **metadata.resource** in the **module.json5** file.

   Metadata resource profile example:

   ```json
   {
       "allowToBackupRestore": true,
       "includes": [
           "/data/storage/el2/base/files/users/*/*.json"
       ],
       "excludes": [
           "/data/storage/el2/base/files/users/*/hidden.json"
       ],
   }
   ```

### Description of the Metadata Resource Configuration File

| Name            | Type  | Mandatory| Description    |
| -------------------- | ---------- | ---- | ----------------------- |
| allowToBackupRestore | Boolean    | Yes  | Whether to allow backup and restoration. The default value is **false**. |
| includes             | String array| No  | Files and directories to be backed up in the application sandbox.<br>Each item in the array is a pattern string, which can contain shell-style wildcards such as `*`, `?`, `[`.<br>The pattern string that does not start with a slash (/) indicates a relative path.<br>If **includes** is configured, the backup and restoration framework uses the pattern strings configured. Otherwise, the backup and restoration framework uses the **includes** default value (see the following code segment). |
| excludes             | String array| No  | Items in **includes** that do not need to be backed up. The value is in the same format as **includes**.<br>If **excludes** is configured, the backup and restoration framework uses the pattern strings configured. Otherwise, the backup and restoration framework uses an empty array as the default value. |

**includes** default value:

```json
{
    "includes": [
    "data/storage/el2/database/",
    "data/storage/el2/base/files/",
    "data/storage/el2/base/preferences/",
    "data/storage/el2/base/haps/*/database/",
    "data/storage/el2/base/haps/*/files/",
    "data/storage/el2/base/haps/*/preferences/",
    ]
}
```



