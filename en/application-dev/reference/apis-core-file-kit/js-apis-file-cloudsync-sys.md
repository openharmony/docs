# @ohos.file.cloudSync (Device-Cloud Sync) (System API)

The **cloudSync** module provides the device-cloud sync capabilities for applications. You can use the APIs to start or stop device-cloud sync and start or stop the download of images.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.cloudSync (Device-Cloud Sync Capability)](js-apis-file-cloudsync.md).

## Modules to Import

```ts
import cloudSync from '@ohos.file.cloudSync';
```

## SyncState

Enumerates the device-cloud sync states.

> **NOTE**
>
> If a sync progress event listener is registered for an application, a callback will be invoked to notify the application when the device-cloud sync state is changed.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| UPLOADING |  0 | Uploading.|
| UPLOAD_FAILED |  1 | Upload failed.|
| DOWNLOADING |  2 | Downloading.|
| DOWNLOAD_FAILED |  3 | Download failed.|
| COMPLETED |  4 | Sync completed.|
| STOPPED |  5 | Sync stopped.|

## ErrorType

Enumerates the device-cloud sync errors.

- Currently, **NETWORK_UNAVAILABLE** is returned only when both the mobile network and Wi-Fi are unavailable during sync. If either network is available, sync can be performed normally.
- During the sync process, if the battery level is lower than 15% in non-charging scenarios, **BATTERY_LEVEL_LOW** will be return when the current upload is complete; if the battery level is lower than 10% in non-charging scenarios, **BATTERY_LEVEL_WARNING** will be returned when the current upload is complete.
- When sync is being triggered, if the battery level is lower than 15% in non-charging scenarios, sync is not allowed and an error code will be returned by **start()**.
- If the cloud space is insufficient when a file is uploaded, the upload will fail and there is no such a file in the cloud. 
- If the local space is insufficient when a file is downloaded, the download will fail. After the local space is released, the file will be downloaded again when sync starts.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | No error.|
| NETWORK_UNAVAILABLE |  1 | No network is available.|
| WIFI_UNAVAILABLE |  2 | Wi-Fi is unavailable.|
| BATTERY_LEVEL_LOW |  3 | The battery level is lower than 15%.|
| BATTERY_LEVEL_WARNING |  4 | The battery level is lower than 10%.|
| CLOUD_STORAGE_FULL |  5 | The cloud space is insufficient.|
| LOCAL_STORAGE_FULL |  6 | The local space is insufficient.|
| DEVICE_TEMPERATURE_TOO_HIGH<sup>12+</sup> |  7 | The device temperature is too high.|

## SyncProgress

