# @ohos.file.storageStatistics (应用空间统计)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @gzhuangzhuang-->
<!--Designer: @renguang1116; @wang_zhangjun-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

该模块提供空间查询相关的常用功能：包括对内置存储和外置存储卡的空间查询、对应用分类数据统计的查询、对应用数据的查询、对文件系统inode资源（总量、剩余量及当前应用占用量）的查询等。适用于存储空间管理、系统监控、应用存储优化等场景，帮助开发者实时掌握设备存储和inode资源使用情况，合理规划存储策略，避免因存储空间或inode资源不足导致应用异常。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { storageStatistics } from '@kit.CoreFileKit';
```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(): Promise&lt;BundleStats&gt;

获取当前应用的存储空间大小（单位为Byte），使用Promise异步回调。

例如，可在应用的存储管理或设置页面中，用于展示当前应用占用的存储空间，帮助用户了解应用的存储使用情况。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**返回值：**

  | 类型                                        | 说明                       |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[BundleStats](#bundlestats9)&gt; | Promise对象，返回当前应用的存储空间大小（单位为Byte）。      |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getCurrentBundleStats().then((bundleStats: storageStatistics.BundleStats) => {
  console.info('getCurrentBundleStats successfully:' + JSON.stringify(bundleStats));
}).catch((err: BusinessError) => {
  console.error(`getCurrentBundleStats failed. Code: ${err.code}, message: ${err.message}`);
});
```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback&lt;BundleStats&gt;): void

获取当前应用的存储空间大小（单位为Byte），使用callback异步回调。

例如，可在应用的存储管理或设置页面中，用于展示当前应用占用的存储空间，帮助用户了解应用的存储使用情况。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**参数：**

  | 参数名    | 类型                                                       | 必填  | 说明                                 |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[BundleStats](#bundlestats9)&gt;          | 是   | 回调函数，获取当前应用的存储空间大小之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>bundleStats：当前应用的存储空间统计信息。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getCurrentBundleStats((error: BusinessError, bundleStats: storageStatistics.BundleStats) => {
  if (error) {
    console.error(`getCurrentBundleStats failed. Code: ${error.code}, message: ${error.message}`);
  } else {
    // do something
    console.info('getCurrentBundleStats successfully:' + JSON.stringify(bundleStats));
  }
});
```

## storageStatistics.getTotalSize<sup>15+</sup>

getTotalSize(): Promise&lt;number&gt;

获取内置存储的总空间大小（单位为Byte），使用Promise异步回调。

与getTotalSizeSync相比，本方法不会阻塞当前线程，适用于需要避免阻塞的场景。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**返回值：**

| 类型                  | 说明                                                |
| --------------------- | --------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回内置存储的总空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getTotalSize().then((totalSize: number) => {
  console.info('getTotalSize successfully:' + totalSize);
}).catch((err: BusinessError) => {
  console.error(`getTotalSize failed. Code: ${err.code}, message: ${err.message}`);
});
```

## storageStatistics.getTotalSize<sup>15+</sup>

getTotalSize(callback: AsyncCallback&lt;number&gt;): void

获取内置存储的总空间大小（单位为Byte），使用callback异步回调。

与getTotalSizeSync相比，本方法不会阻塞当前线程，适用于需要避免阻塞的场景。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**参数：**

| 参数名   | 类型                        | 必填 | 说明                               |
| -------- | --------------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，获取内置存储的总空间大小之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>number：内置存储的总空间大小，单位为Byte。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error.                                                   |
| 13900042 | Unknown error.                                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getTotalSize((error: BusinessError, totalSize: number) => {
  if (error) {
    console.error(`getTotalSize failed. Code: ${error.code}, message: ${error.message}`);
  } else {
    // do something
    console.info('getTotalSize successfully:' + totalSize);
  }
});
```

## storageStatistics.getTotalSizeSync<sup>15+</sup>

getTotalSizeSync(): number

同步获取内置存储的总空间大小（单位为Byte）。本方法为同步调用，可能会短暂阻塞当前线程，适用于需要立即获取结果且能接受短暂阻塞的场景。

例如，在存储管理类应用中快速展示设备内置存储总容量。如需避免阻塞，请使用getTotalSize异步接口。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**返回值：**

| 类型   | 说明                                   |
| ------ | -------------------------------------- |
| number | 返回内置存储的总空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let totalSize = storageStatistics.getTotalSizeSync();
  console.info('getTotalSizeSync successfully:' + totalSize);
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`getTotalSizeSync failed. Code: ${error.code}, message: ${error.message}`);
}
```

## storageStatistics.getFreeSize<sup>15+</sup>

getFreeSize(): Promise&lt;number&gt;

获取内置存储的可用空间大小（单位为Byte），使用Promise异步回调。

与getFreeSizeSync相比，本方法不会阻塞当前线程，适用于需要避免阻塞的场景。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**返回值：**

