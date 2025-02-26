# @ohos.file.cloudSync (端云同步能力)

该模块向应用提供端云同步能力，包括启动/停止端云同步以及启动/停止原图下载功能。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { cloudSync } from '@kit.CoreFileKit';
```

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

**系统能力**：SystemCapability.FileManagement.DistributedFileService.CloudSync.Core

| 名称     | 类型   | 必填 | 说明 |
| ---------- | ------ | ---- | ---- |
| state | [State](#state11) | 是   | 枚举值，云文件下载状态。|
| processed | number | 是   | 已下载数据大小。|
| size | number | 是   | 当前云文件大小。|
| uri | string | 是   | 当前云文件uri。|
| error | [DownloadErrorType](#downloaderrortype11) | 是   | 下载的错误类型。|

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