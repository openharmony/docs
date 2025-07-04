# @ohos.file.storageStatistics (Application Storage Statistics) (System API)

The **storageStatistics** module provides APIs for obtaining storage space information, including the space of built-in and plug-in memory cards, space occupied by different types of data, and space of application data.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.storageStatistics](js-apis-file-storage-statistics.md).

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
  | Promise&lt;number&gt; | Promise used to return the total volume space (in bytes) obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
      console.error("getTotalSizeOfVolume failed with error:" + JSON.stringify(err));
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
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
  | callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback used to return the total volume space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
        console.error("getTotalSizeOfVolume failed with error:" + JSON.stringify(error));
      } else {
        // Do something.
        console.info("getTotalSizeOfVolume successfully:" + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
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
  | Promise&lt;number&gt; | Promise used to return the available volume space (in bytes) obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
      console.error("getFreeSizeOfVolume failed with error:" + JSON.stringify(err));
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
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
  | callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback used to return the available volume space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
        console.error("getFreeSizeOfVolume failed with error:" + JSON.stringify(error));
      } else {
        // Do something.
        console.info("getFreeSizeOfVolume successfully: " + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string, index?: number): Promise&lt;BundleStats&gt;

Obtains the storage space of an application, in bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name     | Type  | Mandatory| Description    |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | Yes  | Package name of the application.|
  | index<sup>12+</sup> | number | No  | Index of an application clone. The default value is **0**, which indicates the application itself. When an application clone is created, an index is assigned from 1 sequentially to **appIndex** of [BundleResourceInfo](../apis-ability-kit/js-apis-bundleManager-BundleResourceInfo-sys.md#bundleresourceinfo). The index can be obtained by [getBundleResourceInfo](../apis-ability-kit/js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo12).|

**Return value**

  | Type                                      | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](js-apis-file-storage-statistics.md#bundlestats9)&gt; | Promise used to return the application storage space (in bytes) obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
  import storageStatistics from "@ohos.file.storageStatistics";
  import { BusinessError } from '@ohos.base';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let bundleName = "com.example.myapplication";
  let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
  try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));

    let packageName:string = bundleName;
    let index:number = resourceInfo.appIndex;
    storageStatistics.getBundleStats(packageName, index).then((BundleStats: storageStatistics.BundleStats) => {
      hilog.info(0x0000, 'testTag', 'getBundleStats successfully. BundleStats: %{public}s', JSON.stringify(BundleStats));
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', 'getBundleStats failed with error: %{public}s', JSON.stringify(err));
    });
  
  } catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed with error: %{public}s', message);
  }
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string,  callback: AsyncCallback&lt;BundleStats&gt;, index?: number): void

Obtains the storage space of an application, in bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

**Parameters**

  | Name  | Type                                                     | Mandatory| Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | Yes  | Package name of the application.|
  | callback | AsyncCallback&lt;[Bundlestats](js-apis-file-storage-statistics.md#bundlestats9)&gt; | Yes  | Callback used to return the application storage space obtained.|
  | index<sup>12+</sup> | number | No  | Index of an application clone. The default value is **0**, which indicates the application itself. When an application clone is created, an index is assigned from 1 sequentially to **appIndex** of [BundleResourceInfo](../apis-ability-kit/js-apis-bundleManager-BundleResourceInfo-sys.md#bundleresourceinfo). The index can be obtained by [getBundleResourceInfo](../apis-ability-kit/js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo12).|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
  import storageStatistics from "@ohos.file.storageStatistics";
  import { BusinessError } from '@ohos.base';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let bundleName = "com.example.myapplication";
  let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
  try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));

    let packageName:string = bundleName;
    let index:number = resourceInfo.appIndex;
    storageStatistics.getBundleStats(packageName, (err: BusinessError, BundleStats: storageStatistics.BundleStats) => {
      if (err) {
        hilog.error(0x0000, 'testTag', 'getBundleStats failed with error: %{public}s', JSON.stringify(err));
      } else {
        hilog.info(0x0000, 'testTag', 'getBundleStats successfully. BundleStats: %{public}s', JSON.stringify(BundleStats));
      }
    }, index);
  
  } catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed: %{public}s', message);
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
  | Promise&lt;number&gt; | Promise used to return the system data size (in bytes) obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getSystemSize().then((number: number) => {
    console.info("getSystemSize successfully:" + number);
  }).catch((err: BusinessError) => {
    console.error("getSystemSize failed with error:" + JSON.stringify(err));
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
  | callback   |  AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the system data size obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getSystemSize((error: BusinessError, number: number) => {
    if (error) {
      console.error("getSystemSize failed with error:" + JSON.stringify(error));
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
  | Promise&lt;[StorageStats](#storagestats9)&gt; | Promise used to return the storage statistics (in bytes) obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getUserStorageStats().then((storageStats: storageStatistics.StorageStats) => {
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
  }).catch((err: BusinessError) => {
    console.error("getUserStorageStats failed with error:" + JSON.stringify(err));
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
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | Yes  | Callback used to return the storage statistics obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  storageStatistics.getUserStorageStats((error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.error("getUserStorageStats failed with error:" + JSON.stringify(error));
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
  | userId | number | Yes  | User ID.|

**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | Promise used to return the storage statistics (in bytes) obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
    console.error("getUserStorageStats failed with error:" + JSON.stringify(err));
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
  | userId | number                               | Yes  | User ID.|
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | Yes  | Callback used to return the storage statistics obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@ohos.base';
  let userId: number = 100;
  storageStatistics.getUserStorageStats(userId, (error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.error("getUserStorageStats failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
    }
  });
  ```

## StorageStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API.

| Name     | Type  | Read-Only | Optional | Description          |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | No| No| Total space of the built-in storage, in bytes.   |
| audio | number  |No| No| Size of the audio data, in bytes. |
| video  | number | No| No| Size of the video data, in bytes.|
| image   | number | No| No| Size of the image data, in bytes.  |
| file | number | No| No| Size of files, in bytes. |
| app  | number | No| No| Size of application data, in bytes.|
