# App Storage Statistics

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import storagestatistics from "@ohos.storagestatistics";
```

## System Capabilities

SystemCapability.FileManagement.StorageService.SpatialStatistics

## storagestatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the total space of the specified volume. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes| Universally unique identifier (UUID) of the volume.|

- Return value

  | Type| Description|
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

Asynchronously obtains the total space of the specified volume. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | Yes| UUID of the volume.|
  | callback   | callback:AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the total space of the volume.|

- Example

  ```js
  let uuid = "";
  storagestatistics.getTotalSizeOfVolume(uuid, function(error, number){
      // Do something
  });
  ```

  

## storagestatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the available space of the specified volume. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | Yes| UUID of the volume.|

- Return value

  | Type| Description|
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

Asynchronously obtains the available space of the specified volume. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | Yes| UUID of the volume.|
  | callback   | callback:AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the available space of the volume.|

- Example

  ```js
  let uuid = "";
  storagestatistics.getFreeSizeOfVolume(uuid, function(error, number){
      // Do something
  });
  ```

## storagestatistics.getBundleStats

getBundleStats(volumeUuid: string,  packageName:String, ): Promise&lt;BundleStats&gt;

Asynchronously obtains the bundle status on the specified volume. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ----------- | ------ | ---- | -------- |
  | volumeUuid  | string | Yes| UUID of the volume.|
  | packageName | string | Yes| Bundle name of the app.|

- Return value

  | Type| Description|
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats)&gt; | Promise used to return the bundle status on the volume.|

- Example

  ```js
  let uuid = "";
  let packageName = "";
  storagestatistics.getBundleStats(uuid, packageName).then(function(BundleStats){
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  }).catch(function(err){
      console.info("getBundleStats failed with error:"+ err);
  });
  ```

## storagestatistics.getBundleStats

getBundleStats(volumeUuid: string, callback:AsyncCallback&lt;BundleStats&gt;):void

Asynchronously obtains the bundle status on the specified volume. This method uses a callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | volumeUuid | string                                                    | Yes| UUID of the volume.|
  | callback   | callback:AsyncCallback&lt;[Bundlestats](#bundlestats)&gt; | Yes| Callback invoked to return the bundle status on the volume.|

- Example

  ```js
  let uuid = "";
  let packageName = "";
  storagestatistics.getBundleStats(uuid, packageName, function(error, BundleStats){
      // Do something
  });
  ```

## BundleStats

### Attributes

| Name| Type| Description|
| --------- | ------ | -------------- |
| appSize   | number | Size of the app.|
| cacheSize | number | Size of the cached data.|
| dataSize  | number | Total data size of the app.|
