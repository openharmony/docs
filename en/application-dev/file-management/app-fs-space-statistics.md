# Obtaining Application and File System Space Statistics
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--Designer: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

This topic describes how to obtain statistics on the space occupied by your application and the free space and total space of a file system.

## Available APIs

For details about APIs, see [ohos.file.statvfs](../reference/apis-core-file-kit/js-apis-file-statvfs.md) and [ohos.file.storageStatistics](../reference/apis-core-file-kit/js-apis-file-storage-statistics.md).

**Table 1** APIs for application and file system space statistics

| Module| API| Description|
| -------- | -------- | -------- |
| \@ohos.file.storageStatistics | getCurrentBundleStats | Obtains the storage space of the current application, in bytes.|
| \@ohos.file.storageStatistics | getFreeSize | Obtains the available space of the built-in storage, in bytes. This API returns the result asynchronously.<br>**Note**: This API is supported since API version 15.|
| \@ohos.file.storageStatistics | getFreeSizeSync | Obtains the available space of the built-in storage, in bytes. This API returns the result synchronously.<br>**Note**: This API is supported since API version 15.|
| \@ohos.file.storageStatistics | getTotalSize | Obtains the total space of the built-in storage, in bytes. This API returns the result asynchronously.<br>**Note**: This API is supported since API version 15.|
| \@ohos.file.storageStatistics | getTotalSizeSync | Obtains the total space of the built-in storage, in bytes. This API returns the result synchronously.<br>**Note**: This API is supported since API version 15.|
| \@ohos.file.statvfs | getFreeSize | Obtains the free space of a file system, in bytes.|
| \@ohos.file.statvfs | getTotalSize | Obtains the total space of a file system, in bytes.|

**Table 2** Attributes for application space statistics

> **NOTE**
>
> The directories involved in the statistics path column in the table refer to the sandbox paths of applications. Before viewing the paths, you need to access the corresponding sandbox space by running the following commands:
>
> 1. hdc shell
> 2. nsenter -t {pid} -m sh

| BundleStats Attribute| Description| Directory for Statistics|
| -------- | -------- | -------- |
| appSize | Size of the application installation files, in bytes.| Application installation file directory:<br>**/data/storage/el1/bundle**|
| cacheSize | Size of the application cache files, in bytes.| Application cache file directories:<br>/data/storage/\${el1-el5}/base/cache<br>/data/storage/\${el1-el5}/base/haps/\${moduleName}/cache<br>/data/storage/el2/sharefiles/cache<br>/data/storage/el2/sharefiles/haps/${moduleName}/cache<br> **NOTE**<br>**\${el1-el5}** denotes the directories [el1, el2, el3, el4, el5](./app-sandbox-directory.md#application-file-directory-and-application-file-path). **\${moduleName}** indicates the module name.|
| dataSize | Size of application files (excluding application installation files), in bytes.| The files include local files, distributed files, and database files of the application.<br>- Local file directories (parent directories of the **cache** directories):<br>/data/storage/\${el1-el5}/base<br>- Distributed application directory:<br>/data/storage/el2/distributedfiles<br>- Database directories:<br>/data/storage/\${el1-el5}/database<br> **NOTE**<br>**\${el1-el5}** denotes the directories [el1, el2, el3, el4, el5](./app-sandbox-directory.md#application-file-directory-and-application-file-path).|

## How to Develop

- Obtain the free space of **/data** of the file system.
  
  ```ts
  import { statfs } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { common } from '@kit.AbilityKit';
  
  // Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext; 
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
    console.info(`getTotalSize successfully, number is ${number}`);
  }).catch((err: BusinessError) => {
    console.error(`getTotalSize failed with error, code is ${err.code}, message is ${err.message}`);
  });
  ```

- Obtain the total space of the built-in storage synchronously.

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  try {
    let number = storageStatistics.getTotalSizeSync();
    console.info(`getTotalSizeSync successfully, number is ${number}`);
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error(`getTotalSizeSync failed with error, code is ${error.code}, message is ${error.message}`);
  }
  ```

- Obtain the available space of the built-in storage asynchronously.

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  storageStatistics.getFreeSize().then((number: number) => {
    console.info(`getFreeSize successfully, number is ${number}`);
  }).catch((err: BusinessError) => {
    console.error(`getFreeSize failed with error, code is ${err.code}, message is ${err.message}`);
  });
  ```

- Obtain the available space of the built-in storage synchronously.

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  try {
    let number = storageStatistics.getFreeSizeSync();
    console.info(`getFreeSizeSync successfully, number is ${number}`);
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error(`getFreeSizeSync failed with error, code is ${error.code}, message is ${error.message}`);
  }
  ```
