# @ohos.file.storageStatistics (Application Storage Statistics)

The **storageStatistics** module provides APIs for obtaining storage space information, including the space of built-in and plug-in memory cards, space occupied by different types of data, and space of application data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import  { storageStatistics } from '@kit.CoreFileKit';
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  storageStatistics.getCurrentBundleStats().then((BundleStats: storageStatistics.BundleStats) => {
    console.info("getCurrentBundleStats successfully:" + JSON.stringify(BundleStats));
  }).catch((err: BusinessError) => {
    console.error("getCurrentBundleStats failed with error:"+ JSON.stringify(err));
  });
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback&lt;BundleStats&gt;): void

Obtains the storage space of this application, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Parameters**

  | Name   | Type                                                      | Mandatory | Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[BundleStats](#bundlestats9)&gt;          | Yes  | Callback used to return the application space obtained.       |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | -------- |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  storageStatistics.getCurrentBundleStats((error: BusinessError, bundleStats: storageStatistics.BundleStats) => {
    if (error) {
      console.error("getCurrentBundleStats failed with error:" + JSON.stringify(error));
    } else {
      // Do something.
      console.info("getCurrentBundleStats successfully:" + JSON.stringify(bundleStats));
    }
  });
  ```

## BundleStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

| Name     | Type  | Mandatory| Description          |
| --------- | ------ | --- | -------------- |
| appSize   | number | Yes| Size of the application (excluding empty folders), in bytes.   |
| cacheSize | number | Yes| Size of the cache data, in bytes.  |
| dataSize  | number | Yes| Total size of the application, in bytes.|
