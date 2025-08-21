# @ohos.application.BackupExtensionAbility (BackupExtensionAbility)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @lvzhenjie-->
<!--Designer: @wang_zhangjun; @chenxi0605-->
<!--Tester: @liuhonggang123-->
<!--Adviser: @foryourself-->

The **BackupExtensionAbility** module provides extended backup and restore capabilities for applications.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
```

## BundleVersion

Defines the version information required for data restore. You can determine the application data to be restored based on the version information.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name| Type  | Mandatory| Description            |
| ---- | ------ | ---- | ---------------- |
| code | number | Yes  | Internal version number of the application.  |
| name | string | Yes  | Version name of the application.|

## BackupExtensionAbility

Implements backup and restore for application access data. You can use [onBackup](#onbackup) and [onRestore](#onrestore) to implement custom backup and restore operations.

### Properties

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name                 | Type                                                             | Mandatory| Description                                               |
| --------------------- | ----------------------------------------------------------------- | ---- | --------------------------------------------------- |
| context<sup>11+</sup> | [BackupExtensionContext](js-apis-file-backupextensioncontext.md) | Yes | Context of the BackupExtensionAbility. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### onBackup

onBackup(): void

Called when data is being backed up. You need to implement extended data backup operations.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Example**

  ```ts
  class BackupExt extends BackupExtensionAbility {
    async onBackup() {
      console.log('onBackup');
    }
  }
  ```

### onBackupEx<sup>12+</sup>

onBackupEx(backupInfo: string): string | Promise&lt;string&gt;

Called to pass parameters to the application during the application backup or restore process. It uses a promise to return the result.<br>
**onBackupEx** and **onBackup** are mutually exclusive. Call **onBackupEx** preferentially if it is overridden.<br>
The return value of **onBackupEx** cannot be an empty string. If an empty string is returned, **onBackup** will be called.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name          | Type                           | Mandatory| Description                         |
|---------------| ------------------------------- | ---- |-----------------------------|
| backupInfo    |string | Yes  | Package information to be passed by the third-party application.<br>When it is an empty string, you need to determine how to handle this scenario.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
|string \| Promise&lt;string&gt; |Information about the custom backup operation executed by the application, including the backup result and error information. The return value is in JSON format.<br>A promise object is returned for asynchronous operations.<br>A string is returned for synchronous operations.|

> **NOTE**
>
> The following shows the sample code for synchronous implementation.

**Example**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';

interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  onBackupEx(backupInfo: string): string {
    try {
      if (backupInfo == "") {
        // When backupInfo is empty, you need to handle this based on the service logic of the application.
        console.info("backupInfo is empty");
      }
      console.log(`onBackupEx ok`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      console.error(`BackupExt error. Code:${err.code}, message:${err.message}`);
    }
    return "";
  }
} 
```

> **NOTE**
>
> The following shows the sample code for asynchronous implementation.

**Example**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';

interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  // Asynchronous implementation.
  async onBackupEx(backupInfo: string): Promise<string> {
    try {
      if (backupInfo == "") {
        // When backupInfo is empty, you need to handle this based on the service logic of the application.
        console.info("backupInfo is empty");
      }
      console.log(`onBackupEx ok`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      console.error(`BackupExt error. Code:${err.code}, message:${err.message}`);
    }
    return "";
  }
} 
```

### onRestore

onRestore(bundleVersion: BundleVersion): void

Called when data is being restored. You need to implement the extended data restore operation.

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
      console.log(`onRestore ok ${JSON.stringify(bundleVersion)}`);
    }
  }
  ```

### onRestoreEx<sup>12+</sup>

onRestoreEx(bundleVersion: BundleVersion, restoreInfo: string): string | Promise&lt;string&gt;

Called when data is being restored. You need to implement the extended data restore operation. It uses a promise to return the result.<br>
**onRestoreEx** and **onRestore** are mutually exclusive. Call **onRestoreEx** preferentially if it is overridden.<br>
The return value of **onRestoreEx** cannot be an empty string. If an empty string is returned, the system will attempt to call **onRestore**.<br>
The return value of **onRestoreEx** is in JSON format. For details, see the sample code.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | Yes  | Version information of the application data to be restored.|
| restoreInfo |string | Yes  | Parameter to be passed in the restore process. This field is reserved.<br>It may be an empty string in some cases.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| string \| Promise&lt;string&gt; |Information about the custom restore operation executed by the application, including the restore result and error information. The return value is in JSON format.<br>A promise object is returned for asynchronous operations.<br>A string is returned for synchronous operations.|

> **NOTE**
>
> The following shows the sample code for asynchronous implementation.

