# @ohos.application.BackupExtensionAbility (BackupExtensionAbility)

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

onBackup(): void;

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

Called to pass parameters to the application during the application backup or restore process.
**onBackupEx()** and **onBackup()** are mutually exclusive. If **onBackupEx()** needs to be overridden, call **onBackupEx()** preferentially.
The return value of **onBackupEx()** cannot be an empty string. If an empty string is returned, **onRestore** will be called.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name          | Type                           | Mandatory| Description                         |
|---------------| ------------------------------- | ---- |-----------------------------|
| backupInfo    |string | Yes  | Package information to be passed by the third-party application.|

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

Called when data is being restored. You need to implement extended data restore operations.

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

Called when data is being restored. You need to implement the extended data restore operation. Asynchronous implementation is supported.
**onRestoreEx** and **onRestore** are mutually exclusive. Call **onRestoreEx** preferentially if it is overridden.
The return value of **onRestoreEx** cannot be an empty string. If an empty string is returned, the system will attempt to call **onRestore**.
The return value of **onRestoreEx()** is in JSON format. For details, see the sample code.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name       | Type                           | Mandatory| Description                          |
| ------------- | ------------------------------- | ---- | ------------------------------ |
| bundleVersion | [BundleVersion](#bundleversion) | Yes  | Version information of the application data to be restored.|
| restoreInfo |string | Yes  | Parameter to be passed in the restore process. This field is reserved.|

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

Called to report the progress information. This callback is executed synchronously and implemented during the execution of **onBackup/onBackupEx** or **onRestore/onRestoreEx**.
This callback returns the service processing progress of the application. The return value is in JSON format. For details, see the sample code.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

> **NOTE**
>
> - The system provides the default processing mechanism if **onProcess** is not implemented. If **onProcess** is used, the return value must strictly comply with that in the sample code. If **onProcess** is used, **onBackup/onBackupEx** and **onRestore/onRestoreEx** must be asynchronously executed
>   in a dedicated thread. Otherwise, **onProcess** cannot run properly. For details, see the sample code.
> - The following example shows the recommended use of **onProcess**.

**Example**

  ```ts
  import { BackupExtensionAbility, BundleVersion } from '@kit.CoreFileKit';
  import { taskpool } from '@kit.ArkTS';

  interface ProgressInfo {
    progressed: number,
    total: number
  }

  class BackupExt extends BackupExtensionAbility {
    // In the following code, the appJob method is the simulated service code, and args specifies the parameters of appJob(). This method is used to start a worker thread in the task pool.
    async onBackup() {
      console.log(`onBackup begin`);
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.HIGH);
      } catch (error) {
        console.error("onBackup error." + error.message);
      }
      console.log(`onBackup end`);
    }

    async onRestore() {
      console.log(`onRestore begin`);
      let jobTask: taskpool.Task = new taskpool.LongTask(appJob, args);
      try {
        await taskpool.execute(jobTask, taskpool.Priority.HIGH);
      } catch (error) {
        console.error("onRestore error." + error.message);
      }
      console.log(`onRestore end`);
    }


    onProcess(): string {
      console.log(`onProcess begin`);
      let processInfo: ProgressInfo = {
        progressed: 100, // Processed data.
        total: 1000, // Total data.
      }
      console.log(`onProcess end`);
      return JSON.stringify(processInfo);
    }
  }

  @Concurrent
  function appJob(args: number) : string {
    // Service logic.
    console.log(`appJob begin, args is: ` + args);
    return "ok";
  }
  ```
