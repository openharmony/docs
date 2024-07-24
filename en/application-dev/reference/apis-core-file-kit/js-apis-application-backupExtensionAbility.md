# @ohos.application.BackupExtensionAbility (BackupExtensionAbility)

The **BackupExtensionAbility** module provides extended backup and restore capabilities for applications.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import BackupExtension from '@ohos.application.BackupExtensionAbility';
```

## BundleVersion

Defines the version information required for data restore. You can determine the application data to be restored based on the version information.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name| Type  | Mandatory| Description            |
| ---- | ------ | ---- | ---------------- |
| code | number | Yes  | Internal version number of the application.  |
| name | string | Yes  | Version name of the application.|

## BackupExtensionAbility

Implements backup and restore for application access data. You can use [onBackup](#onbackup) and [onRestore](#onrestore) to implement custom backup and restore operations.

### Attributes

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name                 | Type                                                             | Read-Only| Writable| Description                                               |
| --------------------- | ----------------------------------------------------------------- | ---- | ---- | --------------------------------------------------- |
| context<sup>11+</sup> | [BackupExtensionContext](js-apis-file-backupextensioncontext.md) | Yes  | No  | Context of the BackupExtensionAbility. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### onBackup

onBackup(): void;

Called when data is being backed up. You need to implement extended data backup operations.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Example**

  ```ts
  class BackupExt extends BackupExtension {
    async onBackup() {
      console.log('onBackup');
    }
  }
  ```


### onRestore

onRestore(bundleVersion: BundleVersion): void;

Called when data is being restored. You need to implement extended data restore operations.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | Yes  | Version information of the application data to be restored.|

**Example**

  ```ts
  import { BundleVersion } from '@ohos.application.BackupExtensionAbility';

  class BackupExt extends BackupExtension {
    async onRestore(bundleVersion : BundleVersion) {
      console.log(`onRestore ok ${JSON.stringify(bundleVersion)}`);
    }
  }
  ```
  ### onRestoreEx

onRestoreEx(bundleVersion: BundleVersion, bundleInfo: string): string | Promise<string>;

Called when data is being restored. You need to implement the extended data restore operation.
**onRestoreEx** and **onRestore** are mutually exclusive. Call **onRestoreEx** preferentially if it is overridden.
The return value of **onRestoreEx** cannot be an empty string. If an empty string is returned, the system will attempt to call **onRestore**.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | Yes  | Version information of the application data to be restored.|
| bundleInfo |string | No  | Other information about the application.|

**Example**

  ```ts
  import { BundleVersion } from '@ohos.application.BackupExtensionAbility';

  class BackupExt extends BackupExtension {
    // Asynchronous implementation
    async onRestoreEx(bundleVersion : BundleVersion, bundleInfo: string): Promise<string> {
      console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let info = "app diy info";
      return info;
    }

    // Synchronous implementation
    onRestoreEx(bundleVersion : BundleVersion, bundleInfo: string): string {
      console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let info = "app diy info";
      return info;
    }
  }
  ```

  ### getBackupInfo

getBackupInfo(): string;

Obtains backup information. This API is called when the caller queries application data. You need to implement the operation for querying application data.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Example**

  ```ts

  class BackupExt extends BackupExtension {
    async getBackupInfo(): Promise<string> {
      console.log(`getBackupInfo ok`);
      let info = "app diy info";
      return info;
    }
  }
  ```
