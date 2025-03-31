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

**系统能力**： SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

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

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

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

**系统能力**： SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

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
| processed | number | 是   | 已下载数据大小，取值范围[0，9223372036854775807]。|
| size | number | 是   | 当前云文件大小，取值范围[0，9223372036854775807]。|
| uri | string | 是   | 当前云文件uri。|
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
| 202 | Permission verification failed, application which is not a system application uses system API. |
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
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

异步方法启动云盘端云同步,以Promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;void&gt; | Promise对象，无返回值。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

异步方法启动云盘端云同步,以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;void&gt; | 是   | 异步启动端云同步的回调。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

异步方法停止云盘端云同步,以Promise形式返回结果。

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
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

异步方法停止云盘端云同步,以callback形式返回结果。

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
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

异步方法获取上次同步时间, 以promise形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**返回值：**

| 类型                  | 说明             |
| --------------------- | ---------------- |
| Promise&lt;number&gt; | 使用Promise形式返回上次同步时间。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

异步方法获取上次同步时间, 以callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

**参数：**

| 参数名     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| callback | AsyncCallback&lt;number&gt; | 是   | 异步获取上次同步时间的回调。|

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 201 | Permission verification failed, usually the result returned by VerifyAccessToken. |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 401 | The input parameter is invalid. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 13600001  | IPC error. |
| 13900002 | No such file or directory. |
| 13900025 | No space left on device. |
| 14000002 | Invalid uri. |

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
| 14000002 | Invalid uri. |

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
| recursion | boolean | 是   | true为监听该uri以及子文件和子目录，false为仅监听该uri文件。|
| callback | Callback&lt;[ChangeData](#changedata12)&gt; | 是   | 返回更改的数据。 |

**错误码：**

以下错误码的详细介绍请参见[文件管理子系统错误码](errorcode-filemanagement.md)。

| 错误码ID                     | 错误信息        |
| ---------------------------- | ---------- |
| 202 | Permission verification failed, application which is not a system application uses system API. |
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
  let onCallback1 = (changeData: ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // 取消注册监听
  cloudSync.unRegisterChange(uri);
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
| 202 | Permission verification failed, application which is not a system application uses system API. |
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
  let onCallback1 = (changeData: ChangeData) => {
    if (changeData.type == cloudSync.NotifyType.NOTIFY_ADDED) {
      //file had added, do something
    } else if (changeData.type== cloudSync.NotifyType.NOTIFY_DELETED) {
      //file had removed, do something
    }
  }
  cloudSync.registerChange(uri, false, onCallback1);
  // 取消注册监听
  cloudSync.unRegisterChange(uri);
  ```

## NotifyType<sup>12+</sup>

数据变更通知类型。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称 |  值|  说明 |
| ----- |  ---- |  ---- |
| NOTIFY_ADDED |  0 | 文件已新建。 |
| NOTIFY_MODIFIED |  1 | 文件已修改。 |
| NOTIFY_DELETED |  2 | 文件已被删除。 |
| NOTIFY_RENAMED |  3 | 文件被重命名或者移动。 |

## ChangeData<sup>12+</sup>

定义变更数据。

**系统能力**: SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| type | [NotifyType](#notifytype12) | 是   | 更改的通知类型。|
| isDirectory | Array&lt;boolean&gt; | 是   | 指示更改的uri是否为目录。|
| uris | Array&lt;string&gt; | 是   | 更改的uris。|
