# Obtaining Application and File System Space Statistics

This topic describes how to obtain information about the free system space and space occupied by applications so as to prevent insufficient storage space of the system or ensure proper use of quota-controlled **cacheDir** directories.

## Available APIs

For details about the APIs, see [ohos.file.statvfs](../reference/apis/js-apis-file-statvfs.md) and [ohos.file.storageStatistics](../reference/apis/js-apis-file-storage-statistics.md).

**Table 1** APIs for file system and application space statistics

| Module| API| Description|
| -------- | -------- | -------- |
| \@ohos.file.storageStatistics | getCurrentBundleStats | Obtains the storage space of the current application, in bytes.|
| \@ohos.file.statvfs | getFreeSize | Obtains the free space of a file system, in bytes.|
| \@ohos.file.statvfs | getTotalSize | Obtains the total space of a file system, in bytes.|

**Table 2** Attributes for application space statistics

| BundleStats Attribute| Description| Directory for Statistics|
| -------- | -------- | -------- |
| appSize | Size of the application installation files, in bytes.| /data/storage/el1/bundle |
| cacheSize | Size of the application cache files, in bytes.| /data/storage/el1/base/cache<br>/data/storage/el1/base/haps/entry/cache<br>/data/storage/el2/base/cache<br>/data/storage/el2/base/haps/entry/cache |
| dataSize | Size of the application files (excluding the application installation files and cache files), in bytes.| The application files include local files, distributed files, and database files.<br>- Local application file directories (parent directories of the **cache** directories):<br>**/data/storage/el1/base**<br>**/data/storage/el2/base**<br>- Distributed application directory: **/data/storage/el2/distributedfiles**<br>- Database directories:<br>**/data/storage/el1/database**<br>**/data/storage/el2/database** |

## Development Example

- Obtain the free space of **/data** of the file system.
  
  ```ts
  import statvfs from '@ohos.file.statvfs';
  
  let path = "/data";
  statvfs.getFreeSize(path, (err, number) => {
    if (err) {
      console.error(`Invoke getFreeSize failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info(`Invoke getFreeSize succeeded, size is ${number}`);
    }
  });
  ```

- Obtain the space occupied by the current application.
  
  ```ts
  import storageStatistics from "@ohos.file.storageStatistics";
  
  storageStatistics.getCurrentBundleStats((err, bundleStats) => {
    if (err) {
      console.error(`Invoke getCurrentBundleStats failed, code is ${err.code}, message is ${err.message}`);
    } else {
      console.info(`Invoke getCurrentBundleStats succeeded, appsize is ${bundleStats.appSize}`);
    }
  });
  ```
