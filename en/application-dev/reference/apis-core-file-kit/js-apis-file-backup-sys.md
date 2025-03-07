# @ohos.file.backup (Backup and Restore) (System API)

The **file.backup** module provides APIs for backing up and restoring data for applications.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import backup from '@ohos.file.backup';
```

## FileMeta

Defines a file metadata object, which includes the application name and file URI. **FileMeta** is an indispensable object for data backup and restore.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name      | Type  | Mandatory| Description                                                                                               |
| ---------- | ------ | ---- | --------------------------------------------------------------------------------------------------- |
| bundleName | string | Yes  | Application name, which can be obtained from [bundleManager.BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md).|
| uri        | string | Yes  | URI of the file in the application sandbox.<br>Currently, the URI is not in the standard format. It can consist of digits (0–9), letters (a–z and A–Z), underscores (_), and period (.) only.     |

## FileData

Defines a file data object, which includes the file descriptor (FD) of the file opened. **FileData** is an indispensable object for data backup and restore.

> **NOTE**
>
> The **FileData** must be closed after being used. Otherwise, memory leakage may occur. For details about how to close a **FileData** object, see [fs.closeSync](js-apis-file-fs.md#fsclosesync) provided by [@ohos.file.fs](js-apis-file-fs.md).

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name| Type  | Mandatory| Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | Yes  | FD, which can be obtained through the backup service.|

## FileManifestData<sup>12+</sup>

Defines a file data object, which includes the file descriptor (FD) of the file opened. The file opened by **FileManifestData** provides basic information about the files involved in incremental backup or restore. **FileManifestData** is an indispensable object for incremental backup or restore.

> **NOTE**
>
> For details about how to close **FileManifestData**, see [fs.closeSync](js-apis-file-fs.md#fsclosesync).

**System capability**: SystemCapability.FileManagement.StorageService.Backup
| Name      | Type  | Mandatory| Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| manifestFd | number | Yes  | FD, which can be obtained through the backup service.|

## IncrementalBackupTime<sup>12+</sup>

Represents the time of the last incremental backup.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name               | Type  | Mandatory| Description                                                                                               |
| ------------------- | ------ | ---- | --------------------------------------------------------------------------------------------------- |
| bundleName          | string | Yes  | Application name, which can be obtained from [bundleManager.BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md).|
| lastIncrementalTime | number | Yes  | Time when the last incremental backup was performed.                                                                             |

## BackupParams<sup>12+</sup>

Represents optional parameters in JSON strings for backup and restore.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name      | Type  | Mandatory| Description                                              |
| ---------- | ------ | ---- | -------------------------------------------------- |
| parameters | string | No  | Optional parameters for backup or restore, in JSON strings.|

## BackupPriority<sup>12+</sup>

Represents the backup priority.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name    | Type  | Mandatory| Description                                                  |
| -------- | ------ | ---- | ------------------------------------------------------ |
| priority | number | No  | Backup priority. A larger value indicates a higher priority. If the priorities are the same, the API called first is executed first.|

## IncrementalBackupData<sup>12+</sup>

Represents an incremental backup object, which inherits from [IncrementalBackupTime](#incrementalbackuptime12), [FileManifestData](#filemanifestdata12), [BackupParams](#backupparams12), and [BackupPriority](#backuppriority12).

> **NOTE**
>
> This object provides information about the last incremental backup time and the FD of the file that contains a list of the files involved in the incremental backup. Optional parameters include backup and restore configuration and backup priority.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

## File

Defines a file object, which
inherits from [FileMeta](#filemeta) and [FileData](#filedata).

> **NOTE**
>
> **file.backup.File** is different from [File](js-apis-file-fs.md#file) provided in @ohos.file.fs. The former is an object that inherits from [FileMeta](#filemeta) and [FileData](#filedata), while the latter has only one FD object. Pay attention to the difference between them.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

## File <sup>12+</sup>

Defines a file object, which
inherits from [FileMeta](#filemeta), [FileData](#filedata), and [FileManifestData](#filemanifestdata12).

> **NOTE**
>
> **file.backup.File** is different from [File](js-apis-file-fs.md#file) provided in @ohos.file.fs. The former is an object that inherits from [FileMeta](#filemeta) and [FileData](#filedata), while the latter has only one FD object. Pay attention to the difference between them.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

## GeneralCallbacks

Provides callbacks to be used in the backup or restore process. The backup service uses these callbacks to notify the client of the backup/restore progress of the application.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

### onFileReady

onFileReady : AsyncCallback&lt;File&gt;

Called when the file is ready for sending to the client. If the callback is invoked successfully, [File](#file) is returned. Otherwise, an **err** object is returned.

> **NOTE**
>
> The **File** returned by **AsyncCallback** is the file.backup.[File](#file). The returned file belongs to the backup service. Once the file is closed, the backup service shall clear the resources used by the file at the proper time. However, the client must close the file handle first.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  onFileReady: (err: BusinessError, file: backup.File) => {
    if (err) {
      console.error('onFileReady failed with err: ' + JSON.stringify(err));
      return;
    }
    console.info('onFileReady success with file: ' + file.bundleName + ' ' + file.uri);
    fs.closeSync(file.fd);
  }
  ```

