# @ohos.application.BackupExtensionAbility (备份恢复扩展能力)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

BackupExtensionAbility模块提供备份恢复服务的扩展能力。应用接入该能力后，可由系统备份恢复框架调度备份、恢复、进度上报和安全退出逻辑，满足应用数据迁移、版本兼容处理和临时文件清理等场景，提升数据迁移连续性并降低应用自行管理备份恢复流程的复杂度。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 约束限制

为保障系统安全性和稳定性，防止BackupExtensionAbility滥用系统资源，系统对其能力进行管控，不支持部分模块的引用，详情请参考[附录](#附录)。

## 导入模块

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
```

## BundleVersion

恢复时所需要的版本信息，开发者可根据配置的版本号来判断本次恢复时的应用版本数据。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称 | 类型   | 只读 | 可选 | 说明             |
| ---- | ------ | ---- | --- | ---------------- |
| code | number | 否   | 否  | 应用的版本号。   |
| name | string | 否   | 否  | 应用的版本名称。 |

## BackupExtensionAbility

应用接入数据备份恢复需要通过BackupExtensionAbility实现。开发者可以通过[onBackup](#onbackup)或[onBackupEx](#onbackupex12)实现自定义备份操作，通过[onRestore](#onrestore)或[onRestoreEx](#onrestoreex12)实现自定义恢复操作，并可通过[onProcess](#onprocess12)上报应用处理进度，通过[onRelease](#onrelease20)在备份或恢复结束前执行清理逻辑。如果同时重写onBackup和onBackupEx，框架优先调用onBackupEx。如果同时重写onRestore和onRestoreEx，框架优先调用onRestoreEx。

### 属性

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

| 名称                  | 类型                                                              | 只读 | 可选 | 说明                                                |
| --------------------- | ----------------------------------------------------------------- | ---- | --- | --------------------------------------------------- |
| context<sup>11+</sup> | [BackupExtensionContext](js-apis-file-backupextensioncontext.md) | 否  | 否 | BackupExtensionAbility的上下文环境，继承自[ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)。 |

### onBackup

onBackup(): void

Extension生命周期回调，在执行备份数据时回调，由开发者实现自定义备份数据处理。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**示例：**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async onBackup() {
      console.info('onBackup');
    }
  }
  ```

### onBackupEx<sup>12+</sup>

onBackupEx(backupInfo: string): string | Promise&lt;string&gt;

备份恢复框架在备份时向应用传递扩展参数，支持应用根据参数执行自定义备份处理。与onBackup相比，onBackupEx支持接收扩展参数、返回处理结果并支持异步操作。需要处理调用方扩展参数或返回备份结果时使用onBackupEx，仅需执行基础备份逻辑时使用onBackup。使用Promise异步回调。<br>
onBackupEx与onBackup互斥，如果重写onBackupEx，则优先调用onBackupEx。<br>
onBackupEx返回值不能为空字符串，若onBackupEx返回值为空字符串，则会尝试调用onBackup。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名           | 类型                            | 必填 | 说明                          |
|---------------| ------------------------------- | ---- |-----------------------------|
| backupInfo    | string | 是   | 备份时框架传递给应用的扩展信息，参数为JSON格式字符串。 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| string \| Promise&lt;string&gt; | 返回应用执行自定义备份操作的信息，返回值为JSON格式字符串，包含type、errorCode和errorInfo字段。type、errorCode和errorInfo由应用根据业务处理结果自行填充。<br>异步返回Promise&lt;string&gt;。<br>同步返回string。 |

> **说明：**
>
> 同步处理业务场景中，推荐使用示例如下。

**示例：**

```ts
import { BackupExtensionAbility } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  onBackupEx(backupInfo: string): string {
    try {
      if (backupInfo == '') {
        // 当backupInfo为空时，应用根据业务自行做处理。
        console.info('backupInfo is empty');
      }
      console.info(`onBackupEx ok`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: 0,
        errorInfo: 'app customized error info'
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error(`BackupExt error. Code:${error.code}, message:${error.message}`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: error.code,
        errorInfo: error.message
      }
      return JSON.stringify(errorInfo);
    }
  }
} 
```

> **说明：**
>
> 异步处理业务场景中，推荐使用示例如下。

**示例：**

```ts
import { BackupExtensionAbility } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  // 异步实现
  async onBackupEx(backupInfo: string): Promise<string> {
    try {
      if (backupInfo == '') {
        // 当backupInfo为空时，应用根据业务自行做处理。
        console.info('backupInfo is empty');
      }
      console.info(`onBackupEx ok`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: 0,
        errorInfo: 'app customized error info'
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error(`BackupExt error. Code:${error.code}, message:${error.message}`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: error.code,
        errorInfo: error.message
      }
      return JSON.stringify(errorInfo);
    }
  }
} 
```

### onRestore

onRestore(bundleVersion: BundleVersion): void

Extension生命周期回调，在执行恢复数据时回调，由开发者提供扩展的恢复数据操作。

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
      console.info(`onRestore ok ${JSON.stringify(bundleVersion)}`);
    }
  }
  ```

### onRestoreEx<sup>12+</sup>

onRestoreEx(bundleVersion: BundleVersion, restoreInfo: string): string | Promise&lt;string&gt;

Extension生命周期回调，在执行恢复数据时回调，由开发者实现自定义恢复数据处理。与onRestore相比，onRestoreEx支持接收扩展参数、返回处理结果并支持异步操作。需要处理调用方扩展参数或返回恢复结果时使用onRestoreEx，仅需执行基础恢复逻辑时使用onRestore。使用Promise异步回调。<br>
onRestoreEx与onRestore互斥，如果重写onRestoreEx，则优先调用onRestoreEx。<br>
onRestoreEx返回值不能为空字符串，若onRestoreEx返回值为空字符串，则会尝试调用onRestore。<br>
onRestoreEx的返回值为JSON格式，使用方法见示例代码。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | 是   | 恢复时应用数据所在的版本信息。 |
| restoreInfo | string | 是   | 恢复时框架传递给应用的扩展信息，参数为JSON格式字符串。 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| string \| Promise&lt;string&gt; | 返回应用执行自定义恢复操作的信息，返回值为JSON格式字符串，包含type、errorCode和errorInfo字段。type、errorCode和errorInfo由应用根据业务处理结果自行填充。<br>异步返回Promise&lt;string&gt;。<br>同步返回string。 |

> **说明：**
>
> 异步处理业务场景中，推荐使用示例如下。

**示例：**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  // 异步实现
  async onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): Promise<string> {
    try {
      if (restoreInfo == '') {
        // 当restoreInfo为空时，应用根据业务自行做处理。
        console.info('restoreInfo is empty');
      }
      console.info(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: 0,
        errorInfo: 'app customized error info'
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error(`onRestoreEx error. Code:${error.code}, message:${error.message}`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: error.code,
        errorInfo: error.message
      }
      return JSON.stringify(errorInfo);
    }
  }
}
```

