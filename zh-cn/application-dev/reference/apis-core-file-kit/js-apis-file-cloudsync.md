# @ohos.file.cloudSync (端云同步能力)

该模块向应用提供端云同步能力，包括启动/停止端云同步以及启动/停止原图下载功能。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { cloudSync } from '@kit.CoreFileKit';
```
## SyncState<sup>12+</sup>

端云同步状态，为枚举类型。

> **说明：**
>
> 以下同步状态发生变更时，如果应用注册了同步过程事件监听，则通过回调通知应用。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| UPLOADING |  0 | 上行同步中。 |
| UPLOAD_FAILED |  1 | 上行同步失败。 |
| DOWNLOADING |  2 | 下行同步中。 |
| DOWNLOAD_FAILED |  3 | 下行同步失败。 |
| COMPLETED |  4 | 同步成功。 |
| STOPPED |  5 | 同步已停止。 |

## ErrorType<sup>12+</sup>

端云同步失败类型，为枚举类型。

- 当前阶段，同步过程中，当开启无限量使用移动数据网络，移动数据网络和WIFI均不可用时，才会返回NETWORK_UNAVAILABLE；开启无限量使用移动数据网络，若有一种类型网络可用，则能正常同步。
- 同步过程中，非充电场景下，电量低于10%，完成当前批上行同步后停止同步，返回低电量；
- 触发同步时，非充电场景下，若电量低于10%，则不允许同步，start接口返回对应错误。
- 上行时，若云端空间不足，则文件上行失败，云端无该文件记录。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | 没有错误。 |
| NETWORK_UNAVAILABLE |  1 | 所有网络不可用。 |
| WIFI_UNAVAILABLE |  2 | WIFI不可用。 |
| BATTERY_LEVEL_LOW |  3 | 低电量（低于10%）。 |
| BATTERY_LEVEL_WARNING |  4 | 告警电量（低于15%）。 |
| CLOUD_STORAGE_FULL |  5 | 云端空间不足。 |
| LOCAL_STORAGE_FULL |  6 | 本地空间不足。 |
| DEVICE_TEMPERATURE_TOO_HIGH |  7 | 设备温度过高。 |

## SyncProgress<sup>12+</sup>

端云同步过程。

### 属性

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| state | [SyncState](#syncstate12) | 是   | 枚举值，端云同步状态。|
| error | [ErrorType](#errortype12) | 是   | 枚举值，同步失败错误类型。|

## State<sup>11+</sup>

云文件下载状态，为枚举类型。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| RUNNING |  0 | 云文件正在下载中。 |
| COMPLETED |  1 | 云文件下载完成。 |
| FAILED |  2 | 云文件下载失败。 |
| STOPPED |  3 | 云文件下载已停止。 |

## DownloadProgress<sup>11+</sup>

云文件下载过程。

### 属性

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| state | [State](#state11) | 是   | 枚举值，云文件下载状态。|
| processed | number | 是   | 已下载数据大小，取值范围[0，9223372036854775807]（单位：Byte）。|
| size | number | 是   | 当前云文件大小，取值范围[0，9223372036854775807]（单位：Byte）。|
| uri | string | 是   | 当前云文件URI。|
| error | [DownloadErrorType](#downloaderrortype11) | 是   | 下载的错误类型。|

## FileSync<sup>12+</sup>

云盘同步对象，用于支撑文件管理器应用完成云盘文件的端云同步流程。在使用前，需要先创建FileSync实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

### constructor<sup>12+</sup>

constructor()

端云同步流程的构造函数，用于获取FileSync类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |

**示例：**

  ```ts
  let fileSync = new cloudSync.FileSync()
  ```

### on<sup>12+</sup>

on(event: 'progress', callback: Callback\<SyncProgress>): void

添加同步过程事件监听。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| event | string | 是   | 订阅的事件类型，取值为'progress'（同步过程事件）。 |
| callback | Callback\<[SyncProgress](#syncprogress12)> | 是   | 同步过程事件回调。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let fileSync = new cloudSync.FileSync();
  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state：" + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);
  ```

