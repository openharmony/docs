# @ohos.storageStatistics (Application Storage Statistics)

The **storageStatistics** module provides APIs for obtaining storage space information, including the space of built-in and plug-in memory cards, space occupied by different types of data, and space of application data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import storageStatistics from "@ohos.storageStatistics";
```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the total size of the specified volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes  | UUID of the volume.|

**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise used to return the total size of the volume.|

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

Asynchronously obtains the total size of the specified volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | Yes  | UUID of the volume.                      |
  | callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the total size of the volume.|

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

Asynchronously obtains the available space of the specified volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes  | UUID of the volume.|

**Return value**

  | Type                 | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the available space of the volume.|

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

Asynchronously obtains the available space of the specified volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name    | Type                                | Mandatory| Description                        |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | Yes  | UUID of the volume.                        |
  | callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the available space of the volume.|

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

Asynchronously obtains space information of an application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name     | Type  | Mandatory| Description    |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | Yes  | Bundle name of the application.|

**Return value**

  | Type                                      | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | Promise used to return the space information obtained.|

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

Asynchronously obtains space information of an application. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name  | Type                                                     | Mandatory| Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | Yes  | Bundle name of the application.|
  | callback | AsyncCallback&lt;[Bundlestats](#bundlestats9)&gt; | Yes  | Callback invoked to return the space information obtained.|

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

Asynchronously obtains space information of the current third-party application. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

  | Type                                       | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | Promise used to return the space information obtained.     |

**Example**

  ```js
  let bundleStats = storageStatistics.getCurrentBundleStats();
  console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback&lt;BundleStats&gt;): void

Asynchronously obtains space information of the current third-party application. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Parameters**

  | Name   | Type                                                      | Mandatory | Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[BundleStats](#bundlestats9)&gt;          | Yes  | Callback invoked to return the space information obtained.       |

**Example**

  ```js
  storageStatistics.getCurrentBundleStats(function(error, bundleStats){
      // Do something.
      console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  });
  ```

## BundleStats<sup>9+</sup>

### Attributes

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.

| Name     | Type  | Readable| Writable| Description          |
| --------- | ------ | --- | ---- | -------------- |
| appSize   | number | Yes| No| Size of the application.   |
| cacheSize | number | Yes| No| Cache size of the application.  |
| dataSize  | number | Yes| No| Total data size of the application.|


## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(): Promise&lt;number&gt;

Obtains the total space of the built-in memory card. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Return value**

  | Type                  | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the total space of the built-in memory card.  |

**Example**

  ```js
  let number = storageStatistics.getTotalSize();
  console.info("getTotalSize successfully:"+ JSON.stringify(number));
  ```

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the total space of the built-in memory card. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name   | Type                                 | Mandatory | Description                    |
  | -------- | ------------------------------------ | ---- | ------------------------ |
  | callback | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the total space of the built-in memory card.|

**Example**

  ```js
  storageStatistics.getTotalSize(function(error, number){
      // Do something.
      console.info("getTotalSize successfully:"+ JSON.stringify(number));
  });
  ```


## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(): Promise&lt;number&gt;

Obtains the available space of the built-in memory card. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Return value**

  | Type                  | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the available space of the built-in memory card.|

**Example**

  ```js
  let number = storageStatistics.getFreeSize();
  console.info("getFreeSize successfully:"+ JSON.stringify(number));
  ```


## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the available space of the built-in memory card. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name   | Type                                 | Mandatory| Description                      |
  | -------- | ------------------------------------ | ---- | ------------------------- |
  | callback | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the available space of the built-in memory card.|

**Example**

  ```js
  storageStatistics.getFreeSize(function(error, number){
      // Do something.
      console.info("getFreeSize successfully:"+ JSON.stringify(number));
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

Asynchronously obtains the system space. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise used to return the system space obtained.|

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

Asynchronously obtains the system space. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   |  AsyncCallback&lt;number&gt;         | Yes  | Callback used to return the system space obtained.|

**Example**

  ```js
  storageStatistics.getSystemSize(function(error, number){
      // Do something.
      console.info("getSystemSize successfully:"+ number);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId?: number): Promise&lt;StorageStats&gt;

Asynchronously obtains the space occupied by each type of user data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | userId | number | No  | User ID.<br>Value:<br>-&nbsp; Set this parameter to the ID of the user to be queried.<br>-&nbsp; If no value is specified, information about the current user is queried.|

**Return value**

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | Promise used to return the information obtained.|

**Example**

  ```js
  let userId = 1;
  storageStatistics.getUserStorageStats(userId).then(function(StorageStats){
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  }).catch(function(err){
      console.info("getUserStorageStats failed with error:"+ err);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId?: number, callback: AsyncCallback&lt;StorageStats&gt;): void

Asynchronously obtains the space occupied by each type of user data. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.


**Parameters**

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number                               | No  | User ID.<br>Value:<br>-&nbsp; Set this parameter to the ID of the user to be queried.<br>-&nbsp; If no value is specified, information about the current user is queried.                      |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | Yes  | Callback invoked to return the information obtained.|

**Example**

  ```js
  let userId = 1;
  storageStatistics.getUserStorageStats(userId, function(error, StorageStats){
      // Do something.
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  });
  ```


## StorageStats<sup>9+</sup>

### Attributes

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics


This is a system API and cannot be called by third-party applications.

| Name     | Type  | Readable | Writable | Description          |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | Yes| No| Total space of the built-in memory card.   |
| audio | number  |Yes| No| Space occupied by audio data.  |
| video  | number | Yes| No| Space occupied by video data.|
| image   | number | Yes| No| Space occupied by image data.   |
| file | number | Yes| No| Space occupied by files.  |
| app  | number | Yes| No| Space occupied by application data.|
