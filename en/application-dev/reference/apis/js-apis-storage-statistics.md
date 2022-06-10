# App Storage Statistics

> **NOTE**<br/>
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - API version 9 is a canary version for trial use. The APIs of this version may be unstable.

The APIs of this module can be used to obtain storage space information, including the space of built-in and plug-in memory cards, space occupied by different types of data, and space of application data.

## Modules to Import

```js
import storagestatistics from "@ohos.storageStatistics";
```

## storagestatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the total size of the specified volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes  | UUID of the volume.|

- Return value

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise used to return the total size of the volume.|

- Example

  ```js
  let uuid = "";
  storagestatistics.getTotalSizeOfVolume(uuid).then(function(number){
      console.info("getTotalSizeOfVolume successfully:"+ number);
  }).catch(function(err){
      console.info("getTotalSizeOfVolume failed with error:"+ err);
  });
  ```

## storagestatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string, callback:AsyncCallback&lt;number&gt;):void

Asynchronously obtains the total size of the specified volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | Yes  | UUID of the volume.                      |
  | callback   | callback:AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the total size of the volume.|

- Example

  ```js
  let uuid = "";
  storagestatistics.getTotalSizeOfVolume(uuid, function(error, number){
      // Do something.
      console.info("getTotalSizeOfVolume successfully:"+ number);
  });
  ```
  
  

## storagestatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the available space of the specified volume. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes  | UUID of the volume.|

- Return value

  | Type                 | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the available space of the volume.|

- Example

  ```js
  let uuid = "";
  storagestatistics.getFreeSizeOfVolume(uuid).then(function(number){
      console.info("getFreeSizeOfVolume successfully:"+ number);
  }).catch(function(err){
      console.info("getFreeSizeOfVolume failed with error:"+ err);
  });
  
  ```

## storagestatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string, callback:AsyncCallback&lt;number&gt;):void

Asynchronously obtains the available space of the specified volume. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name    | Type                                | Mandatory| Description                        |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | Yes  | UUID of the volume.                        |
  | callback   | callback:AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the available space of the volume.|

- Example

  ```js
  let uuid = "";
  storagestatistics.getFreeSizeOfVolume(uuid, function(error, number){
      // Do something.
      console.info("getFreeSizeOfVolume successfully:"+ number);
  });
  ```

## storagestatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string): Promise&lt;BundleStats&gt;

Asynchronously obtains information about an application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name     | Type  | Mandatory| Description    |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | Yes  | Bundle name of the application.|
  
- Return value

  | Type                                      | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats)&gt; | Promise used to return the application information obtained.|

- Example

  ```js
  let packageName = "";
  storagestatistics.getBundleStats(packageName).then(function(BundleStats){
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  }).catch(function(err){
      console.info("getBundleStats failed with error:"+ err);
  });
  ```

## storagestatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string,  callback: AsyncCallback&lt;BundleStats&gt;): void

Asynchronously obtains information about an application. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name  | Type                                                     | Mandatory| Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | Yes  | Bundle name of the application.|
  | callback | callback:AsyncCallback&lt;[Bundlestats](#bundlestats)&gt; | Yes  | Callback invoked to return the application information obtained.|
  
- Example

  ```js
  let packageName = "";
  storagestatistics.getBundleStats(packageName, function(error, BundleStats){
      // Do something.
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  });
  ```



## storagestatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(): Promise<BundleStats>

Asynchronously obtains information about the current third-party application. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Return value

  | Type                                       | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats)&gt; | Promise used to return the application information obtained.     |

- Example

  ```js
      let bundleStats = await storageStatistics.getCurrentBundleStats();
      console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  ```

## storagestatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback<BundleStats>): void

Asynchronously obtains information about the current third-party application. This API uses a callback to return the result.
 
