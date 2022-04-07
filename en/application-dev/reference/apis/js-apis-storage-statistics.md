# App Storage Statistics

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br/>
>
> - The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This is a system API and cannot be called by third-party applications.

## Modules to Import

```js
import storagestatistics from "@ohos.storageStatistics";
```

## storagestatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the total space of the specified volume. This method uses a promise to return the result.

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

Asynchronously obtains the total space of the specified volume. This method uses a callback to return the result.

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
      // Do something
      console.info("getTotalSizeOfVolume successfully:"+ number);
  });
  ```
  
  

## storagestatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

Asynchronously obtains the available space of the specified volume. This method uses a promise to return the result.

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

Asynchronously obtains the available space of the specified volume. This method uses a callback to return the result.

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
      // Do something
      console.info("getFreeSizeOfVolume successfully:"+ number);
  });
  ```