**Example**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}
class BackupExt extends BackupExtensionAbility {
  // Asynchronous implementation
  async onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): Promise<string> {
    try {
      if (restoreInfo == "") {
        // When restoreInfo is empty, you need to handle this based on the service logic of the application.
        console.info("restoreInfo is empty");
      }
      console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      console.error(`onRestoreEx error. Code:${err.code}, message:${err.message}`);
    }
    return "";
  }
}
```

> **NOTE**
>
> The following shows the sample code for synchronous implementation.

**Example**

```ts
import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
interface ErrorInfo {
  type: string,
  errorCode: number,
  errorInfo: string
}

class BackupExt extends BackupExtensionAbility {
  // Synchronous implementation
  onRestoreEx(bundleVersion : BundleVersion, restoreInfo: string): string {
    try {
      if (restoreInfo == "") {
        // When restoreInfo is empty, you need to handle this based on the service logic of the application.
        console.info("restoreInfo is empty");
      }
      console.log(`onRestoreEx ok ${JSON.stringify(bundleVersion)}`);
      let errorInfo: ErrorInfo = {
        type: "ErrorInfo",
        errorCode: 0,
        errorInfo: "app customized error info"
      }
      return JSON.stringify(errorInfo);
    } catch (err) {
      console.error(`onRestoreEx error. Code:${err.code}, message:${err.message}`);
    }
    return "";
  }
}

```

### onProcess<sup>12+</sup>

onProcess(): string

Called to return the progress information. This callback is executed synchronously and implemented during the execution of **onBackup/onBackupEx** or **onRestore/onRestoreEx**. This callback returns the service processing progress of the application. The return value is in JSON format. For details, see the sample code.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Type                  | Description   |
| --------------------- | :---- |
| string |Progress information during the execution of **onBackup** or **onRestore**. The return value is in JSON format.|

> **NOTE**
>
> - The system provides the default processing mechanism if **onProcess** is not implemented. If **onProcess** is used, the return value must strictly comply with that in the sample code.
> - If **onProcess** is used, **onBackup/onBackupEx** and **onRestore/onRestoreEx** must be asynchronously executed in a dedicated thread. Otherwise, **onProcess** cannot run properly. For details, see the sample code.
> - The following example shows the recommended use of **onProcess()**.

**Example**

  ```ts
  import { BackupExtensionAbility } from '@kit.CoreFileKit';
  import { taskpool } from '@kit.ArkTS';

  @Sendable
  class MigrateProgressInfo {
    private migrateProgress: string = '';
    private name: string = "test"; // appName
    private processed: number = 0; // Processed data
    private total: number = 100; // Total number
    private isPercentage: boolean = true // (Optional) The value true means to display the progress in percentage; the value false or an unimplemented field means to display the progress by the number of items.

    getMigrateProgress(): string {
      this.migrateProgress = `{"progressInfo": [{"name": "${this.name}", "processed": "${this.processed}", "total": "${
        this.total}", "isPercentage": "${this.isPercentage}"}]}`;
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
      console.log(`onBackup begin`);
      let args = 100; // args is a parameter of appJob().
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, this.progressInfo, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        console.error("onBackup error." + error.message);
      }
      taskpool.terminateTask(jobTask); // Manually destroy the task.
      console.log(`onBackup end`);
    }

    async onRestore() {
      console.log(`onRestore begin`);
      let args = 100; // args is a parameter of appJob().
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, this.progressInfo, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.LOW);
      } catch (error) {
        console.error("onRestore error." + error.message);
      }
      taskpool.terminateTask(jobTask); // Manually destroy the task.
      console.log(`onRestore end`);
    }
 

    onProcess(): string {
      console.log(`onProcess begin`);
      return this.progressInfo.getMigrateProgress();
    }
  }

  @Concurrent
  function appJob(progressInfo: MigrateProgressInfo, args: number) : string {
    console.log(`appJob begin, args is: ` + args);
    // Update the processing progress during service execution.
    let currentProcessed: number = 0;
    // Simulate the actual service logic.
    for (let i = 0; i < args; i++) {
      currentProcessed = i;
      progressInfo.updateProcessed(currentProcessed);
    }
    return "ok";
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
| scenario | number | Yes  | Indicates the backup or restore scenario.<br>The value **1** indicates the backup scenario.<br>The value **2** indicates the restore scenario.|

**Return value**

| Type                  | Description   |
| --------------------- | :---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
// The following describes an example of removing files.
import { BackupExtensionAbility, fileIo } from '@kit.CoreFileKit';

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
      console.error(`onRelease failed with error. Code: ${error.code}, message: ${error.message}`);
    }
  }
}
```