### off<sup>12+</sup>

off(event: 'progress', callback?: Callback\<SyncProgress>): void

移除同步过程事件监听。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| event | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）。|
| callback | Callback\<[SyncProgress](#syncprogress12)> |  否   | 同步过程事件回调， 默认值为null。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  let fileSync = new cloudSync.FileSync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state：" + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);

  fileSync.off('progress', callback);
  ```

### start<sup>12+</sup>

start(): Promise&lt;void&gt;

异步方法启动云盘端云同步，以Promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |
| 22400001  | Cloud status not ready. |
| 22400002  | Network unavailable. |
| 22400003  | Low battery level. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  let callback = (pg: cloudSync.SyncProgress) => {
    console.info("file sync state：" + pg.state + "error type:" + pg.error);
  }

  fileSync.on('progress', callback);

  fileSync.start().then(() => {
    console.info("start sync successfully");
  }).catch((err: BusinessError) => {
    console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start<sup>12+</sup>

start(callback: AsyncCallback&lt;void&gt;): void

异步方法启动云盘端云同步，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动端云同步的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 22400001  | Cloud status not ready. |
| 22400002  | Network unavailable. |
| 22400003  | Low battery level. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.start((err: BusinessError) => {
    if (err) {
      console.error("start sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start sync successfully");
    }
  });
  ```

### stop<sup>12+</sup>

stop(): Promise&lt;void&gt;

异步方法停止云盘端云同步，以Promise形式返回结果。

调用stop接口，同步流程会停止。再次调用[start](#start12)接口会继续同步。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回停止端云同步的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop().then(() => {
    console.info("stop sync successfully");
  }).catch((err: BusinessError) => {
    console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop<sup>12+</sup>

stop(callback: AsyncCallback&lt;void&gt;): void

异步方法停止云盘端云同步，以callback形式返回结果。

调用stop接口，同步流程会停止。再次调用[start](#start12)接口会继续同步。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步停止端云同步的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.stop((err: BusinessError) => {
    if (err) {
      console.error("stop sync failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop sync successfully");
    }
  });
  ```

### getLastSyncTime<sup>12+</sup>

getLastSyncTime(): Promise&lt;number&gt;

异步方法获取上次同步时间，以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | 使用Promise形式返回上次同步时间。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.getLastSyncTime().then((timeStamp: number) => {
    let date = new Date(timeStamp);
    console.info("get last sync time successfully:"+ date);
  }).catch((err: BusinessError) => {
    console.error("get last sync time failed with error message: " + err.message + ", error code: " + err.code);
  });

  ```

### getLastSyncTime<sup>12+</sup>

getLastSyncTime(callback: AsyncCallback&lt;number&gt;): void

异步方法获取上次同步时间，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;number&gt; | 是   | 异步获取上次同步时间的回调。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileSync = new cloudSync.FileSync();

  fileSync.getLastSyncTime((err: BusinessError, timeStamp: number) => {
    if (err) {
      console.error("get last sync time with error message: " + err.message + ", error code: " + err.code);
    } else {
      let date = new Date(timeStamp);
      console.info("get last sync time successfully:"+ date);
    }
  });
  ```

## CloudFileCache<sup>11+</sup>

云盘文件缓存对象，用来支撑文件管理应用原文件下载流程。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

### construct<sup>11+</sup>

constructor()

云盘文件缓存流程的构造函数，用于获取CloudFileCache类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**错误码：**

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes:Incorrect parameter types. |

**示例：**

  ```ts
  let fileCache = new cloudSync.CloudFileCache();
  ```

### on<sup>11+</sup>

on(event: 'progress', callback: Callback\<DownloadProgress>): void

添加云盘文件缓存过程事件监听。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| event | string | 是   | 订阅的事件类型，取值为'progress'（下载过程事件）。|
| callback | Callback\<[DownloadProgress](#downloadprogress11)> | 是   | 云文件下载过程事件回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileCache = new cloudSync.CloudFileCache();
  let callback = (pg: cloudSync.DownloadProgress) => {
    console.info("download state：" + pg.state);
  };

  try {
    fileCache.on('progress', callback);
  } catch (e) {
    const error = e as BusinessError;
    console.error(`Error code: ${error.code}, message: ${error.message}`);
  }
  ```

### off<sup>11+</sup>

off(event: 'progress', callback?: Callback\<DownloadProgress>): void

移除云盘文件缓存过程事件监听。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| event | string | 是   | 取消订阅的事件类型，取值为'progress'（同步过程事件）。|
| callback | Callback\<[DownloadProgress](#downloadprogress11)> | 否   | 云文件下载过程事件回调。若填写，将视为取消指定的回调函数；否则为取消当前订阅的所有回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let fileCache = new cloudSync.CloudFileCache();

  let callback = (pg: cloudSync.DownloadProgress) => {
    console.info("download state：" + pg.state);
  }

  try {
    fileCache.on('progress', callback);
    fileCache.off('progress', callback);
  } catch (e) {
    const error = e as BusinessError;
    console.error(`Error code: ${error.code}, message: ${error.message}`);
  }
  ```

### start<sup>11+</sup>

start(uri: string): Promise&lt;void&gt;

异步方法启动云盘文件缓存，以Promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回启动云文件下载的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |
| 14000002 | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  try {
    fileCache.on('progress', (pg: cloudSync.DownloadProgress) => {
      console.info("download state:" + pg.state);
    });
  } catch (e) {
    const error = e as BusinessError;
    console.error(`Error code: ${error.code}, message: ${error.message}`);
  }

  fileCache.start(uri).then(() => {
    console.info("start download successfully");
  }).catch((err: BusinessError) => {
    console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### start<sup>11+</sup>

start(uri: string, callback: AsyncCallback&lt;void&gt;): void

异步方法启动云盘文件缓存，以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动云文件下载的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |
| 14000002 | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileCache.start(uri, (err: BusinessError) => {
    if (err) {
      console.error("start download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("start download successfully");
    }
  });
  ```

### stop<sup>11+</sup>

stop(uri: string, needClean?: boolean): Promise&lt;void&gt;

异步方法停止云盘文件缓存，以Promise形式返回结果。

调用stop接口，当前文件下载流程会终止，缓存文件会被删除，再次调用start接口会重新开始下载。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |
| needClean<sup>12+</sup> | boolean | 否   | 是否删除已下载的文件。默认值为false表示删除；true表示不删除。<br>从API version12开始支持该参数。 |

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | 使用Promise形式返回停止云文件下载的结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 14000002 | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileCache.stop(uri, true).then(() => {
    console.info("stop download successfully");
  }).catch((err: BusinessError) => {
    console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### stop<sup>11+</sup>

stop(uri: string, callback: AsyncCallback&lt;void&gt;): void

异步方法停止云盘文件缓存，以callback形式返回结果。

调用stop接口，当前文件下载流程会终止，缓存文件会被删除，再次调用start接口会重新开始下载。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步停止云文件下载的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 14000002 | Invalid URI. |

**示例：**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  import { fileUri } from '@kit.CoreFileKit';
  let fileCache = new cloudSync.CloudFileCache();
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileCache.stop(uri, (err: BusinessError) => {
    if (err) {
      console.error("stop download failed with error message: " + err.message + ", error code: " + err.code);
    } else {
      console.info("stop download successfully");
    }
  });
  ```

## DownloadErrorType<sup>11+</sup>

端云下载错误类型，为枚举类型。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| NO_ERROR |  0 | 没有错误。 |
| UNKNOWN_ERROR |  1 | 未知错误。 |
| NETWORK_UNAVAILABLE |  2 | 网络不可用。 |
| LOCAL_STORAGE_FULL |  3 | 本地空间不足。 |
| CONTENT_NOT_FOUND |  4 | 云端空间未找到对应文件。 |
| FREQUENT_USER_REQUESTS |  5 | 用户请求过于频繁。 |

## cloudSync.registerChange<sup>12+</sup>

registerChange(uri: string, recursion: boolean, callback: Callback&lt;ChangeData&gt;): void

订阅监听指定文件的变化通知。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |
| recursion | boolean | 是   | true为监听该URI以及子文件和子目录，false为仅监听该URI文件。|
| callback | Callback&lt;[ChangeData](#changedata12)&gt; | 是   | 返回更改的数据。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900001  | Operation not permitted. |
| 13900002  | No such file or directory. |
| 13900012  | Permission denied. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let onCallback1 = (changeData: cloudSync.ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // 取消注册监听
  cloudSync.unregisterChange(uri);
  ```

## cloudSync.unregisterChange<sup>12+</sup>

unregisterChange(uri: string): void

取消订阅监听指定文件的变化通知。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   | 待下载文件uri。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13900001  | Operation not permitted. |
| 13900002  | No such file or directory. |
| 13900012  | Permission denied. |
| 14000002  | Invalid URI. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let onCallback1 = (changeData: cloudSync.ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // 取消注册监听
  cloudSync.unregisterChange(uri);
  ```

## NotifyType<sup>12+</sup>

数据变更通知类型。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| NOTIFY_ADDED |  0 | 文件已新建。 |
| NOTIFY_MODIFIED |  1 | 文件已修改。 |
| NOTIFY_DELETED |  2 | 文件已被删除。 |
| NOTIFY_RENAMED |  3 | 文件被重命名或者移动。 |

## ChangeData<sup>12+</sup>

定义变更数据。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| type | [NotifyType](#notifytype12) | 是   | 更改的通知类型。|
| isDirectory | Array&lt;boolean&gt; | 是   | 指示更改的URI是否为目录。true：是目录。false：非目录。|
| uris | Array&lt;string&gt; | 是   | 需要更改的URI列表。|


## HistoryVersion<sup>20+</sup>

端云文件历史版本信息，调用端云文件版本管理类[FileVersion](#fileversion20)的[gethistoryversionlist](#gethistoryversionlist20)方法时，历史版本列表中的属性。

### 属性

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 说明 |
| ---------- | ------ | ---- |
| editedTime | number | 文件内容修改时间。 |
| fileSize | number | 文件大小，单位：Byte。 |
| versionId | string | 文件版本号。 |
| originalFileName | string | 当前版本对应的文件名。 |
| sha256 | string | 当前版本对应文件内容的哈希值。 |
| autoResolved | boolean | 当前版本是否为自动解决冲突的版本。<br>应用设置手动解冲突时，默认返回false，无意义。<br>应用设置自动解冲突时，端侧会自动解冲突，true表示当前版本存在冲突，端云服务已自动解决冲突，false表示无冲突，未自动解冲突。 |

**补充说明**：当本地和他端同时修改文件产生冲突时，当前端云同步有自动解冲突机制，但有些应用希望由用户手动解决冲突，此时应用可以通过在项目工程的/entry/src/main/resources/base/profile目录下增加cloudkit_config.json文件，并配置manualConflictResolutionEnable为true，表示手动解决冲突使能；若应用不需要手动解决冲突，可以不配置该文件或者配置manualConflictResolutionEnable为false，表示采用已有的自动解冲突策略。

配置文件cloudkit_config.json样例：

  ```json
  {
    "cloudKitConfig": {
      "cloudFileSyncConfig": {
        "manualConflictResolutionEnable": "true"
      }
    }
  }
  ```

## VersionDownloadProgress<sup>20+</sup>

历史版本文件下载状态和进度信息，调用端云文件版本管理类[FileVersion](#fileversion20)的[downloadHistoryVersion](#downloadhistoryversion20)方法时，回调函数的入参类型。

### 属性

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 | 类型 | 必填 | 说明 |
| ---------- | ------ | ------ | ---- |
| state | [State](#state11) | 是 | 所选版本云文件的下载状态。 |
| progress | number | 是 | 下载进度。 |
| errType | [DownloadErrorType](#downloaderrortype11) | 是 | 若出现下载失败，失败的错误类型。 |

## FileVersion<sup>20+</sup>

端云文件版本管理类。支持对端云文件的历史版本进行管理，提供获取文件历史版本信息列表的能力，通过历史版本信息，可将历史版本下载到本地；并提供历史版本文件替换当前本地文件的能力，针对版本冲突，提供查询冲突标志，解除冲突标志的能力。

### construct<sup>20+</sup>

constructor()

端云文件版本管理的构造函数，用于获取FileVersion类的实例。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  let fileVersion = new cloudSync.FileVersion();
  ```

### getHistoryVersionList<sup>20+</sup>

getHistoryVersionList(uri: string, versionNumLimit: number): Promise&lt;Array&lt;HistoryVersion&gt;&gt;

获取历史版本列表，可限制传出列表长度，当云上版本数量小于参数限制时，按照实际版本数量返回历史版本列表。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   |  文件的URI。 |
| versionNumLimit | number | 是 | 历史版本列表长度限制。 |

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| Promise&lt;Array&lt;[HistoryVersion](#historyversion20)&gt;&gt; | Promise对象，返回历史版本列表。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400002 | Network unavailable. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let limit = 10;

  fileVersion.getHistoryVersionList(uri, limit).then((versionList: Array<cloudSync.HistoryVersion>) => {
    for(let i = 0, len = versionList.length; i < len; i++) {
      console.info("get history versionId: " + versionList[i].versionId);
    }
  }).catch((err: BusinessError) => {
    console.error("get history version failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### downloadHistoryVersion<sup>20+</sup>

downloadHistoryVersion(uri: string, versionId: string, callback: Callback&lt;[VersionDownloadProgress](#versiondownloadprogress20)&gt;): Promise&lt;string&gt;

根据版本号获取指定文件的某一版本的文件内容。用户通过版本号指定云上某一版本，将其下载到本地临时存储路径，临时文件由应用自行决定是否替换原始文件，也可以选择保留或直接删除。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   |  文件的URI。 |
| versionId | string | 是 | 文件某一版本的版本号，格式以接口[gethistoryversionlist](#gethistoryversionlist20)返回为准。 |
| callback | Callback&lt;[VersionDownloadProgress](#versiondownloadprogress20)&gt; | 是 | 下载进度的回调。 |

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| Promise&lt;string&gt; | Promise对象，返回历史版本临时存储文件的URI。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400002 | Network unavailable. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let versionId = '123456'; // 以 getHistoryVersionList 方法返回的格式为准，此处仅作为 demo 示例。

  let callback = (data: cloudSync.VersionDownloadProgress) => {
    if (data.state == cloudSync.State.RUNNING) {
      console.info("download progress: " + data.progress);
    } else if (data.state == cloudSync.State.FAILED) {
      console.info("download failed errType: " + data.errType);
    } else if (data.state == cloudSync.State.COMPLETED) {
      console.info("download version file success");
    }
  };

  fileVersion.downloadHistoryVersion(uri, versionId, callback).then((fileUri: string) => {
    console.info("success to begin download, downloadFileUri: " + fileUri);
  }).catch((err: BusinessError) => {
    console.error("download history version file failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### replaceFileWithHistoryVersion<sup>20+</sup>

replaceFileWithHistoryVersion(originalUri: string, versionUri: string): Promise&lt;void&gt;

提供使用历史版本文件替换本地文件的能力。在替换前，需要调用[downloadHistoryVersion](#downloadhistoryversion20)方法对选择的历史版本进行下载并拿到versionUri；直接调用此接口或者versionUri非法会产生异常；替换完成后会删除临时存储文件。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| originalUri | string | 是   |  本地文件的URI。 |
| versionUri | string | 是 | 历史版本文件的URI。 |

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900005 | I/O error. |
| 13900008 | Bad file descriptor. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |
| 22400007 | Version file not exist. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);
  let versionId = '123456'; // 以 getHistoryVersionList 方法返回的格式为准，此处仅作为 demo 示例。

  let callback = (data: cloudSync.VersionDownloadProgress) => {
    if (data.state == cloudSync.State.RUNNING) {
      console.info("download progress: " + data.progress);
    } else if (data.state == cloudSync.State.FAILED) {
      console.info("download failed errType: " + data.errType);
    } else if (data.state == cloudSync.State.COMPLETED) {
      console.info("download version file success");
    }
  };

  let versionUri = "";
  fileVersion.downloadHistoryVersion(uri, versionId, callback).then((fileUri: string) => {
    versionUri = fileUri;
    console.info("success to begin download, downloadFileUri: " + fileUri);
  }).catch((err: BusinessError) => {
    console.error(`download history version file failed with error message: ${err.message}, error code: ${err.code}`);
  });
  fileVersion.replaceFileWithHistoryVersion(uri, versionUri).then(() => {
    console.info("replace file with history version success.");
  }).catch((err: BusinessError) => {
    console.error("replace file with history version filed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### isFileConflict<sup>20+</sup>

isFileConflict(uri: string): Promise&lt;boolean&gt;

获取本地文件版本冲突标志。使用Promise异步回调。此方法只有应用在配置手动解冲突后才会生效，否则默认自动解冲突，返回值为false，由同步流程自动完成解冲突；

当应用配置手动解冲突后，调用此方法会返回当前文件是否与云侧文件产生冲突，并且由应用提示用户对冲突进行处理，在冲突解决前不会再自动同步上云。当处理完冲突后，需要调用[clearfileconflict](#clearfileconflict20)方法来清除冲突标志，后续才会继续触发同步，与云端保持一致。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   |  文件的URI。 |

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| Promise&lt;boolean&gt; | Promise对象，返回本地文件和云端文件的冲突标志，true表示冲突，false表示不冲突。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  fileVersion.isFileConflict(uri).then((isConflict: boolean) => {
    console.info("current file is conflict: " + isConflict);
  }).catch((err: BusinessError) => {
    console.error("get current file conflict flag failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```

### clearFileConflict<sup>20+</sup>

clearFileConflict(uri: string): Promise&lt;void&gt;

清除本地文件版本冲突标志。如果产生冲突，本地解决冲突后需要调用此方法来清除冲突标记，后续才可以触发自动同步机制，和云上保持一致。使用Promise异步回调。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| uri | string | 是   |  待清除冲突标志的文件URI。 |

**返回值：**

| 类型  | 说明 |
| ------ | ---- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 13600001 | IPC error. Possible causes: 1.IPC failed or timed out. 2.Failed to load the service. |
| 13900002 | No such file or directory. |
| 13900010 | Try again. |
| 13900012 | Permission denied by the file system. |
| 13900020 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 14000002 | Invalid URI. |
| 22400005 | Inner error. Possible causes: 1.Failed to access the database or execute the SQL statement. 2.System error, such as a null pointer, insufficient memory or a JS engine exception. |

**示例：**

  ```ts
  import { fileUri } from '@kit.CoreFileKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  let fileVersion = new cloudSync.FileVersion();

  let path = "/data/storage/el2/cloud/1.txt";
  let uri = fileUri.getUriFromPath(path);

  let isConflict = false;
  fileVersion.isFileConflict(uri).then((isConflictRet: boolean) => {
    isConflict = isConflictRet;
    console.info("current file is conflict: " + isConflictRet);
  }).catch((err: BusinessError) => {
    console.error(`get current file conflict flag failed with error message: ${err.message}, error code: ${err.code}`);
  });
  fileVersion.clearFileConflict(uri).then(() => {
    console.info("clean file conflict flag success");
  }).catch((err: BusinessError) => {
    console.error("clean file conflict flag failed with error message: " + err.message + ", error code: " + err.code);
  });
  ```