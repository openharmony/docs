# Accessing Backup and Restore

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--Designer: @chenxi0605-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=be32bd8bba98ad269ffd4be3b9a7ac920bcf706b translatedAt=2026-08-01T07:23:26.691Z pushedAt=2026-08-01T08:10:45.627Z -->

You can use **BackupExtensionAbility** to enable an application to access the backup and restore framework.

**BackupExtensionAbility** is a derived class of [ExtensionAbility](../application-models/extensionability-overview.md), which is an extension component in the [stage model](../application-models/stage-model-development-overview.md). You can customize the behavior of the backup and restore framework by modifying the configuration file, including whether to allow backup and restore and which files to back up.

## Available APIs

The following table lists the key APIs of the backup and restore extension capability. For API usage guidelines, see [@ohos.application.BackupExtensionAbility (Backup and Restore Extension Capability)](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md#backupextensionability) and [@ohos.file.BackupExtensionContext (Backup and Restore Extension Capability)](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md).

| Name                                                      | Description            |
| ------------------------------------------------------------ | ---------------- |
| onBackup(): void | Called to back up data before backup data migration.|
| onBackupEx(backupInfo: string): string \| Promise&lt;string&gt; | Called to back up data before backup data migration. It supports passing backup information and returning backup results.    |
| onRestore(bundleVersion: BundleVersion): void | Called to restore data after backup data migration.|
| onRestoreEx(bundleVersion: BundleVersion, restoreInfo: string): string \| Promise&lt;string&gt; | Called to restore data after backup data migration. It supports passing restore information and returning restore results.|
| onRelease(scenario: number): Promise&lt;void&gt; | Called when data backup or restore is complete.<br>**NOTE**<br>This API is supported since API version 20.|

## Constraints

- The path of the file or directory to be backed up or restored cannot exceed 4095 bytes. Otherwise, undefined behavior may occur.

- If a directory needs to be backed up, the application process must have the permission to read the directory and all its subdirectories (`r` in DAC). Otherwise, the backup fails.

- If a file needs to be backed up, the application process must have the permission to retrieve all the ancestor directories of the file (`x` in DAC). Otherwise, the backup fails.

- The path of the file or directory to be backed up or restored does not support relative paths (**../**) and soft links.

- For constraints on `BackupExtensionAbility` API calls, see [Constraints](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md#constraints) in the API reference.

## How to Develop

1. Add `extensionAbilities` to the application's `module.json5` file.

   Add the `"extensionAbilities"` field, set the registration type `"type"` to `"backup"`, and add an entry with `"name"` set to `"ohos.extension.backup"` in the ["metadata"](../reference/apis-ability-kit/js-apis-bundleManager-metadata.md).

   Example:

   ```json5
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
               "srcEntry": "./ets/BackupExtension/BackupExtension.ets"
           }      
       ]
   }
   ```

2. Add a metadata profile.

   The metadata profile defines the files to be transferred during the backup and restore process. The profile is located in the `resources/base/profile` directory of the project, and the file name must be the same as the value of `metadata.resource, for example, backup_config.json` in the `module.json5` file.

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

3. Customize `BackupExtensionAbility` in the `BackupExtension.ets` file and override `onBackup/onBackupEx` or `onRestore/onRestoreEx` to back up preprocessed application data or process the data to be restored.

   Empty implementation can be used if there is no special requirement. In this case, the backup and restore service backs up or restores data based on the unified backup and restore rules.

   The following example shows an empty implementation of the `BackupExtension.ets` file.

    ```ts
    // onBackup && onRestore
    import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
    import {hilog} from '@kit.PerformanceAnalysisKit';
    
    const TAG = `FileBackupExtensionAbility`;
    export default class BackupExtension extends  BackupExtensionAbility {
      // onBackup
      async onBackup ()   {
        hilog.info(0x0000, TAG, `onBackup ok`);
      }
      // onRestore
      async onRestore (bundleVersion : BundleVersion) {
        hilog.info(0x0000, TAG, `onRestore end`);
      }
    }
    ```

   <!-- @[on_backup_restore](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileBackupExtension/entry/src/main/ets/common/BackupExtension.ets) -->    

   ``` TypeScript
   import { BackupExtensionAbility } from '@kit.CoreFileKit';
   import { BundleVersion } from '@kit.CoreFileKit';
   // ...
   
   interface ErrorInfo {
     type: string,
     errorCode: number,
     errorInfo: string
   }
   
   // ...
   
   class BackupExt extends BackupExtensionAbility {
     // onBackupEx
     async onBackupEx(backupInfo: string): Promise<string> {
       console.info('onBackupEx ok');
       let errorInfo: ErrorInfo = {
         type: 'ErrorInfo',
         errorCode: 0,
         errorInfo: 'app diy error info'       
       }
       return JSON.stringify(errorInfo);
     }
   
     // onRestoreEx
     async onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): Promise<string> {
       console.info(`onRestoreEx begin`);
       let errorInfo: ErrorInfo = {
         type: 'ErrorInfo',
         errorCode: 0,
         errorInfo: 'app diy error info'
       }
       return JSON.stringify(errorInfo);
     }
     // ...
   }
   ```

4. Starting from API version 20, to perform special operations after application data backup and restore, such as cleaning up temporary files created during these processes, you can customize `BackupExtensionAbility` inherited by the class in the `BackupExtension.ets` file and override the `onRelease` method for execution when the backup or restore is complete.

   `onRelease` has a timeout mechanism. If the `onRelease` operation is not completed within 5 seconds, the application process exits when the backup and restoration are complete.

   The following example shows how to implement `onRelease` when the temporary file directory needs to be removed.

   <!-- @[on_release](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/CoreFile/FileBackupExtension/entry/src/main/ets/common/BackupExtension.ets) -->    

   ``` TypeScript
   import { BackupExtensionAbility } from '@kit.CoreFileKit';
   // ...
   import { fileIo } from '@kit.CoreFileKit';
   
   // ...
   
   const SCENARIO_BACKUP: number = 1;
   const SCENARIO_RESTORE: number = 2;
   // Temporary directory to be removed.
   let filePath: string = '/data/storage/el2/base/.temp/';
   
   class BackupExt extends BackupExtensionAbility {
     // ...
     // onRelease
     async onRelease(scenario: number): Promise<void> {
       try {
         if (scenario == SCENARIO_BACKUP) {
           // In the backup scenario, the application implements the processing. The following describes how to delete temporary files generated during backup.
           console.info(`onRelease begin`);
           await fileIo.rmdir(filePath);
           console.info(`onRelease end, rmdir succeed`);
         }
         if (scenario == SCENARIO_RESTORE) {
           // In the restore scenario, the application implements the processing. The following describes how to remove temporary files generated during restoration.
           console.info(`onRelease begin`);
           await fileIo.rmdir(filePath);
           console.info(`onRelease end, rmdir succeed`);
         }
       } catch (error) {
         console.error(`onRelease failed with error. Code: ${error.code}, message: ${error.message}`);
       }
     }
   }
   ```

### Description of the Metadata Profile

| Field            | Type  | Mandatory| Description                                                        |
| -------------------- | ---------- | ---- | ------------------------------------------------------------ |
| allowToBackupRestore | Boolean    | Yes  | Whether to enable backup and restore. The value **true** means backup and restore are enabled; the value **false** (default) means the opposite.                             |
| includes             | String array| No  | Files and directories to be backed up in the application sandbox directory.<br>The pattern string that does not start with a slash (/) indicates a relative path.<br>When configuring `includes`, ensure that the configured path range is included in the supported paths listed in the following code snippet. **The el3 and el4 paths cannot be backed up**.<br>If `includes` is not configured, the backup and restore framework uses the **includes** default (as listed in the code snippet below).|
| excludes             | String array| No  | Items in `includes` that do not need to be backed up. The value is in the same format as `includes`.<br>When configuring `excludes`, ensure that it is within the subset of `includes`.<br>If `excludes` is not configured, the backup and restore framework uses an empty array by default.|
| fullBackupOnly       | Boolean    | No  | Whether to use the default restore directory of the application. The default value is **false**. If the value is **true**, data will be cached in a temporary directory obtained by [backupDir](../reference/apis-core-file-kit/js-apis-file-backupextensioncontext.md#properties) in the data restore process. If it is **false** or not specified, the restored data is decompressed in **/**.|
| restoreDeps          | String    | No  | **(Not recommended)** Dependencies for the application to restore. The default value is "". You need to configure the names of the dependent applications. Currently, only one dependency is supported. The configured dependency takes effect only in the context of one restore task. If no dependent application is detected, the dependency description will be ignored and the restore task continues. The application restore will fail if the dependent application is not restored or fails to be restored.|
| extraInfo            | JSON string    | No  | Additional information to be passed.            |

**Field Description**

1. When setting **fullBackupOnly**, observe the following:

   - When **fullBackupOnly** is set to **false**, the restored data will be decompressed with **/** as the root directory, and files with the same name in the same path will be overwritten.

   - When **fullBackupOnly** is set to **true**, the restored data will be decompressed with a temporary directory as the root directory. You need to implement the data restoration logic in **onRestore** or **onRestoreEx** to complete the final restoration.

   You can choose the appropriate data restore mode based on your service scenarios.

   **Example:**

   Assume that the app's data backup path is **data/storage/el2/base/files/A/**. During restoration:

   - If **fullBackupOnly** is set to **false**, data will be directly decompressed to the **/data/storage/el2/base/files/A/** directory.

   - If **fullBackupOnly** is set to **true**, data will be decompressed to the **temporary path backupDir + /restore/data/storage/el2/base/files/A/** directory.

2. The list of paths supported by **includes** is as follows:

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

## Samples

The following sample is available:

- [FileBackupExtension (ArkTS) (Full SDK) (API10)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/FileManagement/FileBackupExtension)