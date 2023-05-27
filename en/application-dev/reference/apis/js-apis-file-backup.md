# @ohos.file.backup (Backup and Restoration)

The **file.backup** module provides APIs for backing up and restoring data for applications.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import backup from '@ohos.file.backup';
```

## FileMeta

Defines a file metadata object, which includes the application name and file URI. **FileMeta** is an indispensable object for data backup and restoration.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name      | Type  | Mandatory| Description   |
| ---------- | ------ | ---- | ------------------------- |
| bundleName | string | Yes  | Bundle name of the application, which can be obtained by using the method provided by [bundle.BundleInfo](js-apis-bundle-BundleInfo.md).                 |
| uri        | string | Yes  | Name of the file in the application sandbox.<br>Currently, the URI has not been upgraded to the standard format. It can consist of digits (0–9), letters (a–z and A–Z), underscores (_), and period (.) only.|

## FileData

Defines a file data object, which includes the file descriptor (FD) of the file opened. **FileData** is an indispensable object for data backup and restoration.

> **NOTE**
>
> The **FileData** must be closed after being used. Otherwise, memory leakage may occur. For details about how to close a **FileData** object, see [fs.closeSync](js-apis-file-fs.md#fsclosesync) provided by [@ohos.file.fs](js-apis-file-fs.md).

**System capability**: SystemCapability.FileManagement.StorageService.Backup

| Name| Type  | Mandatory| Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| fd   | number | Yes  | FD, which can be obtained through the backup service.|

## File

Defines a file object, which
inherits from [FileMeta](#filemeta) and [FileData](#filedata).

> **NOTE**
>
> **file.backup.File** is different from [File](js-apis-file-fs.md#file) provided in @ohos.file.fs. The former is an object that inherits from [FileMeta](#filemeta) and [FileData](#filedata), while the latter has only one FD object. Pay attention to the difference between them.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

## GeneralCallbacks

Provides general callbacks invoked during the backup or restoration process. The backup service uses these callbacks to notify the client of the backup/restoration phase of the application.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

### onFileReady

onFileReady : AsyncCallback&lt;File&gt;

Called when the server sends a file to the client. If the file is sent successfully, **err** is **undefined**. Otherwise, **err** is an error object.

> **NOTE**
>
> The **File** returned by **AsyncCallback** is the file.backup.[File](#file). The returned file belongs to the backup service. Once the file is closed, the backup service shall clear the resources used by the file. However, the client must close the file handle first.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  import fs from '@ohos.file.fs';
  onFileReady: (err, file) => {
    if (err) {
      console.error('onFileReady failed with err: ' + err);
    }
    console.info('onFileReady success with file: ' + file.bundleName + ' ' + file.uri);
    fs.closeSync(file.fd);
  }
  ```

### onBundleBegin

onBundleBegin : AsyncCallback&lt;string&gt;

 Called when the backup or restoration of an application begins. If the backup or restoration begins, **err** is undefined. Otherwise, **err** is an error object.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  onBundleBegin: (err, bundleName) => {
    if (err) {
      console.error('onBundleBegin failed with err: ' + err);
    }
    console.info('onBundleBegin success with bundleName: ' + bundleName);
  }
  ```

### onBundleEnd

onBundleEnd : AsyncCallback&lt;string&gt;

Called when the backup or restoration of an application ends. If the backup or restoration ends successfully, **err** is undefined. Otherwise, **err** is an error object.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  onBundleEnd: (err, bundleName) => {
    if (err) {
      console.error('onBundleEnd failed with err: ' + err);
    }
    console.info('onBundleEnd success with bundleName: ' + bundleName);
  }
  ```

### onAllBundlesEnd

onAllBundlesEnd : AsyncCallback&lt;undefined&gt;

