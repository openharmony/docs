# @ohos.file.cloudSync (Device-Cloud Synchronization)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @zsyztt; @Hermits; @reminder2352-->
<!--SE: @yunlanying-->
<!--TSE: @liuhonggang123-->

The **cloudSync** module provides the device-cloud synchronization capabilities for applications. You can use the APIs to start or stop device-cloud synchronization and start or stop the download of images.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { cloudSync } from '@kit.CoreFileKit';
```
## SyncState<sup>12+</sup>

Enumerates the device-cloud sync states.

> **NOTE**
>
> If a sync progress event listener is registered for an application, a callback will be invoked to notify the application when the device-cloud sync state is changed.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| UPLOADING |  0 | The file is being uploaded.|
| UPLOAD_FAILED |  1 | Upload failed.|
| DOWNLOADING |  2 | The file is being downloaded.|
| DOWNLOAD_FAILED |  3 | Download failed.|
| COMPLETED |  4 | Sync completed.|
| STOPPED |  5 | Sync stopped.|

## ErrorType<sup>12+</sup>

Enumerates the device-cloud sync errors.

- In the current phase, **NETWORK_UNAVAILABLE** is returned only when the mobile data network and Wi-Fi are unavailable. If the mobile data network is available, the synchronization can be performed normally.
- During the sync process, if the battery level is lower than 10% in non-charging scenarios, **BATTERY_LEVEL_LOW** will be return when the current upload is complete.
- When sync is being triggered, if the battery level is lower than 10% in non-charging scenarios, sync is not allowed and an error code will be returned by **start()**.
- If the cloud space is insufficient when a file is uploaded, the upload will fail and there is no such a file in the cloud.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | No error.|
| NETWORK_UNAVAILABLE |  1 | No network is available.|
| WIFI_UNAVAILABLE |  2 | Wi-Fi is unavailable.|
| BATTERY_LEVEL_LOW |  3 | The battery level is lower than 10%.|
| BATTERY_LEVEL_WARNING |  4 | The battery level is lower than 15%.|
| CLOUD_STORAGE_FULL |  5 | The cloud space is insufficient.|
| LOCAL_STORAGE_FULL |  6 | The local space is insufficient.|
| DEVICE_TEMPERATURE_TOO_HIGH |  7 | The device temperature is too high.|

## SyncProgress<sup>12+</sup>

Represents information about the device-cloud sync progress.

### Property

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| state | [SyncState](#syncstate12) | Yes  | Device-cloud sync state.|
| error | [ErrorType](#errortype12) | Yes  | Sync error.|

## State<sup>11+</sup>

Enumerates the download states of a cloud file.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| RUNNING |  0 | The cloud file is being downloaded.|
| COMPLETED |  1 | The cloud file download is complete.|
| FAILED |  2 | The cloud file download failed.|
| STOPPED |  3 | The cloud file download is stopped.|

## DownloadProgress<sup>11+</sup>

Represents information about the download progress of a cloud file.

### Property

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| state | [State](#state11) | Yes  | File download state.|
| processed | number | Yes  | Size of the downloaded data, in bytes. The value range is [0, 9223372036854775807].|
| size | number | Yes  | Size of the cloud file, in bytes. The value range is [0, 9223372036854775807].|
| uri | string | Yes  | URI of the cloud file.|
| error | [DownloadErrorType](#downloaderrortype11) | Yes  | Download error type.|

## FileSync<sup>12+</sup>

Provides APIs for the file manager application to perform device-cloud sync of the files stored in the Drive Kit. Before using the APIs of this class, you need to create a **FileSync** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

### constructor<sup>12+</sup>

constructor()

A constructor used to create a **FileSync** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |

**Example**

  ```ts
  let fileSync = new cloudSync.FileSync()
  ```

### on<sup>12+</sup>

on(event: 'progress', callback: Callback\<SyncProgress>): void

Registers a listener for the device-cloud sync progress.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| event | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | Callback\<[SyncProgress](#syncprogress12)> | Yes  | Callback used to return the sync progress information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let fileSync = new cloudSync.FileSync();
  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state: " + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);
  ```

### off<sup>12+</sup>

