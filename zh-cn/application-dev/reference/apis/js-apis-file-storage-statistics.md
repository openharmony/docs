# @ohos.file.storageStatistics (应用空间统计)

该模块提供空间查询相关的常用功能：包括对内外卡的空间查询，对应用分类数据统计的查询，对应用数据的查询等。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import storageStatistics from "@ohos.file.storageStatistics";
```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取外置存储设备中指定卷设备的总空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷设备uuid |

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | 返回指定卷设备的总空间大小（单位为Byte） |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let uuid = "";
  storageStatistics.getTotalSizeOfVolume(uuid).then(function(number){
      console.info("getTotalSizeOfVolume successfully:"+ number);
  }).catch(function(err){
      console.info("getTotalSizeOfVolume failed with error:"+ err);
  });
  ```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

异步获取外置存储设备中指定卷设备的总空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | 是   | 卷设备uuid                       |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 获取指定卷设备总空间之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let uuid = "";
  storageStatistics.getTotalSizeOfVolume(uuid, function(error, number){
      // do something
      console.info("getTotalSizeOfVolume successfully:"+ number);
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取外置存储设备中指定卷设备的可用空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷设备uuid |

**返回值：**

  | 类型                  | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | 返回指定卷的可用空间大小（单位为Byte） |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let uuid = "";
  storageStatistics.getFreeSizeOfVolume(uuid).then(function(number){
      console.info("getFreeSizeOfVolume successfully:"+ number);
  }).catch(function(err){
      console.info("getFreeSizeOfVolume failed with error:"+ err);
  });
  
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

异步获取外置存储设备中指定卷设备的可用空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                         |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | 是   | 卷设备uuid                         |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 获取指定卷可用空间之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let uuid = "";
  storageStatistics.getFreeSizeOfVolume(uuid, function(error, number){
      // do something
      console.info("getFreeSizeOfVolume successfully:"+ number);
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string): Promise&lt;BundleStats&gt;

异步获取应用存储空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名      | 类型   | 必填 | 说明     |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | 是   | 应用包名 |

**返回值：**

  | 类型                                       | 说明                       |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | 返回指定卷上的应用存储数据（单位为Byte） |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let packageName = "";
  storageStatistics.getBundleStats(packageName).then(function(BundleStats){
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  }).catch(function(err){
      console.info("getBundleStats failed with error:"+ err);
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string,  callback: AsyncCallback&lt;BundleStats&gt;): void

异步获取应用存储空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名   | 类型                                                      | 必填 | 说明                                 |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | 是   | 应用包名 |
  | callback | AsyncCallback&lt;[Bundlestats](#bundlestats9)&gt; | 是   | 获取指定卷上的应用存储数据之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let packageName = "";
  storageStatistics.getBundleStats(packageName, function(error, BundleStats){
      // do something
      console.info("getBundleStats successfully:"+ JSON.stringify(BundleStats));
  });
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(): Promise&lt;BundleStats&gt;

第三方应用异步获取当前应用存储空间大小（单位为Byte），以promise方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**返回值：**

  | 类型                                        | 说明                       |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | 返回指定卷上的应用存空间大小（单位为Byte）      |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let bundleStats = storageStatistics.getCurrentBundleStats();
  console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback&lt;BundleStats&gt;): void

第三方应用异步获取当前应用存储空间大小（单位为Byte），以callback方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**参数：**

  | 参数名    | 类型                                                       | 必填  | 说明                                 |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[BundleStats](#bundlestats9)&gt;          | 是   | 获取指定卷上的应用存储空间大小之后的回调        |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  storageStatistics.getCurrentBundleStats(function(error, bundleStats){
      // do something
      console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  });
  ```

## BundleStats<sup>9+</sup>

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

| 名称      | 类型   | 可读 | 可写 | 说明           |
| --------- | ------ | --- | ---- | -------------- |
| appSize   | number | 是 | 否 | app数据大小（单位为Byte）    |
| cacheSize | number | 是 | 否 | 缓存数据大小（单位为Byte）   |
| dataSize  | number | 是 | 否 | 应用总数据大小（单位为Byte） |

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(): Promise&lt;number&gt;

获取内置存储的总空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**返回值：**

  | 类型                   | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | 返回内置存储的总空间大小（单位为Byte）   |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let number = storageStatistics.getTotalSize();
  console.info("getTotalSize successfully:"+ JSON.stringify(number));
  ```

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(callback: AsyncCallback&lt;number&gt;): void

获取内置存储的总空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名    | 类型                                  | 必填  | 说明                     |
  | -------- | ------------------------------------ | ---- | ------------------------ |
  | callback | AsyncCallback&lt;number&gt;          | 是   | 获取内置存储的总空间大小之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  storageStatistics.getTotalSize(function(error, number){
      // do something
      console.info("getTotalSize successfully:"+ JSON.stringify(number));
  });
  ```

## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(): Promise&lt;number&gt;

获取内置存储的可用空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**返回值：**

  | 类型                   | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | 返回内置存储的可用空间大小（单位为Byte） |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let number = storageStatistics.getFreeSize();
  console.info("getFreeSize successfully:"+ JSON.stringify(number));
  ```

## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(callback: AsyncCallback&lt;number&gt;): void

获取内置存储的可用空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名    | 类型                                  | 必填 | 说明                       |
  | -------- | ------------------------------------ | ---- | ------------------------- |
  | callback | AsyncCallback&lt;number&gt;          | 是   | 获取内置存储的可用空间大小之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  storageStatistics.getFreeSize(function(error, number){
      // do something
      console.info("getFreeSize successfully:"+ JSON.stringify(number));
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

异步获取系统数据的空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | 返回系统数据的空间大小（单位为Byte） |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  storageStatistics.getSystemSize().then(function(number){
      console.info("getSystemSize successfully:"+ number);
  }).catch(function(err){
      console.info("getSystemSize failed with error:"+ err);
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(callback: AsyncCallback&lt;number&gt;): void

异步获取系统数据的空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   |  AsyncCallback&lt;number&gt;         | 是   | 获取系统数据的空间大小之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  storageStatistics.getSystemSize(function(error, number){
      // do something
      console.info("getSystemSize successfully:"+ number);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(): Promise&lt;StorageStats&gt;

异步获取当前用户各类别存储空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | 返回当前用户各类别存储空间大小（单位为Byte） |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  storageStatistics.getUserStorageStats().then(function(StorageStats){
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  }).catch(function(err){
      console.info("getUserStorageStats failed with error:"+ err);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(callback: AsyncCallback&lt;StorageStats&gt;): void

异步获取当前用户各类别存储空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | 是   | 返回用户各类别存储空间大小之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  storageStatistics.getUserStorageStats(function(error, StorageStats){
      // do something
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number): Promise&lt;StorageStats&gt;

异步获取指定用户各类别存储空间大小（单位为Byte），以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | userId | number | 是   | 用户id|

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | 返回指定用户各类别存储空间大小（单位为Byte） |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let userId = 100;
  storageStatistics.getUserStorageStats(userId).then(function(StorageStats){
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  }).catch(function(err){
      console.info("getUserStorageStats failed with error:"+ err);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number, callback: AsyncCallback&lt;StorageStats&gt;): void

异步获取指定用户各类别存储空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number                               | 是   | 用户id |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | 是   | 返回各类别数据大小之后的回调 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900032 | Unknown error. |

**示例：**

  ```js
  let userId = 100;
  storageStatistics.getUserStorageStats(userId, function(error, StorageStats){
      // do something
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  });
  ```

## StorageStats<sup>9+</sup>

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口：** 该接口为系统接口。

| 名称      | 类型   | 可读  | 可写  | 说明           |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | 是 | 否 | 内置存储总空间大小（单位为Byte）    |
| audio | number  |是 | 否 | 音频数据大小 （单位为Byte）  |
| video  | number | 是 | 否 | 视频数据大小（单位为Byte） |
| image   | number | 是 | 否 | 图像数据大小 （单位为Byte）   |
| file | number | 是 | 否 | 文件数据大小 （单位为Byte）  |
| app  | number | 是 | 否 | 应用数据大小（单位为Byte） |