### onBundleBegin

onBundleBegin : AsyncCallback&lt;string, void | string&gt;

Called when the application backup or restore starts. If the callback is successfully invoked, **bundleName** is returned. Otherwise, an **err** object is returned. Since API version 12, **err** and **bundleName** are returned.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Name    | Type         | Mandatory| Description                                                       |
| ---------- | ------------- | ---- | ----------------------------------------------------------- |
| bundleName | string        | Yes  | Application name.                                         |
| err        | BusinessError | No  | Error returned if the operation fails. If the operation is successful, **err** is **undefined**, and **data** is the bundle name.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                                             |
| -------- | ----------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13500001 | The application is not added to the backup or restore |
| 13500002 | Failed to start application extension Procedure       |
| 13600001 | IPC error                                             |
| 13900005 | I/O error                                             |
| 13900011 | Out of memory                                         |
| 13900020 | Invalid argument                                      |
| 13900025 | No space left on device                               |
| 13900042 | Unknown error                                         |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleBegin: (err: BusinessError, bundleName: string) => {
    if (err) {
      console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code));
      return;
    }
    console.info('onBundleBegin success');
  }
  ```

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleBegin: (err: BusinessError<string>, bundleName: string) => {
    if (err) {
      console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
      return;
    }
    console.info('onBundleBegin success');
  }
  ```

### onBundleEnd

onBundleEnd : AsyncCallback&lt;string, void | string&gt;

Called when the application backup or restore ends. If the callback is successfully invoked, **bundleName** is returned. Otherwise, an **err** object is returned. Since API version 12, **err** and **bundleName** are returned.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Name    | Type         | Mandatory| Description                                                       |
| ---------- | ------------- | ---- | ----------------------------------------------------------- |
| bundleName | string        | Yes  | Application name.                                         |
| err        | BusinessError | No  | Error returned if the operation fails. If the operation is successful, **err** is **undefined**, and **data** is the bundle name.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13500003 | Backup or restore timed out     |
| 13500004 | Application extension death     |
| 13600001 | IPC error                       |
| 13900005 | I/O error                       |
| 13900011 | Out of memory                   |
| 13900020 | Invalid argument                |
| 13900025 | No space left on device         |
| 13900042 | Unknown error                   |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleEnd: (err: BusinessError, bundleName: string) => {
    if (err) {
      console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
      return;
    }
    console.info('onBundleEnd success with bundleName: ' + bundleName);
  }
  ```

  ```ts
  import { BusinessError } from '@ohos.base';

  onBundleEnd: (err: BusinessError<string>, bundleName: string) => {
    if (err) {
      console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
      return;
    }
    console.info('onBundleEnd success');
  }
  ```

### onAllBundlesEnd

onAllBundlesEnd : AsyncCallback&lt;undefined&gt;

Called when the backup or restore of all applications ends. If the callback fails to be invoked, an **err** object is returned.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  onAllBundlesEnd: (err: BusinessError) => {
    if (err) {
      console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
      return;
    }
    console.info('onAllBundlesEnd success');
  }
  ```

### onBackupServiceDied

onBackupServiceDied : Callback&lt;undefined&gt;

Called when the backup service is suspended. If this callback fails to be invoked, an **err** object is returned.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Example**

  ```ts
  onBackupServiceDied: () => {
    console.info('onBackupServiceDied success');
  }
  ```

### onResultReport

onResultReport (bundleName: string, result: string)

Called when the backup or restore is complete. If the callback is invoked successfully, the application bundle name and backup or restore information (such as the number of backed up or restored records or exception information) are returned.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Name    | Type  | Mandatory| Description                           |
| ---------- | ------ | ---- | ------------------------------- |
| bundleName | string | Yes  | Bundle name.                       |
| result     | string | Yes  | Application backup/restore information returned in JSON format.|

