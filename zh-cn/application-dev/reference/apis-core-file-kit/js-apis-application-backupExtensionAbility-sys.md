# @ohos.application.BackupExtensionAbility (备份恢复扩展能力)(系统接口)

BackupExtensionAbility模块提供备份恢复服务相关扩展能力，为应用提供扩展的备份恢复能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.application.BackupExtensionAbility (备份恢复扩展能力)](js-apis-application-backupExtensionAbility-sys.md)。
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
```

### getBackupInfo<sup>12+</sup>

getBackupInfo(): string

在调用方查询应用数据时执行，由开发者提供扩展查询应用数据的操作。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**示例：**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    getBackupInfo(): string {
      console.log(`getBackupInfo ok`);
      let info = "app diy info";
      return info;
    }
  }
  ```