Called when the backup or restoration of all bundles ends. If the backup or restoration of all bundles ends, **err** is **undefined**. Otherwise, **err** is an error object.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  onAllBundlesEnd: (err) => {
    if (err) {
      console.error('onAllBundlesEnd failed with err: ' + err);
    }
    console.info('onAllBundlesEnd success');
  }
  ```

### onBackupServiceDied

onBackupServiceDied : Callback&lt;undefined&gt;

Called when the backup service is suspended.

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Example**

  ```js
  onBackupServiceDied: () => {
    console.info('onBackupServiceDied success');
  }
  ```

## backup.getLocalCapabilities

getLocalCapabilities(callback: AsyncCallback&lt;FileData&gt;): void

Obtains a JSON file that describes local capabilities. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                  | Mandatory| Description                 |
| -------- | ------------------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;[FileData](#filedata)&gt; | Yes  | Callback invoked to return the result. If the file is obtained, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  import fs from '@ohos.file.fs';
  try {
    backup.getLocalCapabilities((err, fileData) => {
      if (err) {
        console.error('getLocalCapabilities failed with err: ' + err);
      }
      console.info('getLocalCapabilities success');
      fs.closeSync(fileData.fd);
    });
  } catch (err) {
    console.error('getLocalCapabilities failed with err: ' + err);
  }
  ```

The following is an example of the file obtained:

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
  "deviceType" : "phone",
  "systemFullName" : "OpenHarmony-4.0.0.0"
 }
 ```

## backup.getLocalCapabilities

getLocalCapabilities(): Promise&lt;FileData&gt;

Obtains a JSON file that describes local capabilities. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Return value**

| Type            | Description                    |
| -------------------- | ------------------ |
| Promise&lt;[FileData](#filedata)&gt; | Promise used to return the **FileData** of the JSON file obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  import fs from '@ohos.file.fs';
  try {
    let fileData = await backup.getLocalCapabilities();
    console.info('getLocalCapabilities success');
    fs.closeSync(fileData.fd);
  } catch (err) {
    console.error('getLocalCapabilities failed with err: ' + err);
  }
  ```

  The following is an example of the file obtained:

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
  "deviceType" : "phone",
  "systemFullName" : "OpenHarmony-4.0.0.0"
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

  ```js
  import fs from '@ohos.file.fs';
  let sessionBackup = new backup.SessionBackup({
    onFileReady: (err, file) => {
      if (err) {
        console.error('onFileReady failed with err: ' + err);
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err, bundleName) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + err);
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err, bundleName) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + err);
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + err);
      }
      console.info('onAllBundlesEnd success');
    },
    onBackupServiceDied: () => {
      console.info('service died');
    }
  });
  ```

### appendBundles

appendBundles(bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

Appends the applications whose data needs to be backed up. Currently, the obtained **SessionBackup** instance can be called only once in the entire backup process. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type                     | Mandatory| Description                                                          |
| --------------- | ------------------------- | ---- | -------------------------------------------------------------- |
| bundlesToBackup | string[]                  | Yes  | Array of the application names to append.                                     |
| callback        | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the applications are appended successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    sessionBackup.appendBundles(['com.example.hiworld'], (err) => {
      if (err) {
        console.error('appendBundles failed with err: ' + err);
      }
      console.info('appendBundles success');
    });
  } catch (err) {
    console.error('appendBundles failed with err: ' + err);
  }
  ```

### appendBundles

appendBundles(bundlesToBackup: string[]): Promise&lt;void&gt;

Appends the applications whose data needs to be backed up. Currently, the obtained **SessionBackup** instance can be called only once in the entire backup process. This API uses a promise to return the result.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name         | Type    | Mandatory| Description                      |
| --------------- | -------- | ---- | -------------------------- |
| bundlesToBackup | string[] | Yes  | Array of the application names to append.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    await sessionBackup.appendBundles(['com.example.hiworld']);
    console.info('appendBundles success');
  } catch (err) {
    console.error('appendBundles failed with err: ' + err);
  }
  ```

## SessionRestore

Provides a restoration process object to support the data restoration process of applications. Before using the APIs of this class, you need to create a **SessionRestore** instance.