**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Parameters

  | Name   | Type                                                      | Mandatory | Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | callback:AsyncCallback&lt;[BundleStats](#bundlestats)&gt; | Yes  | Callback invoked to return the application information obtained.       |

- Example

  ```js
  storagestatistics.getCurrentBundleStats(function(error, bundleStats){
      // Do something.
      console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  });
  ```
  
  
  
## BundleStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Attribute

| Name     | Type  | Description          |
| --------- | ------ | -------------- |
| appSize   | number | Size of the application.   |
| cacheSize | number | Cache size of the application.  |
| dataSize  | number | Total data size of the application.|




## storagestatistics.getTotalSize<sup>9+</sup>

getTotalSize(): Promise<number>

Obtains the total space of the built-in memory card. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Return value

  | Type                  | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the total space of the built-in memory card.  |

- Example

  ```js
      let number = await storageStatistics.getTotalSize();
      console.info("getTotalSize successfully:"+ JSON.stringify(number));
  ```
  
## storagestatistics.getTotalSize<sup>9+</sup>

getTotalSize(callback: AsyncCallback<number>): void

Obtains the total space of the built-in memory card. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name   | Type                                 | Mandatory | Description                    |
  | -------- | ------------------------------------ | ---- | ------------------------ |
  | callback | callback:AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the total space of the built-in memory card.|

- Example

  ```js
  storagestatistics.getTotalSize(function(error, number){
      // Do something.
      console.info("getTotalSize successfully:"+ JSON.stringify(number));
  });
  ```


## storagestatistics.getFreeSize<sup>9+</sup>

getFreeSize(): Promise<number>

Obtains the available space of the built-in memory card. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Return value

  | Type                  | Description              |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise used to return the available space of the built-in memory card.|

- Example

  ```js
      let number = await storageStatistics.getFreeSize();
      console.info("getFreeSize successfully:"+ JSON.stringify(number));
  ```


## storagestatistics.getFreeSize<sup>9+</sup>

getFreeSize(callback: AsyncCallback<number>): void

Obtains the available space of the built-in memory card. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name   | Type                                 | Mandatory| Description                      |
  | -------- | ------------------------------------ | ---- | ------------------------- |
  | callback | callback:AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the available space of the built-in memory card.|

- Example

  ```js
  storagestatistics.getFreeSize(function(error, number){
      // Do something.
      console.info("getFreeSize successfully:"+ JSON.stringify(number));
  });
  ```



## storagestatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

Asynchronously obtains the system space. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Return value

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise used to return the system space obtained.|

- Example

  ```js
  storagestatistics.getSystemSize().then(function(number){
      console.info("getSystemSize successfully:"+ number);
  }).catch(function(err){
      console.info("getSystemSize failed with error:"+ err);
  });
  ```

## storagestatistics.getSystemSize<sup>9+</sup>

getSystemSize(callback:AsyncCallback&lt;number&gt;):void

Asynchronously obtains the system space. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   | callback:AsyncCallback&lt;number&gt; | Yes  | Callback used to return the system space obtained.|

- Example

  ```js
  storagestatistics.getSystemSize(function(error, number){
      // Do something.
      console.info("getSystemSize successfully:"+ number);
  });
  ```
  
  
  
## storagestatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId?: string): Promise&lt;StorageStats&gt;

Asynchronously obtains the space occupied by each type of user data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | userId | string | No  | User ID.<br>Value:<br>-&nbsp; Set this parameter to the ID of the user to be queried.<br>-&nbsp; If no value is specified, information about the current user is queried.|

- Return value

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#StorageStats)&gt; | Promise used to return the information obtained.|

- Example

  ```js
  let userId = "";
  storagestatistics.getUserStorageStats(userId).then(function(StorageStats){
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  }).catch(function(err){
      console.info("getUserStorageStats failed with error:"+ err);
  });
  ```

## storagestatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId?: string, callback:AsyncCallback&lt;StorageStats&gt;):void

Asynchronously obtains the space occupied by each type of user data. This API uses a callback to return the result.

**Required permissions**: ohos.permission.STORAGE_MANAGER

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**System API**: This is a system API and cannot be called by third-party applications.

- Parameters

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | string                               | No  | User ID.<br>Value:<br>-&nbsp; Set this parameter to the ID of the user to be queried.<br>-&nbsp; If no value is specified, information about the current user is queried.                      |
  | callback   | callback:AsyncCallback&lt;[StorageStats](#StorageStats)&gt; | Yes  | Callback invoked to return the information obtained.|

- Example

  ```js
  storagestatistics.getUserStorageStats(userId, function(error, StorageStats){
      // Do something.
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  });
  ```



## StorageStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Attribute

| Name     | Type  | Description          |
| --------- | ------ | -------------- |
| total   | number | Total space of the built-in memory card.   |
| audio | number | Space occupied by the audio data.  |
| video  | number | Space occupied by the video data.|
| image   | number | Space occupied by the image data.   |
| file | number | Space occupied by files.  |
| app  | number | Space occupied by the application data.|
