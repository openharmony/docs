# @ohos.file.storageStatistics (Application Storage Statistics)

The **storageStatistics** module provides APIs for obtaining storage space information, including the space of built-in and plug-in memory cards, space occupied by different types of data, and space of application data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import storageStatistics from "@ohos.file.storageStatistics";
```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Obtains the total space of a volume in an external storage device, in bytes. This API uses a promise to return the result.

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
| Promise&lt;number&gt; | Promise used to return the total volume space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import volumemanager from "@ohos.file.volumeManager";
  import { BusinessError } from '@ohos.base';
  volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {
    let uuid: string = volumes[0].uuid;
    storageStatistics.getTotalSizeOfVolume(uuid).then((number: number) => {
      console.info("getTotalSizeOfVolume successfully:" + number);
    }).catch((err: BusinessError) => {
      console.info("getTotalSizeOfVolume failed with error:" + JSON.stringify(err));
    });
  }).catch((err: BusinessError) => {
    console.info("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the total space of a volume in an external storage device, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name    | Type                                | Mandatory| Description                      |
| ---------- | ------------------------------------ | ---- | -------------------------- |
| volumeUuid | string                               | Yes  | UUID of the volume.                      |
| callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the total volume space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import volumemanager from "@ohos.file.volumeManager";
  import { BusinessError } from '@ohos.base';
  volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {
    let uuid: string = volumes[0].uuid;
    storageStatistics.getTotalSizeOfVolume(uuid, (error: BusinessError, number: number) => {
      if (error) {
        console.info("getTotalSizeOfVolume failed with error:" + JSON.stringify(error));
      } else {
        // Do something.
        console.info("getTotalSizeOfVolume successfully:" + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.info("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Obtains the available space of a volume in an external storage device, in bytes. This API uses a promise to return the result.

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
| 13900042 | Unknown error. |

**Example**

  ```ts
  import volumemanager from "@ohos.file.volumeManager";
  import { BusinessError } from '@ohos.base';
  volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {
    let uuid: string = volumes[0].uuid;
    storageStatistics.getFreeSizeOfVolume(uuid).then((number: number) => {
      console.info("getFreeSizeOfVolume successfully:" + number);
    }).catch((err: BusinessError) => {
      console.info("getFreeSizeOfVolume failed with error:" + JSON.stringify(err));
    });
  }).catch((err: BusinessError) => {
    console.info("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

Obtains the available space of a volume in an external storage device, in bytes. This API uses an asynchronous callback to return the result.

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
| 13900042 | Unknown error. |

**Example**

  ```ts
  import volumemanager from "@ohos.file.volumeManager";
  import { BusinessError } from '@ohos.base';
  volumemanager.getAllVolumes().then((volumes: Array<volumemanager.Volume>) => {
    let uuid: string = volumes[0].uuid;
    storageStatistics.getFreeSizeOfVolume(uuid, (error: BusinessError, number: number) => {
      if (error) {
        console.info("getFreeSizeOfVolume failed with error:" + JSON.stringify(error));
      } else {
        // Do something.
        console.info("getFreeSizeOfVolume successfully: " + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.info("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string): Promise&lt;BundleStats&gt;

Obtains the storage space of an application, in bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name     | Type  | Mandatory| Description    |
| ----------- | ------ | ---- | -------- |
| packageName | string | Yes  | Bundle name.|

**Return value**

| Type                                      | Description                      |
| ------------------------------------------ | -------------------------- |
| Promise&lt;[Bundlestats](#bundlestats9)&gt; | Promise used to return the application storage space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let packageName: string = "";
  storageStatistics.getBundleStats(packageName).then((BundleStats: storageStatistics.BundleStats) => {
    console.info("getBundleStats successfully:" + JSON.stringify(BundleStats));
  }).catch((err: BusinessError) => {
    console.info("getBundleStats failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string,  callback: AsyncCallback&lt;BundleStats&gt;): void

Obtains the storage space of an application, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
| packageName | string | Yes  | Bundle name.|
| callback | AsyncCallback&lt;[Bundlestats](#bundlestats9)&gt; | Yes  | Callback invoked to return the application storage space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let packageName: string = "";
  storageStatistics.getBundleStats(packageName, (error: BusinessError, BundleStats: storageStatistics.BundleStats) => {
    if (error) {
      console.info("getBundleStats failed with error:" + JSON.stringify(error));
    }  else {
      // Do something.
      console.info("getBundleStats successfully:" + JSON.stringify(BundleStats));
    }
  });
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(): Promise&lt;BundleStats&gt;

Obtains the storage space of this application, in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

| Type                                       | Description                      |
| ------------------------------------------ | -------------------------- |
| Promise&lt;[Bundlestats](#bundlestats9)&gt; | Promise used to return the application storage space obtained.     |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getCurrentBundleStats().then((BundleStats: storageStatistics.BundleStats) => {
    console.info("getCurrentBundleStats successfully:" + JSON.stringify(BundleStats));
  }).catch((err: BusinessError) => {
    console.info("getCurrentBundleStats failed with error:"+ JSON.stringify(err));
  });
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback&lt;BundleStats&gt;): void

Obtains the storage space of this application, in bytes. This API uses an asynchronous callback to return the result.

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
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getCurrentBundleStats((error: BusinessError, bundleStats: storageStatistics.BundleStats) => {
    if (error) {
      console.info("getCurrentBundleStats failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getCurrentBundleStats successfully:" + JSON.stringify(bundleStats));
    }
  });
  ```

## BundleStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

| Name     | Type  | Readable| Writable| Description          |
| --------- | ------ | --- | ---- | -------------- |
| appSize   | number | Yes| No| Size of the application, in bytes.   |
| cacheSize | number | Yes| No| Size of the cache data, in bytes.  |
| dataSize  | number | Yes| No| Total size of the application, in bytes.|

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(): Promise&lt;number&gt;

Obtains the total space of the built-in storage, in bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

| Type                  | Description              |
| --------------------- | ------------------ |
| Promise&lt;number&gt; | Promise used to return the total built-in storage space obtained.  |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getTotalSize().then((number: number) => {
    console.info("getTotalSize successfully:" + JSON.stringify(number));
  }).catch((err: BusinessError) => {
    console.info("getTotalSize failed with error:"+ JSON.stringify(err));
  });
  ```

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the total space of the built-in storage, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name   | Type                                 | Mandatory | Description                    |
| -------- | ------------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the built-in storage space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getTotalSize((error: BusinessError, number: number) => {
    if (error) {
      console.info("getTotalSize failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getTotalSize successfully:" + number);
    }
  });
  ```

## storageStatistics.getTotalSizeSync<sup>10+</sup>

getTotalSizeSync(): number

Obtains the total space of the built-in storage, in bytes. This API returns the result synchronously.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

| Type                  | Description              |
| --------------------- | ------------------ |
| number | Built-in storage space obtained.  |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  try {
    let number = storageStatistics.getTotalSizeSync();
    console.info("getTotalSizeSync successfully:" + JSON.stringify(number));
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.info("getTotalSizeSync failed with error:" + JSON.stringify(error));
  }
  ```

## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(): Promise&lt;number&gt;

Obtains the available space of the built-in storage, in bytes. This API uses a promise to return the result.

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
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getFreeSize().then((number: number) => {
    console.info("getFreeSize successfully:" + JSON.stringify(number));
  }).catch((err: BusinessError) => {
    console.info("getFreeSize failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the available space of the built-in storage, in bytes. This API uses an asynchronous callback to return the result.

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
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getFreeSize((error: BusinessError, number: number) => {
    if (error) {
      console.info("getFreeSize failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getFreeSize successfully:" + number);
    }
  });
  ```

## storageStatistics.getFreeSizeSync<sup>10+</sup>

getFreeSizeSync(): number

Obtains the available space of the built-in storage, in bytes. This API returns the result synchronously.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

| Type                  | Description              |
| --------------------- | ------------------ |
| number | Available space of the built-in storage obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  try {
    let number = storageStatistics.getFreeSizeSync();
    console.info("getFreeSizeSync successfully:" + JSON.stringify(number));
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.info("getFreeSizeSync failed with error:" + JSON.stringify(error));
  }
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

Obtains the system data size, in bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | Promise used to return the system data size obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getSystemSize().then((number: number) => {
    console.info("getSystemSize successfully:" + number);
  }).catch((err: BusinessError) => {
    console.info("getSystemSize failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the system data size, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name    | Type                                | Mandatory| Description                      |
| ---------- | ------------------------------------ | ---- | -------------------------- |
| callback   |  AsyncCallback&lt;number&gt;         | Yes  | Callback invoked to return the system data size obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getSystemSize((error: BusinessError, number: number) => {
    if (error) {
      console.info("getSystemSize failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getSystemSize successfully:" + number);
    }
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(): Promise&lt;StorageStats&gt;

Obtains the storage statistics of this user, in bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;[StorageStats](#storagestats9)&gt; | Promise used to return the storage statistics obtained. |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getUserStorageStats().then((storageStats: storageStatistics.StorageStats) => {
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
  }).catch((err: BusinessError) => {
    console.info("getUserStorageStats failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(callback: AsyncCallback&lt;StorageStats&gt;): void

Obtains the storage statistics of this user, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name    | Type                                | Mandatory| Description                      |
| ---------- | ------------------------------------ | ---- | -------------------------- |
| callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | Yes  | Callback invoked to return the storage statistics obtained. |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getUserStorageStats((error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.info("getUserStorageStats failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
    }
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number): Promise&lt;StorageStats&gt;

Obtains the storage statistics of the specified user, in bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name    | Type  | Mandatory| Description|
| ---------- | ------ | ---- | ---- |
| userId | number | Yes  | User ID|

**Return value**

| Type                 | Description            |
| --------------------- | ---------------- |
| Promise&lt;[StorageStats](#storagestats9)&gt; | Promise used to return the storage statistics obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let userId: number = 100;
  storageStatistics.getUserStorageStats(userId).then((storageStats: storageStatistics.StorageStats) => {
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
  }).catch((err: BusinessError) => {
    console.info("getUserStorageStats failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number, callback: AsyncCallback&lt;StorageStats&gt;): void

Obtains the storage statistics of the specified user, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

| Name    | Type                                | Mandatory| Description                      |
| ---------- | ------------------------------------ | ---- | -------------------------- |
| userId | number                               | Yes  | User ID|
| callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | Yes  | Callback invoked to return the storage statistics obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let userId: number = 100;
  storageStatistics.getUserStorageStats(userId, (error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.info("getUserStorageStats failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
    }
  });
  ```

## StorageStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

| Name     | Type  | Readable | Writable | Description          |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | Yes| No| Total space of the built-in storage, in bytes.   |
| audio | number  |Yes| No| Size of the audio data, in bytes. |
| video  | number | Yes| No| Size of the video data, in bytes.|
| image   | number | Yes| No| Size of the image data, in bytes.  |
| file | number | Yes| No| Size of files, in bytes. |
| app  | number | Yes| No| Size of application data, in bytes.|