### constructor

constructor(callbacks: GeneralCallbacks);

A constructor used to create a **SessionRestore** instance.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                                 | Mandatory| Description                |
| -------- | ------------------------------------- | ---- | -------------------- |
| callback | [GeneralCallbacks](#generalcallbacks) | Yes  | Callbacks to be invoked during the data restoration process.|

**Example**

  ```js
  import fs from '@ohos.file.fs';
  let sessionRestore = new backup.SessionRestore({
    onFileReady: (err, file) => {
      if (err) {
        console.error('onFileReady failed with err: ' + err);
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
    },
    onBundleBegin: (err, bundleName) => {
      if (err) {
        console.error('onBundleBegin failed with err: ' + err);
      }
      console.info('onBundleBegin success');
    },
    onBundleEnd: (err, bundleName) => {
      if (err) {
        console.error('onBundleEnd failed with err: ' + err);
      }
      console.info('onBundleEnd success');
    },
    onAllBundlesEnd: (err) => {
      if (err) {
        console.error('onAllBundlesEnd failed with err: ' + err);
      }
      console.info('onAllBundlesEnd success');
    },
    onRestoreServiceDied: () => {
      console.info('service died');
    }
  });
  ```

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[], callback: AsyncCallback&lt;void&gt;): void

Appends the applications whose data needs to be restored. Currently, the obtained **SessionRestore** instance can be called only once in the entire restoration process. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - During the data restoration, the capability file needs to be verified.
> - Therefore, **remoteCapabilitiesFd** can be obtained by using the [getLocalCapabilities](#backupgetlocalcapabilities) API provided by the backup service. You can modify the parameters based on the actual situation of your application. You can also use the JSON file example provided by **getLocalCapabilities** to generate a capability file.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name              | Type                     | Mandatory| Description                                                          |
| -------------------- | ------------------------- | ---- | -------------------------------------------------------------- |
| remoteCapabilitiesFd | number                    | Yes  | FD of the file containing the capabilities to be restored.                            |
| bundlesToBackup      | string[]                  | Yes  | Array of the application names to append.                                    |
| callback             | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the applications are appended successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    let fileData = await backup.getLocalCapabilities();
    console.info('getLocalCapabilities success');
    sessionRestore.appendBundles(fileData.fd, ['com.example.hiworld'], (err) => {
      if (err) {
        console.error('appendBundles failed with err: ' + err);
      }
      console.info('appendBundles success');
    });
  } catch (err) {
    console.error('appendBundles failed with err: ' + err);
  }
  ```

### appendBundles

appendBundles(remoteCapabilitiesFd: number, bundlesToBackup: string[]): Promise&lt;void&gt;

Appends the applications whose data needs to be restored. Currently, the obtained **SessionRestore** instance can be called only once in the entire restoration process. This API uses a promise to return the result.

> **NOTE**
>
> - During the data restoration, the capability file needs to be verified.
> - Therefore, **remoteCapabilitiesFd** can be obtained by using the [getLocalCapabilities](#backupgetlocalcapabilities) API provided by the backup service. You can modify the parameters based on the actual situation of your application. You can also use the JSON file example provided by **getLocalCapabilities** to generate a capability file.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name              | Type    | Mandatory| Description                              |
| -------------------- | -------- | ---- | ---------------------------------- |
| remoteCapabilitiesFd | number   | Yes  | FD of the file containing the capabilities to be restored.|
| bundlesToBackup      | string[] | Yes  | Array of the application names to append.      |

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900005 | I/O error |
| 13900011 | Out of memory |
| 13900020 | Invalid argument |
| 13900025 | No space left on device |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    let fileData = await backup.getLocalCapabilities();
    console.info('getLocalCapabilities success');
    await sessionRestore.appendBundles(fileData.fd, ['com.example.hiworld']);
    console.info('appendBundles success');
  } catch (err) {
    console.error('appendBundles failed with err: ' + err);
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

| Name  | Type                     | Mandatory| Description                                                          |
| -------- | ------------------------- | ---- | -------------------------------------------------------------- |
| fileMeta | [FileMeta](#filemeta)     | Yes  | Metadata of the file to restore.                                            |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the file handle is obtained, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    sessionRestore.getFileHandle({
      bundleName: "com.example.hiworld",
      uri: "test.txt"
      }, (err, file) => {
      if (err) {
        console.error('getFileHandle failed with err: ' + err);
      }
      console.info('getFileHandle success');
    });
  } catch (err) {
    console.error('getFileHandle failed with err: ' + err);
  }
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

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    await sessionRestore.getFileHandle({
      bundleName: "com.example.hiworld",
      uri: "test.txt"
      });
    console.info('getFileHandle success');
  } catch (err) {
    console.error('getFileHandle failed with err: ' + err);
  }
  ```

