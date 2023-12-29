# @ohos.file.cloudSync (Device-Cloud Synchronization)

The **cloudSync** module provides the device-cloud synchronization capabilities for applications. You can use the APIs to start or stop device-cloud synchronization and start or stop the download of images.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

## Modules to Import

```ts
import cloudSync from '@ohos.file.cloudSync';
```

## SyncState

Enumerates the device-cloud synchronization states.

> **NOTE**
>
> If a synchronization process event listener is registered for an application, a callback will be invoked to notify the application when any of the following states is changed.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| UPLOADING |  0 | Uploading.|
| UPLOAD_FAILED |  1 | Upload failed.|
| DOWNLOADING |  2 | Downloading.|
| DOWNLOAD_FAILED |  3 | Download failed.|
| COMPLETED |  4 | Synchronization completed.|
| STOPPED |  5 | Synchronization stopped.|

## ErrorType

Enumerates the device-cloud synchronization error types.

- Currently, **NETWORK_UNAVAILABLE** is returned only when both the mobile network and Wi-Fi are unavailable during synchronization. If either network is available, synchronization can be performed normally.
- During the synchronization process, if the battery level is lower than 15% in non-charging scenarios, **BATTERY_LEVEL_LOW** will be return when the current upload is complete; if the battery level is lower than 10% in non-charging scenarios, **BATTERY_LEVEL_WARNING** will be returned when the current upload is complete.
- When synchronization is triggered, if the battery level is lower than 15% in non-charging scenarios, synchronization is not allowed and an error code will be returned by **start()**.
- If the cloud space is insufficient when a file is uploaded, the upload will fail. 
- If the local space is insufficient when a file is downloaded, the download will fail. After the local space is released, the file will be downloaded again when synchronization starts.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | No error.|
| NETWORK_UNAVAILABLE |  1 | No network is available.|
| WIFI_UNAVAILABLE |  2 | Wi-Fi is unavailable.|
| BATTERY_LEVEL_LOW |  3 | The battery level is lower than 15%.|
| BATTERY_LEVEL_WARNING |  4 | The battery level is lower than 10%.|
| CLOUD_STORAGE_FULL |  5 | The cloud space is insufficient.|
| LOCAL_STORAGE_FULL |  6 | The local space is insufficient.|

## SyncProgress

Defines the device-cloud synchronization process.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| state | [SyncState](#syncstate) | Yes  | Device-cloud synchronization state.|
| error | [ErrorType](#errortype) | Yes  | Synchronization error type.|

## GallerySync

Provides APIs to implement device-cloud synchronization of media resources of the Gallery. Before using the APIs of **GallerySync**, you need to create a **GallerySync** instance.

### constructor

constructor()

A constructor used to create a **GallerySync** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Example**

  ```ts
  let gallerySync = new cloudSync.GallerySync()
  ```

### on

on(evt: 'progress', callback: (pg: SyncProgress) => void): void

Subscribes to the synchronization process event.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Type of the event to subscribe to. The value is **progress**, which indicates the synchronization process event.|
| callback | (pg: SyncProgress) => void | Yes  | Callback invoked to return the result. The input parameter is [SyncProgress](#syncprogress), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

Unsubscribes from the synchronization process event.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Type of the event to unsubscribe from. The value is **progress**, which indicates the synchronization process event.|
| callback | (pg: SyncProgress) => void | Yes  | Callback for the synchronization process event. The input parameter is [SyncProgress](#syncprogress), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

Unsubscribes from the synchronization process event.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Type of the event to unsubscribe from. The value is **progress**, which indicates the synchronization process event.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

Starts device-cloud synchronization. This API uses a promise to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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
	  console.info("start sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start

start(callback: AsyncCallback&lt;void&gt;): void

Starts device-cloud synchronization. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 22400001 | Cloud status not ready. |
| 22400002 | Network unavailable. |
| 22400003  | Battery level warning. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.start((err: BusinessError) => {
    if (err) {
      console.info("start sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start sync successfully");
    }
  });
  ```

### stop

stop(): Promise&lt;void&gt;

Stops device-cloud synchronization. This API uses a promise to return the result.

> **NOTE**
>
> Calling **stop** will stop the synchronization process. To resume the synchronization, call [start](#start).

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop().then(() => {
	  console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
	  console.info("stop sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop

stop(callback: AsyncCallback&lt;void&gt;): void

Stops device-cloud synchronization. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Calling **stop** will stop the synchronization process. To resume the synchronization, call [start](#start-1).

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let gallerySync = new cloudSync.GallerySync();

  gallerySync.stop((err: BusinessError) => {
    if (err) {
      console.info("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

## State

Enumerates the download states of a cloud file.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| RUNNING |  0 | The cloud file is being downloaded.|
| COMPLETED |  1 | The cloud file download is complete.|
| FAILED |  2 | The cloud file download failed.|
| STOPPED |  3 | The cloud file download is stopped.|

## DownloadProgress

Defines the download process of a cloud file.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| state | [State](#state) | Yes  | File download state.|
| processed | number | Yes  | Size of data downloaded.|
| size | number | Yes  | Current size of the file.|
| uri | string | Yes  | URI of the file.|

## Download

Provides APIs for downloading the image files in Gallery. Before using the APIs of **Download**, you need to create a **Download** instance.

### constructor

constructor()

A constructor used to create a **Download** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Example**

  ```ts
  let download = new cloudSync.Download()
  ```

### on

on(evt: 'progress', callback: (pg: DownloadProgress) => void): void

Subscribes to the cloud file download event.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Type of the event to subscribe to. The value is **progress**, which indicates the download process event.|
| callback | (pg: DownloadProgress) => void | Yes  | Callback invoked to return the result. The input parameter is [DownloadProgress](#downloadprogress), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

Unsubscribes from the cloud file download event.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Type of the event to unsubscribe from. The value is **progress**, which indicates the synchronization process event.|
| callback | (pg: DownloadProgress) => void | Yes  | Callback for the cloud file download event. The input parameter is [DownloadProgress](#downloadprogress), and the return value is **void**.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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

Unsubscribes from the cloud file download event.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| evt | string | Yes  | Type of the event to unsubscribe from. The value is **progress**, which indicates the download process event.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
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
	  console.info("start download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

### start

start(uri: string, callback: AsyncCallback&lt;void&gt;): void

Starts to download a cloud file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.start(uri, (err: BusinessError) => {
    if (err) {
      console.info("start download failed with error message: " + err.message + ", error code: " + err.code);
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
> Calling **stop** will terminate the download of the current file and clear the cached file. You can use **start** to start the download again.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

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

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri).then(() => {
	  console.info("stop download successfully");
  }).catch((err: BusinessError) => {
	  console.info("stop download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop

stop(uri: string, callback: AsyncCallback&lt;void&gt;): void

Stops downloading a cloud file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> Calling **stop** will terminate the download of the current file and clear the cached file. You can use **start** to start the download again.

**Required permissions**: ohos.permission.CLOUDFILE_SYNC

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| uri | string | Yes  | URI of the file to download.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID                    | Error Message       |
| ---------------------------- | ---------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let download = new cloudSync.Download();
  let uri: string = "file:///media/Photo/1";

  download.stop(uri, (err: BusinessError) => {
    if (err) {
      console.info("stop download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop download successfully");
    }
  });
  ```
