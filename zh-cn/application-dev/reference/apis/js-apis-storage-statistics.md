# 应用空间统计

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口，三方应用不支持调用。

## 导入模块

```js
import storagestatistics from "@ohos.storageStatistics";
```

## storagestatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取指定卷的总空间大小，以promise方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

- 参数

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷id |

- 返回值

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | 返回指定卷总空间 |

- 示例

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

异步获取指定卷的总空间大小，以callback方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

- 参数

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | 是   | 卷id                       |
  | callback   | callback:AsyncCallback&lt;number&gt; | 是   | 获取指定卷总空间之后的回调 |

- 示例

  ```js
  let uuid = "";
  storagestatistics.getTotalSizeOfVolume(uuid, function(error, number){
      // do something
      console.info("getTotalSizeOfVolume successfully:"+ number);
  });
  ```
  

## storagestatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取指定卷的可用空间大小，以promise方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

- 参数

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷id |

- 返回值

  | 类型                  | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | 返回指定卷可用空间 |

- 示例

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

异步获取指定卷的可用空间大小，以callback方式返回。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

- 参数

  | 参数名     | 类型                                 | 必填 | 说明                         |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | 是   | 卷id                         |
  | callback   | callback:AsyncCallback&lt;number&gt; | 是   | 获取指定卷可用空间之后的回调 |

- 示例

  ```js
  let uuid = "";
  storagestatistics.getFreeSizeOfVolume(uuid, function(error, number){
      // do something
      console.info("getFreeSizeOfVolume successfully:"+ number);
  });
  ```