### publishFile

publishFile(fileMeta: FileMeta, callback: AsyncCallback&lt;void&gt;): void

Publishes **FileMeta** to the backup service to indicate that the file content is ready. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This interface is part of the zero-copy feature, which reduces unnecessary memory copies and increases transmission efficiency. For details about the zero-copy methods, see the zero-copy APIs such as [fs.copyFile](js-apis-file-fs.md#fscopyfile) provided by [@ohos.file.fs](js-apis-file-fs.md).
> - After the server returns a file handle through **onFileReady**, the client can copy data to the file corresponding to the file handle provided by the server through zero-copy operations.
> - After the copy is complete, you can use **publishFile** to notify the backup service that the file is ready.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                     | Mandatory| Description                                                      |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| fileMeta | [FileMeta](#filemeta)     | Yes  | Metadata of the file to restore.                                          |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the file is published successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    onFileReady: (err, file) => {
      if (err) {
        console.error('onFileReady failed with err: ' + err);
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
      sessionRestore.publishFile({
      bundleName: file.bundleName,
      uri: file.uri
      }, (err) => {
        if (err) {
          console.error('publishFile failed with err: ' + err);
        }
        console.info('publishFile success');
      });
    }
  } catch (err) {
    console.error('publishFile failed with err: ' + err);
  }
  ```

### publishFile

publishFile(fileMeta: FileMeta): Promise&lt;void&gt;

Publishes **FileMeta** to the backup service to indicate that the file content is ready. This API uses a promise to return the result.

> **NOTE**
>
> - This interface is part of the zero-copy feature, which reduces unnecessary memory copies and increases transmission efficiency. For details about the zero-copy methods, see the zero-copy APIs such as [fs.copyFile](js-apis-file-fs.md#fscopyfile) provided by [@ohos.file.fs](js-apis-file-fs.md).
> - After the server returns a file handle through **onFileReady**, the client can copy data to the file corresponding to the file handle provided by the server through zero-copy operations.
> - After the copy is complete, you can use **publishFile** to notify the backup service that the file is ready.

**Required permissions**: ohos.permission.BACKUP

**System capability**: SystemCapability.FileManagement.StorageService.Backup

**Parameters**

| Name  | Type                 | Mandatory| Description            |
| -------- | --------------------- | ---- | ---------------- |
| fileMeta | [FileMeta](#filemeta) | Yes  | Metadata of the file to restore.|

**Return value**

| Type               | Description                                  |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).
| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error |
| 13900001 | Operation not permitted |
| 13900020 | Invalid argument |
| 13900042 | Unknown error |

**Example**

  ```js
  try {
    onFileReady: (err, file) => {
      if (err) {
        console.error('onFileReady failed with err: ' + err);
      }
      console.info('onFileReady success');
      fs.closeSync(file.fd);
      await sessionRestore.publishFile({
      bundleName: file.bundleName,
      uri: file.uri
      });
      console.info('publishFile success');
    },
  } catch (err) {
    console.error('publishFile failed with err: ' + err);
  }
  ```
