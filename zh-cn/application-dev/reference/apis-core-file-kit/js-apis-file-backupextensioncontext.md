# @ohos.file.BackupExtensionContext (备份恢复扩展能力)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

BackupExtensionContext是BackupExtensionAbility的上下文环境，继承自ExtensionContext，用于在备份恢复过程中获取临时目录。

BackupExtensionContext模块提供访问特定BackupExtensionAbility资源的能力。应用实现备份恢复扩展能力时，可通过该上下文获取EL1（设备级加密区）或EL2（用户级加密区）对应的临时目录，用于临时保存待备份数据或读取待恢复数据，从而简化备份恢复扩展能力开发，并按数据安全等级隔离临时数据。对于扩展的BackupExtensionAbility，可直接将BackupExtensionContext作为上下文环境，或者定义一个继承自BackupExtensionContext的类型作为上下文环境。

> **说明：**
>
>  - 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>  - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { BackupExtensionContext } from '@kit.CoreFileKit';
```

## BackupExtensionContext

### 属性

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- |-------| -------- | -------- |
| backupDir | string | 是 | 否 | 获取备份恢复时的临时路径，该路径只允许在备份恢复过程中作为临时路径使用，不允许应用将该路径作为其他用途来使用。目前只支持EL1, EL2路径，使用其他路径会返回空值。 |

### 使用场景

BackupExtensionContext主要用于获取备份恢复过程中的临时路径。

**示例：**

```ts
import { BackupExtensionAbility } from '@kit.CoreFileKit';
import { contextConstant } from '@kit.AbilityKit';

export default class MyBackupExtAbility extends BackupExtensionAbility {
    async onBackup() {
        console.info('onBackup begin');
        // 设置加密区域为EL1（设备级加密区）
        this.context.area = contextConstant.AreaMode.EL1;
        // 使用者可通过this.context.backupDir对沙箱路径进行获取
        let dir = this.context.backupDir;
        console.info(`onBackup EL1 dir: ${dir}`);
        this.context.area = contextConstant.AreaMode.EL2;
        dir = this.context.backupDir;
        console.info(`onBackup EL2 dir: ${dir}`);
        console.info('onBackup end');
    }

    async onRestore() {
        console.info('onRestore begin');
        // 设置加密区域为EL1（设备级加密区）
        this.context.area = contextConstant.AreaMode.EL1;
        // 使用者可通过this.context.backupDir对沙箱路径进行获取
        let dir = this.context.backupDir;
        console.info(`onRestore EL1 dir: ${dir}`);
        this.context.area = contextConstant.AreaMode.EL2;
        dir = this.context.backupDir;
        console.info(`onRestore EL2 dir: ${dir}`);
        console.info('onRestore end');
    }
}
```
