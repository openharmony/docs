# @ohos.application.BackupExtensionAbility (Backup and Restore Extension Capability)

<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @rainlost-->
<!--Designer: @rainlost-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->
<!-- md-trans-meta sourceCommit=0547715d750965c950e08363cedf1ff726e5bd8a translatedAt=2026-08-17T09:27:56.352Z pushedAt=2026-08-18T09:00:33.700Z -->

The **BackupExtensionAbility** module provides the extension capability for the backup and restoration service. After an app integrates this capability, the system backup and restoration framework can schedule the backup, restoration, progress reporting, and secure exit logic to meet the requirements of app data migration, version compatibility processing, and temporary file cleanup. This improves data migration continuity and simplifies management of the backup and restoration process.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Constraints

To ensure system security and stability and prevent **BackupExtensionAbility** from abusing system resources, the system restricts its capabilities. Referencing certain modules is not supported. For details, please refer to the [Appendix](#appendix).

## Modules to Import

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
```

## BundleVersion

Defines the version information required for data restore. You can determine the application data to be restored based on the version information.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name| Type  | Read-Only| Optional| Description            |
| ---- | ------ | ---- | --- | ---------------- |
| code | number | No  | No | Internal version number of the application.  |
| name | string | No  | No | Version name of the application.|

## BackupExtensionAbility

You can use **BackupExtensionAbility** to enable an app to access the backup and restore framework. You can use [onBackup](#onbackup) or [onBackupEx](#onbackupex12) to implement custom backup, [onRestore](#onrestore) or [onRestoreEx](#onrestoreex12) to implement custom restoration, [onProcess](#onprocess12) to report the app processing progress, and [onRelease](#onrelease20) to execute the cleanup logic before the backup or restoration is complete. If **onBackup** and **onBackupEx** are rewritten at the same time, the framework preferentially calls **onBackupEx**. If **onRestore** and **onRestoreEx** are rewritten at the same time, the framework preferentially calls **onRestoreEx**.

### Properties

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name                 | Type                                                             | Read-Only| Optional| Description                                               |
| --------------------- | ----------------------------------------------------------------- | ---- | --- | --------------------------------------------------- |
| context<sup>11+</sup> | [BackupExtensionContext](js-apis-file-backupextensioncontext.md) | No | No| Context of the BackupExtensionAbility. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### onBackup

onBackup(): void

Defines an extension lifecycle callback, which is called when data is being backed up. You can customize the backup data processing logic.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Example**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async onBackup() {
      console.info('onBackup');
    }
  }
  ```

### onBackupEx<sup>12+</sup>

onBackupEx(backupInfo: string): string | Promise&lt;string&gt;

The backup and restoration framework passes extended parameters to the app during backup, allowing the app to perform custom backup processing based on the parameters. Compared with **onBackup**, **onBackupEx** can receive extended parameters, return processing results, and support asynchronous operations. Use **onBackupEx** when you need to process extended parameters from the caller or return the backup result. Use **onBackup** when you only need to execute the basic backup logic. This API uses a promise to return the result.<br>
**onBackupEx** and **onBackup** are mutually exclusive. Call **onBackupEx** preferentially if it is overridden.<br>
The return value of **onBackupEx** cannot be an empty string. If an empty string is returned, **onBackup** will be called.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name          | Type                           | Mandatory| Description                         |
|---------------| ------------------------------- | ---- |-----------------------------|
| backupInfo    | string | Yes   | Extended information transferred by the framework to the app during backup. The value is a string in JSON format. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| string \| Promise&lt;string&gt; | Information about the app's custom backup operation. The return value is a JSON format string containing the **type**, **errorCode**, and **errorInfo** fields, which are filled in by the app based on the business processing result.<br>**Promise&lt;string&gt;** is returned asynchronously.<br>A string is returned for synchronous operations. |

> **NOTE**
>
> The following shows the sample code for synchronous implementation.

**Example**

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
        // If backupInfo is empty, the application processes the data based on the service.
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

> **NOTE**
>
> The following shows the sample code for asynchronous implementation.

**Example**

```ts
import { BackupExtensionAbility } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  // Asynchronous implementation
  async onBackupEx(backupInfo: string): Promise<string> {
    try {
      if (backupInfo == '') {
        // If backupInfo is empty, the application processes the data based on the service.
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

Defines an extension lifecycle callback, which is called when data is being restored. You need to implement the extended data restore operation.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | Yes  | Version information of the application data to be restored.|

**Example**

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

Defines an extension lifecycle callback, which is called when data is being restored. You need to implement the custom data restore operation. Compared with **onRestore**, **onRestoreEx** can receive extended parameters, return processing results, and support asynchronous operations. Use **onRestoreEx** when you need to process extended parameters from the caller or return the restore result. Use **onRestore** when you only need to execute the basic restore logic. This API uses a promise to return the result.<br>
**onRestoreEx** and **onRestore** are mutually exclusive. Call **onRestoreEx** preferentially if it is overridden.<br>
The return value of **onRestoreEx** cannot be an empty string. If an empty string is returned, the system will attempt to call **onRestore**.<br>
The return value of **onRestoreEx** is in JSON format. For details, see the sample code.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | Yes  | Version information of the app data to be restored.|
| restoreInfo | string | Yes | Extended information transferred by the framework to the app during restoration. The value is a string in JSON format. |

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| string \| Promise&lt;string&gt; | Information about the app's custom restore operation. The return value is a JSON format string containing the **type**, **errorCode**, and **errorInfo** fields, which are filled in by the app based on the business processing result.<br>**Promise&lt;string&gt;** is returned asynchronously.<br>A string is returned for synchronous operations. |

> **NOTE**
>
> The following shows the sample code for asynchronous implementation.

**Example**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  // Asynchronous implementation
  async onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): Promise<string> {
    try {
      if (restoreInfo == '') {
        // If restoreInfo is empty, the application processes the data based on the service.
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

> **NOTE**
>
> The following shows the sample code for synchronous implementation.

**Example**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}

class BackupExt extends BackupExtensionAbility {
  // Synchronous implementation
  onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): string {
    try {
      if (restoreInfo == '') {
        // If restoreInfo is empty, the application processes the data based on the service.
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

Adds an API to the backup and restoration framework to return the progress information. This callback is executed synchronously and implemented during the execution of **onBackup/onBackupEx** or **onRestore/onRestoreEx**. This callback returns the service processing progress of the application. The return value is in JSON format. For details, see the sample code.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Type                  | Description   |
| --------------------- | :---- |
| string | Progress information during the execution of **onBackup** or **onRestore**. The return value is in JSON format. The JSON structure contains the **name**, **processed**, **total**, and **isPercentage** fields. For details, see the sample code. |

> **NOTE**
>
> - If it is not implemented, the system reports only the backup and restoration progress that can be obtained on the framework, excluding the custom service processing progress of the app. If **onProcess** is used, the return value must strictly comply with that in the sample code.
> - The execution of **onProcess** cannot exceed 1 second. The system calls **onProcess** every 5 seconds. If the execution times out for three consecutive times, the current backup or restoration task of the application is terminated.
> - If **onProcess** is used, **onBackup/onBackupEx** and **onRestore/onRestoreEx** must be asynchronously executed in a dedicated thread. Otherwise, **onProcess** cannot run properly. For details, see the sample code.
> - The following example shows the recommended use of **onProcess()**.

**Example**

  ```ts
  import { BackupExtensionAbility } from '@kit.CoreFileKit';
  import { taskpool } from '@kit.ArkTS';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Sendable
  class MigrateProgressInfo {
    private migrateProgress: string = '';
    private name: string = 'test'; // appName
    private processed: number = 0; // Processed data
    private total: number = 100; // Total number
    private isPercentage: boolean = true // (Optional) The value true means to display the progress in percentage; the value false or an unimplemented field means to display the progress by the number of items.

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

    // In the following code, the appJob method is the simulated service code, and args specifies the parameters of appJob(). This method is used to start a worker thread in the task pool.
    async onBackup() {
      console.info(`onBackup begin`);
      let args = 100; // args is a parameter of appJob().
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, this.progressInfo, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`onBackup error. Code: ${err.code}, message: ${err.message}`);
      }
      taskpool.terminateTask(jobTask); // Manually destroy the task.
      console.info(`onBackup end`);
    }

    async onRestore() {
      console.info(`onRestore begin`);
      let args = 100; // args is a parameter of appJob().
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, this.progressInfo, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        let err: BusinessError = error as BusinessError;
        console.error(`onRestore error. Code: ${err.code}, message: ${err.message}`);
      }
      taskpool.terminateTask(jobTask); // Manually destroy the task.
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
    // Update the processing progress during service execution.
    let currentProcessed: number = 0;
    // Simulate the actual service logic.
    for (let i = 0; i < args; i++) {
      currentProcessed = i;
      progressInfo.updateProcessed(currentProcessed);
    }
    return 'ok';
  }
  ```

### onRelease<sup>20+</sup>

onRelease(scenario: number): Promise&lt;void&gt;

Provides secure exit APIs of the backup and restore framework. It is triggered when the application backup or restore is complete, allowing the application to perform special processing afterward, such as removing temporary files generated during these operations. This API uses a promise to return the result.<br>
**onRelease** has a timeout mechanism. If the **onRelease** operation is not completed within 5 seconds, the application process exits when the backup and restoration are complete.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| scenario | number | Yes | The system passes this parameter based on the current operation scenario. Developers execute the corresponding cleanup logic based on the parameter value.<br>The value **1** indicates the backup scenario.<br>The value **2** indicates the restore scenario. |

**Return value**

| Type                  | Description   |
| --------------------- | :---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
// The following describes an example of removing files.
import { BackupExtensionAbility, fileIo } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';

const SCENARIO_BACKUP: number = 1;
const SCENARIO_RESTORE: number = 2;
// Temporary directory to be removed.
let filePath: string = '/data/storage/el2/base/.temp/';

class BackupExt extends BackupExtensionAbility {
  async onRelease(scenario: number): Promise<void> {
    try {
      if (scenario == SCENARIO_BACKUP) {
        // In the backup scenario, the application implements the processing. The following describes how to remove temporary files generated during backup.
        console.info(`onRelease begin`);
        await fileIo.rmdir(filePath);
        console.info(`onRelease end, rmdir succeed`);
      }
      if (scenario == SCENARIO_RESTORE) {
        // In the restore scenario, the application implements the processing. The following describes how to remove temporary files generated during restoration.
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

## Appendix

**BackupExtensionAbility** does not support referencing the following modules.

| Kit | Module |
| --- | --- |
| Ability Kit | [@ohos.abilityAccessCtrl (Application Access Control)](../apis-ability-kit/js-apis-abilityAccessCtrl.md) |
| Ability Kit | [@ohos.app.ability.appManager (Application Management)](../apis-ability-kit/js-apis-app-ability-appManager.md) |
| <!--DelRow--> Ability Kit | [@ohos.app.ability.missionManager (missionManager) (System API)](../apis-ability-kit/js-apis-app-ability-missionManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.app.ability.quickFixManager (quickFixManager) (System API)](../apis-ability-kit/js-apis-app-ability-quickFixManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.application.missionManager (missionManager) (System API)](../apis-ability-kit/js-apis-application-missionManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.appControl (appControl Module) (System API)](../apis-ability-kit/js-apis-appControl-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.bundleMonitor (bundleMonitor Module) (System API)](../apis-ability-kit/js-apis-bundleMonitor-sys.md) |
| Ability Kit | [@ohos.bundle.defaultAppManager (Default Application Management)](../apis-ability-kit/js-apis-defaultAppManager.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.distributedBundleManager (distributedBundleManager Module) (System API)](../apis-ability-kit/js-apis-distributedBundleManager-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.freeInstall (freeInstall Module) (System API)](../apis-ability-kit/js-apis-freeInstall-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.bundle.innerBundleManager (innerBundleManager Module) (System API)](../apis-ability-kit/js-apis-Bundle-InnerBundleManager-sys.md) |
| Ability Kit | [@ohos.bundle.launcherBundleManager (launcherBundleManager Module)](../apis-ability-kit/js-apis-launcherBundleManager.md) |
| <!--DelRow--> Ability Kit | [@ohos.distributedBundle (Distributed Bundle Management) (System API)](../apis-ability-kit/js-apis-Bundle-distributedBundle-sys.md) |
| <!--DelRow--> Ability Kit | [@ohos.distributedMissionManager (Distributed Mission Management) (System API)](../apis-ability-kit/js-apis-distributedMissionManager-sys.md) |
| <!--DelRow--> Ability Kit | [BundleInstaller (System API)](../apis-ability-kit/js-apis-bundle-BundleInstaller-sys.md) |
| <!--DelRow--> Ability Kit | [ServiceExtensionContext (System API)](../apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md) |
| Ability Kit | [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) |
| <!--DelRow--> ArkUI | [@ohos.screen (Screen) (System API)](../apis-arkui/js-apis-screen-sys.md) |
| ArkUI | [@ohos.screenshot (Screenshot)](../apis-arkui/js-apis-screenshot.md) |
| <!--DelRow--> ArkUI | [@ohos.window (Window) (System API)](../apis-arkui/js-apis-window-sys.md) |
| <!--DelRow--> Audio Kit | [@ohos.multimedia.audio (Audio Management) (System API)](../apis-audio-kit/js-apis-audio-sys.md) |
| Background Tasks Kit | [@ohos.bundleState (Device Usage Statistics)](../apis-backgroundtasks-kit/js-apis-deviceUsageStatistics.md) |
| Background Tasks Kit | [@ohos.reminderAgent (Agent-powered Reminder)](../apis-backgroundtasks-kit/js-apis-reminderAgent.md) |
| Background Tasks Kit | [@ohos.reminderAgentManager (Agent-powered Reminder)](../apis-backgroundtasks-kit/js-apis-reminderAgentManager.md) |
| <!--DelRow--> Background Tasks Kit | [@ohos.resourceschedule.usageStatistics (Device Usage Statistics) (System API)](../apis-backgroundtasks-kit/js-apis-resourceschedule-deviceUsageStatistics-sys.md) |
| Basic Services Kit | [@ohos.power (System Power Management)](../apis-basic-services-kit/js-apis-power.md) |
| <!--DelRow--> Basic Services Kit | [@ohos.update (Update) (System API)](../apis-basic-services-kit/js-apis-update-sys.md) |
| Connectivity Kit | [@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../apis-connectivity-kit/js-apis-cardEmulation.md) |
| <!--DelRow--> Core File Kit | [@ohos.file.fileAccess (User File Access and Management) (System API)](js-apis-fileAccess-sys.md) |
| <!--DelRow--> Form Kit | [@ohos.app.form.formHost (formHost) (System API)](../apis-form-kit/js-apis-app-form-formHost-sys.md) |
| Form Kit | [@ohos.application.formError (formError)](../apis-form-kit/js-apis-application-formError.md) |
| Form Kit | [@ohos.application.formError (formError)](../apis-form-kit/js-apis-application-formError.md) |
| <!--DelRow--> Form Kit | [@ohos.application.formHost (formHost) (System API)](../apis-form-kit/js-apis-application-formHost-sys.md) |
| IME Kit | [@ohos.inputMethod (Input Method Framework)](../apis-ime-kit/js-apis-inputmethod.md) |
| <!--DelRow--> Input Kit | [@ohos.multimodalInput.inputMonitor (Input Monitor) (System API)](../apis-input-kit/js-apis-inputmonitor-sys.md) |
| Location Kit | [@ohos.geolocation (Geolocation)](../apis-location-kit/js-apis-geolocation.md) |
| MDM Kit | [@ohos.enterprise.adminManager (Administrator Permission Management)](../apis-mdm-kit/js-apis-enterprise-adminManager.md) |
| <!--DelRow--> MDM Kit | [@ohos.enterprise.dateTimeManager (System Time Management) (System API)](../apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md) |
| <!--DelRow--> Media Kit | [@ohos.multimedia.media (Media) (System API)](../apis-media-kit/js-apis-media-sys.md) |
| Sensor Service Kit | [@ohos.sensor (Sensor)](../apis-sensor-service-kit/js-apis-sensor.md) |