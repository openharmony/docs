# @ohos.file.storageStatistics (Application Storage Statistics)

The **storageStatistics** module provides APIs for obtaining storage space information, including the space of built-in and plug-in memory cards, space occupied by different types of data, and space of application data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import storageStatistics from "@ohos.file.storageStatistics";
```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Obtains the total size (in bytes) of the specified volume in an external storage device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes  | UUID of the volume.|

**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise used to return the total volume size obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let uuid = "";
  storageStatistics.getTotalSizeOfVolume(uuid).then(function(number){
      console.info("getTotalSizeOfVolume successfully:"+ number);
  }).catch(function(err){
      console.info("getTotalSizeOfVolume failed with error:"+ err);
  });
  ```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the total size (in bytes) of the specified volume in an external storage device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | Yes  | UUID of the volume.                      |
  | callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the total volume size obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let uuid = "";
  storageStatistics.getTotalSizeOfVolume(uuid, function(error, number){
      // Do something.
      console.info("getTotalSizeOfVolume successfully:"+ number);
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Obtains the available space (in bytes) of the specified volume in an external storage device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes  | UUID of the volume.|

**Return value**

  | Type                 | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the available volume space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let uuid = "";
  storageStatistics.getFreeSizeOfVolume(uuid).then(function(number){
      console.info("getFreeSizeOfVolume successfully:"+ number);
  }).catch(function(err){
      console.info("getFreeSizeOfVolume failed with error:"+ err);
  });
  
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the available space (in bytes) of the specified volume in an external storage device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type                                | Mandatory| Description                        |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | Yes  | UUID of the volume.                        |
  | callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the available volume space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let uuid = "";
  storageStatistics.getFreeSizeOfVolume(uuid, function(error, number){
      // Do something.
      console.info("getFreeSizeOfVolume successfully:"+ number);
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string): Promise&lt;BundleStats&gt;

Obtains the space (in bytes) of an application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name     | Type  | Mandatory| Description    |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | Yes  | Bundle name of the application.|

**Return value**

  | Type                                      | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | Promise used to return the application space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let packageName = "";
  storageStatistics.getBundleStats(packageName).then(function(BundleStats){
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  }).catch(function(err){
      console.info("getBundleStats failed with error:"+ err);
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string,  callback: AsyncCallback&lt;BundleStats&gt;): void

Obtains the space (in bytes) of an application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name  | Type                                                     | Mandatory| Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | Yes  | Bundle name of the application.|
  | callback | AsyncCallback&lt;[Bundlestats](#bundlestats9)&gt; | Yes  | Callback invoked to return the application space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let packageName = "";
  storageStatistics.getBundleStats(packageName, function(error, BundleStats){
      // Do something.
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  });
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(): Promise&lt;BundleStats&gt;

Obtains the space (in bytes) of this third-party application. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

  | Type                                       | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | Promise used to return the application space obtained.     |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let bundleStats = storageStatistics.getCurrentBundleStats();
  console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback&lt;BundleStats&gt;): void

Obtains the space (in bytes) of this third-party application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Parameters**

  | Name   | Type                                                      | Mandatory | Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[BundleStats](#bundlestats9)&gt;          | Yes  | Callback invoked to return the application space obtained.       |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  storageStatistics.getCurrentBundleStats(function(error, bundleStats){
      // Do something.
      console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  });
  ```

## BundleStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

| Name     | Type  | Readable| Writable| Description          |
| --------- | ------ | --- | ---- | -------------- |
| appSize   | number | Yes| No| Size of the application, in bytes.   |
| cacheSize | number | Yes| No| Cache size of the application, in bytes.  |
| dataSize  | number | Yes| No| Total data size of the application, in bytes.|

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(): Promise&lt;number&gt;

Obtains the total size (in bytes) of the built-in storage. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

  | Type                  | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the built-in storage size obtained.  |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let number = storageStatistics.getTotalSize();
  console.info("getTotalSize successfully:"+ JSON.stringify(number));
  ```

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the total size (in bytes) of the built-in storage. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name   | Type                                 | Mandatory | Description                    |
  | -------- | ------------------------------------ | ---- | ------------------------ |
  | callback | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the built-in storage size obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  storageStatistics.getTotalSize(function(error, number){
      // Do something.
      console.info("getTotalSize successfully:"+ JSON.stringify(number));
  });
  ```

## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(): Promise&lt;number&gt;

Obtains the available space (in bytes) of the built-in storage. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

  | Type                  | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the available space of the built-in storage obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let number = storageStatistics.getFreeSize();
  console.info("getFreeSize successfully:"+ JSON.stringify(number));
  ```

## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the available space (in bytes) of the built-in storage. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name   | Type                                 | Mandatory| Description                      |
  | -------- | ------------------------------------ | ---- | ------------------------- |
  | callback | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the available space of the built-in storage obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  storageStatistics.getFreeSize(function(error, number){
      // Do something.
      console.info("getFreeSize successfully:"+ JSON.stringify(number));
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

Obtains the system data space, in bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise used to return the system data space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  storageStatistics.getSystemSize().then(function(number){
      console.info("getSystemSize successfully:"+ number);
  }).catch(function(err){
      console.info("getSystemSize failed with error:"+ err);
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the system data space, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   |  AsyncCallback&lt;number&gt;         | Yes  | Callback invoked to return the system data space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  storageStatistics.getSystemSize(function(error, number){
      // Do something.
      console.info("getSystemSize successfully:"+ number);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(): Promise&lt;StorageStats&gt;

Obtains the storage statistics (in bytes) of this user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  storageStatistics.getUserStorageStats().then(function(StorageStats){
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  }).catch(function(err){
      console.info("getUserStorageStats failed with error:"+ err);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(callback: AsyncCallback&lt;StorageStats&gt;): void

Obtains the storage statistics (in bytes) of this user. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | Yes  | Callback invoked to return the information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**Example**

  ```js
  storageStatistics.getUserStorageStats(function(error, StorageStats){
      // Do something.
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number): Promise&lt;StorageStats&gt;

Obtains the storage statistics (in bytes) of the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | userId | number | Yes  | User ID.|

**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | Promise used to return the information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let userId = 100;
  storageStatistics.getUserStorageStats(userId).then(function(StorageStats){
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  }).catch(function(err){
      console.info("getUserStorageStats failed with error:"+ err);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number, callback: AsyncCallback&lt;StorageStats&gt;): void

Obtains the storage statistics (in bytes) of the specified user. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number                               | Yes  | User ID.|
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | Yes  | Callback invoked to return the information obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900032 | Unknown error. |

**Example**

  ```js
  let userId = 100;
  storageStatistics.getUserStorageStats(userId, function(error, StorageStats){
      // Do something.
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  });
  ```

## StorageStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

| Name     | Type  | Readable | Writable | Description          |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | Yes| No| Total size of the built-in storage, in bytes.   |
| audio | number  |Yes| No| Space occupied by audio data, in bytes. |
| video  | number | Yes| No| Space occupied by video data, in bytes.|
| image   | number | Yes| No| Space occupied by image data, in bytes.  |
| file | number | Yes| No| Space occupied by files, in bytes. |
| app  | number | Yes| No| Space occupied by application data, in bytes.|