Represents information about the device-cloud sync progress.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| state | [SyncState](#syncstate) | Yes  | Device-cloud sync state.|
| error | [ErrorType](#errortype) | Yes  | Sync error.|

## GallerySync

Provides APIs to implement device-cloud sync of media assets in **Gallery**. Before using the APIs of **GallerySync**, you need to create a **GallerySync** instance.

### constructor

constructor()

A constructor used to create a **GallerySync** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Example**

  ```ts
  let gallerySync = new cloudSync.GallerySync()
  ```

### on

on(evt: 'progress', callback: (pg: SyncProgress) => void): void

Registers a listener for the device-cloud sync progress.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | (pg: SyncProgress) => void | Yes  | Callback used to return the sync progress event. The input parameter is [SyncProgress](#syncprogress), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.on('progress', (pg: cloudSync.SyncProgress) => {
    console.info("syncState: " + pg.state);
  });
  ```

### off

off(evt: 'progress', callback: (pg: SyncProgress) => void): void

Unregisters a listener for the device-cloud sync progress.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | (pg: SyncProgress) => void | Yes  | Callback to unregister. The input parameter is [SyncProgress](#syncprogress), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let gallerySync = new cloudSync.GallerySync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("gallery sync state: " + pg.state + "error type:" + pg.error);
  }

  gallerySync.on('progress', callback);

  gallerySync.off('progress', callback);
  ```

### off

off(evt: 'progress'): void

Unregisters all listeners for the device-cloud sync progress.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.on('progress', (pg: cloudSync.SyncProgress) => {
      console.info("syncState: " + pg.state);
  });

  gallerySync.off('progress');
  ```

### start

start(): Promise&lt;void&gt;

Starts device-cloud sync. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 22400001 | Cloud status not ready. |
| 22400002 | Network unavailable. |
| 22400003  | Battery level warning. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.on('progress', (pg: cloudSync.SyncProgress) => {
	  console.info("syncState: " + pg.state);
  });

  gallerySync.start().then(() => {
	  console.info("start sync successfully");
  }).catch((err: BusinessError) => {
	  console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start

start(callback: AsyncCallback&lt;void&gt;): void

Starts device-cloud sync. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 22400001 | Cloud status not ready. |
| 22400002 | Network unavailable. |
| 22400003  | Battery level warning. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.start((err: BusinessError) => {
    if (err) {
      console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start sync successfully");
    }
  });
  ```

### stop

stop(): Promise&lt;void&gt;

Stops device-cloud sync. This API uses a promise to return the result.

> **NOTE**
>
> Calling **stop** will stop the sync process. To resume the sync, call [start](#start).

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop().then(() => {
	  console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
	  console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop

stop(callback: AsyncCallback&lt;void&gt;): void

Stops device-cloud sync. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Calling **stop** will stop the sync process. To resume the sync, call [start](#start).

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop((err: BusinessError) => {
    if (err) {
      console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

## Download

Provides APIs for downloading image files to **Gallery**. Before using the APIs of **Download**, you need to create a **Download** instance.

### constructor

constructor()

A constructor used to create a **Download** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Example**

  ```ts
  let download = new cloudSync.Download()
  ```

### on

on(evt: 'progress', callback: (pg: DownloadProgress) => void): void

Registers a listener for the download progress of a cloud file.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Event. The value is **progress**, which indicates the download progress event of a cloud file.|
| callback | (pg: DownloadProgress) => void | Yes  | Callback used to return the file download progress. The input parameter is [DownloadProgress](js-apis-file-cloudsync.md#downloadprogress11), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let download = new cloudSync.Download();

  download.on('progress', (pg: cloudSync.DownloadProgress) => {
    console.info("download state: " + pg.state);
  });
  ```

### off

off(evt: 'progress', callback: (pg: DownloadProgress) => void): void

Unregisters a listener for the download progress of a cloud file.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | (pg: DownloadProgress) => void | Yes  | Callback used to return the file download progress. The input parameter is [DownloadProgress](js-apis-file-cloudsync.md#downloadprogress11), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let download = new cloudSync.Download();

  let callback = (pg: cloudSync.DownloadProgress) => {
    console.info("download state: " + pg.state);
  }

  download.on('progress', callback);

  download.off('progress', callback);
  ```

### off

off(evt: 'progress'): void

Unregisters all listeners for the download progress event of a cloud file.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Event type. The value is **progress**, which indicates the download progress event of a cloud file.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**Example**

  ```ts
  let download = new cloudSync.Download();

  download.on('progress', (pg: cloudSync.DownloadProgress) => {
      console.info("download state:" + pg.state);
  });

  download.off('progress');
  ```

### start

start(uri: string): Promise&lt;void&gt;

Starts to download a cloud file. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.on('progress', (pg: cloudSync.DownloadProgress) => {
	  console.info("download state:" + pg.state);
  });

  download.start(uri).then(() => {
	  console.info("start download successfully");
  }).catch((err: BusinessError) => {
	  console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

### start

start(uri: string, callback: AsyncCallback&lt;void&gt;): void

Starts to download a cloud file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.start(uri, (err: BusinessError) => {
    if (err) {
      console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start download successfully");
    }
  });
  ```

### stop

stop(uri: string): Promise&lt;void&gt;

Stops downloading a cloud file. This API uses a promise to return the result.

> **NOTE**
>
> Calling **stop** will terminate the download of the current file and clear the cache file. You can use **start** to start the download again.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri).then(() => {
	  console.info("stop download successfully");
  }).catch((err: BusinessError) => {
	  console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop

stop(uri: string, callback: AsyncCallback&lt;void&gt;): void

Stops downloading a cloud file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Calling **stop** will terminate the download of the current file and clear the cache file. You can use **start** to start the download again.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri, (err: BusinessError) => {
    if (err) {
      console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop download successfully");
    }
  });
  ```

## FileSync<sup>11+</sup>

Provides APIs for the file manager application to perform device-cloud sync of the files stored in the Drive Kit. Before using the APIs of this class, you need to create a **FileSync** instance.

### constructor<sup>11+</sup>

constructor()

A constructor used to create a **FileSync** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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

### constructor<sup>12+</sup>

constructor(bundleName: string)

A constructor used to create a **FileSync** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| bundleName | string | Yes  | Application bundle name.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**Example**

  ```ts
  let fileSync = new cloudSync.FileSync("com.ohos.demo")
  ```

### on<sup>11+</sup>

on(event: 'progress', callback: Callback\<SyncProgress>): void

Registers a listener for the device-cloud sync progress.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| event | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | Callback\<[SyncProgress](#syncprogress)> | Yes  | Callback used to return the sync progress information.|

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

### off<sup>11+</sup>

off(event: 'progress', callback?: Callback\<SyncProgress>): void

Unregisters a listener for the device-cloud sync progress.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| event | string | Yes  | Event type. The value is **progress**, which indicates the sync progress event.|
| callback | Callback\<[SyncProgress](#syncprogress)> |  No  | Callback for the sync progress event.|

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

### start<sup>11+</sup>

start(): Promise&lt;void&gt;

Starts device-cloud sync of a file in the Drive Kit. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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
| 22400003  | Battery level warning. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
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

### start<sup>11+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

Starts device-cloud sync of a file in the Drive Kit. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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
| 22400003  | Battery level warning. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let fileSync = new cloudSync.FileSync();

  fileSync.start((err: BusinessError) => {
    if (err) {
      console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start sync successfully");
    }
  });
  ```

### stop<sup>11+</sup>

stop(): Promise&lt;void&gt;

Stops device-cloud sync of the file in the Drive Kit. This API uses a promise to return the result.

Calling **stop** will stop the sync process. To resume the sync, call [start](#start).

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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
  import { BusinessError } from '@ohos.base';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop().then(() => {
	  console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
	  console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop<sup>11+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

Stops device-cloud sync of the file in the Drive Kit. This API uses an asynchronous callback to return the result.

Calling **stop** will stop the sync process. To resume the sync, call [start](#start).

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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
  import { BusinessError } from '@ohos.base';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop((err: BusinessError) => {
    if (err) {
      console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

### getLastSyncTime<sup>11+</sup>

getLastSyncTime(): Promise&lt;number&gt;

Obtains the last sync time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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
  import { BusinessError } from '@ohos.base';
  let fileSync = new cloudSync.FileSync();

  fileSync.getLastSyncTime().then((timeStamp: number) => {
    let date = new Date(timeStamp);
    console.info("get last sync time successfully:"+ date);
  }).catch((err: BusinessError) => {
	  console.error("get last sync time failed with error message: " + err.message + ", error code: " + err.code);
  });

  ```

### getLastSyncTime<sup>11+</sup>

getLastSyncTime(callback: AsyncCallback&lt;number&gt;): void;

Obtains the last sync time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

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
  import { BusinessError } from '@ohos.base';
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

### cleanCache<sup>11+</sup>

cleanCache(uri: string): void;

Deletes a cache file. This API returns the result synchronously.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the cache file to delete.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002  | No such file or directory. |
| 14000002  | Invalid uri. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fileUri from '@ohos.file.fileuri';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  try {
    fileCache.cleanCache(uri);
  } catch (err) {
    let error:BusinessError = err as BusinessError;
    console.error("clean cache failed with error message: " + err.message + ", error code: " + err.code);
  } 

  ```

## cloudSync.getFileSyncState<sup>11+</sup>

getFileSyncState(uri: Array&lt;string&gt;): Promise&lt;Array&lt;FileSyncState&gt;&gt;

Obtains the file sync state. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | Array&lt;string&gt; | Yes  | URI of the file whose sync state is to be obtained.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;Array&lt;FileSyncState&gt;&gt; | Promise used to return the sync state obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002  | No such file or directory. |
| 14000002  | Invalid uri. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  let uris: Array<string> = ["file://uri"];
  cloudSync.getFileSyncState(uris).then(function(syncStates: Array<cloudSync.FileSyncState>) {
    for(let i = 0, len = syncStates.length; i < len; i++){
        console.info("get file sync state successfully" + syncStates[i]);
    }
  }).catch((err: BusinessError) => {
	  console.error("get file sync state failed with error message: " + err.message + ", error code: " + err.code);
  });

  ```

## cloudSync.getFileSyncState<sup>11+</sup>

getFileSyncState(uri: Array&lt;string&gt;, callback: AsyncCallback&lt;Array&lt;FileSyncState&gt;&gt;): void

Obtains the file sync state. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | Array&lt;string&gt; | Yes  | URI of the file whose sync state is to be obtained.|
| callback | AsyncCallback&lt;Array&lt;FileSyncState&gt;&gt; | Yes  | Callback used to return the file sync state.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002  | No such file or directory. |
| 14000002  | Invalid uri. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';

  let uris: Array<string> = ["file://uri"];
  cloudSync.getFileSyncState(uris, (err: BusinessError, syncStates: Array<cloudSync.FileSyncState>) => {
    if (err) {
      console.error("get file sync state with error message: " + err.message + ", error code: " + err.code);
    } else {
      for(let i = 0, len = syncStates.length; i < len; i++){
        console.info("get file sync state successfully" + syncStates[i]);
    }
    }
  });
  ```

## cloudSync.getFileSyncState<sup>12+</sup>

getFileSyncState(uri: string): FileSyncState

Obtains the file sync status.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the target file.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| [FileSyncState](#filesyncstate11) | Sync status of the file.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900002  | No such file or directory. |
| 13900004  | Interrupted system call. |
| 13900010  | Try again. |
| 13900012  | Permission denied by the file system. |
| 13900031  | Function not implemented. |
| 13900042  | Unknown error. |
| 14000002  | Invalid uri. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  import fileUri from '@ohos.file.fileuri';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  try {
    let state = fileSync.getFileSyncState(uri)
  }.catch(err) {
    let error:BusinessError = err as BusinessError;
    console.error("getFileSyncStatefailed with error:" + JSON.stringify(error));
  }
  ```

## cloudSync.registerChange<sup>12+</sup>

registerChange(uri: string, recursion: boolean, callback: Callback&lt;ChangeData&gt;): void

Subscribes to the change of a file.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the target file.|
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
| 14000002  | Invalid uri. |

**Example**

  ```ts
  import fileUri from '@ohos.file.fileuri';
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

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the target file.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900001  | Operation not permitted. |
| 13900002  | No such file or directory. |
| 13900012  | Permission denied. |
| 14000002  | Invalid uri. |

**Example**

  ```ts
  import fileUri from '@ohos.file.fileuri';
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

**System API**: This is a system API.

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| NOTIFY_ADDED |  0 | A file is created.|
| NOTIFY_MODIFIED |  1 | The file is modified.|
| NOTIFY_DELETED |  2 | The file is deleted.|
| NOTIFY_RENAMED |  3 | The file is renamed or moved.|

## ChangeData<sup>12+</sup>

Represents the data change information.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| type | [NotifyType](#notifytype12) | Yes  | Type of the data change.|
| isDirectory | Array&lt;boolean&gt; | Yes  | Whether the URIs with data changed are of folders.|
| uris | Array&lt;string&gt; | Yes  | URIs of the files changed.|

## FileSyncState<sup>11+</sup>

Enumerates the device-cloud file sync states.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| UPLOADING |  0 | The file is being uploaded.|
| DOWNLOADING |  1 | The file is being downloaded.|
| COMPLETED |  2 | The file sync is complete.|
| STOPPED |  3 | The file sync is stopped.|
| TO_BE_UPLOADED<sup>12+</sup> |  4 | The file is to be uploaded.|
| UPLOAD_SUCCESS<sup>12+</sup> |  5 | The file is uploaded successfully.|
| UPLOAD_FAILURE<sup>12+</sup> |  6 | The upload fails.|
