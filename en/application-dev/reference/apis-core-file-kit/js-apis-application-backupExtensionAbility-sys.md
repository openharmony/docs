# @ohos.application.BackupExtensionAbility (Backup and Restore Extension Capability) (System API)

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

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Example**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    getBackupInfo(): string {
      console.log(`getBackupInfo ok`);
      let info = "app diy info";
      return info;
    }
  }
  ```
