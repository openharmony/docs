# @ohos.application.BackupExtensionAbility (Backup and Restore Extension Capability) (System API)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--SE: @wang_zhangjun; @chenxi0605-->
<!--TSE: @liuhonggang123-->

The **BackupExtensionAbility** module provides extended backup and restore capabilities for applications.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This page contains only the system APIs of this module. For details about other public APIs, see [@ohos.application.BackupExtensionAbility (Backup and Restore Extension Capability)](js-apis-application-backupExtensionAbility-sys.md).
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
```

### getBackupInfo<sup>12+</sup>

getBackupInfo(): string

Obtains backup information. This API is called when the caller queries application data. You need to implement the operation for querying application data.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Returns**

| Type                  | Description   |
| --------------------- | :---- |
| string | Backup information customized by the application.|

**Example**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    getBackupInfo(): string {
      console.info('getBackupInfo ok');
      let info = "app diy info";
      return info;
    }
  }
  ```

### getBackupCompatibilityInfo<sup>20+</sup>

getBackupCompatibilityInfo(extInfo: string): Promise&lt;string&gt;

Obtains the backup compatibility information. This API is called when the caller obtains application's custom capabilities during backup. The operation is implemented by the application. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| extInfo | string | Yes  | Extra information passed to the application. The implementation is determined by the application.|

**Returns**

| Type                  | Description   |
| --------------------- | :---- |
| Promise&lt;string&gt; | Promise that describes the application's custom capabilities during backup.|

**Example**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async getBackupCompatibilityInfo(extInfo: string): Promise<string> {
      let ret: string = '';
      try {
        // Here JSON is used only as an example. The corresponding judgment logic and relevant fields should be customized by the application.
        if (!extInfo) {
          ret = '{"dbVersion": "1.0", "isThemCardEnable": "true"}';
        } else {
          let extJson: Record<string, string> = JSON.parse(extInfo);
          if (extJson?.requireCompatibility) {
            ret = '{"isSupportBackup": "true"}';
          } else {
            ret = '{"isSupportBackup": "false"}';
          }
        }
      } catch (error) {
        console.error(`getBackupCompatibilityInfo failed with error. Code: ${error.code}, message: ${error.message}`);
      }
      return JSON.stringify(ret);
    }
  }
  ```

### getRestoreCompatibilityInfo<sup>20+</sup>

getRestoreCompatibilityInfo(extInfo: string): Promise&lt;string&gt;

Obtains the restore compatibility information. This API is called when the caller obtains application's custom capabilities during restore. The operation is implemented by the application. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| extInfo | string | Yes  | Extra information passed to the application. The implementation is determined by the application.|

**Returns**

| Type                  | Description   |
| --------------------- | :---- |
| Promise&lt;string&gt; | Promise that describes the application's custom capabilities during restore.|

**Example**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async getRestoreCompatibilityInfo(extInfo: string): Promise<string> {
      let ret: string = '';
      try {
        // Here JSON is used only as an example. The corresponding judgment logic and relevant fields should be customized by the application.
        if (!extInfo) {
          ret = '{"dbVersion": "1.0", "isThemCardEnable": "true"}';
        } else {
          let extJson: Record<string, string> = JSON.parse(extInfo);
          if (extJson?.requireCompatibility) {
            ret = '{"isSupportRestore": "true"}';
          } else {
            ret = '{"isSupportRestore": "false"}';
          }
        }
      } catch (error) {
        console.error(`getRestoreCompatibilityInfo failed with error. Code: ${error.code}, message: ${error.message}`);
      }
      return JSON.stringify(ret);
    }
  }
  ```
