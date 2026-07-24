# @ohos.application.BackupExtensionAbility (备份恢复扩展能力)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

BackupExtensionAbility模块提供备份恢复服务的系统扩展能力。应用可在备份、恢复阶段向调用方返回自定义备份信息和兼容性信息，用于支持备份恢复框架查询应用能力、判断兼容性并执行后续处理，降低备份恢复前能力协商和版本兼容判断的接入成本。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.application.BackupExtensionAbility (备份恢复扩展能力)](js-apis-application-backupExtensionAbility.md)。
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { BackupExtensionAbility } from '@kit.CoreFileKit';
```

### getBackupInfo<sup>12+</sup>

getBackupInfo(): string

在调用方查询应用数据时执行，由应用返回自定义备份信息。该接口适用于备份前需要向调用方提供应用数据描述、备份范围或其他自定义信息的场景。

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| string | 应用自定义的备份信息，具体格式和字段由应用自行定义，调用方按约定解析。|

**示例：**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    getBackupInfo(): string {
      console.info('getBackupInfo ok');
      let info = 'app diy info';
      return info;
    }
  }
  ```

### getBackupCompatibilityInfo<sup>20+</sup>

getBackupCompatibilityInfo(extInfo: string): Promise&lt;string&gt;

在应用备份阶段，调用方获取应用自定义兼容性信息时执行，由应用实现返回。该接口适用于备份前需要向调用方提供数据库版本、业务能力开关或是否支持备份等兼容性信息的场景。兼容性信息的具体格式和字段由应用自行定义，调用方按约定解析。使用Promise进行异步回调。

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| extInfo | string | 是   | 传递给应用的额外信息，由应用自行处理。|
**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| Promise&lt;string&gt; | Promise对象，返回备份过程中应用自定义的兼容性信息。|

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  class BackupExt extends BackupExtensionAbility {
    async getBackupCompatibilityInfo(extInfo: string): Promise<string> {
      let ret: string = '';
      try {
        // 此处仅以JSON为示范，相应判断逻辑及相应字段由应用自定义
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
        let err: BusinessError = error as BusinessError;
        console.error(`getBackupCompatibilityInfo failed with error. Code: ${err.code}, message: ${err.message}`);
      }
      return ret;
    }
  }
  ```

### getRestoreCompatibilityInfo<sup>20+</sup>

getRestoreCompatibilityInfo(extInfo: string): Promise&lt;string&gt;

在应用恢复阶段，调用方获取应用自定义兼容性信息时执行，由应用实现返回。该接口适用于恢复前需要向调用方提供数据库版本、业务能力开关或是否支持恢复等兼容性信息的场景。兼容性信息的具体格式和字段由应用自行定义，调用方按约定解析。使用Promise进行异步回调。

**系统接口**：此接口为系统接口

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| extInfo | string | 是   | 传递给应用的额外信息，由应用自行处理。|
**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| Promise&lt;string&gt; | Promise对象，返回恢复过程中应用自定义的兼容性信息。|

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  class BackupExt extends BackupExtensionAbility {
    async getRestoreCompatibilityInfo(extInfo: string): Promise<string> {
      let ret: string = '';
      try {
        // 此处仅以JSON为示范，相应判断逻辑及相应字段由应用自定义
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
        let err: BusinessError = error as BusinessError;
        console.error(`getRestoreCompatibilityInfo failed with error. Code: ${err.code}, message: ${err.message}`);
      }
      return ret;
    }
  }
  ```
