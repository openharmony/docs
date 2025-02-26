# @ohos.request.cacheDownload (Download and Cache)

The **request** module provides applications with the basic capabilities of file upload and download and background transfer proxy.
The child component **cacheDownload** provides the basic capability of caching application resources in advance.

**cacheDownload** uses the HTTP protocol to download data and caches data resources to the application memory or files in the application sandbox directory.
The cached data can be used by some ArkUI components, such as the **Image** component, to improve resource loading efficiency. Check whether the ArkUI components support this function by referring to the ArkUI component topics.

> **NOTE**
>
> The initial APIs of this module are supported since API version 16. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { cacheDownload } from '@kit.BasicServicesKit';
```

## cacheDownload.CacheDownloadOptions

Describes configuration options for download and cache from the perspective of HTTP, transmission, and task.

**System capability**: SystemCapability.Request.FileTransferAgent

| Name     | Type                      | Mandatory| Description                   |
|---------|--------------------------|----|-----------------------|
| headers | Record\<string, string\> | No | Request header used by a download-and-cache task during HTTP transmission.|

## cacheDownload.download

download(url: string, options: CacheDownloadOptions)

Starts a download-and-cache task. If the transmission is successful, the data is downloaded to the memory cache and file cache.
After automatically decompressing during HTTP transmission, the size of the target resource cannot exceed 20971520 bytes (20 MB). Otherwise, the resource fails to store in the memory cache or file cache.

When caching the downloaded data, if the data already exists in the destination URL, the new data will overwrite the old one.

In addition, the system determines whether to store the target resource in a specified location based on each cache type's size limit in **cacheDownload**. By default, the LRU mode is used to replace the existing cached data.

This API uses a synchronous method and does not block the calling thread.

**Required permissions**: ohos.permission.INTERNET

**System capability**: SystemCapability.Request.FileTransferAgent

**Parameters**

| Name    | Type                                                        | Mandatory| Description                            |
|---------|------------------------------------------------------------|----|--------------------------------|
| url     | string                                                     | Yes | Destination URL with a maximum of 8192 bytes. Only the HTTP protocol is supported.|
| options | [CacheDownloadOptions](#cachedownloadcachedownloadoptions) | Yes | Cache download options for the target resource.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message                                                                                                                                     |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 201      | the permissions check fails.                                                                                                              |
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**Example**:

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';

  // Provide configuration options for the download-and-cache task.
  let options: cacheDownload.CacheDownloadOptions;
  
  try {
    // Download the resource. If the download is successful, the resource will be cached to the specified file in the application memory or sandbox directory. 
    cacheDownload.download("https://www.example.com", options);
  } catch (err) {
    console.error(`Failed to download the resource. err: ${JSON.stringify(err)}`);
  }
  ```

## cacheDownload.cancel

cancel(url: string)

Cancels an ongoing download-and-cache task based on the URL. The saved memory cache and file cache are not affected. If the task corresponding to the URL does not exist, no operation is required.

This API uses a synchronous method and does not block the calling thread.

**System capability**: SystemCapability.Request.FileTransferAgent

**Parameters**

| Name | Type    | Mandatory| Description                            |
|------|--------|----|--------------------------------|
| url  | string | Yes | Destination URL with a maximum of 8192 bytes. Only the HTTP protocol is supported.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message                                                                                                                                     |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**Example**:

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';

  // Provide configuration options for the download-and-cache task.
  let options: cacheDownload.CacheDownloadOptions;
  
  try {
    // Download the resource. If the download is successful, the resource will be cached to the specified file in the application memory or sandbox directory. 
    cacheDownload.download("https://www.example.com", options);
  } catch (err) {
    console.error(`Failed to download the resource. err: ${JSON.stringify(err)}`);
  }

  // Other service logic is omitted here.
  
  try {
    // Cancel the download-and-cache task when it is not required. The cached data is not affected.
    cacheDownload.cancel("https://www.example.com");
  } catch (err) {
    console.error(`Failed to cancel the task. err: ${JSON.stringify(err)}`);
  }
  ```

## cacheDownload.setMemoryCacheSize

setMemoryCacheSize(bytes: number)

Sets the upper limit of the memory cache size for the **cacheDownload** component.

When this API is used to adjust the cache size, the LRU mode is used by default to clear redundant cached data in the memory.

This API uses a synchronous method and does not block the calling thread.

**System capability**: SystemCapability.Request.FileTransferAgent

**Parameters**

| Name  | Type    | Mandatory| Description                                     |
|-------|--------|----|-----------------------------------------|
| bytes | number | Yes | Upper limit of the cache size. The value ranges from 0 (default) to 1073741824 bytes (1 GB). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message                                                                                                                                     |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**Example**:

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';
  
  try {
    // Set the upper limit of the memory cache size. 
    cacheDownload.setMemoryCacheSize(10 * 1024 * 1024);
  } catch (err) {
    console.error(`Failed to set memory cache size. err: ${JSON.stringify(err)}`);
  }
  ```

## cacheDownload.setFileCacheSize

setFileCacheSize(bytes: number)

Sets the upper limit of the file cache size for the **cacheDownload** component.

When this API is used to adjust the cache size, the LRU mode is used by default to clear redundant cached data in the file.

This API uses a synchronous method and does not block the calling thread.

**System capability**: SystemCapability.Request.FileTransferAgent

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
|-------|--------|----|------------------------------------------------------------|
| bytes | number | Yes | Upper limit of the cache size. The value ranges from 104857600 (100 MB, default) to 4294967296 bytes (4 GB). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID   | Error Message                                                                                                                                     |
|----------|-------------------------------------------------------------------------------------------------------------------------------------------|
| 401      | the parameters check fails. Possible causes: 1. Missing mandatory parameters 2. Incorrect parameter type 3. Parameter verification failed |

**Example**:

  ```ts
  import { cacheDownload, BusinessError } from '@kit.BasicServicesKit';
  
  try {
    // Set the upper limit of the file cache size. 
    cacheDownload.setFileCacheSize(100 * 1024 * 1024);
  } catch (err) {
    console.error(`Failed to set file cache size. err: ${JSON.stringify(err)}`);
  }
  ```