| 类型                  | 说明                                                  |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回内置存储的可用空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getFreeSize().then((freeSize: number) => {
  console.info('getFreeSize successfully:' + freeSize);
}).catch((err: BusinessError) => {
  console.error(`getFreeSize failed. Code: ${err.code}, message: ${err.message}`);
});
```

## storageStatistics.getFreeSize<sup>15+</sup>

getFreeSize(callback: AsyncCallback&lt;number&gt;): void

获取内置存储的可用空间大小（单位为Byte），使用callback异步回调。

与getFreeSizeSync相比，本方法不会阻塞当前线程，适用于需要避免阻塞的场景。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                 |
| -------- | --------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数，获取内置存储的可用空间大小之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>number：内置存储的可用空间大小，单位为Byte。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error.                                                   |
| 13900042 | Unknown error.                                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
storageStatistics.getFreeSize((error: BusinessError, freeSize: number) => {
  if (error) {
    console.error(`getFreeSize failed. Code: ${error.code}, message: ${error.message}`);
  } else {
    // do something
    console.info('getFreeSize successfully:' + freeSize);
  }
});
```

## storageStatistics.getFreeSizeSync<sup>15+</sup>

getFreeSizeSync(): number

同步获取内置存储的可用空间大小（单位为Byte）。本方法为同步调用，可能会短暂阻塞当前线程，适用于需要立即获取结果且能接受短暂阻塞的场景。

例如，在存储管理类应用中快速展示设备剩余可用存储空间。如需避免阻塞，请使用getFreeSize()异步接口。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**返回值：**

| 类型   | 说明                                     |
| ------ | ---------------------------------------- |
| number | 返回内置存储的可用空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息       |
| -------- | -------------- |
| 13600001 | IPC error.     |
| 13900042 | Unknown error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  let freeSize = storageStatistics.getFreeSizeSync();
  console.info('getFreeSizeSync successfully:' + freeSize);
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`getFreeSizeSync failed. Code: ${error.code}, message: ${error.message}`);
}
```

## BundleStats<sup>9+</sup>

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

| 名称                    | 类型                                          | 只读 | 可选 | 说明                                       |
| :---------------------- |---------------------------------------------| ---- | ---- | ------------------------------------------|
| appSize   | number  | 否 | 否 | 应用安装文件大小（单位为Byte）。    |
| cacheSize | number  | 否 | 否  | 应用缓存文件大小（单位为Byte）。   |
| dataSize  | number  | 否 | 否  | 应用文件存储大小（不含应用安装文件）（单位为Byte）。 |

## storageStatistics.getTotalInodes<sup>24+</sup>

getTotalInodes(): Promise&lt;number&gt;

获取文件系统的inode资源总量，仅支持查询系统数据分区。使用Promise异步回调。

inode是文件系统中用于标识和管理文件的数据结构，每个文件或目录占用一个inode。当应用创建大量小文件（如日志文件、缓存文件等）时，可能因inode资源耗尽导致无法创建新文件（即使存储空间仍有剩余）。

例如，可在存储管理或系统监控类应用中，用于评估文件系统inode资源是否充足。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**返回值：**

| 类型                  | 说明                                                  |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回文件系统inode资源总量。                |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 13600001 | IPC error.                                                   |
| 13600016 | Failed to query the inode information of the data partition. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

storageStatistics.getTotalInodes().then((totalInodes: number) => {
  console.info('getTotalInodes successfully:' + totalInodes);
}).catch((err: BusinessError) => {
  console.error(`getTotalInodes failed. Code: ${err.code}, message: ${err.message}`);
});
```

## storageStatistics.getFreeInodes<sup>24+</sup>

getFreeInodes(): Promise&lt;number&gt;

获取文件系统的inode资源剩余量，仅支持查询系统数据分区。使用Promise异步回调。

inode是文件系统中用于标识和管理文件的数据结构，每个文件或目录占用一个inode。

例如，在需要频繁创建小文件的应用（如日志系统、缓存管理）中，可用于监控inode剩余量，提前预警避免因inode耗尽导致文件创建失败。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**返回值：**

| 类型                  | 说明                                                  |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回文件系统inode资源剩余量。               |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 13600001 | IPC error.                                                   |
| 13600016 | Failed to query the inode information of the data partition. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

storageStatistics.getFreeInodes().then((freeInodes: number) => {
  console.info('getFreeInodes successfully:' + freeInodes);
}).catch((err: BusinessError) => {
  console.error(`getFreeInodes failed. Code: ${err.code}, message: ${err.message}`);
});
```

## storageStatistics.getCurrentBundleInodes<sup>24+</sup>

getCurrentBundleInodes(): Promise&lt;number&gt;

获取当前应用的inode占用量（仅支持查询系统数据分区），使用Promise异步回调。

inode是文件系统中用于标识和管理文件的数据结构，每个文件或目录占用一个inode。

例如，在应用的存储管理页面中，可用于展示当前应用的inode使用情况，帮助开发者评估应用的inode占用情况，以便优化文件管理策略。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**返回值：**

| 类型                  | 说明                                                  |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回当前应用的inode占用量。               |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息                                                      |
| -------- | ------------------------------------------------------------ |
| 13600001 | IPC error.                                                   |
| 13600002 | File system not supported.                                   |
| 13600017 | Failed to query the inode information of the application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

storageStatistics.getCurrentBundleInodes().then((bundleInodes: number) => {
  console.info('getCurrentBundleInodes successfully:' + bundleInodes);
}).catch((err: BusinessError) => {
  console.error(`getCurrentBundleInodes failed. Code: ${err.code}, message: ${err.message}`);
});
```