**Example**

  ```ts
  import backup from '@ohos.file.backup';

  onResultReport: (bundleName: string, result: string) => {
    console.info('onResultReport bundleName : ' + bundleName);
    console.info('onResultReport result : ' + result);
  }
  ```

### onProcess

onProcess (bundleName: string, process: string)

Called to report the backup or restore progress information. If the callback is invoked successfully, the progress information or exception information are returned.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Name    | Type  | Mandatory| Description                           |
| ---------- | ------ | ---- | ------------------------------- |
| bundleName | string | Yes  | Bundle name.                       |
| process     | string | Yes  | Backup/restore progress information in JSON format.|

**Example**

  ```ts
  import backup from '@ohos.file.backup';

  onProcess: (bundleName: string, process: string) => {
    console.info('onProcess bundleName : ' + bundleName);
    console.info('onProcess processInfo : ' + process);
  }
  ```

## backup.getLocalCapabilities

getLocalCapabilities(callback: AsyncCallback&lt;FileData&gt;): void

Obtains a JSON file that describes local capabilities. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                                      | Mandatory| Description                                              |
| -------- | ------------------------------------------ | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;[FileData](#filedata)&gt; | Yes  | Callback used to return the **FileData** object obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  try {
    backup.getLocalCapabilities((err: BusinessError, fileData: backup.FileData) => {
      if (err) {
        console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      fs.closeSync(fileData.fd);
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
  }
  ```

The capability file can be obtained by using [fs.stat](js-apis-file-fs.md#fsstat-1) of the [@ohos.file.fs](js-apis-file-fs.md) module. The following is an example of the capability file.

 ```json
 {
  "bundleInfos" :[{
    "allToBackup" : true,
    "extensionName" : "BackupExtensionAbility",
    "name" : "com.example.hiworld",
    "needToInstall" : false,
    "spaceOccupied" : 0,
    "versionCode" : 1000000,
    "versionName" : "1.0.0"
    }],
  "deviceType" : "default",
  "systemFullName" : "OpenHarmony-4.0.0.0"
 }
 ```

## backup.getLocalCapabilities

getLocalCapabilities(): Promise&lt;FileData&gt;

Obtains a JSON file that describes local capabilities. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Type                                | Description                           |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise used to return the **FileData** object obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  async function getLocalCapabilities() {
    try {
      let fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      fs.closeSync(fileData.fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    }
  }
  ```

  The capability file can be obtained by using [fs.stat](js-apis-file-fs.md#fsstat) of the [@ohos.file.fs](js-apis-file-fs.md) module. The following is an example of the capability file.

 ```json
 {
  "bundleInfos" :[{
    "allToBackup" : true,
    "extensionName" : "BackupExtensionAbility",
    "name" : "com.example.hiworld",
    "needToInstall" : false,
    "spaceOccupied" : 0,
    "versionCode" : 1000000,
    "versionName" : "1.0.0"
    }],
  "deviceType" : "default",
  "systemFullName" : "OpenHarmony-4.0.0.0"
 }
 ```

## backup.getLocalCapabilities<sup>12+</sup>

getLocalCapabilities(dataList:Array&lt;IncrementalBackupTime&gt;): Promise&lt;FileData&gt;

Obtains local capabilities. The local capabilities of an application are queried based on the **dataList** parameter passed in. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**
| Name  | Type                                                          | Mandatory| Description                                          |
| -------- | -------------------------------------------------------------- | ---- | ---------------------------------------------- |
| dataList | Array&lt;[IncrementalBackupTime](#incrementalbackuptime12)&gt; | Yes  | List of the files involved in the incremental backup.|

**Return value**

| Type                                | Description                           |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[FileData](#filedata)&gt; | Promise used to return the **FileData** object obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                                                                                      |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900005 | I/O error                                                                                      |
| 13900011 | Out of memory                                                                                  |
| 13900020 | Invalid argument                                                                               |
| 13900025 | No space left on device                                                                        |
| 13900042 | Unknown error                                                                                  |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  async function getLocalCapabilities() {
    try {
      let backupApps: backup.IncrementalBackupTime[] = [{
        bundleName: "com.example.hiworld",
        lastIncrementalTime: 1700107870 // Time of the last incremental backup.
      }];
      let fileData = await backup.getLocalCapabilities(backupApps);
      console.info('getLocalCapabilities success');
      console.info('fileData info:' + fileData.fd);
      fs.closeSync(fileData.fd);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## backup.getBackupInfo

getBackupInfo(bundleToBackup: string): string;

Obtains information about the application to back up.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type    | Mandatory| Description                      |
| --------------- | -------- | ---- | -------------------------- |
| bundleToBackup | string | Yes  | Name of the application to back up.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| string | Application information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';
  import backup from '@ohos.file.backup';

  function getBackupInfo() {
    try {
      let backupApp = "com.example.hiworld";
      let result = backup.getBackupInfo(backupApp);
      console.info('getBackupInfo success, result: ' + result);
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getBackupInfo failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## backup.updateTimer

updateTimer(bundleName: string, timeout: number): void;

Called after **onBundleBegin** and before **onBundleEnd** to set the backup or restore timer.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type    | Mandatory| Description                      |
| --------------- | -------- | ---- | -------------------------- |
| bundleName | string | Yes  | Name of the application, for which you want to set the backup or restore duration.|
| timeout | number | Yes  | Maximum backup or restore duration, in ms.<br>Value range: [0, 14400000]|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| boolean | A Boolean value indicating whether the backup or restore timeout is set successfully.|

**Error codes**

| ID| Error Message               |
| -------- | ----------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | The input parameter is invalid. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import backup form '@ohos.file.backup';

  function updateTimer() {
    try {
      let timeout = 30000;
      let bundleName = "com.example.hiworld";
      let result = backup.updateTimer(bundleName, timeout);
      if (result) {
        console.info('updateTimer success');
      } else {
        console.info('updateTimer fail');
      }
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('updateTimer failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## backup.updateSendRate

updateSendRate(bundleName: string, sendRate: number): boolean;

Called after **onBundleBegin** and before **onBundleEnd** to update the send rate.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type    | Mandatory| Description                      |
| --------------- | -------- | ---- | -------------------------- |
| bundleName|string | Yes  | Name of the target application.
| sendRate | number | Yes  | Send rate to set, in file descriptors (FDs) per second.<br>Value range: 0 to 800<br>Default value: 60 FDs/second<br>The value **0** means to stop transmission. If the value is greater than **800**, the send rate is 800 FDs/second.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| boolean | A Boolean value indicating whether the send rate is set successfully.|

**Error codes**

| ID| Error Message               |
| -------- | ----------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | The input parameter is invalid. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import backup form '@ohos.file.backup';

  function updateSendRate() {
    try {
      let bundleName = "com.example.myApp";
      let sendRate = 300;
      let result = backup.updateSendRate(bundleName, sendRate);
      if (result) {
        console.info('updateSendRate success');
      } else {
        console.info('updateSendRate fail');
      }
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('updateSendRate failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## SessionBackup

Provides a backup process object to support the application backup process. Before using the APIs of this class, you need to create a **SessionBackup** instance.

### constructor

constructor(callbacks: GeneralCallbacks);

A constructor used to create a **SessionBackup** instance.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                                 | Mandatory| Description                |
| -------- | ------------------------------------- | ---- | -------------------- |
| callback | [GeneralCallbacks](#generalcallbacks) | Yes  | Callbacks to be invoked during the backup process.|

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // Create a backup process.
  ```

### appendBundles

appendBundles(bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

Appends the applications whose data needs to be backed up. Currently, the obtained **SessionBackup** instance can be called only once in the entire backup process. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type                     | Mandatory| Description                        |
| --------------- | ------------------------- | ---- | ---------------------------- |
| bundlesToBackup | string[]                  | Yes  | Array of the application names to append.  |
| callback        | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // Create a backup process.
  try {
    let backupApps: Array<string> = [
      "com.example.hiworld",
    ];
    sessionBackup.appendBundles(backupApps, (err: BusinessError) => {
      if (err) {
        console.error('appendBundles failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('appendBundles success');
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
  }
  ```

### appendBundles

appendBundles(bundlesToBackup: string[], infos?: string[]): Promise&lt;void&gt;

Appends the applications whose data needs to be backed up. Currently, the obtained **SessionBackup** instance can be called only once in the entire backup process. This API uses a promise to return the result.

From API version 12, the optional parameter **infos** is added to carry information about each application to be backed up. The mappings between **infos** and **bundlesToBackup** are identified by index.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type    | Mandatory| Description                      |
| --------------- | -------- | ---- | -------------------------- |
| bundlesToBackup | string[] | Yes  | Array of the application names to append.|
| infos           | string[] | No  | Array of the information about each application to be backed up. The mappings between **infos** and **bundlesToBackup** are identified by index. This parameter is supported since API version 12.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // Create a backup process.
  async function appendBundles() {
    try {
      let backupApps: Array<string> = [
        "com.example.hiworld",
        "com.example.myApp"
      ];
      await sessionBackup.appendBundles(backupApps);
      console.info('appendBundles success');
      // Application information is carried. In the following, infos, details, and type are fixed parameters.
      let infos: Array<string> = [
        `
        {
        "infos": [
            {
                "details": [
                    {
                        "detail": [
                            {
                                "key1": "value1",
                                "key2": "value2"
                            }
                        ]
                    }
                ],
                "type": "unicast",
                "bundleName": "com.example.hiworld"
            }
        ]
    },
    {
        "infos": [
            {
                "details": [
                    {
                        "detail": [
                            {
                                "key1": "value1",
                                "key2": "value2"
                            }
                        ]
                    }
                ],
                "type": "unicast",
                "bundleName": "com.example.myApp"
            }
        ]
    }
      `
    ]
      await sessionBackup.appendBundles(backupApps, infos);
      console.info('appendBundles success');
    } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### release<sup>12+</sup>

release(): Promise&lt;void&gt;

Releases the backup session when the backup process is complete. This API disconnects the application from the backup and restore service and exits the service. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                                                                                      |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900042 | Unknown error                                                                                  |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionBackup = new backup.SessionBackup(generalCallbacks); // Create a backup process.
  async function release() {
    try {
      await sessionBackup.release();
      console.info('release success');
    } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('release failed with err: ' + JSON.stringify(err));
    }
  }
  ```

## SessionRestore

Provides an object to support the application restore process. Before using the APIs of this class, you need to create a **SessionRestore** instance.

### constructor

constructor(callbacks: GeneralCallbacks);

A constructor used to create a **SessionRestore** instance.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                                 | Mandatory| Description                |
| -------- | ------------------------------------- | ---- | -------------------- |
| callback | [GeneralCallbacks](#generalcallbacks) | Yes  | Callbacks to be invoked during the data restore process.|

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
  ```

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

Appends the applications whose data needs to be restored. Currently, the obtained **SessionRestore** instance can be called only once in the entire restore process.

> **NOTE**
>
> - During the data restore, the capability file needs to be verified.
> - Therefore, **remoteCapabilitiesFd** can be obtained by using the [getLocalCapabilities](#backupgetlocalcapabilities) API provided by the backup service. You can modify the parameters based on the actual situation of your application. You can also use the JSON file example provided by **getLocalCapabilities** to generate a capability file.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name              | Type                     | Mandatory| Description                              |
| -------------------- | ------------------------- | ---- | ---------------------------------- |
| remoteCapabilitiesFd | number                    | Yes  | FD of the file containing the capabilities to be restored.|
| bundlesToBackup      | string[]                  | Yes  | Array of the application names to append.        |
| callback             | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
  async function appendBundles() {
    let fileData : backup.FileData = {
      fd : -1
    }
    try {
      fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      let restoreApps: Array<string> = [
        "com.example.hiworld",
      ];
      sessionRestore.appendBundles(fileData.fd, restoreApps, (err: BusinessError) => {
        if (err) {
          console.error('appendBundles failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('appendBundles success');
      });
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    } finally {
      fs.closeSync(fileData.fd);
    }
  }
  ```

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], infos?: string[]): Promise&lt;void&gt;

Appends the applications whose data needs to be restored. From API version 12, the optional parameter **infos** is added to carry information about each application to be restored. The mappings between **infos** and **bundlesToBackup** are identified by index.
Currently, the obtained **SessionRestore** instance can be called only once in the entire restore process. This API uses a promise to return the result.

> **NOTE**
>
> - During the data restore, the capability file needs to be verified.
> - You can use [getLocalCapabilities](#backupgetlocalcapabilities) to obtain **remoteCapabilitiesFd**,
    and modify the parameters based on the application to be restored. You can also use the JSON file example provided by **getLocalCapabilities** to generate a capability file.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name              | Type    | Mandatory| Description                              |
| -------------------- | -------- | ---- | ---------------------------------- |
| remoteCapabilitiesFd | number   | Yes  | FD of the file containing the capabilities to be restored.|
| bundlesToBackup      | string[] | Yes  | Array of the application names to append.      |
| infos<sup>12+</sup>  | string[] | No  | Array of the information about each application to be restored. The mappings between **infos** and **bundlesToBackup** are identified by index. This parameter is supported since API version 12.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900005 | I/O error               |
| 13900011 | Out of memory           |
| 13900020 | Invalid argument        |
| 13900025 | No space left on device |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
  async function appendBundles() {
    let fileData : backup.FileData = {
      fd : -1
    }
    try {
      fileData = await backup.getLocalCapabilities();
      console.info('getLocalCapabilities success');
      let restoreApps: Array<string> = [
        "com.example.hiworld",
      ];
      await sessionRestore.appendBundles(fileData.fd, restoreApps);
      console.info('appendBundles success');
      // Information of the applications to restore.
      let infos: Array<string> = [
        `
         {
          "infos":[
            {
              "details": [
                {
                  "detail": [
                    {
                      "source": "com.example.hiworld", // Old bundle name of the application.
                      "target": "com.example.helloworld" // New bundle name of the application.
                    }
                  ],
                  "type": "app_mapping_relation"
                }
              ],
              "type":"broadcast"
            }
          ]
         }
        `
      ]
      await sessionRestore.appendBundles(fileData.fd, restoreApps, infos);
      console.info('appendBundles success');
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getLocalCapabilities failed with err: ' + JSON.stringify(err));
    } finally {
      fs.closeSync(fileData.fd);
    }
  }
  ```

### getFileHandle

getFileHandle(fileMeta: FileMeta, callback: AsyncCallback&lt;void&gt;): void

Obtains the handle of the shared file from the service. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This interface is part of the zero-copy feature, which reduces unnecessary memory copies and increases transmission efficiency. For details about the zero-copy methods, see the zero-copy APIs such as [fs.copyFile](js-apis-file-fs.md#fscopyfile) provided by [@ohos.file.fs](js-apis-file-fs.md).
> - Before using **getFileHandle**, you need to obtain a **SessionRestore** instance and add the applications with data to be restored by using **appendBundles**.
> - You can use **onFileReady** to obtain the file handle. When file operations are completed at the client, you need to use **publishFile** to publish the file.
> - **getFileHandle** can be called multiple times based on the number of files to be restored.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| fileMeta | [FileMeta](#filemeta)     | Yes  | Metadata of the file to restore.              |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
  let fileMeta: backup.FileMeta = {
    bundleName: "com.example.hiworld",
    uri: "test.txt"
  }
  sessionRestore.getFileHandle(fileMeta, (err: BusinessError) => {
    if (err) {
      console.error('getFileHandle failed with err: ' + JSON.stringify(err));
    }
    console.info('getFileHandle success');
  });
  ```

### getFileHandle

getFileHandle(fileMeta: FileMeta): Promise&lt;void&gt;

Obtains the handle of the shared file from the service. This API uses a promise to return the result.

> **NOTE**
>
> - This interface is part of the zero-copy feature, which reduces unnecessary memory copies and increases transmission efficiency. For details about the zero-copy methods, see the zero-copy APIs such as [fs.copyFile](js-apis-file-fs.md#fscopyfile) provided by [@ohos.file.fs](js-apis-file-fs.md).
> - Before using **getFileHandle**, you need to obtain a **SessionRestore** instance and add the applications with data to be restored by using **appendBundles**.
> - You can use **onFileReady** to obtain the file handle. When file operations are completed at the client, you need to use **publishFile** to publish the file.
> - **getFileHandle** can be called multiple times based on the number of files to be restored.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| fileMeta | [FileMeta](#filemeta) | Yes  | Metadata of the file to restore.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
  async function getFileHandle() {
    try {
      let fileMeta: backup.FileMeta = {
        bundleName: "com.example.hiworld",
        uri: "test.txt"
      }
      await sessionRestore.getFileHandle(fileMeta);
      console.info('getFileHandle success');
    } catch (error) {
      let err: BusinessError = error as BusinessError;
      console.error('getFileHandle failed with err: ' + JSON.stringify(err));
    }
  }
  ```

### publishFile

publishFile(fileMeta: FileMeta, callback: AsyncCallback&lt;void&gt;): void

Publishes **FileMeta** to the backup service to indicate that the file content is ready. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This interface is part of the zero-copy feature, which reduces unnecessary memory copies and increases transmission efficiency. For details about the zero-copy methods, see the zero-copy APIs such as [fs.copyFile](js-apis-file-fs.md#fscopyfile) provided by [@ohos.file.fs](js-apis-file-fs.md).
> - After the server returns a file handle through **onFileReady**, the client can copy data to the file corresponding to the file handle provided by the server through zero-copy operations.
> - This API can be called only after the caller has written all the data to be restored. The caller must ensure the consistency and integrity of the data to be written.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                     | Mandatory| Description                        |
| -------- | ------------------------- | ---- | ---------------------------- |
| fileMeta | [FileMeta](#filemeta)     | Yes  | Metadata of the file to restore.            |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let g_session: backup.SessionRestore;
  let initMap = new Map<string, number>();
  let testFileNum = 123; // Number of files required for the restore.
  let testBundleName = 'com.example.myapplication'; // Test bundle name.
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // Initialize the number of files written.
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        countMap[file.bundleName]++; // Update the number of files written.
        // Called only when the number of files to be restored is the same as the number of files actually written. This ensures data consistency and integrity.
        if (countMap[file.bundleName] == initMap[file.bundleName]) { // Trigger publishFile when all the files of each package are received.
          let fileMeta: backup.FileMeta = {
            bundleName: file.bundleName,
            uri: ''
          }
          g_session.publishFile(fileMeta, (err: BusinessError) => {
            if (err) {
              console.error('publishFile failed with err: ' + JSON.stringify(err));
              return;
            }
            console.info('publishFile success');
          });
        }
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
      },
      onProcess: (bundleName: string, process: string) => {
       console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
      }
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
    return sessionRestore;
  }
  g_session = createSessionRestore();
  ```

### publishFile

publishFile(fileMeta: FileMeta): Promise&lt;void&gt;

Publishes **FileMeta** to the backup service to indicate that the file content is ready. This API uses a promise to return the result.

> **NOTE**
>
> - This interface is part of the zero-copy feature, which reduces unnecessary memory copies and increases transmission efficiency. For details about the zero-copy methods, see the zero-copy APIs such as [fs.copyFile](js-apis-file-fs.md#fscopyfile) provided by [@ohos.file.fs](js-apis-file-fs.md).
> - After the server returns a file handle through **onFileReady**, the client can copy data to the file corresponding to the file handle provided by the server through zero-copy operations.
> - This API can be called only after the caller has written all the data to be restored. The caller must ensure the consistency and integrity of the data to be written.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                 | Mandatory| Description            |
| -------- | --------------------- | ---- | ---------------- |
| fileMeta | [FileMeta](#filemeta) | Yes  | Metadata of the file to restore.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message               |
| -------- | ----------------------- |
| 13600001 | IPC error               |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument        |
| 13900042 | Unknown error           |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let g_session: backup.SessionRestore;
  let initMap = new Map<string, number>();
  let testFileNum = 123; // Number of files required for the restore.
  let testBundleName = 'com.example.myapplication'; // Test bundle name.
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // Initialize the number of files written.
  async function publishFile(file: backup.FileMeta) {
    let fileMeta: backup.FileMeta = {
      bundleName: file.bundleName,
      uri: ''
    }
    await g_session.publishFile(fileMeta);
  }
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        countMap[file.bundleName]++; // Update the number of files written.
        // Called only when the number of files to be restored is the same as the number of files actually written. This ensures data consistency and integrity.
        if (countMap[file.bundleName] == initMap[file.bundleName]) { // Trigger publishFile when all the files of each package are received.
          publishFile(file);
        }
        console.info('publishFile success');
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
      },
      onProcess: (bundleName: string, process: string) => {
        console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
      }
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
    return sessionRestore;
  }
  g_session = createSessionRestore();
  ```

### release<sup>12+</sup>

release(): Promise&lt;void&gt;

Releases the restore session when the restore process is complete. This API disconnects the application from the backup and restore service and exits the service. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                                                                                      |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900042 | Unknown error                                                                                  |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let g_session: backup.SessionRestore;
  let initMap = new Map<string, number>();
  let testFileNum = 123; // Number of files required for the restore.
  let testBundleName = 'com.example.myapplication'; // Test bundle name.
  initMap.set(testBundleName, testFileNum);
  let countMap = new Map<string, number>();
  countMap.set(testBundleName, 0); // Initialize the number of files written.
  function createSessionRestore() {
    let generalCallbacks: backup.GeneralCallbacks = {
      onFileReady: (err: BusinessError, file: backup.File) => {
        if (err) {
          console.error('onFileReady failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onFileReady success');
        fs.closeSync(file.fd);
        countMap[file.bundleName]++; // Update the number of files written.
        // Called only when the number of files to be restored is the same as the number of files actually written. This ensures data consistency and integrity.
        if (countMap[file.bundleName] == initMap[file.bundleName]) { // Trigger publishFile when all the files of each package are received.
          let fileMeta: backup.FileMeta = {
            bundleName: file.bundleName,
            uri: ''
          }
          g_session.publishFile(fileMeta, (err: BusinessError) => {
            if (err) {
              console.error('publishFile failed with err: ' + JSON.stringify(err));
              return;
            }
            console.info('publishFile success');
          });
        }
      },
      onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
          return;
        }
        console.info('onBundleBegin success');
      },
      onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
        if (err) {
          console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
          return;
        }
        console.info('onBundleEnd success');
      },
      onAllBundlesEnd: (err: BusinessError) => {
        if (err) {
          console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
          return;
        }
        console.info('onAllBundlesEnd success');
      },
      onBackupServiceDied: () => {
        console.info('service died');
      },
      onResultReport: (bundleName: string, result: string) => {
        console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
      },
      onProcess: (bundleName: string, process: string) => {
        console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
      }
    };
    let sessionRestore = new backup.SessionRestore(generalCallbacks); // Create a restore process.
    return sessionRestore;
  }
  g_session = createSessionRestore();
  g_session.release();
  console.info('release success');
  ```

## IncrementalBackupSession<sup>12+</sup>

An object used to implement the incremental backup of applications. Before using the APIs of this class, you need to create an **IncrementalBackupSession** instance.

### constructor<sup>12+</sup>

constructor(callbacks: GeneralCallbacks);

A constructor used to create an **IncrementalBackupSession** instance.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                                 | Mandatory| Description                    |
| -------- | ------------------------------------- | ---- | ------------------------ |
| callback | [GeneralCallbacks](#generalcallbacks) | Yes  | Callbacks to be invoked during the incremental backup process.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                                                                                      |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // Create a session for an incremental backup.
  ```

### appendBundles<sup>12+</sup>

appendBundles(bundlesToBackup: Array&lt;IncrementalBackupData&gt;): Promise&lt;void&gt;

Appends applications that require incremental backup. In the current process, **appendBundles** can be called before **Release()** is called. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type                                                          | Mandatory| Description                      |
| --------------- | -------------------------------------------------------------- | ---- | -------------------------- |
| bundlesToBackup | Array&lt;[IncrementalBackupData](#incrementalbackupdata12)&gt; | Yes  | Array of applications that require incremental backup.|

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                                                                                      |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900011 | Out of memory                                                                                  |
| 13900020 | Invalid argument                                                                               |
| 13900025 | No space left on device                                                                        |
| 13900042 | Unknown error                                                                                  |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // Create a session for an incremental backup.
  let incrementalBackupData: backup.IncrementalBackupData = {
    bundleName: "com.example.hiworld",
    lastIncrementalTime: 1700107870, // Timestamp of the last backup.
    manifestFd:1 // FD of the manifest file of the last backed.
  }
  let incrementalBackupDataArray: backup.IncrementalBackupData[] = [incrementalBackupData];
  incrementalBackupSession.appendBundles(incrementalBackupDataArray).then(() => {
    console.info('appendBundles success');
  }).catch((err: BusinessError) => {
    console.error('appendBundles failed with err: ' + JSON.stringify(err));
  }); // Appends the applications that require incremental backup.
  ```

### release<sup>12+</sup>

release(): Promise&lt;void&gt;

Releases the session for the incremental backup. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Type               | Description                   |
| ------------------- | ----------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message                                                                                      |
| -------- | ---------------------------------------------------------------------------------------------- |
| 201      | Permission verification failed, usually the result returned by VerifyAccessToken.              |
| 202      | Permission verification failed, application which is not a system application uses system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verifcation faild|
| 13600001 | IPC error                                                                                      |
| 13900001 | Operation not permitted                                                                        |
| 13900005 | I/O error                                                                                      |
| 13900020 | Invalid argument                                                                               |
| 13900042 | Unknown error                                                                                  |

**Example**

  ```ts
  import fs from '@ohos.file.fs';
  import { BusinessError } from '@ohos.base';

  let generalCallbacks: backup.GeneralCallbacks = {
    onFileReady: (err: BusinessError, file: backup.File) => {
      if (err) {
        console.error('onFileReady failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err: BusinessError<string|void>, bundleName: string) => {
      if (err) {
        console.error('onBundleBegin failed with err.code: ' + JSON.stringify(err.code) + err.data);
        return;
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err: BusinessError) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    },
    onResultReport: (bundleName: string, result: string) => {
      console.info('onResultReport success, bundleName: ' + bundleName +'result: ' + result);
    },
    onProcess: (bundleName: string, process: string) => {
      console.info('onProcess success, bundleName: ' + bundleName +'process: ' + process);
    }
  };
  let incrementalBackupSession = new backup.IncrementalBackupSession(generalCallbacks); // Create a session for an incremental backup.
  incrementalBackupSession.release(); // End the incremental backup process.
  console.info('release success');
  ```
