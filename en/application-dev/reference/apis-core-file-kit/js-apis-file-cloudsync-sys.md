# @ohos.file.cloudSync (Device-Cloud Sync) (System API)

The **cloudSync** module provides the device-cloud sync capabilities for applications. You can use the APIs to start or stop device-cloud sync and start or stop the download of images.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.cloudSync (Device-Cloud Sync Capability)](js-apis-file-cloudsync.md).

## Modules to Import

```ts
import { cloudSync } from '@kit.CoreFileKit';
```

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
| callback | (pg: SyncProgress) => void | Yes  | Callback of the sync progress event. The input parameter is [SyncProgress](./js-apis-file-cloudsync.md#syncprogress12), and the return value is void.|

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
| callback | (pg: SyncProgress) => void | Yes  | Callback of the sync progress event. The input parameter is [SyncProgress](./js-apis-file-cloudsync.md#syncprogress12), and the return value is void.|

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
| 22400003  | Low battery level. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
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
| 22400003  | Low battery level. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
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
  import { BusinessError } from '@kit.BasicServicesKit';
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
  import { BusinessError } from '@kit.BasicServicesKit';
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
| uri | string | Yes  | URI of the target file.|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
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
| uri | string | Yes  | URI of the target file.|
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
  import { BusinessError } from '@kit.BasicServicesKit';
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
| uri | string | Yes  | URI of the target file.|

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
  import { BusinessError } from '@kit.BasicServicesKit';
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
| uri | string | Yes  | URI of the target file.|
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
  import { BusinessError } from '@kit.BasicServicesKit';
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

## FileSync<sup>12+</sup>

Provides APIs for the file manager application to perform device-cloud sync of the files stored in the Drive Kit. Before using the APIs of this class, you need to create a **FileSync** instance.

### constructor<sup>12+</sup>

constructor(bundleName: string)

A constructor used to create a **FileSync** instance.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| bundleName | string | Yes  | Bundle name.|

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

## CloudFileCache<sup>11+</sup>

Provides APIs for the file manager application to download files from the Drive Kit to a local device.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

### cleanCache<sup>11+</sup>

cleanCache(uri: string): void

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
| 14000002  | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
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
| 14000002  | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  let uris: Array<string> = ["file://uri"];
  cloudSync.getFileSyncState(uris).then((syncStates: Array<cloudSync.FileSyncState>) => {
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
| 14000002  | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

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
| 14000002  | Invalid URI. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  try {
    let state = fileSync.getFileSyncState(uri)
  }.catch(err) {
    let error:BusinessError = err as BusinessError;
    console.error("getFileSyncStatefailed with error:" + JSON.stringify(error));
  }
  ```

## FileSyncState<sup>11+</sup>

Enumerates the device-cloud file sync states.

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**System API**: This is a system API.

| Name|  Value|  Description|
| ----- |  ---- |  ---- |
| UPLOADING |  0 | The file is being uploaded.|
| DOWNLOADING |  1 | The file is being downloaded.|
| COMPLETED |  2 | Sync completed.|
| STOPPED |  3 | Sync stopped.|
| TO_BE_UPLOADED<sup>12+</sup> |  4 | The file is going to be uploaded.|
| UPLOAD_SUCCESS<sup>12+</sup> |  5 | The file has been successfully uploaded.|
| UPLOAD_FAILURE<sup>12+</sup> |  6 | The file fails to be uploaded.|
