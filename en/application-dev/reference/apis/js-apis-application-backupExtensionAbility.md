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


## BackupExtensionAbility.onBackup

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


## BackupExtensionAbility.onRestore

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
