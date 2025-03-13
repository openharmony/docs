# Obtaining Application and File System Space Statistics

This topic describes how to obtain statistics on the space occupied by your application and the free space and total space of a file system.

## Available APIs

For details about APIs, see [ohos.file.statvfs](../reference/apis-core-file-kit/js-apis-file-statvfs.md) and [ohos.file.storageStatistics](../reference/apis-core-file-kit/js-apis-file-storage-statistics.md).

**Table 1** APIs for application and file system space statistics

| Module| API| Description|
| -------- | -------- | -------- |
| \@ohos.file.storageStatistics | getCurrentBundleStats | Obtains the storage space of the current application, in bytes.|
| \@ohos.file.storageStatistics | getFreeSize | Obtains the total space of the built-in storage, in bytes. This API returns the result asynchronously.|
| \@ohos.file.storageStatistics | getFreeSizeSync | Obtains the total space of the built-in storage, in bytes. This API returns the result synchronously.|
| \@ohos.file.storageStatistics | getTotalSize | Obtains the available space of the built-in storage, in bytes. This API returns the result asynchronously.|
| \@ohos.file.storageStatistics | getTotalSizeSync | Obtains the available space of the built-in storage, in bytes. This API returns the result synchronously.|
| \@ohos.file.statvfs | getFreeSize | Obtains the free space of a file system, in bytes.|
| \@ohos.file.statvfs | getTotalSize | Obtains the total space of a file system, in bytes.|

**Table 2** Attributes for application space statistics

| BundleStats Attribute| Description| Directory for Statistics| 
| -------- | -------- | -------- |
| appSize | Size of the application installation files, in bytes.| Application installation file directory:<br>**/data/storage/el1/bundle**| 
| cacheSize | Size of the application cache files, in bytes.| Application cache file directories:<br>**/data/storage/el1/base/cache**<br>**/data/storage/el1/base/haps/entry/cache**<br>**/data/storage/el2/base/cache**<br>**/data/storage/el2/base/haps/entry/cache**| 
| dataSize | Size of other files of the application, in bytes.| The files include local files, distributed files, and database files of the application.<br>- Local file directories (parent directories of the **cache** directories):<br>**/data/storage/el1/base**<br>**/data/storage/el2/base**<br>- Distributed application directory:<br>/data/storage/el2/distributedfiles<br>- Database directories:<br>**/data/storage/el1/database**<br>**/data/storage/el2/database**| 

## Development Example

- Obtain the free space of **/data** of the file system.
  
  ```ts
  import { statfs } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';
  
  let context = getContext(this) as common.UIAbilityContext;
  let path = context.filesDir;
  statfs.getFreeSize(path, (err: BusinessError, number: number) => {
    if (err) {
      console.error(`Invoke getFreeSize failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info(`Invoke getFreeSize succeeded, size is ${number}`);
    }
  });
  ```

- Obtain the space occupied by the current application.
  
  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  storageStatistics.getCurrentBundleStats((err: BusinessError, bundleStats: storageStatistics.BundleStats) => {
    if (err) {
      console.error(`Invoke getCurrentBundleStats failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info(`Invoke getCurrentBundleStats succeeded, appsize is ${bundleStats.appSize}`);
    }
  });
  ```

- Obtain the total space of the built-in storage asynchronously.

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  storageStatistics.getTotalSize().then((number: number) => {
    console.info("getTotalSize successfully:" + JSON.stringify(number));
  }).catch((err: BusinessError) => {
    console.error("getTotalSize failed with error:"+ JSON.stringify(err));
  });
  ```

- Obtain the total space of the built-in storage synchronously.

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  try {
    let number = storageStatistics.getTotalSizeSync();
    console.info("getTotalSizeSync successfully:" + JSON.stringify(number));
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getTotalSizeSync failed with error:" + JSON.stringify(error));
  }
  ```

- Obtain the available space of the built-in storage asynchronously.

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  storageStatistics.getFreeSize().then((number: number) => {
    console.info("getFreeSize successfully:" + JSON.stringify(number));
  }).catch((err: BusinessError) => {
    console.error("getFreeSize failed with error:" + JSON.stringify(err));
  });
  ```

- Obtain the available space of the built-in storage synchronously.

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  try {
    let number = storageStatistics.getFreeSizeSync();
    console.info("getFreeSizeSync successfully:" + JSON.stringify(number));
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error("getFreeSizeSync failed with error:" + JSON.stringify(error));
  }
  ```
