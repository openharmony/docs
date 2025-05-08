# @ohos.file.cloudSync (Device-Cloud Synchronization)

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
| processed | number | Yes  | Size of the data downloaded.|
| size | number | Yes  | Size of the cloud file.|
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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
| callback | Callback\<[SyncProgress](#syncprogress12)> |  No  | Callback used to return the sync progress information.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

A constructor used to create a **CloudFileCache** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Error codes**

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

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

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |
| 14000002 | Invalid uri. |

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |
| 14000002 | Invalid uri. |

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

### stop<sup>11+</sup>

stop(uri: string, needClean?: boolean): Promise&lt;void&gt;

Stops downloading a file from the Drive Kit to the local device. This API uses a promise to return the result.

Calling **stop** will terminate the download of the current file and clear the cache file. You can use **start** to start the download again.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| needClean<sup>12+</sup> | boolean | No  | Whether to delete the downloaded files. The default value **false** means to delete the downloaded files; the value **true** means the opposite.<br>This parameter is available since API version 12.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

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

Calling **stop** will terminate the download of the current file and clear the cache file. You can use **start** to start the download again.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

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

## cloudSync.registerChange<sup>12+</sup>

registerChange(uri: string, recursion: boolean, callback: Callback&lt;ChangeData&gt;): void

Subscribes to the change of a file.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| recursion | boolean | Yes  | Whether to subscribe to the change of the sub-folders and files of the given URI. The value **true** means to subscribe to the change of the sub-folders and files of the given URI; the value **false** means to subscribe to only the change of the given URI.|
| callback | Callback&lt;[ChangeData](#changedata12)&gt; | Yes  | Callback used to return the changed data.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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
  let onCallback1 = (changeData: ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // Unregister the listener.
  cloudSync.unRegisterChange(uri);
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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
  let onCallback1 = (changeData: ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // Unregister the listener.
  cloudSync.unRegisterChange(uri);
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
| isDirectory | Array&lt;boolean&gt; | Yes  | Whether the URIs with data changed are of folders.|
| uris | Array&lt;string&gt; | Yes  | URIs of the files changed.|
