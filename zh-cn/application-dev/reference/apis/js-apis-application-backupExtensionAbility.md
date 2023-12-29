# @ohos.application.BackupExtensionAbility (备份恢复扩展能力)

BackupExtensionAbility模块提供备份恢复服务相关扩展能力，为应用提供扩展的备份恢复能力。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import BackupExtension from '@ohos.application.BackupExtensionAbility';
```

## BundleVersion

恢复时所需要的版本信息，开发者可根据配置的版本号来判断本次恢复时的应用版本数据。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称 | 类型   | 必填 | 说明             |
| ---- | ------ | ---- | ---------------- |
| code | number | 是   | 应用的版本号。   |
| name | string | 是   | 应用的版本名称。 |

## BackupExtensionAbility

应用接入数据备份恢复需要通过BackupExtensionAbility实现，开发者可以通过[onBackup](#onbackup)，[onRestore](#onrestore)来实现自定义的备份恢复操作。

### 属性

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称                  | 类型                                                              | 可读 | 可写 | 说明                                                |
| --------------------- | ----------------------------------------------------------------- | ---- | ---- | --------------------------------------------------- |
| context<sup>11+</sup> | [ExtensionContext](js-apis-inner-application-extensionContext.md) | 是   | 否   | BackupExtensionAbility的上下文环境，继承自Context。 |

### onBackup

onBackup(): void;

Extension生命周期回调，在执行备份数据时回调，由开发者提供扩展的备份数据的操作。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**示例：**

  ```ts
  class BackupExt extends BackupExtension {
    async onBackup() {
      console.log('onBackup');
    }
  }
  ```


### onRestore

onRestore(bundleVersion: BundleVersion): void;

Extension生命周期回调，在执行恢复数据时回调，由开发者提供扩展的恢复数据的操作。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | 是   | 恢复时应用数据所在的版本信息。 |

**示例：**

  ```ts
  import { BundleVersion } from '@ohos.application.BackupExtensionAbility';
  
  class BackupExt extends BackupExtension {
    async onRestore(bundleVersion : BundleVersion) {
      console.log(`onRestore ok ${JSON.stringify(bundleVersion)}`);
    }
  }
  ```