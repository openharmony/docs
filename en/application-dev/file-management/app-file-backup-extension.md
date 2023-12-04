# Accessing Backup and Restore

You can use BackupExtensionAbility to enable an application to access the backup and restore framework.

BackupExtensionAbility is a class derived from [ExtensionAbility](../application-models/extensionability-overview.md) in the [stage model](../application-models/stage-model-development-overview.md). The application that has accessed the backup and restore framework can customize the backup and restore behavior, including whether to enable backup and restore and specifying the data to be backed up, in a profile.

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
               "srcEntrance": "",
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
   }
   ```

### Description of the Metadata Profile

| Field            | Type  | Mandatory| Description    |
| -------------------- | ---------- | ---- | ----------------------- |
| allowToBackupRestore | Boolean    | Yes  | Whether to enable backup and restore. The default value is **false**. |
| includes             | String array| No  | Files and directories to be backed up in the application sandbox directory.<br>The value is an array of pattern strings, which can contain shell-style wildcards such as *, ?, and [.<br>The pattern string that does not start with a slash (/) indicates a relative path.<br>If **includes** is not specified, the backup and restore framework uses the **includes** default (as listed in the code snippet below). |
| excludes             | String array| No  | Items in **includes** that do not need to be backed up. The value is in the same format as **includes**.<br>If **excludes** is not configured, the backup and restore framework uses an empty array by default. |

**includes** default:

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