off(event: 'progress', callback?: Callback\<SyncProgress>): void

Unregisters all listeners for the device-cloud sync progress.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| event | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | Callback\<[SyncProgress](#syncprogress12)> |  No  | Callback used to return the sync progress. The default value is null.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let fileSync = new cloudSync.FileSync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state: " + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);

  fileSync.off('progress', callback);
  ```

### start<sup>12+</sup>

start(): Promise&lt;void&gt;

Starts device-cloud sync of a file in the Drive Kit. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |
| 22400001  | Cloud status not ready. |
| 22400002  | Network unavailable. |
| 22400003  | Low battery level. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state: " + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);

  fileSync.start().then(() => {
    console.info("start sync successfully");
  }).catch((err: BusinessError) => {
    console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start<sup>12+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

Starts device-cloud sync of a file in the Drive Kit. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 22400001  | Cloud status not ready. |
| 22400002  | Network unavailable. |
| 22400003  | Low battery level. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.start((err: BusinessError) => {
    if (err) {
      console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start sync successfully");
    }
  });
  ```

### stop<sup>12+</sup>

stop(): Promise&lt;void&gt;

Stops device-cloud sync of the file in the Drive Kit. This API uses a promise to return the result.

Calling **stop** will stop the sync process. To resume the sync, call [start](#start12).

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop().then(() => {
    console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
    console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop<sup>12+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

Stops device-cloud sync of the file in the Drive Kit. This API uses an asynchronous callback to return the result.

Calling **stop** will stop the sync process. To resume the sync, call [start](#start12).

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop((err: BusinessError) => {
    if (err) {
      console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

### getLastSyncTime<sup>12+</sup>

getLastSyncTime(): Promise&lt;number&gt;

Obtains the last sync time. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | Promise used to return the last sync time obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.getLastSyncTime().then((timeStamp: number) => {
    let date = new Date(timeStamp);
    console.info("get last sync time successfully:"+ date);
  }).catch((err: BusinessError) => {
    console.error("get last sync time failed with error message: " + err.message + ", error code: " + err.code);
  });

  ```

### getLastSyncTime<sup>12+</sup>

getLastSyncTime(callback: AsyncCallback&lt;number&gt;): void

Obtains the last sync time. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the last sync time obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.getLastSyncTime((err: BusinessError, timeStamp: number) => {
    if (err) {
      console.error("get last sync time with error message: " + err.message + ", error code: " + err.code);
    } else {
      let date = new Date(timeStamp);
      console.info("get last sync time successfully:"+ date);
    }
  });
  ```

## CloudFileCache<sup>11+</sup>

Provides APIs for the file manager application to download files from the Drive Kit to a local device.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

### construct<sup>11+</sup>

constructor()

A constructor used to create a **CloudFileCache** instance. Data is not shared between multiple instances.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |

**Example**

  ```ts
  let fileCache = new cloudSync.CloudFileCache();
  ```

### on<sup>11+</sup>

on(event: 'progress', callback: Callback\<DownloadProgress>): void

Registers a listener for the download progress of a file from the Drive Kit.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| event | string | Yes  | Event. The value is **progress**, which indicates the download progress event of a cloud file.|
| callback | Callback\<[DownloadProgress](#downloadprogress11)> | Yes  | Callback for the download progress event of a file from the Drive Kit.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileCache = new cloudSync.CloudFileCache();
  let callback = (pg: cloudSync.DownloadProgress) => {
    console.info("download state: " + pg.state);
  };

  try {
    fileCache.on('progress', callback);
  } catch (e) {
    const error = e as BusinessError;
    console.error(`Error code: ${error.code}, message: ${error.message}`);
  }
  ```

### on<sup>20+</sup>

on(event: 'batchDownload', callback: Callback&lt;MultiDownloadProgress&gt;): void

Registers a listener for the batch download of a file from the Drive Kit.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name  | Type                                                             | Mandatory| Description                                                         |
| -------- | ----------------------------------------------------------------- | ---- | ------------------------------------------------------------- |
| event    | string                                                            | Yes  | Event type. The value is **'batchDownload'**, indicating the batch download event.|
| callback | Callback&lt;[MultiDownloadProgress](#multidownloadprogress20)&gt; | Yes  | Callback for the batch download event of a file from the Drive Kit.                               |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 13900020 | Invalid argument. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileCache = new cloudSync.CloudFileCache();
  let callback = (data: cloudSync.MultiDownloadProgress) => {
    console.info(`Batch download progress: downloadedSize: ${data.downloadedSize}, totalSize: ${data.totalSize}`);
    if (data.state == cloudSync.State.COMPLETED) {
      console.info('Batch download finished.');
    } else if (data.state == cloudSync.State.FAILED) {
      console.info(`Batch download stopped, error type: ${data.errType}.`);
    }
  };

  try {
    fileCache.on('batchDownload', callback);
  } catch (e) {
    let error = e as BusinessError;
    console.error(`Failed to register download callback, error code: ${error.code}, message: ${error.message}`);
  }
  ```

### off<sup>11+</sup>

off(event: 'progress', callback?: Callback\<DownloadProgress>): void

Unregisters a listener for the download progress of a file from the Drive Kit.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| event | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | Callback\<[DownloadProgress](#downloadprogress11)> | No  | Callback for the download progress event of a file from the Drive Kit. If this parameter is not specified, this API unregisters all callbacks for the download progress event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileCache = new cloudSync.CloudFileCache();

  let callback = (pg: cloudSync.DownloadProgress) => {
    console.info("download state: " + pg.state);
  }

  try {
    fileCache.on('progress', callback);
    fileCache.off('progress', callback);
  } catch (e) {
    const error = e as BusinessError;
    console.error(`Error code: ${error.code}, message: ${error.message}`);
  }
  ```

### off<sup>20+</sup>

off(event: 'batchDownload', callback?: Callback&lt;MultiDownloadProgress&gt;): void

Unregisters a listener enabled by [on](#on20) for the batch download of a file from the Drive Kit.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name  | Type                                                             | Mandatory| Description                                                                                                   |
| -------- | ----------------------------------------------------------------- | ---- | ------------------------------------------------------------------------------------------------------- |
| event    | string                                                            | Yes  | Event type. The value is **'batchDownload'**, indicating the batch download event.                                      |
| callback | Callback&lt;[MultiDownloadProgress](#multidownloadprogress20)&gt; | No  | Callback for the batch download of a file from the Drive Kit. If this parameter is set, the specified callback will be canceled; otherwise, all currently subscribed callbacks of the same event type will be canceled.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 13900020 | Invalid argument. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileCache = new cloudSync.CloudFileCache();
  let callback = (pg: cloudSync.MultiDownloadProgress) => {
    console.info("download state: " + pg.state);
  }

  try {
    fileCache.on('batchDownload', callback);
    fileCache.off('batchDownload', callback);
  } catch (e) {
    let error = e as BusinessError;
    console.error(`Failed to unregister download callback, error code: ${error.code}, message: ${error.message}`);
  }
  ```

### start<sup>11+</sup>

start(uri: string): Promise&lt;void&gt;

Starts to download a file from the Drive Kit to the local device. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |
| 14000002 | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  try {
    fileCache.on('progress', (pg: cloudSync.DownloadProgress) => {
      console.info("download state:" + pg.state);
    });
  } catch (e) {
    const error = e as BusinessError;
    console.error(`Error code: ${error.code}, message: ${error.message}`);
  }

  fileCache.start(uri).then(() => {
    console.info("start download successfully");
  }).catch((err: BusinessError) => {
    console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start<sup>11+</sup>

start(uri: string, callback: AsyncCallback&lt;void&gt;): void

Starts to download a file from the Drive Kit to the local device. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |
| 14000002 | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileCache.start(uri, (err: BusinessError) => {
    if (err) {
      console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start download successfully");
    }
  });
  ```

### startBatch<sup>20+</sup>

startBatch(uris: Array&lt;string&gt;, fileType?: DownloadFileType): Promise&lt;number&gt;

Starts the batch download of a file from the Drive Kit. This API uses a promise to return the result.

Different batch download tasks can be distinguished by the task ID returned.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name  | Type                                   | Mandatory| Description                                                               |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------------- |
| uris     | Array&lt;string&gt;                     | Yes  | URI list. A maximum of 400 URIs can be transferred at a time. An error (22400004) will be thrown if the number of URIs exceeds 400.|
| fileType | [DownloadFileType](#downloadfiletype20) | No  | File type. The default value is **CONTENT**.                                    |

**Return value**

|         Type         |               Description                          |
| --------------------- | ------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the ID of the batch download task.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 13900020 | Invalid argument. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400004 | Exceed the maximum limit.                                                                                                                                                         |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileCache = new cloudSync.CloudFileCache();
  try {
    fileCache.on('batchDownload', (pg: cloudSync.MultiDownloadProgress) => {
      console.info(`batch download state: ${pg.state}`);
    });
  } catch (e) {
    let error = e as BusinessError;
    console.error(`Failed to unregister download callback, error code: ${error.code}, message: ${error.message}`);
  }

  let uriList: Array<string> = [];
  fileCache.startBatch(uriList, cloudSync.DownloadFileType.CONTENT).then((downloadId: number) => {
    console.info(`start batch download successfully, taskId: ${downloadId}`);
  }).catch((err: BusinessError) => {
    console.error(`start download failed with error message: ${err.message}, error code: ${err.code}`);
  });
  ```

### stop<sup>11+</sup>

stop(uri: string, needClean?: boolean): Promise&lt;void&gt;

Stops downloading a file from the Drive Kit to the local device. This API uses a promise to return the result.

When **stop()** is called, the current file download process terminates, and downloaded files are retained by default. You can call **start()** to resume the download.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| needClean<sup>12+</sup> | boolean | No  | Whether to delete the downloaded files. The default value **false** means not to delete the downloaded files; the value **true** means the opposite.<br>This parameter is available since API version 12.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 14000002 | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileCache.stop(uri, true).then(() => {
    console.info("stop download successfully");
  }).catch((err: BusinessError) => {
    console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop<sup>11+</sup>

stop(uri: string, callback: AsyncCallback&lt;void&gt;): void

Stops downloading a file from the Drive Kit to the local device. This API uses an asynchronous callback to return the result.

When **stop()** is called, the current file download process terminates, and downloaded files are retained. You can call **start()** to resume the download.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 14000002 | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileCache.stop(uri, (err: BusinessError) => {
    if (err) {
      console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop download successfully");
    }
  });
  ```

### stopBatch<sup>20+</sup>

stopBatch(downloadId: number, needClean?: boolean): Promise&lt;void&gt;

Stops the batch download task enabled by [startBatch](#startbatch20) of a file from the Drive Kit. This API uses a promise to return the result.

When **stopBatch()** is called, the batch download terminates. The **needClean** parameter determines whether to delete incompletely downloaded files.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type   | Mandatory| Description                                                             |
| ---------- | ------- | ---- | ----------------------------------------------------------------- |
| downloadId | number  | Yes  | ID of the download task to be stopped.                                           |
| needClean  | boolean | No  | Whether to delete incompletely downloaded files. The default value **false** means not to delete the files; the value **true** means the opposite.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service.                                                                                              |
| 13900020 | Invalid argument. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.                                                                     |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let taskId = -1;
  let uriList: Array<string> = [];
  let fileCache = new cloudSync.CloudFileCache();
  fileCache.startBatch(uriList, cloudSync.DownloadFileType.CONTENT).then((downloadId: number) => {
    taskId = downloadId;
    console.info("start batch download successfully");
  }).catch((err: BusinessError) => {
    console.error(`start batch download failed with error message: ${err.message}, error code: ${err.code}`);
  });

  let needStop = true;
  if (needStop && taskId > 0) {
    fileCache.stopBatch(taskId, true).then(() => {
      console.info("stop batch download successfully");
    }).catch((err: BusinessError) => {
      console.error(`stop batch download failed with error message: ${err.message}, error code: ${err.code}`);
    });
  }
  ```

## DownloadErrorType<sup>11+</sup>

Enumerates the device-cloud download error types.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | No error.|
| UNKNOWN_ERROR |  1 | Unknown error.|
| NETWORK_UNAVAILABLE |  2 | The network is unavailable.|
| LOCAL_STORAGE_FULL |  3 | The local space is insufficient.|
| CONTENT_NOT_FOUND |  4 | The file is not found in the cloud space.|
| FREQUENT_USER_REQUESTS |  5 | The user requests are too frequent to respond.|

## DownloadFileType<sup>20+</sup>

Enumerates the download file types from the Drive Kit.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name     | Value | Description               |
| --------- | --- | ------------------- |
| CONTENT   | 0   | Content file.  |
| THUMBNAIL | 1   | Thumbnail file.|
| LCD       | 2   | LCD file.      |

## FailedFileInfo<sup>20+</sup>

Represents a list of files that fail to be downloaded from the Drive Kit and failure causes.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name | Type                                     | Mandatory| Description                  |
| ----- | ----------------------------------------- | ---- | ---------------------- |
| uri   | string                                    | Yes  | URI of the file that fails to be downloaded.     |
| error | [DownloadErrorType](#downloaderrortype11) | Yes  | Error type of the file download failure.|


## MultiDownloadProgress<sup>20+</sup>

Represents the batch download progress of a file from the Drive Kit.

### Property

| Name           | Type                                     | Read-Only| Optional| Description                                                                                              |
| --------------- | ----------------------------------------- | ---- | ---- | -------------------------------------------------------------------------------------------------- |
| state           | [State](#state11)                         | No  | No  | Execution state of the batch download.                                                                            |
| taskId          | number                                    | No  | No  | ID of a batch download task. The value ranges from 0 to INT64_MAX. If the progress is abnormal, the value **-1** is returned.                                      |
| successfulCount | number                                    | No  | No  | Number of successfully downloaded files. The value ranges from 0 to 400. If the progress is abnormal, the value **-1** is returned.                                          |
| failedCount     | number                                    | No  | No  | Number of files that fail to be downloaded. The value ranges from 0 to 400. If the progress is abnormal, the value **-1** is returned.                                  |
| totalCount      | number                                    | No  | No  | Total number of files. The value ranges from 0 to 400. If the progress is abnormal, the value **-1** is returned.                                          |
| downloadedSize  | number                                    | No  | No  | Size of the downloaded file, in bytes. The value range is [0, INT64_MAX). If the progress is abnormal, the value **INT64_MAX** is returned.           |
| totalSize       | number                                    | No  | No  | Total size of the files to be downloaded, in bytes. The value range is [0, INT64_MAX). If the progress is abnormal, the value **INT64_MAX** is returned.|
| errType         | [DownloadErrorType](#downloaderrortype11) | No  | No  | Type of the error returned when the batch download fails.|

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

### getFailedFiles<sup>20+</sup>

getFailedFiles(): Array&lt;FailedFileInfo&gt;

Obtains the list of files that fail to be downloaded in batches.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Return value**

| Type                                            | Description                                               |
| ------------------------------------------------ | --------------------------------------------------- |
| Array&lt;[FailedFileInfo](#failedfileinfo20)&gt; | List of file URIs that fail to be downloaded and the corresponding error types.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let taskId = -1;
  let failedList: Array<cloudSync.FailedFileInfo> = [];
  let fileCache = new cloudSync.CloudFileCache();
  let callback = (data: cloudSync.MultiDownloadProgress) => {
    console.info(`Batch download progress: downloadedSize: ${data.downloadedSize}, totalSize: ${data.totalSize}`);
    if (data.state == cloudSync.State.FAILED) {
      console.info(`Batch download stopped, error type: ${data.errType}.`);
      failedList = data.getFailedFiles();
    }
  };

  try {
    fileCache.on('batchDownload', callback);
  } catch (e) {
    let error = e as BusinessError;
    console.error(`Failed to register download callback, error code: ${error.code}, message: ${error.message}`);
  }

  let uriList: Array<string> = [];
  fileCache.startBatch(uriList, cloudSync.DownloadFileType.CONTENT).then((downloadId: number) => {
    taskId = downloadId;
    console.info("start batch download successfully");
  }).catch((err: BusinessError) => {
    console.error(`start batch download failed with error message: ${err.message}, error code: ${err.code}`);
  });
  ```

### getSuccessfulFiles<sup>20+</sup>

getSuccessfulFiles(): Array&lt;string&gt;

Obtains the list of files that are successfully downloaded in batches.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------- |
| Array&lt;string&gt; | List of URIs of the files that are successfully downloaded. The value is an array.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let finishedList: Array<string> = [];
  let fileCache = new cloudSync.CloudFileCache();
  let callback = (data: cloudSync.MultiDownloadProgress) => {
    console.info(`Batch download progress: downloadedSize: ${data.downloadedSize}, totalSize: ${data.totalSize}`);
    if (data.state == cloudSync.State.COMPLETED) {
      console.info(`Batch download stopped, error type: ${data.errType}.`);
      finishedList = data.getSuccessfulFiles();
    }
  };

  try {
    fileCache.on('batchDownload', callback);
  } catch (e) {
    const error = e as BusinessError;
    console.error(`Failed to register download callback, error code: ${error.code}, message: ${error.message}`);
  }

  let uriList: Array<string> = [];
  fileCache.startBatch(uriList, cloudSync.DownloadFileType.CONTENT).then((downloadId: number) => {
    console.info(`start batch download successfully, taskId: ${downloadId}`);
  }).catch((err: BusinessError) => {
    console.error(`start batch download failed with error message: ${err.message}, error code: ${err.code}`);
  });
  ```

## cloudSync.registerChange<sup>12+</sup>

registerChange(uri: string, recursion: boolean, callback: Callback&lt;ChangeData&gt;): void

Subscribes to the change of a file.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| recursion | boolean | Yes  | Whether to listen for the change of the URI, subfiles, and subdirectories. The value **true** means to listen for the change of the URI, subfiles, and subdirectories; the value **false** means to only listen for the change of the URI.|
| callback | Callback&lt;[ChangeData](#changedata12)&gt; | Yes  | Callback used to return the changed data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900001  | Operation not permitted. |
| 13900002  | No such file or directory. |
| 13900012  | Permission denied. |
| 14000002  | Invalid URI. |

**Example**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let onCallback1 = (changeData: cloudSync.ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // Unregister the listener.
  cloudSync.unregisterChange(uri);
  ```

## cloudSync.unregisterChange<sup>12+</sup>

unregisterChange(uri: string): void

Unsubscribes from the change of a file.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900001  | Operation not permitted. |
| 13900002  | No such file or directory. |
| 13900012  | Permission denied. |
| 14000002  | Invalid URI. |

**Example**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let onCallback1 = (changeData: cloudSync.ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // Unregister the listener.
  cloudSync.unregisterChange(uri);
  ```

## NotifyType<sup>12+</sup>

Enumerates the data change types.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| NOTIFY_ADDED |  0 | A file is created.|
| NOTIFY_MODIFIED |  1 | The file is modified.|
| NOTIFY_DELETED |  2 | The file is deleted.|
| NOTIFY_RENAMED |  3 | The file is renamed or moved.|

## ChangeData<sup>12+</sup>

Represents the data change information.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| type | [NotifyType](#notifytype12) | Yes  | Type of the data change.|
| isDirectory | Array&lt;boolean&gt; | Yes  | Whether the URIs with data changed are of directories. The value **true** means the URIs are of directories; the value **false** means the opposite.|
| uris | Array&lt;string&gt; | Yes  | List of URIs whose data needs to be changed.|


## HistoryVersion<sup>20+</sup>

Represents the historical version information of the device-cloud file when the [gethistoryversionlist](#gethistoryversionlist20) method of the [FileVersion](#fileversion20) class is called.

### Property

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name    | Type  | Description|
| ---------- | ------ | ---- |
| editedTime | number | Time when the file content is modified.|
| fileSize | number | File size in bytes.|
| versionId | string | File version.|
| originalFileName | string | File name of the current version.|
| sha256 | string | Hash value of the file content of the current version.|
| autoResolved | boolean | Whether the current version is the one where conflicts were automatically resolved.<br>When the application is set to manually resolve conflicts, **false** is returned by default, which is meaningless.<br>When the application is set to automatically resolve conflicts, the device side automatically resolves conflicts. The value **true** means conflicts exist in the current version and have been automatically resolved by the device-cloud service; the value **false** means no conflict exists and conflicts are not automatically resolved.|

**NOTE**<br>The current device-cloud sync provides an automatic conflict resolution mechanism for cases where a file is modified simultaneously on both the local device and another device. To enable users to manually resolve the conflict, add the **cloudkit_config.json** file to the **/entry/src/main/resources/base/profile** directory of the project and set **manualConflictResolutionEnable** to **true**. Otherwise, skip this step or set **manualConflictResolutionEnable** to **false**.

Example of configuring the **cloudkit_config.json** file:

  ```json
  {
    "cloudKitConfig": {
      "cloudFileSyncConfig": {
        "manualConflictResolutionEnable": "true"
      }
    }
  }
  ```

## VersionDownloadProgress<sup>20+</sup>

Represents the download state and progress information of historical version files when the [downloadHistoryVersion](#downloadhistoryversion20) method of the [FileVersion](#fileversion20) class is called.

### Property

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name| Type| Mandatory| Description|
| ---------- | ------ | ------ | ---- |
| state | [State](#state11) | Yes| Download state of the cloud file of the selected version.|
| progress | number | Yes| Download progress.|
| errType | [DownloadErrorType](#downloaderrortype11) | Yes| Type of the error that occurs when the download fails.|

## FileVersion<sup>20+</sup>

Represents the device-cloud file version management class. It allows you to manage historical versions of client-cloud files, obtain the list of historical versions, download historical versions to the local device, replace the current local file with a historical version file, and query and remove conflict flags for version conflicts.

### construct<sup>20+</sup>

constructor()

A constructor used to create a **FileVersion** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  let fileVersion = new cloudSync.FileVersion();
  ```

### getHistoryVersionList<sup>20+</sup>

getHistoryVersionList(uri: string, versionNumLimit: number): Promise&lt;Array&lt;HistoryVersion&gt;&gt;

Obtains the list of historical versions. The length of the returned list can be limited. If the number of cloud versions is less than the specified limit, the list will be returned with the actual number of versions. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  |  File URI.|
| versionNumLimit | number | Yes| Length limit of the historical version list.|

**Return value**

| Type | Description|
| ------ | ---- |
| Promise&lt;Array&lt;[HistoryVersion](#historyversion20)&gt;&gt; | Promise used to return the list of historical versions.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400002 | Network unavailable. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let limit = 10;

  fileVersion.getHistoryVersionList(uri, limit).then((versionList: Array<cloudSync.HistoryVersion>) => {
    for(let i = 0, len = versionList.length; i < len; i++) {
      console.info("get history versionId: " + versionList[i].versionId);
    }
  }).catch((err: BusinessError) => {
    console.error("get history version failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### downloadHistoryVersion<sup>20+</sup>

downloadHistoryVersion(uri: string, versionId: string, callback: Callback&lt;[VersionDownloadProgress](#versiondownloadprogress20)&gt;): Promise&lt;string&gt;

Obtains the content of a file of a specified version based on the version number. You can download a file of a specified version from the cloud to a temporary local path. The application determines whether to replace the original file with the temporary file, or retain or delete the temporary file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  |  File URI.|
| versionId | string | Yes| Version ID of a file. The format is returned by the [gethistoryversionlist](#gethistoryversionlist20) API.|
| callback | Callback&lt;[VersionDownloadProgress](#versiondownloadprogress20)&gt; | Yes| Callback for download progress.|

**Return value**

| Type | Description|
| ------ | ---- |
| Promise&lt;string&gt; | Promise used to return the URI of the temporary file of a historical version.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400002 | Network unavailable. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let versionId = '123456'; // The format returned by the getHistoryVersionList method is used as an example.

  let callback = (data: cloudSync.VersionDownloadProgress) => {
    if (data.state == cloudSync.State.RUNNING) {
      console.info("download progress: " + data.progress);
    } else if (data.state == cloudSync.State.FAILED) {
      console.info("download failed errType: " + data.errType);
    } else if (data.state == cloudSync.State.COMPLETED) {
      console.info("download version file success");
    }
  };

  fileVersion.downloadHistoryVersion(uri, versionId, callback).then((fileUri: string) => {
    console.info("success to begin download, downloadFileUri: " + fileUri);
  }).catch((err: BusinessError) => {
    console.error("download history version file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### replaceFileWithHistoryVersion<sup>20+</sup>

replaceFileWithHistoryVersion(originalUri: string, versionUri: string): Promise&lt;void&gt;

Replaces the local file with the file of a historical version. Before replacement, call the [downloadHistoryVersion](#downloadhistoryversion20) method to download the selected historical version and obtain its version URI. If this API is called directly without prior download or the version URI is invalid, an exception will be thrown. Once replacement is complete, the temporary file will be automatically deleted. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| originalUri | string | Yes  |  URI of the local file.|
| versionUri | string | Yes| URI of the historical file.|

**Return value**

| Type | Description|
| ------ | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900005 | I/O error. |
| 13900008 | Bad file descriptor. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |
| 22400007 | Version file not exist. |

**Example**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let versionId = '123456'; // The format returned by the getHistoryVersionList method is used as an example.

  let callback = (data: cloudSync.VersionDownloadProgress) => {
    if (data.state == cloudSync.State.RUNNING) {
      console.info("download progress: " + data.progress);
    } else if (data.state == cloudSync.State.FAILED) {
      console.info("download failed errType: " + data.errType);
    } else if (data.state == cloudSync.State.COMPLETED) {
      console.info("download version file success");
    }
  };

  let versionUri = "";
  fileVersion.downloadHistoryVersion(uri, versionId, callback).then((fileUri: string) => {
    versionUri = fileUri;
    console.info("success to begin download, downloadFileUri: " + fileUri);
  }).catch((err: BusinessError) => {
    console.error(`download history version file failed with error message: ${err.message}, error code: ${err.code}`);
  });
  fileVersion.replaceFileWithHistoryVersion(uri, versionUri).then(() => {
    console.info("replace file with history version success.");
  }).catch((err: BusinessError) => {
    console.error("replace file with history version filed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### isFileConflict<sup>20+</sup>

isFileConflict(uri: string): Promise&lt;boolean&gt;

Obtains the version conflict flag of a local file. This API uses a promise to return the result. This API takes effect only when the application is configured for manual conflict resolution. Otherwise, conflicts are automatically resolved during synchronization, and the return value will be **false**.

Once the application is configured for manual conflict resolution, calling this API returns whether the current local file conflicts with the cloud file. The application then prompts the user to handle the conflict. After the conflict is resolved, you need to call the [clearfileconflict](#clearfileconflict20) method to clear the conflict flag and synchronize the file to the cloud.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  |  File URI.|

**Return value**

| Type | Description|
| ------ | ---- |
| Promise&lt;boolean&gt; | Promise used to return the conflict flag between the local file and the cloud file. The value **true** indicates that the local file conflicts with the cloud file, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileVersion.isFileConflict(uri).then((isConflict: boolean) => {
    console.info("current file is conflict: " + isConflict);
  }).catch((err: BusinessError) => {
    console.error("get current file conflict flag failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### clearFileConflict<sup>20+</sup>

clearFileConflict(uri: string): Promise&lt;void&gt;

Clears the version conflict flag of the local file. If a conflict occurs, you need to call this API to clear the conflict flag after the conflict is resolved locally and trigger automatic synchronization. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  |  URI of the file for which the conflict flag is to be cleared.|

**Return value**

| Type | Description|
| ------ | ---- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**Example**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  let isConflict = false;
  fileVersion.isFileConflict(uri).then((isConflictRet: boolean) => {
    isConflict = isConflictRet;
    console.info("current file is conflict: " + isConflictRet);
  }).catch((err: BusinessError) => {
    console.error(`get current file conflict flag failed with error message: ${err.message}, error code: ${err.code}`);
  });
  fileVersion.clearFileConflict(uri).then(() => {
    console.info("clean file conflict flag success");
  }).catch((err: BusinessError) => {
    console.error("clean file conflict flag failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```
