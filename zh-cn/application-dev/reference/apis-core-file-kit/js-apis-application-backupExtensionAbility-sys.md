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

### getBackupCompatibilityInfo<sup>20+</sup>

getBackupCompatibilityInfo(extInfo: string): Promise&lt;string&gt;

在应用备份阶段，调用方获取应用自定义的能力描述信息时执行，由应用实现返回。使用Promise进行异步回调。

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| extInfo | string | 是   | 传递给应用的额外信息，由应用自行处理。|

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| Promise&lt;string&gt; | Promise对象，备份过程中应用自定义的能力描述信息。|

**示例：**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async getBackupCompatibilityInfo(extInfo: string): Promise<string> {
      let ret: string = '';
      try {
        // 此处仅以Json为示范，相应判断逻辑及相应字段由应用自定义
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

在应用恢复阶段，调用方获取应用自定义的能力描述信息时执行，由应用实现返回。使用Promise进行异步回调。

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| extInfo | string | 是   | 传递给应用的额外信息，由应用自行处理。|

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| Promise&lt;string&gt; | Promise对象，恢复过程中应用自定义的能力描述信息。|

**示例：**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async getRestoreCompatibilityInfo(extInfo: string): Promise<string> {
      let ret: string = '';
      try {
        // 此处仅以Json为示范，相应判断逻辑及相应字段由应用自定义
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