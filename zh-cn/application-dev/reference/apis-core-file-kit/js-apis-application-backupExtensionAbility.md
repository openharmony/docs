# @ohos.application.BackupExtensionAbility (备份恢复扩展能力)

BackupExtensionAbility模块提供备份恢复服务相关扩展能力，为应用提供扩展的备份恢复能力。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
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

| 名称                  | 类型                                                              | 必填 | 说明                                                |
| --------------------- | ----------------------------------------------------------------- | ---- | --------------------------------------------------- |
| context<sup>11+</sup> | [BackupExtensionContext](js-apis-file-backupextensioncontext.md) | 是  | BackupExtensionAbility的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。 |

### onBackup

onBackup(): void;

Extension生命周期回调，在执行备份数据时回调，由开发者提供扩展的备份数据的操作。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**示例：**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async onBackup() {
      console.log('onBackup');
    }
  }
  ```

### onBackupEx<sup>12+</sup>

onBackupEx(backupInfo: string): string | Promise&lt;string&gt;

备份恢复框架增加扩展参数，允许应用备份、恢复时传递参数给应用。<br>
onBackupEx与onBackup互斥，如果重写onBackupEx，则优先调用onBackupEx。<br>
onBackupEx返回值不能为空字符串，若onBackupEx返回值为空字符串，则会尝试调用onBackup。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名           | 类型                            | 必填 | 说明                          |
|---------------| ------------------------------- | ---- |-----------------------------|
| backupInfo    |string | 是   | 扩展恢复数据的特殊处理接口中三方应用需要传递的包信息。 |

> **说明：**
>
> 同步处理业务场景中，推荐使用示例如下。

**示例：**

  ```ts
  import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';

  interface ErrorInfo {
    type: string,
    errorCode: number,
    errorInfo: string
  }

  class BackupExt extends BackupExtensionAbility {
    onBackupEx(backupInfo: string): string {
      console.log(`onBackupEx ok`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
    }
  }
  ```

> **说明：**
>
> 异步处理业务场景中，推荐使用示例如下。

**示例：**

  ```ts
  import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';

  interface ErrorInfo {
    type: string,
    errorCode: number,
    errorInfo: string
  }

  class BackupExt extends BackupExtensionAbility {
    //异步实现
    async onBackupEx(backupInfo: string): Promise<string> {
      console.log(`onBackupEx ok`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
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
  import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';

  class BackupExt extends BackupExtensionAbility {
    async onRestore(bundleVersion : BundleVersion) {
      console.log(`onRestore ok ${JSON.stringify(bundleVersion)}`);
    }
  }
  ```

### onRestoreEx<sup>12+</sup>

onRestoreEx(bundleVersion: BundleVersion, restoreInfo: string): string | Promise&lt;string&gt;

Extension生命周期回调，在执行恢复数据时回调，由开发者提供扩展的恢复数据的操作，支持异步操作。<br>
onRestoreEx与onRestore互斥，如果重写onRestoreEx，则优先调用onRestoreEx。<br>
onRestoreEx返回值不能为空字符串，若onRestoreEx返回值为空字符串，则会尝试调用onRestore。<br>
onRestoreEx的返回值为Json格式，使用方法见示例代码。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | 是   | 恢复时应用数据所在的版本信息。 |
| restoreInfo |string | 是   | 预留字段，应用恢复过程中需要的扩展参数。 |

> **说明：**
>
> 异步处理业务场景中，推荐使用示例如下。

**示例：**

  ```ts
  import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
  interface ErrorInfo {
    type: string,
    errorCode: number,
    errorInfo: string
  }

  class BackupExt extends BackupExtensionAbility {
    // 异步实现
    async onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): Promise<string> {
      console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
    }
  }
  ```

> **说明：**
>
> 同步处理业务场景中，推荐使用示例如下。

**示例：**

```ts
  import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
  interface ErrorInfo {
    type: string,
    errorCode: number,
    errorInfo: string
  }

  class BackupExt extends BackupExtensionAbility {
    // 同步实现
    onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): string {
      console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
    }
  }
  ```

### onProcess<sup>12+</sup>

onProcess(): string;

备份恢复框架增加进度返回接口。该接口为同步接口，由应用在执行onBackup(onBackupEx)/onRestore(onRestoreEx)期间进行实现。返回应用自身处理业务的进度，返回值为json结构，使用方法见示例代码。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

> **说明：**
> - onProcess可以不实现，系统有默认处理机制；若要实现，返回值结构严格按照示例代码返回。
> - 实现onProcess时，业务需要将onBackup(onBackupEx)/onRestore(onRestoreEx)做异步实现，且需要单独开辟子线程，否则onProcess相关功能无法正常运行。具体使用方式见示例代码。
> - onProcess() 推荐使用示例如下。

**示例：**

  ```ts
  import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
  import { taskpool } from '@kit.ArkTS';

  interface ProgressInfo {
    name: string, // appName
    processed: number, // 已处理的数据 
    total: number, // 总数
    isPercentage: boolean // 可选字段，true表示需要按百分比的格式化展示进度，false或者不实现该字段表示按具体项数展示进度
  }

  class BackupExt extends BackupExtensionAbility {
    // 如下代码中，appJob方法为模拟的实际业务代码，args为appJob方法的参数，用于提交到taskpool中，开启子线程进行工作
    async onBackup() {
      console.log(`onBackup begin`);
      let args = 100; // args为appJob方法的参数
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        console.error("onBackup error." + error.message);
      }
      taskpool.terminateTask(jobTask); // 需要手动销毁
      console.log(`onBackup end`);
    }

    async onRestore() {
      console.log(`onRestore begin`);
      let args = 100; // args为appJob方法的参数
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        console.error("onRestore error." + error.message);
      }
      taskpool.terminateTask(jobTask); // 需要手动销毁
      console.log(`onRestore end`);
    }
 

    onProcess(): string {
      console.log(`onProcess begin`);
      let process: string = `{
       "progressInfo":[
         {
          "name": "callact", // appName
          "processed": 100, // 已处理的数据 
          "total": 1000, //总数
          "isPercentage", true // 可选字段，true表示需要按百分比的格式化展示进度，false或者不实现该字段表示按具体项数展示进度
         }
       ]
      }`;
      console.log(`onProcess end`);
      return JSON.stringify(process);
    }
  }

  @Concurrent
  function appJob(args: number) : string {
    // 业务实际逻辑
    console.log(`appJob begin, args is: ` + args);
    return "ok";
  }
  ```
