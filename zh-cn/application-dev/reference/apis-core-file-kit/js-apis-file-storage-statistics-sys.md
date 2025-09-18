# @ohos.file.storageStatistics (应用空间统计)(系统接口)
<!--Kit: Core File Kit-->
<!--Subsystem: FileManagement-->
<!--Owner: @wang_zhangjun; @zhuangzhuang-->
<!--Designer: @wang_zhangjun; @zhuangzhuang; @renguang1116-->
<!--Tester: @liuhonggang123; @yue-ye2; @juxiaopang-->
<!--Adviser: @foryourself-->

该模块提供空间查询相关的常用功能：包括对内外卡的空间查询、对应用分类数据统计的查询、对应用数据的查询等。

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

异步获取外置存储设备中指定卷设备的总空间大小（单位为Byte），以Promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷设备uuid。 |

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
  import { BusinessError } from '@ohos.base';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getTotalSizeOfVolume(uuid).then((number: number) => {
      console.info("getTotalSizeOfVolume successfully:" + number);
    }).catch((err: BusinessError) => {
      console.error("getTotalSizeOfVolume failed with error:" + JSON.stringify(err));
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getTotalSizeOfVolume

getTotalSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

异步获取外置存储设备中指定卷设备的总空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | volumeUuid | string                               | 是   | 卷设备uuid。                       |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 获取指定卷设备总空间之后的回调。 |

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
  import { BusinessError } from '@ohos.base';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getTotalSizeOfVolume(uuid, (error: BusinessError, number: number) => {
      if (error) {
        console.error("getTotalSizeOfVolume failed with error:" + JSON.stringify(error));
      } else {
        // do something
        console.info("getTotalSizeOfVolume successfully:" + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string): Promise&lt;number&gt;

异步获取外置存储设备中指定卷设备的可用空间大小（单位为Byte），以Promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | volumeUuid | string | 是   | 卷设备uuid。 |

**返回值：**

  | 类型                  | 说明               |
  | --------------------- | ------------------ |
  | Promise&lt;number&gt; | Promise对象，返回指定卷的可用空间大小（单位为Byte）。 |

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
  import { BusinessError } from '@ohos.base';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getFreeSizeOfVolume(uuid).then((number: number) => {
      console.info("getFreeSizeOfVolume successfully:" + number);
    }).catch((err: BusinessError) => {
      console.error("getFreeSizeOfVolume failed with error:" + JSON.stringify(err));
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getFreeSizeOfVolume

getFreeSizeOfVolume(volumeUuid: string, callback: AsyncCallback&lt;number&gt;): void

异步获取外置存储设备中指定卷设备的可用空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                         |
  | ---------- | ------------------------------------ | ---- | ---------------------------- |
  | volumeUuid | string                               | 是   | 卷设备uuid。                         |
  | callback   | AsyncCallback&lt;number&gt;          | 是   | 获取指定卷可用空间之后的回调。 |

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
  import { BusinessError } from '@ohos.base';

  volumeManager.getAllVolumes().then((volumes: Array<volumeManager.Volume>) => {
    if (volumes == null || volumes.length <= 0) {
      console.error("volumes is null or length is invalid");
      return;
    }
    let uuid: string = volumes[0].uuid;
    storageStatistics.getFreeSizeOfVolume(uuid, (error: BusinessError, number: number) => {
      if (error) {
        console.error("getFreeSizeOfVolume failed with error:" + JSON.stringify(error));
      } else {
        // do something
        console.info("getFreeSizeOfVolume successfully: " + number);
      }
    });
  }).catch((err: BusinessError) => {
    console.error("getAllVolumes failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string, index?: number): Promise&lt;BundleStats&gt;

异步获取应用存储数据的空间大小（单位为Byte），以Promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名      | 类型   | 必填 | 说明     |
  | ----------- | ------ | ---- | -------- |
  | packageName | string | 是   | 应用包名。 |
  | index<sup>12+</sup> | number | 否   | 分身应用的索引号，默认值为0（表示未分身的主应用）。分身应用索引号在分身创建时默认占用从1开始且当前未被占用的最小索引号，并赋值给该应用的[BundleResourceInfo](../apis-ability-kit/js-apis-bundleManager-BundleResourceInfo-sys.md#bundleresourceinfo)的appIndex属性，后续可以通过调用[getBundleResourceInfo](../apis-ability-kit/js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo12)接口获得。|

**返回值：**

  | 类型                                       | 说明                       |
  | ------------------------------------------ | -------------------------- |
  | Promise&lt;[Bundlestats](js-apis-file-storage-statistics.md#bundlestats9)&gt; | Promise对象，返回指定卷上的应用存储数据的空间大小（单位为Byte）。 |

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
  import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@ohos.base';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let bundleName = "com.example.myapplication";
  let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
  try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));

    let packageName:string = bundleName;
    let index:number = resourceInfo.appIndex;
    storageStatistics.getBundleStats(packageName, index).then((BundleStats: storageStatistics.BundleStats) => {
      hilog.info(0x0000, 'testTag', 'getBundleStats successfully. BundleStats: %{public}s', JSON.stringify(BundleStats));
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', 'getBundleStats failed with error: %{public}s', JSON.stringify(err));
    });
  
  } catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed with error: %{public}s', message);
  }
  ```

## storageStatistics.getBundleStats<sup>9+</sup>

getBundleStats(packageName: string,  callback: AsyncCallback&lt;BundleStats&gt;, index?: number): void

异步获取应用存储数据的空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名   | 类型                                                      | 必填 | 说明                                 |
  | -------- | --------------------------------------------------------- | ---- | ------------------------------------ |
  | packageName | string | 是   | 应用包名。 |
  | callback | AsyncCallback&lt;[Bundlestats](js-apis-file-storage-statistics.md#bundlestats9)&gt; | 是   | 获取指定卷上的应用存储数据的空间大小之后的回调。 |
  | index<sup>12+</sup> | number | 否   | 分身应用的索引号，默认值为0（表示未分身的主应用）。分身应用索引号在分身创建时默认占用从1开始且当前未被占用的最小索引号，并赋值给该应用的[BundleResourceInfo](../apis-ability-kit/js-apis-bundleManager-BundleResourceInfo-sys.md#bundleresourceinfo)的appIndex属性，后续可以通过调用[getBundleResourceInfo](../apis-ability-kit/js-apis-bundleResourceManager-sys.md#bundleresourcemanagergetbundleresourceinfo12)接口获得。|

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
  import bundleResourceManager from '@ohos.bundle.bundleResourceManager';
  import { storageStatistics } from '@kit.CoreFileKit';
  import { BusinessError } from '@ohos.base';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  let bundleName = "com.example.myapplication";
  let bundleFlags = bundleResourceManager.ResourceFlag.GET_RESOURCE_INFO_ALL;
  try {
    let resourceInfo = bundleResourceManager.getBundleResourceInfo(bundleName, bundleFlags);
    hilog.info(0x0000, 'testTag', 'getBundleResourceInfo successfully. Data label: %{public}s', JSON.stringify(resourceInfo.label));

    let packageName:string = bundleName;
    let index:number = resourceInfo.appIndex;
    storageStatistics.getBundleStats(packageName, (err: BusinessError, BundleStats: storageStatistics.BundleStats) => {
      if (err) {
        hilog.error(0x0000, 'testTag', 'getBundleStats failed with error: %{public}s', JSON.stringify(err));
      } else {
        hilog.info(0x0000, 'testTag', 'getBundleStats successfully. BundleStats: %{public}s', JSON.stringify(BundleStats));
      }
    }, index);
  
  } catch (err) {
    let message = (err as BusinessError).message;
    hilog.error(0x0000, 'testTag', 'getBundleResourceInfo failed: %{public}s', message);
  }
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(): Promise&lt;number&gt;

异步获取系统数据的空间大小（单位为Byte），以Promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

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
  import { BusinessError } from '@ohos.base';
  storageStatistics.getSystemSize().then((number: number) => {
    console.info("getSystemSize successfully:" + number);
  }).catch((err: BusinessError) => {
    console.error("getSystemSize failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getSystemSize<sup>9+</sup>

getSystemSize(callback: AsyncCallback&lt;number&gt;): void

异步获取系统数据的空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   |  AsyncCallback&lt;number&gt;         | 是   | 获取系统数据的空间大小之后的回调。 |

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
  import { BusinessError } from '@ohos.base';
  storageStatistics.getSystemSize((error: BusinessError, number: number) => {
    if (error) {
      console.error("getSystemSize failed with error:" + JSON.stringify(error));
    } else {
      // do something
      console.info("getSystemSize successfully:" + number);
    }
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(): Promise&lt;StorageStats&gt;

异步获取当前用户各类别存储空间大小（单位为Byte），以Promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

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
  import { BusinessError } from '@ohos.base';
  storageStatistics.getUserStorageStats().then((storageStats: storageStatistics.StorageStats) => {
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
  }).catch((err: BusinessError) => {
    console.error("getUserStorageStats failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(callback: AsyncCallback&lt;StorageStats&gt;): void

异步获取当前用户各类别存储空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | 是   | 返回用户各类别存储空间大小之后的回调。 |

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
  import { BusinessError } from '@ohos.base';
  storageStatistics.getUserStorageStats((error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.error("getUserStorageStats failed with error:" + JSON.stringify(error));
    } else {
      // do something
      console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
    }
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number): Promise&lt;StorageStats&gt;

异步获取指定用户各类别存储空间大小（单位为Byte），以Promise方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型   | 必填 | 说明 |
  | ---------- | ------ | ---- | ---- |
  | userId | number | 是   | 用户id。|

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
  import { BusinessError } from '@ohos.base';
  let userId: number = 100;
  storageStatistics.getUserStorageStats(userId).then((storageStats: storageStatistics.StorageStats) => {
    console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
  }).catch((err: BusinessError) => {
    console.error("getUserStorageStats failed with error:" + JSON.stringify(err));
  });
  ```

## storageStatistics.getUserStorageStats<sup>9+</sup>

getUserStorageStats(userId: number, callback: AsyncCallback&lt;StorageStats&gt;): void

异步获取指定用户各类别存储空间大小（单位为Byte），以callback方式返回。

**需要权限**：ohos.permission.STORAGE_MANAGER

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

**参数：**

  | 参数名     | 类型                                 | 必填 | 说明                       |
  | ---------- | ------------------------------------ | ---- | -------------------------- |
  | userId | number                               | 是   | 用户id。 |
  | callback   | AsyncCallback&lt;[StorageStats](#storagestats9)&gt; | 是   | 返回指定用户各类别存储空间大小之后的回调。 |

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
  import { BusinessError } from '@ohos.base';
  let userId: number = 100;
  storageStatistics.getUserStorageStats(userId, (error: BusinessError, storageStats: storageStatistics.StorageStats) => {
    if (error) {
      console.error("getUserStorageStats failed with error:" + JSON.stringify(error));
    } else {
      // do something
      console.info("getUserStorageStats successfully:" + JSON.stringify(storageStats));
    }
  });
  ```

## StorageStats<sup>9+</sup>

**系统能力**：SystemCapability.FileManagement.StorageService.SpatialStatistics

**系统接口**：该接口为系统接口。

| 名称      | 类型   | 只读  | 可选  | 说明           |
| --------- | ------ | ---- | ----- | -------------- |
| total   | number | 否 | 否 | 内置存储总空间大小，单位为Byte。    |
| audio | number  |否 | 否 | 音频数据大小，单位为Byte。  |
| video  | number | 否 | 否 | 视频数据大小，单位为Byte。 |
| image   | number | 否 | 否 | 图像数据大小，单位为Byte。   |
| file | number | 否 | 否 | 文件数据大小，单位为Byte。  |
| app  | number | 否 | 否 | 应用数据大小，单位为Byte。 |
