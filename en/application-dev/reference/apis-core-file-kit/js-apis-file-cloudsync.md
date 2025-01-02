# @ohos.file.cloudSync (Device-Cloud Synchronization)

The **cloudSync** module provides the device-cloud synchronization capabilities for applications. You can use the APIs to start or stop device-cloud synchronization and start or stop the download of images.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { cloudSync } from '@kit.CoreFileKit';
```

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

**System capability**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| state | [State](#state11) | Yes  | File download state.|
| processed | number | Yes  | Size of the data downloaded.|
| size | number | Yes  | Size of the cloud file.|
| uri | string | Yes  | URI of the cloud file.|
| error | [DownloadErrorType](#downloaderrortype11) | Yes  | Download error type.|

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
| event | string | Yes  | Event type. The value is **progress**, which indicates the download progress event of a file from the Drive Kit.|
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
| event | string | Yes  | Event type. The value is **progress**, which indicates the download progress event of a file from the Drive Kit.|
| callback | Callback\<[DownloadProgress](#downloadprogress11)> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the download progress event.|

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
| needClean<sup>12+</sup> | boolean | No  | Whether to delete the downloaded files. By default, downloaded files are deleted.<br>This parameter is available since API version 12.|

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
