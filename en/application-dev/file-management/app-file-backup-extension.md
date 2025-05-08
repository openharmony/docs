# Accessing Backup and Restore

You can use **BackupExtensionAbility** to enable an application to access the backup and restore framework.

**BackupExtensionAbility** is a class derived from [ExtensionAbility](../application-models/extensionability-overview.md) in the [stage model](../application-models/stage-model-development-overview.md). The application that has accessed the backup and restore framework can customize the backup and restore behavior, including whether to enable backup and restore and specifying the data to be backed up, in a profile. 

## Available APIs

For details about how to use the APIs, see [BackupExtensionAbility](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md#backupextensionability) and [Backup and Restore Extension Capability](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md).

## Constraints

- The path of the file or directory to be backed up or restored cannot exceed 4095 bytes. Otherwise, undefined behavior may occur.
- If a directory needs to be backed up, the application process must have the permission to read the directory and all its subdirectories (`r` in DAC). Otherwise, the backup fails.
- If a file needs to be backed up, the application process must have the permission to retrieve all the ancestor directories of the file (`x` in DAC). Otherwise, the backup fails.
- The path of the file or directory to be backed up or restored does not support relative paths (**../**) and soft links.

## How to Develop

1. Add `extensionAbilities` to the application's `module.json5` file.

   In `module.json5`, add the `extensionAbilities` field, set `type` to `backup`, and add a record with `name` set to `ohos.extension. backup` under **["metadata"](../reference/apis-ability-kit/js-apis-bundleManager-metadata.md)**.

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
               // In the BackupExtension.ets file, define BackupExtensionAbility in extensionAbilities and override onBackup or onBackupEx
               // and onRestore or onRestoreEx methods. The onBackupEx and onRestoreEx methods are recommended.
               // Empty implementation can be used if there is no special requirement. In this case, the backup and restore service backs up or restores data based on the unified backup and restore rules.
               "srcEntry": "./ets/BackupExtension/BackupExtension.ets", 
           }      
       ]
   }
   ```

2. Add a metadata profile.

   The metadata profile defines the files to be transferred during the backup and restore process. The profile is located in the **resources/base/profile** directory of the project, and the file name must be the same as the value of **metadata.resource**, for example, **backup_config.json** in the **module.json5** file.

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
       "restoreDeps": ""
   }
   ```

3. Customize **BackupExtensionAbility** in the **BackupExtension.ets** file and override **onBackup**/**onBackupEx** or **onRestore**/**onRestoreEx** to back up preprocessed application data or process the data to be restored.

   Empty implementation can be used if there is no special requirement. In this case, the backup and restore service backs up or restores data based on the unified backup and restore rules.

   The following example shows an empty implementation of the `BackupExtension.ets` file.

    ```ts
    //onBackup && onRestore
    import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
    import {hilog} from '@kit.PerformanceAnalysisKit';
    
    const TAG = `FileBackupExtensionAbility`;
    export default class BackupExtension extends  BackupExtensionAbility {
      //onBackup
      async onBackup ()   {
        hilog.info(0x0000, TAG, `onBackup ok`);
      }
      //onRestore
      async onRestore (bundleVersion : BundleVersion) {
        hilog.info(0x0000, TAG, `onRestore ok ${JSON.stringify(bundleVersion)}`);
        hilog.info(0x0000, TAG, `onRestore end`);
      }
    }
    ```

    ```ts
    //onBackupEx && onRestoreEx
    import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';

    interface ErrorInfo {
      type: string,
      errorCode: number,
      errorInfo: string
    }

    class BackupExt extends BackupExtensionAbility {
      //onBackupEx
      async onBackupEx(backupInfo: string): Promise<string> {
        console.log(`onBackupEx ok`);
        let errorInfo: ErrorInfo = {
          type: "ErrorInfo",
          errorCode: 0,
          errorInfo: "app diy error info"       
        }
        return JSON.stringify(errorInfo);
      }

      // onRestoreEx
      async onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): Promise<string> {
        console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
        let errorInfo: ErrorInfo = {
          type: "ErrorInfo",
          errorCode: 0,
          errorInfo: "app diy error info"
        }
        return JSON.stringify(errorInfo);
      }
    }
    ```

### Description of the Metadata Profile

| Field            | Type  | Mandatory| Description                                                        |
| -------------------- | ---------- | ---- | ------------------------------------------------------------ |
| allowToBackupRestore | Boolean    | Yes  | Whether to enable backup and restore. The default value is **false**.                             |
| includes             | String array| No  | Files and directories to be backed up in the application sandbox directory.<br>The pattern string that does not start with a slash (/) indicates a relative path.<br>When configuring `includes`, ensure that the configured path range is included in the supported paths listed in the following code snippet.<br>If `includes` is not configured, the backup and restore framework uses the **includes** default (as listed in the code snippet below).|
| excludes             | String array| No  | Items in `includes` that do not need to be backed up. The value is in the same format as `includes`.<br>When configuring `excludes`, ensure that it is within the subset of `includes`.<br>If `excludes` is not configured, the backup and restore framework uses an empty array by default.|
| fullBackupOnly       | Boolean    | No  | Whether to use the default restore directory of the application. The default value is **false**. If the value is **true**, data will be cached in a temporary directory obtained by [backupDir](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md) in the data restore process. If it is **false** or not specified, the restored data is decompressed in **/**.|
| restoreDeps          | String    | No  | **(Not recommended)** Dependencies for the application to restore. The default value is "". You need to configure the names of the dependent applications. Currently, only one dependency is supported. The configured dependency takes effect only in the context of one restore task. If no dependent application is detected, the dependency description will be ignored and the restore task continues. The application restore will fail if the dependent application is not restored or fails to be restored.|
| extraInfo            | JSON string    | No  | Additional information to be passed.                                  |

> **NOTE**
>
> When setting **fullBackupOnly**, observe the following:
>
> - If **fullBackupOnly** is set to **false**, the restored data will be decompressed in the root directory **/**, and the file with the same name in the directory will be overwritten.
> - If **fullBackupOnly** is set to **true**, the restored data will be decompressed in a temporary directory. You need to implement the data restoration logic in **OnRestore** or **OnRestoreEx**.
>
> You can determine the data restore mode to use based on service requirements.
>
> Example:
> Assume that the application backup path is **data/storage/el2/base/files/A/**. If **fullBackupOnly** is **false**, the restored data will be decompressed to the **/data/storage/el2/base/files/A/** directory. If **fullBackupOnly** is **true**, data will be decompressed to the temporary directory **[backupDir](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md)/restore/data/storage/el2/base/files/A/**.

The following lists the paths supported by **includes**:

```json
{
    "includes": [
    "data/storage/el1/database/",
    "data/storage/el1/base/files/",
    "data/storage/el1/base/preferences/",
    "data/storage/el1/base/haps/*/files/",
    "data/storage/el1/base/haps/*/preferences/",
    "data/storage/el2/database/",
    "data/storage/el2/base/files/",
    "data/storage/el2/base/preferences/",
    "data/storage/el2/base/haps/*/files/",
    "data/storage/el2/base/haps/*/preferences/",
    "data/storage/el2/distributedfiles/",
    "data/storage/el5/database/",
    "data/storage/el5/base/files/",
    "data/storage/el5/base/preferences/",
    "data/storage/el5/base/haps/*/files/",
    "data/storage/el5/base/haps/*/preferences/"
    ]
}
```

##  

 

-  
