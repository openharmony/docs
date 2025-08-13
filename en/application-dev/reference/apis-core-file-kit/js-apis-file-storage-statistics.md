# @ohos.file.storageStatistics (Application Storage Statistics)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--SE: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--TSE: @liuhonggang123; @yue-ye2; @juxiaopang-->

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

Obtains the storage space (in bytes) of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

  | Type                                       | Description                      |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[BundleStats](#bundlestats9)&gt; | Promise used to return the application storage space obtained.     |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

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

Obtains the storage space (in bytes) of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Parameters**

  | Name   | Type                                                      | Mandatory | Description                                |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[BundleStats](#bundlestats9)&gt;          | Yes  | Callback used to return the application space obtained.       |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

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

## storageStatistics.getTotalSize<sup>15+</sup>

getTotalSize(): Promise&lt;number&gt;

Obtains the total space of the built-in storage, in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

| Type                 | Description                                               |
| --------------------- | --------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the total built-in storage space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message      |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**Example**

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getTotalSize().then((number: number) => {
  console.info("getTotalSize successfully:" + JSON.stringify(number));
}).catch((err: BusinessError) => {
  console.error("getTotalSize failed with error:"+ JSON.stringify(err));
});
  ```

## storageStatistics.getTotalSize<sup>15+</sup>

getTotalSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the total space of the built-in storage, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Parameters**

| Name  | Type                       | Mandatory| Description                              |
| -------- | --------------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the built-in storage space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error.                                                   |
| 13900042 | Unknown error.                                               |

**Example**

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getTotalSize((error: BusinessError, number: number) => {
  if (error) {
    console.error("getTotalSize failed with error:" + JSON.stringify(error));
  } else {
    // Do something.
    console.info("getTotalSize successfully:" + number);
  }
});
  ```

## storageStatistics.getTotalSizeSync<sup>15+</sup>

getTotalSizeSync(): number

Obtains the total space of the built-in storage, in bytes. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

| Type  | Description                                  |
| ------ | -------------------------------------- |
| number | Built-in storage space obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message      |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**Example**

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let number = storageStatistics.getTotalSizeSync();
  console.info("getTotalSizeSync successfully:" + JSON.stringify(number));
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("getTotalSizeSync failed with error:" + JSON.stringify(error));
}
  ```

## storageStatistics.getFreeSize<sup>15+</sup>

getFreeSize(): Promise&lt;number&gt;

Obtains the available space of the built-in storage, in bytes. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

| Type                 | Description                                                 |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the available space of the built-in storage obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message      |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**Example**

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getFreeSize().then((number: number) => {
  console.info("getFreeSize successfully:" + JSON.stringify(number));
}).catch((err: BusinessError) => {
  console.error("getFreeSize failed with error:" + JSON.stringify(err));
});
  ```

## storageStatistics.getFreeSize<sup>15+</sup>

getFreeSize(callback: AsyncCallback&lt;number&gt;): void

Obtains the available space of the built-in storage, in bytes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Parameters**

| Name  | Type                       | Mandatory| Description                                |
| -------- | --------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the available space of the built-in storage obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401      | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error.                                                   |
| 13900042 | Unknown error.                                               |

**Example**

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getFreeSize((error: BusinessError, number: number) => {
  if (error) {
    console.error("getFreeSize failed with error:" + JSON.stringify(error));
  } else {
    // Do something.
    console.info("getFreeSize successfully:" + number);
  }
});
  ```

## storageStatistics.getFreeSizeSync<sup>15+</sup>

getFreeSizeSync(): number

Obtains the available space of the built-in storage, in bytes. This API returns the result synchronously.

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

**Return value**

| Type  | Description                                    |
| ------ | ---------------------------------------- |
| number | Available space of the built-in storage obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message      |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**Example**

  ```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let number = storageStatistics.getFreeSizeSync();
  console.info("getFreeSizeSync successfully:" + JSON.stringify(number));
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error("getFreeSizeSync failed with error:" + JSON.stringify(error));
}
  ```

## BundleStats<sup>9+</sup>

**System capability**: SystemCapability.FileManagement.StorageService.SpatialStatistics

| Name     | Type  | Mandatory| Description          |
| --------- | ------ | --- | -------------- |
| appSize   | number | Yes| Size of the application installation files, in bytes.   |
| cacheSize | number | Yes| Size of the application cache files, in bytes.  |
| dataSize  | number | Yes| Size of application files (excluding application installation files), in bytes.|
