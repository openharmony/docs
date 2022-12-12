# 应用空间统计

该模块提供空间查询相关的常用功能：包括对内外卡的空间查询，对应用分类数据统计的查询，对应用数据的查询等。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import storageStatistics from "@ohos.storageStatistics";
```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取指定卷的总空间大小，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷id |

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | 返回指定卷总空间 |

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

异步获取指定卷的总空间大小，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | 是   | 卷id                       |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 获取指定卷总空间之后的回调 |

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

异步获取指定卷的可用空间大小，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷id |

**返回值：**

  | 类型                  | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | 返回指定卷可用空间 |

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

异步获取指定卷的可用空间大小，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                         |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | 是   | 卷id                         |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 获取指定卷可用空间之后的回调 |

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

异步获取应用存储数据，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名      | 类型   | 必填 | 说明     |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | 是   | 应用包名 |

**返回值：**

  | 类型                                       | 说明                       |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | 返回指定卷上的应用存储数据 |

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

异步获取应用存储数据，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名   | 类型                                                      | 必填 | 说明                                 |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | 是   | 应用包名 |
  | callback | AsyncCallback&lt;[Bundlestats](#bundlestats9)&gt; | 是   | 获取指定卷上的应用存储数据之后的回调 |

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

第三方应用异步获取占用空间，以promise方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**返回值：**

  | 类型                                        | 说明                       |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](#bundlestats9)&gt; | 返回指定卷上的应用存储状态      |

**示例：**

  ```js
  let bundleStats = storageStatistics.getCurrentBundleStats();
  console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  ```

## storageStatistics.getCurrentBundleStats<sup>9+</sup>

getCurrentBundleStats(callback: AsyncCallback&lt;BundleStats&gt;): void

第三方应用异步获取占用空间，以callback方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**参数：**

  | 参数名    | 类型                                                       | 必填  | 说明                                 |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | callback | AsyncCallback&lt;[BundleStats](#bundlestats9)&gt;          | 是   | 获取指定卷上的应用存储状态之后的回调        |

**示例：**

  ```js
  storageStatistics.getCurrentBundleStats(function(error, bundleStats){
      // do something
      console.info("getCurrentBundleStats successfully:"+ JSON.stringify(bundleStats));
  });
  ```

## BundleStats<sup>9+</sup>

### 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用

| 名称      | 类型   | 可读 | 可写 | 说明           |
| --------- | ------ | --- | ---- | -------------- |
| appSize   | number | 是 | 否 | app数据大小    |
| cacheSize | number | 是 | 否 | 缓存数据大小   |
| dataSize  | number | 是 | 否 | 应用总数据大小 |


## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(): Promise&lt;number&gt;

获取内卡的总空间大小，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**返回值：**

  | 类型                   | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | 返回内卡的总空间大小   |

**示例：**

  ```js
  let number = storageStatistics.getTotalSize();
  console.info("getTotalSize successfully:"+ JSON.stringify(number));
  ```

## storageStatistics.getTotalSize<sup>9+</sup>

getTotalSize(callback: AsyncCallback&lt;number&gt;): void

获取内卡的总空间大小，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名    | 类型                                  | 必填  | 说明                     |
  | -------- | ------------------------------------ | ---- | ------------------------ |
  | callback | AsyncCallback&lt;number&gt;          | 是   | 获取内卡的总空间大小之后的回调 |

**示例：**

  ```js
  storageStatistics.getTotalSize(function(error, number){
      // do something
      console.info("getTotalSize successfully:"+ JSON.stringify(number));
  });
  ```


## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(): Promise&lt;number&gt;

获取内卡的可用空间大小，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**返回值：**

  | 类型                   | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | 返回内卡的可用空间大小 |

**示例：**

  ```js
  let number = storageStatistics.getFreeSize();
  console.info("getFreeSize successfully:"+ JSON.stringify(number));
  ```


## storageStatistics.getFreeSize<sup>9+</sup>

getFreeSize(callback: AsyncCallback&lt;number&gt;): void

获取内卡的可用空间大小，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名    | 类型                                  | 必填 | 说明                       |
  | -------- | ------------------------------------ | ---- | ------------------------- |
  | callback | AsyncCallback&lt;number&gt;          | 是   | 获取内卡的可用空间大小之后的回调 |

**示例：**

  ```js
  storageStatistics.getFreeSize(function(error, number){
      // do something
      console.info("getFreeSize successfully:"+ JSON.stringify(number));
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

异步获取系统空间大小，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | 返回系统空间大小 |

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

异步获取系统空间大小，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   |  AsyncCallback&lt;number&gt;         | 是   | 获取系统空间大小之后的回调 |

**示例：**

  ```js
  storageStatistics.getSystemSize(function(error, number){
      // do something
      console.info("getSystemSize successfully:"+ number);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId?: number): Promise&lt;StorageStats&gt;

异步获取用户各类别数据大小，以promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | userId | number | 否   | 用户id <br/>确认当前用户：<br/>-&nbsp;有值：表示指定用户。<br/>-&nbsp;无值：表示当前用户。|

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | 返回各类别数据大小 |

**示例：**

  ```js
  let userId = 1;
  storageStatistics.getUserStorageStats(userId).then(function(StorageStats){
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  }).catch(function(err){
      console.info("getUserStorageStats failed with error:"+ err);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId?: number, callback: AsyncCallback&lt;StorageStats&gt;): void

异步获取用户各类别数据大小，以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用


**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number                               | 否   | 用户id <br/>确认当前用户：<br/>-&nbsp;有值：表示指定用户。<br/>-&nbsp;无值：表示当前用户。                       |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | 是   | 返回各类别数据大小之后的回调 |

**示例：**

  ```js
  let userId = 1;
  storageStatistics.getUserStorageStats(userId, function(error, StorageStats){
      // do something
      console.info("getUserStorageStats successfully:"+ JSON.stringify(StorageStats));
  });
  ```


## StorageStats<sup>9+</sup>

### 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.FileManagement.StorageService.SpatialStatistics


该接口为系统接口，三方应用不支持调用

| 名称      | 类型   | 可读  | 可写  | 说明           |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | 是 | 否 | 内卡总空间大小    |
| audio | number  |是 | 否 | 音频数据大小   |
| video  | number | 是 | 否 | 视频数据大小 |
| image   | number | 是 | 否 | 图像数据大小    |
| file | number | 是 | 否 | 文件数据大小   |
| app  | number | 是 | 否 | 应用数据大小 |
