# @ohos.file.BackupExtensionContext (Backup and Restore Extension Capability)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--Designer: @wang_zhangjun; @chenxi0605-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @foryourself-->

**BackupExtensionContext** is the context of **BackupExtension** and inherits from **ExtensionContext**.

The **BackupExtensionContext** module provides the capability for accessing a specific **BackupExtension**. For a **BackupExtension**, you can directly use **BackupExtensionContext** as the context or define a context that inherits from **BackupExtensionContext**.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import  { BackupExtensionContext } from '@kit.CoreFileKit';
```

## BackupExtensionContext

### Properties

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- |-------| -------- | -------- |
| backupDir<sup>12+</sup> | string | Yes| No| Temporary directory used for backup or restore. This directory cannot be used for other purposes. Currently, only **el1/** and **el2/** are supported.|

### When to Use
**BackupExtensionContext** is used to obtain a temporary directory for backup or restore.

**Example**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
import { contextConstant } from '@kit.AbilityKit';

export default class MyBackupExtAbility extends BackupExtensionAbility {
    async onBackup() {
        console.log("onBackup begin");
        // You can modify this.context.area to change the sandbox path corresponding to el1/ or el2/.
        this.context.area = contextConstant.AreaMode.EL1;
        // Use this.context.backupDir to obtain the sandbox path.
        let dir = this.context.backupDir;
        console.log(`onBackup el1 dir: ${dir}`);
        this.context.area = contextConstant.AreaMode.EL2;
        dir = this.context.backupDir;
        console.log(`onBackup el2 dir: ${dir}`);
        console.log("onBackup end");
    }

    async onRestore() {
        console.log("onRestore begin");
        this.context.area = contextConstant.AreaMode.EL1;
        let dir = this.context.backupDir;
        console.log(`onRestore el1 dir: ${dir}`);
        this.context.area = contextConstant.AreaMode.EL2;
        dir = this.context.backupDir;
        console.log(`onRestore el2 dir: ${dir}`);
        console.log("onRestore end");
    }
}
```
