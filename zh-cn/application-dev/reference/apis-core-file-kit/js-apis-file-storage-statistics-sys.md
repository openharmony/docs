# @ohos.file.storageStatistics (应用空间统计)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @gzhuangzhuang-->
<!--Designer: @renguang1116; @wang_zhangjun-->
<!--Tester: @zsyztt; @yue-ye2; @fuwei-->
<!--Adviser: @jinqiuheng-->

该模块提供应用空间统计相关的常用功能，包括：对内置存储和外置存储设备的空间查询、对应用分类数据统计的查询、对应用数据的查询、对系统数据空间大小的查询、对系统应用或系统服务空间占用的上报与查询，以及对用户设备目录空间占用详情的查询等。适用于系统应用中需要在“设置-存储”界面展示空间占用详情或进行存储空间管理的场景。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.file.storageStatistics (应用空间统计)](js-apis-file-storage-statistics.md)。

## 导入模块

```ts
import { storageStatistics } from '@kit.CoreFileKit';
```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取外置存储设备中指定卷设备的总空间大小（单位为Byte）。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷设备uuid，可通过[volumeManager.getAllVolumes()](js-apis-file-volumemanager-sys.md#volumemanagergetallvolumes)接口获取。 |

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise对象，返回指定卷设备的总空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { volumeManager } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getTotalSizeOfVolume(uuid).then((number: number) => {
      console.info("getTotalSizeOfVolume successfully:" + number);
    }).catch((err: BusinessError) => {
      console.error(`getTotalSizeOfVolume failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`getAllVolumes failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

异步获取外置存储设备中指定卷设备的总空间大小（单位为Byte），使用callback异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | 是   | 卷设备uuid，可通过[volumeManager.getAllVolumes()](js-apis-file-volumemanager-sys.md#volumemanagergetallvolumes)接口获取。                       |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 回调函数，获取指定卷设备总空间之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>totalSize：指定卷设备的总空间大小，单位为Byte。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { volumeManager } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getTotalSizeOfVolume(uuid, (error: BusinessError, number: number) => {
      if (error) {
        console.error(`getTotalSizeOfVolume failed with err, code is: ${error.code}, message is: ${error.message}`);
      } else {
        // do something
        console.info("getTotalSizeOfVolume successfully:" + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.error(`getAllVolumes failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取外置存储设备中指定卷设备的可用空间大小（单位为Byte）。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷设备uuid，可通过[volumeManager.getAllVolumes()](js-apis-file-volumemanager-sys.md#volumemanagergetallvolumes)接口获取。 |

**返回值：**

  | 类型                  | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise对象，返回指定卷设备的可用空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { volumeManager } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getFreeSizeOfVolume(uuid).then((number: number) => {
      console.info("getFreeSizeOfVolume successfully:" + number);
    }).catch((err: BusinessError) => {
      console.error(`getFreeSizeOfVolume failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`getAllVolumes failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

异步获取外置存储设备中指定卷设备的可用空间大小（单位为Byte），使用callback异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                         |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | 是   | 卷设备uuid，可通过[volumeManager.getAllVolumes()](js-apis-file-volumemanager-sys.md#volumemanagergetallvolumes)接口获取。                         |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 回调函数，获取指定卷设备可用空间之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>freeSize：指定卷设备的可用空间大小，单位为Byte。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { volumeManager } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getFreeSizeOfVolume(uuid, (error: BusinessError, number: number) => {
      if (error) {
        console.error(`getFreeSizeOfVolume failed with err, code is: ${error.code}, message is: ${error.message}`);
      } else {
        // do something
        console.info("getFreeSizeOfVolume successfully: " + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.error(`getAllVolumes failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string, index?: number): Promise&lt;BundleStats&gt;

异步获取应用存储数据的空间大小（单位为Byte）。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名      | 类型   | 必填 | 说明     |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | 是   | 应用包名。 |
  | index<sup>12+</sup> | number | 否   | 分身应用的索引号，取值需为大于等于0的整数，默认值为0（表示未分身的主应用）。传入不满足范围的值时返回错误码401。分身应用索引号在分身创建时默认占用从1开始且当前未被占用的最小索引号，并赋值给该应用的[BundleResourceInfo](../apis-ability-kit/js-apis-bundleManager-BundleResourceInfo-sys.md#bundleresourceinfo)的appIndex属性，后续可以通过调用[getBundleResourceInfo](../apis-ability-kit/js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo12)接口获得。|

**返回值：**

  | 类型                                       | 说明                       |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[BundleStats](js-apis-file-storage-statistics.md#bundlestats9)&gt; | Promise对象，返回指定应用的存储数据的空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { bundleResourceManager } from '@kit.AbilityKit';
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let bundleName = "com.example.myapplication";
  let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
  try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));

    let packageName:string = bundleName;
    let index:number = resourceInfo.appIndex;
    storageStatistics.getBundleStats(packageName, index).then((bundleStats: storageStatistics.BundleStats) => {
      hilog.info(0x0000, 'testTag', 'getBundleStats successfully. BundleStats: %{public}s', JSON.stringify(bundleStats));
    }).catch((err: BusinessError) => {
      console.error(`getBundleStats failed with err, code is: ${err.code}, message is: ${err.message}`);
    });
  
  } catch (err) {
    let message = (err as BusinessError).message;
    console.error(`getBundleResourceInfo failed with err, message is: ${message}`);
  }
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string, callback: AsyncCallback&lt;BundleStats&gt;, index?: number): void

异步获取应用存储数据的空间大小（单位为Byte），使用callback异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名   | 类型                                                      | 必填 | 说明                                 |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | 是   | 应用包名。 |
  | callback | AsyncCallback&lt;[BundleStats](js-apis-file-storage-statistics.md#bundlestats9)&gt; | 是   | 回调函数，获取指定应用的存储数据的空间大小之后的回调。回调参数包括：err（错误信息，调用成功时为undefined）和bundleStats（指定应用的存储数据的空间大小，单位为Byte）。 |
  | index<sup>12+</sup> | number | 否   | 分身应用的索引号，取值范围为大于等于0的整数，默认值为0（表示未分身的主应用）。传入不满足范围的值时返回错误码401。分身应用索引号在分身创建时默认占用从1开始且当前未被占用的最小索引号，并赋值给该应用的[BundleResourceInfo](../apis-ability-kit/js-apis-bundleManager-BundleResourceInfo-sys.md#bundleresourceinfo)的appIndex属性，后续可以通过调用[getBundleResourceInfo](../apis-ability-kit/js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo12)接口获得。|

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. |
| 13600001 | IPC error. |
| 13600008 | No such object. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { bundleResourceManager } from '@kit.AbilityKit';
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let bundleName = "com.example.myapplication";
  let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
  try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));

    let packageName:string = bundleName;
    let index:number = resourceInfo.appIndex;
    storageStatistics.getBundleStats(packageName, (err: BusinessError, bundleStats: storageStatistics.BundleStats) => {
      if (err) {
        console.error(`getBundleStats failed with err, code is: ${err.code}, message is: ${err.message}`);
      } else {
        hilog.info(0x0000, 'testTag', 'getBundleStats successfully. BundleStats: %{public}s', JSON.stringify(bundleStats));
      }
    }, index);
  
  } catch (err) {
    let message = (err as BusinessError).message;
    console.error(`getBundleResourceInfo failed with err, message is: ${message}`);
  }
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

异步获取系统数据的空间大小（单位为Byte）。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;number&gt; | Promise对象，返回系统数据的空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  storageStatistics.getSystemSize().then((number: number) => {
    console.info("getSystemSize successfully:" + number);
  }).catch((err: BusinessError) => {
    console.error(`getSystemSize failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(callback: AsyncCallback&lt;number&gt;): void

异步获取系统数据的空间大小（单位为Byte），使用callback异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   |  AsyncCallback&lt;number&gt;         | 是   | 回调函数，获取系统数据的空间大小之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>systemSize：系统数据的空间大小，单位为Byte。|

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: Mandatory parameters are left unspecified. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  storageStatistics.getSystemSize((error: BusinessError, number: number) => {
    if (error) {
      console.error(`getSystemSize failed with err, code is: ${error.code}, message is: ${error.message}`);
    } else {
      // do something
      console.info("getSystemSize successfully:" + number);
    }
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(): Promise&lt;StorageStats&gt;

异步获取当前用户各类别存储空间大小（单位为Byte）。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | Promise对象，返回当前用户各类别存储空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  storageStatistics.getUserStorageStats().then((storageStats: storageStatistics.StorageStats) => {
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
  }).catch((err: BusinessError) => {
    console.error(`getUserStorageStats failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(callback: AsyncCallback&lt;StorageStats&gt;): void

异步获取当前用户各类别存储空间大小（单位为Byte），使用callback异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | 是   | 回调函数，获取用户各类别存储空间大小之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>storageStats：用户各类别存储空间大小，单位为Byte。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  storageStatistics.getUserStorageStats((error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.error(`getUserStorageStats failed with err, code is: ${error.code}, message is: ${error.message}`);
    } else {
      // do something
      console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
    }
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number): Promise&lt;StorageStats&gt;

异步获取指定用户各类别存储空间大小（单位为Byte）。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | userId | number | 是   | 用户ID，必须为系统中已存在的有效用户ID。传入不存在的用户ID时返回错误码13600009。|

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;[StorageStats](#storagestats9)&gt; | Promise对象，返回指定用户各类别存储空间大小（单位为Byte）。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userId: number = 100;
  storageStatistics.getUserStorageStats(userId).then((storageStats: storageStatistics.StorageStats) => {
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
  }).catch((err: BusinessError) => {
    console.error(`getUserStorageStats failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number, callback: AsyncCallback&lt;StorageStats&gt;): void

异步获取指定用户各类别存储空间大小（单位为Byte），使用callback异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number                               | 是   | 用户ID，必须为系统中已存在的有效用户ID。传入不存在的用户ID时返回错误码13600009。 |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | 是   | 回调函数，获取指定用户各类别存储空间大小之后的回调。<br>回调参数包括：<br>err：错误信息，调用成功时为undefined。<br>storageStats：指定用户各类别存储空间大小，单位为Byte。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001 | IPC error. |
| 13600009 | User if out of range. |
| 13900042 | Unknown error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let userId: number = 100;
  storageStatistics.getUserStorageStats(userId, (error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.error(`getUserStorageStats failed with err, code is: ${error.code}, message is: ${error.message}`);
    } else {
      // do something
      console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
    }
  });
  ```

## StorageStats<sup>9+</sup>

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：此接口为系统接口。

| 名称      | 类型   | 只读  | 可选  | 说明           |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | 否 | 否 | 内置存储总空间大小，单位为Byte。    |
| audio | number  |否 | 否 | 音频数据大小，单位为Byte。  |
| video  | number | 否 | 否 | 视频数据大小，单位为Byte。 |
| image   | number | 否 | 否 | 图像数据大小，单位为Byte。   |
| file | number | 否 | 否 | 文件数据大小，单位为Byte。  |
| app  | number | 否 | 否 | 应用数据大小，单位为Byte。 |

## ExtBundleStats<sup>23+</sup>

系统应用或系统服务的空间占用详情。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称      | 类型   | 只读  | 可选  | 说明           |
| --------- | ------ | ---- | ----- | -------------- |
| businessName   | string | 否 | 否 | 系统应用包名或系统服务名称。当flag为false时，仅支持系统应用包名。   |
| size | number  |否 | 否 | 系统应用或系统服务的空间占用大小，单位为Byte，取值必须为非负数。传入负数时返回错误码13600010。  |
| flag  | boolean | 否 | 否 | 系统应用或系统服务的空间占用是否需要在“设置-存储”界面单独展示。true表示单独显示，false表示不单独显示。该值为false时，空间占用会被归并到businessName指定的应用中。 |

## storageStatistics.setExtBundleStats<sup>23+</sup>

setExtBundleStats(userId: number, stats: ExtBundleStats): Promise&lt;void&gt;

系统应用或系统服务上报自身的空间占用信息，以便在"设置-存储"界面中单独展示或归并到指定应用。使用Promise异步回调。

> **说明：**
>
> 入参stats中的flag为false时，businessName必须为某个应用的包名。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number | 是   | 用户ID，必须为系统中已存在的有效用户ID。传入不存在的用户ID时返回错误码13600010。                      |
  | stats   | [ExtBundleStats](#extbundlestats23) | 是   | 系统应用或系统服务的空间占用详情。 |

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600010 | The input parameter is invalid. |
| 13600011 | Failed to report the specified business space usage. |

**示例：**

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let userId: number = 100;
  let extBundleStats: storageStatistics.ExtBundleStats = {
    businessName: "com.example.storagedemo",
    size: 10000,
    flag: true
  };
  storageStatistics.setExtBundleStats(userId, extBundleStats).then(() => {
    console.info("setExtBundleStats successfully");
  }).catch((err: BusinessError) => {
    console.error(`setExtBundleStats failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getExtBundleStats<sup>23+</sup>

getExtBundleStats(userId: number, businessName: string): Promise&lt;ExtBundleStats&gt;

获取指定用户、指定系统应用包名或系统服务名称的空间占用详情。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number | 是   | 用户ID，必须为系统中已存在的有效用户ID。传入不存在的用户ID时返回错误码13600010。 |
  | businessName | string | 是   | 系统应用包名或系统服务名称。 |

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;[ExtBundleStats](#extbundlestats23)&gt; | Promise对象，返回指定用户、指定系统应用包名或系统服务名称的空间占用详情。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600010 | The input parameter is invalid. |
| 13600012 | Failed to query the specified business space usage. |

**示例：**

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let userId: number = 100;
  let businessName: string = "com.example.storagedemo";
  storageStatistics.getExtBundleStats(userId, businessName).then((bundleStats: storageStatistics.ExtBundleStats) => {
    console.info("getExtBundleStats successfully.");
  }).catch((err: BusinessError) => {
    console.error(`getExtBundleStats failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```

## storageStatistics.getAllExtBundleStats<sup>23+</sup>

getAllExtBundleStats(userId: number): Promise&lt;Array&lt;ExtBundleStats&gt;&gt;

获取指定用户下所有系统应用或系统服务的空间占用详情。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number | 是   | 用户ID，必须为系统中已存在的有效用户ID。传入不存在的用户ID时返回错误码13600010。                       |

**返回值：**

  | 类型                  | 说明             |
  | --------------------- | ---------------- |
  | Promise&lt;Array&lt;[ExtBundleStats](#extbundlestats23)&gt;&gt; | Promise对象，返回指定用户下所有系统应用或系统服务的空间占用详情。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600010 | The input parameter is invalid. |
| 13600013 | Failed to query all business space usage. |

**示例：**

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let userId: number = 100;
  storageStatistics.getAllExtBundleStats(userId).then((bundleStatsList: storageStatistics.ExtBundleStats[]) => {
    console.info("getAllExtBundleStats successfully");
  }).catch((err: BusinessError) => {
    console.error(`getAllExtBundleStats failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```
  
## UserdataDirInfo<sup>23+</sup>
  
用户设备中/data目录下的空间占用详情。

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

| 名称      | 类型   | 只读  | 可选  | 说明           |
| --------- | ------ | ---- | ----- | -------------- |
| path   | string | 否 | 否 | /data目录下子目录的路径，如'/data/app'。    |
| totalSize | number  |否 | 否 | 路径占用的总空间大小，单位为Byte。  |
| totalCnt  | number | 否 | 否 | 路径下目录和文件总数量。 |

## storageStatistics.listUserdataDirInfo<sup>23+</sup>

listUserdataDirInfo(): Promise&lt;Array&lt;UserdataDirInfo&gt;&gt;

查询用户设备中/data目录下的空间占用详情。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
|  Promise&lt;Array&lt;[UserdataDirInfo](#userdatadirinfo23)&gt;&gt; | Promise对象，返回用户设备中/data目录下的空间占用详情。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600015 | Failed to traverse the query data partition directory. |

**示例：**

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  storageStatistics.listUserdataDirInfo().then((dirInfos: storageStatistics.UserdataDirInfo[]) => {
    console.info("listUserdataDirInfo successfully.");
  }).catch((err: BusinessError) => {
    console.error(`listUserdataDirInfo failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```
  
## storageStatistics.getSystemDataSize<sup>24+</sup>

getSystemDataSize(): Promise&lt;number&gt;

获取系统数据的总空间大小（单位为Byte）。使用Promise异步回调。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**返回值：**

| 类型                   | 说明    |
| --------------------- | :---- |
|  Promise&lt;number&gt; | Promise对象，返回系统数据的总空间大小（单位为Byte）。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission verification failed. |
| 202 | The caller is not a system application. |
| 13600001 | IPC error. |
| 13600018 | Failed to query the system data size. |

**示例：**

  ```ts
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  storageStatistics.getSystemDataSize().then((systemDataSize: number) => {
    console.info("getSystemDataSize successfully: " + systemDataSize);
  }).catch((err: BusinessError) => {
    console.error(`getSystemDataSize failed with err, code is: ${err.code}, message is: ${err.message}`);
  });
  ```