> **说明：**
>
> 同步处理业务场景中，推荐使用示例如下。

**示例：**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}

class BackupExt extends BackupExtensionAbility {
  // 同步实现
  onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): string {
    try {
      if (restoreInfo == '') {
        // 当restoreInfo为空时，应用根据业务自行做处理。
        console.info('restoreInfo is empty');
      }
      console.info(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: 0,
        errorInfo: 'app customized error info'
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error(`onRestoreEx error. Code:${error.code}, message:${error.message}`);
      let errorInfo: ErrorInfo = {
        type: 'ErrorInfo',
        errorCode: error.code,
        errorInfo: error.message
      }
      return JSON.stringify(errorInfo);
    }
  }
}

```

### onProcess<sup>12+</sup>

onProcess(): string

备份恢复框架增加用于返回进度的接口。该接口为同步接口，由应用在执行onBackup(onBackupEx)/onRestore(onRestoreEx)期间实现。返回应用自身处理业务的进度，返回值为JSON结构，使用方法见示例代码。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| string | 返回应用onBackup或者onRestore执行过程中处理数据的进度信息，返回值为JSON格式。JSON结构包含name、processed、total、isPercentage等字段，具体含义见示例代码。 |

> **说明：**
>
> - onProcess可以不实现。不实现时，系统仅上报框架侧可获取的备份恢复进度，不包含应用自定义业务处理进度。若要实现，返回值结构严格按照示例代码返回。
> - onProcess具有超时机制，执行不可超过1秒，系统每5秒调用一次onProcess，累计3次超时后，直接结束应用当前备份或恢复任务。
> - 实现onProcess时，业务需要将onBackup(onBackupEx)/onRestore(onRestoreEx)做异步实现，且需要单独开辟子线程，否则onProcess进度上报功能无法正常运行。具体使用方式见示例代码。
> - onProcess()推荐使用示例如下。

**示例：**

  ```ts
  import { BackupExtensionAbility } from '@kit.CoreFileKit';
  import { taskpool } from '@kit.ArkTS';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Sendable
  class MigrateProgressInfo {
    private migrateProgress: string = '';
    private name: string = 'test'; // appName
    private processed: number = 0; // 已处理的数据
    private total: number = 100; // 总数
    private isPercentage: boolean = true // 可选字段，true表示需要按百分比的格式化展示进度，false或者不实现该字段表示按具体项数展示进度

    getMigrateProgress(): string {
      this.migrateProgress = `{"progressInfo": [{"name": ${this.name}, "processed": ${this.processed}, "total": ${
        this.total}, "isPercentage": ${this.isPercentage}}]}`;
      return this.migrateProgress;
    }

    updateProcessed(processed: number) {
      this.processed = processed;
    }
  }

  class BackupExt extends BackupExtensionAbility {
    private progressInfo: MigrateProgressInfo = new MigrateProgressInfo();

    // 如下代码中，appJob方法为模拟的实际业务代码，args为appJob方法的参数，用于提交到taskpool中，开启子线程进行工作
    async onBackup() {
      console.info(`onBackup begin`);
      let args = 100; // args为appJob方法的参数
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, this.progressInfo, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`onBackup error. Code: ${err.code}, message: ${err.message}`);
      }
      taskpool.terminateTask(jobTask); // 需要手动销毁
      console.info(`onBackup end`);
    }

    async onRestore() {
      console.info(`onRestore begin`);
      let args = 100; // args为appJob方法的参数
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, this.progressInfo, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`onRestore error. Code: ${err.code}, message: ${err.message}`);
      }
      taskpool.terminateTask(jobTask); // 需要手动销毁
      console.info(`onRestore end`);
    }
 

    onProcess(): string {
      console.info(`onProcess begin`);
      return this.progressInfo.getMigrateProgress();
    }
  }

  @Concurrent
  function appJob(progressInfo: MigrateProgressInfo, args: number) : string {
    console.info(`appJob begin, args is: ` + args);
    // 在业务执行时刷新已处理进度
    let currentProcessed: number = 0;
    // 模拟业务实际逻辑
    for (let i = 0; i < args; i++) {
      currentProcessed = i;
      progressInfo.updateProcessed(currentProcessed);
    }
    return 'ok';
  }
  ```

### onRelease<sup>20+</sup>

onRelease(scenario: number): Promise&lt;void&gt;

备份恢复框架安全退出接口。应用备份或恢复完成时回调，应用可实现备份恢复完成后的一些特殊处理，例如清理备份或恢复产生的临时文件。使用Promise异步回调。<br>
onRelease具有超时机制，应用若在5秒内未完成onRelease操作，将触发备份恢复结束时的应用进程退出流程。

**系统能力**：SystemCapability.FileManagement.StorageService.Backup

**参数：**

| 参数名        | 类型                            | 必填 | 说明                           |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| scenario | number | 是   | 系统根据当前操作场景传入该参数，开发者根据参数值执行对应清理逻辑。<br>scenario = 1表示当前为备份场景。<br>scenario = 2表示当前为恢复场景。|

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**示例：**

```ts
// 以清理文件为例
import { BackupExtensionAbility, fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

const SCENARIO_BACKUP: number = 1;
const SCENARIO_RESTORE: number = 2;
// 需要清理的临时目录
let filePath: string = '/data/storage/el2/base/.temp/';

class BackupExt extends BackupExtensionAbility {
  async onRelease(scenario: number): Promise<void> {
    try {
      if (scenario == SCENARIO_BACKUP) {
        // 备份场景，应用自行实现处理，以清理备份产生的临时文件为例
        console.info(`onRelease begin`);
        await fileIo.rmdir(filePath);
        console.info(`onRelease end, rmdir succeed`);
      }
      if (scenario == SCENARIO_RESTORE) {
        // 恢复场景，应用自行实现处理，以清理恢复产生的临时文件为例
        console.info(`onRelease begin`);
        await fileIo.rmdir(filePath);
        console.info(`onRelease end, rmdir succeed`);
      }
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error(`onRelease failed with error. Code: ${err.code}, message: ${err.message}`);
    }
  }
}
```

## 附录

BackupExtensionAbility不支持以下模块的引用。

| Kit | 模块 |
| --- | --- |
| Ability Kit | [@ohos.abilityAccessCtrl (程序访问控制管理)](../apis-ability-kit/js-apis-abilityAccessCtrl.md) |
| Ability Kit | [@ohos.app.ability.appManager (应用管理)](../apis-ability-kit/js-apis-app-ability-appManager.md) |
| <!--DelRow--> Ability Kit | [@ohos.app.ability.missionManager (missionManager)(系统接口)](../apis-ability-kit/js-apis-app-ability-missionManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.app.ability.quickFixManager (quickFixManager)(系统接口)](../apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.application.missionManager (missionManager)(系统接口)](../apis-ability-kit/js-apis-application-missionManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.appControl (appControl模块)(系统接口)](../apis-ability-kit/js-apis-appControl-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.bundleMonitor (bundleMonitor模块)(系统接口)](../apis-ability-kit/js-apis-bundleMonitor-sys.md) |
| Ability Kit | [@ohos.bundle.defaultAppManager (默认应用管理)](../apis-ability-kit/js-apis-defaultAppManager.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.distributedBundleManager (distributedBundleManager模块)(系统接口)](../apis-ability-kit/js-apis-distributedBundleManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.freeInstall (freeInstall模块)(系统接口)](../apis-ability-kit/js-apis-freeInstall-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.innerBundleManager (innerBundleManager模块)(系统接口)](../apis-ability-kit/js-apis-Bundle-InnerBundleManager-sys.md) |
| Ability Kit | [@ohos.bundle.launcherBundleManager (launcherBundleManager模块)](../apis-ability-kit/js-apis-launcherBundleManager.md) |
| <!--DelRow--> Ability Kit | [@ohos.distributedBundle (分布式包管理)(系统接口)](../apis-ability-kit/js-apis-Bundle-distributedBundle-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.distributedMissionManager (分布式任务管理)(系统接口)](../apis-ability-kit/js-apis-distributedMissionManager-sys.md) |
| <!--DelRow--> Ability Kit | [BundleInstaller (系统接口)](../apis-ability-kit/js-apis-bundle-BundleInstaller-sys.md) |
| <!--DelRow--> Ability Kit | [ServiceExtensionContext (系统接口)](../apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md) |
| Ability Kit | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) |
| <!--DelRow--> ArkUI | [@ohos.screen (屏幕)(系统接口)](../apis-arkui/js-apis-screen-sys.md) |
| ArkUI | [@ohos.screenshot (屏幕截图)](../apis-arkui/js-apis-screenshot.md) |
| <!--DelRow--> ArkUI | [@ohos.window (窗口)(系统接口)](../apis-arkui/js-apis-window-sys.md) |
| <!--DelRow--> Audio Kit | [@ohos.multimedia.audio (音频管理)(系统接口)](../apis-audio-kit/js-apis-audio-sys.md) |
| Background Tasks Kit | [@ohos.bundleState (设备使用信息统计)](../apis-backgroundtasks-kit/js-apis-deviceUsageStatistics.md) |
| Background Tasks Kit | [@ohos.reminderAgent (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgent.md) |
| Background Tasks Kit | [@ohos.reminderAgentManager (后台代理提醒)](../apis-backgroundtasks-kit/js-apis-reminderAgentManager.md) |
| <!--DelRow--> Background Tasks Kit | [@ohos.resourceschedule.usageStatistics (设备使用信息统计)(系统接口)](../apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md) |
| Basic Services Kit | [@ohos.power (系统电源管理)](../apis-basic-services-kit/js-apis-power.md) |
| <!--DelRow--> Basic Services Kit | [@ohos.update (升级)(系统接口)](../apis-basic-services-kit/js-apis-update-sys.md) |
| Connectivity Kit | [@ohos.nfc.cardEmulation (标准NFC-cardEmulation)](../apis-connectivity-kit/js-apis-cardEmulation.md) |
| <!--DelRow--> Core File Kit | [@ohos.file.fileAccess (公共文件访问与管理)(系统接口)](js-apis-fileAccess-sys.md) |
| <!--DelRow--> Form Kit | [@ohos.app.form.formHost (formHost)(系统接口)](../apis-form-kit/js-apis-app-form-formHost-sys.md) |
| Form Kit | [@ohos.application.formError (formError)](../apis-form-kit/js-apis-application-formError.md) |
| Form Kit | [@ohos.application.formError (formError)](../apis-form-kit/js-apis-application-formError.md) |
| <!--DelRow--> Form Kit | [@ohos.application.formHost (formHost)(系统接口)](../apis-form-kit/js-apis-application-formHost-sys.md) |
| IME Kit | [@ohos.inputMethod (输入法框架)](../apis-ime-kit/js-apis-inputmethod.md) |
| <!--DelRow--> Input Kit | [@ohos.multimodalInput.inputMonitor (输入监听)(系统接口)](../apis-input-kit/js-apis-inputmonitor-sys.md) |
| Location Kit | [@ohos.geolocation (位置服务)](../apis-location-kit/js-apis-geolocation.md) |
| MDM Kit | [@ohos.enterprise.adminManager（admin权限管理）](../apis-mdm-kit/js-apis-enterprise-adminManager.md) |
| <!--DelRow--> MDM Kit | [@ohos.enterprise.dateTimeManager（系统时间管理）(系统接口)](../apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md) |
| <!--DelRow--> Media Kit | [@ohos.multimedia.media (媒体服务)(系统接口)](../apis-media-kit/js-apis-media-sys.md) |
| Sensor Service Kit | [@ohos.sensor (传感器)](../apis-sensor-service-kit/js-apis-sensor.md) |
