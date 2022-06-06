# App Storage Statistics

> **NOTE**<br/>
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - API version 9 is a canary version for trial use. The APIs of this version may be unstable.
> - The APIs of this module are system APIs and cannot be called by third-party applications.

This module provides functions to obtain storage statistics, including the space of built-in and plug-in memory cards, statistics of application data by type, and application data.

## Modules to Import

```js
import storagestatistics from "@ohos.storageStatistics";
```

## storagestatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the total space of the specified volume. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Parameters

  | Name    | Type  | Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes  | UUID of the volume.|

- Return value

  | Type                 | Description            |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise used to return the total space of the volume.|

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

Asynchronously obtains the total space of the specified volume. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Parameters

  | Name    | Type                                | Mandatory| Description                      |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | Yes  | UUID of the volume.                      |
  | callback   | callback:AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the total space of the volume.|

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

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

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

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

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

Asynchronously obtains application information. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Parameters

  | Name     | Type  | Mandatory| Description    |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | Yes  | Bundle name of the application.|
  
- Return value

  | Type                                      | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats)&gt; | Promise used to return the application data obtained.|

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

Asynchronously obtains application information. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

- Parameters

  | Name  | Type                                                     | Mandatory| Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | Yes  | Bundle name of the application.|
  | callback | callback:AsyncCallback&lt;[Bundlestats](#bundlestats)&gt; | Yes  | Callback used to return the application information obtained.|
  
- Example

  ```js
  let packageName = "";
  storagestatistics.getBundleStats(packageName, function(error, BundleStats){
      // Do something.
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  });
  ```

## BundleStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

### Attribute

| Name     | Type  | Description          |
| --------- | ------ | -------------- |
| appSize<sup>9+</sup>   | number | Size of the application.   |
| cacheSize<sup>9+</sup> | number | Cache size of the application.  |
| dataSize<sup>9+</sup>  | number | Total data size of the application.|
